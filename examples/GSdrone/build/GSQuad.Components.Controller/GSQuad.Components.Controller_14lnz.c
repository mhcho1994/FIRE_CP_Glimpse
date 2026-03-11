/* Linearization */
#include "GSQuad.Components.Controller_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *GSQuad_Components_Controller_linear_model_frame()
{
  return "def linearized_model():\n"
  "    # GSQuad_Components_Controller\n"
  "    # der(x) = A * x + B * u\n"
  "    # y = C * x + D * u\n"
  "    n = 0 # number of states\n"
  "    m = 27 # number of inputs\n"
  "    p = 4 # number of outputs\n"
  "\n"
  "    x0 = %s\n"
  "    u0 = %s\n"
  "\n"
  "    A = %s\n\n"
  "    B = %s\n\n"
  "    C = %s\n\n"
  "    D = %s\n\n"
  "    stateVars  = []\n"
  "    inputVars  = ['acc_w_p_b_fdbk(1)','acc_w_p_b_fdbk(2)','acc_w_p_b_fdbk(3)','euler_wb_fdbk(1)','euler_wb_fdbk(2)','euler_wb_fdbk(3)','pos_w_p_w_fdbk(1)','pos_w_p_w_fdbk(2)','pos_w_p_w_fdbk(3)','position_setpoint(1)','position_setpoint(2)','position_setpoint(3)','quat_wb_fdbk(1)','quat_wb_fdbk(2)','quat_wb_fdbk(3)','quat_wb_fdbk(4)','rate_wb_b_fdbk(1)','rate_wb_b_fdbk(2)','rate_wb_b_fdbk(3)','rc_input(1)','rc_input(2)','rc_input(3)','rc_input(4)','vel_w_p_b_fdbk(1)','vel_w_p_b_fdbk(2)','vel_w_p_b_fdbk(3)','yaw_setpoint']\n"
  "    outputVars = ['pwm_rotor_cmd(1)','pwm_rotor_cmd(2)','pwm_rotor_cmd(3)','pwm_rotor_cmd(4)']\n"
  "\n"
  "    return (n, m, p, x0, u0, A, B, C, D, stateVars, inputVars, outputVars)\n";
}
const char *GSQuad_Components_Controller_linear_model_datarecovery_frame()
{
  errorStreamPrint(OMC_LOG_STDOUT, 0, "Linearization with data recovery not implemented for Python.");
  return "";
}

#if defined(__cplusplus)
}
#endif
