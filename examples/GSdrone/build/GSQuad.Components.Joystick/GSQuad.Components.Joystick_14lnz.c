/* Linearization */
#include "GSQuad.Components.Joystick_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *GSQuad_Components_Joystick_linear_model_frame()
{
  return "def linearized_model():\n"
  "    # GSQuad_Components_Joystick\n"
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
  "    outputVars = ['stick_cmd(1)','stick_cmd(2)','stick_cmd(3)','stick_cmd(4)']\n"
  "\n"
  "    return (n, m, p, x0, u0, A, B, C, D, stateVars, inputVars, outputVars)\n";
}
const char *GSQuad_Components_Joystick_linear_model_datarecovery_frame()
{
  errorStreamPrint(OMC_LOG_STDOUT, 0, "Linearization with data recovery not implemented for Python.");
  return "";
}

#if defined(__cplusplus)
}
#endif
