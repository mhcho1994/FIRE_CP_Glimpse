#if defined(__cplusplus)
  extern "C" {
#endif
  int GSQuad_Components_Joystick_mayer(DATA* data, modelica_real** res, short*);
  int GSQuad_Components_Joystick_lagrange(DATA* data, modelica_real** res, short *, short *);
  int GSQuad_Components_Joystick_getInputVarIndicesInOptimization(DATA* data, int* input_var_indices);
  int GSQuad_Components_Joystick_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int GSQuad_Components_Joystick_setInputData(DATA *data, const modelica_boolean file);
  int GSQuad_Components_Joystick_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif
