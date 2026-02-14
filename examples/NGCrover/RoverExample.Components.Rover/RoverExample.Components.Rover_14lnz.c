/* Linearization */
#include "RoverExample.Components.Rover_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *RoverExample_Components_Rover_linear_model_frame()
{
  return "def linearized_model():\n"
  "    # RoverExample_Components_Rover\n"
  "    # der(x) = A * x + B * u\n"
  "    # y = C * x + D * u\n"
  "    n = 35 # number of states\n"
  "    m = 2 # number of inputs\n"
  "    p = 19 # number of outputs\n"
  "\n"
  "    x0 = %s\n"
  "    u0 = %s\n"
  "\n"
  "    A = %s\n\n"
  "    B = %s\n\n"
  "    C = %s\n\n"
  "    D = %s\n\n"
  "    stateVars  = ['rover_3d_phi','rover_3d_psi','rover_3d_theta','rover_3d_vy','rover_3d_vz','rover_3d_x','rover_3d_y','rover_3d_z','rover_8d_Iq','rover_8d_alpha_fl','rover_8d_alpha_fr','rover_8d_alpha_rl','rover_8d_alpha_rr','rover_8d_delta','rover_8d_kappa_fl','rover_8d_kappa_fr','rover_8d_kappa_rl','rover_8d_kappa_rr','rover_8d_lambda','rover_8d_omega_fl','rover_8d_omega_fr','rover_8d_omega_rl','rover_8d_omega_rr','rover_8d_p','rover_8d_phi','rover_8d_psi','rover_8d_q','rover_8d_r','rover_8d_theta','rover_8d_vx','rover_8d_vy','rover_8d_vz','rover_8d_x','rover_8d_y','rover_8d_z']\n"
  "    inputVars  = ['pwm_steering','pwm_throttle']\n"
  "    outputVars = ['ax_meas','ay_meas','az_meas','mx_meas','my_meas','mz_meas','p_meas','phi_meas','psi_meas','q_meas','r_meas','rollover_detected','theta_meas','vx_meas','vy_meas','vz_meas','x_meas','y_meas','z_meas']\n"
  "\n"
  "    return (n, m, p, x0, u0, A, B, C, D, stateVars, inputVars, outputVars)\n";
}
const char *RoverExample_Components_Rover_linear_model_datarecovery_frame()
{ /* not implemented */ }
#if defined(__cplusplus)
}
#endif

