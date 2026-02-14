#ifndef RoverExample_Components_Rover__H
#define RoverExample_Components_Rover__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif


DLLDirection
real_array omc__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData_t *threadData, real_array _euler, real_array __omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler);
DLLDirection
modelica_metatype boxptr__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData_t *threadData, modelica_metatype _euler, modelica_metatype __omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler);
static const MMC_DEFSTRUCTLIT(boxvar_lit__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot,2,0) {(void*) boxptr__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot,0}};
#define boxvar__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot MMC_REFSTRUCTLIT(boxvar_lit__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot)


DLLDirection
modelica_real omc_RoverExample_Utils_avoidzero(threadData_t *threadData, modelica_real _x);
DLLDirection
modelica_metatype boxptr_RoverExample_Utils_avoidzero(threadData_t *threadData, modelica_metatype _x);
static const MMC_DEFSTRUCTLIT(boxvar_lit_RoverExample_Utils_avoidzero,2,0) {(void*) boxptr_RoverExample_Utils_avoidzero,0}};
#define boxvar_RoverExample_Utils_avoidzero MMC_REFSTRUCTLIT(boxvar_lit_RoverExample_Utils_avoidzero)


DLLDirection
modelica_real omc_RoverExample_Utils_clip(threadData_t *threadData, modelica_real _x, modelica_real _x_min, modelica_real _x_max);
DLLDirection
modelica_metatype boxptr_RoverExample_Utils_clip(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x_min, modelica_metatype _x_max);
static const MMC_DEFSTRUCTLIT(boxvar_lit_RoverExample_Utils_clip,2,0) {(void*) boxptr_RoverExample_Utils_clip,0}};
#define boxvar_RoverExample_Utils_clip MMC_REFSTRUCTLIT(boxvar_lit_RoverExample_Utils_clip)


DLLDirection
real_array omc_RoverExample_Utils_cross3(threadData_t *threadData, real_array _v_in1, real_array _v_in2);
DLLDirection
modelica_metatype boxptr_RoverExample_Utils_cross3(threadData_t *threadData, modelica_metatype _v_in1, modelica_metatype _v_in2);
static const MMC_DEFSTRUCTLIT(boxvar_lit_RoverExample_Utils_cross3,2,0) {(void*) boxptr_RoverExample_Utils_cross3,0}};
#define boxvar_RoverExample_Utils_cross3 MMC_REFSTRUCTLIT(boxvar_lit_RoverExample_Utils_cross3)


DLLDirection
modelica_real omc_RoverExample_Utils_dot3(threadData_t *threadData, real_array _v_in1, real_array _v_in2);
DLLDirection
modelica_metatype boxptr_RoverExample_Utils_dot3(threadData_t *threadData, modelica_metatype _v_in1, modelica_metatype _v_in2);
static const MMC_DEFSTRUCTLIT(boxvar_lit_RoverExample_Utils_dot3,2,0) {(void*) boxptr_RoverExample_Utils_dot3,0}};
#define boxvar_RoverExample_Utils_dot3 MMC_REFSTRUCTLIT(boxvar_lit_RoverExample_Utils_dot3)


DLLDirection
real_array omc_RoverExample_Utils_eul2rot(threadData_t *threadData, real_array _euler);
DLLDirection
modelica_metatype boxptr_RoverExample_Utils_eul2rot(threadData_t *threadData, modelica_metatype _euler);
static const MMC_DEFSTRUCTLIT(boxvar_lit_RoverExample_Utils_eul2rot,2,0) {(void*) boxptr_RoverExample_Utils_eul2rot,0}};
#define boxvar_RoverExample_Utils_eul2rot MMC_REFSTRUCTLIT(boxvar_lit_RoverExample_Utils_eul2rot)
#include "RoverExample.Components.Rover_model.h"


#ifdef __cplusplus
}
#endif
#endif

