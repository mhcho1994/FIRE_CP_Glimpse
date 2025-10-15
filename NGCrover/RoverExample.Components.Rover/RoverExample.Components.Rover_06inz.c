/* Initialization */
#include "RoverExample.Components.Rover_model.h"
#include "RoverExample.Components.Rover_11mix.h"
#include "RoverExample.Components.Rover_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void RoverExample_Components_Rover_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
rover_3d.z = $START.rover_3d.z
*/
void RoverExample_Components_Rover_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* rover_3d.z STATE(1) */) = (data->modelData->realVarsData[7] /* rover_3d.z STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
rover_3d.vy = $START.rover_3d.vy
*/
void RoverExample_Components_Rover_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* rover_3d.vy STATE(1) */) = (data->modelData->realVarsData[3] /* rover_3d.vy STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
rover_3d.vz = $START.rover_3d.vz
*/
void RoverExample_Components_Rover_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* rover_3d.vz STATE(1) */) = (data->modelData->realVarsData[4] /* rover_3d.vz STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
rover_3d.y = $START.rover_3d.y
*/
void RoverExample_Components_Rover_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* rover_3d.y STATE(1) */) = (data->modelData->realVarsData[6] /* rover_3d.y STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
rover_3d.x = $START.rover_3d.x
*/
void RoverExample_Components_Rover_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* rover_3d.x STATE(1) */) = (data->modelData->realVarsData[5] /* rover_3d.x STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
rover_3d.length_to_tire = sqrt(rover_3d.cg_height ^ 2.0 + (0.5 * rover_3d.track_width) ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = (data->simulationInfo->realParameter[54] /* rover_3d.cg_height PARAM */);
  tmp1 = (0.5) * ((data->simulationInfo->realParameter[59] /* rover_3d.track_width PARAM */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1);
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_3d.cg_height ^ 2.0 + (0.5 * rover_3d.track_width) ^ 2.0) was %g should be >= 0", tmp2);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[133]] /* rover_3d.length_to_tire variable */) = sqrt(tmp2);
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
rover_3d.ax = 0.0
*/
void RoverExample_Components_Rover_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[129]] /* rover_3d.ax variable */) = 0.0;
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
rover_3d.az = 0.0
*/
void RoverExample_Components_Rover_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[131]] /* rover_3d.az variable */) = 0.0;
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
rover_3d.p = 0.0
*/
void RoverExample_Components_Rover_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[146]] /* rover_3d.p variable */) = 0.0;
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
rover_3d.q = 0.0
*/
void RoverExample_Components_Rover_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[148]] /* rover_3d.q variable */) = 0.0;
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
$PRE.rover_3d.turn_radius = $START.rover_3d.turn_radius
*/
void RoverExample_Components_Rover_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->simulationInfo->realVarsPre[243] /* rover_3d.turn_radius DISCRETE */) = (data->modelData->realVarsData[243] /* rover_3d.turn_radius DISCRETE */).attribute .start;
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
rover_3d.turn_radius = $PRE.rover_3d.turn_radius
*/
void RoverExample_Components_Rover_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */) = (data->simulationInfo->realVarsPre[243] /* rover_3d.turn_radius DISCRETE */);
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
rover_3d.psi = $START.rover_3d.psi
*/
void RoverExample_Components_Rover_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */) = (data->modelData->realVarsData[1] /* rover_3d.psi STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
rover_3d.theta = $START.rover_3d.theta
*/
void RoverExample_Components_Rover_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* rover_3d.theta STATE(1) */) = (data->modelData->realVarsData[2] /* rover_3d.theta STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 15
type: SIMPLE_ASSIGN
rover_3d.phi = $START.rover_3d.phi
*/
void RoverExample_Components_Rover_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* rover_3d.phi STATE(1) */) = (data->modelData->realVarsData[0] /* rover_3d.phi STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 16
type: ARRAY_CALL_ASSIGN

rover_3d.C_n2b = transpose(RoverExample.Utils.eul2rot({rover_3d.phi, rover_3d.theta, mod(rover_3d.psi + 3.14159265, 6.2831853) - 3.14159265}))
*/
void RoverExample_Components_Rover_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  real_array tmp3;
  modelica_real tmp4;
  real_array tmp5;
  real_array tmp6;
  real_array tmp7;
  tmp4 = 6.2831853;
  if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(rover_3d.psi + 3.14159265, 6.2831853)");}
  array_alloc_scalar_real_array(&tmp3, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* rover_3d.phi STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* rover_3d.theta STATE(1) */), (modelica_real)modelica_real_mod((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */) + 3.14159265, tmp4) - 3.14159265);
  tmp5 = omc_RoverExample_Utils_eul2rot(threadData, tmp3);
  transpose_alloc_real_array(&tmp5, &tmp6);
  real_array_create(&tmp7, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* rover_3d.C_n2b[1,1] variable */))[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp6, tmp7);
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_232(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_234(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_233(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_210(DATA *data, threadData_t *threadData);


/*
equation index: 21
type: SIMPLE_ASSIGN
rover_3d.mz = rover_3d.mag.C_n2b[3,1] * rover_3d.mag.b_earth0 * sin(1.570796325 - rover_3d.mag.lat0) + (-2.0) * rover_3d.mag.C_n2b[3,3] * rover_3d.mag.b_earth0 * cos(1.570796325 - rover_3d.mag.lat0)
*/
void RoverExample_Components_Rover_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[145]] /* rover_3d.mz variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[140]] /* rover_3d.mag.C_n2b[3,1] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * (sin(1.570796325 - (data->simulationInfo->realParameter[57] /* rover_3d.mag.lat0 PARAM */)))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[142]] /* rover_3d.mag.C_n2b[3,3] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * (cos(1.570796325 - (data->simulationInfo->realParameter[57] /* rover_3d.mag.lat0 PARAM */)))));
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
rover_3d.my = rover_3d.mag.C_n2b[2,1] * rover_3d.mag.b_earth0 * sin(1.570796325 - rover_3d.mag.lat0) + (-2.0) * rover_3d.mag.C_n2b[2,3] * rover_3d.mag.b_earth0 * cos(1.570796325 - rover_3d.mag.lat0)
*/
void RoverExample_Components_Rover_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[144]] /* rover_3d.my variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[137]] /* rover_3d.mag.C_n2b[2,1] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * (sin(1.570796325 - (data->simulationInfo->realParameter[57] /* rover_3d.mag.lat0 PARAM */)))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[139]] /* rover_3d.mag.C_n2b[2,3] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * (cos(1.570796325 - (data->simulationInfo->realParameter[57] /* rover_3d.mag.lat0 PARAM */)))));
  TRACE_POP
}

/*
equation index: 23
type: SIMPLE_ASSIGN
rover_3d.mx = rover_3d.mag.C_n2b[1,1] * rover_3d.mag.b_earth0 * sin(1.570796325 - rover_3d.mag.lat0) + (-2.0) * rover_3d.mag.C_n2b[1,3] * rover_3d.mag.b_earth0 * cos(1.570796325 - rover_3d.mag.lat0)
*/
void RoverExample_Components_Rover_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[143]] /* rover_3d.mx variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[134]] /* rover_3d.mag.C_n2b[1,1] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * (sin(1.570796325 - (data->simulationInfo->realParameter[57] /* rover_3d.mag.lat0 PARAM */)))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[136]] /* rover_3d.mag.C_n2b[1,3] variable */)) * (((data->simulationInfo->realParameter[56] /* rover_3d.mag.b_earth0 PARAM */)) * (cos(1.570796325 - (data->simulationInfo->realParameter[57] /* rover_3d.mag.lat0 PARAM */)))));
  TRACE_POP
}

/*
equation index: 24
type: SIMPLE_ASSIGN
$PRE.rover_3d.delta_cmd = $START.rover_3d.delta_cmd
*/
void RoverExample_Components_Rover_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->simulationInfo->realVarsPre[242] /* rover_3d.delta_cmd DISCRETE */) = (data->modelData->realVarsData[242] /* rover_3d.delta_cmd DISCRETE */).attribute .start;
  TRACE_POP
}

/*
equation index: 25
type: SIMPLE_ASSIGN
rover_3d.delta_cmd = $PRE.rover_3d.delta_cmd
*/
void RoverExample_Components_Rover_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[242]] /* rover_3d.delta_cmd DISCRETE */) = (data->simulationInfo->realVarsPre[242] /* rover_3d.delta_cmd DISCRETE */);
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
rover_3d.delta = $PRE.rover_3d.delta_cmd
*/
void RoverExample_Components_Rover_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) = (data->simulationInfo->realVarsPre[242] /* rover_3d.delta_cmd DISCRETE */);
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_217(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_216(DATA *data, threadData_t *threadData);


/*
equation index: 29
type: SIMPLE_ASSIGN
$PRE.rover_3d.D = $START.rover_3d.D
*/
void RoverExample_Components_Rover_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->simulationInfo->realVarsPre[241] /* rover_3d.D DISCRETE */) = (data->modelData->realVarsData[241] /* rover_3d.D DISCRETE */).attribute .start;
  TRACE_POP
}

/*
equation index: 30
type: SIMPLE_ASSIGN
rover_3d.D = $PRE.rover_3d.D
*/
void RoverExample_Components_Rover_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[241]] /* rover_3d.D DISCRETE */) = (data->simulationInfo->realVarsPre[241] /* rover_3d.D DISCRETE */);
  TRACE_POP
}

/*
equation index: 31
type: SIMPLE_ASSIGN
rover_3d.vx = rover_3d.v_max * $PRE.rover_3d.D
*/
void RoverExample_Components_Rover_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */) = ((data->simulationInfo->realParameter[60] /* rover_3d.v_max PARAM */)) * ((data->simulationInfo->realVarsPre[241] /* rover_3d.D DISCRETE */));
  TRACE_POP
}

/*
equation index: 32
type: SIMPLE_ASSIGN
rover_3d.r = rover_3d.vx * tan(rover_3d.delta) / rover_3d.l_total
*/
void RoverExample_Components_Rover_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[149]] /* rover_3d.r variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (DIVISION_SIM(tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */)),(data->simulationInfo->realParameter[55] /* rover_3d.l_total PARAM */),"rover_3d.l_total",equationIndexes));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_226(DATA *data, threadData_t *threadData);


/*
equation index: 34
type: SIMPLE_ASSIGN
rover_3d.ay = rover_3d.vx ^ 2.0 * tan(-rover_3d.delta) / rover_3d.l_total
*/
void RoverExample_Components_Rover_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  modelica_real tmp8;
  tmp8 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[130]] /* rover_3d.ay variable */) = ((tmp8 * tmp8)) * (DIVISION_SIM(tan((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */))),(data->simulationInfo->realParameter[55] /* rover_3d.l_total PARAM */),"rover_3d.l_total",equationIndexes));
  TRACE_POP
}

/*
equation index: 35
type: SIMPLE_ASSIGN
$DER.rover_3d.y = rover_3d.vx * sin(rover_3d.psi)
*/
void RoverExample_Components_Rover_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* der(rover_3d.y) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */)));
  TRACE_POP
}

/*
equation index: 36
type: SIMPLE_ASSIGN
$DER.rover_3d.x = rover_3d.vx * cos(rover_3d.psi)
*/
void RoverExample_Components_Rover_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* der(rover_3d.x) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */)));
  TRACE_POP
}

/*
equation index: 37
type: SIMPLE_ASSIGN
rover_3d.phi_f = atan2(rover_3d.cg_height, 0.5 * rover_3d.track_width)
*/
void RoverExample_Components_Rover_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* rover_3d.phi_f variable */) = atan2((data->simulationInfo->realParameter[54] /* rover_3d.cg_height PARAM */), (0.5) * ((data->simulationInfo->realParameter[59] /* rover_3d.track_width PARAM */)));
  TRACE_POP
}

/*
equation index: 38
type: SIMPLE_ASSIGN
$whenCondition6 = 9.80665 * cos(rover_3d.phi_f + rover_3d.phi_t) > rover_3d.vx ^ 2.0 / rover_3d.turn_radius * sin(rover_3d.phi_f)
*/
void RoverExample_Components_Rover_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  modelica_real tmp9;
  modelica_boolean tmp10;
  tmp9 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
  tmp10 = Greater((9.80665) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* rover_3d.phi_f variable */) + (data->simulationInfo->realParameter[58] /* rover_3d.phi_t PARAM */))),(DIVISION_SIM((tmp9 * tmp9),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius",equationIndexes)) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* rover_3d.phi_f variable */))));
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[6]] /* $whenCondition6 DISCRETE */) = tmp10;
  TRACE_POP
}

/*
equation index: 39
type: SIMPLE_ASSIGN
$whenCondition7 = 9.80665 * cos(rover_3d.phi_f + rover_3d.phi_t) <= rover_3d.vx ^ 2.0 / rover_3d.turn_radius * sin(rover_3d.phi_f)
*/
void RoverExample_Components_Rover_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  modelica_real tmp11;
  modelica_boolean tmp12;
  tmp11 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
  tmp12 = LessEq((9.80665) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* rover_3d.phi_f variable */) + (data->simulationInfo->realParameter[58] /* rover_3d.phi_t PARAM */))),(DIVISION_SIM((tmp11 * tmp11),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius",equationIndexes)) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* rover_3d.phi_f variable */))));
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[7]] /* $whenCondition7 DISCRETE */) = tmp12;
  TRACE_POP
}

/*
equation index: 40
type: SIMPLE_ASSIGN
rover_8d.az = 0.0
*/
void RoverExample_Components_Rover_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[184]] /* rover_8d.az variable */) = 0.0;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_395(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_394(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_393(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_391(DATA *data, threadData_t *threadData);


/*
equation index: 45
type: SIMPLE_ASSIGN
rover_8d.z = $START.rover_8d.z
*/
void RoverExample_Components_Rover_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* rover_8d.z STATE(1) */) = (data->modelData->realVarsData[34] /* rover_8d.z STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_392(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_389(DATA *data, threadData_t *threadData);


/*
equation index: 48
type: SIMPLE_ASSIGN
rover_8d.vz = $START.rover_8d.vz
*/
void RoverExample_Components_Rover_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* rover_8d.vz STATE(1) */) = (data->modelData->realVarsData[31] /* rover_8d.vz STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_390(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_387(DATA *data, threadData_t *threadData);


/*
equation index: 51
type: SIMPLE_ASSIGN
rover_8d.q = $START.rover_8d.q
*/
void RoverExample_Components_Rover_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* rover_8d.q STATE(1) */) = (data->modelData->realVarsData[26] /* rover_8d.q STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_388(DATA *data, threadData_t *threadData);


/*
equation index: 53
type: ALGORITHM

  $whenCondition1 := $START.$whenCondition1;
  $whenCondition1 := false;
*/
void RoverExample_Components_Rover_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->modelData->booleanVarsData[0] /* $whenCondition1 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = 0 /* false */;
  TRACE_POP
}

/*
equation index: 54
type: ALGORITHM

  $whenCondition2 := $START.$whenCondition2;
  $whenCondition2 := false;
*/
void RoverExample_Components_Rover_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition2 DISCRETE */) = (data->modelData->booleanVarsData[2] /* $whenCondition2 DISCRETE */).attribute .start;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* $whenCondition2 DISCRETE */) = 0 /* false */;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_229(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_230(DATA *data, threadData_t *threadData);


/*
equation index: 57
type: SIMPLE_ASSIGN
$PRE.gyroatk.timer_count = $START.gyroatk.timer_count
*/
void RoverExample_Components_Rover_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  (data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */) = (data->modelData->integerVarsData[0] /* gyroatk.timer_count DISCRETE */).attribute .start;
  TRACE_POP
}

/*
equation index: 58
type: SIMPLE_ASSIGN
gyroatk.timer_count = $PRE.gyroatk.timer_count
*/
void RoverExample_Components_Rover_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* gyroatk.timer_count DISCRETE */) = (data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */);
  TRACE_POP
}

/*
equation index: 59
type: SIMPLE_ASSIGN
gyroatk.omega_yaw_false = 0.5 * gyroatk.l_g * gyroatk.w_d * (gyroatk.X_ac * cos((gyroatk.w_ac - gyroatk.w_d) * gyroatk.sample_interval * (*Real*)($PRE.gyroatk.timer_count) - gyroatk.Phi_ac) + gyroatk.X_d * cos(gyroatk.Phi_d)) / gyroatk.dis_d
*/
void RoverExample_Components_Rover_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* gyroatk.omega_yaw_false variable */) = (0.5) * (((data->simulationInfo->realParameter[33] /* gyroatk.l_g PARAM */)) * (((data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[21] /* gyroatk.X_ac PARAM */)) * (cos(((data->simulationInfo->realParameter[47] /* gyroatk.w_ac PARAM */) - (data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */)) * (((data->simulationInfo->realParameter[42] /* gyroatk.sample_interval PARAM */)) * (((modelica_real)(data->simulationInfo->integerVarsPre[0] /* gyroatk.timer_count DISCRETE */)))) - (data->simulationInfo->realParameter[17] /* gyroatk.Phi_ac PARAM */))) + ((data->simulationInfo->realParameter[24] /* gyroatk.X_d PARAM */)) * (cos((data->simulationInfo->realParameter[18] /* gyroatk.Phi_d PARAM */))),(data->simulationInfo->realParameter[27] /* gyroatk.dis_d PARAM */),"gyroatk.dis_d",equationIndexes))));
  TRACE_POP
}

/*
equation index: 60
type: SIMPLE_ASSIGN
rover_8d.delta = $START.rover_8d.delta
*/
void RoverExample_Components_Rover_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */) = (data->modelData->realVarsData[13] /* rover_8d.delta STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_269(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_268(DATA *data, threadData_t *threadData);


/*
equation index: 63
type: SIMPLE_ASSIGN
rover_8d.lambda = $START.rover_8d.lambda
*/
void RoverExample_Components_Rover_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */) = (data->modelData->realVarsData[18] /* rover_8d.lambda STATE(1,rover_8d.omega) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_272(DATA *data, threadData_t *threadData);


/*
equation index: 65
type: SIMPLE_ASSIGN
rover_8d.Iq = $START.rover_8d.Iq
*/
void RoverExample_Components_Rover_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */) = (data->modelData->realVarsData[8] /* rover_8d.Iq STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_255(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_239(DATA *data, threadData_t *threadData);


/*
equation index: 68
type: SIMPLE_ASSIGN
rover_8d.emi.b_motor[3] = 9.999999999999998e-8 * rover_8d.emi.eta_motor * (3.0 * RoverExample.Utils.dot3({0.0, (rover_8d.emi.mag_motor + rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * cos(rover_8d.lambda), (rover_8d.emi.mag_motor + rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * sin(rover_8d.lambda)}, rover_8d.emi.x_motor) * rover_8d.emi.x_motor[3] / rover_8d.emi.dist_motor ^ 5.0 + ((-rover_8d.emi.mag_motor) - rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * sin(rover_8d.lambda) / rover_8d.emi.dist_motor ^ 3.0)
*/
void RoverExample_Components_Rover_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  real_array tmp13;
  real_array tmp14;
  modelica_real tmp15;
  array_alloc_scalar_real_array(&tmp13, 3, (modelica_real)0.0, (modelica_real)((data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */) + (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */))) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */))), (modelica_real)((data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */) + (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */))) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */))));
  real_array_create(&tmp14, ((modelica_real*)&((&data->simulationInfo->realParameter[96] /* rover_8d.emi.x_motor[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  tmp15 = (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[187]] /* rover_8d.emi.b_motor[3] variable */) = (9.999999999999998e-8) * (((data->simulationInfo->realParameter[91] /* rover_8d.emi.eta_motor PARAM */)) * ((3.0) * ((omc_RoverExample_Utils_dot3(threadData, tmp13, tmp14)) * (DIVISION_SIM((data->simulationInfo->realParameter[98] /* rover_8d.emi.x_motor[3] PARAM */),real_int_pow(threadData, (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */), 5),"rover_8d.emi.dist_motor ^ 5.0",equationIndexes))) + ((-(data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */)) - (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */)) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))))) * (DIVISION_SIM(sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */)),(tmp15 * tmp15 * tmp15),"rover_8d.emi.dist_motor ^ 3.0",equationIndexes))));
  TRACE_POP
}

/*
equation index: 69
type: SIMPLE_ASSIGN
rover_8d.emi.b_motor[2] = 9.999999999999998e-8 * rover_8d.emi.eta_motor * (3.0 * RoverExample.Utils.dot3({0.0, (rover_8d.emi.mag_motor + rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * cos(rover_8d.lambda), (rover_8d.emi.mag_motor + rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * sin(rover_8d.lambda)}, rover_8d.emi.x_motor) * rover_8d.emi.x_motor[2] / rover_8d.emi.dist_motor ^ 5.0 + ((-rover_8d.emi.mag_motor) - rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * cos(rover_8d.lambda) / rover_8d.emi.dist_motor ^ 3.0)
*/
void RoverExample_Components_Rover_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  real_array tmp16;
  real_array tmp17;
  modelica_real tmp18;
  array_alloc_scalar_real_array(&tmp16, 3, (modelica_real)0.0, (modelica_real)((data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */) + (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */))) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */))), (modelica_real)((data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */) + (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */))) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */))));
  real_array_create(&tmp17, ((modelica_real*)&((&data->simulationInfo->realParameter[96] /* rover_8d.emi.x_motor[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  tmp18 = (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[186]] /* rover_8d.emi.b_motor[2] variable */) = (9.999999999999998e-8) * (((data->simulationInfo->realParameter[91] /* rover_8d.emi.eta_motor PARAM */)) * ((3.0) * ((omc_RoverExample_Utils_dot3(threadData, tmp16, tmp17)) * (DIVISION_SIM((data->simulationInfo->realParameter[97] /* rover_8d.emi.x_motor[2] PARAM */),real_int_pow(threadData, (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */), 5),"rover_8d.emi.dist_motor ^ 5.0",equationIndexes))) + ((-(data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */)) - (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */)) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))))) * (DIVISION_SIM(cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */)),(tmp18 * tmp18 * tmp18),"rover_8d.emi.dist_motor ^ 3.0",equationIndexes))));
  TRACE_POP
}

/*
equation index: 70
type: SIMPLE_ASSIGN
rover_8d.emi.b_motor[1] = 2.9999999999999993e-7 * rover_8d.emi.eta_motor * RoverExample.Utils.dot3({0.0, (rover_8d.emi.mag_motor + rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * cos(rover_8d.lambda), (rover_8d.emi.mag_motor + rover_8d.emi.Nw * rover_8d.Iq * rover_8d.emi.A) * sin(rover_8d.lambda)}, rover_8d.emi.x_motor) * rover_8d.emi.x_motor[1] / rover_8d.emi.dist_motor ^ 5.0
*/
void RoverExample_Components_Rover_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
  real_array tmp19;
  real_array tmp20;
  array_alloc_scalar_real_array(&tmp19, 3, (modelica_real)0.0, (modelica_real)((data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */) + (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */))) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */))), (modelica_real)((data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */) + (((data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */))) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */))) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */))));
  real_array_create(&tmp20, ((modelica_real*)&((&data->simulationInfo->realParameter[96] /* rover_8d.emi.x_motor[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[185]] /* rover_8d.emi.b_motor[1] variable */) = (2.9999999999999993e-7) * (((data->simulationInfo->realParameter[91] /* rover_8d.emi.eta_motor PARAM */)) * ((omc_RoverExample_Utils_dot3(threadData, tmp19, tmp20)) * (DIVISION_SIM((data->simulationInfo->realParameter[96] /* rover_8d.emi.x_motor[1] PARAM */),real_int_pow(threadData, (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */), 5),"rover_8d.emi.dist_motor ^ 5.0",equationIndexes))));
  TRACE_POP
}

/*
equation index: 71
type: SIMPLE_ASSIGN
rover_8d.alpha_rr = $START.rover_8d.alpha_rr
*/
void RoverExample_Components_Rover_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* rover_8d.alpha_rr STATE(1) */) = (data->modelData->realVarsData[12] /* rover_8d.alpha_rr STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_287(DATA *data, threadData_t *threadData);


/*
equation index: 73
type: SIMPLE_ASSIGN
rover_8d.alpha_rl = $START.rover_8d.alpha_rl
*/
void RoverExample_Components_Rover_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* rover_8d.alpha_rl STATE(1) */) = (data->modelData->realVarsData[11] /* rover_8d.alpha_rl STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_290(DATA *data, threadData_t *threadData);


/*
equation index: 75
type: SIMPLE_ASSIGN
rover_8d.alpha_fr = $START.rover_8d.alpha_fr
*/
void RoverExample_Components_Rover_eqFunction_75(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* rover_8d.alpha_fr STATE(1) */) = (data->modelData->realVarsData[10] /* rover_8d.alpha_fr STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_293(DATA *data, threadData_t *threadData);


/*
equation index: 77
type: SIMPLE_ASSIGN
rover_8d.alpha_fl = $START.rover_8d.alpha_fl
*/
void RoverExample_Components_Rover_eqFunction_77(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* rover_8d.alpha_fl STATE(1) */) = (data->modelData->realVarsData[9] /* rover_8d.alpha_fl STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_295(DATA *data, threadData_t *threadData);


/*
equation index: 79
type: SIMPLE_ASSIGN
rover_8d.kappa_rr = $START.rover_8d.kappa_rr
*/
void RoverExample_Components_Rover_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */) = (data->modelData->realVarsData[17] /* rover_8d.kappa_rr STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_311(DATA *data, threadData_t *threadData);


/*
equation index: 81
type: SIMPLE_ASSIGN
rover_8d.kappa_rl = $START.rover_8d.kappa_rl
*/
void RoverExample_Components_Rover_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */) = (data->modelData->realVarsData[16] /* rover_8d.kappa_rl STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_314(DATA *data, threadData_t *threadData);


/*
equation index: 83
type: SIMPLE_ASSIGN
rover_8d.kappa_fr = $START.rover_8d.kappa_fr
*/
void RoverExample_Components_Rover_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */) = (data->modelData->realVarsData[15] /* rover_8d.kappa_fr STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_317(DATA *data, threadData_t *threadData);


/*
equation index: 85
type: SIMPLE_ASSIGN
rover_8d.kappa_fl = $START.rover_8d.kappa_fl
*/
void RoverExample_Components_Rover_eqFunction_85(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */) = (data->modelData->realVarsData[14] /* rover_8d.kappa_fl STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_320(DATA *data, threadData_t *threadData);


/*
equation index: 87
type: SIMPLE_ASSIGN
rover_8d.omega_rr = $START.rover_8d.omega_rr
*/
void RoverExample_Components_Rover_eqFunction_87(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* rover_8d.omega_rr STATE(1) */) = (data->modelData->realVarsData[22] /* rover_8d.omega_rr STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 88
type: SIMPLE_ASSIGN
rover_8d.omega_rl = $START.rover_8d.omega_rl
*/
void RoverExample_Components_Rover_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* rover_8d.omega_rl STATE(1) */) = (data->modelData->realVarsData[21] /* rover_8d.omega_rl STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 89
type: SIMPLE_ASSIGN
rover_8d.omega_fr = $START.rover_8d.omega_fr
*/
void RoverExample_Components_Rover_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* rover_8d.omega_fr STATE(1) */) = (data->modelData->realVarsData[20] /* rover_8d.omega_fr STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 90
type: SIMPLE_ASSIGN
rover_8d.omega_fl = $START.rover_8d.omega_fl
*/
void RoverExample_Components_Rover_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* rover_8d.omega_fl STATE(1) */) = (data->modelData->realVarsData[19] /* rover_8d.omega_fl STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_273(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_274(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_275(DATA *data, threadData_t *threadData);


/*
equation index: 94
type: SIMPLE_ASSIGN
rover_8d.r = $START.rover_8d.r
*/
void RoverExample_Components_Rover_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */) = (data->modelData->realVarsData[27] /* rover_8d.r STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_278(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_254(DATA *data, threadData_t *threadData);


/*
equation index: 97
type: SIMPLE_ASSIGN
rover_8d.p = $START.rover_8d.p
*/
void RoverExample_Components_Rover_eqFunction_97(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,97};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */) = (data->modelData->realVarsData[23] /* rover_8d.p STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_261(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_252(DATA *data, threadData_t *threadData);


/*
equation index: 100
type: SIMPLE_ASSIGN
rover_8d.psi = $START.rover_8d.psi
*/
void RoverExample_Components_Rover_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */) = (data->modelData->realVarsData[25] /* rover_8d.psi STATE(1,rover_8d.r) */).attribute .start;
  TRACE_POP
}

/*
equation index: 101
type: SIMPLE_ASSIGN
psi_meas = -3.14159265 + mod(rover_8d.psi + 3.14159265, 6.2831853)
*/
void RoverExample_Components_Rover_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  modelica_real tmp21;
  tmp21 = 6.2831853;
  if (tmp21 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(rover_8d.psi + 3.14159265, 6.2831853)");}
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* psi_meas variable */) = -3.14159265 + modelica_real_mod((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */) + 3.14159265, tmp21);
  TRACE_POP
}

/*
equation index: 102
type: SIMPLE_ASSIGN
rover_8d.theta = $START.rover_8d.theta
*/
void RoverExample_Components_Rover_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */) = (data->modelData->realVarsData[28] /* rover_8d.theta STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_262(DATA *data, threadData_t *threadData);


/*
equation index: 104
type: SIMPLE_ASSIGN
rover_8d.phi = $START.rover_8d.phi
*/
void RoverExample_Components_Rover_eqFunction_104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,104};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */) = (data->modelData->realVarsData[24] /* rover_8d.phi STATE(1,rover_8d.p) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_263(DATA *data, threadData_t *threadData);


/*
equation index: 106
type: ARRAY_CALL_ASSIGN

rover_8d.C_n2b = transpose(RoverExample.Utils.eul2rot({rover_8d.phi, rover_8d.theta, mod(rover_8d.psi + 3.14159265, 6.2831853) - 3.14159265}))
*/
void RoverExample_Components_Rover_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  real_array tmp22;
  modelica_real tmp23;
  real_array tmp24;
  real_array tmp25;
  real_array tmp26;
  tmp23 = 6.2831853;
  if (tmp23 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(rover_8d.psi + 3.14159265, 6.2831853)");}
  array_alloc_scalar_real_array(&tmp22, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */), (modelica_real)modelica_real_mod((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */) + 3.14159265, tmp23) - 3.14159265);
  tmp24 = omc_RoverExample_Utils_eul2rot(threadData, tmp22);
  transpose_alloc_real_array(&tmp24, &tmp25);
  real_array_create(&tmp26, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[154]] /* rover_8d.C_n2b[1,1] variable */))[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp25, tmp26);
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_258(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_259(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_257(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_235(DATA *data, threadData_t *threadData);


/*
equation index: 111
type: SIMPLE_ASSIGN
rover_8d.mag.b_earth[3] = rover_8d.mag.C_n2b[3,1] * rover_8d.mag.b_earth0 * sin(1.570796325 - rover_8d.mag.lat0) + (-2.0) * rover_8d.mag.C_n2b[3,3] * rover_8d.mag.b_earth0 * cos(1.570796325 - rover_8d.mag.lat0)
*/
void RoverExample_Components_Rover_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[210]] /* rover_8d.mag.b_earth[3] variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[205]] /* rover_8d.mag.C_n2b[3,1] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * (sin(1.570796325 - (data->simulationInfo->realParameter[116] /* rover_8d.mag.lat0 PARAM */)))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[207]] /* rover_8d.mag.C_n2b[3,3] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * (cos(1.570796325 - (data->simulationInfo->realParameter[116] /* rover_8d.mag.lat0 PARAM */)))));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_241(DATA *data, threadData_t *threadData);


/*
equation index: 113
type: SIMPLE_ASSIGN
rover_8d.mag.b_earth[1] = rover_8d.mag.C_n2b[1,1] * rover_8d.mag.b_earth0 * sin(1.570796325 - rover_8d.mag.lat0) + (-2.0) * rover_8d.mag.C_n2b[1,3] * rover_8d.mag.b_earth0 * cos(1.570796325 - rover_8d.mag.lat0)
*/
void RoverExample_Components_Rover_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[208]] /* rover_8d.mag.b_earth[1] variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[199]] /* rover_8d.mag.C_n2b[1,1] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * (sin(1.570796325 - (data->simulationInfo->realParameter[116] /* rover_8d.mag.lat0 PARAM */)))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[201]] /* rover_8d.mag.C_n2b[1,3] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * (cos(1.570796325 - (data->simulationInfo->realParameter[116] /* rover_8d.mag.lat0 PARAM */)))));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_242(DATA *data, threadData_t *threadData);


/*
equation index: 115
type: SIMPLE_ASSIGN
rover_8d.mag.b_earth[2] = rover_8d.mag.C_n2b[2,1] * rover_8d.mag.b_earth0 * sin(1.570796325 - rover_8d.mag.lat0) + (-2.0) * rover_8d.mag.C_n2b[2,3] * rover_8d.mag.b_earth0 * cos(1.570796325 - rover_8d.mag.lat0)
*/
void RoverExample_Components_Rover_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[209]] /* rover_8d.mag.b_earth[2] variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[202]] /* rover_8d.mag.C_n2b[2,1] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * (sin(1.570796325 - (data->simulationInfo->realParameter[116] /* rover_8d.mag.lat0 PARAM */)))) + (-2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[204]] /* rover_8d.mag.C_n2b[2,3] variable */)) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * (cos(1.570796325 - (data->simulationInfo->realParameter[116] /* rover_8d.mag.lat0 PARAM */)))));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_240(DATA *data, threadData_t *threadData);


/*
equation index: 117
type: SIMPLE_ASSIGN
rover_8d.vy = $START.rover_8d.vy
*/
void RoverExample_Components_Rover_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) = (data->modelData->realVarsData[30] /* rover_8d.vy STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_264(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_247(DATA *data, threadData_t *threadData);


/*
equation index: 120
type: SIMPLE_ASSIGN
rover_8d.vx = $START.rover_8d.vx
*/
void RoverExample_Components_Rover_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) = (data->modelData->realVarsData[29] /* rover_8d.vx STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_265(DATA *data, threadData_t *threadData);


/*
equation index: 122
type: SIMPLE_ASSIGN
$DER.rover_8d.y = rover_8d.vx * sin(rover_8d.psi) + rover_8d.vy * cos(rover_8d.psi)
*/
void RoverExample_Components_Rover_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* der(rover_8d.y) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */))) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */)));
  TRACE_POP
}

/*
equation index: 123
type: SIMPLE_ASSIGN
$DER.rover_8d.x = rover_8d.vx * cos(rover_8d.psi) - rover_8d.vy * sin(rover_8d.psi)
*/
void RoverExample_Components_Rover_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* der(rover_8d.x) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */))));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_249(DATA *data, threadData_t *threadData);


/*
equation index: 125
type: SIMPLE_ASSIGN
rover_8d.vs_rr = rover_8d.vx_rr * sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + tan(rover_8d.alpha_rr_bnd) ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  tmp27 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  tmp28 = tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[181]] /* rover_8d.alpha_rr_bnd variable */));
  tmp29 = (tmp27 * tmp27) + (tmp28 * tmp28);
  if(!(tmp29 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + tan(rover_8d.alpha_rr_bnd) ^ 2.0) was %g should be >= 0", tmp29);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (sqrt(tmp29));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_313(DATA *data, threadData_t *threadData);


/*
equation index: 127
type: SIMPLE_ASSIGN
rover_8d.vs_fr = rover_8d.vx_rr * sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + tan(rover_8d.alpha_fr_bnd) ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  tmp30 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  tmp31 = tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* rover_8d.alpha_fr_bnd variable */));
  tmp32 = (tmp30 * tmp30) + (tmp31 * tmp31);
  if(!(tmp32 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + tan(rover_8d.alpha_fr_bnd) ^ 2.0) was %g should be >= 0", tmp32);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (sqrt(tmp32));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_319(DATA *data, threadData_t *threadData);


/*
equation index: 129
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rr = (-abs(rover_8d.vx_rr)) * tan(rover_8d.alpha_rr_bnd) / (rover_8d.Lrely * RoverExample.Utils.clip(tanh(abs(rover_8d.vx_rr)), 0.001, 1.0)) - tanh(abs(rover_8d.vy_rr)) * rover_8d.vy_rr / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,129};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* der(rover_8d.alpha_rr) STATE_DER */) = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)))) * (DIVISION_SIM(tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[181]] /* rover_8d.alpha_rr_bnd variable */)),((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (omc_RoverExample_Utils_clip(threadData, tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */))), 0.001, 1.0)),"rover_8d.Lrely * RoverExample.Utils.clip(tanh(abs(rover_8d.vx_rr)), 0.001, 1.0)",equationIndexes)) - ((tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely",equationIndexes)));
  TRACE_POP
}

/*
equation index: 130
type: SIMPLE_ASSIGN
rover_8d.vy_fr = cos(rover_8d.delta) * (rover_8d.vy + rover_8d.l_front * rover_8d.r) - sin(rover_8d.delta) * rover_8d.vx_rr
*/
void RoverExample_Components_Rover_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */) = (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - ((sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)));
  TRACE_POP
}

/*
equation index: 131
type: SIMPLE_ASSIGN
rover_8d.vx_fr = cos(rover_8d.delta) * rover_8d.vx_rr + sin(rover_8d.delta) * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */) = (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) + (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 132
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fr = (-abs(rover_8d.vx_fr)) * tan(rover_8d.alpha_fr_bnd) / (rover_8d.Lrely * RoverExample.Utils.clip(tanh(abs(rover_8d.vx_fr)), 0.001, 1.0)) - tanh(abs(rover_8d.vy_fr)) * rover_8d.vy_fr / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* der(rover_8d.alpha_fr) STATE_DER */) = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */)))) * (DIVISION_SIM(tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* rover_8d.alpha_fr_bnd variable */)),((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (omc_RoverExample_Utils_clip(threadData, tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))), 0.001, 1.0)),"rover_8d.Lrely * RoverExample.Utils.clip(tanh(abs(rover_8d.vx_fr)), 0.001, 1.0)",equationIndexes)) - ((tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely",equationIndexes)));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_244(DATA *data, threadData_t *threadData);


/*
equation index: 134
type: SIMPLE_ASSIGN
rover_8d.vs_rl = rover_8d.vx_rl * sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + tan(rover_8d.alpha_rl_bnd) ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
  modelica_real tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  tmp33 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  tmp34 = tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[180]] /* rover_8d.alpha_rl_bnd variable */));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + tan(rover_8d.alpha_rl_bnd) ^ 2.0) was %g should be >= 0", tmp35);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (sqrt(tmp35));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_316(DATA *data, threadData_t *threadData);


/*
equation index: 136
type: SIMPLE_ASSIGN
rover_8d.vs_fl = rover_8d.vx_rl * sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + tan(rover_8d.alpha_fl_bnd) ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
  modelica_real tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  tmp36 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  tmp37 = tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[178]] /* rover_8d.alpha_fl_bnd variable */));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + tan(rover_8d.alpha_fl_bnd) ^ 2.0) was %g should be >= 0", tmp38);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (sqrt(tmp38));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_322(DATA *data, threadData_t *threadData);


void RoverExample_Components_Rover_eqFunction_138(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_139(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_140(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_141(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_142(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_143(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_144(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_145(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_146(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_147(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_148(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_149(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_150(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_151(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_152(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_153(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_154(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_155(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_159(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_158(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_157(DATA*, threadData_t*);
void RoverExample_Components_Rover_eqFunction_156(DATA*, threadData_t*);
/*
equation index: 160
indexNonlinear: 0
type: NONLINEAR

vars: {rover_8d.fz_fr, rover_8d.fz_rr, rover_8d.fz_rl, rover_8d.fz_fl}
eqns: {138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 159, 158, 157, 156}
*/
void RoverExample_Components_Rover_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
  int retValue;
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving nonlinear system 160 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */);
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[1] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */);
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[2] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */);
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[3] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */);
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,160};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 160 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */) = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */) = data->simulationInfo->nonlinearSystemData[0].nlsx[1];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */) = data->simulationInfo->nonlinearSystemData[0].nlsx[2];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */) = data->simulationInfo->nonlinearSystemData[0].nlsx[3];
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_347(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_346(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_349(DATA *data, threadData_t *threadData);


/*
equation index: 164
type: SIMPLE_ASSIGN
$DER.rover_8d.p = (rover_8d.mass_sprung * (9.80665 * sin(rover_8d.phi) - rover_8d.ay * cos(rover_8d.phi)) * rover_8d.hs + (-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.I_xx
*/
void RoverExample_Components_Rover_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* der(rover_8d.p) STATE_DER */) = DIVISION_SIM((((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((9.80665) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)))))) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[65] /* rover_8d.I_xx PARAM */),"rover_8d.I_xx",equationIndexes);
  TRACE_POP
}

/*
equation index: 165
type: SIMPLE_ASSIGN
$DER.rover_8d.r = (0.5 * (rover_8d.Fx_fl * cos(-rover_8d.delta) + rover_8d.Fy_fl * sin(-rover_8d.delta) + rover_8d.Fx_rl - rover_8d.Fx_rr - rover_8d.Fy_fr * sin(-rover_8d.delta) - rover_8d.Fx_fr * cos(-rover_8d.delta)) * rover_8d.tw + rover_8d.l_front * (rover_8d.Fy_fl * cos(-rover_8d.delta) - rover_8d.Fx_fl * sin(-rover_8d.delta)) + rover_8d.l_front * (rover_8d.Fy_fr * cos(-rover_8d.delta) - rover_8d.Fx_fr * sin(-rover_8d.delta)) - rover_8d.l_rear * (rover_8d.Fy_rl + rover_8d.Fy_rr)) / rover_8d.I_zz
*/
void RoverExample_Components_Rover_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* der(rover_8d.r) STATE_DER */) = DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * (cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[165]] /* rover_8d.Fx_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[166]] /* rover_8d.Fx_rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * (cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))))) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * (sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * (sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))))) - (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[169]] /* rover_8d.Fy_rl variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[170]] /* rover_8d.Fy_rr variable */))),(data->simulationInfo->realParameter[66] /* rover_8d.I_zz PARAM */),"rover_8d.I_zz",equationIndexes);
  TRACE_POP
}

/*
equation index: 166
type: SIMPLE_ASSIGN
$DER.rover_8d.vy = rover_8d.ay + (rover_8d.l_rear * rover_8d.mass_unsprung_rear - rover_8d.l_front * rover_8d.mass_unsprung_front) * $DER.rover_8d.r / rover_8d.mass_total - rover_8d.vx * rover_8d.r
*/
void RoverExample_Components_Rover_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* der(rover_8d.vy) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */) + (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) - (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* der(rover_8d.r) STATE_DER */),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_350(DATA *data, threadData_t *threadData);


/*
equation index: 180
type: LINEAR

<var>rover_8d.thr</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_180(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,180};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { (data->localData[1]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 180 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 0, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,180};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 180 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) = aux_x[0];

  TRACE_POP
}

/*
equation index: 181
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rl = (-abs(rover_8d.vx_rl)) * tan(rover_8d.alpha_rl_bnd) / (RoverExample.Utils.clip(tanh(abs(rover_8d.vx_rl)), 0.001, 1.0) * rover_8d.Lrely) - tanh(abs(rover_8d.vy_rr)) * rover_8d.vy_rr / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,181};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* der(rover_8d.alpha_rl) STATE_DER */) = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)))) * (DIVISION_SIM(tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[180]] /* rover_8d.alpha_rl_bnd variable */)),(omc_RoverExample_Utils_clip(threadData, tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */))), 0.001, 1.0)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"RoverExample.Utils.clip(tanh(abs(rover_8d.vx_rl)), 0.001, 1.0) * rover_8d.Lrely",equationIndexes)) - ((tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely",equationIndexes)));
  TRACE_POP
}

/*
equation index: 182
type: SIMPLE_ASSIGN
rover_8d.vy_fl = cos(rover_8d.delta) * (rover_8d.vy + rover_8d.l_front * rover_8d.r) - sin(rover_8d.delta) * rover_8d.vx_rl
*/
void RoverExample_Components_Rover_eqFunction_182(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,182};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */) = (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - ((sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)));
  TRACE_POP
}

/*
equation index: 183
type: SIMPLE_ASSIGN
rover_8d.vx_fl = cos(rover_8d.delta) * rover_8d.vx_rl + sin(rover_8d.delta) * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,183};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */) = (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) + (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 184
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fl = (-abs(rover_8d.vx_fl)) * tan(rover_8d.alpha_fl_bnd) / (rover_8d.Lrely * RoverExample.Utils.clip(tanh(abs(rover_8d.vx_fl)), 0.001, 1.0)) - tanh(abs(rover_8d.vy_fl)) * rover_8d.vy_fl / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* der(rover_8d.alpha_fl) STATE_DER */) = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */)))) * (DIVISION_SIM(tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[178]] /* rover_8d.alpha_fl_bnd variable */)),((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (omc_RoverExample_Utils_clip(threadData, tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))), 0.001, 1.0)),"rover_8d.Lrely * RoverExample.Utils.clip(tanh(abs(rover_8d.vx_fl)), 0.001, 1.0)",equationIndexes)) - ((tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely",equationIndexes)));
  TRACE_POP
}

/*
equation index: 185
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rr = (rover_8d.r_tire * rover_8d.omega_rr + 0.5 * rover_8d.tw * rover_8d.r - rover_8d.vx) / rover_8d.Lrelx - abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r) * rover_8d.kappa_rr / (rover_8d.Lrelx * RoverExample.Utils.clip(tanh(abs(rover_8d.vx)), 0.001, 1.0))
*/
void RoverExample_Components_Rover_eqFunction_185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,185};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* der(rover_8d.kappa_rr) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* rover_8d.omega_rr STATE(1) */)) + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */),(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx",equationIndexes) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */),((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (omc_RoverExample_Utils_clip(threadData, tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */))), 0.001, 1.0)),"rover_8d.Lrelx * RoverExample.Utils.clip(tanh(abs(rover_8d.vx)), 0.001, 1.0)",equationIndexes)));
  TRACE_POP
}

/*
equation index: 186
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rl = (rover_8d.r_tire * rover_8d.omega_rl + (-0.5) * rover_8d.tw * rover_8d.r - rover_8d.vx) / rover_8d.Lrelx - abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r) * rover_8d.kappa_rl / (rover_8d.Lrelx * RoverExample.Utils.clip(tanh(abs(rover_8d.vx)), 0.001, 1.0))
*/
void RoverExample_Components_Rover_eqFunction_186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,186};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* der(rover_8d.kappa_rl) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* rover_8d.omega_rl STATE(1) */)) + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */),(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx",equationIndexes) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */),((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (omc_RoverExample_Utils_clip(threadData, tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */))), 0.001, 1.0)),"rover_8d.Lrelx * RoverExample.Utils.clip(tanh(abs(rover_8d.vx)), 0.001, 1.0)",equationIndexes)));
  TRACE_POP
}

/*
equation index: 187
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fr = (rover_8d.r_tire * rover_8d.omega_fr + 0.5 * rover_8d.tw * rover_8d.r - rover_8d.vx) / rover_8d.Lrelx - abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r) * rover_8d.kappa_fr / (rover_8d.Lrelx * RoverExample.Utils.clip(tanh(abs(rover_8d.vx)), 0.001, 1.0))
*/
void RoverExample_Components_Rover_eqFunction_187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,187};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* der(rover_8d.kappa_fr) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* rover_8d.omega_fr STATE(1) */)) + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */),(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx",equationIndexes) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */),((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (omc_RoverExample_Utils_clip(threadData, tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */))), 0.001, 1.0)),"rover_8d.Lrelx * RoverExample.Utils.clip(tanh(abs(rover_8d.vx)), 0.001, 1.0)",equationIndexes)));
  TRACE_POP
}

/*
equation index: 188
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fl = (rover_8d.r_tire * rover_8d.omega_fl + (-0.5) * rover_8d.tw * rover_8d.r - rover_8d.vx) / rover_8d.Lrelx - abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r) * rover_8d.kappa_fl / (rover_8d.Lrelx * RoverExample.Utils.clip(tanh(abs(rover_8d.vx)), 0.001, 1.0))
*/
void RoverExample_Components_Rover_eqFunction_188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,188};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* der(rover_8d.kappa_fl) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* rover_8d.omega_fl STATE(1) */)) + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */),(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx",equationIndexes) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */),((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (omc_RoverExample_Utils_clip(threadData, tanh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */))), 0.001, 1.0)),"rover_8d.Lrelx * RoverExample.Utils.clip(tanh(abs(rover_8d.vx)), 0.001, 1.0)",equationIndexes)));
  TRACE_POP
}

/*
equation index: 189
type: SIMPLE_ASSIGN
$PRE.rover_8d.delta_cmd = $START.rover_8d.delta_cmd
*/
void RoverExample_Components_Rover_eqFunction_189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,189};
  (data->simulationInfo->realVarsPre[245] /* rover_8d.delta_cmd DISCRETE */) = (data->modelData->realVarsData[245] /* rover_8d.delta_cmd DISCRETE */).attribute .start;
  TRACE_POP
}

/*
equation index: 190
type: SIMPLE_ASSIGN
rover_8d.delta_cmd = $PRE.rover_8d.delta_cmd
*/
void RoverExample_Components_Rover_eqFunction_190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,190};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[245]] /* rover_8d.delta_cmd DISCRETE */) = (data->simulationInfo->realVarsPre[245] /* rover_8d.delta_cmd DISCRETE */);
  TRACE_POP
}

/*
equation index: 191
type: SIMPLE_ASSIGN
$DER.rover_8d.delta = ($PRE.rover_8d.delta_cmd - rover_8d.delta) / rover_8d.tau_servo
*/
void RoverExample_Components_Rover_eqFunction_191(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,191};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* der(rover_8d.delta) STATE_DER */) = DIVISION_SIM((data->simulationInfo->realVarsPre[245] /* rover_8d.delta_cmd DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */),(data->simulationInfo->realParameter[125] /* rover_8d.tau_servo PARAM */),"rover_8d.tau_servo",equationIndexes);
  TRACE_POP
}

/*
equation index: 192
type: SIMPLE_ASSIGN
$PRE.rover_8d.D = $START.rover_8d.D
*/
void RoverExample_Components_Rover_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
  (data->simulationInfo->realVarsPre[244] /* rover_8d.D DISCRETE */) = (data->modelData->realVarsData[244] /* rover_8d.D DISCRETE */).attribute .start;
  TRACE_POP
}

/*
equation index: 193
type: SIMPLE_ASSIGN
rover_8d.D = $PRE.rover_8d.D
*/
void RoverExample_Components_Rover_eqFunction_193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,193};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[244]] /* rover_8d.D DISCRETE */) = (data->simulationInfo->realVarsPre[244] /* rover_8d.D DISCRETE */);
  TRACE_POP
}

/*
equation index: 194
type: SIMPLE_ASSIGN
rover_8d.Vq = 1.224744871391589 * rover_8d.Vs * RoverExample.Utils.clip($PRE.rover_8d.D, (rover_8d.R_phi * rover_8d.b / rover_8d.Kt_q + rover_8d.Kb_q) / (1.224744871391589 * rover_8d.Vs) * 0.001 / rover_8d.r_tire * rover_8d.gratio, 1.0)
*/
void RoverExample_Components_Rover_eqFunction_194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,194};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[177]] /* rover_8d.Vq variable */) = (1.224744871391589) * (((data->simulationInfo->realParameter[78] /* rover_8d.Vs PARAM */)) * (omc_RoverExample_Utils_clip(threadData, (data->simulationInfo->realVarsPre[244] /* rover_8d.D DISCRETE */), (DIVISION_SIM(DIVISION_SIM(((data->simulationInfo->realParameter[77] /* rover_8d.R_phi PARAM */)) * ((data->simulationInfo->realParameter[81] /* rover_8d.b PARAM */)),(data->simulationInfo->realParameter[71] /* rover_8d.Kt_q PARAM */),"rover_8d.Kt_q",equationIndexes) + (data->simulationInfo->realParameter[69] /* rover_8d.Kb_q PARAM */),(1.224744871391589) * ((data->simulationInfo->realParameter[78] /* rover_8d.Vs PARAM */)),"1.224744871391589 * rover_8d.Vs",equationIndexes)) * ((DIVISION_SIM(0.001,(data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */),"rover_8d.r_tire",equationIndexes)) * ((data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */))), 1.0)));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_376(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_253(DATA *data, threadData_t *threadData);


/*
equation index: 197
type: SIMPLE_ASSIGN
$PRE.rover_8d.rollover_detected = $START.rover_8d.rollover_detected
*/
void RoverExample_Components_Rover_eqFunction_197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,197};
  (data->simulationInfo->integerVarsPre[2] /* rover_8d.rollover_detected DISCRETE */) = (data->modelData->integerVarsData[2] /* rover_8d.rollover_detected DISCRETE */).attribute .start;
  TRACE_POP
}

/*
equation index: 198
type: SIMPLE_ASSIGN
rover_8d.rollover_detected = $PRE.rover_8d.rollover_detected
*/
void RoverExample_Components_Rover_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* rover_8d.rollover_detected DISCRETE */) = (data->simulationInfo->integerVarsPre[2] /* rover_8d.rollover_detected DISCRETE */);
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_352(DATA *data, threadData_t *threadData);


/*
equation index: 200
type: SIMPLE_ASSIGN
rover_8d.y = $START.rover_8d.y
*/
void RoverExample_Components_Rover_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* rover_8d.y STATE(1) */) = (data->modelData->realVarsData[33] /* rover_8d.y STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_266(DATA *data, threadData_t *threadData);


/*
equation index: 202
type: SIMPLE_ASSIGN
rover_8d.x = $START.rover_8d.x
*/
void RoverExample_Components_Rover_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* rover_8d.x STATE(1) */) = (data->modelData->realVarsData[32] /* rover_8d.x STATE(1) */).attribute .start;
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_267(DATA *data, threadData_t *threadData);


/*
equation index: 204
type: SIMPLE_ASSIGN
$PRE.rover_8d.turn_radius = $START.rover_8d.turn_radius
*/
void RoverExample_Components_Rover_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
  (data->simulationInfo->realVarsPre[246] /* rover_8d.turn_radius DISCRETE */) = (data->modelData->realVarsData[246] /* rover_8d.turn_radius DISCRETE */).attribute .start;
  TRACE_POP
}

/*
equation index: 205
type: SIMPLE_ASSIGN
rover_8d.turn_radius = $PRE.rover_8d.turn_radius
*/
void RoverExample_Components_Rover_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[246]] /* rover_8d.turn_radius DISCRETE */) = (data->simulationInfo->realVarsPre[246] /* rover_8d.turn_radius DISCRETE */);
  TRACE_POP
}

/*
equation index: 206
type: SIMPLE_ASSIGN
$PRE.rover_3d.rollover_detected = $START.rover_3d.rollover_detected
*/
void RoverExample_Components_Rover_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
  (data->simulationInfo->integerVarsPre[1] /* rover_3d.rollover_detected DISCRETE */) = (data->modelData->integerVarsData[1] /* rover_3d.rollover_detected DISCRETE */).attribute .start;
  TRACE_POP
}

/*
equation index: 207
type: SIMPLE_ASSIGN
rover_3d.rollover_detected = $PRE.rover_3d.rollover_detected
*/
void RoverExample_Components_Rover_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* rover_3d.rollover_detected DISCRETE */) = (data->simulationInfo->integerVarsPre[1] /* rover_3d.rollover_detected DISCRETE */);
  TRACE_POP
}
OMC_DISABLE_OPT
void RoverExample_Components_Rover_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RoverExample_Components_Rover_eqFunction_1(data, threadData);
  RoverExample_Components_Rover_eqFunction_2(data, threadData);
  RoverExample_Components_Rover_eqFunction_3(data, threadData);
  RoverExample_Components_Rover_eqFunction_4(data, threadData);
  RoverExample_Components_Rover_eqFunction_5(data, threadData);
  RoverExample_Components_Rover_eqFunction_6(data, threadData);
  RoverExample_Components_Rover_eqFunction_7(data, threadData);
  RoverExample_Components_Rover_eqFunction_8(data, threadData);
  RoverExample_Components_Rover_eqFunction_9(data, threadData);
  RoverExample_Components_Rover_eqFunction_10(data, threadData);
  RoverExample_Components_Rover_eqFunction_11(data, threadData);
  RoverExample_Components_Rover_eqFunction_12(data, threadData);
  RoverExample_Components_Rover_eqFunction_13(data, threadData);
  RoverExample_Components_Rover_eqFunction_14(data, threadData);
  RoverExample_Components_Rover_eqFunction_15(data, threadData);
  RoverExample_Components_Rover_eqFunction_16(data, threadData);
  RoverExample_Components_Rover_eqFunction_232(data, threadData);
  RoverExample_Components_Rover_eqFunction_234(data, threadData);
  RoverExample_Components_Rover_eqFunction_233(data, threadData);
  RoverExample_Components_Rover_eqFunction_210(data, threadData);
  RoverExample_Components_Rover_eqFunction_21(data, threadData);
  RoverExample_Components_Rover_eqFunction_22(data, threadData);
  RoverExample_Components_Rover_eqFunction_23(data, threadData);
  RoverExample_Components_Rover_eqFunction_24(data, threadData);
  RoverExample_Components_Rover_eqFunction_25(data, threadData);
  RoverExample_Components_Rover_eqFunction_26(data, threadData);
  RoverExample_Components_Rover_eqFunction_217(data, threadData);
  RoverExample_Components_Rover_eqFunction_216(data, threadData);
  RoverExample_Components_Rover_eqFunction_29(data, threadData);
  RoverExample_Components_Rover_eqFunction_30(data, threadData);
  RoverExample_Components_Rover_eqFunction_31(data, threadData);
  RoverExample_Components_Rover_eqFunction_32(data, threadData);
  RoverExample_Components_Rover_eqFunction_226(data, threadData);
  RoverExample_Components_Rover_eqFunction_34(data, threadData);
  RoverExample_Components_Rover_eqFunction_35(data, threadData);
  RoverExample_Components_Rover_eqFunction_36(data, threadData);
  RoverExample_Components_Rover_eqFunction_37(data, threadData);
  RoverExample_Components_Rover_eqFunction_38(data, threadData);
  RoverExample_Components_Rover_eqFunction_39(data, threadData);
  RoverExample_Components_Rover_eqFunction_40(data, threadData);
  RoverExample_Components_Rover_eqFunction_395(data, threadData);
  RoverExample_Components_Rover_eqFunction_394(data, threadData);
  RoverExample_Components_Rover_eqFunction_393(data, threadData);
  RoverExample_Components_Rover_eqFunction_391(data, threadData);
  RoverExample_Components_Rover_eqFunction_45(data, threadData);
  RoverExample_Components_Rover_eqFunction_392(data, threadData);
  RoverExample_Components_Rover_eqFunction_389(data, threadData);
  RoverExample_Components_Rover_eqFunction_48(data, threadData);
  RoverExample_Components_Rover_eqFunction_390(data, threadData);
  RoverExample_Components_Rover_eqFunction_387(data, threadData);
  RoverExample_Components_Rover_eqFunction_51(data, threadData);
  RoverExample_Components_Rover_eqFunction_388(data, threadData);
  RoverExample_Components_Rover_eqFunction_53(data, threadData);
  RoverExample_Components_Rover_eqFunction_54(data, threadData);
  RoverExample_Components_Rover_eqFunction_229(data, threadData);
  RoverExample_Components_Rover_eqFunction_230(data, threadData);
  RoverExample_Components_Rover_eqFunction_57(data, threadData);
  RoverExample_Components_Rover_eqFunction_58(data, threadData);
  RoverExample_Components_Rover_eqFunction_59(data, threadData);
  RoverExample_Components_Rover_eqFunction_60(data, threadData);
  RoverExample_Components_Rover_eqFunction_269(data, threadData);
  RoverExample_Components_Rover_eqFunction_268(data, threadData);
  RoverExample_Components_Rover_eqFunction_63(data, threadData);
  RoverExample_Components_Rover_eqFunction_272(data, threadData);
  RoverExample_Components_Rover_eqFunction_65(data, threadData);
  RoverExample_Components_Rover_eqFunction_255(data, threadData);
  RoverExample_Components_Rover_eqFunction_239(data, threadData);
  RoverExample_Components_Rover_eqFunction_68(data, threadData);
  RoverExample_Components_Rover_eqFunction_69(data, threadData);
  RoverExample_Components_Rover_eqFunction_70(data, threadData);
  RoverExample_Components_Rover_eqFunction_71(data, threadData);
  RoverExample_Components_Rover_eqFunction_287(data, threadData);
  RoverExample_Components_Rover_eqFunction_73(data, threadData);
  RoverExample_Components_Rover_eqFunction_290(data, threadData);
  RoverExample_Components_Rover_eqFunction_75(data, threadData);
  RoverExample_Components_Rover_eqFunction_293(data, threadData);
  RoverExample_Components_Rover_eqFunction_77(data, threadData);
  RoverExample_Components_Rover_eqFunction_295(data, threadData);
  RoverExample_Components_Rover_eqFunction_79(data, threadData);
  RoverExample_Components_Rover_eqFunction_311(data, threadData);
  RoverExample_Components_Rover_eqFunction_81(data, threadData);
  RoverExample_Components_Rover_eqFunction_314(data, threadData);
  RoverExample_Components_Rover_eqFunction_83(data, threadData);
  RoverExample_Components_Rover_eqFunction_317(data, threadData);
  RoverExample_Components_Rover_eqFunction_85(data, threadData);
  RoverExample_Components_Rover_eqFunction_320(data, threadData);
  RoverExample_Components_Rover_eqFunction_87(data, threadData);
  RoverExample_Components_Rover_eqFunction_88(data, threadData);
  RoverExample_Components_Rover_eqFunction_89(data, threadData);
  RoverExample_Components_Rover_eqFunction_90(data, threadData);
  RoverExample_Components_Rover_eqFunction_273(data, threadData);
  RoverExample_Components_Rover_eqFunction_274(data, threadData);
  RoverExample_Components_Rover_eqFunction_275(data, threadData);
  RoverExample_Components_Rover_eqFunction_94(data, threadData);
  RoverExample_Components_Rover_eqFunction_278(data, threadData);
  RoverExample_Components_Rover_eqFunction_254(data, threadData);
  RoverExample_Components_Rover_eqFunction_97(data, threadData);
  RoverExample_Components_Rover_eqFunction_261(data, threadData);
  RoverExample_Components_Rover_eqFunction_252(data, threadData);
  RoverExample_Components_Rover_eqFunction_100(data, threadData);
  RoverExample_Components_Rover_eqFunction_101(data, threadData);
  RoverExample_Components_Rover_eqFunction_102(data, threadData);
  RoverExample_Components_Rover_eqFunction_262(data, threadData);
  RoverExample_Components_Rover_eqFunction_104(data, threadData);
  RoverExample_Components_Rover_eqFunction_263(data, threadData);
  RoverExample_Components_Rover_eqFunction_106(data, threadData);
  RoverExample_Components_Rover_eqFunction_258(data, threadData);
  RoverExample_Components_Rover_eqFunction_259(data, threadData);
  RoverExample_Components_Rover_eqFunction_257(data, threadData);
  RoverExample_Components_Rover_eqFunction_235(data, threadData);
  RoverExample_Components_Rover_eqFunction_111(data, threadData);
  RoverExample_Components_Rover_eqFunction_241(data, threadData);
  RoverExample_Components_Rover_eqFunction_113(data, threadData);
  RoverExample_Components_Rover_eqFunction_242(data, threadData);
  RoverExample_Components_Rover_eqFunction_115(data, threadData);
  RoverExample_Components_Rover_eqFunction_240(data, threadData);
  RoverExample_Components_Rover_eqFunction_117(data, threadData);
  RoverExample_Components_Rover_eqFunction_264(data, threadData);
  RoverExample_Components_Rover_eqFunction_247(data, threadData);
  RoverExample_Components_Rover_eqFunction_120(data, threadData);
  RoverExample_Components_Rover_eqFunction_265(data, threadData);
  RoverExample_Components_Rover_eqFunction_122(data, threadData);
  RoverExample_Components_Rover_eqFunction_123(data, threadData);
  RoverExample_Components_Rover_eqFunction_249(data, threadData);
  RoverExample_Components_Rover_eqFunction_125(data, threadData);
  RoverExample_Components_Rover_eqFunction_313(data, threadData);
  RoverExample_Components_Rover_eqFunction_127(data, threadData);
  RoverExample_Components_Rover_eqFunction_319(data, threadData);
  RoverExample_Components_Rover_eqFunction_129(data, threadData);
  RoverExample_Components_Rover_eqFunction_130(data, threadData);
  RoverExample_Components_Rover_eqFunction_131(data, threadData);
  RoverExample_Components_Rover_eqFunction_132(data, threadData);
  RoverExample_Components_Rover_eqFunction_244(data, threadData);
  RoverExample_Components_Rover_eqFunction_134(data, threadData);
  RoverExample_Components_Rover_eqFunction_316(data, threadData);
  RoverExample_Components_Rover_eqFunction_136(data, threadData);
  RoverExample_Components_Rover_eqFunction_322(data, threadData);
  RoverExample_Components_Rover_eqFunction_160(data, threadData);
  RoverExample_Components_Rover_eqFunction_347(data, threadData);
  RoverExample_Components_Rover_eqFunction_346(data, threadData);
  RoverExample_Components_Rover_eqFunction_349(data, threadData);
  RoverExample_Components_Rover_eqFunction_164(data, threadData);
  RoverExample_Components_Rover_eqFunction_165(data, threadData);
  RoverExample_Components_Rover_eqFunction_166(data, threadData);
  RoverExample_Components_Rover_eqFunction_350(data, threadData);
  RoverExample_Components_Rover_eqFunction_180(data, threadData);
  RoverExample_Components_Rover_eqFunction_181(data, threadData);
  RoverExample_Components_Rover_eqFunction_182(data, threadData);
  RoverExample_Components_Rover_eqFunction_183(data, threadData);
  RoverExample_Components_Rover_eqFunction_184(data, threadData);
  RoverExample_Components_Rover_eqFunction_185(data, threadData);
  RoverExample_Components_Rover_eqFunction_186(data, threadData);
  RoverExample_Components_Rover_eqFunction_187(data, threadData);
  RoverExample_Components_Rover_eqFunction_188(data, threadData);
  RoverExample_Components_Rover_eqFunction_189(data, threadData);
  RoverExample_Components_Rover_eqFunction_190(data, threadData);
  RoverExample_Components_Rover_eqFunction_191(data, threadData);
  RoverExample_Components_Rover_eqFunction_192(data, threadData);
  RoverExample_Components_Rover_eqFunction_193(data, threadData);
  RoverExample_Components_Rover_eqFunction_194(data, threadData);
  RoverExample_Components_Rover_eqFunction_376(data, threadData);
  RoverExample_Components_Rover_eqFunction_253(data, threadData);
  RoverExample_Components_Rover_eqFunction_197(data, threadData);
  RoverExample_Components_Rover_eqFunction_198(data, threadData);
  RoverExample_Components_Rover_eqFunction_352(data, threadData);
  RoverExample_Components_Rover_eqFunction_200(data, threadData);
  RoverExample_Components_Rover_eqFunction_266(data, threadData);
  RoverExample_Components_Rover_eqFunction_202(data, threadData);
  RoverExample_Components_Rover_eqFunction_267(data, threadData);
  RoverExample_Components_Rover_eqFunction_204(data, threadData);
  RoverExample_Components_Rover_eqFunction_205(data, threadData);
  RoverExample_Components_Rover_eqFunction_206(data, threadData);
  RoverExample_Components_Rover_eqFunction_207(data, threadData);
  TRACE_POP
}

int RoverExample_Components_Rover_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  RoverExample_Components_Rover_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No RoverExample_Components_Rover_functionInitialEquations_lambda0 function */

int RoverExample_Components_Rover_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

