/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "GSQuad.Components.MissionPlanner_model.h"
#include "simulation/solver/events.h"
#include "util/real_array.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation GSQuad_Components_MissionPlanner_performSimulation
#define prefixedName_updateContinuousSystem GSQuad_Components_MissionPlanner_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation GSQuad_Components_MissionPlanner_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int GSQuad_Components_MissionPlanner_input_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

int GSQuad_Components_MissionPlanner_input_function_init(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

int GSQuad_Components_MissionPlanner_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

int GSQuad_Components_MissionPlanner_inputNames(DATA *data, char ** names){
  
  return 0;
}

int GSQuad_Components_MissionPlanner_data_function(DATA *data, threadData_t *threadData)
{
  return 0;
}

int GSQuad_Components_MissionPlanner_dataReconciliationInputNames(DATA *data, char ** names){
  
  return 0;
}

int GSQuad_Components_MissionPlanner_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  
  return 0;
}

int GSQuad_Components_MissionPlanner_output_function(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* position_setpoint_w[1] variable */);
  data->simulationInfo->outputVars[1] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* position_setpoint_w[2] variable */);
  data->simulationInfo->outputVars[2] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* position_setpoint_w[3] variable */);
  data->simulationInfo->outputVars[3] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* yaw_setpoint_w variable */);
  
  return 0;
}

int GSQuad_Components_MissionPlanner_setc_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

int GSQuad_Components_MissionPlanner_setb_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}


/*
equation index: 14
type: SIMPLE_ASSIGN
yaw_setpoint_w = pre(yaw_setpoint_w_buf)
*/
void GSQuad_Components_MissionPlanner_eqFunction_14(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* yaw_setpoint_w variable */) = (data->simulationInfo->realVarsPre[7] /* yaw_setpoint_w_buf DISCRETE */);
  threadData->lastEquationSolved = 14;
}

/*
equation index: 15
type: SIMPLE_ASSIGN
position_setpoint_w[3] = pre(position_setpoint_w_buf[3])
*/
void GSQuad_Components_MissionPlanner_eqFunction_15(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* position_setpoint_w[3] variable */) = (data->simulationInfo->realVarsPre[6] /* position_setpoint_w_buf[3] DISCRETE */);
  threadData->lastEquationSolved = 15;
}

/*
equation index: 16
type: SIMPLE_ASSIGN
position_setpoint_w[2] = pre(position_setpoint_w_buf[2])
*/
void GSQuad_Components_MissionPlanner_eqFunction_16(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* position_setpoint_w[2] variable */) = (data->simulationInfo->realVarsPre[5] /* position_setpoint_w_buf[2] DISCRETE */);
  threadData->lastEquationSolved = 16;
}

/*
equation index: 17
type: SIMPLE_ASSIGN
position_setpoint_w[1] = pre(position_setpoint_w_buf[1])
*/
void GSQuad_Components_MissionPlanner_eqFunction_17(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* position_setpoint_w[1] variable */) = (data->simulationInfo->realVarsPre[4] /* position_setpoint_w_buf[1] DISCRETE */);
  threadData->lastEquationSolved = 17;
}

/*
equation index: 18
type: ALGORITHM

  yaw_setpoint_w_buf := pre(yaw_setpoint_w_buf);
  position_setpoint_w_buf[3] := pre(position_setpoint_w_buf[3]);
  position_setpoint_w_buf[2] := pre(position_setpoint_w_buf[2]);
  position_setpoint_w_buf[1] := pre(position_setpoint_w_buf[1]);
  $whenCondition1 := pre($whenCondition1);
  $whenCondition1 := sample(1, 0.0, sample_period);
  when $whenCondition1 then
    position_setpoint_w_buf := {0.0, 0.0, 0.0};
    yaw_setpoint_w_buf := 0.01;
  end when;
*/
void GSQuad_Components_MissionPlanner_eqFunction_18(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,18};
  real_array tmp0;
  real_array tmp1;
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* yaw_setpoint_w_buf DISCRETE */) = (data->simulationInfo->realVarsPre[7] /* yaw_setpoint_w_buf DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* position_setpoint_w_buf[3] DISCRETE */) = (data->simulationInfo->realVarsPre[6] /* position_setpoint_w_buf[3] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* position_setpoint_w_buf[2] DISCRETE */) = (data->simulationInfo->realVarsPre[5] /* position_setpoint_w_buf[2] DISCRETE */);

  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* position_setpoint_w_buf[1] DISCRETE */) = (data->simulationInfo->realVarsPre[4] /* position_setpoint_w_buf[1] DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = data->simulationInfo->samples[0];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
    {
      array_alloc_scalar_real_array(&tmp0, 3, (modelica_real)0.0, (modelica_real)0.0, (modelica_real)0.0);
      real_array_create(&tmp1, ((modelica_real*)&((&(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* position_setpoint_w_buf[1] DISCRETE */))[((modelica_integer) 1) - 1])), 1, (_index_t)3);
      real_array_copy_data(tmp0, tmp1);

      (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* yaw_setpoint_w_buf DISCRETE */) = 0.01;
    }
  }
  threadData->lastEquationSolved = 18;
}

OMC_DISABLE_OPT
int GSQuad_Components_MissionPlanner_functionDAE(DATA *data, threadData_t *threadData)
{
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  GSQuad_Components_MissionPlanner_functionLocalKnownVars(data, threadData);
  static void (*const eqFunctions[5])(DATA*, threadData_t*) = {
    GSQuad_Components_MissionPlanner_eqFunction_14,
    GSQuad_Components_MissionPlanner_eqFunction_15,
    GSQuad_Components_MissionPlanner_eqFunction_16,
    GSQuad_Components_MissionPlanner_eqFunction_17,
    GSQuad_Components_MissionPlanner_eqFunction_18
  };
  
  for (int id = 0; id < 5; id++) {
    eqFunctions[id](data, threadData);
  }
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  return 0;
}


int GSQuad_Components_MissionPlanner_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  
  return 0;
}


int GSQuad_Components_MissionPlanner_functionODE(DATA *data, threadData_t *threadData)
{
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  GSQuad_Components_MissionPlanner_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);
extern int _main_OptimizationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);

#include "GSQuad.Components.MissionPlanner_12jac.h"
#include "GSQuad.Components.MissionPlanner_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks GSQuad_Components_MissionPlanner_callback = {
  (int (*)(DATA *, threadData_t *, void *)) GSQuad_Components_MissionPlanner_performSimulation,    /* performSimulation */
  (int (*)(DATA *, threadData_t *, void *)) GSQuad_Components_MissionPlanner_performQSSSimulation,    /* performQSSSimulation */
  GSQuad_Components_MissionPlanner_updateContinuousSystem,    /* updateContinuousSystem */
  GSQuad_Components_MissionPlanner_callExternalObjectDestructors,    /* callExternalObjectDestructors */
  NULL,    /* initialNonLinearSystem */
  NULL,    /* initialLinearSystem */
  NULL,    /* initialMixedSystem */
  #if !defined(OMC_NO_STATESELECTION)
  GSQuad_Components_MissionPlanner_initializeStateSets,
  #else
  NULL,
  #endif    /* initializeStateSets */
  GSQuad_Components_MissionPlanner_initializeDAEmodeData,
  GSQuad_Components_MissionPlanner_functionODE,
  GSQuad_Components_MissionPlanner_functionAlgebraics,
  GSQuad_Components_MissionPlanner_functionDAE,
  GSQuad_Components_MissionPlanner_functionLocalKnownVars,
  GSQuad_Components_MissionPlanner_input_function,
  GSQuad_Components_MissionPlanner_input_function_init,
  GSQuad_Components_MissionPlanner_input_function_updateStartValues,
  GSQuad_Components_MissionPlanner_data_function,
  GSQuad_Components_MissionPlanner_output_function,
  GSQuad_Components_MissionPlanner_setc_function,
  GSQuad_Components_MissionPlanner_setb_function,
  GSQuad_Components_MissionPlanner_function_storeDelayed,
  GSQuad_Components_MissionPlanner_function_storeSpatialDistribution,
  GSQuad_Components_MissionPlanner_function_initSpatialDistribution,
  GSQuad_Components_MissionPlanner_updateBoundVariableAttributes,
  GSQuad_Components_MissionPlanner_functionInitialEquations,
  GLOBAL_EQUIDISTANT_HOMOTOPY,
  NULL,
  GSQuad_Components_MissionPlanner_functionRemovedInitialEquations,
  GSQuad_Components_MissionPlanner_updateBoundParameters,
  GSQuad_Components_MissionPlanner_checkForAsserts,
  GSQuad_Components_MissionPlanner_function_ZeroCrossingsEquations,
  GSQuad_Components_MissionPlanner_function_ZeroCrossings,
  GSQuad_Components_MissionPlanner_function_updateRelations,
  GSQuad_Components_MissionPlanner_zeroCrossingDescription,
  GSQuad_Components_MissionPlanner_relationDescription,
  GSQuad_Components_MissionPlanner_function_initSample,
  GSQuad_Components_MissionPlanner_INDEX_JAC_A,
  GSQuad_Components_MissionPlanner_INDEX_JAC_B,
  GSQuad_Components_MissionPlanner_INDEX_JAC_C,
  GSQuad_Components_MissionPlanner_INDEX_JAC_D,
  GSQuad_Components_MissionPlanner_INDEX_JAC_F,
  GSQuad_Components_MissionPlanner_INDEX_JAC_H,
  GSQuad_Components_MissionPlanner_initialAnalyticJacobianA,
  GSQuad_Components_MissionPlanner_initialAnalyticJacobianB,
  GSQuad_Components_MissionPlanner_initialAnalyticJacobianC,
  GSQuad_Components_MissionPlanner_initialAnalyticJacobianD,
  GSQuad_Components_MissionPlanner_initialAnalyticJacobianF,
  GSQuad_Components_MissionPlanner_initialAnalyticJacobianH,
  GSQuad_Components_MissionPlanner_functionJacA_column,
  GSQuad_Components_MissionPlanner_functionJacB_column,
  GSQuad_Components_MissionPlanner_functionJacC_column,
  GSQuad_Components_MissionPlanner_functionJacD_column,
  GSQuad_Components_MissionPlanner_functionJacF_column,
  GSQuad_Components_MissionPlanner_functionJacH_column,
  GSQuad_Components_MissionPlanner_linear_model_frame,
  GSQuad_Components_MissionPlanner_linear_model_datarecovery_frame,
  GSQuad_Components_MissionPlanner_mayer,
  GSQuad_Components_MissionPlanner_lagrange,
  GSQuad_Components_MissionPlanner_getInputVarIndicesInOptimization,
  GSQuad_Components_MissionPlanner_pickUpBoundsForInputsInOptimization,
  GSQuad_Components_MissionPlanner_setInputData,
  GSQuad_Components_MissionPlanner_getTimeGrid,
  GSQuad_Components_MissionPlanner_symbolicInlineSystem,
  GSQuad_Components_MissionPlanner_function_initSynchronous,
  GSQuad_Components_MissionPlanner_function_updateSynchronous,
  GSQuad_Components_MissionPlanner_function_equationsSynchronous,
  GSQuad_Components_MissionPlanner_inputNames,
  GSQuad_Components_MissionPlanner_dataReconciliationInputNames,
  GSQuad_Components_MissionPlanner_dataReconciliationUnmeasuredVariables,
  NULL,
  NULL,
  NULL,
  NULL,
  -1,
  NULL,
  NULL,
  -1

};

#define _OMC_LIT_RESOURCE_0_name_data "GSQuad"
#define _OMC_LIT_RESOURCE_0_dir_data "/home/mhcho/ws/FIRE_CP_Glimpse/examples/GSdrone/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,6,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,53,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void GSQuad_Components_MissionPlanner_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &GSQuad_Components_MissionPlanner_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "GSQuad.Components.MissionPlanner";
  data->modelData->modelFilePrefix = "GSQuad.Components.MissionPlanner";
  data->modelData->modelFileName = "MFQuadrotor.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/mhcho/ws/FIRE_CP_Glimpse/examples/GSdrone/model";
  data->modelData->modelGUID = "{42292a78-d043-45a7-a880-7fac66bac836}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "GSQuad.Components.MissionPlanner_init.c"
    ;
  static const char contents_info[] =
    #include "GSQuad.Components.MissionPlanner_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "GSQuad.Components.MissionPlanner_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "GSQuad.Components.MissionPlanner_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "GSQuad.Components.MissionPlanner_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStatesArray = 0;
  data->modelData->nDiscreteReal = 4;
  data->modelData->nVariablesRealArray = 8;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 1;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersRealArray = 1;
  data->modelData->nParametersIntegerArray = 0;
  data->modelData->nParametersBooleanArray = 0;
  data->modelData->nParametersStringArray = 0;
  data->modelData->nParametersReal = 1;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nAliasRealArray = 4;
  data->modelData->nAliasIntegerArray = 0;
  data->modelData->nAliasBooleanArray = 0;
  data->modelData->nAliasStringArray = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 4;
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 1;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 19;
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
  
    GSQuad_Components_MissionPlanner_setupDataStruc(&data, threadData);
    res = _main_initRuntimeAndSimulation(argc, newargv, &data, threadData);
    if(res == 0) {
      if (omc_flag[FLAG_MOO_OPTIMIZATION]) {
        res = _main_OptimizationRuntime(argc, newargv, &data, threadData);
      } else {
        res = _main_SimulationRuntime(argc, newargv, &data, threadData);
      }
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


