#ifndef GSQuad_Components_Quadrotor__H
#define GSQuad_Components_Quadrotor__H
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
real_array omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData_t *threadData, real_array _v_in1, real_array _v_in2, real_array __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, real_array __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2);
DLLDirection
modelica_metatype boxptr__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData_t *threadData, modelica_metatype _v_in1, modelica_metatype _v_in2, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2);
static const MMC_DEFSTRUCTLIT(boxvar_lit__omcQ_24DER_24GSQuad_24PUtils_24Pcross3,2,0) {(void*) boxptr__omcQ_24DER_24GSQuad_24PUtils_24Pcross3,0}};
#define boxvar__omcQ_24DER_24GSQuad_24PUtils_24Pcross3 MMC_REFSTRUCTLIT(boxvar_lit__omcQ_24DER_24GSQuad_24PUtils_24Pcross3)


DLLDirection
real_array omc__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot(threadData_t *threadData, real_array _q, real_array __omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq);
DLLDirection
modelica_metatype boxptr__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot(threadData_t *threadData, modelica_metatype _q, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq);
static const MMC_DEFSTRUCTLIT(boxvar_lit__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot,2,0) {(void*) boxptr__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot,0}};
#define boxvar__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot MMC_REFSTRUCTLIT(boxvar_lit__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot)


DLLDirection
real_array omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData_t *threadData, real_array _q_in1, real_array _q_in2, real_array __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, real_array __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2);
DLLDirection
modelica_metatype boxptr__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData_t *threadData, modelica_metatype _q_in1, modelica_metatype _q_in2, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2);
static const MMC_DEFSTRUCTLIT(boxvar_lit__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod,2,0) {(void*) boxptr__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod,0}};
#define boxvar__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod MMC_REFSTRUCTLIT(boxvar_lit__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod)


DLLDirection
modelica_real omc_GSQuad_Utils_avoidzero(threadData_t *threadData, modelica_real _x);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_avoidzero(threadData_t *threadData, modelica_metatype _x);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_avoidzero,2,0) {(void*) boxptr_GSQuad_Utils_avoidzero,0}};
#define boxvar_GSQuad_Utils_avoidzero MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_avoidzero)


DLLDirection
modelica_real omc_GSQuad_Utils_clip(threadData_t *threadData, modelica_real _x, modelica_real _x_min, modelica_real _x_max);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_clip(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x_min, modelica_metatype _x_max);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_clip,2,0) {(void*) boxptr_GSQuad_Utils_clip,0}};
#define boxvar_GSQuad_Utils_clip MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_clip)


DLLDirection
real_array omc_GSQuad_Utils_cross3(threadData_t *threadData, real_array _v_in1, real_array _v_in2);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_cross3(threadData_t *threadData, modelica_metatype _v_in1, modelica_metatype _v_in2);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_cross3,2,0) {(void*) boxptr_GSQuad_Utils_cross3,0}};
#define boxvar_GSQuad_Utils_cross3 MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_cross3)


DLLDirection
real_array omc_GSQuad_Utils_hatmap(threadData_t *threadData, real_array _v);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_hatmap(threadData_t *threadData, modelica_metatype _v);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_hatmap,2,0) {(void*) boxptr_GSQuad_Utils_hatmap,0}};
#define boxvar_GSQuad_Utils_hatmap MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_hatmap)


DLLDirection
real_array omc_GSQuad_Utils_inv3x3(threadData_t *threadData, real_array _M);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_inv3x3(threadData_t *threadData, modelica_metatype _M);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_inv3x3,2,0) {(void*) boxptr_GSQuad_Utils_inv3x3,0}};
#define boxvar_GSQuad_Utils_inv3x3 MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_inv3x3)


DLLDirection
real_array omc_GSQuad_Utils_quat2eul(threadData_t *threadData, real_array _q);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_quat2eul(threadData_t *threadData, modelica_metatype _q);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_quat2eul,2,0) {(void*) boxptr_GSQuad_Utils_quat2eul,0}};
#define boxvar_GSQuad_Utils_quat2eul MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_quat2eul)


DLLDirection
real_array omc_GSQuad_Utils_quat2rot(threadData_t *threadData, real_array _q);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_quat2rot(threadData_t *threadData, modelica_metatype _q);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_quat2rot,2,0) {(void*) boxptr_GSQuad_Utils_quat2rot,0}};
#define boxvar_GSQuad_Utils_quat2rot MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_quat2rot)


DLLDirection
real_array omc_GSQuad_Utils_quatprod(threadData_t *threadData, real_array _q_in1, real_array _q_in2);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_quatprod(threadData_t *threadData, modelica_metatype _q_in1, modelica_metatype _q_in2);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_quatprod,2,0) {(void*) boxptr_GSQuad_Utils_quatprod,0}};
#define boxvar_GSQuad_Utils_quatprod MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_quatprod)
#include "GSQuad.Components.Quadrotor_model.h"


#ifdef __cplusplus
}
#endif
#endif
