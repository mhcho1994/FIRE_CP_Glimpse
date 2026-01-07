/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "RoverExample.Components.Controller_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation RoverExample_Components_Controller_performSimulation
#define prefixedName_updateContinuousSystem RoverExample_Components_Controller_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation RoverExample_Components_Controller_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int RoverExample_Components_Controller_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* ax_acc variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* ay_acc variable */) = data->simulationInfo->inputVars[1];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* az_acc variable */) = data->simulationInfo->inputVars[2];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* mx_mag variable */) = data->simulationInfo->inputVars[3];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* my_mag variable */) = data->simulationInfo->inputVars[4];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* mz_mag variable */) = data->simulationInfo->inputVars[5];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* p_gyro variable */) = data->simulationInfo->inputVars[6];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* phi_gyro variable */) = data->simulationInfo->inputVars[7];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* psi_gyro variable */) = data->simulationInfo->inputVars[8];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* q_gyro variable */) = data->simulationInfo->inputVars[9];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* r_gyro variable */) = data->simulationInfo->inputVars[10];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* theta_gyro variable */) = data->simulationInfo->inputVars[11];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* x variable */) = data->simulationInfo->inputVars[12];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* y variable */) = data->simulationInfo->inputVars[13];
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[0].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[1].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->realVarsData[2].attribute.start;
  data->simulationInfo->inputVars[3] = data->modelData->realVarsData[3].attribute.start;
  data->simulationInfo->inputVars[4] = data->modelData->realVarsData[4].attribute.start;
  data->simulationInfo->inputVars[5] = data->modelData->realVarsData[5].attribute.start;
  data->simulationInfo->inputVars[6] = data->modelData->realVarsData[6].attribute.start;
  data->simulationInfo->inputVars[7] = data->modelData->realVarsData[7].attribute.start;
  data->simulationInfo->inputVars[8] = data->modelData->realVarsData[8].attribute.start;
  data->simulationInfo->inputVars[9] = data->modelData->realVarsData[9].attribute.start;
  data->simulationInfo->inputVars[10] = data->modelData->realVarsData[10].attribute.start;
  data->simulationInfo->inputVars[11] = data->modelData->realVarsData[11].attribute.start;
  data->simulationInfo->inputVars[12] = data->modelData->realVarsData[12].attribute.start;
  data->simulationInfo->inputVars[13] = data->modelData->realVarsData[13].attribute.start;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[0].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[1].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->realVarsData[2].attribute.start = data->simulationInfo->inputVars[2];
  data->modelData->realVarsData[3].attribute.start = data->simulationInfo->inputVars[3];
  data->modelData->realVarsData[4].attribute.start = data->simulationInfo->inputVars[4];
  data->modelData->realVarsData[5].attribute.start = data->simulationInfo->inputVars[5];
  data->modelData->realVarsData[6].attribute.start = data->simulationInfo->inputVars[6];
  data->modelData->realVarsData[7].attribute.start = data->simulationInfo->inputVars[7];
  data->modelData->realVarsData[8].attribute.start = data->simulationInfo->inputVars[8];
  data->modelData->realVarsData[9].attribute.start = data->simulationInfo->inputVars[9];
  data->modelData->realVarsData[10].attribute.start = data->simulationInfo->inputVars[10];
  data->modelData->realVarsData[11].attribute.start = data->simulationInfo->inputVars[11];
  data->modelData->realVarsData[12].attribute.start = data->simulationInfo->inputVars[12];
  data->modelData->realVarsData[13].attribute.start = data->simulationInfo->inputVars[13];
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_inputNames(DATA *data, char ** names){
  TRACE_PUSH

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
  names[12] = (char *) data->modelData->integerVarsData[3].info.name;
  names[13] = (char *) data->modelData->realVarsData[12].info.name;
  names[14] = (char *) data->modelData->realVarsData[13].info.name;
  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Controller_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 38
type: ALGORITHM

  delta := pre(delta);
  v := pre(v);
  psi_ref := pre(psi_ref);
  y_ref := pre(y_ref);
  x_ref := pre(x_ref);
  s := pre(s);
  psi_change := pre(psi_change);
  d := pre(d);
  psi_filtered := pre(psi_filtered);
  euler_filtered[3] := pre(euler_filtered[3]);
  euler_filtered[2] := pre(euler_filtered[2]);
  euler_filtered[1] := pre(euler_filtered[1]);
  quaternion_filtered[4] := pre(quaternion_filtered[4]);
  quaternion_filtered[3] := pre(quaternion_filtered[3]);
  quaternion_filtered[2] := pre(quaternion_filtered[2]);
  quaternion_filtered[1] := pre(quaternion_filtered[1]);
  pwm_steering := pre(pwm_steering);
  pwm_throttle := pre(pwm_throttle);
  $whenCondition1 := pre($whenCondition1);
  $whenCondition1 := sample(1, 0.0, sample_interval);
  when $whenCondition1 then
    pwm_throttle := 1000 + integer(1000.0 * v / v_max);
    pwm_steering := 1500 + integer(500.0 * delta / delta_max);
    quaternion_filtered := RoverExample.Components.MadgwickFusionStep(ax_acc, ay_acc, az_acc, p_gyro, q_gyro, r_gyro, mx_mag, my_mag, mz_mag, quaternion_filtered, alpha, beta, sample_interval);
    euler_filtered := RoverExample.Utils.quat2eul(quaternion_filtered);
    psi_filtered := euler_filtered[3];
    d := sqrt((x - x_ref) ^ 2.0 + (y - y_ref) ^ 2.0);
    psi_change := mod(psi_filtered - psi_ref + 3.14159265, 6.2831853) - 3.14159265;
    if s == 0 and turn < 0 then
      s := 1;
      x_ref := x;
      y_ref := y;
      psi_ref := psi_filtered;
      v := v_fwd;
      delta := 0.0;
    elseif s == 0 and turn > 0 then
      s := 3;
      x_ref := x;
      y_ref := y;
      psi_ref := psi_filtered;
      v := v_fwd;
      delta := 0.0;
    elseif s == 1 and d > 7.0 then
      s := 2;
      x_ref := x_ref;
      y_ref := y_ref;
      psi_ref := psi_ref;
      v := v_fwd;
      delta := delta_turn;
    elseif s == 3 and d > 7.0 then
      s := 4;
      x_ref := x_ref;
      y_ref := y_ref;
      psi_ref := psi_ref;
      v := v_fwd;
      delta := -delta_turn;
    elseif s == 2 and psi_change > turn_angle then
      s := 5;
      x_ref := x;
      y_ref := y;
      psi_ref := psi_filtered;
      v := v_fwd;
      delta := 0.0;
    elseif s == 4 and psi_change < (-turn_angle) then
      s := 5;
      x_ref := x;
      y_ref := y;
      psi_ref := psi_filtered;
      v := v_fwd;
      delta := 0.0;
    elseif s == 5 and d > 7.0 then
      s := 0;
      x_ref := x_ref;
      y_ref := y_ref;
      psi_ref := psi_ref;
      v := 0.0;
      delta := 0.0;
    end if;
  end when;
*/
void RoverExample_Components_Controller_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  real_array tmp0;
  real_array tmp1;
  real_array tmp2;
  real_array tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = (data->simulationInfo->realVarsPre[15] /* delta DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = (data->simulationInfo->realVarsPre[26] /* v DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->simulationInfo->realVarsPre[21] /* psi_ref DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->simulationInfo->realVarsPre[28] /* y_ref DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->simulationInfo->realVarsPre[27] /* x_ref DISCRETE */);

  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = (data->simulationInfo->integerVarsPre[2] /* s DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* psi_change DISCRETE */) = (data->simulationInfo->realVarsPre[19] /* psi_change DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* d DISCRETE */) = (data->simulationInfo->realVarsPre[14] /* d DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */) = (data->simulationInfo->realVarsPre[20] /* psi_filtered DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* euler_filtered[3] DISCRETE */) = (data->simulationInfo->realVarsPre[18] /* euler_filtered[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* euler_filtered[2] DISCRETE */) = (data->simulationInfo->realVarsPre[17] /* euler_filtered[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* euler_filtered[1] DISCRETE */) = (data->simulationInfo->realVarsPre[16] /* euler_filtered[1] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* quaternion_filtered[4] DISCRETE */) = (data->simulationInfo->realVarsPre[25] /* quaternion_filtered[4] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* quaternion_filtered[3] DISCRETE */) = (data->simulationInfo->realVarsPre[24] /* quaternion_filtered[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* quaternion_filtered[2] DISCRETE */) = (data->simulationInfo->realVarsPre[23] /* quaternion_filtered[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* quaternion_filtered[1] DISCRETE */) = (data->simulationInfo->realVarsPre[22] /* quaternion_filtered[1] DISCRETE */);

  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* pwm_steering DISCRETE */) = (data->simulationInfo->integerVarsPre[0] /* pwm_steering DISCRETE */);

  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* pwm_throttle DISCRETE */) = (data->simulationInfo->integerVarsPre[1] /* pwm_throttle DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = data->simulationInfo->samples[0];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
    {
      (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* pwm_throttle DISCRETE */) = ((modelica_integer) 1000) + ((modelica_integer)floor(DIVISION_SIM((1000.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */)),(data->simulationInfo->realParameter[7] /* v_max PARAM */),"v_max",equationIndexes)));

      (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* pwm_steering DISCRETE */) = ((modelica_integer) 1500) + ((modelica_integer)floor(DIVISION_SIM((500.0) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */)),(data->simulationInfo->realParameter[2] /* delta_max PARAM */),"delta_max",equationIndexes)));

      real_array_create(&tmp0, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* quaternion_filtered[1] DISCRETE */)[((modelica_integer) 1) - 1])), 1, (_index_t)4);
      real_array_create(&tmp1, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* quaternion_filtered[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)4);
      real_array_copy_data(omc_RoverExample_Components_MadgwickFusionStep(threadData, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* ax_acc variable */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* ay_acc variable */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* az_acc variable */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* p_gyro variable */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* q_gyro variable */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* r_gyro variable */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* mx_mag variable */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* my_mag variable */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* mz_mag variable */), tmp0, (data->simulationInfo->realParameter[0] /* alpha PARAM */), (data->simulationInfo->realParameter[1] /* beta PARAM */), (data->simulationInfo->realParameter[4] /* sample_interval PARAM */)), tmp1);

      real_array_create(&tmp2, ((modelica_real*)&((&data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* quaternion_filtered[1] DISCRETE */)[((modelica_integer) 1) - 1])), 1, (_index_t)4);
      real_array_create(&tmp3, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* euler_filtered[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(omc_RoverExample_Utils_quat2eul(threadData, tmp2), tmp3);

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* euler_filtered[3] DISCRETE */);

      tmp4 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* x variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */);
      tmp5 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* y variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */);
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
          throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((x - x_ref) ^ 2.0 + (y - y_ref) ^ 2.0) was %g should be >= 0", tmp6);
        }
      }
      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* d DISCRETE */) = sqrt(tmp6);

      tmp7 = 6.2831853;
      if (tmp7 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(psi_filtered - psi_ref + 3.14159265, 6.2831853)");}
      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* psi_change DISCRETE */) = modelica_real_mod((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) + 3.14159265, tmp7) - 3.14159265;

      tmp8 = Less((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[3]] /* turn variable */),((modelica_integer) 0));
      if((((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) == ((modelica_integer) 0)) && tmp8))
      {
        (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = ((modelica_integer) 1);

        (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* x variable */);

        (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* y variable */);

        (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */);

        (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = (data->simulationInfo->realParameter[6] /* v_fwd PARAM */);

        (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = 0.0;
      }
      else
      {
        tmp9 = Greater((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[3]] /* turn variable */),((modelica_integer) 0));
        if((((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) == ((modelica_integer) 0)) && tmp9))
        {
          (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = ((modelica_integer) 3);

          (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* x variable */);

          (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* y variable */);

          (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */);

          (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = (data->simulationInfo->realParameter[6] /* v_fwd PARAM */);

          (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = 0.0;
        }
        else
        {
          tmp10 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* d DISCRETE */),7.0);
          if((((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) == ((modelica_integer) 1)) && tmp10))
          {
            (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = ((modelica_integer) 2);

            (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */);

            (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */);

            (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */);

            (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = (data->simulationInfo->realParameter[6] /* v_fwd PARAM */);

            (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = (data->simulationInfo->realParameter[3] /* delta_turn PARAM */);
          }
          else
          {
            tmp11 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* d DISCRETE */),7.0);
            if((((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) == ((modelica_integer) 3)) && tmp11))
            {
              (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = ((modelica_integer) 4);

              (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */);

              (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */);

              (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */);

              (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = (data->simulationInfo->realParameter[6] /* v_fwd PARAM */);

              (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = (-(data->simulationInfo->realParameter[3] /* delta_turn PARAM */));
            }
            else
            {
              tmp12 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* psi_change DISCRETE */),(data->simulationInfo->realParameter[5] /* turn_angle PARAM */));
              if((((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) == ((modelica_integer) 2)) && tmp12))
              {
                (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = ((modelica_integer) 5);

                (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* x variable */);

                (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* y variable */);

                (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */);

                (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = (data->simulationInfo->realParameter[6] /* v_fwd PARAM */);

                (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = 0.0;
              }
              else
              {
                tmp13 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* psi_change DISCRETE */),(-(data->simulationInfo->realParameter[5] /* turn_angle PARAM */)));
                if((((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) == ((modelica_integer) 4)) && tmp13))
                {
                  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = ((modelica_integer) 5);

                  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* x variable */);

                  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* y variable */);

                  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* psi_filtered DISCRETE */);

                  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = (data->simulationInfo->realParameter[6] /* v_fwd PARAM */);

                  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = 0.0;
                }
                else
                {
                  tmp14 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* d DISCRETE */),7.0);
                  if((((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) == ((modelica_integer) 5)) && tmp14))
                  {
                    (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[2]] /* s DISCRETE */) = ((modelica_integer) 0);

                    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* x_ref DISCRETE */);

                    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* y_ref DISCRETE */);

                    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* psi_ref DISCRETE */);

                    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* v DISCRETE */) = 0.0;

                    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* delta DISCRETE */) = 0.0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Controller_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  RoverExample_Components_Controller_functionLocalKnownVars(data, threadData);
  RoverExample_Components_Controller_eqFunction_38(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int RoverExample_Components_Controller_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int RoverExample_Components_Controller_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  RoverExample_Components_Controller_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void RoverExample_Components_Controller_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  
  /* derivativeVars */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ax_acc variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ay_acc variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* az_acc variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* mx_mag variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* my_mag variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* mz_mag variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* p_gyro variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* phi_gyro variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* psi_gyro variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* q_gyro variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* r_gyro variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* theta_gyro variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* x variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* y variable */
  
  /* discreteAlgVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* d DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* delta DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* euler_filtered[1] DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* euler_filtered[2] DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* euler_filtered[3] DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* psi_change DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* psi_filtered DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* psi_ref DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* quaternion_filtered[1] DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* quaternion_filtered[2] DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* quaternion_filtered[3] DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* quaternion_filtered[4] DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* x_ref DISCRETE */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* y_ref DISCRETE */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* pwm_steering DISCRETE */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* pwm_throttle DISCRETE */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* s DISCRETE */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* turn variable */
  
  /* boolAlgVars */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition1 DISCRETE */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "RoverExample.Components.Controller_12jac.h"
#include "RoverExample.Components.Controller_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks RoverExample_Components_Controller_callback = {
   (int (*)(DATA *, threadData_t *, void *)) RoverExample_Components_Controller_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) RoverExample_Components_Controller_performQSSSimulation,    /* performQSSSimulation */
   RoverExample_Components_Controller_updateContinuousSystem,    /* updateContinuousSystem */
   RoverExample_Components_Controller_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   RoverExample_Components_Controller_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   RoverExample_Components_Controller_initializeDAEmodeData,
   RoverExample_Components_Controller_computeVarIndices,
   RoverExample_Components_Controller_functionODE,
   RoverExample_Components_Controller_functionAlgebraics,
   RoverExample_Components_Controller_functionDAE,
   RoverExample_Components_Controller_functionLocalKnownVars,
   RoverExample_Components_Controller_input_function,
   RoverExample_Components_Controller_input_function_init,
   RoverExample_Components_Controller_input_function_updateStartValues,
   RoverExample_Components_Controller_data_function,
   RoverExample_Components_Controller_output_function,
   RoverExample_Components_Controller_setc_function,
   RoverExample_Components_Controller_setb_function,
   RoverExample_Components_Controller_function_storeDelayed,
   RoverExample_Components_Controller_function_storeSpatialDistribution,
   RoverExample_Components_Controller_function_initSpatialDistribution,
   RoverExample_Components_Controller_updateBoundVariableAttributes,
   RoverExample_Components_Controller_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   RoverExample_Components_Controller_functionRemovedInitialEquations,
   RoverExample_Components_Controller_updateBoundParameters,
   RoverExample_Components_Controller_checkForAsserts,
   RoverExample_Components_Controller_function_ZeroCrossingsEquations,
   RoverExample_Components_Controller_function_ZeroCrossings,
   RoverExample_Components_Controller_function_updateRelations,
   RoverExample_Components_Controller_zeroCrossingDescription,
   RoverExample_Components_Controller_relationDescription,
   RoverExample_Components_Controller_function_initSample,
   RoverExample_Components_Controller_INDEX_JAC_A,
   RoverExample_Components_Controller_INDEX_JAC_B,
   RoverExample_Components_Controller_INDEX_JAC_C,
   RoverExample_Components_Controller_INDEX_JAC_D,
   RoverExample_Components_Controller_INDEX_JAC_F,
   RoverExample_Components_Controller_INDEX_JAC_H,
   RoverExample_Components_Controller_initialAnalyticJacobianA,
   RoverExample_Components_Controller_initialAnalyticJacobianB,
   RoverExample_Components_Controller_initialAnalyticJacobianC,
   RoverExample_Components_Controller_initialAnalyticJacobianD,
   RoverExample_Components_Controller_initialAnalyticJacobianF,
   RoverExample_Components_Controller_initialAnalyticJacobianH,
   RoverExample_Components_Controller_functionJacA_column,
   RoverExample_Components_Controller_functionJacB_column,
   RoverExample_Components_Controller_functionJacC_column,
   RoverExample_Components_Controller_functionJacD_column,
   RoverExample_Components_Controller_functionJacF_column,
   RoverExample_Components_Controller_functionJacH_column,
   RoverExample_Components_Controller_linear_model_frame,
   RoverExample_Components_Controller_linear_model_datarecovery_frame,
   RoverExample_Components_Controller_mayer,
   RoverExample_Components_Controller_lagrange,
   RoverExample_Components_Controller_pickUpBoundsForInputsInOptimization,
   RoverExample_Components_Controller_setInputData,
   RoverExample_Components_Controller_getTimeGrid,
   RoverExample_Components_Controller_symbolicInlineSystem,
   RoverExample_Components_Controller_function_initSynchronous,
   RoverExample_Components_Controller_function_updateSynchronous,
   RoverExample_Components_Controller_function_equationsSynchronous,
   RoverExample_Components_Controller_inputNames,
   RoverExample_Components_Controller_dataReconciliationInputNames,
   RoverExample_Components_Controller_dataReconciliationUnmeasuredVariables,
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
void RoverExample_Components_Controller_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &RoverExample_Components_Controller_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "RoverExample.Components.Controller";
  data->modelData->modelFilePrefix = "RoverExample.Components.Controller";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/mnt/d/Dropbox/05.Workspace/C02.FIREFLY/06.Rover/251015.LoFi_update/NGCrover/model";
  data->modelData->modelGUID = "{ed085fef-f30a-4124-8dea-b27fee34e238}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "RoverExample.Components.Controller_init.c"
    ;
  static const char contents_info[] =
    #include "RoverExample.Components.Controller_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "RoverExample.Components.Controller_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "RoverExample.Components.Controller_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "RoverExample.Components.Controller_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 0;
  data->modelData->nVariablesRealArray = 29;
  data->modelData->nDiscreteReal = 15;
  data->modelData->nVariablesIntegerArray = 4;
  data->modelData->nVariablesBooleanArray = 1;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 8;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 15;
  data->modelData->nOutputVars = 2;
  data->modelData->nAliasReal = 14;
  data->modelData->nAliasInteger = 3;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 1;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 8;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 40;
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
  
    RoverExample_Components_Controller_setupDataStruc(&data, threadData);
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


