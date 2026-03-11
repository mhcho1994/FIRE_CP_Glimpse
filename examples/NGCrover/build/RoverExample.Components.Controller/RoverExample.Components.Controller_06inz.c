/* Initialization */
#include "RoverExample.Components.Controller_model.h"
#include "RoverExample.Components.Controller_11mix.h"
#include "RoverExample.Components.Controller_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void RoverExample_Components_Controller_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: ALGORITHM

  $whenCondition1 := $START.$whenCondition1;
  $whenCondition1 := false;
*/
void RoverExample_Components_Controller_eqFunction_1(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->modelData->booleanVarsData[0] /* $whenCondition1 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = 0 /* false */;
  threadData->lastEquationSolved = 1;
}

/*
equation index: 2
type: SIMPLE_ASSIGN
$PRE.pwm_throttle = $START.pwm_throttle
*/
void RoverExample_Components_Controller_eqFunction_2(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,2};
  (data->simulationInfo->integerVarsPre[1] /* pwm_throttle DISCRETE */) = (data->modelData->integerVarsData[1] /* pwm_throttle DISCRETE */).attribute .start;
  threadData->lastEquationSolved = 2;
}

/*
equation index: 3
type: SIMPLE_ASSIGN
pwm_throttle = $PRE.pwm_throttle
*/
void RoverExample_Components_Controller_eqFunction_3(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* pwm_throttle DISCRETE */) = (data->simulationInfo->integerVarsPre[1] /* pwm_throttle DISCRETE */);
  threadData->lastEquationSolved = 3;
}

/*
equation index: 4
type: SIMPLE_ASSIGN
$PRE.pwm_steering = $START.pwm_steering
*/
void RoverExample_Components_Controller_eqFunction_4(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,4};
  (data->simulationInfo->integerVarsPre[0] /* pwm_steering DISCRETE */) = (data->modelData->integerVarsData[0] /* pwm_steering DISCRETE */).attribute .start;
  threadData->lastEquationSolved = 4;
}

/*
equation index: 5
type: SIMPLE_ASSIGN
pwm_steering = $PRE.pwm_steering
*/
void RoverExample_Components_Controller_eqFunction_5(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* pwm_steering DISCRETE */) = (data->simulationInfo->integerVarsPre[0] /* pwm_steering DISCRETE */);
  threadData->lastEquationSolved = 5;
}

/*
equation index: 6
type: SIMPLE_ASSIGN
$PRE.quaternion_filtered[1] = $START.quaternion_filtered[1]
*/
void RoverExample_Components_Controller_eqFunction_6(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,6};
  (data->simulationInfo->realVarsPre[22] /* quaternion_filtered[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[22] /* quaternion_filtered[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 6;
}

/*
equation index: 7
type: SIMPLE_ASSIGN
quaternion_filtered[1] = $PRE.quaternion_filtered[1]
*/
void RoverExample_Components_Controller_eqFunction_7(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* quaternion_filtered[1] DISCRETE */) = (data->simulationInfo->realVarsPre[22] /* quaternion_filtered[1] DISCRETE */);
  threadData->lastEquationSolved = 7;
}

/*
equation index: 8
type: SIMPLE_ASSIGN
$PRE.quaternion_filtered[2] = $START.quaternion_filtered[2]
*/
void RoverExample_Components_Controller_eqFunction_8(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,8};
  (data->simulationInfo->realVarsPre[23] /* quaternion_filtered[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[23] /* quaternion_filtered[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 8;
}

/*
equation index: 9
type: SIMPLE_ASSIGN
quaternion_filtered[2] = $PRE.quaternion_filtered[2]
*/
void RoverExample_Components_Controller_eqFunction_9(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* quaternion_filtered[2] DISCRETE */) = (data->simulationInfo->realVarsPre[23] /* quaternion_filtered[2] DISCRETE */);
  threadData->lastEquationSolved = 9;
}

/*
equation index: 10
type: SIMPLE_ASSIGN
$PRE.quaternion_filtered[3] = $START.quaternion_filtered[3]
*/
void RoverExample_Components_Controller_eqFunction_10(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,10};
  (data->simulationInfo->realVarsPre[24] /* quaternion_filtered[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[24] /* quaternion_filtered[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 10;
}

/*
equation index: 11
type: SIMPLE_ASSIGN
quaternion_filtered[3] = $PRE.quaternion_filtered[3]
*/
void RoverExample_Components_Controller_eqFunction_11(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* quaternion_filtered[3] DISCRETE */) = (data->simulationInfo->realVarsPre[24] /* quaternion_filtered[3] DISCRETE */);
  threadData->lastEquationSolved = 11;
}

/*
equation index: 12
type: SIMPLE_ASSIGN
$PRE.quaternion_filtered[4] = $START.quaternion_filtered[4]
*/
void RoverExample_Components_Controller_eqFunction_12(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,12};
  (data->simulationInfo->realVarsPre[25] /* quaternion_filtered[4] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[25] /* quaternion_filtered[4] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 12;
}

/*
equation index: 13
type: SIMPLE_ASSIGN
quaternion_filtered[4] = $PRE.quaternion_filtered[4]
*/
void RoverExample_Components_Controller_eqFunction_13(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* quaternion_filtered[4] DISCRETE */) = (data->simulationInfo->realVarsPre[25] /* quaternion_filtered[4] DISCRETE */);
  threadData->lastEquationSolved = 13;
}

/*
equation index: 14
type: SIMPLE_ASSIGN
$PRE.euler_filtered[1] = $START.euler_filtered[1]
*/
void RoverExample_Components_Controller_eqFunction_14(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,14};
  (data->simulationInfo->realVarsPre[16] /* euler_filtered[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[16] /* euler_filtered[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 14;
}

/*
equation index: 15
type: SIMPLE_ASSIGN
euler_filtered[1] = $PRE.euler_filtered[1]
*/
void RoverExample_Components_Controller_eqFunction_15(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* euler_filtered[1] DISCRETE */) = (data->simulationInfo->realVarsPre[16] /* euler_filtered[1] DISCRETE */);
  threadData->lastEquationSolved = 15;
}

/*
equation index: 16
type: SIMPLE_ASSIGN
$PRE.euler_filtered[2] = $START.euler_filtered[2]
*/
void RoverExample_Components_Controller_eqFunction_16(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,16};
  (data->simulationInfo->realVarsPre[17] /* euler_filtered[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[17] /* euler_filtered[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 16;
}

/*
equation index: 17
type: SIMPLE_ASSIGN
euler_filtered[2] = $PRE.euler_filtered[2]
*/
void RoverExample_Components_Controller_eqFunction_17(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* euler_filtered[2] DISCRETE */) = (data->simulationInfo->realVarsPre[17] /* euler_filtered[2] DISCRETE */);
  threadData->lastEquationSolved = 17;
}

/*
equation index: 18
type: SIMPLE_ASSIGN
$PRE.euler_filtered[3] = $START.euler_filtered[3]
*/
void RoverExample_Components_Controller_eqFunction_18(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,18};
  (data->simulationInfo->realVarsPre[18] /* euler_filtered[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[18] /* euler_filtered[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 18;
}

/*
equation index: 19
type: SIMPLE_ASSIGN
euler_filtered[3] = $PRE.euler_filtered[3]
*/
void RoverExample_Components_Controller_eqFunction_19(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* euler_filtered[3] DISCRETE */) = (data->simulationInfo->realVarsPre[18] /* euler_filtered[3] DISCRETE */);
  threadData->lastEquationSolved = 19;
}

/*
equation index: 20
type: SIMPLE_ASSIGN
$PRE.psi_filtered = $START.psi_filtered
*/
void RoverExample_Components_Controller_eqFunction_20(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,20};
  (data->simulationInfo->realVarsPre[20] /* psi_filtered DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[20] /* psi_filtered DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 20;
}

/*
equation index: 21
type: SIMPLE_ASSIGN
psi_filtered = $PRE.psi_filtered
*/
void RoverExample_Components_Controller_eqFunction_21(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */) = (data->simulationInfo->realVarsPre[20] /* psi_filtered DISCRETE */);
  threadData->lastEquationSolved = 21;
}

/*
equation index: 22
type: SIMPLE_ASSIGN
$PRE.d = $START.d
*/
void RoverExample_Components_Controller_eqFunction_22(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,22};
  (data->simulationInfo->realVarsPre[14] /* d DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[14] /* d DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 22;
}

/*
equation index: 23
type: SIMPLE_ASSIGN
d = $PRE.d
*/
void RoverExample_Components_Controller_eqFunction_23(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* d DISCRETE */) = (data->simulationInfo->realVarsPre[14] /* d DISCRETE */);
  threadData->lastEquationSolved = 23;
}

/*
equation index: 24
type: SIMPLE_ASSIGN
$PRE.psi_change = $START.psi_change
*/
void RoverExample_Components_Controller_eqFunction_24(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,24};
  (data->simulationInfo->realVarsPre[19] /* psi_change DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[19] /* psi_change DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 24;
}

/*
equation index: 25
type: SIMPLE_ASSIGN
psi_change = $PRE.psi_change
*/
void RoverExample_Components_Controller_eqFunction_25(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* psi_change DISCRETE */) = (data->simulationInfo->realVarsPre[19] /* psi_change DISCRETE */);
  threadData->lastEquationSolved = 25;
}

/*
equation index: 26
type: SIMPLE_ASSIGN
$PRE.s = $START.s
*/
void RoverExample_Components_Controller_eqFunction_26(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,26};
  (data->simulationInfo->integerVarsPre[2] /* s DISCRETE */) = (data->modelData->integerVarsData[2] /* s DISCRETE */).attribute .start;
  threadData->lastEquationSolved = 26;
}

/*
equation index: 27
type: SIMPLE_ASSIGN
s = $PRE.s
*/
void RoverExample_Components_Controller_eqFunction_27(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,27};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = (data->simulationInfo->integerVarsPre[2] /* s DISCRETE */);
  threadData->lastEquationSolved = 27;
}

/*
equation index: 28
type: SIMPLE_ASSIGN
$PRE.x_ref = $START.x_ref
*/
void RoverExample_Components_Controller_eqFunction_28(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,28};
  (data->simulationInfo->realVarsPre[27] /* x_ref DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[27] /* x_ref DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 28;
}

/*
equation index: 29
type: SIMPLE_ASSIGN
x_ref = $PRE.x_ref
*/
void RoverExample_Components_Controller_eqFunction_29(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,29};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->simulationInfo->realVarsPre[27] /* x_ref DISCRETE */);
  threadData->lastEquationSolved = 29;
}

/*
equation index: 30
type: SIMPLE_ASSIGN
$PRE.y_ref = $START.y_ref
*/
void RoverExample_Components_Controller_eqFunction_30(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,30};
  (data->simulationInfo->realVarsPre[28] /* y_ref DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[28] /* y_ref DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 30;
}

/*
equation index: 31
type: SIMPLE_ASSIGN
y_ref = $PRE.y_ref
*/
void RoverExample_Components_Controller_eqFunction_31(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,31};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->simulationInfo->realVarsPre[28] /* y_ref DISCRETE */);
  threadData->lastEquationSolved = 31;
}

/*
equation index: 32
type: SIMPLE_ASSIGN
$PRE.psi_ref = $START.psi_ref
*/
void RoverExample_Components_Controller_eqFunction_32(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,32};
  (data->simulationInfo->realVarsPre[21] /* psi_ref DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[21] /* psi_ref DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 32;
}

/*
equation index: 33
type: SIMPLE_ASSIGN
psi_ref = $PRE.psi_ref
*/
void RoverExample_Components_Controller_eqFunction_33(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,33};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->simulationInfo->realVarsPre[21] /* psi_ref DISCRETE */);
  threadData->lastEquationSolved = 33;
}

/*
equation index: 34
type: SIMPLE_ASSIGN
$PRE.v = $START.v
*/
void RoverExample_Components_Controller_eqFunction_34(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,34};
  (data->simulationInfo->realVarsPre[26] /* v DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[26] /* v DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 34;
}

/*
equation index: 35
type: SIMPLE_ASSIGN
v = $PRE.v
*/
void RoverExample_Components_Controller_eqFunction_35(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,35};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = (data->simulationInfo->realVarsPre[26] /* v DISCRETE */);
  threadData->lastEquationSolved = 35;
}

/*
equation index: 36
type: SIMPLE_ASSIGN
$PRE.delta = $START.delta
*/
void RoverExample_Components_Controller_eqFunction_36(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,36};
  (data->simulationInfo->realVarsPre[15] /* delta DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[15] /* delta DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 36;
}

/*
equation index: 37
type: SIMPLE_ASSIGN
delta = $PRE.delta
*/
void RoverExample_Components_Controller_eqFunction_37(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,37};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = (data->simulationInfo->realVarsPre[15] /* delta DISCRETE */);
  threadData->lastEquationSolved = 37;
}
OMC_DISABLE_OPT
void RoverExample_Components_Controller_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[37])(DATA*, threadData_t*) = {
    RoverExample_Components_Controller_eqFunction_1,
    RoverExample_Components_Controller_eqFunction_2,
    RoverExample_Components_Controller_eqFunction_3,
    RoverExample_Components_Controller_eqFunction_4,
    RoverExample_Components_Controller_eqFunction_5,
    RoverExample_Components_Controller_eqFunction_6,
    RoverExample_Components_Controller_eqFunction_7,
    RoverExample_Components_Controller_eqFunction_8,
    RoverExample_Components_Controller_eqFunction_9,
    RoverExample_Components_Controller_eqFunction_10,
    RoverExample_Components_Controller_eqFunction_11,
    RoverExample_Components_Controller_eqFunction_12,
    RoverExample_Components_Controller_eqFunction_13,
    RoverExample_Components_Controller_eqFunction_14,
    RoverExample_Components_Controller_eqFunction_15,
    RoverExample_Components_Controller_eqFunction_16,
    RoverExample_Components_Controller_eqFunction_17,
    RoverExample_Components_Controller_eqFunction_18,
    RoverExample_Components_Controller_eqFunction_19,
    RoverExample_Components_Controller_eqFunction_20,
    RoverExample_Components_Controller_eqFunction_21,
    RoverExample_Components_Controller_eqFunction_22,
    RoverExample_Components_Controller_eqFunction_23,
    RoverExample_Components_Controller_eqFunction_24,
    RoverExample_Components_Controller_eqFunction_25,
    RoverExample_Components_Controller_eqFunction_26,
    RoverExample_Components_Controller_eqFunction_27,
    RoverExample_Components_Controller_eqFunction_28,
    RoverExample_Components_Controller_eqFunction_29,
    RoverExample_Components_Controller_eqFunction_30,
    RoverExample_Components_Controller_eqFunction_31,
    RoverExample_Components_Controller_eqFunction_32,
    RoverExample_Components_Controller_eqFunction_33,
    RoverExample_Components_Controller_eqFunction_34,
    RoverExample_Components_Controller_eqFunction_35,
    RoverExample_Components_Controller_eqFunction_36,
    RoverExample_Components_Controller_eqFunction_37
  };
  
  for (int id = 0; id < 37; id++) {
    eqFunctions[id](data, threadData);
  }
}

int RoverExample_Components_Controller_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->discreteCall = 1;
  RoverExample_Components_Controller_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  return 0;
}

/* No RoverExample_Components_Controller_functionInitialEquations_lambda0 function */

int RoverExample_Components_Controller_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  return 0;
}


#if defined(__cplusplus)
}
#endif
