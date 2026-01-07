/* Linear Systems */
#include "RoverExample.Components.Rover_model.h"
#include "RoverExample.Components.Rover_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* linear systems */

/*
equation index: 598
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERA.dummyVarA = (rover_8d.Kt_q * rover_8d.Iq.SeedA + (-4.0) * rover_8d.thr.$pDERA.dummyVarA - rover_8d.b * $DER.rover_8d.lambda.$pDERA.dummyVarA) / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_598(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,598};
  (parentJacobian->tmpVars[22]) /* der(rover_8d.omega.$pDERA.dummyVarA) JACOBIAN_TMP_VAR */ = DIVISION(((data->simulationInfo->realParameter[71] /* rover_8d.Kt_q PARAM */)) * ((parentJacobian->seedVars[8]) /* rover_8d.Iq.SeedA SEED_VAR */) + (-4.0) * ((parentJacobian->tmpVars[161]) /* rover_8d.thr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - (((data->simulationInfo->realParameter[81] /* rover_8d.b PARAM */)) * ((parentJacobian->resultVars[18]) /* der(rover_8d.lambda.$pDERA.dummyVarA) JACOBIAN_VAR */)),(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J");
  TRACE_POP
}
/*
equation index: 599
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERA.dummyVarA = (rover_8d.thr.$pDERA.dummyVarA - rover_8d.r_tire * rover_8d.Fx_fl.$pDERA.dummyVarA) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_599(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,599};
  (parentJacobian->resultVars[19]) /* der(rover_8d.omega_fl.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION((parentJacobian->tmpVars[161]) /* rover_8d.thr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[107]) /* rover_8d.Fx_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 600
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERA.dummyVarA = (rover_8d.thr.$pDERA.dummyVarA - rover_8d.r_tire * rover_8d.Fx_fr.$pDERA.dummyVarA) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_600(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,600};
  (parentJacobian->resultVars[20]) /* der(rover_8d.omega_fr.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION((parentJacobian->tmpVars[161]) /* rover_8d.thr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[108]) /* rover_8d.Fx_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 601
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERA.dummyVarA = (rover_8d.thr.$pDERA.dummyVarA - rover_8d.r_tire * rover_8d.Fx_rl.$pDERA.dummyVarA) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_601(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,601};
  (parentJacobian->resultVars[21]) /* der(rover_8d.omega_rl.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION((parentJacobian->tmpVars[161]) /* rover_8d.thr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[109]) /* rover_8d.Fx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 602
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERA.dummyVarA = 4.0 * $DER.rover_8d.omega.$pDERA.dummyVarA / rover_8d.gratio - $DER.rover_8d.omega_rl.$pDERA.dummyVarA - $DER.rover_8d.omega_fl.$pDERA.dummyVarA - $DER.rover_8d.omega_fr.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_602(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,602};
  (parentJacobian->resultVars[22]) /* der(rover_8d.omega_rr.$pDERA.dummyVarA) JACOBIAN_VAR */ = (4.0) * (DIVISION((parentJacobian->tmpVars[22]) /* der(rover_8d.omega.$pDERA.dummyVarA) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - (parentJacobian->resultVars[21]) /* der(rover_8d.omega_rl.$pDERA.dummyVarA) JACOBIAN_VAR */ - (parentJacobian->resultVars[19]) /* der(rover_8d.omega_fl.$pDERA.dummyVarA) JACOBIAN_VAR */ - (parentJacobian->resultVars[20]) /* der(rover_8d.omega_fr.$pDERA.dummyVarA) JACOBIAN_VAR */;
  TRACE_POP
}

void residualFunc610(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,610};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[9].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[161]) /* rover_8d.thr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = xloc[0];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_598(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_599(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_600(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_601(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_602(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[161]) /* rover_8d.thr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ + ((-(data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */))) * ((parentJacobian->tmpVars[110]) /* rover_8d.Fx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - (((parentJacobian->resultVars[22]) /* der(rover_8d.omega_rr.$pDERA.dummyVarA) JACOBIAN_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData610(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[1] = {
    161 /* rover_8d.thr.$pDERA.dummyVarA */
  };
  for (int i = 0; i < 1; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}



/*
equation index: 549
type: SIMPLE_ASSIGN
rover_8d.Fx_fl.$pDERA.dummyVarA = rover_8d.c_kappa * (rover_8d.kappa_fl_bnd * (rover_8d.fz_fl.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_fl_bnd) + rover_8d.fz_fl * rover_8d.kappa_fl_bnd.$pDERA.dummyVarA) / (1.0 - rover_8d.kappa_fl_bnd) ^ 2.0 + rover_8d.kappa_fl_bnd.$pDERA.dummyVarA * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_549(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,549};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  (parentJacobian->tmpVars[107]) /* rover_8d.Fx_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION(((parentJacobian->tmpVars[134]) /* rover_8d.fz_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */)) * ((parentJacobian->tmpVars[138]) /* rover_8d.kappa_fl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_fl_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[138]) /* rover_8d.kappa_fl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}
/*
equation index: 550
type: SIMPLE_ASSIGN
rover_8d.Fy_fl.$pDERA.dummyVarA = rover_8d.c_alpha * ($cse17 * (rover_8d.fz_fl.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_fl_bnd) + rover_8d.fz_fl * rover_8d.kappa_fl_bnd.$pDERA.dummyVarA) / (1.0 - rover_8d.kappa_fl_bnd) ^ 2.0 + $cse17.$pDERA.dummyVarA * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_550(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,550};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  (parentJacobian->tmpVars[111]) /* rover_8d.Fy_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION(((parentJacobian->tmpVars[134]) /* rover_8d.fz_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */)) * ((parentJacobian->tmpVars[138]) /* rover_8d.kappa_fl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_fl_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[30]) /* $cse17.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}
/*
equation index: 551
type: SIMPLE_ASSIGN
rover_8d.Fx_rr.$pDERA.dummyVarA = rover_8d.c_kappa * (rover_8d.kappa_rr_bnd * (rover_8d.fz_rr.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_rr_bnd) + rover_8d.fz_rr * rover_8d.kappa_rr_bnd.$pDERA.dummyVarA) / (1.0 - rover_8d.kappa_rr_bnd) ^ 2.0 + rover_8d.kappa_rr_bnd.$pDERA.dummyVarA * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_551(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,551};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  (parentJacobian->tmpVars[110]) /* rover_8d.Fx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION(((parentJacobian->tmpVars[137]) /* rover_8d.fz_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */)) * ((parentJacobian->tmpVars[141]) /* rover_8d.kappa_rr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_rr_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[141]) /* rover_8d.kappa_rr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}
/*
equation index: 552
type: SIMPLE_ASSIGN
rover_8d.Fy_rr.$pDERA.dummyVarA = rover_8d.c_alpha * ($cse29 * (rover_8d.fz_rr.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_rr_bnd) + rover_8d.fz_rr * rover_8d.kappa_rr_bnd.$pDERA.dummyVarA) / (1.0 - rover_8d.kappa_rr_bnd) ^ 2.0 + $cse29.$pDERA.dummyVarA * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_552(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,552};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  (parentJacobian->tmpVars[114]) /* rover_8d.Fy_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION(((parentJacobian->tmpVars[137]) /* rover_8d.fz_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */)) * ((parentJacobian->tmpVars[141]) /* rover_8d.kappa_rr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_rr_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[42]) /* $cse29.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}
/*
equation index: 553
type: SIMPLE_ASSIGN
rover_8d.Fx_fr.$pDERA.dummyVarA = rover_8d.c_kappa * (rover_8d.kappa_fr_bnd * (rover_8d.fz_fr.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_fr_bnd) + rover_8d.fz_fr * rover_8d.kappa_fr_bnd.$pDERA.dummyVarA) / (1.0 - rover_8d.kappa_fr_bnd) ^ 2.0 + rover_8d.kappa_fr_bnd.$pDERA.dummyVarA * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_553(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,553};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  (parentJacobian->tmpVars[108]) /* rover_8d.Fx_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION(((parentJacobian->tmpVars[135]) /* rover_8d.fz_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */)) * ((parentJacobian->tmpVars[139]) /* rover_8d.kappa_fr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_fr_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[139]) /* rover_8d.kappa_fr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}
/*
equation index: 554
type: SIMPLE_ASSIGN
rover_8d.Fy_fr.$pDERA.dummyVarA = rover_8d.c_alpha * ($cse21 * (rover_8d.fz_fr.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_fr_bnd) + rover_8d.fz_fr * rover_8d.kappa_fr_bnd.$pDERA.dummyVarA) / (1.0 - rover_8d.kappa_fr_bnd) ^ 2.0 + $cse21.$pDERA.dummyVarA * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_554(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,554};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  (parentJacobian->tmpVars[112]) /* rover_8d.Fy_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION(((parentJacobian->tmpVars[135]) /* rover_8d.fz_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */)) * ((parentJacobian->tmpVars[139]) /* rover_8d.kappa_fr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_fr_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[34]) /* $cse21.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}
/*
equation index: 555
type: SIMPLE_ASSIGN
rover_8d.Fy_rl.$pDERA.dummyVarA = rover_8d.c_alpha * ($cse25 * (rover_8d.fz_rl.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_rl_bnd) + rover_8d.fz_rl * rover_8d.kappa_rl_bnd.$pDERA.dummyVarA) / (1.0 - rover_8d.kappa_rl_bnd) ^ 2.0 + $cse25.$pDERA.dummyVarA * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_555(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,555};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  (parentJacobian->tmpVars[113]) /* rover_8d.Fy_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION(((parentJacobian->tmpVars[136]) /* rover_8d.fz_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */)) * ((parentJacobian->tmpVars[140]) /* rover_8d.kappa_rl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_rl_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[38]) /* $cse25.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}
/*
equation index: 556
type: SIMPLE_ASSIGN
rover_8d.ay.$pDERA.dummyVarA = (rover_8d.Fy_fl * $cse34.$pDERA.dummyVarA + rover_8d.Fy_fl.$pDERA.dummyVarA * $cse34 + rover_8d.Fy_fr * $cse34.$pDERA.dummyVarA + rover_8d.Fy_fr.$pDERA.dummyVarA * $cse34 + rover_8d.Fy_rl.$pDERA.dummyVarA + rover_8d.Fy_rr.$pDERA.dummyVarA + (-rover_8d.Fx_fl) * $cse35.$pDERA.dummyVarA - rover_8d.Fx_fl.$pDERA.dummyVarA * $cse35 - rover_8d.Fx_fr.$pDERA.dummyVarA * $cse35 - rover_8d.Fx_fr * $cse35.$pDERA.dummyVarA) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_556(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,556};
  (parentJacobian->tmpVars[127]) /* rover_8d.ay.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((parentJacobian->tmpVars[48]) /* $cse34.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[111]) /* rover_8d.Fy_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((parentJacobian->tmpVars[48]) /* $cse34.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[112]) /* rover_8d.Fy_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (parentJacobian->tmpVars[113]) /* rover_8d.Fy_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ + (parentJacobian->tmpVars[114]) /* rover_8d.Fy_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */))) * ((parentJacobian->tmpVars[49]) /* $cse35.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - (((parentJacobian->tmpVars[107]) /* rover_8d.Fx_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((parentJacobian->tmpVars[108]) /* rover_8d.Fx_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((parentJacobian->tmpVars[49]) /* $cse35.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}
/*
equation index: 557
type: SIMPLE_ASSIGN
rover_8d.Fx_rl.$pDERA.dummyVarA = rover_8d.c_kappa * (rover_8d.kappa_rl_bnd * (rover_8d.fz_rl.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_rl_bnd) + rover_8d.fz_rl * rover_8d.kappa_rl_bnd.$pDERA.dummyVarA) / (1.0 - rover_8d.kappa_rl_bnd) ^ 2.0 + rover_8d.kappa_rl_bnd.$pDERA.dummyVarA * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_557(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,557};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  (parentJacobian->tmpVars[109]) /* rover_8d.Fx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION(((parentJacobian->tmpVars[136]) /* rover_8d.fz_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */)) * ((parentJacobian->tmpVars[140]) /* rover_8d.kappa_rl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_rl_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[140]) /* rover_8d.kappa_rl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}
/*
equation index: 558
type: SIMPLE_ASSIGN
rover_8d.ax.$pDERA.dummyVarA = (rover_8d.Fx_fl * $cse34.$pDERA.dummyVarA + rover_8d.Fx_fl.$pDERA.dummyVarA * $cse34 + rover_8d.Fy_fl * $cse35.$pDERA.dummyVarA + rover_8d.Fy_fl.$pDERA.dummyVarA * $cse35 + rover_8d.Fx_fr * $cse34.$pDERA.dummyVarA + rover_8d.Fx_fr.$pDERA.dummyVarA * $cse34 + rover_8d.Fy_fr * $cse35.$pDERA.dummyVarA + rover_8d.Fy_fr.$pDERA.dummyVarA * $cse35 + rover_8d.Fx_rl.$pDERA.dummyVarA + rover_8d.Fx_rr.$pDERA.dummyVarA) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_558(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,558};
  (parentJacobian->tmpVars[126]) /* rover_8d.ax.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * ((parentJacobian->tmpVars[48]) /* $cse34.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[107]) /* rover_8d.Fx_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((parentJacobian->tmpVars[49]) /* $cse35.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[111]) /* rover_8d.Fy_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((parentJacobian->tmpVars[48]) /* $cse34.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[108]) /* rover_8d.Fx_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((parentJacobian->tmpVars[49]) /* $cse35.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[112]) /* rover_8d.Fy_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (parentJacobian->tmpVars[109]) /* rover_8d.Fx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ + (parentJacobian->tmpVars[110]) /* rover_8d.Fx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}
/*
equation index: 559
type: SIMPLE_ASSIGN
rover_8d.Fz_rr.$pDERA.dummyVarA = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERA.dummyVarA / rover_8d.l_total + (-0.5) * ((-rover_8d.k_rllsp) * rover_8d.phi.SeedA - rover_8d.c_rllsp * rover_8d.p.SeedA) / rover_8d.tw - rover_8d.ay.$pDERA.dummyVarA * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_559(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,559};
  (parentJacobian->tmpVars[118]) /* rover_8d.Fz_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[126]) /* rover_8d.ax.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (-0.5) * (DIVISION(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((parentJacobian->seedVars[24]) /* rover_8d.phi.SeedA SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((parentJacobian->seedVars[23]) /* rover_8d.p.SeedA SEED_VAR */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")) - (((parentJacobian->tmpVars[127]) /* rover_8d.ay.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}
/*
equation index: 560
type: SIMPLE_ASSIGN
rover_8d.z_rr.$pDERA.dummyVarA = if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_rr * (rover_8d.Fz_rr * ((-rover_8d.kappa_rr_bnd.$pDERA.dummyVarA) * sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) - (1.0 - rover_8d.kappa_rr_bnd) * 0.5 * (2.0 * rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.c_kappa * rover_8d.kappa_rr_bnd.$pDERA.dummyVarA + 2.0 * rover_8d.c_alpha * $cse29 * rover_8d.c_alpha * $cse29.$pDERA.dummyVarA) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)) / ((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) + rover_8d.Fz_rr.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)) + rover_8d.mu_rr.$pDERA.dummyVarA * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_560(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,560};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp24 = (modelica_boolean)tmp3;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp22 = (modelica_boolean)tmp7;
    if(tmp22)
    {
      tmp23 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp13 = (tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15;
      if(!(tmp13 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp13);
        }
      }tmp14 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp15 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }tmp19 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp20 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp21 = (tmp19 * tmp19) + (tmp20 * tmp20) + 1e-15;
      if(!(tmp21 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp21);
        }
      }
      tmp23 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(((-(parentJacobian->tmpVars[141]) /* rover_8d.kappa_rr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)) * (sqrt(tmp10)) - ((1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)))) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((parentJacobian->tmpVars[141]) /* rover_8d.kappa_rr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)) + ((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[42]) /* $cse29.$pDERA.dummyVarA JACOBIAN_TMP_VAR */))),sqrt(tmp13),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))),(tmp14 * tmp14) + (tmp15 * tmp15) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15")) + ((parentJacobian->tmpVars[118]) /* rover_8d.Fz_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[157]) /* rover_8d.mu_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp21),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))));
    }
    tmp25 = tmp23;
  }
  (parentJacobian->tmpVars[176]) /* rover_8d.z_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp25;
  TRACE_POP
}
/*
equation index: 561
type: SIMPLE_ASSIGN
rover_8d.Fz_fr.$pDERA.dummyVarA = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERA.dummyVarA / rover_8d.l_total + (-0.5) * ((-rover_8d.k_rllsp) * rover_8d.phi.SeedA - rover_8d.c_rllsp * rover_8d.p.SeedA) / rover_8d.tw - rover_8d.ay.$pDERA.dummyVarA * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_561(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,561};
  (parentJacobian->tmpVars[116]) /* rover_8d.Fz_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[126]) /* rover_8d.ax.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (-0.5) * (DIVISION(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((parentJacobian->seedVars[24]) /* rover_8d.phi.SeedA SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((parentJacobian->seedVars[23]) /* rover_8d.p.SeedA SEED_VAR */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")) - (((parentJacobian->tmpVars[127]) /* rover_8d.ay.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}
/*
equation index: 562
type: SIMPLE_ASSIGN
rover_8d.z_fr.$pDERA.dummyVarA = if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_fr * (rover_8d.Fz_fr * ((-rover_8d.kappa_fr_bnd.$pDERA.dummyVarA) * sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) - (1.0 - rover_8d.kappa_fr_bnd) * 0.5 * (2.0 * rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.c_kappa * rover_8d.kappa_fr_bnd.$pDERA.dummyVarA + 2.0 * rover_8d.c_alpha * $cse21 * rover_8d.c_alpha * $cse21.$pDERA.dummyVarA) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)) / ((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) + rover_8d.Fz_fr.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)) + rover_8d.mu_fr.$pDERA.dummyVarA * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_562(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,562};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp24 = (modelica_boolean)tmp3;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp22 = (modelica_boolean)tmp7;
    if(tmp22)
    {
      tmp23 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp13 = (tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15;
      if(!(tmp13 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp13);
        }
      }tmp14 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp15 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }tmp19 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp20 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp21 = (tmp19 * tmp19) + (tmp20 * tmp20) + 1e-15;
      if(!(tmp21 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp21);
        }
      }
      tmp23 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(((-(parentJacobian->tmpVars[139]) /* rover_8d.kappa_fr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)) * (sqrt(tmp10)) - ((1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)))) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((parentJacobian->tmpVars[139]) /* rover_8d.kappa_fr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)) + ((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[34]) /* $cse21.$pDERA.dummyVarA JACOBIAN_TMP_VAR */))),sqrt(tmp13),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))),(tmp14 * tmp14) + (tmp15 * tmp15) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15")) + ((parentJacobian->tmpVars[116]) /* rover_8d.Fz_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[155]) /* rover_8d.mu_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp21),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))));
    }
    tmp25 = tmp23;
  }
  (parentJacobian->tmpVars[174]) /* rover_8d.z_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp25;
  TRACE_POP
}
/*
equation index: 563
type: SIMPLE_ASSIGN
rover_8d.Fz_rl.$pDERA.dummyVarA = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERA.dummyVarA / rover_8d.l_total + rover_8d.ay.$pDERA.dummyVarA * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw + 0.5 * ((-rover_8d.k_rllsp) * rover_8d.phi.SeedA - rover_8d.c_rllsp * rover_8d.p.SeedA) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_563(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,563};
  (parentJacobian->tmpVars[117]) /* rover_8d.Fz_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[126]) /* rover_8d.ax.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((parentJacobian->tmpVars[127]) /* rover_8d.ay.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")) + (0.5) * (DIVISION(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((parentJacobian->seedVars[24]) /* rover_8d.phi.SeedA SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((parentJacobian->seedVars[23]) /* rover_8d.p.SeedA SEED_VAR */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}
/*
equation index: 564
type: SIMPLE_ASSIGN
rover_8d.z_rl.$pDERA.dummyVarA = if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_rl * (rover_8d.Fz_rl * ((-rover_8d.kappa_rl_bnd.$pDERA.dummyVarA) * sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) - (1.0 - rover_8d.kappa_rl_bnd) * 0.5 * (2.0 * rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.c_kappa * rover_8d.kappa_rl_bnd.$pDERA.dummyVarA + 2.0 * rover_8d.c_alpha * $cse25 * rover_8d.c_alpha * $cse25.$pDERA.dummyVarA) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)) / ((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) + rover_8d.Fz_rl.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)) + rover_8d.mu_rl.$pDERA.dummyVarA * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_564(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,564};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp24 = (modelica_boolean)tmp3;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp22 = (modelica_boolean)tmp7;
    if(tmp22)
    {
      tmp23 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp13 = (tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15;
      if(!(tmp13 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp13);
        }
      }tmp14 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp15 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }tmp19 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp20 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp21 = (tmp19 * tmp19) + (tmp20 * tmp20) + 1e-15;
      if(!(tmp21 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp21);
        }
      }
      tmp23 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(((-(parentJacobian->tmpVars[140]) /* rover_8d.kappa_rl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)) * (sqrt(tmp10)) - ((1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)))) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((parentJacobian->tmpVars[140]) /* rover_8d.kappa_rl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)) + ((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[38]) /* $cse25.$pDERA.dummyVarA JACOBIAN_TMP_VAR */))),sqrt(tmp13),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))),(tmp14 * tmp14) + (tmp15 * tmp15) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15")) + ((parentJacobian->tmpVars[117]) /* rover_8d.Fz_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[156]) /* rover_8d.mu_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp21),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))));
    }
    tmp25 = tmp23;
  }
  (parentJacobian->tmpVars[175]) /* rover_8d.z_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp25;
  TRACE_POP
}
/*
equation index: 565
type: SIMPLE_ASSIGN
rover_8d.Fz_fl.$pDERA.dummyVarA = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERA.dummyVarA / rover_8d.l_total + rover_8d.ay.$pDERA.dummyVarA * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw + 0.5 * ((-rover_8d.k_rllsp) * rover_8d.phi.SeedA - rover_8d.c_rllsp * rover_8d.p.SeedA) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_565(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,565};
  (parentJacobian->tmpVars[115]) /* rover_8d.Fz_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[126]) /* rover_8d.ax.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((parentJacobian->tmpVars[127]) /* rover_8d.ay.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")) + (0.5) * (DIVISION(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((parentJacobian->seedVars[24]) /* rover_8d.phi.SeedA SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((parentJacobian->seedVars[23]) /* rover_8d.p.SeedA SEED_VAR */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}
/*
equation index: 566
type: SIMPLE_ASSIGN
rover_8d.z_fl.$pDERA.dummyVarA = if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_fl * (rover_8d.Fz_fl * ((-rover_8d.kappa_fl_bnd.$pDERA.dummyVarA) * sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) - (1.0 - rover_8d.kappa_fl_bnd) * 0.5 * (2.0 * rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.c_kappa * rover_8d.kappa_fl_bnd.$pDERA.dummyVarA + 2.0 * rover_8d.c_alpha * $cse17 * rover_8d.c_alpha * $cse17.$pDERA.dummyVarA) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)) / ((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) + rover_8d.Fz_fl.$pDERA.dummyVarA * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)) + rover_8d.mu_fl.$pDERA.dummyVarA * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_566(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,566};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp24 = (modelica_boolean)tmp3;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp22 = (modelica_boolean)tmp7;
    if(tmp22)
    {
      tmp23 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp13 = (tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15;
      if(!(tmp13 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp13);
        }
      }tmp14 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp15 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }tmp19 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp20 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp21 = (tmp19 * tmp19) + (tmp20 * tmp20) + 1e-15;
      if(!(tmp21 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp21);
        }
      }
      tmp23 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(((-(parentJacobian->tmpVars[138]) /* rover_8d.kappa_fl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)) * (sqrt(tmp10)) - ((1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)))) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((parentJacobian->tmpVars[138]) /* rover_8d.kappa_fl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)) + ((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[30]) /* $cse17.$pDERA.dummyVarA JACOBIAN_TMP_VAR */))),sqrt(tmp13),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))),(tmp14 * tmp14) + (tmp15 * tmp15) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15")) + ((parentJacobian->tmpVars[115]) /* rover_8d.Fz_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[154]) /* rover_8d.mu_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp21),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))));
    }
    tmp25 = tmp23;
  }
  (parentJacobian->tmpVars[173]) /* rover_8d.z_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp25;
  TRACE_POP
}

void residualFunc593(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,593};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[8].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  (parentJacobian->tmpVars[136]) /* rover_8d.fz_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = xloc[0];
  (parentJacobian->tmpVars[135]) /* rover_8d.fz_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = xloc[1];
  (parentJacobian->tmpVars[137]) /* rover_8d.fz_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = xloc[2];
  (parentJacobian->tmpVars[134]) /* rover_8d.fz_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = xloc[3];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_549(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_550(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_551(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_552(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_553(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_554(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_555(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_556(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_557(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_558(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_559(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_560(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_561(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_562(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_563(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_564(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_565(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_566(data, threadData, jacobian, parentJacobian);
  tmp0 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */),1.0);
  res[0] = (tmp0?((parentJacobian->tmpVars[175]) /* rover_8d.z_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):0.0) - (parentJacobian->tmpVars[136]) /* rover_8d.fz_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */;

  tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */),1.0);
  res[1] = (tmp1?((parentJacobian->tmpVars[174]) /* rover_8d.z_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):0.0) - (parentJacobian->tmpVars[135]) /* rover_8d.fz_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */;

  tmp2 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */),1.0);
  res[2] = (tmp2?((parentJacobian->tmpVars[176]) /* rover_8d.z_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):0.0) - (parentJacobian->tmpVars[137]) /* rover_8d.fz_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */;

  tmp3 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */),1.0);
  res[3] = (tmp3?((parentJacobian->tmpVars[173]) /* rover_8d.z_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):0.0) - (parentJacobian->tmpVars[134]) /* rover_8d.fz_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData593(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[4] = {
    136 /* rover_8d.fz_rl.$pDERA.dummyVarA */,
    135 /* rover_8d.fz_fr.$pDERA.dummyVarA */,
    137 /* rover_8d.fz_rr.$pDERA.dummyVarA */,
    134 /* rover_8d.fz_fl.$pDERA.dummyVarA */
  };
  for (int i = 0; i < 4; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}



/*
equation index: 715
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERB.dummyVarB = (-4.0) * rover_8d.thr.$pDERB.dummyVarB / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_715(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,715};
  (parentJacobian->tmpVars[4]) /* der(rover_8d.omega.$pDERB.dummyVarB) JACOBIAN_TMP_VAR */ = (-4.0) * (DIVISION((parentJacobian->tmpVars[143]) /* rover_8d.thr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J"));
  TRACE_POP
}
/*
equation index: 716
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERB.dummyVarB = (rover_8d.thr.$pDERB.dummyVarB - rover_8d.r_tire * rover_8d.Fx_fr.$pDERB.dummyVarB) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_716(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,716};
  (parentJacobian->resultVars[20]) /* der(rover_8d.omega_fr.$pDERB.dummyVarB) JACOBIAN_VAR */ = DIVISION((parentJacobian->tmpVars[143]) /* rover_8d.thr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[90]) /* rover_8d.Fx_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 717
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERB.dummyVarB = (rover_8d.thr.$pDERB.dummyVarB - rover_8d.r_tire * rover_8d.Fx_fl.$pDERB.dummyVarB) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_717(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,717};
  (parentJacobian->resultVars[19]) /* der(rover_8d.omega_fl.$pDERB.dummyVarB) JACOBIAN_VAR */ = DIVISION((parentJacobian->tmpVars[143]) /* rover_8d.thr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[89]) /* rover_8d.Fx_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 718
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERB.dummyVarB = (rover_8d.thr.$pDERB.dummyVarB - rover_8d.r_tire * rover_8d.Fx_rl.$pDERB.dummyVarB) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_718(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,718};
  (parentJacobian->resultVars[21]) /* der(rover_8d.omega_rl.$pDERB.dummyVarB) JACOBIAN_VAR */ = DIVISION((parentJacobian->tmpVars[143]) /* rover_8d.thr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[91]) /* rover_8d.Fx_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 719
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERB.dummyVarB = 4.0 * $DER.rover_8d.omega.$pDERB.dummyVarB / rover_8d.gratio - $DER.rover_8d.omega_rl.$pDERB.dummyVarB - $DER.rover_8d.omega_fl.$pDERB.dummyVarB - $DER.rover_8d.omega_fr.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_719(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,719};
  (parentJacobian->resultVars[22]) /* der(rover_8d.omega_rr.$pDERB.dummyVarB) JACOBIAN_VAR */ = (4.0) * (DIVISION((parentJacobian->tmpVars[4]) /* der(rover_8d.omega.$pDERB.dummyVarB) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - (parentJacobian->resultVars[21]) /* der(rover_8d.omega_rl.$pDERB.dummyVarB) JACOBIAN_VAR */ - (parentJacobian->resultVars[19]) /* der(rover_8d.omega_fl.$pDERB.dummyVarB) JACOBIAN_VAR */ - (parentJacobian->resultVars[20]) /* der(rover_8d.omega_fr.$pDERB.dummyVarB) JACOBIAN_VAR */;
  TRACE_POP
}

void residualFunc727(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,727};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[7].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[143]) /* rover_8d.thr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = xloc[0];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_715(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_716(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_717(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_718(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_719(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[143]) /* rover_8d.thr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ + ((-(data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */))) * ((parentJacobian->tmpVars[92]) /* rover_8d.Fx_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) - (((parentJacobian->resultVars[22]) /* der(rover_8d.omega_rr.$pDERB.dummyVarB) JACOBIAN_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData727(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[1] = {
    143 /* rover_8d.thr.$pDERB.dummyVarB */
  };
  for (int i = 0; i < 1; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}



/*
equation index: 667
type: SIMPLE_ASSIGN
rover_8d.Fx_fr.$pDERB.dummyVarB = rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.fz_fr.$pDERB.dummyVarB / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_667(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,667};
  (parentJacobian->tmpVars[90]) /* rover_8d.Fx_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION((parentJacobian->tmpVars[117]) /* rover_8d.fz_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}
/*
equation index: 668
type: SIMPLE_ASSIGN
rover_8d.Fy_fr.$pDERB.dummyVarB = rover_8d.c_alpha * ($cse21 * rover_8d.fz_fr.$pDERB.dummyVarB / (1.0 - rover_8d.kappa_fr_bnd) + $cse21.$pDERB.dummyVarB * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_668(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,668};
  (parentJacobian->tmpVars[94]) /* rover_8d.Fy_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION((parentJacobian->tmpVars[117]) /* rover_8d.fz_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")) + ((parentJacobian->tmpVars[16]) /* $cse21.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}
/*
equation index: 669
type: SIMPLE_ASSIGN
rover_8d.Fx_rr.$pDERB.dummyVarB = rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.fz_rr.$pDERB.dummyVarB / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_669(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,669};
  (parentJacobian->tmpVars[92]) /* rover_8d.Fx_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION((parentJacobian->tmpVars[119]) /* rover_8d.fz_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}
/*
equation index: 670
type: SIMPLE_ASSIGN
rover_8d.Fy_rr.$pDERB.dummyVarB = rover_8d.c_alpha * ($cse29 * rover_8d.fz_rr.$pDERB.dummyVarB / (1.0 - rover_8d.kappa_rr_bnd) + $cse29.$pDERB.dummyVarB * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_670(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,670};
  (parentJacobian->tmpVars[96]) /* rover_8d.Fy_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION((parentJacobian->tmpVars[119]) /* rover_8d.fz_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")) + ((parentJacobian->tmpVars[24]) /* $cse29.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}
/*
equation index: 671
type: SIMPLE_ASSIGN
rover_8d.Fx_fl.$pDERB.dummyVarB = rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.fz_fl.$pDERB.dummyVarB / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_671(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,671};
  (parentJacobian->tmpVars[89]) /* rover_8d.Fx_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION((parentJacobian->tmpVars[116]) /* rover_8d.fz_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}
/*
equation index: 672
type: SIMPLE_ASSIGN
rover_8d.Fy_fl.$pDERB.dummyVarB = rover_8d.c_alpha * ($cse17 * rover_8d.fz_fl.$pDERB.dummyVarB / (1.0 - rover_8d.kappa_fl_bnd) + $cse17.$pDERB.dummyVarB * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_672(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,672};
  (parentJacobian->tmpVars[93]) /* rover_8d.Fy_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION((parentJacobian->tmpVars[116]) /* rover_8d.fz_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")) + ((parentJacobian->tmpVars[12]) /* $cse17.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}
/*
equation index: 673
type: SIMPLE_ASSIGN
rover_8d.Fy_rl.$pDERB.dummyVarB = rover_8d.c_alpha * ($cse25 * rover_8d.fz_rl.$pDERB.dummyVarB / (1.0 - rover_8d.kappa_rl_bnd) + $cse25.$pDERB.dummyVarB * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_673(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,673};
  (parentJacobian->tmpVars[95]) /* rover_8d.Fy_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION((parentJacobian->tmpVars[118]) /* rover_8d.fz_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")) + ((parentJacobian->tmpVars[20]) /* $cse25.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}
/*
equation index: 674
type: SIMPLE_ASSIGN
rover_8d.ay.$pDERB.dummyVarB = (rover_8d.Fy_fl * $cse34.$pDERB.dummyVarB + rover_8d.Fy_fl.$pDERB.dummyVarB * $cse34 + rover_8d.Fy_fr * $cse34.$pDERB.dummyVarB + rover_8d.Fy_fr.$pDERB.dummyVarB * $cse34 + rover_8d.Fy_rl.$pDERB.dummyVarB + rover_8d.Fy_rr.$pDERB.dummyVarB + (-rover_8d.Fx_fl) * $cse35.$pDERB.dummyVarB - rover_8d.Fx_fl.$pDERB.dummyVarB * $cse35 - rover_8d.Fx_fr.$pDERB.dummyVarB * $cse35 - rover_8d.Fx_fr * $cse35.$pDERB.dummyVarB) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_674(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,674};
  (parentJacobian->tmpVars[109]) /* rover_8d.ay.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((parentJacobian->tmpVars[30]) /* $cse34.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[93]) /* rover_8d.Fy_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((parentJacobian->tmpVars[30]) /* $cse34.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[94]) /* rover_8d.Fy_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (parentJacobian->tmpVars[95]) /* rover_8d.Fy_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ + (parentJacobian->tmpVars[96]) /* rover_8d.Fy_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */))) * ((parentJacobian->tmpVars[31]) /* $cse35.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) - (((parentJacobian->tmpVars[89]) /* rover_8d.Fx_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((parentJacobian->tmpVars[90]) /* rover_8d.Fx_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((parentJacobian->tmpVars[31]) /* $cse35.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}
/*
equation index: 675
type: SIMPLE_ASSIGN
rover_8d.Fx_rl.$pDERB.dummyVarB = rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.fz_rl.$pDERB.dummyVarB / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_675(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,675};
  (parentJacobian->tmpVars[91]) /* rover_8d.Fx_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION((parentJacobian->tmpVars[118]) /* rover_8d.fz_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}
/*
equation index: 676
type: SIMPLE_ASSIGN
$DER.rover_8d.vx.$pDERB.dummyVarB = (rover_8d.Fx_fl * $cse34.$pDERB.dummyVarB + rover_8d.Fx_fl.$pDERB.dummyVarB * $cse34 + rover_8d.Fy_fl * $cse35.$pDERB.dummyVarB + rover_8d.Fy_fl.$pDERB.dummyVarB * $cse35 + rover_8d.Fx_fr * $cse34.$pDERB.dummyVarB + rover_8d.Fx_fr.$pDERB.dummyVarB * $cse34 + rover_8d.Fy_fr * $cse35.$pDERB.dummyVarB + rover_8d.Fy_fr.$pDERB.dummyVarB * $cse35 + rover_8d.Fx_rl.$pDERB.dummyVarB + rover_8d.Fx_rr.$pDERB.dummyVarB) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_676(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,676};
  (parentJacobian->resultVars[29]) /* der(rover_8d.vx.$pDERB.dummyVarB) JACOBIAN_VAR */ = DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * ((parentJacobian->tmpVars[30]) /* $cse34.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[89]) /* rover_8d.Fx_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((parentJacobian->tmpVars[31]) /* $cse35.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[93]) /* rover_8d.Fy_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((parentJacobian->tmpVars[30]) /* $cse34.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[90]) /* rover_8d.Fx_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((parentJacobian->tmpVars[31]) /* $cse35.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[94]) /* rover_8d.Fy_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (parentJacobian->tmpVars[91]) /* rover_8d.Fx_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ + (parentJacobian->tmpVars[92]) /* rover_8d.Fx_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}
/*
equation index: 677
type: SIMPLE_ASSIGN
rover_8d.Fz_rr.$pDERB.dummyVarB = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERB.dummyVarB / rover_8d.l_total - rover_8d.ay.$pDERB.dummyVarB * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_677(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,677};
  (parentJacobian->tmpVars[100]) /* rover_8d.Fz_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->resultVars[29]) /* der(rover_8d.vx.$pDERB.dummyVarB) JACOBIAN_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - (((parentJacobian->tmpVars[109]) /* rover_8d.ay.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}
/*
equation index: 678
type: SIMPLE_ASSIGN
rover_8d.z_rr.$pDERB.dummyVarB = if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_rr * (rover_8d.Fz_rr * (rover_8d.kappa_rr_bnd - 1.0) * 0.5 * 2.0 * rover_8d.c_alpha * $cse29 * rover_8d.c_alpha * $cse29.$pDERB.dummyVarB / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) / ((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) + rover_8d.Fz_rr.$pDERB.dummyVarB * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)) + rover_8d.mu_rr.$pDERB.dummyVarB * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_678(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,678};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_boolean tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp21 = (modelica_boolean)tmp3;
  if(tmp21)
  {
    tmp22 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp19 = (modelica_boolean)tmp7;
    if(tmp19)
    {
      tmp20 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp13 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp14 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp15 = (tmp13 * tmp13) + (tmp14 * tmp14) + 1e-15;
      if(!(tmp15 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp15);
        }
      }tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }
      tmp20 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */) - 1.0) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[24]) /* $cse29.$pDERB.dummyVarB JACOBIAN_TMP_VAR */))),sqrt(tmp10),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))),(tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15") + ((parentJacobian->tmpVars[100]) /* rover_8d.Fz_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp15),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[139]) /* rover_8d.mu_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))));
    }
    tmp22 = tmp20;
  }
  (parentJacobian->tmpVars[158]) /* rover_8d.z_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp22;
  TRACE_POP
}
/*
equation index: 679
type: SIMPLE_ASSIGN
rover_8d.Fz_fr.$pDERB.dummyVarB = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERB.dummyVarB / rover_8d.l_total - rover_8d.ay.$pDERB.dummyVarB * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_679(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,679};
  (parentJacobian->tmpVars[98]) /* rover_8d.Fz_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->resultVars[29]) /* der(rover_8d.vx.$pDERB.dummyVarB) JACOBIAN_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - (((parentJacobian->tmpVars[109]) /* rover_8d.ay.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}
/*
equation index: 680
type: SIMPLE_ASSIGN
rover_8d.z_fr.$pDERB.dummyVarB = if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_fr * (rover_8d.Fz_fr * (rover_8d.kappa_fr_bnd - 1.0) * 0.5 * 2.0 * rover_8d.c_alpha * $cse21 * rover_8d.c_alpha * $cse21.$pDERB.dummyVarB / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) / ((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) + rover_8d.Fz_fr.$pDERB.dummyVarB * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)) + rover_8d.mu_fr.$pDERB.dummyVarB * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_680(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,680};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_boolean tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp21 = (modelica_boolean)tmp3;
  if(tmp21)
  {
    tmp22 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp19 = (modelica_boolean)tmp7;
    if(tmp19)
    {
      tmp20 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp13 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp14 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp15 = (tmp13 * tmp13) + (tmp14 * tmp14) + 1e-15;
      if(!(tmp15 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp15);
        }
      }tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }
      tmp20 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */) - 1.0) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[16]) /* $cse21.$pDERB.dummyVarB JACOBIAN_TMP_VAR */))),sqrt(tmp10),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))),(tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15") + ((parentJacobian->tmpVars[98]) /* rover_8d.Fz_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp15),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[137]) /* rover_8d.mu_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))));
    }
    tmp22 = tmp20;
  }
  (parentJacobian->tmpVars[156]) /* rover_8d.z_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp22;
  TRACE_POP
}
/*
equation index: 681
type: SIMPLE_ASSIGN
rover_8d.Fz_rl.$pDERB.dummyVarB = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERB.dummyVarB / rover_8d.l_total + rover_8d.ay.$pDERB.dummyVarB * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_681(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,681};
  (parentJacobian->tmpVars[99]) /* rover_8d.Fz_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->resultVars[29]) /* der(rover_8d.vx.$pDERB.dummyVarB) JACOBIAN_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((parentJacobian->tmpVars[109]) /* rover_8d.ay.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}
/*
equation index: 682
type: SIMPLE_ASSIGN
rover_8d.z_rl.$pDERB.dummyVarB = if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_rl * (rover_8d.Fz_rl * (rover_8d.kappa_rl_bnd - 1.0) * 0.5 * 2.0 * rover_8d.c_alpha * $cse25 * rover_8d.c_alpha * $cse25.$pDERB.dummyVarB / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) / ((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) + rover_8d.Fz_rl.$pDERB.dummyVarB * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)) + rover_8d.mu_rl.$pDERB.dummyVarB * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_682(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,682};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_boolean tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp21 = (modelica_boolean)tmp3;
  if(tmp21)
  {
    tmp22 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp19 = (modelica_boolean)tmp7;
    if(tmp19)
    {
      tmp20 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp13 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp14 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp15 = (tmp13 * tmp13) + (tmp14 * tmp14) + 1e-15;
      if(!(tmp15 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp15);
        }
      }tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }
      tmp20 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */) - 1.0) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[20]) /* $cse25.$pDERB.dummyVarB JACOBIAN_TMP_VAR */))),sqrt(tmp10),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))),(tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15") + ((parentJacobian->tmpVars[99]) /* rover_8d.Fz_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp15),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[138]) /* rover_8d.mu_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))));
    }
    tmp22 = tmp20;
  }
  (parentJacobian->tmpVars[157]) /* rover_8d.z_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp22;
  TRACE_POP
}
/*
equation index: 683
type: SIMPLE_ASSIGN
rover_8d.Fz_fl.$pDERB.dummyVarB = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERB.dummyVarB / rover_8d.l_total + rover_8d.ay.$pDERB.dummyVarB * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_683(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,683};
  (parentJacobian->tmpVars[97]) /* rover_8d.Fz_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->resultVars[29]) /* der(rover_8d.vx.$pDERB.dummyVarB) JACOBIAN_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((parentJacobian->tmpVars[109]) /* rover_8d.ay.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}
/*
equation index: 684
type: SIMPLE_ASSIGN
rover_8d.z_fl.$pDERB.dummyVarB = if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_fl * (rover_8d.Fz_fl * (rover_8d.kappa_fl_bnd - 1.0) * 0.5 * 2.0 * rover_8d.c_alpha * $cse17 * rover_8d.c_alpha * $cse17.$pDERB.dummyVarB / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) / ((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) + rover_8d.Fz_fl.$pDERB.dummyVarB * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)) + rover_8d.mu_fl.$pDERB.dummyVarB * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_684(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,684};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_boolean tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp21 = (modelica_boolean)tmp3;
  if(tmp21)
  {
    tmp22 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp19 = (modelica_boolean)tmp7;
    if(tmp19)
    {
      tmp20 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp13 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp14 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp15 = (tmp13 * tmp13) + (tmp14 * tmp14) + 1e-15;
      if(!(tmp15 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp15);
        }
      }tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }
      tmp20 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */) - 1.0) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[12]) /* $cse17.$pDERB.dummyVarB JACOBIAN_TMP_VAR */))),sqrt(tmp10),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))),(tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15") + ((parentJacobian->tmpVars[97]) /* rover_8d.Fz_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp15),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[136]) /* rover_8d.mu_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))));
    }
    tmp22 = tmp20;
  }
  (parentJacobian->tmpVars[155]) /* rover_8d.z_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp22;
  TRACE_POP
}

void residualFunc711(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,711};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[6].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  (parentJacobian->tmpVars[118]) /* rover_8d.fz_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = xloc[0];
  (parentJacobian->tmpVars[116]) /* rover_8d.fz_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = xloc[1];
  (parentJacobian->tmpVars[119]) /* rover_8d.fz_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = xloc[2];
  (parentJacobian->tmpVars[117]) /* rover_8d.fz_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = xloc[3];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_667(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_668(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_669(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_670(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_671(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_672(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_673(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_674(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_675(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_676(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_677(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_678(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_679(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_680(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_681(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_682(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_683(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_684(data, threadData, jacobian, parentJacobian);
  tmp0 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */),1.0);
  res[0] = (tmp0?((parentJacobian->tmpVars[157]) /* rover_8d.z_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):0.0) - (parentJacobian->tmpVars[118]) /* rover_8d.fz_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */;

  tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */),1.0);
  res[1] = (tmp1?((parentJacobian->tmpVars[155]) /* rover_8d.z_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):0.0) - (parentJacobian->tmpVars[116]) /* rover_8d.fz_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */;

  tmp2 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */),1.0);
  res[2] = (tmp2?((parentJacobian->tmpVars[158]) /* rover_8d.z_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):0.0) - (parentJacobian->tmpVars[119]) /* rover_8d.fz_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */;

  tmp3 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */),1.0);
  res[3] = (tmp3?((parentJacobian->tmpVars[156]) /* rover_8d.z_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):0.0) - (parentJacobian->tmpVars[117]) /* rover_8d.fz_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData711(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[4] = {
    118 /* rover_8d.fz_rl.$pDERB.dummyVarB */,
    116 /* rover_8d.fz_fl.$pDERB.dummyVarB */,
    119 /* rover_8d.fz_rr.$pDERB.dummyVarB */,
    117 /* rover_8d.fz_fr.$pDERB.dummyVarB */
  };
  for (int i = 0; i < 4; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}



/*
equation index: 902
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERC.dummyVarC = (rover_8d.Kt_q * rover_8d.Iq.SeedC + (-4.0) * rover_8d.thr.$pDERC.dummyVarC - rover_8d.b * $DER.rover_8d.lambda.$pDERC.dummyVarC) / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_902(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,902};
  (parentJacobian->tmpVars[57]) /* der(rover_8d.omega.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION(((data->simulationInfo->realParameter[71] /* rover_8d.Kt_q PARAM */)) * ((parentJacobian->seedVars[8]) /* rover_8d.Iq.SeedC SEED_VAR */) + (-4.0) * ((parentJacobian->tmpVars[184]) /* rover_8d.thr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - (((data->simulationInfo->realParameter[81] /* rover_8d.b PARAM */)) * ((parentJacobian->tmpVars[40]) /* der(rover_8d.lambda.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J");
  TRACE_POP
}
/*
equation index: 903
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERC.dummyVarC = (rover_8d.thr.$pDERC.dummyVarC - rover_8d.r_tire * rover_8d.Fx_fl.$pDERC.dummyVarC) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_903(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,903};
  (parentJacobian->tmpVars[41]) /* der(rover_8d.omega_fl.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION((parentJacobian->tmpVars[184]) /* rover_8d.thr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[130]) /* rover_8d.Fx_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 904
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERC.dummyVarC = (rover_8d.thr.$pDERC.dummyVarC - rover_8d.r_tire * rover_8d.Fx_fr.$pDERC.dummyVarC) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_904(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,904};
  (parentJacobian->tmpVars[42]) /* der(rover_8d.omega_fr.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION((parentJacobian->tmpVars[184]) /* rover_8d.thr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[131]) /* rover_8d.Fx_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 905
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERC.dummyVarC = (rover_8d.thr.$pDERC.dummyVarC - rover_8d.r_tire * rover_8d.Fx_rl.$pDERC.dummyVarC) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_905(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,905};
  (parentJacobian->tmpVars[43]) /* der(rover_8d.omega_rl.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION((parentJacobian->tmpVars[184]) /* rover_8d.thr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[132]) /* rover_8d.Fx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 906
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERC.dummyVarC = 4.0 * $DER.rover_8d.omega.$pDERC.dummyVarC / rover_8d.gratio - $DER.rover_8d.omega_rl.$pDERC.dummyVarC - $DER.rover_8d.omega_fl.$pDERC.dummyVarC - $DER.rover_8d.omega_fr.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_906(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,906};
  (parentJacobian->tmpVars[44]) /* der(rover_8d.omega_rr.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = (4.0) * (DIVISION((parentJacobian->tmpVars[57]) /* der(rover_8d.omega.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - (parentJacobian->tmpVars[43]) /* der(rover_8d.omega_rl.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ - (parentJacobian->tmpVars[41]) /* der(rover_8d.omega_fl.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ - (parentJacobian->tmpVars[42]) /* der(rover_8d.omega_fr.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */;
  TRACE_POP
}

void residualFunc914(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,914};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[5].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[184]) /* rover_8d.thr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = xloc[0];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_902(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_903(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_904(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_905(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_906(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[184]) /* rover_8d.thr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ + ((-(data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */))) * ((parentJacobian->tmpVars[133]) /* rover_8d.Fx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - (((parentJacobian->tmpVars[44]) /* der(rover_8d.omega_rr.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData914(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[1] = {
    184 /* rover_8d.thr.$pDERC.dummyVarC */
  };
  for (int i = 0; i < 1; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}



/*
equation index: 851
type: SIMPLE_ASSIGN
rover_8d.Fx_fl.$pDERC.dummyVarC = rover_8d.c_kappa * (rover_8d.kappa_fl_bnd * (rover_8d.fz_fl.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_fl_bnd) + rover_8d.fz_fl * rover_8d.kappa_fl_bnd.$pDERC.dummyVarC) / (1.0 - rover_8d.kappa_fl_bnd) ^ 2.0 + rover_8d.kappa_fl_bnd.$pDERC.dummyVarC * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_851(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,851};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  (parentJacobian->tmpVars[130]) /* rover_8d.Fx_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION(((parentJacobian->tmpVars[157]) /* rover_8d.fz_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */)) * ((parentJacobian->tmpVars[161]) /* rover_8d.kappa_fl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_fl_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[161]) /* rover_8d.kappa_fl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}
/*
equation index: 852
type: SIMPLE_ASSIGN
rover_8d.Fy_fl.$pDERC.dummyVarC = rover_8d.c_alpha * ($cse17 * (rover_8d.fz_fl.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_fl_bnd) + rover_8d.fz_fl * rover_8d.kappa_fl_bnd.$pDERC.dummyVarC) / (1.0 - rover_8d.kappa_fl_bnd) ^ 2.0 + $cse17.$pDERC.dummyVarC * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_852(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,852};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  (parentJacobian->tmpVars[134]) /* rover_8d.Fy_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION(((parentJacobian->tmpVars[157]) /* rover_8d.fz_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */)) * ((parentJacobian->tmpVars[161]) /* rover_8d.kappa_fl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_fl_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[65]) /* $cse17.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}
/*
equation index: 853
type: SIMPLE_ASSIGN
rover_8d.Fx_rl.$pDERC.dummyVarC = rover_8d.c_kappa * (rover_8d.kappa_rl_bnd * (rover_8d.fz_rl.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_rl_bnd) + rover_8d.fz_rl * rover_8d.kappa_rl_bnd.$pDERC.dummyVarC) / (1.0 - rover_8d.kappa_rl_bnd) ^ 2.0 + rover_8d.kappa_rl_bnd.$pDERC.dummyVarC * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_853(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,853};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  (parentJacobian->tmpVars[132]) /* rover_8d.Fx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION(((parentJacobian->tmpVars[159]) /* rover_8d.fz_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */)) * ((parentJacobian->tmpVars[163]) /* rover_8d.kappa_rl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_rl_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[163]) /* rover_8d.kappa_rl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}
/*
equation index: 854
type: SIMPLE_ASSIGN
rover_8d.Fy_rl.$pDERC.dummyVarC = rover_8d.c_alpha * ($cse25 * (rover_8d.fz_rl.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_rl_bnd) + rover_8d.fz_rl * rover_8d.kappa_rl_bnd.$pDERC.dummyVarC) / (1.0 - rover_8d.kappa_rl_bnd) ^ 2.0 + $cse25.$pDERC.dummyVarC * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_854(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,854};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  (parentJacobian->tmpVars[136]) /* rover_8d.Fy_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION(((parentJacobian->tmpVars[159]) /* rover_8d.fz_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */)) * ((parentJacobian->tmpVars[163]) /* rover_8d.kappa_rl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_rl_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[73]) /* $cse25.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}
/*
equation index: 855
type: SIMPLE_ASSIGN
rover_8d.Fy_fr.$pDERC.dummyVarC = rover_8d.c_alpha * ($cse21 * (rover_8d.fz_fr.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_fr_bnd) + rover_8d.fz_fr * rover_8d.kappa_fr_bnd.$pDERC.dummyVarC) / (1.0 - rover_8d.kappa_fr_bnd) ^ 2.0 + $cse21.$pDERC.dummyVarC * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_855(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,855};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  (parentJacobian->tmpVars[135]) /* rover_8d.Fy_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION(((parentJacobian->tmpVars[158]) /* rover_8d.fz_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */)) * ((parentJacobian->tmpVars[162]) /* rover_8d.kappa_fr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_fr_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[69]) /* $cse21.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}
/*
equation index: 856
type: SIMPLE_ASSIGN
rover_8d.Fx_fr.$pDERC.dummyVarC = rover_8d.c_kappa * (rover_8d.kappa_fr_bnd * (rover_8d.fz_fr.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_fr_bnd) + rover_8d.fz_fr * rover_8d.kappa_fr_bnd.$pDERC.dummyVarC) / (1.0 - rover_8d.kappa_fr_bnd) ^ 2.0 + rover_8d.kappa_fr_bnd.$pDERC.dummyVarC * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_856(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,856};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  (parentJacobian->tmpVars[131]) /* rover_8d.Fx_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION(((parentJacobian->tmpVars[158]) /* rover_8d.fz_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */)) * ((parentJacobian->tmpVars[162]) /* rover_8d.kappa_fr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_fr_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[162]) /* rover_8d.kappa_fr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}
/*
equation index: 857
type: SIMPLE_ASSIGN
rover_8d.Fx_rr.$pDERC.dummyVarC = rover_8d.c_kappa * (rover_8d.kappa_rr_bnd * (rover_8d.fz_rr.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_rr_bnd) + rover_8d.fz_rr * rover_8d.kappa_rr_bnd.$pDERC.dummyVarC) / (1.0 - rover_8d.kappa_rr_bnd) ^ 2.0 + rover_8d.kappa_rr_bnd.$pDERC.dummyVarC * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_857(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,857};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  (parentJacobian->tmpVars[133]) /* rover_8d.Fx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION(((parentJacobian->tmpVars[160]) /* rover_8d.fz_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */)) * ((parentJacobian->tmpVars[164]) /* rover_8d.kappa_rr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_rr_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[164]) /* rover_8d.kappa_rr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}
/*
equation index: 858
type: SIMPLE_ASSIGN
rover_8d.ax.$pDERC.dummyVarC = (rover_8d.Fx_fl * $cse34.$pDERC.dummyVarC + rover_8d.Fx_fl.$pDERC.dummyVarC * $cse34 + rover_8d.Fy_fl * $cse35.$pDERC.dummyVarC + rover_8d.Fy_fl.$pDERC.dummyVarC * $cse35 + rover_8d.Fx_fr * $cse34.$pDERC.dummyVarC + rover_8d.Fx_fr.$pDERC.dummyVarC * $cse34 + rover_8d.Fy_fr * $cse35.$pDERC.dummyVarC + rover_8d.Fy_fr.$pDERC.dummyVarC * $cse35 + rover_8d.Fx_rl.$pDERC.dummyVarC + rover_8d.Fx_rr.$pDERC.dummyVarC) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_858(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,858};
  (parentJacobian->tmpVars[149]) /* rover_8d.ax.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * ((parentJacobian->tmpVars[83]) /* $cse34.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[130]) /* rover_8d.Fx_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((parentJacobian->tmpVars[84]) /* $cse35.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[134]) /* rover_8d.Fy_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((parentJacobian->tmpVars[83]) /* $cse34.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[131]) /* rover_8d.Fx_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((parentJacobian->tmpVars[84]) /* $cse35.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[135]) /* rover_8d.Fy_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (parentJacobian->tmpVars[132]) /* rover_8d.Fx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ + (parentJacobian->tmpVars[133]) /* rover_8d.Fx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}
/*
equation index: 859
type: SIMPLE_ASSIGN
rover_8d.Fy_rr.$pDERC.dummyVarC = rover_8d.c_alpha * ($cse29 * (rover_8d.fz_rr.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_rr_bnd) + rover_8d.fz_rr * rover_8d.kappa_rr_bnd.$pDERC.dummyVarC) / (1.0 - rover_8d.kappa_rr_bnd) ^ 2.0 + $cse29.$pDERC.dummyVarC * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_859(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,859};
  modelica_real tmp0;
  tmp0 = 1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  (parentJacobian->tmpVars[137]) /* rover_8d.Fy_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION(((parentJacobian->tmpVars[160]) /* rover_8d.fz_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */)) * ((parentJacobian->tmpVars[164]) /* rover_8d.kappa_rr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */),(tmp0 * tmp0),"(1.0 - rover_8d.kappa_rr_bnd) ^ 2.0")) + ((parentJacobian->tmpVars[77]) /* $cse29.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}
/*
equation index: 860
type: SIMPLE_ASSIGN
rover_8d.ay.$pDERC.dummyVarC = (rover_8d.Fy_fl * $cse34.$pDERC.dummyVarC + rover_8d.Fy_fl.$pDERC.dummyVarC * $cse34 + rover_8d.Fy_fr * $cse34.$pDERC.dummyVarC + rover_8d.Fy_fr.$pDERC.dummyVarC * $cse34 + rover_8d.Fy_rl.$pDERC.dummyVarC + rover_8d.Fy_rr.$pDERC.dummyVarC + (-rover_8d.Fx_fl) * $cse35.$pDERC.dummyVarC - rover_8d.Fx_fl.$pDERC.dummyVarC * $cse35 - rover_8d.Fx_fr.$pDERC.dummyVarC * $cse35 - rover_8d.Fx_fr * $cse35.$pDERC.dummyVarC) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_860(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,860};
  (parentJacobian->tmpVars[150]) /* rover_8d.ay.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((parentJacobian->tmpVars[83]) /* $cse34.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[134]) /* rover_8d.Fy_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((parentJacobian->tmpVars[83]) /* $cse34.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[135]) /* rover_8d.Fy_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (parentJacobian->tmpVars[136]) /* rover_8d.Fy_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ + (parentJacobian->tmpVars[137]) /* rover_8d.Fy_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */))) * ((parentJacobian->tmpVars[84]) /* $cse35.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - (((parentJacobian->tmpVars[130]) /* rover_8d.Fx_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((parentJacobian->tmpVars[131]) /* rover_8d.Fx_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((parentJacobian->tmpVars[84]) /* $cse35.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}
/*
equation index: 861
type: SIMPLE_ASSIGN
rover_8d.Fz_fr.$pDERC.dummyVarC = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERC.dummyVarC / rover_8d.l_total + (-0.5) * ((-rover_8d.k_rllsp) * rover_8d.phi.SeedC - rover_8d.c_rllsp * rover_8d.p.SeedC) / rover_8d.tw - rover_8d.ay.$pDERC.dummyVarC * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_861(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,861};
  (parentJacobian->tmpVars[139]) /* rover_8d.Fz_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[149]) /* rover_8d.ax.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (-0.5) * (DIVISION(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((parentJacobian->seedVars[24]) /* rover_8d.phi.SeedC SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((parentJacobian->seedVars[23]) /* rover_8d.p.SeedC SEED_VAR */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")) - (((parentJacobian->tmpVars[150]) /* rover_8d.ay.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}
/*
equation index: 862
type: SIMPLE_ASSIGN
rover_8d.z_fr.$pDERC.dummyVarC = if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_fr * (rover_8d.Fz_fr * ((-rover_8d.kappa_fr_bnd.$pDERC.dummyVarC) * sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) - (1.0 - rover_8d.kappa_fr_bnd) * 0.5 * (2.0 * rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.c_kappa * rover_8d.kappa_fr_bnd.$pDERC.dummyVarC + 2.0 * rover_8d.c_alpha * $cse21 * rover_8d.c_alpha * $cse21.$pDERC.dummyVarC) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)) / ((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) + rover_8d.Fz_fr.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)) + rover_8d.mu_fr.$pDERC.dummyVarC * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_862(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,862};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp24 = (modelica_boolean)tmp3;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp22 = (modelica_boolean)tmp7;
    if(tmp22)
    {
      tmp23 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp13 = (tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15;
      if(!(tmp13 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp13);
        }
      }tmp14 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp15 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }tmp19 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp20 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp21 = (tmp19 * tmp19) + (tmp20 * tmp20) + 1e-15;
      if(!(tmp21 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp21);
        }
      }
      tmp23 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(((-(parentJacobian->tmpVars[162]) /* rover_8d.kappa_fr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)) * (sqrt(tmp10)) - ((1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)))) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((parentJacobian->tmpVars[162]) /* rover_8d.kappa_fr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)) + ((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[69]) /* $cse21.$pDERC.dummyVarC JACOBIAN_TMP_VAR */))),sqrt(tmp13),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))),(tmp14 * tmp14) + (tmp15 * tmp15) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15")) + ((parentJacobian->tmpVars[139]) /* rover_8d.Fz_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[178]) /* rover_8d.mu_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp21),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))));
    }
    tmp25 = tmp23;
  }
  (parentJacobian->tmpVars[197]) /* rover_8d.z_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp25;
  TRACE_POP
}
/*
equation index: 863
type: SIMPLE_ASSIGN
rover_8d.Fz_rl.$pDERC.dummyVarC = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERC.dummyVarC / rover_8d.l_total + rover_8d.ay.$pDERC.dummyVarC * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw + 0.5 * ((-rover_8d.k_rllsp) * rover_8d.phi.SeedC - rover_8d.c_rllsp * rover_8d.p.SeedC) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_863(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,863};
  (parentJacobian->tmpVars[140]) /* rover_8d.Fz_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[149]) /* rover_8d.ax.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((parentJacobian->tmpVars[150]) /* rover_8d.ay.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")) + (0.5) * (DIVISION(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((parentJacobian->seedVars[24]) /* rover_8d.phi.SeedC SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((parentJacobian->seedVars[23]) /* rover_8d.p.SeedC SEED_VAR */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}
/*
equation index: 864
type: SIMPLE_ASSIGN
rover_8d.z_rl.$pDERC.dummyVarC = if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_rl * (rover_8d.Fz_rl * ((-rover_8d.kappa_rl_bnd.$pDERC.dummyVarC) * sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) - (1.0 - rover_8d.kappa_rl_bnd) * 0.5 * (2.0 * rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.c_kappa * rover_8d.kappa_rl_bnd.$pDERC.dummyVarC + 2.0 * rover_8d.c_alpha * $cse25 * rover_8d.c_alpha * $cse25.$pDERC.dummyVarC) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)) / ((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) + rover_8d.Fz_rl.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)) + rover_8d.mu_rl.$pDERC.dummyVarC * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_864(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,864};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp24 = (modelica_boolean)tmp3;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp22 = (modelica_boolean)tmp7;
    if(tmp22)
    {
      tmp23 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp13 = (tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15;
      if(!(tmp13 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp13);
        }
      }tmp14 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp15 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }tmp19 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp20 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp21 = (tmp19 * tmp19) + (tmp20 * tmp20) + 1e-15;
      if(!(tmp21 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp21);
        }
      }
      tmp23 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(((-(parentJacobian->tmpVars[163]) /* rover_8d.kappa_rl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)) * (sqrt(tmp10)) - ((1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)))) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((parentJacobian->tmpVars[163]) /* rover_8d.kappa_rl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)) + ((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[73]) /* $cse25.$pDERC.dummyVarC JACOBIAN_TMP_VAR */))),sqrt(tmp13),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))),(tmp14 * tmp14) + (tmp15 * tmp15) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15")) + ((parentJacobian->tmpVars[140]) /* rover_8d.Fz_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[179]) /* rover_8d.mu_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp21),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))));
    }
    tmp25 = tmp23;
  }
  (parentJacobian->tmpVars[198]) /* rover_8d.z_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp25;
  TRACE_POP
}
/*
equation index: 865
type: SIMPLE_ASSIGN
rover_8d.Fz_rr.$pDERC.dummyVarC = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERC.dummyVarC / rover_8d.l_total + (-0.5) * ((-rover_8d.k_rllsp) * rover_8d.phi.SeedC - rover_8d.c_rllsp * rover_8d.p.SeedC) / rover_8d.tw - rover_8d.ay.$pDERC.dummyVarC * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_865(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,865};
  (parentJacobian->tmpVars[141]) /* rover_8d.Fz_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[149]) /* rover_8d.ax.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (-0.5) * (DIVISION(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((parentJacobian->seedVars[24]) /* rover_8d.phi.SeedC SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((parentJacobian->seedVars[23]) /* rover_8d.p.SeedC SEED_VAR */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")) - (((parentJacobian->tmpVars[150]) /* rover_8d.ay.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}
/*
equation index: 866
type: SIMPLE_ASSIGN
rover_8d.z_rr.$pDERC.dummyVarC = if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_rr * (rover_8d.Fz_rr * ((-rover_8d.kappa_rr_bnd.$pDERC.dummyVarC) * sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) - (1.0 - rover_8d.kappa_rr_bnd) * 0.5 * (2.0 * rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.c_kappa * rover_8d.kappa_rr_bnd.$pDERC.dummyVarC + 2.0 * rover_8d.c_alpha * $cse29 * rover_8d.c_alpha * $cse29.$pDERC.dummyVarC) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)) / ((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) + rover_8d.Fz_rr.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)) + rover_8d.mu_rr.$pDERC.dummyVarC * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_866(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,866};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp24 = (modelica_boolean)tmp3;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp22 = (modelica_boolean)tmp7;
    if(tmp22)
    {
      tmp23 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp13 = (tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15;
      if(!(tmp13 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp13);
        }
      }tmp14 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp15 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }tmp19 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp20 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp21 = (tmp19 * tmp19) + (tmp20 * tmp20) + 1e-15;
      if(!(tmp21 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp21);
        }
      }
      tmp23 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(((-(parentJacobian->tmpVars[164]) /* rover_8d.kappa_rr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)) * (sqrt(tmp10)) - ((1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)))) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((parentJacobian->tmpVars[164]) /* rover_8d.kappa_rr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)) + ((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[77]) /* $cse29.$pDERC.dummyVarC JACOBIAN_TMP_VAR */))),sqrt(tmp13),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))),(tmp14 * tmp14) + (tmp15 * tmp15) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15")) + ((parentJacobian->tmpVars[141]) /* rover_8d.Fz_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[180]) /* rover_8d.mu_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp21),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))));
    }
    tmp25 = tmp23;
  }
  (parentJacobian->tmpVars[199]) /* rover_8d.z_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp25;
  TRACE_POP
}
/*
equation index: 867
type: SIMPLE_ASSIGN
rover_8d.Fz_fl.$pDERC.dummyVarC = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERC.dummyVarC / rover_8d.l_total + rover_8d.ay.$pDERC.dummyVarC * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw + 0.5 * ((-rover_8d.k_rllsp) * rover_8d.phi.SeedC - rover_8d.c_rllsp * rover_8d.p.SeedC) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_867(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,867};
  (parentJacobian->tmpVars[138]) /* rover_8d.Fz_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[149]) /* rover_8d.ax.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((parentJacobian->tmpVars[150]) /* rover_8d.ay.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")) + (0.5) * (DIVISION(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((parentJacobian->seedVars[24]) /* rover_8d.phi.SeedC SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((parentJacobian->seedVars[23]) /* rover_8d.p.SeedC SEED_VAR */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}
/*
equation index: 868
type: SIMPLE_ASSIGN
rover_8d.z_fl.$pDERC.dummyVarC = if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_fl * (rover_8d.Fz_fl * ((-rover_8d.kappa_fl_bnd.$pDERC.dummyVarC) * sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) - (1.0 - rover_8d.kappa_fl_bnd) * 0.5 * (2.0 * rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.c_kappa * rover_8d.kappa_fl_bnd.$pDERC.dummyVarC + 2.0 * rover_8d.c_alpha * $cse17 * rover_8d.c_alpha * $cse17.$pDERC.dummyVarC) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)) / ((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) + rover_8d.Fz_fl.$pDERC.dummyVarC * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)) + rover_8d.mu_fl.$pDERC.dummyVarC * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_868(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,868};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp24 = (modelica_boolean)tmp3;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp22 = (modelica_boolean)tmp7;
    if(tmp22)
    {
      tmp23 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp13 = (tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15;
      if(!(tmp13 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp13);
        }
      }tmp14 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp15 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }tmp19 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp20 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp21 = (tmp19 * tmp19) + (tmp20 * tmp20) + 1e-15;
      if(!(tmp21 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp21);
        }
      }
      tmp23 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(((-(parentJacobian->tmpVars[161]) /* rover_8d.kappa_fl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)) * (sqrt(tmp10)) - ((1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)))) * (((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((parentJacobian->tmpVars[161]) /* rover_8d.kappa_fl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)) + ((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[65]) /* $cse17.$pDERC.dummyVarC JACOBIAN_TMP_VAR */))),sqrt(tmp13),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))),(tmp14 * tmp14) + (tmp15 * tmp15) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15")) + ((parentJacobian->tmpVars[138]) /* rover_8d.Fz_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[177]) /* rover_8d.mu_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp21),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))));
    }
    tmp25 = tmp23;
  }
  (parentJacobian->tmpVars[196]) /* rover_8d.z_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp25;
  TRACE_POP
}

void residualFunc895(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,895};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[4].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  (parentJacobian->tmpVars[160]) /* rover_8d.fz_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = xloc[0];
  (parentJacobian->tmpVars[158]) /* rover_8d.fz_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = xloc[1];
  (parentJacobian->tmpVars[159]) /* rover_8d.fz_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = xloc[2];
  (parentJacobian->tmpVars[157]) /* rover_8d.fz_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = xloc[3];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_851(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_852(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_853(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_854(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_855(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_856(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_857(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_858(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_859(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_860(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_861(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_862(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_863(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_864(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_865(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_866(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_867(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_868(data, threadData, jacobian, parentJacobian);
  tmp0 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */),1.0);
  res[0] = (tmp0?((parentJacobian->tmpVars[198]) /* rover_8d.z_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):0.0) - (parentJacobian->tmpVars[159]) /* rover_8d.fz_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */;

  tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */),1.0);
  res[1] = (tmp1?((parentJacobian->tmpVars[199]) /* rover_8d.z_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):0.0) - (parentJacobian->tmpVars[160]) /* rover_8d.fz_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */;

  tmp2 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */),1.0);
  res[2] = (tmp2?((parentJacobian->tmpVars[197]) /* rover_8d.z_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):0.0) - (parentJacobian->tmpVars[158]) /* rover_8d.fz_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */;

  tmp3 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */),1.0);
  res[3] = (tmp3?((parentJacobian->tmpVars[196]) /* rover_8d.z_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):0.0) - (parentJacobian->tmpVars[157]) /* rover_8d.fz_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData895(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[4] = {
    160 /* rover_8d.fz_rr.$pDERC.dummyVarC */,
    158 /* rover_8d.fz_fr.$pDERC.dummyVarC */,
    159 /* rover_8d.fz_rl.$pDERC.dummyVarC */,
    157 /* rover_8d.fz_fl.$pDERC.dummyVarC */
  };
  for (int i = 0; i < 4; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}



/*
equation index: 1039
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERD.dummyVarD = (-4.0) * rover_8d.thr.$pDERD.dummyVarD / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_1039(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1039};
  (parentJacobian->tmpVars[39]) /* der(rover_8d.omega.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = (-4.0) * (DIVISION((parentJacobian->tmpVars[166]) /* rover_8d.thr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J"));
  TRACE_POP
}
/*
equation index: 1040
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERD.dummyVarD = (rover_8d.thr.$pDERD.dummyVarD - rover_8d.r_tire * rover_8d.Fx_fl.$pDERD.dummyVarD) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_1040(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1040};
  (parentJacobian->tmpVars[23]) /* der(rover_8d.omega_fl.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = DIVISION((parentJacobian->tmpVars[166]) /* rover_8d.thr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[112]) /* rover_8d.Fx_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 1041
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERD.dummyVarD = (rover_8d.thr.$pDERD.dummyVarD - rover_8d.r_tire * rover_8d.Fx_rr.$pDERD.dummyVarD) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_1041(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1041};
  (parentJacobian->tmpVars[26]) /* der(rover_8d.omega_rr.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = DIVISION((parentJacobian->tmpVars[166]) /* rover_8d.thr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[115]) /* rover_8d.Fx_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 1042
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERD.dummyVarD = (rover_8d.thr.$pDERD.dummyVarD - rover_8d.r_tire * rover_8d.Fx_rl.$pDERD.dummyVarD) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_1042(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1042};
  (parentJacobian->tmpVars[25]) /* der(rover_8d.omega_rl.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = DIVISION((parentJacobian->tmpVars[166]) /* rover_8d.thr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((parentJacobian->tmpVars[114]) /* rover_8d.Fx_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}
/*
equation index: 1043
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERD.dummyVarD = 4.0 * $DER.rover_8d.omega.$pDERD.dummyVarD / rover_8d.gratio - $DER.rover_8d.omega_rr.$pDERD.dummyVarD - $DER.rover_8d.omega_rl.$pDERD.dummyVarD - $DER.rover_8d.omega_fl.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_1043(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1043};
  (parentJacobian->tmpVars[24]) /* der(rover_8d.omega_fr.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = (4.0) * (DIVISION((parentJacobian->tmpVars[39]) /* der(rover_8d.omega.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - (parentJacobian->tmpVars[26]) /* der(rover_8d.omega_rr.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ - (parentJacobian->tmpVars[25]) /* der(rover_8d.omega_rl.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ - (parentJacobian->tmpVars[23]) /* der(rover_8d.omega_fl.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */;
  TRACE_POP
}

void residualFunc1051(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1051};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[3].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[166]) /* rover_8d.thr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = xloc[0];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_1039(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_1040(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_1041(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_1042(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_1043(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[166]) /* rover_8d.thr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ + ((-(data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */))) * ((parentJacobian->tmpVars[113]) /* rover_8d.Fx_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) - (((parentJacobian->tmpVars[24]) /* der(rover_8d.omega_fr.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData1051(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[1] = {
    166 /* rover_8d.thr.$pDERD.dummyVarD */
  };
  for (int i = 0; i < 1; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}



/*
equation index: 971
type: SIMPLE_ASSIGN
rover_8d.Fx_rr.$pDERD.dummyVarD = rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.fz_rr.$pDERD.dummyVarD / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_971(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,971};
  (parentJacobian->tmpVars[115]) /* rover_8d.Fx_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION((parentJacobian->tmpVars[142]) /* rover_8d.fz_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}
/*
equation index: 972
type: SIMPLE_ASSIGN
rover_8d.Fy_rr.$pDERD.dummyVarD = rover_8d.c_alpha * ($cse29 * rover_8d.fz_rr.$pDERD.dummyVarD / (1.0 - rover_8d.kappa_rr_bnd) + $cse29.$pDERD.dummyVarD * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_972(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,972};
  (parentJacobian->tmpVars[119]) /* rover_8d.Fy_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION((parentJacobian->tmpVars[142]) /* rover_8d.fz_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")) + ((parentJacobian->tmpVars[59]) /* $cse29.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}
/*
equation index: 973
type: SIMPLE_ASSIGN
rover_8d.Fx_fr.$pDERD.dummyVarD = rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.fz_fr.$pDERD.dummyVarD / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_973(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,973};
  (parentJacobian->tmpVars[113]) /* rover_8d.Fx_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION((parentJacobian->tmpVars[140]) /* rover_8d.fz_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}
/*
equation index: 974
type: SIMPLE_ASSIGN
rover_8d.Fy_fr.$pDERD.dummyVarD = rover_8d.c_alpha * ($cse21 * rover_8d.fz_fr.$pDERD.dummyVarD / (1.0 - rover_8d.kappa_fr_bnd) + $cse21.$pDERD.dummyVarD * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd))
*/
void RoverExample_Components_Rover_eqFunction_974(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,974};
  (parentJacobian->tmpVars[117]) /* rover_8d.Fy_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION((parentJacobian->tmpVars[140]) /* rover_8d.fz_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")) + ((parentJacobian->tmpVars[51]) /* $cse21.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}
/*
equation index: 975
type: SIMPLE_ASSIGN
rover_8d.Fy_fl.$pDERD.dummyVarD = rover_8d.c_alpha * ($cse17 * rover_8d.fz_fl.$pDERD.dummyVarD / (1.0 - rover_8d.kappa_fl_bnd) + $cse17.$pDERD.dummyVarD * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_975(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,975};
  (parentJacobian->tmpVars[116]) /* rover_8d.Fy_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION((parentJacobian->tmpVars[139]) /* rover_8d.fz_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")) + ((parentJacobian->tmpVars[47]) /* $cse17.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}
/*
equation index: 976
type: SIMPLE_ASSIGN
rover_8d.Fx_fl.$pDERD.dummyVarD = rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.fz_fl.$pDERD.dummyVarD / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_976(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,976};
  (parentJacobian->tmpVars[112]) /* rover_8d.Fx_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION((parentJacobian->tmpVars[139]) /* rover_8d.fz_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}
/*
equation index: 977
type: SIMPLE_ASSIGN
rover_8d.Fx_rl.$pDERD.dummyVarD = rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.fz_rl.$pDERD.dummyVarD / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_977(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,977};
  (parentJacobian->tmpVars[114]) /* rover_8d.Fx_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION((parentJacobian->tmpVars[141]) /* rover_8d.fz_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}
/*
equation index: 978
type: SIMPLE_ASSIGN
$DER.rover_8d.vx.$pDERD.dummyVarD = (rover_8d.Fx_fl * $cse34.$pDERD.dummyVarD + rover_8d.Fx_fl.$pDERD.dummyVarD * $cse34 + rover_8d.Fy_fl * $cse35.$pDERD.dummyVarD + rover_8d.Fy_fl.$pDERD.dummyVarD * $cse35 + rover_8d.Fx_fr * $cse34.$pDERD.dummyVarD + rover_8d.Fx_fr.$pDERD.dummyVarD * $cse34 + rover_8d.Fy_fr * $cse35.$pDERD.dummyVarD + rover_8d.Fy_fr.$pDERD.dummyVarD * $cse35 + rover_8d.Fx_rl.$pDERD.dummyVarD + rover_8d.Fx_rr.$pDERD.dummyVarD) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_978(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,978};
  (parentJacobian->tmpVars[33]) /* der(rover_8d.vx.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * ((parentJacobian->tmpVars[65]) /* $cse34.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[112]) /* rover_8d.Fx_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((parentJacobian->tmpVars[66]) /* $cse35.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[116]) /* rover_8d.Fy_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((parentJacobian->tmpVars[65]) /* $cse34.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[113]) /* rover_8d.Fx_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((parentJacobian->tmpVars[66]) /* $cse35.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[117]) /* rover_8d.Fy_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (parentJacobian->tmpVars[114]) /* rover_8d.Fx_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ + (parentJacobian->tmpVars[115]) /* rover_8d.Fx_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}
/*
equation index: 979
type: SIMPLE_ASSIGN
rover_8d.Fy_rl.$pDERD.dummyVarD = rover_8d.c_alpha * ($cse25 * rover_8d.fz_rl.$pDERD.dummyVarD / (1.0 - rover_8d.kappa_rl_bnd) + $cse25.$pDERD.dummyVarD * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd))
*/
void RoverExample_Components_Rover_eqFunction_979(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,979};
  (parentJacobian->tmpVars[118]) /* rover_8d.Fy_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION((parentJacobian->tmpVars[141]) /* rover_8d.fz_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")) + ((parentJacobian->tmpVars[55]) /* $cse25.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}
/*
equation index: 980
type: SIMPLE_ASSIGN
ay_meas.$pDERD.dummyVarD = (rover_8d.Fy_fl * $cse34.$pDERD.dummyVarD + rover_8d.Fy_fl.$pDERD.dummyVarD * $cse34 + rover_8d.Fy_fr * $cse34.$pDERD.dummyVarD + rover_8d.Fy_fr.$pDERD.dummyVarD * $cse34 + rover_8d.Fy_rl.$pDERD.dummyVarD + rover_8d.Fy_rr.$pDERD.dummyVarD + (-rover_8d.Fx_fr.$pDERD.dummyVarD) * $cse35 - rover_8d.Fx_fr * $cse35.$pDERD.dummyVarD - rover_8d.Fx_fl.$pDERD.dummyVarD * $cse35 - rover_8d.Fx_fl * $cse35.$pDERD.dummyVarD) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_980(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,980};
  (parentJacobian->resultVars[1]) /* ay_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((parentJacobian->tmpVars[65]) /* $cse34.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[116]) /* rover_8d.Fy_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((parentJacobian->tmpVars[65]) /* $cse34.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + ((parentJacobian->tmpVars[117]) /* rover_8d.Fy_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (parentJacobian->tmpVars[118]) /* rover_8d.Fy_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ + (parentJacobian->tmpVars[119]) /* rover_8d.Fy_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ + ((-(parentJacobian->tmpVars[113]) /* rover_8d.Fx_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((parentJacobian->tmpVars[66]) /* $cse35.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)) - (((parentJacobian->tmpVars[112]) /* rover_8d.Fx_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * ((parentJacobian->tmpVars[66]) /* $cse35.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}
/*
equation index: 981
type: SIMPLE_ASSIGN
rover_8d.Fz_fr.$pDERD.dummyVarD = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERD.dummyVarD / rover_8d.l_total - ay_meas.$pDERD.dummyVarD * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_981(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,981};
  (parentJacobian->tmpVars[121]) /* rover_8d.Fz_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[33]) /* der(rover_8d.vx.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - (((parentJacobian->resultVars[1]) /* ay_meas.$pDERD.dummyVarD JACOBIAN_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}
/*
equation index: 982
type: SIMPLE_ASSIGN
rover_8d.z_fr.$pDERD.dummyVarD = if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_fr * (rover_8d.Fz_fr * (rover_8d.kappa_fr_bnd - 1.0) * 0.5 * 2.0 * rover_8d.c_alpha * $cse21 * rover_8d.c_alpha * $cse21.$pDERD.dummyVarD / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) / ((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) + rover_8d.Fz_fr.$pDERD.dummyVarD * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)) + rover_8d.mu_fr.$pDERD.dummyVarD * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_982(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,982};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_boolean tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp21 = (modelica_boolean)tmp3;
  if(tmp21)
  {
    tmp22 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp19 = (modelica_boolean)tmp7;
    if(tmp19)
    {
      tmp20 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp13 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp14 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp15 = (tmp13 * tmp13) + (tmp14 * tmp14) + 1e-15;
      if(!(tmp15 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp15);
        }
      }tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }
      tmp20 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */) - 1.0) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[51]) /* $cse21.$pDERD.dummyVarD JACOBIAN_TMP_VAR */))),sqrt(tmp10),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))),(tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15") + ((parentJacobian->tmpVars[121]) /* rover_8d.Fz_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp15),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[160]) /* rover_8d.mu_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))));
    }
    tmp22 = tmp20;
  }
  (parentJacobian->tmpVars[179]) /* rover_8d.z_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp22;
  TRACE_POP
}
/*
equation index: 983
type: SIMPLE_ASSIGN
rover_8d.Fz_fl.$pDERD.dummyVarD = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERD.dummyVarD / rover_8d.l_total + ay_meas.$pDERD.dummyVarD * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_983(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,983};
  (parentJacobian->tmpVars[120]) /* rover_8d.Fz_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[33]) /* der(rover_8d.vx.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((parentJacobian->resultVars[1]) /* ay_meas.$pDERD.dummyVarD JACOBIAN_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}
/*
equation index: 984
type: SIMPLE_ASSIGN
rover_8d.z_fl.$pDERD.dummyVarD = if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_fl * (rover_8d.Fz_fl * (rover_8d.kappa_fl_bnd - 1.0) * 0.5 * 2.0 * rover_8d.c_alpha * $cse17 * rover_8d.c_alpha * $cse17.$pDERD.dummyVarD / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) / ((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) + rover_8d.Fz_fl.$pDERD.dummyVarD * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)) + rover_8d.mu_fl.$pDERD.dummyVarD * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_984(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,984};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_boolean tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp21 = (modelica_boolean)tmp3;
  if(tmp21)
  {
    tmp22 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp19 = (modelica_boolean)tmp7;
    if(tmp19)
    {
      tmp20 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp13 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp14 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp15 = (tmp13 * tmp13) + (tmp14 * tmp14) + 1e-15;
      if(!(tmp15 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp15);
        }
      }tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }
      tmp20 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */) - 1.0) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[47]) /* $cse17.$pDERD.dummyVarD JACOBIAN_TMP_VAR */))),sqrt(tmp10),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))),(tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15") + ((parentJacobian->tmpVars[120]) /* rover_8d.Fz_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp15),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[159]) /* rover_8d.mu_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))));
    }
    tmp22 = tmp20;
  }
  (parentJacobian->tmpVars[178]) /* rover_8d.z_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp22;
  TRACE_POP
}
/*
equation index: 985
type: SIMPLE_ASSIGN
rover_8d.Fz_rr.$pDERD.dummyVarD = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERD.dummyVarD / rover_8d.l_total - ay_meas.$pDERD.dummyVarD * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_985(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,985};
  (parentJacobian->tmpVars[123]) /* rover_8d.Fz_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[33]) /* der(rover_8d.vx.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - (((parentJacobian->resultVars[1]) /* ay_meas.$pDERD.dummyVarD JACOBIAN_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}
/*
equation index: 986
type: SIMPLE_ASSIGN
rover_8d.z_rr.$pDERD.dummyVarD = if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_rr * (rover_8d.Fz_rr * (rover_8d.kappa_rr_bnd - 1.0) * 0.5 * 2.0 * rover_8d.c_alpha * $cse29 * rover_8d.c_alpha * $cse29.$pDERD.dummyVarD / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) / ((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) + rover_8d.Fz_rr.$pDERD.dummyVarD * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)) + rover_8d.mu_rr.$pDERD.dummyVarD * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_986(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,986};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_boolean tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp21 = (modelica_boolean)tmp3;
  if(tmp21)
  {
    tmp22 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp19 = (modelica_boolean)tmp7;
    if(tmp19)
    {
      tmp20 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp13 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp14 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp15 = (tmp13 * tmp13) + (tmp14 * tmp14) + 1e-15;
      if(!(tmp15 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp15);
        }
      }tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }
      tmp20 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */) - 1.0) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[59]) /* $cse29.$pDERD.dummyVarD JACOBIAN_TMP_VAR */))),sqrt(tmp10),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))),(tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15") + ((parentJacobian->tmpVars[123]) /* rover_8d.Fz_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp15),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[162]) /* rover_8d.mu_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))));
    }
    tmp22 = tmp20;
  }
  (parentJacobian->tmpVars[181]) /* rover_8d.z_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp22;
  TRACE_POP
}
/*
equation index: 987
type: SIMPLE_ASSIGN
rover_8d.Fz_rl.$pDERD.dummyVarD = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERD.dummyVarD / rover_8d.l_total + ay_meas.$pDERD.dummyVarD * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_987(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,987};
  (parentJacobian->tmpVars[122]) /* rover_8d.Fz_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION((parentJacobian->tmpVars[33]) /* der(rover_8d.vx.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((parentJacobian->resultVars[1]) /* ay_meas.$pDERD.dummyVarD JACOBIAN_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}
/*
equation index: 988
type: SIMPLE_ASSIGN
rover_8d.z_rl.$pDERD.dummyVarD = if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * (rover_8d.mu_rl * (rover_8d.Fz_rl * (rover_8d.kappa_rl_bnd - 1.0) * 0.5 * 2.0 * rover_8d.c_alpha * $cse25 * rover_8d.c_alpha * $cse25.$pDERD.dummyVarD / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) / ((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) + rover_8d.Fz_rl.$pDERD.dummyVarD * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)) + rover_8d.mu_rl.$pDERD.dummyVarD * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15))
*/
void RoverExample_Components_Rover_eqFunction_988(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,988};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_boolean tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }tmp3 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp21 = (modelica_boolean)tmp3;
  if(tmp21)
  {
    tmp22 = 0.0;
  }
  else
  {
    tmp4 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
    tmp5 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
    tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5) + 1e-15;
    if(!(tmp6 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp6);
      }
    }tmp7 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp6),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp19 = (modelica_boolean)tmp7;
    if(tmp19)
    {
      tmp20 = 0.0;
    }
    else
    {
      tmp8 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp9 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp10 = (tmp8 * tmp8) + (tmp9 * tmp9) + 1e-15;
      if(!(tmp10 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp10);
        }
      }tmp11 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp12 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp13 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp14 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp15 = (tmp13 * tmp13) + (tmp14 * tmp14) + 1e-15;
      if(!(tmp15 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp15);
        }
      }tmp16 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp17 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp18 = (tmp16 * tmp16) + (tmp17 * tmp17) + 1e-15;
      if(!(tmp18 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp18);
        }
      }
      tmp20 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */) - 1.0) * (DIVISION((0.5) * (((2.0) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)))) * (((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((parentJacobian->tmpVars[55]) /* $cse25.$pDERD.dummyVarD JACOBIAN_TMP_VAR */))),sqrt(tmp10),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))),(tmp11 * tmp11) + (tmp12 * tmp12) + 1e-15,"(rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15") + ((parentJacobian->tmpVars[122]) /* rover_8d.Fz_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp15),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))) + ((parentJacobian->tmpVars[161]) /* rover_8d.mu_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp18),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))));
    }
    tmp22 = tmp20;
  }
  (parentJacobian->tmpVars[180]) /* rover_8d.z_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp22;
  TRACE_POP
}

void residualFunc1015(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1015};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[2].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  (parentJacobian->tmpVars[141]) /* rover_8d.fz_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = xloc[0];
  (parentJacobian->tmpVars[139]) /* rover_8d.fz_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = xloc[1];
  (parentJacobian->tmpVars[140]) /* rover_8d.fz_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = xloc[2];
  (parentJacobian->tmpVars[142]) /* rover_8d.fz_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = xloc[3];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_971(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_972(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_973(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_974(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_975(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_976(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_977(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_978(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_979(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_980(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_981(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_982(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_983(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_984(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_985(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_986(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_987(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_988(data, threadData, jacobian, parentJacobian);
  tmp0 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */),1.0);
  res[0] = (tmp0?((parentJacobian->tmpVars[181]) /* rover_8d.z_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):0.0) - (parentJacobian->tmpVars[142]) /* rover_8d.fz_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */;

  tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */),1.0);
  res[1] = (tmp1?((parentJacobian->tmpVars[180]) /* rover_8d.z_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):0.0) - (parentJacobian->tmpVars[141]) /* rover_8d.fz_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */;

  tmp2 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */),1.0);
  res[2] = (tmp2?((parentJacobian->tmpVars[178]) /* rover_8d.z_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):0.0) - (parentJacobian->tmpVars[139]) /* rover_8d.fz_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */;

  tmp3 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */),1.0);
  res[3] = (tmp3?((parentJacobian->tmpVars[179]) /* rover_8d.z_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):0.0) - (parentJacobian->tmpVars[140]) /* rover_8d.fz_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData1015(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[4] = {
    141 /* rover_8d.fz_rl.$pDERD.dummyVarD */,
    139 /* rover_8d.fz_fl.$pDERD.dummyVarD */,
    140 /* rover_8d.fz_fr.$pDERD.dummyVarD */,
    142 /* rover_8d.fz_rr.$pDERD.dummyVarD */
  };
  for (int i = 0; i < 4; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}



/*
equation index: 355
type: SIMPLE_ASSIGN
$DER.rover_8d.omega = (rover_8d.Kt_q * rover_8d.Iq + (-4.0) * rover_8d.thr - rover_8d.b * rover_8d.omega) / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_355(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,355};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* der(rover_8d.omega) DUMMY_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[71] /* rover_8d.Kt_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */)) + (-4.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */)) - (((data->simulationInfo->realParameter[81] /* rover_8d.b PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* rover_8d.omega DUMMY_STATE */))),(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J",equationIndexes);
  TRACE_POP
}
/*
equation index: 356
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl = (rover_8d.thr - rover_8d.r_tire * rover_8d.Fx_fl) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_356(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,356};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* der(rover_8d.omega_fl) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */))),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel",equationIndexes);
  TRACE_POP
}
/*
equation index: 357
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr = (rover_8d.thr - rover_8d.r_tire * rover_8d.Fx_rr) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_357(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,357};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* der(rover_8d.omega_rr) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[166]] /* rover_8d.Fx_rr variable */))),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel",equationIndexes);
  TRACE_POP
}
/*
equation index: 358
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr = (rover_8d.thr - rover_8d.r_tire * rover_8d.Fx_fr) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_358(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,358};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* der(rover_8d.omega_fr) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel",equationIndexes);
  TRACE_POP
}
/*
equation index: 359
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl = 4.0 * $DER.rover_8d.omega / rover_8d.gratio - der(rover_8d.omega_fr) - der(rover_8d.omega_fl) - der(rover_8d.omega_rr)
*/
void RoverExample_Components_Rover_eqFunction_359(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,359};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* der(rover_8d.omega_rl) STATE_DER */) = (4.0) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* der(rover_8d.omega) DUMMY_DER */),(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio",equationIndexes)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* der(rover_8d.omega_fr) STATE_DER */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* der(rover_8d.omega_fl) STATE_DER */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* der(rover_8d.omega_rr) STATE_DER */);
  TRACE_POP
}

void residualFunc367(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,367};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) = xloc[0];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_355(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_356(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_357(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_358(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_359(data, threadData);
  res[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) + ((-(data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[165]] /* rover_8d.Fx_rl variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* der(rover_8d.omega_rl) STATE_DER */)) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData367(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[1] = {
    218 /* rover_8d.thr */
  };
  for (int i = 0; i < 1; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}



/*
equation index: 168
type: SIMPLE_ASSIGN
$DER.rover_8d.omega = (rover_8d.Kt_q * rover_8d.Iq + (-4.0) * rover_8d.thr - rover_8d.b * rover_8d.omega) / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* der(rover_8d.omega) DUMMY_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[71] /* rover_8d.Kt_q PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* rover_8d.Iq STATE(1) */)) + (-4.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */)) - (((data->simulationInfo->realParameter[81] /* rover_8d.b PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* rover_8d.omega DUMMY_STATE */))),(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J",equationIndexes);
  TRACE_POP
}
/*
equation index: 169
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl = (rover_8d.thr - rover_8d.r_tire * rover_8d.Fx_fl) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* der(rover_8d.omega_fl) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */))),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel",equationIndexes);
  TRACE_POP
}
/*
equation index: 170
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl = (rover_8d.thr - rover_8d.r_tire * rover_8d.Fx_rl) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* der(rover_8d.omega_rl) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[165]] /* rover_8d.Fx_rl variable */))),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel",equationIndexes);
  TRACE_POP
}
/*
equation index: 171
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr = (rover_8d.thr - rover_8d.r_tire * rover_8d.Fx_fr) / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,171};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* der(rover_8d.omega_fr) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) - (((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))),(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel",equationIndexes);
  TRACE_POP
}
/*
equation index: 172
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr = 4.0 * $DER.rover_8d.omega / rover_8d.gratio - $DER.rover_8d.omega_fr - $DER.rover_8d.omega_fl - $DER.rover_8d.omega_rl
*/
void RoverExample_Components_Rover_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* der(rover_8d.omega_rr) STATE_DER */) = (4.0) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* der(rover_8d.omega) DUMMY_DER */),(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio",equationIndexes)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* der(rover_8d.omega_fr) STATE_DER */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* der(rover_8d.omega_fl) STATE_DER */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* der(rover_8d.omega_rl) STATE_DER */);
  TRACE_POP
}

void residualFunc180(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,180};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) = xloc[0];
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_168(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_169(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_170(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_171(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_172(data, threadData);
  res[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* rover_8d.thr variable */) + ((-(data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[166]] /* rover_8d.Fx_rr variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* der(rover_8d.omega_rr) STATE_DER */)) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData180(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[1] = {
    218 /* rover_8d.thr */
  };
  for (int i = 0; i < 1; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize linear systems */
void RoverExample_Components_Rover_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA* linearSystemData)
{
  /* linear systems */
  assertStreamPrint(NULL, nLinearSystems > 9, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[9].equationIndex = 610;
  linearSystemData[9].size = 1;
  linearSystemData[9].nnz = 0;
  linearSystemData[9].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[9].residualFunc = residualFunc610;
  linearSystemData[9].strictTearingFunctionCall = NULL;
  linearSystemData[9].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac5_column;
  linearSystemData[9].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac5;
  linearSystemData[9].jacobianIndex = 15 /*jacInx*/;
  linearSystemData[9].setA = NULL;  //setLinearMatrixA610;
  linearSystemData[9].setb = NULL;  //setLinearVectorb610;
  linearSystemData[9].initializeStaticLSData = initializeStaticLSData610;
  
  assertStreamPrint(NULL, nLinearSystems > 8, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[8].equationIndex = 593;
  linearSystemData[8].size = 4;
  linearSystemData[8].nnz = 0;
  linearSystemData[8].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[8].residualFunc = residualFunc593;
  linearSystemData[8].strictTearingFunctionCall = NULL;
  linearSystemData[8].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac4_column;
  linearSystemData[8].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac4;
  linearSystemData[8].jacobianIndex = 14 /*jacInx*/;
  linearSystemData[8].setA = NULL;  //setLinearMatrixA593;
  linearSystemData[8].setb = NULL;  //setLinearVectorb593;
  linearSystemData[8].initializeStaticLSData = initializeStaticLSData593;
  
  assertStreamPrint(NULL, nLinearSystems > 7, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[7].equationIndex = 727;
  linearSystemData[7].size = 1;
  linearSystemData[7].nnz = 0;
  linearSystemData[7].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[7].residualFunc = residualFunc727;
  linearSystemData[7].strictTearingFunctionCall = NULL;
  linearSystemData[7].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac7_column;
  linearSystemData[7].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac7;
  linearSystemData[7].jacobianIndex = 12 /*jacInx*/;
  linearSystemData[7].setA = NULL;  //setLinearMatrixA727;
  linearSystemData[7].setb = NULL;  //setLinearVectorb727;
  linearSystemData[7].initializeStaticLSData = initializeStaticLSData727;
  
  assertStreamPrint(NULL, nLinearSystems > 6, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[6].equationIndex = 711;
  linearSystemData[6].size = 4;
  linearSystemData[6].nnz = 0;
  linearSystemData[6].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[6].residualFunc = residualFunc711;
  linearSystemData[6].strictTearingFunctionCall = NULL;
  linearSystemData[6].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac6_column;
  linearSystemData[6].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac6;
  linearSystemData[6].jacobianIndex = 11 /*jacInx*/;
  linearSystemData[6].setA = NULL;  //setLinearMatrixA711;
  linearSystemData[6].setb = NULL;  //setLinearVectorb711;
  linearSystemData[6].initializeStaticLSData = initializeStaticLSData711;
  
  assertStreamPrint(NULL, nLinearSystems > 5, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[5].equationIndex = 914;
  linearSystemData[5].size = 1;
  linearSystemData[5].nnz = 0;
  linearSystemData[5].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[5].residualFunc = residualFunc914;
  linearSystemData[5].strictTearingFunctionCall = NULL;
  linearSystemData[5].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac9_column;
  linearSystemData[5].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac9;
  linearSystemData[5].jacobianIndex = 9 /*jacInx*/;
  linearSystemData[5].setA = NULL;  //setLinearMatrixA914;
  linearSystemData[5].setb = NULL;  //setLinearVectorb914;
  linearSystemData[5].initializeStaticLSData = initializeStaticLSData914;
  
  assertStreamPrint(NULL, nLinearSystems > 4, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[4].equationIndex = 895;
  linearSystemData[4].size = 4;
  linearSystemData[4].nnz = 0;
  linearSystemData[4].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[4].residualFunc = residualFunc895;
  linearSystemData[4].strictTearingFunctionCall = NULL;
  linearSystemData[4].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac8_column;
  linearSystemData[4].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac8;
  linearSystemData[4].jacobianIndex = 8 /*jacInx*/;
  linearSystemData[4].setA = NULL;  //setLinearMatrixA895;
  linearSystemData[4].setb = NULL;  //setLinearVectorb895;
  linearSystemData[4].initializeStaticLSData = initializeStaticLSData895;
  
  assertStreamPrint(NULL, nLinearSystems > 3, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[3].equationIndex = 1051;
  linearSystemData[3].size = 1;
  linearSystemData[3].nnz = 0;
  linearSystemData[3].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[3].residualFunc = residualFunc1051;
  linearSystemData[3].strictTearingFunctionCall = NULL;
  linearSystemData[3].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac11_column;
  linearSystemData[3].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac11;
  linearSystemData[3].jacobianIndex = 6 /*jacInx*/;
  linearSystemData[3].setA = NULL;  //setLinearMatrixA1051;
  linearSystemData[3].setb = NULL;  //setLinearVectorb1051;
  linearSystemData[3].initializeStaticLSData = initializeStaticLSData1051;
  
  assertStreamPrint(NULL, nLinearSystems > 2, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[2].equationIndex = 1015;
  linearSystemData[2].size = 4;
  linearSystemData[2].nnz = 0;
  linearSystemData[2].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[2].residualFunc = residualFunc1015;
  linearSystemData[2].strictTearingFunctionCall = NULL;
  linearSystemData[2].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac10_column;
  linearSystemData[2].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac10;
  linearSystemData[2].jacobianIndex = 5 /*jacInx*/;
  linearSystemData[2].setA = NULL;  //setLinearMatrixA1015;
  linearSystemData[2].setb = NULL;  //setLinearVectorb1015;
  linearSystemData[2].initializeStaticLSData = initializeStaticLSData1015;
  
  assertStreamPrint(NULL, nLinearSystems > 1, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[1].equationIndex = 367;
  linearSystemData[1].size = 1;
  linearSystemData[1].nnz = 0;
  linearSystemData[1].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[1].residualFunc = residualFunc367;
  linearSystemData[1].strictTearingFunctionCall = NULL;
  linearSystemData[1].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac3_column;
  linearSystemData[1].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac3;
  linearSystemData[1].jacobianIndex = 1 /*jacInx*/;
  linearSystemData[1].setA = NULL;  //setLinearMatrixA367;
  linearSystemData[1].setb = NULL;  //setLinearVectorb367;
  linearSystemData[1].initializeStaticLSData = initializeStaticLSData367;
  
  assertStreamPrint(NULL, nLinearSystems > 0, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[0].equationIndex = 180;
  linearSystemData[0].size = 1;
  linearSystemData[0].nnz = 0;
  linearSystemData[0].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[0].residualFunc = residualFunc180;
  linearSystemData[0].strictTearingFunctionCall = NULL;
  linearSystemData[0].analyticalJacobianColumn = RoverExample_Components_Rover_functionJacLSJac1_column;
  linearSystemData[0].initialAnalyticalJacobian = RoverExample_Components_Rover_initialAnalyticJacobianLSJac1;
  linearSystemData[0].jacobianIndex = 0 /*jacInx*/;
  linearSystemData[0].setA = NULL;  //setLinearMatrixA180;
  linearSystemData[0].setb = NULL;  //setLinearVectorb180;
  linearSystemData[0].initializeStaticLSData = initializeStaticLSData180;
}

#if defined(__cplusplus)
}
#endif

