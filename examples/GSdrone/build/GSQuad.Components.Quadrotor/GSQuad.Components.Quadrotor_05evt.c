/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "GSQuad.Components.Quadrotor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void GSQuad_Components_Quadrotor_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
  /* sample 1 */
  data->modelData->samplesInfo[i].index = 1;
  data->modelData->samplesInfo[i].start = 0.0;
  data->modelData->samplesInfo[i].interval = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[36]] /* gyroatk.sample_interval PARAM */) /* (max real for single time events) */;
  i++;
  /* sample 2 */
  data->modelData->samplesInfo[i].index = 2;
  data->modelData->samplesInfo[i].start = 0.0;
  data->modelData->samplesInfo[i].interval = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[2]] /* actuator_sample_period PARAM */) /* (max real for single time events) */;
  i++;
  /* sample 3 */
  data->modelData->samplesInfo[i].index = 3;
  data->modelData->samplesInfo[i].start = 0.0;
  data->modelData->samplesInfo[i].interval = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[94]] /* sensor_sample_period PARAM */) /* (max real for single time events) */;
  i++;
}

const char *GSQuad_Components_Quadrotor_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"mod(pre(euler_wb_buf[3]) + 3.14159265, 6.2831853, 0)"};
  static const int occurEqs0[] = {1,154};
  static const int *occurEqs[] = {occurEqs0};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */

int GSQuad_Components_Quadrotor_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  
  return 0;
}

int GSQuad_Components_Quadrotor_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  const int *equationIndexes = NULL;

  modelica_real tmp6;
  modelica_real tmp7;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  start_index = current_index;
  tmp6 = floor(((data->simulationInfo->realVarsPre[80] /* euler_wb_buf[3] DISCRETE */) + 3.14159265) / (6.2831853));
  tmp7 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)+1]));
  gout[start_index] = tmp6 != tmp7 ? 1 : -1;
  current_index++;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  return 0;
}

const char *GSQuad_Components_Quadrotor_relationDescription(int i)
{
  return "empty";
}

int GSQuad_Components_Quadrotor_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  const int *equationIndexes = NULL;

  modelica_integer current_index = 0;
  modelica_integer start_index;
  
  if(evalforZeroCross) {
  } else {
  }
  
  return 0;
}

#if defined(__cplusplus)
}
#endif
