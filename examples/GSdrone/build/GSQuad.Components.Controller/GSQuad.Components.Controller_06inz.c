/* Initialization */
#include "GSQuad.Components.Controller_model.h"
#include "GSQuad.Components.Controller_11mix.h"
#include "GSQuad.Components.Controller_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void GSQuad_Components_Controller_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: ALGORITHM

  $whenCondition1 := $START.$whenCondition1;
  $whenCondition1 := false;
*/
void GSQuad_Components_Controller_eqFunction_1(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->modelData->booleanVarsData[0] /* $whenCondition1 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = 0 /* false */;
  threadData->lastEquationSolved = 1;
}

/*
equation index: 2
type: ALGORITHM

  $whenCondition2 := $START.$whenCondition2;
  $whenCondition2 := false;
*/
void GSQuad_Components_Controller_eqFunction_2(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = (data->modelData->booleanVarsData[1] /* $whenCondition2 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = 0 /* false */;
  threadData->lastEquationSolved = 2;
}

/*
equation index: 3
type: SIMPLE_ASSIGN
$PRE.euler_pid.normalized_ctrl_input[1] = $START.euler_pid.normalized_ctrl_input[1]
*/
void GSQuad_Components_Controller_eqFunction_3(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,3};
  (data->simulationInfo->realVarsPre[64] /* euler_pid.normalized_ctrl_input[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[64] /* euler_pid.normalized_ctrl_input[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 3;
}

/*
equation index: 4
type: SIMPLE_ASSIGN
euler_pid.normalized_ctrl_input[1] = $PRE.euler_pid.normalized_ctrl_input[1]
*/
void GSQuad_Components_Controller_eqFunction_4(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* euler_pid.normalized_ctrl_input[1] DISCRETE */) = (data->simulationInfo->realVarsPre[64] /* euler_pid.normalized_ctrl_input[1] DISCRETE */);
  threadData->lastEquationSolved = 4;
}

/*
equation index: 5
type: SIMPLE_ASSIGN
pwm_rotor_cmd[1] = pwm_min + (pwm_max - pwm_min) * $PRE.euler_pid.normalized_ctrl_input[1]
*/
void GSQuad_Components_Controller_eqFunction_5(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* pwm_rotor_cmd[1] variable */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* pwm_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */)) * ((data->simulationInfo->realVarsPre[64] /* euler_pid.normalized_ctrl_input[1] DISCRETE */));
  threadData->lastEquationSolved = 5;
}

/*
equation index: 6
type: SIMPLE_ASSIGN
$PRE.euler_pid.normalized_ctrl_input[2] = $START.euler_pid.normalized_ctrl_input[2]
*/
void GSQuad_Components_Controller_eqFunction_6(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,6};
  (data->simulationInfo->realVarsPre[65] /* euler_pid.normalized_ctrl_input[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[65] /* euler_pid.normalized_ctrl_input[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 6;
}

/*
equation index: 7
type: SIMPLE_ASSIGN
euler_pid.normalized_ctrl_input[2] = $PRE.euler_pid.normalized_ctrl_input[2]
*/
void GSQuad_Components_Controller_eqFunction_7(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* euler_pid.normalized_ctrl_input[2] DISCRETE */) = (data->simulationInfo->realVarsPre[65] /* euler_pid.normalized_ctrl_input[2] DISCRETE */);
  threadData->lastEquationSolved = 7;
}

/*
equation index: 8
type: SIMPLE_ASSIGN
pwm_rotor_cmd[2] = pwm_min + (pwm_max - pwm_min) * $PRE.euler_pid.normalized_ctrl_input[2]
*/
void GSQuad_Components_Controller_eqFunction_8(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,8};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* pwm_rotor_cmd[2] variable */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* pwm_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */)) * ((data->simulationInfo->realVarsPre[65] /* euler_pid.normalized_ctrl_input[2] DISCRETE */));
  threadData->lastEquationSolved = 8;
}

/*
equation index: 9
type: SIMPLE_ASSIGN
$PRE.euler_pid.normalized_ctrl_input[3] = $START.euler_pid.normalized_ctrl_input[3]
*/
void GSQuad_Components_Controller_eqFunction_9(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,9};
  (data->simulationInfo->realVarsPre[66] /* euler_pid.normalized_ctrl_input[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[66] /* euler_pid.normalized_ctrl_input[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 9;
}

/*
equation index: 10
type: SIMPLE_ASSIGN
euler_pid.normalized_ctrl_input[3] = $PRE.euler_pid.normalized_ctrl_input[3]
*/
void GSQuad_Components_Controller_eqFunction_10(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* euler_pid.normalized_ctrl_input[3] DISCRETE */) = (data->simulationInfo->realVarsPre[66] /* euler_pid.normalized_ctrl_input[3] DISCRETE */);
  threadData->lastEquationSolved = 10;
}

/*
equation index: 11
type: SIMPLE_ASSIGN
pwm_rotor_cmd[3] = pwm_min + (pwm_max - pwm_min) * $PRE.euler_pid.normalized_ctrl_input[3]
*/
void GSQuad_Components_Controller_eqFunction_11(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* pwm_rotor_cmd[3] variable */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* pwm_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */)) * ((data->simulationInfo->realVarsPre[66] /* euler_pid.normalized_ctrl_input[3] DISCRETE */));
  threadData->lastEquationSolved = 11;
}

/*
equation index: 12
type: SIMPLE_ASSIGN
$PRE.euler_pid.normalized_ctrl_input[4] = $START.euler_pid.normalized_ctrl_input[4]
*/
void GSQuad_Components_Controller_eqFunction_12(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,12};
  (data->simulationInfo->realVarsPre[67] /* euler_pid.normalized_ctrl_input[4] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[67] /* euler_pid.normalized_ctrl_input[4] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 12;
}

/*
equation index: 13
type: SIMPLE_ASSIGN
euler_pid.normalized_ctrl_input[4] = $PRE.euler_pid.normalized_ctrl_input[4]
*/
void GSQuad_Components_Controller_eqFunction_13(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* euler_pid.normalized_ctrl_input[4] DISCRETE */) = (data->simulationInfo->realVarsPre[67] /* euler_pid.normalized_ctrl_input[4] DISCRETE */);
  threadData->lastEquationSolved = 13;
}

/*
equation index: 14
type: SIMPLE_ASSIGN
pwm_rotor_cmd[4] = pwm_min + (pwm_max - pwm_min) * $PRE.euler_pid.normalized_ctrl_input[4]
*/
void GSQuad_Components_Controller_eqFunction_14(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* pwm_rotor_cmd[4] variable */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* pwm_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */)) * ((data->simulationInfo->realVarsPre[67] /* euler_pid.normalized_ctrl_input[4] DISCRETE */));
  threadData->lastEquationSolved = 14;
}

/*
equation index: 15
type: SIMPLE_ASSIGN
$PRE.euler_pid.pos_error[1] = $START.euler_pid.pos_error[1]
*/
void GSQuad_Components_Controller_eqFunction_15(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,15};
  (data->simulationInfo->realVarsPre[73] /* euler_pid.pos_error[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[73] /* euler_pid.pos_error[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 15;
}

/*
equation index: 16
type: SIMPLE_ASSIGN
euler_pid.pos_error[1] = $PRE.euler_pid.pos_error[1]
*/
void GSQuad_Components_Controller_eqFunction_16(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* euler_pid.pos_error[1] DISCRETE */) = (data->simulationInfo->realVarsPre[73] /* euler_pid.pos_error[1] DISCRETE */);
  threadData->lastEquationSolved = 16;
}

/*
equation index: 17
type: SIMPLE_ASSIGN
$PRE.euler_pid.pos_error[2] = $START.euler_pid.pos_error[2]
*/
void GSQuad_Components_Controller_eqFunction_17(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,17};
  (data->simulationInfo->realVarsPre[74] /* euler_pid.pos_error[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[74] /* euler_pid.pos_error[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 17;
}

/*
equation index: 18
type: SIMPLE_ASSIGN
euler_pid.pos_error[2] = $PRE.euler_pid.pos_error[2]
*/
void GSQuad_Components_Controller_eqFunction_18(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* euler_pid.pos_error[2] DISCRETE */) = (data->simulationInfo->realVarsPre[74] /* euler_pid.pos_error[2] DISCRETE */);
  threadData->lastEquationSolved = 18;
}

/*
equation index: 19
type: SIMPLE_ASSIGN
$PRE.euler_pid.pos_error[3] = $START.euler_pid.pos_error[3]
*/
void GSQuad_Components_Controller_eqFunction_19(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,19};
  (data->simulationInfo->realVarsPre[75] /* euler_pid.pos_error[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[75] /* euler_pid.pos_error[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 19;
}

/*
equation index: 20
type: SIMPLE_ASSIGN
euler_pid.pos_error[3] = $PRE.euler_pid.pos_error[3]
*/
void GSQuad_Components_Controller_eqFunction_20(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* euler_pid.pos_error[3] DISCRETE */) = (data->simulationInfo->realVarsPre[75] /* euler_pid.pos_error[3] DISCRETE */);
  threadData->lastEquationSolved = 20;
}

/*
equation index: 21
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_target[1] = $START.euler_pid.vel_target[1]
*/
void GSQuad_Components_Controller_eqFunction_21(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,21};
  (data->simulationInfo->realVarsPre[117] /* euler_pid.vel_target[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[117] /* euler_pid.vel_target[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 21;
}

/*
equation index: 22
type: SIMPLE_ASSIGN
euler_pid.vel_target[1] = $PRE.euler_pid.vel_target[1]
*/
void GSQuad_Components_Controller_eqFunction_22(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[117]] /* euler_pid.vel_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[117] /* euler_pid.vel_target[1] DISCRETE */);
  threadData->lastEquationSolved = 22;
}

/*
equation index: 23
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_target[2] = $START.euler_pid.vel_target[2]
*/
void GSQuad_Components_Controller_eqFunction_23(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,23};
  (data->simulationInfo->realVarsPre[118] /* euler_pid.vel_target[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[118] /* euler_pid.vel_target[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 23;
}

/*
equation index: 24
type: SIMPLE_ASSIGN
euler_pid.vel_target[2] = $PRE.euler_pid.vel_target[2]
*/
void GSQuad_Components_Controller_eqFunction_24(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[118]] /* euler_pid.vel_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[118] /* euler_pid.vel_target[2] DISCRETE */);
  threadData->lastEquationSolved = 24;
}

/*
equation index: 25
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_target[3] = $START.euler_pid.vel_target[3]
*/
void GSQuad_Components_Controller_eqFunction_25(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,25};
  (data->simulationInfo->realVarsPre[119] /* euler_pid.vel_target[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[119] /* euler_pid.vel_target[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 25;
}

/*
equation index: 26
type: SIMPLE_ASSIGN
euler_pid.vel_target[3] = $PRE.euler_pid.vel_target[3]
*/
void GSQuad_Components_Controller_eqFunction_26(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[119]] /* euler_pid.vel_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[119] /* euler_pid.vel_target[3] DISCRETE */);
  threadData->lastEquationSolved = 26;
}

/*
equation index: 27
type: SIMPLE_ASSIGN
$PRE.euler_pid.C_wb[1,1] = $START.euler_pid.C_wb[1,1]
*/
void GSQuad_Components_Controller_eqFunction_27(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,27};
  (data->simulationInfo->realVarsPre[31] /* euler_pid.C_wb[1,1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[31] /* euler_pid.C_wb[1,1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 27;
}

/*
equation index: 28
type: SIMPLE_ASSIGN
euler_pid.C_wb[1,1] = $PRE.euler_pid.C_wb[1,1]
*/
void GSQuad_Components_Controller_eqFunction_28(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,28};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* euler_pid.C_wb[1,1] DISCRETE */) = (data->simulationInfo->realVarsPre[31] /* euler_pid.C_wb[1,1] DISCRETE */);
  threadData->lastEquationSolved = 28;
}

/*
equation index: 29
type: SIMPLE_ASSIGN
$PRE.euler_pid.C_wb[1,2] = $START.euler_pid.C_wb[1,2]
*/
void GSQuad_Components_Controller_eqFunction_29(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,29};
  (data->simulationInfo->realVarsPre[32] /* euler_pid.C_wb[1,2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[32] /* euler_pid.C_wb[1,2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 29;
}

/*
equation index: 30
type: SIMPLE_ASSIGN
euler_pid.C_wb[1,2] = $PRE.euler_pid.C_wb[1,2]
*/
void GSQuad_Components_Controller_eqFunction_30(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,30};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* euler_pid.C_wb[1,2] DISCRETE */) = (data->simulationInfo->realVarsPre[32] /* euler_pid.C_wb[1,2] DISCRETE */);
  threadData->lastEquationSolved = 30;
}

/*
equation index: 31
type: SIMPLE_ASSIGN
$PRE.euler_pid.C_wb[1,3] = $START.euler_pid.C_wb[1,3]
*/
void GSQuad_Components_Controller_eqFunction_31(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,31};
  (data->simulationInfo->realVarsPre[33] /* euler_pid.C_wb[1,3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[33] /* euler_pid.C_wb[1,3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 31;
}

/*
equation index: 32
type: SIMPLE_ASSIGN
euler_pid.C_wb[1,3] = $PRE.euler_pid.C_wb[1,3]
*/
void GSQuad_Components_Controller_eqFunction_32(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,32};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* euler_pid.C_wb[1,3] DISCRETE */) = (data->simulationInfo->realVarsPre[33] /* euler_pid.C_wb[1,3] DISCRETE */);
  threadData->lastEquationSolved = 32;
}

/*
equation index: 33
type: SIMPLE_ASSIGN
$PRE.euler_pid.C_wb[2,1] = $START.euler_pid.C_wb[2,1]
*/
void GSQuad_Components_Controller_eqFunction_33(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,33};
  (data->simulationInfo->realVarsPre[34] /* euler_pid.C_wb[2,1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[34] /* euler_pid.C_wb[2,1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 33;
}

/*
equation index: 34
type: SIMPLE_ASSIGN
euler_pid.C_wb[2,1] = $PRE.euler_pid.C_wb[2,1]
*/
void GSQuad_Components_Controller_eqFunction_34(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,34};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* euler_pid.C_wb[2,1] DISCRETE */) = (data->simulationInfo->realVarsPre[34] /* euler_pid.C_wb[2,1] DISCRETE */);
  threadData->lastEquationSolved = 34;
}

/*
equation index: 35
type: SIMPLE_ASSIGN
$PRE.euler_pid.C_wb[2,2] = $START.euler_pid.C_wb[2,2]
*/
void GSQuad_Components_Controller_eqFunction_35(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,35};
  (data->simulationInfo->realVarsPre[35] /* euler_pid.C_wb[2,2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[35] /* euler_pid.C_wb[2,2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 35;
}

/*
equation index: 36
type: SIMPLE_ASSIGN
euler_pid.C_wb[2,2] = $PRE.euler_pid.C_wb[2,2]
*/
void GSQuad_Components_Controller_eqFunction_36(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,36};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* euler_pid.C_wb[2,2] DISCRETE */) = (data->simulationInfo->realVarsPre[35] /* euler_pid.C_wb[2,2] DISCRETE */);
  threadData->lastEquationSolved = 36;
}

/*
equation index: 37
type: SIMPLE_ASSIGN
$PRE.euler_pid.C_wb[2,3] = $START.euler_pid.C_wb[2,3]
*/
void GSQuad_Components_Controller_eqFunction_37(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,37};
  (data->simulationInfo->realVarsPre[36] /* euler_pid.C_wb[2,3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[36] /* euler_pid.C_wb[2,3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 37;
}

/*
equation index: 38
type: SIMPLE_ASSIGN
euler_pid.C_wb[2,3] = $PRE.euler_pid.C_wb[2,3]
*/
void GSQuad_Components_Controller_eqFunction_38(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,38};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* euler_pid.C_wb[2,3] DISCRETE */) = (data->simulationInfo->realVarsPre[36] /* euler_pid.C_wb[2,3] DISCRETE */);
  threadData->lastEquationSolved = 38;
}

/*
equation index: 39
type: SIMPLE_ASSIGN
$PRE.euler_pid.C_wb[3,1] = $START.euler_pid.C_wb[3,1]
*/
void GSQuad_Components_Controller_eqFunction_39(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,39};
  (data->simulationInfo->realVarsPre[37] /* euler_pid.C_wb[3,1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[37] /* euler_pid.C_wb[3,1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 39;
}

/*
equation index: 40
type: SIMPLE_ASSIGN
euler_pid.C_wb[3,1] = $PRE.euler_pid.C_wb[3,1]
*/
void GSQuad_Components_Controller_eqFunction_40(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,40};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* euler_pid.C_wb[3,1] DISCRETE */) = (data->simulationInfo->realVarsPre[37] /* euler_pid.C_wb[3,1] DISCRETE */);
  threadData->lastEquationSolved = 40;
}

/*
equation index: 41
type: SIMPLE_ASSIGN
$PRE.euler_pid.C_wb[3,2] = $START.euler_pid.C_wb[3,2]
*/
void GSQuad_Components_Controller_eqFunction_41(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,41};
  (data->simulationInfo->realVarsPre[38] /* euler_pid.C_wb[3,2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[38] /* euler_pid.C_wb[3,2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 41;
}

/*
equation index: 42
type: SIMPLE_ASSIGN
euler_pid.C_wb[3,2] = $PRE.euler_pid.C_wb[3,2]
*/
void GSQuad_Components_Controller_eqFunction_42(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,42};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* euler_pid.C_wb[3,2] DISCRETE */) = (data->simulationInfo->realVarsPre[38] /* euler_pid.C_wb[3,2] DISCRETE */);
  threadData->lastEquationSolved = 42;
}

/*
equation index: 43
type: SIMPLE_ASSIGN
$PRE.euler_pid.C_wb[3,3] = $START.euler_pid.C_wb[3,3]
*/
void GSQuad_Components_Controller_eqFunction_43(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,43};
  (data->simulationInfo->realVarsPre[39] /* euler_pid.C_wb[3,3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[39] /* euler_pid.C_wb[3,3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 43;
}

/*
equation index: 44
type: SIMPLE_ASSIGN
euler_pid.C_wb[3,3] = $PRE.euler_pid.C_wb[3,3]
*/
void GSQuad_Components_Controller_eqFunction_44(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,44};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* euler_pid.C_wb[3,3] DISCRETE */) = (data->simulationInfo->realVarsPre[39] /* euler_pid.C_wb[3,3] DISCRETE */);
  threadData->lastEquationSolved = 44;
}

/*
equation index: 45
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error[1] = $START.euler_pid.vel_error[1]
*/
void GSQuad_Components_Controller_eqFunction_45(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,45};
  (data->simulationInfo->realVarsPre[105] /* euler_pid.vel_error[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[105] /* euler_pid.vel_error[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 45;
}

/*
equation index: 46
type: SIMPLE_ASSIGN
euler_pid.vel_error[1] = $PRE.euler_pid.vel_error[1]
*/
void GSQuad_Components_Controller_eqFunction_46(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,46};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* euler_pid.vel_error[1] DISCRETE */) = (data->simulationInfo->realVarsPre[105] /* euler_pid.vel_error[1] DISCRETE */);
  threadData->lastEquationSolved = 46;
}

/*
equation index: 47
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error[2] = $START.euler_pid.vel_error[2]
*/
void GSQuad_Components_Controller_eqFunction_47(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,47};
  (data->simulationInfo->realVarsPre[106] /* euler_pid.vel_error[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[106] /* euler_pid.vel_error[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 47;
}

/*
equation index: 48
type: SIMPLE_ASSIGN
euler_pid.vel_error[2] = $PRE.euler_pid.vel_error[2]
*/
void GSQuad_Components_Controller_eqFunction_48(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,48};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* euler_pid.vel_error[2] DISCRETE */) = (data->simulationInfo->realVarsPre[106] /* euler_pid.vel_error[2] DISCRETE */);
  threadData->lastEquationSolved = 48;
}

/*
equation index: 49
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error[3] = $START.euler_pid.vel_error[3]
*/
void GSQuad_Components_Controller_eqFunction_49(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,49};
  (data->simulationInfo->realVarsPre[107] /* euler_pid.vel_error[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[107] /* euler_pid.vel_error[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 49;
}

/*
equation index: 50
type: SIMPLE_ASSIGN
euler_pid.vel_error[3] = $PRE.euler_pid.vel_error[3]
*/
void GSQuad_Components_Controller_eqFunction_50(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,50};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* euler_pid.vel_error[3] DISCRETE */) = (data->simulationInfo->realVarsPre[107] /* euler_pid.vel_error[3] DISCRETE */);
  threadData->lastEquationSolved = 50;
}

/*
equation index: 51
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error_i[1] = $START.euler_pid.vel_error_i[1]
*/
void GSQuad_Components_Controller_eqFunction_51(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,51};
  (data->simulationInfo->realVarsPre[111] /* euler_pid.vel_error_i[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[111] /* euler_pid.vel_error_i[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 51;
}

/*
equation index: 52
type: SIMPLE_ASSIGN
euler_pid.vel_error_i[1] = $PRE.euler_pid.vel_error_i[1]
*/
void GSQuad_Components_Controller_eqFunction_52(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,52};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* euler_pid.vel_error_i[1] DISCRETE */) = (data->simulationInfo->realVarsPre[111] /* euler_pid.vel_error_i[1] DISCRETE */);
  threadData->lastEquationSolved = 52;
}

/*
equation index: 53
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error_i[2] = $START.euler_pid.vel_error_i[2]
*/
void GSQuad_Components_Controller_eqFunction_53(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,53};
  (data->simulationInfo->realVarsPre[112] /* euler_pid.vel_error_i[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[112] /* euler_pid.vel_error_i[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 53;
}

/*
equation index: 54
type: SIMPLE_ASSIGN
euler_pid.vel_error_i[2] = $PRE.euler_pid.vel_error_i[2]
*/
void GSQuad_Components_Controller_eqFunction_54(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,54};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[112]] /* euler_pid.vel_error_i[2] DISCRETE */) = (data->simulationInfo->realVarsPre[112] /* euler_pid.vel_error_i[2] DISCRETE */);
  threadData->lastEquationSolved = 54;
}

/*
equation index: 55
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error_i[3] = $START.euler_pid.vel_error_i[3]
*/
void GSQuad_Components_Controller_eqFunction_55(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,55};
  (data->simulationInfo->realVarsPre[113] /* euler_pid.vel_error_i[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[113] /* euler_pid.vel_error_i[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 55;
}

/*
equation index: 56
type: SIMPLE_ASSIGN
euler_pid.vel_error_i[3] = $PRE.euler_pid.vel_error_i[3]
*/
void GSQuad_Components_Controller_eqFunction_56(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,56};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[113]] /* euler_pid.vel_error_i[3] DISCRETE */) = (data->simulationInfo->realVarsPre[113] /* euler_pid.vel_error_i[3] DISCRETE */);
  threadData->lastEquationSolved = 56;
}

/*
equation index: 57
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error_d[1] = $START.euler_pid.vel_error_d[1]
*/
void GSQuad_Components_Controller_eqFunction_57(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,57};
  (data->simulationInfo->realVarsPre[108] /* euler_pid.vel_error_d[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[108] /* euler_pid.vel_error_d[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 57;
}

/*
equation index: 58
type: SIMPLE_ASSIGN
euler_pid.vel_error_d[1] = $PRE.euler_pid.vel_error_d[1]
*/
void GSQuad_Components_Controller_eqFunction_58(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,58};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* euler_pid.vel_error_d[1] DISCRETE */) = (data->simulationInfo->realVarsPre[108] /* euler_pid.vel_error_d[1] DISCRETE */);
  threadData->lastEquationSolved = 58;
}

/*
equation index: 59
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error_d[2] = $START.euler_pid.vel_error_d[2]
*/
void GSQuad_Components_Controller_eqFunction_59(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,59};
  (data->simulationInfo->realVarsPre[109] /* euler_pid.vel_error_d[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[109] /* euler_pid.vel_error_d[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 59;
}

/*
equation index: 60
type: SIMPLE_ASSIGN
euler_pid.vel_error_d[2] = $PRE.euler_pid.vel_error_d[2]
*/
void GSQuad_Components_Controller_eqFunction_60(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,60};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[109]] /* euler_pid.vel_error_d[2] DISCRETE */) = (data->simulationInfo->realVarsPre[109] /* euler_pid.vel_error_d[2] DISCRETE */);
  threadData->lastEquationSolved = 60;
}

/*
equation index: 61
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error_d[3] = $START.euler_pid.vel_error_d[3]
*/
void GSQuad_Components_Controller_eqFunction_61(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,61};
  (data->simulationInfo->realVarsPre[110] /* euler_pid.vel_error_d[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[110] /* euler_pid.vel_error_d[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 61;
}

/*
equation index: 62
type: SIMPLE_ASSIGN
euler_pid.vel_error_d[3] = $PRE.euler_pid.vel_error_d[3]
*/
void GSQuad_Components_Controller_eqFunction_62(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,62};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[110]] /* euler_pid.vel_error_d[3] DISCRETE */) = (data->simulationInfo->realVarsPre[110] /* euler_pid.vel_error_d[3] DISCRETE */);
  threadData->lastEquationSolved = 62;
}

/*
equation index: 63
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error_last[1] = $START.euler_pid.vel_error_last[1]
*/
void GSQuad_Components_Controller_eqFunction_63(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,63};
  (data->simulationInfo->realVarsPre[114] /* euler_pid.vel_error_last[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[114] /* euler_pid.vel_error_last[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 63;
}

/*
equation index: 64
type: SIMPLE_ASSIGN
euler_pid.vel_error_last[1] = $PRE.euler_pid.vel_error_last[1]
*/
void GSQuad_Components_Controller_eqFunction_64(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,64};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* euler_pid.vel_error_last[1] DISCRETE */) = (data->simulationInfo->realVarsPre[114] /* euler_pid.vel_error_last[1] DISCRETE */);
  threadData->lastEquationSolved = 64;
}

/*
equation index: 65
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error_last[2] = $START.euler_pid.vel_error_last[2]
*/
void GSQuad_Components_Controller_eqFunction_65(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,65};
  (data->simulationInfo->realVarsPre[115] /* euler_pid.vel_error_last[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[115] /* euler_pid.vel_error_last[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 65;
}

/*
equation index: 66
type: SIMPLE_ASSIGN
euler_pid.vel_error_last[2] = $PRE.euler_pid.vel_error_last[2]
*/
void GSQuad_Components_Controller_eqFunction_66(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,66};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[115]] /* euler_pid.vel_error_last[2] DISCRETE */) = (data->simulationInfo->realVarsPre[115] /* euler_pid.vel_error_last[2] DISCRETE */);
  threadData->lastEquationSolved = 66;
}

/*
equation index: 67
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_error_last[3] = $START.euler_pid.vel_error_last[3]
*/
void GSQuad_Components_Controller_eqFunction_67(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,67};
  (data->simulationInfo->realVarsPre[116] /* euler_pid.vel_error_last[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[116] /* euler_pid.vel_error_last[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 67;
}

/*
equation index: 68
type: SIMPLE_ASSIGN
euler_pid.vel_error_last[3] = $PRE.euler_pid.vel_error_last[3]
*/
void GSQuad_Components_Controller_eqFunction_68(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,68};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[116]] /* euler_pid.vel_error_last[3] DISCRETE */) = (data->simulationInfo->realVarsPre[116] /* euler_pid.vel_error_last[3] DISCRETE */);
  threadData->lastEquationSolved = 68;
}

/*
equation index: 69
type: SIMPLE_ASSIGN
$PRE.euler_pid.acc_target[1] = $START.euler_pid.acc_target[1]
*/
void GSQuad_Components_Controller_eqFunction_69(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,69};
  (data->simulationInfo->realVarsPre[42] /* euler_pid.acc_target[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[42] /* euler_pid.acc_target[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 69;
}

/*
equation index: 70
type: SIMPLE_ASSIGN
euler_pid.acc_target[1] = $PRE.euler_pid.acc_target[1]
*/
void GSQuad_Components_Controller_eqFunction_70(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,70};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* euler_pid.acc_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[42] /* euler_pid.acc_target[1] DISCRETE */);
  threadData->lastEquationSolved = 70;
}

/*
equation index: 71
type: SIMPLE_ASSIGN
$PRE.euler_pid.acc_target[2] = $START.euler_pid.acc_target[2]
*/
void GSQuad_Components_Controller_eqFunction_71(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,71};
  (data->simulationInfo->realVarsPre[43] /* euler_pid.acc_target[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[43] /* euler_pid.acc_target[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 71;
}

/*
equation index: 72
type: SIMPLE_ASSIGN
euler_pid.acc_target[2] = $PRE.euler_pid.acc_target[2]
*/
void GSQuad_Components_Controller_eqFunction_72(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,72};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* euler_pid.acc_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[43] /* euler_pid.acc_target[2] DISCRETE */);
  threadData->lastEquationSolved = 72;
}

/*
equation index: 73
type: SIMPLE_ASSIGN
$PRE.euler_pid.acc_target[3] = $START.euler_pid.acc_target[3]
*/
void GSQuad_Components_Controller_eqFunction_73(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,73};
  (data->simulationInfo->realVarsPre[44] /* euler_pid.acc_target[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[44] /* euler_pid.acc_target[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 73;
}

/*
equation index: 74
type: SIMPLE_ASSIGN
euler_pid.acc_target[3] = $PRE.euler_pid.acc_target[3]
*/
void GSQuad_Components_Controller_eqFunction_74(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,74};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* euler_pid.acc_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[44] /* euler_pid.acc_target[3] DISCRETE */);
  threadData->lastEquationSolved = 74;
}

/*
equation index: 75
type: SIMPLE_ASSIGN
$PRE.euler_pid.acc_z_target = $START.euler_pid.acc_z_target
*/
void GSQuad_Components_Controller_eqFunction_75(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,75};
  (data->simulationInfo->realVarsPre[45] /* euler_pid.acc_z_target DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[45] /* euler_pid.acc_z_target DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 75;
}

/*
equation index: 76
type: SIMPLE_ASSIGN
euler_pid.acc_z_target = $PRE.euler_pid.acc_z_target
*/
void GSQuad_Components_Controller_eqFunction_76(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,76};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* euler_pid.acc_z_target DISCRETE */) = (data->simulationInfo->realVarsPre[45] /* euler_pid.acc_z_target DISCRETE */);
  threadData->lastEquationSolved = 76;
}

/*
equation index: 77
type: SIMPLE_ASSIGN
$PRE.euler_pid.acc_fwd_target = $START.euler_pid.acc_fwd_target
*/
void GSQuad_Components_Controller_eqFunction_77(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,77};
  (data->simulationInfo->realVarsPre[40] /* euler_pid.acc_fwd_target DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[40] /* euler_pid.acc_fwd_target DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 77;
}

/*
equation index: 78
type: SIMPLE_ASSIGN
euler_pid.acc_fwd_target = $PRE.euler_pid.acc_fwd_target
*/
void GSQuad_Components_Controller_eqFunction_78(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,78};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* euler_pid.acc_fwd_target DISCRETE */) = (data->simulationInfo->realVarsPre[40] /* euler_pid.acc_fwd_target DISCRETE */);
  threadData->lastEquationSolved = 78;
}

/*
equation index: 79
type: SIMPLE_ASSIGN
$PRE.euler_pid.acc_rgt_target = $START.euler_pid.acc_rgt_target
*/
void GSQuad_Components_Controller_eqFunction_79(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,79};
  (data->simulationInfo->realVarsPre[41] /* euler_pid.acc_rgt_target DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[41] /* euler_pid.acc_rgt_target DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 79;
}

/*
equation index: 80
type: SIMPLE_ASSIGN
euler_pid.acc_rgt_target = $PRE.euler_pid.acc_rgt_target
*/
void GSQuad_Components_Controller_eqFunction_80(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,80};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* euler_pid.acc_rgt_target DISCRETE */) = (data->simulationInfo->realVarsPre[41] /* euler_pid.acc_rgt_target DISCRETE */);
  threadData->lastEquationSolved = 80;
}

/*
equation index: 81
type: SIMPLE_ASSIGN
$PRE.euler_pid.pitch_target = $START.euler_pid.pitch_target
*/
void GSQuad_Components_Controller_eqFunction_81(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,81};
  (data->simulationInfo->realVarsPre[72] /* euler_pid.pitch_target DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[72] /* euler_pid.pitch_target DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 81;
}

/*
equation index: 82
type: SIMPLE_ASSIGN
euler_pid.pitch_target = $PRE.euler_pid.pitch_target
*/
void GSQuad_Components_Controller_eqFunction_82(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,82};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* euler_pid.pitch_target DISCRETE */) = (data->simulationInfo->realVarsPre[72] /* euler_pid.pitch_target DISCRETE */);
  threadData->lastEquationSolved = 82;
}

/*
equation index: 83
type: SIMPLE_ASSIGN
$PRE.euler_pid.roll_target = $START.euler_pid.roll_target
*/
void GSQuad_Components_Controller_eqFunction_83(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,83};
  (data->simulationInfo->realVarsPre[100] /* euler_pid.roll_target DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[100] /* euler_pid.roll_target DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 83;
}

/*
equation index: 84
type: SIMPLE_ASSIGN
euler_pid.roll_target = $PRE.euler_pid.roll_target
*/
void GSQuad_Components_Controller_eqFunction_84(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,84};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[100]] /* euler_pid.roll_target DISCRETE */) = (data->simulationInfo->realVarsPre[100] /* euler_pid.roll_target DISCRETE */);
  threadData->lastEquationSolved = 84;
}

/*
equation index: 85
type: SIMPLE_ASSIGN
$PRE.euler_pid.yaw_target = $START.euler_pid.yaw_target
*/
void GSQuad_Components_Controller_eqFunction_85(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,85};
  (data->simulationInfo->realVarsPre[124] /* euler_pid.yaw_target DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[124] /* euler_pid.yaw_target DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 85;
}

/*
equation index: 86
type: SIMPLE_ASSIGN
euler_pid.yaw_target = $PRE.euler_pid.yaw_target
*/
void GSQuad_Components_Controller_eqFunction_86(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,86};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[124]] /* euler_pid.yaw_target DISCRETE */) = (data->simulationInfo->realVarsPre[124] /* euler_pid.yaw_target DISCRETE */);
  threadData->lastEquationSolved = 86;
}

/*
equation index: 87
type: SIMPLE_ASSIGN
$PRE.euler_pid.att_error[1] = $START.euler_pid.att_error[1]
*/
void GSQuad_Components_Controller_eqFunction_87(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,87};
  (data->simulationInfo->realVarsPre[49] /* euler_pid.att_error[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[49] /* euler_pid.att_error[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 87;
}

/*
equation index: 88
type: SIMPLE_ASSIGN
euler_pid.att_error[1] = $PRE.euler_pid.att_error[1]
*/
void GSQuad_Components_Controller_eqFunction_88(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,88};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* euler_pid.att_error[1] DISCRETE */) = (data->simulationInfo->realVarsPre[49] /* euler_pid.att_error[1] DISCRETE */);
  threadData->lastEquationSolved = 88;
}

/*
equation index: 89
type: SIMPLE_ASSIGN
$PRE.euler_pid.att_error[2] = $START.euler_pid.att_error[2]
*/
void GSQuad_Components_Controller_eqFunction_89(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,89};
  (data->simulationInfo->realVarsPre[50] /* euler_pid.att_error[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[50] /* euler_pid.att_error[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 89;
}

/*
equation index: 90
type: SIMPLE_ASSIGN
euler_pid.att_error[2] = $PRE.euler_pid.att_error[2]
*/
void GSQuad_Components_Controller_eqFunction_90(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,90};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* euler_pid.att_error[2] DISCRETE */) = (data->simulationInfo->realVarsPre[50] /* euler_pid.att_error[2] DISCRETE */);
  threadData->lastEquationSolved = 90;
}

/*
equation index: 91
type: SIMPLE_ASSIGN
$PRE.euler_pid.att_error[3] = $START.euler_pid.att_error[3]
*/
void GSQuad_Components_Controller_eqFunction_91(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,91};
  (data->simulationInfo->realVarsPre[51] /* euler_pid.att_error[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[51] /* euler_pid.att_error[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 91;
}

/*
equation index: 92
type: SIMPLE_ASSIGN
euler_pid.att_error[3] = $PRE.euler_pid.att_error[3]
*/
void GSQuad_Components_Controller_eqFunction_92(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,92};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* euler_pid.att_error[3] DISCRETE */) = (data->simulationInfo->realVarsPre[51] /* euler_pid.att_error[3] DISCRETE */);
  threadData->lastEquationSolved = 92;
}

/*
equation index: 93
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_target[1] = $START.euler_pid.rate_target[1]
*/
void GSQuad_Components_Controller_eqFunction_93(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,93};
  (data->simulationInfo->realVarsPre[94] /* euler_pid.rate_target[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[94] /* euler_pid.rate_target[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 93;
}

/*
equation index: 94
type: SIMPLE_ASSIGN
euler_pid.rate_target[1] = $PRE.euler_pid.rate_target[1]
*/
void GSQuad_Components_Controller_eqFunction_94(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,94};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* euler_pid.rate_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[94] /* euler_pid.rate_target[1] DISCRETE */);
  threadData->lastEquationSolved = 94;
}

/*
equation index: 95
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_target[2] = $START.euler_pid.rate_target[2]
*/
void GSQuad_Components_Controller_eqFunction_95(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,95};
  (data->simulationInfo->realVarsPre[95] /* euler_pid.rate_target[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[95] /* euler_pid.rate_target[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 95;
}

/*
equation index: 96
type: SIMPLE_ASSIGN
euler_pid.rate_target[2] = $PRE.euler_pid.rate_target[2]
*/
void GSQuad_Components_Controller_eqFunction_96(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,96};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* euler_pid.rate_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[95] /* euler_pid.rate_target[2] DISCRETE */);
  threadData->lastEquationSolved = 96;
}

/*
equation index: 97
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_target[3] = $START.euler_pid.rate_target[3]
*/
void GSQuad_Components_Controller_eqFunction_97(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,97};
  (data->simulationInfo->realVarsPre[96] /* euler_pid.rate_target[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[96] /* euler_pid.rate_target[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 97;
}

/*
equation index: 98
type: SIMPLE_ASSIGN
euler_pid.rate_target[3] = $PRE.euler_pid.rate_target[3]
*/
void GSQuad_Components_Controller_eqFunction_98(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,98};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* euler_pid.rate_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[96] /* euler_pid.rate_target[3] DISCRETE */);
  threadData->lastEquationSolved = 98;
}

/*
equation index: 99
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error[1] = $START.euler_pid.rate_error[1]
*/
void GSQuad_Components_Controller_eqFunction_99(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,99};
  (data->simulationInfo->realVarsPre[82] /* euler_pid.rate_error[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[82] /* euler_pid.rate_error[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 99;
}

/*
equation index: 100
type: SIMPLE_ASSIGN
euler_pid.rate_error[1] = $PRE.euler_pid.rate_error[1]
*/
void GSQuad_Components_Controller_eqFunction_100(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,100};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* euler_pid.rate_error[1] DISCRETE */) = (data->simulationInfo->realVarsPre[82] /* euler_pid.rate_error[1] DISCRETE */);
  threadData->lastEquationSolved = 100;
}

/*
equation index: 101
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error[2] = $START.euler_pid.rate_error[2]
*/
void GSQuad_Components_Controller_eqFunction_101(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,101};
  (data->simulationInfo->realVarsPre[83] /* euler_pid.rate_error[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[83] /* euler_pid.rate_error[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 101;
}

/*
equation index: 102
type: SIMPLE_ASSIGN
euler_pid.rate_error[2] = $PRE.euler_pid.rate_error[2]
*/
void GSQuad_Components_Controller_eqFunction_102(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,102};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* euler_pid.rate_error[2] DISCRETE */) = (data->simulationInfo->realVarsPre[83] /* euler_pid.rate_error[2] DISCRETE */);
  threadData->lastEquationSolved = 102;
}

/*
equation index: 103
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error[3] = $START.euler_pid.rate_error[3]
*/
void GSQuad_Components_Controller_eqFunction_103(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,103};
  (data->simulationInfo->realVarsPre[84] /* euler_pid.rate_error[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[84] /* euler_pid.rate_error[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 103;
}

/*
equation index: 104
type: SIMPLE_ASSIGN
euler_pid.rate_error[3] = $PRE.euler_pid.rate_error[3]
*/
void GSQuad_Components_Controller_eqFunction_104(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,104};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* euler_pid.rate_error[3] DISCRETE */) = (data->simulationInfo->realVarsPre[84] /* euler_pid.rate_error[3] DISCRETE */);
  threadData->lastEquationSolved = 104;
}

/*
equation index: 105
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error_i[1] = $START.euler_pid.rate_error_i[1]
*/
void GSQuad_Components_Controller_eqFunction_105(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,105};
  (data->simulationInfo->realVarsPre[88] /* euler_pid.rate_error_i[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[88] /* euler_pid.rate_error_i[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 105;
}

/*
equation index: 106
type: SIMPLE_ASSIGN
euler_pid.rate_error_i[1] = $PRE.euler_pid.rate_error_i[1]
*/
void GSQuad_Components_Controller_eqFunction_106(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,106};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* euler_pid.rate_error_i[1] DISCRETE */) = (data->simulationInfo->realVarsPre[88] /* euler_pid.rate_error_i[1] DISCRETE */);
  threadData->lastEquationSolved = 106;
}

/*
equation index: 107
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error_i[2] = $START.euler_pid.rate_error_i[2]
*/
void GSQuad_Components_Controller_eqFunction_107(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,107};
  (data->simulationInfo->realVarsPre[89] /* euler_pid.rate_error_i[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[89] /* euler_pid.rate_error_i[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 107;
}

/*
equation index: 108
type: SIMPLE_ASSIGN
euler_pid.rate_error_i[2] = $PRE.euler_pid.rate_error_i[2]
*/
void GSQuad_Components_Controller_eqFunction_108(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,108};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* euler_pid.rate_error_i[2] DISCRETE */) = (data->simulationInfo->realVarsPre[89] /* euler_pid.rate_error_i[2] DISCRETE */);
  threadData->lastEquationSolved = 108;
}

/*
equation index: 109
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error_i[3] = $START.euler_pid.rate_error_i[3]
*/
void GSQuad_Components_Controller_eqFunction_109(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,109};
  (data->simulationInfo->realVarsPre[90] /* euler_pid.rate_error_i[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[90] /* euler_pid.rate_error_i[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 109;
}

/*
equation index: 110
type: SIMPLE_ASSIGN
euler_pid.rate_error_i[3] = $PRE.euler_pid.rate_error_i[3]
*/
void GSQuad_Components_Controller_eqFunction_110(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,110};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* euler_pid.rate_error_i[3] DISCRETE */) = (data->simulationInfo->realVarsPre[90] /* euler_pid.rate_error_i[3] DISCRETE */);
  threadData->lastEquationSolved = 110;
}

/*
equation index: 111
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error_d[1] = $START.euler_pid.rate_error_d[1]
*/
void GSQuad_Components_Controller_eqFunction_111(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,111};
  (data->simulationInfo->realVarsPre[85] /* euler_pid.rate_error_d[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[85] /* euler_pid.rate_error_d[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 111;
}

/*
equation index: 112
type: SIMPLE_ASSIGN
euler_pid.rate_error_d[1] = $PRE.euler_pid.rate_error_d[1]
*/
void GSQuad_Components_Controller_eqFunction_112(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,112};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* euler_pid.rate_error_d[1] DISCRETE */) = (data->simulationInfo->realVarsPre[85] /* euler_pid.rate_error_d[1] DISCRETE */);
  threadData->lastEquationSolved = 112;
}

/*
equation index: 113
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error_d[2] = $START.euler_pid.rate_error_d[2]
*/
void GSQuad_Components_Controller_eqFunction_113(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,113};
  (data->simulationInfo->realVarsPre[86] /* euler_pid.rate_error_d[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[86] /* euler_pid.rate_error_d[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 113;
}

/*
equation index: 114
type: SIMPLE_ASSIGN
euler_pid.rate_error_d[2] = $PRE.euler_pid.rate_error_d[2]
*/
void GSQuad_Components_Controller_eqFunction_114(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,114};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* euler_pid.rate_error_d[2] DISCRETE */) = (data->simulationInfo->realVarsPre[86] /* euler_pid.rate_error_d[2] DISCRETE */);
  threadData->lastEquationSolved = 114;
}

/*
equation index: 115
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error_d[3] = $START.euler_pid.rate_error_d[3]
*/
void GSQuad_Components_Controller_eqFunction_115(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,115};
  (data->simulationInfo->realVarsPre[87] /* euler_pid.rate_error_d[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[87] /* euler_pid.rate_error_d[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 115;
}

/*
equation index: 116
type: SIMPLE_ASSIGN
euler_pid.rate_error_d[3] = $PRE.euler_pid.rate_error_d[3]
*/
void GSQuad_Components_Controller_eqFunction_116(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,116};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* euler_pid.rate_error_d[3] DISCRETE */) = (data->simulationInfo->realVarsPre[87] /* euler_pid.rate_error_d[3] DISCRETE */);
  threadData->lastEquationSolved = 116;
}

/*
equation index: 117
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error_last[1] = $START.euler_pid.rate_error_last[1]
*/
void GSQuad_Components_Controller_eqFunction_117(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,117};
  (data->simulationInfo->realVarsPre[91] /* euler_pid.rate_error_last[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[91] /* euler_pid.rate_error_last[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 117;
}

/*
equation index: 118
type: SIMPLE_ASSIGN
euler_pid.rate_error_last[1] = $PRE.euler_pid.rate_error_last[1]
*/
void GSQuad_Components_Controller_eqFunction_118(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,118};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* euler_pid.rate_error_last[1] DISCRETE */) = (data->simulationInfo->realVarsPre[91] /* euler_pid.rate_error_last[1] DISCRETE */);
  threadData->lastEquationSolved = 118;
}

/*
equation index: 119
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error_last[2] = $START.euler_pid.rate_error_last[2]
*/
void GSQuad_Components_Controller_eqFunction_119(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,119};
  (data->simulationInfo->realVarsPre[92] /* euler_pid.rate_error_last[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[92] /* euler_pid.rate_error_last[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 119;
}

/*
equation index: 120
type: SIMPLE_ASSIGN
euler_pid.rate_error_last[2] = $PRE.euler_pid.rate_error_last[2]
*/
void GSQuad_Components_Controller_eqFunction_120(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,120};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* euler_pid.rate_error_last[2] DISCRETE */) = (data->simulationInfo->realVarsPre[92] /* euler_pid.rate_error_last[2] DISCRETE */);
  threadData->lastEquationSolved = 120;
}

/*
equation index: 121
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_error_last[3] = $START.euler_pid.rate_error_last[3]
*/
void GSQuad_Components_Controller_eqFunction_121(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,121};
  (data->simulationInfo->realVarsPre[93] /* euler_pid.rate_error_last[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[93] /* euler_pid.rate_error_last[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 121;
}

/*
equation index: 122
type: SIMPLE_ASSIGN
euler_pid.rate_error_last[3] = $PRE.euler_pid.rate_error_last[3]
*/
void GSQuad_Components_Controller_eqFunction_122(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,122};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* euler_pid.rate_error_last[3] DISCRETE */) = (data->simulationInfo->realVarsPre[93] /* euler_pid.rate_error_last[3] DISCRETE */);
  threadData->lastEquationSolved = 122;
}

/*
equation index: 123
type: SIMPLE_ASSIGN
$PRE.euler_pid.moment_target[1] = $START.euler_pid.moment_target[1]
*/
void GSQuad_Components_Controller_eqFunction_123(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,123};
  (data->simulationInfo->realVarsPre[61] /* euler_pid.moment_target[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[61] /* euler_pid.moment_target[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 123;
}

/*
equation index: 124
type: SIMPLE_ASSIGN
euler_pid.moment_target[1] = $PRE.euler_pid.moment_target[1]
*/
void GSQuad_Components_Controller_eqFunction_124(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,124};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* euler_pid.moment_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[61] /* euler_pid.moment_target[1] DISCRETE */);
  threadData->lastEquationSolved = 124;
}

/*
equation index: 125
type: SIMPLE_ASSIGN
$PRE.euler_pid.moment_target[2] = $START.euler_pid.moment_target[2]
*/
void GSQuad_Components_Controller_eqFunction_125(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,125};
  (data->simulationInfo->realVarsPre[62] /* euler_pid.moment_target[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[62] /* euler_pid.moment_target[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 125;
}

/*
equation index: 126
type: SIMPLE_ASSIGN
euler_pid.moment_target[2] = $PRE.euler_pid.moment_target[2]
*/
void GSQuad_Components_Controller_eqFunction_126(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,126};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* euler_pid.moment_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[62] /* euler_pid.moment_target[2] DISCRETE */);
  threadData->lastEquationSolved = 126;
}

/*
equation index: 127
type: SIMPLE_ASSIGN
$PRE.euler_pid.moment_target[3] = $START.euler_pid.moment_target[3]
*/
void GSQuad_Components_Controller_eqFunction_127(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,127};
  (data->simulationInfo->realVarsPre[63] /* euler_pid.moment_target[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[63] /* euler_pid.moment_target[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 127;
}

/*
equation index: 128
type: SIMPLE_ASSIGN
euler_pid.moment_target[3] = $PRE.euler_pid.moment_target[3]
*/
void GSQuad_Components_Controller_eqFunction_128(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,128};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* euler_pid.moment_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[63] /* euler_pid.moment_target[3] DISCRETE */);
  threadData->lastEquationSolved = 128;
}

/*
equation index: 129
type: SIMPLE_ASSIGN
$PRE.euler_pid.att_body_thrust_vec[1] = $START.euler_pid.att_body_thrust_vec[1]
*/
void GSQuad_Components_Controller_eqFunction_129(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,129};
  (data->simulationInfo->realVarsPre[46] /* euler_pid.att_body_thrust_vec[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[46] /* euler_pid.att_body_thrust_vec[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 129;
}

/*
equation index: 130
type: SIMPLE_ASSIGN
euler_pid.att_body_thrust_vec[1] = $PRE.euler_pid.att_body_thrust_vec[1]
*/
void GSQuad_Components_Controller_eqFunction_130(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,130};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* euler_pid.att_body_thrust_vec[1] DISCRETE */) = (data->simulationInfo->realVarsPre[46] /* euler_pid.att_body_thrust_vec[1] DISCRETE */);
  threadData->lastEquationSolved = 130;
}

/*
equation index: 131
type: SIMPLE_ASSIGN
$PRE.euler_pid.att_body_thrust_vec[2] = $START.euler_pid.att_body_thrust_vec[2]
*/
void GSQuad_Components_Controller_eqFunction_131(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,131};
  (data->simulationInfo->realVarsPre[47] /* euler_pid.att_body_thrust_vec[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[47] /* euler_pid.att_body_thrust_vec[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 131;
}

/*
equation index: 132
type: SIMPLE_ASSIGN
euler_pid.att_body_thrust_vec[2] = $PRE.euler_pid.att_body_thrust_vec[2]
*/
void GSQuad_Components_Controller_eqFunction_132(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,132};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* euler_pid.att_body_thrust_vec[2] DISCRETE */) = (data->simulationInfo->realVarsPre[47] /* euler_pid.att_body_thrust_vec[2] DISCRETE */);
  threadData->lastEquationSolved = 132;
}

/*
equation index: 133
type: SIMPLE_ASSIGN
$PRE.euler_pid.att_body_thrust_vec[3] = $START.euler_pid.att_body_thrust_vec[3]
*/
void GSQuad_Components_Controller_eqFunction_133(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,133};
  (data->simulationInfo->realVarsPre[48] /* euler_pid.att_body_thrust_vec[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[48] /* euler_pid.att_body_thrust_vec[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 133;
}

/*
equation index: 134
type: SIMPLE_ASSIGN
euler_pid.att_body_thrust_vec[3] = $PRE.euler_pid.att_body_thrust_vec[3]
*/
void GSQuad_Components_Controller_eqFunction_134(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,134};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* euler_pid.att_body_thrust_vec[3] DISCRETE */) = (data->simulationInfo->realVarsPre[48] /* euler_pid.att_body_thrust_vec[3] DISCRETE */);
  threadData->lastEquationSolved = 134;
}

/*
equation index: 135
type: SIMPLE_ASSIGN
$PRE.euler_pid.lean_angle = $START.euler_pid.lean_angle
*/
void GSQuad_Components_Controller_eqFunction_135(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,135};
  (data->simulationInfo->realVarsPre[60] /* euler_pid.lean_angle DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[60] /* euler_pid.lean_angle DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 135;
}

/*
equation index: 136
type: SIMPLE_ASSIGN
euler_pid.lean_angle = $PRE.euler_pid.lean_angle
*/
void GSQuad_Components_Controller_eqFunction_136(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,136};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* euler_pid.lean_angle DISCRETE */) = (data->simulationInfo->realVarsPre[60] /* euler_pid.lean_angle DISCRETE */);
  threadData->lastEquationSolved = 136;
}

/*
equation index: 137
type: SIMPLE_ASSIGN
$PRE.euler_pid.force_target = $START.euler_pid.force_target
*/
void GSQuad_Components_Controller_eqFunction_137(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,137};
  (data->simulationInfo->realVarsPre[59] /* euler_pid.force_target DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[59] /* euler_pid.force_target DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 137;
}

/*
equation index: 138
type: SIMPLE_ASSIGN
euler_pid.force_target = $PRE.euler_pid.force_target
*/
void GSQuad_Components_Controller_eqFunction_138(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,138};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* euler_pid.force_target DISCRETE */) = (data->simulationInfo->realVarsPre[59] /* euler_pid.force_target DISCRETE */);
  threadData->lastEquationSolved = 138;
}

/*
equation index: 139
type: SIMPLE_ASSIGN
$PRE.euler_pid.fm_target[1] = $START.euler_pid.fm_target[1]
*/
void GSQuad_Components_Controller_eqFunction_139(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,139};
  (data->simulationInfo->realVarsPre[55] /* euler_pid.fm_target[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[55] /* euler_pid.fm_target[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 139;
}

/*
equation index: 140
type: SIMPLE_ASSIGN
euler_pid.fm_target[1] = $PRE.euler_pid.fm_target[1]
*/
void GSQuad_Components_Controller_eqFunction_140(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,140};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* euler_pid.fm_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[55] /* euler_pid.fm_target[1] DISCRETE */);
  threadData->lastEquationSolved = 140;
}

/*
equation index: 141
type: SIMPLE_ASSIGN
$PRE.euler_pid.fm_target[2] = $START.euler_pid.fm_target[2]
*/
void GSQuad_Components_Controller_eqFunction_141(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,141};
  (data->simulationInfo->realVarsPre[56] /* euler_pid.fm_target[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[56] /* euler_pid.fm_target[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 141;
}

/*
equation index: 142
type: SIMPLE_ASSIGN
euler_pid.fm_target[2] = $PRE.euler_pid.fm_target[2]
*/
void GSQuad_Components_Controller_eqFunction_142(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,142};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* euler_pid.fm_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[56] /* euler_pid.fm_target[2] DISCRETE */);
  threadData->lastEquationSolved = 142;
}

/*
equation index: 143
type: SIMPLE_ASSIGN
$PRE.euler_pid.fm_target[3] = $START.euler_pid.fm_target[3]
*/
void GSQuad_Components_Controller_eqFunction_143(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,143};
  (data->simulationInfo->realVarsPre[57] /* euler_pid.fm_target[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[57] /* euler_pid.fm_target[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 143;
}

/*
equation index: 144
type: SIMPLE_ASSIGN
euler_pid.fm_target[3] = $PRE.euler_pid.fm_target[3]
*/
void GSQuad_Components_Controller_eqFunction_144(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,144};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* euler_pid.fm_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[57] /* euler_pid.fm_target[3] DISCRETE */);
  threadData->lastEquationSolved = 144;
}

/*
equation index: 145
type: SIMPLE_ASSIGN
$PRE.euler_pid.fm_target[4] = $START.euler_pid.fm_target[4]
*/
void GSQuad_Components_Controller_eqFunction_145(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,145};
  (data->simulationInfo->realVarsPre[58] /* euler_pid.fm_target[4] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[58] /* euler_pid.fm_target[4] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 145;
}

/*
equation index: 146
type: SIMPLE_ASSIGN
euler_pid.fm_target[4] = $PRE.euler_pid.fm_target[4]
*/
void GSQuad_Components_Controller_eqFunction_146(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,146};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* euler_pid.fm_target[4] DISCRETE */) = (data->simulationInfo->realVarsPre[58] /* euler_pid.fm_target[4] DISCRETE */);
  threadData->lastEquationSolved = 146;
}

/*
equation index: 147
type: SIMPLE_ASSIGN
$PRE.euler_pid.thrust_target[1] = $START.euler_pid.thrust_target[1]
*/
void GSQuad_Components_Controller_eqFunction_147(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,147};
  (data->simulationInfo->realVarsPre[101] /* euler_pid.thrust_target[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[101] /* euler_pid.thrust_target[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 147;
}

/*
equation index: 148
type: SIMPLE_ASSIGN
euler_pid.thrust_target[1] = $PRE.euler_pid.thrust_target[1]
*/
void GSQuad_Components_Controller_eqFunction_148(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,148};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[101]] /* euler_pid.thrust_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[101] /* euler_pid.thrust_target[1] DISCRETE */);
  threadData->lastEquationSolved = 148;
}

/*
equation index: 149
type: SIMPLE_ASSIGN
$PRE.euler_pid.thrust_target[2] = $START.euler_pid.thrust_target[2]
*/
void GSQuad_Components_Controller_eqFunction_149(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,149};
  (data->simulationInfo->realVarsPre[102] /* euler_pid.thrust_target[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[102] /* euler_pid.thrust_target[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 149;
}

/*
equation index: 150
type: SIMPLE_ASSIGN
euler_pid.thrust_target[2] = $PRE.euler_pid.thrust_target[2]
*/
void GSQuad_Components_Controller_eqFunction_150(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,150};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[102]] /* euler_pid.thrust_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[102] /* euler_pid.thrust_target[2] DISCRETE */);
  threadData->lastEquationSolved = 150;
}

/*
equation index: 151
type: SIMPLE_ASSIGN
$PRE.euler_pid.thrust_target[3] = $START.euler_pid.thrust_target[3]
*/
void GSQuad_Components_Controller_eqFunction_151(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,151};
  (data->simulationInfo->realVarsPre[103] /* euler_pid.thrust_target[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[103] /* euler_pid.thrust_target[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 151;
}

/*
equation index: 152
type: SIMPLE_ASSIGN
euler_pid.thrust_target[3] = $PRE.euler_pid.thrust_target[3]
*/
void GSQuad_Components_Controller_eqFunction_152(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,152};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[103]] /* euler_pid.thrust_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[103] /* euler_pid.thrust_target[3] DISCRETE */);
  threadData->lastEquationSolved = 152;
}

/*
equation index: 153
type: SIMPLE_ASSIGN
$PRE.euler_pid.thrust_target[4] = $START.euler_pid.thrust_target[4]
*/
void GSQuad_Components_Controller_eqFunction_153(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,153};
  (data->simulationInfo->realVarsPre[104] /* euler_pid.thrust_target[4] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[104] /* euler_pid.thrust_target[4] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 153;
}

/*
equation index: 154
type: SIMPLE_ASSIGN
euler_pid.thrust_target[4] = $PRE.euler_pid.thrust_target[4]
*/
void GSQuad_Components_Controller_eqFunction_154(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,154};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* euler_pid.thrust_target[4] DISCRETE */) = (data->simulationInfo->realVarsPre[104] /* euler_pid.thrust_target[4] DISCRETE */);
  threadData->lastEquationSolved = 154;
}

/*
equation index: 155
type: SIMPLE_ASSIGN
$PRE.euler_pid.omega_spd_sq_target[1] = $START.euler_pid.omega_spd_sq_target[1]
*/
void GSQuad_Components_Controller_eqFunction_155(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,155};
  (data->simulationInfo->realVarsPre[68] /* euler_pid.omega_spd_sq_target[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[68] /* euler_pid.omega_spd_sq_target[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 155;
}

/*
equation index: 156
type: SIMPLE_ASSIGN
euler_pid.omega_spd_sq_target[1] = $PRE.euler_pid.omega_spd_sq_target[1]
*/
void GSQuad_Components_Controller_eqFunction_156(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,156};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* euler_pid.omega_spd_sq_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[68] /* euler_pid.omega_spd_sq_target[1] DISCRETE */);
  threadData->lastEquationSolved = 156;
}

/*
equation index: 157
type: SIMPLE_ASSIGN
$PRE.euler_pid.omega_spd_sq_target[2] = $START.euler_pid.omega_spd_sq_target[2]
*/
void GSQuad_Components_Controller_eqFunction_157(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,157};
  (data->simulationInfo->realVarsPre[69] /* euler_pid.omega_spd_sq_target[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[69] /* euler_pid.omega_spd_sq_target[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 157;
}

/*
equation index: 158
type: SIMPLE_ASSIGN
euler_pid.omega_spd_sq_target[2] = $PRE.euler_pid.omega_spd_sq_target[2]
*/
void GSQuad_Components_Controller_eqFunction_158(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,158};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* euler_pid.omega_spd_sq_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[69] /* euler_pid.omega_spd_sq_target[2] DISCRETE */);
  threadData->lastEquationSolved = 158;
}

/*
equation index: 159
type: SIMPLE_ASSIGN
$PRE.euler_pid.omega_spd_sq_target[3] = $START.euler_pid.omega_spd_sq_target[3]
*/
void GSQuad_Components_Controller_eqFunction_159(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,159};
  (data->simulationInfo->realVarsPre[70] /* euler_pid.omega_spd_sq_target[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[70] /* euler_pid.omega_spd_sq_target[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 159;
}

/*
equation index: 160
type: SIMPLE_ASSIGN
euler_pid.omega_spd_sq_target[3] = $PRE.euler_pid.omega_spd_sq_target[3]
*/
void GSQuad_Components_Controller_eqFunction_160(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,160};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* euler_pid.omega_spd_sq_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[70] /* euler_pid.omega_spd_sq_target[3] DISCRETE */);
  threadData->lastEquationSolved = 160;
}

/*
equation index: 161
type: SIMPLE_ASSIGN
$PRE.euler_pid.omega_spd_sq_target[4] = $START.euler_pid.omega_spd_sq_target[4]
*/
void GSQuad_Components_Controller_eqFunction_161(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,161};
  (data->simulationInfo->realVarsPre[71] /* euler_pid.omega_spd_sq_target[4] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[71] /* euler_pid.omega_spd_sq_target[4] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 161;
}

/*
equation index: 162
type: SIMPLE_ASSIGN
euler_pid.omega_spd_sq_target[4] = $PRE.euler_pid.omega_spd_sq_target[4]
*/
void GSQuad_Components_Controller_eqFunction_162(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,162};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* euler_pid.omega_spd_sq_target[4] DISCRETE */) = (data->simulationInfo->realVarsPre[71] /* euler_pid.omega_spd_sq_target[4] DISCRETE */);
  threadData->lastEquationSolved = 162;
}

/*
equation index: 163
type: SIMPLE_ASSIGN
$PRE.euler_pid.position_setpoint[1] = $START.euler_pid.position_setpoint[1]
*/
void GSQuad_Components_Controller_eqFunction_163(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,163};
  (data->simulationInfo->realVarsPre[79] /* euler_pid.position_setpoint[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[79] /* euler_pid.position_setpoint[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 163;
}

/*
equation index: 164
type: SIMPLE_ASSIGN
euler_pid.position_setpoint[1] = $PRE.euler_pid.position_setpoint[1]
*/
void GSQuad_Components_Controller_eqFunction_164(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,164};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* euler_pid.position_setpoint[1] DISCRETE */) = (data->simulationInfo->realVarsPre[79] /* euler_pid.position_setpoint[1] DISCRETE */);
  threadData->lastEquationSolved = 164;
}

/*
equation index: 165
type: SIMPLE_ASSIGN
$PRE.euler_pid.position_setpoint[2] = $START.euler_pid.position_setpoint[2]
*/
void GSQuad_Components_Controller_eqFunction_165(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,165};
  (data->simulationInfo->realVarsPre[80] /* euler_pid.position_setpoint[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[80] /* euler_pid.position_setpoint[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 165;
}

/*
equation index: 166
type: SIMPLE_ASSIGN
euler_pid.position_setpoint[2] = $PRE.euler_pid.position_setpoint[2]
*/
void GSQuad_Components_Controller_eqFunction_166(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,166};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* euler_pid.position_setpoint[2] DISCRETE */) = (data->simulationInfo->realVarsPre[80] /* euler_pid.position_setpoint[2] DISCRETE */);
  threadData->lastEquationSolved = 166;
}

/*
equation index: 167
type: SIMPLE_ASSIGN
$PRE.euler_pid.position_setpoint[3] = $START.euler_pid.position_setpoint[3]
*/
void GSQuad_Components_Controller_eqFunction_167(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,167};
  (data->simulationInfo->realVarsPre[81] /* euler_pid.position_setpoint[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[81] /* euler_pid.position_setpoint[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 167;
}

/*
equation index: 168
type: SIMPLE_ASSIGN
euler_pid.position_setpoint[3] = $PRE.euler_pid.position_setpoint[3]
*/
void GSQuad_Components_Controller_eqFunction_168(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,168};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* euler_pid.position_setpoint[3] DISCRETE */) = (data->simulationInfo->realVarsPre[81] /* euler_pid.position_setpoint[3] DISCRETE */);
  threadData->lastEquationSolved = 168;
}

/*
equation index: 169
type: SIMPLE_ASSIGN
$PRE.euler_pid.yaw_setpoint = $START.euler_pid.yaw_setpoint
*/
void GSQuad_Components_Controller_eqFunction_169(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,169};
  (data->simulationInfo->realVarsPre[123] /* euler_pid.yaw_setpoint DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[123] /* euler_pid.yaw_setpoint DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 169;
}

/*
equation index: 170
type: SIMPLE_ASSIGN
euler_pid.yaw_setpoint = $PRE.euler_pid.yaw_setpoint
*/
void GSQuad_Components_Controller_eqFunction_170(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,170};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[123]] /* euler_pid.yaw_setpoint DISCRETE */) = (data->simulationInfo->realVarsPre[123] /* euler_pid.yaw_setpoint DISCRETE */);
  threadData->lastEquationSolved = 170;
}

/*
equation index: 171
type: SIMPLE_ASSIGN
$PRE.euler_pid.pos_w_p_w_fdbk[1] = $START.euler_pid.pos_w_p_w_fdbk[1]
*/
void GSQuad_Components_Controller_eqFunction_171(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,171};
  (data->simulationInfo->realVarsPre[76] /* euler_pid.pos_w_p_w_fdbk[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[76] /* euler_pid.pos_w_p_w_fdbk[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 171;
}

/*
equation index: 172
type: SIMPLE_ASSIGN
euler_pid.pos_w_p_w_fdbk[1] = $PRE.euler_pid.pos_w_p_w_fdbk[1]
*/
void GSQuad_Components_Controller_eqFunction_172(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,172};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* euler_pid.pos_w_p_w_fdbk[1] DISCRETE */) = (data->simulationInfo->realVarsPre[76] /* euler_pid.pos_w_p_w_fdbk[1] DISCRETE */);
  threadData->lastEquationSolved = 172;
}

/*
equation index: 173
type: SIMPLE_ASSIGN
$PRE.euler_pid.pos_w_p_w_fdbk[2] = $START.euler_pid.pos_w_p_w_fdbk[2]
*/
void GSQuad_Components_Controller_eqFunction_173(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,173};
  (data->simulationInfo->realVarsPre[77] /* euler_pid.pos_w_p_w_fdbk[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[77] /* euler_pid.pos_w_p_w_fdbk[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 173;
}

/*
equation index: 174
type: SIMPLE_ASSIGN
euler_pid.pos_w_p_w_fdbk[2] = $PRE.euler_pid.pos_w_p_w_fdbk[2]
*/
void GSQuad_Components_Controller_eqFunction_174(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,174};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* euler_pid.pos_w_p_w_fdbk[2] DISCRETE */) = (data->simulationInfo->realVarsPre[77] /* euler_pid.pos_w_p_w_fdbk[2] DISCRETE */);
  threadData->lastEquationSolved = 174;
}

/*
equation index: 175
type: SIMPLE_ASSIGN
$PRE.euler_pid.pos_w_p_w_fdbk[3] = $START.euler_pid.pos_w_p_w_fdbk[3]
*/
void GSQuad_Components_Controller_eqFunction_175(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,175};
  (data->simulationInfo->realVarsPre[78] /* euler_pid.pos_w_p_w_fdbk[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[78] /* euler_pid.pos_w_p_w_fdbk[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 175;
}

/*
equation index: 176
type: SIMPLE_ASSIGN
euler_pid.pos_w_p_w_fdbk[3] = $PRE.euler_pid.pos_w_p_w_fdbk[3]
*/
void GSQuad_Components_Controller_eqFunction_176(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,176};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* euler_pid.pos_w_p_w_fdbk[3] DISCRETE */) = (data->simulationInfo->realVarsPre[78] /* euler_pid.pos_w_p_w_fdbk[3] DISCRETE */);
  threadData->lastEquationSolved = 176;
}

/*
equation index: 177
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_w_p_b_fdbk[1] = $START.euler_pid.vel_w_p_b_fdbk[1]
*/
void GSQuad_Components_Controller_eqFunction_177(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,177};
  (data->simulationInfo->realVarsPre[120] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[120] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 177;
}

/*
equation index: 178
type: SIMPLE_ASSIGN
euler_pid.vel_w_p_b_fdbk[1] = $PRE.euler_pid.vel_w_p_b_fdbk[1]
*/
void GSQuad_Components_Controller_eqFunction_178(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,178};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */) = (data->simulationInfo->realVarsPre[120] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */);
  threadData->lastEquationSolved = 178;
}

/*
equation index: 179
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_w_p_b_fdbk[2] = $START.euler_pid.vel_w_p_b_fdbk[2]
*/
void GSQuad_Components_Controller_eqFunction_179(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,179};
  (data->simulationInfo->realVarsPre[121] /* euler_pid.vel_w_p_b_fdbk[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[121] /* euler_pid.vel_w_p_b_fdbk[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 179;
}

/*
equation index: 180
type: SIMPLE_ASSIGN
euler_pid.vel_w_p_b_fdbk[2] = $PRE.euler_pid.vel_w_p_b_fdbk[2]
*/
void GSQuad_Components_Controller_eqFunction_180(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,180};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[121]] /* euler_pid.vel_w_p_b_fdbk[2] DISCRETE */) = (data->simulationInfo->realVarsPre[121] /* euler_pid.vel_w_p_b_fdbk[2] DISCRETE */);
  threadData->lastEquationSolved = 180;
}

/*
equation index: 181
type: SIMPLE_ASSIGN
$PRE.euler_pid.vel_w_p_b_fdbk[3] = $START.euler_pid.vel_w_p_b_fdbk[3]
*/
void GSQuad_Components_Controller_eqFunction_181(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,181};
  (data->simulationInfo->realVarsPre[122] /* euler_pid.vel_w_p_b_fdbk[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[122] /* euler_pid.vel_w_p_b_fdbk[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 181;
}

/*
equation index: 182
type: SIMPLE_ASSIGN
euler_pid.vel_w_p_b_fdbk[3] = $PRE.euler_pid.vel_w_p_b_fdbk[3]
*/
void GSQuad_Components_Controller_eqFunction_182(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,182};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[122]] /* euler_pid.vel_w_p_b_fdbk[3] DISCRETE */) = (data->simulationInfo->realVarsPre[122] /* euler_pid.vel_w_p_b_fdbk[3] DISCRETE */);
  threadData->lastEquationSolved = 182;
}

/*
equation index: 183
type: SIMPLE_ASSIGN
$PRE.euler_pid.euler_wb_fdbk[1] = $START.euler_pid.euler_wb_fdbk[1]
*/
void GSQuad_Components_Controller_eqFunction_183(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,183};
  (data->simulationInfo->realVarsPre[52] /* euler_pid.euler_wb_fdbk[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[52] /* euler_pid.euler_wb_fdbk[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 183;
}

/*
equation index: 184
type: SIMPLE_ASSIGN
euler_pid.euler_wb_fdbk[1] = $PRE.euler_pid.euler_wb_fdbk[1]
*/
void GSQuad_Components_Controller_eqFunction_184(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,184};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* euler_pid.euler_wb_fdbk[1] DISCRETE */) = (data->simulationInfo->realVarsPre[52] /* euler_pid.euler_wb_fdbk[1] DISCRETE */);
  threadData->lastEquationSolved = 184;
}

/*
equation index: 185
type: SIMPLE_ASSIGN
$PRE.euler_pid.euler_wb_fdbk[2] = $START.euler_pid.euler_wb_fdbk[2]
*/
void GSQuad_Components_Controller_eqFunction_185(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,185};
  (data->simulationInfo->realVarsPre[53] /* euler_pid.euler_wb_fdbk[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[53] /* euler_pid.euler_wb_fdbk[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 185;
}

/*
equation index: 186
type: SIMPLE_ASSIGN
euler_pid.euler_wb_fdbk[2] = $PRE.euler_pid.euler_wb_fdbk[2]
*/
void GSQuad_Components_Controller_eqFunction_186(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,186};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* euler_pid.euler_wb_fdbk[2] DISCRETE */) = (data->simulationInfo->realVarsPre[53] /* euler_pid.euler_wb_fdbk[2] DISCRETE */);
  threadData->lastEquationSolved = 186;
}

/*
equation index: 187
type: SIMPLE_ASSIGN
$PRE.euler_pid.euler_wb_fdbk[3] = $START.euler_pid.euler_wb_fdbk[3]
*/
void GSQuad_Components_Controller_eqFunction_187(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,187};
  (data->simulationInfo->realVarsPre[54] /* euler_pid.euler_wb_fdbk[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[54] /* euler_pid.euler_wb_fdbk[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 187;
}

/*
equation index: 188
type: SIMPLE_ASSIGN
euler_pid.euler_wb_fdbk[3] = $PRE.euler_pid.euler_wb_fdbk[3]
*/
void GSQuad_Components_Controller_eqFunction_188(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,188};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* euler_pid.euler_wb_fdbk[3] DISCRETE */) = (data->simulationInfo->realVarsPre[54] /* euler_pid.euler_wb_fdbk[3] DISCRETE */);
  threadData->lastEquationSolved = 188;
}

/*
equation index: 189
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_wb_b_fdbk[1] = $START.euler_pid.rate_wb_b_fdbk[1]
*/
void GSQuad_Components_Controller_eqFunction_189(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,189};
  (data->simulationInfo->realVarsPre[97] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[97] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 189;
}

/*
equation index: 190
type: SIMPLE_ASSIGN
euler_pid.rate_wb_b_fdbk[1] = $PRE.euler_pid.rate_wb_b_fdbk[1]
*/
void GSQuad_Components_Controller_eqFunction_190(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,190};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */) = (data->simulationInfo->realVarsPre[97] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */);
  threadData->lastEquationSolved = 190;
}

/*
equation index: 191
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_wb_b_fdbk[2] = $START.euler_pid.rate_wb_b_fdbk[2]
*/
void GSQuad_Components_Controller_eqFunction_191(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,191};
  (data->simulationInfo->realVarsPre[98] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[98] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 191;
}

/*
equation index: 192
type: SIMPLE_ASSIGN
euler_pid.rate_wb_b_fdbk[2] = $PRE.euler_pid.rate_wb_b_fdbk[2]
*/
void GSQuad_Components_Controller_eqFunction_192(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,192};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */) = (data->simulationInfo->realVarsPre[98] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */);
  threadData->lastEquationSolved = 192;
}

/*
equation index: 193
type: SIMPLE_ASSIGN
$PRE.euler_pid.rate_wb_b_fdbk[3] = $START.euler_pid.rate_wb_b_fdbk[3]
*/
void GSQuad_Components_Controller_eqFunction_193(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,193};
  (data->simulationInfo->realVarsPre[99] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */) = ((modelica_real *)((data->modelData->realVarsData[99] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */).attribute .start.data))[0];
  threadData->lastEquationSolved = 193;
}

/*
equation index: 194
type: SIMPLE_ASSIGN
euler_pid.rate_wb_b_fdbk[3] = $PRE.euler_pid.rate_wb_b_fdbk[3]
*/
void GSQuad_Components_Controller_eqFunction_194(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,194};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */) = (data->simulationInfo->realVarsPre[99] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */);
  threadData->lastEquationSolved = 194;
}
OMC_DISABLE_OPT
void GSQuad_Components_Controller_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[194])(DATA*, threadData_t*) = {
    GSQuad_Components_Controller_eqFunction_1,
    GSQuad_Components_Controller_eqFunction_2,
    GSQuad_Components_Controller_eqFunction_3,
    GSQuad_Components_Controller_eqFunction_4,
    GSQuad_Components_Controller_eqFunction_5,
    GSQuad_Components_Controller_eqFunction_6,
    GSQuad_Components_Controller_eqFunction_7,
    GSQuad_Components_Controller_eqFunction_8,
    GSQuad_Components_Controller_eqFunction_9,
    GSQuad_Components_Controller_eqFunction_10,
    GSQuad_Components_Controller_eqFunction_11,
    GSQuad_Components_Controller_eqFunction_12,
    GSQuad_Components_Controller_eqFunction_13,
    GSQuad_Components_Controller_eqFunction_14,
    GSQuad_Components_Controller_eqFunction_15,
    GSQuad_Components_Controller_eqFunction_16,
    GSQuad_Components_Controller_eqFunction_17,
    GSQuad_Components_Controller_eqFunction_18,
    GSQuad_Components_Controller_eqFunction_19,
    GSQuad_Components_Controller_eqFunction_20,
    GSQuad_Components_Controller_eqFunction_21,
    GSQuad_Components_Controller_eqFunction_22,
    GSQuad_Components_Controller_eqFunction_23,
    GSQuad_Components_Controller_eqFunction_24,
    GSQuad_Components_Controller_eqFunction_25,
    GSQuad_Components_Controller_eqFunction_26,
    GSQuad_Components_Controller_eqFunction_27,
    GSQuad_Components_Controller_eqFunction_28,
    GSQuad_Components_Controller_eqFunction_29,
    GSQuad_Components_Controller_eqFunction_30,
    GSQuad_Components_Controller_eqFunction_31,
    GSQuad_Components_Controller_eqFunction_32,
    GSQuad_Components_Controller_eqFunction_33,
    GSQuad_Components_Controller_eqFunction_34,
    GSQuad_Components_Controller_eqFunction_35,
    GSQuad_Components_Controller_eqFunction_36,
    GSQuad_Components_Controller_eqFunction_37,
    GSQuad_Components_Controller_eqFunction_38,
    GSQuad_Components_Controller_eqFunction_39,
    GSQuad_Components_Controller_eqFunction_40,
    GSQuad_Components_Controller_eqFunction_41,
    GSQuad_Components_Controller_eqFunction_42,
    GSQuad_Components_Controller_eqFunction_43,
    GSQuad_Components_Controller_eqFunction_44,
    GSQuad_Components_Controller_eqFunction_45,
    GSQuad_Components_Controller_eqFunction_46,
    GSQuad_Components_Controller_eqFunction_47,
    GSQuad_Components_Controller_eqFunction_48,
    GSQuad_Components_Controller_eqFunction_49,
    GSQuad_Components_Controller_eqFunction_50,
    GSQuad_Components_Controller_eqFunction_51,
    GSQuad_Components_Controller_eqFunction_52,
    GSQuad_Components_Controller_eqFunction_53,
    GSQuad_Components_Controller_eqFunction_54,
    GSQuad_Components_Controller_eqFunction_55,
    GSQuad_Components_Controller_eqFunction_56,
    GSQuad_Components_Controller_eqFunction_57,
    GSQuad_Components_Controller_eqFunction_58,
    GSQuad_Components_Controller_eqFunction_59,
    GSQuad_Components_Controller_eqFunction_60,
    GSQuad_Components_Controller_eqFunction_61,
    GSQuad_Components_Controller_eqFunction_62,
    GSQuad_Components_Controller_eqFunction_63,
    GSQuad_Components_Controller_eqFunction_64,
    GSQuad_Components_Controller_eqFunction_65,
    GSQuad_Components_Controller_eqFunction_66,
    GSQuad_Components_Controller_eqFunction_67,
    GSQuad_Components_Controller_eqFunction_68,
    GSQuad_Components_Controller_eqFunction_69,
    GSQuad_Components_Controller_eqFunction_70,
    GSQuad_Components_Controller_eqFunction_71,
    GSQuad_Components_Controller_eqFunction_72,
    GSQuad_Components_Controller_eqFunction_73,
    GSQuad_Components_Controller_eqFunction_74,
    GSQuad_Components_Controller_eqFunction_75,
    GSQuad_Components_Controller_eqFunction_76,
    GSQuad_Components_Controller_eqFunction_77,
    GSQuad_Components_Controller_eqFunction_78,
    GSQuad_Components_Controller_eqFunction_79,
    GSQuad_Components_Controller_eqFunction_80,
    GSQuad_Components_Controller_eqFunction_81,
    GSQuad_Components_Controller_eqFunction_82,
    GSQuad_Components_Controller_eqFunction_83,
    GSQuad_Components_Controller_eqFunction_84,
    GSQuad_Components_Controller_eqFunction_85,
    GSQuad_Components_Controller_eqFunction_86,
    GSQuad_Components_Controller_eqFunction_87,
    GSQuad_Components_Controller_eqFunction_88,
    GSQuad_Components_Controller_eqFunction_89,
    GSQuad_Components_Controller_eqFunction_90,
    GSQuad_Components_Controller_eqFunction_91,
    GSQuad_Components_Controller_eqFunction_92,
    GSQuad_Components_Controller_eqFunction_93,
    GSQuad_Components_Controller_eqFunction_94,
    GSQuad_Components_Controller_eqFunction_95,
    GSQuad_Components_Controller_eqFunction_96,
    GSQuad_Components_Controller_eqFunction_97,
    GSQuad_Components_Controller_eqFunction_98,
    GSQuad_Components_Controller_eqFunction_99,
    GSQuad_Components_Controller_eqFunction_100,
    GSQuad_Components_Controller_eqFunction_101,
    GSQuad_Components_Controller_eqFunction_102,
    GSQuad_Components_Controller_eqFunction_103,
    GSQuad_Components_Controller_eqFunction_104,
    GSQuad_Components_Controller_eqFunction_105,
    GSQuad_Components_Controller_eqFunction_106,
    GSQuad_Components_Controller_eqFunction_107,
    GSQuad_Components_Controller_eqFunction_108,
    GSQuad_Components_Controller_eqFunction_109,
    GSQuad_Components_Controller_eqFunction_110,
    GSQuad_Components_Controller_eqFunction_111,
    GSQuad_Components_Controller_eqFunction_112,
    GSQuad_Components_Controller_eqFunction_113,
    GSQuad_Components_Controller_eqFunction_114,
    GSQuad_Components_Controller_eqFunction_115,
    GSQuad_Components_Controller_eqFunction_116,
    GSQuad_Components_Controller_eqFunction_117,
    GSQuad_Components_Controller_eqFunction_118,
    GSQuad_Components_Controller_eqFunction_119,
    GSQuad_Components_Controller_eqFunction_120,
    GSQuad_Components_Controller_eqFunction_121,
    GSQuad_Components_Controller_eqFunction_122,
    GSQuad_Components_Controller_eqFunction_123,
    GSQuad_Components_Controller_eqFunction_124,
    GSQuad_Components_Controller_eqFunction_125,
    GSQuad_Components_Controller_eqFunction_126,
    GSQuad_Components_Controller_eqFunction_127,
    GSQuad_Components_Controller_eqFunction_128,
    GSQuad_Components_Controller_eqFunction_129,
    GSQuad_Components_Controller_eqFunction_130,
    GSQuad_Components_Controller_eqFunction_131,
    GSQuad_Components_Controller_eqFunction_132,
    GSQuad_Components_Controller_eqFunction_133,
    GSQuad_Components_Controller_eqFunction_134,
    GSQuad_Components_Controller_eqFunction_135,
    GSQuad_Components_Controller_eqFunction_136,
    GSQuad_Components_Controller_eqFunction_137,
    GSQuad_Components_Controller_eqFunction_138,
    GSQuad_Components_Controller_eqFunction_139,
    GSQuad_Components_Controller_eqFunction_140,
    GSQuad_Components_Controller_eqFunction_141,
    GSQuad_Components_Controller_eqFunction_142,
    GSQuad_Components_Controller_eqFunction_143,
    GSQuad_Components_Controller_eqFunction_144,
    GSQuad_Components_Controller_eqFunction_145,
    GSQuad_Components_Controller_eqFunction_146,
    GSQuad_Components_Controller_eqFunction_147,
    GSQuad_Components_Controller_eqFunction_148,
    GSQuad_Components_Controller_eqFunction_149,
    GSQuad_Components_Controller_eqFunction_150,
    GSQuad_Components_Controller_eqFunction_151,
    GSQuad_Components_Controller_eqFunction_152,
    GSQuad_Components_Controller_eqFunction_153,
    GSQuad_Components_Controller_eqFunction_154,
    GSQuad_Components_Controller_eqFunction_155,
    GSQuad_Components_Controller_eqFunction_156,
    GSQuad_Components_Controller_eqFunction_157,
    GSQuad_Components_Controller_eqFunction_158,
    GSQuad_Components_Controller_eqFunction_159,
    GSQuad_Components_Controller_eqFunction_160,
    GSQuad_Components_Controller_eqFunction_161,
    GSQuad_Components_Controller_eqFunction_162,
    GSQuad_Components_Controller_eqFunction_163,
    GSQuad_Components_Controller_eqFunction_164,
    GSQuad_Components_Controller_eqFunction_165,
    GSQuad_Components_Controller_eqFunction_166,
    GSQuad_Components_Controller_eqFunction_167,
    GSQuad_Components_Controller_eqFunction_168,
    GSQuad_Components_Controller_eqFunction_169,
    GSQuad_Components_Controller_eqFunction_170,
    GSQuad_Components_Controller_eqFunction_171,
    GSQuad_Components_Controller_eqFunction_172,
    GSQuad_Components_Controller_eqFunction_173,
    GSQuad_Components_Controller_eqFunction_174,
    GSQuad_Components_Controller_eqFunction_175,
    GSQuad_Components_Controller_eqFunction_176,
    GSQuad_Components_Controller_eqFunction_177,
    GSQuad_Components_Controller_eqFunction_178,
    GSQuad_Components_Controller_eqFunction_179,
    GSQuad_Components_Controller_eqFunction_180,
    GSQuad_Components_Controller_eqFunction_181,
    GSQuad_Components_Controller_eqFunction_182,
    GSQuad_Components_Controller_eqFunction_183,
    GSQuad_Components_Controller_eqFunction_184,
    GSQuad_Components_Controller_eqFunction_185,
    GSQuad_Components_Controller_eqFunction_186,
    GSQuad_Components_Controller_eqFunction_187,
    GSQuad_Components_Controller_eqFunction_188,
    GSQuad_Components_Controller_eqFunction_189,
    GSQuad_Components_Controller_eqFunction_190,
    GSQuad_Components_Controller_eqFunction_191,
    GSQuad_Components_Controller_eqFunction_192,
    GSQuad_Components_Controller_eqFunction_193,
    GSQuad_Components_Controller_eqFunction_194
  };
  
  for (int id = 0; id < 194; id++) {
    eqFunctions[id](data, threadData);
  }
}

int GSQuad_Components_Controller_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->discreteCall = 1;
  GSQuad_Components_Controller_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  return 0;
}

/* No GSQuad_Components_Controller_functionInitialEquations_lambda0 function */

int GSQuad_Components_Controller_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  return 0;
}


#if defined(__cplusplus)
}
#endif
