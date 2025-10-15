/* Non Linear Systems */
#include "RoverExample.Components.Rover_model.h"
#include "RoverExample.Components.Rover_12jac.h"
#include "simulation/jacobian_util.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
equation index: 138
type: SIMPLE_ASSIGN
rover_8d.Fx_fl = rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */) = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 139
type: SIMPLE_ASSIGN
rover_8d.Fy_fl = rover_8d.c_alpha * tan(rover_8d.alpha_fl_bnd) * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */) = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[178]] /* rover_8d.alpha_fl_bnd variable */))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 140
type: SIMPLE_ASSIGN
rover_8d.Fx_rl = rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[165]] /* rover_8d.Fx_rl variable */) = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 141
type: SIMPLE_ASSIGN
rover_8d.Fy_rl = rover_8d.c_alpha * tan(rover_8d.alpha_rl_bnd) * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[169]] /* rover_8d.Fy_rl variable */) = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[180]] /* rover_8d.alpha_rl_bnd variable */))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 142
type: SIMPLE_ASSIGN
rover_8d.Fx_rr = rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[166]] /* rover_8d.Fx_rr variable */) = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 143
type: SIMPLE_ASSIGN
rover_8d.Fy_rr = rover_8d.c_alpha * tan(rover_8d.alpha_rr_bnd) * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[170]] /* rover_8d.Fy_rr variable */) = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[181]] /* rover_8d.alpha_rr_bnd variable */))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 144
type: SIMPLE_ASSIGN
rover_8d.Fy_fr = rover_8d.c_alpha * tan(rover_8d.alpha_fr_bnd) * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */) = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* rover_8d.alpha_fr_bnd variable */))) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 145
type: SIMPLE_ASSIGN
rover_8d.Fx_fr = rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */) = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 146
type: SIMPLE_ASSIGN
rover_8d.ax = (rover_8d.Fx_fl * cos(-rover_8d.delta) + rover_8d.Fy_fl * sin(-rover_8d.delta) + rover_8d.Fx_fr * cos(-rover_8d.delta) + rover_8d.Fy_fr * sin(-rover_8d.delta) + rover_8d.Fx_rl + rover_8d.Fx_rr) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */) = DIVISION_SIM(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * (cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * (cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[165]] /* rover_8d.Fx_rl variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[166]] /* rover_8d.Fx_rr variable */),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total",equationIndexes);
  TRACE_POP
}
/*
equation index: 147
type: SIMPLE_ASSIGN
rover_8d.ay = (rover_8d.Fy_fl * cos(-rover_8d.delta) + rover_8d.Fy_fr * cos(-rover_8d.delta) + rover_8d.Fy_rl + rover_8d.Fy_rr - rover_8d.Fx_fr * sin(-rover_8d.delta) - rover_8d.Fx_fl * sin(-rover_8d.delta)) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */) = DIVISION_SIM(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * (cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * (cos((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */)))) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[169]] /* rover_8d.Fy_rl variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[170]] /* rover_8d.Fy_rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * (sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * (sin((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* rover_8d.delta STATE(1) */))))),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total",equationIndexes);
  TRACE_POP
}
/*
equation index: 148
type: SIMPLE_ASSIGN
rover_8d.Fz_rl = (4.903325 * rover_8d.mass_total * rover_8d.l_front + 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax) / rover_8d.l_total + rover_8d.ay * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw + 0.5 * ((-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,148};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */) = DIVISION_SIM((4.903325) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */))) + (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */))),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)) + (0.5) * (DIVISION_SIM(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes));
  TRACE_POP
}
/*
equation index: 149
type: SIMPLE_ASSIGN
rover_8d.z_rl = RoverExample.Utils.clip(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_rl_bnd)) ^ 2.0 + 1e-15), rover_8d.z_min, rover_8d.z_max)
*/
void RoverExample_Components_Rover_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[180]] /* rover_8d.alpha_rl_bnd variable */)));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_rl_bnd)) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) = omc_RoverExample_Utils_clip(threadData, DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */))) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */))),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_rl_bnd)) ^ 2.0 + 1e-15)",equationIndexes), (data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */), (data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
  TRACE_POP
}
/*
equation index: 150
type: SIMPLE_ASSIGN
rover_8d.Fz_fl = (4.903325 * rover_8d.mass_total * rover_8d.l_rear + (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax) / rover_8d.l_total + rover_8d.ay * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw + 0.5 * ((-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */) = DIVISION_SIM((4.903325) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */))) + (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */))),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)) + (0.5) * (DIVISION_SIM(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes));
  TRACE_POP
}
/*
equation index: 151
type: SIMPLE_ASSIGN
rover_8d.z_fl = RoverExample.Utils.clip(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_fl_bnd)) ^ 2.0 + 1e-15), rover_8d.z_min, rover_8d.z_max)
*/
void RoverExample_Components_Rover_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[178]] /* rover_8d.alpha_fl_bnd variable */)));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_fl_bnd)) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) = omc_RoverExample_Utils_clip(threadData, DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */))) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */))),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_fl_bnd)) ^ 2.0 + 1e-15)",equationIndexes), (data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */), (data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
  TRACE_POP
}
/*
equation index: 152
type: SIMPLE_ASSIGN
rover_8d.Fz_fr = (4.903325 * rover_8d.mass_total * rover_8d.l_rear + (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax) / rover_8d.l_total + (-0.5) * ((-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.tw - rover_8d.ay * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */) = DIVISION_SIM((4.903325) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */))) + (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */))),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes) + (-0.5) * (DIVISION_SIM(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)));
  TRACE_POP
}
/*
equation index: 153
type: SIMPLE_ASSIGN
rover_8d.z_fr = RoverExample.Utils.clip(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_fr_bnd)) ^ 2.0 + 1e-15), rover_8d.z_min, rover_8d.z_max)
*/
void RoverExample_Components_Rover_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* rover_8d.alpha_fr_bnd variable */)));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_fr_bnd)) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) = omc_RoverExample_Utils_clip(threadData, DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */))) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */))),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_fr_bnd)) ^ 2.0 + 1e-15)",equationIndexes), (data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */), (data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
  TRACE_POP
}
/*
equation index: 154
type: SIMPLE_ASSIGN
rover_8d.Fz_rr = (4.903325 * rover_8d.mass_total * rover_8d.l_front + 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax) / rover_8d.l_total + (-0.5) * ((-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.tw - rover_8d.ay * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */) = DIVISION_SIM((4.903325) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */))) + (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */))),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes) + (-0.5) * (DIVISION_SIM(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)));
  TRACE_POP
}
/*
equation index: 155
type: SIMPLE_ASSIGN
rover_8d.z_rr = RoverExample.Utils.clip(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_rr_bnd)) ^ 2.0 + 1e-15), rover_8d.z_min, rover_8d.z_max)
*/
void RoverExample_Components_Rover_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (tan((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[181]] /* rover_8d.alpha_rr_bnd variable */)));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_rr_bnd)) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) = omc_RoverExample_Utils_clip(threadData, DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */))) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */))),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * tan(rover_8d.alpha_rr_bnd)) ^ 2.0 + 1e-15)",equationIndexes), (data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */), (data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
  TRACE_POP
}

void residualFunc160(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,160};
  int i,j;
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  /* iteration variables */
  for (i=0; i<4; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc160: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 160).vars[i]);
      for (j=0; j<4; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc160 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */) = xloc[0];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */) = xloc[1];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */) = xloc[2];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */) = xloc[3];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_138(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_139(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_140(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_141(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_142(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_143(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_144(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_145(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_146(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_147(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_148(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_149(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_150(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_151(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_152(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_153(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_154(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_155(data, threadData);
  /* body */
  tmp0 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */),1.0);
  res[0] = (tmp0?((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):1.0) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */);

  tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */),1.0);
  res[1] = (tmp1?((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):1.0) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */);

  tmp2 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */),1.0);
  res[2] = (tmp2?((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):1.0) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */);

  tmp3 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */),1.0);
  res[3] = (tmp3?((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):1.0) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS160(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+4] = {0,4,4,4,4};
  const int rowIndex[16] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(4, 16, 4);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (4+1)*sizeof(unsigned int));
  
  for(i=2;i<4+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 16*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {3};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {2};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_2[i]] = 2;
  
  /* color 3 with 1 columns */
  const int indices_3[1] = {1};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_3[i]] = 3;
  
  /* color 4 with 1 columns */
  const int indices_4[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_4[i]] = 4;
}

void freeSparsePatternNLS160(NONLINEAR_SYSTEM_DATA* inSysData)
{
  if (inSysData->isPatternAvailable) {
    freeSparsePattern(inSysData->sparsePattern);
    free(inSysData->sparsePattern);
    inSysData->sparsePattern = NULL;
    inSysData->isPatternAvailable = FALSE;
  }
}
void initializeNonlinearPatternNLS160(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
}

OMC_DISABLE_OPT
void initializeStaticDataNLS160(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for rover_8d.fz_fr */
  sysData->nominal[i] = data->modelData->realVarsData[192].attribute /* rover_8d.fz_fr */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[192].attribute /* rover_8d.fz_fr */.min;
  sysData->max[i++]   = data->modelData->realVarsData[192].attribute /* rover_8d.fz_fr */.max;
  /* static nls data for rover_8d.fz_rr */
  sysData->nominal[i] = data->modelData->realVarsData[194].attribute /* rover_8d.fz_rr */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[194].attribute /* rover_8d.fz_rr */.min;
  sysData->max[i++]   = data->modelData->realVarsData[194].attribute /* rover_8d.fz_rr */.max;
  /* static nls data for rover_8d.fz_rl */
  sysData->nominal[i] = data->modelData->realVarsData[193].attribute /* rover_8d.fz_rl */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[193].attribute /* rover_8d.fz_rl */.min;
  sysData->max[i++]   = data->modelData->realVarsData[193].attribute /* rover_8d.fz_rl */.max;
  /* static nls data for rover_8d.fz_fl */
  sysData->nominal[i] = data->modelData->realVarsData[191].attribute /* rover_8d.fz_fl */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[191].attribute /* rover_8d.fz_fl */.min;
  sysData->max[i++]   = data->modelData->realVarsData[191].attribute /* rover_8d.fz_fl */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS160(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS160(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS160(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS160(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS160(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */);
  array[1] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */);
  array[2] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */);
  array[3] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */);
}


/* inner equations */

/*
equation index: 323
type: SIMPLE_ASSIGN
rover_8d.Fx_fl = rover_8d.c_kappa * rover_8d.kappa_fl_bnd * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_323(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,323};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */) = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 324
type: SIMPLE_ASSIGN
rover_8d.Fy_fl = rover_8d.c_alpha * $cse17 * rover_8d.fz_fl / (1.0 - rover_8d.kappa_fl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,324};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */) = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */),"1.0 - rover_8d.kappa_fl_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 325
type: SIMPLE_ASSIGN
rover_8d.Fx_rl = rover_8d.c_kappa * rover_8d.kappa_rl_bnd * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_325(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,325};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[165]] /* rover_8d.Fx_rl variable */) = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 326
type: SIMPLE_ASSIGN
rover_8d.Fy_rl = rover_8d.c_alpha * $cse25 * rover_8d.fz_rl / (1.0 - rover_8d.kappa_rl_bnd)
*/
void RoverExample_Components_Rover_eqFunction_326(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,326};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[169]] /* rover_8d.Fy_rl variable */) = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */),"1.0 - rover_8d.kappa_rl_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 327
type: SIMPLE_ASSIGN
rover_8d.Fy_rr = rover_8d.c_alpha * $cse29 * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_327(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,327};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[170]] /* rover_8d.Fy_rr variable */) = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 328
type: SIMPLE_ASSIGN
rover_8d.Fx_rr = rover_8d.c_kappa * rover_8d.kappa_rr_bnd * rover_8d.fz_rr / (1.0 - rover_8d.kappa_rr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,328};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[166]] /* rover_8d.Fx_rr variable */) = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */),"1.0 - rover_8d.kappa_rr_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 329
type: SIMPLE_ASSIGN
rover_8d.Fx_fr = rover_8d.c_kappa * rover_8d.kappa_fr_bnd * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,329};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */) = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 330
type: SIMPLE_ASSIGN
rover_8d.Fy_fr = rover_8d.c_alpha * $cse21 * rover_8d.fz_fr / (1.0 - rover_8d.kappa_fr_bnd)
*/
void RoverExample_Components_Rover_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,330};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */) = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */),1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */),"1.0 - rover_8d.kappa_fr_bnd",equationIndexes)));
  TRACE_POP
}
/*
equation index: 331
type: SIMPLE_ASSIGN
rover_8d.ax = (rover_8d.Fx_fl * $cse34 + rover_8d.Fy_fl * $cse35 + rover_8d.Fx_fr * $cse34 + rover_8d.Fy_fr * $cse35 + rover_8d.Fx_rl + rover_8d.Fx_rr) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,331};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */) = DIVISION_SIM(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */)) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[165]] /* rover_8d.Fx_rl variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[166]] /* rover_8d.Fx_rr variable */),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total",equationIndexes);
  TRACE_POP
}
/*
equation index: 332
type: SIMPLE_ASSIGN
rover_8d.ay = (rover_8d.Fy_fl * $cse34 + rover_8d.Fy_fr * $cse34 + rover_8d.Fy_rl + rover_8d.Fy_rr - rover_8d.Fx_fr * $cse35 - rover_8d.Fx_fl * $cse35) / rover_8d.mass_total
*/
void RoverExample_Components_Rover_eqFunction_332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,332};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */) = DIVISION_SIM(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* rover_8d.Fy_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* rover_8d.Fy_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* $cse34 variable */)) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[169]] /* rover_8d.Fy_rl variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[170]] /* rover_8d.Fy_rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* rover_8d.Fx_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* rover_8d.Fx_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* $cse35 variable */))),(data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */),"rover_8d.mass_total",equationIndexes);
  TRACE_POP
}
/*
equation index: 333
type: SIMPLE_ASSIGN
rover_8d.Fz_rr = (4.903325 * rover_8d.mass_total * rover_8d.l_front + 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax) / rover_8d.l_total + (-0.5) * ((-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.tw - rover_8d.ay * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_333(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,333};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */) = DIVISION_SIM((4.903325) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */))) + (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */))),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes) + (-0.5) * (DIVISION_SIM(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)));
  TRACE_POP
}
/*
equation index: 334
type: SIMPLE_ASSIGN
rover_8d.z_rr = RoverExample.Utils.clip(0.5 * rover_8d.mu_rr * rover_8d.Fz_rr * (1.0 - rover_8d.kappa_rr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15), rover_8d.z_min, rover_8d.z_max)
*/
void RoverExample_Components_Rover_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* $cse29 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */) = omc_RoverExample_Utils_clip(threadData, DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* rover_8d.mu_rr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* rover_8d.Fz_rr variable */))) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* rover_8d.kappa_rr_bnd variable */))),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse29) ^ 2.0 + 1e-15)",equationIndexes), (data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */), (data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
  TRACE_POP
}
/*
equation index: 335
type: SIMPLE_ASSIGN
rover_8d.Fz_fr = (4.903325 * rover_8d.mass_total * rover_8d.l_rear + (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax) / rover_8d.l_total + (-0.5) * ((-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.tw - rover_8d.ay * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */) = DIVISION_SIM((4.903325) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */))) + (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */))),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes) + (-0.5) * (DIVISION_SIM(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)));
  TRACE_POP
}
/*
equation index: 336
type: SIMPLE_ASSIGN
rover_8d.z_fr = RoverExample.Utils.clip(0.5 * rover_8d.mu_fr * rover_8d.Fz_fr * (1.0 - rover_8d.kappa_fr_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15), rover_8d.z_min, rover_8d.z_max)
*/
void RoverExample_Components_Rover_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* $cse21 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */) = omc_RoverExample_Utils_clip(threadData, DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* rover_8d.mu_fr variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* rover_8d.Fz_fr variable */))) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* rover_8d.kappa_fr_bnd variable */))),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fr_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse21) ^ 2.0 + 1e-15)",equationIndexes), (data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */), (data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
  TRACE_POP
}
/*
equation index: 337
type: SIMPLE_ASSIGN
rover_8d.Fz_rl = (4.903325 * rover_8d.mass_total * rover_8d.l_front + 0.5 * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax) / rover_8d.l_total + rover_8d.ay * (rover_8d.mass_sprung * rover_8d.l_front * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_rear * rover_8d.hur) / rover_8d.tw + 0.5 * ((-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,337};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */) = DIVISION_SIM((4.903325) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */))) + (0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */))),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[110] /* rover_8d.l_front PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes))) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)) + (0.5) * (DIVISION_SIM(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes));
  TRACE_POP
}
/*
equation index: 338
type: SIMPLE_ASSIGN
rover_8d.z_rl = RoverExample.Utils.clip(0.5 * rover_8d.mu_rl * rover_8d.Fz_rl * (1.0 - rover_8d.kappa_rl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15), rover_8d.z_min, rover_8d.z_max)
*/
void RoverExample_Components_Rover_eqFunction_338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,338};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* $cse25 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */) = omc_RoverExample_Utils_clip(threadData, DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* rover_8d.mu_rl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* rover_8d.Fz_rl variable */))) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* rover_8d.kappa_rl_bnd variable */))),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_rl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse25) ^ 2.0 + 1e-15)",equationIndexes), (data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */), (data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
  TRACE_POP
}
/*
equation index: 339
type: SIMPLE_ASSIGN
rover_8d.Fz_fl = (4.903325 * rover_8d.mass_total * rover_8d.l_rear + (-0.5) * (rover_8d.mass_unsprung_front * rover_8d.huf + rover_8d.mass_sprung * rover_8d.hs + rover_8d.mass_unsprung_rear * rover_8d.hur) * rover_8d.ax) / rover_8d.l_total + rover_8d.ay * (rover_8d.mass_sprung * rover_8d.l_rear * rover_8d.hs / rover_8d.l_total + rover_8d.mass_unsprung_front * rover_8d.huf) / rover_8d.tw + 0.5 * ((-rover_8d.k_rllsp) * rover_8d.phi - rover_8d.c_rllsp * rover_8d.p) / rover_8d.tw
*/
void RoverExample_Components_Rover_eqFunction_339(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,339};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */) = DIVISION_SIM((4.903325) * (((data->simulationInfo->realParameter[118] /* rover_8d.mass_total PARAM */)) * ((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */))) + (-0.5) * ((((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)) + ((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * ((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */)) + ((data->simulationInfo->realParameter[120] /* rover_8d.mass_unsprung_rear PARAM */)) * ((data->simulationInfo->realParameter[106] /* rover_8d.hur PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* rover_8d.ax variable */))),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* rover_8d.ay variable */)) * (DIVISION_SIM(((data->simulationInfo->realParameter[117] /* rover_8d.mass_sprung PARAM */)) * (((data->simulationInfo->realParameter[111] /* rover_8d.l_rear PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[104] /* rover_8d.hs PARAM */),(data->simulationInfo->realParameter[112] /* rover_8d.l_total PARAM */),"rover_8d.l_total",equationIndexes))) + ((data->simulationInfo->realParameter[119] /* rover_8d.mass_unsprung_front PARAM */)) * ((data->simulationInfo->realParameter[105] /* rover_8d.huf PARAM */)),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes)) + (0.5) * (DIVISION_SIM(((-(data->simulationInfo->realParameter[107] /* rover_8d.k_rllsp PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* rover_8d.phi STATE(1,rover_8d.p) */)) - (((data->simulationInfo->realParameter[85] /* rover_8d.c_rllsp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* rover_8d.p STATE(1) */))),(data->simulationInfo->realParameter[126] /* rover_8d.tw PARAM */),"rover_8d.tw",equationIndexes));
  TRACE_POP
}
/*
equation index: 340
type: SIMPLE_ASSIGN
rover_8d.z_fl = RoverExample.Utils.clip(0.5 * rover_8d.mu_fl * rover_8d.Fz_fl * (1.0 - rover_8d.kappa_fl_bnd) / sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15), rover_8d.z_min, rover_8d.z_max)
*/
void RoverExample_Components_Rover_eqFunction_340(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,340};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = ((data->simulationInfo->realParameter[84] /* rover_8d.c_kappa PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */));
  tmp1 = ((data->simulationInfo->realParameter[83] /* rover_8d.c_alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* $cse17 variable */));
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1) + 1e-15;
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15) was %g should be >= 0", tmp2);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */) = omc_RoverExample_Utils_clip(threadData, DIVISION_SIM((0.5) * ((((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* rover_8d.mu_fl variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* rover_8d.Fz_fl variable */))) * (1.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* rover_8d.kappa_fl_bnd variable */))),sqrt(tmp2),"sqrt((rover_8d.c_kappa * rover_8d.kappa_fl_bnd) ^ 2.0 + (rover_8d.c_alpha * $cse17) ^ 2.0 + 1e-15)",equationIndexes), (data->simulationInfo->realParameter[129] /* rover_8d.z_min PARAM */), (data->simulationInfo->realParameter[128] /* rover_8d.z_max PARAM */));
  TRACE_POP
}

void residualFunc345(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,345};
  int i,j;
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  /* iteration variables */
  for (i=0; i<4; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc345: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 345).vars[i]);
      for (j=0; j<4; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc345 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */) = xloc[0];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */) = xloc[1];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */) = xloc[2];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */) = xloc[3];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  RoverExample_Components_Rover_eqFunction_323(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_324(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_325(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_326(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_327(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_328(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_329(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_330(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_331(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_332(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_333(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_334(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_335(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_336(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_337(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_338(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_339(data, threadData);

  /* local constraints */
  RoverExample_Components_Rover_eqFunction_340(data, threadData);
  /* body */
  tmp1 = 1.0;
  tmp2 = 1.0;
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */), 1.0, tmp1, tmp2, 3, Less, LessZC);
  res[0] = (tmp0?((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* rover_8d.z_rl variable */)):1.0) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */);

  tmp4 = 1.0;
  tmp5 = 1.0;
  relationhysteresis(data, &tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */), 1.0, tmp4, tmp5, 5, Less, LessZC);
  res[1] = (tmp3?((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* rover_8d.z_fr variable */)):1.0) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */);

  tmp7 = 1.0;
  tmp8 = 1.0;
  relationhysteresis(data, &tmp6, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */), 1.0, tmp7, tmp8, 6, Less, LessZC);
  res[2] = (tmp6?((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* rover_8d.z_rr variable */)):1.0) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */);

  tmp10 = 1.0;
  tmp11 = 1.0;
  relationhysteresis(data, &tmp9, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */), 1.0, tmp10, tmp11, 4, Less, LessZC);
  res[3] = (tmp9?((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)) * (2.0 - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* rover_8d.z_fl variable */)):1.0) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS345(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+4] = {0,4,4,4,4};
  const int rowIndex[16] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(4, 16, 4);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (4+1)*sizeof(unsigned int));
  
  for(i=2;i<4+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 16*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {3};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {2};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_2[i]] = 2;
  
  /* color 3 with 1 columns */
  const int indices_3[1] = {1};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_3[i]] = 3;
  
  /* color 4 with 1 columns */
  const int indices_4[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_4[i]] = 4;
}

void freeSparsePatternNLS345(NONLINEAR_SYSTEM_DATA* inSysData)
{
  if (inSysData->isPatternAvailable) {
    freeSparsePattern(inSysData->sparsePattern);
    free(inSysData->sparsePattern);
    inSysData->sparsePattern = NULL;
    inSysData->isPatternAvailable = FALSE;
  }
}
void initializeNonlinearPatternNLS345(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
}

OMC_DISABLE_OPT
void initializeStaticDataNLS345(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for rover_8d.fz_fr */
  sysData->nominal[i] = data->modelData->realVarsData[192].attribute /* rover_8d.fz_fr */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[192].attribute /* rover_8d.fz_fr */.min;
  sysData->max[i++]   = data->modelData->realVarsData[192].attribute /* rover_8d.fz_fr */.max;
  /* static nls data for rover_8d.fz_rr */
  sysData->nominal[i] = data->modelData->realVarsData[194].attribute /* rover_8d.fz_rr */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[194].attribute /* rover_8d.fz_rr */.min;
  sysData->max[i++]   = data->modelData->realVarsData[194].attribute /* rover_8d.fz_rr */.max;
  /* static nls data for rover_8d.fz_rl */
  sysData->nominal[i] = data->modelData->realVarsData[193].attribute /* rover_8d.fz_rl */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[193].attribute /* rover_8d.fz_rl */.min;
  sysData->max[i++]   = data->modelData->realVarsData[193].attribute /* rover_8d.fz_rl */.max;
  /* static nls data for rover_8d.fz_fl */
  sysData->nominal[i] = data->modelData->realVarsData[191].attribute /* rover_8d.fz_fl */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[191].attribute /* rover_8d.fz_fl */.min;
  sysData->max[i++]   = data->modelData->realVarsData[191].attribute /* rover_8d.fz_fl */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS345(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS345(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS345(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS345(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS345(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* rover_8d.fz_fr variable */);
  array[1] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* rover_8d.fz_rr variable */);
  array[2] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* rover_8d.fz_rl variable */);
  array[3] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* rover_8d.fz_fl variable */);
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void RoverExample_Components_Rover_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[1].equationIndex = 345;
  nonLinearSystemData[1].size = 4;
  nonLinearSystemData[1].homotopySupport = 0 /* false */;
  nonLinearSystemData[1].mixedSystem = 1 /* true */;
  nonLinearSystemData[1].residualFunc = residualFunc345;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = NULL;
  nonLinearSystemData[1].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[1].jacobianIndex = -1;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS345;
  nonLinearSystemData[1].freeStaticNLSData = freeStaticDataNLS345;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS345;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  const int tmp_eqn_indices_1[22] = {323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 344, 343, 342, 341};
  nonLinearSystemData[1].eqn_simcode_indices = malloc(22 * sizeof(int));
  memcpy(nonLinearSystemData[1].eqn_simcode_indices, tmp_eqn_indices_1, 22 * sizeof(int));
  
  
  nonLinearSystemData[0].equationIndex = 160;
  nonLinearSystemData[0].size = 4;
  nonLinearSystemData[0].homotopySupport = 0 /* false */;
  nonLinearSystemData[0].mixedSystem = 1 /* true */;
  nonLinearSystemData[0].residualFunc = residualFunc160;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = NULL;
  nonLinearSystemData[0].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[0].jacobianIndex = -1;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS160;
  nonLinearSystemData[0].freeStaticNLSData = freeStaticDataNLS160;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS160;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  const int tmp_eqn_indices_0[22] = {138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 159, 158, 157, 156};
  nonLinearSystemData[0].eqn_simcode_indices = malloc(22 * sizeof(int));
  memcpy(nonLinearSystemData[0].eqn_simcode_indices, tmp_eqn_indices_0, 22 * sizeof(int));
}

#if defined(__cplusplus)
}
#endif

