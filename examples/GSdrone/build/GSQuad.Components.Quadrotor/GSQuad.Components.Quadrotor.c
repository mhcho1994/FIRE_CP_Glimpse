/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "GSQuad.Components.Quadrotor_model.h"
#include "simulation/solver/events.h"
#include "util/real_array.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation GSQuad_Components_Quadrotor_performSimulation
#define prefixedName_updateContinuousSystem GSQuad_Components_Quadrotor_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation GSQuad_Components_Quadrotor_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int GSQuad_Components_Quadrotor_input_function(DATA *data, threadData_t *threadData)
{
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* pwm_rotor_cmd[1] variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* pwm_rotor_cmd[2] variable */) = data->simulationInfo->inputVars[1];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* pwm_rotor_cmd[3] variable */) = data->simulationInfo->inputVars[2];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* pwm_rotor_cmd[4] variable */) = data->simulationInfo->inputVars[3];
  
  return 0;
}

int GSQuad_Components_Quadrotor_input_function_init(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData, data->modelData->realVarsData[42].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[0] = real_get(data->modelData->realVarsData[42].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[43].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[1] = real_get(data->modelData->realVarsData[43].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[44].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[2] = real_get(data->modelData->realVarsData[44].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[45].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[3] = real_get(data->modelData->realVarsData[45].attribute.start, 0);
  
  return 0;
}

int GSQuad_Components_Quadrotor_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData, data->modelData->realVarsData[42].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[0], 0, &data->modelData->realVarsData[42].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[43].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[1], 0, &data->modelData->realVarsData[43].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[44].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[2], 0, &data->modelData->realVarsData[44].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[45].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[3], 0, &data->modelData->realVarsData[45].attribute.start);
  
  return 0;
}

int GSQuad_Components_Quadrotor_inputNames(DATA *data, char ** names){
  names[0] = (char *) data->modelData->realVarsData[42].info.name;
  names[1] = (char *) data->modelData->realVarsData[43].info.name;
  names[2] = (char *) data->modelData->realVarsData[44].info.name;
  names[3] = (char *) data->modelData->realVarsData[45].info.name;
  
  return 0;
}

int GSQuad_Components_Quadrotor_data_function(DATA *data, threadData_t *threadData)
{
  return 0;
}

int GSQuad_Components_Quadrotor_dataReconciliationInputNames(DATA *data, char ** names){
  
  return 0;
}

int GSQuad_Components_Quadrotor_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  
  return 0;
}

int GSQuad_Components_Quadrotor_output_function(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* acc_w_p_b_meas[1] variable */);
  data->simulationInfo->outputVars[1] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* acc_w_p_b_meas[2] variable */);
  data->simulationInfo->outputVars[2] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* acc_w_p_b_meas[3] variable */);
  data->simulationInfo->outputVars[3] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* euler_wb_meas[1] variable */);
  data->simulationInfo->outputVars[4] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* euler_wb_meas[2] variable */);
  data->simulationInfo->outputVars[5] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* euler_wb_meas[3] variable */);
  data->simulationInfo->outputVars[6] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* pos_w_p_w_meas[1] variable */);
  data->simulationInfo->outputVars[7] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* pos_w_p_w_meas[2] variable */);
  data->simulationInfo->outputVars[8] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* pos_w_p_w_meas[3] variable */);
  data->simulationInfo->outputVars[9] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* quat_wb_meas[1] variable */);
  data->simulationInfo->outputVars[10] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* quat_wb_meas[2] variable */);
  data->simulationInfo->outputVars[11] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* quat_wb_meas[3] variable */);
  data->simulationInfo->outputVars[12] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* quat_wb_meas[4] variable */);
  data->simulationInfo->outputVars[13] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* rate_wb_b_meas[1] variable */);
  data->simulationInfo->outputVars[14] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* rate_wb_b_meas[2] variable */);
  data->simulationInfo->outputVars[15] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* rate_wb_b_meas[3] variable */);
  data->simulationInfo->outputVars[16] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* vel_w_p_b_meas[1] variable */);
  data->simulationInfo->outputVars[17] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* vel_w_p_b_meas[2] variable */);
  data->simulationInfo->outputVars[18] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* vel_w_p_b_meas[3] variable */);
  
  return 0;
}

int GSQuad_Components_Quadrotor_setc_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

int GSQuad_Components_Quadrotor_setb_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}


/*
equation index: 112
type: SIMPLE_ASSIGN
$cse1 = cos((gyroatk.w_ac - gyroatk.w_d) * gyroatk.sample_interval * (*Real*)(pre(gyroatk.timer_count)) - gyroatk.Phi_ac)
*/
void GSQuad_Components_Quadrotor_eqFunction_112(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,112};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* $cse1 variable */) = cos(((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[41]] /* gyroatk.w_ac PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[36]] /* gyroatk.sample_interval PARAM */)) * (((modelica_real)(data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */)))) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* gyroatk.Phi_ac PARAM */));
  threadData->lastEquationSolved = 112;
}

/*
equation index: 113
type: SIMPLE_ASSIGN
quad_low.omega_motor[4] = GSQuad.Utils.clip(pre(quad_low.omega_rotor_cmd[4]), quad_low.omega_rotor_min, quad_low.omega_rotor_max)
*/
void GSQuad_Components_Quadrotor_eqFunction_113(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,113};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* quad_low.omega_motor[4] variable */) = omc_GSQuad_Utils_clip(threadData, (data->simulationInfo->realVarsPre[87] /* quad_low.omega_rotor_cmd[4] DISCRETE */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[79]] /* quad_low.omega_rotor_max PARAM */));
  threadData->lastEquationSolved = 113;
}

/*
equation index: 114
type: SIMPLE_ASSIGN
quad_low.omega_motor[3] = GSQuad.Utils.clip(pre(quad_low.omega_rotor_cmd[3]), quad_low.omega_rotor_min, quad_low.omega_rotor_max)
*/
void GSQuad_Components_Quadrotor_eqFunction_114(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,114};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* quad_low.omega_motor[3] variable */) = omc_GSQuad_Utils_clip(threadData, (data->simulationInfo->realVarsPre[86] /* quad_low.omega_rotor_cmd[3] DISCRETE */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[79]] /* quad_low.omega_rotor_max PARAM */));
  threadData->lastEquationSolved = 114;
}

/*
equation index: 115
type: SIMPLE_ASSIGN
quad_low.omega_motor[2] = GSQuad.Utils.clip(pre(quad_low.omega_rotor_cmd[2]), quad_low.omega_rotor_min, quad_low.omega_rotor_max)
*/
void GSQuad_Components_Quadrotor_eqFunction_115(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,115};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* quad_low.omega_motor[2] variable */) = omc_GSQuad_Utils_clip(threadData, (data->simulationInfo->realVarsPre[85] /* quad_low.omega_rotor_cmd[2] DISCRETE */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[79]] /* quad_low.omega_rotor_max PARAM */));
  threadData->lastEquationSolved = 115;
}

/*
equation index: 116
type: SIMPLE_ASSIGN
quad_low.omega_motor[1] = GSQuad.Utils.clip(pre(quad_low.omega_rotor_cmd[1]), quad_low.omega_rotor_min, quad_low.omega_rotor_max)
*/
void GSQuad_Components_Quadrotor_eqFunction_116(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,116};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* quad_low.omega_motor[1] variable */) = omc_GSQuad_Utils_clip(threadData, (data->simulationInfo->realVarsPre[84] /* quad_low.omega_rotor_cmd[1] DISCRETE */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[79]] /* quad_low.omega_rotor_max PARAM */));
  threadData->lastEquationSolved = 116;
}

/*
equation index: 117
type: ALGORITHM

  gyroatk.timer_count := pre(gyroatk.timer_count);
  $whenCondition3 := pre($whenCondition3);
  $whenCondition3 := sample(1, 0.0, gyroatk.sample_interval);
  when $whenCondition3 then
    gyroatk.timer_count := gyroatk.timer_count + 1;
  end when;
*/
void GSQuad_Components_Quadrotor_eqFunction_117(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,117};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* gyroatk.timer_count DISCRETE */) = (data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition3 DISCRETE */) = (data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition3 DISCRETE */) = data->simulationInfo->samples[0];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition3 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */) /* edge */))
    {
      (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* gyroatk.timer_count DISCRETE */) = (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* gyroatk.timer_count DISCRETE */) + ((modelica_integer) 1);
    }
  }
  threadData->lastEquationSolved = 117;
}

/*
equation index: 118
type: SIMPLE_ASSIGN
quad_low.F_b[3] = (-quad_low.k_eta) * (quad_low.omega_motor[1] ^ 2.0 + quad_low.omega_motor[2] ^ 2.0 + quad_low.omega_motor[3] ^ 2.0 + quad_low.omega_motor[4] ^ 2.0)
*/
void GSQuad_Components_Quadrotor_eqFunction_118(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,118};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  tmp0 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* quad_low.omega_motor[1] variable */);
  tmp1 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* quad_low.omega_motor[2] variable */);
  tmp2 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* quad_low.omega_motor[3] variable */);
  tmp3 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* quad_low.omega_motor[4] variable */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* quad_low.F_b[3] variable */) = ((-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[76]] /* quad_low.k_eta PARAM */))) * ((tmp0 * tmp0) + (tmp1 * tmp1) + (tmp2 * tmp2) + (tmp3 * tmp3));
  threadData->lastEquationSolved = 118;
}

/*
equation index: 119
type: SIMPLE_ASSIGN
quad_low.M_b[1] = quad_low.rotor_pos[2,3] * (-quad_low.k_eta) * quad_low.omega_motor[3] ^ 2.0 + quad_low.rotor_pos[2,4] * (-quad_low.k_eta) * quad_low.omega_motor[4] ^ 2.0 - quad_low.k_eta * (quad_low.rotor_pos[2,1] * quad_low.omega_motor[1] ^ 2.0 + quad_low.rotor_pos[2,2] * quad_low.omega_motor[2] ^ 2.0)
*/
void GSQuad_Components_Quadrotor_eqFunction_119(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,119};
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  tmp4 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* quad_low.omega_motor[3] variable */);
  tmp5 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* quad_low.omega_motor[4] variable */);
  tmp6 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* quad_low.omega_motor[1] variable */);
  tmp7 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* quad_low.omega_motor[2] variable */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */) = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[88]] /* quad_low.rotor_pos[2,3] PARAM */)) * (((-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[76]] /* quad_low.k_eta PARAM */))) * ((tmp4 * tmp4))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[89]] /* quad_low.rotor_pos[2,4] PARAM */)) * (((-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[76]] /* quad_low.k_eta PARAM */))) * ((tmp5 * tmp5))) - (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[76]] /* quad_low.k_eta PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[86]] /* quad_low.rotor_pos[2,1] PARAM */)) * ((tmp6 * tmp6)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[87]] /* quad_low.rotor_pos[2,2] PARAM */)) * ((tmp7 * tmp7))));
  threadData->lastEquationSolved = 119;
}

/*
equation index: 120
type: SIMPLE_ASSIGN
quad_low.M_b[2] = quad_low.k_eta * (quad_low.rotor_pos[1,1] * quad_low.omega_motor[1] ^ 2.0 + quad_low.rotor_pos[1,2] * quad_low.omega_motor[2] ^ 2.0 - ((-quad_low.rotor_pos[1,3]) * quad_low.omega_motor[3] ^ 2.0 - quad_low.rotor_pos[1,4] * quad_low.omega_motor[4] ^ 2.0))
*/
void GSQuad_Components_Quadrotor_eqFunction_120(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,120};
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  tmp8 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* quad_low.omega_motor[1] variable */);
  tmp9 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* quad_low.omega_motor[2] variable */);
  tmp10 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* quad_low.omega_motor[3] variable */);
  tmp11 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* quad_low.omega_motor[4] variable */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* quad_low.M_b[2] variable */) = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[76]] /* quad_low.k_eta PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[82]] /* quad_low.rotor_pos[1,1] PARAM */)) * ((tmp8 * tmp8)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[83]] /* quad_low.rotor_pos[1,2] PARAM */)) * ((tmp9 * tmp9)) - (((-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[84]] /* quad_low.rotor_pos[1,3] PARAM */))) * ((tmp10 * tmp10)) - (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[85]] /* quad_low.rotor_pos[1,4] PARAM */)) * ((tmp11 * tmp11)))));
  threadData->lastEquationSolved = 120;
}

/*
equation index: 121
type: SIMPLE_ASSIGN
quad_low.M_b[3] = quad_low.k_m * ((*Real*)(quad_low.rotor_dir[1]) * quad_low.omega_motor[1] ^ 2.0 + (*Real*)(quad_low.rotor_dir[2]) * quad_low.omega_motor[2] ^ 2.0 + (*Real*)(quad_low.rotor_dir[3]) * quad_low.omega_motor[3] ^ 2.0 + (*Real*)(quad_low.rotor_dir[4]) * quad_low.omega_motor[4] ^ 2.0)
*/
void GSQuad_Components_Quadrotor_eqFunction_121(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,121};
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  tmp12 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* quad_low.omega_motor[1] variable */);
  tmp13 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* quad_low.omega_motor[2] variable */);
  tmp14 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* quad_low.omega_motor[3] variable */);
  tmp15 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* quad_low.omega_motor[4] variable */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* quad_low.M_b[3] variable */) = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[77]] /* quad_low.k_m PARAM */)) * ((((modelica_real)(data->simulationInfo->integerParameter[data->simulationInfo->integerParamsIndex[1]] /* quad_low.rotor_dir[1] PARAM */))) * ((tmp12 * tmp12)) + (((modelica_real)(data->simulationInfo->integerParameter[data->simulationInfo->integerParamsIndex[2]] /* quad_low.rotor_dir[2] PARAM */))) * ((tmp13 * tmp13)) + (((modelica_real)(data->simulationInfo->integerParameter[data->simulationInfo->integerParamsIndex[3]] /* quad_low.rotor_dir[3] PARAM */))) * ((tmp14 * tmp14)) + (((modelica_real)(data->simulationInfo->integerParameter[data->simulationInfo->integerParamsIndex[4]] /* quad_low.rotor_dir[4] PARAM */))) * ((tmp15 * tmp15)));
  threadData->lastEquationSolved = 121;
}

/*
equation index: 122
type: ARRAY_CALL_ASSIGN

quad_low.C_wb = transpose(GSQuad.Utils.quat2rot(quad_low.quaternion_wb))
*/
void GSQuad_Components_Quadrotor_eqFunction_122(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,122};
  real_array tmp16;
  real_array tmp17;
  real_array tmp18;
  real_array tmp19;
  real_array_create(&tmp16, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)4);
  tmp17 = omc_GSQuad_Utils_quat2rot(threadData, tmp16);
  transpose_alloc_real_array(&tmp17, &tmp18);
  real_array_create(&tmp19, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* quad_low.C_wb[1,1] variable */))[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp18, tmp19);
  threadData->lastEquationSolved = 122;
}

/*
equation index: 123
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w[1] = quad_low.C_wb[1,1] * quad_low.velocity_w_p_b[1] + quad_low.C_wb[2,1] * quad_low.velocity_w_p_b[2] + quad_low.C_wb[3,1] * quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_123(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,123};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* der(quad_low.position_w_p_w[1]) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* quad_low.C_wb[1,1] variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* quad_low.C_wb[2,1] variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* quad_low.C_wb[3,1] variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */));
  threadData->lastEquationSolved = 123;
}

/*
equation index: 124
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w[2] = quad_low.C_wb[1,2] * quad_low.velocity_w_p_b[1] + quad_low.C_wb[2,2] * quad_low.velocity_w_p_b[2] + quad_low.C_wb[3,2] * quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_124(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,124};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* der(quad_low.position_w_p_w[2]) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* quad_low.C_wb[1,2] variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* quad_low.C_wb[2,2] variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* quad_low.C_wb[3,2] variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */));
  threadData->lastEquationSolved = 124;
}

/*
equation index: 125
type: SIMPLE_ASSIGN
$DER.quad_low.position_w_p_w[3] = quad_low.C_wb[1,3] * quad_low.velocity_w_p_b[1] + quad_low.C_wb[2,3] * quad_low.velocity_w_p_b[2] + quad_low.C_wb[3,3] * quad_low.velocity_w_p_b[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_125(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,125};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* der(quad_low.position_w_p_w[3]) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* quad_low.C_wb[1,3] variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* quad_low.C_wb[2,3] variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* quad_low.velocity_w_p_b[2] STATE(1) */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* quad_low.C_wb[3,3] variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* quad_low.velocity_w_p_b[3] STATE(1) */));
  threadData->lastEquationSolved = 125;
}

/*
equation index: 126
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b[1] = 9.80665 * quad_low.C_wb[1,3] - GSQuad.Utils.cross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b)[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_126(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,126};
  real_array tmp20;
  real_array tmp21;
  real_array_create(&tmp20, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_create(&tmp21, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* der(quad_low.velocity_w_p_b[1]) STATE_DER */) = (9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* quad_low.C_wb[1,3] variable */)) - (real_get(omc_GSQuad_Utils_cross3(threadData, tmp20, tmp21), 0));
  threadData->lastEquationSolved = 126;
}

/*
equation index: 127
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b[2] = 9.80665 * quad_low.C_wb[2,3] - GSQuad.Utils.cross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b)[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_127(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,127};
  real_array tmp22;
  real_array tmp23;
  real_array_create(&tmp22, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_create(&tmp23, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* der(quad_low.velocity_w_p_b[2]) STATE_DER */) = (9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* quad_low.C_wb[2,3] variable */)) - (real_get(omc_GSQuad_Utils_cross3(threadData, tmp22, tmp23), 1));
  threadData->lastEquationSolved = 127;
}

/*
equation index: 128
type: SIMPLE_ASSIGN
$DER.quad_low.velocity_w_p_b[3] = quad_low.F_b[3] / quad_low.mass + 9.80665 * quad_low.C_wb[3,3] - GSQuad.Utils.cross3(quad_low.rate_wb_b, quad_low.velocity_w_p_b)[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_128(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,128};
  real_array tmp24;
  real_array tmp25;
  real_array_create(&tmp24, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_create(&tmp25, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* der(quad_low.velocity_w_p_b[3]) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* quad_low.F_b[3] variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[78]] /* quad_low.mass PARAM */),"quad_low.mass",equationIndexes) + (9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* quad_low.C_wb[3,3] variable */)) - (real_get(omc_GSQuad_Utils_cross3(threadData, tmp24, tmp25), 2));
  threadData->lastEquationSolved = 128;
}

/*
equation index: 129
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb[1] = (GSQuad.Utils.quatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb) * 0.5)[1] + quad_low.quat_fdbk_correction * (1.0 + (-quad_low.quaternion_wb[3] ^ 2.0) - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[2] ^ 2.0 - quad_low.quaternion_wb[1] ^ 2.0) * quad_low.quaternion_wb[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_129(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,129};
  real_array tmp26;
  real_array tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  array_alloc_scalar_real_array(&tmp26, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp27, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)4);
  tmp28 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  tmp29 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp30 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp31 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* der(quad_low.quaternion_wb[1]) STATE_DER */) = real_get(mul_alloc_real_array_scalar(omc_GSQuad_Utils_quatprod(threadData, tmp26, tmp27), 0.5), 0) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp28 * tmp28))) - ((tmp29 * tmp29)) - ((tmp30 * tmp30)) - ((tmp31 * tmp31))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)));
  threadData->lastEquationSolved = 129;
}

/*
equation index: 130
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb[2] = (GSQuad.Utils.quatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb) * 0.5)[2] + quad_low.quat_fdbk_correction * (1.0 + (-quad_low.quaternion_wb[3] ^ 2.0) - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[2] ^ 2.0 - quad_low.quaternion_wb[1] ^ 2.0) * quad_low.quaternion_wb[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_130(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,130};
  real_array tmp32;
  real_array tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_real tmp36;
  modelica_real tmp37;
  array_alloc_scalar_real_array(&tmp32, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp33, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)4);
  tmp34 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  tmp35 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp36 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp37 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* der(quad_low.quaternion_wb[2]) STATE_DER */) = real_get(mul_alloc_real_array_scalar(omc_GSQuad_Utils_quatprod(threadData, tmp32, tmp33), 0.5), 1) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp34 * tmp34))) - ((tmp35 * tmp35)) - ((tmp36 * tmp36)) - ((tmp37 * tmp37))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */)));
  threadData->lastEquationSolved = 130;
}

/*
equation index: 131
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb[3] = (GSQuad.Utils.quatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb) * 0.5)[3] + quad_low.quat_fdbk_correction * (1.0 + (-quad_low.quaternion_wb[3] ^ 2.0) - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[2] ^ 2.0 - quad_low.quaternion_wb[1] ^ 2.0) * quad_low.quaternion_wb[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_131(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,131};
  real_array tmp38;
  real_array tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  modelica_real tmp42;
  modelica_real tmp43;
  array_alloc_scalar_real_array(&tmp38, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp39, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)4);
  tmp40 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  tmp41 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp42 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp43 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* der(quad_low.quaternion_wb[3]) STATE_DER */) = real_get(mul_alloc_real_array_scalar(omc_GSQuad_Utils_quatprod(threadData, tmp38, tmp39), 0.5), 2) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp40 * tmp40))) - ((tmp41 * tmp41)) - ((tmp42 * tmp42)) - ((tmp43 * tmp43))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */)));
  threadData->lastEquationSolved = 131;
}

/*
equation index: 132
type: SIMPLE_ASSIGN
$DER.quad_low.quaternion_wb[4] = (GSQuad.Utils.quatprod({0.0, quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3]}, quad_low.quaternion_wb) * 0.5)[4] + quad_low.quat_fdbk_correction * (1.0 + (-quad_low.quaternion_wb[3] ^ 2.0) - quad_low.quaternion_wb[4] ^ 2.0 - quad_low.quaternion_wb[2] ^ 2.0 - quad_low.quaternion_wb[1] ^ 2.0) * quad_low.quaternion_wb[4]
*/
void GSQuad_Components_Quadrotor_eqFunction_132(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,132};
  real_array tmp44;
  real_array tmp45;
  modelica_real tmp46;
  modelica_real tmp47;
  modelica_real tmp48;
  modelica_real tmp49;
  array_alloc_scalar_real_array(&tmp44, 4, (modelica_real)0.0, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */));
  real_array_create(&tmp45, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)4);
  tmp46 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* quad_low.quaternion_wb[3] STATE(1) */);
  tmp47 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */);
  tmp48 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* quad_low.quaternion_wb[2] STATE(1) */);
  tmp49 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* der(quad_low.quaternion_wb[4]) STATE_DER */) = real_get(mul_alloc_real_array_scalar(omc_GSQuad_Utils_quatprod(threadData, tmp44, tmp45), 0.5), 3) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[81]] /* quad_low.quat_fdbk_correction PARAM */)) * ((1.0 + (-((tmp46 * tmp46))) - ((tmp47 * tmp47)) - ((tmp48 * tmp48)) - ((tmp49 * tmp49))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* quad_low.quaternion_wb[4] STATE(1) */)));
  threadData->lastEquationSolved = 132;
}

/*
equation index: 136
type: ARRAY_CALL_ASSIGN

$TMP_133 = quad_low.Jinv * (quad_low.M_b - GSQuad.Utils.hatmap(quad_low.rate_wb_b) * {quad_low.J[1,1] * quad_low.rate_wb_b[1] + quad_low.J[1,2] * quad_low.rate_wb_b[2] + quad_low.J[1,3] * quad_low.rate_wb_b[3], quad_low.J[2,1] * quad_low.rate_wb_b[1] + quad_low.J[2,2] * quad_low.rate_wb_b[2] + quad_low.J[2,3] * quad_low.rate_wb_b[3], quad_low.J[3,1] * quad_low.rate_wb_b[1] + quad_low.J[3,2] * quad_low.rate_wb_b[2] + quad_low.J[3,3] * quad_low.rate_wb_b[3]})
*/
void GSQuad_Components_Quadrotor_eqFunction_136(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,136};
  real_array tmp50;
  real_array tmp51;
  real_array tmp52;
  real_array tmp53;
  real_array tmp54;
  real_array_create(&tmp50, ((modelica_real*)&((&data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_create(&tmp51, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* quad_low.M_b[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_create(&tmp52, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  array_alloc_scalar_real_array(&tmp53, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */)));
  real_array_create(&tmp54, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* $TMP_133[1] variable */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_copy_data(mul_alloc_real_matrix_product_smart(tmp50, sub_alloc_real_array(tmp51, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp52), tmp53))), tmp54);
  threadData->lastEquationSolved = 136;
}

/*
equation index: 133
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b[1] = $TMP_133[1]
*/
void GSQuad_Components_Quadrotor_eqFunction_133(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,133};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* der(quad_low.rate_wb_b[1]) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* $TMP_133[1] variable */);
  threadData->lastEquationSolved = 133;
}

/*
equation index: 134
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b[2] = $TMP_133[2]
*/
void GSQuad_Components_Quadrotor_eqFunction_134(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,134};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* der(quad_low.rate_wb_b[2]) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* $TMP_133[2] variable */);
  threadData->lastEquationSolved = 134;
}

/*
equation index: 135
type: SIMPLE_ASSIGN
$DER.quad_low.rate_wb_b[3] = $TMP_133[3]
*/
void GSQuad_Components_Quadrotor_eqFunction_135(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,135};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* der(quad_low.rate_wb_b[3]) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* $TMP_133[3] variable */);
  threadData->lastEquationSolved = 135;
}

/*
equation index: 137
type: SIMPLE_ASSIGN
gyroatk.omega_false[3] = 0.5 * gyroatk.l_g * gyroatk.w_d * (gyroatk.X_ac * $cse1 + gyroatk.X_d * $cse2) / gyroatk.dis_d
*/
void GSQuad_Components_Quadrotor_eqFunction_137(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,137};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* gyroatk.omega_false[3] variable */) = (0.5) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[27]] /* gyroatk.l_g PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[15]] /* gyroatk.X_ac PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* $cse1 variable */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[18]] /* gyroatk.X_d PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[0]] /* $cse2 PARAM */)),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* gyroatk.dis_d PARAM */),"gyroatk.dis_d",equationIndexes))));
  threadData->lastEquationSolved = 137;
}

/*
equation index: 138
type: ALGORITHM

  rate_wb_b_buf[3] := pre(rate_wb_b_buf[3]);
  rate_wb_b_buf[2] := pre(rate_wb_b_buf[2]);
  rate_wb_b_buf[1] := pre(rate_wb_b_buf[1]);
  euler_wb_buf[3] := pre(euler_wb_buf[3]);
  euler_wb_buf[2] := pre(euler_wb_buf[2]);
  euler_wb_buf[1] := pre(euler_wb_buf[1]);
  quat_wb_buf[4] := pre(quat_wb_buf[4]);
  quat_wb_buf[3] := pre(quat_wb_buf[3]);
  quat_wb_buf[2] := pre(quat_wb_buf[2]);
  quat_wb_buf[1] := pre(quat_wb_buf[1]);
  acc_w_p_b_buf[3] := pre(acc_w_p_b_buf[3]);
  acc_w_p_b_buf[2] := pre(acc_w_p_b_buf[2]);
  acc_w_p_b_buf[1] := pre(acc_w_p_b_buf[1]);
  vel_w_p_b_buf[3] := pre(vel_w_p_b_buf[3]);
  vel_w_p_b_buf[2] := pre(vel_w_p_b_buf[2]);
  vel_w_p_b_buf[1] := pre(vel_w_p_b_buf[1]);
  pos_w_p_w_buf[3] := pre(pos_w_p_w_buf[3]);
  pos_w_p_w_buf[2] := pre(pos_w_p_w_buf[2]);
  pos_w_p_w_buf[1] := pre(pos_w_p_w_buf[1]);
  $whenCondition2 := pre($whenCondition2);
  quad_low.omega_rotor_cmd[4] := pre(quad_low.omega_rotor_cmd[4]);
  quad_low.omega_rotor_cmd[3] := pre(quad_low.omega_rotor_cmd[3]);
  quad_low.omega_rotor_cmd[2] := pre(quad_low.omega_rotor_cmd[2]);
  quad_low.omega_rotor_cmd[1] := pre(quad_low.omega_rotor_cmd[1]);
  $whenCondition1 := pre($whenCondition1);
  $whenCondition1 := sample(2, 0.0, actuator_sample_period);
  when $whenCondition1 then
    for idx in 1:4 loop
      quad_low.omega_rotor_cmd[idx] := (quad_low.omega_rotor_max - quad_low.omega_rotor_min) * (GSQuad.Utils.clip(pwm_rotor_cmd[idx], pwm_min, pwm_max) - pwm_min) / (pwm_max - pwm_min) + quad_low.omega_rotor_min;
    end for;
  end when;
  $whenCondition2 := sample(3, 0.0, sensor_sample_period);
  when $whenCondition2 then
    pos_w_p_w_buf := quad_low.position_w_p_w;
    vel_w_p_b_buf := quad_low.velocity_w_p_b;
    acc_w_p_b_buf := {0.0, 0.0, 0.0};
    quat_wb_buf := quad_low.quaternion_wb;
    euler_wb_buf := GSQuad.Utils.quat2eul(quad_low.quaternion_wb);
    rate_wb_b_buf := {quad_low.rate_wb_b[1], quad_low.rate_wb_b[2], quad_low.rate_wb_b[3] + gyroatk.omega_false[3]};
  end when;
*/
void GSQuad_Components_Quadrotor_eqFunction_138(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,138};
  modelica_integer tmp55;
  modelica_integer tmp56;
  modelica_integer tmp57;
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
  real_array tmp69;
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* rate_wb_b_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[94] /* rate_wb_b_buf[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* rate_wb_b_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[93] /* rate_wb_b_buf[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* rate_wb_b_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[92] /* rate_wb_b_buf[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* euler_wb_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[80] /* euler_wb_buf[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* euler_wb_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[79] /* euler_wb_buf[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* euler_wb_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[78] /* euler_wb_buf[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* quat_wb_buf[4] DISCRETE */) = (data->simulationInfo->realVarsPre[91] /* quat_wb_buf[4] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* quat_wb_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[90] /* quat_wb_buf[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* quat_wb_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[89] /* quat_wb_buf[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* quat_wb_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[88] /* quat_wb_buf[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* acc_w_p_b_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[77] /* acc_w_p_b_buf[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* acc_w_p_b_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[76] /* acc_w_p_b_buf[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* acc_w_p_b_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[75] /* acc_w_p_b_buf[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* vel_w_p_b_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[97] /* vel_w_p_b_buf[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* vel_w_p_b_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[96] /* vel_w_p_b_buf[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* vel_w_p_b_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[95] /* vel_w_p_b_buf[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* pos_w_p_w_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[83] /* pos_w_p_w_buf[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* pos_w_p_w_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[82] /* pos_w_p_w_buf[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* pos_w_p_w_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[81] /* pos_w_p_w_buf[1] DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = (data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* quad_low.omega_rotor_cmd[4] DISCRETE */) = (data->simulationInfo->realVarsPre[87] /* quad_low.omega_rotor_cmd[4] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* quad_low.omega_rotor_cmd[3] DISCRETE */) = (data->simulationInfo->realVarsPre[86] /* quad_low.omega_rotor_cmd[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* quad_low.omega_rotor_cmd[2] DISCRETE */) = (data->simulationInfo->realVarsPre[85] /* quad_low.omega_rotor_cmd[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* quad_low.omega_rotor_cmd[1] DISCRETE */) = (data->simulationInfo->realVarsPre[84] /* quad_low.omega_rotor_cmd[1] DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = data->simulationInfo->samples[1];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
    {
      tmp55 = ((modelica_integer) 1); tmp56 = 1; tmp57 = ((modelica_integer) 4);
      if(!(((tmp56 > 0) && (tmp55 > tmp57)) || ((tmp56 < 0) && (tmp55 < tmp57))))
      {
        modelica_integer idx;
        for(idx = ((modelica_integer) 1); in_range_integer(idx, tmp55, tmp57); idx += tmp56)
        {
          (&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* quad_low.omega_rotor_cmd[1] DISCRETE */))[idx - 1] = DIVISION_SIM(((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[79]] /* quad_low.omega_rotor_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */)) * (omc_GSQuad_Utils_clip(threadData, (&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* pwm_rotor_cmd[1] variable */)[idx - 1], (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[49]] /* pwm_min PARAM */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[48]] /* pwm_max PARAM */)) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[49]] /* pwm_min PARAM */)),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[48]] /* pwm_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[49]] /* pwm_min PARAM */),"pwm_max - pwm_min",equationIndexes) + (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */);
        }
      }
    }
  }

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = data->simulationInfo->samples[2];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */) /* edge */))
    {
      real_array_create(&tmp58, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* quad_low.position_w_p_w[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_create(&tmp59, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* pos_w_p_w_buf[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp58, tmp59);

      real_array_create(&tmp60, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* quad_low.velocity_w_p_b[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_create(&tmp61, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* vel_w_p_b_buf[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp60, tmp61);

      array_alloc_scalar_real_array(&tmp62, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
      real_array_create(&tmp63, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* acc_w_p_b_buf[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp62, tmp63);

      real_array_create(&tmp64, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)4);
      real_array_create(&tmp65, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* quat_wb_buf[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)4);
      real_array_copy_data(tmp64, tmp65);

      real_array_create(&tmp66, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* quad_low.quaternion_wb[1] STATE(1) */)[((modelica_integer) 1) - 1])), 1, (_index_t)4);
      real_array_create(&tmp67, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* euler_wb_buf[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(omc_GSQuad_Utils_quat2eul(threadData, tmp66), tmp67);

      array_alloc_scalar_real_array(&tmp68, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* quad_low.rate_wb_b[1] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* quad_low.rate_wb_b[2] STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* quad_low.rate_wb_b[3] STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* gyroatk.omega_false[3] variable */));
      real_array_create(&tmp69, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* rate_wb_b_buf[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp68, tmp69);
    }
  }
  threadData->lastEquationSolved = 138;
}

/*
equation index: 139
type: SIMPLE_ASSIGN
pos_w_p_w_meas[1] = pre(pos_w_p_w_buf[1])
*/
void GSQuad_Components_Quadrotor_eqFunction_139(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,139};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* pos_w_p_w_meas[1] variable */) = (data->simulationInfo->realVarsPre[81] /* pos_w_p_w_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 139;
}

/*
equation index: 140
type: SIMPLE_ASSIGN
pos_w_p_w_meas[2] = pre(pos_w_p_w_buf[2])
*/
void GSQuad_Components_Quadrotor_eqFunction_140(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,140};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* pos_w_p_w_meas[2] variable */) = (data->simulationInfo->realVarsPre[82] /* pos_w_p_w_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 140;
}

/*
equation index: 141
type: SIMPLE_ASSIGN
pos_w_p_w_meas[3] = pre(pos_w_p_w_buf[3])
*/
void GSQuad_Components_Quadrotor_eqFunction_141(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,141};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* pos_w_p_w_meas[3] variable */) = (data->simulationInfo->realVarsPre[83] /* pos_w_p_w_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 141;
}

/*
equation index: 142
type: SIMPLE_ASSIGN
vel_w_p_b_meas[1] = pre(vel_w_p_b_buf[1])
*/
void GSQuad_Components_Quadrotor_eqFunction_142(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,142};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* vel_w_p_b_meas[1] variable */) = (data->simulationInfo->realVarsPre[95] /* vel_w_p_b_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 142;
}

/*
equation index: 143
type: SIMPLE_ASSIGN
vel_w_p_b_meas[2] = pre(vel_w_p_b_buf[2])
*/
void GSQuad_Components_Quadrotor_eqFunction_143(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,143};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* vel_w_p_b_meas[2] variable */) = (data->simulationInfo->realVarsPre[96] /* vel_w_p_b_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 143;
}

/*
equation index: 144
type: SIMPLE_ASSIGN
vel_w_p_b_meas[3] = pre(vel_w_p_b_buf[3])
*/
void GSQuad_Components_Quadrotor_eqFunction_144(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,144};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* vel_w_p_b_meas[3] variable */) = (data->simulationInfo->realVarsPre[97] /* vel_w_p_b_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 144;
}

/*
equation index: 145
type: SIMPLE_ASSIGN
acc_w_p_b_meas[1] = pre(acc_w_p_b_buf[1])
*/
void GSQuad_Components_Quadrotor_eqFunction_145(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,145};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* acc_w_p_b_meas[1] variable */) = (data->simulationInfo->realVarsPre[75] /* acc_w_p_b_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 145;
}

/*
equation index: 146
type: SIMPLE_ASSIGN
acc_w_p_b_meas[2] = pre(acc_w_p_b_buf[2])
*/
void GSQuad_Components_Quadrotor_eqFunction_146(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,146};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* acc_w_p_b_meas[2] variable */) = (data->simulationInfo->realVarsPre[76] /* acc_w_p_b_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 146;
}

/*
equation index: 147
type: SIMPLE_ASSIGN
acc_w_p_b_meas[3] = pre(acc_w_p_b_buf[3])
*/
void GSQuad_Components_Quadrotor_eqFunction_147(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,147};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* acc_w_p_b_meas[3] variable */) = (data->simulationInfo->realVarsPre[77] /* acc_w_p_b_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 147;
}

/*
equation index: 148
type: SIMPLE_ASSIGN
quat_wb_meas[1] = pre(quat_wb_buf[1])
*/
void GSQuad_Components_Quadrotor_eqFunction_148(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,148};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* quat_wb_meas[1] variable */) = (data->simulationInfo->realVarsPre[88] /* quat_wb_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 148;
}

/*
equation index: 149
type: SIMPLE_ASSIGN
quat_wb_meas[2] = pre(quat_wb_buf[2])
*/
void GSQuad_Components_Quadrotor_eqFunction_149(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,149};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* quat_wb_meas[2] variable */) = (data->simulationInfo->realVarsPre[89] /* quat_wb_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 149;
}

/*
equation index: 150
type: SIMPLE_ASSIGN
quat_wb_meas[3] = pre(quat_wb_buf[3])
*/
void GSQuad_Components_Quadrotor_eqFunction_150(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,150};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* quat_wb_meas[3] variable */) = (data->simulationInfo->realVarsPre[90] /* quat_wb_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 150;
}

/*
equation index: 151
type: SIMPLE_ASSIGN
quat_wb_meas[4] = pre(quat_wb_buf[4])
*/
void GSQuad_Components_Quadrotor_eqFunction_151(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,151};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* quat_wb_meas[4] variable */) = (data->simulationInfo->realVarsPre[91] /* quat_wb_buf[4] DISCRETE */);
  threadData->lastEquationSolved = 151;
}

/*
equation index: 152
type: SIMPLE_ASSIGN
euler_wb_meas[1] = pre(euler_wb_buf[1])
*/
void GSQuad_Components_Quadrotor_eqFunction_152(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,152};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* euler_wb_meas[1] variable */) = (data->simulationInfo->realVarsPre[78] /* euler_wb_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 152;
}

/*
equation index: 153
type: SIMPLE_ASSIGN
euler_wb_meas[2] = pre(euler_wb_buf[2])
*/
void GSQuad_Components_Quadrotor_eqFunction_153(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,153};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* euler_wb_meas[2] variable */) = (data->simulationInfo->realVarsPre[79] /* euler_wb_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 153;
}

/*
equation index: 154
type: SIMPLE_ASSIGN
euler_wb_meas[3] = -3.14159265 + mod(pre(euler_wb_buf[3]) + 3.14159265, 6.2831853, 0)
*/
void GSQuad_Components_Quadrotor_eqFunction_154(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,154};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* euler_wb_meas[3] variable */) = -3.14159265 + _event_mod_real((data->simulationInfo->realVarsPre[80] /* euler_wb_buf[3] DISCRETE */) + 3.14159265, 6.2831853, ((modelica_integer) 0), data, threadData);
  threadData->lastEquationSolved = 154;
}

/*
equation index: 155
type: SIMPLE_ASSIGN
rate_wb_b_meas[1] = pre(rate_wb_b_buf[1])
*/
void GSQuad_Components_Quadrotor_eqFunction_155(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,155};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* rate_wb_b_meas[1] variable */) = (data->simulationInfo->realVarsPre[92] /* rate_wb_b_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 155;
}

/*
equation index: 156
type: SIMPLE_ASSIGN
rate_wb_b_meas[2] = pre(rate_wb_b_buf[2])
*/
void GSQuad_Components_Quadrotor_eqFunction_156(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,156};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* rate_wb_b_meas[2] variable */) = (data->simulationInfo->realVarsPre[93] /* rate_wb_b_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 156;
}

/*
equation index: 157
type: SIMPLE_ASSIGN
rate_wb_b_meas[3] = pre(rate_wb_b_buf[3])
*/
void GSQuad_Components_Quadrotor_eqFunction_157(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,157};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* rate_wb_b_meas[3] variable */) = (data->simulationInfo->realVarsPre[94] /* rate_wb_b_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 157;
}

OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_functionDAE(DATA *data, threadData_t *threadData)
{
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  GSQuad_Components_Quadrotor_functionLocalKnownVars(data, threadData);
  static void (*const eqFunctions[46])(DATA*, threadData_t*) = {
    GSQuad_Components_Quadrotor_eqFunction_112,
    GSQuad_Components_Quadrotor_eqFunction_113,
    GSQuad_Components_Quadrotor_eqFunction_114,
    GSQuad_Components_Quadrotor_eqFunction_115,
    GSQuad_Components_Quadrotor_eqFunction_116,
    GSQuad_Components_Quadrotor_eqFunction_117,
    GSQuad_Components_Quadrotor_eqFunction_118,
    GSQuad_Components_Quadrotor_eqFunction_119,
    GSQuad_Components_Quadrotor_eqFunction_120,
    GSQuad_Components_Quadrotor_eqFunction_121,
    GSQuad_Components_Quadrotor_eqFunction_122,
    GSQuad_Components_Quadrotor_eqFunction_123,
    GSQuad_Components_Quadrotor_eqFunction_124,
    GSQuad_Components_Quadrotor_eqFunction_125,
    GSQuad_Components_Quadrotor_eqFunction_126,
    GSQuad_Components_Quadrotor_eqFunction_127,
    GSQuad_Components_Quadrotor_eqFunction_128,
    GSQuad_Components_Quadrotor_eqFunction_129,
    GSQuad_Components_Quadrotor_eqFunction_130,
    GSQuad_Components_Quadrotor_eqFunction_131,
    GSQuad_Components_Quadrotor_eqFunction_132,
    GSQuad_Components_Quadrotor_eqFunction_136,
    GSQuad_Components_Quadrotor_eqFunction_133,
    GSQuad_Components_Quadrotor_eqFunction_134,
    GSQuad_Components_Quadrotor_eqFunction_135,
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
  
  for (int id = 0; id < 46; id++) {
    eqFunctions[id](data, threadData);
  }
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  return 0;
}


int GSQuad_Components_Quadrotor_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

/* forwarded equations */
extern void GSQuad_Components_Quadrotor_eqFunction_113(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_114(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_115(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_116(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_118(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_119(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_120(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_121(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_122(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_123(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_124(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_125(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_126(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_127(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_128(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_129(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_130(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_131(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_132(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_136(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_133(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_134(DATA* data, threadData_t *threadData);
extern void GSQuad_Components_Quadrotor_eqFunction_135(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[23])(DATA*, threadData_t*) = {
    GSQuad_Components_Quadrotor_eqFunction_113,
    GSQuad_Components_Quadrotor_eqFunction_114,
    GSQuad_Components_Quadrotor_eqFunction_115,
    GSQuad_Components_Quadrotor_eqFunction_116,
    GSQuad_Components_Quadrotor_eqFunction_118,
    GSQuad_Components_Quadrotor_eqFunction_119,
    GSQuad_Components_Quadrotor_eqFunction_120,
    GSQuad_Components_Quadrotor_eqFunction_121,
    GSQuad_Components_Quadrotor_eqFunction_122,
    GSQuad_Components_Quadrotor_eqFunction_123,
    GSQuad_Components_Quadrotor_eqFunction_124,
    GSQuad_Components_Quadrotor_eqFunction_125,
    GSQuad_Components_Quadrotor_eqFunction_126,
    GSQuad_Components_Quadrotor_eqFunction_127,
    GSQuad_Components_Quadrotor_eqFunction_128,
    GSQuad_Components_Quadrotor_eqFunction_129,
    GSQuad_Components_Quadrotor_eqFunction_130,
    GSQuad_Components_Quadrotor_eqFunction_131,
    GSQuad_Components_Quadrotor_eqFunction_132,
    GSQuad_Components_Quadrotor_eqFunction_136,
    GSQuad_Components_Quadrotor_eqFunction_133,
    GSQuad_Components_Quadrotor_eqFunction_134,
    GSQuad_Components_Quadrotor_eqFunction_135
  };
  
  for (int id = 0; id < 23; id++) {
    eqFunctions[id](data, threadData);
  }
}

int GSQuad_Components_Quadrotor_functionODE(DATA *data, threadData_t *threadData)
{
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  GSQuad_Components_Quadrotor_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);
extern int _main_OptimizationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);

#include "GSQuad.Components.Quadrotor_12jac.h"
#include "GSQuad.Components.Quadrotor_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks GSQuad_Components_Quadrotor_callback = {
  (int (*)(DATA *, threadData_t *, void *)) GSQuad_Components_Quadrotor_performSimulation,    /* performSimulation */
  (int (*)(DATA *, threadData_t *, void *)) GSQuad_Components_Quadrotor_performQSSSimulation,    /* performQSSSimulation */
  GSQuad_Components_Quadrotor_updateContinuousSystem,    /* updateContinuousSystem */
  GSQuad_Components_Quadrotor_callExternalObjectDestructors,    /* callExternalObjectDestructors */
  GSQuad_Components_Quadrotor_initialNonLinearSystem,    /* initialNonLinearSystem */
  NULL,    /* initialLinearSystem */
  NULL,    /* initialMixedSystem */
  #if !defined(OMC_NO_STATESELECTION)
  GSQuad_Components_Quadrotor_initializeStateSets,
  #else
  NULL,
  #endif    /* initializeStateSets */
  GSQuad_Components_Quadrotor_initializeDAEmodeData,
  GSQuad_Components_Quadrotor_functionODE,
  GSQuad_Components_Quadrotor_functionAlgebraics,
  GSQuad_Components_Quadrotor_functionDAE,
  GSQuad_Components_Quadrotor_functionLocalKnownVars,
  GSQuad_Components_Quadrotor_input_function,
  GSQuad_Components_Quadrotor_input_function_init,
  GSQuad_Components_Quadrotor_input_function_updateStartValues,
  GSQuad_Components_Quadrotor_data_function,
  GSQuad_Components_Quadrotor_output_function,
  GSQuad_Components_Quadrotor_setc_function,
  GSQuad_Components_Quadrotor_setb_function,
  GSQuad_Components_Quadrotor_function_storeDelayed,
  GSQuad_Components_Quadrotor_function_storeSpatialDistribution,
  GSQuad_Components_Quadrotor_function_initSpatialDistribution,
  GSQuad_Components_Quadrotor_updateBoundVariableAttributes,
  GSQuad_Components_Quadrotor_functionInitialEquations,
  GLOBAL_EQUIDISTANT_HOMOTOPY,
  NULL,
  GSQuad_Components_Quadrotor_functionRemovedInitialEquations,
  GSQuad_Components_Quadrotor_updateBoundParameters,
  GSQuad_Components_Quadrotor_checkForAsserts,
  GSQuad_Components_Quadrotor_function_ZeroCrossingsEquations,
  GSQuad_Components_Quadrotor_function_ZeroCrossings,
  GSQuad_Components_Quadrotor_function_updateRelations,
  GSQuad_Components_Quadrotor_zeroCrossingDescription,
  GSQuad_Components_Quadrotor_relationDescription,
  GSQuad_Components_Quadrotor_function_initSample,
  GSQuad_Components_Quadrotor_INDEX_JAC_A,
  GSQuad_Components_Quadrotor_INDEX_JAC_B,
  GSQuad_Components_Quadrotor_INDEX_JAC_C,
  GSQuad_Components_Quadrotor_INDEX_JAC_D,
  GSQuad_Components_Quadrotor_INDEX_JAC_F,
  GSQuad_Components_Quadrotor_INDEX_JAC_H,
  GSQuad_Components_Quadrotor_initialAnalyticJacobianA,
  GSQuad_Components_Quadrotor_initialAnalyticJacobianB,
  GSQuad_Components_Quadrotor_initialAnalyticJacobianC,
  GSQuad_Components_Quadrotor_initialAnalyticJacobianD,
  GSQuad_Components_Quadrotor_initialAnalyticJacobianF,
  GSQuad_Components_Quadrotor_initialAnalyticJacobianH,
  GSQuad_Components_Quadrotor_functionJacA_column,
  GSQuad_Components_Quadrotor_functionJacB_column,
  GSQuad_Components_Quadrotor_functionJacC_column,
  GSQuad_Components_Quadrotor_functionJacD_column,
  GSQuad_Components_Quadrotor_functionJacF_column,
  GSQuad_Components_Quadrotor_functionJacH_column,
  GSQuad_Components_Quadrotor_linear_model_frame,
  GSQuad_Components_Quadrotor_linear_model_datarecovery_frame,
  GSQuad_Components_Quadrotor_mayer,
  GSQuad_Components_Quadrotor_lagrange,
  GSQuad_Components_Quadrotor_getInputVarIndicesInOptimization,
  GSQuad_Components_Quadrotor_pickUpBoundsForInputsInOptimization,
  GSQuad_Components_Quadrotor_setInputData,
  GSQuad_Components_Quadrotor_getTimeGrid,
  GSQuad_Components_Quadrotor_symbolicInlineSystem,
  GSQuad_Components_Quadrotor_function_initSynchronous,
  GSQuad_Components_Quadrotor_function_updateSynchronous,
  GSQuad_Components_Quadrotor_function_equationsSynchronous,
  GSQuad_Components_Quadrotor_inputNames,
  GSQuad_Components_Quadrotor_dataReconciliationInputNames,
  GSQuad_Components_Quadrotor_dataReconciliationUnmeasuredVariables,
  NULL,
  NULL,
  NULL,
  NULL,
  -1,
  NULL,
  NULL,
  -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Complex"
#define _OMC_LIT_RESOURCE_0_dir_data "/home/mhcho/.openmodelica/libraries/Complex 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,58,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "GSQuad"
#define _OMC_LIT_RESOURCE_1_dir_data "/home/mhcho/ws/FIRE_CP_Glimpse/examples/GSdrone/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,6,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,53,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "/home/mhcho/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,59,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_3_dir_data "/home/mhcho/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,16,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,67,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void GSQuad_Components_Quadrotor_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &GSQuad_Components_Quadrotor_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "GSQuad.Components.Quadrotor";
  data->modelData->modelFilePrefix = "GSQuad.Components.Quadrotor";
  data->modelData->modelFileName = "MFQuadrotor.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/mhcho/ws/FIRE_CP_Glimpse/examples/GSdrone/model";
  data->modelData->modelGUID = "{5b5d6851-116f-4408-bb43-b151d6993286}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "GSQuad.Components.Quadrotor_init.c"
    ;
  static const char contents_info[] =
    #include "GSQuad.Components.Quadrotor_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "GSQuad.Components.Quadrotor_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "GSQuad.Components.Quadrotor_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "GSQuad.Components.Quadrotor_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStatesArray = 13;
  data->modelData->nDiscreteReal = 23;
  data->modelData->nVariablesRealArray = 98;
  data->modelData->nVariablesIntegerArray = 1;
  data->modelData->nVariablesBooleanArray = 3;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersRealArray = 96;
  data->modelData->nParametersIntegerArray = 5;
  data->modelData->nParametersBooleanArray = 0;
  data->modelData->nParametersStringArray = 0;
  data->modelData->nParametersReal = 96;
  data->modelData->nParametersInteger = 5;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nAliasRealArray = 23;
  data->modelData->nAliasIntegerArray = 0;
  data->modelData->nAliasBooleanArray = 0;
  data->modelData->nAliasStringArray = 0;
  data->modelData->nInputVars = 4;
  data->modelData->nOutputVars = 19;
  data->modelData->nZeroCrossings = 1;
  data->modelData->nSamples = 3;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 3;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 11;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 305;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 4;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 6;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  data->modelData->nDelayExpressions = 0;
  data->modelData->nBaseClocks = 0;
  data->modelData->nSpatialDistributions = 0;
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->nSetbVars = 0;
  data->modelData->nRelatedBoundaryConditions = 0;
  data->modelData->linearizationDumpLanguage = OMC_LINEARIZE_DUMP_LANGUAGE_PYTHON;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}


#if defined(__MINGW32__) || defined(_MSC_VER)

#if !defined(_UNICODE)
#define _UNICODE
#endif
#if !defined(UNICODE)
#define UNICODE
#endif

#include <windows.h>
char** omc_fixWindowsArgv(int argc, wchar_t **wargv)
{
  char** newargv;
  /* Support for non-ASCII characters
  * Read the unicode command line arguments and translate it to char*
  */
  newargv = (char**)malloc(argc*sizeof(char*));
  for (int i = 0; i < argc; i++) {
    newargv[i] = omc_wchar_to_multibyte_str(wargv[i]);
  }
  return newargv;
}

#define OMC_MAIN wmain
#define OMC_CHAR wchar_t
#define OMC_EXPORT __declspec(dllexport) extern

#else
#define omc_fixWindowsArgv(N, A) (A)
#define OMC_MAIN main
#define OMC_CHAR char
#define OMC_EXPORT extern
#endif

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
#if defined(OMC_DLL_MAIN_DEFINE)
OMC_EXPORT int omcDllMain(int argc, OMC_CHAR **argv)
#else
int OMC_MAIN(int argc, OMC_CHAR** argv)
#endif
{
  char** newargv = omc_fixWindowsArgv(argc, argv);
  /*
    Set the error functions to be used for simulation.
    The default value for them is 'functions' version. Change it here to 'simulation' versions
  */
  omc_assert = omc_assert_simulation;
  omc_assert_withEquationIndexes = omc_assert_simulation_withEquationIndexes;

  omc_assert_warning_withEquationIndexes = omc_assert_warning_simulation_withEquationIndexes;
  omc_assert_warning = omc_assert_warning_simulation;
  omc_terminate = omc_terminate_simulation;
  omc_throw = omc_throw_simulation;

  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    GSQuad_Components_Quadrotor_setupDataStruc(&data, threadData);
    res = _main_initRuntimeAndSimulation(argc, newargv, &data, threadData);
    if(res == 0) {
      if (omc_flag[FLAG_MOO_OPTIMIZATION]) {
        res = _main_OptimizationRuntime(argc, newargv, &data, threadData);
      } else {
        res = _main_SimulationRuntime(argc, newargv, &data, threadData);
      }
    }
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  return res;
}

#ifdef __cplusplus
}
#endif


