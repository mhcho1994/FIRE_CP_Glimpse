/* Initialization */
#include "RoverExample.Components.Webserver_model.h"
#include "RoverExample.Components.Webserver_11mix.h"
#include "RoverExample.Components.Webserver_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void RoverExample_Components_Webserver_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: ALGORITHM

  timer_count := $START.timer_count;
  turn := $START.turn;
  $whenCondition1 := $START.$whenCondition1;
  $whenCondition1 := false;
  if timer_count <= turn_interval_count and timer_count >= 0 then
    turn := 0;
  elseif timer_count <= 2 * turn_interval_count and timer_count > turn_interval_count then
    turn := 1;
  elseif timer_count <= 3 * turn_interval_count and timer_count > 2 * turn_interval_count then
    turn := 1;
  else
    turn := 0;
  end if;
  if timer_count >= repeat_interval_count then
    timer_count := 0;
  end if;
*/
void RoverExample_Components_Webserver_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */) = (data->modelData->integerVarsData[0] /* timer_count DISCRETE */).attribute .start;

  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = (data->modelData->integerVarsData[1] /* turn DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->modelData->booleanVarsData[0] /* $whenCondition1 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = 0 /* false */;

  tmp0 = LessEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */));
  tmp1 = GreaterEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),((modelica_integer) 0));
  if((tmp0 && tmp1))
  {
    (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = ((modelica_integer) 0);
  }
  else
  {
    tmp2 = LessEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(((modelica_integer) 2)) * ((data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */)));
    tmp3 = Greater((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */));
    if((tmp2 && tmp3))
    {
      (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = ((modelica_integer) 1);
    }
    else
    {
      tmp4 = LessEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(((modelica_integer) 3)) * ((data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */)));
      tmp5 = Greater((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(((modelica_integer) 2)) * ((data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */)));
      if((tmp4 && tmp5))
      {
        (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = ((modelica_integer) 1);
      }
      else
      {
        (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = ((modelica_integer) 0);
      }
    }
  }

  tmp6 = GreaterEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(data->simulationInfo->integerParameter[0] /* repeat_interval_count PARAM */));
  if(tmp6)
  {
    (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */) = ((modelica_integer) 0);
  }
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
$PRE.timer_count = timer_count
*/
void RoverExample_Components_Webserver_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->simulationInfo->integerVarsPre[0] /* timer_count DISCRETE */) = (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */);
  TRACE_POP
}
OMC_DISABLE_OPT
void RoverExample_Components_Webserver_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RoverExample_Components_Webserver_eqFunction_1(data, threadData);
  RoverExample_Components_Webserver_eqFunction_2(data, threadData);
  TRACE_POP
}

int RoverExample_Components_Webserver_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  RoverExample_Components_Webserver_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No RoverExample_Components_Webserver_functionInitialEquations_lambda0 function */

int RoverExample_Components_Webserver_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

