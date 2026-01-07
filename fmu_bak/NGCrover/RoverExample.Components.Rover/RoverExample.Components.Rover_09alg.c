/* Algebraic */
#include "RoverExample.Components.Rover_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void RoverExample_Components_Rover_eqFunction_208(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_209(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_210(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_211(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_212(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_213(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_216(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_217(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_220(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_221(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_227(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_228(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_231(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_232(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_233(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_234(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_235(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_236(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_237(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_238(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_239(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_240(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_241(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_242(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_255(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_256(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_257(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_258(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_259(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_260(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_261(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_262(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_263(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_264(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_265(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_266(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_267(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_268(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_269(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_272(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_274(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_276(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_277(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_278(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_347(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_349(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_350(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_352(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_377(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_378(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_379(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_380(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_381(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_382(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_388(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_390(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_392(DATA* data, threadData_t *threadData);
extern void RoverExample_Components_Rover_eqFunction_396(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[58])(DATA*, threadData_t*) = {
    RoverExample_Components_Rover_eqFunction_208,
    RoverExample_Components_Rover_eqFunction_209,
    RoverExample_Components_Rover_eqFunction_210,
    RoverExample_Components_Rover_eqFunction_211,
    RoverExample_Components_Rover_eqFunction_212,
    RoverExample_Components_Rover_eqFunction_213,
    RoverExample_Components_Rover_eqFunction_216,
    RoverExample_Components_Rover_eqFunction_217,
    RoverExample_Components_Rover_eqFunction_220,
    RoverExample_Components_Rover_eqFunction_221,
    RoverExample_Components_Rover_eqFunction_227,
    RoverExample_Components_Rover_eqFunction_228,
    RoverExample_Components_Rover_eqFunction_231,
    RoverExample_Components_Rover_eqFunction_232,
    RoverExample_Components_Rover_eqFunction_233,
    RoverExample_Components_Rover_eqFunction_234,
    RoverExample_Components_Rover_eqFunction_235,
    RoverExample_Components_Rover_eqFunction_236,
    RoverExample_Components_Rover_eqFunction_237,
    RoverExample_Components_Rover_eqFunction_238,
    RoverExample_Components_Rover_eqFunction_239,
    RoverExample_Components_Rover_eqFunction_240,
    RoverExample_Components_Rover_eqFunction_241,
    RoverExample_Components_Rover_eqFunction_242,
    RoverExample_Components_Rover_eqFunction_255,
    RoverExample_Components_Rover_eqFunction_256,
    RoverExample_Components_Rover_eqFunction_257,
    RoverExample_Components_Rover_eqFunction_258,
    RoverExample_Components_Rover_eqFunction_259,
    RoverExample_Components_Rover_eqFunction_260,
    RoverExample_Components_Rover_eqFunction_261,
    RoverExample_Components_Rover_eqFunction_262,
    RoverExample_Components_Rover_eqFunction_263,
    RoverExample_Components_Rover_eqFunction_264,
    RoverExample_Components_Rover_eqFunction_265,
    RoverExample_Components_Rover_eqFunction_266,
    RoverExample_Components_Rover_eqFunction_267,
    RoverExample_Components_Rover_eqFunction_268,
    RoverExample_Components_Rover_eqFunction_269,
    RoverExample_Components_Rover_eqFunction_272,
    RoverExample_Components_Rover_eqFunction_274,
    RoverExample_Components_Rover_eqFunction_276,
    RoverExample_Components_Rover_eqFunction_277,
    RoverExample_Components_Rover_eqFunction_278,
    RoverExample_Components_Rover_eqFunction_347,
    RoverExample_Components_Rover_eqFunction_349,
    RoverExample_Components_Rover_eqFunction_350,
    RoverExample_Components_Rover_eqFunction_352,
    RoverExample_Components_Rover_eqFunction_377,
    RoverExample_Components_Rover_eqFunction_378,
    RoverExample_Components_Rover_eqFunction_379,
    RoverExample_Components_Rover_eqFunction_380,
    RoverExample_Components_Rover_eqFunction_381,
    RoverExample_Components_Rover_eqFunction_382,
    RoverExample_Components_Rover_eqFunction_388,
    RoverExample_Components_Rover_eqFunction_390,
    RoverExample_Components_Rover_eqFunction_392,
    RoverExample_Components_Rover_eqFunction_396
  };
  
  static const int eqIndices[58] = {
    208,
    209,
    210,
    211,
    212,
    213,
    216,
    217,
    220,
    221,
    227,
    228,
    231,
    232,
    233,
    234,
    235,
    236,
    237,
    238,
    239,
    240,
    241,
    242,
    255,
    256,
    257,
    258,
    259,
    260,
    261,
    262,
    263,
    264,
    265,
    266,
    267,
    268,
    269,
    272,
    274,
    276,
    277,
    278,
    347,
    349,
    350,
    352,
    377,
    378,
    379,
    380,
    381,
    382,
    388,
    390,
    392,
    396
  };
  
  for (id = 0; id < 58; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}
/* for continuous time variables */
int RoverExample_Components_Rover_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  RoverExample_Components_Rover_function_savePreSynchronous(data, threadData);
  
  functionAlg_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
