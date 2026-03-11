/* Jacobians 6 */
#include "GSQuad.Components.Controller_model.h"
#include "GSQuad.Components.Controller_12jac.h"
#include "simulation/jacobian_util.h"
#include "util/omc_file.h"
int GSQuad_Components_Controller_functionJacH_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}
int GSQuad_Components_Controller_functionJacF_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 211
type: SIMPLE_ASSIGN
pwm_rotor_cmd.$pDERD.dummyVarD[4] = 0.0
*/
void GSQuad_Components_Controller_eqFunction_211(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,211};
  jacobian->resultVars[3] /* pwm_rotor_cmd.$pDERD.dummyVarD[4] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 211;
}

/*
equation index: 212
type: SIMPLE_ASSIGN
pwm_rotor_cmd.$pDERD.dummyVarD[3] = 0.0
*/
void GSQuad_Components_Controller_eqFunction_212(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,212};
  jacobian->resultVars[2] /* pwm_rotor_cmd.$pDERD.dummyVarD[3] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 212;
}

/*
equation index: 213
type: SIMPLE_ASSIGN
pwm_rotor_cmd.$pDERD.dummyVarD[2] = 0.0
*/
void GSQuad_Components_Controller_eqFunction_213(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,213};
  jacobian->resultVars[1] /* pwm_rotor_cmd.$pDERD.dummyVarD[2] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 213;
}

/*
equation index: 214
type: SIMPLE_ASSIGN
pwm_rotor_cmd.$pDERD.dummyVarD[1] = 0.0
*/
void GSQuad_Components_Controller_eqFunction_214(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,214};
  jacobian->resultVars[0] /* pwm_rotor_cmd.$pDERD.dummyVarD[1] JACOBIAN_VAR */ = 0.0;
  threadData->lastEquationSolved = 214;
}

OMC_DISABLE_OPT
int GSQuad_Components_Controller_functionJacD_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Controller_INDEX_JAC_D;
  
  
  return 0;
}

int GSQuad_Components_Controller_functionJacD_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = GSQuad_Components_Controller_INDEX_JAC_D;
  
  static void (*const eqFunctions[4])(DATA*, threadData_t*, JACOBIAN*, JACOBIAN*) = {
    GSQuad_Components_Controller_eqFunction_211,
    GSQuad_Components_Controller_eqFunction_212,
    GSQuad_Components_Controller_eqFunction_213,
    GSQuad_Components_Controller_eqFunction_214
  };
  
  for (int id = 0; id < 4; id++) {
    eqFunctions[id](data, threadData, jacobian, parentJacobian);
  }
  
  return 0;
}
int GSQuad_Components_Controller_functionJacC_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}
int GSQuad_Components_Controller_functionJacB_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}
int GSQuad_Components_Controller_functionJacA_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}

int GSQuad_Components_Controller_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int GSQuad_Components_Controller_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
OMC_DISABLE_OPT
int GSQuad_Components_Controller_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "GSQuad.Components.Controller_JacD.bin");
  
  initJacobian(jacobian, 27, 4, 100, GSQuad_Components_Controller_functionJacD_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(27, 0, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 27+1, pFile, FALSE);
  if (count != 27+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 27+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 0, pFile, FALSE);
  if (count != 0) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 0, count);
  }
  
  /* write color array */
  /* color 1 with 27 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 27, 27);
  
  omc_fclose(pFile);
  
  return 0;
}
int GSQuad_Components_Controller_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int GSQuad_Components_Controller_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int GSQuad_Components_Controller_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}


