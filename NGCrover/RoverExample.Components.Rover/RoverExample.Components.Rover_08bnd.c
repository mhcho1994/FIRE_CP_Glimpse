/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "RoverExample.Components.Rover_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int RoverExample_Components_Rover_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating min-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating max-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating nominal-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating primary start-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void RoverExample_Components_Rover_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 397
type: SIMPLE_ASSIGN
$cse1 = sin(1.570796325 - rover_3d.mag.lat0)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,397};
  (data->simulationInfo->realParameter[0] /* $cse1 PARAM */) = sin(1.570796325 - (data->simulationInfo->realParameter[57] /* rover_3d.mag.lat0 PARAM */));
  TRACE_POP
}

/*
equation index: 398
type: SIMPLE_ASSIGN
$cse2 = cos(1.570796325 - rover_3d.mag.lat0)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,398};
  (data->simulationInfo->realParameter[1] /* $cse2 PARAM */) = cos(1.570796325 - (data->simulationInfo->realParameter[57] /* rover_3d.mag.lat0 PARAM */));
  TRACE_POP
}

/*
equation index: 399
type: SIMPLE_ASSIGN
$cse7 = sin(1.570796325 - rover_8d.mag.lat0)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,399};
  (data->simulationInfo->realParameter[5] /* $cse7 PARAM */) = sin(1.570796325 - (data->simulationInfo->realParameter[116] /* rover_8d.mag.lat0 PARAM */));
  TRACE_POP
}

/*
equation index: 400
type: SIMPLE_ASSIGN
$cse8 = cos(1.570796325 - rover_8d.mag.lat0)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,400};
  (data->simulationInfo->realParameter[6] /* $cse8 PARAM */) = cos(1.570796325 - (data->simulationInfo->realParameter[116] /* rover_8d.mag.lat0 PARAM */));
  TRACE_POP
}

/*
equation index: 401
type: SIMPLE_ASSIGN
gyroatk.epsilon = epsilon
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,401};
  (data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */) = (data->simulationInfo->realParameter[10] /* epsilon PARAM */);
  TRACE_POP
}

/*
equation index: 402
type: SIMPLE_ASSIGN
gyroatk.w_2 = gyroatk.w_s / gyroatk.w_d
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,402};
  (data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[49] /* gyroatk.w_s PARAM */),(data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */),"gyroatk.w_d",equationIndexes);
  TRACE_POP
}

/*
equation index: 403
type: SIMPLE_ASSIGN
gyroatk.k_d = gyroatk.m_d * gyroatk.w_d ^ 2.0
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_403(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,403};
  modelica_real tmp0;
  tmp0 = (data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */);
  (data->simulationInfo->realParameter[31] /* gyroatk.k_d PARAM */) = ((data->simulationInfo->realParameter[34] /* gyroatk.m_d PARAM */)) * ((tmp0 * tmp0));
  TRACE_POP
}

/*
equation index: 404
type: SIMPLE_ASSIGN
gyroatk.F_d = 2.0 * gyroatk.k_d * gyroatk.dis_d * gyroatk.zeta_d
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,404};
  (data->simulationInfo->realParameter[16] /* gyroatk.F_d PARAM */) = (2.0) * (((data->simulationInfo->realParameter[31] /* gyroatk.k_d PARAM */)) * (((data->simulationInfo->realParameter[27] /* gyroatk.dis_d PARAM */)) * ((data->simulationInfo->realParameter[50] /* gyroatk.zeta_d PARAM */))));
  TRACE_POP
}

/*
equation index: 405
type: SIMPLE_ASSIGN
gyroatk.D_s = gyroatk.F_d / (gyroatk.w_d ^ 2.0 * gyroatk.l_g * gyroatk.m_s)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_405(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,405};
  modelica_real tmp1;
  tmp1 = (data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */);
  (data->simulationInfo->realParameter[15] /* gyroatk.D_s PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[16] /* gyroatk.F_d PARAM */),((tmp1 * tmp1)) * (((data->simulationInfo->realParameter[33] /* gyroatk.l_g PARAM */)) * ((data->simulationInfo->realParameter[35] /* gyroatk.m_s PARAM */))),"gyroatk.w_d ^ 2.0 * gyroatk.l_g * gyroatk.m_s",equationIndexes);
  TRACE_POP
}

/*
equation index: 406
type: SIMPLE_ASSIGN
gyroatk.X_d1 = sin(gyroatk.epsilon) * gyroatk.D_s / sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,406};
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  tmp2 = (data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */);
  tmp3 = omc_RoverExample_Utils_avoidzero(threadData, 1.0 - ((tmp2 * tmp2)));
  tmp4 = ((data->simulationInfo->realParameter[51] /* gyroatk.zeta_s PARAM */)) * ((data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */));
  tmp5 = (tmp3 * tmp3) + (4.0) * ((tmp4 * tmp4));
  if(!(tmp5 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0) was %g should be >= 0", tmp5);
    }
  }
  (data->simulationInfo->realParameter[25] /* gyroatk.X_d1 PARAM */) = (sin((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */))) * (DIVISION_SIM((data->simulationInfo->realParameter[15] /* gyroatk.D_s PARAM */),sqrt(tmp5),"sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0)",equationIndexes));
  TRACE_POP
}

/*
equation index: 407
type: SIMPLE_ASSIGN
gyroatk.X_d2 = 0.5 * sin(2.0 * gyroatk.epsilon) * gyroatk.D_s * sqrt(1.0 + (2.0 * gyroatk.zeta_d) ^ 2.0) / (sqrt(RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * cos(gyroatk.epsilon)) ^ 2.0) * sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0))
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_407(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,407};
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  tmp6 = (2.0) * ((data->simulationInfo->realParameter[50] /* gyroatk.zeta_d PARAM */));
  tmp7 = 1.0 + (tmp6 * tmp6);
  if(!(tmp7 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(1.0 + (2.0 * gyroatk.zeta_d) ^ 2.0) was %g should be >= 0", tmp7);
    }
  }tmp8 = omc_RoverExample_Utils_avoidzero(threadData, cos((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */)) - 1.0);
  tmp9 = ((data->simulationInfo->realParameter[50] /* gyroatk.zeta_d PARAM */)) * (cos((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */)));
  tmp10 = (tmp8 * tmp8) + (4.0) * ((tmp9 * tmp9));
  if(!(tmp10 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * cos(gyroatk.epsilon)) ^ 2.0) was %g should be >= 0", tmp10);
    }
  }tmp11 = (data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */);
  tmp12 = omc_RoverExample_Utils_avoidzero(threadData, 1.0 - ((tmp11 * tmp11)));
  tmp13 = ((data->simulationInfo->realParameter[51] /* gyroatk.zeta_s PARAM */)) * ((data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */));
  tmp14 = (tmp12 * tmp12) + (4.0) * ((tmp13 * tmp13));
  if(!(tmp14 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0) was %g should be >= 0", tmp14);
    }
  }
  (data->simulationInfo->realParameter[26] /* gyroatk.X_d2 PARAM */) = (0.5) * ((sin((2.0) * ((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */)))) * (((data->simulationInfo->realParameter[15] /* gyroatk.D_s PARAM */)) * (DIVISION_SIM(sqrt(tmp7),(sqrt(tmp10)) * (sqrt(tmp14)),"sqrt(RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * cos(gyroatk.epsilon)) ^ 2.0) * sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0)",equationIndexes))));
  TRACE_POP
}

/*
equation index: 408
type: SIMPLE_ASSIGN
gyroatk.theta_d = atan(2.0 * gyroatk.zeta_s * gyroatk.w_2 / RoverExample.Utils.avoidzero(gyroatk.w_2 ^ 2.0 - 1.0))
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_408(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,408};
  modelica_real tmp15;
  tmp15 = (data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */);
  (data->simulationInfo->realParameter[43] /* gyroatk.theta_d PARAM */) = atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[51] /* gyroatk.zeta_s PARAM */))) * ((data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */)),omc_RoverExample_Utils_avoidzero(threadData, (tmp15 * tmp15) - 1.0),"RoverExample.Utils.avoidzero(gyroatk.w_2 ^ 2.0 - 1.0)",equationIndexes));
  TRACE_POP
}

/*
equation index: 409
type: SIMPLE_ASSIGN
gyroatk.phi_d = atan(2.0 * gyroatk.zeta_d * cos(gyroatk.epsilon) / RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0)) + atan(2.0 * gyroatk.zeta_s * gyroatk.w_2 / RoverExample.Utils.avoidzero(gyroatk.w_2 ^ 2.0 - 1.0)) - atan(2.0 * gyroatk.zeta_d)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_409(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,409};
  modelica_real tmp16;
  tmp16 = (data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */);
  (data->simulationInfo->realParameter[39] /* gyroatk.phi_d PARAM */) = atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[50] /* gyroatk.zeta_d PARAM */))) * (cos((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */))),omc_RoverExample_Utils_avoidzero(threadData, cos((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */)) - 1.0),"RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0)",equationIndexes)) + atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[51] /* gyroatk.zeta_s PARAM */))) * ((data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */)),omc_RoverExample_Utils_avoidzero(threadData, (tmp16 * tmp16) - 1.0),"RoverExample.Utils.avoidzero(gyroatk.w_2 ^ 2.0 - 1.0)",equationIndexes)) - atan((2.0) * ((data->simulationInfo->realParameter[50] /* gyroatk.zeta_d PARAM */)));
  TRACE_POP
}

/*
equation index: 410
type: SIMPLE_ASSIGN
gyroatk.Phi_d = atan((gyroatk.X_d1 * sin(gyroatk.theta_d) - gyroatk.X_d2 * sin(gyroatk.phi_d)) / RoverExample.Utils.avoidzero(gyroatk.X_d1 * cos(gyroatk.theta_d) - gyroatk.X_d2 * cos(gyroatk.phi_d)))
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_410(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,410};
  (data->simulationInfo->realParameter[18] /* gyroatk.Phi_d PARAM */) = atan(DIVISION_SIM(((data->simulationInfo->realParameter[25] /* gyroatk.X_d1 PARAM */)) * (sin((data->simulationInfo->realParameter[43] /* gyroatk.theta_d PARAM */))) - (((data->simulationInfo->realParameter[26] /* gyroatk.X_d2 PARAM */)) * (sin((data->simulationInfo->realParameter[39] /* gyroatk.phi_d PARAM */)))),omc_RoverExample_Utils_avoidzero(threadData, ((data->simulationInfo->realParameter[25] /* gyroatk.X_d1 PARAM */)) * (cos((data->simulationInfo->realParameter[43] /* gyroatk.theta_d PARAM */))) - (((data->simulationInfo->realParameter[26] /* gyroatk.X_d2 PARAM */)) * (cos((data->simulationInfo->realParameter[39] /* gyroatk.phi_d PARAM */))))),"RoverExample.Utils.avoidzero(gyroatk.X_d1 * cos(gyroatk.theta_d) - gyroatk.X_d2 * cos(gyroatk.phi_d))",equationIndexes));
  TRACE_POP
}

/*
equation index: 411
type: SIMPLE_ASSIGN
$cse39 = cos(gyroatk.Phi_d)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_411(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,411};
  (data->simulationInfo->realParameter[2] /* $cse39 PARAM */) = cos((data->simulationInfo->realParameter[18] /* gyroatk.Phi_d PARAM */));
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_37(DATA *data, threadData_t *threadData);


/*
equation index: 413
type: SIMPLE_ASSIGN
$cse40 = cos(rover_3d.phi_f + rover_3d.phi_t)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_413(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,413};
  (data->simulationInfo->realParameter[3] /* $cse40 PARAM */) = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* rover_3d.phi_f variable */) + (data->simulationInfo->realParameter[58] /* rover_3d.phi_t PARAM */));
  TRACE_POP
}

/*
equation index: 414
type: SIMPLE_ASSIGN
$cse41 = sin(rover_3d.phi_f)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_414(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,414};
  (data->simulationInfo->realParameter[4] /* $cse41 PARAM */) = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* rover_3d.phi_f variable */));
  TRACE_POP
}

/*
equation index: 415
type: SIMPLE_ASSIGN
gyroatk.phi_0 = phi_0
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_415(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,415};
  (data->simulationInfo->realParameter[37] /* gyroatk.phi_0 PARAM */) = (data->simulationInfo->realParameter[52] /* phi_0 PARAM */);
  TRACE_POP
}

/*
equation index: 416
type: SIMPLE_ASSIGN
gyroatk.W = W
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_416(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,416};
  (data->simulationInfo->realParameter[20] /* gyroatk.W PARAM */) = (data->simulationInfo->realParameter[7] /* W PARAM */);
  TRACE_POP
}

/*
equation index: 417
type: SIMPLE_ASSIGN
gyroatk.dist = dist
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_417(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,417};
  (data->simulationInfo->realParameter[28] /* gyroatk.dist PARAM */) = (data->simulationInfo->realParameter[9] /* dist PARAM */);
  TRACE_POP
}

/*
equation index: 418
type: SIMPLE_ASSIGN
gyroatk.SPL = 10.0 * log10(RoverExample.Utils.avoidzero(0.07957747163687819 * gyroatk.W / (415.03 * gyroatk.dist ^ 2.0 * gyroatk.p0 ^ 2.0)))
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_418(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,418};
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  tmp17 = (data->simulationInfo->realParameter[28] /* gyroatk.dist PARAM */);
  tmp18 = (data->simulationInfo->realParameter[36] /* gyroatk.p0 PARAM */);
  tmp19 = omc_RoverExample_Utils_avoidzero(threadData, DIVISION_SIM((0.07957747163687819) * ((data->simulationInfo->realParameter[20] /* gyroatk.W PARAM */)),((415.03) * ((tmp17 * tmp17))) * ((tmp18 * tmp18)),"415.03 * gyroatk.dist ^ 2.0 * gyroatk.p0 ^ 2.0",equationIndexes));
  if(!(tmp19 > 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of log10(RoverExample.Utils.avoidzero(0.07957747163687819 * gyroatk.W / (415.03 * gyroatk.dist ^ 2.0 * gyroatk.p0 ^ 2.0))) was %g should be > 0", tmp19);
    }
  }
  (data->simulationInfo->realParameter[19] /* gyroatk.SPL PARAM */) = (10.0) * (log10(tmp19));
  TRACE_POP
}

/*
equation index: 419
type: SIMPLE_ASSIGN
gyroatk.A = gyroatk.p0 * 10.0 ^ (0.05 * gyroatk.SPL) * (2.0 * gyroatk.dis_d) ^ 2.0
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_419(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,419};
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_real tmp27;
  tmp20 = 10.0;
  tmp21 = (0.05) * ((data->simulationInfo->realParameter[19] /* gyroatk.SPL PARAM */));
  if(tmp20 < 0.0 && tmp21 != 0.0)
  {
    tmp23 = modf(tmp21, &tmp24);
    
    if(tmp23 > 0.5)
    {
      tmp23 -= 1.0;
      tmp24 += 1.0;
    }
    else if(tmp23 < -0.5)
    {
      tmp23 += 1.0;
      tmp24 -= 1.0;
    }
    
    if(fabs(tmp23) < 1e-10)
      tmp22 = pow(tmp20, tmp24);
    else
    {
      tmp26 = modf(1.0/tmp21, &tmp25);
      if(tmp26 > 0.5)
      {
        tmp26 -= 1.0;
        tmp25 += 1.0;
      }
      else if(tmp26 < -0.5)
      {
        tmp26 += 1.0;
        tmp25 -= 1.0;
      }
      if(fabs(tmp26) < 1e-10 && ((unsigned long)tmp25 & 1))
      {
        tmp22 = -pow(-tmp20, tmp23)*pow(tmp20, tmp24);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp20, tmp21);
      }
    }
  }
  else
  {
    tmp22 = pow(tmp20, tmp21);
  }
  if(isnan(tmp22) || isinf(tmp22))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp20, tmp21);
  }tmp27 = (2.0) * ((data->simulationInfo->realParameter[27] /* gyroatk.dis_d PARAM */));
  (data->simulationInfo->realParameter[11] /* gyroatk.A PARAM */) = ((data->simulationInfo->realParameter[36] /* gyroatk.p0 PARAM */)) * ((tmp22) * ((tmp27 * tmp27)));
  TRACE_POP
}

/*
equation index: 420
type: SIMPLE_ASSIGN
gyroatk.psi_ac = psi_ac
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_420(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,420};
  (data->simulationInfo->realParameter[41] /* gyroatk.psi_ac PARAM */) = (data->simulationInfo->realParameter[53] /* psi_ac PARAM */);
  TRACE_POP
}

/*
equation index: 421
type: SIMPLE_ASSIGN
gyroatk.A_x = gyroatk.A * cos(gyroatk.psi_ac)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_421(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,421};
  (data->simulationInfo->realParameter[12] /* gyroatk.A_x PARAM */) = ((data->simulationInfo->realParameter[11] /* gyroatk.A PARAM */)) * (cos((data->simulationInfo->realParameter[41] /* gyroatk.psi_ac PARAM */)));
  TRACE_POP
}

/*
equation index: 422
type: SIMPLE_ASSIGN
gyroatk.w_ac = w_ac
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_422(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,422};
  (data->simulationInfo->realParameter[47] /* gyroatk.w_ac PARAM */) = (data->simulationInfo->realParameter[131] /* w_ac PARAM */);
  TRACE_POP
}

/*
equation index: 423
type: SIMPLE_ASSIGN
gyroatk.w_3 = gyroatk.w_ac / gyroatk.w_s
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_423(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,423};
  (data->simulationInfo->realParameter[46] /* gyroatk.w_3 PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[47] /* gyroatk.w_ac PARAM */),(data->simulationInfo->realParameter[49] /* gyroatk.w_s PARAM */),"gyroatk.w_s",equationIndexes);
  TRACE_POP
}

/*
equation index: 424
type: SIMPLE_ASSIGN
gyroatk.X_acx = gyroatk.A_x / ((gyroatk.w_d * gyroatk.w_2) ^ 2.0 * sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) * gyroatk.l_g * gyroatk.m_s)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_424(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,424};
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  tmp28 = ((data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */)) * ((data->simulationInfo->realParameter[45] /* gyroatk.w_2 PARAM */));
  tmp29 = (data->simulationInfo->realParameter[46] /* gyroatk.w_3 PARAM */);
  tmp30 = omc_RoverExample_Utils_avoidzero(threadData, 1.0 - ((tmp29 * tmp29)));
  tmp31 = ((data->simulationInfo->realParameter[51] /* gyroatk.zeta_s PARAM */)) * ((data->simulationInfo->realParameter[46] /* gyroatk.w_3 PARAM */));
  tmp32 = (tmp30 * tmp30) + (4.0) * ((tmp31 * tmp31));
  if(!(tmp32 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) was %g should be >= 0", tmp32);
    }
  }
  (data->simulationInfo->realParameter[22] /* gyroatk.X_acx PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[12] /* gyroatk.A_x PARAM */),((tmp28 * tmp28)) * (((sqrt(tmp32)) * ((data->simulationInfo->realParameter[33] /* gyroatk.l_g PARAM */))) * ((data->simulationInfo->realParameter[35] /* gyroatk.m_s PARAM */))),"(gyroatk.w_d * gyroatk.w_2) ^ 2.0 * sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) * gyroatk.l_g * gyroatk.m_s",equationIndexes);
  TRACE_POP
}

/*
equation index: 425
type: SIMPLE_ASSIGN
gyroatk.A_y = gyroatk.A * sin(gyroatk.psi_ac)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_425(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,425};
  (data->simulationInfo->realParameter[13] /* gyroatk.A_y PARAM */) = ((data->simulationInfo->realParameter[11] /* gyroatk.A PARAM */)) * (sin((data->simulationInfo->realParameter[41] /* gyroatk.psi_ac PARAM */)));
  TRACE_POP
}

/*
equation index: 426
type: SIMPLE_ASSIGN
gyroatk.k_s = gyroatk.m_s * gyroatk.w_s ^ 2.0
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_426(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,426};
  modelica_real tmp33;
  tmp33 = (data->simulationInfo->realParameter[49] /* gyroatk.w_s PARAM */);
  (data->simulationInfo->realParameter[32] /* gyroatk.k_s PARAM */) = ((data->simulationInfo->realParameter[35] /* gyroatk.m_s PARAM */)) * ((tmp33 * tmp33));
  TRACE_POP
}

/*
equation index: 427
type: SIMPLE_ASSIGN
gyroatk.k_bar = gyroatk.k_d / gyroatk.k_s
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_427(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,427};
  (data->simulationInfo->realParameter[30] /* gyroatk.k_bar PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[31] /* gyroatk.k_d PARAM */),(data->simulationInfo->realParameter[32] /* gyroatk.k_s PARAM */),"gyroatk.k_s",equationIndexes);
  TRACE_POP
}

/*
equation index: 428
type: SIMPLE_ASSIGN
gyroatk.w_1 = gyroatk.w_ac / gyroatk.w_d
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,428};
  (data->simulationInfo->realParameter[44] /* gyroatk.w_1 PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[47] /* gyroatk.w_ac PARAM */),(data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */),"gyroatk.w_d",equationIndexes);
  TRACE_POP
}

/*
equation index: 429
type: SIMPLE_ASSIGN
gyroatk.X_acy = sqrt(1.0 + 4.0 * (gyroatk.zeta_d * gyroatk.w_1) ^ 2.0) * gyroatk.k_bar * sin(gyroatk.epsilon) * gyroatk.A_y / (gyroatk.w_d ^ 2.0 * sqrt(RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * gyroatk.w_1 * cos(gyroatk.epsilon)) ^ 2.0) * sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) * gyroatk.l_g * gyroatk.m_d)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,429};
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_real tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  modelica_real tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  modelica_real tmp42;
  modelica_real tmp43;
  modelica_real tmp44;
  tmp34 = ((data->simulationInfo->realParameter[50] /* gyroatk.zeta_d PARAM */)) * ((data->simulationInfo->realParameter[44] /* gyroatk.w_1 PARAM */));
  tmp35 = 1.0 + (4.0) * ((tmp34 * tmp34));
  if(!(tmp35 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(1.0 + 4.0 * (gyroatk.zeta_d * gyroatk.w_1) ^ 2.0) was %g should be >= 0", tmp35);
    }
  }tmp36 = (data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */);
  tmp37 = (data->simulationInfo->realParameter[44] /* gyroatk.w_1 PARAM */);
  tmp38 = omc_RoverExample_Utils_avoidzero(threadData, cos((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */)) - ((tmp37 * tmp37)));
  tmp39 = ((data->simulationInfo->realParameter[50] /* gyroatk.zeta_d PARAM */)) * (((data->simulationInfo->realParameter[44] /* gyroatk.w_1 PARAM */)) * (cos((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */))));
  tmp40 = (tmp38 * tmp38) + (4.0) * ((tmp39 * tmp39));
  if(!(tmp40 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * gyroatk.w_1 * cos(gyroatk.epsilon)) ^ 2.0) was %g should be >= 0", tmp40);
    }
  }tmp41 = (data->simulationInfo->realParameter[46] /* gyroatk.w_3 PARAM */);
  tmp42 = omc_RoverExample_Utils_avoidzero(threadData, 1.0 - ((tmp41 * tmp41)));
  tmp43 = ((data->simulationInfo->realParameter[51] /* gyroatk.zeta_s PARAM */)) * ((data->simulationInfo->realParameter[46] /* gyroatk.w_3 PARAM */));
  tmp44 = (tmp42 * tmp42) + (4.0) * ((tmp43 * tmp43));
  if(!(tmp44 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) was %g should be >= 0", tmp44);
    }
  }
  (data->simulationInfo->realParameter[23] /* gyroatk.X_acy PARAM */) = (sqrt(tmp35)) * (((data->simulationInfo->realParameter[30] /* gyroatk.k_bar PARAM */)) * ((sin((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */))) * (DIVISION_SIM((data->simulationInfo->realParameter[13] /* gyroatk.A_y PARAM */),((tmp36 * tmp36)) * ((((sqrt(tmp40)) * (sqrt(tmp44))) * ((data->simulationInfo->realParameter[33] /* gyroatk.l_g PARAM */))) * ((data->simulationInfo->realParameter[34] /* gyroatk.m_d PARAM */))),"gyroatk.w_d ^ 2.0 * sqrt(RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * gyroatk.w_1 * cos(gyroatk.epsilon)) ^ 2.0) * sqrt(RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) * gyroatk.l_g * gyroatk.m_d",equationIndexes))));
  TRACE_POP
}

/*
equation index: 430
type: SIMPLE_ASSIGN
gyroatk.phi_ac = atan(2.0 * gyroatk.zeta_s * gyroatk.w_3 / RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0))
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,430};
  modelica_real tmp45;
  tmp45 = (data->simulationInfo->realParameter[46] /* gyroatk.w_3 PARAM */);
  (data->simulationInfo->realParameter[38] /* gyroatk.phi_ac PARAM */) = atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[51] /* gyroatk.zeta_s PARAM */))) * ((data->simulationInfo->realParameter[46] /* gyroatk.w_3 PARAM */)),omc_RoverExample_Utils_avoidzero(threadData, 1.0 - ((tmp45 * tmp45))),"RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0)",equationIndexes));
  TRACE_POP
}

/*
equation index: 431
type: SIMPLE_ASSIGN
gyroatk.phi_y = atan(2.0 * gyroatk.zeta_d * gyroatk.w_1 * cos(gyroatk.epsilon) / RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0)) + atan(2.0 * gyroatk.zeta_s * gyroatk.w_3 / RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0)) - atan(2.0 * gyroatk.zeta_d * gyroatk.w_1)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,431};
  modelica_real tmp46;
  modelica_real tmp47;
  tmp46 = (data->simulationInfo->realParameter[44] /* gyroatk.w_1 PARAM */);
  tmp47 = (data->simulationInfo->realParameter[46] /* gyroatk.w_3 PARAM */);
  (data->simulationInfo->realParameter[40] /* gyroatk.phi_y PARAM */) = atan(DIVISION_SIM((((2.0) * ((data->simulationInfo->realParameter[50] /* gyroatk.zeta_d PARAM */))) * ((data->simulationInfo->realParameter[44] /* gyroatk.w_1 PARAM */))) * (cos((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */))),omc_RoverExample_Utils_avoidzero(threadData, cos((data->simulationInfo->realParameter[29] /* gyroatk.epsilon PARAM */)) - ((tmp46 * tmp46))),"RoverExample.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0)",equationIndexes)) + atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[51] /* gyroatk.zeta_s PARAM */))) * ((data->simulationInfo->realParameter[46] /* gyroatk.w_3 PARAM */)),omc_RoverExample_Utils_avoidzero(threadData, 1.0 - ((tmp47 * tmp47))),"RoverExample.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0)",equationIndexes)) - atan(((2.0) * ((data->simulationInfo->realParameter[50] /* gyroatk.zeta_d PARAM */))) * ((data->simulationInfo->realParameter[44] /* gyroatk.w_1 PARAM */)));
  TRACE_POP
}

/*
equation index: 432
type: SIMPLE_ASSIGN
gyroatk.Phi_ac = atan((gyroatk.X_acx * sin(gyroatk.phi_0 + gyroatk.phi_ac) - gyroatk.X_acy * sin(gyroatk.phi_0 + gyroatk.phi_y)) / RoverExample.Utils.avoidzero(gyroatk.X_acx * cos(gyroatk.phi_0 + gyroatk.phi_ac) - gyroatk.X_acy * cos(gyroatk.phi_0 + gyroatk.phi_y)))
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,432};
  (data->simulationInfo->realParameter[17] /* gyroatk.Phi_ac PARAM */) = atan(DIVISION_SIM(((data->simulationInfo->realParameter[22] /* gyroatk.X_acx PARAM */)) * (sin((data->simulationInfo->realParameter[37] /* gyroatk.phi_0 PARAM */) + (data->simulationInfo->realParameter[38] /* gyroatk.phi_ac PARAM */))) - (((data->simulationInfo->realParameter[23] /* gyroatk.X_acy PARAM */)) * (sin((data->simulationInfo->realParameter[37] /* gyroatk.phi_0 PARAM */) + (data->simulationInfo->realParameter[40] /* gyroatk.phi_y PARAM */)))),omc_RoverExample_Utils_avoidzero(threadData, ((data->simulationInfo->realParameter[22] /* gyroatk.X_acx PARAM */)) * (cos((data->simulationInfo->realParameter[37] /* gyroatk.phi_0 PARAM */) + (data->simulationInfo->realParameter[38] /* gyroatk.phi_ac PARAM */))) - (((data->simulationInfo->realParameter[23] /* gyroatk.X_acy PARAM */)) * (cos((data->simulationInfo->realParameter[37] /* gyroatk.phi_0 PARAM */) + (data->simulationInfo->realParameter[40] /* gyroatk.phi_y PARAM */))))),"RoverExample.Utils.avoidzero(gyroatk.X_acx * cos(gyroatk.phi_0 + gyroatk.phi_ac) - gyroatk.X_acy * cos(gyroatk.phi_0 + gyroatk.phi_y))",equationIndexes));
  TRACE_POP
}

/*
equation index: 433
type: SIMPLE_ASSIGN
gyroatk.X_d = sqrt(2.0 * gyroatk.X_d1 ^ 2.0 - 2.0 * gyroatk.X_d1 * gyroatk.X_d2 * cos(gyroatk.phi_d - gyroatk.theta_d))
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,433};
  modelica_real tmp48;
  modelica_real tmp49;
  tmp48 = (data->simulationInfo->realParameter[25] /* gyroatk.X_d1 PARAM */);
  tmp49 = (2.0) * ((tmp48 * tmp48)) - ((((2.0) * ((data->simulationInfo->realParameter[25] /* gyroatk.X_d1 PARAM */))) * ((data->simulationInfo->realParameter[26] /* gyroatk.X_d2 PARAM */))) * (cos((data->simulationInfo->realParameter[39] /* gyroatk.phi_d PARAM */) - (data->simulationInfo->realParameter[43] /* gyroatk.theta_d PARAM */))));
  if(!(tmp49 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(2.0 * gyroatk.X_d1 ^ 2.0 - 2.0 * gyroatk.X_d1 * gyroatk.X_d2 * cos(gyroatk.phi_d - gyroatk.theta_d)) was %g should be >= 0", tmp49);
    }
  }
  (data->simulationInfo->realParameter[24] /* gyroatk.X_d PARAM */) = sqrt(tmp49);
  TRACE_POP
}

/*
equation index: 434
type: SIMPLE_ASSIGN
gyroatk.X_ac = sqrt(gyroatk.X_acx ^ 2.0 + gyroatk.X_acy ^ 2.0 - 2.0 * gyroatk.X_acx * gyroatk.X_acy * cos(gyroatk.phi_ac - gyroatk.phi_y))
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,434};
  modelica_real tmp50;
  modelica_real tmp51;
  modelica_real tmp52;
  tmp50 = (data->simulationInfo->realParameter[22] /* gyroatk.X_acx PARAM */);
  tmp51 = (data->simulationInfo->realParameter[23] /* gyroatk.X_acy PARAM */);
  tmp52 = (tmp50 * tmp50) + (tmp51 * tmp51) - ((((2.0) * ((data->simulationInfo->realParameter[22] /* gyroatk.X_acx PARAM */))) * ((data->simulationInfo->realParameter[23] /* gyroatk.X_acy PARAM */))) * (cos((data->simulationInfo->realParameter[38] /* gyroatk.phi_ac PARAM */) - (data->simulationInfo->realParameter[40] /* gyroatk.phi_y PARAM */))));
  if(!(tmp52 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(gyroatk.X_acx ^ 2.0 + gyroatk.X_acy ^ 2.0 - 2.0 * gyroatk.X_acx * gyroatk.X_acy * cos(gyroatk.phi_ac - gyroatk.phi_y)) was %g should be >= 0", tmp52);
    }
  }
  (data->simulationInfo->realParameter[21] /* gyroatk.X_ac PARAM */) = sqrt(tmp52);
  TRACE_POP
}

/*
equation index: 435
type: SIMPLE_ASSIGN
gyroatk.D_d = gyroatk.F_d / (gyroatk.w_d ^ 2.0 * gyroatk.l_g * gyroatk.m_d)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,435};
  modelica_real tmp53;
  tmp53 = (data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */);
  (data->simulationInfo->realParameter[14] /* gyroatk.D_d PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[16] /* gyroatk.F_d PARAM */),((tmp53 * tmp53)) * (((data->simulationInfo->realParameter[33] /* gyroatk.l_g PARAM */)) * ((data->simulationInfo->realParameter[34] /* gyroatk.m_d PARAM */))),"gyroatk.w_d ^ 2.0 * gyroatk.l_g * gyroatk.m_d",equationIndexes);
  TRACE_POP
}

/*
equation index: 436
type: SIMPLE_ASSIGN
rover_8d.emi.dist_wire = sqrt(rover_8d.emi.x_wire[1] ^ 2.0 + rover_8d.emi.x_wire[2] ^ 2.0 + rover_8d.emi.x_wire[3] ^ 2.0)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_436(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,436};
  modelica_real tmp54;
  modelica_real tmp55;
  modelica_real tmp56;
  modelica_real tmp57;
  tmp54 = (data->simulationInfo->realParameter[99] /* rover_8d.emi.x_wire[1] PARAM */);
  tmp55 = (data->simulationInfo->realParameter[100] /* rover_8d.emi.x_wire[2] PARAM */);
  tmp56 = (data->simulationInfo->realParameter[101] /* rover_8d.emi.x_wire[3] PARAM */);
  tmp57 = (tmp54 * tmp54) + (tmp55 * tmp55) + (tmp56 * tmp56);
  if(!(tmp57 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.emi.x_wire[1] ^ 2.0 + rover_8d.emi.x_wire[2] ^ 2.0 + rover_8d.emi.x_wire[3] ^ 2.0) was %g should be >= 0", tmp57);
    }
  }
  (data->simulationInfo->realParameter[90] /* rover_8d.emi.dist_wire PARAM */) = sqrt(tmp57);
  TRACE_POP
}

/*
equation index: 437
type: SIMPLE_ASSIGN
rover_8d.emi.dist_motor = sqrt(rover_8d.emi.x_motor[1] ^ 2.0 + rover_8d.emi.x_motor[2] ^ 2.0 + rover_8d.emi.x_motor[3] ^ 2.0)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_437(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,437};
  modelica_real tmp58;
  modelica_real tmp59;
  modelica_real tmp60;
  modelica_real tmp61;
  tmp58 = (data->simulationInfo->realParameter[96] /* rover_8d.emi.x_motor[1] PARAM */);
  tmp59 = (data->simulationInfo->realParameter[97] /* rover_8d.emi.x_motor[2] PARAM */);
  tmp60 = (data->simulationInfo->realParameter[98] /* rover_8d.emi.x_motor[3] PARAM */);
  tmp61 = (tmp58 * tmp58) + (tmp59 * tmp59) + (tmp60 * tmp60);
  if(!(tmp61 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.emi.x_motor[1] ^ 2.0 + rover_8d.emi.x_motor[2] ^ 2.0 + rover_8d.emi.x_motor[3] ^ 2.0) was %g should be >= 0", tmp61);
    }
  }
  (data->simulationInfo->realParameter[89] /* rover_8d.emi.dist_motor PARAM */) = sqrt(tmp61);
  TRACE_POP
}

/*
equation index: 438
type: SIMPLE_ASSIGN
rover_8d.emi.A = rover_8d.A
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_438(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,438};
  (data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */) = (data->simulationInfo->realParameter[61] /* rover_8d.A PARAM */);
  TRACE_POP
}

/*
equation index: 439
type: SIMPLE_ASSIGN
rover_8d.emi.B = rover_8d.B
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_439(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,439};
  (data->simulationInfo->realParameter[87] /* rover_8d.emi.B PARAM */) = (data->simulationInfo->realParameter[63] /* rover_8d.B PARAM */);
  TRACE_POP
}

/*
equation index: 440
type: SIMPLE_ASSIGN
rover_8d.emi.mag_motor = 3978.87358184391 * rover_8d.emi.B * rover_8d.emi.A
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_440(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,440};
  (data->simulationInfo->realParameter[92] /* rover_8d.emi.mag_motor PARAM */) = (3978.87358184391) * (((data->simulationInfo->realParameter[87] /* rover_8d.emi.B PARAM */)) * ((data->simulationInfo->realParameter[86] /* rover_8d.emi.A PARAM */)));
  TRACE_POP
}

/*
equation index: 441
type: SIMPLE_ASSIGN
rover_8d.emi.Nw = rover_8d.Nw
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_441(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,441};
  (data->simulationInfo->realParameter[88] /* rover_8d.emi.Nw PARAM */) = (data->simulationInfo->realParameter[76] /* rover_8d.Nw PARAM */);
  TRACE_POP
}

/*
equation index: 442
type: SIMPLE_ASSIGN
rover_8d.Kb_phi = rover_8d.Np * rover_8d.Nw * rover_8d.A * rover_8d.B
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_442(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,442};
  (data->simulationInfo->realParameter[68] /* rover_8d.Kb_phi PARAM */) = ((data->simulationInfo->realParameter[75] /* rover_8d.Np PARAM */)) * (((data->simulationInfo->realParameter[76] /* rover_8d.Nw PARAM */)) * (((data->simulationInfo->realParameter[61] /* rover_8d.A PARAM */)) * ((data->simulationInfo->realParameter[63] /* rover_8d.B PARAM */))));
  TRACE_POP
}

/*
equation index: 443
type: SIMPLE_ASSIGN
rover_8d.Kb_q = 1.224744871391589 * rover_8d.Kb_phi
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_443(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,443};
  (data->simulationInfo->realParameter[69] /* rover_8d.Kb_q PARAM */) = (1.224744871391589) * ((data->simulationInfo->realParameter[68] /* rover_8d.Kb_phi PARAM */));
  TRACE_POP
}

/*
equation index: 444
type: SIMPLE_ASSIGN
rover_8d.Kt_phi = rover_8d.eta_mech * rover_8d.Np * rover_8d.Nw * rover_8d.A * rover_8d.B
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_444(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,444};
  (data->simulationInfo->realParameter[70] /* rover_8d.Kt_phi PARAM */) = ((data->simulationInfo->realParameter[102] /* rover_8d.eta_mech PARAM */)) * (((data->simulationInfo->realParameter[75] /* rover_8d.Np PARAM */)) * (((data->simulationInfo->realParameter[76] /* rover_8d.Nw PARAM */)) * (((data->simulationInfo->realParameter[61] /* rover_8d.A PARAM */)) * ((data->simulationInfo->realParameter[63] /* rover_8d.B PARAM */)))));
  TRACE_POP
}

/*
equation index: 445
type: SIMPLE_ASSIGN
rover_8d.Kt_q = 1.224744871391589 * rover_8d.Kt_phi
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_445(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,445};
  (data->simulationInfo->realParameter[71] /* rover_8d.Kt_q PARAM */) = (1.224744871391589) * ((data->simulationInfo->realParameter[70] /* rover_8d.Kt_phi PARAM */));
  TRACE_POP
}

/*
equation index: 446
type: SIMPLE_ASSIGN
rover_8d.I_xx = 0.5 * rover_8d.mass_total * (0.5 * rover_8d.tw) ^ 2.0
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_446(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,446};
  modelica_real tmp62;
  tmp62 = (0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */));
  (data->simulationInfo->realParameter[65] /* rover_8d.I_xx PARAM */) = (0.5) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((tmp62 * tmp62)));
  TRACE_POP
}

/*
equation index: 447
type: SIMPLE_ASSIGN
rover_8d.I_zz = 0.08333333333333333 * rover_8d.mass_total * (rover_8d.l_total ^ 2.0 + rover_8d.tw ^ 2.0)
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_447(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,447};
  modelica_real tmp63;
  modelica_real tmp64;
  tmp63 = (data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */);
  tmp64 = (data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */);
  (data->simulationInfo->realParameter[66] /* rover_8d.I_zz PARAM */) = (0.08333333333333333) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((tmp63 * tmp63) + (tmp64 * tmp64)));
  TRACE_POP
}

/*
equation index: 448
type: SIMPLE_ASSIGN
rover_8d.I_wheel = 1.5 * rover_8d.mass_wheel * rover_8d.r_tire ^ 2.0
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_448(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,448};
  modelica_real tmp65;
  tmp65 = (data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */);
  (data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */) = (1.5) * (((data->simulationInfo->realParameter[121] /* rover_8d.mass_wheel PARAM */)) * ((tmp65 * tmp65)));
  TRACE_POP
}

/*
equation index: 449
type: SIMPLE_ASSIGN
rover_8d.mass_unsprung_front = 8.0 * rover_8d.mass_wheel
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_449(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,449};
  (data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */) = (8.0) * ((data->simulationInfo->realParameter[121] /* rover_8d.mass_wheel PARAM */));
  TRACE_POP
}

/*
equation index: 450
type: SIMPLE_ASSIGN
rover_8d.mass_unsprung_rear = 8.0 * rover_8d.mass_wheel
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_450(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,450};
  (data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */) = (8.0) * ((data->simulationInfo->realParameter[121] /* rover_8d.mass_wheel PARAM */));
  TRACE_POP
}

/*
equation index: 451
type: SIMPLE_ASSIGN
rover_8d.mass_sprung = rover_8d.mass_total + (-rover_8d.mass_unsprung_front) - rover_8d.mass_unsprung_rear
*/
OMC_DISABLE_OPT
static void RoverExample_Components_Rover_eqFunction_451(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,451};
  (data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */) = (data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */) + (-(data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) - (data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */);
  TRACE_POP
}
extern void RoverExample_Components_Rover_eqFunction_40(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_10(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_9(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_8(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_7(DATA *data, threadData_t *threadData);

extern void RoverExample_Components_Rover_eqFunction_6(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void RoverExample_Components_Rover_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RoverExample_Components_Rover_eqFunction_397(data, threadData);
  RoverExample_Components_Rover_eqFunction_398(data, threadData);
  RoverExample_Components_Rover_eqFunction_399(data, threadData);
  RoverExample_Components_Rover_eqFunction_400(data, threadData);
  RoverExample_Components_Rover_eqFunction_401(data, threadData);
  RoverExample_Components_Rover_eqFunction_402(data, threadData);
  RoverExample_Components_Rover_eqFunction_403(data, threadData);
  RoverExample_Components_Rover_eqFunction_404(data, threadData);
  RoverExample_Components_Rover_eqFunction_405(data, threadData);
  RoverExample_Components_Rover_eqFunction_406(data, threadData);
  RoverExample_Components_Rover_eqFunction_407(data, threadData);
  RoverExample_Components_Rover_eqFunction_408(data, threadData);
  RoverExample_Components_Rover_eqFunction_409(data, threadData);
  RoverExample_Components_Rover_eqFunction_410(data, threadData);
  RoverExample_Components_Rover_eqFunction_411(data, threadData);
  RoverExample_Components_Rover_eqFunction_37(data, threadData);
  RoverExample_Components_Rover_eqFunction_413(data, threadData);
  RoverExample_Components_Rover_eqFunction_414(data, threadData);
  RoverExample_Components_Rover_eqFunction_415(data, threadData);
  RoverExample_Components_Rover_eqFunction_416(data, threadData);
  RoverExample_Components_Rover_eqFunction_417(data, threadData);
  RoverExample_Components_Rover_eqFunction_418(data, threadData);
  RoverExample_Components_Rover_eqFunction_419(data, threadData);
  RoverExample_Components_Rover_eqFunction_420(data, threadData);
  RoverExample_Components_Rover_eqFunction_421(data, threadData);
  RoverExample_Components_Rover_eqFunction_422(data, threadData);
  RoverExample_Components_Rover_eqFunction_423(data, threadData);
  RoverExample_Components_Rover_eqFunction_424(data, threadData);
  RoverExample_Components_Rover_eqFunction_425(data, threadData);
  RoverExample_Components_Rover_eqFunction_426(data, threadData);
  RoverExample_Components_Rover_eqFunction_427(data, threadData);
  RoverExample_Components_Rover_eqFunction_428(data, threadData);
  RoverExample_Components_Rover_eqFunction_429(data, threadData);
  RoverExample_Components_Rover_eqFunction_430(data, threadData);
  RoverExample_Components_Rover_eqFunction_431(data, threadData);
  RoverExample_Components_Rover_eqFunction_432(data, threadData);
  RoverExample_Components_Rover_eqFunction_433(data, threadData);
  RoverExample_Components_Rover_eqFunction_434(data, threadData);
  RoverExample_Components_Rover_eqFunction_435(data, threadData);
  RoverExample_Components_Rover_eqFunction_436(data, threadData);
  RoverExample_Components_Rover_eqFunction_437(data, threadData);
  RoverExample_Components_Rover_eqFunction_438(data, threadData);
  RoverExample_Components_Rover_eqFunction_439(data, threadData);
  RoverExample_Components_Rover_eqFunction_440(data, threadData);
  RoverExample_Components_Rover_eqFunction_441(data, threadData);
  RoverExample_Components_Rover_eqFunction_442(data, threadData);
  RoverExample_Components_Rover_eqFunction_443(data, threadData);
  RoverExample_Components_Rover_eqFunction_444(data, threadData);
  RoverExample_Components_Rover_eqFunction_445(data, threadData);
  RoverExample_Components_Rover_eqFunction_446(data, threadData);
  RoverExample_Components_Rover_eqFunction_447(data, threadData);
  RoverExample_Components_Rover_eqFunction_448(data, threadData);
  RoverExample_Components_Rover_eqFunction_449(data, threadData);
  RoverExample_Components_Rover_eqFunction_450(data, threadData);
  RoverExample_Components_Rover_eqFunction_451(data, threadData);
  RoverExample_Components_Rover_eqFunction_40(data, threadData);
  RoverExample_Components_Rover_eqFunction_10(data, threadData);
  RoverExample_Components_Rover_eqFunction_9(data, threadData);
  RoverExample_Components_Rover_eqFunction_8(data, threadData);
  RoverExample_Components_Rover_eqFunction_7(data, threadData);
  RoverExample_Components_Rover_eqFunction_6(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->integerParameter[0]/* fidelity PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[0].time_unvarying = 1;
  RoverExample_Components_Rover_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

