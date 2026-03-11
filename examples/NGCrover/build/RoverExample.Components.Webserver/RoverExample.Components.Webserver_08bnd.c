/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "RoverExample.Components.Webserver_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int RoverExample_Components_Webserver_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  /* min ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating min-values");
  messageClose(OMC_LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating max-values");
  messageClose(OMC_LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating nominal-values");
  messageClose(OMC_LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating primary start-values");
  messageClose(OMC_LOG_INIT);
  
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
  const int equationIndexes[2] = {1,4};
  (data->simulationInfo->integerParameter[data->simulationInfo->integerParamsIndex[0]] /* repeat_interval_count PARAM */) = ((modelica_integer)floor(DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[0]] /* repeat_interval PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* sample_interval PARAM */),"sample_interval",equationIndexes)));
  threadData->lastEquationSolved = 4;
}

/*
equation index: 5
type: SIMPLE_ASSIGN
turn_interval_count = integer(turn_interval / sample_interval)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Webserver_eqFunction_5(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,5};
  (data->simulationInfo->integerParameter[data->simulationInfo->integerParamsIndex[1]] /* turn_interval_count PARAM */) = ((modelica_integer)floor(DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[2]] /* turn_interval PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* sample_interval PARAM */),"sample_interval",equationIndexes)));
  threadData->lastEquationSolved = 5;
}
OMC_DISABLE_OPT
void RoverExample_Components_Webserver_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[2])(DATA*, threadData_t*) = {
    RoverExample_Components_Webserver_eqFunction_4,
    RoverExample_Components_Webserver_eqFunction_5
  };
  
  for (int id = 0; id < 2; id++) {
    eqFunctions[id](data, threadData);
  }
}
OMC_DISABLE_OPT
int RoverExample_Components_Webserver_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  RoverExample_Components_Webserver_updateBoundParameters_0(data, threadData);
  return 0;
}

#if defined(__cplusplus)
}
#endif
