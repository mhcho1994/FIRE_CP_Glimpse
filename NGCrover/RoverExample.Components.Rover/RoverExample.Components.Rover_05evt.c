/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "RoverExample.Components.Rover_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void RoverExample_Components_Rover_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
  /* sample 1 */
  data->modelData->samplesInfo[i].index = 1;
  data->modelData->samplesInfo[i].start = 0.0;
  data->modelData->samplesInfo[i].interval = (data->simulationInfo->realParameter[42] /* gyroatk.sample_interval PARAM */) /* (max real for single time events) */;
  i++;
  /* sample 2 */
  data->modelData->samplesInfo[i].index = 2;
  data->modelData->samplesInfo[i].start = 0.0;
  data->modelData->samplesInfo[i].interval = (data->simulationInfo->realParameter[130] /* sample_interval PARAM */) /* (max real for single time events) */;
  i++;
}

const char *RoverExample_Components_Rover_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"rover_8d.lambda > 6.2831853",
  "rover_8d.delta == 0.0",
  "rover_8d.delta <> 0.0",
  "mod(rover_8d.psi + 3.14159265, 6.2831853, 0)",
  "rover_8d.z_rl < 1.0",
  "rover_8d.z_fl < 1.0",
  "rover_8d.z_fr < 1.0",
  "rover_8d.z_rr < 1.0",
  "rover_8d.Fz_fl <= 1.5 or rover_8d.Fz_fr <= 1.5 or rover_8d.Fz_rl <= 1.5 or rover_8d.Fz_rr <= 1.5",
  "mod(rover_3d.psi + 3.14159265, 6.2831853, 4)",
  "rover_3d.delta <> 0.0",
  "rover_3d.delta == 0.0",
  "9.80665 * $cse40 <= rover_3d.vx ^ 2.0 / rover_3d.turn_radius * $cse41",
  "9.80665 * $cse40 > rover_3d.vx ^ 2.0 / rover_3d.turn_radius * $cse41"};
  static const int occurEqs0[] = {1,272};
  static const int occurEqs1[] = {1,269};
  static const int occurEqs2[] = {1,268};
  static const int occurEqs3[] = {1,260};
  static const int occurEqs4[] = {1,-1};
  static const int occurEqs5[] = {1,-1};
  static const int occurEqs6[] = {1,-1};
  static const int occurEqs7[] = {1,-1};
  static const int occurEqs8[] = {1,350};
  static const int occurEqs9[] = {1,231};
  static const int occurEqs10[] = {1,216};
  static const int occurEqs11[] = {1,217};
  static const int occurEqs12[] = {1,220};
  static const int occurEqs13[] = {1,221};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5,occurEqs6,occurEqs7,occurEqs8,occurEqs9,occurEqs10,occurEqs11,occurEqs12,occurEqs13};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void RoverExample_Components_Rover_eqFunction_214(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_215(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_216(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_217(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_224(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_225(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_226(DATA* data, threadData_t *threadData);
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
extern void RoverExample_Components_Rover_eqFunction_254(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_273(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_275(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_279(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_280(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_281(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_282(DATA* data, threadData_t *threadData);
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

int RoverExample_Components_Rover_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  RoverExample_Components_Rover_eqFunction_214(data, threadData);

  RoverExample_Components_Rover_eqFunction_215(data, threadData);

  RoverExample_Components_Rover_eqFunction_216(data, threadData);

  RoverExample_Components_Rover_eqFunction_217(data, threadData);

  RoverExample_Components_Rover_eqFunction_224(data, threadData);

  RoverExample_Components_Rover_eqFunction_225(data, threadData);

  RoverExample_Components_Rover_eqFunction_226(data, threadData);

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

  RoverExample_Components_Rover_eqFunction_254(data, threadData);

  RoverExample_Components_Rover_eqFunction_273(data, threadData);

  RoverExample_Components_Rover_eqFunction_275(data, threadData);

  RoverExample_Components_Rover_eqFunction_279(data, threadData);

  RoverExample_Components_Rover_eqFunction_280(data, threadData);

  RoverExample_Components_Rover_eqFunction_281(data, threadData);

  RoverExample_Components_Rover_eqFunction_282(data, threadData);

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

  RoverExample_Components_Rover_eqFunction_348(data, threadData);

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
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_boolean tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_boolean tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_boolean tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_real tmp36;
  modelica_boolean tmp37;
  modelica_real tmp38;
  modelica_real tmp39;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  start_index = current_index;
  tmp2 = 1.0;
  tmp3 = 6.2831853;
  tmp1 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */), 6.2831853, tmp2, tmp3, data->simulationInfo->storedRelations[0]);
  gout[start_index] = (tmp1) ? 1 : -1;
  current_index++;

  start_index = current_index;
  gout[start_index] = (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */) == 0.0)) ? 1 : -1;
  current_index++;

  start_index = current_index;
  gout[start_index] = (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */) != 0.0)) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp4 = floor(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */) + 3.14159265) / (6.2831853));
  tmp5 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)+1]));
  gout[start_index] = tmp4 != tmp5 ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp7 = 1.0;
  tmp8 = 1.0;
  tmp6 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */), 1.0, tmp7, tmp8, data->simulationInfo->storedRelations[3]);
  gout[start_index] = (tmp6) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp10 = 1.0;
  tmp11 = 1.0;
  tmp9 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */), 1.0, tmp10, tmp11, data->simulationInfo->storedRelations[4]);
  gout[start_index] = (tmp9) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp13 = 1.0;
  tmp14 = 1.0;
  tmp12 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */), 1.0, tmp13, tmp14, data->simulationInfo->storedRelations[5]);
  gout[start_index] = (tmp12) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp16 = 1.0;
  tmp17 = 1.0;
  tmp15 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */), 1.0, tmp16, tmp17, data->simulationInfo->storedRelations[6]);
  gout[start_index] = (tmp15) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp19 = 1.0;
  tmp20 = 1.5;
  tmp18 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */), 1.5, tmp19, tmp20, data->simulationInfo->storedRelations[7]);
  tmp22 = 1.0;
  tmp23 = 1.5;
  tmp21 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */), 1.5, tmp22, tmp23, data->simulationInfo->storedRelations[8]);
  tmp25 = 1.0;
  tmp26 = 1.5;
  tmp24 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */), 1.5, tmp25, tmp26, data->simulationInfo->storedRelations[9]);
  tmp28 = 1.0;
  tmp29 = 1.5;
  tmp27 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */), 1.5, tmp28, tmp29, data->simulationInfo->storedRelations[10]);
  gout[start_index] = ((((tmp18 || tmp21) || tmp24) || tmp27)) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp30 = floor(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */) + 3.14159265) / (6.2831853));
  tmp31 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 4)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 4)+1]));
  gout[start_index] = tmp30 != tmp31 ? 1 : -1;
  current_index++;

  start_index = current_index;
  gout[start_index] = (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) != 0.0)) ? 1 : -1;
  current_index++;

  start_index = current_index;
  gout[start_index] = (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) == 0.0)) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp32 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
  tmp34 = (9.80665) * (fabs((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)));
  tmp35 = (1.0) * (fabs((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)));
  tmp33 = LessEqZC((9.80665) * ((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)), (DIVISION((tmp32 * tmp32),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius")) * ((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)), tmp34, tmp35, data->simulationInfo->storedRelations[13]);
  gout[start_index] = (tmp33) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp36 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
  tmp38 = (9.80665) * (fabs((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)));
  tmp39 = (1.0) * (fabs((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)));
  tmp37 = GreaterZC((9.80665) * ((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)), (DIVISION((tmp36 * tmp36),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius")) * ((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)), tmp38, tmp39, data->simulationInfo->storedRelations[14]);
  gout[start_index] = (tmp37) ? 1 : -1;
  current_index++;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *RoverExample_Components_Rover_relationDescription(int i)
{
  const char *res[] = {"rover_8d.lambda > 6.2831853",
  "rover_8d.delta == 0.0",
  "rover_8d.delta <> 0.0",
  "rover_8d.z_rl < 1.0",
  "rover_8d.z_fl < 1.0",
  "rover_8d.z_fr < 1.0",
  "rover_8d.z_rr < 1.0",
  "rover_8d.Fz_fl <= 1.5",
  "rover_8d.Fz_fr <= 1.5",
  "rover_8d.Fz_rl <= 1.5",
  "rover_8d.Fz_rr <= 1.5",
  "rover_3d.delta <> 0.0",
  "rover_3d.delta == 0.0",
  "9.80665 * $cse40 <= rover_3d.vx ^ 2.0 / rover_3d.turn_radius * $cse41",
  "9.80665 * $cse40 > rover_3d.vx ^ 2.0 / rover_3d.turn_radius * $cse41"};
  return res[i];
}

int RoverExample_Components_Rover_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp40;
  modelica_real tmp41;
  modelica_real tmp42;
  modelica_boolean tmp43;
  modelica_real tmp44;
  modelica_real tmp45;
  modelica_boolean tmp46;
  modelica_real tmp47;
  modelica_real tmp48;
  modelica_boolean tmp49;
  modelica_real tmp50;
  modelica_real tmp51;
  modelica_boolean tmp52;
  modelica_real tmp53;
  modelica_real tmp54;
  modelica_boolean tmp55;
  modelica_real tmp56;
  modelica_real tmp57;
  modelica_boolean tmp58;
  modelica_real tmp59;
  modelica_real tmp60;
  modelica_boolean tmp61;
  modelica_real tmp62;
  modelica_real tmp63;
  modelica_boolean tmp64;
  modelica_real tmp65;
  modelica_real tmp66;
  modelica_real tmp67;
  modelica_boolean tmp68;
  modelica_real tmp69;
  modelica_real tmp70;
  modelica_real tmp71;
  modelica_boolean tmp72;
  modelica_real tmp73;
  modelica_real tmp74;
  modelica_real tmp75;
  modelica_real tmp76;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
  if(evalforZeroCross) {
    start_index = current_index;
    tmp41 = 1.0;
    tmp42 = 6.2831853;
    tmp40 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */), 6.2831853, tmp41, tmp42, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[start_index] = tmp40;
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */) == 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */) != 0.0);
    current_index++;

    start_index = current_index;
    tmp44 = 1.0;
    tmp45 = 1.0;
    tmp43 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */), 1.0, tmp44, tmp45, data->simulationInfo->storedRelations[3]);
    data->simulationInfo->relations[start_index] = tmp43;
    current_index++;

    start_index = current_index;
    tmp47 = 1.0;
    tmp48 = 1.0;
    tmp46 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */), 1.0, tmp47, tmp48, data->simulationInfo->storedRelations[4]);
    data->simulationInfo->relations[start_index] = tmp46;
    current_index++;

    start_index = current_index;
    tmp50 = 1.0;
    tmp51 = 1.0;
    tmp49 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */), 1.0, tmp50, tmp51, data->simulationInfo->storedRelations[5]);
    data->simulationInfo->relations[start_index] = tmp49;
    current_index++;

    start_index = current_index;
    tmp53 = 1.0;
    tmp54 = 1.0;
    tmp52 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */), 1.0, tmp53, tmp54, data->simulationInfo->storedRelations[6]);
    data->simulationInfo->relations[start_index] = tmp52;
    current_index++;

    start_index = current_index;
    tmp56 = 1.0;
    tmp57 = 1.5;
    tmp55 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */), 1.5, tmp56, tmp57, data->simulationInfo->storedRelations[7]);
    data->simulationInfo->relations[start_index] = tmp55;
    current_index++;

    start_index = current_index;
    tmp59 = 1.0;
    tmp60 = 1.5;
    tmp58 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */), 1.5, tmp59, tmp60, data->simulationInfo->storedRelations[8]);
    data->simulationInfo->relations[start_index] = tmp58;
    current_index++;

    start_index = current_index;
    tmp62 = 1.0;
    tmp63 = 1.5;
    tmp61 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */), 1.5, tmp62, tmp63, data->simulationInfo->storedRelations[9]);
    data->simulationInfo->relations[start_index] = tmp61;
    current_index++;

    start_index = current_index;
    tmp65 = 1.0;
    tmp66 = 1.5;
    tmp64 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */), 1.5, tmp65, tmp66, data->simulationInfo->storedRelations[10]);
    data->simulationInfo->relations[start_index] = tmp64;
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) != 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) == 0.0);
    current_index++;

    start_index = current_index;
    tmp67 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
    tmp69 = (9.80665) * (fabs((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)));
    tmp70 = (1.0) * (fabs((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)));
    tmp68 = LessEqZC((9.80665) * ((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)), (DIVISION((tmp67 * tmp67),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius")) * ((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)), tmp69, tmp70, data->simulationInfo->storedRelations[13]);
    data->simulationInfo->relations[start_index] = tmp68;
    current_index++;

    start_index = current_index;
    tmp71 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
    tmp73 = (9.80665) * (fabs((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)));
    tmp74 = (1.0) * (fabs((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)));
    tmp72 = GreaterZC((9.80665) * ((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)), (DIVISION((tmp71 * tmp71),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius")) * ((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)), tmp73, tmp74, data->simulationInfo->storedRelations[14]);
    data->simulationInfo->relations[start_index] = tmp72;
    current_index++;
  } else {
    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* rover_8d.lambda STATE(1,rover_8d.omega) */) > 6.2831853);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */) == 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */) != 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) < 1.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) < 1.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) < 1.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) < 1.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */) <= 1.5);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */) <= 1.5);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */) <= 1.5);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */) <= 1.5);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) != 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* rover_3d.delta variable */) == 0.0);
    current_index++;

    start_index = current_index;
    tmp75 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
    data->simulationInfo->relations[start_index] = ((9.80665) * ((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)) <= (DIVISION((tmp75 * tmp75),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius")) * ((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)));
    current_index++;

    start_index = current_index;
    tmp76 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */);
    data->simulationInfo->relations[start_index] = ((9.80665) * ((data->simulationInfo->realParameter[3] /* $cse40 PARAM */)) > (DIVISION((tmp76 * tmp76),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* rover_3d.turn_radius DISCRETE */),"rover_3d.turn_radius")) * ((data->simulationInfo->realParameter[4] /* $cse41 PARAM */)));
    current_index++;
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

