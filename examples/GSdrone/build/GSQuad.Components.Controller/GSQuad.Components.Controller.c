/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "GSQuad.Components.Controller_model.h"
#include "simulation/solver/events.h"
#include "util/real_array.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation GSQuad_Components_Controller_performSimulation
#define prefixedName_updateContinuousSystem GSQuad_Components_Controller_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation GSQuad_Components_Controller_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int GSQuad_Components_Controller_input_function(DATA *data, threadData_t *threadData)
{
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* acc_w_p_b_fdbk[1] variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* acc_w_p_b_fdbk[2] variable */) = data->simulationInfo->inputVars[1];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* acc_w_p_b_fdbk[3] variable */) = data->simulationInfo->inputVars[2];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* euler_wb_fdbk[1] variable */) = data->simulationInfo->inputVars[3];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* euler_wb_fdbk[2] variable */) = data->simulationInfo->inputVars[4];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* euler_wb_fdbk[3] variable */) = data->simulationInfo->inputVars[5];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* pos_w_p_w_fdbk[1] variable */) = data->simulationInfo->inputVars[6];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* pos_w_p_w_fdbk[2] variable */) = data->simulationInfo->inputVars[7];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* pos_w_p_w_fdbk[3] variable */) = data->simulationInfo->inputVars[8];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* position_setpoint[1] variable */) = data->simulationInfo->inputVars[9];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* position_setpoint[2] variable */) = data->simulationInfo->inputVars[10];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* position_setpoint[3] variable */) = data->simulationInfo->inputVars[11];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* quat_wb_fdbk[1] variable */) = data->simulationInfo->inputVars[12];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* quat_wb_fdbk[2] variable */) = data->simulationInfo->inputVars[13];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* quat_wb_fdbk[3] variable */) = data->simulationInfo->inputVars[14];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* quat_wb_fdbk[4] variable */) = data->simulationInfo->inputVars[15];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* rate_wb_b_fdbk[1] variable */) = data->simulationInfo->inputVars[16];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* rate_wb_b_fdbk[2] variable */) = data->simulationInfo->inputVars[17];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* rate_wb_b_fdbk[3] variable */) = data->simulationInfo->inputVars[18];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rc_input[1] variable */) = data->simulationInfo->inputVars[19];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rc_input[2] variable */) = data->simulationInfo->inputVars[20];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rc_input[3] variable */) = data->simulationInfo->inputVars[21];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* rc_input[4] variable */) = data->simulationInfo->inputVars[22];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* vel_w_p_b_fdbk[1] variable */) = data->simulationInfo->inputVars[23];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* vel_w_p_b_fdbk[2] variable */) = data->simulationInfo->inputVars[24];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* vel_w_p_b_fdbk[3] variable */) = data->simulationInfo->inputVars[25];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* yaw_setpoint variable */) = data->simulationInfo->inputVars[26];
  
  return 0;
}

int GSQuad_Components_Controller_input_function_init(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData, data->modelData->realVarsData[0].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[0] = real_get(data->modelData->realVarsData[0].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[1].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[1] = real_get(data->modelData->realVarsData[1].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[2].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[2] = real_get(data->modelData->realVarsData[2].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[3].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[3] = real_get(data->modelData->realVarsData[3].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[4].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[4] = real_get(data->modelData->realVarsData[4].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[5].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[5] = real_get(data->modelData->realVarsData[5].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[6].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[6] = real_get(data->modelData->realVarsData[6].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[7].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[7] = real_get(data->modelData->realVarsData[7].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[8].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[8] = real_get(data->modelData->realVarsData[8].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[9].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[9] = real_get(data->modelData->realVarsData[9].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[10].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[10] = real_get(data->modelData->realVarsData[10].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[11].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[11] = real_get(data->modelData->realVarsData[11].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[16].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[12] = real_get(data->modelData->realVarsData[16].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[17].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[13] = real_get(data->modelData->realVarsData[17].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[18].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[14] = real_get(data->modelData->realVarsData[18].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[19].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[15] = real_get(data->modelData->realVarsData[19].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[20].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[16] = real_get(data->modelData->realVarsData[20].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[21].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[17] = real_get(data->modelData->realVarsData[21].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[22].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[18] = real_get(data->modelData->realVarsData[22].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[23].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[19] = real_get(data->modelData->realVarsData[23].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[24].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[20] = real_get(data->modelData->realVarsData[24].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[25].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[21] = real_get(data->modelData->realVarsData[25].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[26].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[22] = real_get(data->modelData->realVarsData[26].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[27].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[23] = real_get(data->modelData->realVarsData[27].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[28].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[24] = real_get(data->modelData->realVarsData[28].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[29].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[25] = real_get(data->modelData->realVarsData[29].attribute.start, 0);
  assertStreamPrint(threadData, data->modelData->realVarsData[30].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  data->simulationInfo->inputVars[26] = real_get(data->modelData->realVarsData[30].attribute.start, 0);
  
  return 0;
}

int GSQuad_Components_Controller_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData, data->modelData->realVarsData[0].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[0], 0, &data->modelData->realVarsData[0].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[1].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[1], 0, &data->modelData->realVarsData[1].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[2].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[2], 0, &data->modelData->realVarsData[2].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[3].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[3], 0, &data->modelData->realVarsData[3].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[4].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[4], 0, &data->modelData->realVarsData[4].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[5].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[5], 0, &data->modelData->realVarsData[5].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[6].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[6], 0, &data->modelData->realVarsData[6].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[7].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[7], 0, &data->modelData->realVarsData[7].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[8].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[8], 0, &data->modelData->realVarsData[8].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[9].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[9], 0, &data->modelData->realVarsData[9].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[10].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[10], 0, &data->modelData->realVarsData[10].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[11].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[11], 0, &data->modelData->realVarsData[11].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[16].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[12], 0, &data->modelData->realVarsData[16].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[17].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[13], 0, &data->modelData->realVarsData[17].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[18].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[14], 0, &data->modelData->realVarsData[18].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[19].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[15], 0, &data->modelData->realVarsData[19].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[20].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[16], 0, &data->modelData->realVarsData[20].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[21].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[17], 0, &data->modelData->realVarsData[21].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[22].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[18], 0, &data->modelData->realVarsData[22].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[23].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[19], 0, &data->modelData->realVarsData[23].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[24].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[20], 0, &data->modelData->realVarsData[24].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[25].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[21], 0, &data->modelData->realVarsData[25].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[26].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[22], 0, &data->modelData->realVarsData[26].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[27].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[23], 0, &data->modelData->realVarsData[27].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[28].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[24], 0, &data->modelData->realVarsData[28].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[29].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[25], 0, &data->modelData->realVarsData[29].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[30].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[26], 0, &data->modelData->realVarsData[30].attribute.start);
  
  return 0;
}

int GSQuad_Components_Controller_inputNames(DATA *data, char ** names){
  names[0] = (char *) data->modelData->realVarsData[0].info.name;
  names[1] = (char *) data->modelData->realVarsData[1].info.name;
  names[2] = (char *) data->modelData->realVarsData[2].info.name;
  names[3] = (char *) data->modelData->realVarsData[3].info.name;
  names[4] = (char *) data->modelData->realVarsData[4].info.name;
  names[5] = (char *) data->modelData->realVarsData[5].info.name;
  names[6] = (char *) data->modelData->realVarsData[6].info.name;
  names[7] = (char *) data->modelData->realVarsData[7].info.name;
  names[8] = (char *) data->modelData->realVarsData[8].info.name;
  names[9] = (char *) data->modelData->realVarsData[9].info.name;
  names[10] = (char *) data->modelData->realVarsData[10].info.name;
  names[11] = (char *) data->modelData->realVarsData[11].info.name;
  names[12] = (char *) data->modelData->realVarsData[16].info.name;
  names[13] = (char *) data->modelData->realVarsData[17].info.name;
  names[14] = (char *) data->modelData->realVarsData[18].info.name;
  names[15] = (char *) data->modelData->realVarsData[19].info.name;
  names[16] = (char *) data->modelData->realVarsData[20].info.name;
  names[17] = (char *) data->modelData->realVarsData[21].info.name;
  names[18] = (char *) data->modelData->realVarsData[22].info.name;
  names[19] = (char *) data->modelData->realVarsData[23].info.name;
  names[20] = (char *) data->modelData->realVarsData[24].info.name;
  names[21] = (char *) data->modelData->realVarsData[25].info.name;
  names[22] = (char *) data->modelData->realVarsData[26].info.name;
  names[23] = (char *) data->modelData->realVarsData[27].info.name;
  names[24] = (char *) data->modelData->realVarsData[28].info.name;
  names[25] = (char *) data->modelData->realVarsData[29].info.name;
  names[26] = (char *) data->modelData->realVarsData[30].info.name;
  
  return 0;
}

int GSQuad_Components_Controller_data_function(DATA *data, threadData_t *threadData)
{
  return 0;
}

int GSQuad_Components_Controller_dataReconciliationInputNames(DATA *data, char ** names){
  
  return 0;
}

int GSQuad_Components_Controller_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  
  return 0;
}

int GSQuad_Components_Controller_output_function(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* pwm_rotor_cmd[1] variable */);
  data->simulationInfo->outputVars[1] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* pwm_rotor_cmd[2] variable */);
  data->simulationInfo->outputVars[2] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* pwm_rotor_cmd[3] variable */);
  data->simulationInfo->outputVars[3] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* pwm_rotor_cmd[4] variable */);
  
  return 0;
}

int GSQuad_Components_Controller_setc_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

int GSQuad_Components_Controller_setb_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}


/*
equation index: 195
type: SIMPLE_ASSIGN
pwm_rotor_cmd[4] = pwm_min + (pwm_max - pwm_min) * pre(euler_pid.normalized_ctrl_input[4])
*/
void GSQuad_Components_Controller_eqFunction_195(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,195};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* pwm_rotor_cmd[4] variable */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* pwm_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */)) * ((data->simulationInfo->realVarsPre[67] /* euler_pid.normalized_ctrl_input[4] DISCRETE */));
  threadData->lastEquationSolved = 195;
}

/*
equation index: 196
type: SIMPLE_ASSIGN
pwm_rotor_cmd[3] = pwm_min + (pwm_max - pwm_min) * pre(euler_pid.normalized_ctrl_input[3])
*/
void GSQuad_Components_Controller_eqFunction_196(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,196};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* pwm_rotor_cmd[3] variable */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* pwm_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */)) * ((data->simulationInfo->realVarsPre[66] /* euler_pid.normalized_ctrl_input[3] DISCRETE */));
  threadData->lastEquationSolved = 196;
}

/*
equation index: 197
type: SIMPLE_ASSIGN
pwm_rotor_cmd[2] = pwm_min + (pwm_max - pwm_min) * pre(euler_pid.normalized_ctrl_input[2])
*/
void GSQuad_Components_Controller_eqFunction_197(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,197};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* pwm_rotor_cmd[2] variable */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* pwm_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */)) * ((data->simulationInfo->realVarsPre[65] /* euler_pid.normalized_ctrl_input[2] DISCRETE */));
  threadData->lastEquationSolved = 197;
}

/*
equation index: 198
type: SIMPLE_ASSIGN
pwm_rotor_cmd[1] = pwm_min + (pwm_max - pwm_min) * pre(euler_pid.normalized_ctrl_input[1])
*/
void GSQuad_Components_Controller_eqFunction_198(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,198};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* pwm_rotor_cmd[1] variable */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* pwm_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* pwm_min PARAM */)) * ((data->simulationInfo->realVarsPre[64] /* euler_pid.normalized_ctrl_input[1] DISCRETE */));
  threadData->lastEquationSolved = 198;
}

/*
equation index: 199
type: ALGORITHM

  euler_pid.rate_wb_b_fdbk[3] := pre(euler_pid.rate_wb_b_fdbk[3]);
  euler_pid.rate_wb_b_fdbk[2] := pre(euler_pid.rate_wb_b_fdbk[2]);
  euler_pid.rate_wb_b_fdbk[1] := pre(euler_pid.rate_wb_b_fdbk[1]);
  euler_pid.euler_wb_fdbk[3] := pre(euler_pid.euler_wb_fdbk[3]);
  euler_pid.euler_wb_fdbk[2] := pre(euler_pid.euler_wb_fdbk[2]);
  euler_pid.euler_wb_fdbk[1] := pre(euler_pid.euler_wb_fdbk[1]);
  euler_pid.vel_w_p_b_fdbk[3] := pre(euler_pid.vel_w_p_b_fdbk[3]);
  euler_pid.vel_w_p_b_fdbk[2] := pre(euler_pid.vel_w_p_b_fdbk[2]);
  euler_pid.vel_w_p_b_fdbk[1] := pre(euler_pid.vel_w_p_b_fdbk[1]);
  euler_pid.pos_w_p_w_fdbk[3] := pre(euler_pid.pos_w_p_w_fdbk[3]);
  euler_pid.pos_w_p_w_fdbk[2] := pre(euler_pid.pos_w_p_w_fdbk[2]);
  euler_pid.pos_w_p_w_fdbk[1] := pre(euler_pid.pos_w_p_w_fdbk[1]);
  euler_pid.yaw_setpoint := pre(euler_pid.yaw_setpoint);
  euler_pid.position_setpoint[3] := pre(euler_pid.position_setpoint[3]);
  euler_pid.position_setpoint[2] := pre(euler_pid.position_setpoint[2]);
  euler_pid.position_setpoint[1] := pre(euler_pid.position_setpoint[1]);
  $whenCondition2 := pre($whenCondition2);
  $whenCondition2 := sample(2, 0.0, update_period);
  when $whenCondition2 then
    if fidelity == 1 then
      euler_pid.position_setpoint := position_setpoint;
      euler_pid.yaw_setpoint := yaw_setpoint;
      euler_pid.pos_w_p_w_fdbk := pos_w_p_w_fdbk;
      euler_pid.vel_w_p_b_fdbk := vel_w_p_b_fdbk;
      euler_pid.euler_wb_fdbk := euler_wb_fdbk;
      euler_pid.rate_wb_b_fdbk := rate_wb_b_fdbk;
    end if;
  end when;
*/
void GSQuad_Components_Controller_eqFunction_199(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,199};
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
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */) = (data->simulationInfo->realVarsPre[99] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */) = (data->simulationInfo->realVarsPre[98] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */) = (data->simulationInfo->realVarsPre[97] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* euler_pid.euler_wb_fdbk[3] DISCRETE */) = (data->simulationInfo->realVarsPre[54] /* euler_pid.euler_wb_fdbk[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* euler_pid.euler_wb_fdbk[2] DISCRETE */) = (data->simulationInfo->realVarsPre[53] /* euler_pid.euler_wb_fdbk[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* euler_pid.euler_wb_fdbk[1] DISCRETE */) = (data->simulationInfo->realVarsPre[52] /* euler_pid.euler_wb_fdbk[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[122]] /* euler_pid.vel_w_p_b_fdbk[3] DISCRETE */) = (data->simulationInfo->realVarsPre[122] /* euler_pid.vel_w_p_b_fdbk[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[121]] /* euler_pid.vel_w_p_b_fdbk[2] DISCRETE */) = (data->simulationInfo->realVarsPre[121] /* euler_pid.vel_w_p_b_fdbk[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */) = (data->simulationInfo->realVarsPre[120] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* euler_pid.pos_w_p_w_fdbk[3] DISCRETE */) = (data->simulationInfo->realVarsPre[78] /* euler_pid.pos_w_p_w_fdbk[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* euler_pid.pos_w_p_w_fdbk[2] DISCRETE */) = (data->simulationInfo->realVarsPre[77] /* euler_pid.pos_w_p_w_fdbk[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* euler_pid.pos_w_p_w_fdbk[1] DISCRETE */) = (data->simulationInfo->realVarsPre[76] /* euler_pid.pos_w_p_w_fdbk[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[123]] /* euler_pid.yaw_setpoint DISCRETE */) = (data->simulationInfo->realVarsPre[123] /* euler_pid.yaw_setpoint DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* euler_pid.position_setpoint[3] DISCRETE */) = (data->simulationInfo->realVarsPre[81] /* euler_pid.position_setpoint[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* euler_pid.position_setpoint[2] DISCRETE */) = (data->simulationInfo->realVarsPre[80] /* euler_pid.position_setpoint[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* euler_pid.position_setpoint[1] DISCRETE */) = (data->simulationInfo->realVarsPre[79] /* euler_pid.position_setpoint[1] DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = (data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = data->simulationInfo->samples[1];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */) /* edge */))
    {
      if(((data->simulationInfo->integerParameter[data->simulationInfo->integerParamsIndex[0]] /* fidelity PARAM */) == ((modelica_integer) 1)))
      {
        real_array_create(&tmp0, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* position_setpoint[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_create(&tmp1, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* euler_pid.position_setpoint[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_copy_data(tmp0, tmp1);

        (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[123]] /* euler_pid.yaw_setpoint DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* yaw_setpoint variable */);

        real_array_create(&tmp2, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* pos_w_p_w_fdbk[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_create(&tmp3, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* euler_pid.pos_w_p_w_fdbk[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_copy_data(tmp2, tmp3);

        real_array_create(&tmp4, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* vel_w_p_b_fdbk[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_create(&tmp5, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_copy_data(tmp4, tmp5);

        real_array_create(&tmp6, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* euler_wb_fdbk[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_create(&tmp7, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* euler_pid.euler_wb_fdbk[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_copy_data(tmp6, tmp7);

        real_array_create(&tmp8, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* rate_wb_b_fdbk[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_create(&tmp9, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
        real_array_copy_data(tmp8, tmp9);
      }
    }
  }
  threadData->lastEquationSolved = 199;
}

/*
equation index: 200
type: ALGORITHM

  euler_pid.normalized_ctrl_input[4] := pre(euler_pid.normalized_ctrl_input[4]);
  euler_pid.normalized_ctrl_input[3] := pre(euler_pid.normalized_ctrl_input[3]);
  euler_pid.normalized_ctrl_input[2] := pre(euler_pid.normalized_ctrl_input[2]);
  euler_pid.normalized_ctrl_input[1] := pre(euler_pid.normalized_ctrl_input[1]);
  euler_pid.omega_spd_sq_target[4] := pre(euler_pid.omega_spd_sq_target[4]);
  euler_pid.omega_spd_sq_target[3] := pre(euler_pid.omega_spd_sq_target[3]);
  euler_pid.omega_spd_sq_target[2] := pre(euler_pid.omega_spd_sq_target[2]);
  euler_pid.omega_spd_sq_target[1] := pre(euler_pid.omega_spd_sq_target[1]);
  euler_pid.thrust_target[4] := pre(euler_pid.thrust_target[4]);
  euler_pid.thrust_target[3] := pre(euler_pid.thrust_target[3]);
  euler_pid.thrust_target[2] := pre(euler_pid.thrust_target[2]);
  euler_pid.thrust_target[1] := pre(euler_pid.thrust_target[1]);
  euler_pid.fm_target[4] := pre(euler_pid.fm_target[4]);
  euler_pid.fm_target[3] := pre(euler_pid.fm_target[3]);
  euler_pid.fm_target[2] := pre(euler_pid.fm_target[2]);
  euler_pid.fm_target[1] := pre(euler_pid.fm_target[1]);
  euler_pid.force_target := pre(euler_pid.force_target);
  euler_pid.lean_angle := pre(euler_pid.lean_angle);
  euler_pid.att_body_thrust_vec[3] := pre(euler_pid.att_body_thrust_vec[3]);
  euler_pid.att_body_thrust_vec[2] := pre(euler_pid.att_body_thrust_vec[2]);
  euler_pid.att_body_thrust_vec[1] := pre(euler_pid.att_body_thrust_vec[1]);
  euler_pid.moment_target[3] := pre(euler_pid.moment_target[3]);
  euler_pid.moment_target[2] := pre(euler_pid.moment_target[2]);
  euler_pid.moment_target[1] := pre(euler_pid.moment_target[1]);
  euler_pid.rate_error_last[3] := pre(euler_pid.rate_error_last[3]);
  euler_pid.rate_error_last[2] := pre(euler_pid.rate_error_last[2]);
  euler_pid.rate_error_last[1] := pre(euler_pid.rate_error_last[1]);
  euler_pid.rate_error_d[3] := pre(euler_pid.rate_error_d[3]);
  euler_pid.rate_error_d[2] := pre(euler_pid.rate_error_d[2]);
  euler_pid.rate_error_d[1] := pre(euler_pid.rate_error_d[1]);
  euler_pid.rate_error_i[3] := pre(euler_pid.rate_error_i[3]);
  euler_pid.rate_error_i[2] := pre(euler_pid.rate_error_i[2]);
  euler_pid.rate_error_i[1] := pre(euler_pid.rate_error_i[1]);
  euler_pid.rate_error[3] := pre(euler_pid.rate_error[3]);
  euler_pid.rate_error[2] := pre(euler_pid.rate_error[2]);
  euler_pid.rate_error[1] := pre(euler_pid.rate_error[1]);
  euler_pid.rate_target[3] := pre(euler_pid.rate_target[3]);
  euler_pid.rate_target[2] := pre(euler_pid.rate_target[2]);
  euler_pid.rate_target[1] := pre(euler_pid.rate_target[1]);
  euler_pid.att_error[3] := pre(euler_pid.att_error[3]);
  euler_pid.att_error[2] := pre(euler_pid.att_error[2]);
  euler_pid.att_error[1] := pre(euler_pid.att_error[1]);
  euler_pid.yaw_target := pre(euler_pid.yaw_target);
  euler_pid.roll_target := pre(euler_pid.roll_target);
  euler_pid.pitch_target := pre(euler_pid.pitch_target);
  euler_pid.acc_rgt_target := pre(euler_pid.acc_rgt_target);
  euler_pid.acc_fwd_target := pre(euler_pid.acc_fwd_target);
  euler_pid.acc_z_target := pre(euler_pid.acc_z_target);
  euler_pid.acc_target[3] := pre(euler_pid.acc_target[3]);
  euler_pid.acc_target[2] := pre(euler_pid.acc_target[2]);
  euler_pid.acc_target[1] := pre(euler_pid.acc_target[1]);
  euler_pid.vel_error_last[3] := pre(euler_pid.vel_error_last[3]);
  euler_pid.vel_error_last[2] := pre(euler_pid.vel_error_last[2]);
  euler_pid.vel_error_last[1] := pre(euler_pid.vel_error_last[1]);
  euler_pid.vel_error_d[3] := pre(euler_pid.vel_error_d[3]);
  euler_pid.vel_error_d[2] := pre(euler_pid.vel_error_d[2]);
  euler_pid.vel_error_d[1] := pre(euler_pid.vel_error_d[1]);
  euler_pid.vel_error_i[3] := pre(euler_pid.vel_error_i[3]);
  euler_pid.vel_error_i[2] := pre(euler_pid.vel_error_i[2]);
  euler_pid.vel_error_i[1] := pre(euler_pid.vel_error_i[1]);
  euler_pid.vel_error[3] := pre(euler_pid.vel_error[3]);
  euler_pid.vel_error[2] := pre(euler_pid.vel_error[2]);
  euler_pid.vel_error[1] := pre(euler_pid.vel_error[1]);
  euler_pid.C_wb[3,3] := pre(euler_pid.C_wb[3,3]);
  euler_pid.C_wb[3,2] := pre(euler_pid.C_wb[3,2]);
  euler_pid.C_wb[3,1] := pre(euler_pid.C_wb[3,1]);
  euler_pid.C_wb[2,3] := pre(euler_pid.C_wb[2,3]);
  euler_pid.C_wb[2,2] := pre(euler_pid.C_wb[2,2]);
  euler_pid.C_wb[2,1] := pre(euler_pid.C_wb[2,1]);
  euler_pid.C_wb[1,3] := pre(euler_pid.C_wb[1,3]);
  euler_pid.C_wb[1,2] := pre(euler_pid.C_wb[1,2]);
  euler_pid.C_wb[1,1] := pre(euler_pid.C_wb[1,1]);
  euler_pid.vel_target[3] := pre(euler_pid.vel_target[3]);
  euler_pid.vel_target[2] := pre(euler_pid.vel_target[2]);
  euler_pid.vel_target[1] := pre(euler_pid.vel_target[1]);
  euler_pid.pos_error[3] := pre(euler_pid.pos_error[3]);
  euler_pid.pos_error[2] := pre(euler_pid.pos_error[2]);
  euler_pid.pos_error[1] := pre(euler_pid.pos_error[1]);
  $whenCondition1 := pre($whenCondition1);
  $whenCondition1 := sample(1, 0.0, euler_pid.update_interval);
  when $whenCondition1 then
    euler_pid.pos_error := {euler_pid.position_setpoint[1] - euler_pid.pos_w_p_w_fdbk[1], euler_pid.position_setpoint[2] - euler_pid.pos_w_p_w_fdbk[2], euler_pid.position_setpoint[3] - euler_pid.pos_w_p_w_fdbk[3]};
    euler_pid.vel_target := {euler_pid.Kp_x * euler_pid.pos_error[1], euler_pid.Kp_y * euler_pid.pos_error[2], euler_pid.Kp_z * euler_pid.pos_error[3]};
    euler_pid.C_wb := transpose(GSQuad.Utils.eul2rot(euler_pid.euler_wb_fdbk));
    euler_pid.vel_error := {euler_pid.vel_target[1] - (euler_pid.C_wb[1,1] * euler_pid.vel_w_p_b_fdbk[1] + euler_pid.C_wb[2,1] * euler_pid.vel_w_p_b_fdbk[2] + euler_pid.C_wb[3,1] * euler_pid.vel_w_p_b_fdbk[3]), euler_pid.vel_target[2] - (euler_pid.C_wb[1,2] * euler_pid.vel_w_p_b_fdbk[1] + euler_pid.C_wb[2,2] * euler_pid.vel_w_p_b_fdbk[2] + euler_pid.C_wb[3,2] * euler_pid.vel_w_p_b_fdbk[3]), euler_pid.vel_target[3] - (euler_pid.C_wb[1,3] * euler_pid.vel_w_p_b_fdbk[1] + euler_pid.C_wb[2,3] * euler_pid.vel_w_p_b_fdbk[2] + euler_pid.C_wb[3,3] * euler_pid.vel_w_p_b_fdbk[3])};
    euler_pid.vel_error_i := {euler_pid.vel_error_i[1] + euler_pid.vel_error[1] * euler_pid.update_interval, euler_pid.vel_error_i[2] + euler_pid.vel_error[2] * euler_pid.update_interval, euler_pid.vel_error_i[3] + euler_pid.vel_error[3] * euler_pid.update_interval};
    euler_pid.vel_error_d := {(euler_pid.vel_error[1] - euler_pid.vel_error_last[1]) / euler_pid.update_interval, (euler_pid.vel_error[2] - euler_pid.vel_error_last[2]) / euler_pid.update_interval, (euler_pid.vel_error[3] - euler_pid.vel_error_last[3]) / euler_pid.update_interval};
    euler_pid.vel_error_last := euler_pid.vel_error;
    euler_pid.acc_target := {euler_pid.Kp_vx * euler_pid.vel_error[1] + euler_pid.Ki_vx * euler_pid.vel_error_i[1] + euler_pid.Kd_vx * euler_pid.vel_error_d[1], euler_pid.Kp_vy * euler_pid.vel_error[2] + euler_pid.Ki_vy * euler_pid.vel_error_i[2] + euler_pid.Kd_vy * euler_pid.vel_error_d[2], euler_pid.Kp_vz * euler_pid.vel_error[3] + euler_pid.Ki_vz * euler_pid.vel_error_i[3] + euler_pid.Kd_vz * euler_pid.vel_error_d[3] - 9.80665};
    euler_pid.acc_z_target := -euler_pid.acc_target[3];
    euler_pid.acc_fwd_target := euler_pid.acc_target[1] * cos(euler_pid.euler_wb_fdbk[3]) + euler_pid.acc_target[2] * sin(euler_pid.euler_wb_fdbk[3]);
    euler_pid.acc_rgt_target := euler_pid.acc_target[2] * cos(euler_pid.euler_wb_fdbk[3]) - euler_pid.acc_target[1] * sin(euler_pid.euler_wb_fdbk[3]);
    euler_pid.pitch_target := atan((-euler_pid.acc_fwd_target) / 9.80665);
    euler_pid.roll_target := atan(euler_pid.acc_rgt_target * cos(euler_pid.pitch_target) / 9.80665);
    euler_pid.yaw_target := euler_pid.yaw_setpoint;
    euler_pid.att_error := {euler_pid.roll_target - euler_pid.euler_wb_fdbk[1], euler_pid.pitch_target - euler_pid.euler_wb_fdbk[2], euler_pid.yaw_target - euler_pid.euler_wb_fdbk[3]};
    euler_pid.rate_target := {euler_pid.Kp_phi * euler_pid.att_error[1], euler_pid.Kp_the * euler_pid.att_error[2], euler_pid.Kp_psi * euler_pid.att_error[3]};
    euler_pid.rate_error := {euler_pid.rate_target[1] - euler_pid.rate_wb_b_fdbk[1], euler_pid.rate_target[2] - euler_pid.rate_wb_b_fdbk[2], euler_pid.rate_target[3] - euler_pid.rate_wb_b_fdbk[3]};
    euler_pid.rate_error_i := {euler_pid.rate_error_i[1] + euler_pid.rate_error[1] * euler_pid.update_interval, euler_pid.rate_error_i[2] + euler_pid.rate_error[2] * euler_pid.update_interval, euler_pid.rate_error_i[3] + euler_pid.rate_error[3] * euler_pid.update_interval};
    euler_pid.rate_error_d := {(euler_pid.rate_error[1] - euler_pid.rate_error_last[1]) / euler_pid.update_interval, (euler_pid.rate_error[2] - euler_pid.rate_error_last[2]) / euler_pid.update_interval, (euler_pid.rate_error[3] - euler_pid.rate_error_last[3]) / euler_pid.update_interval};
    euler_pid.rate_error_last := euler_pid.rate_error;
    euler_pid.moment_target := {euler_pid.J[1,1] * (euler_pid.Kp_p * euler_pid.rate_error[1] + euler_pid.Ki_p * euler_pid.rate_error_i[1] + euler_pid.Kd_p * euler_pid.rate_error_d[1]) + euler_pid.J[1,2] * (euler_pid.Kp_q * euler_pid.rate_error[2] + euler_pid.Ki_q * euler_pid.rate_error_i[2] + euler_pid.Kd_q * euler_pid.rate_error_d[2]) + euler_pid.J[1,3] * (euler_pid.Kp_r * euler_pid.rate_error[3] + euler_pid.Ki_r * euler_pid.rate_error_i[3] + euler_pid.Kd_r * euler_pid.rate_error_d[3]), euler_pid.J[2,1] * (euler_pid.Kp_p * euler_pid.rate_error[1] + euler_pid.Ki_p * euler_pid.rate_error_i[1] + euler_pid.Kd_p * euler_pid.rate_error_d[1]) + euler_pid.J[2,2] * (euler_pid.Kp_q * euler_pid.rate_error[2] + euler_pid.Ki_q * euler_pid.rate_error_i[2] + euler_pid.Kd_q * euler_pid.rate_error_d[2]) + euler_pid.J[2,3] * (euler_pid.Kp_r * euler_pid.rate_error[3] + euler_pid.Ki_r * euler_pid.rate_error_i[3] + euler_pid.Kd_r * euler_pid.rate_error_d[3]), euler_pid.J[3,1] * (euler_pid.Kp_p * euler_pid.rate_error[1] + euler_pid.Ki_p * euler_pid.rate_error_i[1] + euler_pid.Kd_p * euler_pid.rate_error_d[1]) + euler_pid.J[3,2] * (euler_pid.Kp_q * euler_pid.rate_error[2] + euler_pid.Ki_q * euler_pid.rate_error_i[2] + euler_pid.Kd_q * euler_pid.rate_error_d[2]) + euler_pid.J[3,3] * (euler_pid.Kp_r * euler_pid.rate_error[3] + euler_pid.Ki_r * euler_pid.rate_error_i[3] + euler_pid.Kd_r * euler_pid.rate_error_d[3])} + GSQuad.Utils.hatmap(euler_pid.rate_wb_b_fdbk) * {euler_pid.J[1,1] * euler_pid.rate_wb_b_fdbk[1] + euler_pid.J[1,2] * euler_pid.rate_wb_b_fdbk[2] + euler_pid.J[1,3] * euler_pid.rate_wb_b_fdbk[3], euler_pid.J[2,1] * euler_pid.rate_wb_b_fdbk[1] + euler_pid.J[2,2] * euler_pid.rate_wb_b_fdbk[2] + euler_pid.J[2,3] * euler_pid.rate_wb_b_fdbk[3], euler_pid.J[3,1] * euler_pid.rate_wb_b_fdbk[1] + euler_pid.J[3,2] * euler_pid.rate_wb_b_fdbk[2] + euler_pid.J[3,3] * euler_pid.rate_wb_b_fdbk[3]};
    euler_pid.att_body_thrust_vec := {-euler_pid.C_wb[1,3], -euler_pid.C_wb[2,3], -euler_pid.C_wb[3,3]};
    euler_pid.lean_angle := acos(GSQuad.Utils.clip(-euler_pid.att_body_thrust_vec[3], -1.0, 1.0));
    euler_pid.force_target := euler_pid.mass * euler_pid.acc_z_target / cos(euler_pid.lean_angle);
    euler_pid.fm_target := {euler_pid.force_target, euler_pid.moment_target[1], euler_pid.moment_target[2], euler_pid.moment_target[3]};
    euler_pid.thrust_target := {euler_pid.pinv_CA[1,1] * euler_pid.fm_target[1] + euler_pid.pinv_CA[1,2] * euler_pid.fm_target[2] + euler_pid.pinv_CA[1,3] * euler_pid.fm_target[3] + euler_pid.pinv_CA[1,4] * euler_pid.fm_target[4], euler_pid.pinv_CA[2,1] * euler_pid.fm_target[1] + euler_pid.pinv_CA[2,2] * euler_pid.fm_target[2] + euler_pid.pinv_CA[2,3] * euler_pid.fm_target[3] + euler_pid.pinv_CA[2,4] * euler_pid.fm_target[4], euler_pid.pinv_CA[3,1] * euler_pid.fm_target[1] + euler_pid.pinv_CA[3,2] * euler_pid.fm_target[2] + euler_pid.pinv_CA[3,3] * euler_pid.fm_target[3] + euler_pid.pinv_CA[3,4] * euler_pid.fm_target[4], euler_pid.pinv_CA[4,1] * euler_pid.fm_target[1] + euler_pid.pinv_CA[4,2] * euler_pid.fm_target[2] + euler_pid.pinv_CA[4,3] * euler_pid.fm_target[3] + euler_pid.pinv_CA[4,4] * euler_pid.fm_target[4]};
    euler_pid.omega_spd_sq_target := {euler_pid.thrust_target[1] / euler_pid.k_eta, euler_pid.thrust_target[2] / euler_pid.k_eta, euler_pid.thrust_target[3] / euler_pid.k_eta, euler_pid.thrust_target[4] / euler_pid.k_eta};
    for i in 1:4 loop
      euler_pid.normalized_ctrl_input[i] := (sqrt(GSQuad.Utils.clip(euler_pid.omega_spd_sq_target[i], 0.0, euler_pid.omega_rotor_max ^ 8.0)) - euler_pid.omega_rotor_min) / (euler_pid.omega_rotor_max - euler_pid.omega_rotor_min) + euler_pid.omega_rotor_min;
    end for;
  end when;
*/
void GSQuad_Components_Controller_eqFunction_200(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,200};
  real_array tmp10;
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
  real_array tmp45;
  modelica_real tmp46;
  real_array tmp47;
  real_array tmp48;
  real_array tmp49;
  real_array tmp50;
  real_array tmp51;
  real_array tmp52;
  modelica_real tmp53;
  modelica_integer tmp54;
  modelica_integer tmp55;
  modelica_integer tmp56;
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* euler_pid.normalized_ctrl_input[4] DISCRETE */) = (data->simulationInfo->realVarsPre[67] /* euler_pid.normalized_ctrl_input[4] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* euler_pid.normalized_ctrl_input[3] DISCRETE */) = (data->simulationInfo->realVarsPre[66] /* euler_pid.normalized_ctrl_input[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* euler_pid.normalized_ctrl_input[2] DISCRETE */) = (data->simulationInfo->realVarsPre[65] /* euler_pid.normalized_ctrl_input[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* euler_pid.normalized_ctrl_input[1] DISCRETE */) = (data->simulationInfo->realVarsPre[64] /* euler_pid.normalized_ctrl_input[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* euler_pid.omega_spd_sq_target[4] DISCRETE */) = (data->simulationInfo->realVarsPre[71] /* euler_pid.omega_spd_sq_target[4] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* euler_pid.omega_spd_sq_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[70] /* euler_pid.omega_spd_sq_target[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* euler_pid.omega_spd_sq_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[69] /* euler_pid.omega_spd_sq_target[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* euler_pid.omega_spd_sq_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[68] /* euler_pid.omega_spd_sq_target[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* euler_pid.thrust_target[4] DISCRETE */) = (data->simulationInfo->realVarsPre[104] /* euler_pid.thrust_target[4] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[103]] /* euler_pid.thrust_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[103] /* euler_pid.thrust_target[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[102]] /* euler_pid.thrust_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[102] /* euler_pid.thrust_target[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[101]] /* euler_pid.thrust_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[101] /* euler_pid.thrust_target[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* euler_pid.fm_target[4] DISCRETE */) = (data->simulationInfo->realVarsPre[58] /* euler_pid.fm_target[4] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* euler_pid.fm_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[57] /* euler_pid.fm_target[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* euler_pid.fm_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[56] /* euler_pid.fm_target[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* euler_pid.fm_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[55] /* euler_pid.fm_target[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* euler_pid.force_target DISCRETE */) = (data->simulationInfo->realVarsPre[59] /* euler_pid.force_target DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* euler_pid.lean_angle DISCRETE */) = (data->simulationInfo->realVarsPre[60] /* euler_pid.lean_angle DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* euler_pid.att_body_thrust_vec[3] DISCRETE */) = (data->simulationInfo->realVarsPre[48] /* euler_pid.att_body_thrust_vec[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* euler_pid.att_body_thrust_vec[2] DISCRETE */) = (data->simulationInfo->realVarsPre[47] /* euler_pid.att_body_thrust_vec[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* euler_pid.att_body_thrust_vec[1] DISCRETE */) = (data->simulationInfo->realVarsPre[46] /* euler_pid.att_body_thrust_vec[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* euler_pid.moment_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[63] /* euler_pid.moment_target[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* euler_pid.moment_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[62] /* euler_pid.moment_target[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* euler_pid.moment_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[61] /* euler_pid.moment_target[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* euler_pid.rate_error_last[3] DISCRETE */) = (data->simulationInfo->realVarsPre[93] /* euler_pid.rate_error_last[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* euler_pid.rate_error_last[2] DISCRETE */) = (data->simulationInfo->realVarsPre[92] /* euler_pid.rate_error_last[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* euler_pid.rate_error_last[1] DISCRETE */) = (data->simulationInfo->realVarsPre[91] /* euler_pid.rate_error_last[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* euler_pid.rate_error_d[3] DISCRETE */) = (data->simulationInfo->realVarsPre[87] /* euler_pid.rate_error_d[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* euler_pid.rate_error_d[2] DISCRETE */) = (data->simulationInfo->realVarsPre[86] /* euler_pid.rate_error_d[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* euler_pid.rate_error_d[1] DISCRETE */) = (data->simulationInfo->realVarsPre[85] /* euler_pid.rate_error_d[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* euler_pid.rate_error_i[3] DISCRETE */) = (data->simulationInfo->realVarsPre[90] /* euler_pid.rate_error_i[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* euler_pid.rate_error_i[2] DISCRETE */) = (data->simulationInfo->realVarsPre[89] /* euler_pid.rate_error_i[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* euler_pid.rate_error_i[1] DISCRETE */) = (data->simulationInfo->realVarsPre[88] /* euler_pid.rate_error_i[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* euler_pid.rate_error[3] DISCRETE */) = (data->simulationInfo->realVarsPre[84] /* euler_pid.rate_error[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* euler_pid.rate_error[2] DISCRETE */) = (data->simulationInfo->realVarsPre[83] /* euler_pid.rate_error[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* euler_pid.rate_error[1] DISCRETE */) = (data->simulationInfo->realVarsPre[82] /* euler_pid.rate_error[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* euler_pid.rate_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[96] /* euler_pid.rate_target[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* euler_pid.rate_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[95] /* euler_pid.rate_target[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* euler_pid.rate_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[94] /* euler_pid.rate_target[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* euler_pid.att_error[3] DISCRETE */) = (data->simulationInfo->realVarsPre[51] /* euler_pid.att_error[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* euler_pid.att_error[2] DISCRETE */) = (data->simulationInfo->realVarsPre[50] /* euler_pid.att_error[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* euler_pid.att_error[1] DISCRETE */) = (data->simulationInfo->realVarsPre[49] /* euler_pid.att_error[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[124]] /* euler_pid.yaw_target DISCRETE */) = (data->simulationInfo->realVarsPre[124] /* euler_pid.yaw_target DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[100]] /* euler_pid.roll_target DISCRETE */) = (data->simulationInfo->realVarsPre[100] /* euler_pid.roll_target DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* euler_pid.pitch_target DISCRETE */) = (data->simulationInfo->realVarsPre[72] /* euler_pid.pitch_target DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* euler_pid.acc_rgt_target DISCRETE */) = (data->simulationInfo->realVarsPre[41] /* euler_pid.acc_rgt_target DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* euler_pid.acc_fwd_target DISCRETE */) = (data->simulationInfo->realVarsPre[40] /* euler_pid.acc_fwd_target DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* euler_pid.acc_z_target DISCRETE */) = (data->simulationInfo->realVarsPre[45] /* euler_pid.acc_z_target DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* euler_pid.acc_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[44] /* euler_pid.acc_target[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* euler_pid.acc_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[43] /* euler_pid.acc_target[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* euler_pid.acc_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[42] /* euler_pid.acc_target[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[116]] /* euler_pid.vel_error_last[3] DISCRETE */) = (data->simulationInfo->realVarsPre[116] /* euler_pid.vel_error_last[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[115]] /* euler_pid.vel_error_last[2] DISCRETE */) = (data->simulationInfo->realVarsPre[115] /* euler_pid.vel_error_last[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* euler_pid.vel_error_last[1] DISCRETE */) = (data->simulationInfo->realVarsPre[114] /* euler_pid.vel_error_last[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[110]] /* euler_pid.vel_error_d[3] DISCRETE */) = (data->simulationInfo->realVarsPre[110] /* euler_pid.vel_error_d[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[109]] /* euler_pid.vel_error_d[2] DISCRETE */) = (data->simulationInfo->realVarsPre[109] /* euler_pid.vel_error_d[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* euler_pid.vel_error_d[1] DISCRETE */) = (data->simulationInfo->realVarsPre[108] /* euler_pid.vel_error_d[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[113]] /* euler_pid.vel_error_i[3] DISCRETE */) = (data->simulationInfo->realVarsPre[113] /* euler_pid.vel_error_i[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[112]] /* euler_pid.vel_error_i[2] DISCRETE */) = (data->simulationInfo->realVarsPre[112] /* euler_pid.vel_error_i[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* euler_pid.vel_error_i[1] DISCRETE */) = (data->simulationInfo->realVarsPre[111] /* euler_pid.vel_error_i[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* euler_pid.vel_error[3] DISCRETE */) = (data->simulationInfo->realVarsPre[107] /* euler_pid.vel_error[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* euler_pid.vel_error[2] DISCRETE */) = (data->simulationInfo->realVarsPre[106] /* euler_pid.vel_error[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* euler_pid.vel_error[1] DISCRETE */) = (data->simulationInfo->realVarsPre[105] /* euler_pid.vel_error[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* euler_pid.C_wb[3,3] DISCRETE */) = (data->simulationInfo->realVarsPre[39] /* euler_pid.C_wb[3,3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* euler_pid.C_wb[3,2] DISCRETE */) = (data->simulationInfo->realVarsPre[38] /* euler_pid.C_wb[3,2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* euler_pid.C_wb[3,1] DISCRETE */) = (data->simulationInfo->realVarsPre[37] /* euler_pid.C_wb[3,1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* euler_pid.C_wb[2,3] DISCRETE */) = (data->simulationInfo->realVarsPre[36] /* euler_pid.C_wb[2,3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* euler_pid.C_wb[2,2] DISCRETE */) = (data->simulationInfo->realVarsPre[35] /* euler_pid.C_wb[2,2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* euler_pid.C_wb[2,1] DISCRETE */) = (data->simulationInfo->realVarsPre[34] /* euler_pid.C_wb[2,1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* euler_pid.C_wb[1,3] DISCRETE */) = (data->simulationInfo->realVarsPre[33] /* euler_pid.C_wb[1,3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* euler_pid.C_wb[1,2] DISCRETE */) = (data->simulationInfo->realVarsPre[32] /* euler_pid.C_wb[1,2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* euler_pid.C_wb[1,1] DISCRETE */) = (data->simulationInfo->realVarsPre[31] /* euler_pid.C_wb[1,1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[119]] /* euler_pid.vel_target[3] DISCRETE */) = (data->simulationInfo->realVarsPre[119] /* euler_pid.vel_target[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[118]] /* euler_pid.vel_target[2] DISCRETE */) = (data->simulationInfo->realVarsPre[118] /* euler_pid.vel_target[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[117]] /* euler_pid.vel_target[1] DISCRETE */) = (data->simulationInfo->realVarsPre[117] /* euler_pid.vel_target[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* euler_pid.pos_error[3] DISCRETE */) = (data->simulationInfo->realVarsPre[75] /* euler_pid.pos_error[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* euler_pid.pos_error[2] DISCRETE */) = (data->simulationInfo->realVarsPre[74] /* euler_pid.pos_error[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* euler_pid.pos_error[1] DISCRETE */) = (data->simulationInfo->realVarsPre[73] /* euler_pid.pos_error[1] DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = data->simulationInfo->samples[0];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
    {
      array_alloc_scalar_real_array(&tmp10, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* euler_pid.position_setpoint[1] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* euler_pid.pos_w_p_w_fdbk[1] DISCRETE */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* euler_pid.position_setpoint[2] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* euler_pid.pos_w_p_w_fdbk[2] DISCRETE */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* euler_pid.position_setpoint[3] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* euler_pid.pos_w_p_w_fdbk[3] DISCRETE */));
      real_array_create(&tmp11, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* euler_pid.pos_error[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp10, tmp11);

      array_alloc_scalar_real_array(&tmp12, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[36]] /* euler_pid.Kp_x PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* euler_pid.pos_error[1] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[37]] /* euler_pid.Kp_y PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* euler_pid.pos_error[2] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[38]] /* euler_pid.Kp_z PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* euler_pid.pos_error[3] DISCRETE */)));
      real_array_create(&tmp13, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[117]] /* euler_pid.vel_target[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp12, tmp13);

      real_array_create(&tmp14, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* euler_pid.euler_wb_fdbk[1] DISCRETE */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      tmp15 = omc_GSQuad_Utils_eul2rot(threadData, tmp14);
      transpose_alloc_real_array(&tmp15, &tmp16);
      real_array_create(&tmp17, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* euler_pid.C_wb[1,1] DISCRETE */))[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
      real_array_copy_data(tmp16, tmp17);

      array_alloc_scalar_real_array(&tmp18, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[117]] /* euler_pid.vel_target[1] DISCRETE */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* euler_pid.C_wb[1,1] DISCRETE */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* euler_pid.C_wb[2,1] DISCRETE */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[121]] /* euler_pid.vel_w_p_b_fdbk[2] DISCRETE */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* euler_pid.C_wb[3,1] DISCRETE */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[122]] /* euler_pid.vel_w_p_b_fdbk[3] DISCRETE */))), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[118]] /* euler_pid.vel_target[2] DISCRETE */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* euler_pid.C_wb[1,2] DISCRETE */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* euler_pid.C_wb[2,2] DISCRETE */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[121]] /* euler_pid.vel_w_p_b_fdbk[2] DISCRETE */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* euler_pid.C_wb[3,2] DISCRETE */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[122]] /* euler_pid.vel_w_p_b_fdbk[3] DISCRETE */))), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[119]] /* euler_pid.vel_target[3] DISCRETE */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* euler_pid.C_wb[1,3] DISCRETE */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* euler_pid.vel_w_p_b_fdbk[1] DISCRETE */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* euler_pid.C_wb[2,3] DISCRETE */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[121]] /* euler_pid.vel_w_p_b_fdbk[2] DISCRETE */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* euler_pid.C_wb[3,3] DISCRETE */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[122]] /* euler_pid.vel_w_p_b_fdbk[3] DISCRETE */))));
      real_array_create(&tmp19, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* euler_pid.vel_error[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp18, tmp19);

      array_alloc_scalar_real_array(&tmp20, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* euler_pid.vel_error_i[1] DISCRETE */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* euler_pid.vel_error[1] DISCRETE */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */)), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[112]] /* euler_pid.vel_error_i[2] DISCRETE */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* euler_pid.vel_error[2] DISCRETE */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */)), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[113]] /* euler_pid.vel_error_i[3] DISCRETE */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* euler_pid.vel_error[3] DISCRETE */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */)));
      real_array_create(&tmp21, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* euler_pid.vel_error_i[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp20, tmp21);

      array_alloc_scalar_real_array(&tmp22, 3, (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* euler_pid.vel_error[1] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* euler_pid.vel_error_last[1] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */),"euler_pid.update_interval",equationIndexes), (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* euler_pid.vel_error[2] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[115]] /* euler_pid.vel_error_last[2] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */),"euler_pid.update_interval",equationIndexes), (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* euler_pid.vel_error[3] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[116]] /* euler_pid.vel_error_last[3] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */),"euler_pid.update_interval",equationIndexes));
      real_array_create(&tmp23, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* euler_pid.vel_error_d[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp22, tmp23);

      real_array_create(&tmp24, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* euler_pid.vel_error[1] DISCRETE */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_create(&tmp25, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* euler_pid.vel_error_last[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp24, tmp25);

      array_alloc_scalar_real_array(&tmp26, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[33]] /* euler_pid.Kp_vx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* euler_pid.vel_error[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[24]] /* euler_pid.Ki_vx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* euler_pid.vel_error_i[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[18]] /* euler_pid.Kd_vx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* euler_pid.vel_error_d[1] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[34]] /* euler_pid.Kp_vy PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* euler_pid.vel_error[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[25]] /* euler_pid.Ki_vy PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[112]] /* euler_pid.vel_error_i[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* euler_pid.Kd_vy PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[109]] /* euler_pid.vel_error_d[2] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[35]] /* euler_pid.Kp_vz PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* euler_pid.vel_error[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[26]] /* euler_pid.Ki_vz PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[113]] /* euler_pid.vel_error_i[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[20]] /* euler_pid.Kd_vz PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[110]] /* euler_pid.vel_error_d[3] DISCRETE */)) - 9.80665);
      real_array_create(&tmp27, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* euler_pid.acc_target[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp26, tmp27);

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* euler_pid.acc_z_target DISCRETE */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* euler_pid.acc_target[3] DISCRETE */));

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* euler_pid.acc_fwd_target DISCRETE */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* euler_pid.acc_target[1] DISCRETE */)) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* euler_pid.euler_wb_fdbk[3] DISCRETE */))) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* euler_pid.acc_target[2] DISCRETE */)) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* euler_pid.euler_wb_fdbk[3] DISCRETE */)));

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* euler_pid.acc_rgt_target DISCRETE */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* euler_pid.acc_target[2] DISCRETE */)) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* euler_pid.euler_wb_fdbk[3] DISCRETE */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* euler_pid.acc_target[1] DISCRETE */)) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* euler_pid.euler_wb_fdbk[3] DISCRETE */))));

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* euler_pid.pitch_target DISCRETE */) = atan(DIVISION_SIM((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* euler_pid.acc_fwd_target DISCRETE */)),9.80665,"9.80665",equationIndexes));

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[100]] /* euler_pid.roll_target DISCRETE */) = atan(DIVISION_SIM(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* euler_pid.acc_rgt_target DISCRETE */)) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* euler_pid.pitch_target DISCRETE */))),9.80665,"9.80665",equationIndexes));

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[124]] /* euler_pid.yaw_target DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[123]] /* euler_pid.yaw_setpoint DISCRETE */);

      array_alloc_scalar_real_array(&tmp28, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[100]] /* euler_pid.roll_target DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* euler_pid.euler_wb_fdbk[1] DISCRETE */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* euler_pid.pitch_target DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* euler_pid.euler_wb_fdbk[2] DISCRETE */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[124]] /* euler_pid.yaw_target DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* euler_pid.euler_wb_fdbk[3] DISCRETE */));
      real_array_create(&tmp29, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* euler_pid.att_error[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp28, tmp29);

      array_alloc_scalar_real_array(&tmp30, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[28]] /* euler_pid.Kp_phi PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* euler_pid.att_error[1] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[32]] /* euler_pid.Kp_the PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* euler_pid.att_error[2] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[29]] /* euler_pid.Kp_psi PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* euler_pid.att_error[3] DISCRETE */)));
      real_array_create(&tmp31, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* euler_pid.rate_target[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp30, tmp31);

      array_alloc_scalar_real_array(&tmp32, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* euler_pid.rate_target[1] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* euler_pid.rate_target[2] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* euler_pid.rate_target[3] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */));
      real_array_create(&tmp33, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* euler_pid.rate_error[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp32, tmp33);

      array_alloc_scalar_real_array(&tmp34, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* euler_pid.rate_error_i[1] DISCRETE */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* euler_pid.rate_error[1] DISCRETE */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */)), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* euler_pid.rate_error_i[2] DISCRETE */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* euler_pid.rate_error[2] DISCRETE */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */)), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* euler_pid.rate_error_i[3] DISCRETE */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* euler_pid.rate_error[3] DISCRETE */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */)));
      real_array_create(&tmp35, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* euler_pid.rate_error_i[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp34, tmp35);

      array_alloc_scalar_real_array(&tmp36, 3, (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* euler_pid.rate_error[1] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* euler_pid.rate_error_last[1] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */),"euler_pid.update_interval",equationIndexes), (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* euler_pid.rate_error[2] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* euler_pid.rate_error_last[2] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */),"euler_pid.update_interval",equationIndexes), (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* euler_pid.rate_error[3] DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* euler_pid.rate_error_last[3] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */),"euler_pid.update_interval",equationIndexes));
      real_array_create(&tmp37, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* euler_pid.rate_error_d[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp36, tmp37);

      real_array_create(&tmp38, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* euler_pid.rate_error[1] DISCRETE */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_create(&tmp39, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* euler_pid.rate_error_last[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp38, tmp39);

      array_alloc_scalar_real_array(&tmp40, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[6]] /* euler_pid.J[1,1] PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[27]] /* euler_pid.Kp_p PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* euler_pid.rate_error[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* euler_pid.Ki_p PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* euler_pid.rate_error_i[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[15]] /* euler_pid.Kd_p PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* euler_pid.rate_error_d[1] DISCRETE */))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[7]] /* euler_pid.J[1,2] PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[30]] /* euler_pid.Kp_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* euler_pid.rate_error[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* euler_pid.Ki_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* euler_pid.rate_error_i[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[16]] /* euler_pid.Kd_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* euler_pid.rate_error_d[2] DISCRETE */))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[8]] /* euler_pid.J[1,3] PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[31]] /* euler_pid.Kp_r PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* euler_pid.rate_error[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* euler_pid.Ki_r PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* euler_pid.rate_error_i[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[17]] /* euler_pid.Kd_r PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* euler_pid.rate_error_d[3] DISCRETE */))), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* euler_pid.J[2,1] PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[27]] /* euler_pid.Kp_p PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* euler_pid.rate_error[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* euler_pid.Ki_p PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* euler_pid.rate_error_i[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[15]] /* euler_pid.Kd_p PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* euler_pid.rate_error_d[1] DISCRETE */))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* euler_pid.J[2,2] PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[30]] /* euler_pid.Kp_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* euler_pid.rate_error[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* euler_pid.Ki_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* euler_pid.rate_error_i[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[16]] /* euler_pid.Kd_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* euler_pid.rate_error_d[2] DISCRETE */))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* euler_pid.J[2,3] PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[31]] /* euler_pid.Kp_r PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* euler_pid.rate_error[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* euler_pid.Ki_r PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* euler_pid.rate_error_i[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[17]] /* euler_pid.Kd_r PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* euler_pid.rate_error_d[3] DISCRETE */))), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[12]] /* euler_pid.J[3,1] PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[27]] /* euler_pid.Kp_p PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* euler_pid.rate_error[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* euler_pid.Ki_p PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* euler_pid.rate_error_i[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[15]] /* euler_pid.Kd_p PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* euler_pid.rate_error_d[1] DISCRETE */))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[13]] /* euler_pid.J[3,2] PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[30]] /* euler_pid.Kp_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* euler_pid.rate_error[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* euler_pid.Ki_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* euler_pid.rate_error_i[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[16]] /* euler_pid.Kd_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* euler_pid.rate_error_d[2] DISCRETE */))) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[14]] /* euler_pid.J[3,3] PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[31]] /* euler_pid.Kp_r PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* euler_pid.rate_error[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* euler_pid.Ki_r PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* euler_pid.rate_error_i[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[17]] /* euler_pid.Kd_r PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* euler_pid.rate_error_d[3] DISCRETE */))));
      real_array_create(&tmp41, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      array_alloc_scalar_real_array(&tmp42, 3, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[6]] /* euler_pid.J[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[7]] /* euler_pid.J[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[8]] /* euler_pid.J[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* euler_pid.J[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* euler_pid.J[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* euler_pid.J[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[12]] /* euler_pid.J[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* euler_pid.rate_wb_b_fdbk[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[13]] /* euler_pid.J[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* euler_pid.rate_wb_b_fdbk[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[14]] /* euler_pid.J[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* euler_pid.rate_wb_b_fdbk[3] DISCRETE */)));
      real_array_create(&tmp43, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* euler_pid.moment_target[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(add_alloc_real_array(tmp40, mul_alloc_real_matrix_product_smart(omc_GSQuad_Utils_hatmap(threadData, tmp41), tmp42)), tmp43);

      array_alloc_scalar_real_array(&tmp44, 3, (modelica_real)(-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* euler_pid.C_wb[1,3] DISCRETE */)), (modelica_real)(-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* euler_pid.C_wb[2,3] DISCRETE */)), (modelica_real)(-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* euler_pid.C_wb[3,3] DISCRETE */)));
      real_array_create(&tmp45, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* euler_pid.att_body_thrust_vec[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp44, tmp45);

      tmp46 = omc_GSQuad_Utils_clip(threadData, (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* euler_pid.att_body_thrust_vec[3] DISCRETE */)), -1.0, 1.0);
      if(!(tmp46 >= -1.0 && tmp46 <= 1.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos(GSQuad.Utils.clip(-euler_pid.att_body_thrust_vec[3], -1.0, 1.0)) outside the domain -1.0 <= %g <= 1.0", tmp46);
        }
      }
      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* euler_pid.lean_angle DISCRETE */) = acos(tmp46);

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* euler_pid.force_target DISCRETE */) = DIVISION_SIM(((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* euler_pid.mass PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* euler_pid.acc_z_target DISCRETE */)),cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* euler_pid.lean_angle DISCRETE */)),"cos(euler_pid.lean_angle)",equationIndexes);

      array_alloc_scalar_real_array(&tmp47, 4, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* euler_pid.force_target DISCRETE */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* euler_pid.moment_target[1] DISCRETE */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* euler_pid.moment_target[2] DISCRETE */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* euler_pid.moment_target[3] DISCRETE */));
      real_array_create(&tmp48, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* euler_pid.fm_target[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)4);
      real_array_copy_data(tmp47, tmp48);

      array_alloc_scalar_real_array(&tmp49, 4, (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[43]] /* euler_pid.pinv_CA[1,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* euler_pid.fm_target[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* euler_pid.pinv_CA[1,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* euler_pid.fm_target[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[45]] /* euler_pid.pinv_CA[1,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* euler_pid.fm_target[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[46]] /* euler_pid.pinv_CA[1,4] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* euler_pid.fm_target[4] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[47]] /* euler_pid.pinv_CA[2,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* euler_pid.fm_target[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[48]] /* euler_pid.pinv_CA[2,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* euler_pid.fm_target[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[49]] /* euler_pid.pinv_CA[2,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* euler_pid.fm_target[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[50]] /* euler_pid.pinv_CA[2,4] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* euler_pid.fm_target[4] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[51]] /* euler_pid.pinv_CA[3,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* euler_pid.fm_target[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[52]] /* euler_pid.pinv_CA[3,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* euler_pid.fm_target[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[53]] /* euler_pid.pinv_CA[3,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* euler_pid.fm_target[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[54]] /* euler_pid.pinv_CA[3,4] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* euler_pid.fm_target[4] DISCRETE */)), (modelica_real)((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[55]] /* euler_pid.pinv_CA[4,1] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* euler_pid.fm_target[1] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[56]] /* euler_pid.pinv_CA[4,2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* euler_pid.fm_target[2] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* euler_pid.pinv_CA[4,3] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* euler_pid.fm_target[3] DISCRETE */)) + ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* euler_pid.pinv_CA[4,4] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* euler_pid.fm_target[4] DISCRETE */)));
      real_array_create(&tmp50, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[101]] /* euler_pid.thrust_target[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)4);
      real_array_copy_data(tmp49, tmp50);

      array_alloc_scalar_real_array(&tmp51, 4, (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[101]] /* euler_pid.thrust_target[1] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* euler_pid.k_eta PARAM */),"euler_pid.k_eta",equationIndexes), (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[102]] /* euler_pid.thrust_target[2] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* euler_pid.k_eta PARAM */),"euler_pid.k_eta",equationIndexes), (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[103]] /* euler_pid.thrust_target[3] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* euler_pid.k_eta PARAM */),"euler_pid.k_eta",equationIndexes), (modelica_real)DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* euler_pid.thrust_target[4] DISCRETE */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* euler_pid.k_eta PARAM */),"euler_pid.k_eta",equationIndexes));
      real_array_create(&tmp52, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* euler_pid.omega_spd_sq_target[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)4);
      real_array_copy_data(tmp51, tmp52);

      tmp54 = ((modelica_integer) 1); tmp55 = 1; tmp56 = ((modelica_integer) 4);
      if(!(((tmp55 > 0) && (tmp54 > tmp56)) || ((tmp55 < 0) && (tmp54 < tmp56))))
      {
        modelica_integer i;
        for(i = ((modelica_integer) 1); in_range_integer(i, tmp54, tmp56); i += tmp55)
        {
          tmp53 = omc_GSQuad_Utils_clip(threadData, (&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* euler_pid.omega_spd_sq_target[1] DISCRETE */)[i - 1], 0.0, real_int_pow(threadData, (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[41]] /* euler_pid.omega_rotor_max PARAM */), 8));
          if(!(tmp53 >= 0.0))
          {
            if (data->simulationInfo->noThrowAsserts) {
              FILE_INFO info = {"",0,0,0,0,0};
              infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
              data->simulationInfo->needToReThrow = 1;
            } else {
              FILE_INFO info = {"",0,0,0,0,0};
              omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
              throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(GSQuad.Utils.clip(euler_pid.omega_spd_sq_target[i], 0.0, euler_pid.omega_rotor_max ^ 8.0)) was %g should be >= 0", tmp53);
            }
          }
          (&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* euler_pid.normalized_ctrl_input[1] DISCRETE */))[i - 1] = DIVISION_SIM(sqrt(tmp53) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* euler_pid.omega_rotor_min PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[41]] /* euler_pid.omega_rotor_max PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* euler_pid.omega_rotor_min PARAM */),"euler_pid.omega_rotor_max - euler_pid.omega_rotor_min",equationIndexes) + (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* euler_pid.omega_rotor_min PARAM */);
        }
      }
    }
  }
  threadData->lastEquationSolved = 200;
}

OMC_DISABLE_OPT
int GSQuad_Components_Controller_functionDAE(DATA *data, threadData_t *threadData)
{
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  GSQuad_Components_Controller_functionLocalKnownVars(data, threadData);
  static void (*const eqFunctions[6])(DATA*, threadData_t*) = {
    GSQuad_Components_Controller_eqFunction_195,
    GSQuad_Components_Controller_eqFunction_196,
    GSQuad_Components_Controller_eqFunction_197,
    GSQuad_Components_Controller_eqFunction_198,
    GSQuad_Components_Controller_eqFunction_199,
    GSQuad_Components_Controller_eqFunction_200
  };
  
  for (int id = 0; id < 6; id++) {
    eqFunctions[id](data, threadData);
  }
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  return 0;
}


int GSQuad_Components_Controller_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  
  return 0;
}


int GSQuad_Components_Controller_functionODE(DATA *data, threadData_t *threadData)
{
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  GSQuad_Components_Controller_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);
extern int _main_OptimizationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);

#include "GSQuad.Components.Controller_12jac.h"
#include "GSQuad.Components.Controller_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks GSQuad_Components_Controller_callback = {
  (int (*)(DATA *, threadData_t *, void *)) GSQuad_Components_Controller_performSimulation,    /* performSimulation */
  (int (*)(DATA *, threadData_t *, void *)) GSQuad_Components_Controller_performQSSSimulation,    /* performQSSSimulation */
  GSQuad_Components_Controller_updateContinuousSystem,    /* updateContinuousSystem */
  GSQuad_Components_Controller_callExternalObjectDestructors,    /* callExternalObjectDestructors */
  NULL,    /* initialNonLinearSystem */
  NULL,    /* initialLinearSystem */
  NULL,    /* initialMixedSystem */
  #if !defined(OMC_NO_STATESELECTION)
  GSQuad_Components_Controller_initializeStateSets,
  #else
  NULL,
  #endif    /* initializeStateSets */
  GSQuad_Components_Controller_initializeDAEmodeData,
  GSQuad_Components_Controller_functionODE,
  GSQuad_Components_Controller_functionAlgebraics,
  GSQuad_Components_Controller_functionDAE,
  GSQuad_Components_Controller_functionLocalKnownVars,
  GSQuad_Components_Controller_input_function,
  GSQuad_Components_Controller_input_function_init,
  GSQuad_Components_Controller_input_function_updateStartValues,
  GSQuad_Components_Controller_data_function,
  GSQuad_Components_Controller_output_function,
  GSQuad_Components_Controller_setc_function,
  GSQuad_Components_Controller_setb_function,
  GSQuad_Components_Controller_function_storeDelayed,
  GSQuad_Components_Controller_function_storeSpatialDistribution,
  GSQuad_Components_Controller_function_initSpatialDistribution,
  GSQuad_Components_Controller_updateBoundVariableAttributes,
  GSQuad_Components_Controller_functionInitialEquations,
  GLOBAL_EQUIDISTANT_HOMOTOPY,
  NULL,
  GSQuad_Components_Controller_functionRemovedInitialEquations,
  GSQuad_Components_Controller_updateBoundParameters,
  GSQuad_Components_Controller_checkForAsserts,
  GSQuad_Components_Controller_function_ZeroCrossingsEquations,
  GSQuad_Components_Controller_function_ZeroCrossings,
  GSQuad_Components_Controller_function_updateRelations,
  GSQuad_Components_Controller_zeroCrossingDescription,
  GSQuad_Components_Controller_relationDescription,
  GSQuad_Components_Controller_function_initSample,
  GSQuad_Components_Controller_INDEX_JAC_A,
  GSQuad_Components_Controller_INDEX_JAC_B,
  GSQuad_Components_Controller_INDEX_JAC_C,
  GSQuad_Components_Controller_INDEX_JAC_D,
  GSQuad_Components_Controller_INDEX_JAC_F,
  GSQuad_Components_Controller_INDEX_JAC_H,
  GSQuad_Components_Controller_initialAnalyticJacobianA,
  GSQuad_Components_Controller_initialAnalyticJacobianB,
  GSQuad_Components_Controller_initialAnalyticJacobianC,
  GSQuad_Components_Controller_initialAnalyticJacobianD,
  GSQuad_Components_Controller_initialAnalyticJacobianF,
  GSQuad_Components_Controller_initialAnalyticJacobianH,
  GSQuad_Components_Controller_functionJacA_column,
  GSQuad_Components_Controller_functionJacB_column,
  GSQuad_Components_Controller_functionJacC_column,
  GSQuad_Components_Controller_functionJacD_column,
  GSQuad_Components_Controller_functionJacF_column,
  GSQuad_Components_Controller_functionJacH_column,
  GSQuad_Components_Controller_linear_model_frame,
  GSQuad_Components_Controller_linear_model_datarecovery_frame,
  GSQuad_Components_Controller_mayer,
  GSQuad_Components_Controller_lagrange,
  GSQuad_Components_Controller_getInputVarIndicesInOptimization,
  GSQuad_Components_Controller_pickUpBoundsForInputsInOptimization,
  GSQuad_Components_Controller_setInputData,
  GSQuad_Components_Controller_getTimeGrid,
  GSQuad_Components_Controller_symbolicInlineSystem,
  GSQuad_Components_Controller_function_initSynchronous,
  GSQuad_Components_Controller_function_updateSynchronous,
  GSQuad_Components_Controller_function_equationsSynchronous,
  GSQuad_Components_Controller_inputNames,
  GSQuad_Components_Controller_dataReconciliationInputNames,
  GSQuad_Components_Controller_dataReconciliationUnmeasuredVariables,
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
void GSQuad_Components_Controller_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &GSQuad_Components_Controller_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "GSQuad.Components.Controller";
  data->modelData->modelFilePrefix = "GSQuad.Components.Controller";
  data->modelData->modelFileName = "MFQuadrotor.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/mhcho/ws/FIRE_CP_Glimpse/examples/GSdrone/model";
  data->modelData->modelGUID = "{c87bba2f-eed8-41e1-882f-9d299384506c}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "GSQuad.Components.Controller_init.c"
    ;
  static const char contents_info[] =
    #include "GSQuad.Components.Controller_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "GSQuad.Components.Controller_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "GSQuad.Components.Controller_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "GSQuad.Components.Controller_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStatesArray = 0;
  data->modelData->nDiscreteReal = 94;
  data->modelData->nVariablesRealArray = 125;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 2;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersRealArray = 63;
  data->modelData->nParametersIntegerArray = 1;
  data->modelData->nParametersBooleanArray = 0;
  data->modelData->nParametersStringArray = 0;
  data->modelData->nParametersReal = 63;
  data->modelData->nParametersInteger = 1;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nAliasRealArray = 31;
  data->modelData->nAliasIntegerArray = 0;
  data->modelData->nAliasBooleanArray = 0;
  data->modelData->nAliasStringArray = 0;
  data->modelData->nInputVars = 27;
  data->modelData->nOutputVars = 4;
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 2;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 3;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 215;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
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
  
    GSQuad_Components_Controller_setupDataStruc(&data, threadData);
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


