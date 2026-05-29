# load packages
import fmu
import modelica 
import logging 
import numpy as np 
import os 
import pandas as pd
import json
import utils
from pathlib import Path

"""
example of a closed/open loop simulation using FMUs generated from Modelica (component) models
notes:
   this script is only valid for simulating autonomous systems (time invariant dynamics)
   do not use if the system model has time-dependent elements 
   if you have time-dependent elements in the model, please covert them into time-dependent variables
   closed loop simulation: simulation considers controller, (webserver), rover chassis
   open loop simulation: rover-only

to do:
   1: change 'fidelity' parameter type (make it not to be 'final', modify modelica script)
   2: make 'final run statistics' silent (to decrease running time)
"""

class MFQuadrotorCoSIM:
    """
    simulation classes for a multi-fidelity rover model, supports:
    - rover-only simulation (input: throttle PWM duty cycle, )
    - set input variables to inputs at given time instances
    - be careful for
    - retrieve the final value of all state variables
    """
    def __init__(self, fidelity = 1, t0 = 0, fmu_type = "me", attack_scenario = 0, parameter_file = "rover_parameters.json", fmu_gen = False):
        """
        inputs:
            fidelity (int): fidelity level
                1: low-fidelity model
                2: high-fidelity model
        outputs:
            simulation class
                - fmus
                - data dictionary
                - attack scenario and parameters
        """
        # manual switch for generating fmu, will be deprecated after patching the following issue
        # important note: currently, the fidelity parameter is automatically set as a "final" parameter, which cannot be modified using Python API
        #                 please change it manually in the RoverExample.Components.Rover script (be careful that the fidelity parameter is also in RoverExample.ExampleScenario)
        # fmu_gen = True

        # t0 should be 0
        self.t0 = t0
        
        # save fidelity level
        self.dyn_fidelity = 1
        self.ctrl_fidelity = fidelity

        # read specification file (.json format)
        with open(parameter_file, 'r') as file:
            self.parameters_info = json.load(file)

        # enable when you want to generate or update the FMU (e.g. Lo-Fi -> Hi-Fi, Hi-Fi -> Lo-Fi)
        # convert the modelica file into a fmu and set the ininital conditions and parameters 
        if fmu_gen:
            if self.dyn_fidelity == 1:
                modelica.generate_fmu("GSQuad.Components.Quadrotor", Path("./model/MFQuadrotor.mo").absolute(), 
                                      fmu_type, {'fidelity': 1}) 
        fmuDyn = Path("./build").absolute()/"GSQuad.Components.Quadrotor/GSQuad.Components.Quadrotor.fmu"
        self.fmudyn = fmu.FMU(fmuDyn, fmu_type, self.t0, tol=1e-6)
        # get parameter information before reset
        if self.dyn_fidelity == 1:
            pass
        self.fmudyn.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmudyn.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmudyn.model.initialize()
        if self.dyn_fidelity == 1:
            self.fmudyn.set_param({'quad_low.position_w_p_w[1]': 0.0 , 'quad_low.position_w_p_w[2]': 0.0, 'quad_low.position_w_p_w[3]': 0.0,    # location
                                   'quad_low.velocity_w_p_b[1]': 0.0, 'quad_low.velocity_w_p_b[2]': 0.0, 'quad_low.velocity_w_p_b[3]': 0.0,     # body fixed velocity
                                   'quad_low.quaternion_wb[1]': 1.0, 'quad_low.quaternion_wb[2]': 0.0, 'quad_low.quaternion_wb[3]': 0.0, 'quad_low.quaternion_wb[4]': 0.0, # quaternion
                                   'quad_low.rate_wb_b[1]': 0.0, 'quad_low.rate_wb_b[2]': 0.0, 'quad_low.rate_wb_b[3]': 0.0})                   # body rates

        if fmu_gen:
            if self.ctrl_fidelity == 1:
                modelica.generate_fmu("GSQuad.Components.Controller", Path("./model/MFQuadrotor.mo").absolute(), 
                                      fmu_type, {'fidelity': 1}) 
            elif self.ctrl_fidelity == 2:
                modelica.generate_fmu("GSQuad.Components.Controller", Path("./model/MFQuadrotor.mo").absolute(), 
                                      fmu_type, {'fidelity': 2}) 
        fmuController = Path("./build").absolute()/"GSQuad.Components.Controller/GSQuad.Components.Controller.fmu" 
        self.fmuctrl = fmu.FMU(fmuController, fmu_type, self.t0, tol=1e-6)
        # get parameter information before reset
        if self.ctrl_fidelity == 1:
            self.parameters_info['mass'] = self.fmuctrl.get_param('euler_pid.mass')
            self.parameters_info['g'] = 9.81
            self.parameters_info['thrust_coefficient'] = self.fmuctrl.get_param('euler_pid.k_eta')
            self.parameters_info['omega_rotor_max'] = self.fmuctrl.get_param('euler_pid.omega_rotor_max')
            self.parameters_info['omega_rotor_min'] = self.fmuctrl.get_param('euler_pid.omega_rotor_min')
        elif self.ctrl_fidelity == 2:
            self.parameters_info['mass'] = self.fmuctrl.get_param('euler_pid.mass')
            self.parameters_info['g'] = 9.81
            self.parameters_info['thrust_coefficient'] = self.fmuctrl.get_param('euler_pid.k_eta')
            self.parameters_info['omega_rotor_max'] = self.fmuctrl.get_param('euler_pid.omega_rotor_max')
            self.parameters_info['omega_rotor_min'] = self.fmuctrl.get_param('euler_pid.omega_rotor_min')
        self.fmuctrl.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmuctrl.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmuctrl.model.initialize()
        if self.ctrl_fidelity == 1:
            self.fmuctrl.set_param({'euler_pid.pos_w_p_w_fdbk[1]': 0, 'euler_pid.pos_w_p_w_fdbk[2]': 0, 'euler_pid.pos_w_p_w_fdbk[3]': 0,     # initial position feedback
                                    'euler_pid.vel_w_p_b_fdbk[1]': 0, 'euler_pid.vel_w_p_b_fdbk[2]': 0, 'euler_pid.vel_w_p_b_fdbk[3]': 0,     # initial velocity feedback
                                    'euler_pid.euler_wb_fdbk[1]': 0, 'euler_pid.euler_wb_fdbk[2]': 0, 'euler_pid.euler_wb_fdbk[3]': 0,        # initial euler angle feedback
                                    'euler_pid.rate_wb_b_fdbk[1]': 0, 'euler_pid.rate_wb_b_fdbk[2]': 0, 'euler_pid.rate_wb_b_fdbk[3]': 0,     # initial body rate feedback
                                    'euler_pid.pos_error[1]': 0, 'euler_pid.pos_error[2]': 0, 'euler_pid.pos_error[3]': 0,                    # initial position error
                                    'euler_pid.vel_target[1]': 0, 'euler_pid.vel_target[1]': 0, 'euler_pid.vel_target[1]': 0,                 # initial velocity target   
                                    'euler_pid.vel_error_last[1]': 0, 'euler_pid.vel_error_last[2]': 0, 'euler_pid.vel_error_last[3]': 0,     # initial velocity error previous step
                                    'euler_pid.vel_error_i[1]': 0, 'euler_pid.vel_error_i[2]': 0, 'euler_pid.vel_error_i[3]': 0,              # initial velocity error integral
                                    'euler_pid.vel_error_d[1]': 0, 'euler_pid.vel_error_d[2]': 0, 'euler_pid.vel_error_d[3]': 0,              # initial velocity error derivative
                                    'euler_pid.acc_target[1]': 0, 'euler_pid.acc_target[2]': 0, 'euler_pid.acc_target[3]': 0,                 # initial aceeleration target
                                    'euler_pid.acc_z_target': self.parameters_info['g'], 'euler_pid.acc_fwd_target': 0, 'euler_pid.acc_rgt_target': 0,      # initial aceeleration target
                                    'euler_pid.roll_target': 0, 'euler_pid.pitch_target': 0, 'euler_pid.yaw_target': 0,                       # initial attitude target
                                    'euler_pid.att_error[1]': 0, 'euler_pid.att_error[2]': 0, 'euler_pid.att_error[3]': 0,                    # initial attitude error
                                    'euler_pid.rate_target[1]': 0, 'euler_pid.rate_target[2]': 0, 'euler_pid.rate_target[3]': 0,              # initial rate target
                                    'euler_pid.rate_error[1]': 0, 'euler_pid.rate_error[2]': 0, 'euler_pid.rate_error[3]': 0,                 # initial rate error
                                    'euler_pid.rate_error_i[1]': 0, 'euler_pid.rate_error_i[2]': 0, 'euler_pid.rate_error_i[3]': 0,           # initial rate error integral
                                    'euler_pid.rate_error_d[1]': 0, 'euler_pid.rate_error_d[2]': 0, 'euler_pid.rate_error_d[3]': 0,           # initial rate error derivative
                                    'euler_pid.force_target': self.parameters_info['mass']*self.parameters_info['g'], 'euler_pid.moment_target[1]': 0, 'euler_pid.moment_target[2]': 0, 'euler_pid.moment_target[3]': 0,   # initial force and moment target
                                    'euler_pid.fm_target[1]': self.parameters_info['mass']*self.parameters_info['g'], 'euler_pid.fm_target[2]': 0, 'euler_pid.fm_target[3]': 0, 'euler_pid.fm_target[4]': 0,               # initial force and moment target
                                    'euler_pid.thrust_target[1]': (self.parameters_info['mass']*self.parameters_info['g'])/4, 
                                    'euler_pid.thrust_target[2]': (self.parameters_info['mass']*self.parameters_info['g'])/4, 
                                    'euler_pid.thrust_target[3]': (self.parameters_info['mass']*self.parameters_info['g'])/4,  
                                    'euler_pid.thrust_target[4]': (self.parameters_info['mass']*self.parameters_info['g'])/4,   # initial thrust target
                                    'euler_pid.omega_spd_sq_target[1]': np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient']), 
                                    'euler_pid.omega_spd_sq_target[2]': np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient']), 
                                    'euler_pid.omega_spd_sq_target[3]': np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient']),  
                                    'euler_pid.omega_spd_sq_target[4]': np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient']),   # initial rotor speed squared target
                                    'euler_pid.normalized_ctrl_input[1]': (np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient'])-self.parameters_info['omega_rotor_min'])/(self.parameters_info['omega_rotor_max']-self.parameters_info['omega_rotor_min']),
                                    'euler_pid.normalized_ctrl_input[2]': (np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient'])-self.parameters_info['omega_rotor_min'])/(self.parameters_info['omega_rotor_max']-self.parameters_info['omega_rotor_min']),
                                    'euler_pid.normalized_ctrl_input[3]': (np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient'])-self.parameters_info['omega_rotor_min'])/(self.parameters_info['omega_rotor_max']-self.parameters_info['omega_rotor_min']),
                                    'euler_pid.normalized_ctrl_input[4]': (np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient'])-self.parameters_info['omega_rotor_min'])/(self.parameters_info['omega_rotor_max']-self.parameters_info['omega_rotor_min'])})    # initial normalized control input

        elif self.ctrl_fidelity == 2:
            pass

        if fmu_gen:
            modelica.generate_fmu("GSQuad.Components.MissionPlanner", Path("./model/MFQuadrotor.mo").absolute(), fmu_type)
        fmuplanner = Path("./build").absolute()/"GSQuad.Components.MissionPlanner/GSQuad.Components.MissionPlanner.fmu"
        self.fmuplanner = fmu.FMU(fmuplanner, fmu_type, self.t0, tol=1e-6)
        self.fmuplanner.reset() 
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmuplanner.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmuplanner.model.initialize()

        if fmu_gen:
            modelica.generate_fmu("GSQuad.Components.Joystick", Path("./model/MFQuadrotor.mo").absolute(), fmu_type)
        fmustick = Path("./build").absolute()/"GSQuad.Components.Joystick/GSQuad.Components.Joystick.fmu"
        self.fmustick = fmu.FMU(fmustick, fmu_type, self.t0, tol=1e-6)
        self.fmustick.reset() 
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmustick.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmustick.model.initialize()

        # closed loop simulation by calling all components
        self.data = {'t': np.zeros((0,)), 'webserver': {}, 'controller': {}, 'rover': {}}

        # set up the attack model
        self.attack_scenario = attack_scenario
        if self.attack_scenario == 0:
            self.target_x_pos = self.parameters_info['target_x']
            self.target_y_pos = self.parameters_info['target_y']
            self.target_z_pos = -self.parameters_info['target_z']
        elif self.attack_scenario == 1:        # [-] attack_scneario: 0 = no attack, 1 = parameter change attack, 2 = barometer attack, 3 = gyro attack
            pass
        elif self.attack_scenario == 2:
            pass
        elif self.attack_scenario == 3:
            self.gyro_atk_power = self.parameters_info['acoustic_power']
            self.speaker_dist = self.parameters_info['speaker_dist']
            self.gyro_atk_freq = (self.parameters_info['drive_freq']+self.parameters_info['acoustic_freq_range']*(2*np.random.rand()-1))*(2*np.pi)
            self.gyro_misalignment = self.parameters_info['gyro_misalignment']*np.random.rand()*(np.pi/180)
            self.gyro_atk_dir = np.random.rand()*(np.pi/2)
            self.gyro_atk_phase = np.random.rand()*2*np.pi-np.pi


    def simulate(self, tf = 10, dt = 0.1):
        """
        inputs:
            tf (np.float64): final time
            dt (np.float64): time step for simulation propagation

        outputs :
            pandas dataframe
                - time history of outputs
        """

        self.data['t'] = np.linspace(self.t0, tf, int((tf-self.t0)/dt)+1)

        for t_cur in self.data['t']:

            # get planner command
            if self.attack_scenario == 0:
                self.fmuplanner.set_param({'position_setpoint_w_buf[1]': self.parameters_info['target_x'], 
                                           'position_setpoint_w_buf[2]': self.parameters_info['target_y'], 
                                           'position_setpoint_w_buf[3]': -self.parameters_info['target_z']})
            self.fmuplanner.set_param({'sample_period': dt+1e-6})  # avoid unnecessary update at t = dt, make update happen only at t=0
            self.fmuplanner.step_time(t_cur, t_cur+dt)
            
            # get joystick command
            self.fmustick.set_param({'sample_period': dt+1e-6})  # avoid unnecessary update at t = dt, make update happen only at t=0
            self.fmustick.step_time(t_cur, t_cur+dt)

            # set command for controller
            self.fmuctrl.set_input(t_cur+dt, {"pos_w_p_w_fdbk[1]": self.fmudyn.get_output_value()['pos_w_p_w_meas[1]'],
                                              "pos_w_p_w_fdbk[2]": self.fmudyn.get_output_value()['pos_w_p_w_meas[2]'],
                                              "pos_w_p_w_fdbk[3]": self.fmudyn.get_output_value()['pos_w_p_w_meas[3]'],
                                              "vel_w_p_b_fdbk[1]": self.fmudyn.get_output_value()['vel_w_p_b_meas[1]'],
                                              "vel_w_p_b_fdbk[2]": self.fmudyn.get_output_value()['vel_w_p_b_meas[2]'],
                                              "vel_w_p_b_fdbk[3]": self.fmudyn.get_output_value()['vel_w_p_b_meas[3]'],
                                              "acc_w_p_b_fdbk[1]": self.fmudyn.get_output_value()['acc_w_p_b_meas[1]'],
                                              "acc_w_p_b_fdbk[2]": self.fmudyn.get_output_value()['acc_w_p_b_meas[2]'],
                                              "acc_w_p_b_fdbk[3]": self.fmudyn.get_output_value()['acc_w_p_b_meas[3]'],
                                              "quat_wb_fdbk[1]": self.fmudyn.get_output_value()['quat_wb_meas[1]'],
                                              "quat_wb_fdbk[2]": self.fmudyn.get_output_value()['quat_wb_meas[2]'],
                                              "quat_wb_fdbk[3]": self.fmudyn.get_output_value()['quat_wb_meas[3]'],
                                              "quat_wb_fdbk[4]": self.fmudyn.get_output_value()['quat_wb_meas[4]'],
                                              "euler_wb_fdbk[1]": self.fmudyn.get_output_value()['euler_wb_meas[1]'],
                                              "euler_wb_fdbk[2]": self.fmudyn.get_output_value()['euler_wb_meas[2]'],
                                              "euler_wb_fdbk[3]": self.fmudyn.get_output_value()['euler_wb_meas[3]'],
                                              "rate_wb_b_fdbk[1]": self.fmudyn.get_output_value()['rate_wb_b_meas[1]'],
                                              "rate_wb_b_fdbk[2]": self.fmudyn.get_output_value()['rate_wb_b_meas[2]'],
                                              "rate_wb_b_fdbk[3]": self.fmudyn.get_output_value()['rate_wb_b_meas[3]'],
                                              "position_setpoint[1]": self.fmuplanner.get_output_value()['position_setpoint_w[1]'] if self.attack_scenario != 0 else self.target_x_pos,
                                              "position_setpoint[2]": self.fmuplanner.get_output_value()['position_setpoint_w[2]'] if self.attack_scenario != 0 else self.target_y_pos,
                                              "position_setpoint[3]": self.fmuplanner.get_output_value()['position_setpoint_w[3]'] if self.attack_scenario != 0 else self.target_z_pos,
                                              "yaw_setpoint": self.fmuplanner.get_output_value()['yaw_setpoint_w'],
                                              "rc_input[1]": self.fmustick.get_output_value()['stick_cmd[1]'],
                                              "rc_input[2]": self.fmustick.get_output_value()['stick_cmd[2]'],
                                              "rc_input[3]": self.fmustick.get_output_value()['stick_cmd[3]'],
                                              "rc_input[4]": self.fmustick.get_output_value()['stick_cmd[4]']})

            self.fmuctrl.set_param({'update_period': dt+1e-6})  # avoid unnecessary update at t = dt, make update happen only at t=0
            self.fmuctrl.step_time(t_cur, t_cur+dt)

            # set pwm command for chassis dynamic model
            self.fmudyn.set_input(t_cur+dt, {"pwm_rotor_cmd[1]": self.fmuctrl.get_output_value()['pwm_rotor_cmd[1]'],
                                             "pwm_rotor_cmd[2]": self.fmuctrl.get_output_value()['pwm_rotor_cmd[2]'],
                                             "pwm_rotor_cmd[3]": self.fmuctrl.get_output_value()['pwm_rotor_cmd[3]'],
                                             "pwm_rotor_cmd[4]": self.fmuctrl.get_output_value()['pwm_rotor_cmd[4]']})
            if self.attack_scenario == 3:
                self.fmudyn.set_param({'W': self.gyro_atk_power, 
                                       'dist': self.speaker_dist,
                                       'w_ac': self.gyro_atk_freq, 
                                       'phi_0': self.gyro_atk_phase, 
                                       'psi_ac': self.gyro_atk_dir, 
                                       'epsilon': self.gyro_misalignment})
            else:
                self.fmudyn.set_param({'W': 0.0, 
                                       'dist': 0.01,
                                       'w_ac': 15000.0, 
                                       'phi_0': 0.0, 
                                       'psi_ac': 0.0, 
                                       'epsilon': 0.0})
                
            self.fmudyn.set_param({'sensor_sample_period': dt+1e-6})  # avoid unnecessary update at t = dt, make update happen only at t=0
            self.fmudyn.step_time(t_cur, t_cur+dt)

            # correct internal time clock
            self.fmudyn.model.set(['gyroatk.timer_count'],[np.float64(t_cur/dt)])

            # check
            # print(np.float64(t_cur/dt))
            # print(self.fmudyn.variable[self.fmudyn.variableNames.index('timer_count')])
            # print(' -- ')

        # log the data
        self.data['quadrotor'] = self.fmudyn.data
        self.data['controller'] = self.fmuctrl.data
        self.data['missionplanner'] = self.fmuplanner.data
        self.data['joystick'] = self.fmustick.data

        # return the simulation output
        save_data = pd.DataFrame(np.hstack((self.data['t'][:,np.newaxis], 
                                            self.data['quadrotor']['state']['values'], self.data['quadrotor']['variable']['values'], 
                                            self.data['controller']['state']['values'], self.data['controller']['variable']['values'], 
                                            self.data['missionplanner']['state']['values'], self.data['missionplanner']['variable']['values'],
                                            self.data['joystick']['state']['values'], self.data['joystick']['variable']['values'])), 
                                 columns=np.hstack((['time'], self.data['quadrotor']['state']['names'], self.data['quadrotor']['variable']['names'],
                                                   self.data['controller']['state']['names'], self.data['controller']['variable']['names'], 
                                                   self.data['missionplanner']['state']['names'], self.data['missionplanner']['variable']['names'],
                                                   self.data['joystick']['state']['names'], self.data['joystick']['variable']['names'])))

        return save_data

    def sim_reset(self):
        """
        reset the simulation model
        inputs :
        outputs :
        """
        self.fmudyn.empty_data()
        self.fmudyn.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmudyn.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmudyn.model.initialize()
        if self.dyn_fidelity == 1:
            self.fmudyn.set_param({'quad_low.position_w_p_w[1]': 0.0 , 'quad_low.position_w_p_w[2]': 0.0, 'quad_low.position_w_p_w[3]': 0.0,    # location
                                   'quad_low.velocity_w_p_b[1]': 0.0, 'quad_low.velocity_w_p_b[2]': 0.0, 'quad_low.velocity_w_p_b[3]': 0.0,     # body fixed velocity
                                   'quad_low.quaternion_wb[1]': 1.0, 'quad_low.quaternion_wb[2]': 0.0, 'quad_low.quaternion_wb[3]': 0.0, 'quad_low.quaternion_wb[4]': 0.0, # quaternion
                                   'quad_low.rate_wb_b[1]': 0.0, 'quad_low.rate_wb_b[2]': 0.0, 'quad_low.rate_wb_b[3]': 0.0})                   # body rates

        self.fmuctrl.empty_data()
        self.fmuctrl.reset() 
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmuctrl.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmuctrl.model.initialize()
        if self.ctrl_fidelity == 1:
            self.fmuctrl.set_param({'euler_pid.pos_w_p_w_fdbk[1]': 0, 'euler_pid.pos_w_p_w_fdbk[2]': 0, 'euler_pid.pos_w_p_w_fdbk[3]': 0,     # initial position feedback
                                    'euler_pid.vel_w_p_b_fdbk[1]': 0, 'euler_pid.vel_w_p_b_fdbk[2]': 0, 'euler_pid.vel_w_p_b_fdbk[3]': 0,     # initial velocity feedback
                                    'euler_pid.euler_wb_fdbk[1]': 0, 'euler_pid.euler_wb_fdbk[2]': 0, 'euler_pid.euler_wb_fdbk[3]': 0,        # initial euler angle feedback
                                    'euler_pid.rate_wb_b_fdbk[1]': 0, 'euler_pid.rate_wb_b_fdbk[2]': 0, 'euler_pid.rate_wb_b_fdbk[3]': 0,     # initial body rate feedback
                                    'euler_pid.pos_error[1]': 0, 'euler_pid.pos_error[2]': 0, 'euler_pid.pos_error[3]': 0,                    # initial position error
                                    'euler_pid.vel_target[1]': 0, 'euler_pid.vel_target[1]': 0, 'euler_pid.vel_target[1]': 0,                 # initial velocity target   
                                    'euler_pid.vel_error_last[1]': 0, 'euler_pid.vel_error_last[2]': 0, 'euler_pid.vel_error_last[3]': 0,     # initial velocity error previous step
                                    'euler_pid.vel_error_i[1]': 0, 'euler_pid.vel_error_i[2]': 0, 'euler_pid.vel_error_i[3]': 0,              # initial velocity error integral
                                    'euler_pid.vel_error_d[1]': 0, 'euler_pid.vel_error_d[2]': 0, 'euler_pid.vel_error_d[3]': 0,              # initial velocity error derivative
                                    'euler_pid.acc_target[1]': 0, 'euler_pid.acc_target[2]': 0, 'euler_pid.acc_target[3]': 0,                 # initial aceeleration target
                                    'euler_pid.acc_z_target': self.parameters_info['g'], 'euler_pid.acc_fwd_target': 0, 'euler_pid.acc_rgt_target': 0,      # initial aceeleration target
                                    'euler_pid.roll_target': 0, 'euler_pid.pitch_target': 0, 'euler_pid.yaw_target': 0,                       # initial attitude target
                                    'euler_pid.att_error[1]': 0, 'euler_pid.att_error[2]': 0, 'euler_pid.att_error[3]': 0,                    # initial attitude error
                                    'euler_pid.rate_target[1]': 0, 'euler_pid.rate_target[2]': 0, 'euler_pid.rate_target[3]': 0,              # initial rate target
                                    'euler_pid.rate_error[1]': 0, 'euler_pid.rate_error[2]': 0, 'euler_pid.rate_error[3]': 0,                 # initial rate error
                                    'euler_pid.rate_error_i[1]': 0, 'euler_pid.rate_error_i[2]': 0, 'euler_pid.rate_error_i[3]': 0,           # initial rate error integral
                                    'euler_pid.rate_error_d[1]': 0, 'euler_pid.rate_error_d[2]': 0, 'euler_pid.rate_error_d[3]': 0,           # initial rate error derivative
                                    'euler_pid.force_target': self.parameters_info['mass']*self.parameters_info['g'], 'euler_pid.moment_target[1]': 0, 'euler_pid.moment_target[2]': 0, 'euler_pid.moment_target[3]': 0,   # initial force and moment target
                                    'euler_pid.fm_target[1]': self.parameters_info['mass']*self.parameters_info['g'], 'euler_pid.fm_target[2]': 0, 'euler_pid.fm_target[3]': 0, 'euler_pid.fm_target[4]': 0,               # initial force and moment target
                                    'euler_pid.thrust_target[1]': (self.parameters_info['mass']*self.parameters_info['g'])/4, 
                                    'euler_pid.thrust_target[2]': (self.parameters_info['mass']*self.parameters_info['g'])/4, 
                                    'euler_pid.thrust_target[3]': (self.parameters_info['mass']*self.parameters_info['g'])/4,  
                                    'euler_pid.thrust_target[4]': (self.parameters_info['mass']*self.parameters_info['g'])/4,   # initial thrust target
                                    'euler_pid.omega_spd_sq_target[1]': np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient']), 
                                    'euler_pid.omega_spd_sq_target[2]': np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient']), 
                                    'euler_pid.omega_spd_sq_target[3]': np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient']),  
                                    'euler_pid.omega_spd_sq_target[4]': np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient']),   # initial rotor speed squared target
                                    'euler_pid.normalized_ctrl_input[1]': (np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient'])-self.parameters_info['omega_rotor_min'])/(self.parameters_info['omega_rotor_max']-self.parameters_info['omega_rotor_min']),
                                    'euler_pid.normalized_ctrl_input[2]': (np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient'])-self.parameters_info['omega_rotor_min'])/(self.parameters_info['omega_rotor_max']-self.parameters_info['omega_rotor_min']),
                                    'euler_pid.normalized_ctrl_input[3]': (np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient'])-self.parameters_info['omega_rotor_min'])/(self.parameters_info['omega_rotor_max']-self.parameters_info['omega_rotor_min']),
                                    'euler_pid.normalized_ctrl_input[4]': (np.sqrt((self.parameters_info['mass']*self.parameters_info['g'])/4/self.parameters_info['thrust_coefficient'])-self.parameters_info['omega_rotor_min'])/(self.parameters_info['omega_rotor_max']-self.parameters_info['omega_rotor_min'])})    # initial normalized control

        self.fmuplanner.empty_data()
        self.fmuplanner.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmuplanner.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmuplanner.model.initialize()

        self.fmustick.empty_data()
        self.fmustick.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmustick.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmustick.model.initialize()

        # initialize data log
        self.data = {'t': np.zeros((0,)), 'webserver': {}, 'controller': {}, 'rover': {}}

        # randomly change attack parameters
        if self.attack_scenario == 1:
            pass

        if self.attack_scenario == 3:
            self.gyro_atk_freq = (self.parameters_info['drive_freq']+self.parameters_info['acoustic_freq_range']*(2*np.random.rand()-1))*(2*np.pi)
            self.gyro_misalignment = self.parameters_info['gyro_misalignment']*np.random.rand()*(np.pi/180)
            self.gyro_atk_dir = np.random.rand()*(np.pi/2)
            self.gyro_atk_phase = np.random.rand()*2*np.pi-np.pi
