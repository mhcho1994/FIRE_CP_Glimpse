# load packages
import fmu
import modelica 
import logging 
import numpy as np 
import os 
import pandas as pd
import json
import utils
from math import gcd

"""
example of a closed/open loop simulation using FMUs generated from Modelica (component) models
notes:
   this script is only valid for simulating autonomous systems (time invariant dynamics)
   do not use if the system model has time-dependent elements 
   if you have time-dependent elements in the model, please covert them into time-dependent variables
   CoSIM (co-simulation): simulation considers controller, joystick, mission planner, quadrotor physics (multiple components)
   CLoopSIM (closed-loop simulation): simulation considers controller, quadrotor physics
   OLooopSIM (open-loop simulation): quadrotor physics-only

to do:
   1: change 'fidelity' parameter type (make it not to be 'final', modify modelica script)
   2: make 'final run statistics' silent (to decrease running time)
"""

class MFQuadrotorCoSIM:
    """
    simulation classes for a multi-fidelity quadrotor co-simulation, supports:
    - orchestrate different CPS components in whole drone system
    - retrieve the final value of all state variables
    """
    def __init__(self, physics_fidelity = 1, cyber_fidelity = 1, t0 = 0, fmu_type = "me", attack_scenario = 0, parameter_file = "dronesim.json", logging_file = None):
        """
        inputs:
            fidelity (int): physics/cyber fidelity level
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
        fmu_gen = False

        # t0 should be 0
        self.t0 = t0
        
        # save fidelity level
        self.physics_fidelity = physics_fidelity
        self.cyber_fidelity = cyber_fidelity

        # read specification file (.json format)
        self.parameters_info = {}
        with open(parameter_file, 'r') as file:
            self.parameters_info['scneario'] = json.load(file)

        # check logging option
        if logging_file is None:
            self.logging = False
        else:
            self.logging = True
            self.logfile = logging_file

        # enable when you want to generate or update the FMU (e.g. Lo-Fi -> Hi-Fi, Hi-Fi -> Lo-Fi)
        # convert the modelica file into a fmu and set the ininital conditions and parameters 
        if fmu_gen:
            if self.physics_fidelity == 1:
                modelica.generate_fmu("GSQuad.Components.Quadrotor", f"{os.getcwd()}/model/MFQuadrotor_FMUgen.mo", fmu_type, {'fidelity': 1}) 
            elif self.physics_fidelity == 2:
                modelica.generate_fmu("GSQuad.Components.Quadrotor", f"{os.getcwd()}/model/MFQuadrotor_FMUgen.mo", fmu_type, {'fidelity': 2})
            if self.cyber_fidelity == 1:
                modelica.generate_fmu("GSQuad.Components.Controller", f"{os.getcwd()}/model/MFQuadrotor_FMUgen.mo", fmu_type, {'fidelity': 1}) 
            elif self.cyber_fidelity == 2:
                modelica.generate_fmu("GSQuad.Components.Controller", f"{os.getcwd()}/model/MFQuadrotor_FMUgen.mo", fmu_type, {'fidelity': 2})
            modelica.generate_fmu("GSQuad.Components.Joystick", f"{os.getcwd()}/model/MFQuadrotor_FMUgen.mo", fmu_type, {})
            modelica.generate_fmu("GSQuad.Components.MissionPlanner", f"{os.getcwd()}/model/MFQuadrotor_FMUgen.mo", fmu_type, {})

        # load fmu for chassis dynamics
        fmuDyn = "GSQuad.Components.Quadrotor/GSQuad.Components.Quadrotor.fmu"
        self.fmudyn = fmu.FMU(fmuDyn, fmu_type, self.t0, tol=1e-6)
        # retrieve parameter information before reset if needed
        self.parameters_info['chassis'] = {}
        if self.physics_fidelity == 1:
            self.parameters_info['chassis']['actuator_sample_period'] = self.fmudyn.get_param('actuator_sample_period')
            self.parameters_info['chassis']['sensor_sample_period'] = self.fmudyn.get_param('sensor_sample_period')
        elif self.physics_fidelity == 2:
            pass
        self.fmudyn.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmudyn.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmudyn.model.initialize()
        if self.physics_fidelity == 1:
            self.fmudyn.set_param({'quad_low.position_w_p_w[1]': 0.0, 'quad_low.position_w_p_w[2]': 0.0, 'quad_low.position_w_p_w[3]': 0.0, # location
                                   'quad_low.velocity_w_p_b[1]': 0.0, 'quad_low.velocity_w_p_b[2]': 0.0, "quad_low.velocity_w_p_b[3]": 0.0, # body fixed velocity
                                   'quad_low.quaternion_wb[1]': 1.0, 'quad_low.quaternion_wb[2]':0.0, 'quad_low.quaternion_wb[3]': 0.0, 'quad_low.quaternion_wb[4]': 0.0, # quaternion from inertial to body
                                   'quad_low.velocity_w_p_b[1]': 0.0, 'quad_low.velocity_w_p_b[2]': 0.0, 'quad_low.velocity_w_p_b[3]': 0.0}) # rotation rates in body
        elif self.physics_fidelity == 2:
            self.fmudyn.set_param({'quad_high.position_w_p_w[1]': 0.0, 'quad_high.position_w_p_w[2]': 0.0, 'quad_high.position_w_p_w[3]': 0.0, # location
                                   'quad_high.velocity_w_p_b[1]': 0.0, 'quad_high.velocity_w_p_b[2]': 0.0, "quad_high.velocity_w_p_b[3]": 0.0, # body fixed velocity
                                   'quad_high.quaternion_wb[1]': 1.0, 'quad_high.quaternion_wb[2]':0.0, 'quad_high.quaternion_wb[3]': 0.0, 'quad_low.quaternion_wb[4]': 0.0, # quaternion from inertial to body
                                   'quad_high.velocity_w_p_b[1]': 0.0, 'quad_high.velocity_w_p_b[2]': 0.0, 'quad_high.velocity_w_p_b[3]': 0.0}) # rotation rates in body

        fmuController = "GSQuad.Components.Controller/GSQuad.Components.Controller.fmu" 
        self.fmuctrl = fmu.FMU(fmuController, fmu_type, self.t0, tol=1e-6)
        # retrieve parameter information before reset if needed
        self.parameters_info['controller'] = {}
        if self.cyber_fidelity == 1:
            self.parameters_info['controller']['update_period'] = self.fmuctrl.get_param('update_period')
        elif self.cyber_fidelity == 2:
            pass
        self.fmuctrl.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmuctrl.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmuctrl.model.initialize()
        if self.cyber_fidelity == 1:
            self.fmuctrl.set_param({'euler_pid.vel_error_i[1]': 0.0, 'euler_pid.vel_error_i[2]': 0.0, 'euler_pid.vel_error_i[3]': 0.0, # velocity error integral
                                    'euler_pid.vel_error_last[1]': 0.0, 'euler_pid.vel_error_last[2]': 0.0, 'euler_pid.vel_error_last[3]': 0.0, # last velocity error
                                    'euler_pid.rate_error_i[1]': 0.0, 'euler_pid.rate_error_i[2]': 0.0, 'euler_pid.rate_error_i[3]': 0.0, # rate error integral
                                    'euler_pid.rate_error_last[1]': 0.0, 'euler_pid.rate_error_last[2]': 0.0, 'euler_pid.rate_error_last[3]': 0.0})  # last rate error
        elif self.cyber_fidelity == 2:
            pass

        fmuJoystick = "GSQuad.Components.Joystick/GSQuad.Components.Joystick.fmu"
        self.fmustick = fmu.FMU(fmuJoystick, fmu_type, self.t0, tol=1e-6)
        # retrieve parameter information before reset if needed
        self.parameters_info['joystick'] = {}
        self.parameters_info['joystick']['sample_period'] = self.fmustick.get_param('sample_period')
        self.fmustick.reset() 
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmustick.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmustick.model.initialize()
        self.fmustick.set_param({'stick_cmd[1]': 0.0, 'stick_cmd[2]': 0.0, 'stick_cmd[3]': 0.0, 'stick_cmd[4]': 0.0}) # zero throttle, zero roll/pitch/yaw commands

        fmuMissionPlanner = "GSQuad.Components.MissionPlanner/GSQuad.Components.MissionPlanner.fmu"
        self.fmuplanner = fmu.FMU(fmuMissionPlanner, fmu_type, self.t0, tol=1e-6)
        # retrieve parameter information before reset if needed
        self.parameters_info['planner'] = {}
        self.parameters_info['planner']['sample_period'] = self.fmuplanner.get_param('sample_period')
        self.fmuplanner.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmuplanner.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmuplanner.model.initialize()
        self.fmuplanner.set_param({'position_setpoint_w[1]': 0.0, 'position_setpoint_w[2]': 0.0, 'position_setpoint_w[3]': -30.0, 'position_setpoint_w[1]': 0.0,
                                   'yaw_setpoint_w': 0.0}) # position coordinates in NED, yaw setpoint with respect to north direction
        
        # closed loop simulation by calling all components
        self.data = {'time': np.zeros((0,)), 'missionplanner': {}, 'joystick': {}, 'controller': {}, 'quadrotor': {}}

        # set up the attack model
        self.attack_scenario = attack_scenario
        if self.attack_scenario == 0:  # [-] attack_scneario 0: no attack
            pass
        elif self.attack_scenario == 1:  # [-] attack_scenario 1: additive bias on velocity measurement (optical flow sensor spoofing)
            self.optical_flow_vel_bias = 0.0
            self.optical_flow_vel_variance = 1.0

            
    def simulate(self, tf = 10.0, dt = 0.1):
        """
        multi-rate, event-driven closed-loop simulation.
        - planner, joystick, controller run at their own rates.
        - chassis (plant) integrates at the base tick (gcd of all periods)
        - zero-order hold between updates for slower publishers.
        returns a pandas.DataFrame with stitched logs (time + selected signals).
        inputs:
            tf (np.float64): final time
            dt (np.float64): time step for simulation propagation

        outputs :
            pandas dataframe
                - time history of outputs
        """
        # compute gcd of update period to set it as step size
        dt_dyn = np.min(np.array([self.parameters_info['chassis'].get('actuator_sample_period'),
                                  self.parameters_info['chassis'].get('sensor_sample_period')],dtype=np.float64))
        dt_ctrl = np.float64(self.parameters_info['controller'].get('update_period'))
        dt_plan = np.float64(self.parameters_info['planner'].get('sample_period'))
        dt_stick = np.float64(self.parameters_info['joystick'].get('sample_period'))

        dt_base = _gcd_dt([dt_dyn, dt_ctrl, dt_plan, dt_stick], quantum=1e-6)
        if dt_base - min(dt_dyn, dt_ctrl, dt_plan, dt_stick) > 1e-12:
            dt_base = min(dt_dyn, dt_ctrl, dt_plan, dt_stick)

        # number of ticks
        n_ticks = int(round((tf-self.t0)/dt_base))+1 

        # compute stride
        k_dyn = np.max([1,np.int16(round(dt_dyn/dt_base))])
        k_ctrl = np.max([1,np.int16(round(dt_ctrl/dt_base))])
        k_plan = np.max([1,np.int16(round(dt_plan/dt_base))])
        k_stick = np.max([1,np.int16(round(dt_stick/dt_base))])

        if self.attack_scenario == 1:  # [-] attack_scenario 1
            k_opticalflow = np.max([1,np.int16(round(0.25/dt_base))]) # 4Hz sampling rate for optical flow sensor

        # event-loop
        t_last_dyn = self.t0
        t_last_ctrl = self.t0
        t_last_plan = self.t0
        t_last_stick = self.t0

        for itick in range(n_ticks):
            t_cur = self.t0+itick*dt_base

            # propagate mission planner
            if itick%k_plan == 0:
                self.fmuplanner.step_time(t_last_plan, t_cur)
                t_last_plan = t_cur

            # propagate joystick
            if itick%k_stick == 0:
                self.fmustick.step_time(t_last_stick, t_cur)
                t_last_stick = t_cur

            # propagate controller
            if itick%k_ctrl == 0 and itick != 0:
                self.fmuctrl.set_input(t_cur+dt_ctrl, {"pos_w_p_w_fdbk[1]": self.fmudyn.get_output_value()['pos_w_p_w_meas[1]'],
                                                       "pos_w_p_w_fdbk[2]": self.fmudyn.get_output_value()['pos_w_p_w_meas[2]'],
                                                       "pos_w_p_w_fdbk[3]": self.fmudyn.get_output_value()['pos_w_p_w_meas[3]'],
                                                       "vel_w_p_b_fdbk[1]": self.fmudyn.get_output_value()['vel_w_p_b_meas[1]']+(self.optical_spoof_vector[0] if self.attack_scenario == 1 else 0.0),
                                                       "vel_w_p_b_fdbk[2]": self.fmudyn.get_output_value()['vel_w_p_b_meas[2]']+(self.optical_spoof_vector[1] if self.attack_scenario == 1 else 0.0),
                                                       "vel_w_p_b_fdbk[3]": self.fmudyn.get_output_value()['vel_w_p_b_meas[3]']+(self.optical_spoof_vector[2] if self.attack_scenario == 1 else 0.0),
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
                                                       "rc_input[1]": self.fmustick.get_output_value()['stick_cmd[1]'],
                                                       "rc_input[2]": self.fmustick.get_output_value()['stick_cmd[2]'],
                                                       "rc_input[3]": self.fmustick.get_output_value()['stick_cmd[3]'],
                                                       "rc_input[4]": self.fmustick.get_output_value()['stick_cmd[4]'],
                                                       "position_setpoint[1]": self.fmuplanner.get_output_value()['position_setpoint_w[1]'],
                                                       "position_setpoint[2]": self.fmuplanner.get_output_value()['position_setpoint_w[2]'],
                                                       "position_setpoint[3]": self.fmuplanner.get_output_value()['position_setpoint_w[3]'],
                                                       "yaw_setpoint": self.fmuplanner.get_output_value()['yaw_setpoint_w']})
                self.fmuctrl.step_time(t_last_ctrl, t_cur)
                t_last_ctrl = t_cur
            elif itick%k_ctrl == 0 and itick == 0:
                self.fmuctrl.set_input(t_cur+dt_ctrl, {"pos_w_p_w_fdbk[1]": 0.0, "pos_w_p_w_fdbk[2]": 0.0, "pos_w_p_w_fdbk[3]": 0.0,
                                                       "vel_w_p_b_fdbk[1]": 0.0, "vel_w_p_b_fdbk[2]": 0.0, "vel_w_p_b_fdbk[3]": 0.0,
                                                       "acc_w_p_b_fdbk[1]": 0.0, "acc_w_p_b_fdbk[2]": 0.0, "acc_w_p_b_fdbk[3]": 0.0,
                                                       "quat_wb_fdbk[1]": 0.0, "quat_wb_fdbk[2]": 0.0, "quat_wb_fdbk[3]": 0.0, "quat_wb_fdbk[4]": 0.0,
                                                       "euler_wb_fdbk[1]": 0.0, "euler_wb_fdbk[2]": 0.0, "euler_wb_fdbk[3]": 0.0,
                                                       "rate_wb_b_fdbk[1]": 0.0, "rate_wb_b_fdbk[2]": 0.0, "rate_wb_b_fdbk[3]": 0.0,
                                                       "rc_input[1]": 0.0, "rc_input[2]": 0.0, "rc_input[3]": 0.0, "rc_input[4]": 0.0,
                                                       "position_setpoint[1]": 0.0, "position_setpoint[2]": 0.0, "position_setpoint[3]": 0.0, "yaw_setpoint": 0.0})
                self.fmuctrl.step_time(t_last_ctrl, t_cur)
                t_last_ctrl = t_cur

            # propagate dynamics
            if itick%k_dyn == 0:
                self.fmudyn.set_input(t_cur+dt_dyn, {"pwm_rotor_cmd[1]": self.fmuctrl.get_output_value()['pwm_rotor_cmd[1]'], 
                                                     "pwm_rotor_cmd[2]": self.fmuctrl.get_output_value()['pwm_rotor_cmd[2]'], 
                                                     "pwm_rotor_cmd[3]": self.fmuctrl.get_output_value()['pwm_rotor_cmd[3]'], 
                                                     "pwm_rotor_cmd[4]": self.fmuctrl.get_output_value()['pwm_rotor_cmd[4]']})
                self.fmudyn.step_time(t_last_dyn, t_cur)
                t_last_dyn = t_cur

            # attack dynamics
            if self.attack_scenario == 1:  # [-] attack_scenario 1
                # add bias to velocity measurement
                if itick%k_opticalflow == 0:
                    self.optical_spoof_vector = np.array([np.random.normal(self.optical_flow_vel_bias, self.optical_flow_vel_variance),
                                                          np.random.normal(self.optical_flow_vel_bias, self.optical_flow_vel_variance),
                                                          0.0], dtype=np.float64)

            # save time history
            self.data['time'] = np.hstack([self.data['time'],t_cur])

            # # correct internal time clock - needed for considering the time mismatch (propagation time is not exact)
            # self.fweb.model.set(['timer_count'],[np.float64(t_cur/dt)])
            # self.fmudyn.model.set(['gyroatk.timer_count'],[np.float64(t_cur/dt)])

            # # check
            # print(np.float64(t_cur/dt))
            # print(self.fmudyn.variable[self.fmudyn.variableNames.index('timer_count')])
            # print(' -- ')

        # log the data
        self.data['missionplanner']['state'] = {'names': self.fmuplanner.stateNames,'values': np.empty((self.data['time'].shape[0],self.fmuplanner.data['state']['values'].shape[1]))}
        if self.fmuplanner.data['state']['values'].shape[1] != 0:
            for idx in range(self.fmuplanner.data['state']['values'].shape[1]):
                self.data['missionplanner']['state']['values'][:,idx] = np.interp(self.data['time'],self.fmuplanner.data['time'],self.fmuplanner.data['state']['values'][:,idx])
        self.data['missionplanner']['variable'] = {'names': self.fmuplanner.variableNames,'values': np.empty((self.data['time'].shape[0],self.fmuplanner.data['variable']['values'].shape[1]))}
        if self.fmuplanner.data['variable']['values'].shape[1] != 0:
            for idx in range(self.fmuplanner.data['variable']['values'].shape[1]):
                self.data['missionplanner']['variable']['values'][:,idx] = np.interp(self.data['time'],self.fmuplanner.data['time'],self.fmuplanner.data['variable']['values'][:,idx])

        self.data['joystick']['state'] = {'names': self.fmustick.stateNames,'values': np.empty((self.data['time'].shape[0],self.fmustick.data['state']['values'].shape[1]))}
        if self.fmustick.data['state']['values'].shape[1] != 0:
            for idx in range(self.fmustick.data['state']['values'].shape[1]):
                self.data['joystick']['state']['values'][:,idx] = np.interp(self.data['time'],self.fmustick.data['time'],self.fmustick.data['state']['values'][:,idx])
        self.data['joystick']['variable'] = {'names': self.fmustick.variableNames,'values': np.empty((self.data['time'].shape[0],self.fmustick.data['variable']['values'].shape[1]))}
        if self.fmustick.data['variable']['values'].shape[1] != 0:
            for idx in range(self.fmustick.data['variable']['values'].shape[1]):
                self.data['joystick']['variable']['values'][:,idx] = np.interp(self.data['time'],self.fmustick.data['time'],self.fmustick.data['variable']['values'][:,idx])
        
        self.data['controller']['state'] = {'names': self.fmuctrl.stateNames,'values': np.empty((self.data['time'].shape[0],self.fmuctrl.data['state']['values'].shape[1]))}
        if self.fmuctrl.data['state']['values'].shape[1] != 0:
            for idx in range(self.fmuctrl.data['state']['values'].shape[1]):
                self.data['controller']['state']['values'][:,idx] = np.interp(self.data['time'],self.fmuctrl.data['time'],self.fmuctrl.data['state']['values'][:,idx])
        self.data['controller']['variable'] = {'names': self.fmuctrl.variableNames,'values': np.empty((self.data['time'].shape[0],self.fmuctrl.data['variable']['values'].shape[1]))}
        if self.fmuctrl.data['variable']['values'].shape[1] != 0:
            for idx in range(self.fmuctrl.data['variable']['values'].shape[1]):
                self.data['controller']['variable']['values'][:,idx] = np.interp(self.data['time'],self.fmuctrl.data['time'],self.fmuctrl.data['variable']['values'][:,idx])

        self.data['quadrotor']['state'] = {'names': self.fmudyn.stateNames,'values': np.empty((self.data['time'].shape[0],self.fmudyn.data['state']['values'].shape[1]))}
        if self.fmudyn.data['state']['values'].shape[1] != 0:
            for idx in range(self.fmudyn.data['state']['values'].shape[1]):
                self.data['quadrotor']['state']['values'][:,idx] = np.interp(self.data['time'],self.fmudyn.data['time'],self.fmudyn.data['state']['values'][:,idx])
        self.data['quadrotor']['variable'] = {'names': self.fmudyn.variableNames,'values': np.empty((self.data['time'].shape[0],self.fmudyn.data['variable']['values'].shape[1]))}
        if self.fmudyn.data['variable']['values'].shape[1] != 0:
            for idx in range(self.fmudyn.data['variable']['values'].shape[1]):
                self.data['quadrotor']['variable']['values'][:,idx] = np.interp(self.data['time'],self.fmudyn.data['time'],self.fmudyn.data['variable']['values'][:,idx])

        # return the simulation output
        save_data = pd.DataFrame(np.hstack((self.data['time'][:,np.newaxis], 
                                            self.data['missionplanner']['state']['values'], self.data['missionplanner']['variable']['values'],
                                            self.data['joystick']['state']['values'], self.data['joystick']['variable']['values'],
                                            self.data['controller']['state']['values'], self.data['controller']['variable']['values'],
                                            self.data['quadrotor']['state']['values'], self.data['quadrotor']['variable']['values'])), 
                                columns=np.hstack((['time'], 
                                                   self.data['missionplanner']['state']['names'], self.data['missionplanner']['variable']['names'],
                                                   self.data['joystick']['state']['names'], self.data['joystick']['variable']['names'],
                                                   self.data['controller']['state']['names'], self.data['controller']['variable']['names'], 
                                                   self.data['quadrotor']['state']['names'], self.data['quadrotor']['variable']['names'])))

        return save_data

    def sim_reset(self):
        """
        reset the simulation model
        inputs :
        outputs :
        """
        self.fmuplanner.empty_data()
        self.fmuplanner.reset()

        self.fmustick.empty_data()
        self.fmustick.reset()

        self.fmudyn.empty_data()
        self.fmudyn.reset()

        self.fmuctrl.empty_data()
        self.fmuctrl.reset() 

        # initialize data log
        self.data = {'time': np.zeros((0,)), 'missionplanner': {}, 'joystick': {}, 'controller': {}, 'quadrotor': {}}

        # randomly change attack parameters
        if self.attack_scenario == 1:
            pass

# class MFRoverOnlySIM:
#     """
#     simulation classes for a multi-fidelity rover model, supports:
#     - rover-only simulation (input: throttle PWM duty cycle, )
#     - set input variables to inputs at given time instances
#     - be careful for
#     - retrieve the final value of all state variables
#     """


def _gcd_dt(dts, quantum=1e-6):
    """
    compute a robust gcd time step for floating periods
    - 'quantum' is the rounding quantum (e.g., 1e-6s = 1us)
    """
    us = [max(1, int(round(dt/quantum))) for dt in dts]  # [-] convert to integer ticks
    g = us[0]
    for u in us[1:]:
        g = gcd(g, u)
    return g*quantum