/* Optimization */
#include "RoverExample.Components.Rover_model.h"
#include "RoverExample.Components.Rover_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif
int RoverExample_Components_Rover_mayer(DATA* data, modelica_real** res,short *i) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
int RoverExample_Components_Rover_lagrange(DATA* data, modelica_real** res, short * i1, short*i2) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
int RoverExample_Components_Rover_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
int RoverExample_Components_Rover_setInputData(DATA *data, const modelica_boolean file) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
int RoverExample_Components_Rover_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
#if defined(__cplusplus)
}
#endif