/* Initialization */
#include "GSQuad.Components.Joystick_model.h"
#include "GSQuad.Components.Joystick_11mix.h"
#include "GSQuad.Components.Joystick_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void GSQuad_Components_Joystick_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: ALGORITHM

  $whenCondition1 := $START.$whenCondition1;
  $whenCondition1 := false;
*/
void GSQuad_Components_Joystick_eqFunction_1(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->modelData->booleanVarsData[0] /* $whenCondition1 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = 0 /* false */;
  threadData->lastEquationSolved = 1;
}

/*
equation index: 2
type: SIMPLE_ASSIGN
$PRE.stick_cmd_buf[1] = 0.0
*/
void GSQuad_Components_Joystick_eqFunction_2(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,2};
  (data->simulationInfo->realVarsPre[4] /* stick_cmd_buf[1] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 2;
}

/*
equation index: 3
type: SIMPLE_ASSIGN
stick_cmd_buf[1] = $PRE.stick_cmd_buf[1]
*/
void GSQuad_Components_Joystick_eqFunction_3(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* stick_cmd_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[4] /* stick_cmd_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 3;
}

/*
equation index: 4
type: SIMPLE_ASSIGN
stick_cmd[1] = $PRE.stick_cmd_buf[1]
*/
void GSQuad_Components_Joystick_eqFunction_4(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* stick_cmd[1] variable */) = (data->simulationInfo->realVarsPre[4] /* stick_cmd_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 4;
}

/*
equation index: 5
type: SIMPLE_ASSIGN
$PRE.stick_cmd_buf[2] = 0.0
*/
void GSQuad_Components_Joystick_eqFunction_5(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,5};
  (data->simulationInfo->realVarsPre[5] /* stick_cmd_buf[2] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 5;
}

/*
equation index: 6
type: SIMPLE_ASSIGN
stick_cmd_buf[2] = $PRE.stick_cmd_buf[2]
*/
void GSQuad_Components_Joystick_eqFunction_6(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* stick_cmd_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[5] /* stick_cmd_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 6;
}

/*
equation index: 7
type: SIMPLE_ASSIGN
stick_cmd[2] = $PRE.stick_cmd_buf[2]
*/
void GSQuad_Components_Joystick_eqFunction_7(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* stick_cmd[2] variable */) = (data->simulationInfo->realVarsPre[5] /* stick_cmd_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 7;
}

/*
equation index: 8
type: SIMPLE_ASSIGN
$PRE.stick_cmd_buf[3] = 0.0
*/
void GSQuad_Components_Joystick_eqFunction_8(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,8};
  (data->simulationInfo->realVarsPre[6] /* stick_cmd_buf[3] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 8;
}

/*
equation index: 9
type: SIMPLE_ASSIGN
stick_cmd_buf[3] = $PRE.stick_cmd_buf[3]
*/
void GSQuad_Components_Joystick_eqFunction_9(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* stick_cmd_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[6] /* stick_cmd_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 9;
}

/*
equation index: 10
type: SIMPLE_ASSIGN
stick_cmd[3] = $PRE.stick_cmd_buf[3]
*/
void GSQuad_Components_Joystick_eqFunction_10(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* stick_cmd[3] variable */) = (data->simulationInfo->realVarsPre[6] /* stick_cmd_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 10;
}

/*
equation index: 11
type: SIMPLE_ASSIGN
$PRE.stick_cmd_buf[4] = 0.0
*/
void GSQuad_Components_Joystick_eqFunction_11(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,11};
  (data->simulationInfo->realVarsPre[7] /* stick_cmd_buf[4] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 11;
}

/*
equation index: 12
type: SIMPLE_ASSIGN
stick_cmd_buf[4] = $PRE.stick_cmd_buf[4]
*/
void GSQuad_Components_Joystick_eqFunction_12(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* stick_cmd_buf[4] DISCRETE */) = (data->simulationInfo->realVarsPre[7] /* stick_cmd_buf[4] DISCRETE */);
  threadData->lastEquationSolved = 12;
}

/*
equation index: 13
type: SIMPLE_ASSIGN
stick_cmd[4] = $PRE.stick_cmd_buf[4]
*/
void GSQuad_Components_Joystick_eqFunction_13(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* stick_cmd[4] variable */) = (data->simulationInfo->realVarsPre[7] /* stick_cmd_buf[4] DISCRETE */);
  threadData->lastEquationSolved = 13;
}
OMC_DISABLE_OPT
void GSQuad_Components_Joystick_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[13])(DATA*, threadData_t*) = {
    GSQuad_Components_Joystick_eqFunction_1,
    GSQuad_Components_Joystick_eqFunction_2,
    GSQuad_Components_Joystick_eqFunction_3,
    GSQuad_Components_Joystick_eqFunction_4,
    GSQuad_Components_Joystick_eqFunction_5,
    GSQuad_Components_Joystick_eqFunction_6,
    GSQuad_Components_Joystick_eqFunction_7,
    GSQuad_Components_Joystick_eqFunction_8,
    GSQuad_Components_Joystick_eqFunction_9,
    GSQuad_Components_Joystick_eqFunction_10,
    GSQuad_Components_Joystick_eqFunction_11,
    GSQuad_Components_Joystick_eqFunction_12,
    GSQuad_Components_Joystick_eqFunction_13
  };
  
  for (int id = 0; id < 13; id++) {
    eqFunctions[id](data, threadData);
  }
}

int GSQuad_Components_Joystick_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->discreteCall = 1;
  GSQuad_Components_Joystick_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  return 0;
}

/* No GSQuad_Components_Joystick_functionInitialEquations_lambda0 function */

int GSQuad_Components_Joystick_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  return 0;
}


#if defined(__cplusplus)
}
#endif
