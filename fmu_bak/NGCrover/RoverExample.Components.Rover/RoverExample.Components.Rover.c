/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "RoverExample.Components.Rover_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation RoverExample_Components_Rover_performSimulation
#define prefixedName_updateContinuousSystem RoverExample_Components_Rover_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation RoverExample_Components_Rover_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int RoverExample_Components_Rover_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[115]] /* pwm_steering variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[116]] /* pwm_throttle variable */) = data->simulationInfo->inputVars[1];
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[115].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[116].attribute.start;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[115].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[116].attribute.start = data->simulationInfo->inputVars[1];
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[115].info.name;
  names[1] = (char *) data->modelData->realVarsData[116].info.name;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* ax_meas variable */);
  data->simulationInfo->outputVars[1] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* ay_meas variable */);
  data->simulationInfo->outputVars[2] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* az_meas variable */);
  data->simulationInfo->outputVars[3] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[109]] /* mx_meas variable */);
  data->simulationInfo->outputVars[4] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[110]] /* my_meas variable */);
  data->simulationInfo->outputVars[5] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* mz_meas variable */);
  data->simulationInfo->outputVars[6] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[112]] /* p_meas variable */);
  data->simulationInfo->outputVars[7] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[113]] /* phi_meas variable */);
  data->simulationInfo->outputVars[8] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* psi_meas variable */);
  data->simulationInfo->outputVars[9] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[117]] /* q_meas variable */);
  data->simulationInfo->outputVars[10] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[118]] /* r_meas variable */);
  data->simulationInfo->outputVars[11] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[119]] /* rollover_detected variable */);
  data->simulationInfo->outputVars[12] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[234]] /* theta_meas variable */);
  data->simulationInfo->outputVars[13] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[235]] /* vx_meas variable */);
  data->simulationInfo->outputVars[14] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[236]] /* vy_meas variable */);
  data->simulationInfo->outputVars[15] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[237]] /* vz_meas variable */);
  data->simulationInfo->outputVars[16] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[238]] /* x_meas variable */);
  data->simulationInfo->outputVars[17] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[239]] /* y_meas variable */);
  data->simulationInfo->outputVars[18] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[240]] /* z_meas variable */);
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 208
type: ALGORITHM

  gyroatk.timer_count := pre(gyroatk.timer_count);
  $whenCondition1 := pre($whenCondition1);
  $whenCondition1 := sample(1, 0.0, gyroatk.sample_interval);
  when $whenCondition1 then
    gyroatk.timer_count := gyroatk.timer_count + 1;
  end when;
*/
void RoverExample_Components_Rover_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* gyroatk.timer_count DISCRETE */) = (data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = data->simulationInfo->samples[0];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
    {
      (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* gyroatk.timer_count DISCRETE */) = (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* gyroatk.timer_count DISCRETE */) + ((modelica_integer) 1);
    }
  }
  TRACE_POP
}
/*
equation index: 209
type: ALGORITHM

  rover_8d.delta_cmd := pre(rover_8d.delta_cmd);
  rover_8d.D := pre(rover_8d.D);
  rover_3d.delta_cmd := pre(rover_3d.delta_cmd);
  rover_3d.D := pre(rover_3d.D);
  $whenCondition2 := pre($whenCondition2);
  $whenCondition2 := sample(2, 0.0, sample_interval);
  when $whenCondition2 then
    rover_3d.D := 0.0;
    rover_3d.delta_cmd := 0.0;
    rover_8d.D := 0.001 * pwm_throttle - 1.0;
    rover_8d.delta_cmd := 0.002 * delta_max * (pwm_steering - 1500.0);
  end when;
*/
void RoverExample_Components_Rover_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[245]] /* rover_8d.delta_cmd DISCRETE */) = (data->simulationInfo->realVarsPre[245] /* rover_8d.delta_cmd DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[244]] /* rover_8d.D DISCRETE */) = (data->simulationInfo->realVarsPre[244] /* rover_8d.D DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[242]] /* rover_3d.delta_cmd DISCRETE */) = (data->simulationInfo->realVarsPre[242] /* rover_3d.delta_cmd DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[241]] /* rover_3d.D DISCRETE */) = (data->simulationInfo->realVarsPre[241] /* rover_3d.D DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition2 DISCRETE */) = (data->simulationInfo->booleanVarsPre[2] /* $whenCondition2 DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition2 DISCRETE */) = data->simulationInfo->samples[1];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition2 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[2] /* $whenCondition2 DISCRETE */) /* edge */))
    {
      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[241]] /* rover_3d.D DISCRETE */) = 0.0;

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[242]] /* rover_3d.delta_cmd DISCRETE */) = 0.0;

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[244]] /* rover_8d.D DISCRETE */) = (0.001) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[116]] /* pwm_throttle variable */)) - 1.0;

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[245]] /* rover_8d.delta_cmd DISCRETE */) = (0.002) * (((data->simulationInfo->realParameter[8] /* delta_max PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[115]] /* pwm_steering variable */) - 1500.0));
    }
  }
  TRACE_POP
}
/*
equation index: 210
type: ARRAY_CALL_ASSIGN

rover_3d.mag.C_n2b = transpose(RoverExample.Utils.eul2rot({rover_3d.phi, rover_3d.theta, rover_3d.psi}))
*/
void RoverExample_Components_Rover_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
  real_array tmp0;
  real_array tmp1;
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp0, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* rover_3d.phi STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* rover_3d.theta STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */));
  tmp1 = omc_RoverExample_Utils_eul2rot(threadData, tmp0);
  transpose_alloc_real_array(&tmp1, &tmp2);
  real_array_create(&tmp3, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[134]] /* rover_3d.mag.C_n2b[1,1] variable */))[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp2, tmp3);
  TRACE_POP
}
/*
equation index: 211
type: SIMPLE_ASSIGN
rover_3d.my = rover_3d.mag.C_n2b[2,1] * rover_3d.mag.b_earth0 * $cse1 + (-2.0) * rover_3d.mag.C_n2b[2,3] * rover_3d.mag.b_earth0 * $cse2
*/
void RoverExample_Components_Rover_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[144]] /* rover_3d.my variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[137]] /* rover_3d.mag.C_n2b[2,1] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[0] /* $cse1 PARAM */))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[139]] /* rover_3d.mag.C_n2b[2,3] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[1] /* $cse2 PARAM */))));
  TRACE_POP
}
/*
equation index: 212
type: SIMPLE_ASSIGN
rover_3d.mx = rover_3d.mag.C_n2b[1,1] * rover_3d.mag.b_earth0 * $cse1 + (-2.0) * rover_3d.mag.C_n2b[1,3] * rover_3d.mag.b_earth0 * $cse2
*/
void RoverExample_Components_Rover_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[143]] /* rover_3d.mx variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[134]] /* rover_3d.mag.C_n2b[1,1] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[0] /* $cse1 PARAM */))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[136]] /* rover_3d.mag.C_n2b[1,3] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[1] /* $cse2 PARAM */))));
  TRACE_POP
}
/*
equation index: 213
type: SIMPLE_ASSIGN
rover_3d.mz = rover_3d.mag.C_n2b[3,1] * rover_3d.mag.b_earth0 * $cse1 + (-2.0) * rover_3d.mag.C_n2b[3,3] * rover_3d.mag.b_earth0 * $cse2
*/
void RoverExample_Components_Rover_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[145]] /* rover_3d.mz variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[140]] /* rover_3d.mag.C_n2b[3,1] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[0] /* $cse1 PARAM */))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[142]] /* rover_3d.mag.C_n2b[3,3] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[1] /* $cse2 PARAM */))));
  TRACE_POP
}
/*
equation index: 214
type: SIMPLE_ASSIGN
rover_3d.vx = rover_3d.v_max * pre(rover_3d.D)
*/
void RoverExample_Components_Rover_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */) = ((data->simulationInfo->realParameter[60] /* rover_3d.v_max PARAM */)) * ((data->simulationInfo->realVarsPre[241] /* rover_3d.D DISCRETE */));
  TRACE_POP
}
/*
equation index: 215
type: SIMPLE_ASSIGN
rover_3d.delta = pre(rover_3d.delta_cmd)
*/
void RoverExample_Components_Rover_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) = (data->simulationInfo->realVarsPre[242] /* rover_3d.delta_cmd DISCRETE */);
  TRACE_POP
}
/*
equation index: 216
type: SIMPLE_ASSIGN
$whenCondition9 = rover_3d.delta <> 0.0
*/
void RoverExample_Components_Rover_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[9]] /* $whenCondition9 DISCRETE */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) != 0.0);
  TRACE_POP
}
/*
equation index: 217
type: SIMPLE_ASSIGN
$whenCondition8 = rover_3d.delta == 0.0
*/
void RoverExample_Components_Rover_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[8]] /* $whenCondition8 DISCRETE */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) == 0.0);
  TRACE_POP
}
/*
equation index: 218
type: WHEN

when {$whenCondition9} then
  rover_3d.turn_radius = RoverExample.Utils.clip(abs(rover_3d.l_total * cos(rover_3d.delta) / sin(rover_3d.delta)), 0.0, 1000.0);
end when;
*/
void RoverExample_Components_Rover_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[9]] /* $whenCondition9 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[9] /* $whenCondition9 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */) = omc_RoverExample_Utils_clip(threadData, fabs(((data->simulationInfo->realParameter[55] /* rover_3d.l_total PARAM */)) * (DIVISION_SIM(cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */)),sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */)),"sin(rover_3d.delta)",equationIndexes))), 0.0, 1000.0);
  }
  else if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[8]] /* $whenCondition8 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[8] /* $whenCondition8 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */) = 1000.0;
  }
  TRACE_POP
}
/*
equation index: 220
type: SIMPLE_ASSIGN
$whenCondition7 = 9.80665 * $cse40 <= rover_3d.vx ^ 2.0 / rover_3d.turn_radius * $cse41
*/
void RoverExample_Components_Rover_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  modelica_real tmp4;
  modelica_boolean tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  tmp4 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
  tmp6 = (9.80665) * (fabs((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)));
  tmp7 = (1.0) * (fabs((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)));
  relationhysteresis(data, &tmp5, (9.80665) * ((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)), (DIVISION_SIM((tmp4 * tmp4),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius",equationIndexes)) * ((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)), tmp6, tmp7, 13, LessEq, LessEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[7]] /* $whenCondition7 DISCRETE */) = tmp5;
  TRACE_POP
}
/*
equation index: 221
type: SIMPLE_ASSIGN
$whenCondition6 = 9.80665 * $cse40 > rover_3d.vx ^ 2.0 / rover_3d.turn_radius * $cse41
*/
void RoverExample_Components_Rover_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  tmp8 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
  tmp10 = (9.80665) * (fabs((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)));
  tmp11 = (1.0) * (fabs((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)));
  relationhysteresis(data, &tmp9, (9.80665) * ((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)), (DIVISION_SIM((tmp8 * tmp8),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius",equationIndexes)) * ((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)), tmp10, tmp11, 14, Greater, GreaterZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[6]] /* $whenCondition6 DISCRETE */) = tmp9;
  TRACE_POP
}
/*
equation index: 222
type: WHEN

when {$whenCondition7} then
  rover_3d.rollover_detected = 1;
end when;
*/
void RoverExample_Components_Rover_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[7]] /* $whenCondition7 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[7] /* $whenCondition7 DISCRETE */) /* edge */))
  {
    (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* rover_3d.rollover_detected DISCRETE */) = ((modelica_integer) 1);
  }
  else if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[6]] /* $whenCondition6 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[6] /* $whenCondition6 DISCRETE */) /* edge */))
  {
    (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* rover_3d.rollover_detected DISCRETE */) = ((modelica_integer) 0);
  }
  TRACE_POP
}
/*
equation index: 224
type: SIMPLE_ASSIGN
$cse6 = tan(rover_3d.delta)
*/
void RoverExample_Components_Rover_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[103]] /* $cse6 variable */) = tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */));
  TRACE_POP
}
/*
equation index: 225
type: SIMPLE_ASSIGN
rover_3d.r = rover_3d.vx * $cse6 / rover_3d.l_total
*/
void RoverExample_Components_Rover_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[149]] /* rover_3d.r variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[103]] /* $cse6 variable */),(data->simulationInfo->realParameter[55] /* rover_3d.l_total PARAM */),"rover_3d.l_total",equationIndexes));
  TRACE_POP
}
/*
equation index: 226
type: SIMPLE_ASSIGN
$DER.rover_3d.psi = rover_3d.r
*/
void RoverExample_Components_Rover_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* der(rover_3d.psi) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[149]] /* rover_3d.r variable */);
  TRACE_POP
}
/*
equation index: 227
type: SIMPLE_ASSIGN
$cse5 = tan(-rover_3d.delta)
*/
void RoverExample_Components_Rover_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[102]] /* $cse5 variable */) = tan((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */)));
  TRACE_POP
}
/*
equation index: 228
type: SIMPLE_ASSIGN
rover_3d.ay = rover_3d.vx ^ 2.0 * $cse5 / rover_3d.l_total
*/
void RoverExample_Components_Rover_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  modelica_real tmp12;
  tmp12 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[130]] /* rover_3d.ay variable */) = ((tmp12 * tmp12)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[102]] /* $cse5 variable */),(data->simulationInfo->realParameter[55] /* rover_3d.l_total PARAM */),"rover_3d.l_total",equationIndexes));
  TRACE_POP
}
/*
equation index: 229
type: SIMPLE_ASSIGN
$DER.rover_3d.phi = 0.0
*/
void RoverExample_Components_Rover_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* der(rover_3d.phi) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 230
type: SIMPLE_ASSIGN
$DER.rover_3d.theta = 0.0
*/
void RoverExample_Components_Rover_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* der(rover_3d.theta) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 231
type: ARRAY_CALL_ASSIGN

rover_3d.C_n2b = transpose(RoverExample.Utils.eul2rot({rover_3d.phi, rover_3d.theta, mod(rover_3d.psi + 3.14159265, 6.2831853, 4) - 3.14159265}))
*/
void RoverExample_Components_Rover_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  real_array tmp13;
  real_array tmp14;
  real_array tmp15;
  real_array tmp16;
  array_alloc_scalar_real_array(&tmp13, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* rover_3d.phi STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* rover_3d.theta STATE(1) */), (modelica_real)_event_mod_real((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */) + 3.14159265, 6.2831853, ((modelica_integer) 4), data, threadData) - 3.14159265);
  tmp14 = omc_RoverExample_Utils_eul2rot(threadData, tmp13);
  transpose_alloc_real_array(&tmp14, &tmp15);
  real_array_create(&tmp16, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* rover_3d.C_n2b[1,1] variable */))[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp15, tmp16);
  TRACE_POP
}
/*
equation index: 232
type: SIMPLE_ASSIGN
rover_3d.specific_g[1] = 9.80665 * rover_3d.C_n2b[1,3]
*/
void RoverExample_Components_Rover_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[150]] /* rover_3d.specific_g[1] variable */) = (9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[122]] /* rover_3d.C_n2b[1,3] variable */));
  TRACE_POP
}
/*
equation index: 233
type: SIMPLE_ASSIGN
rover_3d.specific_g[3] = 9.80665 * rover_3d.C_n2b[3,3]
*/
void RoverExample_Components_Rover_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[152]] /* rover_3d.specific_g[3] variable */) = (9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[128]] /* rover_3d.C_n2b[3,3] variable */));
  TRACE_POP
}
/*
equation index: 234
type: SIMPLE_ASSIGN
rover_3d.specific_g[2] = 9.80665 * rover_3d.C_n2b[2,3]
*/
void RoverExample_Components_Rover_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[151]] /* rover_3d.specific_g[2] variable */) = (9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[125]] /* rover_3d.C_n2b[2,3] variable */));
  TRACE_POP
}
/*
equation index: 235
type: ARRAY_CALL_ASSIGN

rover_8d.mag.C_n2b = transpose(RoverExample.Utils.eul2rot({rover_8d.phi, rover_8d.theta, rover_8d.psi}))
*/
void RoverExample_Components_Rover_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  real_array tmp17;
  real_array tmp18;
  real_array tmp19;
  real_array tmp20;
  array_alloc_scalar_real_array(&tmp17, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  tmp18 = omc_RoverExample_Utils_eul2rot(threadData, tmp17);
  transpose_alloc_real_array(&tmp18, &tmp19);
  real_array_create(&tmp20, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[199]] /* rover_8d.mag.C_n2b[1,1] variable */))[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp19, tmp20);
  TRACE_POP
}
/*
equation index: 236
type: SIMPLE_ASSIGN
rover_8d.mag.b_earth[2] = rover_8d.mag.C_n2b[2,1] * rover_8d.mag.b_earth0 * $cse7 + (-2.0) * rover_8d.mag.C_n2b[2,3] * rover_8d.mag.b_earth0 * $cse8
*/
void RoverExample_Components_Rover_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[209]] /* rover_8d.mag.b_earth[2] variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[202]] /* rover_8d.mag.C_n2b[2,1] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[5] /* $cse7 PARAM */))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[204]] /* rover_8d.mag.C_n2b[2,3] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[6] /* $cse8 PARAM */))));
  TRACE_POP
}
/*
equation index: 237
type: SIMPLE_ASSIGN
rover_8d.mag.b_earth[1] = rover_8d.mag.C_n2b[1,1] * rover_8d.mag.b_earth0 * $cse7 + (-2.0) * rover_8d.mag.C_n2b[1,3] * rover_8d.mag.b_earth0 * $cse8
*/
void RoverExample_Components_Rover_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[208]] /* rover_8d.mag.b_earth[1] variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[199]] /* rover_8d.mag.C_n2b[1,1] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[5] /* $cse7 PARAM */))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[201]] /* rover_8d.mag.C_n2b[1,3] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[6] /* $cse8 PARAM */))));
  TRACE_POP
}
/*
equation index: 238
type: SIMPLE_ASSIGN
rover_8d.mag.b_earth[3] = rover_8d.mag.C_n2b[3,1] * rover_8d.mag.b_earth0 * $cse7 + (-2.0) * rover_8d.mag.C_n2b[3,3] * rover_8d.mag.b_earth0 * $cse8
*/
void RoverExample_Components_Rover_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[210]] /* rover_8d.mag.b_earth[3] variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[205]] /* rover_8d.mag.C_n2b[3,1] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[5] /* $cse7 PARAM */))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[207]] /* rover_8d.mag.C_n2b[3,3] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[6] /* $cse8 PARAM */))));
  TRACE_POP
}
/*
equation index: 239
type: ARRAY_CALL_ASSIGN

rover_8d.emi.b_wire = RoverExample.Utils.cross3(rover_8d.emi.wire_dir, rover_8d.emi.x_wire) * 1.9999999999999996e-7 * rover_8d.Iq / rover_8d.emi.dist_wire ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
  real_array tmp21;
  real_array tmp22;
  modelica_real tmp23;
  real_array tmp24;
  real_array_create(&tmp21, ((modelica_real*)&((&data->simulationInfo->realParameter[93] /* rover_8d.emi.wire_dir[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_create(&tmp22, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* rover_8d.emi.x_wire[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  tmp23 = (data->simulationInfo->realParameter[90] /* rover_8d.emi.dist_wire PARAM */);
  real_array_create(&tmp24, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[188]] /* rover_8d.emi.b_wire[1] variable */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_copy_data(mul_alloc_real_array_scalar(omc_RoverExample_Utils_cross3(threadData, tmp21, tmp22), DIVISION_SIM((1.9999999999999996e-7) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */)),(tmp23 * tmp23),"rover_8d.emi.dist_wire ^ 2.0",equationIndexes)), tmp24);
  TRACE_POP
}
/*
equation index: 240
type: SIMPLE_ASSIGN
my_meas = rover_8d.mag.b_earth[2] + rover_8d.emi.b_wire[2]
*/
void RoverExample_Components_Rover_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[110]] /* my_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[209]] /* rover_8d.mag.b_earth[2] variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[189]] /* rover_8d.emi.b_wire[2] variable */);
  TRACE_POP
}
/*
equation index: 241
type: SIMPLE_ASSIGN
mz_meas = rover_8d.mag.b_earth[3] + rover_8d.emi.b_wire[3]
*/
void RoverExample_Components_Rover_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* mz_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[210]] /* rover_8d.mag.b_earth[3] variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[190]] /* rover_8d.emi.b_wire[3] variable */);
  TRACE_POP
}
/*
equation index: 242
type: SIMPLE_ASSIGN
mx_meas = rover_8d.mag.b_earth[1] + rover_8d.emi.b_wire[1]
*/
void RoverExample_Components_Rover_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[109]] /* mx_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[208]] /* rover_8d.mag.b_earth[1] variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[188]] /* rover_8d.emi.b_wire[1] variable */);
  TRACE_POP
}
/*
equation index: 243
type: SIMPLE_ASSIGN
$DER.rover_8d.delta = (pre(rover_8d.delta_cmd) - rover_8d.delta) / rover_8d.tau_servo
*/
void RoverExample_Components_Rover_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* der(rover_8d.delta) STATE_DER */) = DIVISION_SIM((data->simulationInfo->realVarsPre[245] /* rover_8d.delta_cmd DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */),(data->simulationInfo->realParameter[125] /* rover_8d.tau_servo PARAM */),"rover_8d.tau_servo",equationIndexes);
  TRACE_POP
}
/*
equation index: 244
type: SIMPLE_ASSIGN
rover_8d.vx_rl = rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r
*/
void RoverExample_Components_Rover_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}
/*
equation index: 245
type: SIMPLE_ASSIGN
$cse27 = tanh(abs(rover_8d.vx_rl))
*/
void RoverExample_Components_Rover_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */) = tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)));
  TRACE_POP
}
/*
equation index: 246
type: SIMPLE_ASSIGN
$cse26 = RoverExample.Utils.clip($cse27, 0.001, 1.0)
*/
void RoverExample_Components_Rover_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */), 0.001, 1.0);
  TRACE_POP
}
/*
equation index: 247
type: SIMPLE_ASSIGN
rover_8d.vy_rr = rover_8d.vy - rover_8d.l_rear * rover_8d.r
*/
void RoverExample_Components_Rover_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) - (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}
/*
equation index: 248
type: SIMPLE_ASSIGN
$cse28 = tanh(abs(rover_8d.vy_rr))
*/
void RoverExample_Components_Rover_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* $cse28 variable */) = tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */)));
  TRACE_POP
}
/*
equation index: 249
type: SIMPLE_ASSIGN
rover_8d.vx_rr = rover_8d.vx + (-0.5) * rover_8d.tw * rover_8d.r
*/
void RoverExample_Components_Rover_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}
/*
equation index: 250
type: SIMPLE_ASSIGN
$cse31 = tanh(abs(rover_8d.vx_rr))
*/
void RoverExample_Components_Rover_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */) = tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)));
  TRACE_POP
}
/*
equation index: 251
type: SIMPLE_ASSIGN
$cse30 = RoverExample.Utils.clip($cse31, 0.001, 1.0)
*/
void RoverExample_Components_Rover_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */), 0.001, 1.0);
  TRACE_POP
}
/*
equation index: 252
type: SIMPLE_ASSIGN
$DER.rover_8d.phi = rover_8d.p
*/
void RoverExample_Components_Rover_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* der(rover_8d.phi) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */);
  TRACE_POP
}
/*
equation index: 253
type: SIMPLE_ASSIGN
$DER.rover_8d.theta = 0.0
*/
void RoverExample_Components_Rover_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* der(rover_8d.theta) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 254
type: SIMPLE_ASSIGN
$DER.rover_8d.psi = rover_8d.r
*/
void RoverExample_Components_Rover_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* der(rover_8d.psi) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */);
  TRACE_POP
}
/*
equation index: 255
type: SIMPLE_ASSIGN
rover_8d.Ploss = rover_8d.Iq ^ 2.0 * rover_8d.R_phi
*/
void RoverExample_Components_Rover_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  modelica_real tmp25;
  tmp25 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[175]] /* rover_8d.Ploss variable */) = ((tmp25 * tmp25)) * ((data->simulationInfo->realParameter[77] /* rover_8d.R_phi PARAM */));
  TRACE_POP
}
/*
equation index: 256
type: ARRAY_CALL_ASSIGN

rover_8d.C_n2b = transpose(RoverExample.Utils.eul2rot({rover_8d.phi, rover_8d.theta, mod(rover_8d.psi + 3.14159265, 6.2831853, 0) - 3.14159265}))
*/
void RoverExample_Components_Rover_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
  real_array tmp26;
  real_array tmp27;
  real_array tmp28;
  real_array tmp29;
  array_alloc_scalar_real_array(&tmp26, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */), (modelica_real)_event_mod_real((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */) + 3.14159265, 6.2831853, ((modelica_integer) 0), data, threadData) - 3.14159265);
  tmp27 = omc_RoverExample_Utils_eul2rot(threadData, tmp26);
  transpose_alloc_real_array(&tmp27, &tmp28);
  real_array_create(&tmp29, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[154]] /* rover_8d.C_n2b[1,1] variable */))[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp28, tmp29);
  TRACE_POP
}
/*
equation index: 257
type: SIMPLE_ASSIGN
rover_8d.specific_g[1] = 9.80665 * rover_8d.C_n2b[1,3]
*/
void RoverExample_Components_Rover_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[216]] /* rover_8d.specific_g[1] variable */) = (9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[156]] /* rover_8d.C_n2b[1,3] variable */));
  TRACE_POP
}
/*
equation index: 258
type: SIMPLE_ASSIGN
rover_8d.specific_g[2] = 9.80665 * rover_8d.C_n2b[2,3]
*/
void RoverExample_Components_Rover_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[217]] /* rover_8d.specific_g[2] variable */) = (9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[159]] /* rover_8d.C_n2b[2,3] variable */));
  TRACE_POP
}
/*
equation index: 259
type: SIMPLE_ASSIGN
az_meas = (-9.80665) * rover_8d.C_n2b[3,3]
*/
void RoverExample_Components_Rover_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* az_meas variable */) = (-9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[162]] /* rover_8d.C_n2b[3,3] variable */));
  TRACE_POP
}
/*
equation index: 260
type: SIMPLE_ASSIGN
psi_meas = -3.14159265 + mod(rover_8d.psi + 3.14159265, 6.2831853, 0)
*/
void RoverExample_Components_Rover_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* psi_meas variable */) = -3.14159265 + _event_mod_real((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */) + 3.14159265, 6.2831853, ((modelica_integer) 0), data, threadData);
  TRACE_POP
}
/*
equation index: 261
type: SIMPLE_ASSIGN
p_meas = rover_8d.p
*/
void RoverExample_Components_Rover_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[112]] /* p_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */);
  TRACE_POP
}
/*
equation index: 262
type: SIMPLE_ASSIGN
theta_meas = rover_8d.theta
*/
void RoverExample_Components_Rover_eqFunction_262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,262};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[234]] /* theta_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */);
  TRACE_POP
}
/*
equation index: 263
type: SIMPLE_ASSIGN
phi_meas = rover_8d.phi
*/
void RoverExample_Components_Rover_eqFunction_263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,263};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[113]] /* phi_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */);
  TRACE_POP
}
/*
equation index: 264
type: SIMPLE_ASSIGN
vy_meas = rover_8d.vy
*/
void RoverExample_Components_Rover_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,264};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[236]] /* vy_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */);
  TRACE_POP
}
/*
equation index: 265
type: SIMPLE_ASSIGN
vx_meas = rover_8d.vx
*/
void RoverExample_Components_Rover_eqFunction_265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,265};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[235]] /* vx_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */);
  TRACE_POP
}
/*
equation index: 266
type: SIMPLE_ASSIGN
y_meas = rover_8d.y
*/
void RoverExample_Components_Rover_eqFunction_266(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,266};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[239]] /* y_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* rover_8d.y STATE(1) */);
  TRACE_POP
}
/*
equation index: 267
type: SIMPLE_ASSIGN
x_meas = rover_8d.x
*/
void RoverExample_Components_Rover_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[238]] /* x_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* rover_8d.x STATE(1) */);
  TRACE_POP
}
/*
equation index: 268
type: SIMPLE_ASSIGN
$whenCondition5 = rover_8d.delta <> 0.0
*/
void RoverExample_Components_Rover_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[5]] /* $whenCondition5 DISCRETE */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */) != 0.0);
  TRACE_POP
}
/*
equation index: 269
type: SIMPLE_ASSIGN
$whenCondition4 = rover_8d.delta == 0.0
*/
void RoverExample_Components_Rover_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[4]] /* $whenCondition4 DISCRETE */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */) == 0.0);
  TRACE_POP
}
/*
equation index: 270
type: WHEN

when {$whenCondition5} then
  rover_8d.turn_radius = RoverExample.Utils.clip(abs(rover_8d.l_total * cos(rover_8d.delta) / sin(rover_8d.delta)), 0.0, 1000.0);
end when;
*/
void RoverExample_Components_Rover_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[5]] /* $whenCondition5 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[5] /* $whenCondition5 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[246]] /* rover_8d.turn_radius DISCRETE */) = omc_RoverExample_Utils_clip(threadData, fabs(((data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */)) * (DIVISION_SIM(cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)),sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)),"sin(rover_8d.delta)",equationIndexes))), 0.0, 1000.0);
  }
  else if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[4]] /* $whenCondition4 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[4] /* $whenCondition4 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[246]] /* rover_8d.turn_radius DISCRETE */) = 1000.0;
  }
  TRACE_POP
}
/*
equation index: 272
type: SIMPLE_ASSIGN
$whenCondition10 = rover_8d.lambda > 6.2831853
*/
void RoverExample_Components_Rover_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
  modelica_boolean tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  tmp31 = 1.0;
  tmp32 = 6.2831853;
  relationhysteresis(data, &tmp30, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */), 6.2831853, tmp31, tmp32, 0, Greater, GreaterZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition10 DISCRETE */) = tmp30;
  TRACE_POP
}
/*
equation index: 273
type: SIMPLE_ASSIGN
rover_8d.omega = 0.25 * (rover_8d.omega_fl - ((-rover_8d.omega_rl) - rover_8d.omega_rr - rover_8d.omega_fr)) * rover_8d.gratio
*/
void RoverExample_Components_Rover_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* rover_8d.omega DUMMY_STATE */) = (0.25) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* rover_8d.omega_fl STATE(1) */) - ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* rover_8d.omega_rl STATE(1) */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* rover_8d.omega_rr STATE(1) */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* rover_8d.omega_fr STATE(1) */))) * ((data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */)));
  TRACE_POP
}
/*
equation index: 274
type: SIMPLE_ASSIGN
rover_8d.Pmech = rover_8d.Kt_q * rover_8d.Iq * rover_8d.omega
*/
void RoverExample_Components_Rover_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[176]] /* rover_8d.Pmech variable */) = ((data->simulationInfo->realParameter[71] /* rover_8d.Kt_q PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* rover_8d.omega DUMMY_STATE */)));
  TRACE_POP
}
/*
equation index: 275
type: SIMPLE_ASSIGN
$DER.rover_8d.lambda = rover_8d.omega
*/
void RoverExample_Components_Rover_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* der(rover_8d.lambda) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* rover_8d.omega DUMMY_STATE */);
  TRACE_POP
}
/*
equation index: 276
type: SIMPLE_ASSIGN
$cse38 = cos((gyroatk.w_ac - gyroatk.w_d) * gyroatk.sample_interval * (*Real*)(pre(gyroatk.timer_count)) - gyroatk.Phi_ac)
*/
void RoverExample_Components_Rover_eqFunction_276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,276};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[100]] /* $cse38 variable */) = cos(((data->simulationInfo->realParameter[47] /* gyroatk.w_ac PARAM */) - (data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */)) * (((data->simulationInfo->realParameter[42] /* gyroatk.sample_interval PARAM */)) * (((modelica_real)(data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */)))) - (data->simulationInfo->realParameter[17] /* gyroatk.Phi_ac PARAM */));
  TRACE_POP
}
/*
equation index: 277
type: SIMPLE_ASSIGN
gyroatk.omega_yaw_false = 0.5 * gyroatk.l_g * gyroatk.w_d * (gyroatk.X_ac * $cse38 + gyroatk.X_d * $cse39) / gyroatk.dis_d
*/
void RoverExample_Components_Rover_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,277};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* gyroatk.omega_yaw_false variable */) = (0.5) * (((data->simulationInfo->realParameter[33] /* gyroatk.l_g PARAM */)) * (((data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[21] /* gyroatk.X_ac PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[100]] /* $cse38 variable */)) + ((data->simulationInfo->realParameter[24] /* gyroatk.X_d PARAM */)) * ((data->simulationInfo->realParameter[2] /* $cse39 PARAM */)),(data->simulationInfo->realParameter[27] /* gyroatk.dis_d PARAM */),"gyroatk.dis_d",equationIndexes))));
  TRACE_POP
}
/*
equation index: 278
type: SIMPLE_ASSIGN
r_meas = rover_8d.r + gyroatk.omega_yaw_false
*/
void RoverExample_Components_Rover_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[118]] /* r_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* gyroatk.omega_yaw_false variable */);
  TRACE_POP
}
/*
equation index: 279
type: SIMPLE_ASSIGN
$cse37 = cos(rover_8d.phi)
*/
void RoverExample_Components_Rover_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,279};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* $cse37 variable */) = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */));
  TRACE_POP
}
/*
equation index: 280
type: SIMPLE_ASSIGN
$cse36 = sin(rover_8d.phi)
*/
void RoverExample_Components_Rover_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* $cse36 variable */) = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */));
  TRACE_POP
}
/*
equation index: 281
type: SIMPLE_ASSIGN
$cse35 = sin(-rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */) = sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)));
  TRACE_POP
}
/*
equation index: 282
type: SIMPLE_ASSIGN
$cse34 = cos(-rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */) = cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)));
  TRACE_POP
}
/*
equation index: 283
type: SIMPLE_ASSIGN
$cse33 = sin(rover_8d.psi)
*/
void RoverExample_Components_Rover_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* $cse33 variable */) = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  TRACE_POP
}
/*
equation index: 284
type: SIMPLE_ASSIGN
$cse32 = cos(rover_8d.psi)
*/
void RoverExample_Components_Rover_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* $cse32 variable */) = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  TRACE_POP
}
/*
equation index: 285
type: SIMPLE_ASSIGN
$DER.rover_8d.y = rover_8d.vx * $cse33 + rover_8d.vy * $cse32
*/
void RoverExample_Components_Rover_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* der(rover_8d.y) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* $cse33 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* $cse32 variable */));
  TRACE_POP
}
/*
equation index: 286
type: SIMPLE_ASSIGN
$DER.rover_8d.x = rover_8d.vx * $cse32 - rover_8d.vy * $cse33
*/
void RoverExample_Components_Rover_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* der(rover_8d.x) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* $cse32 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* $cse33 variable */)));
  TRACE_POP
}
/*
equation index: 287
type: SIMPLE_ASSIGN
rover_8d.alpha_rr_bnd = RoverExample.Utils.clip(rover_8d.alpha_rr, rover_8d.alpha_min, rover_8d.alpha_max)
*/
void RoverExample_Components_Rover_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[181]] /* rover_8d.alpha_rr_bnd variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* rover_8d.alpha_rr STATE(1) */), (data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */), (data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
  TRACE_POP
}
/*
equation index: 288
type: SIMPLE_ASSIGN
$cse29 = tan(rover_8d.alpha_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */) = tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[181]] /* rover_8d.alpha_rr_bnd variable */));
  TRACE_POP
}
/*
equation index: 289
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rr = (-abs(rover_8d.vx_rr)) * $cse29 / (rover_8d.Lrely * $cse30) - $cse28 * rover_8d.vy_rr / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* der(rover_8d.alpha_rr) STATE_DER */) = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */),((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */)),"rover_8d.Lrely * $cse30",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* $cse28 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely",equationIndexes)));
  TRACE_POP
}
/*
equation index: 290
type: SIMPLE_ASSIGN
rover_8d.alpha_rl_bnd = RoverExample.Utils.clip(rover_8d.alpha_rl, rover_8d.alpha_min, rover_8d.alpha_max)
*/
void RoverExample_Components_Rover_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[180]] /* rover_8d.alpha_rl_bnd variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* rover_8d.alpha_rl STATE(1) */), (data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */), (data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
  TRACE_POP
}
/*
equation index: 291
type: SIMPLE_ASSIGN
$cse25 = tan(rover_8d.alpha_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */) = tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[180]] /* rover_8d.alpha_rl_bnd variable */));
  TRACE_POP
}
/*
equation index: 292
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rl = (-abs(rover_8d.vx_rl)) * $cse25 / ($cse26 * rover_8d.Lrely) - $cse28 * rover_8d.vy_rr / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* der(rover_8d.alpha_rl) STATE_DER */) = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse26 * rover_8d.Lrely",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* $cse28 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely",equationIndexes)));
  TRACE_POP
}
/*
equation index: 293
type: SIMPLE_ASSIGN
rover_8d.alpha_fr_bnd = RoverExample.Utils.clip(rover_8d.alpha_fr, rover_8d.alpha_min, rover_8d.alpha_max)
*/
void RoverExample_Components_Rover_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* rover_8d.alpha_fr_bnd variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* rover_8d.alpha_fr STATE(1) */), (data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */), (data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
  TRACE_POP
}
/*
equation index: 294
type: SIMPLE_ASSIGN
$cse21 = tan(rover_8d.alpha_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */) = tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* rover_8d.alpha_fr_bnd variable */));
  TRACE_POP
}
/*
equation index: 295
type: SIMPLE_ASSIGN
rover_8d.alpha_fl_bnd = RoverExample.Utils.clip(rover_8d.alpha_fl, rover_8d.alpha_min, rover_8d.alpha_max)
*/
void RoverExample_Components_Rover_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[178]] /* rover_8d.alpha_fl_bnd variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* rover_8d.alpha_fl STATE(1) */), (data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */), (data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
  TRACE_POP
}
/*
equation index: 296
type: SIMPLE_ASSIGN
$cse17 = tan(rover_8d.alpha_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */) = tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[178]] /* rover_8d.alpha_fl_bnd variable */));
  TRACE_POP
}
/*
equation index: 297
type: SIMPLE_ASSIGN
$cse16 = sin(rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */) = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */));
  TRACE_POP
}
/*
equation index: 298
type: SIMPLE_ASSIGN
$cse15 = cos(rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */) = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */));
  TRACE_POP
}
/*
equation index: 299
type: SIMPLE_ASSIGN
rover_8d.vy_fr = $cse15 * (rover_8d.vy + rover_8d.l_front * rover_8d.r) - $cse16 * rover_8d.vx_rr
*/
void RoverExample_Components_Rover_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)));
  TRACE_POP
}
/*
equation index: 300
type: SIMPLE_ASSIGN
$cse24 = tanh(abs(rover_8d.vy_fr))
*/
void RoverExample_Components_Rover_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* $cse24 variable */) = tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */)));
  TRACE_POP
}
/*
equation index: 301
type: SIMPLE_ASSIGN
rover_8d.vx_fr = $cse15 * rover_8d.vx_rr + $cse16 * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}
/*
equation index: 302
type: SIMPLE_ASSIGN
$cse23 = tanh(abs(rover_8d.vx_fr))
*/
void RoverExample_Components_Rover_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */) = tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */)));
  TRACE_POP
}
/*
equation index: 303
type: SIMPLE_ASSIGN
$cse22 = RoverExample.Utils.clip($cse23, 0.001, 1.0)
*/
void RoverExample_Components_Rover_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */), 0.001, 1.0);
  TRACE_POP
}
/*
equation index: 304
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fr = (-abs(rover_8d.vx_fr)) * $cse21 / (rover_8d.Lrely * $cse22) - $cse24 * rover_8d.vy_fr / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* der(rover_8d.alpha_fr) STATE_DER */) = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */),((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */)),"rover_8d.Lrely * $cse22",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* $cse24 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely",equationIndexes)));
  TRACE_POP
}
/*
equation index: 305
type: SIMPLE_ASSIGN
rover_8d.vy_fl = $cse15 * (rover_8d.vy + rover_8d.l_front * rover_8d.r) - $cse16 * rover_8d.vx_rl
*/
void RoverExample_Components_Rover_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)));
  TRACE_POP
}
/*
equation index: 306
type: SIMPLE_ASSIGN
$cse20 = tanh(abs(rover_8d.vy_fl))
*/
void RoverExample_Components_Rover_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* $cse20 variable */) = tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */)));
  TRACE_POP
}
/*
equation index: 307
type: SIMPLE_ASSIGN
rover_8d.vx_fl = $cse15 * rover_8d.vx_rl + $cse16 * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,307};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}
/*
equation index: 308
type: SIMPLE_ASSIGN
$cse19 = tanh(abs(rover_8d.vx_fl))
*/
void RoverExample_Components_Rover_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,308};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */) = tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */)));
  TRACE_POP
}
/*
equation index: 309
type: SIMPLE_ASSIGN
$cse18 = RoverExample.Utils.clip($cse19, 0.001, 1.0)
*/
void RoverExample_Components_Rover_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */), 0.001, 1.0);
  TRACE_POP
}
/*
equation index: 310
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fl = (-abs(rover_8d.vx_fl)) * $cse17 / (rover_8d.Lrely * $cse18) - $cse20 * rover_8d.vy_fl / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* der(rover_8d.alpha_fl) STATE_DER */) = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */),((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */)),"rover_8d.Lrely * $cse18",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* $cse20 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely",equationIndexes)));
  TRACE_POP
}
/*
equation index: 311
type: SIMPLE_ASSIGN
rover_8d.kappa_rr_bnd = RoverExample.Utils.clip(rover_8d.kappa_rr, rover_8d.kappa_min, rover_8d.kappa_max)
*/
void RoverExample_Components_Rover_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */), (data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */), (data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
  TRACE_POP
}
/*
equation index: 312
type: SIMPLE_ASSIGN
rover_8d.vs_rr = rover_8d.vx_rr * sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,312};
  modelica_real tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  tmp33 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  tmp34 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */);
  tmp35 = (tmp33 * tmp33) + (tmp34 * tmp34);
  if(!(tmp35 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0) was %g should be >= 0", tmp35);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (sqrt(tmp35));
  TRACE_POP
}
/*
equation index: 313
type: SIMPLE_ASSIGN
rover_8d.mu_rr = RoverExample.Utils.clip(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rr), 0.0, rover_8d.mu0)
*/
void RoverExample_Components_Rover_eqFunction_313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,313};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */) = omc_RoverExample_Utils_clip(threadData, ((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */)))), 0.0, (data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
  TRACE_POP
}
/*
equation index: 314
type: SIMPLE_ASSIGN
rover_8d.kappa_rl_bnd = RoverExample.Utils.clip(rover_8d.kappa_rl, rover_8d.kappa_min, rover_8d.kappa_max)
*/
void RoverExample_Components_Rover_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */), (data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */), (data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
  TRACE_POP
}
/*
equation index: 315
type: SIMPLE_ASSIGN
rover_8d.vs_rl = rover_8d.vx_rl * sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,315};
  modelica_real tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  tmp36 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  tmp37 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */);
  tmp38 = (tmp36 * tmp36) + (tmp37 * tmp37);
  if(!(tmp38 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0) was %g should be >= 0", tmp38);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (sqrt(tmp38));
  TRACE_POP
}
/*
equation index: 316
type: SIMPLE_ASSIGN
rover_8d.mu_rl = RoverExample.Utils.clip(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rl), 0.0, rover_8d.mu0)
*/
void RoverExample_Components_Rover_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */) = omc_RoverExample_Utils_clip(threadData, ((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */)))), 0.0, (data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
  TRACE_POP
}
/*
equation index: 317
type: SIMPLE_ASSIGN
rover_8d.kappa_fr_bnd = RoverExample.Utils.clip(rover_8d.kappa_fr, rover_8d.kappa_min, rover_8d.kappa_max)
*/
void RoverExample_Components_Rover_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */), (data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */), (data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
  TRACE_POP
}
/*
equation index: 318
type: SIMPLE_ASSIGN
rover_8d.vs_fr = rover_8d.vx_rr * sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  modelica_real tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  tmp39 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  tmp40 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */);
  tmp41 = (tmp39 * tmp39) + (tmp40 * tmp40);
  if(!(tmp41 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0) was %g should be >= 0", tmp41);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (sqrt(tmp41));
  TRACE_POP
}
/*
equation index: 319
type: SIMPLE_ASSIGN
rover_8d.mu_fr = RoverExample.Utils.clip(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fr), 0.0, rover_8d.mu0)
*/
void RoverExample_Components_Rover_eqFunction_319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,319};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */) = omc_RoverExample_Utils_clip(threadData, ((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */)))), 0.0, (data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
  TRACE_POP
}
/*
equation index: 320
type: SIMPLE_ASSIGN
rover_8d.kappa_fl_bnd = RoverExample.Utils.clip(rover_8d.kappa_fl, rover_8d.kappa_min, rover_8d.kappa_max)
*/
void RoverExample_Components_Rover_eqFunction_320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,320};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */), (data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */), (data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
  TRACE_POP
}
/*
equation index: 321
type: SIMPLE_ASSIGN
rover_8d.vs_fl = rover_8d.vx_rl * sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_321(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,321};
  modelica_real tmp42;
  modelica_real tmp43;
  modelica_real tmp44;
  tmp42 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  tmp43 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */);
  tmp44 = (tmp42 * tmp42) + (tmp43 * tmp43);
  if(!(tmp44 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0) was %g should be >= 0", tmp44);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (sqrt(tmp44));
  TRACE_POP
}
/*
equation index: 322
type: SIMPLE_ASSIGN
rover_8d.mu_fl = RoverExample.Utils.clip(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fl), 0.0, rover_8d.mu0)
*/
void RoverExample_Components_Rover_eqFunction_322(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,322};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */) = omc_RoverExample_Utils_clip(threadData, ((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */)))), 0.0, (data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
  TRACE_POP
}
void RoverExample_Components_Rover_eqFunction_323(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_324(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_325(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_326(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_327(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_328(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_329(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_330(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_331(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_332(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_333(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_334(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_335(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_336(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_337(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_338(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_339(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_340(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_344(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_343(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_342(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_341(DATA*, threadData_t*);
/*
equation index: 345
indexNonlinear: 1
type: NONLINEAR

vars: {rover_8d.fz_fr, rover_8d.fz_rr, rover_8d.fz_rl, rover_8d.fz_fl}
eqns: {323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 344, 343, 342, 341}
*/
void RoverExample_Components_Rover_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,345};
  int retValue;
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving nonlinear system 345 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */);
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[1] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */);
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[2] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */);
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[3] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */);
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,345};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 345 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */) = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */) = data->simulationInfo->nonlinearSystemData[1].nlsx[1];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */) = data->simulationInfo->nonlinearSystemData[1].nlsx[2];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */) = data->simulationInfo->nonlinearSystemData[1].nlsx[3];
  TRACE_POP
}
/*
equation index: 346
type: SIMPLE_ASSIGN
$DER.rover_8d.vx = rover_8d.vy * rover_8d.r + rover_8d.ax
*/
void RoverExample_Components_Rover_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,346};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* der(rover_8d.vx) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */);
  TRACE_POP
}
/*
equation index: 347
type: SIMPLE_ASSIGN
ax_meas = rover_8d.ax - rover_8d.specific_g[1]
*/
void RoverExample_Components_Rover_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,347};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* ax_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[216]] /* rover_8d.specific_g[1] variable */);
  TRACE_POP
}
/*
equation index: 348
type: SIMPLE_ASSIGN
$DER.rover_8d.p = (rover_8d.mass_sprung * (9.80665 * $cse36 - rover_8d.ay * $cse37) * rover_8d.hs + (-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.I_xx
*/
void RoverExample_Components_Rover_eqFunction_348(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,348};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* der(rover_8d.p) STATE_DER */) = DIVISION_SIM((((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((9.80665) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* $cse36 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* $cse37 variable */))))) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[65] /* rover_8d.I_xx PARAM */),"rover_8d.I_xx",equationIndexes);
  TRACE_POP
}
/*
equation index: 349
type: SIMPLE_ASSIGN
ay_meas = rover_8d.ay - rover_8d.specific_g[2]
*/
void RoverExample_Components_Rover_eqFunction_349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,349};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* ay_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[217]] /* rover_8d.specific_g[2] variable */);
  TRACE_POP
}
/*
equation index: 350
type: SIMPLE_ASSIGN
$whenCondition3 = rover_8d.Fz_fl <= 1.5 or rover_8d.Fz_fr <= 1.5 or rover_8d.Fz_rl <= 1.5 or rover_8d.Fz_rr <= 1.5
*/
void RoverExample_Components_Rover_eqFunction_350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,350};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  tmp1 = 1.0;
  tmp2 = 1.5;
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */), 1.5, tmp1, tmp2, 7, LessEq, LessEqZC);
  tmp4 = 1.0;
  tmp5 = 1.5;
  relationhysteresis(data, &tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */), 1.5, tmp4, tmp5, 8, LessEq, LessEqZC);
  tmp7 = 1.0;
  tmp8 = 1.5;
  relationhysteresis(data, &tmp6, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */), 1.5, tmp7, tmp8, 9, LessEq, LessEqZC);
  tmp10 = 1.0;
  tmp11 = 1.5;
  relationhysteresis(data, &tmp9, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */), 1.5, tmp10, tmp11, 10, LessEq, LessEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[3]] /* $whenCondition3 DISCRETE */) = (((tmp0 || tmp3) || tmp6) || tmp9);
  TRACE_POP
}
/*
equation index: 351
type: WHEN

when {$whenCondition3} then
  rover_8d.rollover_detected = 1;
end when;
*/
void RoverExample_Components_Rover_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[3]] /* $whenCondition3 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[3] /* $whenCondition3 DISCRETE */) /* edge */))
  {
    (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* rover_8d.rollover_detected DISCRETE */) = ((modelica_integer) 1);
  }
  TRACE_POP
}
/*
equation index: 352
type: SIMPLE_ASSIGN
rollover_detected = (*Real*)(rover_8d.rollover_detected)
*/
void RoverExample_Components_Rover_eqFunction_352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,352};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[119]] /* rollover_detected variable */) = ((modelica_real)(data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* rover_8d.rollover_detected DISCRETE */));
  TRACE_POP
}
/*
equation index: 353
type: SIMPLE_ASSIGN
$DER.rover_8d.r = (0.5 * (rover_8d.Fx_fl * $cse34 + rover_8d.Fy_fl * $cse35 + rover_8d.Fx_rl - rover_8d.Fx_rr - rover_8d.Fy_fr * $cse35 - rover_8d.Fx_fr * $cse34) * rover_8d.tw + rover_8d.l_front * (rover_8d.Fy_fl * $cse34 - rover_8d.Fx_fl * $cse35) + rover_8d.l_front * (rover_8d.Fy_fr * $cse34 - rover_8d.Fx_fr * $cse35) - rover_8d.l_rear * (rover_8d.Fy_rl + rover_8d.Fy_rr)) / rover_8d.I_zz
*/
void RoverExample_Components_Rover_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* der(rover_8d.r) STATE_DER */) = DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[165]] /* rover_8d.Fx_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[166]] /* rover_8d.Fx_rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)))) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) - (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[169]] /* rover_8d.Fy_rl variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[170]] /* rover_8d.Fy_rr variable */))),(data->simulationInfo->realParameter[66] /* rover_8d.I_zz PARAM */),"rover_8d.I_zz",equationIndexes);
  TRACE_POP
}
/*
equation index: 354
type: SIMPLE_ASSIGN
$DER.rover_8d.vy = rover_8d.ay + (rover_8d.l_rear * rover_8d.mass_unsprung_rear - rover_8d.l_front * rover_8d.mass_unsprung_front) * der(rover_8d.r) / rover_8d.mass_total - rover_8d.vx * rover_8d.r
*/
void RoverExample_Components_Rover_eqFunction_354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,354};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* der(rover_8d.vy) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */) + (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) - (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* der(rover_8d.r) STATE_DER */),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}
/*
equation index: 367
type: LINEAR

<var>rover_8d.thr</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_367(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,367};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { (data->localData[1]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 367 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 1, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,367};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 367 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) = aux_x[0];

  TRACE_POP
}
/*
equation index: 368
type: SIMPLE_ASSIGN
$cse14 = tanh(abs(rover_8d.vx))
*/
void RoverExample_Components_Rover_eqFunction_368(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,368};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */) = tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)));
  TRACE_POP
}
/*
equation index: 369
type: SIMPLE_ASSIGN
$cse13 = RoverExample.Utils.clip($cse14, 0.001, 1.0)
*/
void RoverExample_Components_Rover_eqFunction_369(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,369};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */) = omc_RoverExample_Utils_clip(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */), 0.001, 1.0);
  TRACE_POP
}
/*
equation index: 370
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rr = (rover_8d.r_tire * rover_8d.omega_rr + 0.5 * rover_8d.tw * rover_8d.r - rover_8d.vx) / rover_8d.Lrelx - abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r) * rover_8d.kappa_rr / (rover_8d.Lrelx * $cse13)
*/
void RoverExample_Components_Rover_eqFunction_370(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,370};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* der(rover_8d.kappa_rr) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* rover_8d.omega_rr STATE(1) */)) + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */),(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx",equationIndexes) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */),((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)),"rover_8d.Lrelx * $cse13",equationIndexes)));
  TRACE_POP
}
/*
equation index: 371
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rl = (rover_8d.r_tire * rover_8d.omega_rl + (-0.5) * rover_8d.tw * rover_8d.r - rover_8d.vx) / rover_8d.Lrelx - abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r) * rover_8d.kappa_rl / (rover_8d.Lrelx * $cse13)
*/
void RoverExample_Components_Rover_eqFunction_371(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,371};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* der(rover_8d.kappa_rl) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* rover_8d.omega_rl STATE(1) */)) + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */),(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx",equationIndexes) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */),((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)),"rover_8d.Lrelx * $cse13",equationIndexes)));
  TRACE_POP
}
/*
equation index: 372
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fr = (rover_8d.r_tire * rover_8d.omega_fr + 0.5 * rover_8d.tw * rover_8d.r - rover_8d.vx) / rover_8d.Lrelx - abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r) * rover_8d.kappa_fr / (rover_8d.Lrelx * $cse13)
*/
void RoverExample_Components_Rover_eqFunction_372(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,372};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* der(rover_8d.kappa_fr) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* rover_8d.omega_fr STATE(1) */)) + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */),(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx",equationIndexes) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */),((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)),"rover_8d.Lrelx * $cse13",equationIndexes)));
  TRACE_POP
}
/*
equation index: 373
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fl = (rover_8d.r_tire * rover_8d.omega_fl + (-0.5) * rover_8d.tw * rover_8d.r - rover_8d.vx) / rover_8d.Lrelx - abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r) * rover_8d.kappa_fl / (rover_8d.Lrelx * $cse13)
*/
void RoverExample_Components_Rover_eqFunction_373(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,373};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* der(rover_8d.kappa_fl) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* rover_8d.omega_fl STATE(1) */)) + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */),(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx",equationIndexes) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */),((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)),"rover_8d.Lrelx * $cse13",equationIndexes)));
  TRACE_POP
}
/*
equation index: 374
type: SIMPLE_ASSIGN
$cse12 = RoverExample.Utils.clip(pre(rover_8d.D), (rover_8d.R_phi * rover_8d.b / rover_8d.Kt_q + rover_8d.Kb_q) / (1.224744871391589 * rover_8d.Vs) * 0.001 / rover_8d.r_tire * rover_8d.gratio, 1.0)
*/
void RoverExample_Components_Rover_eqFunction_374(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,374};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* $cse12 variable */) = omc_RoverExample_Utils_clip(threadData, (data->simulationInfo->realVarsPre[244] /* rover_8d.D DISCRETE */), (DIVISION_SIM(DIVISION_SIM(((data->simulationInfo->realParameter[77] /* rover_8d.R_phi PARAM */)) * ((data->simulationInfo->realParameter[81] /* rover_8d.b PARAM */)),(data->simulationInfo->realParameter[71] /* rover_8d.Kt_q PARAM */),"rover_8d.Kt_q",equationIndexes) + (data->simulationInfo->realParameter[69] /* rover_8d.Kb_q PARAM */),(1.224744871391589) * ((data->simulationInfo->realParameter[78] /* rover_8d.Vs PARAM */)),"1.224744871391589 * rover_8d.Vs",equationIndexes)) * ((DIVISION_SIM(0.001,(data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */),"rover_8d.r_tire",equationIndexes)) * ((data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */))), 1.0);
  TRACE_POP
}
/*
equation index: 375
type: SIMPLE_ASSIGN
rover_8d.Vq = 1.224744871391589 * rover_8d.Vs * $cse12
*/
void RoverExample_Components_Rover_eqFunction_375(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,375};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[177]] /* rover_8d.Vq variable */) = (1.224744871391589) * (((data->simulationInfo->realParameter[78] /* rover_8d.Vs PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* $cse12 variable */)));
  TRACE_POP
}
/*
equation index: 376
type: SIMPLE_ASSIGN
$DER.rover_8d.Iq = (rover_8d.Vq + (-rover_8d.R_phi) * rover_8d.Iq - rover_8d.Kb_q * rover_8d.omega) / rover_8d.Le
*/
void RoverExample_Components_Rover_eqFunction_376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,376};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* der(rover_8d.Iq) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[177]] /* rover_8d.Vq variable */) + ((-(data->simulationInfo->realParameter[77] /* rover_8d.R_phi PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */)) - (((data->simulationInfo->realParameter[69] /* rover_8d.Kb_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* rover_8d.omega DUMMY_STATE */))),(data->simulationInfo->realParameter[72] /* rover_8d.Le PARAM */),"rover_8d.Le",equationIndexes);
  TRACE_POP
}
/*
equation index: 377
type: SIMPLE_ASSIGN
$cse11 = sin(rover_8d.lambda)
*/
void RoverExample_Components_Rover_eqFunction_377(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,377};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* $cse11 variable */) = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */));
  TRACE_POP
}
/*
equation index: 378
type: SIMPLE_ASSIGN
$cse10 = cos(rover_8d.lambda)
*/
void RoverExample_Components_Rover_eqFunction_378(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,378};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* $cse10 variable */) = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */));
  TRACE_POP
}
/*
equation index: 379
type: SIMPLE_ASSIGN
$cse9 = RoverExample.Utils.dot3({0.0, (rover_8d.emi.mag_motor + rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * $cse10, (rover_8d.emi.mag_motor + rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * $cse11}, rover_8d.emi.x_motor)
*/
void RoverExample_Components_Rover_eqFunction_379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,379};
  real_array tmp12;
  real_array tmp13;
  array_alloc_scalar_real_array(&tmp12, 3, (modelica_real)0.0, (modelica_real)((data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */) + (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */))) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* $cse10 variable */)), (modelica_real)((data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */) + (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */))) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* $cse11 variable */)));
  real_array_create(&tmp13, ((modelica_real*)&((&data->simulationInfo->realParameter[96] /* rover_8d.emi.x_motor[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* $cse9 variable */) = omc_RoverExample_Utils_dot3(threadData, tmp12, tmp13);
  TRACE_POP
}
/*
equation index: 380
type: SIMPLE_ASSIGN
rover_8d.emi.b_motor[3] = 9.999999999999998e-8 * rover_8d.emi.eta_motor * (3.0 * $cse9 * rover_8d.emi.x_motor[3] / rover_8d.emi.dist_motor ^ 5.0 + ((-rover_8d.emi.mag_motor) - rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * $cse11 / rover_8d.emi.dist_motor ^ 3.0)
*/
void RoverExample_Components_Rover_eqFunction_380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,380};
  modelica_real tmp14;
  tmp14 = (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[187]] /* rover_8d.emi.b_motor[3] variable */) = (9.999999999999998e-8) * (((data->simulationInfo->realParameter[91] /* rover_8d.emi.eta_motor PARAM */)) * ((3.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* $cse9 variable */)) * (DIVISION_SIM((data->simulationInfo->realParameter[98] /* rover_8d.emi.x_motor[3] PARAM */),real_int_pow(threadData, (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */), 5),"rover_8d.emi.dist_motor ^ 5.0",equationIndexes))) + ((-(data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */)) - (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */)) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* $cse11 variable */),(tmp14 * tmp14 * tmp14),"rover_8d.emi.dist_motor ^ 3.0",equationIndexes))));
  TRACE_POP
}
/*
equation index: 381
type: SIMPLE_ASSIGN
rover_8d.emi.b_motor[1] = 2.9999999999999993e-7 * rover_8d.emi.eta_motor * $cse9 * rover_8d.emi.x_motor[1] / rover_8d.emi.dist_motor ^ 5.0
*/
void RoverExample_Components_Rover_eqFunction_381(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,381};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[185]] /* rover_8d.emi.b_motor[1] variable */) = (2.9999999999999993e-7) * (((data->simulationInfo->realParameter[91] /* rover_8d.emi.eta_motor PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* $cse9 variable */)) * (DIVISION_SIM((data->simulationInfo->realParameter[96] /* rover_8d.emi.x_motor[1] PARAM */),real_int_pow(threadData, (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */), 5),"rover_8d.emi.dist_motor ^ 5.0",equationIndexes))));
  TRACE_POP
}
/*
equation index: 382
type: SIMPLE_ASSIGN
rover_8d.emi.b_motor[2] = 9.999999999999998e-8 * rover_8d.emi.eta_motor * (3.0 * $cse9 * rover_8d.emi.x_motor[2] / rover_8d.emi.dist_motor ^ 5.0 + ((-rover_8d.emi.mag_motor) - rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * $cse10 / rover_8d.emi.dist_motor ^ 3.0)
*/
void RoverExample_Components_Rover_eqFunction_382(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,382};
  modelica_real tmp15;
  tmp15 = (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[186]] /* rover_8d.emi.b_motor[2] variable */) = (9.999999999999998e-8) * (((data->simulationInfo->realParameter[91] /* rover_8d.emi.eta_motor PARAM */)) * ((3.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* $cse9 variable */)) * (DIVISION_SIM((data->simulationInfo->realParameter[97] /* rover_8d.emi.x_motor[2] PARAM */),real_int_pow(threadData, (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */), 5),"rover_8d.emi.dist_motor ^ 5.0",equationIndexes))) + ((-(data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */)) - (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */)) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* $cse10 variable */),(tmp15 * tmp15 * tmp15),"rover_8d.emi.dist_motor ^ 3.0",equationIndexes))));
  TRACE_POP
}
/*
equation index: 383
type: SIMPLE_ASSIGN
$cse4 = sin(rover_3d.psi)
*/
void RoverExample_Components_Rover_eqFunction_383(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,383};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[101]] /* $cse4 variable */) = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */));
  TRACE_POP
}
/*
equation index: 384
type: SIMPLE_ASSIGN
$DER.rover_3d.y = rover_3d.vx * $cse4
*/
void RoverExample_Components_Rover_eqFunction_384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,384};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* der(rover_3d.y) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[101]] /* $cse4 variable */));
  TRACE_POP
}
/*
equation index: 385
type: SIMPLE_ASSIGN
$cse3 = cos(rover_3d.psi)
*/
void RoverExample_Components_Rover_eqFunction_385(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,385};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* $cse3 variable */) = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */));
  TRACE_POP
}
/*
equation index: 386
type: SIMPLE_ASSIGN
$DER.rover_3d.x = rover_3d.vx * $cse3
*/
void RoverExample_Components_Rover_eqFunction_386(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,386};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* der(rover_3d.x) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* $cse3 variable */));
  TRACE_POP
}
/*
equation index: 387
type: SIMPLE_ASSIGN
$DER.rover_8d.q = 0.0
*/
void RoverExample_Components_Rover_eqFunction_387(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,387};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* der(rover_8d.q) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 388
type: SIMPLE_ASSIGN
q_meas = rover_8d.q
*/
void RoverExample_Components_Rover_eqFunction_388(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,388};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[117]] /* q_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* rover_8d.q STATE(1) */);
  TRACE_POP
}
/*
equation index: 389
type: SIMPLE_ASSIGN
$DER.rover_8d.vz = 0.0
*/
void RoverExample_Components_Rover_eqFunction_389(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,389};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* der(rover_8d.vz) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 390
type: SIMPLE_ASSIGN
vz_meas = rover_8d.vz
*/
void RoverExample_Components_Rover_eqFunction_390(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,390};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[237]] /* vz_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* rover_8d.vz STATE(1) */);
  TRACE_POP
}
/*
equation index: 391
type: SIMPLE_ASSIGN
$DER.rover_8d.z = 0.0
*/
void RoverExample_Components_Rover_eqFunction_391(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,391};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* der(rover_8d.z) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 392
type: SIMPLE_ASSIGN
z_meas = rover_8d.z
*/
void RoverExample_Components_Rover_eqFunction_392(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,392};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[240]] /* z_meas variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* rover_8d.z STATE(1) */);
  TRACE_POP
}
/*
equation index: 393
type: SIMPLE_ASSIGN
$DER.rover_3d.vz = 0.0
*/
void RoverExample_Components_Rover_eqFunction_393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,393};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* der(rover_3d.vz) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 394
type: SIMPLE_ASSIGN
$DER.rover_3d.vy = 0.0
*/
void RoverExample_Components_Rover_eqFunction_394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,394};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* der(rover_3d.vy) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 395
type: SIMPLE_ASSIGN
$DER.rover_3d.z = 0.0
*/
void RoverExample_Components_Rover_eqFunction_395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,395};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* der(rover_3d.z) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 396
type: WHEN

when {$whenCondition10} then
  reinit(rover_8d.lambda,  rover_8d.lambda - 6.2831853);
end when;
*/
void RoverExample_Components_Rover_eqFunction_396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,396};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition10 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[1] /* $whenCondition10 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */) - 6.2831853;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit rover_8d.lambda = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  RoverExample_Components_Rover_functionLocalKnownVars(data, threadData);
  RoverExample_Components_Rover_eqFunction_208(data, threadData);

  RoverExample_Components_Rover_eqFunction_209(data, threadData);

  RoverExample_Components_Rover_eqFunction_210(data, threadData);

  RoverExample_Components_Rover_eqFunction_211(data, threadData);

  RoverExample_Components_Rover_eqFunction_212(data, threadData);

  RoverExample_Components_Rover_eqFunction_213(data, threadData);

  RoverExample_Components_Rover_eqFunction_214(data, threadData);

  RoverExample_Components_Rover_eqFunction_215(data, threadData);

  RoverExample_Components_Rover_eqFunction_216(data, threadData);

  RoverExample_Components_Rover_eqFunction_217(data, threadData);

  RoverExample_Components_Rover_eqFunction_218(data, threadData);

  RoverExample_Components_Rover_eqFunction_220(data, threadData);

  RoverExample_Components_Rover_eqFunction_221(data, threadData);

  RoverExample_Components_Rover_eqFunction_222(data, threadData);

  RoverExample_Components_Rover_eqFunction_224(data, threadData);

  RoverExample_Components_Rover_eqFunction_225(data, threadData);

  RoverExample_Components_Rover_eqFunction_226(data, threadData);

  RoverExample_Components_Rover_eqFunction_227(data, threadData);

  RoverExample_Components_Rover_eqFunction_228(data, threadData);

  RoverExample_Components_Rover_eqFunction_229(data, threadData);

  RoverExample_Components_Rover_eqFunction_230(data, threadData);

  RoverExample_Components_Rover_eqFunction_231(data, threadData);

  RoverExample_Components_Rover_eqFunction_232(data, threadData);

  RoverExample_Components_Rover_eqFunction_233(data, threadData);

  RoverExample_Components_Rover_eqFunction_234(data, threadData);

  RoverExample_Components_Rover_eqFunction_235(data, threadData);

  RoverExample_Components_Rover_eqFunction_236(data, threadData);

  RoverExample_Components_Rover_eqFunction_237(data, threadData);

  RoverExample_Components_Rover_eqFunction_238(data, threadData);

  RoverExample_Components_Rover_eqFunction_239(data, threadData);

  RoverExample_Components_Rover_eqFunction_240(data, threadData);

  RoverExample_Components_Rover_eqFunction_241(data, threadData);

  RoverExample_Components_Rover_eqFunction_242(data, threadData);

  RoverExample_Components_Rover_eqFunction_243(data, threadData);

  RoverExample_Components_Rover_eqFunction_244(data, threadData);

  RoverExample_Components_Rover_eqFunction_245(data, threadData);

  RoverExample_Components_Rover_eqFunction_246(data, threadData);

  RoverExample_Components_Rover_eqFunction_247(data, threadData);

  RoverExample_Components_Rover_eqFunction_248(data, threadData);

  RoverExample_Components_Rover_eqFunction_249(data, threadData);

  RoverExample_Components_Rover_eqFunction_250(data, threadData);

  RoverExample_Components_Rover_eqFunction_251(data, threadData);

  RoverExample_Components_Rover_eqFunction_252(data, threadData);

  RoverExample_Components_Rover_eqFunction_253(data, threadData);

  RoverExample_Components_Rover_eqFunction_254(data, threadData);

  RoverExample_Components_Rover_eqFunction_255(data, threadData);

  RoverExample_Components_Rover_eqFunction_256(data, threadData);

  RoverExample_Components_Rover_eqFunction_257(data, threadData);

  RoverExample_Components_Rover_eqFunction_258(data, threadData);

  RoverExample_Components_Rover_eqFunction_259(data, threadData);

  RoverExample_Components_Rover_eqFunction_260(data, threadData);

  RoverExample_Components_Rover_eqFunction_261(data, threadData);

  RoverExample_Components_Rover_eqFunction_262(data, threadData);

  RoverExample_Components_Rover_eqFunction_263(data, threadData);

  RoverExample_Components_Rover_eqFunction_264(data, threadData);

  RoverExample_Components_Rover_eqFunction_265(data, threadData);

  RoverExample_Components_Rover_eqFunction_266(data, threadData);

  RoverExample_Components_Rover_eqFunction_267(data, threadData);

  RoverExample_Components_Rover_eqFunction_268(data, threadData);

  RoverExample_Components_Rover_eqFunction_269(data, threadData);

  RoverExample_Components_Rover_eqFunction_270(data, threadData);

  RoverExample_Components_Rover_eqFunction_272(data, threadData);

  RoverExample_Components_Rover_eqFunction_273(data, threadData);

  RoverExample_Components_Rover_eqFunction_274(data, threadData);

  RoverExample_Components_Rover_eqFunction_275(data, threadData);

  RoverExample_Components_Rover_eqFunction_276(data, threadData);

  RoverExample_Components_Rover_eqFunction_277(data, threadData);

  RoverExample_Components_Rover_eqFunction_278(data, threadData);

  RoverExample_Components_Rover_eqFunction_279(data, threadData);

  RoverExample_Components_Rover_eqFunction_280(data, threadData);

  RoverExample_Components_Rover_eqFunction_281(data, threadData);

  RoverExample_Components_Rover_eqFunction_282(data, threadData);

  RoverExample_Components_Rover_eqFunction_283(data, threadData);

  RoverExample_Components_Rover_eqFunction_284(data, threadData);

  RoverExample_Components_Rover_eqFunction_285(data, threadData);

  RoverExample_Components_Rover_eqFunction_286(data, threadData);

  RoverExample_Components_Rover_eqFunction_287(data, threadData);

  RoverExample_Components_Rover_eqFunction_288(data, threadData);

  RoverExample_Components_Rover_eqFunction_289(data, threadData);

  RoverExample_Components_Rover_eqFunction_290(data, threadData);

  RoverExample_Components_Rover_eqFunction_291(data, threadData);

  RoverExample_Components_Rover_eqFunction_292(data, threadData);

  RoverExample_Components_Rover_eqFunction_293(data, threadData);

  RoverExample_Components_Rover_eqFunction_294(data, threadData);

  RoverExample_Components_Rover_eqFunction_295(data, threadData);

  RoverExample_Components_Rover_eqFunction_296(data, threadData);

  RoverExample_Components_Rover_eqFunction_297(data, threadData);

  RoverExample_Components_Rover_eqFunction_298(data, threadData);

  RoverExample_Components_Rover_eqFunction_299(data, threadData);

  RoverExample_Components_Rover_eqFunction_300(data, threadData);

  RoverExample_Components_Rover_eqFunction_301(data, threadData);

  RoverExample_Components_Rover_eqFunction_302(data, threadData);

  RoverExample_Components_Rover_eqFunction_303(data, threadData);

  RoverExample_Components_Rover_eqFunction_304(data, threadData);

  RoverExample_Components_Rover_eqFunction_305(data, threadData);

  RoverExample_Components_Rover_eqFunction_306(data, threadData);

  RoverExample_Components_Rover_eqFunction_307(data, threadData);

  RoverExample_Components_Rover_eqFunction_308(data, threadData);

  RoverExample_Components_Rover_eqFunction_309(data, threadData);

  RoverExample_Components_Rover_eqFunction_310(data, threadData);

  RoverExample_Components_Rover_eqFunction_311(data, threadData);

  RoverExample_Components_Rover_eqFunction_312(data, threadData);

  RoverExample_Components_Rover_eqFunction_313(data, threadData);

  RoverExample_Components_Rover_eqFunction_314(data, threadData);

  RoverExample_Components_Rover_eqFunction_315(data, threadData);

  RoverExample_Components_Rover_eqFunction_316(data, threadData);

  RoverExample_Components_Rover_eqFunction_317(data, threadData);

  RoverExample_Components_Rover_eqFunction_318(data, threadData);

  RoverExample_Components_Rover_eqFunction_319(data, threadData);

  RoverExample_Components_Rover_eqFunction_320(data, threadData);

  RoverExample_Components_Rover_eqFunction_321(data, threadData);

  RoverExample_Components_Rover_eqFunction_322(data, threadData);

  RoverExample_Components_Rover_eqFunction_345(data, threadData);

  RoverExample_Components_Rover_eqFunction_346(data, threadData);

  RoverExample_Components_Rover_eqFunction_347(data, threadData);

  RoverExample_Components_Rover_eqFunction_348(data, threadData);

  RoverExample_Components_Rover_eqFunction_349(data, threadData);

  RoverExample_Components_Rover_eqFunction_350(data, threadData);

  RoverExample_Components_Rover_eqFunction_351(data, threadData);

  RoverExample_Components_Rover_eqFunction_352(data, threadData);

  RoverExample_Components_Rover_eqFunction_353(data, threadData);

  RoverExample_Components_Rover_eqFunction_354(data, threadData);

  RoverExample_Components_Rover_eqFunction_367(data, threadData);

  RoverExample_Components_Rover_eqFunction_368(data, threadData);

  RoverExample_Components_Rover_eqFunction_369(data, threadData);

  RoverExample_Components_Rover_eqFunction_370(data, threadData);

  RoverExample_Components_Rover_eqFunction_371(data, threadData);

  RoverExample_Components_Rover_eqFunction_372(data, threadData);

  RoverExample_Components_Rover_eqFunction_373(data, threadData);

  RoverExample_Components_Rover_eqFunction_374(data, threadData);

  RoverExample_Components_Rover_eqFunction_375(data, threadData);

  RoverExample_Components_Rover_eqFunction_376(data, threadData);

  RoverExample_Components_Rover_eqFunction_377(data, threadData);

  RoverExample_Components_Rover_eqFunction_378(data, threadData);

  RoverExample_Components_Rover_eqFunction_379(data, threadData);

  RoverExample_Components_Rover_eqFunction_380(data, threadData);

  RoverExample_Components_Rover_eqFunction_381(data, threadData);

  RoverExample_Components_Rover_eqFunction_382(data, threadData);

  RoverExample_Components_Rover_eqFunction_383(data, threadData);

  RoverExample_Components_Rover_eqFunction_384(data, threadData);

  RoverExample_Components_Rover_eqFunction_385(data, threadData);

  RoverExample_Components_Rover_eqFunction_386(data, threadData);

  RoverExample_Components_Rover_eqFunction_387(data, threadData);

  RoverExample_Components_Rover_eqFunction_388(data, threadData);

  RoverExample_Components_Rover_eqFunction_389(data, threadData);

  RoverExample_Components_Rover_eqFunction_390(data, threadData);

  RoverExample_Components_Rover_eqFunction_391(data, threadData);

  RoverExample_Components_Rover_eqFunction_392(data, threadData);

  RoverExample_Components_Rover_eqFunction_393(data, threadData);

  RoverExample_Components_Rover_eqFunction_394(data, threadData);

  RoverExample_Components_Rover_eqFunction_395(data, threadData);

  RoverExample_Components_Rover_eqFunction_396(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int RoverExample_Components_Rover_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void RoverExample_Components_Rover_eqFunction_395(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_394(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_393(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_391(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_389(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_387(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_214(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_215(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_224(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_225(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_226(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_229(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_230(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_243(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_244(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_245(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_246(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_247(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_248(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_249(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_250(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_251(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_252(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_253(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_254(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_273(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_275(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_279(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_280(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_281(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_282(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_283(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_284(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_285(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_286(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_287(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_288(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_289(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_290(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_291(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_292(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_293(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_294(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_295(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_296(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_297(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_298(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_299(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_300(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_301(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_302(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_303(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_304(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_305(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_306(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_307(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_308(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_309(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_310(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_311(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_312(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_313(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_314(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_315(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_316(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_317(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_318(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_319(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_320(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_321(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_322(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_345(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_346(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_348(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_353(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_354(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_367(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_368(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_369(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_370(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_371(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_372(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_373(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_374(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_375(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_376(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_383(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_384(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_385(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_386(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[90])(DATA*, threadData_t*) = {
    RoverExample_Components_Rover_eqFunction_395,
    RoverExample_Components_Rover_eqFunction_394,
    RoverExample_Components_Rover_eqFunction_393,
    RoverExample_Components_Rover_eqFunction_391,
    RoverExample_Components_Rover_eqFunction_389,
    RoverExample_Components_Rover_eqFunction_387,
    RoverExample_Components_Rover_eqFunction_214,
    RoverExample_Components_Rover_eqFunction_215,
    RoverExample_Components_Rover_eqFunction_224,
    RoverExample_Components_Rover_eqFunction_225,
    RoverExample_Components_Rover_eqFunction_226,
    RoverExample_Components_Rover_eqFunction_229,
    RoverExample_Components_Rover_eqFunction_230,
    RoverExample_Components_Rover_eqFunction_243,
    RoverExample_Components_Rover_eqFunction_244,
    RoverExample_Components_Rover_eqFunction_245,
    RoverExample_Components_Rover_eqFunction_246,
    RoverExample_Components_Rover_eqFunction_247,
    RoverExample_Components_Rover_eqFunction_248,
    RoverExample_Components_Rover_eqFunction_249,
    RoverExample_Components_Rover_eqFunction_250,
    RoverExample_Components_Rover_eqFunction_251,
    RoverExample_Components_Rover_eqFunction_252,
    RoverExample_Components_Rover_eqFunction_253,
    RoverExample_Components_Rover_eqFunction_254,
    RoverExample_Components_Rover_eqFunction_273,
    RoverExample_Components_Rover_eqFunction_275,
    RoverExample_Components_Rover_eqFunction_279,
    RoverExample_Components_Rover_eqFunction_280,
    RoverExample_Components_Rover_eqFunction_281,
    RoverExample_Components_Rover_eqFunction_282,
    RoverExample_Components_Rover_eqFunction_283,
    RoverExample_Components_Rover_eqFunction_284,
    RoverExample_Components_Rover_eqFunction_285,
    RoverExample_Components_Rover_eqFunction_286,
    RoverExample_Components_Rover_eqFunction_287,
    RoverExample_Components_Rover_eqFunction_288,
    RoverExample_Components_Rover_eqFunction_289,
    RoverExample_Components_Rover_eqFunction_290,
    RoverExample_Components_Rover_eqFunction_291,
    RoverExample_Components_Rover_eqFunction_292,
    RoverExample_Components_Rover_eqFunction_293,
    RoverExample_Components_Rover_eqFunction_294,
    RoverExample_Components_Rover_eqFunction_295,
    RoverExample_Components_Rover_eqFunction_296,
    RoverExample_Components_Rover_eqFunction_297,
    RoverExample_Components_Rover_eqFunction_298,
    RoverExample_Components_Rover_eqFunction_299,
    RoverExample_Components_Rover_eqFunction_300,
    RoverExample_Components_Rover_eqFunction_301,
    RoverExample_Components_Rover_eqFunction_302,
    RoverExample_Components_Rover_eqFunction_303,
    RoverExample_Components_Rover_eqFunction_304,
    RoverExample_Components_Rover_eqFunction_305,
    RoverExample_Components_Rover_eqFunction_306,
    RoverExample_Components_Rover_eqFunction_307,
    RoverExample_Components_Rover_eqFunction_308,
    RoverExample_Components_Rover_eqFunction_309,
    RoverExample_Components_Rover_eqFunction_310,
    RoverExample_Components_Rover_eqFunction_311,
    RoverExample_Components_Rover_eqFunction_312,
    RoverExample_Components_Rover_eqFunction_313,
    RoverExample_Components_Rover_eqFunction_314,
    RoverExample_Components_Rover_eqFunction_315,
    RoverExample_Components_Rover_eqFunction_316,
    RoverExample_Components_Rover_eqFunction_317,
    RoverExample_Components_Rover_eqFunction_318,
    RoverExample_Components_Rover_eqFunction_319,
    RoverExample_Components_Rover_eqFunction_320,
    RoverExample_Components_Rover_eqFunction_321,
    RoverExample_Components_Rover_eqFunction_322,
    RoverExample_Components_Rover_eqFunction_345,
    RoverExample_Components_Rover_eqFunction_346,
    RoverExample_Components_Rover_eqFunction_348,
    RoverExample_Components_Rover_eqFunction_353,
    RoverExample_Components_Rover_eqFunction_354,
    RoverExample_Components_Rover_eqFunction_367,
    RoverExample_Components_Rover_eqFunction_368,
    RoverExample_Components_Rover_eqFunction_369,
    RoverExample_Components_Rover_eqFunction_370,
    RoverExample_Components_Rover_eqFunction_371,
    RoverExample_Components_Rover_eqFunction_372,
    RoverExample_Components_Rover_eqFunction_373,
    RoverExample_Components_Rover_eqFunction_374,
    RoverExample_Components_Rover_eqFunction_375,
    RoverExample_Components_Rover_eqFunction_376,
    RoverExample_Components_Rover_eqFunction_383,
    RoverExample_Components_Rover_eqFunction_384,
    RoverExample_Components_Rover_eqFunction_385,
    RoverExample_Components_Rover_eqFunction_386
  };
  
  static const int eqIndices[90] = {
    395,
    394,
    393,
    391,
    389,
    387,
    214,
    215,
    224,
    225,
    226,
    229,
    230,
    243,
    244,
    245,
    246,
    247,
    248,
    249,
    250,
    251,
    252,
    253,
    254,
    273,
    275,
    279,
    280,
    281,
    282,
    283,
    284,
    285,
    286,
    287,
    288,
    289,
    290,
    291,
    292,
    293,
    294,
    295,
    296,
    297,
    298,
    299,
    300,
    301,
    302,
    303,
    304,
    305,
    306,
    307,
    308,
    309,
    310,
    311,
    312,
    313,
    314,
    315,
    316,
    317,
    318,
    319,
    320,
    321,
    322,
    345,
    346,
    348,
    353,
    354,
    367,
    368,
    369,
    370,
    371,
    372,
    373,
    374,
    375,
    376,
    383,
    384,
    385,
    386
  };
  
  for (id = 0; id < 90; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int RoverExample_Components_Rover_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  RoverExample_Components_Rover_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void RoverExample_Components_Rover_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
{
  TRACE_PUSH

  size_t i_real = 0;
  size_t i_integer = 0;
  size_t i_boolean = 0;
  size_t i_string = 0;

  realIndex[0] = 0;
  integerIndex[0] = 0;
  booleanIndex[0] = 0;
  stringIndex[0] = 0;

  /* stateVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.phi STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.psi STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.theta STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.vy STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.vz STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.x STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.y STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.z STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Iq STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.alpha_fl STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.alpha_fr STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.alpha_rl STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.alpha_rr STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.delta STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.kappa_fl STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.kappa_fr STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.kappa_rl STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.kappa_rr STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.lambda STATE(1,rover_8d.omega) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.omega_fl STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.omega_fr STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.omega_rl STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.omega_rr STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.p STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.phi STATE(1,rover_8d.p) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.psi STATE(1,rover_8d.r) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.q STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.r STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.theta STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vx STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vy STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vz STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.x STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.y STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.z STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_3d.phi) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_3d.psi) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_3d.theta) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_3d.vy) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_3d.vz) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_3d.x) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_3d.y) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_3d.z) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.Iq) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.alpha_fl) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.alpha_fr) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.alpha_rl) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.alpha_rr) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.delta) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.kappa_fl) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.kappa_fr) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.kappa_rl) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.kappa_rr) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.lambda) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.omega_fl) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.omega_fr) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.omega_rl) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.omega_rr) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.p) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.phi) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.psi) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.q) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.r) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.theta) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.vx) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.vy) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.vz) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.x) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.y) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.z) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(rover_8d.omega) DUMMY_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse10 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse11 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse12 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse13 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse14 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse15 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse16 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse17 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse18 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse19 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse20 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse21 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse22 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse23 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse24 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse25 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse26 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse27 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse28 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse29 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse3 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse30 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse31 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse32 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse33 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse34 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse35 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse36 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse37 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse38 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse4 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse5 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse6 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse9 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ax_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ay_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* az_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* gyroatk.omega_yaw_false variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* mx_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* my_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* mz_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* p_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* phi_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* psi_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* pwm_steering variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* pwm_throttle variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* q_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* r_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rollover_detected variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.C_n2b[1,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.C_n2b[1,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.C_n2b[1,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.C_n2b[2,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.C_n2b[2,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.C_n2b[2,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.C_n2b[3,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.C_n2b[3,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.C_n2b[3,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.ax variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.ay variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.az variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.delta variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.length_to_tire variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mag.C_n2b[1,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mag.C_n2b[1,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mag.C_n2b[1,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mag.C_n2b[2,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mag.C_n2b[2,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mag.C_n2b[2,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mag.C_n2b[3,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mag.C_n2b[3,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mag.C_n2b[3,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mx variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.my variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.mz variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.p variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.phi_f variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.q variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.r variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.specific_g[1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.specific_g[2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.specific_g[3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.vx variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.C_n2b[1,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.C_n2b[1,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.C_n2b[1,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.C_n2b[2,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.C_n2b[2,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.C_n2b[2,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.C_n2b[3,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.C_n2b[3,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.C_n2b[3,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fx_fl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fx_fr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fx_rl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fx_rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fy_fl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fy_fr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fy_rl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fy_rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fz_fl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fz_fr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fz_rl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Fz_rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Ploss variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Pmech variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.Vq variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.alpha_fl_bnd variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.alpha_fr_bnd variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.alpha_rl_bnd variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.alpha_rr_bnd variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.ax variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.ay variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.az variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.emi.b_motor[1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.emi.b_motor[2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.emi.b_motor[3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.emi.b_wire[1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.emi.b_wire[2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.emi.b_wire[3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.fz_fl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.fz_fr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.fz_rl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.fz_rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.kappa_fl_bnd variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.kappa_fr_bnd variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.kappa_rl_bnd variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.kappa_rr_bnd variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.C_n2b[1,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.C_n2b[1,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.C_n2b[1,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.C_n2b[2,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.C_n2b[2,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.C_n2b[2,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.C_n2b[3,1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.C_n2b[3,2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.C_n2b[3,3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.b_earth[1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.b_earth[2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mag.b_earth[3] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mu_fl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mu_fr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mu_rl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.mu_rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.omega DUMMY_STATE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.specific_g[1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.specific_g[2] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.thr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vs_fl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vs_fr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vs_rl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vs_rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vx_fl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vx_fr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vx_rl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vx_rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vy_fl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vy_fr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.vy_rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.z_fl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.z_fr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.z_rl variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.z_rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* theta_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* vx_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* vy_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* vz_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* x_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* y_meas variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* z_meas variable */
  
  /* discreteAlgVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.D DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.delta_cmd DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_3d.turn_radius DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.D DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.delta_cmd DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* rover_8d.turn_radius DISCRETE */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* gyroatk.timer_count DISCRETE */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* rover_3d.rollover_detected DISCRETE */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* rover_8d.rollover_detected DISCRETE */
  
  /* boolAlgVars */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition1 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition10 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition2 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition3 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition4 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition5 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition6 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition7 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition8 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition9 DISCRETE */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "RoverExample.Components.Rover_12jac.h"
#include "RoverExample.Components.Rover_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks RoverExample_Components_Rover_callback = {
   (int (*)(DATA *, threadData_t *, void *)) RoverExample_Components_Rover_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) RoverExample_Components_Rover_performQSSSimulation,    /* performQSSSimulation */
   RoverExample_Components_Rover_updateContinuousSystem,    /* updateContinuousSystem */
   RoverExample_Components_Rover_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   RoverExample_Components_Rover_initialNonLinearSystem,    /* initialNonLinearSystem */
   RoverExample_Components_Rover_initialLinearSystem,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   RoverExample_Components_Rover_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   RoverExample_Components_Rover_initializeDAEmodeData,
   RoverExample_Components_Rover_computeVarIndices,
   RoverExample_Components_Rover_functionODE,
   RoverExample_Components_Rover_functionAlgebraics,
   RoverExample_Components_Rover_functionDAE,
   RoverExample_Components_Rover_functionLocalKnownVars,
   RoverExample_Components_Rover_input_function,
   RoverExample_Components_Rover_input_function_init,
   RoverExample_Components_Rover_input_function_updateStartValues,
   RoverExample_Components_Rover_data_function,
   RoverExample_Components_Rover_output_function,
   RoverExample_Components_Rover_setc_function,
   RoverExample_Components_Rover_setb_function,
   RoverExample_Components_Rover_function_storeDelayed,
   RoverExample_Components_Rover_function_storeSpatialDistribution,
   RoverExample_Components_Rover_function_initSpatialDistribution,
   RoverExample_Components_Rover_updateBoundVariableAttributes,
   RoverExample_Components_Rover_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   RoverExample_Components_Rover_functionRemovedInitialEquations,
   RoverExample_Components_Rover_updateBoundParameters,
   RoverExample_Components_Rover_checkForAsserts,
   RoverExample_Components_Rover_function_ZeroCrossingsEquations,
   RoverExample_Components_Rover_function_ZeroCrossings,
   RoverExample_Components_Rover_function_updateRelations,
   RoverExample_Components_Rover_zeroCrossingDescription,
   RoverExample_Components_Rover_relationDescription,
   RoverExample_Components_Rover_function_initSample,
   RoverExample_Components_Rover_INDEX_JAC_A,
   RoverExample_Components_Rover_INDEX_JAC_B,
   RoverExample_Components_Rover_INDEX_JAC_C,
   RoverExample_Components_Rover_INDEX_JAC_D,
   RoverExample_Components_Rover_INDEX_JAC_F,
   RoverExample_Components_Rover_INDEX_JAC_H,
   RoverExample_Components_Rover_initialAnalyticJacobianA,
   RoverExample_Components_Rover_initialAnalyticJacobianB,
   RoverExample_Components_Rover_initialAnalyticJacobianC,
   RoverExample_Components_Rover_initialAnalyticJacobianD,
   RoverExample_Components_Rover_initialAnalyticJacobianF,
   RoverExample_Components_Rover_initialAnalyticJacobianH,
   RoverExample_Components_Rover_functionJacA_column,
   RoverExample_Components_Rover_functionJacB_column,
   RoverExample_Components_Rover_functionJacC_column,
   RoverExample_Components_Rover_functionJacD_column,
   RoverExample_Components_Rover_functionJacF_column,
   RoverExample_Components_Rover_functionJacH_column,
   RoverExample_Components_Rover_linear_model_frame,
   RoverExample_Components_Rover_linear_model_datarecovery_frame,
   RoverExample_Components_Rover_mayer,
   RoverExample_Components_Rover_lagrange,
   RoverExample_Components_Rover_pickUpBoundsForInputsInOptimization,
   RoverExample_Components_Rover_setInputData,
   RoverExample_Components_Rover_getTimeGrid,
   RoverExample_Components_Rover_symbolicInlineSystem,
   RoverExample_Components_Rover_function_initSynchronous,
   RoverExample_Components_Rover_function_updateSynchronous,
   RoverExample_Components_Rover_function_equationsSynchronous,
   RoverExample_Components_Rover_inputNames,
   RoverExample_Components_Rover_dataReconciliationInputNames,
   RoverExample_Components_Rover_dataReconciliationUnmeasuredVariables,
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

#define _OMC_LIT_RESOURCE_1_name_data "Modelica"
#define _OMC_LIT_RESOURCE_1_dir_data "/home/mhcho/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,8,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,59,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_2_dir_data "/home/mhcho/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,16,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,67,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "RoverExample"
#define _OMC_LIT_RESOURCE_3_dir_data "/mnt/d/Dropbox/05.Workspace/C02.FIREFLY/06.Rover/251015.LoFi_update/NGCrover/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,12,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,82,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void RoverExample_Components_Rover_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &RoverExample_Components_Rover_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "RoverExample.Components.Rover";
  data->modelData->modelFilePrefix = "RoverExample.Components.Rover";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/mnt/d/Dropbox/05.Workspace/C02.FIREFLY/06.Rover/251015.LoFi_update/NGCrover/model";
  data->modelData->modelGUID = "{a406cd9e-fb92-4fe0-a1a1-448e7c0f4094}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "RoverExample.Components.Rover_init.c"
    ;
  static const char contents_info[] =
    #include "RoverExample.Components.Rover_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "RoverExample.Components.Rover_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "RoverExample.Components.Rover_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "RoverExample.Components.Rover_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 35;
  data->modelData->nVariablesRealArray = 247;
  data->modelData->nDiscreteReal = 6;
  data->modelData->nVariablesIntegerArray = 3;
  data->modelData->nVariablesBooleanArray = 10;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 132;
  data->modelData->nParametersInteger = 1;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 2;
  data->modelData->nOutputVars = 19;
  data->modelData->nAliasReal = 37;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 14;
  data->modelData->nSamples = 2;
  data->modelData->nRelations = 15;
  data->modelData->nMathEvents = 7;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 6;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 1057;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 10;
  data->modelData->nNonLinearSystems = 2;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 16;
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
  
    RoverExample_Components_Rover_setupDataStruc(&data, threadData);
    res = _main_initRuntimeAndSimulation(argc, newargv, &data, threadData);
    if(res == 0) {
      res = _main_SimulationRuntime(argc, newargv, &data, threadData);
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


