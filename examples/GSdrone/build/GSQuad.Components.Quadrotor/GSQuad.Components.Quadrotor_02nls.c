/* Non Linear Systems */
#include "GSQuad.Components.Quadrotor_model.h"
#include "GSQuad.Components.Quadrotor_12jac.h"
#include "simulation/jacobian_util.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

void residualFunc87(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,87};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc87: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 87).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc87 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->simulationInfo->realVarsPre[84] /* quad_low.omega_rotor_cmd[1] DISCRETE */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* body */
  res[0] = omc_GSQuad_Utils_clip(threadData, (data->simulationInfo->realVarsPre[84] /* quad_low.omega_rotor_cmd[1] DISCRETE */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[79]] /* quad_low.omega_rotor_max PARAM */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* quad_low.omega_motor[1] variable */);
  threadData->lastEquationSolved = 86;
  /* restore known outputs */
  threadData->lastEquationSolved = 87;
}
void initializeSparsePatternNLS87(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no sparsity pattern available */
  inSysData->isPatternAvailable = FALSE;
}

void freeSparsePatternNLS87(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* nothing to free */
}
void initializeNonlinearPatternNLS87(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
}

OMC_DISABLE_OPT
void initializeStaticDataNLS87(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for $PRE.quad_low.omega_rotor_cmd[1] */
  sysData->nominal[i] = data->modelData->realVarsData[84].attribute /* quad_low.omega_rotor_cmd[1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[84].attribute /* quad_low.omega_rotor_cmd[1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[84].attribute /* quad_low.omega_rotor_cmd[1] */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS87(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS87(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS87(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS87(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS87(DATA* data, double *array)
{
  array[0] = (data->simulationInfo->realVarsPre[84] /* quad_low.omega_rotor_cmd[1] DISCRETE */);
}


/* inner equations */

void residualFunc91(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,91};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc91: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 91).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc91 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->simulationInfo->realVarsPre[85] /* quad_low.omega_rotor_cmd[2] DISCRETE */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* body */
  res[0] = omc_GSQuad_Utils_clip(threadData, (data->simulationInfo->realVarsPre[85] /* quad_low.omega_rotor_cmd[2] DISCRETE */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[79]] /* quad_low.omega_rotor_max PARAM */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* quad_low.omega_motor[2] variable */);
  threadData->lastEquationSolved = 90;
  /* restore known outputs */
  threadData->lastEquationSolved = 91;
}
void initializeSparsePatternNLS91(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no sparsity pattern available */
  inSysData->isPatternAvailable = FALSE;
}

void freeSparsePatternNLS91(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* nothing to free */
}
void initializeNonlinearPatternNLS91(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
}

OMC_DISABLE_OPT
void initializeStaticDataNLS91(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for $PRE.quad_low.omega_rotor_cmd[2] */
  sysData->nominal[i] = data->modelData->realVarsData[85].attribute /* quad_low.omega_rotor_cmd[2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[85].attribute /* quad_low.omega_rotor_cmd[2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[85].attribute /* quad_low.omega_rotor_cmd[2] */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS91(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS91(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS91(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS91(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS91(DATA* data, double *array)
{
  array[0] = (data->simulationInfo->realVarsPre[85] /* quad_low.omega_rotor_cmd[2] DISCRETE */);
}


/* inner equations */

void residualFunc95(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,95};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc95: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 95).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc95 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->simulationInfo->realVarsPre[86] /* quad_low.omega_rotor_cmd[3] DISCRETE */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* body */
  res[0] = omc_GSQuad_Utils_clip(threadData, (data->simulationInfo->realVarsPre[86] /* quad_low.omega_rotor_cmd[3] DISCRETE */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[79]] /* quad_low.omega_rotor_max PARAM */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* quad_low.omega_motor[3] variable */);
  threadData->lastEquationSolved = 94;
  /* restore known outputs */
  threadData->lastEquationSolved = 95;
}
void initializeSparsePatternNLS95(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no sparsity pattern available */
  inSysData->isPatternAvailable = FALSE;
}

void freeSparsePatternNLS95(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* nothing to free */
}
void initializeNonlinearPatternNLS95(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
}

OMC_DISABLE_OPT
void initializeStaticDataNLS95(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for $PRE.quad_low.omega_rotor_cmd[3] */
  sysData->nominal[i] = data->modelData->realVarsData[86].attribute /* quad_low.omega_rotor_cmd[3] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[86].attribute /* quad_low.omega_rotor_cmd[3] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[86].attribute /* quad_low.omega_rotor_cmd[3] */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS95(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS95(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS95(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS95(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS95(DATA* data, double *array)
{
  array[0] = (data->simulationInfo->realVarsPre[86] /* quad_low.omega_rotor_cmd[3] DISCRETE */);
}


/* inner equations */

void residualFunc99(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,99};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc99: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 99).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc99 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->simulationInfo->realVarsPre[87] /* quad_low.omega_rotor_cmd[4] DISCRETE */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* body */
  res[0] = omc_GSQuad_Utils_clip(threadData, (data->simulationInfo->realVarsPre[87] /* quad_low.omega_rotor_cmd[4] DISCRETE */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[80]] /* quad_low.omega_rotor_min PARAM */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[79]] /* quad_low.omega_rotor_max PARAM */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* quad_low.omega_motor[4] variable */);
  threadData->lastEquationSolved = 98;
  /* restore known outputs */
  threadData->lastEquationSolved = 99;
}
void initializeSparsePatternNLS99(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no sparsity pattern available */
  inSysData->isPatternAvailable = FALSE;
}

void freeSparsePatternNLS99(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* nothing to free */
}
void initializeNonlinearPatternNLS99(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
}

OMC_DISABLE_OPT
void initializeStaticDataNLS99(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for $PRE.quad_low.omega_rotor_cmd[4] */
  sysData->nominal[i] = data->modelData->realVarsData[87].attribute /* quad_low.omega_rotor_cmd[4] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[87].attribute /* quad_low.omega_rotor_cmd[4] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[87].attribute /* quad_low.omega_rotor_cmd[4] */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS99(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS99(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS99(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS99(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS99(DATA* data, double *array)
{
  array[0] = (data->simulationInfo->realVarsPre[87] /* quad_low.omega_rotor_cmd[4] DISCRETE */);
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void GSQuad_Components_Quadrotor_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[3].equationIndex = 99;
  nonLinearSystemData[3].size = 1;
  nonLinearSystemData[3].homotopySupport = 0 /* false */;
  nonLinearSystemData[3].mixedSystem = 0 /* false */;
  nonLinearSystemData[3].residualFunc = residualFunc99;
  nonLinearSystemData[3].strictTearingFunctionCall = NULL;
  nonLinearSystemData[3].analyticalJacobianColumn = NULL;
  nonLinearSystemData[3].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[3].jacobianIndex = -1;
  nonLinearSystemData[3].initializeStaticNLSData = initializeStaticDataNLS99;
  nonLinearSystemData[3].freeStaticNLSData = freeStaticDataNLS99;
  nonLinearSystemData[3].getIterationVars = getIterationVarsNLS99;
  nonLinearSystemData[3].checkConstraints = NULL;
  
  const int tmp_eqn_indices_3[1] = {98};
  nonLinearSystemData[3].eqn_simcode_indices = malloc(1 * sizeof(int));
  memcpy(nonLinearSystemData[3].eqn_simcode_indices, tmp_eqn_indices_3, 1 * sizeof(int));
  nonLinearSystemData[3].torn_plus_residual_size = 1;
  
  
  nonLinearSystemData[2].equationIndex = 95;
  nonLinearSystemData[2].size = 1;
  nonLinearSystemData[2].homotopySupport = 0 /* false */;
  nonLinearSystemData[2].mixedSystem = 0 /* false */;
  nonLinearSystemData[2].residualFunc = residualFunc95;
  nonLinearSystemData[2].strictTearingFunctionCall = NULL;
  nonLinearSystemData[2].analyticalJacobianColumn = NULL;
  nonLinearSystemData[2].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[2].jacobianIndex = -1;
  nonLinearSystemData[2].initializeStaticNLSData = initializeStaticDataNLS95;
  nonLinearSystemData[2].freeStaticNLSData = freeStaticDataNLS95;
  nonLinearSystemData[2].getIterationVars = getIterationVarsNLS95;
  nonLinearSystemData[2].checkConstraints = NULL;
  
  const int tmp_eqn_indices_2[1] = {94};
  nonLinearSystemData[2].eqn_simcode_indices = malloc(1 * sizeof(int));
  memcpy(nonLinearSystemData[2].eqn_simcode_indices, tmp_eqn_indices_2, 1 * sizeof(int));
  nonLinearSystemData[2].torn_plus_residual_size = 1;
  
  
  nonLinearSystemData[1].equationIndex = 91;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0 /* false */;
  nonLinearSystemData[1].mixedSystem = 0 /* false */;
  nonLinearSystemData[1].residualFunc = residualFunc91;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = NULL;
  nonLinearSystemData[1].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[1].jacobianIndex = -1;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS91;
  nonLinearSystemData[1].freeStaticNLSData = freeStaticDataNLS91;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS91;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  const int tmp_eqn_indices_1[1] = {90};
  nonLinearSystemData[1].eqn_simcode_indices = malloc(1 * sizeof(int));
  memcpy(nonLinearSystemData[1].eqn_simcode_indices, tmp_eqn_indices_1, 1 * sizeof(int));
  nonLinearSystemData[1].torn_plus_residual_size = 1;
  
  
  nonLinearSystemData[0].equationIndex = 87;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0 /* false */;
  nonLinearSystemData[0].mixedSystem = 0 /* false */;
  nonLinearSystemData[0].residualFunc = residualFunc87;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = NULL;
  nonLinearSystemData[0].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[0].jacobianIndex = -1;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS87;
  nonLinearSystemData[0].freeStaticNLSData = freeStaticDataNLS87;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS87;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  const int tmp_eqn_indices_0[1] = {86};
  nonLinearSystemData[0].eqn_simcode_indices = malloc(1 * sizeof(int));
  memcpy(nonLinearSystemData[0].eqn_simcode_indices, tmp_eqn_indices_0, 1 * sizeof(int));
  nonLinearSystemData[0].torn_plus_residual_size = 1;
}

#if defined(__cplusplus)
}
#endif
