/* Linearization */
#include "RoverExample.Components.Webserver_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *RoverExample_Components_Webserver_linear_model_frame()
{
  return "def linearized_model():\n"
  "    # RoverExample_Components_Webserver\n"
  "    # der(x) = A * x + B * u\n"
  "    # y = C * x + D * u\n"
  "    n = 0 # number of states\n"
  "    m = 0 # number of inputs\n"
  "    p = 1 # number of outputs\n"
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
  "    outputVars = ['turn']\n"
  "\n"
  "    return (n, m, p, x0, u0, A, B, C, D, stateVars, inputVars, outputVars)\n";
}
const char *RoverExample_Components_Webserver_linear_model_datarecovery_frame()
{ /* not implemented */ }
#if defined(__cplusplus)
}
#endif

