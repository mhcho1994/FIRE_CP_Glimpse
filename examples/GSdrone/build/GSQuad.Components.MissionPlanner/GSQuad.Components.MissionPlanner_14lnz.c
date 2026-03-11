/* Linearization */
#include "GSQuad.Components.MissionPlanner_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *GSQuad_Components_MissionPlanner_linear_model_frame()
{
  return "def linearized_model():\n"
  "    # GSQuad_Components_MissionPlanner\n"
  "    # der(x) = A * x + B * u\n"
  "    # y = C * x + D * u\n"
  "    n = 0 # number of states\n"
  "    m = 0 # number of inputs\n"
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
  "    inputVars  = []\n"
  "    outputVars = ['position_setpoint_w(1)','position_setpoint_w(2)','position_setpoint_w(3)','yaw_setpoint_w']\n"
  "\n"
  "    return (n, m, p, x0, u0, A, B, C, D, stateVars, inputVars, outputVars)\n";
}
const char *GSQuad_Components_MissionPlanner_linear_model_datarecovery_frame()
{
  errorStreamPrint(OMC_LOG_STDOUT, 0, "Linearization with data recovery not implemented for Python.");
  return "";
}

#if defined(__cplusplus)
}
#endif
