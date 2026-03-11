/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "GSQuad.Components.Quadrotor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  /* min ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating min-values");
  messageClose(OMC_LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating max-values");
  messageClose(OMC_LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating nominal-values");
  messageClose(OMC_LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating primary start-values");
  messageClose(OMC_LOG_INIT);
  
  return 0;
}

void GSQuad_Components_Quadrotor_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 158
type: SIMPLE_ASSIGN
gyroatk.epsilon = epsilon
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_158(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,158};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* epsilon PARAM */);
  threadData->lastEquationSolved = 158;
}

/*
equation index: 159
type: SIMPLE_ASSIGN
gyroatk.w_2 = gyroatk.w_s / gyroatk.w_d
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_159(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,159};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[43]] /* gyroatk.w_s PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */),"gyroatk.w_d",equationIndexes);
  threadData->lastEquationSolved = 159;
}

/*
equation index: 160
type: SIMPLE_ASSIGN
gyroatk.k_d = gyroatk.m_d * gyroatk.w_d ^ 2.0
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_160(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,160};
  modelica_real tmp0;
  tmp0 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */);
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[25]] /* gyroatk.k_d PARAM */) = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[28]] /* gyroatk.m_d PARAM */)) * ((tmp0 * tmp0));
  threadData->lastEquationSolved = 160;
}

/*
equation index: 161
type: SIMPLE_ASSIGN
gyroatk.F_d = 2.0 * gyroatk.k_d * gyroatk.dis_d * gyroatk.zeta_d
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_161(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,161};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* gyroatk.F_d PARAM */) = (2.0) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[25]] /* gyroatk.k_d PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* gyroatk.dis_d PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* gyroatk.zeta_d PARAM */))));
  threadData->lastEquationSolved = 161;
}

/*
equation index: 162
type: SIMPLE_ASSIGN
gyroatk.D_s = gyroatk.F_d / (gyroatk.w_d ^ 2.0 * gyroatk.l_g * gyroatk.m_s)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_162(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,162};
  modelica_real tmp1;
  tmp1 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */);
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* gyroatk.D_s PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* gyroatk.F_d PARAM */),((tmp1 * tmp1)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[27]] /* gyroatk.l_g PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[29]] /* gyroatk.m_s PARAM */))),"gyroatk.w_d ^ 2.0 * gyroatk.l_g * gyroatk.m_s",equationIndexes);
  threadData->lastEquationSolved = 162;
}

/*
equation index: 163
type: SIMPLE_ASSIGN
gyroatk.X_d1 = sin(gyroatk.epsilon) * gyroatk.D_s / sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_163(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,163};
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  tmp2 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */);
  tmp3 = omc_GSQuad_Utils_avoidzero(threadData, 1.0 - ((tmp2 * tmp2)));
  tmp4 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[45]] /* gyroatk.zeta_s PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0) was %g should be >= 0", tmp5);
    }
  }
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* gyroatk.X_d1 PARAM */) = (sin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */))) * (DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* gyroatk.D_s PARAM */),sqrt(tmp5),"sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0)",equationIndexes));
  threadData->lastEquationSolved = 163;
}

/*
equation index: 164
type: SIMPLE_ASSIGN
gyroatk.X_d2 = 0.5 * sin(2.0 * gyroatk.epsilon) * gyroatk.D_s * sqrt(1.0 + (2.0 * gyroatk.zeta_d) ^ 2.0) / (sqrt(GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * cos(gyroatk.epsilon)) ^ 2.0) * sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0))
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_164(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,164};
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  tmp6 = (2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* gyroatk.zeta_d PARAM */));
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
  }tmp8 = omc_GSQuad_Utils_avoidzero(threadData, cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */)) - 1.0);
  tmp9 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* gyroatk.zeta_d PARAM */)) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */)));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * cos(gyroatk.epsilon)) ^ 2.0) was %g should be >= 0", tmp10);
    }
  }tmp11 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */);
  tmp12 = omc_GSQuad_Utils_avoidzero(threadData, 1.0 - ((tmp11 * tmp11)));
  tmp13 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[45]] /* gyroatk.zeta_s PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0) was %g should be >= 0", tmp14);
    }
  }
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[20]] /* gyroatk.X_d2 PARAM */) = (0.5) * ((sin((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */)))) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* gyroatk.D_s PARAM */)) * (DIVISION_SIM(sqrt(tmp7),(sqrt(tmp10)) * (sqrt(tmp14)),"sqrt(GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * cos(gyroatk.epsilon)) ^ 2.0) * sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_2 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_2) ^ 2.0)",equationIndexes))));
  threadData->lastEquationSolved = 164;
}

/*
equation index: 165
type: SIMPLE_ASSIGN
gyroatk.theta_d = atan(2.0 * gyroatk.zeta_s * gyroatk.w_2 / GSQuad.Utils.avoidzero(gyroatk.w_2 ^ 2.0 - 1.0))
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_165(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,165};
  modelica_real tmp15;
  tmp15 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */);
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[37]] /* gyroatk.theta_d PARAM */) = atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[45]] /* gyroatk.zeta_s PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */)),omc_GSQuad_Utils_avoidzero(threadData, (tmp15 * tmp15) - 1.0),"GSQuad.Utils.avoidzero(gyroatk.w_2 ^ 2.0 - 1.0)",equationIndexes));
  threadData->lastEquationSolved = 165;
}

/*
equation index: 166
type: SIMPLE_ASSIGN
gyroatk.phi_d = atan(2.0 * gyroatk.zeta_d * cos(gyroatk.epsilon) / GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0)) + atan(2.0 * gyroatk.zeta_s * gyroatk.w_2 / GSQuad.Utils.avoidzero(gyroatk.w_2 ^ 2.0 - 1.0)) - atan(2.0 * gyroatk.zeta_d)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_166(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,166};
  modelica_real tmp16;
  tmp16 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */);
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[33]] /* gyroatk.phi_d PARAM */) = atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* gyroatk.zeta_d PARAM */))) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */))),omc_GSQuad_Utils_avoidzero(threadData, cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */)) - 1.0),"GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - 1.0)",equationIndexes)) + atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[45]] /* gyroatk.zeta_s PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */)),omc_GSQuad_Utils_avoidzero(threadData, (tmp16 * tmp16) - 1.0),"GSQuad.Utils.avoidzero(gyroatk.w_2 ^ 2.0 - 1.0)",equationIndexes)) - atan((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* gyroatk.zeta_d PARAM */)));
  threadData->lastEquationSolved = 166;
}

/*
equation index: 167
type: SIMPLE_ASSIGN
gyroatk.Phi_d = atan((gyroatk.X_d1 * sin(gyroatk.theta_d) - gyroatk.X_d2 * sin(gyroatk.phi_d)) / GSQuad.Utils.avoidzero(gyroatk.X_d1 * cos(gyroatk.theta_d) - gyroatk.X_d2 * cos(gyroatk.phi_d)))
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_167(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,167};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[12]] /* gyroatk.Phi_d PARAM */) = atan(DIVISION_SIM(((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* gyroatk.X_d1 PARAM */)) * (sin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[37]] /* gyroatk.theta_d PARAM */))) - (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[20]] /* gyroatk.X_d2 PARAM */)) * (sin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[33]] /* gyroatk.phi_d PARAM */)))),omc_GSQuad_Utils_avoidzero(threadData, ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* gyroatk.X_d1 PARAM */)) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[37]] /* gyroatk.theta_d PARAM */))) - (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[20]] /* gyroatk.X_d2 PARAM */)) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[33]] /* gyroatk.phi_d PARAM */))))),"GSQuad.Utils.avoidzero(gyroatk.X_d1 * cos(gyroatk.theta_d) - gyroatk.X_d2 * cos(gyroatk.phi_d))",equationIndexes));
  threadData->lastEquationSolved = 167;
}

/*
equation index: 168
type: SIMPLE_ASSIGN
$cse2 = cos(gyroatk.Phi_d)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_168(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,168};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[0]] /* $cse2 PARAM */) = cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[12]] /* gyroatk.Phi_d PARAM */));
  threadData->lastEquationSolved = 168;
}

/*
equation index: 169
type: SIMPLE_ASSIGN
gyroatk.phi_0 = phi_0
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_169(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,169};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[31]] /* gyroatk.phi_0 PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[46]] /* phi_0 PARAM */);
  threadData->lastEquationSolved = 169;
}

/*
equation index: 170
type: SIMPLE_ASSIGN
gyroatk.W = W
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_170(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,170};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[14]] /* gyroatk.W PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* W PARAM */);
  threadData->lastEquationSolved = 170;
}

/*
equation index: 171
type: SIMPLE_ASSIGN
gyroatk.dist = dist
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_171(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,171};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* gyroatk.dist PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[3]] /* dist PARAM */);
  threadData->lastEquationSolved = 171;
}

/*
equation index: 172
type: SIMPLE_ASSIGN
gyroatk.SPL = 10.0 * log10(GSQuad.Utils.avoidzero(0.07957747163687819 * gyroatk.W / (415.03 * gyroatk.dist ^ 2.0 * gyroatk.p0 ^ 2.0)))
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_172(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,172};
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  tmp17 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* gyroatk.dist PARAM */);
  tmp18 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[30]] /* gyroatk.p0 PARAM */);
  tmp19 = omc_GSQuad_Utils_avoidzero(threadData, DIVISION_SIM((0.07957747163687819) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[14]] /* gyroatk.W PARAM */)),((415.03) * ((tmp17 * tmp17))) * ((tmp18 * tmp18)),"415.03 * gyroatk.dist ^ 2.0 * gyroatk.p0 ^ 2.0",equationIndexes));
  if(!(tmp19 > 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of log10(GSQuad.Utils.avoidzero(0.07957747163687819 * gyroatk.W / (415.03 * gyroatk.dist ^ 2.0 * gyroatk.p0 ^ 2.0))) was %g should be > 0", tmp19);
    }
  }
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[13]] /* gyroatk.SPL PARAM */) = (10.0) * (log10(tmp19));
  threadData->lastEquationSolved = 172;
}

/*
equation index: 173
type: SIMPLE_ASSIGN
gyroatk.A = gyroatk.p0 * 10.0 ^ (0.05 * gyroatk.SPL) * (2.0 * gyroatk.dis_d) ^ 2.0
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_173(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,173};
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_real tmp27;
  tmp20 = 10.0;
  tmp21 = (0.05) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[13]] /* gyroatk.SPL PARAM */));
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
  }tmp27 = (2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* gyroatk.dis_d PARAM */));
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* gyroatk.A PARAM */) = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[30]] /* gyroatk.p0 PARAM */)) * ((tmp22) * ((tmp27 * tmp27)));
  threadData->lastEquationSolved = 173;
}

/*
equation index: 174
type: SIMPLE_ASSIGN
gyroatk.psi_ac = psi_ac
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_174(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,174};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[35]] /* gyroatk.psi_ac PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[47]] /* psi_ac PARAM */);
  threadData->lastEquationSolved = 174;
}

/*
equation index: 175
type: SIMPLE_ASSIGN
gyroatk.A_x = gyroatk.A * cos(gyroatk.psi_ac)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_175(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,175};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[6]] /* gyroatk.A_x PARAM */) = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* gyroatk.A PARAM */)) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[35]] /* gyroatk.psi_ac PARAM */)));
  threadData->lastEquationSolved = 175;
}

/*
equation index: 176
type: SIMPLE_ASSIGN
gyroatk.w_ac = w_ac
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_176(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,176};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[41]] /* gyroatk.w_ac PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[95]] /* w_ac PARAM */);
  threadData->lastEquationSolved = 176;
}

/*
equation index: 177
type: SIMPLE_ASSIGN
gyroatk.w_3 = gyroatk.w_ac / gyroatk.w_s
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_177(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,177};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* gyroatk.w_3 PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[41]] /* gyroatk.w_ac PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[43]] /* gyroatk.w_s PARAM */),"gyroatk.w_s",equationIndexes);
  threadData->lastEquationSolved = 177;
}

/*
equation index: 178
type: SIMPLE_ASSIGN
gyroatk.X_acx = gyroatk.A_x / ((gyroatk.w_d * gyroatk.w_2) ^ 2.0 * sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) * gyroatk.l_g * gyroatk.m_s)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_178(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,178};
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  tmp28 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[39]] /* gyroatk.w_2 PARAM */));
  tmp29 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* gyroatk.w_3 PARAM */);
  tmp30 = omc_GSQuad_Utils_avoidzero(threadData, 1.0 - ((tmp29 * tmp29)));
  tmp31 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[45]] /* gyroatk.zeta_s PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* gyroatk.w_3 PARAM */));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) was %g should be >= 0", tmp32);
    }
  }
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[16]] /* gyroatk.X_acx PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[6]] /* gyroatk.A_x PARAM */),((tmp28 * tmp28)) * (((sqrt(tmp32)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[27]] /* gyroatk.l_g PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[29]] /* gyroatk.m_s PARAM */))),"(gyroatk.w_d * gyroatk.w_2) ^ 2.0 * sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) * gyroatk.l_g * gyroatk.m_s",equationIndexes);
  threadData->lastEquationSolved = 178;
}

/*
equation index: 179
type: SIMPLE_ASSIGN
gyroatk.A_y = gyroatk.A * sin(gyroatk.psi_ac)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_179(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,179};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[7]] /* gyroatk.A_y PARAM */) = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* gyroatk.A PARAM */)) * (sin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[35]] /* gyroatk.psi_ac PARAM */)));
  threadData->lastEquationSolved = 179;
}

/*
equation index: 180
type: SIMPLE_ASSIGN
gyroatk.k_s = gyroatk.m_s * gyroatk.w_s ^ 2.0
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_180(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,180};
  modelica_real tmp33;
  tmp33 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[43]] /* gyroatk.w_s PARAM */);
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[26]] /* gyroatk.k_s PARAM */) = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[29]] /* gyroatk.m_s PARAM */)) * ((tmp33 * tmp33));
  threadData->lastEquationSolved = 180;
}

/*
equation index: 181
type: SIMPLE_ASSIGN
gyroatk.k_bar = gyroatk.k_d / gyroatk.k_s
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_181(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,181};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[24]] /* gyroatk.k_bar PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[25]] /* gyroatk.k_d PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[26]] /* gyroatk.k_s PARAM */),"gyroatk.k_s",equationIndexes);
  threadData->lastEquationSolved = 181;
}

/*
equation index: 182
type: SIMPLE_ASSIGN
gyroatk.w_1 = gyroatk.w_ac / gyroatk.w_d
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_182(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,182};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[38]] /* gyroatk.w_1 PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[41]] /* gyroatk.w_ac PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */),"gyroatk.w_d",equationIndexes);
  threadData->lastEquationSolved = 182;
}

/*
equation index: 183
type: SIMPLE_ASSIGN
gyroatk.X_acy = sqrt(1.0 + 4.0 * (gyroatk.zeta_d * gyroatk.w_1) ^ 2.0) * gyroatk.k_bar * sin(gyroatk.epsilon) * gyroatk.A_y / (gyroatk.w_d ^ 2.0 * sqrt(GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * gyroatk.w_1 * cos(gyroatk.epsilon)) ^ 2.0) * sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) * gyroatk.l_g * gyroatk.m_d)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_183(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,183};
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
  tmp34 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* gyroatk.zeta_d PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[38]] /* gyroatk.w_1 PARAM */));
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
  }tmp36 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */);
  tmp37 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[38]] /* gyroatk.w_1 PARAM */);
  tmp38 = omc_GSQuad_Utils_avoidzero(threadData, cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */)) - ((tmp37 * tmp37)));
  tmp39 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* gyroatk.zeta_d PARAM */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[38]] /* gyroatk.w_1 PARAM */)) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */))));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * gyroatk.w_1 * cos(gyroatk.epsilon)) ^ 2.0) was %g should be >= 0", tmp40);
    }
  }tmp41 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* gyroatk.w_3 PARAM */);
  tmp42 = omc_GSQuad_Utils_avoidzero(threadData, 1.0 - ((tmp41 * tmp41)));
  tmp43 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[45]] /* gyroatk.zeta_s PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* gyroatk.w_3 PARAM */));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) was %g should be >= 0", tmp44);
    }
  }
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[17]] /* gyroatk.X_acy PARAM */) = (sqrt(tmp35)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[24]] /* gyroatk.k_bar PARAM */)) * ((sin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */))) * (DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[7]] /* gyroatk.A_y PARAM */),((tmp36 * tmp36)) * ((((sqrt(tmp40)) * (sqrt(tmp44))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[27]] /* gyroatk.l_g PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[28]] /* gyroatk.m_d PARAM */))),"gyroatk.w_d ^ 2.0 * sqrt(GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_d * gyroatk.w_1 * cos(gyroatk.epsilon)) ^ 2.0) * sqrt(GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0) ^ 2.0 + 4.0 * (gyroatk.zeta_s * gyroatk.w_3) ^ 2.0) * gyroatk.l_g * gyroatk.m_d",equationIndexes))));
  threadData->lastEquationSolved = 183;
}

/*
equation index: 184
type: SIMPLE_ASSIGN
gyroatk.phi_ac = atan(2.0 * gyroatk.zeta_s * gyroatk.w_3 / GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0))
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_184(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,184};
  modelica_real tmp45;
  tmp45 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* gyroatk.w_3 PARAM */);
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[32]] /* gyroatk.phi_ac PARAM */) = atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[45]] /* gyroatk.zeta_s PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* gyroatk.w_3 PARAM */)),omc_GSQuad_Utils_avoidzero(threadData, 1.0 - ((tmp45 * tmp45))),"GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0)",equationIndexes));
  threadData->lastEquationSolved = 184;
}

/*
equation index: 185
type: SIMPLE_ASSIGN
gyroatk.phi_y = atan(2.0 * gyroatk.zeta_d * gyroatk.w_1 * cos(gyroatk.epsilon) / GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0)) + atan(2.0 * gyroatk.zeta_s * gyroatk.w_3 / GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0)) - atan(2.0 * gyroatk.zeta_d * gyroatk.w_1)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_185(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,185};
  modelica_real tmp46;
  modelica_real tmp47;
  tmp46 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[38]] /* gyroatk.w_1 PARAM */);
  tmp47 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* gyroatk.w_3 PARAM */);
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[34]] /* gyroatk.phi_y PARAM */) = atan(DIVISION_SIM((((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* gyroatk.zeta_d PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[38]] /* gyroatk.w_1 PARAM */))) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */))),omc_GSQuad_Utils_avoidzero(threadData, cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* gyroatk.epsilon PARAM */)) - ((tmp46 * tmp46))),"GSQuad.Utils.avoidzero(cos(gyroatk.epsilon) - gyroatk.w_1 ^ 2.0)",equationIndexes)) + atan(DIVISION_SIM(((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[45]] /* gyroatk.zeta_s PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[40]] /* gyroatk.w_3 PARAM */)),omc_GSQuad_Utils_avoidzero(threadData, 1.0 - ((tmp47 * tmp47))),"GSQuad.Utils.avoidzero(1.0 - gyroatk.w_3 ^ 2.0)",equationIndexes)) - atan(((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[44]] /* gyroatk.zeta_d PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[38]] /* gyroatk.w_1 PARAM */)));
  threadData->lastEquationSolved = 185;
}

/*
equation index: 186
type: SIMPLE_ASSIGN
gyroatk.Phi_ac = atan((gyroatk.X_acx * sin(gyroatk.phi_0 + gyroatk.phi_ac) - gyroatk.X_acy * sin(gyroatk.phi_0 + gyroatk.phi_y)) / GSQuad.Utils.avoidzero(gyroatk.X_acx * cos(gyroatk.phi_0 + gyroatk.phi_ac) - gyroatk.X_acy * cos(gyroatk.phi_0 + gyroatk.phi_y)))
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_186(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,186};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* gyroatk.Phi_ac PARAM */) = atan(DIVISION_SIM(((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[16]] /* gyroatk.X_acx PARAM */)) * (sin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[31]] /* gyroatk.phi_0 PARAM */) + (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[32]] /* gyroatk.phi_ac PARAM */))) - (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[17]] /* gyroatk.X_acy PARAM */)) * (sin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[31]] /* gyroatk.phi_0 PARAM */) + (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[34]] /* gyroatk.phi_y PARAM */)))),omc_GSQuad_Utils_avoidzero(threadData, ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[16]] /* gyroatk.X_acx PARAM */)) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[31]] /* gyroatk.phi_0 PARAM */) + (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[32]] /* gyroatk.phi_ac PARAM */))) - (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[17]] /* gyroatk.X_acy PARAM */)) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[31]] /* gyroatk.phi_0 PARAM */) + (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[34]] /* gyroatk.phi_y PARAM */))))),"GSQuad.Utils.avoidzero(gyroatk.X_acx * cos(gyroatk.phi_0 + gyroatk.phi_ac) - gyroatk.X_acy * cos(gyroatk.phi_0 + gyroatk.phi_y))",equationIndexes));
  threadData->lastEquationSolved = 186;
}

/*
equation index: 187
type: SIMPLE_ASSIGN
gyroatk.X_d = sqrt(2.0 * gyroatk.X_d1 ^ 2.0 - 2.0 * gyroatk.X_d1 * gyroatk.X_d2 * cos(gyroatk.phi_d - gyroatk.theta_d))
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_187(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,187};
  modelica_real tmp48;
  modelica_real tmp49;
  tmp48 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* gyroatk.X_d1 PARAM */);
  tmp49 = (2.0) * ((tmp48 * tmp48)) - ((((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* gyroatk.X_d1 PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[20]] /* gyroatk.X_d2 PARAM */))) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[33]] /* gyroatk.phi_d PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[37]] /* gyroatk.theta_d PARAM */))));
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
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[18]] /* gyroatk.X_d PARAM */) = sqrt(tmp49);
  threadData->lastEquationSolved = 187;
}

/*
equation index: 188
type: SIMPLE_ASSIGN
gyroatk.X_ac = sqrt(gyroatk.X_acx ^ 2.0 + gyroatk.X_acy ^ 2.0 - 2.0 * gyroatk.X_acx * gyroatk.X_acy * cos(gyroatk.phi_ac - gyroatk.phi_y))
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_188(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,188};
  modelica_real tmp50;
  modelica_real tmp51;
  modelica_real tmp52;
  tmp50 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[16]] /* gyroatk.X_acx PARAM */);
  tmp51 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[17]] /* gyroatk.X_acy PARAM */);
  tmp52 = (tmp50 * tmp50) + (tmp51 * tmp51) - ((((2.0) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[16]] /* gyroatk.X_acx PARAM */))) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[17]] /* gyroatk.X_acy PARAM */))) * (cos((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[32]] /* gyroatk.phi_ac PARAM */) - (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[34]] /* gyroatk.phi_y PARAM */))));
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
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[15]] /* gyroatk.X_ac PARAM */) = sqrt(tmp52);
  threadData->lastEquationSolved = 188;
}

/*
equation index: 189
type: SIMPLE_ASSIGN
gyroatk.D_d = gyroatk.F_d / (gyroatk.w_d ^ 2.0 * gyroatk.l_g * gyroatk.m_d)
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_189(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,189};
  modelica_real tmp53;
  tmp53 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[42]] /* gyroatk.w_d PARAM */);
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[8]] /* gyroatk.D_d PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* gyroatk.F_d PARAM */),((tmp53 * tmp53)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[27]] /* gyroatk.l_g PARAM */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[28]] /* gyroatk.m_d PARAM */))),"gyroatk.w_d ^ 2.0 * gyroatk.l_g * gyroatk.m_d",equationIndexes);
  threadData->lastEquationSolved = 189;
}

/*
equation index: 190
type: SIMPLE_ASSIGN
quad_low.rotor_pos[2,4] = (-0.7071067856286897) * quad_low.d_arm
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_190(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,190};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[89]] /* quad_low.rotor_pos[2,4] PARAM */) = (-0.7071067856286897) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[75]] /* quad_low.d_arm PARAM */));
  threadData->lastEquationSolved = 190;
}

/*
equation index: 191
type: SIMPLE_ASSIGN
quad_low.rotor_pos[2,3] = (-0.7071067780135887) * quad_low.d_arm
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_191(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,191};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[88]] /* quad_low.rotor_pos[2,3] PARAM */) = (-0.7071067780135887) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[75]] /* quad_low.d_arm PARAM */));
  threadData->lastEquationSolved = 191;
}

/*
equation index: 192
type: SIMPLE_ASSIGN
quad_low.rotor_pos[2,2] = 0.7071067830903227 * quad_low.d_arm
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_192(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,192};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[87]] /* quad_low.rotor_pos[2,2] PARAM */) = (0.7071067830903227) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[75]] /* quad_low.d_arm PARAM */));
  threadData->lastEquationSolved = 192;
}

/*
equation index: 193
type: SIMPLE_ASSIGN
quad_low.rotor_pos[2,1] = 0.7071067805519557 * quad_low.d_arm
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_193(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,193};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[86]] /* quad_low.rotor_pos[2,1] PARAM */) = (0.7071067805519557) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[75]] /* quad_low.d_arm PARAM */));
  threadData->lastEquationSolved = 193;
}

/*
equation index: 194
type: SIMPLE_ASSIGN
quad_low.rotor_pos[1,4] = 0.7071067767444054 * quad_low.d_arm
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_194(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,194};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[85]] /* quad_low.rotor_pos[1,4] PARAM */) = (0.7071067767444054) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[75]] /* quad_low.d_arm PARAM */));
  threadData->lastEquationSolved = 194;
}

/*
equation index: 195
type: SIMPLE_ASSIGN
quad_low.rotor_pos[1,3] = (-0.7071067843595064) * quad_low.d_arm
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_195(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,195};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[84]] /* quad_low.rotor_pos[1,3] PARAM */) = (-0.7071067843595064) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[75]] /* quad_low.d_arm PARAM */));
  threadData->lastEquationSolved = 195;
}

/*
equation index: 196
type: SIMPLE_ASSIGN
quad_low.rotor_pos[1,2] = (-0.7071067792827723) * quad_low.d_arm
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_196(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,196};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[83]] /* quad_low.rotor_pos[1,2] PARAM */) = (-0.7071067792827723) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[75]] /* quad_low.d_arm PARAM */));
  threadData->lastEquationSolved = 196;
}

/*
equation index: 197
type: SIMPLE_ASSIGN
quad_low.rotor_pos[1,1] = 0.7071067818211393 * quad_low.d_arm
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_197(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,197};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[82]] /* quad_low.rotor_pos[1,1] PARAM */) = (0.7071067818211393) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[75]] /* quad_low.d_arm PARAM */));
  threadData->lastEquationSolved = 197;
}

/*
equation index: 198
type: ARRAY_CALL_ASSIGN

quad_low.Jinv = GSQuad.Utils.inv3x3({{quad_low.Ixx, quad_low.Ixy, quad_low.Ixz}, {quad_low.Ixy, quad_low.Iyy, quad_low.Iyz}, {quad_low.Ixz, quad_low.Iyz, quad_low.Izz}})
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_198(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,198};
  real_array tmp54;
  real_array tmp55;
  real_array tmp56;
  real_array tmp57;
  real_array tmp58;
  array_alloc_scalar_real_array(&tmp55, 3, (modelica_real)(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[51]] /* quad_low.Ixx PARAM */), (modelica_real)(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[52]] /* quad_low.Ixy PARAM */), (modelica_real)(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[53]] /* quad_low.Ixz PARAM */));
  array_alloc_scalar_real_array(&tmp56, 3, (modelica_real)(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[52]] /* quad_low.Ixy PARAM */), (modelica_real)(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[54]] /* quad_low.Iyy PARAM */), (modelica_real)(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[55]] /* quad_low.Iyz PARAM */));
  array_alloc_scalar_real_array(&tmp57, 3, (modelica_real)(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[53]] /* quad_low.Ixz PARAM */), (modelica_real)(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[55]] /* quad_low.Iyz PARAM */), (modelica_real)(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[56]] /* quad_low.Izz PARAM */));
  array_alloc_real_array(&tmp54, 3, tmp55, tmp56, tmp57);
  real_array_create(&tmp58, ((modelica_real*)&((&(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[66]] /* quad_low.Jinv[1,1] PARAM */))[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(omc_GSQuad_Utils_inv3x3(threadData, tmp54), tmp58);
  threadData->lastEquationSolved = 198;
}

/*
equation index: 199
type: SIMPLE_ASSIGN
quad_low.J[3,3] = quad_low.Izz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_199(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,199};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[65]] /* quad_low.J[3,3] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[56]] /* quad_low.Izz PARAM */);
  threadData->lastEquationSolved = 199;
}

/*
equation index: 200
type: SIMPLE_ASSIGN
quad_low.J[3,2] = quad_low.Iyz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_200(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,200};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[64]] /* quad_low.J[3,2] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[55]] /* quad_low.Iyz PARAM */);
  threadData->lastEquationSolved = 200;
}

/*
equation index: 201
type: SIMPLE_ASSIGN
quad_low.J[3,1] = quad_low.Ixz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_201(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,201};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[63]] /* quad_low.J[3,1] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[53]] /* quad_low.Ixz PARAM */);
  threadData->lastEquationSolved = 201;
}

/*
equation index: 202
type: SIMPLE_ASSIGN
quad_low.J[2,3] = quad_low.Iyz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_202(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,202};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* quad_low.J[2,3] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[55]] /* quad_low.Iyz PARAM */);
  threadData->lastEquationSolved = 202;
}

/*
equation index: 203
type: SIMPLE_ASSIGN
quad_low.J[2,2] = quad_low.Iyy
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_203(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,203};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[61]] /* quad_low.J[2,2] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[54]] /* quad_low.Iyy PARAM */);
  threadData->lastEquationSolved = 203;
}

/*
equation index: 204
type: SIMPLE_ASSIGN
quad_low.J[2,1] = quad_low.Ixy
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_204(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,204};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[60]] /* quad_low.J[2,1] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[52]] /* quad_low.Ixy PARAM */);
  threadData->lastEquationSolved = 204;
}

/*
equation index: 205
type: SIMPLE_ASSIGN
quad_low.J[1,3] = quad_low.Ixz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_205(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,205};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* quad_low.J[1,3] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[53]] /* quad_low.Ixz PARAM */);
  threadData->lastEquationSolved = 205;
}

/*
equation index: 206
type: SIMPLE_ASSIGN
quad_low.J[1,2] = quad_low.Ixy
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_206(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,206};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[58]] /* quad_low.J[1,2] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[52]] /* quad_low.Ixy PARAM */);
  threadData->lastEquationSolved = 206;
}

/*
equation index: 207
type: SIMPLE_ASSIGN
quad_low.J[1,1] = quad_low.Ixx
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Quadrotor_eqFunction_207(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,207};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[57]] /* quad_low.J[1,1] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[51]] /* quad_low.Ixx PARAM */);
  threadData->lastEquationSolved = 207;
}
extern void GSQuad_Components_Quadrotor_eqFunction_4(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_3(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_2(DATA *data, threadData_t *threadData);

extern void GSQuad_Components_Quadrotor_eqFunction_1(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void GSQuad_Components_Quadrotor_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[54])(DATA*, threadData_t*) = {
    GSQuad_Components_Quadrotor_eqFunction_158,
    GSQuad_Components_Quadrotor_eqFunction_159,
    GSQuad_Components_Quadrotor_eqFunction_160,
    GSQuad_Components_Quadrotor_eqFunction_161,
    GSQuad_Components_Quadrotor_eqFunction_162,
    GSQuad_Components_Quadrotor_eqFunction_163,
    GSQuad_Components_Quadrotor_eqFunction_164,
    GSQuad_Components_Quadrotor_eqFunction_165,
    GSQuad_Components_Quadrotor_eqFunction_166,
    GSQuad_Components_Quadrotor_eqFunction_167,
    GSQuad_Components_Quadrotor_eqFunction_168,
    GSQuad_Components_Quadrotor_eqFunction_169,
    GSQuad_Components_Quadrotor_eqFunction_170,
    GSQuad_Components_Quadrotor_eqFunction_171,
    GSQuad_Components_Quadrotor_eqFunction_172,
    GSQuad_Components_Quadrotor_eqFunction_173,
    GSQuad_Components_Quadrotor_eqFunction_174,
    GSQuad_Components_Quadrotor_eqFunction_175,
    GSQuad_Components_Quadrotor_eqFunction_176,
    GSQuad_Components_Quadrotor_eqFunction_177,
    GSQuad_Components_Quadrotor_eqFunction_178,
    GSQuad_Components_Quadrotor_eqFunction_179,
    GSQuad_Components_Quadrotor_eqFunction_180,
    GSQuad_Components_Quadrotor_eqFunction_181,
    GSQuad_Components_Quadrotor_eqFunction_182,
    GSQuad_Components_Quadrotor_eqFunction_183,
    GSQuad_Components_Quadrotor_eqFunction_184,
    GSQuad_Components_Quadrotor_eqFunction_185,
    GSQuad_Components_Quadrotor_eqFunction_186,
    GSQuad_Components_Quadrotor_eqFunction_187,
    GSQuad_Components_Quadrotor_eqFunction_188,
    GSQuad_Components_Quadrotor_eqFunction_189,
    GSQuad_Components_Quadrotor_eqFunction_190,
    GSQuad_Components_Quadrotor_eqFunction_191,
    GSQuad_Components_Quadrotor_eqFunction_192,
    GSQuad_Components_Quadrotor_eqFunction_193,
    GSQuad_Components_Quadrotor_eqFunction_194,
    GSQuad_Components_Quadrotor_eqFunction_195,
    GSQuad_Components_Quadrotor_eqFunction_196,
    GSQuad_Components_Quadrotor_eqFunction_197,
    GSQuad_Components_Quadrotor_eqFunction_198,
    GSQuad_Components_Quadrotor_eqFunction_199,
    GSQuad_Components_Quadrotor_eqFunction_200,
    GSQuad_Components_Quadrotor_eqFunction_201,
    GSQuad_Components_Quadrotor_eqFunction_202,
    GSQuad_Components_Quadrotor_eqFunction_203,
    GSQuad_Components_Quadrotor_eqFunction_204,
    GSQuad_Components_Quadrotor_eqFunction_205,
    GSQuad_Components_Quadrotor_eqFunction_206,
    GSQuad_Components_Quadrotor_eqFunction_207,
    GSQuad_Components_Quadrotor_eqFunction_4,
    GSQuad_Components_Quadrotor_eqFunction_3,
    GSQuad_Components_Quadrotor_eqFunction_2,
    GSQuad_Components_Quadrotor_eqFunction_1
  };
  
  for (int id = 0; id < 54; id++) {
    eqFunctions[id](data, threadData);
  }
}
OMC_DISABLE_OPT
int GSQuad_Components_Quadrotor_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  (data->simulationInfo->integerParameter[data->simulationInfo->integerParamsIndex[0]] /* fidelity PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[0].time_unvarying = 1;
  GSQuad_Components_Quadrotor_updateBoundParameters_0(data, threadData);
  return 0;
}

#if defined(__cplusplus)
}
#endif
