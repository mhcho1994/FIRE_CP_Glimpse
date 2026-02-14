# load packages
import fmu
import modelica 
import logging 
import numpy as np 
import os 
import matplotlib.pyplot as plt

log = logging.getLogger(__name__)

"""
example of a closed loop simulation using FMUs generated from Modelica (component) models
inputs:
   fidelity: fidelity level
   1: low-fidelity model
   2: high-fidelity model
outputs:

notes:
   this script is only valid for simulating autonomous systems (time invariant dynamics)
   do not use if the system model has time-dependent elements 
   if you have time-dependent elements in the model, please covert them into time-dependent variables

to do:
   1: change 'fidelity' parameter type (make it not to be 'final', modify modelica script)
   2: make 'final run statistics' silent (to decrease running time)
"""

# simulation time setup
dt = 0.1                                  # [sec] simulation time step
t0 = 0                                    # [sec] start time
tf = 20                                   # [sec] final time

# simulation fidelity level setup
fidelity = 1                              # [-] fidelity level
fmutype = "me"                            # [-] fmu type (cs: co-simulation, me: model-exchange)

# convert the modelica file into a fmu and set the ininital conditions and parameters 
if fidelity == 1:
   fmuDyn = "RoverExample.Components.Rover/RoverExample.Components.Rover.fmu"
   # enable when you want to generate or update the FMU (e.g. Lo-Fi -> Hi-Fi)
   # modelica.generate_fmu("RoverExample.Components.Rover", f"{os.getcwd()}/model/MFRover_FMUgen.mo", fmutype, {'fidelity': 1}) 
   fmudyn = fmu.FMU(fmuDyn, fmutype, t0, tol=1e-6)
   fmudyn.reset()
   fmudyn.set_param({'rover_3d.x': 0.0 , 'rover_3d.y': 0.0, 'rover_3d.z': 0.0, # location
      'rover_3d.vx': 0.0, 'rover_3d.vy': 0.0, "rover_3d.vz": 0.0, # body fixed velocity
      'rover_3d.psi': np.pi/2, 'rover_3d.theta':0.0 , 'rover_3d.phi': 0.0, # intrinsic rotation sequence in order
      'rover_3d.p': 0.0, 'rover_3d.q': 0.0, 'rover_3d.r': 0.0}) # rotation rates about x,y,z

elif fidelity == 2:
   fmuDyn = "RoverExample.Components.Rover/RoverExample.Components.Rover.fmu"
   # enable when you want to generate or update the FMU (e.g. Hi-Fi -> Lo-Fi)
   # important note: currently, the fidelity parameter is automatically set as a "final" parameter, which cannot be modified using Python API
   #                 please change it manually in the RoverExample.Components.Rover script (be careful that the fidelity parameter is also in RoverExample.ExampleScenario)
   # modelica.generate_fmu("RoverExample.Components.Rover", f"{os.getcwd()}/model/MFRover_FMUgen.mo", fmutype, {'fidelity': 2}) 
   fmudyn = fmu.FMU(fmuDyn, fmutype, t0, tol=1e-6)
   fmudyn.reset()
   fmudyn.set_param({'rover_8d.x': 0.0 , 'rover_8d.y': 0.0, 'rover_8d.z': 0.0, # location
      'rover_8d.vx': 0.0, 'rover_8d.vy': 0.0, "rover_8d.vz": 0.0, # body fixed velocity
      'rover_8d.psi': np.pi/2, 'rover_8d.theta':0.0 , 'rover_8d.phi': 0.0, # intrinsic rotation sequence in order
      'rover_8d.p': 0.0, 'rover_8d.q': 0.0, 'rover_8d.r': 0.0, # rotation rates about x,y,z
      'rover_8d.omega_fl': 0.0, 'rover_8d.omega_fr': 0.0, 'rover_8d.omega_rl': 0.0, 'rover_8d.omega_rr': 0.0, # wheel rotational speeds
      'rover_8d.omega': 0.0}) # shaft rotational speeds

fmuController = "RoverExample.Components.Controller/RoverExample.Components.Controller.fmu" 
# enable when you want to generate or update the FMU
# modelica.generate_fmu("RoverExample.Components.Controller", f"{os.getcwd()}/model/MFRover_FMUgen.mo", fmutype)
fctrl = fmu.FMU(fmuController, fmutype, t0, tol=1e-6)
fctrl.reset() 
fctrl.set_param({'s': 0 , 'x_ref': 0.0, 'y_ref': 0.0, 'psi_ref': 0.0, 'v': 0.0, 'delta': 0.0}) # state of Lo-Fi FSM controller

fmuWebserver = "RoverExample.Components.Webserver/RoverExample.Components.Webserver.fmu"
# enable when you want to generate or update the FMU
# modelica.generate_fmu("RoverExample.Components.Webserver", f"{os.getcwd()}/model/MFRover_FMUgen.mo", fmutype)
fweb = fmu.FMU(fmuWebserver, fmutype, t0, tol=1e-6)
fweb.reset() 

# closed loop simulation by calling all components
data = {'t': np.linspace(t0, tf, int((tf-t0)/dt)+1), 'webserver': {}, 'controller': {}, 'rover': {}}

for t_cur in data['t']:

   # get webserver turn command
   fweb.step_time(t_cur, t_cur+dt)

   # set turn command for controller
   # note: turn command is an integer input for controller; however, in FMU generation, it is not given as a parameter of the model
   #       'model.set' can be used to change the parameter 'turn' in the controller
   fctrl.model.set('turn', fweb.get_output_value()['turn'])
   if attack_scenario == 1:
      fctrl.set_input(t_cur+dt, {"psi": fmudyn.get_output_value()['psi_meas']+(emi_dist_level)*(2*(np.random.rand(1)-0.5)), "x": fmudyn.get_output_value()['x_meas'], "y": fmudyn.get_output_value()['y_meas']})
   else:
      fctrl.set_input(t_cur+dt, {"psi": fmudyn.get_output_value()['psi_meas'], "x": fmudyn.get_output_value()['x_meas'], "y": fmudyn.get_output_value()['y_meas']})
   fctrl.step_time(t_cur, t_cur+dt)

   # set pwm command for chassis dynamic model
   if attack_scenario == 2:
      fmudyn.set_input(t_cur+dt, {"pwm_steering": fctrl.get_output_value()['pwm_steering'], "pwm_throttle": np.int32(rollover_thr_pwm)})
   else:
      fmudyn.set_input(t_cur+dt, {"pwm_steering": fctrl.get_output_value()['pwm_steering'], "pwm_throttle": fctrl.get_output_value()['pwm_throttle']})
   fmudyn.step_time(t_cur, t_cur+dt)

# log the data
data['webserver'] = fweb.data
data['controller'] = fctrl.data
data['rover'] = fmudyn.data

# plotting
# 1 - 2D trajectory
plt.figure()
plt.plot(data['rover']['output']['values'][:,13], data['rover']['output']['values'][:,14], label = 'planar trajectory')
plt.grid()
plt.legend()
plt.xlabel('x [m]')
plt.ylabel('y [m]')
plt.title('2-d trajectory of rover')

# 2 - velocity profile
plt.figure()
plt.plot(data['t'], fmudyn.data['output']['values'][:,10], label = 'x-velocity')
plt.plot(data['t'], fmudyn.data['output']['values'][:,11], label = 'y-velocity')
plt.grid()
plt.legend()
plt.xlabel('time [sec]')
plt.ylabel('velocity [m/s]')
plt.title('velocity history')

# 3 - acceleration profile
plt.figure()
plt.plot(data['t'], fmudyn.data['output']['values'][:,0], label = 'x-acceleration')
plt.plot(data['t'], fmudyn.data['output']['values'][:,1], label = 'y-acceleration')
plt.grid()
plt.legend()
plt.xlabel('time [sec]')
plt.ylabel('acc [m/s^2]')
plt.title('acceleration history')

# 4 - roll profile
plt.figure()
plt.plot(data['t'],fmudyn.data['output']['values'][:,4]/np.pi*180, label = 'roll angle')
plt.plot(data['t'],fmudyn.data['output']['values'][:,3]/np.pi*180, label = 'roll rate')
plt.plot(data['t'],fmudyn.data['output']['values'][:,8], label = 'rollover signal')
plt.grid()
plt.legend()
plt.xlabel('time [sec]')
plt.ylabel('angle/rate [deg, deg/s], rollover')
plt.title('roll (rollover) history')

# 5 - yaw profile
plt.figure()
plt.plot(data['t'],fmudyn.data['output']['values'][:,5]/np.pi*180, label = 'heading')
plt.plot(data['t'],fmudyn.data['output']['values'][:,7]/np.pi*180, label = 'yaw rate')
plt.grid()
plt.legend()
plt.xlabel('time [sec]')
plt.ylabel('angle/rate [deg, deg/s]')
plt.title('yaw history')

plt.show()
