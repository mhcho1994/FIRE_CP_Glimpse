# load packages
import numpy as np
import pyfmi
import logging 
import os

# log = logging.getLogger(__name__)

class FMU: 
    """
    use pyfmi to run a fmu in a way that allows us external coarse control over simulation time
    - propagate time step of a FMU
    - set input variables to inputs at given time instances
    - set parameter variables
    - retrieve the final value of all state variables
    """
    def __init__(self, file, fmutype, t0, tol=1e-10):
        """
        initialize class
        inputs:
            name (str): model name in the Modelica file.
            filename (str): path to the Modelica file.
            parameters (dict): dictionary of parameters to update before FMU generation.
        outputs:
            str: path to the generated FMU.
        """
        os.environ["LD_LIBRARY_PATH"] = "/usr/lib/x86_64-linux-gnu:" + os.environ.get("LD_LIBRARY_PATH","")
        self.model = pyfmi.load_fmu(file, kind = fmutype)
        self.model.initialize(start_time = 0.0)

        self.t = t0
        self.t0 = t0
        self.stateNames = list(self.model.get_states_list().keys())
        self.inputNames = list(self.model.get_input_list().keys())
        self.outputNames = list(self.model.get_output_list().keys())
        self.variableNames = list(self.model.get_model_variables().keys())
        
        self.state = np.zeros((len(self.stateNames),))
        self.input = np.zeros((len(self.inputNames),))
        self.timedinput = np.hstack([np.zeros((0,1)), np.zeros((0,len(self.inputNames)))])
        self.output = np.zeros((len(self.outputNames),))
        self.variable = np.zeros((len(self.variableNames),))
        self.data = {'time': np.empty((0,)), 
                     'input': {'names': [],'values': np.empty((0, self.input.size))},
                     'state': {'names': [],'values': np.empty((0, self.state.size))}, 
                     'variable': {'names': [],'values': np.empty((0, self.variable.size))},
                     'output': {'names': [],'values': np.empty((0, self.output.size))}}
        # self.data['time'] = np.hstack((self.data['time'],self.t0))
        self.data['input']['names'] = self.inputNames
        self.data['state']['names'] = self.stateNames
        self.data['variable']['names'] = self.variableNames
        self.data['output']['names'] = self.outputNames

        self.opts = self.model.simulate_options()
        self.opts['solver'] = 'CVode'                                       # solver option: CVode only
        self.opts['result_handling'] = 'memory'                             # avoids writing result files
        self.opts['result_store_variable_description'] = False
        self.opts['ncp'] = 10

        if self.opts['solver'] =='CVode':
            self.opts["CVode_options"]["atol"] = tol                        # absolute tolerance of solver
            self.opts["CVode_options"]["rtol"] = tol                        # relative tolerance of solver
            self.opts["CVode_options"]['discr'] = "BDF"                     # discretization method, BDF or Adams
            self.opts["CVode_options"]["maxord"] = 5                        # maximal order of the solver, reduce from 12 to 5

    def get_inputs(self):
        """
        return the names of all the inputs in the fmu 
        """
        return self.inputNames
    
    def get_states(self):
        """
        return the names of all the states in the fmu 
        """
        return self.stateNames 
    
    def get_states(self):
        """
        return the names of all the variables in the fmu 
        """
        return self.variableNames 
    
    def get_outputs(self):
        """
        return the names of all the outputs in the fmu 
        """
        return self.outputNames 

    def stop(self):
        """
        do nothing for fmu integration in FSM
        """
        pass

    def reset(self):
        """
        reset the fmu, time back to t0, clears the state, inputs, and outputs
        """
        # reset the fmu simulation 
        self.model.reset() 

        # set t to initial value 
        self.t = self.t0

        # make an empty input data frame 
        self.input = np.zeros((len(self.inputNames),))
        self.timedinput = np.hstack([np.zeros((0,1)), np.zeros((0,len(self.inputNames)))])

    def step_time(self, t0, tf):
        """
        propagate time steps of FMUs from t0 to tf. 
        """
        # input tuple object format: 
        # ([variable name list], np.array([[t0,v0,...vn], ... [tm,v0,...,vn]]))
        if self.input.shape[0] == 0:
            result = self.model.simulate(start_time=0, final_time=tf-t0, options=self.opts)
        else:
            varList = self.inputNames
            inputTuple = (varList, self.timedinput)
            result = self.model.simulate(start_time=0, final_time=tf-t0, options=self.opts, input=inputTuple)

        # save the propagation results
        self.state = np.array(self.model.get(self.stateNames)).flatten()
        self.variable = np.array(self.model.get(self.variableNames)).flatten()
        self.output = np.array(self.model.get(self.outputNames)).flatten()

        # log the propagation results
        self.data['time'] = np.hstack((self.data['time'], tf))
        self.data['input']['values'] = np.vstack((self.data['input']['values'], self.input))       # piece-wise constant input (zero-order hold)
        self.data['state']['values'] = np.vstack((self.data['state']['values'], self.state))
        self.data['variable']['values'] = np.vstack((self.data['variable']['values'], self.variable))
        self.data['output']['values'] = np.vstack((self.data['output']['values'], self.output))

        # reset model
        self.reset()
        self.model.set(self.stateNames, self.state)
        self.model.set(self.variableNames, self.variable)
        
        # advance the time
        self.t = tf 

    def set_input(self, t, inputDict):
        """
        set the value of one or more inputs at a specific time by assuming zero-order hold
        e.g., self.set_input(1.23, {"D": 0.5, "delta_cmd":1/180*npi.pi}) 
        at time=1.22, throttle D=0.5, steering delta_cmd=1 from t=1.22 to t=1.23 seconds
        """
        # check whether your input is suitable 
        if isinstance(t, np.ndarray):
            cmd_raw = [np.array(inputDict[key]) for key in self.inputNames]
        elif isinstance(t, list):
            t = np.array(t)
            cmd_raw = [np.array(inputDict[key]) for key in self.inputNames]
        else:
            t = np.array([t])
            cmd_raw = [np.array([inputDict[key]]) for key in self.inputNames]

        # sort the command in ascending order
        cmd_raw = [np.array([cmd_raw[j][i] for i in np.argsort(t)]) for j in range(len(cmd_raw))]
        t = np.sort(t)

        for idx in range(t.size):
            if (t[idx] > self.t):
                self.timedinput = np.vstack((self.timedinput, np.hstack((self.t0, np.zeros((len(self.inputNames)))))))
                self.timedinput = np.vstack((self.timedinput, np.hstack((t[idx]-self.t, np.zeros((len(self.inputNames)))))))
                for sub_idx in range(len(self.inputNames)):
                    self.timedinput[0,sub_idx+1] = cmd_raw[sub_idx][idx]
                    self.timedinput[1,sub_idx+1] = cmd_raw[sub_idx][idx]
                    self.input[sub_idx] =  cmd_raw[sub_idx][idx]
                break

    def set_param(self, paramDict):
        """
        set a parameter input in the FMU to be a certain value 
        """
        for key,val in paramDict.items():
            # log.info(f"Setting parameter {key}={val}")
            self.model.set(key,val)

    def get_param(self, paramKey):
        """
        get a parameter value in the FMU 
        """
        return self.model.get(paramKey)
        
    def get_state_value(self):
        """
        return the final value from the last time step of all states in the FMU 
        """
        # return all the last states as a dict 
        return {self.stateNames[k]: self.state[k] for k in range(0,len(self.stateNames))}
    
    def get_variable_value(self):
        """
        return the final value from the last time step of all variables in the FMU 
        """
        # return all the last variables as a dict 
        return {self.variableNames[k]: self.variable[k] for k in range(0,len(self.variableNames))}

    def get_output_value(self):
        """
        return the final value from the last time step of all outputs in the FMU 
        """
        # return all the last outputs as a dict 
        return {self.outputNames[k]: self.output[k] for k in range(0,len(self.outputNames))}
    
    def empty_data(self):
        # initialize data
        self.data = {'time': np.empty((0,)), 
                     'input': {'names': [],'values': np.empty((0, self.input.size))},
                     'state': {'names': [],'values': np.empty((0, self.state.size))}, 
                     'variable': {'names': [],'values': np.empty((0, self.variable.size))},
                     'output': {'names': [],'values': np.empty((0, self.output.size))}}
        # self.data['time'] = np.hstack((self.data['time'],self.t0))
        self.data['input']['names'] = self.inputNames
        self.data['state']['names'] = self.stateNames
        self.data['variable']['names'] = self.variableNames
        self.data['output']['names'] = self.outputNames