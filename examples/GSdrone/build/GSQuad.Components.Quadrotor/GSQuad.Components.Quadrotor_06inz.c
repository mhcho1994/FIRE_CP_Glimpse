/* Initialization */
#include "GSQuad.Components.Quadrotor_model.h"
#include "GSQuad.Components.Quadrotor_11mix.h"
#include "GSQuad.Components.Quadrotor_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void GSQuad_Components_Quadrotor_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
quad_low.F_b[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_1(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* quad_low.F_b[1] variable */) = 0.0;
  threadData->lastEquationSolved = 1;
}

/*
equation index: 2
type: SIMPLE_ASSIGN
quad_low.F_b[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_2(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* quad_low.F_b[2] variable */) = 0.0;
  threadData->lastEquationSolved = 2;
}

/*
equation index: 3
type: SIMPLE_ASSIGN
gyroatk.omega_false[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_3(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* gyroatk.omega_false[1] variable */) = 0.0;
  threadData->lastEquationSolved = 3;
}

/*
equation index: 4
type: SIMPLE_ASSIGN
gyroatk.omega_false[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_4(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* gyroatk.omega_false[2] variable */) = 0.0;
  threadData->lastEquationSolved = 4;
}

/*
equation index: 5
type: SIMPLE_ASSIGN
$PRE.rate_wb_b_buf[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_5(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,5};
  (data->simulationInfo->realVarsPre[94] /* rate_wb_b_buf[3] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 5;
}

/*
equation index: 6
type: SIMPLE_ASSIGN
rate_wb_b_buf[3] = $PRE.rate_wb_b_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_6(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* rate_wb_b_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[94] /* rate_wb_b_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 6;
}

/*
equation index: 7
type: SIMPLE_ASSIGN
rate_wb_b_meas[3] = $PRE.rate_wb_b_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_7(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* rate_wb_b_meas[3] variable */) = (data->simulationInfo->realVarsPre[94] /* rate_wb_b_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 7;
}

/*
equation index: 8
type: SIMPLE_ASSIGN
$PRE.rate_wb_b_buf[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_8(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,8};
  (data->simulationInfo->realVarsPre[93] /* rate_wb_b_buf[2] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 8;
}

/*
equation index: 9
type: SIMPLE_ASSIGN
rate_wb_b_buf[2] = $PRE.rate_wb_b_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_9(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* rate_wb_b_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[93] /* rate_wb_b_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 9;
}

/*
equation index: 10
type: SIMPLE_ASSIGN
rate_wb_b_meas[2] = $PRE.rate_wb_b_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_10(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* rate_wb_b_meas[2] variable */) = (data->simulationInfo->realVarsPre[93] /* rate_wb_b_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 10;
}

/*
equation index: 11
type: SIMPLE_ASSIGN
$PRE.rate_wb_b_buf[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_11(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,11};
  (data->simulationInfo->realVarsPre[92] /* rate_wb_b_buf[1] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 11;
}

/*
equation index: 12
type: SIMPLE_ASSIGN
rate_wb_b_buf[1] = $PRE.rate_wb_b_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_12(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* rate_wb_b_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[92] /* rate_wb_b_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 12;
}

/*
equation index: 13
type: SIMPLE_ASSIGN
rate_wb_b_meas[1] = $PRE.rate_wb_b_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_13(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* rate_wb_b_meas[1] variable */) = (data->simulationInfo->realVarsPre[92] /* rate_wb_b_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 13;
}

/*
equation index: 14
type: SIMPLE_ASSIGN
$PRE.euler_wb_buf[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_14(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,14};
  (data->simulationInfo->realVarsPre[80] /* euler_wb_buf[3] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 14;
}

/*
equation index: 15
type: SIMPLE_ASSIGN
euler_wb_buf[3] = $PRE.euler_wb_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_15(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* euler_wb_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[80] /* euler_wb_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 15;
}

/*
equation index: 16
type: SIMPLE_ASSIGN
euler_wb_meas[3] = -3.14159265 + mod($PRE.euler_wb_buf[3] + 3.14159265, 6.2831853)
*/
void GSQuad_Components_Quadrotor_eqFunction_16(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,16};
  modelica_real tmp0;
  tmp0 = 6.2831853;
  if (tmp0 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod($PRE.euler_wb_buf[3] + 3.14159265, 6.2831853)");}
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* euler_wb_meas[3] variable */) = -3.14159265 + modelica_real_mod((data->simulationInfo->realVarsPre[80] /* euler_wb_buf[3] DISCRETE */) + 3.14159265, tmp0);
  threadData->lastEquationSolved = 16;
}

/*
equation index: 17
type: SIMPLE_ASSIGN
$PRE.euler_wb_buf[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_17(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,17};
  (data->simulationInfo->realVarsPre[79] /* euler_wb_buf[2] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 17;
}

/*
equation index: 18
type: SIMPLE_ASSIGN
euler_wb_buf[2] = $PRE.euler_wb_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_18(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* euler_wb_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[79] /* euler_wb_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 18;
}

/*
equation index: 19
type: SIMPLE_ASSIGN
euler_wb_meas[2] = $PRE.euler_wb_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_19(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* euler_wb_meas[2] variable */) = (data->simulationInfo->realVarsPre[79] /* euler_wb_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 19;
}

/*
equation index: 20
type: SIMPLE_ASSIGN
$PRE.euler_wb_buf[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_20(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,20};
  (data->simulationInfo->realVarsPre[78] /* euler_wb_buf[1] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 20;
}

/*
equation index: 21
type: SIMPLE_ASSIGN
euler_wb_buf[1] = $PRE.euler_wb_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_21(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* euler_wb_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[78] /* euler_wb_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 21;
}

/*
equation index: 22
type: SIMPLE_ASSIGN
euler_wb_meas[1] = $PRE.euler_wb_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_22(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* euler_wb_meas[1] variable */) = (data->simulationInfo->realVarsPre[78] /* euler_wb_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 22;
}

/*
equation index: 23
type: SIMPLE_ASSIGN
$PRE.quat_wb_buf[4] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_23(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,23};
  (data->simulationInfo->realVarsPre[91] /* quat_wb_buf[4] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 23;
}

/*
equation index: 24
type: SIMPLE_ASSIGN
quat_wb_buf[4] = $PRE.quat_wb_buf[4]
*/
void GSQuad_Components_Quadrotor_eqFunction_24(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* quat_wb_buf[4] DISCRETE */) = (data->simulationInfo->realVarsPre[91] /* quat_wb_buf[4] DISCRETE */);
  threadData->lastEquationSolved = 24;
}

/*
equation index: 25
type: SIMPLE_ASSIGN
quat_wb_meas[4] = $PRE.quat_wb_buf[4]
*/
void GSQuad_Components_Quadrotor_eqFunction_25(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* quat_wb_meas[4] variable */) = (data->simulationInfo->realVarsPre[91] /* quat_wb_buf[4] DISCRETE */);
  threadData->lastEquationSolved = 25;
}

/*
equation index: 26
type: SIMPLE_ASSIGN
$PRE.quat_wb_buf[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_26(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,26};
  (data->simulationInfo->realVarsPre[90] /* quat_wb_buf[3] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 26;
}

/*
equation index: 27
type: SIMPLE_ASSIGN
quat_wb_buf[3] = $PRE.quat_wb_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_27(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,27};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* quat_wb_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[90] /* quat_wb_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 27;
}

/*
equation index: 28
type: SIMPLE_ASSIGN
quat_wb_meas[3] = $PRE.quat_wb_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_28(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,28};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* quat_wb_meas[3] variable */) = (data->simulationInfo->realVarsPre[90] /* quat_wb_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 28;
}

/*
equation index: 29
type: SIMPLE_ASSIGN
$PRE.quat_wb_buf[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_29(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,29};
  (data->simulationInfo->realVarsPre[89] /* quat_wb_buf[2] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 29;
}

/*
equation index: 30
type: SIMPLE_ASSIGN
quat_wb_buf[2] = $PRE.quat_wb_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_30(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,30};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* quat_wb_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[89] /* quat_wb_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 30;
}

/*
equation index: 31
type: SIMPLE_ASSIGN
quat_wb_meas[2] = $PRE.quat_wb_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_31(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,31};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* quat_wb_meas[2] variable */) = (data->simulationInfo->realVarsPre[89] /* quat_wb_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 31;
}

/*
equation index: 32
type: SIMPLE_ASSIGN
$PRE.quat_wb_buf[1] = 1.0
*/
void GSQuad_Components_Quadrotor_eqFunction_32(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,32};
  (data->simulationInfo->realVarsPre[88] /* quat_wb_buf[1] DISCRETE */) = 1.0;
  threadData->lastEquationSolved = 32;
}

/*
equation index: 33
type: SIMPLE_ASSIGN
quat_wb_buf[1] = $PRE.quat_wb_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_33(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,33};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* quat_wb_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[88] /* quat_wb_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 33;
}

/*
equation index: 34
type: SIMPLE_ASSIGN
quat_wb_meas[1] = $PRE.quat_wb_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_34(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,34};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* quat_wb_meas[1] variable */) = (data->simulationInfo->realVarsPre[88] /* quat_wb_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 34;
}

/*
equation index: 35
type: SIMPLE_ASSIGN
$PRE.acc_w_p_b_buf[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_35(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,35};
  (data->simulationInfo->realVarsPre[77] /* acc_w_p_b_buf[3] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 35;
}

/*
equation index: 36
type: SIMPLE_ASSIGN
acc_w_p_b_buf[3] = $PRE.acc_w_p_b_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_36(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,36};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* acc_w_p_b_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[77] /* acc_w_p_b_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 36;
}

/*
equation index: 37
type: SIMPLE_ASSIGN
acc_w_p_b_meas[3] = $PRE.acc_w_p_b_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_37(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,37};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* acc_w_p_b_meas[3] variable */) = (data->simulationInfo->realVarsPre[77] /* acc_w_p_b_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 37;
}

/*
equation index: 38
type: SIMPLE_ASSIGN
$PRE.acc_w_p_b_buf[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_38(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,38};
  (data->simulationInfo->realVarsPre[76] /* acc_w_p_b_buf[2] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 38;
}

/*
equation index: 39
type: SIMPLE_ASSIGN
acc_w_p_b_buf[2] = $PRE.acc_w_p_b_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_39(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,39};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* acc_w_p_b_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[76] /* acc_w_p_b_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 39;
}

/*
equation index: 40
type: SIMPLE_ASSIGN
acc_w_p_b_meas[2] = $PRE.acc_w_p_b_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_40(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,40};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* acc_w_p_b_meas[2] variable */) = (data->simulationInfo->realVarsPre[76] /* acc_w_p_b_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 40;
}

/*
equation index: 41
type: SIMPLE_ASSIGN
$PRE.acc_w_p_b_buf[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_41(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,41};
  (data->simulationInfo->realVarsPre[75] /* acc_w_p_b_buf[1] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 41;
}

/*
equation index: 42
type: SIMPLE_ASSIGN
acc_w_p_b_buf[1] = $PRE.acc_w_p_b_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_42(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,42};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* acc_w_p_b_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[75] /* acc_w_p_b_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 42;
}

/*
equation index: 43
type: SIMPLE_ASSIGN
acc_w_p_b_meas[1] = $PRE.acc_w_p_b_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_43(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,43};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* acc_w_p_b_meas[1] variable */) = (data->simulationInfo->realVarsPre[75] /* acc_w_p_b_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 43;
}

/*
equation index: 44
type: SIMPLE_ASSIGN
$PRE.vel_w_p_b_buf[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_44(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,44};
  (data->simulationInfo->realVarsPre[97] /* vel_w_p_b_buf[3] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 44;
}

/*
equation index: 45
type: SIMPLE_ASSIGN
vel_w_p_b_buf[3] = $PRE.vel_w_p_b_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_45(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,45};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* vel_w_p_b_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[97] /* vel_w_p_b_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 45;
}

/*
equation index: 46
type: SIMPLE_ASSIGN
vel_w_p_b_meas[3] = $PRE.vel_w_p_b_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_46(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,46};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* vel_w_p_b_meas[3] variable */) = (data->simulationInfo->realVarsPre[97] /* vel_w_p_b_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 46;
}

/*
equation index: 47
type: SIMPLE_ASSIGN
$PRE.vel_w_p_b_buf[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_47(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,47};
  (data->simulationInfo->realVarsPre[96] /* vel_w_p_b_buf[2] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 47;
}

/*
equation index: 48
type: SIMPLE_ASSIGN
vel_w_p_b_buf[2] = $PRE.vel_w_p_b_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_48(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,48};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* vel_w_p_b_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[96] /* vel_w_p_b_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 48;
}

/*
equation index: 49
type: SIMPLE_ASSIGN
vel_w_p_b_meas[2] = $PRE.vel_w_p_b_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_49(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,49};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* vel_w_p_b_meas[2] variable */) = (data->simulationInfo->realVarsPre[96] /* vel_w_p_b_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 49;
}

/*
equation index: 50
type: SIMPLE_ASSIGN
$PRE.vel_w_p_b_buf[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_50(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,50};
  (data->simulationInfo->realVarsPre[95] /* vel_w_p_b_buf[1] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 50;
}

/*
equation index: 51
type: SIMPLE_ASSIGN
vel_w_p_b_buf[1] = $PRE.vel_w_p_b_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_51(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,51};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* vel_w_p_b_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[95] /* vel_w_p_b_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 51;
}

/*
equation index: 52
type: SIMPLE_ASSIGN
vel_w_p_b_meas[1] = $PRE.vel_w_p_b_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_52(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,52};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* vel_w_p_b_meas[1] variable */) = (data->simulationInfo->realVarsPre[95] /* vel_w_p_b_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 52;
}

/*
equation index: 53
type: SIMPLE_ASSIGN
$PRE.pos_w_p_w_buf[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_53(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,53};
  (data->simulationInfo->realVarsPre[83] /* pos_w_p_w_buf[3] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 53;
}

/*
equation index: 54
type: SIMPLE_ASSIGN
pos_w_p_w_buf[3] = $PRE.pos_w_p_w_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_54(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,54};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* pos_w_p_w_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[83] /* pos_w_p_w_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 54;
}

/*
equation index: 55
type: SIMPLE_ASSIGN
pos_w_p_w_meas[3] = $PRE.pos_w_p_w_buf[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_55(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,55};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* pos_w_p_w_meas[3] variable */) = (data->simulationInfo->realVarsPre[83] /* pos_w_p_w_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 55;
}

/*
equation index: 56
type: SIMPLE_ASSIGN
$PRE.pos_w_p_w_buf[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_56(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,56};
  (data->simulationInfo->realVarsPre[82] /* pos_w_p_w_buf[2] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 56;
}

/*
equation index: 57
type: SIMPLE_ASSIGN
pos_w_p_w_buf[2] = $PRE.pos_w_p_w_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_57(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,57};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* pos_w_p_w_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[82] /* pos_w_p_w_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 57;
}

/*
equation index: 58
type: SIMPLE_ASSIGN
pos_w_p_w_meas[2] = $PRE.pos_w_p_w_buf[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_58(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,58};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* pos_w_p_w_meas[2] variable */) = (data->simulationInfo->realVarsPre[82] /* pos_w_p_w_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 58;
}

/*
equation index: 59
type: SIMPLE_ASSIGN
$PRE.pos_w_p_w_buf[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_59(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,59};
  (data->simulationInfo->realVarsPre[81] /* pos_w_p_w_buf[1] DISCRETE */) = 0.0;
  threadData->lastEquationSolved = 59;
}

/*
equation index: 60
type: SIMPLE_ASSIGN
pos_w_p_w_buf[1] = $PRE.pos_w_p_w_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_60(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,60};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* pos_w_p_w_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[81] /* pos_w_p_w_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 60;
}

/*
equation index: 61
type: SIMPLE_ASSIGN
pos_w_p_w_meas[1] = $PRE.pos_w_p_w_buf[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_61(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,61};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* pos_w_p_w_meas[1] variable */) = (data->simulationInfo->realVarsPre[81] /* pos_w_p_w_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 61;
}

/*
equation index: 62
type: SIMPLE_ASSIGN
$PRE.gyroatk.timer_count = $START.gyroatk.timer_count
*/
void GSQuad_Components_Quadrotor_eqFunction_62(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,62};
  (data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */) = (data->modelData->integerVarsData[0] /* gyroatk.timer_count DISCRETE */).attribute .start;
  threadData->lastEquationSolved = 62;
}

/*
equation index: 63
type: SIMPLE_ASSIGN
gyroatk.timer_count = $PRE.gyroatk.timer_count
*/
void GSQuad_Components_Quadrotor_eqFunction_63(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,63};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* gyroatk.timer_count DISCRETE */) = (data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */);
  threadData->lastEquationSolved = 63;
}

/*
equation index: 64
type: SIMPLE_ASSIGN
gyroatk.omega_false[3] = 0.5 * gyroatk.l_g * gyroatk.w_d * (gyroatk.X_ac * cos((gyroatk.w_ac - gyroatk.w_d) * gyroatk.sample_interval * (*Real*)($PRE.gyroatk.timer_count) - gyroatk.Phi_ac) + gyroatk.X_d * cos(gyroatk.Phi_d)) / gyroatk.dis_d
*/
void GSQuad_Components_Quadrotor_eqFunction_64(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,64};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* gyroatk.omega_false[3] variable */) = (0.5) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[27]] /* gyroatk.l_g PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[15]] /* gyroatk.X_ac PARAM */)) * (cos(((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[41]] /* gyroatk.w_ac PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[36]] /* gyroatk.sample_interval PARAM */)) * (((modelica_real)(data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */)))) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* gyroatk.Phi_ac PARAM */))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[18]] /* gyroatk.X_d PARAM */)) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[12]] /* gyroatk.Phi_d PARAM */))),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* gyroatk.dis_d PARAM */),"gyroatk.dis_d",equationIndexes))));
  threadData->lastEquationSolved = 64;
}

/*
equation index: 65
type: SIMPLE_ASSIGN
quad_low.velocity_w_p_b[1] = $START.quad_low.velocity_w_p_b[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_65(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,65};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[10] /* quad_low.velocity_w_p_b[1] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 65;
}

/*
equation index: 66
type: SIMPLE_ASSIGN
quad_low.velocity_w_p_b[2] = $START.quad_low.velocity_w_p_b[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_66(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,66};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[11] /* quad_low.velocity_w_p_b[2] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 66;
}

/*
equation index: 67
type: SIMPLE_ASSIGN
quad_low.velocity_w_p_b[3] = $START.quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_67(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,67};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[12] /* quad_low.velocity_w_p_b[3] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 67;
}

/*
equation index: 68
type: SIMPLE_ASSIGN
quad_low.quaternion_wb[1] = $START.quad_low.quaternion_wb[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_68(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,68};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[3] /* quad_low.quaternion_wb[1] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 68;
}

/*
equation index: 69
type: SIMPLE_ASSIGN
quad_low.quaternion_wb[2] = $START.quad_low.quaternion_wb[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_69(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,69};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[4] /* quad_low.quaternion_wb[2] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 69;
}

/*
equation index: 70
type: SIMPLE_ASSIGN
quad_low.quaternion_wb[3] = $START.quad_low.quaternion_wb[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_70(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,70};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[5] /* quad_low.quaternion_wb[3] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 70;
}

/*
equation index: 71
type: SIMPLE_ASSIGN
quad_low.quaternion_wb[4] = $START.quad_low.quaternion_wb[4]
*/
void GSQuad_Components_Quadrotor_eqFunction_71(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,71};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[6] /* quad_low.quaternion_wb[4] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 71;
}
extern void GSQuad_Components_Quadrotor_eqFunction_122(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_123(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_124(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_125(DATA *data, threadData_t *threadData);


/*
equation index: 76
type: SIMPLE_ASSIGN
quad_low.rate_wb_b[1] = $START.quad_low.rate_wb_b[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_76(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,76};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[7] /* quad_low.rate_wb_b[1] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 76;
}

/*
equation index: 77
type: SIMPLE_ASSIGN
quad_low.rate_wb_b[2] = $START.quad_low.rate_wb_b[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_77(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,77};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[8] /* quad_low.rate_wb_b[2] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 77;
}

/*
equation index: 78
type: SIMPLE_ASSIGN
quad_low.rate_wb_b[3] = $START.quad_low.rate_wb_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_78(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,78};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[9] /* quad_low.rate_wb_b[3] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 78;
}
extern void GSQuad_Components_Quadrotor_eqFunction_126(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_127(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_129(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_130(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_131(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_132(DATA *data, threadData_t *threadData);


/*
equation index: 85
type: SIMPLE_ASSIGN
quad_low.omega_motor[1] = $START.quad_low.omega_motor[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_85(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,85};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* quad_low.omega_motor[1] variable */) = ((modelica_real *)((data->modelData->realVarsData[61] /* quad_low.omega_motor[1] variable */).attribute .start.data))[0];
  threadData->lastEquationSolved = 85;
}

void GSQuad_Components_Quadrotor_eqFunction_86(DATA*, threadData_t*);
/*
equation index: 87
indexNonlinear: 0
type: NONLINEAR

vars: {$PRE.quad_low.omega_rotor_cmd[1]}
eqns: {86}
*/
void GSQuad_Components_Quadrotor_eqFunction_87(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,87};
  int retValue;
  infoStreamPrint(OMC_LOG_DT, 0, "Solving nonlinear system 87 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = (data->simulationInfo->realVarsPre[84] /* quad_low.omega_rotor_cmd[1] DISCRETE */);
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,87};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 87 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->simulationInfo->realVarsPre[84] /* quad_low.omega_rotor_cmd[1] DISCRETE */) = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  threadData->lastEquationSolved = 87;
}

/*
equation index: 88
type: SIMPLE_ASSIGN
quad_low.omega_rotor_cmd[1] = $PRE.quad_low.omega_rotor_cmd[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_88(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,88};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* quad_low.omega_rotor_cmd[1] DISCRETE */) = (data->simulationInfo->realVarsPre[84] /* quad_low.omega_rotor_cmd[1] DISCRETE */);
  threadData->lastEquationSolved = 88;
}

/*
equation index: 89
type: SIMPLE_ASSIGN
quad_low.omega_motor[2] = $START.quad_low.omega_motor[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_89(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,89};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* quad_low.omega_motor[2] variable */) = ((modelica_real *)((data->modelData->realVarsData[62] /* quad_low.omega_motor[2] variable */).attribute .start.data))[0];
  threadData->lastEquationSolved = 89;
}

void GSQuad_Components_Quadrotor_eqFunction_90(DATA*, threadData_t*);
/*
equation index: 91
indexNonlinear: 1
type: NONLINEAR

vars: {$PRE.quad_low.omega_rotor_cmd[2]}
eqns: {90}
*/
void GSQuad_Components_Quadrotor_eqFunction_91(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,91};
  int retValue;
  infoStreamPrint(OMC_LOG_DT, 0, "Solving nonlinear system 91 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = (data->simulationInfo->realVarsPre[85] /* quad_low.omega_rotor_cmd[2] DISCRETE */);
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,91};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 91 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->simulationInfo->realVarsPre[85] /* quad_low.omega_rotor_cmd[2] DISCRETE */) = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  threadData->lastEquationSolved = 91;
}

/*
equation index: 92
type: SIMPLE_ASSIGN
quad_low.omega_rotor_cmd[2] = $PRE.quad_low.omega_rotor_cmd[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_92(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,92};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* quad_low.omega_rotor_cmd[2] DISCRETE */) = (data->simulationInfo->realVarsPre[85] /* quad_low.omega_rotor_cmd[2] DISCRETE */);
  threadData->lastEquationSolved = 92;
}

/*
equation index: 93
type: SIMPLE_ASSIGN
quad_low.omega_motor[3] = $START.quad_low.omega_motor[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_93(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,93};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* quad_low.omega_motor[3] variable */) = ((modelica_real *)((data->modelData->realVarsData[63] /* quad_low.omega_motor[3] variable */).attribute .start.data))[0];
  threadData->lastEquationSolved = 93;
}

void GSQuad_Components_Quadrotor_eqFunction_94(DATA*, threadData_t*);
/*
equation index: 95
indexNonlinear: 2
type: NONLINEAR

vars: {$PRE.quad_low.omega_rotor_cmd[3]}
eqns: {94}
*/
void GSQuad_Components_Quadrotor_eqFunction_95(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,95};
  int retValue;
  infoStreamPrint(OMC_LOG_DT, 0, "Solving nonlinear system 95 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
  /* get old value */
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[0] = (data->simulationInfo->realVarsPre[86] /* quad_low.omega_rotor_cmd[3] DISCRETE */);
  retValue = solve_nonlinear_system(data, threadData, 2);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,95};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 95 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->simulationInfo->realVarsPre[86] /* quad_low.omega_rotor_cmd[3] DISCRETE */) = data->simulationInfo->nonlinearSystemData[2].nlsx[0];
  threadData->lastEquationSolved = 95;
}

/*
equation index: 96
type: SIMPLE_ASSIGN
quad_low.omega_rotor_cmd[3] = $PRE.quad_low.omega_rotor_cmd[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_96(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,96};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* quad_low.omega_rotor_cmd[3] DISCRETE */) = (data->simulationInfo->realVarsPre[86] /* quad_low.omega_rotor_cmd[3] DISCRETE */);
  threadData->lastEquationSolved = 96;
}

/*
equation index: 97
type: SIMPLE_ASSIGN
quad_low.omega_motor[4] = $START.quad_low.omega_motor[4]
*/
void GSQuad_Components_Quadrotor_eqFunction_97(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,97};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* quad_low.omega_motor[4] variable */) = ((modelica_real *)((data->modelData->realVarsData[64] /* quad_low.omega_motor[4] variable */).attribute .start.data))[0];
  threadData->lastEquationSolved = 97;
}

void GSQuad_Components_Quadrotor_eqFunction_98(DATA*, threadData_t*);
/*
equation index: 99
indexNonlinear: 3
type: NONLINEAR

vars: {$PRE.quad_low.omega_rotor_cmd[4]}
eqns: {98}
*/
void GSQuad_Components_Quadrotor_eqFunction_99(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,99};
  int retValue;
  infoStreamPrint(OMC_LOG_DT, 0, "Solving nonlinear system 99 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
  /* get old value */
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[0] = (data->simulationInfo->realVarsPre[87] /* quad_low.omega_rotor_cmd[4] DISCRETE */);
  retValue = solve_nonlinear_system(data, threadData, 3);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,99};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 99 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->simulationInfo->realVarsPre[87] /* quad_low.omega_rotor_cmd[4] DISCRETE */) = data->simulationInfo->nonlinearSystemData[3].nlsx[0];
  threadData->lastEquationSolved = 99;
}

/*
equation index: 100
type: SIMPLE_ASSIGN
quad_low.omega_rotor_cmd[4] = $PRE.quad_low.omega_rotor_cmd[4]
*/
void GSQuad_Components_Quadrotor_eqFunction_100(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,100};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* quad_low.omega_rotor_cmd[4] DISCRETE */) = (data->simulationInfo->realVarsPre[87] /* quad_low.omega_rotor_cmd[4] DISCRETE */);
  threadData->lastEquationSolved = 100;
}
extern void GSQuad_Components_Quadrotor_eqFunction_118(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_128(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_119(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_120(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_121(DATA *data, threadData_t *threadData);


/*
equation index: 106
type: ARRAY_CALL_ASSIGN

$DER.quad_low.rate_wb_b = quad_low.Jinv * (quad_low.M_b - GSQuad.Utils.hatmap(quad_low.rate_wb_b) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]})
*/
void GSQuad_Components_Quadrotor_eqFunction_106(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,106};
  real_array tmp1;
  real_array tmp2;
  real_array tmp3;
  real_array tmp4;
  real_array tmp5;
  real_array_create(&tmp1, ((modelica_real*)&((&data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_create(&tmp2, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_create(&tmp3, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp4, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  real_array_create(&tmp5, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* der(quad_low.rate_wb_b[1]) STATE_DER */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_copy_data(mul_alloc_real_matrix_product_smart(tmp1, sub_alloc_real_array(tmp2, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp3), tmp4))), tmp5);
  threadData->lastEquationSolved = 106;
}

/*
equation index: 107
type: ALGORITHM

  $whenCondition2 := $START.$whenCondition2;
  $whenCondition1 := $START.$whenCondition1;
  $whenCondition1 := false;
  $whenCondition2 := false;
*/
void GSQuad_Components_Quadrotor_eqFunction_107(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,107};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = (data->modelData->booleanVarsData[1] /* $whenCondition2 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->modelData->booleanVarsData[0] /* $whenCondition1 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = 0 /* false */;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = 0 /* false */;
  threadData->lastEquationSolved = 107;
}

/*
equation index: 108
type: ALGORITHM

  $whenCondition3 := $START.$whenCondition3;
  $whenCondition3 := false;
*/
void GSQuad_Components_Quadrotor_eqFunction_108(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,108};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition3 DISCRETE */) = (data->modelData->booleanVarsData[2] /* $whenCondition3 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition3 DISCRETE */) = 0 /* false */;
  threadData->lastEquationSolved = 108;
}

/*
equation index: 109
type: SIMPLE_ASSIGN
quad_low.position_w_p_w[1] = $START.quad_low.position_w_p_w[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_109(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,109};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* quad_low.position_w_p_w[1] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[0] /* quad_low.position_w_p_w[1] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 109;
}

/*
equation index: 110
type: SIMPLE_ASSIGN
quad_low.position_w_p_w[2] = $START.quad_low.position_w_p_w[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_110(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,110};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* quad_low.position_w_p_w[2] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[1] /* quad_low.position_w_p_w[2] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 110;
}

/*
equation index: 111
type: SIMPLE_ASSIGN
quad_low.position_w_p_w[3] = $START.quad_low.position_w_p_w[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_111(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,111};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* quad_low.position_w_p_w[3] STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[2] /* quad_low.position_w_p_w[3] STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 111;
}
OMC_DISABLE_OPT
void GSQuad_Components_Quadrotor_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[107])(DATA*, threadData_t*) = {
    GSQuad_Components_Quadrotor_eqFunction_1,
    GSQuad_Components_Quadrotor_eqFunction_2,
    GSQuad_Components_Quadrotor_eqFunction_3,
    GSQuad_Components_Quadrotor_eqFunction_4,
    GSQuad_Components_Quadrotor_eqFunction_5,
    GSQuad_Components_Quadrotor_eqFunction_6,
    GSQuad_Components_Quadrotor_eqFunction_7,
    GSQuad_Components_Quadrotor_eqFunction_8,
    GSQuad_Components_Quadrotor_eqFunction_9,
    GSQuad_Components_Quadrotor_eqFunction_10,
    GSQuad_Components_Quadrotor_eqFunction_11,
    GSQuad_Components_Quadrotor_eqFunction_12,
    GSQuad_Components_Quadrotor_eqFunction_13,
    GSQuad_Components_Quadrotor_eqFunction_14,
    GSQuad_Components_Quadrotor_eqFunction_15,
    GSQuad_Components_Quadrotor_eqFunction_16,
    GSQuad_Components_Quadrotor_eqFunction_17,
    GSQuad_Components_Quadrotor_eqFunction_18,
    GSQuad_Components_Quadrotor_eqFunction_19,
    GSQuad_Components_Quadrotor_eqFunction_20,
    GSQuad_Components_Quadrotor_eqFunction_21,
    GSQuad_Components_Quadrotor_eqFunction_22,
    GSQuad_Components_Quadrotor_eqFunction_23,
    GSQuad_Components_Quadrotor_eqFunction_24,
    GSQuad_Components_Quadrotor_eqFunction_25,
    GSQuad_Components_Quadrotor_eqFunction_26,
    GSQuad_Components_Quadrotor_eqFunction_27,
    GSQuad_Components_Quadrotor_eqFunction_28,
    GSQuad_Components_Quadrotor_eqFunction_29,
    GSQuad_Components_Quadrotor_eqFunction_30,
    GSQuad_Components_Quadrotor_eqFunction_31,
    GSQuad_Components_Quadrotor_eqFunction_32,
    GSQuad_Components_Quadrotor_eqFunction_33,
    GSQuad_Components_Quadrotor_eqFunction_34,
    GSQuad_Components_Quadrotor_eqFunction_35,
    GSQuad_Components_Quadrotor_eqFunction_36,
    GSQuad_Components_Quadrotor_eqFunction_37,
    GSQuad_Components_Quadrotor_eqFunction_38,
    GSQuad_Components_Quadrotor_eqFunction_39,
    GSQuad_Components_Quadrotor_eqFunction_40,
    GSQuad_Components_Quadrotor_eqFunction_41,
    GSQuad_Components_Quadrotor_eqFunction_42,
    GSQuad_Components_Quadrotor_eqFunction_43,
    GSQuad_Components_Quadrotor_eqFunction_44,
    GSQuad_Components_Quadrotor_eqFunction_45,
    GSQuad_Components_Quadrotor_eqFunction_46,
    GSQuad_Components_Quadrotor_eqFunction_47,
    GSQuad_Components_Quadrotor_eqFunction_48,
    GSQuad_Components_Quadrotor_eqFunction_49,
    GSQuad_Components_Quadrotor_eqFunction_50,
    GSQuad_Components_Quadrotor_eqFunction_51,
    GSQuad_Components_Quadrotor_eqFunction_52,
    GSQuad_Components_Quadrotor_eqFunction_53,
    GSQuad_Components_Quadrotor_eqFunction_54,
    GSQuad_Components_Quadrotor_eqFunction_55,
    GSQuad_Components_Quadrotor_eqFunction_56,
    GSQuad_Components_Quadrotor_eqFunction_57,
    GSQuad_Components_Quadrotor_eqFunction_58,
    GSQuad_Components_Quadrotor_eqFunction_59,
    GSQuad_Components_Quadrotor_eqFunction_60,
    GSQuad_Components_Quadrotor_eqFunction_61,
    GSQuad_Components_Quadrotor_eqFunction_62,
    GSQuad_Components_Quadrotor_eqFunction_63,
    GSQuad_Components_Quadrotor_eqFunction_64,
    GSQuad_Components_Quadrotor_eqFunction_65,
    GSQuad_Components_Quadrotor_eqFunction_66,
    GSQuad_Components_Quadrotor_eqFunction_67,
    GSQuad_Components_Quadrotor_eqFunction_68,
    GSQuad_Components_Quadrotor_eqFunction_69,
    GSQuad_Components_Quadrotor_eqFunction_70,
    GSQuad_Components_Quadrotor_eqFunction_71,
    GSQuad_Components_Quadrotor_eqFunction_122,
    GSQuad_Components_Quadrotor_eqFunction_123,
    GSQuad_Components_Quadrotor_eqFunction_124,
    GSQuad_Components_Quadrotor_eqFunction_125,
    GSQuad_Components_Quadrotor_eqFunction_76,
    GSQuad_Components_Quadrotor_eqFunction_77,
    GSQuad_Components_Quadrotor_eqFunction_78,
    GSQuad_Components_Quadrotor_eqFunction_126,
    GSQuad_Components_Quadrotor_eqFunction_127,
    GSQuad_Components_Quadrotor_eqFunction_129,
    GSQuad_Components_Quadrotor_eqFunction_130,
    GSQuad_Components_Quadrotor_eqFunction_131,
    GSQuad_Components_Quadrotor_eqFunction_132,
    GSQuad_Components_Quadrotor_eqFunction_85,
    GSQuad_Components_Quadrotor_eqFunction_87,
    GSQuad_Components_Quadrotor_eqFunction_88,
    GSQuad_Components_Quadrotor_eqFunction_89,
    GSQuad_Components_Quadrotor_eqFunction_91,
    GSQuad_Components_Quadrotor_eqFunction_92,
    GSQuad_Components_Quadrotor_eqFunction_93,
    GSQuad_Components_Quadrotor_eqFunction_95,
    GSQuad_Components_Quadrotor_eqFunction_96,
    GSQuad_Components_Quadrotor_eqFunction_97,
    GSQuad_Components_Quadrotor_eqFunction_99,
    GSQuad_Components_Quadrotor_eqFunction_100,
    GSQuad_Components_Quadrotor_eqFunction_118,
    GSQuad_Components_Quadrotor_eqFunction_128,
    GSQuad_Components_Quadrotor_eqFunction_119,
    GSQuad_Components_Quadrotor_eqFunction_120,
    GSQuad_Components_Quadrotor_eqFunction_121,
    GSQuad_Components_Quadrotor_eqFunction_106,
    GSQuad_Components_Quadrotor_eqFunction_107,
    GSQuad_Components_Quadrotor_eqFunction_108,
    GSQuad_Components_Quadrotor_eqFunction_109,
    GSQuad_Components_Quadrotor_eqFunction_110,
    GSQuad_Components_Quadrotor_eqFunction_111
  };
  
  for (int id = 0; id < 107; id++) {
    eqFunctions[id](data, threadData);
  }
}

int GSQuad_Components_Quadrotor_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->discreteCall = 1;
  GSQuad_Components_Quadrotor_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  return 0;
}

/* No GSQuad_Components_Quadrotor_functionInitialEquations_lambda0 function */

int GSQuad_Components_Quadrotor_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  return 0;
}


#if defined(__cplusplus)
}
#endif
