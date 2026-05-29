# load packages
import numpy as np 

def eul2quat(eul):

    # check the input type
    if eul.shape[0] != 3:
        raise ValueError('Check the input dimension')

    # initialize input/output
    phi     =   eul[0]
    theta	=   eul[1]
    psi   	=   eul[2]

    out   	=   np.zeros((4,))

    # compute the quaternion
    out[0] = np.cos(psi/2)*np.cos(theta/2)*np.cos(phi/2)+np.sin(psi/2)*np.sin(theta/2)*np.sin(phi/2)
    out[1] = np.cos(psi/2)*np.cos(theta/2)*np.sin(phi/2)-np.sin(psi/2)*np.sin(theta/2)*np.cos(phi/2)
    out[2] = np.cos(psi/2)*np.sin(theta/2)*np.cos(phi/2)+np.sin(psi/2)*np.cos(theta/2)*np.sin(phi/2)
    out[3] = np.sin(psi/2)*np.cos(theta/2)*np.cos(phi/2)-np.cos(psi/2)*np.sin(theta/2)*np.sin(phi/2)

    return out