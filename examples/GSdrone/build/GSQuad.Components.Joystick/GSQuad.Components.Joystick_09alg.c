/* Algebraic */
#include "GSQuad.Components.Joystick_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void GSQuad_Components_Joystick_eqFunction_14(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Joystick_eqFunction_15(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Joystick_eqFunction_16(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Joystick_eqFunction_17(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Joystick_eqFunction_18(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[5])(DATA*, threadData_t*) = {
    GSQuad_Components_Joystick_eqFunction_14,
    GSQuad_Components_Joystick_eqFunction_15,
    GSQuad_Components_Joystick_eqFunction_16,
    GSQuad_Components_Joystick_eqFunction_17,
    GSQuad_Components_Joystick_eqFunction_18
  };
  
  for (int id = 0; id < 5; id++) {
    eqFunctions[id](data, threadData);
  }
}
/* for continuous time variables */
int GSQuad_Components_Joystick_functionAlgebraics(DATA *data, threadData_t *threadData)
{

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  GSQuad_Components_Joystick_function_savePreSynchronous(data, threadData);
  
  functionAlg_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  return 0;
}

#ifdef __cplusplus
}
#endif
