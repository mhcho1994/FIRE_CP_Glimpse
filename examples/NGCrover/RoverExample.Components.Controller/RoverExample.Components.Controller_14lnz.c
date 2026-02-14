/* Linearization */
#include "RoverExample.Components.Controller_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *RoverExample_Components_Controller_linear_model_frame()
{
  return "def linearized_model():\n"
  "    # RoverExample_Components_Controller\n"
  "    # der(x) = A * x + B * u\n"
  "    # y = C * x + D * u\n"
  "    n = 0 # number of states\n"
  "    m = 15 # number of inputs\n"
  "    p = 2 # number of outputs\n"
  "\n"
  "    x0 = %s\n"
  "    u0 = %s\n"
  "\n"
  "    A = %s\n\n"
  "    B = %s\n\n"
  "    C = %s\n\n"
  "    D = %s\n\n"
  "    stateVars  = []\n"
  "    inputVars  = ['ax_acc','ay_acc','az_acc','mx_mag','my_mag','mz_mag','p_gyro','phi_gyro','psi_gyro','q_gyro','r_gyro','theta_gyro','turn','x','y']\n"
  "    outputVars = ['pwm_steering','pwm_throttle']\n"
  "\n"
  "    return (n, m, p, x0, u0, A, B, C, D, stateVars, inputVars, outputVars)\n";
}
const char *RoverExample_Components_Controller_linear_model_datarecovery_frame()
{ /* not implemented */ }
#if defined(__cplusplus)
}
#endif

