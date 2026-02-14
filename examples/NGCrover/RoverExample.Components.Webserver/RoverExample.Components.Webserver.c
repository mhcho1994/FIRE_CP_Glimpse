/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "RoverExample.Components.Webserver_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation RoverExample_Components_Webserver_performSimulation
#define prefixedName_updateContinuousSystem RoverExample_Components_Webserver_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation RoverExample_Components_Webserver_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int RoverExample_Components_Webserver_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Webserver_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Webserver_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Webserver_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Webserver_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int RoverExample_Components_Webserver_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Webserver_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Webserver_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Webserver_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RoverExample_Components_Webserver_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 3
type: ALGORITHM

  turn := pre(turn);
  timer_count := pre(timer_count);
  $whenCondition1 := pre($whenCondition1);
  $whenCondition1 := sample(1, 0.0, sample_interval);
  when $whenCondition1 then
    timer_count := timer_count + 1;
  end when;
  if timer_count <= turn_interval_count and timer_count >= 0 then
    turn := 0;
  elseif timer_count <= 2 * turn_interval_count and timer_count > turn_interval_count then
    turn := 1;
  elseif timer_count <= 3 * turn_interval_count and timer_count > 2 * turn_interval_count then
    turn := 1;
  else
    turn := 0;
  end if;
  if timer_count >= repeat_interval_count then
    timer_count := 0;
  end if;
*/
void RoverExample_Components_Webserver_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = (data->simulationInfo->integerVarsPre[1] /* turn DISCRETE */);

  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */) = (data->simulationInfo->integerVarsPre[0] /* timer_count DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */);

  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = data->simulationInfo->samples[0];

  if(data->simulationInfo->discreteCall == 1)
  {
    if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
    {
      (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */) = (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */) + ((modelica_integer) 1);
    }
  }

  tmp0 = LessEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */));
  tmp1 = GreaterEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),((modelica_integer) 0));
  if((tmp0 && tmp1))
  {
    (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = ((modelica_integer) 0);
  }
  else
  {
    tmp2 = LessEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(((modelica_integer) 2)) * ((data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */)));
    tmp3 = Greater((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */));
    if((tmp2 && tmp3))
    {
      (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = ((modelica_integer) 1);
    }
    else
    {
      tmp4 = LessEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(((modelica_integer) 3)) * ((data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */)));
      tmp5 = Greater((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(((modelica_integer) 2)) * ((data->simulationInfo->integerParameter[1] /* turn_interval_count PARAM */)));
      if((tmp4 && tmp5))
      {
        (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = ((modelica_integer) 1);
      }
      else
      {
        (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[1]] /* turn DISCRETE */) = ((modelica_integer) 0);
      }
    }
  }

  tmp6 = GreaterEq((data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */),(data->simulationInfo->integerParameter[0] /* repeat_interval_count PARAM */));
  if(tmp6)
  {
    (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* timer_count DISCRETE */) = ((modelica_integer) 0);
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int RoverExample_Components_Webserver_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  RoverExample_Components_Webserver_functionLocalKnownVars(data, threadData);
  RoverExample_Components_Webserver_eqFunction_3(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int RoverExample_Components_Webserver_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int RoverExample_Components_Webserver_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  RoverExample_Components_Webserver_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void RoverExample_Components_Webserver_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  
  /* discreteAlgVars */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* timer_count DISCRETE */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* turn DISCRETE */
  
  /* boolAlgVars */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition1 DISCRETE */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "RoverExample.Components.Webserver_12jac.h"
#include "RoverExample.Components.Webserver_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks RoverExample_Components_Webserver_callback = {
   (int (*)(DATA *, threadData_t *, void *)) RoverExample_Components_Webserver_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) RoverExample_Components_Webserver_performQSSSimulation,    /* performQSSSimulation */
   RoverExample_Components_Webserver_updateContinuousSystem,    /* updateContinuousSystem */
   RoverExample_Components_Webserver_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   RoverExample_Components_Webserver_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   RoverExample_Components_Webserver_initializeDAEmodeData,
   RoverExample_Components_Webserver_computeVarIndices,
   RoverExample_Components_Webserver_functionODE,
   RoverExample_Components_Webserver_functionAlgebraics,
   RoverExample_Components_Webserver_functionDAE,
   RoverExample_Components_Webserver_functionLocalKnownVars,
   RoverExample_Components_Webserver_input_function,
   RoverExample_Components_Webserver_input_function_init,
   RoverExample_Components_Webserver_input_function_updateStartValues,
   RoverExample_Components_Webserver_data_function,
   RoverExample_Components_Webserver_output_function,
   RoverExample_Components_Webserver_setc_function,
   RoverExample_Components_Webserver_setb_function,
   RoverExample_Components_Webserver_function_storeDelayed,
   RoverExample_Components_Webserver_function_storeSpatialDistribution,
   RoverExample_Components_Webserver_function_initSpatialDistribution,
   RoverExample_Components_Webserver_updateBoundVariableAttributes,
   RoverExample_Components_Webserver_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   RoverExample_Components_Webserver_functionRemovedInitialEquations,
   RoverExample_Components_Webserver_updateBoundParameters,
   RoverExample_Components_Webserver_checkForAsserts,
   RoverExample_Components_Webserver_function_ZeroCrossingsEquations,
   RoverExample_Components_Webserver_function_ZeroCrossings,
   RoverExample_Components_Webserver_function_updateRelations,
   RoverExample_Components_Webserver_zeroCrossingDescription,
   RoverExample_Components_Webserver_relationDescription,
   RoverExample_Components_Webserver_function_initSample,
   RoverExample_Components_Webserver_INDEX_JAC_A,
   RoverExample_Components_Webserver_INDEX_JAC_B,
   RoverExample_Components_Webserver_INDEX_JAC_C,
   RoverExample_Components_Webserver_INDEX_JAC_D,
   RoverExample_Components_Webserver_INDEX_JAC_F,
   RoverExample_Components_Webserver_INDEX_JAC_H,
   RoverExample_Components_Webserver_initialAnalyticJacobianA,
   RoverExample_Components_Webserver_initialAnalyticJacobianB,
   RoverExample_Components_Webserver_initialAnalyticJacobianC,
   RoverExample_Components_Webserver_initialAnalyticJacobianD,
   RoverExample_Components_Webserver_initialAnalyticJacobianF,
   RoverExample_Components_Webserver_initialAnalyticJacobianH,
   RoverExample_Components_Webserver_functionJacA_column,
   RoverExample_Components_Webserver_functionJacB_column,
   RoverExample_Components_Webserver_functionJacC_column,
   RoverExample_Components_Webserver_functionJacD_column,
   RoverExample_Components_Webserver_functionJacF_column,
   RoverExample_Components_Webserver_functionJacH_column,
   RoverExample_Components_Webserver_linear_model_frame,
   RoverExample_Components_Webserver_linear_model_datarecovery_frame,
   RoverExample_Components_Webserver_mayer,
   RoverExample_Components_Webserver_lagrange,
   RoverExample_Components_Webserver_pickUpBoundsForInputsInOptimization,
   RoverExample_Components_Webserver_setInputData,
   RoverExample_Components_Webserver_getTimeGrid,
   RoverExample_Components_Webserver_symbolicInlineSystem,
   RoverExample_Components_Webserver_function_initSynchronous,
   RoverExample_Components_Webserver_function_updateSynchronous,
   RoverExample_Components_Webserver_function_equationsSynchronous,
   RoverExample_Components_Webserver_inputNames,
   RoverExample_Components_Webserver_dataReconciliationInputNames,
   RoverExample_Components_Webserver_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "RoverExample"
#define _OMC_LIT_RESOURCE_0_dir_data "/mnt/d/Dropbox/05.Workspace/C02.FIREFLY/06.Rover/251015.LoFi_update/NGCrover/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,12,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,82,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void RoverExample_Components_Webserver_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &RoverExample_Components_Webserver_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "RoverExample.Components.Webserver";
  data->modelData->modelFilePrefix = "RoverExample.Components.Webserver";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/mnt/d/Dropbox/05.Workspace/C02.FIREFLY/06.Rover/251015.LoFi_update/NGCrover/model";
  data->modelData->modelGUID = "{d337dc9f-5513-4365-a5af-065632d60877}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "RoverExample.Components.Webserver_init.c"
    ;
  static const char contents_info[] =
    #include "RoverExample.Components.Webserver_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "RoverExample.Components.Webserver_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "RoverExample.Components.Webserver_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "RoverExample.Components.Webserver_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 0;
  data->modelData->nVariablesRealArray = 0;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 2;
  data->modelData->nVariablesBooleanArray = 1;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 3;
  data->modelData->nParametersInteger = 2;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 1;
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 1;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 1;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 6;
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
  
    RoverExample_Components_Webserver_setupDataStruc(&data, threadData);
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


