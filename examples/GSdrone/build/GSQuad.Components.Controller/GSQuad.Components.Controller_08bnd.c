/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "GSQuad.Components.Controller_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int GSQuad_Components_Controller_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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

void GSQuad_Components_Controller_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 201
type: SIMPLE_ASSIGN
euler_pid.J[3,3] = euler_pid.Izz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_201(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,201};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[14]] /* euler_pid.J[3,3] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* euler_pid.Izz PARAM */);
  threadData->lastEquationSolved = 201;
}

/*
equation index: 202
type: SIMPLE_ASSIGN
euler_pid.J[3,2] = euler_pid.Iyz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_202(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,202};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[13]] /* euler_pid.J[3,2] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* euler_pid.Iyz PARAM */);
  threadData->lastEquationSolved = 202;
}

/*
equation index: 203
type: SIMPLE_ASSIGN
euler_pid.J[3,1] = euler_pid.Ixz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_203(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,203};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[12]] /* euler_pid.J[3,1] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[2]] /* euler_pid.Ixz PARAM */);
  threadData->lastEquationSolved = 203;
}

/*
equation index: 204
type: SIMPLE_ASSIGN
euler_pid.J[2,3] = euler_pid.Iyz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_204(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,204};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* euler_pid.J[2,3] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* euler_pid.Iyz PARAM */);
  threadData->lastEquationSolved = 204;
}

/*
equation index: 205
type: SIMPLE_ASSIGN
euler_pid.J[2,2] = euler_pid.Iyy
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_205(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,205};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* euler_pid.J[2,2] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[3]] /* euler_pid.Iyy PARAM */);
  threadData->lastEquationSolved = 205;
}

/*
equation index: 206
type: SIMPLE_ASSIGN
euler_pid.J[2,1] = euler_pid.Ixy
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_206(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,206};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* euler_pid.J[2,1] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* euler_pid.Ixy PARAM */);
  threadData->lastEquationSolved = 206;
}

/*
equation index: 207
type: SIMPLE_ASSIGN
euler_pid.J[1,3] = euler_pid.Ixz
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_207(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,207};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[8]] /* euler_pid.J[1,3] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[2]] /* euler_pid.Ixz PARAM */);
  threadData->lastEquationSolved = 207;
}

/*
equation index: 208
type: SIMPLE_ASSIGN
euler_pid.J[1,2] = euler_pid.Ixy
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_208(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,208};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[7]] /* euler_pid.J[1,2] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* euler_pid.Ixy PARAM */);
  threadData->lastEquationSolved = 208;
}

/*
equation index: 209
type: SIMPLE_ASSIGN
euler_pid.J[1,1] = euler_pid.Ixx
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_209(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,209};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[6]] /* euler_pid.J[1,1] PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[0]] /* euler_pid.Ixx PARAM */);
  threadData->lastEquationSolved = 209;
}

/*
equation index: 210
type: SIMPLE_ASSIGN
euler_pid.update_interval = update_period
*/
OMC_DISABLE_OPT
static void GSQuad_Components_Controller_eqFunction_210(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,210};
  (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[59]] /* euler_pid.update_interval PARAM */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[62]] /* update_period PARAM */);
  threadData->lastEquationSolved = 210;
}
OMC_DISABLE_OPT
void GSQuad_Components_Controller_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[10])(DATA*, threadData_t*) = {
    GSQuad_Components_Controller_eqFunction_201,
    GSQuad_Components_Controller_eqFunction_202,
    GSQuad_Components_Controller_eqFunction_203,
    GSQuad_Components_Controller_eqFunction_204,
    GSQuad_Components_Controller_eqFunction_205,
    GSQuad_Components_Controller_eqFunction_206,
    GSQuad_Components_Controller_eqFunction_207,
    GSQuad_Components_Controller_eqFunction_208,
    GSQuad_Components_Controller_eqFunction_209,
    GSQuad_Components_Controller_eqFunction_210
  };
  
  for (int id = 0; id < 10; id++) {
    eqFunctions[id](data, threadData);
  }
}
OMC_DISABLE_OPT
int GSQuad_Components_Controller_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  GSQuad_Components_Controller_updateBoundParameters_0(data, threadData);
  return 0;
}

#if defined(__cplusplus)
}
#endif
