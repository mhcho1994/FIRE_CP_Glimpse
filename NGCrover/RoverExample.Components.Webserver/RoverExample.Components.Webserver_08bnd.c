/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "RoverExample.Components.Webserver_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int RoverExample_Components_Webserver_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating min-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating max-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating nominal-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating primary start-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void RoverExample_Components_Webserver_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 4
type: SIMPLE_ASSIGN
repeat_interval_count = integer(repeat_interval / sample_interval)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Webserver_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->simulationInfo->integerParameter[0] /* repeat_interval_count PARAM */) = ((modelica_integer)floor(DIVISION_SIM((data->simulationInfo->realParameter[0] /* repeat_interval PARAM */),(data->simulationInfo->realParameter[1] /* sample_interval PARAM */),"sample_interval",equationIndexes)));
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
turn_interval_count = integer(turn_interval / sample_interval)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Webserver_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */) = ((modelica_integer)floor(DIVISION_SIM((data->simulationInfo->realParameter[2] /* turn_interval PARAM */),(data->simulationInfo->realParameter[1] /* sample_interval PARAM */),"sample_interval",equationIndexes)));
  TRACE_POP
}
OMC_DISABLE_OPT
void RoverExample_Components_Webserver_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RoverExample_Components_Webserver_eqFunction_4(data, threadData);
  RoverExample_Components_Webserver_eqFunction_5(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int RoverExample_Components_Webserver_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RoverExample_Components_Webserver_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

