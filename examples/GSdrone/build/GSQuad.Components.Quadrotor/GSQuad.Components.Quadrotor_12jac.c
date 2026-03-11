/* Jacobians 6 */
#include "GSQuad.Components.Quadrotor_model.h"
#include "GSQuad.Components.Quadrotor_12jac.h"
#include "simulation/jacobian_util.h"
#include "util/omc_file.h"
int GSQuad_Components_Quadrotor_functionJacH_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}
int GSQuad_Components_Quadrotor_functionJacF_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 273
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_273(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,273};
  jacobian->tmpVars[3] /* der(quad_low.quaternion_wb.$pDERD.dummyVarD[1]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 273;
}

/*
equation index: 274
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_274(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,274};
  jacobian->tmpVars[4] /* der(quad_low.quaternion_wb.$pDERD.dummyVarD[2]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 274;
}

/*
equation index: 275
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_275(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,275};
  jacobian->tmpVars[5] /* der(quad_low.quaternion_wb.$pDERD.dummyVarD[3]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 275;
}

/*
equation index: 276
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERD.dummyVarD[4] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_276(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,276};
  jacobian->tmpVars[6] /* der(quad_low.quaternion_wb.$pDERD.dummyVarD[4]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 276;
}

/*
equation index: 277
type: SIMPLE_ASSIGN
pos_w_p_w_meas.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_277(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,277};
  jacobian->resultVars[6] /* pos_w_p_w_meas.$pDERD.dummyVarD[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 277;
}

/*
equation index: 278
type: SIMPLE_ASSIGN
pos_w_p_w_meas.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_278(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,278};
  jacobian->resultVars[7] /* pos_w_p_w_meas.$pDERD.dummyVarD[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 278;
}

/*
equation index: 279
type: SIMPLE_ASSIGN
pos_w_p_w_meas.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_279(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,279};
  jacobian->resultVars[8] /* pos_w_p_w_meas.$pDERD.dummyVarD[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 279;
}

/*
equation index: 280
type: SIMPLE_ASSIGN
vel_w_p_b_meas.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_280(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,280};
  jacobian->resultVars[16] /* vel_w_p_b_meas.$pDERD.dummyVarD[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 280;
}

/*
equation index: 281
type: SIMPLE_ASSIGN
vel_w_p_b_meas.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_281(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,281};
  jacobian->resultVars[17] /* vel_w_p_b_meas.$pDERD.dummyVarD[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 281;
}

/*
equation index: 282
type: SIMPLE_ASSIGN
vel_w_p_b_meas.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_282(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,282};
  jacobian->resultVars[18] /* vel_w_p_b_meas.$pDERD.dummyVarD[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 282;
}

/*
equation index: 283
type: SIMPLE_ASSIGN
acc_w_p_b_meas.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_283(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,283};
  jacobian->resultVars[0] /* acc_w_p_b_meas.$pDERD.dummyVarD[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 283;
}

/*
equation index: 284
type: SIMPLE_ASSIGN
acc_w_p_b_meas.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_284(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,284};
  jacobian->resultVars[1] /* acc_w_p_b_meas.$pDERD.dummyVarD[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 284;
}

/*
equation index: 285
type: SIMPLE_ASSIGN
acc_w_p_b_meas.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_285(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,285};
  jacobian->resultVars[2] /* acc_w_p_b_meas.$pDERD.dummyVarD[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 285;
}

/*
equation index: 286
type: SIMPLE_ASSIGN
quat_wb_meas.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_286(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,286};
  jacobian->resultVars[9] /* quat_wb_meas.$pDERD.dummyVarD[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 286;
}

/*
equation index: 287
type: SIMPLE_ASSIGN
quat_wb_meas.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_287(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,287};
  jacobian->resultVars[10] /* quat_wb_meas.$pDERD.dummyVarD[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 287;
}

/*
equation index: 288
type: SIMPLE_ASSIGN
quat_wb_meas.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_288(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,288};
  jacobian->resultVars[11] /* quat_wb_meas.$pDERD.dummyVarD[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 288;
}

/*
equation index: 289
type: SIMPLE_ASSIGN
quat_wb_meas.$pDERD.dummyVarD[4] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_289(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,289};
  jacobian->resultVars[12] /* quat_wb_meas.$pDERD.dummyVarD[4] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 289;
}

/*
equation index: 290
type: SIMPLE_ASSIGN
euler_wb_meas.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_290(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,290};
  jacobian->resultVars[3] /* euler_wb_meas.$pDERD.dummyVarD[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 290;
}

/*
equation index: 291
type: SIMPLE_ASSIGN
euler_wb_meas.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_291(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,291};
  jacobian->resultVars[4] /* euler_wb_meas.$pDERD.dummyVarD[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 291;
}

/*
equation index: 292
type: SIMPLE_ASSIGN
euler_wb_meas.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_292(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,292};
  jacobian->resultVars[5] /* euler_wb_meas.$pDERD.dummyVarD[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 292;
}

/*
equation index: 293
type: SIMPLE_ASSIGN
rate_wb_b_meas.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_293(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,293};
  jacobian->resultVars[13] /* rate_wb_b_meas.$pDERD.dummyVarD[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 293;
}

/*
equation index: 294
type: SIMPLE_ASSIGN
rate_wb_b_meas.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_294(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,294};
  jacobian->resultVars[14] /* rate_wb_b_meas.$pDERD.dummyVarD[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 294;
}

/*
equation index: 295
type: SIMPLE_ASSIGN
rate_wb_b_meas.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_295(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,295};
  jacobian->resultVars[15] /* rate_wb_b_meas.$pDERD.dummyVarD[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 295;
}

/*
equation index: 296
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_296(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,296};
  jacobian->tmpVars[11] /* der(quad_low.velocity_w_p_b.$pDERD.dummyVarD[2]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 296;
}

/*
equation index: 297
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_297(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,297};
  jacobian->tmpVars[10] /* der(quad_low.velocity_w_p_b.$pDERD.dummyVarD[1]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 297;
}

/*
equation index: 298
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_298(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,298};
  jacobian->tmpVars[2] /* der(quad_low.position_w_p_w.$pDERD.dummyVarD[3]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 298;
}

/*
equation index: 299
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_299(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,299};
  jacobian->tmpVars[1] /* der(quad_low.position_w_p_w.$pDERD.dummyVarD[2]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 299;
}

/*
equation index: 300
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_300(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,300};
  jacobian->tmpVars[0] /* der(quad_low.position_w_p_w.$pDERD.dummyVarD[1]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 300;
}

/*
equation index: 301
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_301(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,301};
  jacobian->tmpVars[12] /* der(quad_low.velocity_w_p_b.$pDERD.dummyVarD[3]) JACOBIAN_TMP_VAR */ = 0.0;
  threadData->lastEquationSolved = 301;
}

/*
equation index: 302
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERD.dummyVarD[1] = (quad_low.Jinv * (-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {0.0, 0.0, 0.0}))[1] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_302(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,302};
  real_array tmp0;
  real_array tmp1;
  real_array tmp2;
  real_array tmp3;
  real_array tmp4;
  real_array tmp5;
  real_array tmp6;
  real_array tmp7;
  real_array tmp8;
  real_array tmp9;
  real_array tmp10;
  real_array_create(&tmp0, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp1, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp2, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp1), tmp2),&tmp3);
  array_alloc_scalar_real_array(&tmp5, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp6, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp7, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp4, 3, tmp5, tmp6, tmp7);
  array_alloc_scalar_real_array(&tmp8, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp9, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp10, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->tmpVars[7] /* der(quad_low.rate_wb_b.$pDERD.dummyVarD[1]) JACOBIAN_TMP_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp0, tmp3), 0) + real_get(mul_alloc_real_matrix_product_smart(tmp4, sub_alloc_real_array(tmp8, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp9), tmp10))), 0);
  threadData->lastEquationSolved = 302;
}

/*
equation index: 303
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERD.dummyVarD[2] = (quad_low.Jinv * (-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {0.0, 0.0, 0.0}))[2] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_303(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,303};
  real_array tmp11;
  real_array tmp12;
  real_array tmp13;
  real_array tmp14;
  real_array tmp15;
  real_array tmp16;
  real_array tmp17;
  real_array tmp18;
  real_array tmp19;
  real_array tmp20;
  real_array tmp21;
  real_array_create(&tmp11, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp12, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp13, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp12), tmp13),&tmp14);
  array_alloc_scalar_real_array(&tmp16, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp17, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp18, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp15, 3, tmp16, tmp17, tmp18);
  array_alloc_scalar_real_array(&tmp19, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp20, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp21, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->tmpVars[8] /* der(quad_low.rate_wb_b.$pDERD.dummyVarD[2]) JACOBIAN_TMP_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp11, tmp14), 1) + real_get(mul_alloc_real_matrix_product_smart(tmp15, sub_alloc_real_array(tmp19, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp20), tmp21))), 1);
  threadData->lastEquationSolved = 303;
}

/*
equation index: 304
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERD.dummyVarD[3] = (quad_low.Jinv * (-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {0.0, 0.0, 0.0}))[3] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_304(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,304};
  real_array tmp22;
  real_array tmp23;
  real_array tmp24;
  real_array tmp25;
  real_array tmp26;
  real_array tmp27;
  real_array tmp28;
  real_array tmp29;
  real_array tmp30;
  real_array tmp31;
  real_array tmp32;
  real_array_create(&tmp22, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp23, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp24, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp23), tmp24),&tmp25);
  array_alloc_scalar_real_array(&tmp27, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp28, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp29, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp26, 3, tmp27, tmp28, tmp29);
  array_alloc_scalar_real_array(&tmp30, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp31, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp32, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->tmpVars[9] /* der(quad_low.rate_wb_b.$pDERD.dummyVarD[3]) JACOBIAN_TMP_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp22, tmp25), 2) + real_get(mul_alloc_real_matrix_product_smart(tmp26, sub_alloc_real_array(tmp30, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp31), tmp32))), 2);
  threadData->lastEquationSolved = 304;
}

OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_functionJacD_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Quadrotor_INDEX_JAC_D;
  
  
  return 0;
}

int GSQuad_Components_Quadrotor_functionJacD_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Quadrotor_INDEX_JAC_D;
  
  static void (*const eqFunctions[32])(DATA*, threadData_t*, JACOBIAN*, JACOBIAN*) = {
    GSQuad_Components_Quadrotor_eqFunction_273,
    GSQuad_Components_Quadrotor_eqFunction_274,
    GSQuad_Components_Quadrotor_eqFunction_275,
    GSQuad_Components_Quadrotor_eqFunction_276,
    GSQuad_Components_Quadrotor_eqFunction_277,
    GSQuad_Components_Quadrotor_eqFunction_278,
    GSQuad_Components_Quadrotor_eqFunction_279,
    GSQuad_Components_Quadrotor_eqFunction_280,
    GSQuad_Components_Quadrotor_eqFunction_281,
    GSQuad_Components_Quadrotor_eqFunction_282,
    GSQuad_Components_Quadrotor_eqFunction_283,
    GSQuad_Components_Quadrotor_eqFunction_284,
    GSQuad_Components_Quadrotor_eqFunction_285,
    GSQuad_Components_Quadrotor_eqFunction_286,
    GSQuad_Components_Quadrotor_eqFunction_287,
    GSQuad_Components_Quadrotor_eqFunction_288,
    GSQuad_Components_Quadrotor_eqFunction_289,
    GSQuad_Components_Quadrotor_eqFunction_290,
    GSQuad_Components_Quadrotor_eqFunction_291,
    GSQuad_Components_Quadrotor_eqFunction_292,
    GSQuad_Components_Quadrotor_eqFunction_293,
    GSQuad_Components_Quadrotor_eqFunction_294,
    GSQuad_Components_Quadrotor_eqFunction_295,
    GSQuad_Components_Quadrotor_eqFunction_296,
    GSQuad_Components_Quadrotor_eqFunction_297,
    GSQuad_Components_Quadrotor_eqFunction_298,
    GSQuad_Components_Quadrotor_eqFunction_299,
    GSQuad_Components_Quadrotor_eqFunction_300,
    GSQuad_Components_Quadrotor_eqFunction_301,
    GSQuad_Components_Quadrotor_eqFunction_302,
    GSQuad_Components_Quadrotor_eqFunction_303,
    GSQuad_Components_Quadrotor_eqFunction_304
  };
  
  for (int id = 0; id < 32; id++) {
    eqFunctions[id](data, threadData, jacobian, parentJacobian);
  }
  
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 240
type: SIMPLE_ASSIGN
pos_w_p_w_meas.$pDERC.dummyVarC[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_240(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,240};
  jacobian->resultVars[6] /* pos_w_p_w_meas.$pDERC.dummyVarC[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 240;
}

/*
equation index: 241
type: SIMPLE_ASSIGN
pos_w_p_w_meas.$pDERC.dummyVarC[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_241(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,241};
  jacobian->resultVars[7] /* pos_w_p_w_meas.$pDERC.dummyVarC[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 241;
}

/*
equation index: 242
type: SIMPLE_ASSIGN
pos_w_p_w_meas.$pDERC.dummyVarC[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_242(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,242};
  jacobian->resultVars[8] /* pos_w_p_w_meas.$pDERC.dummyVarC[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 242;
}

/*
equation index: 243
type: SIMPLE_ASSIGN
vel_w_p_b_meas.$pDERC.dummyVarC[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_243(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,243};
  jacobian->resultVars[16] /* vel_w_p_b_meas.$pDERC.dummyVarC[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 243;
}

/*
equation index: 244
type: SIMPLE_ASSIGN
vel_w_p_b_meas.$pDERC.dummyVarC[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_244(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,244};
  jacobian->resultVars[17] /* vel_w_p_b_meas.$pDERC.dummyVarC[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 244;
}

/*
equation index: 245
type: SIMPLE_ASSIGN
vel_w_p_b_meas.$pDERC.dummyVarC[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_245(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,245};
  jacobian->resultVars[18] /* vel_w_p_b_meas.$pDERC.dummyVarC[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 245;
}

/*
equation index: 246
type: SIMPLE_ASSIGN
acc_w_p_b_meas.$pDERC.dummyVarC[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_246(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,246};
  jacobian->resultVars[0] /* acc_w_p_b_meas.$pDERC.dummyVarC[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 246;
}

/*
equation index: 247
type: SIMPLE_ASSIGN
acc_w_p_b_meas.$pDERC.dummyVarC[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_247(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,247};
  jacobian->resultVars[1] /* acc_w_p_b_meas.$pDERC.dummyVarC[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 247;
}

/*
equation index: 248
type: SIMPLE_ASSIGN
acc_w_p_b_meas.$pDERC.dummyVarC[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_248(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,248};
  jacobian->resultVars[2] /* acc_w_p_b_meas.$pDERC.dummyVarC[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 248;
}

/*
equation index: 249
type: SIMPLE_ASSIGN
quat_wb_meas.$pDERC.dummyVarC[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_249(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,249};
  jacobian->resultVars[9] /* quat_wb_meas.$pDERC.dummyVarC[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 249;
}

/*
equation index: 250
type: SIMPLE_ASSIGN
quat_wb_meas.$pDERC.dummyVarC[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_250(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,250};
  jacobian->resultVars[10] /* quat_wb_meas.$pDERC.dummyVarC[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 250;
}

/*
equation index: 251
type: SIMPLE_ASSIGN
quat_wb_meas.$pDERC.dummyVarC[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_251(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,251};
  jacobian->resultVars[11] /* quat_wb_meas.$pDERC.dummyVarC[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 251;
}

/*
equation index: 252
type: SIMPLE_ASSIGN
quat_wb_meas.$pDERC.dummyVarC[4] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_252(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,252};
  jacobian->resultVars[12] /* quat_wb_meas.$pDERC.dummyVarC[4] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 252;
}

/*
equation index: 253
type: SIMPLE_ASSIGN
euler_wb_meas.$pDERC.dummyVarC[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_253(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,253};
  jacobian->resultVars[3] /* euler_wb_meas.$pDERC.dummyVarC[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 253;
}

/*
equation index: 254
type: SIMPLE_ASSIGN
euler_wb_meas.$pDERC.dummyVarC[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_254(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,254};
  jacobian->resultVars[4] /* euler_wb_meas.$pDERC.dummyVarC[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 254;
}

/*
equation index: 255
type: SIMPLE_ASSIGN
euler_wb_meas.$pDERC.dummyVarC[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_255(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,255};
  jacobian->resultVars[5] /* euler_wb_meas.$pDERC.dummyVarC[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 255;
}

/*
equation index: 256
type: SIMPLE_ASSIGN
rate_wb_b_meas.$pDERC.dummyVarC[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_256(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,256};
  jacobian->resultVars[13] /* rate_wb_b_meas.$pDERC.dummyVarC[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 256;
}

/*
equation index: 257
type: SIMPLE_ASSIGN
rate_wb_b_meas.$pDERC.dummyVarC[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_257(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,257};
  jacobian->resultVars[14] /* rate_wb_b_meas.$pDERC.dummyVarC[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 257;
}

/*
equation index: 258
type: SIMPLE_ASSIGN
rate_wb_b_meas.$pDERC.dummyVarC[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_258(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,258};
  jacobian->resultVars[15] /* rate_wb_b_meas.$pDERC.dummyVarC[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 258;
}

/*
equation index: 259
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERC.dummyVarC[3] = (quad_low.Jinv * ((-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b.SeedC[1] + quad_low.J[1,2] * quad_low.rate_wb_b.SeedC[2] + quad_low.J[1,3] * quad_low.rate_wb_b.SeedC[3], quad_low.J[2,1] * quad_low.rate_wb_b.SeedC[1] + quad_low.J[2,2] * quad_low.rate_wb_b.SeedC[2] + quad_low.J[2,3] * quad_low.rate_wb_b.SeedC[3], quad_low.J[3,1] * quad_low.rate_wb_b.SeedC[1] + quad_low.J[3,2] * quad_low.rate_wb_b.SeedC[2] + quad_low.J[3,3] * quad_low.rate_wb_b.SeedC[3]}) + {quad_low.rate_wb_b.SeedC[3] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedC[2] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedC[1] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedC[3] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedC[2] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedC[1] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3])}))[3] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_259(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,259};
  real_array tmp33;
  real_array tmp34;
  real_array tmp35;
  real_array tmp36;
  real_array tmp37;
  real_array tmp38;
  real_array tmp39;
  real_array tmp40;
  real_array tmp41;
  real_array tmp42;
  real_array tmp43;
  real_array tmp44;
  real_array_create(&tmp33, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp34, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp35, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */));
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp34), tmp35),&tmp36);
  array_alloc_scalar_real_array(&tmp37, 3, (modelica_real)(jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))));
  array_alloc_scalar_real_array(&tmp39, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp40, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp41, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp38, 3, tmp39, tmp40, tmp41);
  array_alloc_scalar_real_array(&tmp42, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp43, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp44, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->tmpVars[9] /* der(quad_low.rate_wb_b.$pDERC.dummyVarC[3]) JACOBIAN_TMP_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp33, add_alloc_real_array(tmp36, tmp37)), 2) + real_get(mul_alloc_real_matrix_product_smart(tmp38, sub_alloc_real_array(tmp42, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp43), tmp44))), 2);
  threadData->lastEquationSolved = 259;
}

/*
equation index: 260
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERC.dummyVarC[2] = (quad_low.Jinv * ((-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b.SeedC[1] + quad_low.J[1,2] * quad_low.rate_wb_b.SeedC[2] + quad_low.J[1,3] * quad_low.rate_wb_b.SeedC[3], quad_low.J[2,1] * quad_low.rate_wb_b.SeedC[1] + quad_low.J[2,2] * quad_low.rate_wb_b.SeedC[2] + quad_low.J[2,3] * quad_low.rate_wb_b.SeedC[3], quad_low.J[3,1] * quad_low.rate_wb_b.SeedC[1] + quad_low.J[3,2] * quad_low.rate_wb_b.SeedC[2] + quad_low.J[3,3] * quad_low.rate_wb_b.SeedC[3]}) + {quad_low.rate_wb_b.SeedC[3] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedC[2] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedC[1] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedC[3] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedC[2] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedC[1] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3])}))[2] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_260(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,260};
  real_array tmp45;
  real_array tmp46;
  real_array tmp47;
  real_array tmp48;
  real_array tmp49;
  real_array tmp50;
  real_array tmp51;
  real_array tmp52;
  real_array tmp53;
  real_array tmp54;
  real_array tmp55;
  real_array tmp56;
  real_array_create(&tmp45, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp46, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp47, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */));
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp46), tmp47),&tmp48);
  array_alloc_scalar_real_array(&tmp49, 3, (modelica_real)(jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))));
  array_alloc_scalar_real_array(&tmp51, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp52, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp53, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp50, 3, tmp51, tmp52, tmp53);
  array_alloc_scalar_real_array(&tmp54, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp55, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp56, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->tmpVars[8] /* der(quad_low.rate_wb_b.$pDERC.dummyVarC[2]) JACOBIAN_TMP_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp45, add_alloc_real_array(tmp48, tmp49)), 1) + real_get(mul_alloc_real_matrix_product_smart(tmp50, sub_alloc_real_array(tmp54, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp55), tmp56))), 1);
  threadData->lastEquationSolved = 260;
}

/*
equation index: 261
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERC.dummyVarC[1] = (quad_low.Jinv * ((-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b.SeedC[1] + quad_low.J[1,2] * quad_low.rate_wb_b.SeedC[2] + quad_low.J[1,3] * quad_low.rate_wb_b.SeedC[3], quad_low.J[2,1] * quad_low.rate_wb_b.SeedC[1] + quad_low.J[2,2] * quad_low.rate_wb_b.SeedC[2] + quad_low.J[2,3] * quad_low.rate_wb_b.SeedC[3], quad_low.J[3,1] * quad_low.rate_wb_b.SeedC[1] + quad_low.J[3,2] * quad_low.rate_wb_b.SeedC[2] + quad_low.J[3,3] * quad_low.rate_wb_b.SeedC[3]}) + {quad_low.rate_wb_b.SeedC[3] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedC[2] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedC[1] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedC[3] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedC[2] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedC[1] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3])}))[1] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_261(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,261};
  real_array tmp57;
  real_array tmp58;
  real_array tmp59;
  real_array tmp60;
  real_array tmp61;
  real_array tmp62;
  real_array tmp63;
  real_array tmp64;
  real_array tmp65;
  real_array tmp66;
  real_array tmp67;
  real_array tmp68;
  real_array_create(&tmp57, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp58, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp59, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */));
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp58), tmp59),&tmp60);
  array_alloc_scalar_real_array(&tmp61, 3, (modelica_real)(jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))));
  array_alloc_scalar_real_array(&tmp63, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp64, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp65, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp62, 3, tmp63, tmp64, tmp65);
  array_alloc_scalar_real_array(&tmp66, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp67, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp68, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->tmpVars[7] /* der(quad_low.rate_wb_b.$pDERC.dummyVarC[1]) JACOBIAN_TMP_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp57, add_alloc_real_array(tmp60, tmp61)), 0) + real_get(mul_alloc_real_matrix_product_smart(tmp62, sub_alloc_real_array(tmp66, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp67), tmp68))), 0);
  threadData->lastEquationSolved = 261;
}

/*
equation index: 262
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERC.dummyVarC[4] = 0.5 * (($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[1])[4] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[2])[4] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[3])[4] + quad_low.quaternion_wb.SeedC[4] * $DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0})[4]) + quad_low.quat_fdbk_correction * ((1.0 + (-quad_low.quaternion_wb[2] ^ 2.0) - quad_low.quaternion_wb[1] ^ 2.0 - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[3] ^ 2.0) * quad_low.quaternion_wb.SeedC[4] + (-2.0) * (quad_low.quaternion_wb[3] * quad_low.quaternion_wb.SeedC[3] + quad_low.quaternion_wb[4] * quad_low.quaternion_wb.SeedC[4] + quad_low.quaternion_wb[2] * quad_low.quaternion_wb.SeedC[2] + quad_low.quaternion_wb[1] * quad_low.quaternion_wb.SeedC[1]) * quad_low.quaternion_wb[4])
*/
void GSQuad_Components_Quadrotor_eqFunction_262(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,262};
  real_array tmp69;
  real_array tmp70;
  real_array tmp71;
  real_array tmp72;
  real_array tmp73;
  real_array tmp74;
  real_array tmp75;
  real_array tmp76;
  real_array tmp77;
  real_array tmp78;
  real_array tmp79;
  real_array tmp80;
  real_array tmp81;
  real_array tmp82;
  real_array tmp83;
  real_array tmp84;
  modelica_real tmp85;
  modelica_real tmp86;
  modelica_real tmp87;
  modelica_real tmp88;
  array_alloc_scalar_real_array(&tmp69, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp70, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp71, 4, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp72, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp73, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp74, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp75, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp76, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp77, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp78, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp79, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp80, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp81, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp82, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp83, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp84, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp85 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp86 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  tmp87 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp88 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  jacobian->tmpVars[6] /* der(quad_low.quaternion_wb.$pDERC.dummyVarC[4]) JACOBIAN_TMP_VAR */ = (0.5) * (real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp69, tmp70, tmp71, tmp72), jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */), 3) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp73, tmp74, tmp75, tmp76), jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */), 3) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp77, tmp78, tmp79, tmp80), jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), 3) + (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedC[4] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp81, tmp82, tmp83, tmp84), 3))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp85 * tmp85))) - ((tmp86 * tmp86)) - ((tmp87 * tmp87)) - ((tmp88 * tmp88))) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedC[4] SEED_VAR */) + ((-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedC[3] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedC[4] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedC[2] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedC[1] SEED_VAR */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)));
  threadData->lastEquationSolved = 262;
}

/*
equation index: 263
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERC.dummyVarC[3] = 0.5 * (($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[1])[3] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[2])[3] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[3])[3] + quad_low.quaternion_wb.SeedC[3] * $DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0})[3]) + quad_low.quat_fdbk_correction * ((1.0 + (-quad_low.quaternion_wb[2] ^ 2.0) - quad_low.quaternion_wb[1] ^ 2.0 - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[3] ^ 2.0) * quad_low.quaternion_wb.SeedC[3] + (-2.0) * (quad_low.quaternion_wb[3] * quad_low.quaternion_wb.SeedC[3] + quad_low.quaternion_wb[4] * quad_low.quaternion_wb.SeedC[4] + quad_low.quaternion_wb[2] * quad_low.quaternion_wb.SeedC[2] + quad_low.quaternion_wb[1] * quad_low.quaternion_wb.SeedC[1]) * quad_low.quaternion_wb[3])
*/
void GSQuad_Components_Quadrotor_eqFunction_263(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,263};
  real_array tmp89;
  real_array tmp90;
  real_array tmp91;
  real_array tmp92;
  real_array tmp93;
  real_array tmp94;
  real_array tmp95;
  real_array tmp96;
  real_array tmp97;
  real_array tmp98;
  real_array tmp99;
  real_array tmp100;
  real_array tmp101;
  real_array tmp102;
  real_array tmp103;
  real_array tmp104;
  modelica_real tmp105;
  modelica_real tmp106;
  modelica_real tmp107;
  modelica_real tmp108;
  array_alloc_scalar_real_array(&tmp89, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp90, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp91, 4, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp92, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp93, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp94, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp95, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp96, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp97, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp98, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp99, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp100, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp101, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp102, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp103, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp104, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp105 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp106 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  tmp107 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp108 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  jacobian->tmpVars[5] /* der(quad_low.quaternion_wb.$pDERC.dummyVarC[3]) JACOBIAN_TMP_VAR */ = (0.5) * (real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp89, tmp90, tmp91, tmp92), jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */), 2) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp93, tmp94, tmp95, tmp96), jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */), 2) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp97, tmp98, tmp99, tmp100), jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), 2) + (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedC[3] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp101, tmp102, tmp103, tmp104), 2))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp105 * tmp105))) - ((tmp106 * tmp106)) - ((tmp107 * tmp107)) - ((tmp108 * tmp108))) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedC[3] SEED_VAR */) + ((-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedC[3] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedC[4] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedC[2] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedC[1] SEED_VAR */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)));
  threadData->lastEquationSolved = 263;
}

/*
equation index: 264
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERC.dummyVarC[2] = 0.5 * (($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[1])[2] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[2])[2] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[3])[2] + quad_low.quaternion_wb.SeedC[2] * $DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0})[2]) + quad_low.quat_fdbk_correction * ((1.0 + (-quad_low.quaternion_wb[2] ^ 2.0) - quad_low.quaternion_wb[1] ^ 2.0 - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[3] ^ 2.0) * quad_low.quaternion_wb.SeedC[2] + (-2.0) * (quad_low.quaternion_wb[3] * quad_low.quaternion_wb.SeedC[3] + quad_low.quaternion_wb[4] * quad_low.quaternion_wb.SeedC[4] + quad_low.quaternion_wb[2] * quad_low.quaternion_wb.SeedC[2] + quad_low.quaternion_wb[1] * quad_low.quaternion_wb.SeedC[1]) * quad_low.quaternion_wb[2])
*/
void GSQuad_Components_Quadrotor_eqFunction_264(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,264};
  real_array tmp109;
  real_array tmp110;
  real_array tmp111;
  real_array tmp112;
  real_array tmp113;
  real_array tmp114;
  real_array tmp115;
  real_array tmp116;
  real_array tmp117;
  real_array tmp118;
  real_array tmp119;
  real_array tmp120;
  real_array tmp121;
  real_array tmp122;
  real_array tmp123;
  real_array tmp124;
  modelica_real tmp125;
  modelica_real tmp126;
  modelica_real tmp127;
  modelica_real tmp128;
  array_alloc_scalar_real_array(&tmp109, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp110, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp111, 4, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp112, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp113, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp114, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp115, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp116, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp117, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp118, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp119, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp120, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp121, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp122, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp123, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp124, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp125 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp126 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  tmp127 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp128 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  jacobian->tmpVars[4] /* der(quad_low.quaternion_wb.$pDERC.dummyVarC[2]) JACOBIAN_TMP_VAR */ = (0.5) * (real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp109, tmp110, tmp111, tmp112), jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */), 1) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp113, tmp114, tmp115, tmp116), jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */), 1) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp117, tmp118, tmp119, tmp120), jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), 1) + (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedC[2] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp121, tmp122, tmp123, tmp124), 1))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp125 * tmp125))) - ((tmp126 * tmp126)) - ((tmp127 * tmp127)) - ((tmp128 * tmp128))) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedC[2] SEED_VAR */) + ((-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedC[3] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedC[4] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedC[2] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedC[1] SEED_VAR */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)));
  threadData->lastEquationSolved = 264;
}

/*
equation index: 265
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERC.dummyVarC[1] = 0.5 * (($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[1])[1] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[2])[1] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedC[3])[1] + quad_low.quaternion_wb.SeedC[1] * $DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0})[1]) + quad_low.quat_fdbk_correction * ((1.0 + (-quad_low.quaternion_wb[2] ^ 2.0) - quad_low.quaternion_wb[1] ^ 2.0 - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[3] ^ 2.0) * quad_low.quaternion_wb.SeedC[1] + (-2.0) * (quad_low.quaternion_wb[3] * quad_low.quaternion_wb.SeedC[3] + quad_low.quaternion_wb[4] * quad_low.quaternion_wb.SeedC[4] + quad_low.quaternion_wb[2] * quad_low.quaternion_wb.SeedC[2] + quad_low.quaternion_wb[1] * quad_low.quaternion_wb.SeedC[1]) * quad_low.quaternion_wb[1])
*/
void GSQuad_Components_Quadrotor_eqFunction_265(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,265};
  real_array tmp129;
  real_array tmp130;
  real_array tmp131;
  real_array tmp132;
  real_array tmp133;
  real_array tmp134;
  real_array tmp135;
  real_array tmp136;
  real_array tmp137;
  real_array tmp138;
  real_array tmp139;
  real_array tmp140;
  real_array tmp141;
  real_array tmp142;
  real_array tmp143;
  real_array tmp144;
  modelica_real tmp145;
  modelica_real tmp146;
  modelica_real tmp147;
  modelica_real tmp148;
  array_alloc_scalar_real_array(&tmp129, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp130, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp131, 4, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp132, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp133, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp134, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp135, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp136, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp137, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp138, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp139, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp140, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp141, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp142, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp143, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp144, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp145 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp146 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  tmp147 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp148 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  jacobian->tmpVars[3] /* der(quad_low.quaternion_wb.$pDERC.dummyVarC[1]) JACOBIAN_TMP_VAR */ = (0.5) * (real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp129, tmp130, tmp131, tmp132), jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */), 0) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp133, tmp134, tmp135, tmp136), jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */), 0) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp137, tmp138, tmp139, tmp140), jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */), 0) + (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedC[1] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp141, tmp142, tmp143, tmp144), 0))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp145 * tmp145))) - ((tmp146 * tmp146)) - ((tmp147 * tmp147)) - ((tmp148 * tmp148))) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedC[1] SEED_VAR */) + ((-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedC[3] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedC[4] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedC[2] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedC[1] SEED_VAR */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)));
  threadData->lastEquationSolved = 265;
}

/*
equation index: 266
type: ARRAY_CALL_ASSIGN

quad_low.C_wb.$pDERC.dummyVarC = transpose(quad_low.quaternion_wb.SeedC .* $DER$GSQuad$PUtils$Pquat2rot(quad_low.quaternion_wb, {1.0, 1.0, 1.0, 1.0}))
*/
void GSQuad_Components_Quadrotor_eqFunction_266(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,266};
  real_array tmp149;
  real_array tmp150;
  real_array tmp151;
  real_array tmp152;
  real_array tmp153;
  real_array tmp154;
  real_array_create(&tmp149, ((modelica_real*)&(jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedC[1] SEED_VAR */)), 1, (_index_t)4);
  real_array_create(&tmp150, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp151, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp152 = mul_alloc_real_array(tmp149, omc__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot(threadData, tmp150, tmp151));
  transpose_alloc_real_array(&tmp152, &tmp153);
  real_array_create(&tmp154, ((modelica_real*)&((&jacobian->tmpVars[15] /* quad_low.C_wb.$pDERC.dummyVarC[1,1] JACOBIAN_TMP_VAR */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp153, tmp154);
  threadData->lastEquationSolved = 266;
}

/*
equation index: 267
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERC.dummyVarC[3] = 9.80665 * quad_low.C_wb.$pDERC.dummyVarC[3,3] + (-quad_low.rate_wb_b.SeedC[3]) * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0})[3] - quad_low.velocity_w_p_b.SeedC[3] * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0})[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_267(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,267};
  real_array tmp155;
  real_array tmp156;
  real_array tmp157;
  real_array tmp158;
  real_array tmp159;
  real_array tmp160;
  real_array tmp161;
  real_array tmp162;
  real_array_create(&tmp155, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp156, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp157, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp158, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  real_array_create(&tmp159, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp160, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp161, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp162, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  jacobian->tmpVars[12] /* der(quad_low.velocity_w_p_b.$pDERC.dummyVarC[3]) JACOBIAN_TMP_VAR */ = (9.80665) * (jacobian->tmpVars[23] /* quad_low.C_wb.$pDERC.dummyVarC[3,3] JACOBIAN_TMP_VAR */) + ((-jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedC[3] SEED_VAR */)) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp155, tmp156, tmp157, tmp158), 2)) - ((jacobian->seedVars[12] /* quad_low.velocity_w_p_b.SeedC[3] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp159, tmp160, tmp161, tmp162), 2)));
  threadData->lastEquationSolved = 267;
}

/*
equation index: 268
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERC.dummyVarC[2] = 9.80665 * quad_low.C_wb.$pDERC.dummyVarC[2,3] + (-quad_low.rate_wb_b.SeedC[2]) * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0})[2] - quad_low.velocity_w_p_b.SeedC[2] * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0})[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_268(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,268};
  real_array tmp163;
  real_array tmp164;
  real_array tmp165;
  real_array tmp166;
  real_array tmp167;
  real_array tmp168;
  real_array tmp169;
  real_array tmp170;
  real_array_create(&tmp163, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp164, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp165, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp166, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  real_array_create(&tmp167, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp168, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp169, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp170, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  jacobian->tmpVars[11] /* der(quad_low.velocity_w_p_b.$pDERC.dummyVarC[2]) JACOBIAN_TMP_VAR */ = (9.80665) * (jacobian->tmpVars[20] /* quad_low.C_wb.$pDERC.dummyVarC[2,3] JACOBIAN_TMP_VAR */) + ((-jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedC[2] SEED_VAR */)) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp163, tmp164, tmp165, tmp166), 1)) - ((jacobian->seedVars[11] /* quad_low.velocity_w_p_b.SeedC[2] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp167, tmp168, tmp169, tmp170), 1)));
  threadData->lastEquationSolved = 268;
}

/*
equation index: 269
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERC.dummyVarC[1] = quad_low.C_wb[1,1] * quad_low.velocity_w_p_b.SeedC[1] + quad_low.C_wb.$pDERC.dummyVarC[1,1] * quad_low.velocity_w_p_b[1] + quad_low.C_wb[2,1] * quad_low.velocity_w_p_b.SeedC[2] + quad_low.C_wb.$pDERC.dummyVarC[2,1] * quad_low.velocity_w_p_b[2] + quad_low.C_wb[3,1] * quad_low.velocity_w_p_b.SeedC[3] + quad_low.C_wb.$pDERC.dummyVarC[3,1] * quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_269(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,269};
  jacobian->tmpVars[0] /* der(quad_low.position_w_p_w.$pDERC.dummyVarC[1]) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* quad_low.C_wb[1,1] variable */)) * (jacobian->seedVars[10] /* quad_low.velocity_w_p_b.SeedC[1] SEED_VAR */) + (jacobian->tmpVars[15] /* quad_low.C_wb.$pDERC.dummyVarC[1,1] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* quad_low.C_wb[2,1] variable */)) * (jacobian->seedVars[11] /* quad_low.velocity_w_p_b.SeedC[2] SEED_VAR */) + (jacobian->tmpVars[18] /* quad_low.C_wb.$pDERC.dummyVarC[2,1] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* quad_low.C_wb[3,1] variable */)) * (jacobian->seedVars[12] /* quad_low.velocity_w_p_b.SeedC[3] SEED_VAR */) + (jacobian->tmpVars[21] /* quad_low.C_wb.$pDERC.dummyVarC[3,1] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */));
  threadData->lastEquationSolved = 269;
}

/*
equation index: 270
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERC.dummyVarC[3] = quad_low.C_wb[1,3] * quad_low.velocity_w_p_b.SeedC[1] + quad_low.C_wb.$pDERC.dummyVarC[1,3] * quad_low.velocity_w_p_b[1] + quad_low.C_wb[2,3] * quad_low.velocity_w_p_b.SeedC[2] + quad_low.C_wb.$pDERC.dummyVarC[2,3] * quad_low.velocity_w_p_b[2] + quad_low.C_wb[3,3] * quad_low.velocity_w_p_b.SeedC[3] + quad_low.C_wb.$pDERC.dummyVarC[3,3] * quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_270(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,270};
  jacobian->tmpVars[2] /* der(quad_low.position_w_p_w.$pDERC.dummyVarC[3]) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* quad_low.C_wb[1,3] variable */)) * (jacobian->seedVars[10] /* quad_low.velocity_w_p_b.SeedC[1] SEED_VAR */) + (jacobian->tmpVars[17] /* quad_low.C_wb.$pDERC.dummyVarC[1,3] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* quad_low.C_wb[2,3] variable */)) * (jacobian->seedVars[11] /* quad_low.velocity_w_p_b.SeedC[2] SEED_VAR */) + (jacobian->tmpVars[20] /* quad_low.C_wb.$pDERC.dummyVarC[2,3] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* quad_low.C_wb[3,3] variable */)) * (jacobian->seedVars[12] /* quad_low.velocity_w_p_b.SeedC[3] SEED_VAR */) + (jacobian->tmpVars[23] /* quad_low.C_wb.$pDERC.dummyVarC[3,3] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */));
  threadData->lastEquationSolved = 270;
}

/*
equation index: 271
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERC.dummyVarC[1] = 9.80665 * quad_low.C_wb.$pDERC.dummyVarC[1,3] + (-quad_low.rate_wb_b.SeedC[1]) * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0})[1] - quad_low.velocity_w_p_b.SeedC[1] * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0})[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_271(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,271};
  real_array tmp171;
  real_array tmp172;
  real_array tmp173;
  real_array tmp174;
  real_array tmp175;
  real_array tmp176;
  real_array tmp177;
  real_array tmp178;
  real_array_create(&tmp171, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp172, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp173, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp174, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  real_array_create(&tmp175, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp176, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp177, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp178, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  jacobian->tmpVars[10] /* der(quad_low.velocity_w_p_b.$pDERC.dummyVarC[1]) JACOBIAN_TMP_VAR */ = (9.80665) * (jacobian->tmpVars[17] /* quad_low.C_wb.$pDERC.dummyVarC[1,3] JACOBIAN_TMP_VAR */) + ((-jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedC[1] SEED_VAR */)) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp171, tmp172, tmp173, tmp174), 0)) - ((jacobian->seedVars[10] /* quad_low.velocity_w_p_b.SeedC[1] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp175, tmp176, tmp177, tmp178), 0)));
  threadData->lastEquationSolved = 271;
}

/*
equation index: 272
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERC.dummyVarC[2] = quad_low.C_wb[1,2] * quad_low.velocity_w_p_b.SeedC[1] + quad_low.C_wb.$pDERC.dummyVarC[1,2] * quad_low.velocity_w_p_b[1] + quad_low.C_wb[2,2] * quad_low.velocity_w_p_b.SeedC[2] + quad_low.C_wb.$pDERC.dummyVarC[2,2] * quad_low.velocity_w_p_b[2] + quad_low.C_wb[3,2] * quad_low.velocity_w_p_b.SeedC[3] + quad_low.C_wb.$pDERC.dummyVarC[3,2] * quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_272(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 32;
  const int equationIndexes[2] = {1,272};
  jacobian->tmpVars[1] /* der(quad_low.position_w_p_w.$pDERC.dummyVarC[2]) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* quad_low.C_wb[1,2] variable */)) * (jacobian->seedVars[10] /* quad_low.velocity_w_p_b.SeedC[1] SEED_VAR */) + (jacobian->tmpVars[16] /* quad_low.C_wb.$pDERC.dummyVarC[1,2] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* quad_low.C_wb[2,2] variable */)) * (jacobian->seedVars[11] /* quad_low.velocity_w_p_b.SeedC[2] SEED_VAR */) + (jacobian->tmpVars[19] /* quad_low.C_wb.$pDERC.dummyVarC[2,2] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* quad_low.C_wb[3,2] variable */)) * (jacobian->seedVars[12] /* quad_low.velocity_w_p_b.SeedC[3] SEED_VAR */) + (jacobian->tmpVars[22] /* quad_low.C_wb.$pDERC.dummyVarC[3,2] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */));
  threadData->lastEquationSolved = 272;
}

OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_functionJacC_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Quadrotor_INDEX_JAC_C;
  
  
  return 0;
}

int GSQuad_Components_Quadrotor_functionJacC_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Quadrotor_INDEX_JAC_C;
  
  static void (*const eqFunctions[33])(DATA*, threadData_t*, JACOBIAN*, JACOBIAN*) = {
    GSQuad_Components_Quadrotor_eqFunction_240,
    GSQuad_Components_Quadrotor_eqFunction_241,
    GSQuad_Components_Quadrotor_eqFunction_242,
    GSQuad_Components_Quadrotor_eqFunction_243,
    GSQuad_Components_Quadrotor_eqFunction_244,
    GSQuad_Components_Quadrotor_eqFunction_245,
    GSQuad_Components_Quadrotor_eqFunction_246,
    GSQuad_Components_Quadrotor_eqFunction_247,
    GSQuad_Components_Quadrotor_eqFunction_248,
    GSQuad_Components_Quadrotor_eqFunction_249,
    GSQuad_Components_Quadrotor_eqFunction_250,
    GSQuad_Components_Quadrotor_eqFunction_251,
    GSQuad_Components_Quadrotor_eqFunction_252,
    GSQuad_Components_Quadrotor_eqFunction_253,
    GSQuad_Components_Quadrotor_eqFunction_254,
    GSQuad_Components_Quadrotor_eqFunction_255,
    GSQuad_Components_Quadrotor_eqFunction_256,
    GSQuad_Components_Quadrotor_eqFunction_257,
    GSQuad_Components_Quadrotor_eqFunction_258,
    GSQuad_Components_Quadrotor_eqFunction_259,
    GSQuad_Components_Quadrotor_eqFunction_260,
    GSQuad_Components_Quadrotor_eqFunction_261,
    GSQuad_Components_Quadrotor_eqFunction_262,
    GSQuad_Components_Quadrotor_eqFunction_263,
    GSQuad_Components_Quadrotor_eqFunction_264,
    GSQuad_Components_Quadrotor_eqFunction_265,
    GSQuad_Components_Quadrotor_eqFunction_266,
    GSQuad_Components_Quadrotor_eqFunction_267,
    GSQuad_Components_Quadrotor_eqFunction_268,
    GSQuad_Components_Quadrotor_eqFunction_269,
    GSQuad_Components_Quadrotor_eqFunction_270,
    GSQuad_Components_Quadrotor_eqFunction_271,
    GSQuad_Components_Quadrotor_eqFunction_272
  };
  
  for (int id = 0; id < 33; id++) {
    eqFunctions[id](data, threadData, jacobian, parentJacobian);
  }
  
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 227
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERB.dummyVarB[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_227(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,227};
  jacobian->resultVars[3] /* der(quad_low.quaternion_wb.$pDERB.dummyVarB[1]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 227;
}

/*
equation index: 228
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERB.dummyVarB[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_228(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,228};
  jacobian->resultVars[4] /* der(quad_low.quaternion_wb.$pDERB.dummyVarB[2]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 228;
}

/*
equation index: 229
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERB.dummyVarB[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_229(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,229};
  jacobian->resultVars[5] /* der(quad_low.quaternion_wb.$pDERB.dummyVarB[3]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 229;
}

/*
equation index: 230
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERB.dummyVarB[4] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_230(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,230};
  jacobian->resultVars[6] /* der(quad_low.quaternion_wb.$pDERB.dummyVarB[4]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 230;
}

/*
equation index: 231
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERB.dummyVarB[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_231(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,231};
  jacobian->resultVars[11] /* der(quad_low.velocity_w_p_b.$pDERB.dummyVarB[2]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 231;
}

/*
equation index: 232
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERB.dummyVarB[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_232(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,232};
  jacobian->resultVars[10] /* der(quad_low.velocity_w_p_b.$pDERB.dummyVarB[1]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 232;
}

/*
equation index: 233
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERB.dummyVarB[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_233(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,233};
  jacobian->resultVars[2] /* der(quad_low.position_w_p_w.$pDERB.dummyVarB[3]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 233;
}

/*
equation index: 234
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERB.dummyVarB[2] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_234(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,234};
  jacobian->resultVars[1] /* der(quad_low.position_w_p_w.$pDERB.dummyVarB[2]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 234;
}

/*
equation index: 235
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERB.dummyVarB[1] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_235(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,235};
  jacobian->resultVars[0] /* der(quad_low.position_w_p_w.$pDERB.dummyVarB[1]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 235;
}

/*
equation index: 236
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERB.dummyVarB[3] = 0.0
*/
void GSQuad_Components_Quadrotor_eqFunction_236(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,236};
  jacobian->resultVars[12] /* der(quad_low.velocity_w_p_b.$pDERB.dummyVarB[3]) JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 236;
}

/*
equation index: 237
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERB.dummyVarB[1] = (quad_low.Jinv * (-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {0.0, 0.0, 0.0}))[1] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_237(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,237};
  real_array tmp179;
  real_array tmp180;
  real_array tmp181;
  real_array tmp182;
  real_array tmp183;
  real_array tmp184;
  real_array tmp185;
  real_array tmp186;
  real_array tmp187;
  real_array tmp188;
  real_array tmp189;
  real_array_create(&tmp179, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp180, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp181, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp180), tmp181),&tmp182);
  array_alloc_scalar_real_array(&tmp184, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp185, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp186, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp183, 3, tmp184, tmp185, tmp186);
  array_alloc_scalar_real_array(&tmp187, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp188, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp189, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->resultVars[7] /* der(quad_low.rate_wb_b.$pDERB.dummyVarB[1]) JACOBIAN_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp179, tmp182), 0) + real_get(mul_alloc_real_matrix_product_smart(tmp183, sub_alloc_real_array(tmp187, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp188), tmp189))), 0);
  threadData->lastEquationSolved = 237;
}

/*
equation index: 238
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERB.dummyVarB[2] = (quad_low.Jinv * (-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {0.0, 0.0, 0.0}))[2] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_238(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,238};
  real_array tmp190;
  real_array tmp191;
  real_array tmp192;
  real_array tmp193;
  real_array tmp194;
  real_array tmp195;
  real_array tmp196;
  real_array tmp197;
  real_array tmp198;
  real_array tmp199;
  real_array tmp200;
  real_array_create(&tmp190, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp191, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp192, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp191), tmp192),&tmp193);
  array_alloc_scalar_real_array(&tmp195, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp196, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp197, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp194, 3, tmp195, tmp196, tmp197);
  array_alloc_scalar_real_array(&tmp198, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp199, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp200, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->resultVars[8] /* der(quad_low.rate_wb_b.$pDERB.dummyVarB[2]) JACOBIAN_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp190, tmp193), 1) + real_get(mul_alloc_real_matrix_product_smart(tmp194, sub_alloc_real_array(tmp198, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp199), tmp200))), 1);
  threadData->lastEquationSolved = 238;
}

/*
equation index: 239
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERB.dummyVarB[3] = (quad_low.Jinv * (-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {0.0, 0.0, 0.0}))[3] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_239(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,239};
  real_array tmp201;
  real_array tmp202;
  real_array tmp203;
  real_array tmp204;
  real_array tmp205;
  real_array tmp206;
  real_array tmp207;
  real_array tmp208;
  real_array tmp209;
  real_array tmp210;
  real_array tmp211;
  real_array_create(&tmp201, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp202, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp203, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp202), tmp203),&tmp204);
  array_alloc_scalar_real_array(&tmp206, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp207, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp208, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp205, 3, tmp206, tmp207, tmp208);
  array_alloc_scalar_real_array(&tmp209, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp210, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp211, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->resultVars[9] /* der(quad_low.rate_wb_b.$pDERB.dummyVarB[3]) JACOBIAN_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp201, tmp204), 2) + real_get(mul_alloc_real_matrix_product_smart(tmp205, sub_alloc_real_array(tmp209, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp210), tmp211))), 2);
  threadData->lastEquationSolved = 239;
}

OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_functionJacB_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Quadrotor_INDEX_JAC_B;
  
  
  return 0;
}

int GSQuad_Components_Quadrotor_functionJacB_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Quadrotor_INDEX_JAC_B;
  
  static void (*const eqFunctions[13])(DATA*, threadData_t*, JACOBIAN*, JACOBIAN*) = {
    GSQuad_Components_Quadrotor_eqFunction_227,
    GSQuad_Components_Quadrotor_eqFunction_228,
    GSQuad_Components_Quadrotor_eqFunction_229,
    GSQuad_Components_Quadrotor_eqFunction_230,
    GSQuad_Components_Quadrotor_eqFunction_231,
    GSQuad_Components_Quadrotor_eqFunction_232,
    GSQuad_Components_Quadrotor_eqFunction_233,
    GSQuad_Components_Quadrotor_eqFunction_234,
    GSQuad_Components_Quadrotor_eqFunction_235,
    GSQuad_Components_Quadrotor_eqFunction_236,
    GSQuad_Components_Quadrotor_eqFunction_237,
    GSQuad_Components_Quadrotor_eqFunction_238,
    GSQuad_Components_Quadrotor_eqFunction_239
  };
  
  for (int id = 0; id < 13; id++) {
    eqFunctions[id](data, threadData, jacobian, parentJacobian);
  }
  
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 213
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERA.dummyVarA[3] = (quad_low.Jinv * ((-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b.SeedA[1] + quad_low.J[1,2] * quad_low.rate_wb_b.SeedA[2] + quad_low.J[1,3] * quad_low.rate_wb_b.SeedA[3], quad_low.J[2,1] * quad_low.rate_wb_b.SeedA[1] + quad_low.J[2,2] * quad_low.rate_wb_b.SeedA[2] + quad_low.J[2,3] * quad_low.rate_wb_b.SeedA[3], quad_low.J[3,1] * quad_low.rate_wb_b.SeedA[1] + quad_low.J[3,2] * quad_low.rate_wb_b.SeedA[2] + quad_low.J[3,3] * quad_low.rate_wb_b.SeedA[3]}) + {quad_low.rate_wb_b.SeedA[3] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedA[2] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedA[1] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedA[3] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedA[2] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedA[1] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3])}))[3] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_213(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,213};
  real_array tmp212;
  real_array tmp213;
  real_array tmp214;
  real_array tmp215;
  real_array tmp216;
  real_array tmp217;
  real_array tmp218;
  real_array tmp219;
  real_array tmp220;
  real_array tmp221;
  real_array tmp222;
  real_array tmp223;
  real_array_create(&tmp212, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp213, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp214, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */));
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp213), tmp214),&tmp215);
  array_alloc_scalar_real_array(&tmp216, 3, (modelica_real)(jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))));
  array_alloc_scalar_real_array(&tmp218, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp219, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp220, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp217, 3, tmp218, tmp219, tmp220);
  array_alloc_scalar_real_array(&tmp221, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp222, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp223, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->resultVars[9] /* der(quad_low.rate_wb_b.$pDERA.dummyVarA[3]) JACOBIAN_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp212, add_alloc_real_array(tmp215, tmp216)), 2) + real_get(mul_alloc_real_matrix_product_smart(tmp217, sub_alloc_real_array(tmp221, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp222), tmp223))), 2);
  threadData->lastEquationSolved = 213;
}

/*
equation index: 214
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERA.dummyVarA[2] = (quad_low.Jinv * ((-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b.SeedA[1] + quad_low.J[1,2] * quad_low.rate_wb_b.SeedA[2] + quad_low.J[1,3] * quad_low.rate_wb_b.SeedA[3], quad_low.J[2,1] * quad_low.rate_wb_b.SeedA[1] + quad_low.J[2,2] * quad_low.rate_wb_b.SeedA[2] + quad_low.J[2,3] * quad_low.rate_wb_b.SeedA[3], quad_low.J[3,1] * quad_low.rate_wb_b.SeedA[1] + quad_low.J[3,2] * quad_low.rate_wb_b.SeedA[2] + quad_low.J[3,3] * quad_low.rate_wb_b.SeedA[3]}) + {quad_low.rate_wb_b.SeedA[3] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedA[2] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedA[1] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedA[3] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedA[2] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedA[1] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3])}))[2] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_214(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,214};
  real_array tmp224;
  real_array tmp225;
  real_array tmp226;
  real_array tmp227;
  real_array tmp228;
  real_array tmp229;
  real_array tmp230;
  real_array tmp231;
  real_array tmp232;
  real_array tmp233;
  real_array tmp234;
  real_array tmp235;
  real_array_create(&tmp224, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp225, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp226, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */));
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp225), tmp226),&tmp227);
  array_alloc_scalar_real_array(&tmp228, 3, (modelica_real)(jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))));
  array_alloc_scalar_real_array(&tmp230, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp231, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp232, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp229, 3, tmp230, tmp231, tmp232);
  array_alloc_scalar_real_array(&tmp233, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp234, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp235, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->resultVars[8] /* der(quad_low.rate_wb_b.$pDERA.dummyVarA[2]) JACOBIAN_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp224, add_alloc_real_array(tmp227, tmp228)), 1) + real_get(mul_alloc_real_matrix_product_smart(tmp229, sub_alloc_real_array(tmp233, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp234), tmp235))), 1);
  threadData->lastEquationSolved = 214;
}

/*
equation index: 215
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b.$pDERA.dummyVarA[1] = (quad_low.Jinv * ((-GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b.SeedA[1] + quad_low.J[1,2] * quad_low.rate_wb_b.SeedA[2] + quad_low.J[1,3] * quad_low.rate_wb_b.SeedA[3], quad_low.J[2,1] * quad_low.rate_wb_b.SeedA[1] + quad_low.J[2,2] * quad_low.rate_wb_b.SeedA[2] + quad_low.J[2,3] * quad_low.rate_wb_b.SeedA[3], quad_low.J[3,1] * quad_low.rate_wb_b.SeedA[1] + quad_low.J[3,2] * quad_low.rate_wb_b.SeedA[2] + quad_low.J[3,3] * quad_low.rate_wb_b.SeedA[3]}) + {quad_low.rate_wb_b.SeedA[3] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedA[2] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedA[1] * (quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedA[3] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]), quad_low.rate_wb_b.SeedA[2] * (quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3]) - quad_low.rate_wb_b.SeedA[1] * (quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3])}))[1] + ({{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} * ({quad_low.M_b[1], quad_low.M_b[2], quad_low.M_b[3]} - GSQuad.Utils.hatmap({quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]}))[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_215(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,215};
  real_array tmp236;
  real_array tmp237;
  real_array tmp238;
  real_array tmp239;
  real_array tmp240;
  real_array tmp241;
  real_array tmp242;
  real_array tmp243;
  real_array tmp244;
  real_array tmp245;
  real_array tmp246;
  real_array tmp247;
  real_array_create(&tmp236, ((modelica_real*)&((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))), 2, (_index_t)3, (_index_t)3);
  array_alloc_scalar_real_array(&tmp237, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp238, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * (jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * (jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * (jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */));
  usub_alloc_real_array(mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp237), tmp238),&tmp239);
  array_alloc_scalar_real_array(&tmp240, 3, (modelica_real)(jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))), (modelica_real)(jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */))) - ((jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)))));
  array_alloc_scalar_real_array(&tmp242, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp243, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp244, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_real_array(&tmp241, 3, tmp242, tmp243, tmp244);
  array_alloc_scalar_real_array(&tmp245, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */));
  array_alloc_scalar_real_array(&tmp246, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  array_alloc_scalar_real_array(&tmp247, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  jacobian->resultVars[7] /* der(quad_low.rate_wb_b.$pDERA.dummyVarA[1]) JACOBIAN_VAR */ = real_get(mul_alloc_real_matrix_product_smart(tmp236, add_alloc_real_array(tmp239, tmp240)), 0) + real_get(mul_alloc_real_matrix_product_smart(tmp241, sub_alloc_real_array(tmp245, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp246), tmp247))), 0);
  threadData->lastEquationSolved = 215;
}

/*
equation index: 216
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERA.dummyVarA[4] = 0.5 * (($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[1])[4] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[2])[4] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[3])[4] + quad_low.quaternion_wb.SeedA[4] * $DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0})[4]) + quad_low.quat_fdbk_correction * ((1.0 + (-quad_low.quaternion_wb[2] ^ 2.0) - quad_low.quaternion_wb[1] ^ 2.0 - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[3] ^ 2.0) * quad_low.quaternion_wb.SeedA[4] + (-2.0) * (quad_low.quaternion_wb[3] * quad_low.quaternion_wb.SeedA[3] + quad_low.quaternion_wb[4] * quad_low.quaternion_wb.SeedA[4] + quad_low.quaternion_wb[2] * quad_low.quaternion_wb.SeedA[2] + quad_low.quaternion_wb[1] * quad_low.quaternion_wb.SeedA[1]) * quad_low.quaternion_wb[4])
*/
void GSQuad_Components_Quadrotor_eqFunction_216(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,216};
  real_array tmp248;
  real_array tmp249;
  real_array tmp250;
  real_array tmp251;
  real_array tmp252;
  real_array tmp253;
  real_array tmp254;
  real_array tmp255;
  real_array tmp256;
  real_array tmp257;
  real_array tmp258;
  real_array tmp259;
  real_array tmp260;
  real_array tmp261;
  real_array tmp262;
  real_array tmp263;
  modelica_real tmp264;
  modelica_real tmp265;
  modelica_real tmp266;
  modelica_real tmp267;
  array_alloc_scalar_real_array(&tmp248, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp249, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp250, 4, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp251, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp252, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp253, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp254, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp255, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp256, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp257, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp258, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp259, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp260, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp261, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp262, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp263, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp264 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp265 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  tmp266 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp267 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  jacobian->resultVars[6] /* der(quad_low.quaternion_wb.$pDERA.dummyVarA[4]) JACOBIAN_VAR */ = (0.5) * (real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp248, tmp249, tmp250, tmp251), jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */), 3) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp252, tmp253, tmp254, tmp255), jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */), 3) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp256, tmp257, tmp258, tmp259), jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), 3) + (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedA[4] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp260, tmp261, tmp262, tmp263), 3))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp264 * tmp264))) - ((tmp265 * tmp265)) - ((tmp266 * tmp266)) - ((tmp267 * tmp267))) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedA[4] SEED_VAR */) + ((-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedA[3] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedA[4] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedA[2] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedA[1] SEED_VAR */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)));
  threadData->lastEquationSolved = 216;
}

/*
equation index: 217
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERA.dummyVarA[3] = 0.5 * (($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[1])[3] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[2])[3] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[3])[3] + quad_low.quaternion_wb.SeedA[3] * $DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0})[3]) + quad_low.quat_fdbk_correction * ((1.0 + (-quad_low.quaternion_wb[2] ^ 2.0) - quad_low.quaternion_wb[1] ^ 2.0 - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[3] ^ 2.0) * quad_low.quaternion_wb.SeedA[3] + (-2.0) * (quad_low.quaternion_wb[3] * quad_low.quaternion_wb.SeedA[3] + quad_low.quaternion_wb[4] * quad_low.quaternion_wb.SeedA[4] + quad_low.quaternion_wb[2] * quad_low.quaternion_wb.SeedA[2] + quad_low.quaternion_wb[1] * quad_low.quaternion_wb.SeedA[1]) * quad_low.quaternion_wb[3])
*/
void GSQuad_Components_Quadrotor_eqFunction_217(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,217};
  real_array tmp268;
  real_array tmp269;
  real_array tmp270;
  real_array tmp271;
  real_array tmp272;
  real_array tmp273;
  real_array tmp274;
  real_array tmp275;
  real_array tmp276;
  real_array tmp277;
  real_array tmp278;
  real_array tmp279;
  real_array tmp280;
  real_array tmp281;
  real_array tmp282;
  real_array tmp283;
  modelica_real tmp284;
  modelica_real tmp285;
  modelica_real tmp286;
  modelica_real tmp287;
  array_alloc_scalar_real_array(&tmp268, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp269, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp270, 4, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp271, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp272, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp273, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp274, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp275, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp276, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp277, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp278, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp279, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp280, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp281, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp282, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp283, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp284 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp285 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  tmp286 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp287 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  jacobian->resultVars[5] /* der(quad_low.quaternion_wb.$pDERA.dummyVarA[3]) JACOBIAN_VAR */ = (0.5) * (real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp268, tmp269, tmp270, tmp271), jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */), 2) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp272, tmp273, tmp274, tmp275), jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */), 2) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp276, tmp277, tmp278, tmp279), jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), 2) + (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedA[3] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp280, tmp281, tmp282, tmp283), 2))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp284 * tmp284))) - ((tmp285 * tmp285)) - ((tmp286 * tmp286)) - ((tmp287 * tmp287))) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedA[3] SEED_VAR */) + ((-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedA[3] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedA[4] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedA[2] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedA[1] SEED_VAR */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)));
  threadData->lastEquationSolved = 217;
}

/*
equation index: 218
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERA.dummyVarA[2] = 0.5 * (($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[1])[2] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[2])[2] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[3])[2] + quad_low.quaternion_wb.SeedA[2] * $DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0})[2]) + quad_low.quat_fdbk_correction * ((1.0 + (-quad_low.quaternion_wb[2] ^ 2.0) - quad_low.quaternion_wb[1] ^ 2.0 - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[3] ^ 2.0) * quad_low.quaternion_wb.SeedA[2] + (-2.0) * (quad_low.quaternion_wb[3] * quad_low.quaternion_wb.SeedA[3] + quad_low.quaternion_wb[4] * quad_low.quaternion_wb.SeedA[4] + quad_low.quaternion_wb[2] * quad_low.quaternion_wb.SeedA[2] + quad_low.quaternion_wb[1] * quad_low.quaternion_wb.SeedA[1]) * quad_low.quaternion_wb[2])
*/
void GSQuad_Components_Quadrotor_eqFunction_218(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,218};
  real_array tmp288;
  real_array tmp289;
  real_array tmp290;
  real_array tmp291;
  real_array tmp292;
  real_array tmp293;
  real_array tmp294;
  real_array tmp295;
  real_array tmp296;
  real_array tmp297;
  real_array tmp298;
  real_array tmp299;
  real_array tmp300;
  real_array tmp301;
  real_array tmp302;
  real_array tmp303;
  modelica_real tmp304;
  modelica_real tmp305;
  modelica_real tmp306;
  modelica_real tmp307;
  array_alloc_scalar_real_array(&tmp288, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp289, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp290, 4, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp291, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp292, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp293, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp294, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp295, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp296, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp297, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp298, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp299, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp300, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp301, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp302, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp303, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp304 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp305 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  tmp306 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp307 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  jacobian->resultVars[4] /* der(quad_low.quaternion_wb.$pDERA.dummyVarA[2]) JACOBIAN_VAR */ = (0.5) * (real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp288, tmp289, tmp290, tmp291), jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */), 1) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp292, tmp293, tmp294, tmp295), jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */), 1) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp296, tmp297, tmp298, tmp299), jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), 1) + (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedA[2] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp300, tmp301, tmp302, tmp303), 1))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp304 * tmp304))) - ((tmp305 * tmp305)) - ((tmp306 * tmp306)) - ((tmp307 * tmp307))) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedA[2] SEED_VAR */) + ((-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedA[3] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedA[4] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedA[2] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedA[1] SEED_VAR */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)));
  threadData->lastEquationSolved = 218;
}

/*
equation index: 219
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb.$pDERA.dummyVarA[1] = 0.5 * (($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[1])[1] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[2])[1] + ($DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 0.0, 0.0}) * quad_low.rate_wb_b.SeedA[3])[1] + quad_low.quaternion_wb.SeedA[1] * $DER$GSQuad$PUtils$Pquatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb, {0.0, 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0})[1]) + quad_low.quat_fdbk_correction * ((1.0 + (-quad_low.quaternion_wb[2] ^ 2.0) - quad_low.quaternion_wb[1] ^ 2.0 - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[3] ^ 2.0) * quad_low.quaternion_wb.SeedA[1] + (-2.0) * (quad_low.quaternion_wb[3] * quad_low.quaternion_wb.SeedA[3] + quad_low.quaternion_wb[4] * quad_low.quaternion_wb.SeedA[4] + quad_low.quaternion_wb[2] * quad_low.quaternion_wb.SeedA[2] + quad_low.quaternion_wb[1] * quad_low.quaternion_wb.SeedA[1]) * quad_low.quaternion_wb[1])
*/
void GSQuad_Components_Quadrotor_eqFunction_219(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,219};
  real_array tmp308;
  real_array tmp309;
  real_array tmp310;
  real_array tmp311;
  real_array tmp312;
  real_array tmp313;
  real_array tmp314;
  real_array tmp315;
  real_array tmp316;
  real_array tmp317;
  real_array tmp318;
  real_array tmp319;
  real_array tmp320;
  real_array tmp321;
  real_array tmp322;
  real_array tmp323;
  modelica_real tmp324;
  modelica_real tmp325;
  modelica_real tmp326;
  modelica_real tmp327;
  array_alloc_scalar_real_array(&tmp308, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp309, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp310, 4, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp311, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp312, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp313, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp314, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp315, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp316, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp317, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp318, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp319, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp320, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp321, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp322, 4, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp323, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp324 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp325 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  tmp326 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp327 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  jacobian->resultVars[3] /* der(quad_low.quaternion_wb.$pDERA.dummyVarA[1]) JACOBIAN_VAR */ = (0.5) * (real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp308, tmp309, tmp310, tmp311), jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */), 0) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp312, tmp313, tmp314, tmp315), jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */), 0) + real_get(mul_alloc_real_array_scalar(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp316, tmp317, tmp318, tmp319), jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */), 0) + (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedA[1] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, tmp320, tmp321, tmp322, tmp323), 0))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp324 * tmp324))) - ((tmp325 * tmp325)) - ((tmp326 * tmp326)) - ((tmp327 * tmp327))) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedA[1] SEED_VAR */) + ((-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)) * (jacobian->seedVars[5] /* quad_low.quaternion_wb.SeedA[3] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)) * (jacobian->seedVars[6] /* quad_low.quaternion_wb.SeedA[4] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)) * (jacobian->seedVars[4] /* quad_low.quaternion_wb.SeedA[2] SEED_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)) * (jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedA[1] SEED_VAR */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)));
  threadData->lastEquationSolved = 219;
}

/*
equation index: 220
type: ARRAY_CALL_ASSIGN

quad_low.C_wb.$pDERA.dummyVarA = transpose(quad_low.quaternion_wb.SeedA .* $DER$GSQuad$PUtils$Pquat2rot(quad_low.quaternion_wb, {1.0, 1.0, 1.0, 1.0}))
*/
void GSQuad_Components_Quadrotor_eqFunction_220(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,220};
  real_array tmp328;
  real_array tmp329;
  real_array tmp330;
  real_array tmp331;
  real_array tmp332;
  real_array tmp333;
  real_array_create(&tmp328, ((modelica_real*)&(jacobian->seedVars[3] /* quad_low.quaternion_wb.SeedA[1] SEED_VAR */)), 1, (_index_t)4);
  real_array_create(&tmp329, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */))), 1, (_index_t)4);
  array_alloc_scalar_real_array(&tmp330, 4, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  tmp331 = mul_alloc_real_array(tmp328, omc__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot(threadData, tmp329, tmp330));
  transpose_alloc_real_array(&tmp331, &tmp332);
  real_array_create(&tmp333, ((modelica_real*)&((&jacobian->tmpVars[11] /* quad_low.C_wb.$pDERA.dummyVarA[1,1] JACOBIAN_TMP_VAR */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp332, tmp333);
  threadData->lastEquationSolved = 220;
}

/*
equation index: 221
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERA.dummyVarA[1] = 9.80665 * quad_low.C_wb.$pDERA.dummyVarA[1,3] + (-quad_low.rate_wb_b.SeedA[1]) * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0})[1] - quad_low.velocity_w_p_b.SeedA[1] * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0})[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_221(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,221};
  real_array tmp334;
  real_array tmp335;
  real_array tmp336;
  real_array tmp337;
  real_array tmp338;
  real_array tmp339;
  real_array tmp340;
  real_array tmp341;
  real_array_create(&tmp334, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp335, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp336, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp337, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  real_array_create(&tmp338, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp339, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp340, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp341, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  jacobian->resultVars[10] /* der(quad_low.velocity_w_p_b.$pDERA.dummyVarA[1]) JACOBIAN_VAR */ = (9.80665) * (jacobian->tmpVars[13] /* quad_low.C_wb.$pDERA.dummyVarA[1,3] JACOBIAN_TMP_VAR */) + ((-jacobian->seedVars[7] /* quad_low.rate_wb_b.SeedA[1] SEED_VAR */)) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp334, tmp335, tmp336, tmp337), 0)) - ((jacobian->seedVars[10] /* quad_low.velocity_w_p_b.SeedA[1] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp338, tmp339, tmp340, tmp341), 0)));
  threadData->lastEquationSolved = 221;
}

/*
equation index: 222
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERA.dummyVarA[2] = quad_low.C_wb[1,2] * quad_low.velocity_w_p_b.SeedA[1] + quad_low.C_wb.$pDERA.dummyVarA[1,2] * quad_low.velocity_w_p_b[1] + quad_low.C_wb[2,2] * quad_low.velocity_w_p_b.SeedA[2] + quad_low.C_wb.$pDERA.dummyVarA[2,2] * quad_low.velocity_w_p_b[2] + quad_low.C_wb[3,2] * quad_low.velocity_w_p_b.SeedA[3] + quad_low.C_wb.$pDERA.dummyVarA[3,2] * quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_222(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,222};
  jacobian->resultVars[1] /* der(quad_low.position_w_p_w.$pDERA.dummyVarA[2]) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* quad_low.C_wb[1,2] variable */)) * (jacobian->seedVars[10] /* quad_low.velocity_w_p_b.SeedA[1] SEED_VAR */) + (jacobian->tmpVars[12] /* quad_low.C_wb.$pDERA.dummyVarA[1,2] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* quad_low.C_wb[2,2] variable */)) * (jacobian->seedVars[11] /* quad_low.velocity_w_p_b.SeedA[2] SEED_VAR */) + (jacobian->tmpVars[15] /* quad_low.C_wb.$pDERA.dummyVarA[2,2] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* quad_low.C_wb[3,2] variable */)) * (jacobian->seedVars[12] /* quad_low.velocity_w_p_b.SeedA[3] SEED_VAR */) + (jacobian->tmpVars[18] /* quad_low.C_wb.$pDERA.dummyVarA[3,2] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */));
  threadData->lastEquationSolved = 222;
}

/*
equation index: 223
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERA.dummyVarA[2] = 9.80665 * quad_low.C_wb.$pDERA.dummyVarA[2,3] + (-quad_low.rate_wb_b.SeedA[2]) * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0})[2] - quad_low.velocity_w_p_b.SeedA[2] * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0})[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_223(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,223};
  real_array tmp342;
  real_array tmp343;
  real_array tmp344;
  real_array tmp345;
  real_array tmp346;
  real_array tmp347;
  real_array tmp348;
  real_array tmp349;
  real_array_create(&tmp342, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp343, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp344, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp345, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  real_array_create(&tmp346, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp347, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp348, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp349, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  jacobian->resultVars[11] /* der(quad_low.velocity_w_p_b.$pDERA.dummyVarA[2]) JACOBIAN_VAR */ = (9.80665) * (jacobian->tmpVars[16] /* quad_low.C_wb.$pDERA.dummyVarA[2,3] JACOBIAN_TMP_VAR */) + ((-jacobian->seedVars[8] /* quad_low.rate_wb_b.SeedA[2] SEED_VAR */)) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp342, tmp343, tmp344, tmp345), 1)) - ((jacobian->seedVars[11] /* quad_low.velocity_w_p_b.SeedA[2] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp346, tmp347, tmp348, tmp349), 1)));
  threadData->lastEquationSolved = 223;
}

/*
equation index: 224
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERA.dummyVarA[3] = quad_low.C_wb[1,3] * quad_low.velocity_w_p_b.SeedA[1] + quad_low.C_wb.$pDERA.dummyVarA[1,3] * quad_low.velocity_w_p_b[1] + quad_low.C_wb[2,3] * quad_low.velocity_w_p_b.SeedA[2] + quad_low.C_wb.$pDERA.dummyVarA[2,3] * quad_low.velocity_w_p_b[2] + quad_low.C_wb[3,3] * quad_low.velocity_w_p_b.SeedA[3] + quad_low.C_wb.$pDERA.dummyVarA[3,3] * quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_224(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,224};
  jacobian->resultVars[2] /* der(quad_low.position_w_p_w.$pDERA.dummyVarA[3]) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* quad_low.C_wb[1,3] variable */)) * (jacobian->seedVars[10] /* quad_low.velocity_w_p_b.SeedA[1] SEED_VAR */) + (jacobian->tmpVars[13] /* quad_low.C_wb.$pDERA.dummyVarA[1,3] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* quad_low.C_wb[2,3] variable */)) * (jacobian->seedVars[11] /* quad_low.velocity_w_p_b.SeedA[2] SEED_VAR */) + (jacobian->tmpVars[16] /* quad_low.C_wb.$pDERA.dummyVarA[2,3] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* quad_low.C_wb[3,3] variable */)) * (jacobian->seedVars[12] /* quad_low.velocity_w_p_b.SeedA[3] SEED_VAR */) + (jacobian->tmpVars[19] /* quad_low.C_wb.$pDERA.dummyVarA[3,3] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */));
  threadData->lastEquationSolved = 224;
}

/*
equation index: 225
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b.$pDERA.dummyVarA[3] = 9.80665 * quad_low.C_wb.$pDERA.dummyVarA[3,3] + (-quad_low.rate_wb_b.SeedA[3]) * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0})[3] - quad_low.velocity_w_p_b.SeedA[3] * $DER$GSQuad$PUtils$Pcross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0})[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_225(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,225};
  real_array tmp350;
  real_array tmp351;
  real_array tmp352;
  real_array tmp353;
  real_array tmp354;
  real_array tmp355;
  real_array tmp356;
  real_array tmp357;
  real_array_create(&tmp350, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp351, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp352, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  array_alloc_scalar_real_array(&tmp353, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  real_array_create(&tmp354, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */))), 1, (_index_t)3);
  real_array_create(&tmp355, ((modelica_real*)&((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */))), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp356, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp357, 3, (modelica_real)1.0, (modelica_real)1.0, (modelica_real)1.0);
  jacobian->resultVars[12] /* der(quad_low.velocity_w_p_b.$pDERA.dummyVarA[3]) JACOBIAN_VAR */ = (9.80665) * (jacobian->tmpVars[19] /* quad_low.C_wb.$pDERA.dummyVarA[3,3] JACOBIAN_TMP_VAR */) + ((-jacobian->seedVars[9] /* quad_low.rate_wb_b.SeedA[3] SEED_VAR */)) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp350, tmp351, tmp352, tmp353), 2)) - ((jacobian->seedVars[12] /* quad_low.velocity_w_p_b.SeedA[3] SEED_VAR */) * (real_get(omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, tmp354, tmp355, tmp356, tmp357), 2)));
  threadData->lastEquationSolved = 225;
}

/*
equation index: 226
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w.$pDERA.dummyVarA[1] = quad_low.C_wb[1,1] * quad_low.velocity_w_p_b.SeedA[1] + quad_low.C_wb.$pDERA.dummyVarA[1,1] * quad_low.velocity_w_p_b[1] + quad_low.C_wb[2,1] * quad_low.velocity_w_p_b.SeedA[2] + quad_low.C_wb.$pDERA.dummyVarA[2,1] * quad_low.velocity_w_p_b[2] + quad_low.C_wb[3,1] * quad_low.velocity_w_p_b.SeedA[3] + quad_low.C_wb.$pDERA.dummyVarA[3,1] * quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_226(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,226};
  jacobian->resultVars[0] /* der(quad_low.position_w_p_w.$pDERA.dummyVarA[1]) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* quad_low.C_wb[1,1] variable */)) * (jacobian->seedVars[10] /* quad_low.velocity_w_p_b.SeedA[1] SEED_VAR */) + (jacobian->tmpVars[11] /* quad_low.C_wb.$pDERA.dummyVarA[1,1] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* quad_low.C_wb[2,1] variable */)) * (jacobian->seedVars[11] /* quad_low.velocity_w_p_b.SeedA[2] SEED_VAR */) + (jacobian->tmpVars[14] /* quad_low.C_wb.$pDERA.dummyVarA[2,1] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* quad_low.C_wb[3,1] variable */)) * (jacobian->seedVars[12] /* quad_low.velocity_w_p_b.SeedA[3] SEED_VAR */) + (jacobian->tmpVars[17] /* quad_low.C_wb.$pDERA.dummyVarA[3,1] JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */));
  threadData->lastEquationSolved = 226;
}

OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_functionJacA_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Quadrotor_INDEX_JAC_A;
  
  
  return 0;
}

int GSQuad_Components_Quadrotor_functionJacA_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Quadrotor_INDEX_JAC_A;
  
  static void (*const eqFunctions[14])(DATA*, threadData_t*, JACOBIAN*, JACOBIAN*) = {
    GSQuad_Components_Quadrotor_eqFunction_213,
    GSQuad_Components_Quadrotor_eqFunction_214,
    GSQuad_Components_Quadrotor_eqFunction_215,
    GSQuad_Components_Quadrotor_eqFunction_216,
    GSQuad_Components_Quadrotor_eqFunction_217,
    GSQuad_Components_Quadrotor_eqFunction_218,
    GSQuad_Components_Quadrotor_eqFunction_219,
    GSQuad_Components_Quadrotor_eqFunction_220,
    GSQuad_Components_Quadrotor_eqFunction_221,
    GSQuad_Components_Quadrotor_eqFunction_222,
    GSQuad_Components_Quadrotor_eqFunction_223,
    GSQuad_Components_Quadrotor_eqFunction_224,
    GSQuad_Components_Quadrotor_eqFunction_225,
    GSQuad_Components_Quadrotor_eqFunction_226
  };
  
  for (int id = 0; id < 14; id++) {
    eqFunctions[id](data, threadData, jacobian, parentJacobian);
  }
  
  return 0;
}

int GSQuad_Components_Quadrotor_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int GSQuad_Components_Quadrotor_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "GSQuad.Components.Quadrotor_JacD.bin");
  
  initJacobian(jacobian, 4, 19, 78, GSQuad_Components_Quadrotor_functionJacD_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(4, 0, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 4+1, pFile, FALSE);
  if (count != 4+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 4+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 0, pFile, FALSE);
  if (count != 0) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 0, count);
  }
  
  /* write color array */
  /* color 1 with 4 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 4, 4);
  
  omc_fclose(pFile);
  
  return 0;
}
OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "GSQuad.Components.Quadrotor_JacC.bin");
  
  initJacobian(jacobian, 13, 19, 78, GSQuad_Components_Quadrotor_functionJacC_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(13, 0, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 13+1, pFile, FALSE);
  if (count != 13+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 13+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 0, pFile, FALSE);
  if (count != 0) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 0, count);
  }
  
  /* write color array */
  /* color 1 with 13 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 13, 13);
  
  omc_fclose(pFile);
  
  return 0;
}
OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "GSQuad.Components.Quadrotor_JacB.bin");
  
  initJacobian(jacobian, 4, 13, 78, GSQuad_Components_Quadrotor_functionJacB_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(4, 0, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 4+1, pFile, FALSE);
  if (count != 4+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 4+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 0, pFile, FALSE);
  if (count != 0) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 0, count);
  }
  
  /* write color array */
  /* color 1 with 4 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 4, 4);
  
  omc_fclose(pFile);
  
  return 0;
}
OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "GSQuad.Components.Quadrotor_JacA.bin");
  
  initJacobian(jacobian, 13, 13, 78, GSQuad_Components_Quadrotor_functionJacA_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(13, 88, 10);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 13+1, pFile, FALSE);
  if (count != 13+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 13+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 88, pFile, FALSE);
  if (count != 88) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 88, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 13);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1, 13);
  /* color 3 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 1, 13);
  /* color 4 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 4, 1, 13);
  /* color 5 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 5, 1, 13);
  /* color 6 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 6, 1, 13);
  /* color 7 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 7, 1, 13);
  /* color 8 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 8, 1, 13);
  /* color 9 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 9, 1, 13);
  /* color 10 with 4 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 10, 4, 13);
  
  omc_fclose(pFile);
  
  return 0;
}


