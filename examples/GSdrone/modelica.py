# load packages
from OMPython import OMCSessionZMQ
from OMPython import ModelicaSystem
import logging 
import time 
import shutil
import os
import logging

# save log
log = logging.getLogger( __name__ )

# fmu generation function
def generate_fmu(name, filename, fmutype, parameter = {}): 
    """
    translate  modelica .mo file to a model exchange fmu
    inputs:
        name (str): model name in the Modelica file.
        filename (str): path to the Modelica file.
        parameters (dict): dictionary of parameters to update before FMU generation.
    outputs:
        str: path to the generated FMU.
    """
    # load model and modify parameters
    model = ModelicaSystem(filename, name)

    # setParameters() - failed
    # if len(parameter) > 0:
    #     mods = ",".join(f"{k}={v}" for k, v in parameter.items())
    #     model.setParameters(mods)

    # rebuild model using buildModel() API - failed
    # omc = OMCSessionZMQ()
    # omc.sendExpression(f'loadFile("{filename}")')
    # omc.sendExpression("instantiateModel(RoverExample.Components)")
    # set parameters using sendExpression before build
    # for param, value in parameters.items():
        #  result = omc.sendExpression(
            #  f'setParameterValue({model_name}, {param}, {value})',
            #  parsed=False
        #  )
        #  print(f"[DEBUG] Set {param} = {value}: {result}")

    # manually change the parameter
    # with open("OriginalModel.mo", "r") as f:
    #     model_code = f.read()

    #     # Remove all occurrences of 'final parameter' with 'parameter'
    #     model_code = model_code.replace("final parameter", "parameter")

    # with open("MyEditableModel.mo", "w") as f:
    #     f.write(model_code)

    fmu_gen = model.convertMo2Fmu(fileNamePrefix = name, fmuType = fmutype)
    log.info(f"FMU created at {fmu_gen}")
    destination = os.path.join(os.getcwd(), f"{name}")

    if not os.path.exists(destination):
        os.makedirs(destination)

    for file_name in os.listdir(destination):
        file_path = os.path.join(destination, file_name)
        if os.path.isfile(file_path):
            os.remove(file_path)
    shutil.copytree(os.path.dirname(fmu_gen), destination, dirs_exist_ok=True)
    # log.info(f"FMU moved to {destination}")
    f = f"{destination+"/"+os.path.basename(fmu_gen)}"

    return f
