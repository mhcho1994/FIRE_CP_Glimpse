/* Linearization */
#include "GSQuad.Components.Quadrotor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *GSQuad_Components_Quadrotor_linear_model_frame()
{
  return "def linearized_model():\n"
  "    # GSQuad_Components_Quadrotor\n"
  "    # der(x) = A * x + B * u\n"
  "    # y = C * x + D * u\n"
  "    n = 13 # number of states\n"
  "    m = 4 # number of inputs\n"
  "    p = 19 # number of outputs\n"
  "\n"
  "    x0 = %s\n"
  "    u0 = %s\n"
  "\n"
  "    A = %s\n\n"
  "    B = %s\n\n"
  "    C = %s\n\n"
  "    D = %s\n\n"
  "    stateVars  = ['quad_low_position_w_p_w(1)','quad_low_position_w_p_w(2)','quad_low_position_w_p_w(3)','quad_low_quaternion_wb(1)','quad_low_quaternion_wb(2)','quad_low_quaternion_wb(3)','quad_low_quaternion_wb(4)','quad_low_rate_wb_b(1)','quad_low_rate_wb_b(2)','quad_low_rate_wb_b(3)','quad_low_velocity_w_p_b(1)','quad_low_velocity_w_p_b(2)','quad_low_velocity_w_p_b(3)']\n"
  "    inputVars  = ['pwm_rotor_cmd(1)','pwm_rotor_cmd(2)','pwm_rotor_cmd(3)','pwm_rotor_cmd(4)']\n"
  "    outputVars = ['acc_w_p_b_meas(1)','acc_w_p_b_meas(2)','acc_w_p_b_meas(3)','euler_wb_meas(1)','euler_wb_meas(2)','euler_wb_meas(3)','pos_w_p_w_meas(1)','pos_w_p_w_meas(2)','pos_w_p_w_meas(3)','quat_wb_meas(1)','quat_wb_meas(2)','quat_wb_meas(3)','quat_wb_meas(4)','rate_wb_b_meas(1)','rate_wb_b_meas(2)','rate_wb_b_meas(3)','vel_w_p_b_meas(1)','vel_w_p_b_meas(2)','vel_w_p_b_meas(3)']\n"
  "\n"
  "    return (n, m, p, x0, u0, A, B, C, D, stateVars, inputVars, outputVars)\n";
}
const char *GSQuad_Components_Quadrotor_linear_model_datarecovery_frame()
{
  errorStreamPrint(OMC_LOG_STDOUT, 0, "Linearization with data recovery not implemented for Python.");
  return "";
}

#if defined(__cplusplus)
}
#endif
