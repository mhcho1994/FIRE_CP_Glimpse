/* Jacobians 6 */
#include "RoverExample.Components.Controller_model.h"
#include "RoverExample.Components.Controller_12jac.h"
#include "simulation/jacobian_util.h"
#include "util/omc_file.h"
int RoverExample_Components_Controller_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int RoverExample_Components_Controller_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 39
type: ALGORITHM

  delta := delta;
  delta.$pDERD.dummyVarD := 0.0;
  v := v;
  v.$pDERD.dummyVarD := 0.0;
  psi_ref := psi_ref;
  psi_ref.$pDERD.dummyVarD := 0.0;
  y_ref := y_ref;
  y_ref.$pDERD.dummyVarD := 0.0;
  x_ref := x_ref;
  x_ref.$pDERD.dummyVarD := 0.0;
  s := s;
  s.$pDERD.dummyVarD := 0.0;
  psi_change := psi_change;
  psi_change.$pDERD.dummyVarD := 0.0;
  d := d;
  d.$pDERD.dummyVarD := 0.0;
  psi_filtered := psi_filtered;
  psi_filtered.$pDERD.dummyVarD := 0.0;
  euler_filtered[3] := euler_filtered[3];
  euler_filtered.$pDERD.dummyVarD[3] := 0.0;
  euler_filtered[2] := euler_filtered[2];
  euler_filtered.$pDERD.dummyVarD[2] := 0.0;
  euler_filtered[1] := euler_filtered[1];
  euler_filtered.$pDERD.dummyVarD[1] := 0.0;
  quaternion_filtered[4] := quaternion_filtered[4];
  quaternion_filtered.$pDERD.dummyVarD[4] := 0.0;
  quaternion_filtered[3] := quaternion_filtered[3];
  quaternion_filtered.$pDERD.dummyVarD[3] := 0.0;
  quaternion_filtered[2] := quaternion_filtered[2];
  quaternion_filtered.$pDERD.dummyVarD[2] := 0.0;
  quaternion_filtered[1] := quaternion_filtered[1];
  quaternion_filtered.$pDERD.dummyVarD[1] := 0.0;
  pwm_steering := pwm_steering;
  pwm_steering.$pDERD.dummyVarD := 0.0;
  pwm_throttle := pwm_throttle;
  pwm_throttle.$pDERD.dummyVarD := 0.0;
  $whenCondition1 := $whenCondition1;
  $whenCondition1.$pDERD.dummyVarD := 0.0;
  $whenCondition1 := sample(1, 0.0, sample_interval);
  $whenCondition1.$pDERD.dummyVarD := 0.0;
  when $whenCondition1 then
    pwm_throttle := 1000 + integer(1000.0 * v / v_max);
    pwm_throttle.$pDERD.dummyVarD := 0.0;
    pwm_steering := 1500 + integer(500.0 * delta / delta_max);
    pwm_steering.$pDERD.dummyVarD := 0.0;
    quaternion_filtered := RoverExample.Components.MadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval);
    quaternion_filtered.$pDERD.dummyVarD := $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0) * ax_acc.SeedD + $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0) * ay_acc.SeedD + $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0) * az_acc.SeedD + $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, {0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0) * p_gyro.SeedD + $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, {0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0) * q_gyro.SeedD + $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, {0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0) * r_gyro.SeedD + $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, {0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0) * mx_mag.SeedD + $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, {0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0) * my_mag.SeedD + $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, {0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0) * mz_mag.SeedD + quaternion_filtered.$pDERD.dummyVarD .* $DER$RoverExample$PComponents$PMadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {1.0, 1.0, 1.0, 1.0}, 0.0, 0.0, 0.0);
    euler_filtered := RoverExample.Utils.quat2eul(quaternion_filtered);
    euler_filtered.$pDERD.dummyVarD := quaternion_filtered.$pDERD.dummyVarD .* $DER$RoverExample$PUtils$Pquat2eul(quaternion_filtered, {1.0, 1.0, 1.0, 1.0});
    psi_filtered := euler_filtered[3];
    psi_filtered.$pDERD.dummyVarD := euler_filtered.$pDERD.dummyVarD[3];
    d := sqrt((x - x_ref) ^ 2.0 + (y - y_ref) ^ 2.0);
    d.$pDERD.dummyVarD := ((x - x_ref) * (x.SeedD - x_ref.$pDERD.dummyVarD) + (y - y_ref) * (y.SeedD - y_ref.$pDERD.dummyVarD)) / sqrt((x - x_ref) ^ 2.0 + (y - y_ref) ^ 2.0);
    psi_change := mod(psi_filtered - psi_ref + 3.14159265, 6.2831853) - 3.14159265;
    psi_change.$pDERD.dummyVarD := psi_filtered.$pDERD.dummyVarD - psi_ref.$pDERD.dummyVarD;
    if s == 0 and turn < 0 then
      s := 1;
      s.$pDERD.dummyVarD := 0;
      x_ref := x;
      x_ref.$pDERD.dummyVarD := x.SeedD;
      y_ref := y;
      y_ref.$pDERD.dummyVarD := y.SeedD;
      psi_ref := psi_filtered;
      psi_ref.$pDERD.dummyVarD := psi_filtered.$pDERD.dummyVarD;
      v := v_fwd;
      v.$pDERD.dummyVarD := 0.0;
      delta := 0.0;
      delta.$pDERD.dummyVarD := 0.0;
    else
      if s == 0 and turn > 0 then
        s := 3;
        s.$pDERD.dummyVarD := 0;
        x_ref := x;
        x_ref.$pDERD.dummyVarD := x.SeedD;
        y_ref := y;
        y_ref.$pDERD.dummyVarD := y.SeedD;
        psi_ref := psi_filtered;
        psi_ref.$pDERD.dummyVarD := psi_filtered.$pDERD.dummyVarD;
        v := v_fwd;
        v.$pDERD.dummyVarD := 0.0;
        delta := 0.0;
        delta.$pDERD.dummyVarD := 0.0;
      else
        if s == 1 and d > 7.0 then
          s := 2;
          s.$pDERD.dummyVarD := 0;
          x_ref := x_ref;
          x_ref.$pDERD.dummyVarD := x_ref.$pDERD.dummyVarD;
          y_ref := y_ref;
          y_ref.$pDERD.dummyVarD := y_ref.$pDERD.dummyVarD;
          psi_ref := psi_ref;
          psi_ref.$pDERD.dummyVarD := psi_ref.$pDERD.dummyVarD;
          v := v_fwd;
          v.$pDERD.dummyVarD := 0.0;
          delta := delta_turn;
          delta.$pDERD.dummyVarD := 0.0;
        else
          if s == 3 and d > 7.0 then
            s := 4;
            s.$pDERD.dummyVarD := 0;
            x_ref := x_ref;
            x_ref.$pDERD.dummyVarD := x_ref.$pDERD.dummyVarD;
            y_ref := y_ref;
            y_ref.$pDERD.dummyVarD := y_ref.$pDERD.dummyVarD;
            psi_ref := psi_ref;
            psi_ref.$pDERD.dummyVarD := psi_ref.$pDERD.dummyVarD;
            v := v_fwd;
            v.$pDERD.dummyVarD := 0.0;
            delta := -delta_turn;
            delta.$pDERD.dummyVarD := -0.0;
          else
            if s == 2 and psi_change > turn_angle then
              s := 5;
              s.$pDERD.dummyVarD := 0;
              x_ref := x;
              x_ref.$pDERD.dummyVarD := x.SeedD;
              y_ref := y;
              y_ref.$pDERD.dummyVarD := y.SeedD;
              psi_ref := psi_filtered;
              psi_ref.$pDERD.dummyVarD := psi_filtered.$pDERD.dummyVarD;
              v := v_fwd;
              v.$pDERD.dummyVarD := 0.0;
              delta := 0.0;
              delta.$pDERD.dummyVarD := 0.0;
            else
              if s == 4 and psi_change < (-turn_angle) then
                s := 5;
                s.$pDERD.dummyVarD := 0;
                x_ref := x;
                x_ref.$pDERD.dummyVarD := x.SeedD;
                y_ref := y;
                y_ref.$pDERD.dummyVarD := y.SeedD;
                psi_ref := psi_filtered;
                psi_ref.$pDERD.dummyVarD := psi_filtered.$pDERD.dummyVarD;
                v := v_fwd;
                v.$pDERD.dummyVarD := 0.0;
                delta := 0.0;
                delta.$pDERD.dummyVarD := 0.0;
              else
                if s == 5 and d > 7.0 then
                  s := 0;
                  s.$pDERD.dummyVarD := 0;
                  x_ref := x_ref;
                  x_ref.$pDERD.dummyVarD := x_ref.$pDERD.dummyVarD;
                  y_ref := y_ref;
                  y_ref.$pDERD.dummyVarD := y_ref.$pDERD.dummyVarD;
                  psi_ref := psi_ref;
                  psi_ref.$pDERD.dummyVarD := psi_ref.$pDERD.dummyVarD;
                  v := 0.0;
                  v.$pDERD.dummyVarD := 0.0;
                  delta := 0.0;
                  delta.$pDERD.dummyVarD := 0.0;
                end if;
              end if;
            end if;
          end if;
        end if;
      end if;
    end if;
  end when;
*/
void RoverExample_Components_Controller_eqFunction_39(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,39};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */);

  jacobian->tmpVars[1] /* delta.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */);

  jacobian->tmpVars[12] /* v.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */);

  jacobian->tmpVars[7] /* psi_ref.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */);

  jacobian->tmpVars[14] /* y_ref.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */);

  jacobian->tmpVars[13] /* x_ref.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */);

  jacobian->tmpVars[15] /* s.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* psi_change DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* psi_change DISCRETE */);

  jacobian->tmpVars[5] /* psi_change.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* d DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* d DISCRETE */);

  jacobian->tmpVars[0] /* d.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */);

  jacobian->tmpVars[6] /* psi_filtered.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* euler_filtered[3] DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* euler_filtered[3] DISCRETE */);

  jacobian->tmpVars[4] /* euler_filtered.$pDERD.dummyVarD[3] JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* euler_filtered[2] DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* euler_filtered[2] DISCRETE */);

  jacobian->tmpVars[3] /* euler_filtered.$pDERD.dummyVarD[2] JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* euler_filtered[1] DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* euler_filtered[1] DISCRETE */);

  jacobian->tmpVars[2] /* euler_filtered.$pDERD.dummyVarD[1] JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* quaternion_filtered[4] DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* quaternion_filtered[4] DISCRETE */);

  jacobian->tmpVars[11] /* quaternion_filtered.$pDERD.dummyVarD[4] JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* quaternion_filtered[3] DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* quaternion_filtered[3] DISCRETE */);

  jacobian->tmpVars[10] /* quaternion_filtered.$pDERD.dummyVarD[3] JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* quaternion_filtered[2] DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* quaternion_filtered[2] DISCRETE */);

  jacobian->tmpVars[9] /* quaternion_filtered.$pDERD.dummyVarD[2] JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* quaternion_filtered[1] DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* quaternion_filtered[1] DISCRETE */);

  jacobian->tmpVars[8] /* quaternion_filtered.$pDERD.dummyVarD[1] JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* pwm_steering DISCRETE */) = (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* pwm_steering DISCRETE */);

  jacobian->resultVars[0] /* pwm_steering.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;

  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* pwm_throttle DISCRETE */) = (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* pwm_throttle DISCRETE */);

  jacobian->resultVars[1] /* pwm_throttle.$pDERD.dummyVarD JACOBIAN_VAR */ = 0.0;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */);

  jacobian->tmpVars[16] /* $whenCondition1.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = data->simulationInfo->samples[0];

  jacobian->tmpVars[16] /* $whenCondition1.$pDERD.dummyVarD JACOBIAN_TMP_VAR */ = 0.0;
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Controller_functionJacD_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Controller_INDEX_JAC_D;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = RoverExample_Components_Controller_INDEX_JAC_D;
  RoverExample_Components_Controller_eqFunction_39(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
int RoverExample_Components_Controller_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int RoverExample_Components_Controller_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int RoverExample_Components_Controller_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int RoverExample_Components_Controller_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
OMC_DISABLE_OPT
int RoverExample_Components_Controller_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "RoverExample.Components.Controller_JacD.bin");
  
  initAnalyticJacobian(jacobian, 15, 2, 19, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(15, 24, 12);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 15+1, pFile, FALSE);
  if (count != 15+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 15+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 24, pFile, FALSE);
  if (count != 24) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 24, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 15);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1, 15);
  /* color 3 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 1, 15);
  /* color 4 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 4, 1, 15);
  /* color 5 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 5, 1, 15);
  /* color 6 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 6, 1, 15);
  /* color 7 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 7, 1, 15);
  /* color 8 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 8, 1, 15);
  /* color 9 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 9, 1, 15);
  /* color 10 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 10, 1, 15);
  /* color 11 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 11, 1, 15);
  /* color 12 with 4 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 12, 4, 15);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
int RoverExample_Components_Controller_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int RoverExample_Components_Controller_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int RoverExample_Components_Controller_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}



