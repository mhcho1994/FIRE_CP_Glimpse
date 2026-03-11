#include "omc_simulation_settings.h"
#include "GSQuad.Components.Controller_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "GSQuad.Components.Controller_includes.h"


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
real_array omc_GSQuad_Utils_eul2rot(threadData_t *threadData, real_array _euler)
{
  real_array _R;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_R), 2, (_index_t)3, (_index_t)3); // _R has no default value.
  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 1)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3))));

  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 2)) = ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) - ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3)))));

  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 3)) = (sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3)))) + ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 1)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 2)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) + ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 3)) = ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3)))) - ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3)))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 1)) = (-sin(real_array_get(_euler, 1, ((modelica_integer) 2))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 2)) = (sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 2))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 3)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 2))));
  _return: OMC_LABEL_UNUSED
  return _R;
}
modelica_metatype boxptr_GSQuad_Utils_eul2rot(threadData_t *threadData, modelica_metatype _euler)
{
  real_array _R;
  modelica_metatype out_R;
  _R = omc_GSQuad_Utils_eul2rot(threadData, *((base_array_t*)_euler));
  out_R = mmc_mk_modelica_array(_R);
  return out_R;
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

#ifdef __cplusplus
}
#endif
