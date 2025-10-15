/* Jacobians 16 */
#include "RoverExample.Components.Rover_model.h"
#include "RoverExample.Components.Rover_12jac.h"
#include "simulation/jacobian_util.h"
#include "util/omc_file.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 174
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERLSJac1.dummyVarLSJac1 = (-4.0) * rover_8d.thr.SeedLSJac1 / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_174(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,174};
  jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */ = (-4.0) * (DIVISION(jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac1 SEED_VAR */,(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J"));
  TRACE_POP
}

/*
equation index: 175
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERLSJac1.dummyVarLSJac1 = rover_8d.thr.SeedLSJac1 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_175(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,175};
  jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac1 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 176
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERLSJac1.dummyVarLSJac1 = rover_8d.thr.SeedLSJac1 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_176(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,176};
  jacobian->tmpVars[2] /* der(rover_8d.omega_rl.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac1 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 177
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERLSJac1.dummyVarLSJac1 = rover_8d.thr.SeedLSJac1 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_177(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,177};
  jacobian->tmpVars[3] /* der(rover_8d.omega_fr.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac1 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 178
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERLSJac1.dummyVarLSJac1 = 4.0 * $DER.rover_8d.omega.$pDERLSJac1.dummyVarLSJac1 / rover_8d.gratio - $DER.rover_8d.omega_rl.$pDERLSJac1.dummyVarLSJac1 - $DER.rover_8d.omega_fl.$pDERLSJac1.dummyVarLSJac1 - $DER.rover_8d.omega_fr.$pDERLSJac1.dummyVarLSJac1
*/
void RoverExample_Components_Rover_eqFunction_178(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,178};
  jacobian->tmpVars[4] /* der(rover_8d.omega_rr.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */ = (4.0) * (DIVISION(jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - jacobian->tmpVars[2] /* der(rover_8d.omega_rl.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[3] /* der(rover_8d.omega_fr.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 179
type: SIMPLE_ASSIGN
$res_LSJac1_1.$pDERLSJac1.dummyVarLSJac1 = rover_8d.thr.SeedLSJac1 - $DER.rover_8d.omega_rr.$pDERLSJac1.dummyVarLSJac1 * rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_179(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,179};
  jacobian->resultVars[0] /* $res_LSJac1_1.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac1 SEED_VAR */ - ((jacobian->tmpVars[4] /* der(rover_8d.omega_rr.$pDERLSJac1.dummyVarLSJac1) JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac1_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac1;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac1_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac1;
  RoverExample_Components_Rover_eqFunction_174(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_175(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_176(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_177(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_178(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_179(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 361
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERLSJac3.dummyVarLSJac3 = (-4.0) * rover_8d.thr.SeedLSJac3 / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_361(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,361};
  jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */ = (-4.0) * (DIVISION(jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac3 SEED_VAR */,(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J"));
  TRACE_POP
}

/*
equation index: 362
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERLSJac3.dummyVarLSJac3 = rover_8d.thr.SeedLSJac3 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_362(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,362};
  jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac3 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 363
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERLSJac3.dummyVarLSJac3 = rover_8d.thr.SeedLSJac3 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_363(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,363};
  jacobian->tmpVars[2] /* der(rover_8d.omega_rr.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac3 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 364
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERLSJac3.dummyVarLSJac3 = rover_8d.thr.SeedLSJac3 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_364(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,364};
  jacobian->tmpVars[3] /* der(rover_8d.omega_fr.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac3 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 365
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERLSJac3.dummyVarLSJac3 = 4.0 * $DER.rover_8d.omega.$pDERLSJac3.dummyVarLSJac3 / rover_8d.gratio - $DER.rover_8d.omega_rr.$pDERLSJac3.dummyVarLSJac3 - $DER.rover_8d.omega_fl.$pDERLSJac3.dummyVarLSJac3 - $DER.rover_8d.omega_fr.$pDERLSJac3.dummyVarLSJac3
*/
void RoverExample_Components_Rover_eqFunction_365(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,365};
  jacobian->tmpVars[4] /* der(rover_8d.omega_rl.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */ = (4.0) * (DIVISION(jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - jacobian->tmpVars[2] /* der(rover_8d.omega_rr.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[3] /* der(rover_8d.omega_fr.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 366
type: SIMPLE_ASSIGN
$res_LSJac3_1.$pDERLSJac3.dummyVarLSJac3 = rover_8d.thr.SeedLSJac3 - $DER.rover_8d.omega_rl.$pDERLSJac3.dummyVarLSJac3 * rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_366(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,366};
  jacobian->resultVars[0] /* $res_LSJac3_1.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = jacobian->seedVars[0] /* rover_8d.thr.SeedLSJac3 SEED_VAR */ - ((jacobian->tmpVars[4] /* der(rover_8d.omega_rl.$pDERLSJac3.dummyVarLSJac3) JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac3_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac3;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac3_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac3;
  RoverExample_Components_Rover_eqFunction_361(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_362(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_363(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_364(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_365(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_366(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
int RoverExample_Components_Rover_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int RoverExample_Components_Rover_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 925
type: SIMPLE_ASSIGN
$cse90 = cosh(abs(rover_8d.vx_fl))
*/
void RoverExample_Components_Rover_eqFunction_925(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,925};
  jacobian->tmpVars[3] /* $cse90 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */)));
  TRACE_POP
}

/*
equation index: 926
type: SIMPLE_ASSIGN
$cse91 = cosh(abs(rover_8d.vy_fl))
*/
void RoverExample_Components_Rover_eqFunction_926(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,926};
  jacobian->tmpVars[2] /* $cse91 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */)));
  TRACE_POP
}

/*
equation index: 927
type: SIMPLE_ASSIGN
$cse92 = cosh(abs(rover_8d.vx_fr))
*/
void RoverExample_Components_Rover_eqFunction_927(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,927};
  jacobian->tmpVars[1] /* $cse92 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */)));
  TRACE_POP
}

/*
equation index: 928
type: SIMPLE_ASSIGN
$cse93 = cosh(abs(rover_8d.vy_fr))
*/
void RoverExample_Components_Rover_eqFunction_928(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,928};
  jacobian->tmpVars[0] /* $cse93 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */)));
  TRACE_POP
}

/*
equation index: 929
type: SIMPLE_ASSIGN
$DER.rover_3d.phi.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_929(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,929};
  jacobian->tmpVars[4] /* der(rover_3d.phi.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 930
type: SIMPLE_ASSIGN
$DER.rover_3d.theta.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_930(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,930};
  jacobian->tmpVars[6] /* der(rover_3d.theta.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 931
type: SIMPLE_ASSIGN
$DER.rover_8d.delta.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_931(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,931};
  jacobian->tmpVars[17] /* der(rover_8d.delta.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 932
type: SIMPLE_ASSIGN
$DER.rover_8d.phi.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_932(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,932};
  jacobian->tmpVars[28] /* der(rover_8d.phi.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 933
type: SIMPLE_ASSIGN
$DER.rover_8d.theta.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_933(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,933};
  jacobian->tmpVars[32] /* der(rover_8d.theta.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 934
type: SIMPLE_ASSIGN
$DER.rover_8d.psi.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_934(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,934};
  jacobian->tmpVars[29] /* der(rover_8d.psi.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 935
type: SIMPLE_ASSIGN
psi_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_935(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,935};
  jacobian->resultVars[8] /* psi_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 936
type: SIMPLE_ASSIGN
p_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_936(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,936};
  jacobian->resultVars[6] /* p_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 937
type: SIMPLE_ASSIGN
theta_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_937(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,937};
  jacobian->resultVars[12] /* theta_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 938
type: SIMPLE_ASSIGN
phi_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_938(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,938};
  jacobian->resultVars[7] /* phi_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 939
type: SIMPLE_ASSIGN
vy_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_939(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,939};
  jacobian->resultVars[14] /* vy_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 940
type: SIMPLE_ASSIGN
vx_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_940(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,940};
  jacobian->resultVars[13] /* vx_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 941
type: SIMPLE_ASSIGN
y_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_941(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,941};
  jacobian->resultVars[17] /* y_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 942
type: SIMPLE_ASSIGN
x_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_942(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,942};
  jacobian->resultVars[16] /* x_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 943
type: SIMPLE_ASSIGN
$DER.rover_8d.lambda.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_943(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,943};
  jacobian->tmpVars[22] /* der(rover_8d.lambda.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 944
type: SIMPLE_ASSIGN
$DER.rover_8d.q.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_944(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,944};
  jacobian->tmpVars[30] /* der(rover_8d.q.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 945
type: SIMPLE_ASSIGN
q_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_945(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,945};
  jacobian->resultVars[9] /* q_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 946
type: SIMPLE_ASSIGN
$DER.rover_8d.vz.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_946(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,946};
  jacobian->tmpVars[35] /* der(rover_8d.vz.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 947
type: SIMPLE_ASSIGN
vz_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_947(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,947};
  jacobian->resultVars[15] /* vz_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 948
type: SIMPLE_ASSIGN
$DER.rover_8d.z.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_948(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,948};
  jacobian->tmpVars[38] /* der(rover_8d.z.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 949
type: SIMPLE_ASSIGN
z_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_949(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,949};
  jacobian->resultVars[18] /* z_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 950
type: SIMPLE_ASSIGN
$DER.rover_3d.vz.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_950(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,950};
  jacobian->tmpVars[8] /* der(rover_3d.vz.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 951
type: SIMPLE_ASSIGN
$DER.rover_3d.vy.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_951(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,951};
  jacobian->tmpVars[7] /* der(rover_3d.vy.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 952
type: SIMPLE_ASSIGN
$DER.rover_3d.z.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_952(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,952};
  jacobian->tmpVars[11] /* der(rover_3d.z.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 953
type: SIMPLE_ASSIGN
az_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_953(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,953};
  jacobian->resultVars[2] /* az_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 954
type: SIMPLE_ASSIGN
my_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_954(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,954};
  jacobian->resultVars[4] /* my_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 955
type: SIMPLE_ASSIGN
mx_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_955(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,955};
  jacobian->resultVars[3] /* mx_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 956
type: SIMPLE_ASSIGN
mz_meas.$pDERD.dummyVarD = 0.0
*/
void RoverExample_Components_Rover_eqFunction_956(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,956};
  jacobian->resultVars[5] /* mz_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 957
type: SIMPLE_ASSIGN
$cse13.$pDERD.dummyVarD = if noEvent($cse14 < 0.001) then 0.0 else if noEvent($cse14 > 1.0) then 0.0 else $cse14.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_957(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 32;
  const int equationIndexes[2] = {1,957};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */),0.001);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = 0.0;
  }
  else
  {
    tmp1 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */),1.0);
    tmp3 = (tmp1?0.0:jacobian->tmpVars[44] /* $cse14.$pDERD.dummyVarD JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[43] /* $cse13.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp3;
  TRACE_POP
}

/*
equation index: 958
type: SIMPLE_ASSIGN
r_meas.$pDERD.dummyVarD = 0.5 * gyroatk.l_g * gyroatk.w_d * gyroatk.X_ac * $cse38.$pDERD.dummyVarD / gyroatk.dis_d
*/
void RoverExample_Components_Rover_eqFunction_958(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 33;
  const int equationIndexes[2] = {1,958};
  jacobian->resultVars[10] /* r_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = (0.5) * (((data->simulationInfo->realParameter[33] /* gyroatk.l_g PARAM */)) * (((data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */)) * (((data->simulationInfo->realParameter[21] /* gyroatk.X_ac PARAM */)) * (DIVISION(jacobian->tmpVars[69] /* $cse38.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[27] /* gyroatk.dis_d PARAM */),"gyroatk.dis_d")))));
  TRACE_POP
}

/*
equation index: 959
type: SIMPLE_ASSIGN
$DER.rover_8d.y.$pDERD.dummyVarD = rover_8d.vx * $cse33.$pDERD.dummyVarD + rover_8d.vy * $cse32.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_959(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 34;
  const int equationIndexes[2] = {1,959};
  jacobian->tmpVars[37] /* der(rover_8d.y.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (jacobian->tmpVars[64] /* $cse33.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (jacobian->tmpVars[63] /* $cse32.$pDERD.dummyVarD JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 960
type: SIMPLE_ASSIGN
$DER.rover_8d.x.$pDERD.dummyVarD = rover_8d.vx * $cse32.$pDERD.dummyVarD - rover_8d.vy * $cse33.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_960(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 35;
  const int equationIndexes[2] = {1,960};
  jacobian->tmpVars[36] /* der(rover_8d.x.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (jacobian->tmpVars[63] /* $cse32.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (jacobian->tmpVars[64] /* $cse33.$pDERD.dummyVarD JACOBIAN_TMP_VAR */));
  TRACE_POP
}

/*
equation index: 961
type: SIMPLE_ASSIGN
rover_8d.vs_fr.$pDERD.dummyVarD = rover_8d.vx_rr * $cse21 * $cse21.$pDERD.dummyVarD / sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_961(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 36;
  const int equationIndexes[2] = {1,961};
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp4 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  tmp5 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */);
  tmp6 = (tmp4 * tmp4) + (tmp5 * tmp5);
  if(!(tmp6 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0) was %g should be >= 0", tmp6);
    }
  }
  jacobian->tmpVars[168] /* rover_8d.vs_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION(jacobian->tmpVars[51] /* $cse21.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,sqrt(tmp6),"sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0)")));
  TRACE_POP
}

/*
equation index: 962
type: SIMPLE_ASSIGN
rover_8d.mu_fr.$pDERD.dummyVarD = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fr) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fr) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_fr.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_962(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 37;
  const int equationIndexes[2] = {1,962};
  modelica_boolean tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  tmp7 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */)))),0.0);
  tmp9 = (modelica_boolean)tmp7;
  if(tmp9)
  {
    tmp10 = 0.0;
  }
  else
  {
    tmp8 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp10 = (tmp8?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[168] /* rover_8d.vs_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[160] /* rover_8d.mu_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp10;
  TRACE_POP
}

/*
equation index: 963
type: SIMPLE_ASSIGN
rover_8d.vs_rr.$pDERD.dummyVarD = rover_8d.vx_rr * $cse29 * $cse29.$pDERD.dummyVarD / sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_963(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 38;
  const int equationIndexes[2] = {1,963};
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  tmp11 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  tmp12 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */);
  tmp13 = (tmp11 * tmp11) + (tmp12 * tmp12);
  if(!(tmp13 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0) was %g should be >= 0", tmp13);
    }
  }
  jacobian->tmpVars[170] /* rover_8d.vs_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION(jacobian->tmpVars[59] /* $cse29.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,sqrt(tmp13),"sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0)")));
  TRACE_POP
}

/*
equation index: 964
type: SIMPLE_ASSIGN
rover_8d.mu_rr.$pDERD.dummyVarD = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rr) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rr) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_rr.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_964(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 39;
  const int equationIndexes[2] = {1,964};
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_real tmp17;
  tmp14 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */)))),0.0);
  tmp16 = (modelica_boolean)tmp14;
  if(tmp16)
  {
    tmp17 = 0.0;
  }
  else
  {
    tmp15 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp17 = (tmp15?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[170] /* rover_8d.vs_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[162] /* rover_8d.mu_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp17;
  TRACE_POP
}

/*
equation index: 965
type: SIMPLE_ASSIGN
$cse30.$pDERD.dummyVarD = if noEvent($cse31 < 0.001) then 0.0 else if noEvent($cse31 > 1.0) then 0.0 else $cse31.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_965(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 40;
  const int equationIndexes[2] = {1,965};
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  modelica_boolean tmp20;
  modelica_real tmp21;
  tmp18 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */),0.001);
  tmp20 = (modelica_boolean)tmp18;
  if(tmp20)
  {
    tmp21 = 0.0;
  }
  else
  {
    tmp19 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */),1.0);
    tmp21 = (tmp19?0.0:jacobian->tmpVars[62] /* $cse31.$pDERD.dummyVarD JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[61] /* $cse30.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp21;
  TRACE_POP
}

/*
equation index: 966
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rr.$pDERD.dummyVarD = (-$cse28.$pDERD.dummyVarD) * rover_8d.vy_rr / rover_8d.Lrely - abs(rover_8d.vx_rr) * rover_8d.Lrely * ($cse29.$pDERD.dummyVarD * $cse30 - $cse29 * $cse30.$pDERD.dummyVarD) / (rover_8d.Lrely * $cse30) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_966(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 41;
  const int equationIndexes[2] = {1,966};
  modelica_real tmp22;
  tmp22 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */));
  jacobian->tmpVars[16] /* der(rover_8d.alpha_rr.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[58] /* $cse28.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[59] /* $cse29.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (jacobian->tmpVars[61] /* $cse30.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)),(tmp22 * tmp22),"(rover_8d.Lrely * $cse30) ^ 2.0"))));
  TRACE_POP
}

/*
equation index: 967
type: SIMPLE_ASSIGN
rover_8d.vs_fl.$pDERD.dummyVarD = rover_8d.vx_rl * $cse17 * $cse17.$pDERD.dummyVarD / sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_967(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 42;
  const int equationIndexes[2] = {1,967};
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  tmp23 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  tmp24 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */);
  tmp25 = (tmp23 * tmp23) + (tmp24 * tmp24);
  if(!(tmp25 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0) was %g should be >= 0", tmp25);
    }
  }
  jacobian->tmpVars[167] /* rover_8d.vs_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION(jacobian->tmpVars[47] /* $cse17.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,sqrt(tmp25),"sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0)")));
  TRACE_POP
}

/*
equation index: 968
type: SIMPLE_ASSIGN
rover_8d.mu_fl.$pDERD.dummyVarD = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fl) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fl) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_fl.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_968(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 43;
  const int equationIndexes[2] = {1,968};
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  modelica_real tmp29;
  tmp26 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */)))),0.0);
  tmp28 = (modelica_boolean)tmp26;
  if(tmp28)
  {
    tmp29 = 0.0;
  }
  else
  {
    tmp27 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp29 = (tmp27?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[167] /* rover_8d.vs_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[159] /* rover_8d.mu_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp29;
  TRACE_POP
}

/*
equation index: 969
type: SIMPLE_ASSIGN
rover_8d.vs_rl.$pDERD.dummyVarD = rover_8d.vx_rl * $cse25 * $cse25.$pDERD.dummyVarD / sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_969(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 44;
  const int equationIndexes[2] = {1,969};
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  tmp30 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  tmp31 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */);
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0) was %g should be >= 0", tmp32);
    }
  }
  jacobian->tmpVars[169] /* rover_8d.vs_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION(jacobian->tmpVars[55] /* $cse25.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,sqrt(tmp32),"sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0)")));
  TRACE_POP
}

/*
equation index: 970
type: SIMPLE_ASSIGN
rover_8d.mu_rl.$pDERD.dummyVarD = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rl) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rl) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_rl.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_970(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 45;
  const int equationIndexes[2] = {1,970};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  modelica_boolean tmp35;
  modelica_real tmp36;
  tmp33 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */)))),0.0);
  tmp35 = (modelica_boolean)tmp33;
  if(tmp35)
  {
    tmp36 = 0.0;
  }
  else
  {
    tmp34 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp36 = (tmp34?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[169] /* rover_8d.vs_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[161] /* rover_8d.mu_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp36;
  TRACE_POP
}

/*
equation index: 1015
type: LINEAR

<var>rover_8d.fz_rl.$pDERD.dummyVarD</var>
<var>rover_8d.fz_fl.$pDERD.dummyVarD</var>
<var>rover_8d.fz_fr.$pDERD.dummyVarD</var>
<var>rover_8d.fz_rr.$pDERD.dummyVarD</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_1015(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 46;
  const int equationIndexes[2] = {1,1015};
  /* Linear equation system */
  int retValue;
  double aux_x[4] = { jacobian->tmpVars[141] /* rover_8d.fz_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,jacobian->tmpVars[139] /* rover_8d.fz_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,jacobian->tmpVars[140] /* rover_8d.fz_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,jacobian->tmpVars[142] /* rover_8d.fz_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 1015 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  data->simulationInfo->linearSystemData[2].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 2, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1015};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 1015 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[141] /* rover_8d.fz_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = aux_x[0];
  jacobian->tmpVars[139] /* rover_8d.fz_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = aux_x[1];
  jacobian->tmpVars[140] /* rover_8d.fz_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = aux_x[2];
  jacobian->tmpVars[142] /* rover_8d.fz_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = aux_x[3];

  TRACE_POP
}

/*
equation index: 1016
type: SIMPLE_ASSIGN
ax_meas.$pDERD.dummyVarD = $DER.rover_8d.vx.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_1016(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 47;
  const int equationIndexes[2] = {1,1016};
  jacobian->resultVars[0] /* ax_meas.$pDERD.dummyVarD JACOBIAN_VAR */ = jacobian->tmpVars[33] /* der(rover_8d.vx.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 1017
type: SIMPLE_ASSIGN
$DER.rover_8d.p.$pDERD.dummyVarD = rover_8d.mass_sprung * (9.80665 * $cse36.$pDERD.dummyVarD + (-rover_8d.ay) * $cse37.$pDERD.dummyVarD - ay_meas.$pDERD.dummyVarD * $cse37) * rover_8d.hs / rover_8d.I_xx
*/
void RoverExample_Components_Rover_eqFunction_1017(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 48;
  const int equationIndexes[2] = {1,1017};
  jacobian->tmpVars[27] /* der(rover_8d.p.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((9.80665) * (jacobian->tmpVars[67] /* $cse36.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */))) * (jacobian->tmpVars[68] /* $cse37.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) - ((jacobian->resultVars[1] /* ay_meas.$pDERD.dummyVarD JACOBIAN_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* $cse37 variable */)))) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[65] /* rover_8d.I_xx PARAM */),"rover_8d.I_xx")));
  TRACE_POP
}

/*
equation index: 1018
type: SIMPLE_ASSIGN
rollover_detected.$pDERD.dummyVarD = (*Real*)(rover_8d.rollover_detected.$pDERD.dummyVarD)
*/
void RoverExample_Components_Rover_eqFunction_1018(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 49;
  const int equationIndexes[2] = {1,1018};
  jacobian->resultVars[11] /* rollover_detected.$pDERD.dummyVarD JACOBIAN_VAR */ = ((modelica_real)jacobian->tmpVars[190] /* rover_8d.rollover_detected.$pDERD.dummyVarD JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 1019
type: SIMPLE_ASSIGN
$DER.rover_8d.r.$pDERD.dummyVarD = (0.5 * (rover_8d.Fx_fl * $cse34.$pDERD.dummyVarD + rover_8d.Fx_fl.$pDERD.dummyVarD * $cse34 + rover_8d.Fy_fl * $cse35.$pDERD.dummyVarD + rover_8d.Fy_fl.$pDERD.dummyVarD * $cse35 + rover_8d.Fx_rl.$pDERD.dummyVarD + (-rover_8d.Fx_fr) * $cse34.$pDERD.dummyVarD - rover_8d.Fx_fr.$pDERD.dummyVarD * $cse34 - rover_8d.Fy_fr.$pDERD.dummyVarD * $cse35 - rover_8d.Fy_fr * $cse35.$pDERD.dummyVarD - rover_8d.Fx_rr.$pDERD.dummyVarD) * rover_8d.tw + rover_8d.l_front * (rover_8d.Fy_fl * $cse34.$pDERD.dummyVarD + rover_8d.Fy_fl.$pDERD.dummyVarD * $cse34 + (-rover_8d.Fx_fl) * $cse35.$pDERD.dummyVarD - rover_8d.Fx_fl.$pDERD.dummyVarD * $cse35) + rover_8d.l_front * (rover_8d.Fy_fr * $cse34.$pDERD.dummyVarD + rover_8d.Fy_fr.$pDERD.dummyVarD * $cse34 + (-rover_8d.Fx_fr) * $cse35.$pDERD.dummyVarD - rover_8d.Fx_fr.$pDERD.dummyVarD * $cse35) - rover_8d.l_rear * (rover_8d.Fy_rl.$pDERD.dummyVarD + rover_8d.Fy_rr.$pDERD.dummyVarD)) / rover_8d.I_zz
*/
void RoverExample_Components_Rover_eqFunction_1019(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 50;
  const int equationIndexes[2] = {1,1019};
  jacobian->tmpVars[31] /* der(rover_8d.r.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = DIVISION((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * (jacobian->tmpVars[65] /* $cse34.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[112] /* rover_8d.Fx_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (jacobian->tmpVars[66] /* $cse35.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[116] /* rover_8d.Fy_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + jacobian->tmpVars[114] /* rover_8d.Fx_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))) * (jacobian->tmpVars[65] /* $cse34.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[113] /* rover_8d.Fx_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */))) - ((jacobian->tmpVars[117] /* rover_8d.Fy_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (jacobian->tmpVars[66] /* $cse35.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)) - jacobian->tmpVars[115] /* rover_8d.Fx_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (jacobian->tmpVars[65] /* $cse34.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[116] /* rover_8d.Fy_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */))) * (jacobian->tmpVars[66] /* $cse35.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[112] /* rover_8d.Fx_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (jacobian->tmpVars[65] /* $cse34.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[117] /* rover_8d.Fy_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))) * (jacobian->tmpVars[66] /* $cse35.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[113] /* rover_8d.Fx_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) - (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (jacobian->tmpVars[118] /* rover_8d.Fy_rl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ + jacobian->tmpVars[119] /* rover_8d.Fy_rr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[66] /* rover_8d.I_zz PARAM */),"rover_8d.I_zz");
  TRACE_POP
}

/*
equation index: 1020
type: SIMPLE_ASSIGN
$DER.rover_8d.vy.$pDERD.dummyVarD = ay_meas.$pDERD.dummyVarD + (rover_8d.l_rear * rover_8d.mass_unsprung_rear - rover_8d.l_front * rover_8d.mass_unsprung_front) * $DER.rover_8d.r.$pDERD.dummyVarD / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_1020(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 51;
  const int equationIndexes[2] = {1,1020};
  jacobian->tmpVars[34] /* der(rover_8d.vy.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = jacobian->resultVars[1] /* ay_meas.$pDERD.dummyVarD JACOBIAN_VAR */ + (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) - (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)))) * (DIVISION(jacobian->tmpVars[31] /* der(rover_8d.r.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total"));
  TRACE_POP
}

/*
equation index: 1021
type: SIMPLE_ASSIGN
$cse26.$pDERD.dummyVarD = if noEvent($cse27 < 0.001) then 0.0 else if noEvent($cse27 > 1.0) then 0.0 else $cse27.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_1021(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 52;
  const int equationIndexes[2] = {1,1021};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  modelica_boolean tmp39;
  modelica_real tmp40;
  tmp37 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */),0.001);
  tmp39 = (modelica_boolean)tmp37;
  if(tmp39)
  {
    tmp40 = 0.0;
  }
  else
  {
    tmp38 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */),1.0);
    tmp40 = (tmp38?0.0:jacobian->tmpVars[57] /* $cse27.$pDERD.dummyVarD JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[56] /* $cse26.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp40;
  TRACE_POP
}

/*
equation index: 1022
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rl.$pDERD.dummyVarD = abs(rover_8d.vx_rl) * ($cse25 * $cse26.$pDERD.dummyVarD * rover_8d.Lrely - $cse25.$pDERD.dummyVarD * $cse26 * rover_8d.Lrely) / ($cse26 * rover_8d.Lrely) ^ 2.0 - $cse28.$pDERD.dummyVarD * rover_8d.vy_rr / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_1022(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 53;
  const int equationIndexes[2] = {1,1022};
  modelica_real tmp41;
  tmp41 = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */));
  jacobian->tmpVars[15] /* der(rover_8d.alpha_rl.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = (fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */))) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * ((jacobian->tmpVars[56] /* $cse26.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */))) - ((jacobian->tmpVars[55] /* $cse25.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)))),(tmp41 * tmp41),"($cse26 * rover_8d.Lrely) ^ 2.0")) - ((jacobian->tmpVars[58] /* $cse28.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")));
  TRACE_POP
}

/*
equation index: 1023
type: SIMPLE_ASSIGN
rover_8d.vy_fr.$pDERD.dummyVarD = $cse15.$pDERD.dummyVarD * (rover_8d.vy + rover_8d.l_front * rover_8d.r) - $cse16.$pDERD.dummyVarD * rover_8d.vx_rr
*/
void RoverExample_Components_Rover_eqFunction_1023(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 54;
  const int equationIndexes[2] = {1,1023};
  jacobian->tmpVars[176] /* rover_8d.vy_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[45] /* $cse15.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - ((jacobian->tmpVars[46] /* $cse16.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)));
  TRACE_POP
}

/*
equation index: 1024
type: SIMPLE_ASSIGN
$cse24.$pDERD.dummyVarD = sign(rover_8d.vy_fr) * rover_8d.vy_fr.$pDERD.dummyVarD / $cse93 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_1024(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 55;
  const int equationIndexes[2] = {1,1024};
  modelica_real tmp42;
  tmp42 = jacobian->tmpVars[0] /* $cse93 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[54] /* $cse24.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */))) * (DIVISION(jacobian->tmpVars[176] /* rover_8d.vy_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(tmp42 * tmp42),"$cse93 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 1025
type: SIMPLE_ASSIGN
rover_8d.vx_fr.$pDERD.dummyVarD = $cse15.$pDERD.dummyVarD * rover_8d.vx_rr + $cse16.$pDERD.dummyVarD * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_1025(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 56;
  const int equationIndexes[2] = {1,1025};
  jacobian->tmpVars[172] /* rover_8d.vx_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[45] /* $cse15.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) + (jacobian->tmpVars[46] /* $cse16.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 1026
type: SIMPLE_ASSIGN
$cse23.$pDERD.dummyVarD = sign(rover_8d.vx_fr) * rover_8d.vx_fr.$pDERD.dummyVarD / $cse92 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_1026(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 57;
  const int equationIndexes[2] = {1,1026};
  modelica_real tmp43;
  tmp43 = jacobian->tmpVars[1] /* $cse92 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[53] /* $cse23.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * (DIVISION(jacobian->tmpVars[172] /* rover_8d.vx_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(tmp43 * tmp43),"$cse92 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 1027
type: SIMPLE_ASSIGN
$cse22.$pDERD.dummyVarD = if noEvent($cse23 < 0.001) then 0.0 else if noEvent($cse23 > 1.0) then 0.0 else $cse23.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_1027(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 58;
  const int equationIndexes[2] = {1,1027};
  modelica_boolean tmp44;
  modelica_boolean tmp45;
  modelica_boolean tmp46;
  modelica_real tmp47;
  tmp44 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */),0.001);
  tmp46 = (modelica_boolean)tmp44;
  if(tmp46)
  {
    tmp47 = 0.0;
  }
  else
  {
    tmp45 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */),1.0);
    tmp47 = (tmp45?0.0:jacobian->tmpVars[53] /* $cse23.$pDERD.dummyVarD JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[52] /* $cse22.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp47;
  TRACE_POP
}

/*
equation index: 1028
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fr.$pDERD.dummyVarD = (-$cse24) * rover_8d.vy_fr.$pDERD.dummyVarD / rover_8d.Lrely - $cse24.$pDERD.dummyVarD * rover_8d.vy_fr / rover_8d.Lrely - abs(rover_8d.vx_fr) * rover_8d.Lrely * ($cse21.$pDERD.dummyVarD * $cse22 - $cse21 * $cse22.$pDERD.dummyVarD) / (rover_8d.Lrely * $cse22) ^ 2.0 - sign(rover_8d.vx_fr) * rover_8d.vx_fr.$pDERD.dummyVarD * $cse21 / ($cse22 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_1028(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 59;
  const int equationIndexes[2] = {1,1028};
  modelica_real tmp48;
  tmp48 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */));
  jacobian->tmpVars[14] /* der(rover_8d.alpha_fr.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* $cse24 variable */))) * (DIVISION(jacobian->tmpVars[176] /* rover_8d.vy_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[54] /* $cse24.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[51] /* $cse21.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (jacobian->tmpVars[52] /* $cse22.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)),(tmp48 * tmp48),"(rover_8d.Lrely * $cse22) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * ((jacobian->tmpVars[172] /* rover_8d.vx_fr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse22 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 1029
type: SIMPLE_ASSIGN
rover_8d.vy_fl.$pDERD.dummyVarD = $cse15.$pDERD.dummyVarD * (rover_8d.vy + rover_8d.l_front * rover_8d.r) - $cse16.$pDERD.dummyVarD * rover_8d.vx_rl
*/
void RoverExample_Components_Rover_eqFunction_1029(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 60;
  const int equationIndexes[2] = {1,1029};
  jacobian->tmpVars[175] /* rover_8d.vy_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[45] /* $cse15.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - ((jacobian->tmpVars[46] /* $cse16.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)));
  TRACE_POP
}

/*
equation index: 1030
type: SIMPLE_ASSIGN
$cse20.$pDERD.dummyVarD = sign(rover_8d.vy_fl) * rover_8d.vy_fl.$pDERD.dummyVarD / $cse91 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_1030(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 61;
  const int equationIndexes[2] = {1,1030};
  modelica_real tmp49;
  tmp49 = jacobian->tmpVars[2] /* $cse91 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[50] /* $cse20.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */))) * (DIVISION(jacobian->tmpVars[175] /* rover_8d.vy_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(tmp49 * tmp49),"$cse91 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 1031
type: SIMPLE_ASSIGN
rover_8d.vx_fl.$pDERD.dummyVarD = $cse15.$pDERD.dummyVarD * rover_8d.vx_rl + $cse16.$pDERD.dummyVarD * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_1031(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 62;
  const int equationIndexes[2] = {1,1031};
  jacobian->tmpVars[171] /* rover_8d.vx_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[45] /* $cse15.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) + (jacobian->tmpVars[46] /* $cse16.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 1032
type: SIMPLE_ASSIGN
$cse19.$pDERD.dummyVarD = sign(rover_8d.vx_fl) * rover_8d.vx_fl.$pDERD.dummyVarD / $cse90 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_1032(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 63;
  const int equationIndexes[2] = {1,1032};
  modelica_real tmp50;
  tmp50 = jacobian->tmpVars[3] /* $cse90 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[49] /* $cse19.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * (DIVISION(jacobian->tmpVars[171] /* rover_8d.vx_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(tmp50 * tmp50),"$cse90 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 1033
type: SIMPLE_ASSIGN
$cse18.$pDERD.dummyVarD = if noEvent($cse19 < 0.001) then 0.0 else if noEvent($cse19 > 1.0) then 0.0 else $cse19.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_1033(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 64;
  const int equationIndexes[2] = {1,1033};
  modelica_boolean tmp51;
  modelica_boolean tmp52;
  modelica_boolean tmp53;
  modelica_real tmp54;
  tmp51 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */),0.001);
  tmp53 = (modelica_boolean)tmp51;
  if(tmp53)
  {
    tmp54 = 0.0;
  }
  else
  {
    tmp52 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */),1.0);
    tmp54 = (tmp52?0.0:jacobian->tmpVars[49] /* $cse19.$pDERD.dummyVarD JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[48] /* $cse18.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = tmp54;
  TRACE_POP
}

/*
equation index: 1034
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fl.$pDERD.dummyVarD = (-$cse20) * rover_8d.vy_fl.$pDERD.dummyVarD / rover_8d.Lrely - $cse20.$pDERD.dummyVarD * rover_8d.vy_fl / rover_8d.Lrely - abs(rover_8d.vx_fl) * rover_8d.Lrely * ($cse17.$pDERD.dummyVarD * $cse18 - $cse17 * $cse18.$pDERD.dummyVarD) / (rover_8d.Lrely * $cse18) ^ 2.0 - sign(rover_8d.vx_fl) * rover_8d.vx_fl.$pDERD.dummyVarD * $cse17 / ($cse18 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_1034(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 65;
  const int equationIndexes[2] = {1,1034};
  modelica_real tmp55;
  tmp55 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */));
  jacobian->tmpVars[13] /* der(rover_8d.alpha_fl.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* $cse20 variable */))) * (DIVISION(jacobian->tmpVars[175] /* rover_8d.vy_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[50] /* $cse20.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[47] /* $cse17.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (jacobian->tmpVars[48] /* $cse18.$pDERD.dummyVarD JACOBIAN_TMP_VAR */)),(tmp55 * tmp55),"(rover_8d.Lrely * $cse18) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * ((jacobian->tmpVars[171] /* rover_8d.vx_fl.$pDERD.dummyVarD JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse18 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 1035
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rr.$pDERD.dummyVarD = (-abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r)) * (-rover_8d.kappa_rr) * rover_8d.Lrelx * $cse13.$pDERD.dummyVarD / (rover_8d.Lrelx * $cse13) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_1035(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 66;
  const int equationIndexes[2] = {1,1035};
  modelica_real tmp56;
  tmp56 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->tmpVars[21] /* der(rover_8d.kappa_rr.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))))) * (((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION(jacobian->tmpVars[43] /* $cse13.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(tmp56 * tmp56),"(rover_8d.Lrelx * $cse13) ^ 2.0"))));
  TRACE_POP
}

/*
equation index: 1036
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rl.$pDERD.dummyVarD = (-abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r)) * (-rover_8d.kappa_rl) * rover_8d.Lrelx * $cse13.$pDERD.dummyVarD / (rover_8d.Lrelx * $cse13) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_1036(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 67;
  const int equationIndexes[2] = {1,1036};
  modelica_real tmp57;
  tmp57 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->tmpVars[20] /* der(rover_8d.kappa_rl.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION(jacobian->tmpVars[43] /* $cse13.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(tmp57 * tmp57),"(rover_8d.Lrelx * $cse13) ^ 2.0"))));
  TRACE_POP
}

/*
equation index: 1037
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fr.$pDERD.dummyVarD = (-abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r)) * (-rover_8d.kappa_fr) * rover_8d.Lrelx * $cse13.$pDERD.dummyVarD / (rover_8d.Lrelx * $cse13) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_1037(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 68;
  const int equationIndexes[2] = {1,1037};
  modelica_real tmp58;
  tmp58 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->tmpVars[19] /* der(rover_8d.kappa_fr.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))))) * (((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION(jacobian->tmpVars[43] /* $cse13.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(tmp58 * tmp58),"(rover_8d.Lrelx * $cse13) ^ 2.0"))));
  TRACE_POP
}

/*
equation index: 1038
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fl.$pDERD.dummyVarD = (-abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r)) * (-rover_8d.kappa_fl) * rover_8d.Lrelx * $cse13.$pDERD.dummyVarD / (rover_8d.Lrelx * $cse13) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_1038(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 69;
  const int equationIndexes[2] = {1,1038};
  modelica_real tmp59;
  tmp59 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->tmpVars[18] /* der(rover_8d.kappa_fl.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION(jacobian->tmpVars[43] /* $cse13.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(tmp59 * tmp59),"(rover_8d.Lrelx * $cse13) ^ 2.0"))));
  TRACE_POP
}

/*
equation index: 1051
type: LINEAR

<var>rover_8d.thr.$pDERD.dummyVarD</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_1051(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 70;
  const int equationIndexes[2] = {1,1051};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { jacobian->tmpVars[166] /* rover_8d.thr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 1051 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  data->simulationInfo->linearSystemData[3].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 3, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1051};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 1051 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[166] /* rover_8d.thr.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = aux_x[0];

  TRACE_POP
}

/*
equation index: 1052
type: SIMPLE_ASSIGN
rover_8d.Vq.$pDERD.dummyVarD = 1.224744871391589 * rover_8d.Vs * $cse12.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_1052(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 71;
  const int equationIndexes[2] = {1,1052};
  jacobian->tmpVars[126] /* rover_8d.Vq.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = (1.224744871391589) * (((data->simulationInfo->realParameter[78] /* rover_8d.Vs PARAM */)) * (jacobian->tmpVars[42] /* $cse12.$pDERD.dummyVarD JACOBIAN_TMP_VAR */));
  TRACE_POP
}

/*
equation index: 1053
type: SIMPLE_ASSIGN
$DER.rover_8d.Iq.$pDERD.dummyVarD = rover_8d.Vq.$pDERD.dummyVarD / rover_8d.Le
*/
void RoverExample_Components_Rover_eqFunction_1053(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 72;
  const int equationIndexes[2] = {1,1053};
  jacobian->tmpVars[12] /* der(rover_8d.Iq.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->tmpVars[126] /* rover_8d.Vq.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[72] /* rover_8d.Le PARAM */),"rover_8d.Le");
  TRACE_POP
}

/*
equation index: 1054
type: SIMPLE_ASSIGN
$DER.rover_3d.x.$pDERD.dummyVarD = rover_3d.vx * $cse3.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_1054(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 73;
  const int equationIndexes[2] = {1,1054};
  jacobian->tmpVars[9] /* der(rover_3d.x.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (jacobian->tmpVars[60] /* $cse3.$pDERD.dummyVarD JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 1055
type: SIMPLE_ASSIGN
$DER.rover_3d.y.$pDERD.dummyVarD = rover_3d.vx * $cse4.$pDERD.dummyVarD
*/
void RoverExample_Components_Rover_eqFunction_1055(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 74;
  const int equationIndexes[2] = {1,1055};
  jacobian->tmpVars[10] /* der(rover_3d.y.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (jacobian->tmpVars[70] /* $cse4.$pDERD.dummyVarD JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 1056
type: SIMPLE_ASSIGN
$DER.rover_3d.psi.$pDERD.dummyVarD = rover_3d.vx * $cse6.$pDERD.dummyVarD / rover_3d.l_total
*/
void RoverExample_Components_Rover_eqFunction_1056(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 75;
  const int equationIndexes[2] = {1,1056};
  jacobian->tmpVars[5] /* der(rover_3d.psi.$pDERD.dummyVarD) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (DIVISION(jacobian->tmpVars[72] /* $cse6.$pDERD.dummyVarD JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[55] /* rover_3d.l_total PARAM */),"rover_3d.l_total"));
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacD_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_D;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_D;
  RoverExample_Components_Rover_eqFunction_925(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_926(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_927(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_928(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_929(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_930(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_931(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_932(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_933(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_934(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_935(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_936(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_937(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_938(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_939(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_940(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_941(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_942(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_943(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_944(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_945(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_946(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_947(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_948(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_949(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_950(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_951(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_952(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_953(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_954(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_955(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_956(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_957(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_958(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_959(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_960(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_961(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_962(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_963(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_964(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_965(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_966(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_967(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_968(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_969(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_970(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1015(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1016(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1017(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1018(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1019(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1020(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1021(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1022(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1023(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1024(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1025(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1026(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1027(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1028(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1029(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1030(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1031(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1032(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1033(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1034(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1035(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1036(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1037(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1038(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1051(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1052(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1053(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1054(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1055(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1056(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 735
type: SIMPLE_ASSIGN
$cse68 = sin(rover_3d.psi)
*/
void RoverExample_Components_Rover_eqFunction_735(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,735};
  jacobian->tmpVars[21] /* $cse68 JACOBIAN_TMP_VAR */ = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */));
  TRACE_POP
}

/*
equation index: 736
type: SIMPLE_ASSIGN
$cse69 = cos(rover_3d.psi)
*/
void RoverExample_Components_Rover_eqFunction_736(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,736};
  jacobian->tmpVars[20] /* $cse69 JACOBIAN_TMP_VAR */ = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */));
  TRACE_POP
}

/*
equation index: 737
type: SIMPLE_ASSIGN
$cse70 = cosh(abs(rover_8d.vx))
*/
void RoverExample_Components_Rover_eqFunction_737(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,737};
  jacobian->tmpVars[19] /* $cse70 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)));
  TRACE_POP
}

/*
equation index: 738
type: SIMPLE_ASSIGN
$cse71 = sin(rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_738(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,738};
  jacobian->tmpVars[18] /* $cse71 JACOBIAN_TMP_VAR */ = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */));
  TRACE_POP
}

/*
equation index: 739
type: SIMPLE_ASSIGN
$cse72 = cos(rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_739(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,739};
  jacobian->tmpVars[17] /* $cse72 JACOBIAN_TMP_VAR */ = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */));
  TRACE_POP
}

/*
equation index: 740
type: SIMPLE_ASSIGN
$cse73 = cos(2.0 * rover_8d.alpha_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_740(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,740};
  jacobian->tmpVars[16] /* $cse73 JACOBIAN_TMP_VAR */ = cos((2.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[178]] /* rover_8d.alpha_fl_bnd variable */)));
  TRACE_POP
}

/*
equation index: 741
type: SIMPLE_ASSIGN
$cse74 = cos(2.0 * rover_8d.alpha_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_741(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,741};
  jacobian->tmpVars[15] /* $cse74 JACOBIAN_TMP_VAR */ = cos((2.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* rover_8d.alpha_fr_bnd variable */)));
  TRACE_POP
}

/*
equation index: 742
type: SIMPLE_ASSIGN
$cse75 = cos(2.0 * rover_8d.alpha_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_742(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,742};
  jacobian->tmpVars[14] /* $cse75 JACOBIAN_TMP_VAR */ = cos((2.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[180]] /* rover_8d.alpha_rl_bnd variable */)));
  TRACE_POP
}

/*
equation index: 743
type: SIMPLE_ASSIGN
$cse76 = cos(2.0 * rover_8d.alpha_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_743(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,743};
  jacobian->tmpVars[13] /* $cse76 JACOBIAN_TMP_VAR */ = cos((2.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[181]] /* rover_8d.alpha_rr_bnd variable */)));
  TRACE_POP
}

/*
equation index: 744
type: SIMPLE_ASSIGN
$cse77 = sin(rover_8d.psi)
*/
void RoverExample_Components_Rover_eqFunction_744(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,744};
  jacobian->tmpVars[12] /* $cse77 JACOBIAN_TMP_VAR */ = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  TRACE_POP
}

/*
equation index: 745
type: SIMPLE_ASSIGN
$cse78 = cos(rover_8d.psi)
*/
void RoverExample_Components_Rover_eqFunction_745(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,745};
  jacobian->tmpVars[11] /* $cse78 JACOBIAN_TMP_VAR */ = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  TRACE_POP
}

/*
equation index: 746
type: SIMPLE_ASSIGN
$cse79 = sin(-rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_746(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,746};
  jacobian->tmpVars[10] /* $cse79 JACOBIAN_TMP_VAR */ = sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)));
  TRACE_POP
}

/*
equation index: 747
type: SIMPLE_ASSIGN
$cse80 = cos(-rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_747(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,747};
  jacobian->tmpVars[9] /* $cse80 JACOBIAN_TMP_VAR */ = cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)));
  TRACE_POP
}

/*
equation index: 748
type: SIMPLE_ASSIGN
$cse81 = cos(rover_8d.phi)
*/
void RoverExample_Components_Rover_eqFunction_748(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,748};
  jacobian->tmpVars[8] /* $cse81 JACOBIAN_TMP_VAR */ = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */));
  TRACE_POP
}

/*
equation index: 749
type: SIMPLE_ASSIGN
$cse82 = sin(rover_8d.phi)
*/
void RoverExample_Components_Rover_eqFunction_749(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,749};
  jacobian->tmpVars[7] /* $cse82 JACOBIAN_TMP_VAR */ = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */));
  TRACE_POP
}

/*
equation index: 750
type: SIMPLE_ASSIGN
$cse83 = cosh(abs(rover_8d.vx_rr))
*/
void RoverExample_Components_Rover_eqFunction_750(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,750};
  jacobian->tmpVars[6] /* $cse83 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)));
  TRACE_POP
}

/*
equation index: 751
type: SIMPLE_ASSIGN
$cse84 = cosh(abs(rover_8d.vy_rr))
*/
void RoverExample_Components_Rover_eqFunction_751(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,751};
  jacobian->tmpVars[5] /* $cse84 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */)));
  TRACE_POP
}

/*
equation index: 752
type: SIMPLE_ASSIGN
$cse85 = cosh(abs(rover_8d.vx_rl))
*/
void RoverExample_Components_Rover_eqFunction_752(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,752};
  jacobian->tmpVars[4] /* $cse85 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)));
  TRACE_POP
}

/*
equation index: 753
type: SIMPLE_ASSIGN
$cse86 = cosh(abs(rover_8d.vy_fr))
*/
void RoverExample_Components_Rover_eqFunction_753(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,753};
  jacobian->tmpVars[3] /* $cse86 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */)));
  TRACE_POP
}

/*
equation index: 754
type: SIMPLE_ASSIGN
$cse87 = cosh(abs(rover_8d.vx_fr))
*/
void RoverExample_Components_Rover_eqFunction_754(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,754};
  jacobian->tmpVars[2] /* $cse87 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */)));
  TRACE_POP
}

/*
equation index: 755
type: SIMPLE_ASSIGN
$cse88 = cosh(abs(rover_8d.vy_fl))
*/
void RoverExample_Components_Rover_eqFunction_755(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,755};
  jacobian->tmpVars[1] /* $cse88 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */)));
  TRACE_POP
}

/*
equation index: 756
type: SIMPLE_ASSIGN
$cse89 = cosh(abs(rover_8d.vx_fl))
*/
void RoverExample_Components_Rover_eqFunction_756(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,756};
  jacobian->tmpVars[0] /* $cse89 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */)));
  TRACE_POP
}

/*
equation index: 757
type: SIMPLE_ASSIGN
$DER.rover_3d.phi.$pDERC.dummyVarC = 0.0
*/
void RoverExample_Components_Rover_eqFunction_757(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,757};
  jacobian->tmpVars[22] /* der(rover_3d.phi.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 758
type: SIMPLE_ASSIGN
$DER.rover_3d.theta.$pDERC.dummyVarC = 0.0
*/
void RoverExample_Components_Rover_eqFunction_758(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,758};
  jacobian->tmpVars[24] /* der(rover_3d.theta.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 759
type: SIMPLE_ASSIGN
$DER.rover_8d.phi.$pDERC.dummyVarC = rover_8d.p.SeedC
*/
void RoverExample_Components_Rover_eqFunction_759(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,759};
  jacobian->tmpVars[46] /* der(rover_8d.phi.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = jacobian->seedVars[23] /* rover_8d.p.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 760
type: SIMPLE_ASSIGN
$DER.rover_8d.theta.$pDERC.dummyVarC = 0.0
*/
void RoverExample_Components_Rover_eqFunction_760(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,760};
  jacobian->tmpVars[50] /* der(rover_8d.theta.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 761
type: SIMPLE_ASSIGN
$DER.rover_8d.psi.$pDERC.dummyVarC = rover_8d.r.SeedC
*/
void RoverExample_Components_Rover_eqFunction_761(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,761};
  jacobian->tmpVars[47] /* der(rover_8d.psi.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 762
type: SIMPLE_ASSIGN
psi_meas.$pDERC.dummyVarC = rover_8d.psi.SeedC
*/
void RoverExample_Components_Rover_eqFunction_762(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,762};
  jacobian->resultVars[8] /* psi_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[25] /* rover_8d.psi.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 763
type: SIMPLE_ASSIGN
p_meas.$pDERC.dummyVarC = rover_8d.p.SeedC
*/
void RoverExample_Components_Rover_eqFunction_763(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,763};
  jacobian->resultVars[6] /* p_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[23] /* rover_8d.p.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 764
type: SIMPLE_ASSIGN
theta_meas.$pDERC.dummyVarC = rover_8d.theta.SeedC
*/
void RoverExample_Components_Rover_eqFunction_764(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,764};
  jacobian->resultVars[12] /* theta_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[28] /* rover_8d.theta.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 765
type: SIMPLE_ASSIGN
phi_meas.$pDERC.dummyVarC = rover_8d.phi.SeedC
*/
void RoverExample_Components_Rover_eqFunction_765(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,765};
  jacobian->resultVars[7] /* phi_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[24] /* rover_8d.phi.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 766
type: SIMPLE_ASSIGN
vy_meas.$pDERC.dummyVarC = rover_8d.vy.SeedC
*/
void RoverExample_Components_Rover_eqFunction_766(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,766};
  jacobian->resultVars[14] /* vy_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[30] /* rover_8d.vy.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 767
type: SIMPLE_ASSIGN
vx_meas.$pDERC.dummyVarC = rover_8d.vx.SeedC
*/
void RoverExample_Components_Rover_eqFunction_767(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 32;
  const int equationIndexes[2] = {1,767};
  jacobian->resultVars[13] /* vx_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 768
type: SIMPLE_ASSIGN
y_meas.$pDERC.dummyVarC = rover_8d.y.SeedC
*/
void RoverExample_Components_Rover_eqFunction_768(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 33;
  const int equationIndexes[2] = {1,768};
  jacobian->resultVars[17] /* y_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[33] /* rover_8d.y.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 769
type: SIMPLE_ASSIGN
x_meas.$pDERC.dummyVarC = rover_8d.x.SeedC
*/
void RoverExample_Components_Rover_eqFunction_769(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 34;
  const int equationIndexes[2] = {1,769};
  jacobian->resultVars[16] /* x_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[32] /* rover_8d.x.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 770
type: SIMPLE_ASSIGN
$DER.rover_8d.q.$pDERC.dummyVarC = 0.0
*/
void RoverExample_Components_Rover_eqFunction_770(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 35;
  const int equationIndexes[2] = {1,770};
  jacobian->tmpVars[48] /* der(rover_8d.q.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 771
type: SIMPLE_ASSIGN
q_meas.$pDERC.dummyVarC = rover_8d.q.SeedC
*/
void RoverExample_Components_Rover_eqFunction_771(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 36;
  const int equationIndexes[2] = {1,771};
  jacobian->resultVars[9] /* q_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[26] /* rover_8d.q.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 772
type: SIMPLE_ASSIGN
$DER.rover_8d.vz.$pDERC.dummyVarC = 0.0
*/
void RoverExample_Components_Rover_eqFunction_772(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 37;
  const int equationIndexes[2] = {1,772};
  jacobian->tmpVars[53] /* der(rover_8d.vz.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 773
type: SIMPLE_ASSIGN
vz_meas.$pDERC.dummyVarC = rover_8d.vz.SeedC
*/
void RoverExample_Components_Rover_eqFunction_773(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 38;
  const int equationIndexes[2] = {1,773};
  jacobian->resultVars[15] /* vz_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[31] /* rover_8d.vz.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 774
type: SIMPLE_ASSIGN
$DER.rover_8d.z.$pDERC.dummyVarC = 0.0
*/
void RoverExample_Components_Rover_eqFunction_774(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 39;
  const int equationIndexes[2] = {1,774};
  jacobian->tmpVars[56] /* der(rover_8d.z.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 775
type: SIMPLE_ASSIGN
z_meas.$pDERC.dummyVarC = rover_8d.z.SeedC
*/
void RoverExample_Components_Rover_eqFunction_775(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 40;
  const int equationIndexes[2] = {1,775};
  jacobian->resultVars[18] /* z_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[34] /* rover_8d.z.SeedC SEED_VAR */;
  TRACE_POP
}

/*
equation index: 776
type: SIMPLE_ASSIGN
$DER.rover_3d.vz.$pDERC.dummyVarC = 0.0
*/
void RoverExample_Components_Rover_eqFunction_776(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 41;
  const int equationIndexes[2] = {1,776};
  jacobian->tmpVars[26] /* der(rover_3d.vz.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 777
type: SIMPLE_ASSIGN
$DER.rover_3d.vy.$pDERC.dummyVarC = 0.0
*/
void RoverExample_Components_Rover_eqFunction_777(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 42;
  const int equationIndexes[2] = {1,777};
  jacobian->tmpVars[25] /* der(rover_3d.vy.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 778
type: SIMPLE_ASSIGN
$DER.rover_3d.z.$pDERC.dummyVarC = 0.0
*/
void RoverExample_Components_Rover_eqFunction_778(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 43;
  const int equationIndexes[2] = {1,778};
  jacobian->tmpVars[29] /* der(rover_3d.z.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 779
type: SIMPLE_ASSIGN
$DER.rover_3d.psi.$pDERC.dummyVarC = rover_3d.vx * $cse6.$pDERC.dummyVarC / rover_3d.l_total
*/
void RoverExample_Components_Rover_eqFunction_779(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 44;
  const int equationIndexes[2] = {1,779};
  jacobian->tmpVars[23] /* der(rover_3d.psi.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (DIVISION(jacobian->tmpVars[90] /* $cse6.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[55] /* rover_3d.l_total PARAM */),"rover_3d.l_total"));
  TRACE_POP
}

/*
equation index: 780
type: ARRAY_CALL_ASSIGN

rover_8d.mag.C_n2b.$pDERC.dummyVarC = transpose($DER$RoverExample$PUtils$Peul2rot({rover_8d.phi, rover_8d.theta, rover_8d.psi}, {1.0, 0.0, 0.0}) * rover_8d.phi.SeedC + $DER$RoverExample$PUtils$Peul2rot({rover_8d.phi, rover_8d.theta, rover_8d.psi}, {0.0, 1.0, 0.0}) * rover_8d.theta.SeedC + $DER$RoverExample$PUtils$Peul2rot({rover_8d.phi, rover_8d.theta, rover_8d.psi}, {0.0, 0.0, 1.0}) * rover_8d.psi.SeedC)
*/
void RoverExample_Components_Rover_eqFunction_780(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 45;
  const int equationIndexes[2] = {1,780};
  real_array tmp60;
  real_array tmp61;
  real_array tmp62;
  real_array tmp63;
  real_array tmp64;
  real_array tmp65;
  real_array tmp66;
  real_array tmp67;
  real_array tmp68;
  array_alloc_scalar_real_array(&tmp60, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  array_alloc_scalar_real_array(&tmp61, 3, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp62, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  array_alloc_scalar_real_array(&tmp63, 3, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp64, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  array_alloc_scalar_real_array(&tmp65, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  tmp66 = add_alloc_real_array(add_alloc_real_array(mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData, tmp60, tmp61), jacobian->seedVars[24] /* rover_8d.phi.SeedC SEED_VAR */), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData, tmp62, tmp63), jacobian->seedVars[28] /* rover_8d.theta.SeedC SEED_VAR */)), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData, tmp64, tmp65), jacobian->seedVars[25] /* rover_8d.psi.SeedC SEED_VAR */));
  transpose_alloc_real_array(&tmp66, &tmp67);
  real_array_create(&tmp68, ((modelica_real*)&((&jacobian->tmpVars[165] /* rover_8d.mag.C_n2b.$pDERC.dummyVarC[1,1] JACOBIAN_TMP_VAR */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp67, tmp68);
  TRACE_POP
}

/*
equation index: 781
type: SIMPLE_ASSIGN
rover_8d.mag.b_earth.$pDERC.dummyVarC[2] = rover_8d.mag.C_n2b.$pDERC.dummyVarC[2,1] * rover_8d.mag.b_earth0 * $cse7 + (-2.0) * rover_8d.mag.C_n2b.$pDERC.dummyVarC[2,3] * rover_8d.mag.b_earth0 * $cse8
*/
void RoverExample_Components_Rover_eqFunction_781(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 46;
  const int equationIndexes[2] = {1,781};
  jacobian->tmpVars[175] /* rover_8d.mag.b_earth.$pDERC.dummyVarC[2] JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[168] /* rover_8d.mag.C_n2b.$pDERC.dummyVarC[2,1] JACOBIAN_TMP_VAR */) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[5] /* $cse7 PARAM */))) + (-2.0) * ((jacobian->tmpVars[170] /* rover_8d.mag.C_n2b.$pDERC.dummyVarC[2,3] JACOBIAN_TMP_VAR */) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[6] /* $cse8 PARAM */))));
  TRACE_POP
}

/*
equation index: 782
type: SIMPLE_ASSIGN
rover_8d.mag.b_earth.$pDERC.dummyVarC[3] = rover_8d.mag.C_n2b.$pDERC.dummyVarC[3,1] * rover_8d.mag.b_earth0 * $cse7 + (-2.0) * rover_8d.mag.C_n2b.$pDERC.dummyVarC[3,3] * rover_8d.mag.b_earth0 * $cse8
*/
void RoverExample_Components_Rover_eqFunction_782(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 47;
  const int equationIndexes[2] = {1,782};
  jacobian->tmpVars[176] /* rover_8d.mag.b_earth.$pDERC.dummyVarC[3] JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[171] /* rover_8d.mag.C_n2b.$pDERC.dummyVarC[3,1] JACOBIAN_TMP_VAR */) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[5] /* $cse7 PARAM */))) + (-2.0) * ((jacobian->tmpVars[173] /* rover_8d.mag.C_n2b.$pDERC.dummyVarC[3,3] JACOBIAN_TMP_VAR */) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[6] /* $cse8 PARAM */))));
  TRACE_POP
}

/*
equation index: 783
type: SIMPLE_ASSIGN
rover_8d.mag.b_earth.$pDERC.dummyVarC[1] = rover_8d.mag.C_n2b.$pDERC.dummyVarC[1,1] * rover_8d.mag.b_earth0 * $cse7 + (-2.0) * rover_8d.mag.C_n2b.$pDERC.dummyVarC[1,3] * rover_8d.mag.b_earth0 * $cse8
*/
void RoverExample_Components_Rover_eqFunction_783(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 48;
  const int equationIndexes[2] = {1,783};
  jacobian->tmpVars[174] /* rover_8d.mag.b_earth.$pDERC.dummyVarC[1] JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[165] /* rover_8d.mag.C_n2b.$pDERC.dummyVarC[1,1] JACOBIAN_TMP_VAR */) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[5] /* $cse7 PARAM */))) + (-2.0) * ((jacobian->tmpVars[167] /* rover_8d.mag.C_n2b.$pDERC.dummyVarC[1,3] JACOBIAN_TMP_VAR */) * (((data->simulationInfo->realParameter[115] /* rover_8d.mag.b_earth0 PARAM */)) * ((data->simulationInfo->realParameter[6] /* $cse8 PARAM */))));
  TRACE_POP
}

/*
equation index: 784
type: ARRAY_CALL_ASSIGN

rover_8d.emi.b_wire.$pDERC.dummyVarC = RoverExample.Utils.cross3(rover_8d.emi.wire_dir, rover_8d.emi.x_wire) * 1.9999999999999996e-7 * rover_8d.Iq.SeedC * rover_8d.emi.dist_wire ^ 2.0 / rover_8d.emi.dist_wire ^ 4.0
*/
void RoverExample_Components_Rover_eqFunction_784(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 49;
  const int equationIndexes[2] = {1,784};
  real_array tmp69;
  real_array tmp70;
  modelica_real tmp71;
  modelica_real tmp72;
  real_array tmp73;
  real_array_create(&tmp69, ((modelica_real*)&((data->simulationInfo->realParameter[93] /* rover_8d.emi.wire_dir[1] PARAM */))), 1, (_index_t)3);
  real_array_create(&tmp70, ((modelica_real*)&((data->simulationInfo->realParameter[99] /* rover_8d.emi.x_wire[1] PARAM */))), 1, (_index_t)3);
  tmp71 = (data->simulationInfo->realParameter[90] /* rover_8d.emi.dist_wire PARAM */);
  tmp72 = (data->simulationInfo->realParameter[90] /* rover_8d.emi.dist_wire PARAM */);
  tmp72 *= tmp72;real_array_create(&tmp73, ((modelica_real*)&((&jacobian->tmpVars[154] /* rover_8d.emi.b_wire.$pDERC.dummyVarC[1] JACOBIAN_TMP_VAR */)[((modelica_integer) 1) - 1])), 1, (_index_t)3);
  real_array_copy_data(mul_alloc_real_array_scalar(omc_RoverExample_Utils_cross3(threadData, tmp69, tmp70), DIVISION(((1.9999999999999996e-7) * (jacobian->seedVars[8] /* rover_8d.Iq.SeedC SEED_VAR */)) * ((tmp71 * tmp71)),(tmp72 * tmp72),"rover_8d.emi.dist_wire ^ 4.0")), tmp73);
  TRACE_POP
}

/*
equation index: 785
type: SIMPLE_ASSIGN
my_meas.$pDERC.dummyVarC = rover_8d.mag.b_earth.$pDERC.dummyVarC[2] + rover_8d.emi.b_wire.$pDERC.dummyVarC[2]
*/
void RoverExample_Components_Rover_eqFunction_785(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 50;
  const int equationIndexes[2] = {1,785};
  jacobian->resultVars[4] /* my_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->tmpVars[175] /* rover_8d.mag.b_earth.$pDERC.dummyVarC[2] JACOBIAN_TMP_VAR */ + jacobian->tmpVars[155] /* rover_8d.emi.b_wire.$pDERC.dummyVarC[2] JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 786
type: SIMPLE_ASSIGN
mx_meas.$pDERC.dummyVarC = rover_8d.mag.b_earth.$pDERC.dummyVarC[1] + rover_8d.emi.b_wire.$pDERC.dummyVarC[1]
*/
void RoverExample_Components_Rover_eqFunction_786(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 51;
  const int equationIndexes[2] = {1,786};
  jacobian->resultVars[3] /* mx_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->tmpVars[174] /* rover_8d.mag.b_earth.$pDERC.dummyVarC[1] JACOBIAN_TMP_VAR */ + jacobian->tmpVars[154] /* rover_8d.emi.b_wire.$pDERC.dummyVarC[1] JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 787
type: SIMPLE_ASSIGN
mz_meas.$pDERC.dummyVarC = rover_8d.mag.b_earth.$pDERC.dummyVarC[3] + rover_8d.emi.b_wire.$pDERC.dummyVarC[3]
*/
void RoverExample_Components_Rover_eqFunction_787(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 52;
  const int equationIndexes[2] = {1,787};
  jacobian->resultVars[5] /* mz_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->tmpVars[176] /* rover_8d.mag.b_earth.$pDERC.dummyVarC[3] JACOBIAN_TMP_VAR */ + jacobian->tmpVars[156] /* rover_8d.emi.b_wire.$pDERC.dummyVarC[3] JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 788
type: SIMPLE_ASSIGN
rover_8d.Vq.$pDERC.dummyVarC = 1.224744871391589 * rover_8d.Vs * $cse12.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_788(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 53;
  const int equationIndexes[2] = {1,788};
  jacobian->tmpVars[144] /* rover_8d.Vq.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (1.224744871391589) * (((data->simulationInfo->realParameter[78] /* rover_8d.Vs PARAM */)) * (jacobian->tmpVars[60] /* $cse12.$pDERC.dummyVarC JACOBIAN_TMP_VAR */));
  TRACE_POP
}

/*
equation index: 789
type: SIMPLE_ASSIGN
$DER.rover_8d.delta.$pDERC.dummyVarC = (-rover_8d.delta.SeedC) / rover_8d.tau_servo
*/
void RoverExample_Components_Rover_eqFunction_789(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 54;
  const int equationIndexes[2] = {1,789};
  jacobian->tmpVars[35] /* der(rover_8d.delta.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION((-jacobian->seedVars[13] /* rover_8d.delta.SeedC SEED_VAR */),(data->simulationInfo->realParameter[125] /* rover_8d.tau_servo PARAM */),"rover_8d.tau_servo");
  TRACE_POP
}

/*
equation index: 790
type: SIMPLE_ASSIGN
rollover_detected.$pDERC.dummyVarC = (*Real*)(rover_8d.rollover_detected.$pDERC.dummyVarC)
*/
void RoverExample_Components_Rover_eqFunction_790(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 55;
  const int equationIndexes[2] = {1,790};
  jacobian->resultVars[11] /* rollover_detected.$pDERC.dummyVarC JACOBIAN_VAR */ = ((modelica_real)jacobian->tmpVars[208] /* rover_8d.rollover_detected.$pDERC.dummyVarC JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 791
type: SIMPLE_ASSIGN
rover_8d.vx_rl.$pDERC.dummyVarC = rover_8d.vx.SeedC + 0.5 * rover_8d.tw * rover_8d.r.SeedC
*/
void RoverExample_Components_Rover_eqFunction_791(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 56;
  const int equationIndexes[2] = {1,791};
  jacobian->tmpVars[191] /* rover_8d.vx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */ + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */));
  TRACE_POP
}

/*
equation index: 792
type: SIMPLE_ASSIGN
$cse27.$pDERC.dummyVarC = sign(rover_8d.vx_rl) * rover_8d.vx_rl.$pDERC.dummyVarC / $cse85 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_792(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 57;
  const int equationIndexes[2] = {1,792};
  modelica_real tmp74;
  tmp74 = jacobian->tmpVars[4] /* $cse85 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[75] /* $cse27.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */))) * (DIVISION(jacobian->tmpVars[191] /* rover_8d.vx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(tmp74 * tmp74),"$cse85 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 793
type: SIMPLE_ASSIGN
$cse26.$pDERC.dummyVarC = if noEvent($cse27 < 0.001) then 0.0 else if noEvent($cse27 > 1.0) then 0.0 else $cse27.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_793(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 58;
  const int equationIndexes[2] = {1,793};
  modelica_boolean tmp75;
  modelica_boolean tmp76;
  modelica_boolean tmp77;
  modelica_real tmp78;
  tmp75 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */),0.001);
  tmp77 = (modelica_boolean)tmp75;
  if(tmp77)
  {
    tmp78 = 0.0;
  }
  else
  {
    tmp76 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */),1.0);
    tmp78 = (tmp76?0.0:jacobian->tmpVars[75] /* $cse27.$pDERC.dummyVarC JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[74] /* $cse26.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp78;
  TRACE_POP
}

/*
equation index: 794
type: SIMPLE_ASSIGN
rover_8d.vy_rr.$pDERC.dummyVarC = rover_8d.vy.SeedC - rover_8d.l_rear * rover_8d.r.SeedC
*/
void RoverExample_Components_Rover_eqFunction_794(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 59;
  const int equationIndexes[2] = {1,794};
  jacobian->tmpVars[195] /* rover_8d.vy_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = jacobian->seedVars[30] /* rover_8d.vy.SeedC SEED_VAR */ - (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */));
  TRACE_POP
}

/*
equation index: 795
type: SIMPLE_ASSIGN
$cse28.$pDERC.dummyVarC = sign(rover_8d.vy_rr) * rover_8d.vy_rr.$pDERC.dummyVarC / $cse84 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_795(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 60;
  const int equationIndexes[2] = {1,795};
  modelica_real tmp79;
  tmp79 = jacobian->tmpVars[5] /* $cse84 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[76] /* $cse28.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */))) * (DIVISION(jacobian->tmpVars[195] /* rover_8d.vy_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(tmp79 * tmp79),"$cse84 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 796
type: SIMPLE_ASSIGN
rover_8d.vx_rr.$pDERC.dummyVarC = rover_8d.vx.SeedC + (-0.5) * rover_8d.tw * rover_8d.r.SeedC
*/
void RoverExample_Components_Rover_eqFunction_796(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 61;
  const int equationIndexes[2] = {1,796};
  jacobian->tmpVars[192] /* rover_8d.vx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */ + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */));
  TRACE_POP
}

/*
equation index: 797
type: SIMPLE_ASSIGN
$cse31.$pDERC.dummyVarC = sign(rover_8d.vx_rr) * rover_8d.vx_rr.$pDERC.dummyVarC / $cse83 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_797(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 62;
  const int equationIndexes[2] = {1,797};
  modelica_real tmp80;
  tmp80 = jacobian->tmpVars[6] /* $cse83 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[80] /* $cse31.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */))) * (DIVISION(jacobian->tmpVars[192] /* rover_8d.vx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(tmp80 * tmp80),"$cse83 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 798
type: SIMPLE_ASSIGN
$cse30.$pDERC.dummyVarC = if noEvent($cse31 < 0.001) then 0.0 else if noEvent($cse31 > 1.0) then 0.0 else $cse31.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_798(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 63;
  const int equationIndexes[2] = {1,798};
  modelica_boolean tmp81;
  modelica_boolean tmp82;
  modelica_boolean tmp83;
  modelica_real tmp84;
  tmp81 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */),0.001);
  tmp83 = (modelica_boolean)tmp81;
  if(tmp83)
  {
    tmp84 = 0.0;
  }
  else
  {
    tmp82 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */),1.0);
    tmp84 = (tmp82?0.0:jacobian->tmpVars[80] /* $cse31.$pDERC.dummyVarC JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[79] /* $cse30.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp84;
  TRACE_POP
}

/*
equation index: 799
type: ARRAY_CALL_ASSIGN

rover_8d.C_n2b.$pDERC.dummyVarC = transpose($DER$RoverExample$PUtils$Peul2rot({rover_8d.phi, rover_8d.theta, mod(rover_8d.psi + 3.14159265, 6.2831853) - 3.14159265}, {1.0, 0.0, -0.0}) * rover_8d.phi.SeedC + $DER$RoverExample$PUtils$Peul2rot({rover_8d.phi, rover_8d.theta, mod(rover_8d.psi + 3.14159265, 6.2831853) - 3.14159265}, {0.0, 1.0, -0.0}) * rover_8d.theta.SeedC + $DER$RoverExample$PUtils$Peul2rot({rover_8d.phi, rover_8d.theta, mod(rover_8d.psi + 3.14159265, 6.2831853) - 3.14159265}, {0.0, 0.0, 1.0}) * rover_8d.psi.SeedC)
*/
void RoverExample_Components_Rover_eqFunction_799(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 64;
  const int equationIndexes[2] = {1,799};
  real_array tmp85;
  modelica_real tmp86;
  real_array tmp87;
  real_array tmp88;
  modelica_real tmp89;
  real_array tmp90;
  real_array tmp91;
  modelica_real tmp92;
  real_array tmp93;
  real_array tmp94;
  real_array tmp95;
  real_array tmp96;
  tmp86 = 6.2831853;
  if (tmp86 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(rover_8d.psi + 3.14159265, 6.2831853)");}
  array_alloc_scalar_real_array(&tmp85, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */), (modelica_real)modelica_real_mod((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */) + 3.14159265, tmp86) - 3.14159265);
  array_alloc_scalar_real_array(&tmp87, 3, (modelica_real)1.0, (modelica_real)0.0, (modelica_real)-0.0);
  tmp89 = 6.2831853;
  if (tmp89 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(rover_8d.psi + 3.14159265, 6.2831853)");}
  array_alloc_scalar_real_array(&tmp88, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */), (modelica_real)modelica_real_mod((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */) + 3.14159265, tmp89) - 3.14159265);
  array_alloc_scalar_real_array(&tmp90, 3, (modelica_real)0.0, (modelica_real)1.0, (modelica_real)-0.0);
  tmp92 = 6.2831853;
  if (tmp92 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(rover_8d.psi + 3.14159265, 6.2831853)");}
  array_alloc_scalar_real_array(&tmp91, 3, (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */), (modelica_real)(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* rover_8d.theta STATE(1) */), (modelica_real)modelica_real_mod((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */) + 3.14159265, tmp92) - 3.14159265);
  array_alloc_scalar_real_array(&tmp93, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)1.0);
  tmp94 = add_alloc_real_array(add_alloc_real_array(mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData, tmp85, tmp87), jacobian->seedVars[24] /* rover_8d.phi.SeedC SEED_VAR */), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData, tmp88, tmp90), jacobian->seedVars[28] /* rover_8d.theta.SeedC SEED_VAR */)), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData, tmp91, tmp93), jacobian->seedVars[25] /* rover_8d.psi.SeedC SEED_VAR */));
  transpose_alloc_real_array(&tmp94, &tmp95);
  real_array_create(&tmp96, ((modelica_real*)&((&jacobian->tmpVars[121] /* rover_8d.C_n2b.$pDERC.dummyVarC[1,1] JACOBIAN_TMP_VAR */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(tmp95, tmp96);
  TRACE_POP
}

/*
equation index: 800
type: SIMPLE_ASSIGN
rover_8d.specific_g.$pDERC.dummyVarC[2] = 9.80665 * rover_8d.C_n2b.$pDERC.dummyVarC[2,3]
*/
void RoverExample_Components_Rover_eqFunction_800(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 65;
  const int equationIndexes[2] = {1,800};
  jacobian->tmpVars[183] /* rover_8d.specific_g.$pDERC.dummyVarC[2] JACOBIAN_TMP_VAR */ = (9.80665) * (jacobian->tmpVars[126] /* rover_8d.C_n2b.$pDERC.dummyVarC[2,3] JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 801
type: SIMPLE_ASSIGN
rover_8d.specific_g.$pDERC.dummyVarC[1] = 9.80665 * rover_8d.C_n2b.$pDERC.dummyVarC[1,3]
*/
void RoverExample_Components_Rover_eqFunction_801(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 66;
  const int equationIndexes[2] = {1,801};
  jacobian->tmpVars[182] /* rover_8d.specific_g.$pDERC.dummyVarC[1] JACOBIAN_TMP_VAR */ = (9.80665) * (jacobian->tmpVars[123] /* rover_8d.C_n2b.$pDERC.dummyVarC[1,3] JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 802
type: SIMPLE_ASSIGN
az_meas.$pDERC.dummyVarC = (-9.80665) * rover_8d.C_n2b.$pDERC.dummyVarC[3,3]
*/
void RoverExample_Components_Rover_eqFunction_802(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 67;
  const int equationIndexes[2] = {1,802};
  jacobian->resultVars[2] /* az_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = (-9.80665) * (jacobian->tmpVars[129] /* rover_8d.C_n2b.$pDERC.dummyVarC[3,3] JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 803
type: SIMPLE_ASSIGN
gyroatk.omega_yaw_false.$pDERC.dummyVarC = 0.5 * gyroatk.l_g * gyroatk.w_d * gyroatk.X_ac * $cse38.$pDERC.dummyVarC / gyroatk.dis_d
*/
void RoverExample_Components_Rover_eqFunction_803(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 68;
  const int equationIndexes[2] = {1,803};
  jacobian->tmpVars[92] /* gyroatk.omega_yaw_false.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (0.5) * (((data->simulationInfo->realParameter[33] /* gyroatk.l_g PARAM */)) * (((data->simulationInfo->realParameter[48] /* gyroatk.w_d PARAM */)) * (((data->simulationInfo->realParameter[21] /* gyroatk.X_ac PARAM */)) * (DIVISION(jacobian->tmpVars[87] /* $cse38.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[27] /* gyroatk.dis_d PARAM */),"gyroatk.dis_d")))));
  TRACE_POP
}

/*
equation index: 804
type: SIMPLE_ASSIGN
r_meas.$pDERC.dummyVarC = rover_8d.r.SeedC + gyroatk.omega_yaw_false.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_804(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 69;
  const int equationIndexes[2] = {1,804};
  jacobian->resultVars[10] /* r_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */ + jacobian->tmpVars[92] /* gyroatk.omega_yaw_false.$pDERC.dummyVarC JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 805
type: SIMPLE_ASSIGN
$DER.rover_8d.lambda.$pDERC.dummyVarC = 0.25 * (rover_8d.omega_fl.SeedC + rover_8d.omega_rl.SeedC + rover_8d.omega_rr.SeedC + rover_8d.omega_fr.SeedC) * rover_8d.gratio
*/
void RoverExample_Components_Rover_eqFunction_805(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 70;
  const int equationIndexes[2] = {1,805};
  jacobian->tmpVars[40] /* der(rover_8d.lambda.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = (0.25) * ((jacobian->seedVars[19] /* rover_8d.omega_fl.SeedC SEED_VAR */ + jacobian->seedVars[21] /* rover_8d.omega_rl.SeedC SEED_VAR */ + jacobian->seedVars[22] /* rover_8d.omega_rr.SeedC SEED_VAR */ + jacobian->seedVars[20] /* rover_8d.omega_fr.SeedC SEED_VAR */) * ((data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */)));
  TRACE_POP
}

/*
equation index: 806
type: SIMPLE_ASSIGN
$DER.rover_8d.Iq.$pDERC.dummyVarC = (rover_8d.Vq.$pDERC.dummyVarC + (-rover_8d.R_phi) * rover_8d.Iq.SeedC - rover_8d.Kb_q * $DER.rover_8d.lambda.$pDERC.dummyVarC) / rover_8d.Le
*/
void RoverExample_Components_Rover_eqFunction_806(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 71;
  const int equationIndexes[2] = {1,806};
  jacobian->tmpVars[30] /* der(rover_8d.Iq.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->tmpVars[144] /* rover_8d.Vq.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ + ((-(data->simulationInfo->realParameter[77] /* rover_8d.R_phi PARAM */))) * (jacobian->seedVars[8] /* rover_8d.Iq.SeedC SEED_VAR */) - (((data->simulationInfo->realParameter[69] /* rover_8d.Kb_q PARAM */)) * (jacobian->tmpVars[40] /* der(rover_8d.lambda.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[72] /* rover_8d.Le PARAM */),"rover_8d.Le");
  TRACE_POP
}

/*
equation index: 807
type: SIMPLE_ASSIGN
$cse37.$pDERC.dummyVarC = (-$cse82) * rover_8d.phi.SeedC
*/
void RoverExample_Components_Rover_eqFunction_807(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 72;
  const int equationIndexes[2] = {1,807};
  jacobian->tmpVars[86] /* $cse37.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[7] /* $cse82 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[24] /* rover_8d.phi.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 808
type: SIMPLE_ASSIGN
$cse36.$pDERC.dummyVarC = $cse81 * rover_8d.phi.SeedC
*/
void RoverExample_Components_Rover_eqFunction_808(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 73;
  const int equationIndexes[2] = {1,808};
  jacobian->tmpVars[85] /* $cse36.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[8] /* $cse81 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[24] /* rover_8d.phi.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 809
type: SIMPLE_ASSIGN
$cse35.$pDERC.dummyVarC = (-$cse80) * rover_8d.delta.SeedC
*/
void RoverExample_Components_Rover_eqFunction_809(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 74;
  const int equationIndexes[2] = {1,809};
  jacobian->tmpVars[84] /* $cse35.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[9] /* $cse80 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[13] /* rover_8d.delta.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 810
type: SIMPLE_ASSIGN
$cse34.$pDERC.dummyVarC = $cse79 * rover_8d.delta.SeedC
*/
void RoverExample_Components_Rover_eqFunction_810(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 75;
  const int equationIndexes[2] = {1,810};
  jacobian->tmpVars[83] /* $cse34.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[10] /* $cse79 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[13] /* rover_8d.delta.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 811
type: SIMPLE_ASSIGN
$cse33.$pDERC.dummyVarC = $cse78 * rover_8d.psi.SeedC
*/
void RoverExample_Components_Rover_eqFunction_811(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 76;
  const int equationIndexes[2] = {1,811};
  jacobian->tmpVars[82] /* $cse33.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[11] /* $cse78 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[25] /* rover_8d.psi.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 812
type: SIMPLE_ASSIGN
$cse32.$pDERC.dummyVarC = (-$cse77) * rover_8d.psi.SeedC
*/
void RoverExample_Components_Rover_eqFunction_812(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 77;
  const int equationIndexes[2] = {1,812};
  jacobian->tmpVars[81] /* $cse32.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[12] /* $cse77 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[25] /* rover_8d.psi.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 813
type: SIMPLE_ASSIGN
$DER.rover_8d.y.$pDERC.dummyVarC = rover_8d.vx * $cse33.$pDERC.dummyVarC + rover_8d.vx.SeedC * $cse33 + rover_8d.vy * $cse32.$pDERC.dummyVarC + rover_8d.vy.SeedC * $cse32
*/
void RoverExample_Components_Rover_eqFunction_813(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 78;
  const int equationIndexes[2] = {1,813};
  jacobian->tmpVars[55] /* der(rover_8d.y.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (jacobian->tmpVars[82] /* $cse33.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + (jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* $cse33 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (jacobian->tmpVars[81] /* $cse32.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + (jacobian->seedVars[30] /* rover_8d.vy.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* $cse32 variable */));
  TRACE_POP
}

/*
equation index: 814
type: SIMPLE_ASSIGN
$DER.rover_8d.x.$pDERC.dummyVarC = rover_8d.vx * $cse32.$pDERC.dummyVarC + rover_8d.vx.SeedC * $cse32 + (-rover_8d.vy) * $cse33.$pDERC.dummyVarC - rover_8d.vy.SeedC * $cse33
*/
void RoverExample_Components_Rover_eqFunction_814(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 79;
  const int equationIndexes[2] = {1,814};
  jacobian->tmpVars[54] /* der(rover_8d.x.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (jacobian->tmpVars[81] /* $cse32.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + (jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* $cse32 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */))) * (jacobian->tmpVars[82] /* $cse33.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - ((jacobian->seedVars[30] /* rover_8d.vy.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* $cse33 variable */)));
  TRACE_POP
}

/*
equation index: 815
type: SIMPLE_ASSIGN
rover_8d.alpha_rr_bnd.$pDERC.dummyVarC = if noEvent(rover_8d.alpha_rr < rover_8d.alpha_min) then 0.0 else if noEvent(rover_8d.alpha_rr > rover_8d.alpha_max) then 0.0 else rover_8d.alpha_rr.SeedC
*/
void RoverExample_Components_Rover_eqFunction_815(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 80;
  const int equationIndexes[2] = {1,815};
  modelica_boolean tmp97;
  modelica_boolean tmp98;
  modelica_boolean tmp99;
  modelica_real tmp100;
  tmp97 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* rover_8d.alpha_rr STATE(1) */),(data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */));
  tmp99 = (modelica_boolean)tmp97;
  if(tmp99)
  {
    tmp100 = 0.0;
  }
  else
  {
    tmp98 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* rover_8d.alpha_rr STATE(1) */),(data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
    tmp100 = (tmp98?0.0:jacobian->seedVars[12] /* rover_8d.alpha_rr.SeedC SEED_VAR */);
  }
  jacobian->tmpVars[148] /* rover_8d.alpha_rr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp100;
  TRACE_POP
}

/*
equation index: 816
type: SIMPLE_ASSIGN
$cse29.$pDERC.dummyVarC = 2.0 * rover_8d.alpha_rr_bnd.$pDERC.dummyVarC / (1.0 + $cse76)
*/
void RoverExample_Components_Rover_eqFunction_816(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 81;
  const int equationIndexes[2] = {1,816};
  jacobian->tmpVars[77] /* $cse29.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (2.0) * (DIVISION(jacobian->tmpVars[148] /* rover_8d.alpha_rr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,1.0 + jacobian->tmpVars[13] /* $cse76 JACOBIAN_TMP_VAR */,"1.0 + $cse76"));
  TRACE_POP
}

/*
equation index: 817
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rr.$pDERC.dummyVarC = (-$cse28) * rover_8d.vy_rr.$pDERC.dummyVarC / rover_8d.Lrely - $cse28.$pDERC.dummyVarC * rover_8d.vy_rr / rover_8d.Lrely - abs(rover_8d.vx_rr) * rover_8d.Lrely * ($cse29.$pDERC.dummyVarC * $cse30 - $cse29 * $cse30.$pDERC.dummyVarC) / (rover_8d.Lrely * $cse30) ^ 2.0 - sign(rover_8d.vx_rr) * rover_8d.vx_rr.$pDERC.dummyVarC * $cse29 / ($cse30 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_817(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 82;
  const int equationIndexes[2] = {1,817};
  modelica_real tmp101;
  tmp101 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */));
  jacobian->tmpVars[34] /* der(rover_8d.alpha_rr.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* $cse28 variable */))) * (DIVISION(jacobian->tmpVars[195] /* rover_8d.vy_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[76] /* $cse28.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[77] /* $cse29.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (jacobian->tmpVars[79] /* $cse30.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(tmp101 * tmp101),"(rover_8d.Lrely * $cse30) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */))) * ((jacobian->tmpVars[192] /* rover_8d.vx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse30 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 818
type: SIMPLE_ASSIGN
rover_8d.alpha_rl_bnd.$pDERC.dummyVarC = if noEvent(rover_8d.alpha_rl < rover_8d.alpha_min) then 0.0 else if noEvent(rover_8d.alpha_rl > rover_8d.alpha_max) then 0.0 else rover_8d.alpha_rl.SeedC
*/
void RoverExample_Components_Rover_eqFunction_818(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 83;
  const int equationIndexes[2] = {1,818};
  modelica_boolean tmp102;
  modelica_boolean tmp103;
  modelica_boolean tmp104;
  modelica_real tmp105;
  tmp102 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* rover_8d.alpha_rl STATE(1) */),(data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */));
  tmp104 = (modelica_boolean)tmp102;
  if(tmp104)
  {
    tmp105 = 0.0;
  }
  else
  {
    tmp103 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* rover_8d.alpha_rl STATE(1) */),(data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
    tmp105 = (tmp103?0.0:jacobian->seedVars[11] /* rover_8d.alpha_rl.SeedC SEED_VAR */);
  }
  jacobian->tmpVars[147] /* rover_8d.alpha_rl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp105;
  TRACE_POP
}

/*
equation index: 819
type: SIMPLE_ASSIGN
$cse25.$pDERC.dummyVarC = 2.0 * rover_8d.alpha_rl_bnd.$pDERC.dummyVarC / (1.0 + $cse75)
*/
void RoverExample_Components_Rover_eqFunction_819(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 84;
  const int equationIndexes[2] = {1,819};
  jacobian->tmpVars[73] /* $cse25.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (2.0) * (DIVISION(jacobian->tmpVars[147] /* rover_8d.alpha_rl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,1.0 + jacobian->tmpVars[14] /* $cse75 JACOBIAN_TMP_VAR */,"1.0 + $cse75"));
  TRACE_POP
}

/*
equation index: 820
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rl.$pDERC.dummyVarC = abs(rover_8d.vx_rl) * ($cse25 * $cse26.$pDERC.dummyVarC * rover_8d.Lrely - $cse25.$pDERC.dummyVarC * $cse26 * rover_8d.Lrely) / ($cse26 * rover_8d.Lrely) ^ 2.0 + (-$cse28) * rover_8d.vy_rr.$pDERC.dummyVarC / rover_8d.Lrely - $cse28.$pDERC.dummyVarC * rover_8d.vy_rr / rover_8d.Lrely - sign(rover_8d.vx_rl) * rover_8d.vx_rl.$pDERC.dummyVarC * $cse25 / (rover_8d.Lrely * $cse26)
*/
void RoverExample_Components_Rover_eqFunction_820(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 85;
  const int equationIndexes[2] = {1,820};
  modelica_real tmp106;
  tmp106 = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */));
  jacobian->tmpVars[33] /* der(rover_8d.alpha_rl.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */))) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * ((jacobian->tmpVars[74] /* $cse26.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */))) - ((jacobian->tmpVars[73] /* $cse25.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */))))),(tmp106 * tmp106),"($cse26 * rover_8d.Lrely) ^ 2.0") + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* $cse28 variable */))) * (DIVISION(jacobian->tmpVars[195] /* rover_8d.vy_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[76] /* $cse28.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */))) * ((jacobian->tmpVars[191] /* rover_8d.vx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */),((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)),"rover_8d.Lrely * $cse26"))));
  TRACE_POP
}

/*
equation index: 821
type: SIMPLE_ASSIGN
rover_8d.alpha_fr_bnd.$pDERC.dummyVarC = if noEvent(rover_8d.alpha_fr < rover_8d.alpha_min) then 0.0 else if noEvent(rover_8d.alpha_fr > rover_8d.alpha_max) then 0.0 else rover_8d.alpha_fr.SeedC
*/
void RoverExample_Components_Rover_eqFunction_821(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 86;
  const int equationIndexes[2] = {1,821};
  modelica_boolean tmp107;
  modelica_boolean tmp108;
  modelica_boolean tmp109;
  modelica_real tmp110;
  tmp107 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* rover_8d.alpha_fr STATE(1) */),(data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */));
  tmp109 = (modelica_boolean)tmp107;
  if(tmp109)
  {
    tmp110 = 0.0;
  }
  else
  {
    tmp108 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* rover_8d.alpha_fr STATE(1) */),(data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
    tmp110 = (tmp108?0.0:jacobian->seedVars[10] /* rover_8d.alpha_fr.SeedC SEED_VAR */);
  }
  jacobian->tmpVars[146] /* rover_8d.alpha_fr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp110;
  TRACE_POP
}

/*
equation index: 822
type: SIMPLE_ASSIGN
$cse21.$pDERC.dummyVarC = 2.0 * rover_8d.alpha_fr_bnd.$pDERC.dummyVarC / (1.0 + $cse74)
*/
void RoverExample_Components_Rover_eqFunction_822(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 87;
  const int equationIndexes[2] = {1,822};
  jacobian->tmpVars[69] /* $cse21.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (2.0) * (DIVISION(jacobian->tmpVars[146] /* rover_8d.alpha_fr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,1.0 + jacobian->tmpVars[15] /* $cse74 JACOBIAN_TMP_VAR */,"1.0 + $cse74"));
  TRACE_POP
}

/*
equation index: 823
type: SIMPLE_ASSIGN
rover_8d.alpha_fl_bnd.$pDERC.dummyVarC = if noEvent(rover_8d.alpha_fl < rover_8d.alpha_min) then 0.0 else if noEvent(rover_8d.alpha_fl > rover_8d.alpha_max) then 0.0 else rover_8d.alpha_fl.SeedC
*/
void RoverExample_Components_Rover_eqFunction_823(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 88;
  const int equationIndexes[2] = {1,823};
  modelica_boolean tmp111;
  modelica_boolean tmp112;
  modelica_boolean tmp113;
  modelica_real tmp114;
  tmp111 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* rover_8d.alpha_fl STATE(1) */),(data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */));
  tmp113 = (modelica_boolean)tmp111;
  if(tmp113)
  {
    tmp114 = 0.0;
  }
  else
  {
    tmp112 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* rover_8d.alpha_fl STATE(1) */),(data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
    tmp114 = (tmp112?0.0:jacobian->seedVars[9] /* rover_8d.alpha_fl.SeedC SEED_VAR */);
  }
  jacobian->tmpVars[145] /* rover_8d.alpha_fl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp114;
  TRACE_POP
}

/*
equation index: 824
type: SIMPLE_ASSIGN
$cse17.$pDERC.dummyVarC = 2.0 * rover_8d.alpha_fl_bnd.$pDERC.dummyVarC / (1.0 + $cse73)
*/
void RoverExample_Components_Rover_eqFunction_824(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 89;
  const int equationIndexes[2] = {1,824};
  jacobian->tmpVars[65] /* $cse17.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (2.0) * (DIVISION(jacobian->tmpVars[145] /* rover_8d.alpha_fl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,1.0 + jacobian->tmpVars[16] /* $cse73 JACOBIAN_TMP_VAR */,"1.0 + $cse73"));
  TRACE_POP
}

/*
equation index: 825
type: SIMPLE_ASSIGN
$cse16.$pDERC.dummyVarC = $cse72 * rover_8d.delta.SeedC
*/
void RoverExample_Components_Rover_eqFunction_825(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 90;
  const int equationIndexes[2] = {1,825};
  jacobian->tmpVars[64] /* $cse16.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[17] /* $cse72 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[13] /* rover_8d.delta.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 826
type: SIMPLE_ASSIGN
$cse15.$pDERC.dummyVarC = (-$cse71) * rover_8d.delta.SeedC
*/
void RoverExample_Components_Rover_eqFunction_826(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 91;
  const int equationIndexes[2] = {1,826};
  jacobian->tmpVars[63] /* $cse15.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[18] /* $cse71 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[13] /* rover_8d.delta.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 827
type: SIMPLE_ASSIGN
rover_8d.vy_fr.$pDERC.dummyVarC = $cse15 * (rover_8d.vy.SeedC + rover_8d.l_front * rover_8d.r.SeedC) + $cse15.$pDERC.dummyVarC * (rover_8d.vy + rover_8d.l_front * rover_8d.r) + (-$cse16) * rover_8d.vx_rr.$pDERC.dummyVarC - $cse16.$pDERC.dummyVarC * rover_8d.vx_rr
*/
void RoverExample_Components_Rover_eqFunction_827(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 92;
  const int equationIndexes[2] = {1,827};
  jacobian->tmpVars[194] /* rover_8d.vy_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * (jacobian->seedVars[30] /* rover_8d.vy.SeedC SEED_VAR */ + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */)) + (jacobian->tmpVars[63] /* $cse15.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */))) * (jacobian->tmpVars[192] /* rover_8d.vx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[64] /* $cse16.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)));
  TRACE_POP
}

/*
equation index: 828
type: SIMPLE_ASSIGN
$cse24.$pDERC.dummyVarC = sign(rover_8d.vy_fr) * rover_8d.vy_fr.$pDERC.dummyVarC / $cse86 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_828(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 93;
  const int equationIndexes[2] = {1,828};
  modelica_real tmp115;
  tmp115 = jacobian->tmpVars[3] /* $cse86 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[72] /* $cse24.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */))) * (DIVISION(jacobian->tmpVars[194] /* rover_8d.vy_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(tmp115 * tmp115),"$cse86 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 829
type: SIMPLE_ASSIGN
rover_8d.vx_fr.$pDERC.dummyVarC = $cse15 * rover_8d.vx_rr.$pDERC.dummyVarC + $cse15.$pDERC.dummyVarC * rover_8d.vx_rr + $cse16 * (rover_8d.vy.SeedC + rover_8d.l_front * rover_8d.r.SeedC) + $cse16.$pDERC.dummyVarC * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_829(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 94;
  const int equationIndexes[2] = {1,829};
  jacobian->tmpVars[190] /* rover_8d.vx_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * (jacobian->tmpVars[192] /* rover_8d.vx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[63] /* $cse15.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */)) * (jacobian->seedVars[30] /* rover_8d.vy.SeedC SEED_VAR */ + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */)) + (jacobian->tmpVars[64] /* $cse16.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 830
type: SIMPLE_ASSIGN
$cse23.$pDERC.dummyVarC = sign(rover_8d.vx_fr) * rover_8d.vx_fr.$pDERC.dummyVarC / $cse87 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_830(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 95;
  const int equationIndexes[2] = {1,830};
  modelica_real tmp116;
  tmp116 = jacobian->tmpVars[2] /* $cse87 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[71] /* $cse23.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * (DIVISION(jacobian->tmpVars[190] /* rover_8d.vx_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(tmp116 * tmp116),"$cse87 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 831
type: SIMPLE_ASSIGN
$cse22.$pDERC.dummyVarC = if noEvent($cse23 < 0.001) then 0.0 else if noEvent($cse23 > 1.0) then 0.0 else $cse23.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_831(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 96;
  const int equationIndexes[2] = {1,831};
  modelica_boolean tmp117;
  modelica_boolean tmp118;
  modelica_boolean tmp119;
  modelica_real tmp120;
  tmp117 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */),0.001);
  tmp119 = (modelica_boolean)tmp117;
  if(tmp119)
  {
    tmp120 = 0.0;
  }
  else
  {
    tmp118 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */),1.0);
    tmp120 = (tmp118?0.0:jacobian->tmpVars[71] /* $cse23.$pDERC.dummyVarC JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[70] /* $cse22.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp120;
  TRACE_POP
}

/*
equation index: 832
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fr.$pDERC.dummyVarC = (-$cse24) * rover_8d.vy_fr.$pDERC.dummyVarC / rover_8d.Lrely - $cse24.$pDERC.dummyVarC * rover_8d.vy_fr / rover_8d.Lrely - abs(rover_8d.vx_fr) * rover_8d.Lrely * ($cse21.$pDERC.dummyVarC * $cse22 - $cse21 * $cse22.$pDERC.dummyVarC) / (rover_8d.Lrely * $cse22) ^ 2.0 - sign(rover_8d.vx_fr) * rover_8d.vx_fr.$pDERC.dummyVarC * $cse21 / ($cse22 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_832(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 97;
  const int equationIndexes[2] = {1,832};
  modelica_real tmp121;
  tmp121 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */));
  jacobian->tmpVars[32] /* der(rover_8d.alpha_fr.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* $cse24 variable */))) * (DIVISION(jacobian->tmpVars[194] /* rover_8d.vy_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[72] /* $cse24.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[69] /* $cse21.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (jacobian->tmpVars[70] /* $cse22.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(tmp121 * tmp121),"(rover_8d.Lrely * $cse22) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * ((jacobian->tmpVars[190] /* rover_8d.vx_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse22 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 833
type: SIMPLE_ASSIGN
rover_8d.vy_fl.$pDERC.dummyVarC = $cse15 * (rover_8d.vy.SeedC + rover_8d.l_front * rover_8d.r.SeedC) + $cse15.$pDERC.dummyVarC * (rover_8d.vy + rover_8d.l_front * rover_8d.r) + (-$cse16) * rover_8d.vx_rl.$pDERC.dummyVarC - $cse16.$pDERC.dummyVarC * rover_8d.vx_rl
*/
void RoverExample_Components_Rover_eqFunction_833(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 98;
  const int equationIndexes[2] = {1,833};
  jacobian->tmpVars[193] /* rover_8d.vy_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * (jacobian->seedVars[30] /* rover_8d.vy.SeedC SEED_VAR */ + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */)) + (jacobian->tmpVars[63] /* $cse15.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */))) * (jacobian->tmpVars[191] /* rover_8d.vx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[64] /* $cse16.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)));
  TRACE_POP
}

/*
equation index: 834
type: SIMPLE_ASSIGN
$cse20.$pDERC.dummyVarC = sign(rover_8d.vy_fl) * rover_8d.vy_fl.$pDERC.dummyVarC / $cse88 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_834(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 99;
  const int equationIndexes[2] = {1,834};
  modelica_real tmp122;
  tmp122 = jacobian->tmpVars[1] /* $cse88 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[68] /* $cse20.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */))) * (DIVISION(jacobian->tmpVars[193] /* rover_8d.vy_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(tmp122 * tmp122),"$cse88 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 835
type: SIMPLE_ASSIGN
rover_8d.vx_fl.$pDERC.dummyVarC = $cse15 * rover_8d.vx_rl.$pDERC.dummyVarC + $cse15.$pDERC.dummyVarC * rover_8d.vx_rl + $cse16 * (rover_8d.vy.SeedC + rover_8d.l_front * rover_8d.r.SeedC) + $cse16.$pDERC.dummyVarC * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_835(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 100;
  const int equationIndexes[2] = {1,835};
  jacobian->tmpVars[189] /* rover_8d.vx_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * (jacobian->tmpVars[191] /* rover_8d.vx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[63] /* $cse15.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */)) * (jacobian->seedVars[30] /* rover_8d.vy.SeedC SEED_VAR */ + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */)) + (jacobian->tmpVars[64] /* $cse16.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 836
type: SIMPLE_ASSIGN
$cse19.$pDERC.dummyVarC = sign(rover_8d.vx_fl) * rover_8d.vx_fl.$pDERC.dummyVarC / $cse89 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_836(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 101;
  const int equationIndexes[2] = {1,836};
  modelica_real tmp123;
  tmp123 = jacobian->tmpVars[0] /* $cse89 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[67] /* $cse19.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * (DIVISION(jacobian->tmpVars[189] /* rover_8d.vx_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(tmp123 * tmp123),"$cse89 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 837
type: SIMPLE_ASSIGN
$cse18.$pDERC.dummyVarC = if noEvent($cse19 < 0.001) then 0.0 else if noEvent($cse19 > 1.0) then 0.0 else $cse19.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_837(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 102;
  const int equationIndexes[2] = {1,837};
  modelica_boolean tmp124;
  modelica_boolean tmp125;
  modelica_boolean tmp126;
  modelica_real tmp127;
  tmp124 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */),0.001);
  tmp126 = (modelica_boolean)tmp124;
  if(tmp126)
  {
    tmp127 = 0.0;
  }
  else
  {
    tmp125 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */),1.0);
    tmp127 = (tmp125?0.0:jacobian->tmpVars[67] /* $cse19.$pDERC.dummyVarC JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[66] /* $cse18.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp127;
  TRACE_POP
}

/*
equation index: 838
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fl.$pDERC.dummyVarC = (-$cse20) * rover_8d.vy_fl.$pDERC.dummyVarC / rover_8d.Lrely - $cse20.$pDERC.dummyVarC * rover_8d.vy_fl / rover_8d.Lrely - abs(rover_8d.vx_fl) * rover_8d.Lrely * ($cse17.$pDERC.dummyVarC * $cse18 - $cse17 * $cse18.$pDERC.dummyVarC) / (rover_8d.Lrely * $cse18) ^ 2.0 - sign(rover_8d.vx_fl) * rover_8d.vx_fl.$pDERC.dummyVarC * $cse17 / ($cse18 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_838(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 103;
  const int equationIndexes[2] = {1,838};
  modelica_real tmp128;
  tmp128 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */));
  jacobian->tmpVars[31] /* der(rover_8d.alpha_fl.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* $cse20 variable */))) * (DIVISION(jacobian->tmpVars[193] /* rover_8d.vy_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[68] /* $cse20.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[65] /* $cse17.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (jacobian->tmpVars[66] /* $cse18.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(tmp128 * tmp128),"(rover_8d.Lrely * $cse18) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * ((jacobian->tmpVars[189] /* rover_8d.vx_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse18 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 839
type: SIMPLE_ASSIGN
rover_8d.kappa_rr_bnd.$pDERC.dummyVarC = if noEvent(rover_8d.kappa_rr < rover_8d.kappa_min) then 0.0 else if noEvent(rover_8d.kappa_rr > rover_8d.kappa_max) then 0.0 else rover_8d.kappa_rr.SeedC
*/
void RoverExample_Components_Rover_eqFunction_839(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 104;
  const int equationIndexes[2] = {1,839};
  modelica_boolean tmp129;
  modelica_boolean tmp130;
  modelica_boolean tmp131;
  modelica_real tmp132;
  tmp129 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */),(data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */));
  tmp131 = (modelica_boolean)tmp129;
  if(tmp131)
  {
    tmp132 = 0.0;
  }
  else
  {
    tmp130 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */),(data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
    tmp132 = (tmp130?0.0:jacobian->seedVars[17] /* rover_8d.kappa_rr.SeedC SEED_VAR */);
  }
  jacobian->tmpVars[164] /* rover_8d.kappa_rr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp132;
  TRACE_POP
}

/*
equation index: 840
type: SIMPLE_ASSIGN
rover_8d.vs_rr.$pDERC.dummyVarC = 0.5 * rover_8d.vx_rr * 2.0 * (rover_8d.kappa_rr_bnd * rover_8d.kappa_rr_bnd.$pDERC.dummyVarC + $cse29 * $cse29.$pDERC.dummyVarC) / sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0) + rover_8d.vx_rr.$pDERC.dummyVarC * sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_840(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 105;
  const int equationIndexes[2] = {1,840};
  modelica_real tmp133;
  modelica_real tmp134;
  modelica_real tmp135;
  modelica_real tmp136;
  modelica_real tmp137;
  modelica_real tmp138;
  tmp133 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  tmp134 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */);
  tmp135 = (tmp133 * tmp133) + (tmp134 * tmp134);
  if(!(tmp135 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0) was %g should be >= 0", tmp135);
    }
  }tmp136 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  tmp137 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */);
  tmp138 = (tmp136 * tmp136) + (tmp137 * tmp137);
  if(!(tmp138 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0) was %g should be >= 0", tmp138);
    }
  }
  jacobian->tmpVars[188] /* rover_8d.vs_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (jacobian->tmpVars[164] /* rover_8d.kappa_rr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (jacobian->tmpVars[77] /* $cse29.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),sqrt(tmp135),"sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0)"))) + (jacobian->tmpVars[192] /* rover_8d.vx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (sqrt(tmp138));
  TRACE_POP
}

/*
equation index: 841
type: SIMPLE_ASSIGN
rover_8d.mu_rr.$pDERC.dummyVarC = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rr) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rr) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_rr.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_841(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 106;
  const int equationIndexes[2] = {1,841};
  modelica_boolean tmp139;
  modelica_boolean tmp140;
  modelica_boolean tmp141;
  modelica_real tmp142;
  tmp139 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */)))),0.0);
  tmp141 = (modelica_boolean)tmp139;
  if(tmp141)
  {
    tmp142 = 0.0;
  }
  else
  {
    tmp140 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp142 = (tmp140?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[188] /* rover_8d.vs_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[180] /* rover_8d.mu_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp142;
  TRACE_POP
}

/*
equation index: 842
type: SIMPLE_ASSIGN
rover_8d.kappa_rl_bnd.$pDERC.dummyVarC = if noEvent(rover_8d.kappa_rl < rover_8d.kappa_min) then 0.0 else if noEvent(rover_8d.kappa_rl > rover_8d.kappa_max) then 0.0 else rover_8d.kappa_rl.SeedC
*/
void RoverExample_Components_Rover_eqFunction_842(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 107;
  const int equationIndexes[2] = {1,842};
  modelica_boolean tmp143;
  modelica_boolean tmp144;
  modelica_boolean tmp145;
  modelica_real tmp146;
  tmp143 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */),(data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */));
  tmp145 = (modelica_boolean)tmp143;
  if(tmp145)
  {
    tmp146 = 0.0;
  }
  else
  {
    tmp144 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */),(data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
    tmp146 = (tmp144?0.0:jacobian->seedVars[16] /* rover_8d.kappa_rl.SeedC SEED_VAR */);
  }
  jacobian->tmpVars[163] /* rover_8d.kappa_rl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp146;
  TRACE_POP
}

/*
equation index: 843
type: SIMPLE_ASSIGN
rover_8d.vs_rl.$pDERC.dummyVarC = 0.5 * rover_8d.vx_rl * 2.0 * (rover_8d.kappa_rl_bnd * rover_8d.kappa_rl_bnd.$pDERC.dummyVarC + $cse25 * $cse25.$pDERC.dummyVarC) / sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0) + rover_8d.vx_rl.$pDERC.dummyVarC * sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_843(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 108;
  const int equationIndexes[2] = {1,843};
  modelica_real tmp147;
  modelica_real tmp148;
  modelica_real tmp149;
  modelica_real tmp150;
  modelica_real tmp151;
  modelica_real tmp152;
  tmp147 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  tmp148 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */);
  tmp149 = (tmp147 * tmp147) + (tmp148 * tmp148);
  if(!(tmp149 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0) was %g should be >= 0", tmp149);
    }
  }tmp150 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  tmp151 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */);
  tmp152 = (tmp150 * tmp150) + (tmp151 * tmp151);
  if(!(tmp152 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0) was %g should be >= 0", tmp152);
    }
  }
  jacobian->tmpVars[187] /* rover_8d.vs_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (jacobian->tmpVars[163] /* rover_8d.kappa_rl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (jacobian->tmpVars[73] /* $cse25.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),sqrt(tmp149),"sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0)"))) + (jacobian->tmpVars[191] /* rover_8d.vx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (sqrt(tmp152));
  TRACE_POP
}

/*
equation index: 844
type: SIMPLE_ASSIGN
rover_8d.mu_rl.$pDERC.dummyVarC = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rl) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rl) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_rl.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_844(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 109;
  const int equationIndexes[2] = {1,844};
  modelica_boolean tmp153;
  modelica_boolean tmp154;
  modelica_boolean tmp155;
  modelica_real tmp156;
  tmp153 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */)))),0.0);
  tmp155 = (modelica_boolean)tmp153;
  if(tmp155)
  {
    tmp156 = 0.0;
  }
  else
  {
    tmp154 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp156 = (tmp154?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[187] /* rover_8d.vs_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[179] /* rover_8d.mu_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp156;
  TRACE_POP
}

/*
equation index: 845
type: SIMPLE_ASSIGN
rover_8d.kappa_fr_bnd.$pDERC.dummyVarC = if noEvent(rover_8d.kappa_fr < rover_8d.kappa_min) then 0.0 else if noEvent(rover_8d.kappa_fr > rover_8d.kappa_max) then 0.0 else rover_8d.kappa_fr.SeedC
*/
void RoverExample_Components_Rover_eqFunction_845(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 110;
  const int equationIndexes[2] = {1,845};
  modelica_boolean tmp157;
  modelica_boolean tmp158;
  modelica_boolean tmp159;
  modelica_real tmp160;
  tmp157 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */),(data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */));
  tmp159 = (modelica_boolean)tmp157;
  if(tmp159)
  {
    tmp160 = 0.0;
  }
  else
  {
    tmp158 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */),(data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
    tmp160 = (tmp158?0.0:jacobian->seedVars[15] /* rover_8d.kappa_fr.SeedC SEED_VAR */);
  }
  jacobian->tmpVars[162] /* rover_8d.kappa_fr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp160;
  TRACE_POP
}

/*
equation index: 846
type: SIMPLE_ASSIGN
rover_8d.vs_fr.$pDERC.dummyVarC = 0.5 * rover_8d.vx_rr * 2.0 * (rover_8d.kappa_fr_bnd * rover_8d.kappa_fr_bnd.$pDERC.dummyVarC + $cse21 * $cse21.$pDERC.dummyVarC) / sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0) + rover_8d.vx_rr.$pDERC.dummyVarC * sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_846(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 111;
  const int equationIndexes[2] = {1,846};
  modelica_real tmp161;
  modelica_real tmp162;
  modelica_real tmp163;
  modelica_real tmp164;
  modelica_real tmp165;
  modelica_real tmp166;
  tmp161 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  tmp162 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */);
  tmp163 = (tmp161 * tmp161) + (tmp162 * tmp162);
  if(!(tmp163 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0) was %g should be >= 0", tmp163);
    }
  }tmp164 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  tmp165 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */);
  tmp166 = (tmp164 * tmp164) + (tmp165 * tmp165);
  if(!(tmp166 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0) was %g should be >= 0", tmp166);
    }
  }
  jacobian->tmpVars[186] /* rover_8d.vs_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (jacobian->tmpVars[162] /* rover_8d.kappa_fr_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (jacobian->tmpVars[69] /* $cse21.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),sqrt(tmp163),"sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0)"))) + (jacobian->tmpVars[192] /* rover_8d.vx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (sqrt(tmp166));
  TRACE_POP
}

/*
equation index: 847
type: SIMPLE_ASSIGN
rover_8d.mu_fr.$pDERC.dummyVarC = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fr) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fr) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_fr.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_847(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 112;
  const int equationIndexes[2] = {1,847};
  modelica_boolean tmp167;
  modelica_boolean tmp168;
  modelica_boolean tmp169;
  modelica_real tmp170;
  tmp167 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */)))),0.0);
  tmp169 = (modelica_boolean)tmp167;
  if(tmp169)
  {
    tmp170 = 0.0;
  }
  else
  {
    tmp168 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp170 = (tmp168?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[186] /* rover_8d.vs_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[178] /* rover_8d.mu_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp170;
  TRACE_POP
}

/*
equation index: 848
type: SIMPLE_ASSIGN
rover_8d.kappa_fl_bnd.$pDERC.dummyVarC = if noEvent(rover_8d.kappa_fl < rover_8d.kappa_min) then 0.0 else if noEvent(rover_8d.kappa_fl > rover_8d.kappa_max) then 0.0 else rover_8d.kappa_fl.SeedC
*/
void RoverExample_Components_Rover_eqFunction_848(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 113;
  const int equationIndexes[2] = {1,848};
  modelica_boolean tmp171;
  modelica_boolean tmp172;
  modelica_boolean tmp173;
  modelica_real tmp174;
  tmp171 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */),(data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */));
  tmp173 = (modelica_boolean)tmp171;
  if(tmp173)
  {
    tmp174 = 0.0;
  }
  else
  {
    tmp172 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */),(data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
    tmp174 = (tmp172?0.0:jacobian->seedVars[14] /* rover_8d.kappa_fl.SeedC SEED_VAR */);
  }
  jacobian->tmpVars[161] /* rover_8d.kappa_fl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp174;
  TRACE_POP
}

/*
equation index: 849
type: SIMPLE_ASSIGN
rover_8d.vs_fl.$pDERC.dummyVarC = 0.5 * rover_8d.vx_rl * 2.0 * (rover_8d.kappa_fl_bnd * rover_8d.kappa_fl_bnd.$pDERC.dummyVarC + $cse17 * $cse17.$pDERC.dummyVarC) / sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0) + rover_8d.vx_rl.$pDERC.dummyVarC * sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_849(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 114;
  const int equationIndexes[2] = {1,849};
  modelica_real tmp175;
  modelica_real tmp176;
  modelica_real tmp177;
  modelica_real tmp178;
  modelica_real tmp179;
  modelica_real tmp180;
  tmp175 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  tmp176 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */);
  tmp177 = (tmp175 * tmp175) + (tmp176 * tmp176);
  if(!(tmp177 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0) was %g should be >= 0", tmp177);
    }
  }tmp178 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  tmp179 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */);
  tmp180 = (tmp178 * tmp178) + (tmp179 * tmp179);
  if(!(tmp180 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0) was %g should be >= 0", tmp180);
    }
  }
  jacobian->tmpVars[185] /* rover_8d.vs_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (jacobian->tmpVars[161] /* rover_8d.kappa_fl_bnd.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (jacobian->tmpVars[65] /* $cse17.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),sqrt(tmp177),"sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0)"))) + (jacobian->tmpVars[191] /* rover_8d.vx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * (sqrt(tmp180));
  TRACE_POP
}

/*
equation index: 850
type: SIMPLE_ASSIGN
rover_8d.mu_fl.$pDERC.dummyVarC = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fl) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fl) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_fl.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_850(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 115;
  const int equationIndexes[2] = {1,850};
  modelica_boolean tmp181;
  modelica_boolean tmp182;
  modelica_boolean tmp183;
  modelica_real tmp184;
  tmp181 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */)))),0.0);
  tmp183 = (modelica_boolean)tmp181;
  if(tmp183)
  {
    tmp184 = 0.0;
  }
  else
  {
    tmp182 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp184 = (tmp182?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[185] /* rover_8d.vs_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[177] /* rover_8d.mu_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp184;
  TRACE_POP
}

/*
equation index: 895
type: LINEAR

<var>rover_8d.fz_rr.$pDERC.dummyVarC</var>
<var>rover_8d.fz_fr.$pDERC.dummyVarC</var>
<var>rover_8d.fz_rl.$pDERC.dummyVarC</var>
<var>rover_8d.fz_fl.$pDERC.dummyVarC</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_895(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 116;
  const int equationIndexes[2] = {1,895};
  /* Linear equation system */
  int retValue;
  double aux_x[4] = { jacobian->tmpVars[160] /* rover_8d.fz_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,jacobian->tmpVars[158] /* rover_8d.fz_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,jacobian->tmpVars[159] /* rover_8d.fz_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */,jacobian->tmpVars[157] /* rover_8d.fz_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 895 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  data->simulationInfo->linearSystemData[4].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 4, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,895};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 895 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[160] /* rover_8d.fz_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = aux_x[0];
  jacobian->tmpVars[158] /* rover_8d.fz_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = aux_x[1];
  jacobian->tmpVars[159] /* rover_8d.fz_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = aux_x[2];
  jacobian->tmpVars[157] /* rover_8d.fz_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = aux_x[3];

  TRACE_POP
}

/*
equation index: 896
type: SIMPLE_ASSIGN
$DER.rover_8d.p.$pDERC.dummyVarC = (rover_8d.mass_sprung * (9.80665 * $cse36.$pDERC.dummyVarC + (-rover_8d.ay) * $cse37.$pDERC.dummyVarC - rover_8d.ay.$pDERC.dummyVarC * $cse37) * rover_8d.hs + (-rover_8d.k_rllsp) * rover_8d.phi.SeedC - rover_8d.c_rllsp * rover_8d.p.SeedC) / rover_8d.I_xx
*/
void RoverExample_Components_Rover_eqFunction_896(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 117;
  const int equationIndexes[2] = {1,896};
  jacobian->tmpVars[45] /* der(rover_8d.p.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((9.80665) * (jacobian->tmpVars[85] /* $cse36.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */))) * (jacobian->tmpVars[86] /* $cse37.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[150] /* rover_8d.ay.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* $cse37 variable */)))) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */))) + ((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * (jacobian->seedVars[24] /* rover_8d.phi.SeedC SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * (jacobian->seedVars[23] /* rover_8d.p.SeedC SEED_VAR */)),(data->simulationInfo->realParameter[65] /* rover_8d.I_xx PARAM */),"rover_8d.I_xx");
  TRACE_POP
}

/*
equation index: 897
type: SIMPLE_ASSIGN
ay_meas.$pDERC.dummyVarC = rover_8d.ay.$pDERC.dummyVarC - rover_8d.specific_g.$pDERC.dummyVarC[2]
*/
void RoverExample_Components_Rover_eqFunction_897(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 118;
  const int equationIndexes[2] = {1,897};
  jacobian->resultVars[1] /* ay_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->tmpVars[150] /* rover_8d.ay.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ - jacobian->tmpVars[183] /* rover_8d.specific_g.$pDERC.dummyVarC[2] JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 898
type: SIMPLE_ASSIGN
$DER.rover_8d.vx.$pDERC.dummyVarC = rover_8d.vy * rover_8d.r.SeedC + rover_8d.vy.SeedC * rover_8d.r + rover_8d.ax.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_898(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 119;
  const int equationIndexes[2] = {1,898};
  jacobian->tmpVars[51] /* der(rover_8d.vx.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */) + (jacobian->seedVars[30] /* rover_8d.vy.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)) + jacobian->tmpVars[149] /* rover_8d.ax.$pDERC.dummyVarC JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 899
type: SIMPLE_ASSIGN
ax_meas.$pDERC.dummyVarC = rover_8d.ax.$pDERC.dummyVarC - rover_8d.specific_g.$pDERC.dummyVarC[1]
*/
void RoverExample_Components_Rover_eqFunction_899(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 120;
  const int equationIndexes[2] = {1,899};
  jacobian->resultVars[0] /* ax_meas.$pDERC.dummyVarC JACOBIAN_VAR */ = jacobian->tmpVars[149] /* rover_8d.ax.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ - jacobian->tmpVars[182] /* rover_8d.specific_g.$pDERC.dummyVarC[1] JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 900
type: SIMPLE_ASSIGN
$DER.rover_8d.r.$pDERC.dummyVarC = (0.5 * (rover_8d.Fx_fl * $cse34.$pDERC.dummyVarC + rover_8d.Fx_fl.$pDERC.dummyVarC * $cse34 + rover_8d.Fy_fl * $cse35.$pDERC.dummyVarC + rover_8d.Fy_fl.$pDERC.dummyVarC * $cse35 + rover_8d.Fx_rl.$pDERC.dummyVarC + (-rover_8d.Fx_fr) * $cse34.$pDERC.dummyVarC - rover_8d.Fx_fr.$pDERC.dummyVarC * $cse34 - rover_8d.Fy_fr.$pDERC.dummyVarC * $cse35 - rover_8d.Fy_fr * $cse35.$pDERC.dummyVarC - rover_8d.Fx_rr.$pDERC.dummyVarC) * rover_8d.tw + rover_8d.l_front * (rover_8d.Fy_fl * $cse34.$pDERC.dummyVarC + rover_8d.Fy_fl.$pDERC.dummyVarC * $cse34 + (-rover_8d.Fx_fl) * $cse35.$pDERC.dummyVarC - rover_8d.Fx_fl.$pDERC.dummyVarC * $cse35) + rover_8d.l_front * (rover_8d.Fy_fr * $cse34.$pDERC.dummyVarC + rover_8d.Fy_fr.$pDERC.dummyVarC * $cse34 + (-rover_8d.Fx_fr) * $cse35.$pDERC.dummyVarC - rover_8d.Fx_fr.$pDERC.dummyVarC * $cse35) - rover_8d.l_rear * (rover_8d.Fy_rl.$pDERC.dummyVarC + rover_8d.Fy_rr.$pDERC.dummyVarC)) / rover_8d.I_zz
*/
void RoverExample_Components_Rover_eqFunction_900(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 121;
  const int equationIndexes[2] = {1,900};
  jacobian->tmpVars[49] /* der(rover_8d.r.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * (jacobian->tmpVars[83] /* $cse34.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[130] /* rover_8d.Fx_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (jacobian->tmpVars[84] /* $cse35.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[134] /* rover_8d.Fy_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + jacobian->tmpVars[132] /* rover_8d.Fx_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))) * (jacobian->tmpVars[83] /* $cse34.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[131] /* rover_8d.Fx_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */))) - ((jacobian->tmpVars[135] /* rover_8d.Fy_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (jacobian->tmpVars[84] /* $cse35.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)) - jacobian->tmpVars[133] /* rover_8d.Fx_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (jacobian->tmpVars[83] /* $cse34.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[134] /* rover_8d.Fy_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */))) * (jacobian->tmpVars[84] /* $cse35.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[130] /* rover_8d.Fx_fl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (jacobian->tmpVars[83] /* $cse34.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[135] /* rover_8d.Fy_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))) * (jacobian->tmpVars[84] /* $cse35.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[131] /* rover_8d.Fx_fr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) - (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (jacobian->tmpVars[136] /* rover_8d.Fy_rl.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ + jacobian->tmpVars[137] /* rover_8d.Fy_rr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[66] /* rover_8d.I_zz PARAM */),"rover_8d.I_zz");
  TRACE_POP
}

/*
equation index: 901
type: SIMPLE_ASSIGN
$DER.rover_8d.vy.$pDERC.dummyVarC = rover_8d.ay.$pDERC.dummyVarC + (rover_8d.l_rear * rover_8d.mass_unsprung_rear - rover_8d.l_front * rover_8d.mass_unsprung_front) * $DER.rover_8d.r.$pDERC.dummyVarC / rover_8d.mass_total + (-rover_8d.vx) * rover_8d.r.SeedC - rover_8d.vx.SeedC * rover_8d.r
*/
void RoverExample_Components_Rover_eqFunction_901(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 122;
  const int equationIndexes[2] = {1,901};
  jacobian->tmpVars[52] /* der(rover_8d.vy.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = jacobian->tmpVars[150] /* rover_8d.ay.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ + (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) - (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)))) * (DIVISION(jacobian->tmpVars[49] /* der(rover_8d.r.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total")) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */))) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */) - ((jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 914
type: LINEAR

<var>rover_8d.thr.$pDERC.dummyVarC</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_914(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 123;
  const int equationIndexes[2] = {1,914};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { jacobian->tmpVars[184] /* rover_8d.thr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 914 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  data->simulationInfo->linearSystemData[5].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 5, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,914};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 914 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[184] /* rover_8d.thr.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = aux_x[0];

  TRACE_POP
}

/*
equation index: 915
type: SIMPLE_ASSIGN
$cse14.$pDERC.dummyVarC = sign(rover_8d.vx) * rover_8d.vx.SeedC / $cse70 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_915(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 124;
  const int equationIndexes[2] = {1,915};
  modelica_real tmp185;
  tmp185 = jacobian->tmpVars[19] /* $cse70 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[62] /* $cse14.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */))) * (DIVISION(jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */,(tmp185 * tmp185),"$cse70 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 916
type: SIMPLE_ASSIGN
$cse13.$pDERC.dummyVarC = if noEvent($cse14 < 0.001) then 0.0 else if noEvent($cse14 > 1.0) then 0.0 else $cse14.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_916(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 125;
  const int equationIndexes[2] = {1,916};
  modelica_boolean tmp186;
  modelica_boolean tmp187;
  modelica_boolean tmp188;
  modelica_real tmp189;
  tmp186 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */),0.001);
  tmp188 = (modelica_boolean)tmp186;
  if(tmp188)
  {
    tmp189 = 0.0;
  }
  else
  {
    tmp187 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */),1.0);
    tmp189 = (tmp187?0.0:jacobian->tmpVars[62] /* $cse14.$pDERC.dummyVarC JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[61] /* $cse13.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = tmp189;
  TRACE_POP
}

/*
equation index: 917
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rr.$pDERC.dummyVarC = (rover_8d.r_tire * rover_8d.omega_rr.SeedC + 0.5 * rover_8d.tw * rover_8d.r.SeedC - rover_8d.vx.SeedC) / rover_8d.Lrelx + (-abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r)) * rover_8d.Lrelx * (rover_8d.kappa_rr.SeedC * $cse13 - rover_8d.kappa_rr * $cse13.$pDERC.dummyVarC) / (rover_8d.Lrelx * $cse13) ^ 2.0 - sign(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r) * (rover_8d.vx.SeedC + (-0.5) * rover_8d.tw * rover_8d.r.SeedC) * rover_8d.kappa_rr / ($cse13 * rover_8d.Lrelx)
*/
void RoverExample_Components_Rover_eqFunction_917(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 126;
  const int equationIndexes[2] = {1,917};
  modelica_real tmp190;
  tmp190 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->tmpVars[39] /* der(rover_8d.kappa_rr.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * (jacobian->seedVars[22] /* rover_8d.omega_rr.SeedC SEED_VAR */) + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */)) - jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */,(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx") + ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION((jacobian->seedVars[17] /* rover_8d.kappa_rr.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */)) * (jacobian->tmpVars[61] /* $cse13.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(tmp190 * tmp190),"(rover_8d.Lrelx * $cse13) ^ 2.0"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * ((jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */ + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */))) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) * ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)),"$cse13 * rover_8d.Lrelx"))));
  TRACE_POP
}

/*
equation index: 918
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rl.$pDERC.dummyVarC = (rover_8d.r_tire * rover_8d.omega_rl.SeedC + (-0.5) * rover_8d.tw * rover_8d.r.SeedC - rover_8d.vx.SeedC) / rover_8d.Lrelx + (-abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r)) * rover_8d.Lrelx * (rover_8d.kappa_rl.SeedC * $cse13 - rover_8d.kappa_rl * $cse13.$pDERC.dummyVarC) / (rover_8d.Lrelx * $cse13) ^ 2.0 - sign(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r) * (rover_8d.vx.SeedC + 0.5 * rover_8d.tw * rover_8d.r.SeedC) * rover_8d.kappa_rl / ($cse13 * rover_8d.Lrelx)
*/
void RoverExample_Components_Rover_eqFunction_918(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 127;
  const int equationIndexes[2] = {1,918};
  modelica_real tmp191;
  tmp191 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->tmpVars[38] /* der(rover_8d.kappa_rl.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * (jacobian->seedVars[21] /* rover_8d.omega_rl.SeedC SEED_VAR */) + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */)) - jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */,(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx") + ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION((jacobian->seedVars[16] /* rover_8d.kappa_rl.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */)) * (jacobian->tmpVars[61] /* $cse13.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(tmp191 * tmp191),"(rover_8d.Lrelx * $cse13) ^ 2.0"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))) * ((jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */ + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */))) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) * ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)),"$cse13 * rover_8d.Lrelx"))));
  TRACE_POP
}

/*
equation index: 919
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fr.$pDERC.dummyVarC = (rover_8d.r_tire * rover_8d.omega_fr.SeedC + 0.5 * rover_8d.tw * rover_8d.r.SeedC - rover_8d.vx.SeedC) / rover_8d.Lrelx + (-abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r)) * rover_8d.Lrelx * (rover_8d.kappa_fr.SeedC * $cse13 - rover_8d.kappa_fr * $cse13.$pDERC.dummyVarC) / (rover_8d.Lrelx * $cse13) ^ 2.0 - sign(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r) * (rover_8d.vx.SeedC + (-0.5) * rover_8d.tw * rover_8d.r.SeedC) * rover_8d.kappa_fr / ($cse13 * rover_8d.Lrelx)
*/
void RoverExample_Components_Rover_eqFunction_919(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 128;
  const int equationIndexes[2] = {1,919};
  modelica_real tmp192;
  tmp192 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->tmpVars[37] /* der(rover_8d.kappa_fr.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * (jacobian->seedVars[20] /* rover_8d.omega_fr.SeedC SEED_VAR */) + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */)) - jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */,(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx") + ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION((jacobian->seedVars[15] /* rover_8d.kappa_fr.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */)) * (jacobian->tmpVars[61] /* $cse13.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(tmp192 * tmp192),"(rover_8d.Lrelx * $cse13) ^ 2.0"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * ((jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */ + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */))) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) * ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)),"$cse13 * rover_8d.Lrelx"))));
  TRACE_POP
}

/*
equation index: 920
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fl.$pDERC.dummyVarC = (rover_8d.r_tire * rover_8d.omega_fl.SeedC + (-0.5) * rover_8d.tw * rover_8d.r.SeedC - rover_8d.vx.SeedC) / rover_8d.Lrelx + (-abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r)) * rover_8d.Lrelx * (rover_8d.kappa_fl.SeedC * $cse13 - rover_8d.kappa_fl * $cse13.$pDERC.dummyVarC) / (rover_8d.Lrelx * $cse13) ^ 2.0 - sign(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r) * (rover_8d.vx.SeedC + 0.5 * rover_8d.tw * rover_8d.r.SeedC) * rover_8d.kappa_fl / ($cse13 * rover_8d.Lrelx)
*/
void RoverExample_Components_Rover_eqFunction_920(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 129;
  const int equationIndexes[2] = {1,920};
  modelica_real tmp193;
  tmp193 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->tmpVars[36] /* der(rover_8d.kappa_fl.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = DIVISION(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * (jacobian->seedVars[19] /* rover_8d.omega_fl.SeedC SEED_VAR */) + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */)) - jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */,(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx") + ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION((jacobian->seedVars[14] /* rover_8d.kappa_fl.SeedC SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */)) * (jacobian->tmpVars[61] /* $cse13.$pDERC.dummyVarC JACOBIAN_TMP_VAR */)),(tmp193 * tmp193),"(rover_8d.Lrelx * $cse13) ^ 2.0"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))) * ((jacobian->seedVars[29] /* rover_8d.vx.SeedC SEED_VAR */ + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedC SEED_VAR */))) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) * ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)),"$cse13 * rover_8d.Lrelx"))));
  TRACE_POP
}

/*
equation index: 921
type: SIMPLE_ASSIGN
$cse4.$pDERC.dummyVarC = $cse69 * rover_3d.psi.SeedC
*/
void RoverExample_Components_Rover_eqFunction_921(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 130;
  const int equationIndexes[2] = {1,921};
  jacobian->tmpVars[88] /* $cse4.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[20] /* $cse69 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[1] /* rover_3d.psi.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 922
type: SIMPLE_ASSIGN
$DER.rover_3d.y.$pDERC.dummyVarC = rover_3d.vx * $cse4.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_922(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 131;
  const int equationIndexes[2] = {1,922};
  jacobian->tmpVars[28] /* der(rover_3d.y.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (jacobian->tmpVars[88] /* $cse4.$pDERC.dummyVarC JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 923
type: SIMPLE_ASSIGN
$cse3.$pDERC.dummyVarC = (-$cse68) * rover_3d.psi.SeedC
*/
void RoverExample_Components_Rover_eqFunction_923(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 132;
  const int equationIndexes[2] = {1,923};
  jacobian->tmpVars[78] /* $cse3.$pDERC.dummyVarC JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[21] /* $cse68 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[1] /* rover_3d.psi.SeedC SEED_VAR */);
  TRACE_POP
}

/*
equation index: 924
type: SIMPLE_ASSIGN
$DER.rover_3d.x.$pDERC.dummyVarC = rover_3d.vx * $cse3.$pDERC.dummyVarC
*/
void RoverExample_Components_Rover_eqFunction_924(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 133;
  const int equationIndexes[2] = {1,924};
  jacobian->tmpVars[27] /* der(rover_3d.x.$pDERC.dummyVarC) JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (jacobian->tmpVars[78] /* $cse3.$pDERC.dummyVarC JACOBIAN_TMP_VAR */);
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacC_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_C;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_C;
  RoverExample_Components_Rover_eqFunction_735(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_736(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_737(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_738(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_739(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_740(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_741(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_742(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_743(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_744(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_745(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_746(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_747(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_748(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_749(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_750(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_751(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_752(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_753(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_754(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_755(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_756(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_757(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_758(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_759(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_760(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_761(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_762(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_763(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_764(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_765(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_766(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_767(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_768(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_769(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_770(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_771(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_772(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_773(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_774(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_775(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_776(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_777(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_778(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_779(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_780(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_781(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_782(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_783(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_784(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_785(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_786(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_787(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_788(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_789(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_790(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_791(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_792(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_793(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_794(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_795(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_796(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_797(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_798(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_799(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_800(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_801(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_802(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_803(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_804(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_805(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_806(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_807(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_808(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_809(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_810(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_811(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_812(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_813(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_814(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_815(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_816(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_817(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_818(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_819(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_820(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_821(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_822(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_823(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_824(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_825(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_826(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_827(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_828(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_829(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_830(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_831(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_832(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_833(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_834(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_835(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_836(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_837(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_838(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_839(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_840(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_841(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_842(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_843(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_844(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_845(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_846(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_847(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_848(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_849(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_850(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_895(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_896(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_897(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_898(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_899(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_900(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_901(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_914(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_915(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_916(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_917(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_918(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_919(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_920(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_921(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_922(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_923(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_924(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 621
type: SIMPLE_ASSIGN
$cse64 = cosh(abs(rover_8d.vy_fr))
*/
void RoverExample_Components_Rover_eqFunction_621(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,621};
  jacobian->tmpVars[3] /* $cse64 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */)));
  TRACE_POP
}

/*
equation index: 622
type: SIMPLE_ASSIGN
$cse65 = cosh(abs(rover_8d.vx_fr))
*/
void RoverExample_Components_Rover_eqFunction_622(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,622};
  jacobian->tmpVars[2] /* $cse65 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */)));
  TRACE_POP
}

/*
equation index: 623
type: SIMPLE_ASSIGN
$cse66 = cosh(abs(rover_8d.vy_fl))
*/
void RoverExample_Components_Rover_eqFunction_623(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,623};
  jacobian->tmpVars[1] /* $cse66 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */)));
  TRACE_POP
}

/*
equation index: 624
type: SIMPLE_ASSIGN
$cse67 = cosh(abs(rover_8d.vx_fl))
*/
void RoverExample_Components_Rover_eqFunction_624(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,624};
  jacobian->tmpVars[0] /* $cse67 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */)));
  TRACE_POP
}

/*
equation index: 625
type: SIMPLE_ASSIGN
$DER.rover_3d.phi.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_625(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,625};
  jacobian->resultVars[0] /* der(rover_3d.phi.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 626
type: SIMPLE_ASSIGN
$DER.rover_3d.theta.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_626(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,626};
  jacobian->resultVars[2] /* der(rover_3d.theta.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 627
type: SIMPLE_ASSIGN
$DER.rover_8d.delta.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_627(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,627};
  jacobian->resultVars[13] /* der(rover_8d.delta.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 628
type: SIMPLE_ASSIGN
$DER.rover_8d.phi.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_628(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,628};
  jacobian->resultVars[24] /* der(rover_8d.phi.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 629
type: SIMPLE_ASSIGN
$DER.rover_8d.theta.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_629(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,629};
  jacobian->resultVars[28] /* der(rover_8d.theta.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 630
type: SIMPLE_ASSIGN
$DER.rover_8d.psi.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_630(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,630};
  jacobian->resultVars[25] /* der(rover_8d.psi.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 631
type: SIMPLE_ASSIGN
$DER.rover_8d.lambda.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_631(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,631};
  jacobian->resultVars[18] /* der(rover_8d.lambda.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 632
type: SIMPLE_ASSIGN
$DER.rover_8d.q.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_632(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,632};
  jacobian->resultVars[26] /* der(rover_8d.q.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 633
type: SIMPLE_ASSIGN
$DER.rover_8d.vz.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_633(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,633};
  jacobian->resultVars[31] /* der(rover_8d.vz.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 634
type: SIMPLE_ASSIGN
$DER.rover_8d.z.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_634(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,634};
  jacobian->resultVars[34] /* der(rover_8d.z.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 635
type: SIMPLE_ASSIGN
$DER.rover_3d.vz.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_635(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,635};
  jacobian->resultVars[4] /* der(rover_3d.vz.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 636
type: SIMPLE_ASSIGN
$DER.rover_3d.vy.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_636(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,636};
  jacobian->resultVars[3] /* der(rover_3d.vy.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 637
type: SIMPLE_ASSIGN
$DER.rover_3d.z.$pDERB.dummyVarB = 0.0
*/
void RoverExample_Components_Rover_eqFunction_637(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,637};
  jacobian->resultVars[7] /* der(rover_3d.z.$pDERB.dummyVarB) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 638
type: SIMPLE_ASSIGN
$DER.rover_3d.psi.$pDERB.dummyVarB = rover_3d.vx * $cse6.$pDERB.dummyVarB / rover_3d.l_total
*/
void RoverExample_Components_Rover_eqFunction_638(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,638};
  jacobian->resultVars[1] /* der(rover_3d.psi.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (DIVISION(jacobian->tmpVars[37] /* $cse6.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[55] /* rover_3d.l_total PARAM */),"rover_3d.l_total"));
  TRACE_POP
}

/*
equation index: 639
type: SIMPLE_ASSIGN
$DER.rover_3d.y.$pDERB.dummyVarB = rover_3d.vx * $cse4.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_639(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,639};
  jacobian->resultVars[6] /* der(rover_3d.y.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (jacobian->tmpVars[35] /* $cse4.$pDERB.dummyVarB JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 640
type: SIMPLE_ASSIGN
$DER.rover_3d.x.$pDERB.dummyVarB = rover_3d.vx * $cse3.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_640(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,640};
  jacobian->resultVars[5] /* der(rover_3d.x.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (jacobian->tmpVars[25] /* $cse3.$pDERB.dummyVarB JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 641
type: SIMPLE_ASSIGN
rover_8d.Vq.$pDERB.dummyVarB = 1.224744871391589 * rover_8d.Vs * $cse12.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_641(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,641};
  jacobian->tmpVars[103] /* rover_8d.Vq.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (1.224744871391589) * (((data->simulationInfo->realParameter[78] /* rover_8d.Vs PARAM */)) * (jacobian->tmpVars[7] /* $cse12.$pDERB.dummyVarB JACOBIAN_TMP_VAR */));
  TRACE_POP
}

/*
equation index: 642
type: SIMPLE_ASSIGN
$DER.rover_8d.Iq.$pDERB.dummyVarB = rover_8d.Vq.$pDERB.dummyVarB / rover_8d.Le
*/
void RoverExample_Components_Rover_eqFunction_642(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,642};
  jacobian->resultVars[8] /* der(rover_8d.Iq.$pDERB.dummyVarB) JACOBIAN_VAR */ = DIVISION(jacobian->tmpVars[103] /* rover_8d.Vq.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[72] /* rover_8d.Le PARAM */),"rover_8d.Le");
  TRACE_POP
}

/*
equation index: 643
type: SIMPLE_ASSIGN
rover_8d.vx_fl.$pDERB.dummyVarB = $cse15.$pDERB.dummyVarB * rover_8d.vx_rl + $cse16.$pDERB.dummyVarB * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_643(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,643};
  jacobian->tmpVars[148] /* rover_8d.vx_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[10] /* $cse15.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) + (jacobian->tmpVars[11] /* $cse16.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 644
type: SIMPLE_ASSIGN
$cse19.$pDERB.dummyVarB = sign(rover_8d.vx_fl) * rover_8d.vx_fl.$pDERB.dummyVarB / $cse67 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_644(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,644};
  modelica_real tmp194;
  tmp194 = jacobian->tmpVars[0] /* $cse67 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[14] /* $cse19.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * (DIVISION(jacobian->tmpVars[148] /* rover_8d.vx_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(tmp194 * tmp194),"$cse67 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 645
type: SIMPLE_ASSIGN
$cse18.$pDERB.dummyVarB = if noEvent($cse19 < 0.001) then 0.0 else if noEvent($cse19 > 1.0) then 0.0 else $cse19.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_645(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,645};
  modelica_boolean tmp195;
  modelica_boolean tmp196;
  modelica_boolean tmp197;
  modelica_real tmp198;
  tmp195 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */),0.001);
  tmp197 = (modelica_boolean)tmp195;
  if(tmp197)
  {
    tmp198 = 0.0;
  }
  else
  {
    tmp196 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */),1.0);
    tmp198 = (tmp196?0.0:jacobian->tmpVars[14] /* $cse19.$pDERB.dummyVarB JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[13] /* $cse18.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp198;
  TRACE_POP
}

/*
equation index: 646
type: SIMPLE_ASSIGN
rover_8d.vy_fl.$pDERB.dummyVarB = $cse15.$pDERB.dummyVarB * (rover_8d.vy + rover_8d.l_front * rover_8d.r) - $cse16.$pDERB.dummyVarB * rover_8d.vx_rl
*/
void RoverExample_Components_Rover_eqFunction_646(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,646};
  jacobian->tmpVars[152] /* rover_8d.vy_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[10] /* $cse15.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - ((jacobian->tmpVars[11] /* $cse16.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)));
  TRACE_POP
}

/*
equation index: 647
type: SIMPLE_ASSIGN
$cse20.$pDERB.dummyVarB = sign(rover_8d.vy_fl) * rover_8d.vy_fl.$pDERB.dummyVarB / $cse66 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_647(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,647};
  modelica_real tmp199;
  tmp199 = jacobian->tmpVars[1] /* $cse66 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[15] /* $cse20.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */))) * (DIVISION(jacobian->tmpVars[152] /* rover_8d.vy_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(tmp199 * tmp199),"$cse66 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 648
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fl.$pDERB.dummyVarB = (-$cse20) * rover_8d.vy_fl.$pDERB.dummyVarB / rover_8d.Lrely - $cse20.$pDERB.dummyVarB * rover_8d.vy_fl / rover_8d.Lrely - abs(rover_8d.vx_fl) * rover_8d.Lrely * ($cse17.$pDERB.dummyVarB * $cse18 - $cse17 * $cse18.$pDERB.dummyVarB) / (rover_8d.Lrely * $cse18) ^ 2.0 - sign(rover_8d.vx_fl) * rover_8d.vx_fl.$pDERB.dummyVarB * $cse17 / ($cse18 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_648(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,648};
  modelica_real tmp200;
  tmp200 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */));
  jacobian->resultVars[9] /* der(rover_8d.alpha_fl.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* $cse20 variable */))) * (DIVISION(jacobian->tmpVars[152] /* rover_8d.vy_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[15] /* $cse20.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[12] /* $cse17.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (jacobian->tmpVars[13] /* $cse18.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)),(tmp200 * tmp200),"(rover_8d.Lrely * $cse18) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * ((jacobian->tmpVars[148] /* rover_8d.vx_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse18 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 649
type: SIMPLE_ASSIGN
rover_8d.vx_fr.$pDERB.dummyVarB = $cse15.$pDERB.dummyVarB * rover_8d.vx_rr + $cse16.$pDERB.dummyVarB * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_649(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,649};
  jacobian->tmpVars[149] /* rover_8d.vx_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[10] /* $cse15.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) + (jacobian->tmpVars[11] /* $cse16.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 650
type: SIMPLE_ASSIGN
$cse23.$pDERB.dummyVarB = sign(rover_8d.vx_fr) * rover_8d.vx_fr.$pDERB.dummyVarB / $cse65 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_650(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,650};
  modelica_real tmp201;
  tmp201 = jacobian->tmpVars[2] /* $cse65 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[18] /* $cse23.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * (DIVISION(jacobian->tmpVars[149] /* rover_8d.vx_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(tmp201 * tmp201),"$cse65 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 651
type: SIMPLE_ASSIGN
$cse22.$pDERB.dummyVarB = if noEvent($cse23 < 0.001) then 0.0 else if noEvent($cse23 > 1.0) then 0.0 else $cse23.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_651(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,651};
  modelica_boolean tmp202;
  modelica_boolean tmp203;
  modelica_boolean tmp204;
  modelica_real tmp205;
  tmp202 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */),0.001);
  tmp204 = (modelica_boolean)tmp202;
  if(tmp204)
  {
    tmp205 = 0.0;
  }
  else
  {
    tmp203 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */),1.0);
    tmp205 = (tmp203?0.0:jacobian->tmpVars[18] /* $cse23.$pDERB.dummyVarB JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[17] /* $cse22.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp205;
  TRACE_POP
}

/*
equation index: 652
type: SIMPLE_ASSIGN
rover_8d.vy_fr.$pDERB.dummyVarB = $cse15.$pDERB.dummyVarB * (rover_8d.vy + rover_8d.l_front * rover_8d.r) - $cse16.$pDERB.dummyVarB * rover_8d.vx_rr
*/
void RoverExample_Components_Rover_eqFunction_652(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,652};
  jacobian->tmpVars[153] /* rover_8d.vy_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[10] /* $cse15.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) - ((jacobian->tmpVars[11] /* $cse16.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)));
  TRACE_POP
}

/*
equation index: 653
type: SIMPLE_ASSIGN
$cse24.$pDERB.dummyVarB = sign(rover_8d.vy_fr) * rover_8d.vy_fr.$pDERB.dummyVarB / $cse64 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_653(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 32;
  const int equationIndexes[2] = {1,653};
  modelica_real tmp206;
  tmp206 = jacobian->tmpVars[3] /* $cse64 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[19] /* $cse24.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */))) * (DIVISION(jacobian->tmpVars[153] /* rover_8d.vy_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(tmp206 * tmp206),"$cse64 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 654
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fr.$pDERB.dummyVarB = (-$cse24) * rover_8d.vy_fr.$pDERB.dummyVarB / rover_8d.Lrely - $cse24.$pDERB.dummyVarB * rover_8d.vy_fr / rover_8d.Lrely - abs(rover_8d.vx_fr) * rover_8d.Lrely * ($cse21.$pDERB.dummyVarB * $cse22 - $cse21 * $cse22.$pDERB.dummyVarB) / (rover_8d.Lrely * $cse22) ^ 2.0 - sign(rover_8d.vx_fr) * rover_8d.vx_fr.$pDERB.dummyVarB * $cse21 / ($cse22 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_654(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 33;
  const int equationIndexes[2] = {1,654};
  modelica_real tmp207;
  tmp207 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */));
  jacobian->resultVars[10] /* der(rover_8d.alpha_fr.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* $cse24 variable */))) * (DIVISION(jacobian->tmpVars[153] /* rover_8d.vy_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[19] /* $cse24.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[16] /* $cse21.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (jacobian->tmpVars[17] /* $cse22.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)),(tmp207 * tmp207),"(rover_8d.Lrely * $cse22) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * ((jacobian->tmpVars[149] /* rover_8d.vx_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse22 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 655
type: SIMPLE_ASSIGN
$cse26.$pDERB.dummyVarB = if noEvent($cse27 < 0.001) then 0.0 else if noEvent($cse27 > 1.0) then 0.0 else $cse27.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_655(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 34;
  const int equationIndexes[2] = {1,655};
  modelica_boolean tmp208;
  modelica_boolean tmp209;
  modelica_boolean tmp210;
  modelica_real tmp211;
  tmp208 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */),0.001);
  tmp210 = (modelica_boolean)tmp208;
  if(tmp210)
  {
    tmp211 = 0.0;
  }
  else
  {
    tmp209 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */),1.0);
    tmp211 = (tmp209?0.0:jacobian->tmpVars[22] /* $cse27.$pDERB.dummyVarB JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[21] /* $cse26.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp211;
  TRACE_POP
}

/*
equation index: 656
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rl.$pDERB.dummyVarB = abs(rover_8d.vx_rl) * ($cse25 * $cse26.$pDERB.dummyVarB * rover_8d.Lrely - $cse25.$pDERB.dummyVarB * $cse26 * rover_8d.Lrely) / ($cse26 * rover_8d.Lrely) ^ 2.0 - $cse28.$pDERB.dummyVarB * rover_8d.vy_rr / rover_8d.Lrely
*/
void RoverExample_Components_Rover_eqFunction_656(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 35;
  const int equationIndexes[2] = {1,656};
  modelica_real tmp212;
  tmp212 = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */));
  jacobian->resultVars[11] /* der(rover_8d.alpha_rl.$pDERB.dummyVarB) JACOBIAN_VAR */ = (fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */))) * (DIVISION(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * ((jacobian->tmpVars[21] /* $cse26.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */))) - ((jacobian->tmpVars[20] /* $cse25.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)))),(tmp212 * tmp212),"($cse26 * rover_8d.Lrely) ^ 2.0")) - ((jacobian->tmpVars[23] /* $cse28.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")));
  TRACE_POP
}

/*
equation index: 657
type: SIMPLE_ASSIGN
rover_8d.vs_rl.$pDERB.dummyVarB = rover_8d.vx_rl * $cse25 * $cse25.$pDERB.dummyVarB / sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_657(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 36;
  const int equationIndexes[2] = {1,657};
  modelica_real tmp213;
  modelica_real tmp214;
  modelica_real tmp215;
  tmp213 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  tmp214 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */);
  tmp215 = (tmp213 * tmp213) + (tmp214 * tmp214);
  if(!(tmp215 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0) was %g should be >= 0", tmp215);
    }
  }
  jacobian->tmpVars[146] /* rover_8d.vs_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION(jacobian->tmpVars[20] /* $cse25.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,sqrt(tmp215),"sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0)")));
  TRACE_POP
}

/*
equation index: 658
type: SIMPLE_ASSIGN
rover_8d.mu_rl.$pDERB.dummyVarB = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rl) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rl) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_rl.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_658(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 37;
  const int equationIndexes[2] = {1,658};
  modelica_boolean tmp216;
  modelica_boolean tmp217;
  modelica_boolean tmp218;
  modelica_real tmp219;
  tmp216 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */)))),0.0);
  tmp218 = (modelica_boolean)tmp216;
  if(tmp218)
  {
    tmp219 = 0.0;
  }
  else
  {
    tmp217 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp219 = (tmp217?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[146] /* rover_8d.vs_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[138] /* rover_8d.mu_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp219;
  TRACE_POP
}

/*
equation index: 659
type: SIMPLE_ASSIGN
rover_8d.vs_fl.$pDERB.dummyVarB = rover_8d.vx_rl * $cse17 * $cse17.$pDERB.dummyVarB / sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_659(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 38;
  const int equationIndexes[2] = {1,659};
  modelica_real tmp220;
  modelica_real tmp221;
  modelica_real tmp222;
  tmp220 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  tmp221 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */);
  tmp222 = (tmp220 * tmp220) + (tmp221 * tmp221);
  if(!(tmp222 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0) was %g should be >= 0", tmp222);
    }
  }
  jacobian->tmpVars[144] /* rover_8d.vs_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION(jacobian->tmpVars[12] /* $cse17.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,sqrt(tmp222),"sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0)")));
  TRACE_POP
}

/*
equation index: 660
type: SIMPLE_ASSIGN
rover_8d.mu_fl.$pDERB.dummyVarB = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fl) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fl) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_fl.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_660(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 39;
  const int equationIndexes[2] = {1,660};
  modelica_boolean tmp223;
  modelica_boolean tmp224;
  modelica_boolean tmp225;
  modelica_real tmp226;
  tmp223 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */)))),0.0);
  tmp225 = (modelica_boolean)tmp223;
  if(tmp225)
  {
    tmp226 = 0.0;
  }
  else
  {
    tmp224 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp226 = (tmp224?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[144] /* rover_8d.vs_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[136] /* rover_8d.mu_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp226;
  TRACE_POP
}

/*
equation index: 661
type: SIMPLE_ASSIGN
$cse30.$pDERB.dummyVarB = if noEvent($cse31 < 0.001) then 0.0 else if noEvent($cse31 > 1.0) then 0.0 else $cse31.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_661(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 40;
  const int equationIndexes[2] = {1,661};
  modelica_boolean tmp227;
  modelica_boolean tmp228;
  modelica_boolean tmp229;
  modelica_real tmp230;
  tmp227 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */),0.001);
  tmp229 = (modelica_boolean)tmp227;
  if(tmp229)
  {
    tmp230 = 0.0;
  }
  else
  {
    tmp228 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */),1.0);
    tmp230 = (tmp228?0.0:jacobian->tmpVars[27] /* $cse31.$pDERB.dummyVarB JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[26] /* $cse30.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp230;
  TRACE_POP
}

/*
equation index: 662
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rr.$pDERB.dummyVarB = (-$cse28.$pDERB.dummyVarB) * rover_8d.vy_rr / rover_8d.Lrely - abs(rover_8d.vx_rr) * rover_8d.Lrely * ($cse29.$pDERB.dummyVarB * $cse30 - $cse29 * $cse30.$pDERB.dummyVarB) / (rover_8d.Lrely * $cse30) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_662(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 41;
  const int equationIndexes[2] = {1,662};
  modelica_real tmp231;
  tmp231 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */));
  jacobian->resultVars[12] /* der(rover_8d.alpha_rr.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((-jacobian->tmpVars[23] /* $cse28.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[24] /* $cse29.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (jacobian->tmpVars[26] /* $cse30.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)),(tmp231 * tmp231),"(rover_8d.Lrely * $cse30) ^ 2.0"))));
  TRACE_POP
}

/*
equation index: 663
type: SIMPLE_ASSIGN
rover_8d.vs_rr.$pDERB.dummyVarB = rover_8d.vx_rr * $cse29 * $cse29.$pDERB.dummyVarB / sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_663(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 42;
  const int equationIndexes[2] = {1,663};
  modelica_real tmp232;
  modelica_real tmp233;
  modelica_real tmp234;
  tmp232 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  tmp233 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */);
  tmp234 = (tmp232 * tmp232) + (tmp233 * tmp233);
  if(!(tmp234 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0) was %g should be >= 0", tmp234);
    }
  }
  jacobian->tmpVars[147] /* rover_8d.vs_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION(jacobian->tmpVars[24] /* $cse29.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,sqrt(tmp234),"sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0)")));
  TRACE_POP
}

/*
equation index: 664
type: SIMPLE_ASSIGN
rover_8d.mu_rr.$pDERB.dummyVarB = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rr) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rr) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_rr.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_664(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 43;
  const int equationIndexes[2] = {1,664};
  modelica_boolean tmp235;
  modelica_boolean tmp236;
  modelica_boolean tmp237;
  modelica_real tmp238;
  tmp235 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */)))),0.0);
  tmp237 = (modelica_boolean)tmp235;
  if(tmp237)
  {
    tmp238 = 0.0;
  }
  else
  {
    tmp236 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp238 = (tmp236?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[147] /* rover_8d.vs_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[139] /* rover_8d.mu_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp238;
  TRACE_POP
}

/*
equation index: 665
type: SIMPLE_ASSIGN
rover_8d.vs_fr.$pDERB.dummyVarB = rover_8d.vx_rr * $cse21 * $cse21.$pDERB.dummyVarB / sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_665(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 44;
  const int equationIndexes[2] = {1,665};
  modelica_real tmp239;
  modelica_real tmp240;
  modelica_real tmp241;
  tmp239 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  tmp240 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */);
  tmp241 = (tmp239 * tmp239) + (tmp240 * tmp240);
  if(!(tmp241 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0) was %g should be >= 0", tmp241);
    }
  }
  jacobian->tmpVars[145] /* rover_8d.vs_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION(jacobian->tmpVars[16] /* $cse21.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,sqrt(tmp241),"sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0)")));
  TRACE_POP
}

/*
equation index: 666
type: SIMPLE_ASSIGN
rover_8d.mu_fr.$pDERB.dummyVarB = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fr) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fr) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_fr.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_666(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 45;
  const int equationIndexes[2] = {1,666};
  modelica_boolean tmp242;
  modelica_boolean tmp243;
  modelica_boolean tmp244;
  modelica_real tmp245;
  tmp242 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */)))),0.0);
  tmp244 = (modelica_boolean)tmp242;
  if(tmp244)
  {
    tmp245 = 0.0;
  }
  else
  {
    tmp243 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp245 = (tmp243?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[145] /* rover_8d.vs_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[137] /* rover_8d.mu_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp245;
  TRACE_POP
}

/*
equation index: 711
type: LINEAR

<var>rover_8d.fz_rl.$pDERB.dummyVarB</var>
<var>rover_8d.fz_fl.$pDERB.dummyVarB</var>
<var>rover_8d.fz_rr.$pDERB.dummyVarB</var>
<var>rover_8d.fz_fr.$pDERB.dummyVarB</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_711(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 46;
  const int equationIndexes[2] = {1,711};
  /* Linear equation system */
  int retValue;
  double aux_x[4] = { jacobian->tmpVars[118] /* rover_8d.fz_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,jacobian->tmpVars[116] /* rover_8d.fz_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,jacobian->tmpVars[119] /* rover_8d.fz_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,jacobian->tmpVars[117] /* rover_8d.fz_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 711 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  data->simulationInfo->linearSystemData[6].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 6, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,711};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 711 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[118] /* rover_8d.fz_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = aux_x[0];
  jacobian->tmpVars[116] /* rover_8d.fz_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = aux_x[1];
  jacobian->tmpVars[119] /* rover_8d.fz_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = aux_x[2];
  jacobian->tmpVars[117] /* rover_8d.fz_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = aux_x[3];

  TRACE_POP
}

/*
equation index: 712
type: SIMPLE_ASSIGN
$DER.rover_8d.p.$pDERB.dummyVarB = rover_8d.mass_sprung * (9.80665 * $cse36.$pDERB.dummyVarB + (-rover_8d.ay) * $cse37.$pDERB.dummyVarB - rover_8d.ay.$pDERB.dummyVarB * $cse37) * rover_8d.hs / rover_8d.I_xx
*/
void RoverExample_Components_Rover_eqFunction_712(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 47;
  const int equationIndexes[2] = {1,712};
  jacobian->resultVars[23] /* der(rover_8d.p.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((9.80665) * (jacobian->tmpVars[32] /* $cse36.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */))) * (jacobian->tmpVars[33] /* $cse37.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[109] /* rover_8d.ay.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* $cse37 variable */)))) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[65] /* rover_8d.I_xx PARAM */),"rover_8d.I_xx")));
  TRACE_POP
}

/*
equation index: 713
type: SIMPLE_ASSIGN
$DER.rover_8d.r.$pDERB.dummyVarB = (0.5 * (rover_8d.Fx_fl * $cse34.$pDERB.dummyVarB + rover_8d.Fx_fl.$pDERB.dummyVarB * $cse34 + rover_8d.Fy_fl * $cse35.$pDERB.dummyVarB + rover_8d.Fy_fl.$pDERB.dummyVarB * $cse35 + rover_8d.Fx_rl.$pDERB.dummyVarB + (-rover_8d.Fx_fr) * $cse34.$pDERB.dummyVarB - rover_8d.Fx_fr.$pDERB.dummyVarB * $cse34 - rover_8d.Fy_fr.$pDERB.dummyVarB * $cse35 - rover_8d.Fy_fr * $cse35.$pDERB.dummyVarB - rover_8d.Fx_rr.$pDERB.dummyVarB) * rover_8d.tw + rover_8d.l_front * (rover_8d.Fy_fl * $cse34.$pDERB.dummyVarB + rover_8d.Fy_fl.$pDERB.dummyVarB * $cse34 + (-rover_8d.Fx_fl) * $cse35.$pDERB.dummyVarB - rover_8d.Fx_fl.$pDERB.dummyVarB * $cse35) + rover_8d.l_front * (rover_8d.Fy_fr * $cse34.$pDERB.dummyVarB + rover_8d.Fy_fr.$pDERB.dummyVarB * $cse34 + (-rover_8d.Fx_fr) * $cse35.$pDERB.dummyVarB - rover_8d.Fx_fr.$pDERB.dummyVarB * $cse35) - rover_8d.l_rear * (rover_8d.Fy_rl.$pDERB.dummyVarB + rover_8d.Fy_rr.$pDERB.dummyVarB)) / rover_8d.I_zz
*/
void RoverExample_Components_Rover_eqFunction_713(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 48;
  const int equationIndexes[2] = {1,713};
  jacobian->resultVars[27] /* der(rover_8d.r.$pDERB.dummyVarB) JACOBIAN_VAR */ = DIVISION((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * (jacobian->tmpVars[30] /* $cse34.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[89] /* rover_8d.Fx_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (jacobian->tmpVars[31] /* $cse35.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[93] /* rover_8d.Fy_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + jacobian->tmpVars[91] /* rover_8d.Fx_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))) * (jacobian->tmpVars[30] /* $cse34.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[90] /* rover_8d.Fx_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */))) - ((jacobian->tmpVars[94] /* rover_8d.Fy_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (jacobian->tmpVars[31] /* $cse35.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)) - jacobian->tmpVars[92] /* rover_8d.Fx_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (jacobian->tmpVars[30] /* $cse34.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[93] /* rover_8d.Fy_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */))) * (jacobian->tmpVars[31] /* $cse35.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[89] /* rover_8d.Fx_fl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (jacobian->tmpVars[30] /* $cse34.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[94] /* rover_8d.Fy_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))) * (jacobian->tmpVars[31] /* $cse35.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[90] /* rover_8d.Fx_fr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) - (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (jacobian->tmpVars[95] /* rover_8d.Fy_rl.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ + jacobian->tmpVars[96] /* rover_8d.Fy_rr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[66] /* rover_8d.I_zz PARAM */),"rover_8d.I_zz");
  TRACE_POP
}

/*
equation index: 714
type: SIMPLE_ASSIGN
$DER.rover_8d.vy.$pDERB.dummyVarB = rover_8d.ay.$pDERB.dummyVarB + (rover_8d.l_rear * rover_8d.mass_unsprung_rear - rover_8d.l_front * rover_8d.mass_unsprung_front) * $DER.rover_8d.r.$pDERB.dummyVarB / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_714(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 49;
  const int equationIndexes[2] = {1,714};
  jacobian->resultVars[30] /* der(rover_8d.vy.$pDERB.dummyVarB) JACOBIAN_VAR */ = jacobian->tmpVars[109] /* rover_8d.ay.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ + (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) - (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)))) * (DIVISION(jacobian->resultVars[27] /* der(rover_8d.r.$pDERB.dummyVarB) JACOBIAN_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total"));
  TRACE_POP
}

/*
equation index: 727
type: LINEAR

<var>rover_8d.thr.$pDERB.dummyVarB</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_727(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 50;
  const int equationIndexes[2] = {1,727};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { jacobian->tmpVars[143] /* rover_8d.thr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 727 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  data->simulationInfo->linearSystemData[7].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 7, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,727};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 727 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[143] /* rover_8d.thr.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = aux_x[0];

  TRACE_POP
}

/*
equation index: 728
type: SIMPLE_ASSIGN
$DER.rover_8d.x.$pDERB.dummyVarB = rover_8d.vx * $cse32.$pDERB.dummyVarB - rover_8d.vy * $cse33.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_728(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 51;
  const int equationIndexes[2] = {1,728};
  jacobian->resultVars[32] /* der(rover_8d.x.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (jacobian->tmpVars[28] /* $cse32.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (jacobian->tmpVars[29] /* $cse33.$pDERB.dummyVarB JACOBIAN_TMP_VAR */));
  TRACE_POP
}

/*
equation index: 729
type: SIMPLE_ASSIGN
$DER.rover_8d.y.$pDERB.dummyVarB = rover_8d.vx * $cse33.$pDERB.dummyVarB + rover_8d.vy * $cse32.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_729(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 52;
  const int equationIndexes[2] = {1,729};
  jacobian->resultVars[33] /* der(rover_8d.y.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (jacobian->tmpVars[29] /* $cse33.$pDERB.dummyVarB JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (jacobian->tmpVars[28] /* $cse32.$pDERB.dummyVarB JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 730
type: SIMPLE_ASSIGN
$cse13.$pDERB.dummyVarB = if noEvent($cse14 < 0.001) then 0.0 else if noEvent($cse14 > 1.0) then 0.0 else $cse14.$pDERB.dummyVarB
*/
void RoverExample_Components_Rover_eqFunction_730(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 53;
  const int equationIndexes[2] = {1,730};
  modelica_boolean tmp246;
  modelica_boolean tmp247;
  modelica_boolean tmp248;
  modelica_real tmp249;
  tmp246 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */),0.001);
  tmp248 = (modelica_boolean)tmp246;
  if(tmp248)
  {
    tmp249 = 0.0;
  }
  else
  {
    tmp247 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */),1.0);
    tmp249 = (tmp247?0.0:jacobian->tmpVars[9] /* $cse14.$pDERB.dummyVarB JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[8] /* $cse13.$pDERB.dummyVarB JACOBIAN_TMP_VAR */ = tmp249;
  TRACE_POP
}

/*
equation index: 731
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rr.$pDERB.dummyVarB = (-abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r)) * (-rover_8d.kappa_rr) * rover_8d.Lrelx * $cse13.$pDERB.dummyVarB / (rover_8d.Lrelx * $cse13) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_731(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 54;
  const int equationIndexes[2] = {1,731};
  modelica_real tmp250;
  tmp250 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->resultVars[17] /* der(rover_8d.kappa_rr.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))))) * (((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION(jacobian->tmpVars[8] /* $cse13.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(tmp250 * tmp250),"(rover_8d.Lrelx * $cse13) ^ 2.0"))));
  TRACE_POP
}

/*
equation index: 732
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rl.$pDERB.dummyVarB = (-abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r)) * (-rover_8d.kappa_rl) * rover_8d.Lrelx * $cse13.$pDERB.dummyVarB / (rover_8d.Lrelx * $cse13) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_732(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 55;
  const int equationIndexes[2] = {1,732};
  modelica_real tmp251;
  tmp251 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->resultVars[16] /* der(rover_8d.kappa_rl.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION(jacobian->tmpVars[8] /* $cse13.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(tmp251 * tmp251),"(rover_8d.Lrelx * $cse13) ^ 2.0"))));
  TRACE_POP
}

/*
equation index: 733
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fr.$pDERB.dummyVarB = (-abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r)) * (-rover_8d.kappa_fr) * rover_8d.Lrelx * $cse13.$pDERB.dummyVarB / (rover_8d.Lrelx * $cse13) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_733(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 56;
  const int equationIndexes[2] = {1,733};
  modelica_real tmp252;
  tmp252 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->resultVars[15] /* der(rover_8d.kappa_fr.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))))) * (((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION(jacobian->tmpVars[8] /* $cse13.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(tmp252 * tmp252),"(rover_8d.Lrelx * $cse13) ^ 2.0"))));
  TRACE_POP
}

/*
equation index: 734
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fl.$pDERB.dummyVarB = (-abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r)) * (-rover_8d.kappa_fl) * rover_8d.Lrelx * $cse13.$pDERB.dummyVarB / (rover_8d.Lrelx * $cse13) ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_734(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 57;
  const int equationIndexes[2] = {1,734};
  modelica_real tmp253;
  tmp253 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->resultVars[14] /* der(rover_8d.kappa_fl.$pDERB.dummyVarB) JACOBIAN_VAR */ = ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION(jacobian->tmpVars[8] /* $cse13.$pDERB.dummyVarB JACOBIAN_TMP_VAR */,(tmp253 * tmp253),"(rover_8d.Lrelx * $cse13) ^ 2.0"))));
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacB_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_B;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_B;
  RoverExample_Components_Rover_eqFunction_621(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_622(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_623(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_624(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_625(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_626(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_627(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_628(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_629(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_630(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_631(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_632(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_633(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_634(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_635(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_636(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_637(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_638(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_639(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_640(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_641(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_642(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_643(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_644(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_645(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_646(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_647(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_648(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_649(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_650(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_651(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_652(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_653(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_654(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_655(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_656(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_657(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_658(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_659(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_660(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_661(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_662(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_663(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_664(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_665(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_666(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_711(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_712(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_713(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_714(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_727(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_728(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_729(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_730(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_731(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_732(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_733(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_734(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 459
type: SIMPLE_ASSIGN
$cse42 = sin(rover_3d.psi)
*/
void RoverExample_Components_Rover_eqFunction_459(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,459};
  jacobian->tmpVars[21] /* $cse42 JACOBIAN_TMP_VAR */ = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */));
  TRACE_POP
}

/*
equation index: 460
type: SIMPLE_ASSIGN
$cse43 = cos(rover_3d.psi)
*/
void RoverExample_Components_Rover_eqFunction_460(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,460};
  jacobian->tmpVars[20] /* $cse43 JACOBIAN_TMP_VAR */ = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* rover_3d.psi STATE(1) */));
  TRACE_POP
}

/*
equation index: 461
type: SIMPLE_ASSIGN
$cse44 = cosh(abs(rover_8d.vx))
*/
void RoverExample_Components_Rover_eqFunction_461(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,461};
  jacobian->tmpVars[19] /* $cse44 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)));
  TRACE_POP
}

/*
equation index: 462
type: SIMPLE_ASSIGN
$cse45 = sin(rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_462(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,462};
  jacobian->tmpVars[18] /* $cse45 JACOBIAN_TMP_VAR */ = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */));
  TRACE_POP
}

/*
equation index: 463
type: SIMPLE_ASSIGN
$cse46 = cos(rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_463(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,463};
  jacobian->tmpVars[17] /* $cse46 JACOBIAN_TMP_VAR */ = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */));
  TRACE_POP
}

/*
equation index: 464
type: SIMPLE_ASSIGN
$cse47 = cos(2.0 * rover_8d.alpha_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_464(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,464};
  jacobian->tmpVars[16] /* $cse47 JACOBIAN_TMP_VAR */ = cos((2.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[178]] /* rover_8d.alpha_fl_bnd variable */)));
  TRACE_POP
}

/*
equation index: 465
type: SIMPLE_ASSIGN
$cse48 = cos(2.0 * rover_8d.alpha_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_465(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,465};
  jacobian->tmpVars[15] /* $cse48 JACOBIAN_TMP_VAR */ = cos((2.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* rover_8d.alpha_fr_bnd variable */)));
  TRACE_POP
}

/*
equation index: 466
type: SIMPLE_ASSIGN
$cse49 = cos(2.0 * rover_8d.alpha_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_466(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,466};
  jacobian->tmpVars[14] /* $cse49 JACOBIAN_TMP_VAR */ = cos((2.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[180]] /* rover_8d.alpha_rl_bnd variable */)));
  TRACE_POP
}

/*
equation index: 467
type: SIMPLE_ASSIGN
$cse50 = cos(2.0 * rover_8d.alpha_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_467(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,467};
  jacobian->tmpVars[13] /* $cse50 JACOBIAN_TMP_VAR */ = cos((2.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[181]] /* rover_8d.alpha_rr_bnd variable */)));
  TRACE_POP
}

/*
equation index: 468
type: SIMPLE_ASSIGN
$cse51 = sin(rover_8d.psi)
*/
void RoverExample_Components_Rover_eqFunction_468(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,468};
  jacobian->tmpVars[12] /* $cse51 JACOBIAN_TMP_VAR */ = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  TRACE_POP
}

/*
equation index: 469
type: SIMPLE_ASSIGN
$cse52 = cos(rover_8d.psi)
*/
void RoverExample_Components_Rover_eqFunction_469(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,469};
  jacobian->tmpVars[11] /* $cse52 JACOBIAN_TMP_VAR */ = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* rover_8d.psi STATE(1,rover_8d.r) */));
  TRACE_POP
}

/*
equation index: 470
type: SIMPLE_ASSIGN
$cse53 = sin(-rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_470(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,470};
  jacobian->tmpVars[10] /* $cse53 JACOBIAN_TMP_VAR */ = sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)));
  TRACE_POP
}

/*
equation index: 471
type: SIMPLE_ASSIGN
$cse54 = cos(-rover_8d.delta)
*/
void RoverExample_Components_Rover_eqFunction_471(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,471};
  jacobian->tmpVars[9] /* $cse54 JACOBIAN_TMP_VAR */ = cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)));
  TRACE_POP
}

/*
equation index: 472
type: SIMPLE_ASSIGN
$cse55 = cos(rover_8d.phi)
*/
void RoverExample_Components_Rover_eqFunction_472(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,472};
  jacobian->tmpVars[8] /* $cse55 JACOBIAN_TMP_VAR */ = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */));
  TRACE_POP
}

/*
equation index: 473
type: SIMPLE_ASSIGN
$cse56 = sin(rover_8d.phi)
*/
void RoverExample_Components_Rover_eqFunction_473(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,473};
  jacobian->tmpVars[7] /* $cse56 JACOBIAN_TMP_VAR */ = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */));
  TRACE_POP
}

/*
equation index: 474
type: SIMPLE_ASSIGN
$cse57 = cosh(abs(rover_8d.vx_rr))
*/
void RoverExample_Components_Rover_eqFunction_474(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,474};
  jacobian->tmpVars[6] /* $cse57 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)));
  TRACE_POP
}

/*
equation index: 475
type: SIMPLE_ASSIGN
$cse58 = cosh(abs(rover_8d.vy_rr))
*/
void RoverExample_Components_Rover_eqFunction_475(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,475};
  jacobian->tmpVars[5] /* $cse58 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */)));
  TRACE_POP
}

/*
equation index: 476
type: SIMPLE_ASSIGN
$cse59 = cosh(abs(rover_8d.vx_rl))
*/
void RoverExample_Components_Rover_eqFunction_476(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,476};
  jacobian->tmpVars[4] /* $cse59 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)));
  TRACE_POP
}

/*
equation index: 477
type: SIMPLE_ASSIGN
$cse60 = cosh(abs(rover_8d.vy_fr))
*/
void RoverExample_Components_Rover_eqFunction_477(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,477};
  jacobian->tmpVars[3] /* $cse60 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */)));
  TRACE_POP
}

/*
equation index: 478
type: SIMPLE_ASSIGN
$cse61 = cosh(abs(rover_8d.vx_fr))
*/
void RoverExample_Components_Rover_eqFunction_478(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,478};
  jacobian->tmpVars[2] /* $cse61 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */)));
  TRACE_POP
}

/*
equation index: 479
type: SIMPLE_ASSIGN
$cse62 = cosh(abs(rover_8d.vy_fl))
*/
void RoverExample_Components_Rover_eqFunction_479(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,479};
  jacobian->tmpVars[1] /* $cse62 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */)));
  TRACE_POP
}

/*
equation index: 480
type: SIMPLE_ASSIGN
$cse63 = cosh(abs(rover_8d.vx_fl))
*/
void RoverExample_Components_Rover_eqFunction_480(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,480};
  jacobian->tmpVars[0] /* $cse63 JACOBIAN_TMP_VAR */ = cosh(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */)));
  TRACE_POP
}

/*
equation index: 481
type: SIMPLE_ASSIGN
$DER.rover_3d.phi.$pDERA.dummyVarA = 0.0
*/
void RoverExample_Components_Rover_eqFunction_481(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,481};
  jacobian->resultVars[0] /* der(rover_3d.phi.$pDERA.dummyVarA) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 482
type: SIMPLE_ASSIGN
$DER.rover_3d.theta.$pDERA.dummyVarA = 0.0
*/
void RoverExample_Components_Rover_eqFunction_482(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,482};
  jacobian->resultVars[2] /* der(rover_3d.theta.$pDERA.dummyVarA) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 483
type: SIMPLE_ASSIGN
$DER.rover_8d.phi.$pDERA.dummyVarA = rover_8d.p.SeedA
*/
void RoverExample_Components_Rover_eqFunction_483(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,483};
  jacobian->resultVars[24] /* der(rover_8d.phi.$pDERA.dummyVarA) JACOBIAN_VAR */ = jacobian->seedVars[23] /* rover_8d.p.SeedA SEED_VAR */;
  TRACE_POP
}

/*
equation index: 484
type: SIMPLE_ASSIGN
$DER.rover_8d.theta.$pDERA.dummyVarA = 0.0
*/
void RoverExample_Components_Rover_eqFunction_484(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,484};
  jacobian->resultVars[28] /* der(rover_8d.theta.$pDERA.dummyVarA) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 485
type: SIMPLE_ASSIGN
$DER.rover_8d.psi.$pDERA.dummyVarA = rover_8d.r.SeedA
*/
void RoverExample_Components_Rover_eqFunction_485(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,485};
  jacobian->resultVars[25] /* der(rover_8d.psi.$pDERA.dummyVarA) JACOBIAN_VAR */ = jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */;
  TRACE_POP
}

/*
equation index: 486
type: SIMPLE_ASSIGN
$DER.rover_8d.q.$pDERA.dummyVarA = 0.0
*/
void RoverExample_Components_Rover_eqFunction_486(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,486};
  jacobian->resultVars[26] /* der(rover_8d.q.$pDERA.dummyVarA) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 487
type: SIMPLE_ASSIGN
$DER.rover_8d.vz.$pDERA.dummyVarA = 0.0
*/
void RoverExample_Components_Rover_eqFunction_487(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,487};
  jacobian->resultVars[31] /* der(rover_8d.vz.$pDERA.dummyVarA) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 488
type: SIMPLE_ASSIGN
$DER.rover_8d.z.$pDERA.dummyVarA = 0.0
*/
void RoverExample_Components_Rover_eqFunction_488(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,488};
  jacobian->resultVars[34] /* der(rover_8d.z.$pDERA.dummyVarA) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 489
type: SIMPLE_ASSIGN
$DER.rover_3d.vz.$pDERA.dummyVarA = 0.0
*/
void RoverExample_Components_Rover_eqFunction_489(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,489};
  jacobian->resultVars[4] /* der(rover_3d.vz.$pDERA.dummyVarA) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 490
type: SIMPLE_ASSIGN
$DER.rover_3d.vy.$pDERA.dummyVarA = 0.0
*/
void RoverExample_Components_Rover_eqFunction_490(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,490};
  jacobian->resultVars[3] /* der(rover_3d.vy.$pDERA.dummyVarA) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 491
type: SIMPLE_ASSIGN
$DER.rover_3d.z.$pDERA.dummyVarA = 0.0
*/
void RoverExample_Components_Rover_eqFunction_491(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 32;
  const int equationIndexes[2] = {1,491};
  jacobian->resultVars[7] /* der(rover_3d.z.$pDERA.dummyVarA) JACOBIAN_VAR */ = 0.0;
  TRACE_POP
}

/*
equation index: 492
type: SIMPLE_ASSIGN
$DER.rover_3d.psi.$pDERA.dummyVarA = rover_3d.vx * $cse6.$pDERA.dummyVarA / rover_3d.l_total
*/
void RoverExample_Components_Rover_eqFunction_492(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 33;
  const int equationIndexes[2] = {1,492};
  jacobian->resultVars[1] /* der(rover_3d.psi.$pDERA.dummyVarA) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (DIVISION(jacobian->tmpVars[55] /* $cse6.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[55] /* rover_3d.l_total PARAM */),"rover_3d.l_total"));
  TRACE_POP
}

/*
equation index: 493
type: SIMPLE_ASSIGN
rover_8d.Vq.$pDERA.dummyVarA = 1.224744871391589 * rover_8d.Vs * $cse12.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_493(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 34;
  const int equationIndexes[2] = {1,493};
  jacobian->tmpVars[121] /* rover_8d.Vq.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (1.224744871391589) * (((data->simulationInfo->realParameter[78] /* rover_8d.Vs PARAM */)) * (jacobian->tmpVars[25] /* $cse12.$pDERA.dummyVarA JACOBIAN_TMP_VAR */));
  TRACE_POP
}

/*
equation index: 494
type: SIMPLE_ASSIGN
$DER.rover_8d.delta.$pDERA.dummyVarA = (-rover_8d.delta.SeedA) / rover_8d.tau_servo
*/
void RoverExample_Components_Rover_eqFunction_494(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 35;
  const int equationIndexes[2] = {1,494};
  jacobian->resultVars[13] /* der(rover_8d.delta.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION((-jacobian->seedVars[13] /* rover_8d.delta.SeedA SEED_VAR */),(data->simulationInfo->realParameter[125] /* rover_8d.tau_servo PARAM */),"rover_8d.tau_servo");
  TRACE_POP
}

/*
equation index: 495
type: SIMPLE_ASSIGN
rover_8d.vx_rl.$pDERA.dummyVarA = rover_8d.vx.SeedA + 0.5 * rover_8d.tw * rover_8d.r.SeedA
*/
void RoverExample_Components_Rover_eqFunction_495(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 36;
  const int equationIndexes[2] = {1,495};
  jacobian->tmpVars[168] /* rover_8d.vx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */ + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */));
  TRACE_POP
}

/*
equation index: 496
type: SIMPLE_ASSIGN
$cse27.$pDERA.dummyVarA = sign(rover_8d.vx_rl) * rover_8d.vx_rl.$pDERA.dummyVarA / $cse59 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_496(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 37;
  const int equationIndexes[2] = {1,496};
  modelica_real tmp254;
  tmp254 = jacobian->tmpVars[4] /* $cse59 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[40] /* $cse27.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */))) * (DIVISION(jacobian->tmpVars[168] /* rover_8d.vx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(tmp254 * tmp254),"$cse59 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 497
type: SIMPLE_ASSIGN
$cse26.$pDERA.dummyVarA = if noEvent($cse27 < 0.001) then 0.0 else if noEvent($cse27 > 1.0) then 0.0 else $cse27.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_497(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 38;
  const int equationIndexes[2] = {1,497};
  modelica_boolean tmp255;
  modelica_boolean tmp256;
  modelica_boolean tmp257;
  modelica_real tmp258;
  tmp255 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */),0.001);
  tmp257 = (modelica_boolean)tmp255;
  if(tmp257)
  {
    tmp258 = 0.0;
  }
  else
  {
    tmp256 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* $cse27 variable */),1.0);
    tmp258 = (tmp256?0.0:jacobian->tmpVars[40] /* $cse27.$pDERA.dummyVarA JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[39] /* $cse26.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp258;
  TRACE_POP
}

/*
equation index: 498
type: SIMPLE_ASSIGN
rover_8d.vy_rr.$pDERA.dummyVarA = rover_8d.vy.SeedA - rover_8d.l_rear * rover_8d.r.SeedA
*/
void RoverExample_Components_Rover_eqFunction_498(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 39;
  const int equationIndexes[2] = {1,498};
  jacobian->tmpVars[172] /* rover_8d.vy_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = jacobian->seedVars[30] /* rover_8d.vy.SeedA SEED_VAR */ - (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */));
  TRACE_POP
}

/*
equation index: 499
type: SIMPLE_ASSIGN
$cse28.$pDERA.dummyVarA = sign(rover_8d.vy_rr) * rover_8d.vy_rr.$pDERA.dummyVarA / $cse58 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_499(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 40;
  const int equationIndexes[2] = {1,499};
  modelica_real tmp259;
  tmp259 = jacobian->tmpVars[5] /* $cse58 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[41] /* $cse28.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */))) * (DIVISION(jacobian->tmpVars[172] /* rover_8d.vy_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(tmp259 * tmp259),"$cse58 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 500
type: SIMPLE_ASSIGN
rover_8d.vx_rr.$pDERA.dummyVarA = rover_8d.vx.SeedA + (-0.5) * rover_8d.tw * rover_8d.r.SeedA
*/
void RoverExample_Components_Rover_eqFunction_500(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 41;
  const int equationIndexes[2] = {1,500};
  jacobian->tmpVars[169] /* rover_8d.vx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */ + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */));
  TRACE_POP
}

/*
equation index: 501
type: SIMPLE_ASSIGN
$cse31.$pDERA.dummyVarA = sign(rover_8d.vx_rr) * rover_8d.vx_rr.$pDERA.dummyVarA / $cse57 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_501(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 42;
  const int equationIndexes[2] = {1,501};
  modelica_real tmp260;
  tmp260 = jacobian->tmpVars[6] /* $cse57 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[45] /* $cse31.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */))) * (DIVISION(jacobian->tmpVars[169] /* rover_8d.vx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(tmp260 * tmp260),"$cse57 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 502
type: SIMPLE_ASSIGN
$cse30.$pDERA.dummyVarA = if noEvent($cse31 < 0.001) then 0.0 else if noEvent($cse31 > 1.0) then 0.0 else $cse31.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_502(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 43;
  const int equationIndexes[2] = {1,502};
  modelica_boolean tmp261;
  modelica_boolean tmp262;
  modelica_boolean tmp263;
  modelica_real tmp264;
  tmp261 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */),0.001);
  tmp263 = (modelica_boolean)tmp261;
  if(tmp263)
  {
    tmp264 = 0.0;
  }
  else
  {
    tmp262 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* $cse31 variable */),1.0);
    tmp264 = (tmp262?0.0:jacobian->tmpVars[45] /* $cse31.$pDERA.dummyVarA JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[44] /* $cse30.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp264;
  TRACE_POP
}

/*
equation index: 503
type: SIMPLE_ASSIGN
$DER.rover_8d.lambda.$pDERA.dummyVarA = 0.25 * (rover_8d.omega_fl.SeedA + rover_8d.omega_rl.SeedA + rover_8d.omega_rr.SeedA + rover_8d.omega_fr.SeedA) * rover_8d.gratio
*/
void RoverExample_Components_Rover_eqFunction_503(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 44;
  const int equationIndexes[2] = {1,503};
  jacobian->resultVars[18] /* der(rover_8d.lambda.$pDERA.dummyVarA) JACOBIAN_VAR */ = (0.25) * ((jacobian->seedVars[19] /* rover_8d.omega_fl.SeedA SEED_VAR */ + jacobian->seedVars[21] /* rover_8d.omega_rl.SeedA SEED_VAR */ + jacobian->seedVars[22] /* rover_8d.omega_rr.SeedA SEED_VAR */ + jacobian->seedVars[20] /* rover_8d.omega_fr.SeedA SEED_VAR */) * ((data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */)));
  TRACE_POP
}

/*
equation index: 504
type: SIMPLE_ASSIGN
$DER.rover_8d.Iq.$pDERA.dummyVarA = (rover_8d.Vq.$pDERA.dummyVarA + (-rover_8d.R_phi) * rover_8d.Iq.SeedA - rover_8d.Kb_q * $DER.rover_8d.lambda.$pDERA.dummyVarA) / rover_8d.Le
*/
void RoverExample_Components_Rover_eqFunction_504(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 45;
  const int equationIndexes[2] = {1,504};
  jacobian->resultVars[8] /* der(rover_8d.Iq.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION(jacobian->tmpVars[121] /* rover_8d.Vq.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ + ((-(data->simulationInfo->realParameter[77] /* rover_8d.R_phi PARAM */))) * (jacobian->seedVars[8] /* rover_8d.Iq.SeedA SEED_VAR */) - (((data->simulationInfo->realParameter[69] /* rover_8d.Kb_q PARAM */)) * (jacobian->resultVars[18] /* der(rover_8d.lambda.$pDERA.dummyVarA) JACOBIAN_VAR */)),(data->simulationInfo->realParameter[72] /* rover_8d.Le PARAM */),"rover_8d.Le");
  TRACE_POP
}

/*
equation index: 505
type: SIMPLE_ASSIGN
$cse37.$pDERA.dummyVarA = (-$cse56) * rover_8d.phi.SeedA
*/
void RoverExample_Components_Rover_eqFunction_505(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 46;
  const int equationIndexes[2] = {1,505};
  jacobian->tmpVars[51] /* $cse37.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[7] /* $cse56 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[24] /* rover_8d.phi.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 506
type: SIMPLE_ASSIGN
$cse36.$pDERA.dummyVarA = $cse55 * rover_8d.phi.SeedA
*/
void RoverExample_Components_Rover_eqFunction_506(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 47;
  const int equationIndexes[2] = {1,506};
  jacobian->tmpVars[50] /* $cse36.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[8] /* $cse55 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[24] /* rover_8d.phi.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 507
type: SIMPLE_ASSIGN
$cse35.$pDERA.dummyVarA = (-$cse54) * rover_8d.delta.SeedA
*/
void RoverExample_Components_Rover_eqFunction_507(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 48;
  const int equationIndexes[2] = {1,507};
  jacobian->tmpVars[49] /* $cse35.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[9] /* $cse54 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[13] /* rover_8d.delta.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 508
type: SIMPLE_ASSIGN
$cse34.$pDERA.dummyVarA = $cse53 * rover_8d.delta.SeedA
*/
void RoverExample_Components_Rover_eqFunction_508(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 49;
  const int equationIndexes[2] = {1,508};
  jacobian->tmpVars[48] /* $cse34.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[10] /* $cse53 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[13] /* rover_8d.delta.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 509
type: SIMPLE_ASSIGN
$cse33.$pDERA.dummyVarA = $cse52 * rover_8d.psi.SeedA
*/
void RoverExample_Components_Rover_eqFunction_509(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 50;
  const int equationIndexes[2] = {1,509};
  jacobian->tmpVars[47] /* $cse33.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[11] /* $cse52 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[25] /* rover_8d.psi.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 510
type: SIMPLE_ASSIGN
$cse32.$pDERA.dummyVarA = (-$cse51) * rover_8d.psi.SeedA
*/
void RoverExample_Components_Rover_eqFunction_510(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 51;
  const int equationIndexes[2] = {1,510};
  jacobian->tmpVars[46] /* $cse32.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[12] /* $cse51 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[25] /* rover_8d.psi.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 511
type: SIMPLE_ASSIGN
$DER.rover_8d.y.$pDERA.dummyVarA = rover_8d.vx * $cse33.$pDERA.dummyVarA + rover_8d.vx.SeedA * $cse33 + rover_8d.vy * $cse32.$pDERA.dummyVarA + rover_8d.vy.SeedA * $cse32
*/
void RoverExample_Components_Rover_eqFunction_511(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 52;
  const int equationIndexes[2] = {1,511};
  jacobian->resultVars[33] /* der(rover_8d.y.$pDERA.dummyVarA) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (jacobian->tmpVars[47] /* $cse33.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + (jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* $cse33 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (jacobian->tmpVars[46] /* $cse32.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + (jacobian->seedVars[30] /* rover_8d.vy.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* $cse32 variable */));
  TRACE_POP
}

/*
equation index: 512
type: SIMPLE_ASSIGN
$DER.rover_8d.x.$pDERA.dummyVarA = rover_8d.vx * $cse32.$pDERA.dummyVarA + rover_8d.vx.SeedA * $cse32 + (-rover_8d.vy) * $cse33.$pDERA.dummyVarA - rover_8d.vy.SeedA * $cse33
*/
void RoverExample_Components_Rover_eqFunction_512(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 53;
  const int equationIndexes[2] = {1,512};
  jacobian->resultVars[32] /* der(rover_8d.x.$pDERA.dummyVarA) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */)) * (jacobian->tmpVars[46] /* $cse32.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + (jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* $cse32 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */))) * (jacobian->tmpVars[47] /* $cse33.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - ((jacobian->seedVars[30] /* rover_8d.vy.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* $cse33 variable */)));
  TRACE_POP
}

/*
equation index: 513
type: SIMPLE_ASSIGN
rover_8d.alpha_rr_bnd.$pDERA.dummyVarA = if noEvent(rover_8d.alpha_rr < rover_8d.alpha_min) then 0.0 else if noEvent(rover_8d.alpha_rr > rover_8d.alpha_max) then 0.0 else rover_8d.alpha_rr.SeedA
*/
void RoverExample_Components_Rover_eqFunction_513(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 54;
  const int equationIndexes[2] = {1,513};
  modelica_boolean tmp265;
  modelica_boolean tmp266;
  modelica_boolean tmp267;
  modelica_real tmp268;
  tmp265 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* rover_8d.alpha_rr STATE(1) */),(data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */));
  tmp267 = (modelica_boolean)tmp265;
  if(tmp267)
  {
    tmp268 = 0.0;
  }
  else
  {
    tmp266 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* rover_8d.alpha_rr STATE(1) */),(data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
    tmp268 = (tmp266?0.0:jacobian->seedVars[12] /* rover_8d.alpha_rr.SeedA SEED_VAR */);
  }
  jacobian->tmpVars[125] /* rover_8d.alpha_rr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp268;
  TRACE_POP
}

/*
equation index: 514
type: SIMPLE_ASSIGN
$cse29.$pDERA.dummyVarA = 2.0 * rover_8d.alpha_rr_bnd.$pDERA.dummyVarA / (1.0 + $cse50)
*/
void RoverExample_Components_Rover_eqFunction_514(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 55;
  const int equationIndexes[2] = {1,514};
  jacobian->tmpVars[42] /* $cse29.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (2.0) * (DIVISION(jacobian->tmpVars[125] /* rover_8d.alpha_rr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,1.0 + jacobian->tmpVars[13] /* $cse50 JACOBIAN_TMP_VAR */,"1.0 + $cse50"));
  TRACE_POP
}

/*
equation index: 515
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rr.$pDERA.dummyVarA = (-$cse28) * rover_8d.vy_rr.$pDERA.dummyVarA / rover_8d.Lrely - $cse28.$pDERA.dummyVarA * rover_8d.vy_rr / rover_8d.Lrely - abs(rover_8d.vx_rr) * rover_8d.Lrely * ($cse29.$pDERA.dummyVarA * $cse30 - $cse29 * $cse30.$pDERA.dummyVarA) / (rover_8d.Lrely * $cse30) ^ 2.0 - sign(rover_8d.vx_rr) * rover_8d.vx_rr.$pDERA.dummyVarA * $cse29 / ($cse30 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_515(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 56;
  const int equationIndexes[2] = {1,515};
  modelica_real tmp269;
  tmp269 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */));
  jacobian->resultVars[12] /* der(rover_8d.alpha_rr.$pDERA.dummyVarA) JACOBIAN_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* $cse28 variable */))) * (DIVISION(jacobian->tmpVars[172] /* rover_8d.vy_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[41] /* $cse28.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[42] /* $cse29.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (jacobian->tmpVars[44] /* $cse30.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(tmp269 * tmp269),"(rover_8d.Lrely * $cse30) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */))) * ((jacobian->tmpVars[169] /* rover_8d.vx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* $cse30 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse30 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 516
type: SIMPLE_ASSIGN
rover_8d.alpha_rl_bnd.$pDERA.dummyVarA = if noEvent(rover_8d.alpha_rl < rover_8d.alpha_min) then 0.0 else if noEvent(rover_8d.alpha_rl > rover_8d.alpha_max) then 0.0 else rover_8d.alpha_rl.SeedA
*/
void RoverExample_Components_Rover_eqFunction_516(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 57;
  const int equationIndexes[2] = {1,516};
  modelica_boolean tmp270;
  modelica_boolean tmp271;
  modelica_boolean tmp272;
  modelica_real tmp273;
  tmp270 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* rover_8d.alpha_rl STATE(1) */),(data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */));
  tmp272 = (modelica_boolean)tmp270;
  if(tmp272)
  {
    tmp273 = 0.0;
  }
  else
  {
    tmp271 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* rover_8d.alpha_rl STATE(1) */),(data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
    tmp273 = (tmp271?0.0:jacobian->seedVars[11] /* rover_8d.alpha_rl.SeedA SEED_VAR */);
  }
  jacobian->tmpVars[124] /* rover_8d.alpha_rl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp273;
  TRACE_POP
}

/*
equation index: 517
type: SIMPLE_ASSIGN
$cse25.$pDERA.dummyVarA = 2.0 * rover_8d.alpha_rl_bnd.$pDERA.dummyVarA / (1.0 + $cse49)
*/
void RoverExample_Components_Rover_eqFunction_517(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 58;
  const int equationIndexes[2] = {1,517};
  jacobian->tmpVars[38] /* $cse25.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (2.0) * (DIVISION(jacobian->tmpVars[124] /* rover_8d.alpha_rl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,1.0 + jacobian->tmpVars[14] /* $cse49 JACOBIAN_TMP_VAR */,"1.0 + $cse49"));
  TRACE_POP
}

/*
equation index: 518
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_rl.$pDERA.dummyVarA = abs(rover_8d.vx_rl) * ($cse25 * $cse26.$pDERA.dummyVarA * rover_8d.Lrely - $cse25.$pDERA.dummyVarA * $cse26 * rover_8d.Lrely) / ($cse26 * rover_8d.Lrely) ^ 2.0 + (-$cse28) * rover_8d.vy_rr.$pDERA.dummyVarA / rover_8d.Lrely - $cse28.$pDERA.dummyVarA * rover_8d.vy_rr / rover_8d.Lrely - sign(rover_8d.vx_rl) * rover_8d.vx_rl.$pDERA.dummyVarA * $cse25 / (rover_8d.Lrely * $cse26)
*/
void RoverExample_Components_Rover_eqFunction_518(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 59;
  const int equationIndexes[2] = {1,518};
  modelica_real tmp274;
  tmp274 = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */));
  jacobian->resultVars[11] /* der(rover_8d.alpha_rl.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */))) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * ((jacobian->tmpVars[39] /* $cse26.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */))) - ((jacobian->tmpVars[38] /* $cse25.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */))))),(tmp274 * tmp274),"($cse26 * rover_8d.Lrely) ^ 2.0") + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* $cse28 variable */))) * (DIVISION(jacobian->tmpVars[172] /* rover_8d.vy_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[41] /* $cse28.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* rover_8d.vy_rr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */))) * ((jacobian->tmpVars[168] /* rover_8d.vx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */),((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* $cse26 variable */)),"rover_8d.Lrely * $cse26"))));
  TRACE_POP
}

/*
equation index: 519
type: SIMPLE_ASSIGN
rover_8d.alpha_fr_bnd.$pDERA.dummyVarA = if noEvent(rover_8d.alpha_fr < rover_8d.alpha_min) then 0.0 else if noEvent(rover_8d.alpha_fr > rover_8d.alpha_max) then 0.0 else rover_8d.alpha_fr.SeedA
*/
void RoverExample_Components_Rover_eqFunction_519(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 60;
  const int equationIndexes[2] = {1,519};
  modelica_boolean tmp275;
  modelica_boolean tmp276;
  modelica_boolean tmp277;
  modelica_real tmp278;
  tmp275 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* rover_8d.alpha_fr STATE(1) */),(data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */));
  tmp277 = (modelica_boolean)tmp275;
  if(tmp277)
  {
    tmp278 = 0.0;
  }
  else
  {
    tmp276 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* rover_8d.alpha_fr STATE(1) */),(data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
    tmp278 = (tmp276?0.0:jacobian->seedVars[10] /* rover_8d.alpha_fr.SeedA SEED_VAR */);
  }
  jacobian->tmpVars[123] /* rover_8d.alpha_fr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp278;
  TRACE_POP
}

/*
equation index: 520
type: SIMPLE_ASSIGN
$cse21.$pDERA.dummyVarA = 2.0 * rover_8d.alpha_fr_bnd.$pDERA.dummyVarA / (1.0 + $cse48)
*/
void RoverExample_Components_Rover_eqFunction_520(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 61;
  const int equationIndexes[2] = {1,520};
  jacobian->tmpVars[34] /* $cse21.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (2.0) * (DIVISION(jacobian->tmpVars[123] /* rover_8d.alpha_fr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,1.0 + jacobian->tmpVars[15] /* $cse48 JACOBIAN_TMP_VAR */,"1.0 + $cse48"));
  TRACE_POP
}

/*
equation index: 521
type: SIMPLE_ASSIGN
rover_8d.alpha_fl_bnd.$pDERA.dummyVarA = if noEvent(rover_8d.alpha_fl < rover_8d.alpha_min) then 0.0 else if noEvent(rover_8d.alpha_fl > rover_8d.alpha_max) then 0.0 else rover_8d.alpha_fl.SeedA
*/
void RoverExample_Components_Rover_eqFunction_521(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 62;
  const int equationIndexes[2] = {1,521};
  modelica_boolean tmp279;
  modelica_boolean tmp280;
  modelica_boolean tmp281;
  modelica_real tmp282;
  tmp279 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* rover_8d.alpha_fl STATE(1) */),(data->simulationInfo->realParameter[80] /* rover_8d.alpha_min PARAM */));
  tmp281 = (modelica_boolean)tmp279;
  if(tmp281)
  {
    tmp282 = 0.0;
  }
  else
  {
    tmp280 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* rover_8d.alpha_fl STATE(1) */),(data->simulationInfo->realParameter[79] /* rover_8d.alpha_max PARAM */));
    tmp282 = (tmp280?0.0:jacobian->seedVars[9] /* rover_8d.alpha_fl.SeedA SEED_VAR */);
  }
  jacobian->tmpVars[122] /* rover_8d.alpha_fl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp282;
  TRACE_POP
}

/*
equation index: 522
type: SIMPLE_ASSIGN
$cse17.$pDERA.dummyVarA = 2.0 * rover_8d.alpha_fl_bnd.$pDERA.dummyVarA / (1.0 + $cse47)
*/
void RoverExample_Components_Rover_eqFunction_522(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 63;
  const int equationIndexes[2] = {1,522};
  jacobian->tmpVars[30] /* $cse17.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (2.0) * (DIVISION(jacobian->tmpVars[122] /* rover_8d.alpha_fl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,1.0 + jacobian->tmpVars[16] /* $cse47 JACOBIAN_TMP_VAR */,"1.0 + $cse47"));
  TRACE_POP
}

/*
equation index: 523
type: SIMPLE_ASSIGN
$cse16.$pDERA.dummyVarA = $cse46 * rover_8d.delta.SeedA
*/
void RoverExample_Components_Rover_eqFunction_523(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 64;
  const int equationIndexes[2] = {1,523};
  jacobian->tmpVars[29] /* $cse16.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[17] /* $cse46 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[13] /* rover_8d.delta.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 524
type: SIMPLE_ASSIGN
$cse15.$pDERA.dummyVarA = (-$cse45) * rover_8d.delta.SeedA
*/
void RoverExample_Components_Rover_eqFunction_524(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 65;
  const int equationIndexes[2] = {1,524};
  jacobian->tmpVars[28] /* $cse15.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[18] /* $cse45 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[13] /* rover_8d.delta.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 525
type: SIMPLE_ASSIGN
rover_8d.vy_fr.$pDERA.dummyVarA = $cse15 * (rover_8d.vy.SeedA + rover_8d.l_front * rover_8d.r.SeedA) + $cse15.$pDERA.dummyVarA * (rover_8d.vy + rover_8d.l_front * rover_8d.r) + (-$cse16) * rover_8d.vx_rr.$pDERA.dummyVarA - $cse16.$pDERA.dummyVarA * rover_8d.vx_rr
*/
void RoverExample_Components_Rover_eqFunction_525(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 66;
  const int equationIndexes[2] = {1,525};
  jacobian->tmpVars[171] /* rover_8d.vy_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * (jacobian->seedVars[30] /* rover_8d.vy.SeedA SEED_VAR */ + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */)) + (jacobian->tmpVars[28] /* $cse15.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */))) * (jacobian->tmpVars[169] /* rover_8d.vx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[29] /* $cse16.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)));
  TRACE_POP
}

/*
equation index: 526
type: SIMPLE_ASSIGN
$cse24.$pDERA.dummyVarA = sign(rover_8d.vy_fr) * rover_8d.vy_fr.$pDERA.dummyVarA / $cse60 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_526(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 67;
  const int equationIndexes[2] = {1,526};
  modelica_real tmp283;
  tmp283 = jacobian->tmpVars[3] /* $cse60 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[37] /* $cse24.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */))) * (DIVISION(jacobian->tmpVars[171] /* rover_8d.vy_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(tmp283 * tmp283),"$cse60 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 527
type: SIMPLE_ASSIGN
rover_8d.vx_fr.$pDERA.dummyVarA = $cse15 * rover_8d.vx_rr.$pDERA.dummyVarA + $cse15.$pDERA.dummyVarA * rover_8d.vx_rr + $cse16 * (rover_8d.vy.SeedA + rover_8d.l_front * rover_8d.r.SeedA) + $cse16.$pDERA.dummyVarA * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_527(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 68;
  const int equationIndexes[2] = {1,527};
  jacobian->tmpVars[167] /* rover_8d.vx_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * (jacobian->tmpVars[169] /* rover_8d.vx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[28] /* $cse15.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */)) * (jacobian->seedVars[30] /* rover_8d.vy.SeedA SEED_VAR */ + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */)) + (jacobian->tmpVars[29] /* $cse16.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 528
type: SIMPLE_ASSIGN
$cse23.$pDERA.dummyVarA = sign(rover_8d.vx_fr) * rover_8d.vx_fr.$pDERA.dummyVarA / $cse61 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_528(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 69;
  const int equationIndexes[2] = {1,528};
  modelica_real tmp284;
  tmp284 = jacobian->tmpVars[2] /* $cse61 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[36] /* $cse23.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * (DIVISION(jacobian->tmpVars[167] /* rover_8d.vx_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(tmp284 * tmp284),"$cse61 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 529
type: SIMPLE_ASSIGN
$cse22.$pDERA.dummyVarA = if noEvent($cse23 < 0.001) then 0.0 else if noEvent($cse23 > 1.0) then 0.0 else $cse23.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_529(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 70;
  const int equationIndexes[2] = {1,529};
  modelica_boolean tmp285;
  modelica_boolean tmp286;
  modelica_boolean tmp287;
  modelica_real tmp288;
  tmp285 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */),0.001);
  tmp287 = (modelica_boolean)tmp285;
  if(tmp287)
  {
    tmp288 = 0.0;
  }
  else
  {
    tmp286 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* $cse23 variable */),1.0);
    tmp288 = (tmp286?0.0:jacobian->tmpVars[36] /* $cse23.$pDERA.dummyVarA JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[35] /* $cse22.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp288;
  TRACE_POP
}

/*
equation index: 530
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fr.$pDERA.dummyVarA = (-$cse24) * rover_8d.vy_fr.$pDERA.dummyVarA / rover_8d.Lrely - $cse24.$pDERA.dummyVarA * rover_8d.vy_fr / rover_8d.Lrely - abs(rover_8d.vx_fr) * rover_8d.Lrely * ($cse21.$pDERA.dummyVarA * $cse22 - $cse21 * $cse22.$pDERA.dummyVarA) / (rover_8d.Lrely * $cse22) ^ 2.0 - sign(rover_8d.vx_fr) * rover_8d.vx_fr.$pDERA.dummyVarA * $cse21 / ($cse22 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_530(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 71;
  const int equationIndexes[2] = {1,530};
  modelica_real tmp289;
  tmp289 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */));
  jacobian->resultVars[10] /* der(rover_8d.alpha_fr.$pDERA.dummyVarA) JACOBIAN_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* $cse24 variable */))) * (DIVISION(jacobian->tmpVars[171] /* rover_8d.vy_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[37] /* $cse24.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* rover_8d.vy_fr variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[34] /* $cse21.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (jacobian->tmpVars[35] /* $cse22.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(tmp289 * tmp289),"(rover_8d.Lrely * $cse22) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* rover_8d.vx_fr variable */))) * ((jacobian->tmpVars[167] /* rover_8d.vx_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* $cse22 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse22 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 531
type: SIMPLE_ASSIGN
rover_8d.vy_fl.$pDERA.dummyVarA = $cse15 * (rover_8d.vy.SeedA + rover_8d.l_front * rover_8d.r.SeedA) + $cse15.$pDERA.dummyVarA * (rover_8d.vy + rover_8d.l_front * rover_8d.r) + (-$cse16) * rover_8d.vx_rl.$pDERA.dummyVarA - $cse16.$pDERA.dummyVarA * rover_8d.vx_rl
*/
void RoverExample_Components_Rover_eqFunction_531(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 72;
  const int equationIndexes[2] = {1,531};
  jacobian->tmpVars[170] /* rover_8d.vy_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * (jacobian->seedVars[30] /* rover_8d.vy.SeedA SEED_VAR */ + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */)) + (jacobian->tmpVars[28] /* $cse15.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */))) * (jacobian->tmpVars[168] /* rover_8d.vx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[29] /* $cse16.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)));
  TRACE_POP
}

/*
equation index: 532
type: SIMPLE_ASSIGN
$cse20.$pDERA.dummyVarA = sign(rover_8d.vy_fl) * rover_8d.vy_fl.$pDERA.dummyVarA / $cse62 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_532(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 73;
  const int equationIndexes[2] = {1,532};
  modelica_real tmp290;
  tmp290 = jacobian->tmpVars[1] /* $cse62 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[33] /* $cse20.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */))) * (DIVISION(jacobian->tmpVars[170] /* rover_8d.vy_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(tmp290 * tmp290),"$cse62 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 533
type: SIMPLE_ASSIGN
rover_8d.vx_fl.$pDERA.dummyVarA = $cse15 * rover_8d.vx_rl.$pDERA.dummyVarA + $cse15.$pDERA.dummyVarA * rover_8d.vx_rl + $cse16 * (rover_8d.vy.SeedA + rover_8d.l_front * rover_8d.r.SeedA) + $cse16.$pDERA.dummyVarA * (rover_8d.vy + rover_8d.l_front * rover_8d.r)
*/
void RoverExample_Components_Rover_eqFunction_533(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 74;
  const int equationIndexes[2] = {1,533};
  jacobian->tmpVars[166] /* rover_8d.vx_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* $cse15 variable */)) * (jacobian->tmpVars[168] /* rover_8d.vx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[28] /* $cse15.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* $cse16 variable */)) * (jacobian->seedVars[30] /* rover_8d.vy.SeedA SEED_VAR */ + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */)) + (jacobian->tmpVars[29] /* $cse16.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 534
type: SIMPLE_ASSIGN
$cse19.$pDERA.dummyVarA = sign(rover_8d.vx_fl) * rover_8d.vx_fl.$pDERA.dummyVarA / $cse63 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_534(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 75;
  const int equationIndexes[2] = {1,534};
  modelica_real tmp291;
  tmp291 = jacobian->tmpVars[0] /* $cse63 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[32] /* $cse19.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * (DIVISION(jacobian->tmpVars[166] /* rover_8d.vx_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(tmp291 * tmp291),"$cse63 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 535
type: SIMPLE_ASSIGN
$cse18.$pDERA.dummyVarA = if noEvent($cse19 < 0.001) then 0.0 else if noEvent($cse19 > 1.0) then 0.0 else $cse19.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_535(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 76;
  const int equationIndexes[2] = {1,535};
  modelica_boolean tmp292;
  modelica_boolean tmp293;
  modelica_boolean tmp294;
  modelica_real tmp295;
  tmp292 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */),0.001);
  tmp294 = (modelica_boolean)tmp292;
  if(tmp294)
  {
    tmp295 = 0.0;
  }
  else
  {
    tmp293 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* $cse19 variable */),1.0);
    tmp295 = (tmp293?0.0:jacobian->tmpVars[32] /* $cse19.$pDERA.dummyVarA JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[31] /* $cse18.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp295;
  TRACE_POP
}

/*
equation index: 536
type: SIMPLE_ASSIGN
$DER.rover_8d.alpha_fl.$pDERA.dummyVarA = (-$cse20) * rover_8d.vy_fl.$pDERA.dummyVarA / rover_8d.Lrely - $cse20.$pDERA.dummyVarA * rover_8d.vy_fl / rover_8d.Lrely - abs(rover_8d.vx_fl) * rover_8d.Lrely * ($cse17.$pDERA.dummyVarA * $cse18 - $cse17 * $cse18.$pDERA.dummyVarA) / (rover_8d.Lrely * $cse18) ^ 2.0 - sign(rover_8d.vx_fl) * rover_8d.vx_fl.$pDERA.dummyVarA * $cse17 / ($cse18 * rover_8d.Lrely)
*/
void RoverExample_Components_Rover_eqFunction_536(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 77;
  const int equationIndexes[2] = {1,536};
  modelica_real tmp296;
  tmp296 = ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */));
  jacobian->resultVars[9] /* der(rover_8d.alpha_fl.$pDERA.dummyVarA) JACOBIAN_VAR */ = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* $cse20 variable */))) * (DIVISION(jacobian->tmpVars[170] /* rover_8d.vy_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely")) - ((jacobian->tmpVars[33] /* $cse20.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* rover_8d.vy_fl variable */),(data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */),"rover_8d.Lrely"))) - ((fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * (((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)) * (DIVISION((jacobian->tmpVars[30] /* $cse17.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (jacobian->tmpVars[31] /* $cse18.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(tmp296 * tmp296),"(rover_8d.Lrely * $cse18) ^ 2.0")))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* rover_8d.vx_fl variable */))) * ((jacobian->tmpVars[166] /* rover_8d.vx_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* $cse18 variable */)) * ((data->simulationInfo->realParameter[74] /* rover_8d.Lrely PARAM */)),"$cse18 * rover_8d.Lrely"))));
  TRACE_POP
}

/*
equation index: 537
type: SIMPLE_ASSIGN
rover_8d.kappa_rr_bnd.$pDERA.dummyVarA = if noEvent(rover_8d.kappa_rr < rover_8d.kappa_min) then 0.0 else if noEvent(rover_8d.kappa_rr > rover_8d.kappa_max) then 0.0 else rover_8d.kappa_rr.SeedA
*/
void RoverExample_Components_Rover_eqFunction_537(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 78;
  const int equationIndexes[2] = {1,537};
  modelica_boolean tmp297;
  modelica_boolean tmp298;
  modelica_boolean tmp299;
  modelica_real tmp300;
  tmp297 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */),(data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */));
  tmp299 = (modelica_boolean)tmp297;
  if(tmp299)
  {
    tmp300 = 0.0;
  }
  else
  {
    tmp298 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */),(data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
    tmp300 = (tmp298?0.0:jacobian->seedVars[17] /* rover_8d.kappa_rr.SeedA SEED_VAR */);
  }
  jacobian->tmpVars[141] /* rover_8d.kappa_rr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp300;
  TRACE_POP
}

/*
equation index: 538
type: SIMPLE_ASSIGN
rover_8d.vs_rr.$pDERA.dummyVarA = 0.5 * rover_8d.vx_rr * 2.0 * (rover_8d.kappa_rr_bnd * rover_8d.kappa_rr_bnd.$pDERA.dummyVarA + $cse29 * $cse29.$pDERA.dummyVarA) / sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0) + rover_8d.vx_rr.$pDERA.dummyVarA * sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_538(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 79;
  const int equationIndexes[2] = {1,538};
  modelica_real tmp301;
  modelica_real tmp302;
  modelica_real tmp303;
  modelica_real tmp304;
  modelica_real tmp305;
  modelica_real tmp306;
  tmp301 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  tmp302 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */);
  tmp303 = (tmp301 * tmp301) + (tmp302 * tmp302);
  if(!(tmp303 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0) was %g should be >= 0", tmp303);
    }
  }tmp304 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */);
  tmp305 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */);
  tmp306 = (tmp304 * tmp304) + (tmp305 * tmp305);
  if(!(tmp306 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0) was %g should be >= 0", tmp306);
    }
  }
  jacobian->tmpVars[165] /* rover_8d.vs_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (jacobian->tmpVars[141] /* rover_8d.kappa_rr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (jacobian->tmpVars[42] /* $cse29.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),sqrt(tmp303),"sqrt(rover_8d.kappa_rr_bnd ^ 2.0 + $cse29 ^ 2.0)"))) + (jacobian->tmpVars[169] /* rover_8d.vx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (sqrt(tmp306));
  TRACE_POP
}

/*
equation index: 539
type: SIMPLE_ASSIGN
rover_8d.mu_rr.$pDERA.dummyVarA = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rr) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rr) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_rr.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_539(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 80;
  const int equationIndexes[2] = {1,539};
  modelica_boolean tmp307;
  modelica_boolean tmp308;
  modelica_boolean tmp309;
  modelica_real tmp310;
  tmp307 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */)))),0.0);
  tmp309 = (modelica_boolean)tmp307;
  if(tmp309)
  {
    tmp310 = 0.0;
  }
  else
  {
    tmp308 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* rover_8d.vs_rr variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp310 = (tmp308?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[165] /* rover_8d.vs_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[157] /* rover_8d.mu_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp310;
  TRACE_POP
}

/*
equation index: 540
type: SIMPLE_ASSIGN
rover_8d.kappa_rl_bnd.$pDERA.dummyVarA = if noEvent(rover_8d.kappa_rl < rover_8d.kappa_min) then 0.0 else if noEvent(rover_8d.kappa_rl > rover_8d.kappa_max) then 0.0 else rover_8d.kappa_rl.SeedA
*/
void RoverExample_Components_Rover_eqFunction_540(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 81;
  const int equationIndexes[2] = {1,540};
  modelica_boolean tmp311;
  modelica_boolean tmp312;
  modelica_boolean tmp313;
  modelica_real tmp314;
  tmp311 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */),(data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */));
  tmp313 = (modelica_boolean)tmp311;
  if(tmp313)
  {
    tmp314 = 0.0;
  }
  else
  {
    tmp312 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */),(data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
    tmp314 = (tmp312?0.0:jacobian->seedVars[16] /* rover_8d.kappa_rl.SeedA SEED_VAR */);
  }
  jacobian->tmpVars[140] /* rover_8d.kappa_rl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp314;
  TRACE_POP
}

/*
equation index: 541
type: SIMPLE_ASSIGN
rover_8d.vs_rl.$pDERA.dummyVarA = 0.5 * rover_8d.vx_rl * 2.0 * (rover_8d.kappa_rl_bnd * rover_8d.kappa_rl_bnd.$pDERA.dummyVarA + $cse25 * $cse25.$pDERA.dummyVarA) / sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0) + rover_8d.vx_rl.$pDERA.dummyVarA * sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_541(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 82;
  const int equationIndexes[2] = {1,541};
  modelica_real tmp315;
  modelica_real tmp316;
  modelica_real tmp317;
  modelica_real tmp318;
  modelica_real tmp319;
  modelica_real tmp320;
  tmp315 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  tmp316 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */);
  tmp317 = (tmp315 * tmp315) + (tmp316 * tmp316);
  if(!(tmp317 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0) was %g should be >= 0", tmp317);
    }
  }tmp318 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */);
  tmp319 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */);
  tmp320 = (tmp318 * tmp318) + (tmp319 * tmp319);
  if(!(tmp320 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0) was %g should be >= 0", tmp320);
    }
  }
  jacobian->tmpVars[164] /* rover_8d.vs_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (jacobian->tmpVars[140] /* rover_8d.kappa_rl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (jacobian->tmpVars[38] /* $cse25.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),sqrt(tmp317),"sqrt(rover_8d.kappa_rl_bnd ^ 2.0 + $cse25 ^ 2.0)"))) + (jacobian->tmpVars[168] /* rover_8d.vx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (sqrt(tmp320));
  TRACE_POP
}

/*
equation index: 542
type: SIMPLE_ASSIGN
rover_8d.mu_rl.$pDERA.dummyVarA = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rl) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_rl) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_rl.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_542(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 83;
  const int equationIndexes[2] = {1,542};
  modelica_boolean tmp321;
  modelica_boolean tmp322;
  modelica_boolean tmp323;
  modelica_real tmp324;
  tmp321 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */)))),0.0);
  tmp323 = (modelica_boolean)tmp321;
  if(tmp323)
  {
    tmp324 = 0.0;
  }
  else
  {
    tmp322 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* rover_8d.vs_rl variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp324 = (tmp322?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[164] /* rover_8d.vs_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[156] /* rover_8d.mu_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp324;
  TRACE_POP
}

/*
equation index: 543
type: SIMPLE_ASSIGN
rover_8d.kappa_fr_bnd.$pDERA.dummyVarA = if noEvent(rover_8d.kappa_fr < rover_8d.kappa_min) then 0.0 else if noEvent(rover_8d.kappa_fr > rover_8d.kappa_max) then 0.0 else rover_8d.kappa_fr.SeedA
*/
void RoverExample_Components_Rover_eqFunction_543(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 84;
  const int equationIndexes[2] = {1,543};
  modelica_boolean tmp325;
  modelica_boolean tmp326;
  modelica_boolean tmp327;
  modelica_real tmp328;
  tmp325 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */),(data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */));
  tmp327 = (modelica_boolean)tmp325;
  if(tmp327)
  {
    tmp328 = 0.0;
  }
  else
  {
    tmp326 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */),(data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
    tmp328 = (tmp326?0.0:jacobian->seedVars[15] /* rover_8d.kappa_fr.SeedA SEED_VAR */);
  }
  jacobian->tmpVars[139] /* rover_8d.kappa_fr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp328;
  TRACE_POP
}

/*
equation index: 544
type: SIMPLE_ASSIGN
rover_8d.vs_fr.$pDERA.dummyVarA = 0.5 * rover_8d.vx_rr * 2.0 * (rover_8d.kappa_fr_bnd * rover_8d.kappa_fr_bnd.$pDERA.dummyVarA + $cse21 * $cse21.$pDERA.dummyVarA) / sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0) + rover_8d.vx_rr.$pDERA.dummyVarA * sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_544(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 85;
  const int equationIndexes[2] = {1,544};
  modelica_real tmp329;
  modelica_real tmp330;
  modelica_real tmp331;
  modelica_real tmp332;
  modelica_real tmp333;
  modelica_real tmp334;
  tmp329 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  tmp330 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */);
  tmp331 = (tmp329 * tmp329) + (tmp330 * tmp330);
  if(!(tmp331 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0) was %g should be >= 0", tmp331);
    }
  }tmp332 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */);
  tmp333 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */);
  tmp334 = (tmp332 * tmp332) + (tmp333 * tmp333);
  if(!(tmp334 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0) was %g should be >= 0", tmp334);
    }
  }
  jacobian->tmpVars[163] /* rover_8d.vs_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* rover_8d.vx_rr variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (jacobian->tmpVars[139] /* rover_8d.kappa_fr_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (jacobian->tmpVars[34] /* $cse21.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),sqrt(tmp331),"sqrt(rover_8d.kappa_fr_bnd ^ 2.0 + $cse21 ^ 2.0)"))) + (jacobian->tmpVars[169] /* rover_8d.vx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (sqrt(tmp334));
  TRACE_POP
}

/*
equation index: 545
type: SIMPLE_ASSIGN
rover_8d.mu_fr.$pDERA.dummyVarA = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fr) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fr) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_fr.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_545(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 86;
  const int equationIndexes[2] = {1,545};
  modelica_boolean tmp335;
  modelica_boolean tmp336;
  modelica_boolean tmp337;
  modelica_real tmp338;
  tmp335 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */)))),0.0);
  tmp337 = (modelica_boolean)tmp335;
  if(tmp337)
  {
    tmp338 = 0.0;
  }
  else
  {
    tmp336 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* rover_8d.vs_fr variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp338 = (tmp336?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[163] /* rover_8d.vs_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[155] /* rover_8d.mu_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp338;
  TRACE_POP
}

/*
equation index: 546
type: SIMPLE_ASSIGN
rover_8d.kappa_fl_bnd.$pDERA.dummyVarA = if noEvent(rover_8d.kappa_fl < rover_8d.kappa_min) then 0.0 else if noEvent(rover_8d.kappa_fl > rover_8d.kappa_max) then 0.0 else rover_8d.kappa_fl.SeedA
*/
void RoverExample_Components_Rover_eqFunction_546(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 87;
  const int equationIndexes[2] = {1,546};
  modelica_boolean tmp339;
  modelica_boolean tmp340;
  modelica_boolean tmp341;
  modelica_real tmp342;
  tmp339 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */),(data->simulationInfo->realParameter[109] /* rover_8d.kappa_min PARAM */));
  tmp341 = (modelica_boolean)tmp339;
  if(tmp341)
  {
    tmp342 = 0.0;
  }
  else
  {
    tmp340 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */),(data->simulationInfo->realParameter[108] /* rover_8d.kappa_max PARAM */));
    tmp342 = (tmp340?0.0:jacobian->seedVars[14] /* rover_8d.kappa_fl.SeedA SEED_VAR */);
  }
  jacobian->tmpVars[138] /* rover_8d.kappa_fl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp342;
  TRACE_POP
}

/*
equation index: 547
type: SIMPLE_ASSIGN
rover_8d.vs_fl.$pDERA.dummyVarA = 0.5 * rover_8d.vx_rl * 2.0 * (rover_8d.kappa_fl_bnd * rover_8d.kappa_fl_bnd.$pDERA.dummyVarA + $cse17 * $cse17.$pDERA.dummyVarA) / sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0) + rover_8d.vx_rl.$pDERA.dummyVarA * sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0)
*/
void RoverExample_Components_Rover_eqFunction_547(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 88;
  const int equationIndexes[2] = {1,547};
  modelica_real tmp343;
  modelica_real tmp344;
  modelica_real tmp345;
  modelica_real tmp346;
  modelica_real tmp347;
  modelica_real tmp348;
  tmp343 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  tmp344 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */);
  tmp345 = (tmp343 * tmp343) + (tmp344 * tmp344);
  if(!(tmp345 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0) was %g should be >= 0", tmp345);
    }
  }tmp346 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */);
  tmp347 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */);
  tmp348 = (tmp346 * tmp346) + (tmp347 * tmp347);
  if(!(tmp348 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0) was %g should be >= 0", tmp348);
    }
  }
  jacobian->tmpVars[162] /* rover_8d.vs_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* rover_8d.vx_rl variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (jacobian->tmpVars[138] /* rover_8d.kappa_fl_bnd.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (jacobian->tmpVars[30] /* $cse17.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),sqrt(tmp345),"sqrt(rover_8d.kappa_fl_bnd ^ 2.0 + $cse17 ^ 2.0)"))) + (jacobian->tmpVars[168] /* rover_8d.vx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * (sqrt(tmp348));
  TRACE_POP
}

/*
equation index: 548
type: SIMPLE_ASSIGN
rover_8d.mu_fl.$pDERA.dummyVarA = if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fl) < 0.0) then 0.0 else if noEvent(rover_8d.mu0 * (1.0 - rover_8d.As * rover_8d.vs_fl) > rover_8d.mu0) then 0.0 else rover_8d.mu0 * (-rover_8d.As) * rover_8d.vs_fl.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_548(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 89;
  const int equationIndexes[2] = {1,548};
  modelica_boolean tmp349;
  modelica_boolean tmp350;
  modelica_boolean tmp351;
  modelica_real tmp352;
  tmp349 = Less(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */)))),0.0);
  tmp351 = (modelica_boolean)tmp349;
  if(tmp351)
  {
    tmp352 = 0.0;
  }
  else
  {
    tmp350 = Greater(((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (1.0 - (((data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* rover_8d.vs_fl variable */)))),(data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */));
    tmp352 = (tmp350?0.0:((data->simulationInfo->realParameter[122] /* rover_8d.mu0 PARAM */)) * (((-(data->simulationInfo->realParameter[62] /* rover_8d.As PARAM */))) * (jacobian->tmpVars[162] /* rover_8d.vs_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)));
  }
  jacobian->tmpVars[154] /* rover_8d.mu_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp352;
  TRACE_POP
}

/*
equation index: 593
type: LINEAR

<var>rover_8d.fz_rl.$pDERA.dummyVarA</var>
<var>rover_8d.fz_fr.$pDERA.dummyVarA</var>
<var>rover_8d.fz_rr.$pDERA.dummyVarA</var>
<var>rover_8d.fz_fl.$pDERA.dummyVarA</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_593(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 90;
  const int equationIndexes[2] = {1,593};
  /* Linear equation system */
  int retValue;
  double aux_x[4] = { jacobian->tmpVars[136] /* rover_8d.fz_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,jacobian->tmpVars[135] /* rover_8d.fz_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,jacobian->tmpVars[137] /* rover_8d.fz_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */,jacobian->tmpVars[134] /* rover_8d.fz_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 593 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  data->simulationInfo->linearSystemData[8].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 8, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,593};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 593 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[136] /* rover_8d.fz_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = aux_x[0];
  jacobian->tmpVars[135] /* rover_8d.fz_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = aux_x[1];
  jacobian->tmpVars[137] /* rover_8d.fz_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = aux_x[2];
  jacobian->tmpVars[134] /* rover_8d.fz_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = aux_x[3];

  TRACE_POP
}

/*
equation index: 594
type: SIMPLE_ASSIGN
$DER.rover_8d.vx.$pDERA.dummyVarA = rover_8d.vy * rover_8d.r.SeedA + rover_8d.vy.SeedA * rover_8d.r + rover_8d.ax.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_594(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 91;
  const int equationIndexes[2] = {1,594};
  jacobian->resultVars[29] /* der(rover_8d.vx.$pDERA.dummyVarA) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* rover_8d.vy STATE(1) */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */) + (jacobian->seedVars[30] /* rover_8d.vy.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)) + jacobian->tmpVars[126] /* rover_8d.ax.$pDERA.dummyVarA JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 595
type: SIMPLE_ASSIGN
$DER.rover_8d.p.$pDERA.dummyVarA = (rover_8d.mass_sprung * (9.80665 * $cse36.$pDERA.dummyVarA + (-rover_8d.ay) * $cse37.$pDERA.dummyVarA - rover_8d.ay.$pDERA.dummyVarA * $cse37) * rover_8d.hs + (-rover_8d.k_rllsp) * rover_8d.phi.SeedA - rover_8d.c_rllsp * rover_8d.p.SeedA) / rover_8d.I_xx
*/
void RoverExample_Components_Rover_eqFunction_595(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 92;
  const int equationIndexes[2] = {1,595};
  jacobian->resultVars[23] /* der(rover_8d.p.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((9.80665) * (jacobian->tmpVars[50] /* $cse36.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */))) * (jacobian->tmpVars[51] /* $cse37.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[127] /* rover_8d.ay.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* $cse37 variable */)))) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */))) + ((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * (jacobian->seedVars[24] /* rover_8d.phi.SeedA SEED_VAR */) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * (jacobian->seedVars[23] /* rover_8d.p.SeedA SEED_VAR */)),(data->simulationInfo->realParameter[65] /* rover_8d.I_xx PARAM */),"rover_8d.I_xx");
  TRACE_POP
}

/*
equation index: 596
type: SIMPLE_ASSIGN
$DER.rover_8d.r.$pDERA.dummyVarA = (0.5 * (rover_8d.Fx_fl * $cse34.$pDERA.dummyVarA + rover_8d.Fx_fl.$pDERA.dummyVarA * $cse34 + rover_8d.Fy_fl * $cse35.$pDERA.dummyVarA + rover_8d.Fy_fl.$pDERA.dummyVarA * $cse35 + rover_8d.Fx_rl.$pDERA.dummyVarA + (-rover_8d.Fx_fr) * $cse34.$pDERA.dummyVarA - rover_8d.Fx_fr.$pDERA.dummyVarA * $cse34 - rover_8d.Fy_fr.$pDERA.dummyVarA * $cse35 - rover_8d.Fy_fr * $cse35.$pDERA.dummyVarA - rover_8d.Fx_rr.$pDERA.dummyVarA) * rover_8d.tw + rover_8d.l_front * (rover_8d.Fy_fl * $cse34.$pDERA.dummyVarA + rover_8d.Fy_fl.$pDERA.dummyVarA * $cse34 + (-rover_8d.Fx_fl) * $cse35.$pDERA.dummyVarA - rover_8d.Fx_fl.$pDERA.dummyVarA * $cse35) + rover_8d.l_front * (rover_8d.Fy_fr * $cse34.$pDERA.dummyVarA + rover_8d.Fy_fr.$pDERA.dummyVarA * $cse34 + (-rover_8d.Fx_fr) * $cse35.$pDERA.dummyVarA - rover_8d.Fx_fr.$pDERA.dummyVarA * $cse35) - rover_8d.l_rear * (rover_8d.Fy_rl.$pDERA.dummyVarA + rover_8d.Fy_rr.$pDERA.dummyVarA)) / rover_8d.I_zz
*/
void RoverExample_Components_Rover_eqFunction_596(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 93;
  const int equationIndexes[2] = {1,596};
  jacobian->resultVars[27] /* der(rover_8d.r.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * (jacobian->tmpVars[48] /* $cse34.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[107] /* rover_8d.Fx_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (jacobian->tmpVars[49] /* $cse35.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[111] /* rover_8d.Fy_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + jacobian->tmpVars[109] /* rover_8d.Fx_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))) * (jacobian->tmpVars[48] /* $cse34.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[108] /* rover_8d.Fx_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */))) - ((jacobian->tmpVars[112] /* rover_8d.Fy_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (jacobian->tmpVars[49] /* $cse35.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)) - jacobian->tmpVars[110] /* rover_8d.Fx_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (jacobian->tmpVars[48] /* $cse34.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[111] /* rover_8d.Fy_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */))) * (jacobian->tmpVars[49] /* $cse35.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[107] /* rover_8d.Fx_fl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) + ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (jacobian->tmpVars[48] /* $cse34.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[112] /* rover_8d.Fy_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */))) * (jacobian->tmpVars[49] /* $cse35.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) - ((jacobian->tmpVars[108] /* rover_8d.Fx_fr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)))) - (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (jacobian->tmpVars[113] /* rover_8d.Fy_rl.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ + jacobian->tmpVars[114] /* rover_8d.Fy_rr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(data->simulationInfo->realParameter[66] /* rover_8d.I_zz PARAM */),"rover_8d.I_zz");
  TRACE_POP
}

/*
equation index: 597
type: SIMPLE_ASSIGN
$DER.rover_8d.vy.$pDERA.dummyVarA = rover_8d.ay.$pDERA.dummyVarA + (rover_8d.l_rear * rover_8d.mass_unsprung_rear - rover_8d.l_front * rover_8d.mass_unsprung_front) * $DER.rover_8d.r.$pDERA.dummyVarA / rover_8d.mass_total + (-rover_8d.vx) * rover_8d.r.SeedA - rover_8d.vx.SeedA * rover_8d.r
*/
void RoverExample_Components_Rover_eqFunction_597(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 94;
  const int equationIndexes[2] = {1,597};
  jacobian->resultVars[30] /* der(rover_8d.vy.$pDERA.dummyVarA) JACOBIAN_VAR */ = jacobian->tmpVars[127] /* rover_8d.ay.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ + (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) - (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)))) * (DIVISION(jacobian->resultVars[27] /* der(rover_8d.r.$pDERA.dummyVarA) JACOBIAN_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total")) + ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */))) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */) - ((jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)));
  TRACE_POP
}

/*
equation index: 610
type: LINEAR

<var>rover_8d.thr.$pDERA.dummyVarA</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void RoverExample_Components_Rover_eqFunction_610(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 95;
  const int equationIndexes[2] = {1,610};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { jacobian->tmpVars[161] /* rover_8d.thr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 610 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  data->simulationInfo->linearSystemData[9].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 9, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,610};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 610 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[161] /* rover_8d.thr.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = aux_x[0];

  TRACE_POP
}

/*
equation index: 611
type: SIMPLE_ASSIGN
$cse14.$pDERA.dummyVarA = sign(rover_8d.vx) * rover_8d.vx.SeedA / $cse44 ^ 2.0
*/
void RoverExample_Components_Rover_eqFunction_611(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 96;
  const int equationIndexes[2] = {1,611};
  modelica_real tmp353;
  tmp353 = jacobian->tmpVars[19] /* $cse44 JACOBIAN_TMP_VAR */;
  jacobian->tmpVars[27] /* $cse14.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */))) * (DIVISION(jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */,(tmp353 * tmp353),"$cse44 ^ 2.0"));
  TRACE_POP
}

/*
equation index: 612
type: SIMPLE_ASSIGN
$cse13.$pDERA.dummyVarA = if noEvent($cse14 < 0.001) then 0.0 else if noEvent($cse14 > 1.0) then 0.0 else $cse14.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_612(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 97;
  const int equationIndexes[2] = {1,612};
  modelica_boolean tmp354;
  modelica_boolean tmp355;
  modelica_boolean tmp356;
  modelica_real tmp357;
  tmp354 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */),0.001);
  tmp356 = (modelica_boolean)tmp354;
  if(tmp356)
  {
    tmp357 = 0.0;
  }
  else
  {
    tmp355 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* $cse14 variable */),1.0);
    tmp357 = (tmp355?0.0:jacobian->tmpVars[27] /* $cse14.$pDERA.dummyVarA JACOBIAN_TMP_VAR */);
  }
  jacobian->tmpVars[26] /* $cse13.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = tmp357;
  TRACE_POP
}

/*
equation index: 613
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rr.$pDERA.dummyVarA = (rover_8d.r_tire * rover_8d.omega_rr.SeedA + 0.5 * rover_8d.tw * rover_8d.r.SeedA - rover_8d.vx.SeedA) / rover_8d.Lrelx + (-abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r)) * rover_8d.Lrelx * (rover_8d.kappa_rr.SeedA * $cse13 - rover_8d.kappa_rr * $cse13.$pDERA.dummyVarA) / (rover_8d.Lrelx * $cse13) ^ 2.0 - sign(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r) * (rover_8d.vx.SeedA + (-0.5) * rover_8d.tw * rover_8d.r.SeedA) * rover_8d.kappa_rr / ($cse13 * rover_8d.Lrelx)
*/
void RoverExample_Components_Rover_eqFunction_613(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 98;
  const int equationIndexes[2] = {1,613};
  modelica_real tmp358;
  tmp358 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->resultVars[17] /* der(rover_8d.kappa_rr.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * (jacobian->seedVars[22] /* rover_8d.omega_rr.SeedA SEED_VAR */) + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */)) - jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */,(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx") + ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION((jacobian->seedVars[17] /* rover_8d.kappa_rr.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */)) * (jacobian->tmpVars[26] /* $cse13.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(tmp358 * tmp358),"(rover_8d.Lrelx * $cse13) ^ 2.0"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * ((jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */ + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */))) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* rover_8d.kappa_rr STATE(1) */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) * ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)),"$cse13 * rover_8d.Lrelx"))));
  TRACE_POP
}

/*
equation index: 614
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_rl.$pDERA.dummyVarA = (rover_8d.r_tire * rover_8d.omega_rl.SeedA + (-0.5) * rover_8d.tw * rover_8d.r.SeedA - rover_8d.vx.SeedA) / rover_8d.Lrelx + (-abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r)) * rover_8d.Lrelx * (rover_8d.kappa_rl.SeedA * $cse13 - rover_8d.kappa_rl * $cse13.$pDERA.dummyVarA) / (rover_8d.Lrelx * $cse13) ^ 2.0 - sign(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r) * (rover_8d.vx.SeedA + 0.5 * rover_8d.tw * rover_8d.r.SeedA) * rover_8d.kappa_rl / ($cse13 * rover_8d.Lrelx)
*/
void RoverExample_Components_Rover_eqFunction_614(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 99;
  const int equationIndexes[2] = {1,614};
  modelica_real tmp359;
  tmp359 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->resultVars[16] /* der(rover_8d.kappa_rl.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * (jacobian->seedVars[21] /* rover_8d.omega_rl.SeedA SEED_VAR */) + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */)) - jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */,(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx") + ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION((jacobian->seedVars[16] /* rover_8d.kappa_rl.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */)) * (jacobian->tmpVars[26] /* $cse13.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(tmp359 * tmp359),"(rover_8d.Lrelx * $cse13) ^ 2.0"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))) * ((jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */ + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */))) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* rover_8d.kappa_rl STATE(1) */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) * ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)),"$cse13 * rover_8d.Lrelx"))));
  TRACE_POP
}

/*
equation index: 615
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fr.$pDERA.dummyVarA = (rover_8d.r_tire * rover_8d.omega_fr.SeedA + 0.5 * rover_8d.tw * rover_8d.r.SeedA - rover_8d.vx.SeedA) / rover_8d.Lrelx + (-abs(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r)) * rover_8d.Lrelx * (rover_8d.kappa_fr.SeedA * $cse13 - rover_8d.kappa_fr * $cse13.$pDERA.dummyVarA) / (rover_8d.Lrelx * $cse13) ^ 2.0 - sign(rover_8d.vx - 0.5 * rover_8d.tw * rover_8d.r) * (rover_8d.vx.SeedA + (-0.5) * rover_8d.tw * rover_8d.r.SeedA) * rover_8d.kappa_fr / ($cse13 * rover_8d.Lrelx)
*/
void RoverExample_Components_Rover_eqFunction_615(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 100;
  const int equationIndexes[2] = {1,615};
  modelica_real tmp360;
  tmp360 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->resultVars[15] /* der(rover_8d.kappa_fr.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * (jacobian->seedVars[20] /* rover_8d.omega_fr.SeedA SEED_VAR */) + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */)) - jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */,(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx") + ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION((jacobian->seedVars[15] /* rover_8d.kappa_fr.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */)) * (jacobian->tmpVars[26] /* $cse13.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(tmp360 * tmp360),"(rover_8d.Lrelx * $cse13) ^ 2.0"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) - (((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * ((jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */ + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */))) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* rover_8d.kappa_fr STATE(1) */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) * ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)),"$cse13 * rover_8d.Lrelx"))));
  TRACE_POP
}

/*
equation index: 616
type: SIMPLE_ASSIGN
$DER.rover_8d.kappa_fl.$pDERA.dummyVarA = (rover_8d.r_tire * rover_8d.omega_fl.SeedA + (-0.5) * rover_8d.tw * rover_8d.r.SeedA - rover_8d.vx.SeedA) / rover_8d.Lrelx + (-abs(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r)) * rover_8d.Lrelx * (rover_8d.kappa_fl.SeedA * $cse13 - rover_8d.kappa_fl * $cse13.$pDERA.dummyVarA) / (rover_8d.Lrelx * $cse13) ^ 2.0 - sign(rover_8d.vx + 0.5 * rover_8d.tw * rover_8d.r) * (rover_8d.vx.SeedA + 0.5 * rover_8d.tw * rover_8d.r.SeedA) * rover_8d.kappa_fl / ($cse13 * rover_8d.Lrelx)
*/
void RoverExample_Components_Rover_eqFunction_616(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 101;
  const int equationIndexes[2] = {1,616};
  modelica_real tmp361;
  tmp361 = ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */));
  jacobian->resultVars[14] /* der(rover_8d.kappa_fl.$pDERA.dummyVarA) JACOBIAN_VAR */ = DIVISION(((data->simulationInfo->realParameter[124] /* rover_8d.r_tire PARAM */)) * (jacobian->seedVars[19] /* rover_8d.omega_fl.SeedA SEED_VAR */) + (-0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */)) - jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */,(data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */),"rover_8d.Lrelx") + ((-fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */))))) * (((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)) * (DIVISION((jacobian->seedVars[14] /* rover_8d.kappa_fl.SeedA SEED_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */)) * (jacobian->tmpVars[26] /* $cse13.$pDERA.dummyVarA JACOBIAN_TMP_VAR */)),(tmp361 * tmp361),"(rover_8d.Lrelx * $cse13) ^ 2.0"))) - ((sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* rover_8d.vx STATE(1) */) + ((0.5) * ((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* rover_8d.r STATE(1) */)))) * ((jacobian->seedVars[29] /* rover_8d.vx.SeedA SEED_VAR */ + (0.5) * (((data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */)) * (jacobian->seedVars[27] /* rover_8d.r.SeedA SEED_VAR */))) * (DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* rover_8d.kappa_fl STATE(1) */),((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* $cse13 variable */)) * ((data->simulationInfo->realParameter[73] /* rover_8d.Lrelx PARAM */)),"$cse13 * rover_8d.Lrelx"))));
  TRACE_POP
}

/*
equation index: 617
type: SIMPLE_ASSIGN
$cse4.$pDERA.dummyVarA = $cse43 * rover_3d.psi.SeedA
*/
void RoverExample_Components_Rover_eqFunction_617(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 102;
  const int equationIndexes[2] = {1,617};
  jacobian->tmpVars[53] /* $cse4.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[20] /* $cse43 JACOBIAN_TMP_VAR */) * (jacobian->seedVars[1] /* rover_3d.psi.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 618
type: SIMPLE_ASSIGN
$DER.rover_3d.y.$pDERA.dummyVarA = rover_3d.vx * $cse4.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_618(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 103;
  const int equationIndexes[2] = {1,618};
  jacobian->resultVars[6] /* der(rover_3d.y.$pDERA.dummyVarA) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (jacobian->tmpVars[53] /* $cse4.$pDERA.dummyVarA JACOBIAN_TMP_VAR */);
  TRACE_POP
}

/*
equation index: 619
type: SIMPLE_ASSIGN
$cse3.$pDERA.dummyVarA = (-$cse42) * rover_3d.psi.SeedA
*/
void RoverExample_Components_Rover_eqFunction_619(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 104;
  const int equationIndexes[2] = {1,619};
  jacobian->tmpVars[43] /* $cse3.$pDERA.dummyVarA JACOBIAN_TMP_VAR */ = ((-jacobian->tmpVars[21] /* $cse42 JACOBIAN_TMP_VAR */)) * (jacobian->seedVars[1] /* rover_3d.psi.SeedA SEED_VAR */);
  TRACE_POP
}

/*
equation index: 620
type: SIMPLE_ASSIGN
$DER.rover_3d.x.$pDERA.dummyVarA = rover_3d.vx * $cse3.$pDERA.dummyVarA
*/
void RoverExample_Components_Rover_eqFunction_620(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 105;
  const int equationIndexes[2] = {1,620};
  jacobian->resultVars[5] /* der(rover_3d.x.$pDERA.dummyVarA) JACOBIAN_VAR */ = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* rover_3d.vx variable */)) * (jacobian->tmpVars[43] /* $cse3.$pDERA.dummyVarA JACOBIAN_TMP_VAR */);
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacA_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_A;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_A;
  RoverExample_Components_Rover_eqFunction_459(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_460(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_461(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_462(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_463(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_464(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_465(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_466(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_467(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_468(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_469(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_470(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_471(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_472(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_473(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_474(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_475(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_476(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_477(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_478(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_479(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_480(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_481(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_482(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_483(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_484(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_485(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_486(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_487(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_488(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_489(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_490(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_491(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_492(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_493(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_494(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_495(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_496(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_497(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_498(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_499(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_500(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_501(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_502(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_503(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_504(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_505(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_506(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_507(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_508(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_509(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_510(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_511(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_512(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_513(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_514(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_515(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_516(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_517(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_518(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_519(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_520(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_521(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_522(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_523(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_524(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_525(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_526(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_527(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_528(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_529(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_530(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_531(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_532(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_533(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_534(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_535(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_536(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_537(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_538(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_539(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_540(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_541(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_542(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_543(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_544(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_545(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_546(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_547(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_548(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_593(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_594(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_595(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_596(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_597(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_610(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_611(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_612(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_613(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_614(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_615(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_616(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_617(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_618(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_619(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_620(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 993
type: SIMPLE_ASSIGN
rover_8d.Fx_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.fz_rr.$pDERD.dummyVarD.SeedLSJac10 / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_993(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,993};
  jacobian->tmpVars[0] /* rover_8d.Fx_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION(jacobian->seedVars[3] /* rover_8d.fz_rr.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}

/*
equation index: 994
type: SIMPLE_ASSIGN
rover_8d.Fy_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = rover_8d.c_alpha * $cse29 * rover_8d.fz_rr.$pDERD.dummyVarD.SeedLSJac10 / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_994(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,994};
  jacobian->tmpVars[1] /* rover_8d.Fy_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION(jacobian->seedVars[3] /* rover_8d.fz_rr.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}

/*
equation index: 995
type: SIMPLE_ASSIGN
rover_8d.Fx_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.fz_fr.$pDERD.dummyVarD.SeedLSJac10 / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_995(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,995};
  jacobian->tmpVars[2] /* rover_8d.Fx_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION(jacobian->seedVars[2] /* rover_8d.fz_fr.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}

/*
equation index: 996
type: SIMPLE_ASSIGN
rover_8d.Fy_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = rover_8d.c_alpha * $cse21 * rover_8d.fz_fr.$pDERD.dummyVarD.SeedLSJac10 / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_996(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,996};
  jacobian->tmpVars[3] /* rover_8d.Fy_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION(jacobian->seedVars[2] /* rover_8d.fz_fr.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}

/*
equation index: 997
type: SIMPLE_ASSIGN
rover_8d.Fy_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = rover_8d.c_alpha * $cse17 * rover_8d.fz_fl.$pDERD.dummyVarD.SeedLSJac10 / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_997(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,997};
  jacobian->tmpVars[4] /* rover_8d.Fy_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION(jacobian->seedVars[1] /* rover_8d.fz_fl.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}

/*
equation index: 998
type: SIMPLE_ASSIGN
rover_8d.Fx_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.fz_fl.$pDERD.dummyVarD.SeedLSJac10 / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_998(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,998};
  jacobian->tmpVars[5] /* rover_8d.Fx_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION(jacobian->seedVars[1] /* rover_8d.fz_fl.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}

/*
equation index: 999
type: SIMPLE_ASSIGN
rover_8d.Fx_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.fz_rl.$pDERD.dummyVarD.SeedLSJac10 / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_999(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,999};
  jacobian->tmpVars[6] /* rover_8d.Fx_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION(jacobian->seedVars[0] /* rover_8d.fz_rl.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}

/*
equation index: 1000
type: SIMPLE_ASSIGN
$DER.rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = (rover_8d.Fx_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * $cse34 + rover_8d.Fy_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * $cse35 + rover_8d.Fx_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * $cse34 + rover_8d.Fy_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * $cse35 + rover_8d.Fx_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 + rover_8d.Fx_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_1000(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,1000};
  jacobian->tmpVars[7] /* der(rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10) JACOBIAN_TMP_VAR */ = DIVISION((jacobian->tmpVars[5] /* rover_8d.Fx_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[4] /* rover_8d.Fy_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (jacobian->tmpVars[2] /* rover_8d.Fx_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[3] /* rover_8d.Fy_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + jacobian->tmpVars[6] /* rover_8d.Fx_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ + jacobian->tmpVars[0] /* rover_8d.Fx_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}

/*
equation index: 1001
type: SIMPLE_ASSIGN
rover_8d.Fy_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = rover_8d.c_alpha * $cse25 * rover_8d.fz_rl.$pDERD.dummyVarD.SeedLSJac10 / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_1001(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,1001};
  jacobian->tmpVars[8] /* rover_8d.Fy_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION(jacobian->seedVars[0] /* rover_8d.fz_rl.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}

/*
equation index: 1002
type: SIMPLE_ASSIGN
ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = (rover_8d.Fy_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * $cse34 + rover_8d.Fy_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * $cse34 + rover_8d.Fy_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 + rover_8d.Fy_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 + ((-rover_8d.Fx_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10) - rover_8d.Fx_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10) * $cse35) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_1002(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,1002};
  jacobian->tmpVars[9] /* ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = DIVISION((jacobian->tmpVars[4] /* rover_8d.Fy_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[3] /* rover_8d.Fy_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + jacobian->tmpVars[8] /* rover_8d.Fy_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ + jacobian->tmpVars[1] /* rover_8d.Fy_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ + ((-jacobian->tmpVars[2] /* rover_8d.Fx_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) - jacobian->tmpVars[5] /* rover_8d.Fx_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}

/*
equation index: 1003
type: SIMPLE_ASSIGN
rover_8d.Fz_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 / rover_8d.l_total - ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_1003(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,1003};
  jacobian->tmpVars[10] /* rover_8d.Fz_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[7] /* der(rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - ((jacobian->tmpVars[9] /* ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}

/*
equation index: 1004
type: SIMPLE_ASSIGN
rover_8d.z_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_fr * rover_8d.Fz_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_1004(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,1004};
  modelica_real tmp362;
  modelica_real tmp363;
  modelica_real tmp364;
  modelica_boolean tmp365;
  modelica_real tmp366;
  modelica_real tmp367;
  modelica_real tmp368;
  modelica_boolean tmp369;
  modelica_real tmp370;
  modelica_real tmp371;
  modelica_real tmp372;
  modelica_boolean tmp373;
  modelica_real tmp374;
  modelica_boolean tmp375;
  modelica_real tmp376;
  tmp362 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp363 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
  tmp364 = (tmp362 * tmp362) + (tmp363 * tmp363) + 1e-15;
  if(!(tmp364 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp364);
    }
  }tmp365 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp364),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp375 = (modelica_boolean)tmp365;
  if(tmp375)
  {
    tmp376 = 0.0;
  }
  else
  {
    tmp366 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
    tmp367 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
    tmp368 = (tmp366 * tmp366) + (tmp367 * tmp367) + 1e-15;
    if(!(tmp368 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp368);
      }
    }tmp369 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp368),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp373 = (modelica_boolean)tmp369;
    if(tmp373)
    {
      tmp374 = 0.0;
    }
    else
    {
      tmp370 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp371 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp372 = (tmp370 * tmp370) + (tmp371 * tmp371) + 1e-15;
      if(!(tmp372 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp372);
        }
      }
      tmp374 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * ((jacobian->tmpVars[10] /* rover_8d.Fz_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp372),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))));
    }
    tmp376 = tmp374;
  }
  jacobian->tmpVars[11] /* rover_8d.z_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = tmp376;
  TRACE_POP
}

/*
equation index: 1005
type: SIMPLE_ASSIGN
rover_8d.Fz_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 / rover_8d.l_total + ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_1005(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,1005};
  jacobian->tmpVars[12] /* rover_8d.Fz_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[7] /* der(rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (jacobian->tmpVars[9] /* ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}

/*
equation index: 1006
type: SIMPLE_ASSIGN
rover_8d.z_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_fl * rover_8d.Fz_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_1006(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,1006};
  modelica_real tmp377;
  modelica_real tmp378;
  modelica_real tmp379;
  modelica_boolean tmp380;
  modelica_real tmp381;
  modelica_real tmp382;
  modelica_real tmp383;
  modelica_boolean tmp384;
  modelica_real tmp385;
  modelica_real tmp386;
  modelica_real tmp387;
  modelica_boolean tmp388;
  modelica_real tmp389;
  modelica_boolean tmp390;
  modelica_real tmp391;
  tmp377 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp378 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
  tmp379 = (tmp377 * tmp377) + (tmp378 * tmp378) + 1e-15;
  if(!(tmp379 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp379);
    }
  }tmp380 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp379),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp390 = (modelica_boolean)tmp380;
  if(tmp390)
  {
    tmp391 = 0.0;
  }
  else
  {
    tmp381 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
    tmp382 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
    tmp383 = (tmp381 * tmp381) + (tmp382 * tmp382) + 1e-15;
    if(!(tmp383 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp383);
      }
    }tmp384 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp383),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp388 = (modelica_boolean)tmp384;
    if(tmp388)
    {
      tmp389 = 0.0;
    }
    else
    {
      tmp385 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp386 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp387 = (tmp385 * tmp385) + (tmp386 * tmp386) + 1e-15;
      if(!(tmp387 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp387);
        }
      }
      tmp389 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * ((jacobian->tmpVars[12] /* rover_8d.Fz_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp387),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))));
    }
    tmp391 = tmp389;
  }
  jacobian->tmpVars[13] /* rover_8d.z_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = tmp391;
  TRACE_POP
}

/*
equation index: 1007
type: SIMPLE_ASSIGN
rover_8d.Fz_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 / rover_8d.l_total - ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_1007(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,1007};
  jacobian->tmpVars[14] /* rover_8d.Fz_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[7] /* der(rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - ((jacobian->tmpVars[9] /* ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}

/*
equation index: 1008
type: SIMPLE_ASSIGN
rover_8d.z_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_rr * rover_8d.Fz_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_1008(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,1008};
  modelica_real tmp392;
  modelica_real tmp393;
  modelica_real tmp394;
  modelica_boolean tmp395;
  modelica_real tmp396;
  modelica_real tmp397;
  modelica_real tmp398;
  modelica_boolean tmp399;
  modelica_real tmp400;
  modelica_real tmp401;
  modelica_real tmp402;
  modelica_boolean tmp403;
  modelica_real tmp404;
  modelica_boolean tmp405;
  modelica_real tmp406;
  tmp392 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp393 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
  tmp394 = (tmp392 * tmp392) + (tmp393 * tmp393) + 1e-15;
  if(!(tmp394 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp394);
    }
  }tmp395 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp394),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp405 = (modelica_boolean)tmp395;
  if(tmp405)
  {
    tmp406 = 0.0;
  }
  else
  {
    tmp396 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
    tmp397 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
    tmp398 = (tmp396 * tmp396) + (tmp397 * tmp397) + 1e-15;
    if(!(tmp398 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp398);
      }
    }tmp399 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp398),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp403 = (modelica_boolean)tmp399;
    if(tmp403)
    {
      tmp404 = 0.0;
    }
    else
    {
      tmp400 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp401 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp402 = (tmp400 * tmp400) + (tmp401 * tmp401) + 1e-15;
      if(!(tmp402 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp402);
        }
      }
      tmp404 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * ((jacobian->tmpVars[14] /* rover_8d.Fz_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp402),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))));
    }
    tmp406 = tmp404;
  }
  jacobian->tmpVars[15] /* rover_8d.z_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = tmp406;
  TRACE_POP
}

/*
equation index: 1009
type: SIMPLE_ASSIGN
rover_8d.Fz_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 / rover_8d.l_total + ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_1009(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,1009};
  jacobian->tmpVars[16] /* rover_8d.Fz_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[7] /* der(rover_8d.vx.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (jacobian->tmpVars[9] /* ay_meas.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}

/*
equation index: 1010
type: SIMPLE_ASSIGN
rover_8d.z_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 = if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_rl * rover_8d.Fz_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_1010(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,1010};
  modelica_real tmp407;
  modelica_real tmp408;
  modelica_real tmp409;
  modelica_boolean tmp410;
  modelica_real tmp411;
  modelica_real tmp412;
  modelica_real tmp413;
  modelica_boolean tmp414;
  modelica_real tmp415;
  modelica_real tmp416;
  modelica_real tmp417;
  modelica_boolean tmp418;
  modelica_real tmp419;
  modelica_boolean tmp420;
  modelica_real tmp421;
  tmp407 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp408 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
  tmp409 = (tmp407 * tmp407) + (tmp408 * tmp408) + 1e-15;
  if(!(tmp409 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp409);
    }
  }tmp410 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp409),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp420 = (modelica_boolean)tmp410;
  if(tmp420)
  {
    tmp421 = 0.0;
  }
  else
  {
    tmp411 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
    tmp412 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
    tmp413 = (tmp411 * tmp411) + (tmp412 * tmp412) + 1e-15;
    if(!(tmp413 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp413);
      }
    }tmp414 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp413),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp418 = (modelica_boolean)tmp414;
    if(tmp418)
    {
      tmp419 = 0.0;
    }
    else
    {
      tmp415 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp416 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp417 = (tmp415 * tmp415) + (tmp416 * tmp416) + 1e-15;
      if(!(tmp417 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp417);
        }
      }
      tmp419 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * ((jacobian->tmpVars[16] /* rover_8d.Fz_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp417),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))));
    }
    tmp421 = tmp419;
  }
  jacobian->tmpVars[17] /* rover_8d.z_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */ = tmp421;
  TRACE_POP
}

/*
equation index: 1011
type: SIMPLE_ASSIGN
$res_LSJac10_1.$pDERLSJac10.dummyVarLSJac10 = (if rover_8d.z_rr < 1.0 then rover_8d.z_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (2.0 - rover_8d.z_rr - rover_8d.z_rr) else 0.0) - rover_8d.fz_rr.$pDERD.dummyVarD.SeedLSJac10
*/
void RoverExample_Components_Rover_eqFunction_1011(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,1011};
  modelica_boolean tmp422;
  tmp422 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */),1.0);
  jacobian->resultVars[0] /* $res_LSJac10_1.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_VAR */ = (tmp422?(jacobian->tmpVars[15] /* rover_8d.z_rr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):0.0) - jacobian->seedVars[3] /* rover_8d.fz_rr.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 1012
type: SIMPLE_ASSIGN
$res_LSJac10_2.$pDERLSJac10.dummyVarLSJac10 = (if rover_8d.z_rl < 1.0 then rover_8d.z_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (2.0 - rover_8d.z_rl - rover_8d.z_rl) else 0.0) - rover_8d.fz_rl.$pDERD.dummyVarD.SeedLSJac10
*/
void RoverExample_Components_Rover_eqFunction_1012(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,1012};
  modelica_boolean tmp423;
  tmp423 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */),1.0);
  jacobian->resultVars[1] /* $res_LSJac10_2.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_VAR */ = (tmp423?(jacobian->tmpVars[17] /* rover_8d.z_rl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):0.0) - jacobian->seedVars[0] /* rover_8d.fz_rl.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 1013
type: SIMPLE_ASSIGN
$res_LSJac10_3.$pDERLSJac10.dummyVarLSJac10 = (if rover_8d.z_fl < 1.0 then rover_8d.z_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (2.0 - rover_8d.z_fl - rover_8d.z_fl) else 0.0) - rover_8d.fz_fl.$pDERD.dummyVarD.SeedLSJac10
*/
void RoverExample_Components_Rover_eqFunction_1013(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,1013};
  modelica_boolean tmp424;
  tmp424 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */),1.0);
  jacobian->resultVars[2] /* $res_LSJac10_3.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_VAR */ = (tmp424?(jacobian->tmpVars[13] /* rover_8d.z_fl.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):0.0) - jacobian->seedVars[1] /* rover_8d.fz_fl.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 1014
type: SIMPLE_ASSIGN
$res_LSJac10_4.$pDERLSJac10.dummyVarLSJac10 = (if rover_8d.z_fr < 1.0 then rover_8d.z_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 * (2.0 - rover_8d.z_fr - rover_8d.z_fr) else 0.0) - rover_8d.fz_fr.$pDERD.dummyVarD.SeedLSJac10
*/
void RoverExample_Components_Rover_eqFunction_1014(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,1014};
  modelica_boolean tmp425;
  tmp425 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */),1.0);
  jacobian->resultVars[3] /* $res_LSJac10_4.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_VAR */ = (tmp425?(jacobian->tmpVars[11] /* rover_8d.z_fr.$pDERD.dummyVarD.$pDERLSJac10.dummyVarLSJac10 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):0.0) - jacobian->seedVars[2] /* rover_8d.fz_fr.$pDERD.dummyVarD.SeedLSJac10 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac10_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac10;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac10_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac10;
  RoverExample_Components_Rover_eqFunction_993(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_994(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_995(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_996(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_997(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_998(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_999(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1000(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1001(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1002(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1003(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1004(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1005(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1006(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1007(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1008(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1009(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1010(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1011(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1012(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1013(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1014(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 1045
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11 = (-4.0) * rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_1045(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,1045};
  jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */ = (-4.0) * (DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 SEED_VAR */,(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J"));
  TRACE_POP
}

/*
equation index: 1046
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11 = rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_1046(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,1046};
  jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 1047
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11 = rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_1047(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,1047};
  jacobian->tmpVars[2] /* der(rover_8d.omega_rr.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 1048
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11 = rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_1048(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,1048};
  jacobian->tmpVars[3] /* der(rover_8d.omega_rl.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 1049
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11 = 4.0 * $DER.rover_8d.omega.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11 / rover_8d.gratio - $DER.rover_8d.omega_fl.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11 - $DER.rover_8d.omega_rl.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11 - $DER.rover_8d.omega_rr.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11
*/
void RoverExample_Components_Rover_eqFunction_1049(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,1049};
  jacobian->tmpVars[4] /* der(rover_8d.omega_fr.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */ = (4.0) * (DIVISION(jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[3] /* der(rover_8d.omega_rl.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[2] /* der(rover_8d.omega_rr.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 1050
type: SIMPLE_ASSIGN
$res_LSJac11_1.$pDERLSJac11.dummyVarLSJac11 = rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 - $DER.rover_8d.omega_fr.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11 * rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_1050(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,1050};
  jacobian->resultVars[0] /* $res_LSJac11_1.$pDERLSJac11.dummyVarLSJac11 JACOBIAN_VAR */ = jacobian->seedVars[0] /* rover_8d.thr.$pDERD.dummyVarD.SeedLSJac11 SEED_VAR */ - ((jacobian->tmpVars[4] /* der(rover_8d.omega_fr.$pDERD.dummyVarD.$pDERLSJac11.dummyVarLSJac11) JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac11_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac11;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac11_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac11;
  RoverExample_Components_Rover_eqFunction_1045(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1046(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1047(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1048(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1049(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_1050(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 873
type: SIMPLE_ASSIGN
rover_8d.Fx_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.fz_fl.$pDERC.dummyVarC.SeedLSJac8 / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_873(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,873};
  jacobian->tmpVars[0] /* rover_8d.Fx_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION(jacobian->seedVars[3] /* rover_8d.fz_fl.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}

/*
equation index: 874
type: SIMPLE_ASSIGN
rover_8d.Fy_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = rover_8d.c_alpha * $cse17 * rover_8d.fz_fl.$pDERC.dummyVarC.SeedLSJac8 / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_874(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,874};
  jacobian->tmpVars[1] /* rover_8d.Fy_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION(jacobian->seedVars[3] /* rover_8d.fz_fl.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}

/*
equation index: 875
type: SIMPLE_ASSIGN
rover_8d.Fx_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.fz_rl.$pDERC.dummyVarC.SeedLSJac8 / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_875(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,875};
  jacobian->tmpVars[2] /* rover_8d.Fx_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION(jacobian->seedVars[2] /* rover_8d.fz_rl.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}

/*
equation index: 876
type: SIMPLE_ASSIGN
rover_8d.Fy_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = rover_8d.c_alpha * $cse25 * rover_8d.fz_rl.$pDERC.dummyVarC.SeedLSJac8 / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_876(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,876};
  jacobian->tmpVars[3] /* rover_8d.Fy_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION(jacobian->seedVars[2] /* rover_8d.fz_rl.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}

/*
equation index: 877
type: SIMPLE_ASSIGN
rover_8d.Fy_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = rover_8d.c_alpha * $cse21 * rover_8d.fz_fr.$pDERC.dummyVarC.SeedLSJac8 / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_877(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,877};
  jacobian->tmpVars[4] /* rover_8d.Fy_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION(jacobian->seedVars[1] /* rover_8d.fz_fr.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}

/*
equation index: 878
type: SIMPLE_ASSIGN
rover_8d.Fx_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.fz_fr.$pDERC.dummyVarC.SeedLSJac8 / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_878(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,878};
  jacobian->tmpVars[5] /* rover_8d.Fx_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION(jacobian->seedVars[1] /* rover_8d.fz_fr.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}

/*
equation index: 879
type: SIMPLE_ASSIGN
rover_8d.Fx_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.fz_rr.$pDERC.dummyVarC.SeedLSJac8 / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_879(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,879};
  jacobian->tmpVars[6] /* rover_8d.Fx_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION(jacobian->seedVars[0] /* rover_8d.fz_rr.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}

/*
equation index: 880
type: SIMPLE_ASSIGN
rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = (rover_8d.Fx_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * $cse34 + rover_8d.Fy_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * $cse35 + rover_8d.Fx_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * $cse34 + rover_8d.Fy_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * $cse35 + rover_8d.Fx_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 + rover_8d.Fx_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_880(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,880};
  jacobian->tmpVars[7] /* rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = DIVISION((jacobian->tmpVars[0] /* rover_8d.Fx_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[1] /* rover_8d.Fy_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (jacobian->tmpVars[5] /* rover_8d.Fx_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[4] /* rover_8d.Fy_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + jacobian->tmpVars[2] /* rover_8d.Fx_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ + jacobian->tmpVars[6] /* rover_8d.Fx_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}

/*
equation index: 881
type: SIMPLE_ASSIGN
rover_8d.Fy_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = rover_8d.c_alpha * $cse29 * rover_8d.fz_rr.$pDERC.dummyVarC.SeedLSJac8 / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_881(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,881};
  jacobian->tmpVars[8] /* rover_8d.Fy_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION(jacobian->seedVars[0] /* rover_8d.fz_rr.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}

/*
equation index: 882
type: SIMPLE_ASSIGN
rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = (rover_8d.Fy_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * $cse34 + rover_8d.Fy_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * $cse34 + rover_8d.Fy_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 + rover_8d.Fy_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 + ((-rover_8d.Fx_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8) - rover_8d.Fx_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8) * $cse35) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_882(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,882};
  jacobian->tmpVars[9] /* rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = DIVISION((jacobian->tmpVars[1] /* rover_8d.Fy_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[4] /* rover_8d.Fy_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + jacobian->tmpVars[3] /* rover_8d.Fy_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ + jacobian->tmpVars[8] /* rover_8d.Fy_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ + ((-jacobian->tmpVars[0] /* rover_8d.Fx_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) - jacobian->tmpVars[5] /* rover_8d.Fx_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}

/*
equation index: 883
type: SIMPLE_ASSIGN
rover_8d.Fz_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 / rover_8d.l_total - rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_883(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,883};
  jacobian->tmpVars[10] /* rover_8d.Fz_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[7] /* rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - ((jacobian->tmpVars[9] /* rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}

/*
equation index: 884
type: SIMPLE_ASSIGN
rover_8d.z_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_fr * rover_8d.Fz_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_884(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,884};
  modelica_real tmp426;
  modelica_real tmp427;
  modelica_real tmp428;
  modelica_boolean tmp429;
  modelica_real tmp430;
  modelica_real tmp431;
  modelica_real tmp432;
  modelica_boolean tmp433;
  modelica_real tmp434;
  modelica_real tmp435;
  modelica_real tmp436;
  modelica_boolean tmp437;
  modelica_real tmp438;
  modelica_boolean tmp439;
  modelica_real tmp440;
  tmp426 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp427 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
  tmp428 = (tmp426 * tmp426) + (tmp427 * tmp427) + 1e-15;
  if(!(tmp428 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp428);
    }
  }tmp429 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp428),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp439 = (modelica_boolean)tmp429;
  if(tmp439)
  {
    tmp440 = 0.0;
  }
  else
  {
    tmp430 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
    tmp431 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
    tmp432 = (tmp430 * tmp430) + (tmp431 * tmp431) + 1e-15;
    if(!(tmp432 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp432);
      }
    }tmp433 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp432),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp437 = (modelica_boolean)tmp433;
    if(tmp437)
    {
      tmp438 = 0.0;
    }
    else
    {
      tmp434 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp435 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp436 = (tmp434 * tmp434) + (tmp435 * tmp435) + 1e-15;
      if(!(tmp436 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp436);
        }
      }
      tmp438 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * ((jacobian->tmpVars[10] /* rover_8d.Fz_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp436),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))));
    }
    tmp440 = tmp438;
  }
  jacobian->tmpVars[11] /* rover_8d.z_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = tmp440;
  TRACE_POP
}

/*
equation index: 885
type: SIMPLE_ASSIGN
rover_8d.Fz_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 / rover_8d.l_total + rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_885(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,885};
  jacobian->tmpVars[12] /* rover_8d.Fz_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[7] /* rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (jacobian->tmpVars[9] /* rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}

/*
equation index: 886
type: SIMPLE_ASSIGN
rover_8d.z_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_rl * rover_8d.Fz_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_886(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,886};
  modelica_real tmp441;
  modelica_real tmp442;
  modelica_real tmp443;
  modelica_boolean tmp444;
  modelica_real tmp445;
  modelica_real tmp446;
  modelica_real tmp447;
  modelica_boolean tmp448;
  modelica_real tmp449;
  modelica_real tmp450;
  modelica_real tmp451;
  modelica_boolean tmp452;
  modelica_real tmp453;
  modelica_boolean tmp454;
  modelica_real tmp455;
  tmp441 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp442 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
  tmp443 = (tmp441 * tmp441) + (tmp442 * tmp442) + 1e-15;
  if(!(tmp443 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp443);
    }
  }tmp444 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp443),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp454 = (modelica_boolean)tmp444;
  if(tmp454)
  {
    tmp455 = 0.0;
  }
  else
  {
    tmp445 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
    tmp446 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
    tmp447 = (tmp445 * tmp445) + (tmp446 * tmp446) + 1e-15;
    if(!(tmp447 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp447);
      }
    }tmp448 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp447),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp452 = (modelica_boolean)tmp448;
    if(tmp452)
    {
      tmp453 = 0.0;
    }
    else
    {
      tmp449 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp450 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp451 = (tmp449 * tmp449) + (tmp450 * tmp450) + 1e-15;
      if(!(tmp451 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp451);
        }
      }
      tmp453 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * ((jacobian->tmpVars[12] /* rover_8d.Fz_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp451),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))));
    }
    tmp455 = tmp453;
  }
  jacobian->tmpVars[13] /* rover_8d.z_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = tmp455;
  TRACE_POP
}

/*
equation index: 887
type: SIMPLE_ASSIGN
rover_8d.Fz_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 / rover_8d.l_total - rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_887(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,887};
  jacobian->tmpVars[14] /* rover_8d.Fz_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[7] /* rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - ((jacobian->tmpVars[9] /* rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}

/*
equation index: 888
type: SIMPLE_ASSIGN
rover_8d.z_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_rr * rover_8d.Fz_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_888(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,888};
  modelica_real tmp456;
  modelica_real tmp457;
  modelica_real tmp458;
  modelica_boolean tmp459;
  modelica_real tmp460;
  modelica_real tmp461;
  modelica_real tmp462;
  modelica_boolean tmp463;
  modelica_real tmp464;
  modelica_real tmp465;
  modelica_real tmp466;
  modelica_boolean tmp467;
  modelica_real tmp468;
  modelica_boolean tmp469;
  modelica_real tmp470;
  tmp456 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp457 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
  tmp458 = (tmp456 * tmp456) + (tmp457 * tmp457) + 1e-15;
  if(!(tmp458 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp458);
    }
  }tmp459 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp458),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp469 = (modelica_boolean)tmp459;
  if(tmp469)
  {
    tmp470 = 0.0;
  }
  else
  {
    tmp460 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
    tmp461 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
    tmp462 = (tmp460 * tmp460) + (tmp461 * tmp461) + 1e-15;
    if(!(tmp462 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp462);
      }
    }tmp463 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp462),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp467 = (modelica_boolean)tmp463;
    if(tmp467)
    {
      tmp468 = 0.0;
    }
    else
    {
      tmp464 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp465 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp466 = (tmp464 * tmp464) + (tmp465 * tmp465) + 1e-15;
      if(!(tmp466 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp466);
        }
      }
      tmp468 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * ((jacobian->tmpVars[14] /* rover_8d.Fz_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp466),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))));
    }
    tmp470 = tmp468;
  }
  jacobian->tmpVars[15] /* rover_8d.z_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = tmp470;
  TRACE_POP
}

/*
equation index: 889
type: SIMPLE_ASSIGN
rover_8d.Fz_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 / rover_8d.l_total + rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_889(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,889};
  jacobian->tmpVars[16] /* rover_8d.Fz_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[7] /* rover_8d.ax.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (jacobian->tmpVars[9] /* rover_8d.ay.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}

/*
equation index: 890
type: SIMPLE_ASSIGN
rover_8d.z_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 = if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_fl * rover_8d.Fz_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_890(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,890};
  modelica_real tmp471;
  modelica_real tmp472;
  modelica_real tmp473;
  modelica_boolean tmp474;
  modelica_real tmp475;
  modelica_real tmp476;
  modelica_real tmp477;
  modelica_boolean tmp478;
  modelica_real tmp479;
  modelica_real tmp480;
  modelica_real tmp481;
  modelica_boolean tmp482;
  modelica_real tmp483;
  modelica_boolean tmp484;
  modelica_real tmp485;
  tmp471 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp472 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
  tmp473 = (tmp471 * tmp471) + (tmp472 * tmp472) + 1e-15;
  if(!(tmp473 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp473);
    }
  }tmp474 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp473),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp484 = (modelica_boolean)tmp474;
  if(tmp484)
  {
    tmp485 = 0.0;
  }
  else
  {
    tmp475 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
    tmp476 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
    tmp477 = (tmp475 * tmp475) + (tmp476 * tmp476) + 1e-15;
    if(!(tmp477 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp477);
      }
    }tmp478 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp477),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp482 = (modelica_boolean)tmp478;
    if(tmp482)
    {
      tmp483 = 0.0;
    }
    else
    {
      tmp479 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp480 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp481 = (tmp479 * tmp479) + (tmp480 * tmp480) + 1e-15;
      if(!(tmp481 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp481);
        }
      }
      tmp483 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * ((jacobian->tmpVars[16] /* rover_8d.Fz_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp481),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))));
    }
    tmp485 = tmp483;
  }
  jacobian->tmpVars[17] /* rover_8d.z_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */ = tmp485;
  TRACE_POP
}

/*
equation index: 891
type: SIMPLE_ASSIGN
$res_LSJac8_1.$pDERLSJac8.dummyVarLSJac8 = (if rover_8d.z_rl < 1.0 then rover_8d.z_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (2.0 - rover_8d.z_rl - rover_8d.z_rl) else 0.0) - rover_8d.fz_rl.$pDERC.dummyVarC.SeedLSJac8
*/
void RoverExample_Components_Rover_eqFunction_891(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,891};
  modelica_boolean tmp486;
  tmp486 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */),1.0);
  jacobian->resultVars[0] /* $res_LSJac8_1.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_VAR */ = (tmp486?(jacobian->tmpVars[13] /* rover_8d.z_rl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):0.0) - jacobian->seedVars[2] /* rover_8d.fz_rl.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 892
type: SIMPLE_ASSIGN
$res_LSJac8_2.$pDERLSJac8.dummyVarLSJac8 = (if rover_8d.z_rr < 1.0 then rover_8d.z_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (2.0 - rover_8d.z_rr - rover_8d.z_rr) else 0.0) - rover_8d.fz_rr.$pDERC.dummyVarC.SeedLSJac8
*/
void RoverExample_Components_Rover_eqFunction_892(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,892};
  modelica_boolean tmp487;
  tmp487 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */),1.0);
  jacobian->resultVars[1] /* $res_LSJac8_2.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_VAR */ = (tmp487?(jacobian->tmpVars[15] /* rover_8d.z_rr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):0.0) - jacobian->seedVars[0] /* rover_8d.fz_rr.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 893
type: SIMPLE_ASSIGN
$res_LSJac8_3.$pDERLSJac8.dummyVarLSJac8 = (if rover_8d.z_fr < 1.0 then rover_8d.z_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (2.0 - rover_8d.z_fr - rover_8d.z_fr) else 0.0) - rover_8d.fz_fr.$pDERC.dummyVarC.SeedLSJac8
*/
void RoverExample_Components_Rover_eqFunction_893(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,893};
  modelica_boolean tmp488;
  tmp488 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */),1.0);
  jacobian->resultVars[2] /* $res_LSJac8_3.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_VAR */ = (tmp488?(jacobian->tmpVars[11] /* rover_8d.z_fr.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):0.0) - jacobian->seedVars[1] /* rover_8d.fz_fr.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 894
type: SIMPLE_ASSIGN
$res_LSJac8_4.$pDERLSJac8.dummyVarLSJac8 = (if rover_8d.z_fl < 1.0 then rover_8d.z_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 * (2.0 - rover_8d.z_fl - rover_8d.z_fl) else 0.0) - rover_8d.fz_fl.$pDERC.dummyVarC.SeedLSJac8
*/
void RoverExample_Components_Rover_eqFunction_894(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,894};
  modelica_boolean tmp489;
  tmp489 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */),1.0);
  jacobian->resultVars[3] /* $res_LSJac8_4.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_VAR */ = (tmp489?(jacobian->tmpVars[17] /* rover_8d.z_fl.$pDERC.dummyVarC.$pDERLSJac8.dummyVarLSJac8 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):0.0) - jacobian->seedVars[3] /* rover_8d.fz_fl.$pDERC.dummyVarC.SeedLSJac8 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac8_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac8;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac8_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac8;
  RoverExample_Components_Rover_eqFunction_873(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_874(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_875(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_876(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_877(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_878(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_879(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_880(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_881(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_882(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_883(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_884(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_885(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_886(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_887(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_888(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_889(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_890(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_891(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_892(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_893(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_894(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 908
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9 = (-4.0) * rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_908(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,908};
  jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */ = (-4.0) * (DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 SEED_VAR */,(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J"));
  TRACE_POP
}

/*
equation index: 909
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9 = rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_909(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,909};
  jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 910
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9 = rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_910(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,910};
  jacobian->tmpVars[2] /* der(rover_8d.omega_fr.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 911
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9 = rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_911(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,911};
  jacobian->tmpVars[3] /* der(rover_8d.omega_rl.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 912
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9 = 4.0 * $DER.rover_8d.omega.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9 / rover_8d.gratio - $DER.rover_8d.omega_fl.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9 - $DER.rover_8d.omega_fr.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9 - $DER.rover_8d.omega_rl.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9
*/
void RoverExample_Components_Rover_eqFunction_912(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,912};
  jacobian->tmpVars[4] /* der(rover_8d.omega_rr.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */ = (4.0) * (DIVISION(jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[2] /* der(rover_8d.omega_fr.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[3] /* der(rover_8d.omega_rl.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 913
type: SIMPLE_ASSIGN
$res_LSJac9_1.$pDERLSJac9.dummyVarLSJac9 = rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 - $DER.rover_8d.omega_rr.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9 * rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_913(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,913};
  jacobian->resultVars[0] /* $res_LSJac9_1.$pDERLSJac9.dummyVarLSJac9 JACOBIAN_VAR */ = jacobian->seedVars[0] /* rover_8d.thr.$pDERC.dummyVarC.SeedLSJac9 SEED_VAR */ - ((jacobian->tmpVars[4] /* der(rover_8d.omega_rr.$pDERC.dummyVarC.$pDERLSJac9.dummyVarLSJac9) JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac9_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac9;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac9_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac9;
  RoverExample_Components_Rover_eqFunction_908(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_909(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_910(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_911(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_912(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_913(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 689
type: SIMPLE_ASSIGN
rover_8d.Fx_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.fz_fr.$pDERB.dummyVarB.SeedLSJac6 / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_689(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,689};
  jacobian->tmpVars[0] /* rover_8d.Fx_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION(jacobian->seedVars[3] /* rover_8d.fz_fr.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}

/*
equation index: 690
type: SIMPLE_ASSIGN
rover_8d.Fy_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = rover_8d.c_alpha * $cse21 * rover_8d.fz_fr.$pDERB.dummyVarB.SeedLSJac6 / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_690(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,690};
  jacobian->tmpVars[1] /* rover_8d.Fy_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION(jacobian->seedVars[3] /* rover_8d.fz_fr.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}

/*
equation index: 691
type: SIMPLE_ASSIGN
rover_8d.Fx_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.fz_rr.$pDERB.dummyVarB.SeedLSJac6 / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_691(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,691};
  jacobian->tmpVars[2] /* rover_8d.Fx_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION(jacobian->seedVars[2] /* rover_8d.fz_rr.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}

/*
equation index: 692
type: SIMPLE_ASSIGN
rover_8d.Fy_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = rover_8d.c_alpha * $cse29 * rover_8d.fz_rr.$pDERB.dummyVarB.SeedLSJac6 / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_692(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,692};
  jacobian->tmpVars[3] /* rover_8d.Fy_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION(jacobian->seedVars[2] /* rover_8d.fz_rr.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}

/*
equation index: 693
type: SIMPLE_ASSIGN
rover_8d.Fx_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.fz_fl.$pDERB.dummyVarB.SeedLSJac6 / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_693(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,693};
  jacobian->tmpVars[4] /* rover_8d.Fx_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION(jacobian->seedVars[1] /* rover_8d.fz_fl.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}

/*
equation index: 694
type: SIMPLE_ASSIGN
rover_8d.Fy_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = rover_8d.c_alpha * $cse17 * rover_8d.fz_fl.$pDERB.dummyVarB.SeedLSJac6 / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_694(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,694};
  jacobian->tmpVars[5] /* rover_8d.Fy_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION(jacobian->seedVars[1] /* rover_8d.fz_fl.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}

/*
equation index: 695
type: SIMPLE_ASSIGN
rover_8d.Fy_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = rover_8d.c_alpha * $cse25 * rover_8d.fz_rl.$pDERB.dummyVarB.SeedLSJac6 / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_695(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,695};
  jacobian->tmpVars[6] /* rover_8d.Fy_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION(jacobian->seedVars[0] /* rover_8d.fz_rl.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}

/*
equation index: 696
type: SIMPLE_ASSIGN
rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = (rover_8d.Fy_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * $cse34 + rover_8d.Fy_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * $cse34 + rover_8d.Fy_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 + rover_8d.Fy_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 + ((-rover_8d.Fx_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6) - rover_8d.Fx_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6) * $cse35) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_696(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,696};
  jacobian->tmpVars[7] /* rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = DIVISION((jacobian->tmpVars[5] /* rover_8d.Fy_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[1] /* rover_8d.Fy_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + jacobian->tmpVars[6] /* rover_8d.Fy_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ + jacobian->tmpVars[3] /* rover_8d.Fy_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ + ((-jacobian->tmpVars[4] /* rover_8d.Fx_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) - jacobian->tmpVars[0] /* rover_8d.Fx_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}

/*
equation index: 697
type: SIMPLE_ASSIGN
rover_8d.Fx_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.fz_rl.$pDERB.dummyVarB.SeedLSJac6 / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_697(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,697};
  jacobian->tmpVars[8] /* rover_8d.Fx_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION(jacobian->seedVars[0] /* rover_8d.fz_rl.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}

/*
equation index: 698
type: SIMPLE_ASSIGN
$DER.rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = (rover_8d.Fx_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * $cse34 + rover_8d.Fy_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * $cse35 + rover_8d.Fx_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * $cse34 + rover_8d.Fy_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * $cse35 + rover_8d.Fx_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 + rover_8d.Fx_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_698(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,698};
  jacobian->tmpVars[9] /* der(rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6) JACOBIAN_TMP_VAR */ = DIVISION((jacobian->tmpVars[4] /* rover_8d.Fx_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[5] /* rover_8d.Fy_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (jacobian->tmpVars[0] /* rover_8d.Fx_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[1] /* rover_8d.Fy_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + jacobian->tmpVars[8] /* rover_8d.Fx_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ + jacobian->tmpVars[2] /* rover_8d.Fx_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}

/*
equation index: 699
type: SIMPLE_ASSIGN
rover_8d.Fz_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 / rover_8d.l_total - rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_699(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,699};
  jacobian->tmpVars[10] /* rover_8d.Fz_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[9] /* der(rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - ((jacobian->tmpVars[7] /* rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}

/*
equation index: 700
type: SIMPLE_ASSIGN
rover_8d.z_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_rr * rover_8d.Fz_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_700(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,700};
  modelica_real tmp490;
  modelica_real tmp491;
  modelica_real tmp492;
  modelica_boolean tmp493;
  modelica_real tmp494;
  modelica_real tmp495;
  modelica_real tmp496;
  modelica_boolean tmp497;
  modelica_real tmp498;
  modelica_real tmp499;
  modelica_real tmp500;
  modelica_boolean tmp501;
  modelica_real tmp502;
  modelica_boolean tmp503;
  modelica_real tmp504;
  tmp490 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp491 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
  tmp492 = (tmp490 * tmp490) + (tmp491 * tmp491) + 1e-15;
  if(!(tmp492 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp492);
    }
  }tmp493 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp492),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp503 = (modelica_boolean)tmp493;
  if(tmp503)
  {
    tmp504 = 0.0;
  }
  else
  {
    tmp494 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
    tmp495 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
    tmp496 = (tmp494 * tmp494) + (tmp495 * tmp495) + 1e-15;
    if(!(tmp496 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp496);
      }
    }tmp497 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp496),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp501 = (modelica_boolean)tmp497;
    if(tmp501)
    {
      tmp502 = 0.0;
    }
    else
    {
      tmp498 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp499 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp500 = (tmp498 * tmp498) + (tmp499 * tmp499) + 1e-15;
      if(!(tmp500 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp500);
        }
      }
      tmp502 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * ((jacobian->tmpVars[10] /* rover_8d.Fz_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp500),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))));
    }
    tmp504 = tmp502;
  }
  jacobian->tmpVars[11] /* rover_8d.z_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = tmp504;
  TRACE_POP
}

/*
equation index: 701
type: SIMPLE_ASSIGN
rover_8d.Fz_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 / rover_8d.l_total - rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_701(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,701};
  jacobian->tmpVars[12] /* rover_8d.Fz_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[9] /* der(rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - ((jacobian->tmpVars[7] /* rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}

/*
equation index: 702
type: SIMPLE_ASSIGN
rover_8d.z_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_fr * rover_8d.Fz_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_702(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,702};
  modelica_real tmp505;
  modelica_real tmp506;
  modelica_real tmp507;
  modelica_boolean tmp508;
  modelica_real tmp509;
  modelica_real tmp510;
  modelica_real tmp511;
  modelica_boolean tmp512;
  modelica_real tmp513;
  modelica_real tmp514;
  modelica_real tmp515;
  modelica_boolean tmp516;
  modelica_real tmp517;
  modelica_boolean tmp518;
  modelica_real tmp519;
  tmp505 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp506 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
  tmp507 = (tmp505 * tmp505) + (tmp506 * tmp506) + 1e-15;
  if(!(tmp507 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp507);
    }
  }tmp508 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp507),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp518 = (modelica_boolean)tmp508;
  if(tmp518)
  {
    tmp519 = 0.0;
  }
  else
  {
    tmp509 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
    tmp510 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
    tmp511 = (tmp509 * tmp509) + (tmp510 * tmp510) + 1e-15;
    if(!(tmp511 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp511);
      }
    }tmp512 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp511),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp516 = (modelica_boolean)tmp512;
    if(tmp516)
    {
      tmp517 = 0.0;
    }
    else
    {
      tmp513 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp514 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp515 = (tmp513 * tmp513) + (tmp514 * tmp514) + 1e-15;
      if(!(tmp515 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp515);
        }
      }
      tmp517 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * ((jacobian->tmpVars[12] /* rover_8d.Fz_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp515),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))));
    }
    tmp519 = tmp517;
  }
  jacobian->tmpVars[13] /* rover_8d.z_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = tmp519;
  TRACE_POP
}

/*
equation index: 703
type: SIMPLE_ASSIGN
rover_8d.Fz_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 / rover_8d.l_total + rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_703(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,703};
  jacobian->tmpVars[14] /* rover_8d.Fz_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[9] /* der(rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (jacobian->tmpVars[7] /* rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}

/*
equation index: 704
type: SIMPLE_ASSIGN
rover_8d.z_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_rl * rover_8d.Fz_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_704(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,704};
  modelica_real tmp520;
  modelica_real tmp521;
  modelica_real tmp522;
  modelica_boolean tmp523;
  modelica_real tmp524;
  modelica_real tmp525;
  modelica_real tmp526;
  modelica_boolean tmp527;
  modelica_real tmp528;
  modelica_real tmp529;
  modelica_real tmp530;
  modelica_boolean tmp531;
  modelica_real tmp532;
  modelica_boolean tmp533;
  modelica_real tmp534;
  tmp520 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp521 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
  tmp522 = (tmp520 * tmp520) + (tmp521 * tmp521) + 1e-15;
  if(!(tmp522 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp522);
    }
  }tmp523 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp522),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp533 = (modelica_boolean)tmp523;
  if(tmp533)
  {
    tmp534 = 0.0;
  }
  else
  {
    tmp524 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
    tmp525 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
    tmp526 = (tmp524 * tmp524) + (tmp525 * tmp525) + 1e-15;
    if(!(tmp526 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp526);
      }
    }tmp527 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp526),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp531 = (modelica_boolean)tmp527;
    if(tmp531)
    {
      tmp532 = 0.0;
    }
    else
    {
      tmp528 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp529 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp530 = (tmp528 * tmp528) + (tmp529 * tmp529) + 1e-15;
      if(!(tmp530 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp530);
        }
      }
      tmp532 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * ((jacobian->tmpVars[14] /* rover_8d.Fz_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp530),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))));
    }
    tmp534 = tmp532;
  }
  jacobian->tmpVars[15] /* rover_8d.z_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = tmp534;
  TRACE_POP
}

/*
equation index: 705
type: SIMPLE_ASSIGN
rover_8d.Fz_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * $DER.rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 / rover_8d.l_total + rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_705(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,705};
  jacobian->tmpVars[16] /* rover_8d.Fz_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[9] /* der(rover_8d.vx.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (jacobian->tmpVars[7] /* rover_8d.ay.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}

/*
equation index: 706
type: SIMPLE_ASSIGN
rover_8d.z_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 = if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_fl * rover_8d.Fz_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_706(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,706};
  modelica_real tmp535;
  modelica_real tmp536;
  modelica_real tmp537;
  modelica_boolean tmp538;
  modelica_real tmp539;
  modelica_real tmp540;
  modelica_real tmp541;
  modelica_boolean tmp542;
  modelica_real tmp543;
  modelica_real tmp544;
  modelica_real tmp545;
  modelica_boolean tmp546;
  modelica_real tmp547;
  modelica_boolean tmp548;
  modelica_real tmp549;
  tmp535 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp536 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
  tmp537 = (tmp535 * tmp535) + (tmp536 * tmp536) + 1e-15;
  if(!(tmp537 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp537);
    }
  }tmp538 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp537),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp548 = (modelica_boolean)tmp538;
  if(tmp548)
  {
    tmp549 = 0.0;
  }
  else
  {
    tmp539 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
    tmp540 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
    tmp541 = (tmp539 * tmp539) + (tmp540 * tmp540) + 1e-15;
    if(!(tmp541 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp541);
      }
    }tmp542 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp541),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp546 = (modelica_boolean)tmp542;
    if(tmp546)
    {
      tmp547 = 0.0;
    }
    else
    {
      tmp543 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp544 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp545 = (tmp543 * tmp543) + (tmp544 * tmp544) + 1e-15;
      if(!(tmp545 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp545);
        }
      }
      tmp547 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * ((jacobian->tmpVars[16] /* rover_8d.Fz_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp545),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))));
    }
    tmp549 = tmp547;
  }
  jacobian->tmpVars[17] /* rover_8d.z_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */ = tmp549;
  TRACE_POP
}

/*
equation index: 707
type: SIMPLE_ASSIGN
$res_LSJac6_1.$pDERLSJac6.dummyVarLSJac6 = (if rover_8d.z_rl < 1.0 then rover_8d.z_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (2.0 - rover_8d.z_rl - rover_8d.z_rl) else 0.0) - rover_8d.fz_rl.$pDERB.dummyVarB.SeedLSJac6
*/
void RoverExample_Components_Rover_eqFunction_707(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,707};
  modelica_boolean tmp550;
  tmp550 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */),1.0);
  jacobian->resultVars[0] /* $res_LSJac6_1.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_VAR */ = (tmp550?(jacobian->tmpVars[15] /* rover_8d.z_rl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):0.0) - jacobian->seedVars[0] /* rover_8d.fz_rl.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 708
type: SIMPLE_ASSIGN
$res_LSJac6_2.$pDERLSJac6.dummyVarLSJac6 = (if rover_8d.z_fl < 1.0 then rover_8d.z_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (2.0 - rover_8d.z_fl - rover_8d.z_fl) else 0.0) - rover_8d.fz_fl.$pDERB.dummyVarB.SeedLSJac6
*/
void RoverExample_Components_Rover_eqFunction_708(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,708};
  modelica_boolean tmp551;
  tmp551 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */),1.0);
  jacobian->resultVars[1] /* $res_LSJac6_2.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_VAR */ = (tmp551?(jacobian->tmpVars[17] /* rover_8d.z_fl.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):0.0) - jacobian->seedVars[1] /* rover_8d.fz_fl.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 709
type: SIMPLE_ASSIGN
$res_LSJac6_3.$pDERLSJac6.dummyVarLSJac6 = (if rover_8d.z_rr < 1.0 then rover_8d.z_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (2.0 - rover_8d.z_rr - rover_8d.z_rr) else 0.0) - rover_8d.fz_rr.$pDERB.dummyVarB.SeedLSJac6
*/
void RoverExample_Components_Rover_eqFunction_709(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,709};
  modelica_boolean tmp552;
  tmp552 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */),1.0);
  jacobian->resultVars[2] /* $res_LSJac6_3.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_VAR */ = (tmp552?(jacobian->tmpVars[11] /* rover_8d.z_rr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):0.0) - jacobian->seedVars[2] /* rover_8d.fz_rr.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 710
type: SIMPLE_ASSIGN
$res_LSJac6_4.$pDERLSJac6.dummyVarLSJac6 = (if rover_8d.z_fr < 1.0 then rover_8d.z_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 * (2.0 - rover_8d.z_fr - rover_8d.z_fr) else 0.0) - rover_8d.fz_fr.$pDERB.dummyVarB.SeedLSJac6
*/
void RoverExample_Components_Rover_eqFunction_710(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,710};
  modelica_boolean tmp553;
  tmp553 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */),1.0);
  jacobian->resultVars[3] /* $res_LSJac6_4.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_VAR */ = (tmp553?(jacobian->tmpVars[13] /* rover_8d.z_fr.$pDERB.dummyVarB.$pDERLSJac6.dummyVarLSJac6 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):0.0) - jacobian->seedVars[3] /* rover_8d.fz_fr.$pDERB.dummyVarB.SeedLSJac6 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac6_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac6;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac6_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac6;
  RoverExample_Components_Rover_eqFunction_689(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_690(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_691(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_692(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_693(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_694(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_695(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_696(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_697(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_698(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_699(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_700(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_701(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_702(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_703(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_704(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_705(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_706(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_707(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_708(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_709(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_710(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 721
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7 = (-4.0) * rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_721(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,721};
  jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */ = (-4.0) * (DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 SEED_VAR */,(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J"));
  TRACE_POP
}

/*
equation index: 722
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7 = rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_722(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,722};
  jacobian->tmpVars[1] /* der(rover_8d.omega_fr.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 723
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7 = rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_723(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,723};
  jacobian->tmpVars[2] /* der(rover_8d.omega_fl.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 724
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7 = rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_724(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,724};
  jacobian->tmpVars[3] /* der(rover_8d.omega_rl.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 725
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7 = 4.0 * $DER.rover_8d.omega.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7 / rover_8d.gratio - $DER.rover_8d.omega_fl.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7 - $DER.rover_8d.omega_fr.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7 - $DER.rover_8d.omega_rl.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7
*/
void RoverExample_Components_Rover_eqFunction_725(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,725};
  jacobian->tmpVars[4] /* der(rover_8d.omega_rr.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */ = (4.0) * (DIVISION(jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - jacobian->tmpVars[2] /* der(rover_8d.omega_fl.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[1] /* der(rover_8d.omega_fr.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[3] /* der(rover_8d.omega_rl.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 726
type: SIMPLE_ASSIGN
$res_LSJac7_1.$pDERLSJac7.dummyVarLSJac7 = rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 - $DER.rover_8d.omega_rr.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7 * rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_726(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,726};
  jacobian->resultVars[0] /* $res_LSJac7_1.$pDERLSJac7.dummyVarLSJac7 JACOBIAN_VAR */ = jacobian->seedVars[0] /* rover_8d.thr.$pDERB.dummyVarB.SeedLSJac7 SEED_VAR */ - ((jacobian->tmpVars[4] /* der(rover_8d.omega_rr.$pDERB.dummyVarB.$pDERLSJac7.dummyVarLSJac7) JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac7_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac7;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac7_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac7;
  RoverExample_Components_Rover_eqFunction_721(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_722(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_723(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_724(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_725(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_726(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 571
type: SIMPLE_ASSIGN
rover_8d.Fx_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.fz_fl.$pDERA.dummyVarA.SeedLSJac4 / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_571(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,571};
  jacobian->tmpVars[0] /* rover_8d.Fx_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION(jacobian->seedVars[3] /* rover_8d.fz_fl.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}

/*
equation index: 572
type: SIMPLE_ASSIGN
rover_8d.Fy_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = rover_8d.c_alpha * $cse17 * rover_8d.fz_fl.$pDERA.dummyVarA.SeedLSJac4 / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_572(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,572};
  jacobian->tmpVars[1] /* rover_8d.Fy_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION(jacobian->seedVars[3] /* rover_8d.fz_fl.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd")));
  TRACE_POP
}

/*
equation index: 573
type: SIMPLE_ASSIGN
rover_8d.Fx_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.fz_rr.$pDERA.dummyVarA.SeedLSJac4 / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_573(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,573};
  jacobian->tmpVars[2] /* rover_8d.Fx_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION(jacobian->seedVars[2] /* rover_8d.fz_rr.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}

/*
equation index: 574
type: SIMPLE_ASSIGN
rover_8d.Fy_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = rover_8d.c_alpha * $cse29 * rover_8d.fz_rr.$pDERA.dummyVarA.SeedLSJac4 / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_574(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,574};
  jacobian->tmpVars[3] /* rover_8d.Fy_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION(jacobian->seedVars[2] /* rover_8d.fz_rr.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd")));
  TRACE_POP
}

/*
equation index: 575
type: SIMPLE_ASSIGN
rover_8d.Fx_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.fz_fr.$pDERA.dummyVarA.SeedLSJac4 / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_575(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,575};
  jacobian->tmpVars[4] /* rover_8d.Fx_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION(jacobian->seedVars[1] /* rover_8d.fz_fr.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}

/*
equation index: 576
type: SIMPLE_ASSIGN
rover_8d.Fy_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = rover_8d.c_alpha * $cse21 * rover_8d.fz_fr.$pDERA.dummyVarA.SeedLSJac4 / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_576(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,576};
  jacobian->tmpVars[5] /* rover_8d.Fy_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION(jacobian->seedVars[1] /* rover_8d.fz_fr.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd")));
  TRACE_POP
}

/*
equation index: 577
type: SIMPLE_ASSIGN
rover_8d.Fy_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = rover_8d.c_alpha * $cse25 * rover_8d.fz_rl.$pDERA.dummyVarA.SeedLSJac4 / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_577(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,577};
  jacobian->tmpVars[6] /* rover_8d.Fy_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION(jacobian->seedVars[0] /* rover_8d.fz_rl.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}

/*
equation index: 578
type: SIMPLE_ASSIGN
rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = (rover_8d.Fy_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * $cse34 + rover_8d.Fy_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * $cse34 + rover_8d.Fy_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 + rover_8d.Fy_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 + ((-rover_8d.Fx_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4) - rover_8d.Fx_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4) * $cse35) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_578(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,578};
  jacobian->tmpVars[7] /* rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = DIVISION((jacobian->tmpVars[1] /* rover_8d.Fy_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[5] /* rover_8d.Fy_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + jacobian->tmpVars[6] /* rover_8d.Fy_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ + jacobian->tmpVars[3] /* rover_8d.Fy_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ + ((-jacobian->tmpVars[0] /* rover_8d.Fx_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) - jacobian->tmpVars[4] /* rover_8d.Fx_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}

/*
equation index: 579
type: SIMPLE_ASSIGN
rover_8d.Fx_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.fz_rl.$pDERA.dummyVarA.SeedLSJac4 / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_579(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,579};
  jacobian->tmpVars[8] /* rover_8d.Fx_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION(jacobian->seedVars[0] /* rover_8d.fz_rl.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */,1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd")));
  TRACE_POP
}

/*
equation index: 580
type: SIMPLE_ASSIGN
rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = (rover_8d.Fx_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * $cse34 + rover_8d.Fy_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * $cse35 + rover_8d.Fx_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * $cse34 + rover_8d.Fy_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * $cse35 + rover_8d.Fx_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 + rover_8d.Fx_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_580(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,580};
  jacobian->tmpVars[9] /* rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = DIVISION((jacobian->tmpVars[0] /* rover_8d.Fx_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[1] /* rover_8d.Fy_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (jacobian->tmpVars[4] /* rover_8d.Fx_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (jacobian->tmpVars[5] /* rover_8d.Fy_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + jacobian->tmpVars[8] /* rover_8d.Fx_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ + jacobian->tmpVars[2] /* rover_8d.Fx_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total");
  TRACE_POP
}

/*
equation index: 581
type: SIMPLE_ASSIGN
rover_8d.Fz_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 / rover_8d.l_total - rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_581(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,581};
  jacobian->tmpVars[10] /* rover_8d.Fz_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[9] /* rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - ((jacobian->tmpVars[7] /* rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}

/*
equation index: 582
type: SIMPLE_ASSIGN
rover_8d.z_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_rr * rover_8d.Fz_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_582(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,582};
  modelica_real tmp554;
  modelica_real tmp555;
  modelica_real tmp556;
  modelica_boolean tmp557;
  modelica_real tmp558;
  modelica_real tmp559;
  modelica_real tmp560;
  modelica_boolean tmp561;
  modelica_real tmp562;
  modelica_real tmp563;
  modelica_real tmp564;
  modelica_boolean tmp565;
  modelica_real tmp566;
  modelica_boolean tmp567;
  modelica_real tmp568;
  tmp554 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp555 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
  tmp556 = (tmp554 * tmp554) + (tmp555 * tmp555) + 1e-15;
  if(!(tmp556 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp556);
    }
  }tmp557 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp556),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp567 = (modelica_boolean)tmp557;
  if(tmp567)
  {
    tmp568 = 0.0;
  }
  else
  {
    tmp558 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
    tmp559 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
    tmp560 = (tmp558 * tmp558) + (tmp559 * tmp559) + 1e-15;
    if(!(tmp560 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp560);
      }
    }tmp561 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp560),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp565 = (modelica_boolean)tmp561;
    if(tmp565)
    {
      tmp566 = 0.0;
    }
    else
    {
      tmp562 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
      tmp563 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
      tmp564 = (tmp562 * tmp562) + (tmp563 * tmp563) + 1e-15;
      if(!(tmp564 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp564);
        }
      }
      tmp566 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * ((jacobian->tmpVars[10] /* rover_8d.Fz_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),sqrt(tmp564),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)"))));
    }
    tmp568 = tmp566;
  }
  jacobian->tmpVars[11] /* rover_8d.z_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = tmp568;
  TRACE_POP
}

/*
equation index: 583
type: SIMPLE_ASSIGN
rover_8d.Fz_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 / rover_8d.l_total - rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_583(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,583};
  jacobian->tmpVars[12] /* rover_8d.Fz_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[9] /* rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) - ((jacobian->tmpVars[7] /* rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw")));
  TRACE_POP
}

/*
equation index: 584
type: SIMPLE_ASSIGN
rover_8d.z_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_fr * rover_8d.Fz_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_584(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,584};
  modelica_real tmp569;
  modelica_real tmp570;
  modelica_real tmp571;
  modelica_boolean tmp572;
  modelica_real tmp573;
  modelica_real tmp574;
  modelica_real tmp575;
  modelica_boolean tmp576;
  modelica_real tmp577;
  modelica_real tmp578;
  modelica_real tmp579;
  modelica_boolean tmp580;
  modelica_real tmp581;
  modelica_boolean tmp582;
  modelica_real tmp583;
  tmp569 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp570 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
  tmp571 = (tmp569 * tmp569) + (tmp570 * tmp570) + 1e-15;
  if(!(tmp571 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp571);
    }
  }tmp572 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp571),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp582 = (modelica_boolean)tmp572;
  if(tmp582)
  {
    tmp583 = 0.0;
  }
  else
  {
    tmp573 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
    tmp574 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
    tmp575 = (tmp573 * tmp573) + (tmp574 * tmp574) + 1e-15;
    if(!(tmp575 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp575);
      }
    }tmp576 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp575),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp580 = (modelica_boolean)tmp576;
    if(tmp580)
    {
      tmp581 = 0.0;
    }
    else
    {
      tmp577 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
      tmp578 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
      tmp579 = (tmp577 * tmp577) + (tmp578 * tmp578) + 1e-15;
      if(!(tmp579 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp579);
        }
      }
      tmp581 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * ((jacobian->tmpVars[12] /* rover_8d.Fz_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),sqrt(tmp579),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)"))));
    }
    tmp583 = tmp581;
  }
  jacobian->tmpVars[13] /* rover_8d.z_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = tmp583;
  TRACE_POP
}

/*
equation index: 585
type: SIMPLE_ASSIGN
rover_8d.Fz_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 / rover_8d.l_total + rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_585(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,585};
  jacobian->tmpVars[14] /* rover_8d.Fz_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[9] /* rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (jacobian->tmpVars[7] /* rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}

/*
equation index: 586
type: SIMPLE_ASSIGN
rover_8d.z_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_rl * rover_8d.Fz_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_586(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,586};
  modelica_real tmp584;
  modelica_real tmp585;
  modelica_real tmp586;
  modelica_boolean tmp587;
  modelica_real tmp588;
  modelica_real tmp589;
  modelica_real tmp590;
  modelica_boolean tmp591;
  modelica_real tmp592;
  modelica_real tmp593;
  modelica_real tmp594;
  modelica_boolean tmp595;
  modelica_real tmp596;
  modelica_boolean tmp597;
  modelica_real tmp598;
  tmp584 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp585 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
  tmp586 = (tmp584 * tmp584) + (tmp585 * tmp585) + 1e-15;
  if(!(tmp586 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp586);
    }
  }tmp587 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp586),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp597 = (modelica_boolean)tmp587;
  if(tmp597)
  {
    tmp598 = 0.0;
  }
  else
  {
    tmp588 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
    tmp589 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
    tmp590 = (tmp588 * tmp588) + (tmp589 * tmp589) + 1e-15;
    if(!(tmp590 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp590);
      }
    }tmp591 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp590),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp595 = (modelica_boolean)tmp591;
    if(tmp595)
    {
      tmp596 = 0.0;
    }
    else
    {
      tmp592 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
      tmp593 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
      tmp594 = (tmp592 * tmp592) + (tmp593 * tmp593) + 1e-15;
      if(!(tmp594 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp594);
        }
      }
      tmp596 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * ((jacobian->tmpVars[14] /* rover_8d.Fz_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),sqrt(tmp594),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)"))));
    }
    tmp598 = tmp596;
  }
  jacobian->tmpVars[15] /* rover_8d.z_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = tmp598;
  TRACE_POP
}

/*
equation index: 587
type: SIMPLE_ASSIGN
rover_8d.Fz_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 / rover_8d.l_total + rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_587(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,587};
  jacobian->tmpVars[16] /* rover_8d.Fz_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * (DIVISION(jacobian->tmpVars[9] /* rover_8d.ax.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + (jacobian->tmpVars[7] /* rover_8d.ay.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (DIVISION(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total"))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw"));
  TRACE_POP
}

/*
equation index: 588
type: SIMPLE_ASSIGN
rover_8d.z_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 = if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) < rover_8d.z_min) then 0.0 else if noEvent(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) > rover_8d.z_max) then 0.0 else 0.5 * rover_8d.mu_fl * rover_8d.Fz_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)
*/
void RoverExample_Components_Rover_eqFunction_588(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,588};
  modelica_real tmp599;
  modelica_real tmp600;
  modelica_real tmp601;
  modelica_boolean tmp602;
  modelica_real tmp603;
  modelica_real tmp604;
  modelica_real tmp605;
  modelica_boolean tmp606;
  modelica_real tmp607;
  modelica_real tmp608;
  modelica_real tmp609;
  modelica_boolean tmp610;
  modelica_real tmp611;
  modelica_boolean tmp612;
  modelica_real tmp613;
  tmp599 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp600 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
  tmp601 = (tmp599 * tmp599) + (tmp600 * tmp600) + 1e-15;
  if(!(tmp601 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp601);
    }
  }tmp602 = Less((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp601),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */));
  tmp612 = (modelica_boolean)tmp602;
  if(tmp612)
  {
    tmp613 = 0.0;
  }
  else
  {
    tmp603 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
    tmp604 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
    tmp605 = (tmp603 * tmp603) + (tmp604 * tmp604) + 1e-15;
    if(!(tmp605 >= 0.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        FILE_INFO info = {"",0,0,0,0,0};
        infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp605);
      }
    }tmp606 = Greater((0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */)) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp605),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)")))),(data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
    tmp610 = (modelica_boolean)tmp606;
    if(tmp610)
    {
      tmp611 = 0.0;
    }
    else
    {
      tmp607 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
      tmp608 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
      tmp609 = (tmp607 * tmp607) + (tmp608 * tmp608) + 1e-15;
      if(!(tmp609 >= 0.0))
      {
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"",0,0,0,0,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp609);
        }
      }
      tmp611 = (0.5) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * ((jacobian->tmpVars[16] /* rover_8d.Fz_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (DIVISION(1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),sqrt(tmp609),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)"))));
    }
    tmp613 = tmp611;
  }
  jacobian->tmpVars[17] /* rover_8d.z_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */ = tmp613;
  TRACE_POP
}

/*
equation index: 589
type: SIMPLE_ASSIGN
$res_LSJac4_1.$pDERLSJac4.dummyVarLSJac4 = (if rover_8d.z_rl < 1.0 then rover_8d.z_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (2.0 - rover_8d.z_rl - rover_8d.z_rl) else 0.0) - rover_8d.fz_rl.$pDERA.dummyVarA.SeedLSJac4
*/
void RoverExample_Components_Rover_eqFunction_589(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,589};
  modelica_boolean tmp614;
  tmp614 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */),1.0);
  jacobian->resultVars[0] /* $res_LSJac4_1.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_VAR */ = (tmp614?(jacobian->tmpVars[15] /* rover_8d.z_rl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):0.0) - jacobian->seedVars[0] /* rover_8d.fz_rl.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 590
type: SIMPLE_ASSIGN
$res_LSJac4_2.$pDERLSJac4.dummyVarLSJac4 = (if rover_8d.z_fr < 1.0 then rover_8d.z_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (2.0 - rover_8d.z_fr - rover_8d.z_fr) else 0.0) - rover_8d.fz_fr.$pDERA.dummyVarA.SeedLSJac4
*/
void RoverExample_Components_Rover_eqFunction_590(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,590};
  modelica_boolean tmp615;
  tmp615 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */),1.0);
  jacobian->resultVars[1] /* $res_LSJac4_2.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_VAR */ = (tmp615?(jacobian->tmpVars[13] /* rover_8d.z_fr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):0.0) - jacobian->seedVars[1] /* rover_8d.fz_fr.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 591
type: SIMPLE_ASSIGN
$res_LSJac4_3.$pDERLSJac4.dummyVarLSJac4 = (if rover_8d.z_rr < 1.0 then rover_8d.z_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (2.0 - rover_8d.z_rr - rover_8d.z_rr) else 0.0) - rover_8d.fz_rr.$pDERA.dummyVarA.SeedLSJac4
*/
void RoverExample_Components_Rover_eqFunction_591(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,591};
  modelica_boolean tmp616;
  tmp616 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */),1.0);
  jacobian->resultVars[2] /* $res_LSJac4_3.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_VAR */ = (tmp616?(jacobian->tmpVars[11] /* rover_8d.z_rr.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):0.0) - jacobian->seedVars[2] /* rover_8d.fz_rr.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */;
  TRACE_POP
}

/*
equation index: 592
type: SIMPLE_ASSIGN
$res_LSJac4_4.$pDERLSJac4.dummyVarLSJac4 = (if rover_8d.z_fl < 1.0 then rover_8d.z_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 * (2.0 - rover_8d.z_fl - rover_8d.z_fl) else 0.0) - rover_8d.fz_fl.$pDERA.dummyVarA.SeedLSJac4
*/
void RoverExample_Components_Rover_eqFunction_592(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,592};
  modelica_boolean tmp617;
  tmp617 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */),1.0);
  jacobian->resultVars[3] /* $res_LSJac4_4.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_VAR */ = (tmp617?(jacobian->tmpVars[17] /* rover_8d.z_fl.$pDERA.dummyVarA.$pDERLSJac4.dummyVarLSJac4 JACOBIAN_TMP_VAR */) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):0.0) - jacobian->seedVars[3] /* rover_8d.fz_fl.$pDERA.dummyVarA.SeedLSJac4 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac4_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac4;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac4_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac4;
  RoverExample_Components_Rover_eqFunction_571(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_572(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_573(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_574(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_575(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_576(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_577(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_578(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_579(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_580(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_581(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_582(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_583(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_584(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_585(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_586(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_587(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_588(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_589(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_590(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_591(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_592(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 604
type: SIMPLE_ASSIGN
$DER.rover_8d.omega.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5 = (-4.0) * rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 / rover_8d.J
*/
void RoverExample_Components_Rover_eqFunction_604(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,604};
  jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */ = (-4.0) * (DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 SEED_VAR */,(data->simulationInfo->realParameter[67] /* rover_8d.J PARAM */),"rover_8d.J"));
  TRACE_POP
}

/*
equation index: 605
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fl.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5 = rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_605(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,605};
  jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 606
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_fr.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5 = rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_606(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,606};
  jacobian->tmpVars[2] /* der(rover_8d.omega_fr.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 607
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rl.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5 = rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 / rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_607(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,607};
  jacobian->tmpVars[3] /* der(rover_8d.omega_rl.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 SEED_VAR */,(data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */),"rover_8d.I_wheel");
  TRACE_POP
}

/*
equation index: 608
type: SIMPLE_ASSIGN
$DER.rover_8d.omega_rr.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5 = 4.0 * $DER.rover_8d.omega.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5 / rover_8d.gratio - $DER.rover_8d.omega_fl.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5 - $DER.rover_8d.omega_fr.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5 - $DER.rover_8d.omega_rl.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5
*/
void RoverExample_Components_Rover_eqFunction_608(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,608};
  jacobian->tmpVars[4] /* der(rover_8d.omega_rr.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */ = (4.0) * (DIVISION(jacobian->tmpVars[0] /* der(rover_8d.omega.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[103] /* rover_8d.gratio PARAM */),"rover_8d.gratio")) - jacobian->tmpVars[1] /* der(rover_8d.omega_fl.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[2] /* der(rover_8d.omega_fr.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */ - jacobian->tmpVars[3] /* der(rover_8d.omega_rl.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */;
  TRACE_POP
}

/*
equation index: 609
type: SIMPLE_ASSIGN
$res_LSJac5_1.$pDERLSJac5.dummyVarLSJac5 = rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 - $DER.rover_8d.omega_rr.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5 * rover_8d.I_wheel
*/
void RoverExample_Components_Rover_eqFunction_609(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,609};
  jacobian->resultVars[0] /* $res_LSJac5_1.$pDERLSJac5.dummyVarLSJac5 JACOBIAN_VAR */ = jacobian->seedVars[0] /* rover_8d.thr.$pDERA.dummyVarA.SeedLSJac5 SEED_VAR */ - ((jacobian->tmpVars[4] /* der(rover_8d.omega_rr.$pDERA.dummyVarA.$pDERLSJac5.dummyVarLSJac5) JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[64] /* rover_8d.I_wheel PARAM */)));
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_functionJacLSJac5_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac5;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Rover_functionJacLSJac5_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Rover_INDEX_JAC_LSJac5;
  RoverExample_Components_Rover_eqFunction_604(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_605(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_606(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_607(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_608(data, threadData, jacobian, parentJacobian);
  RoverExample_Components_Rover_eqFunction_609(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac1(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac1.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 6, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac3(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac3.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 6, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
int RoverExample_Components_Rover_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int RoverExample_Components_Rover_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacD.bin");
  
  initAnalyticJacobian(jacobian, 2, 19, 220, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(2, 0, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 2+1, pFile, FALSE);
  if (count != 2+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 2+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 0, pFile, FALSE);
  if (count != 0) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 0, count);
  }
  
  /* write color array */
  /* color 1 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 2, 2);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacC.bin");
  
  initAnalyticJacobian(jacobian, 35, 19, 238, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(35, 70, 15);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 35+1, pFile, FALSE);
  if (count != 35+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 35+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 70, pFile, FALSE);
  if (count != 70) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 70, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 35);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1, 35);
  /* color 3 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 1, 35);
  /* color 4 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 4, 1, 35);
  /* color 5 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 5, 1, 35);
  /* color 6 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 6, 1, 35);
  /* color 7 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 7, 1, 35);
  /* color 8 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 8, 1, 35);
  /* color 9 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 9, 1, 35);
  /* color 10 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 10, 1, 35);
  /* color 11 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 11, 1, 35);
  /* color 12 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 12, 1, 35);
  /* color 13 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 13, 1, 35);
  /* color 14 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 14, 1, 35);
  /* color 15 with 21 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 15, 21, 35);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacB.bin");
  
  initAnalyticJacobian(jacobian, 2, 35, 220, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(2, 0, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 2+1, pFile, FALSE);
  if (count != 2+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 2+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 0, pFile, FALSE);
  if (count != 0) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 0, count);
  }
  
  /* write color array */
  /* color 1 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 2, 2);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacA.bin");
  
  initAnalyticJacobian(jacobian, 35, 35, 238, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(35, 179, 18);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 35+1, pFile, FALSE);
  if (count != 35+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 35+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 179, pFile, FALSE);
  if (count != 179) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 179, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 35);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1, 35);
  /* color 3 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 1, 35);
  /* color 4 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 4, 1, 35);
  /* color 5 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 5, 1, 35);
  /* color 6 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 6, 1, 35);
  /* color 7 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 7, 1, 35);
  /* color 8 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 8, 1, 35);
  /* color 9 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 9, 1, 35);
  /* color 10 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 10, 1, 35);
  /* color 11 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 11, 1, 35);
  /* color 12 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 12, 1, 35);
  /* color 13 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 13, 1, 35);
  /* color 14 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 14, 1, 35);
  /* color 15 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 15, 1, 35);
  /* color 16 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 16, 1, 35);
  /* color 17 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 17, 2, 35);
  /* color 18 with 17 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 18, 17, 35);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac10(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac10.bin");
  
  initAnalyticJacobian(jacobian, 4, 4, 22, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(4, 16, 4);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 4+1, pFile, FALSE);
  if (count != 4+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 4+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 16, pFile, FALSE);
  if (count != 16) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 16, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 4);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1, 4);
  /* color 3 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 1, 4);
  /* color 4 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 4, 1, 4);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac11(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac11.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 6, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac8(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac8.bin");
  
  initAnalyticJacobian(jacobian, 4, 4, 22, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(4, 16, 4);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 4+1, pFile, FALSE);
  if (count != 4+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 4+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 16, pFile, FALSE);
  if (count != 16) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 16, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 4);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1, 4);
  /* color 3 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 1, 4);
  /* color 4 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 4, 1, 4);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac9(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac9.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 6, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac6(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac6.bin");
  
  initAnalyticJacobian(jacobian, 4, 4, 22, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(4, 16, 4);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 4+1, pFile, FALSE);
  if (count != 4+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 4+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 16, pFile, FALSE);
  if (count != 16) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 16, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 4);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1, 4);
  /* color 3 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 1, 4);
  /* color 4 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 4, 1, 4);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac7(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac7.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 6, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac4(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac4.bin");
  
  initAnalyticJacobian(jacobian, 4, 4, 22, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(4, 16, 4);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 4+1, pFile, FALSE);
  if (count != 4+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 4+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 16, pFile, FALSE);
  if (count != 16) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 16, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 4);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1, 4);
  /* color 3 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 1, 4);
  /* color 4 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 4, 1, 4);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac5(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Rover_JacLSJac5.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 6, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}



