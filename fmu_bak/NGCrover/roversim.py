# load packages
import fmu
import modelica 
import logging 
import numpy as np 
import os 
import pandas as pd
import json
import utils

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

class MFRoverClosedSIM:
    """
    simulation classes for a multi-fidelity rover model, supports:
    - rover-only simulation (input: throttle PWM duty cycle, )
    - set input variables to inputs at given time instances
    - be careful for
    - retrieve the final value of all state variables
    """
    def __init__(self, fidelity = 1, t0 = 0, fmu_type = "me", attack_scenario = 0, parameter_file = "rover_parameters.json"):
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
        fmu_gen = True

        # t0 should be 0
        self.t0 = t0
        
        # save fidelity level
        self.fidelity = fidelity

        # read specification file (.json format)
        with open(parameter_file, 'r') as file:
            self.parameters_info = json.load(file)

        # enable when you want to generate or update the FMU (e.g. Lo-Fi -> Hi-Fi, Hi-Fi -> Lo-Fi)
        # convert the modelica file into a fmu and set the ininital conditions and parameters 
        if fmu_gen:
            if fidelity == 1:
                modelica.generate_fmu("RoverExample.Components.Rover", f"{os.getcwd()}/model/MFRover.mo", fmu_type, {'fidelity': 1}) 
            elif fidelity == 2:
                modelica.generate_fmu("RoverExample.Components.Rover", f"{os.getcwd()}/model/MFRover.mo", fmu_type, {'fidelity': 2})

        fmuDyn = "RoverExample.Components.Rover/RoverExample.Components.Rover.fmu"
        self.fmudyn = fmu.FMU(fmuDyn, fmu_type, self.t0, tol=1e-6)
        # get parameter information before reset
        if self.fidelity == 1:
            self.parameters_info['l_total'] = self.fmudyn.get_param('rover_3d.l_total')
        elif self.fidelity == 2:
            self.parameters_info['l_total'] = self.fmudyn.get_param('rover_8d.l_total')
        self.fmudyn.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fmudyn.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fmudyn.model.initialize()
        if self.fidelity == 1:
            self.fmudyn.set_param({'rover_3d.x': 0.0 , 'rover_3d.y': 0.0, 'rover_3d.z': 0.0, # location
                                   'rover_3d.vx': 0.0, 'rover_3d.vy': 0.0, "rover_3d.vz": 0.0, # body fixed velocity
                                   'rover_3d.psi': self.parameters_info['heading']/180*np.pi, 'rover_3d.theta':0.0 , 'rover_3d.phi': 0.0, # intrinsic rotation sequence in order
                                   'rover_3d.p': 0.0, 'rover_3d.q': 0.0, 'rover_3d.r': 0.0}) # rotation rates about x,y,z
        elif self.fidelity == 2:
            self.fmudyn.set_param({'rover_8d.x': 0.0 , 'rover_8d.y': 0.0, 'rover_8d.z': 0.0, # location
                                   'rover_8d.vx': 0.0, 'rover_8d.vy': 0.0, "rover_8d.vz": 0.0, # body fixed velocity
                                   'rover_8d.psi': self.parameters_info['heading']/180*np.pi, 'rover_8d.theta':0.0 , 'rover_8d.phi': 0.0, # intrinsic rotation sequence in order
                                   'rover_8d.p': 0.0, 'rover_8d.q': 0.0, 'rover_8d.r': 0.0, # rotation rates about x,y,z
                                   'rover_8d.omega_fl': 0.0, 'rover_8d.omega_fr': 0.0, 'rover_8d.omega_rl': 0.0, 'rover_8d.omega_rr': 0.0, # wheel rotational speeds
                                   'rover_8d.omega': 0.0}) # shaft rotational speeds

        if fmu_gen:
            modelica.generate_fmu("RoverExample.Components.Controller", f"{os.getcwd()}/model/MFRover.mo", fmu_type)
        fmuController = "RoverExample.Components.Controller/RoverExample.Components.Controller.fmu" 
        self.fctrl = fmu.FMU(fmuController, fmu_type, self.t0, tol=1e-6)
        self.fctrl.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fctrl.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fctrl.model.initialize()
        ic_quat = utils.eul2quat(np.array([0.0,0.0,self.parameters_info['heading']/180*np.pi]))
        self.fctrl.set_param({'s': 0 , # state of Lo-Fi FSM controller
                              'x_ref': 0.0, 'y_ref': 0.0, 'psi_ref': 0.0, # reference for turn logic
                              'v': 0.0, 'delta': 0.0, # commands
                              'quaternion_filtered[1]': ic_quat[0], 'quaternion_filtered[2]': ic_quat[1], 'quaternion_filtered[3]': ic_quat[2], 'quaternion_filtered[4]': ic_quat[3]})
        if self.fidelity == 1:
            self.fctrl.set_param({'delta_turn': np.atan(self.parameters_info['l_total']/self.parameters_info['turn_radius'])})
        elif self.fidelity == 2:
            self.fctrl.set_param({'delta_turn': np.atan(self.parameters_info['l_total']/self.parameters_info['turn_radius'])})

        if fmu_gen:
            modelica.generate_fmu("RoverExample.Components.Webserver", f"{os.getcwd()}/model/MFRover.mo", fmu_type)
        fmuWebserver = "RoverExample.Components.Webserver/RoverExample.Components.Webserver.fmu"
        self.fweb = fmu.FMU(fmuWebserver, fmu_type, self.t0, tol=1e-6)
        self.fweb.reset() 
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fweb.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fweb.model.initialize()

        # closed loop simulation by calling all components
        self.data = {'t': np.zeros((0,)), 'webserver': {}, 'controller': {}, 'rover': {}}

        # set up the attack model
        self.attack_scenario = attack_scenario
        if self.attack_scenario == 1:        # [-] attack_scneario: 0 = no attack, 1 = emi attack, 2 = rollover attack, 3 = gyro attack
            self.emi_atk_level = self.parameters_info['emi_disturbance']/180*np.pi
            self.bias = 2*(np.random.rand(1)-0.5)
        elif self.attack_scenario == 2:
            self.rollover_thr_pwm = self.parameters_info['throttle_pwm_level']
        elif self.attack_scenario == 3:
            self.gyro_atk_power = self.parameters_info['acoustic_power']
            self.speaker_dist = self.parameters_info['speaker_dist']
            self.gyro_atk_freq = (self.parameters_info['drive_freq']+self.parameters_info['acoustic_freq_range']*(2*np.random.rand(1)-1))*(2*np.pi)
            self.gyro_misalignment = self.parameters_info['gyro_misalignment']*np.random.rand(1)*(np.pi/180)
            self.gyro_atk_dir = np.random.rand(1)*(np.pi/2)
            self.gyro_atk_phase = np.random.rand(1)*2*np.pi-np.pi
        elif self.attack_scenario == 4:
            if self.parameters_info['wire_dir'] == 1:
                self.wire_dir = np.array([1, 0, 0])
            elif self.parameters_info['wire_dir'] == 2:
                self.wire_dir = np.array([-1, 0, 0])
            elif self.parameters_info['wire_dir'] == 3:
                self.wire_dir = np.array([0, 1, 0])
            elif self.parameters_info['wire_dir'] == 4:
                self.wire_dir = np.array([0, -1, 0])
            elif self.parameters_info['wire_dir'] == 5:
                self.wire_dir = np.array([0, 0, 1])
            else:
                self.wire_dir = np.array([0, 0, -1])
            self.wire_dist = np.array([0, 0, -self.parameters_info['wire_relative_dist']])

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

            # get webserver turn command
            self.fweb.set_param({'sample_interval': dt+1e-6})  # avoid unnecessary update at t = dt, make update happen only at t=0
            self.fweb.step_time(t_cur, t_cur+dt)
            
            # set turn command for controller
            # note: turn command is an integer input for controller; however, in FMU generation, it is not given as a parameter of the model
            #       'model.set' can be used to change the parameter 'turn' in the controller
            self.fctrl.model.set('turn', self.fweb.get_output_value()['turn'])
            if self.attack_scenario == 1 and self.fctrl.get_variable_value()['s'] >= 3.0:               # right turn command given + right turn mode check, initiate attack when rover is turning  
                self.fctrl.set_input(t_cur+dt, {"ax_acc": self.fmudyn.get_output_value()['ax_meas'],
                                                "ay_acc": self.fmudyn.get_output_value()['ay_meas'],
                                                "az_acc": self.fmudyn.get_output_value()['az_meas'],
                                                "mx_mag": self.fmudyn.get_output_value()['mx_meas'],
                                                "my_mag": self.fmudyn.get_output_value()['my_meas'],
                                                "mz_mag": self.fmudyn.get_output_value()['mz_meas'],
                                                "phi_gyro": self.fmudyn.get_output_value()['phi_meas'],
                                                "theta_gyro": self.fmudyn.get_output_value()['theta_meas'],
                                                "psi_gyro": self.fmudyn.get_output_value()['psi_meas']+(self.emi_atk_level)*(self.bias), 
                                                "p_gyro": self.fmudyn.get_output_value()['p_meas'], 
                                                "q_gyro": self.fmudyn.get_output_value()['q_meas'], 
                                                "r_gyro": self.fmudyn.get_output_value()['r_meas'], 
                                                "x": self.fmudyn.get_output_value()['x_meas'], 
                                                "y": self.fmudyn.get_output_value()['y_meas']})
            else:
                self.fctrl.set_input(t_cur+dt, {"ax_acc": self.fmudyn.get_output_value()['ax_meas'],
                                                "ay_acc": self.fmudyn.get_output_value()['ay_meas'],
                                                "az_acc": self.fmudyn.get_output_value()['az_meas'],
                                                "mx_mag": self.fmudyn.get_output_value()['mx_meas'],
                                                "my_mag": self.fmudyn.get_output_value()['my_meas'],
                                                "mz_mag": self.fmudyn.get_output_value()['mz_meas'],
                                                "phi_gyro": self.fmudyn.get_output_value()['phi_meas'],
                                                "theta_gyro": self.fmudyn.get_output_value()['theta_meas'],
                                                "psi_gyro": self.fmudyn.get_output_value()['psi_meas'], 
                                                "p_gyro": self.fmudyn.get_output_value()['p_meas'], 
                                                "q_gyro": self.fmudyn.get_output_value()['q_meas'], 
                                                "r_gyro": self.fmudyn.get_output_value()['r_meas'], 
                                                "x": self.fmudyn.get_output_value()['x_meas'], 
                                                "y": self.fmudyn.get_output_value()['y_meas']})
            self.fctrl.set_param({'sample_interval': dt+1e-6})  # avoid unnecessary update at t = dt, make update happen only at t=0
            self.fctrl.step_time(t_cur, t_cur+dt)

            # set pwm command for chassis dynamic model
            if self.attack_scenario == 2:
                self.fmudyn.set_input(t_cur+dt, {"pwm_steering": self.fctrl.get_output_value()['pwm_steering'], 
                                                 "pwm_throttle": np.int32(self.rollover_thr_pwm)})
            else:
                self.fmudyn.set_input(t_cur+dt, {"pwm_steering": self.fctrl.get_output_value()['pwm_steering'], 
                                                 "pwm_throttle": self.fctrl.get_output_value()['pwm_throttle']})

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
                
            if self.attack_scenario == 4:
                self.fmudyn.set_param({'rover_8d.emi.wire_dir[1]': self.wire_dir[0],
                                       'rover_8d.emi.wire_dir[2]': self.wire_dir[1],
                                       'rover_8d.emi.wire_dir[3]': self.wire_dir[2],
                                       'rover_8d.emi.x_wire[1]': self.wire_dist[0],
                                       'rover_8d.emi.x_wire[2]': self.wire_dist[1],
                                       'rover_8d.emi.x_wire[3]': self.wire_dist[2]})
            else:
                self.fmudyn.set_param({'rover_8d.emi.wire_dir[1]': 0,
                                       'rover_8d.emi.wire_dir[2]': 0,
                                       'rover_8d.emi.wire_dir[3]': 1,
                                       'rover_8d.emi.x_wire[1]': 0,
                                       'rover_8d.emi.x_wire[2]': 0,
                                       'rover_8d.emi.x_wire[3]': -0.01})
            self.fmudyn.set_param({'sample_interval': dt+1e-6})  # avoid unnecessary update at t = dt, make update happen only at t=0
            self.fmudyn.step_time(t_cur, t_cur+dt)

            # correct internal time clock
            self.fweb.model.set(['timer_count'],[np.float64(t_cur/dt)])
            self.fmudyn.model.set(['gyroatk.timer_count'],[np.float64(t_cur/dt)])

            # check
            # print(np.float64(t_cur/dt))
            # print(self.fmudyn.variable[self.fmudyn.variableNames.index('timer_count')])
            # print(' -- ')

        # log the data
        self.data['webserver'] = self.fweb.data
        self.data['controller'] = self.fctrl.data
        self.data['rover'] = self.fmudyn.data

        # return the simulation output
        save_data = pd.DataFrame(np.hstack((self.data['t'][:,np.newaxis], 
                                            self.data['rover']['state']['values'], self.data['rover']['variable']['values'], 
                                            self.data['controller']['state']['values'], self.data['controller']['variable']['values'], 
                                            self.data['webserver']['state']['values'], self.data['webserver']['variable']['values'])), 
                                columns=np.hstack((['time'], self.data['rover']['state']['names'], self.data['rover']['variable']['names'],
                                                   self.data['controller']['state']['names'], self.data['controller']['variable']['names'], 
                                                   self.data['webserver']['state']['names'], self.data['webserver']['variable']['names'])))

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
        if self.fidelity == 1:
            self.fmudyn.set_param({'rover_3d.x': 0.0 , 'rover_3d.y': 0.0, 'rover_3d.z': 0.0, # location
                                   'rover_3d.vx': 0.0, 'rover_3d.vy': 0.0, "rover_3d.vz": 0.0, # body fixed velocity
                                   'rover_3d.psi': self.parameters_info['heading']/180*np.pi, 'rover_3d.theta':0.0 , 'rover_3d.phi': 0.0, # intrinsic rotation sequence in order
                                   'rover_3d.p': 0.0, 'rover_3d.q': 0.0, 'rover_3d.r': 0.0}) # rotation rates about x,y,z
        elif self.fidelity == 2:
            self.fmudyn.set_param({'rover_8d.x': 0.0 , 'rover_8d.y': 0.0, 'rover_8d.z': 0.0, # location
                                   'rover_8d.vx': 0.0, 'rover_8d.vy': 0.0, "rover_8d.vz": 0.0, # body fixed velocity
                                   'rover_8d.psi': self.parameters_info['heading']/180*np.pi, 'rover_8d.theta':0.0 , 'rover_8d.phi': 0.0, # intrinsic rotation sequence in order
                                   'rover_8d.p': 0.0, 'rover_8d.q': 0.0, 'rover_8d.r': 0.0, # rotation rates about x,y,z
                                   'rover_8d.omega_fl': 0.0, 'rover_8d.omega_fr': 0.0, 'rover_8d.omega_rl': 0.0, 'rover_8d.omega_rr': 0.0, # wheel rotational speeds
                                   'rover_8d.omega': 0.0}) # shaft rotational speeds

        self.fctrl.empty_data()
        self.fctrl.reset() 
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fctrl.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fctrl.model.initialize()
        ic_quat = utils.eul2quat(np.array([0.0,0.0,self.parameters_info['heading']/180*np.pi]))
        self.fctrl.set_param({'s': 0 , # state of Lo-Fi FSM controller
                              'x_ref': 0.0, 'y_ref': 0.0, 'psi_ref': 0.0, # reference for turn logic
                              'v': 0.0, 'delta': 0.0, # commands
                              'quaternion_filtered[1]': ic_quat[0], 'quaternion_filtered[2]': ic_quat[1], 'quaternion_filtered[3]': ic_quat[2], 'quaternion_filtered[4]': ic_quat[3]}) 
        self.fctrl.set_param({'sample_interval': 0.1+0.00001})
        if self.fidelity == 1:
            self.fctrl.set_param({'delta_turn': np.atan(self.parameters_info['l_total']/self.parameters_info['turn_radius'])})
        elif self.fidelity == 2:
            self.fctrl.set_param({'delta_turn': np.atan(self.parameters_info['l_total']/self.parameters_info['turn_radius'])})

        self.fweb.empty_data()
        self.fweb.reset()
        # do not use setup_experiment and initialize for ME (CS only)
        # self.fweb.model.setup_experiment(start_time=0.0, stop_time=1.0)
        # self.fweb.model.initialize()

        # initialize data log
        self.data = {'t': np.zeros((0,)), 'webserver': {}, 'controller': {}, 'rover': {}}

        # randomly change attack parameters
        if self.attack_scenario == 1:
            self.bias = 2*(np.random.rand(1)-0.5)

        if self.attack_scenario == 3:
            self.gyro_atk_freq = (self.parameters_info['drive_freq']+self.parameters_info['acoustic_freq_range']*(2*np.random.rand(1)-1))*(2*np.pi)
            self.gyro_misalignment = self.parameters_info['gyro_misalignment']*np.random.rand(1)*(np.pi/180)
            self.gyro_atk_dir = np.random.rand(1)*(np.pi/2)
            self.gyro_atk_phase = np.random.rand(1)*2*np.pi-np.pi

# class MFRoverOnlySIM:
#     """
#     simulation classes for a multi-fidelity rover model, supports:
#     - rover-only simulation (input: throttle PWM duty cycle, )
#     - set input variables to inputs at given time instances
#     - be careful for
#     - retrieve the final value of all state variables
#     """