#include "omc_simulation_settings.h"
#include "GSQuad.Components.Quadrotor_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "GSQuad.Components.Quadrotor_includes.h"


DLLDirection
real_array omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData_t *threadData, real_array _v_in1, real_array _v_in2, real_array __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, real_array __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2)
{
  real_array __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout;
  real_array _v_out;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout), 1, (_index_t)3); // __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout has no default value.
  alloc_real_array(&(_v_out), 1, (_index_t)3); // _v_out has no default value.
  real_array_get(_v_out, 1, ((modelica_integer) 1)) = (real_array_get(_v_in1, 1, ((modelica_integer) 2))) * (real_array_get(_v_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_v_in1, 1, ((modelica_integer) 3))) * (real_array_get(_v_in2, 1, ((modelica_integer) 2))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout, 1, ((modelica_integer) 1)) = (real_array_get(_v_in1, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_v_in2, 1, ((modelica_integer) 3))) + ((-real_array_get(_v_in1, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2, 1, ((modelica_integer) 2))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_v_in2, 1, ((modelica_integer) 2))));

  real_array_get(_v_out, 1, ((modelica_integer) 2)) = (-((real_array_get(_v_in1, 1, ((modelica_integer) 1))) * (real_array_get(_v_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_v_in1, 1, ((modelica_integer) 3))) * (real_array_get(_v_in2, 1, ((modelica_integer) 1))))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout, 1, ((modelica_integer) 2)) = (real_array_get(_v_in1, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_v_in2, 1, ((modelica_integer) 1))) + ((-real_array_get(_v_in1, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2, 1, ((modelica_integer) 3))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_v_in2, 1, ((modelica_integer) 3))));

  real_array_get(_v_out, 1, ((modelica_integer) 3)) = (real_array_get(_v_in1, 1, ((modelica_integer) 1))) * (real_array_get(_v_in2, 1, ((modelica_integer) 2))) - ((real_array_get(_v_in1, 1, ((modelica_integer) 2))) * (real_array_get(_v_in2, 1, ((modelica_integer) 1))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout, 1, ((modelica_integer) 3)) = (real_array_get(_v_in1, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_v_in2, 1, ((modelica_integer) 2))) + ((-real_array_get(_v_in1, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2, 1, ((modelica_integer) 1))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_v_in2, 1, ((modelica_integer) 1))));
  _return: OMC_LABEL_UNUSED
  return __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout;
}
modelica_metatype boxptr__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData_t *threadData, modelica_metatype _v_in1, modelica_metatype _v_in2, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2)
{
  real_array __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout;
  modelica_metatype out__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout;
  __omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout = omc__omcQ_24DER_24GSQuad_24PUtils_24Pcross3(threadData, *((base_array_t*)_v_in1), *((base_array_t*)_v_in2), *((base_array_t*)__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin1), *((base_array_t*)__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fin2));
  out__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout = mmc_mk_modelica_array(__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout);
  return out__omcQ_24GSQuad_24PUtils_24Pcross3_24funDERv_5Fout;
}

DLLDirection
real_array omc__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot(threadData_t *threadData, real_array _q, real_array __omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq)
{
  real_array __omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR;
  real_array _R;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR), 2, (_index_t)3, (_index_t)3); // __omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR has no default value.
  alloc_real_array(&(_R), 2, (_index_t)3, (_index_t)3); // _R has no default value.
  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 1)) = (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 1))) + (real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 2))) - ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 3)))) - ((real_array_get(_q, 1, ((modelica_integer) 4))) * (real_array_get(_q, 1, ((modelica_integer) 4))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR, 2, ((modelica_integer) 1), ((modelica_integer) 1)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 1))) + (real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 2))) + ((-real_array_get(_q, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 3))) - ((real_array_get(_q, 1, ((modelica_integer) 4))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 4)))));

  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 2)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 3))) - ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 4)))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR, 2, ((modelica_integer) 1), ((modelica_integer) 2)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + ((-real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 4))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 4)))));

  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 3)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 3))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR, 2, ((modelica_integer) 1), ((modelica_integer) 3)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 3))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 1)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 4))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR, 2, ((modelica_integer) 2), ((modelica_integer) 1)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 4))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 2)) = (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 1))) + (real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 3))) - ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 2)))) - ((real_array_get(_q, 1, ((modelica_integer) 4))) * (real_array_get(_q, 1, ((modelica_integer) 4))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR, 2, ((modelica_integer) 2), ((modelica_integer) 2)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 1))) + (real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 3))) + ((-real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 2))) - ((real_array_get(_q, 1, ((modelica_integer) 4))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 4)))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 3)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 2)))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR, 2, ((modelica_integer) 2), ((modelica_integer) 3)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + ((-real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 2))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 2)))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 1)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 3)))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR, 2, ((modelica_integer) 3), ((modelica_integer) 1)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + ((-real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 3))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 3)))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 2)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 2))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR, 2, ((modelica_integer) 3), ((modelica_integer) 2)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 2))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 3)) = (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 1))) + (real_array_get(_q, 1, ((modelica_integer) 4))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 2)))) - ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 3))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR, 2, ((modelica_integer) 3), ((modelica_integer) 3)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 1))) + (real_array_get(_q, 1, ((modelica_integer) 4))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 4))) + ((-real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 2))) - ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq, 1, ((modelica_integer) 3)))));
  _return: OMC_LABEL_UNUSED
  return __omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR;
}
modelica_metatype boxptr__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot(threadData_t *threadData, modelica_metatype _q, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq)
{
  real_array __omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR;
  modelica_metatype out__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR;
  __omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR = omc__omcQ_24DER_24GSQuad_24PUtils_24Pquat2rot(threadData, *((base_array_t*)_q), *((base_array_t*)__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERq));
  out__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR = mmc_mk_modelica_array(__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR);
  return out__omcQ_24GSQuad_24PUtils_24Pquat2rot_24funDERR;
}

DLLDirection
real_array omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData_t *threadData, real_array _q_in1, real_array _q_in2, real_array __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, real_array __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2)
{
  real_array __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout;
  real_array _q_out;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout), 1, (_index_t)4); // __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout has no default value.
  alloc_real_array(&(_q_out), 1, (_index_t)4); // _q_out has no default value.
  real_array_get(_q_out, 1, ((modelica_integer) 1)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout, 1, ((modelica_integer) 1)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + ((-real_array_get(_q_in1, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 4))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4)))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 3)))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 2))));

  real_array_get(_q_out, 1, ((modelica_integer) 2)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout, 1, ((modelica_integer) 2)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) + ((-real_array_get(_q_in1, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 3))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))));

  real_array_get(_q_out, 1, ((modelica_integer) 3)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4)))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout, 1, ((modelica_integer) 3)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 4))));

  real_array_get(_q_out, 1, ((modelica_integer) 4)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1)));

  real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout, 1, ((modelica_integer) 4)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) - ((real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 2))));
  _return: OMC_LABEL_UNUSED
  return __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout;
}
modelica_metatype boxptr__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData_t *threadData, modelica_metatype _q_in1, modelica_metatype _q_in2, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1, modelica_metatype __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2)
{
  real_array __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout;
  modelica_metatype out__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout;
  __omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout = omc__omcQ_24DER_24GSQuad_24PUtils_24Pquatprod(threadData, *((base_array_t*)_q_in1), *((base_array_t*)_q_in2), *((base_array_t*)__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin1), *((base_array_t*)__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fin2));
  out__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout = mmc_mk_modelica_array(__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout);
  return out__omcQ_24GSQuad_24PUtils_24Pquatprod_24funDERq_5Fout;
}

DLLDirection
modelica_real omc_GSQuad_Utils_avoidzero(threadData_t *threadData, modelica_real _x)
{
  modelica_real _y;
  _tailrecursive: OMC_LABEL_UNUSED
  // _y has no default value.
  if((fabs(_x) < 1e-15))
  {
    _y = (1e-15) * (((modelica_real)sign(_x + 1e-15)));
  }
  else
  {
    _y = _x;
  }
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_GSQuad_Utils_avoidzero(threadData_t *threadData, modelica_metatype _x)
{
  modelica_real tmp1;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_x);
  _y = omc_GSQuad_Utils_avoidzero(threadData, tmp1);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

DLLDirection
modelica_real omc_GSQuad_Utils_clip(threadData_t *threadData, modelica_real _x, modelica_real _x_min, modelica_real _x_max)
{
  modelica_real _y;
  _tailrecursive: OMC_LABEL_UNUSED
  // _y has no default value.
  _y = ((_x < _x_min)?_x_min:((_x > _x_max)?_x_max:_x));
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_GSQuad_Utils_clip(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x_min, modelica_metatype _x_max)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_x);
  tmp2 = mmc_unbox_real(_x_min);
  tmp3 = mmc_unbox_real(_x_max);
  _y = omc_GSQuad_Utils_clip(threadData, tmp1, tmp2, tmp3);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

DLLDirection
real_array omc_GSQuad_Utils_cross3(threadData_t *threadData, real_array _v_in1, real_array _v_in2)
{
  real_array _v_out;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_v_out), 1, (_index_t)3); // _v_out has no default value.
  real_array_get(_v_out, 1, ((modelica_integer) 1)) = (real_array_get(_v_in1, 1, ((modelica_integer) 2))) * (real_array_get(_v_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_v_in1, 1, ((modelica_integer) 3))) * (real_array_get(_v_in2, 1, ((modelica_integer) 2))));

  real_array_get(_v_out, 1, ((modelica_integer) 2)) = (-((real_array_get(_v_in1, 1, ((modelica_integer) 1))) * (real_array_get(_v_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_v_in1, 1, ((modelica_integer) 3))) * (real_array_get(_v_in2, 1, ((modelica_integer) 1))))));

  real_array_get(_v_out, 1, ((modelica_integer) 3)) = (real_array_get(_v_in1, 1, ((modelica_integer) 1))) * (real_array_get(_v_in2, 1, ((modelica_integer) 2))) - ((real_array_get(_v_in1, 1, ((modelica_integer) 2))) * (real_array_get(_v_in2, 1, ((modelica_integer) 1))));
  _return: OMC_LABEL_UNUSED
  return _v_out;
}
modelica_metatype boxptr_GSQuad_Utils_cross3(threadData_t *threadData, modelica_metatype _v_in1, modelica_metatype _v_in2)
{
  real_array _v_out;
  modelica_metatype out_v_out;
  _v_out = omc_GSQuad_Utils_cross3(threadData, *((base_array_t*)_v_in1), *((base_array_t*)_v_in2));
  out_v_out = mmc_mk_modelica_array(_v_out);
  return out_v_out;
}

DLLDirection
real_array omc_GSQuad_Utils_hatmap(threadData_t *threadData, real_array _v)
{
  real_array _V;
  real_array tmp1;
  real_array tmp2;
  real_array tmp3;
  real_array tmp4;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_V), 2, (_index_t)3, (_index_t)3); // _V has no default value.
  array_alloc_scalar_real_array(&tmp2, 3, (modelica_real)0.0, (modelica_real)(-real_array_get(_v, 1, ((modelica_integer) 3))), (modelica_real)real_array_get(_v, 1, ((modelica_integer) 2)));
  array_alloc_scalar_real_array(&tmp3, 3, (modelica_real)real_array_get(_v, 1, ((modelica_integer) 3)), (modelica_real)0.0, (modelica_real)(-real_array_get(_v, 1, ((modelica_integer) 1))));
  array_alloc_scalar_real_array(&tmp4, 3, (modelica_real)(-real_array_get(_v, 1, ((modelica_integer) 2))), (modelica_real)real_array_get(_v, 1, ((modelica_integer) 1)), (modelica_real)0.0);
  array_alloc_real_array(&tmp1, 3, tmp2, tmp3, tmp4);
  real_array_copy_data(tmp1, _V);
  _return: OMC_LABEL_UNUSED
  return _V;
}
modelica_metatype boxptr_GSQuad_Utils_hatmap(threadData_t *threadData, modelica_metatype _v)
{
  real_array _V;
  modelica_metatype out_V;
  _V = omc_GSQuad_Utils_hatmap(threadData, *((base_array_t*)_v));
  out_V = mmc_mk_modelica_array(_V);
  return out_V;
}

DLLDirection
real_array omc_GSQuad_Utils_inv3x3(threadData_t *threadData, real_array _M)
{
  real_array _invM;
  modelica_real _det;
  modelica_real _eps;
  static int tmp1 = 0;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_invM), 2, (_index_t)3, (_index_t)3); // _invM has no default value.
  // _det has no default value.
  _eps = 1e-12;
  _det = (real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 3))) - ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 2))))) - ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 3))) - ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 1)))))) + (real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 2))) - ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 1)))));

  {
    if(!(fabs(_det) > 1e-12))
    {
      {
        FILE_INFO info = {"/home/mhcho/ws/FIRE_CP_Glimpse/examples/GSdrone/model/MFQuadrotor.mo",958,7,959,77,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT0));
      }
    }
  }

  tmp2 = _det;
  if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(M[2,2] * M[3,3] - M[2,3] * M[3,2]) / det");}
  real_array_get(_invM, 2, ((modelica_integer) 1), ((modelica_integer) 1)) = ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 3))) - ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 2))))) / tmp2;

  tmp3 = _det;
  if (tmp3 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(M[1,2] * M[3,3] - M[1,3] * M[3,2]) / det");}
  real_array_get(_invM, 2, ((modelica_integer) 1), ((modelica_integer) 2)) = (-(((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 3))) - ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 2))))) / tmp3));

  tmp4 = _det;
  if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(M[1,2] * M[2,3] - M[1,3] * M[2,2]) / det");}
  real_array_get(_invM, 2, ((modelica_integer) 1), ((modelica_integer) 3)) = ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 3))) - ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 2))))) / tmp4;

  tmp5 = _det;
  if (tmp5 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(M[2,1] * M[3,3] - M[2,3] * M[3,1]) / det");}
  real_array_get(_invM, 2, ((modelica_integer) 2), ((modelica_integer) 1)) = (-(((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 3))) - ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 1))))) / tmp5));

  tmp6 = _det;
  if (tmp6 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(M[1,1] * M[3,3] - M[1,3] * M[3,1]) / det");}
  real_array_get(_invM, 2, ((modelica_integer) 2), ((modelica_integer) 2)) = ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 3))) - ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 1))))) / tmp6;

  tmp7 = _det;
  if (tmp7 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(M[1,1] * M[2,3] - M[1,3] * M[2,1]) / det");}
  real_array_get(_invM, 2, ((modelica_integer) 2), ((modelica_integer) 3)) = (-(((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 3))) - ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 1))))) / tmp7));

  tmp8 = _det;
  if (tmp8 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(M[2,1] * M[3,2] - M[2,2] * M[3,1]) / det");}
  real_array_get(_invM, 2, ((modelica_integer) 3), ((modelica_integer) 1)) = ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 2))) - ((real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 1))))) / tmp8;

  tmp9 = _det;
  if (tmp9 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(M[1,1] * M[3,2] - M[1,2] * M[3,1]) / det");}
  real_array_get(_invM, 2, ((modelica_integer) 3), ((modelica_integer) 2)) = (-(((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 2))) - ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_M, 2, ((modelica_integer) 3), ((modelica_integer) 1))))) / tmp9));

  tmp10 = _det;
  if (tmp10 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(M[1,1] * M[2,2] - M[1,2] * M[2,1]) / det");}
  real_array_get(_invM, 2, ((modelica_integer) 3), ((modelica_integer) 3)) = ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 2))) - ((real_array_get(_M, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_M, 2, ((modelica_integer) 2), ((modelica_integer) 1))))) / tmp10;
  _return: OMC_LABEL_UNUSED
  return _invM;
}
modelica_metatype boxptr_GSQuad_Utils_inv3x3(threadData_t *threadData, modelica_metatype _M)
{
  real_array _invM;
  modelica_metatype out_invM;
  _invM = omc_GSQuad_Utils_inv3x3(threadData, *((base_array_t*)_M));
  out_invM = mmc_mk_modelica_array(_invM);
  return out_invM;
}

DLLDirection
real_array omc_GSQuad_Utils_quat2eul(threadData_t *threadData, real_array _q)
{
  real_array _eul;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_eul), 1, (_index_t)3); // _eul has no default value.
  tmp1 = real_array_get(_q, 1, ((modelica_integer) 1));
  tmp2 = real_array_get(_q, 1, ((modelica_integer) 4));
  tmp3 = (2.0) * ((tmp1 * tmp1)) + (2.0) * ((tmp2 * tmp2)) - 1.0;
  if (tmp3 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(2.0 * q[3] * q[4] + 2.0 * q[1] * q[2]) / (2.0 * q[1] ^ 2.0 + 2.0 * q[4] ^ 2.0 - 1.0)");}
  real_array_get(_eul, 1, ((modelica_integer) 1)) = atan((((2.0) * (real_array_get(_q, 1, ((modelica_integer) 3)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 2)))) / tmp3);

  tmp4 = (-(((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - (((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 3))))));
  if(!(tmp4 >= -1.0 && tmp4 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of asin(-(2.0 * q[2] * q[4] - 2.0 * q[1] * q[3])) outside the domain -1.0 <= %g <= 1.0", tmp4);
  }
  real_array_get(_eul, 1, ((modelica_integer) 2)) = asin(tmp4);

  tmp5 = real_array_get(_q, 1, ((modelica_integer) 1));
  tmp6 = real_array_get(_q, 1, ((modelica_integer) 2));
  tmp7 = (2.0) * ((tmp5 * tmp5)) + (2.0) * ((tmp6 * tmp6)) - 1.0;
  if (tmp7 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(2.0 * q[2] * q[3] + 2.0 * q[1] * q[4]) / (2.0 * q[1] ^ 2.0 + 2.0 * q[2] ^ 2.0 - 1.0)");}
  real_array_get(_eul, 1, ((modelica_integer) 3)) = atan((((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 4)))) / tmp7);
  _return: OMC_LABEL_UNUSED
  return _eul;
}
modelica_metatype boxptr_GSQuad_Utils_quat2eul(threadData_t *threadData, modelica_metatype _q)
{
  real_array _eul;
  modelica_metatype out_eul;
  _eul = omc_GSQuad_Utils_quat2eul(threadData, *((base_array_t*)_q));
  out_eul = mmc_mk_modelica_array(_eul);
  return out_eul;
}

DLLDirection
real_array omc_GSQuad_Utils_quat2rot(threadData_t *threadData, real_array _q)
{
  real_array _R;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_R), 2, (_index_t)3, (_index_t)3); // _R has no default value.
  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 1)) = (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 1))) + (real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 2))) - ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 3)))) - ((real_array_get(_q, 1, ((modelica_integer) 4))) * (real_array_get(_q, 1, ((modelica_integer) 4))));

  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 2)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 3))) - ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 4)))));

  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 3)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 3))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 1)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 4))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 2)) = (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 1))) + (real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 3))) - ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 2)))) - ((real_array_get(_q, 1, ((modelica_integer) 4))) * (real_array_get(_q, 1, ((modelica_integer) 4))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 3)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 2)))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 1)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 3)))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 2)) = (2.0) * ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 2))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 3)) = (real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 1))) + (real_array_get(_q, 1, ((modelica_integer) 4))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 2)))) - ((real_array_get(_q, 1, ((modelica_integer) 3))) * (real_array_get(_q, 1, ((modelica_integer) 3))));
  _return: OMC_LABEL_UNUSED
  return _R;
}
modelica_metatype boxptr_GSQuad_Utils_quat2rot(threadData_t *threadData, modelica_metatype _q)
{
  real_array _R;
  modelica_metatype out_R;
  _R = omc_GSQuad_Utils_quat2rot(threadData, *((base_array_t*)_q));
  out_R = mmc_mk_modelica_array(_R);
  return out_R;
}

DLLDirection
real_array omc_GSQuad_Utils_quatprod(threadData_t *threadData, real_array _q_in1, real_array _q_in2)
{
  real_array _q_out;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_q_out), 1, (_index_t)4); // _q_out has no default value.
  real_array_get(_q_out, 1, ((modelica_integer) 1)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))));

  real_array_get(_q_out, 1, ((modelica_integer) 2)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))));

  real_array_get(_q_out, 1, ((modelica_integer) 3)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4)))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)));

  real_array_get(_q_out, 1, ((modelica_integer) 4)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1)));
  _return: OMC_LABEL_UNUSED
  return _q_out;
}
modelica_metatype boxptr_GSQuad_Utils_quatprod(threadData_t *threadData, modelica_metatype _q_in1, modelica_metatype _q_in2)
{
  real_array _q_out;
  modelica_metatype out_q_out;
  _q_out = omc_GSQuad_Utils_quatprod(threadData, *((base_array_t*)_q_in1), *((base_array_t*)_q_in2));
  out_q_out = mmc_mk_modelica_array(_q_out);
  return out_q_out;
}

#ifdef __cplusplus
}
#endif
