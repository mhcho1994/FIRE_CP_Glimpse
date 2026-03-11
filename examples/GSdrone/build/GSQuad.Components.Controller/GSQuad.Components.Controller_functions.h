#ifndef GSQuad_Components_Controller__H
#define GSQuad_Components_Controller__H
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
modelica_real omc_GSQuad_Utils_clip(threadData_t *threadData, modelica_real _x, modelica_real _x_min, modelica_real _x_max);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_clip(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x_min, modelica_metatype _x_max);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_clip,2,0) {(void*) boxptr_GSQuad_Utils_clip,0}};
#define boxvar_GSQuad_Utils_clip MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_clip)


DLLDirection
real_array omc_GSQuad_Utils_eul2rot(threadData_t *threadData, real_array _euler);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_eul2rot(threadData_t *threadData, modelica_metatype _euler);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_eul2rot,2,0) {(void*) boxptr_GSQuad_Utils_eul2rot,0}};
#define boxvar_GSQuad_Utils_eul2rot MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_eul2rot)


DLLDirection
real_array omc_GSQuad_Utils_hatmap(threadData_t *threadData, real_array _v);
DLLDirection
modelica_metatype boxptr_GSQuad_Utils_hatmap(threadData_t *threadData, modelica_metatype _v);
static const MMC_DEFSTRUCTLIT(boxvar_lit_GSQuad_Utils_hatmap,2,0) {(void*) boxptr_GSQuad_Utils_hatmap,0}};
#define boxvar_GSQuad_Utils_hatmap MMC_REFSTRUCTLIT(boxvar_lit_GSQuad_Utils_hatmap)
#include "GSQuad.Components.Controller_model.h"


#ifdef __cplusplus
}
#endif
#endif
