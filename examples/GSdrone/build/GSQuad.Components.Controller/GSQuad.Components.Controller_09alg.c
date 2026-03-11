/* Algebraic */
#include "GSQuad.Components.Controller_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void GSQuad_Components_Controller_eqFunction_195(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Controller_eqFunction_196(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Controller_eqFunction_197(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Controller_eqFunction_198(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Controller_eqFunction_199(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Controller_eqFunction_200(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[6])(DATA*, threadData_t*) = {
    GSQuad_Components_Controller_eqFunction_195,
    GSQuad_Components_Controller_eqFunction_196,
    GSQuad_Components_Controller_eqFunction_197,
    GSQuad_Components_Controller_eqFunction_198,
    GSQuad_Components_Controller_eqFunction_199,
    GSQuad_Components_Controller_eqFunction_200
  };
  
  for (int id = 0; id < 6; id++) {
    eqFunctions[id](data, threadData);
  }
}
/* for continuous time variables */
int GSQuad_Components_Controller_functionAlgebraics(DATA *data, threadData_t *threadData)
{

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  GSQuad_Components_Controller_function_savePreSynchronous(data, threadData);
  
  functionAlg_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  return 0;
}

#ifdef __cplusplus
}
#endif
