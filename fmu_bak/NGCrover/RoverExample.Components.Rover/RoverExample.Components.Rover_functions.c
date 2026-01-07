#include "omc_simulation_settings.h"
#include "RoverExample.Components.Rover_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "RoverExample.Components.Rover_includes.h"


DLLDirection
real_array omc__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData_t *threadData, real_array _euler, real_array __omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler)
{
  real_array __omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR;
  real_array _R;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR), 2, (_index_t)3, (_index_t)3); // __omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR has no default value.
  alloc_real_array(&(_R), 2, (_index_t)3, (_index_t)3); // _R has no default value.
  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 1)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR, 2, ((modelica_integer) 1), ((modelica_integer) 1)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (((-sin(real_array_get(_euler, 1, ((modelica_integer) 3))))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3)))) - ((sin(real_array_get(_euler, 1, ((modelica_integer) 2)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 2))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3))))));

  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 2)) = ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) - ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3)))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR, 2, ((modelica_integer) 1), ((modelica_integer) 2)) = (sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((sin(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (((-sin(real_array_get(_euler, 1, ((modelica_integer) 3))))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3))))) + ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 2)))) + (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2)))))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) + (sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3))))) - ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3)))));

  real_array_get(_R, 2, ((modelica_integer) 1), ((modelica_integer) 3)) = (sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3)))) + ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR, 2, ((modelica_integer) 1), ((modelica_integer) 3)) = (sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3)))) + (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3))))) + (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((sin(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (((-sin(real_array_get(_euler, 1, ((modelica_integer) 3))))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3))))) + ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 2)))) - ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 1)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR, 2, ((modelica_integer) 2), ((modelica_integer) 1)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * ((cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3)))) - ((sin(real_array_get(_euler, 1, ((modelica_integer) 2)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 2))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3))))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 2)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) + ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR, 2, ((modelica_integer) 2), ((modelica_integer) 2)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (((-sin(real_array_get(_euler, 1, ((modelica_integer) 3))))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3)))) + (sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((sin(real_array_get(_euler, 1, ((modelica_integer) 2)))) * ((cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3))))) + ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 2)))) + (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2)))))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3)))) - ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3))))));

  real_array_get(_R, 2, ((modelica_integer) 2), ((modelica_integer) 3)) = ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3)))) - ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3)))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR, 2, ((modelica_integer) 2), ((modelica_integer) 3)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((sin(real_array_get(_euler, 1, ((modelica_integer) 2)))) * ((cos(real_array_get(_euler, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3))))) + ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((cos(real_array_get(_euler, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 2)))) - ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 2))))))) * (sin(real_array_get(_euler, 1, ((modelica_integer) 3)))) + ((-sin(real_array_get(_euler, 1, ((modelica_integer) 1))))) * (((-sin(real_array_get(_euler, 1, ((modelica_integer) 3))))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 3)))) - ((cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 3))))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 1)) = (-sin(real_array_get(_euler, 1, ((modelica_integer) 2))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR, 2, ((modelica_integer) 3), ((modelica_integer) 1)) = ((-cos(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 2)));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 2)) = (sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 2))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR, 2, ((modelica_integer) 3), ((modelica_integer) 2)) = (sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (((-sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 2)))) + (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 2)))));

  real_array_get(_R, 2, ((modelica_integer) 3), ((modelica_integer) 3)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 2))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR, 2, ((modelica_integer) 3), ((modelica_integer) 3)) = (cos(real_array_get(_euler, 1, ((modelica_integer) 1)))) * (((-sin(real_array_get(_euler, 1, ((modelica_integer) 2))))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 2)))) - ((sin(real_array_get(_euler, 1, ((modelica_integer) 1)))) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler, 1, ((modelica_integer) 1))) * (cos(real_array_get(_euler, 1, ((modelica_integer) 2))))));
  _return: OMC_LABEL_UNUSED
  return __omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR;
}
modelica_metatype boxptr__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData_t *threadData, modelica_metatype _euler, modelica_metatype __omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler)
{
  real_array __omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR;
  modelica_metatype out__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR;
  __omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR = omc__omcQ_24DER_24RoverExample_24PUtils_24Peul2rot(threadData, *((base_array_t*)_euler), *((base_array_t*)__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDEReuler));
  out__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR = mmc_mk_modelica_array(__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR);
  return out__omcQ_24RoverExample_24PUtils_24Peul2rot_24funDERR;
}

DLLDirection
modelica_real omc_RoverExample_Utils_avoidzero(threadData_t *threadData, modelica_real _x)
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
modelica_metatype boxptr_RoverExample_Utils_avoidzero(threadData_t *threadData, modelica_metatype _x)
{
  modelica_real tmp1;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_x);
  _y = omc_RoverExample_Utils_avoidzero(threadData, tmp1);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

DLLDirection
modelica_real omc_RoverExample_Utils_clip(threadData_t *threadData, modelica_real _x, modelica_real _x_min, modelica_real _x_max)
{
  modelica_real _y;
  _tailrecursive: OMC_LABEL_UNUSED
  // _y has no default value.
  _y = ((_x < _x_min)?_x_min:((_x > _x_max)?_x_max:_x));
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_RoverExample_Utils_clip(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x_min, modelica_metatype _x_max)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_x);
  tmp2 = mmc_unbox_real(_x_min);
  tmp3 = mmc_unbox_real(_x_max);
  _y = omc_RoverExample_Utils_clip(threadData, tmp1, tmp2, tmp3);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

DLLDirection
real_array omc_RoverExample_Utils_cross3(threadData_t *threadData, real_array _v_in1, real_array _v_in2)
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
modelica_metatype boxptr_RoverExample_Utils_cross3(threadData_t *threadData, modelica_metatype _v_in1, modelica_metatype _v_in2)
{
  real_array _v_out;
  modelica_metatype out_v_out;
  _v_out = omc_RoverExample_Utils_cross3(threadData, *((base_array_t*)_v_in1), *((base_array_t*)_v_in2));
  out_v_out = mmc_mk_modelica_array(_v_out);
  return out_v_out;
}

DLLDirection
modelica_real omc_RoverExample_Utils_dot3(threadData_t *threadData, real_array _v_in1, real_array _v_in2)
{
  modelica_real _v_out;
  _tailrecursive: OMC_LABEL_UNUSED
  // _v_out has no default value.
  _v_out = (real_array_get(_v_in1, 1, ((modelica_integer) 1))) * (real_array_get(_v_in2, 1, ((modelica_integer) 1))) + (real_array_get(_v_in1, 1, ((modelica_integer) 2))) * (real_array_get(_v_in2, 1, ((modelica_integer) 2))) + (real_array_get(_v_in1, 1, ((modelica_integer) 3))) * (real_array_get(_v_in2, 1, ((modelica_integer) 3)));
  _return: OMC_LABEL_UNUSED
  return _v_out;
}
modelica_metatype boxptr_RoverExample_Utils_dot3(threadData_t *threadData, modelica_metatype _v_in1, modelica_metatype _v_in2)
{
  modelica_real _v_out;
  modelica_metatype out_v_out;
  _v_out = omc_RoverExample_Utils_dot3(threadData, *((base_array_t*)_v_in1), *((base_array_t*)_v_in2));
  out_v_out = mmc_mk_rcon(_v_out);
  return out_v_out;
}

DLLDirection
real_array omc_RoverExample_Utils_eul2rot(threadData_t *threadData, real_array _euler)
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
modelica_metatype boxptr_RoverExample_Utils_eul2rot(threadData_t *threadData, modelica_metatype _euler)
{
  real_array _R;
  modelica_metatype out_R;
  _R = omc_RoverExample_Utils_eul2rot(threadData, *((base_array_t*)_euler));
  out_R = mmc_mk_modelica_array(_R);
  return out_R;
}

#ifdef __cplusplus
}
#endif
