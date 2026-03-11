/* Algebraic */
#include "GSQuad.Components.Quadrotor_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void GSQuad_Components_Quadrotor_eqFunction_112(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_117(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_137(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_138(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_139(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_140(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_141(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_142(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_143(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_144(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_145(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_146(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_147(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_148(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_149(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_150(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_151(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_152(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_153(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_154(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_155(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_156(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_157(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[23])(DATA*, threadData_t*) = {
    GSQuad_Components_Quadrotor_eqFunction_112,
    GSQuad_Components_Quadrotor_eqFunction_117,
    GSQuad_Components_Quadrotor_eqFunction_137,
    GSQuad_Components_Quadrotor_eqFunction_138,
    GSQuad_Components_Quadrotor_eqFunction_139,
    GSQuad_Components_Quadrotor_eqFunction_140,
    GSQuad_Components_Quadrotor_eqFunction_141,
    GSQuad_Components_Quadrotor_eqFunction_142,
    GSQuad_Components_Quadrotor_eqFunction_143,
    GSQuad_Components_Quadrotor_eqFunction_144,
    GSQuad_Components_Quadrotor_eqFunction_145,
    GSQuad_Components_Quadrotor_eqFunction_146,
    GSQuad_Components_Quadrotor_eqFunction_147,
    GSQuad_Components_Quadrotor_eqFunction_148,
    GSQuad_Components_Quadrotor_eqFunction_149,
    GSQuad_Components_Quadrotor_eqFunction_150,
    GSQuad_Components_Quadrotor_eqFunction_151,
    GSQuad_Components_Quadrotor_eqFunction_152,
    GSQuad_Components_Quadrotor_eqFunction_153,
    GSQuad_Components_Quadrotor_eqFunction_154,
    GSQuad_Components_Quadrotor_eqFunction_155,
    GSQuad_Components_Quadrotor_eqFunction_156,
    GSQuad_Components_Quadrotor_eqFunction_157
  };
  
  for (int id = 0; id < 23; id++) {
    eqFunctions[id](data, threadData);
  }
}
/* for continuous time variables */
int GSQuad_Components_Quadrotor_functionAlgebraics(DATA *data, threadData_t *threadData)
{

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  GSQuad_Components_Quadrotor_function_savePreSynchronous(data, threadData);
  
  functionAlg_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  return 0;
}

#ifdef __cplusplus
}
#endif
