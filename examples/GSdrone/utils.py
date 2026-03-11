# load packages
import numpy as np 

def eul2quat(eul):

    # check the input type
    if eul.shape[0] != 3:
        raise ValueError('Check the input dimension')

    # initialize input/output
    phi   = eul[0]
    theta = eul[1]
    psi   = eul[2]

    out = np.zeros((4,))

    # compute the quaternion
    out[0] = np.cos(psi/2)*np.cos(theta/2)*np.cos(phi/2)+np.sin(psi/2)*np.sin(theta/2)*np.sin(phi/2)
    out[1] = np.cos(psi/2)*np.cos(theta/2)*np.sin(phi/2)-np.sin(psi/2)*np.sin(theta/2)*np.cos(phi/2)
    out[2] = np.cos(psi/2)*np.sin(theta/2)*np.cos(phi/2)+np.sin(psi/2)*np.cos(theta/2)*np.sin(phi/2)
    out[3] = np.sin(psi/2)*np.cos(theta/2)*np.cos(phi/2)-np.cos(psi/2)*np.sin(theta/2)*np.sin(phi/2)

    return out


def quat2eul(quat):

    # check input dimension
    if quat.shape[0] != 4:
        raise ValueError("Check the input dimension")

    # unpack quaternion
    q0 = quat[0]  # w
    q1 = quat[1]  # x
    q2 = quat[2]  # y
    q3 = quat[3]  # z

    # initialize output
    out = np.zeros((3,))

    # compute euler angles
    out[0] = np.arctan2(2*(q0*q1 + q2*q3), 1 - 2*(q1**2 + q2**2))
    sin_theta = 2*(q0*q2 - q3*q1)
    sin_theta = np.clip(sin_theta, -1.0, 1.0)  # numerical safety
    out[1] = np.arcsin(sin_theta)
    out[2] = np.arctan2(2*(q0*q3 + q1*q2), 1 - 2*(q2**2 + q3**2))

    return out