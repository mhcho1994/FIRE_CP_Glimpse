#include "omc_simulation_settings.h"
#include "RoverExample.Components.Controller_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "RoverExample.Components.Controller_includes.h"


DLLDirection
real_array omc__omcQ_24DER_24RoverExample_24PComponents_24PMadgwickFusionStep(threadData_t *threadData, modelica_real _ax, modelica_real _ay, modelica_real _az, modelica_real _gx, modelica_real _gy, modelica_real _gz, modelica_real _mx, modelica_real _my, modelica_real _mz, real_array _q0, modelica_real _alpha, modelica_real _beta, modelica_real _dt, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERax, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERay, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERaz, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgx, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgy, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgz, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmx, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmy, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmz, real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbeta, modelica_real __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdt)
{
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew;
  real_array _qdot;
  real_array _acc_normalized;
  real_array _mag_normalized;
  real_array _hE_quat;
  real_array _bE_quat;
  real_array _fb;
  real_array _Jb;
  real_array _fg;
  real_array _Jg;
  real_array _delta_f;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqdot;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERacc_5Fnormalized;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERhE_5Fquat;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff;
  real_array _qnew;
  real_array tmp1;
  real_array tmp2;
  real_array tmp3;
  real_array tmp4;
  real_array tmp5;
  real_array tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  real_array tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_real tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_real tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  modelica_real tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  modelica_real tmp42;
  modelica_real tmp43;
  modelica_real tmp44;
  modelica_real tmp45;
  modelica_real tmp46;
  modelica_real tmp47;
  modelica_real tmp48;
  modelica_real tmp49;
  modelica_real tmp50;
  modelica_real tmp51;
  modelica_real tmp52;
  modelica_real tmp53;
  modelica_real tmp54;
  modelica_real tmp55;
  modelica_real tmp56;
  modelica_real tmp57;
  modelica_real tmp58;
  modelica_real tmp59;
  modelica_real tmp60;
  modelica_real tmp61;
  modelica_real tmp62;
  modelica_real tmp63;
  modelica_real tmp64;
  modelica_real tmp65;
  modelica_real tmp66;
  modelica_real tmp67;
  real_array tmp68;
  modelica_real tmp69;
  modelica_real tmp70;
  modelica_real tmp71;
  modelica_real tmp72;
  modelica_real tmp73;
  modelica_real tmp74;
  modelica_real tmp75;
  modelica_real tmp76;
  modelica_real tmp77;
  modelica_real tmp78;
  modelica_real tmp79;
  modelica_real tmp80;
  modelica_real tmp81;
  modelica_real tmp82;
  modelica_real tmp83;
  real_array tmp84;
  modelica_real tmp85;
  modelica_real tmp86;
  modelica_real tmp87;
  modelica_real tmp88;
  modelica_real tmp89;
  modelica_real tmp90;
  modelica_real tmp91;
  modelica_real tmp92;
  modelica_real tmp93;
  modelica_real tmp94;
  modelica_real tmp95;
  modelica_real tmp96;
  modelica_real tmp97;
  modelica_real tmp98;
  modelica_real tmp99;
  modelica_real tmp100;
  modelica_real tmp101;
  modelica_real tmp102;
  modelica_real tmp103;
  modelica_real tmp104;
  modelica_real tmp105;
  modelica_real tmp106;
  modelica_real tmp107;
  modelica_real tmp108;
  modelica_real tmp109;
  modelica_real tmp110;
  modelica_real tmp111;
  modelica_real tmp112;
  modelica_real tmp113;
  modelica_real tmp114;
  modelica_real tmp115;
  modelica_real tmp116;
  modelica_real tmp117;
  modelica_real tmp118;
  modelica_real tmp119;
  modelica_real tmp120;
  modelica_real tmp121;
  modelica_real tmp122;
  modelica_real tmp123;
  modelica_real tmp124;
  modelica_real tmp125;
  modelica_real tmp126;
  modelica_real tmp127;
  modelica_real tmp128;
  modelica_real tmp129;
  real_array tmp130;
  real_array tmp131;
  real_array tmp132;
  real_array tmp133;
  real_array tmp134;
  real_array tmp135;
  real_array tmp136;
  real_array tmp137;
  modelica_real tmp138;
  modelica_real tmp139;
  modelica_real tmp140;
  real_array tmp141;
  modelica_real tmp142;
  modelica_real tmp143;
  modelica_real tmp144;
  modelica_real tmp145;
  real_array tmp146;
  modelica_real tmp147;
  modelica_real tmp148;
  modelica_real tmp149;
  modelica_real tmp150;
  real_array tmp151;
  modelica_real tmp152;
  modelica_real tmp153;
  modelica_real tmp154;
  modelica_real tmp155;
  real_array tmp156;
  real_array tmp157;
  real_array tmp158;
  real_array tmp159;
  real_array tmp160;
  real_array tmp161;
  real_array tmp162;
  real_array tmp163;
  real_array tmp164;
  real_array tmp165;
  real_array tmp166;
  modelica_real tmp167;
  modelica_real tmp168;
  real_array tmp169;
  real_array tmp170;
  real_array tmp171;
  real_array tmp172;
  real_array tmp173;
  real_array tmp174;
  real_array tmp175;
  real_array tmp176;
  real_array tmp177;
  real_array tmp178;
  real_array tmp179;
  real_array tmp180;
  real_array tmp181;
  real_array tmp182;
  modelica_real tmp183;
  modelica_real tmp184;
  modelica_real tmp185;
  modelica_real tmp186;
  modelica_real tmp187;
  modelica_real tmp188;
  modelica_real tmp189;
  modelica_real tmp190;
  modelica_real tmp191;
  modelica_real tmp192;
  modelica_real tmp193;
  modelica_real tmp194;
  modelica_real tmp195;
  modelica_real tmp196;
  modelica_real tmp197;
  modelica_real tmp198;
  modelica_real tmp199;
  modelica_real tmp200;
  modelica_real tmp201;
  modelica_real tmp202;
  modelica_real tmp203;
  modelica_real tmp204;
  modelica_real tmp205;
  modelica_real tmp206;
  real_array tmp207;
  modelica_real tmp208;
  modelica_real tmp209;
  modelica_real tmp210;
  modelica_real tmp211;
  modelica_real tmp212;
  modelica_real tmp213;
  modelica_real tmp214;
  modelica_real tmp215;
  modelica_real tmp216;
  modelica_real tmp217;
  modelica_real tmp218;
  modelica_real tmp219;
  modelica_real tmp220;
  modelica_real tmp221;
  modelica_real tmp222;
  modelica_real tmp223;
  modelica_real tmp224;
  modelica_real tmp225;
  modelica_real tmp226;
  modelica_real tmp227;
  modelica_real tmp228;
  modelica_real tmp229;
  modelica_real tmp230;
  modelica_real tmp231;
  modelica_real tmp232;
  modelica_real tmp233;
  modelica_real tmp234;
  modelica_real tmp235;
  modelica_real tmp236;
  modelica_real tmp237;
  modelica_real tmp238;
  modelica_real tmp239;
  modelica_real tmp240;
  modelica_real tmp241;
  modelica_real tmp242;
  modelica_real tmp243;
  modelica_real tmp244;
  modelica_real tmp245;
  modelica_real tmp246;
  modelica_real tmp247;
  modelica_real tmp248;
  modelica_real tmp249;
  modelica_real tmp250;
  modelica_real tmp251;
  modelica_real tmp252;
  modelica_real tmp253;
  modelica_real tmp254;
  modelica_real tmp255;
  modelica_real tmp256;
  modelica_real tmp257;
  modelica_real tmp258;
  modelica_real tmp259;
  modelica_real tmp260;
  modelica_real tmp261;
  modelica_real tmp262;
  modelica_real tmp263;
  modelica_real tmp264;
  modelica_real tmp265;
  modelica_real tmp266;
  modelica_real tmp267;
  modelica_real tmp268;
  modelica_real tmp269;
  modelica_real tmp270;
  modelica_real tmp271;
  modelica_real tmp272;
  modelica_real tmp273;
  modelica_real tmp274;
  modelica_real tmp275;
  modelica_real tmp276;
  modelica_real tmp277;
  modelica_real tmp278;
  modelica_real tmp279;
  modelica_real tmp280;
  modelica_real tmp281;
  modelica_real tmp282;
  modelica_real tmp283;
  modelica_real tmp284;
  modelica_real tmp285;
  modelica_real tmp286;
  modelica_real tmp287;
  modelica_real tmp288;
  modelica_real tmp289;
  modelica_real tmp290;
  modelica_real tmp291;
  modelica_real tmp292;
  modelica_real tmp293;
  modelica_real tmp294;
  modelica_real tmp295;
  modelica_real tmp296;
  modelica_real tmp297;
  modelica_real tmp298;
  modelica_real tmp299;
  modelica_real tmp300;
  modelica_real tmp301;
  modelica_real tmp302;
  modelica_real tmp303;
  real_array tmp304;
  modelica_real tmp305;
  modelica_real tmp306;
  modelica_real tmp307;
  modelica_real tmp308;
  modelica_real tmp309;
  modelica_real tmp310;
  modelica_real tmp311;
  modelica_real tmp312;
  modelica_real tmp313;
  modelica_real tmp314;
  modelica_real tmp315;
  modelica_real tmp316;
  modelica_real tmp317;
  modelica_real tmp318;
  modelica_real tmp319;
  modelica_real tmp320;
  modelica_real tmp321;
  modelica_real tmp322;
  modelica_real tmp323;
  modelica_real tmp324;
  modelica_real tmp325;
  modelica_real tmp326;
  modelica_real tmp327;
  modelica_real tmp328;
  real_array tmp329;
  modelica_real tmp330;
  modelica_real tmp331;
  modelica_real tmp332;
  modelica_real tmp333;
  modelica_real tmp334;
  modelica_real tmp335;
  modelica_real tmp336;
  modelica_real tmp337;
  modelica_real tmp338;
  modelica_real tmp339;
  modelica_real tmp340;
  modelica_real tmp341;
  modelica_real tmp342;
  modelica_real tmp343;
  modelica_real tmp344;
  modelica_real tmp345;
  modelica_real tmp346;
  modelica_real tmp347;
  modelica_real tmp348;
  modelica_real tmp349;
  modelica_real tmp350;
  modelica_real tmp351;
  modelica_real tmp352;
  modelica_real tmp353;
  modelica_real tmp354;
  modelica_real tmp355;
  modelica_real tmp356;
  modelica_real tmp357;
  modelica_real tmp358;
  modelica_real tmp359;
  modelica_real tmp360;
  modelica_real tmp361;
  modelica_real tmp362;
  modelica_real tmp363;
  modelica_real tmp364;
  modelica_real tmp365;
  modelica_real tmp366;
  modelica_real tmp367;
  modelica_real tmp368;
  modelica_real tmp369;
  modelica_real tmp370;
  modelica_real tmp371;
  modelica_real tmp372;
  modelica_real tmp373;
  modelica_real tmp374;
  modelica_real tmp375;
  modelica_real tmp376;
  modelica_real tmp377;
  modelica_real tmp378;
  modelica_real tmp379;
  modelica_real tmp380;
  modelica_real tmp381;
  modelica_real tmp382;
  modelica_real tmp383;
  modelica_real tmp384;
  modelica_real tmp385;
  modelica_real tmp386;
  modelica_real tmp387;
  modelica_real tmp388;
  modelica_real tmp389;
  modelica_real tmp390;
  modelica_real tmp391;
  modelica_real tmp392;
  modelica_real tmp393;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew), 1, (_index_t)4); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew has no default value.
  alloc_real_array(&(_qdot), 1, (_index_t)4); // _qdot has no default value.
  alloc_real_array(&(_acc_normalized), 1, (_index_t)3); // _acc_normalized has no default value.
  alloc_real_array(&(_mag_normalized), 1, (_index_t)3); // _mag_normalized has no default value.
  alloc_real_array(&(_hE_quat), 1, (_index_t)4); // _hE_quat has no default value.
  alloc_real_array(&(_bE_quat), 1, (_index_t)4); // _bE_quat has no default value.
  alloc_real_array(&(_fb), 1, (_index_t)3); // _fb has no default value.
  alloc_real_array(&(_Jb), 2, (_index_t)4, (_index_t)3); // _Jb has no default value.
  alloc_real_array(&(_fg), 1, (_index_t)3); // _fg has no default value.
  alloc_real_array(&(_Jg), 2, (_index_t)4, (_index_t)3); // _Jg has no default value.
  alloc_real_array(&(_delta_f), 1, (_index_t)4); // _delta_f has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqdot), 1, (_index_t)4); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqdot has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERacc_5Fnormalized), 1, (_index_t)3); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERacc_5Fnormalized has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized), 1, (_index_t)3); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERhE_5Fquat), 1, (_index_t)4); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERhE_5Fquat has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat), 1, (_index_t)4); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb), 1, (_index_t)3); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb), 2, (_index_t)4, (_index_t)3); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg), 1, (_index_t)3); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg), 2, (_index_t)4, (_index_t)3); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg has no default value.
  alloc_real_array(&(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff), 1, (_index_t)4); // __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff has no default value.
  alloc_real_array(&(_qnew), 1, (_index_t)4); // _qnew has no default value.
  array_alloc_scalar_real_array(&tmp1, 4, (modelica_real)0.0, (modelica_real)_gx, (modelica_real)_gy, (modelica_real)_gz);
  real_array_copy_data(mul_alloc_real_array_scalar(omc_RoverExample_Utils_quatprod(threadData, _q0, tmp1), 0.5), _qdot);

  array_alloc_scalar_real_array(&tmp2, 4, (modelica_real)0.0, (modelica_real)_gx, (modelica_real)_gy, (modelica_real)_gz);
  array_alloc_scalar_real_array(&tmp3, 4, (modelica_real)0.0, (modelica_real)_gx, (modelica_real)_gy, (modelica_real)_gz);
  array_alloc_scalar_real_array(&tmp4, 4, (modelica_real)0.0, (modelica_real)_gx, (modelica_real)_gy, (modelica_real)_gz);
  array_alloc_scalar_real_array(&tmp5, 4, (modelica_real)0.0, (modelica_real)_gx, (modelica_real)_gy, (modelica_real)_gz);
  real_array_copy_data(mul_alloc_real_array_scalar(add_alloc_real_array(add_alloc_real_array(add_alloc_real_array(mul_alloc_real_array(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, _q0, tmp2, _OMC_LIT0, _OMC_LIT1)), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, _q0, tmp3, _OMC_LIT1, _OMC_LIT2), __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgx)), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, _q0, tmp4, _OMC_LIT1, _OMC_LIT3), __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgy)), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, _q0, tmp5, _OMC_LIT1, _OMC_LIT4), __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgz)), 0.5), __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqdot);

  tmp7 = _ax;
  tmp8 = _ay;
  tmp9 = _az;
  tmp10 = (tmp7 * tmp7) + (tmp8 * tmp8) + (tmp9 * tmp9);
  if(!(tmp10 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp10);
  }tmp11 = sqrt(tmp10) + 1e-15;
  if (tmp11 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "ax / (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15)");}
  tmp12 = _ax;
  tmp13 = _ay;
  tmp14 = _az;
  tmp15 = (tmp12 * tmp12) + (tmp13 * tmp13) + (tmp14 * tmp14);
  if(!(tmp15 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp15);
  }tmp16 = sqrt(tmp15) + 1e-15;
  if (tmp16 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "ay / (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15)");}
  tmp17 = _ax;
  tmp18 = _ay;
  tmp19 = _az;
  tmp20 = (tmp17 * tmp17) + (tmp18 * tmp18) + (tmp19 * tmp19);
  if(!(tmp20 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp20);
  }tmp21 = sqrt(tmp20) + 1e-15;
  if (tmp21 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "az / (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15)");}
  array_alloc_scalar_real_array(&tmp6, 3, (modelica_real)(_ax) / tmp11, (modelica_real)(_ay) / tmp16, (modelica_real)(_az) / tmp21);
  real_array_copy_data(tmp6, _acc_normalized);

  tmp23 = _ax;
  tmp24 = _ay;
  tmp25 = _az;
  tmp26 = (tmp23 * tmp23) + (tmp24 * tmp24) + (tmp25 * tmp25);
  if(!(tmp26 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp26);
  }tmp27 = _ax;
  tmp28 = _ay;
  tmp29 = _az;
  tmp30 = (tmp27 * tmp27) + (tmp28 * tmp28) + (tmp29 * tmp29);
  if(!(tmp30 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp30);
  }tmp31 = sqrt(tmp30);
  if (tmp31 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * ax * $RoverExample$PComponents$PMadgwickFusionStep$funDERax + 2.0 * ay * $RoverExample$PComponents$PMadgwickFusionStep$funDERay + 2.0 * az * $RoverExample$PComponents$PMadgwickFusionStep$funDERaz) / sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0)");}
  tmp32 = _ax;
  tmp33 = _ay;
  tmp34 = _az;
  tmp35 = (tmp32 * tmp32) + (tmp33 * tmp33) + (tmp34 * tmp34);
  if(!(tmp35 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp35);
  }tmp36 = sqrt(tmp35) + 1e-15;
  tmp37 = (tmp36 * tmp36);
  if (tmp37 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERax * (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15) - ax * 0.5 * (2.0 * ax * $RoverExample$PComponents$PMadgwickFusionStep$funDERax + 2.0 * ay * $RoverExample$PComponents$PMadgwickFusionStep$funDERay + 2.0 * az * $RoverExample$PComponents$PMadgwickFusionStep$funDERaz) / sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0)) / (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15) ^ 2.0");}
  tmp38 = _ax;
  tmp39 = _ay;
  tmp40 = _az;
  tmp41 = (tmp38 * tmp38) + (tmp39 * tmp39) + (tmp40 * tmp40);
  if(!(tmp41 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp41);
  }tmp42 = _ax;
  tmp43 = _ay;
  tmp44 = _az;
  tmp45 = (tmp42 * tmp42) + (tmp43 * tmp43) + (tmp44 * tmp44);
  if(!(tmp45 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp45);
  }tmp46 = sqrt(tmp45);
  if (tmp46 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * ax * $RoverExample$PComponents$PMadgwickFusionStep$funDERax + 2.0 * ay * $RoverExample$PComponents$PMadgwickFusionStep$funDERay + 2.0 * az * $RoverExample$PComponents$PMadgwickFusionStep$funDERaz) / sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0)");}
  tmp47 = _ax;
  tmp48 = _ay;
  tmp49 = _az;
  tmp50 = (tmp47 * tmp47) + (tmp48 * tmp48) + (tmp49 * tmp49);
  if(!(tmp50 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp50);
  }tmp51 = sqrt(tmp50) + 1e-15;
  tmp52 = (tmp51 * tmp51);
  if (tmp52 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERay * (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15) - ay * 0.5 * (2.0 * ax * $RoverExample$PComponents$PMadgwickFusionStep$funDERax + 2.0 * ay * $RoverExample$PComponents$PMadgwickFusionStep$funDERay + 2.0 * az * $RoverExample$PComponents$PMadgwickFusionStep$funDERaz) / sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0)) / (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15) ^ 2.0");}
  tmp53 = _ax;
  tmp54 = _ay;
  tmp55 = _az;
  tmp56 = (tmp53 * tmp53) + (tmp54 * tmp54) + (tmp55 * tmp55);
  if(!(tmp56 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp56);
  }tmp57 = _ax;
  tmp58 = _ay;
  tmp59 = _az;
  tmp60 = (tmp57 * tmp57) + (tmp58 * tmp58) + (tmp59 * tmp59);
  if(!(tmp60 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp60);
  }tmp61 = sqrt(tmp60);
  if (tmp61 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * ax * $RoverExample$PComponents$PMadgwickFusionStep$funDERax + 2.0 * ay * $RoverExample$PComponents$PMadgwickFusionStep$funDERay + 2.0 * az * $RoverExample$PComponents$PMadgwickFusionStep$funDERaz) / sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0)");}
  tmp62 = _ax;
  tmp63 = _ay;
  tmp64 = _az;
  tmp65 = (tmp62 * tmp62) + (tmp63 * tmp63) + (tmp64 * tmp64);
  if(!(tmp65 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp65);
  }tmp66 = sqrt(tmp65) + 1e-15;
  tmp67 = (tmp66 * tmp66);
  if (tmp67 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERaz * (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15) - az * 0.5 * (2.0 * ax * $RoverExample$PComponents$PMadgwickFusionStep$funDERax + 2.0 * ay * $RoverExample$PComponents$PMadgwickFusionStep$funDERay + 2.0 * az * $RoverExample$PComponents$PMadgwickFusionStep$funDERaz) / sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0)) / (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15) ^ 2.0");}
  array_alloc_scalar_real_array(&tmp22, 3, (modelica_real)((__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERax) * (sqrt(tmp26) + 1e-15) - ((_ax) * (((0.5) * (((2.0) * (_ax)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERax) + ((2.0) * (_ay)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERay) + ((2.0) * (_az)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERaz))) / tmp31))) / tmp37, (modelica_real)((__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERay) * (sqrt(tmp41) + 1e-15) - ((_ay) * (((0.5) * (((2.0) * (_ax)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERax) + ((2.0) * (_ay)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERay) + ((2.0) * (_az)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERaz))) / tmp46))) / tmp52, (modelica_real)((__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERaz) * (sqrt(tmp56) + 1e-15) - ((_az) * (((0.5) * (((2.0) * (_ax)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERax) + ((2.0) * (_ay)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERay) + ((2.0) * (_az)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERaz))) / tmp61))) / tmp67);
  real_array_copy_data(tmp22, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERacc_5Fnormalized);

  tmp69 = _mx;
  tmp70 = _my;
  tmp71 = _mz;
  tmp72 = (tmp69 * tmp69) + (tmp70 * tmp70) + (tmp71 * tmp71);
  if(!(tmp72 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp72);
  }tmp73 = sqrt(tmp72) + 1e-15;
  if (tmp73 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "mx / (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15)");}
  tmp74 = _mx;
  tmp75 = _my;
  tmp76 = _mz;
  tmp77 = (tmp74 * tmp74) + (tmp75 * tmp75) + (tmp76 * tmp76);
  if(!(tmp77 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp77);
  }tmp78 = sqrt(tmp77) + 1e-15;
  if (tmp78 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "my / (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15)");}
  tmp79 = _mx;
  tmp80 = _my;
  tmp81 = _mz;
  tmp82 = (tmp79 * tmp79) + (tmp80 * tmp80) + (tmp81 * tmp81);
  if(!(tmp82 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp82);
  }tmp83 = sqrt(tmp82) + 1e-15;
  if (tmp83 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "mz / (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15)");}
  array_alloc_scalar_real_array(&tmp68, 3, (modelica_real)(_mx) / tmp73, (modelica_real)(_my) / tmp78, (modelica_real)(_mz) / tmp83);
  real_array_copy_data(tmp68, _mag_normalized);

  tmp85 = _mx;
  tmp86 = _my;
  tmp87 = _mz;
  tmp88 = (tmp85 * tmp85) + (tmp86 * tmp86) + (tmp87 * tmp87);
  if(!(tmp88 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp88);
  }tmp89 = _mx;
  tmp90 = _my;
  tmp91 = _mz;
  tmp92 = (tmp89 * tmp89) + (tmp90 * tmp90) + (tmp91 * tmp91);
  if(!(tmp92 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp92);
  }tmp93 = sqrt(tmp92);
  if (tmp93 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * mx * $RoverExample$PComponents$PMadgwickFusionStep$funDERmx + 2.0 * my * $RoverExample$PComponents$PMadgwickFusionStep$funDERmy + 2.0 * mz * $RoverExample$PComponents$PMadgwickFusionStep$funDERmz) / sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0)");}
  tmp94 = _mx;
  tmp95 = _my;
  tmp96 = _mz;
  tmp97 = (tmp94 * tmp94) + (tmp95 * tmp95) + (tmp96 * tmp96);
  if(!(tmp97 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp97);
  }tmp98 = sqrt(tmp97) + 1e-15;
  tmp99 = (tmp98 * tmp98);
  if (tmp99 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERmx * (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15) - mx * 0.5 * (2.0 * mx * $RoverExample$PComponents$PMadgwickFusionStep$funDERmx + 2.0 * my * $RoverExample$PComponents$PMadgwickFusionStep$funDERmy + 2.0 * mz * $RoverExample$PComponents$PMadgwickFusionStep$funDERmz) / sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0)) / (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15) ^ 2.0");}
  tmp100 = _mx;
  tmp101 = _my;
  tmp102 = _mz;
  tmp103 = (tmp100 * tmp100) + (tmp101 * tmp101) + (tmp102 * tmp102);
  if(!(tmp103 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp103);
  }tmp104 = _mx;
  tmp105 = _my;
  tmp106 = _mz;
  tmp107 = (tmp104 * tmp104) + (tmp105 * tmp105) + (tmp106 * tmp106);
  if(!(tmp107 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp107);
  }tmp108 = sqrt(tmp107);
  if (tmp108 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * mx * $RoverExample$PComponents$PMadgwickFusionStep$funDERmx + 2.0 * my * $RoverExample$PComponents$PMadgwickFusionStep$funDERmy + 2.0 * mz * $RoverExample$PComponents$PMadgwickFusionStep$funDERmz) / sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0)");}
  tmp109 = _mx;
  tmp110 = _my;
  tmp111 = _mz;
  tmp112 = (tmp109 * tmp109) + (tmp110 * tmp110) + (tmp111 * tmp111);
  if(!(tmp112 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp112);
  }tmp113 = sqrt(tmp112) + 1e-15;
  tmp114 = (tmp113 * tmp113);
  if (tmp114 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERmy * (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15) - my * 0.5 * (2.0 * mx * $RoverExample$PComponents$PMadgwickFusionStep$funDERmx + 2.0 * my * $RoverExample$PComponents$PMadgwickFusionStep$funDERmy + 2.0 * mz * $RoverExample$PComponents$PMadgwickFusionStep$funDERmz) / sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0)) / (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15) ^ 2.0");}
  tmp115 = _mx;
  tmp116 = _my;
  tmp117 = _mz;
  tmp118 = (tmp115 * tmp115) + (tmp116 * tmp116) + (tmp117 * tmp117);
  if(!(tmp118 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp118);
  }tmp119 = _mx;
  tmp120 = _my;
  tmp121 = _mz;
  tmp122 = (tmp119 * tmp119) + (tmp120 * tmp120) + (tmp121 * tmp121);
  if(!(tmp122 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp122);
  }tmp123 = sqrt(tmp122);
  if (tmp123 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * mx * $RoverExample$PComponents$PMadgwickFusionStep$funDERmx + 2.0 * my * $RoverExample$PComponents$PMadgwickFusionStep$funDERmy + 2.0 * mz * $RoverExample$PComponents$PMadgwickFusionStep$funDERmz) / sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0)");}
  tmp124 = _mx;
  tmp125 = _my;
  tmp126 = _mz;
  tmp127 = (tmp124 * tmp124) + (tmp125 * tmp125) + (tmp126 * tmp126);
  if(!(tmp127 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp127);
  }tmp128 = sqrt(tmp127) + 1e-15;
  tmp129 = (tmp128 * tmp128);
  if (tmp129 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERmz * (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15) - mz * 0.5 * (2.0 * mx * $RoverExample$PComponents$PMadgwickFusionStep$funDERmx + 2.0 * my * $RoverExample$PComponents$PMadgwickFusionStep$funDERmy + 2.0 * mz * $RoverExample$PComponents$PMadgwickFusionStep$funDERmz) / sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0)) / (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15) ^ 2.0");}
  array_alloc_scalar_real_array(&tmp84, 3, (modelica_real)((__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmx) * (sqrt(tmp88) + 1e-15) - ((_mx) * (((0.5) * (((2.0) * (_mx)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmx) + ((2.0) * (_my)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmy) + ((2.0) * (_mz)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmz))) / tmp93))) / tmp99, (modelica_real)((__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmy) * (sqrt(tmp103) + 1e-15) - ((_my) * (((0.5) * (((2.0) * (_mx)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmx) + ((2.0) * (_my)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmy) + ((2.0) * (_mz)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmz))) / tmp108))) / tmp114, (modelica_real)((__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmz) * (sqrt(tmp118) + 1e-15) - ((_mz) * (((0.5) * (((2.0) * (_mx)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmx) + ((2.0) * (_my)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmy) + ((2.0) * (_mz)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmz))) / tmp123))) / tmp129);
  real_array_copy_data(tmp84, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized);

  array_alloc_scalar_real_array(&tmp130, 4, (modelica_real)0.0, (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  real_array_copy_data(omc_RoverExample_Utils_quatprod(threadData, omc_RoverExample_Utils_quatprod(threadData, _q0, tmp130), omc_RoverExample_Utils_quatinv(threadData, _q0)), _hE_quat);

  array_alloc_scalar_real_array(&tmp131, 4, (modelica_real)0.0, (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  array_alloc_scalar_real_array(&tmp132, 4, (modelica_real)0.0, (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  array_alloc_scalar_real_array(&tmp133, 4, (modelica_real)0.0, (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  array_alloc_scalar_real_array(&tmp134, 4, (modelica_real)0.0, (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  array_alloc_scalar_real_array(&tmp135, 4, (modelica_real)0.0, (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  array_alloc_scalar_real_array(&tmp136, 4, (modelica_real)0.0, (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  real_array_copy_data(add_alloc_real_array(mul_alloc_real_array(add_alloc_real_array(add_alloc_real_array(add_alloc_real_array(mul_alloc_real_array(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, _q0, tmp131, _OMC_LIT0, _OMC_LIT1)), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, _q0, tmp132, _OMC_LIT1, _OMC_LIT2), real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized, 1, ((modelica_integer) 1)))), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, _q0, tmp133, _OMC_LIT1, _OMC_LIT3), real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized, 1, ((modelica_integer) 2)))), mul_alloc_real_array_scalar(omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, _q0, tmp134, _OMC_LIT1, _OMC_LIT4), real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized, 1, ((modelica_integer) 3)))), omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, omc_RoverExample_Utils_quatprod(threadData, _q0, tmp135), omc_RoverExample_Utils_quatinv(threadData, _q0), _OMC_LIT0, _OMC_LIT1)), mul_alloc_real_array(mul_alloc_real_array(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatinv(threadData, _q0, _OMC_LIT0)), omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, omc_RoverExample_Utils_quatprod(threadData, _q0, tmp136), omc_RoverExample_Utils_quatinv(threadData, _q0), _OMC_LIT1, _OMC_LIT0))), __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERhE_5Fquat);

  tmp138 = real_array_get(_hE_quat, 1, ((modelica_integer) 2));
  tmp139 = real_array_get(_hE_quat, 1, ((modelica_integer) 3));
  tmp140 = (tmp138 * tmp138) + (tmp139 * tmp139);
  if(!(tmp140 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(hE_quat[2] ^ 2.0 + hE_quat[3] ^ 2.0) was %g should be >= 0", tmp140);
  }array_alloc_scalar_real_array(&tmp137, 4, (modelica_real)0.0, (modelica_real)sqrt(tmp140), (modelica_real)0.0, (modelica_real)real_array_get(_hE_quat, 1, ((modelica_integer) 4)));
  real_array_copy_data(tmp137, _bE_quat);

  tmp142 = real_array_get(_hE_quat, 1, ((modelica_integer) 2));
  tmp143 = real_array_get(_hE_quat, 1, ((modelica_integer) 3));
  tmp144 = (tmp142 * tmp142) + (tmp143 * tmp143);
  if(!(tmp144 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(hE_quat[2] ^ 2.0 + hE_quat[3] ^ 2.0) was %g should be >= 0", tmp144);
  }tmp145 = sqrt(tmp144);
  if (tmp145 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * hE_quat[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERhE_quat[2] + 2.0 * hE_quat[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERhE_quat[3]) / sqrt(hE_quat[2] ^ 2.0 + hE_quat[3] ^ 2.0)");}
  array_alloc_scalar_real_array(&tmp141, 4, (modelica_real)0.0, (modelica_real)((0.5) * (((2.0) * (real_array_get(_hE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERhE_5Fquat, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_hE_quat, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERhE_5Fquat, 1, ((modelica_integer) 3))))) / tmp145, (modelica_real)0.0, (modelica_real)real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERhE_5Fquat, 1, ((modelica_integer) 4)));
  real_array_copy_data(tmp141, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat);

  tmp147 = real_array_get(_q0, 1, ((modelica_integer) 3));
  tmp148 = real_array_get(_q0, 1, ((modelica_integer) 4));
  tmp149 = real_array_get(_q0, 1, ((modelica_integer) 2));
  tmp150 = real_array_get(_q0, 1, ((modelica_integer) 3));
  array_alloc_scalar_real_array(&tmp146, 3, (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (0.5 - ((tmp147 * tmp147)) - ((tmp148 * tmp148))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))))) - real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 4))))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + (real_array_get(_q0, 1, ((modelica_integer) 3))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) - real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) + (real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (0.5 - ((tmp149 * tmp149)) - ((tmp150 * tmp150))) - real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  real_array_copy_data(tmp146, _fb);

  tmp152 = real_array_get(_q0, 1, ((modelica_integer) 3));
  tmp153 = real_array_get(_q0, 1, ((modelica_integer) 4));
  tmp154 = real_array_get(_q0, 1, ((modelica_integer) 2));
  tmp155 = real_array_get(_q0, 1, ((modelica_integer) 3));
  array_alloc_scalar_real_array(&tmp151, 3, (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (((-2.0) * (real_array_get(_q0, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) - (((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (0.5 - ((tmp152 * tmp152)) - ((tmp153 * tmp153))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))))) - real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized, 1, ((modelica_integer) 1)), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 4))))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 4))))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + (real_array_get(_q0, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + (real_array_get(_q0, 1, ((modelica_integer) 3))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) - real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized, 1, ((modelica_integer) 2)), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) + (real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) + (real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (((-2.0) * (real_array_get(_q0, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) - (((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (0.5 - ((tmp154 * tmp154)) - ((tmp155 * tmp155))) - real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmag_5Fnormalized, 1, ((modelica_integer) 3)));
  real_array_copy_data(tmp151, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb);

  array_alloc_scalar_real_array(&tmp157, 3, (modelica_real)(-(((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) - (((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))));
  array_alloc_scalar_real_array(&tmp158, 3, (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 4))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 1))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - (((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 2)))));
  array_alloc_scalar_real_array(&tmp159, 3, (modelica_real)(-(((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 1))))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 4))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 1))) - (((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 3)))));
  array_alloc_scalar_real_array(&tmp160, 3, (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) - (((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) - (((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 1)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))));
  array_alloc_real_array(&tmp156, 4, tmp157, tmp158, tmp159, tmp160);
  real_array_copy_data(tmp156, _Jb);

  array_alloc_scalar_real_array(&tmp162, 3, (modelica_real)((-2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) - (((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 3)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) - (((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))));
  array_alloc_scalar_real_array(&tmp163, 3, (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 4))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 1))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - (((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) + ((4.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 2)))));
  array_alloc_scalar_real_array(&tmp164, 3, (modelica_real)((-4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) - (((4.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 3)))) + ((-2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) - (((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 1)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 4))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 1))) - (((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) + ((4.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 3)))));
  array_alloc_scalar_real_array(&tmp165, 3, (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) - (((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + ((4.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) - (((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 1)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbE_5Fquat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))));
  array_alloc_real_array(&tmp161, 4, tmp162, tmp163, tmp164, tmp165);
  real_array_copy_data(tmp161, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb);

  tmp167 = real_array_get(_q0, 1, ((modelica_integer) 2));
  tmp168 = real_array_get(_q0, 1, ((modelica_integer) 3));
  array_alloc_scalar_real_array(&tmp166, 3, (modelica_real)(-((2.0) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))))) + real_array_get(_acc_normalized, 1, ((modelica_integer) 1)))), (modelica_real)(-((2.0) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + (real_array_get(_q0, 1, ((modelica_integer) 3))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) + real_array_get(_acc_normalized, 1, ((modelica_integer) 2)))), (modelica_real)(-((2.0) * (0.5 - ((tmp167 * tmp167)) - ((tmp168 * tmp168))) + real_array_get(_acc_normalized, 1, ((modelica_integer) 3)))));
  real_array_copy_data(tmp166, _fg);

  array_alloc_scalar_real_array(&tmp169, 3, (modelica_real)(-2.0) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))))) - real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERacc_5Fnormalized, 1, ((modelica_integer) 1)), (modelica_real)(-2.0) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + (real_array_get(_q0, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) - real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERacc_5Fnormalized, 1, ((modelica_integer) 2)), (modelica_real)(-2.0) * (((-2.0) * (real_array_get(_q0, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))) - (((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))))) - real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERacc_5Fnormalized, 1, ((modelica_integer) 3)));
  real_array_copy_data(tmp169, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg);

  array_alloc_scalar_real_array(&tmp171, 3, (modelica_real)(2.0) * (real_array_get(_q0, 1, ((modelica_integer) 3))), (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 2))))), (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp172, 3, (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 4))))), (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 1))))), (modelica_real)(4.0) * (real_array_get(_q0, 1, ((modelica_integer) 2))));
  array_alloc_scalar_real_array(&tmp173, 3, (modelica_real)(2.0) * (real_array_get(_q0, 1, ((modelica_integer) 1))), (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 4))))), (modelica_real)(4.0) * (real_array_get(_q0, 1, ((modelica_integer) 3))));
  array_alloc_scalar_real_array(&tmp174, 3, (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 2))))), (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 3))))), (modelica_real)0.0);
  array_alloc_real_array(&tmp170, 4, tmp171, tmp172, tmp173, tmp174);
  real_array_copy_data(tmp170, _Jg);

  array_alloc_scalar_real_array(&tmp176, 3, (modelica_real)(2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))), (modelica_real)(-2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))), (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp177, 3, (modelica_real)(-2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))), (modelica_real)(-2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))), (modelica_real)(4.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))));
  array_alloc_scalar_real_array(&tmp178, 3, (modelica_real)(2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1))), (modelica_real)(-2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4))), (modelica_real)(4.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))));
  array_alloc_scalar_real_array(&tmp179, 3, (modelica_real)(-2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2))), (modelica_real)(-2.0) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3))), (modelica_real)0.0);
  array_alloc_real_array(&tmp175, 4, tmp176, tmp177, tmp178, tmp179);
  real_array_copy_data(tmp175, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg);

  array_alloc_scalar_real_array(&tmp180, 4, (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))), (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))), (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))), (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 4), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 4), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 4), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))));
  real_array_copy_data(tmp180, _delta_f);

  array_alloc_scalar_real_array(&tmp181, 4, (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 3))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))), (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 3))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))), (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 3), ((modelica_integer) 1))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 3), ((modelica_integer) 2))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 3))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 3), ((modelica_integer) 3))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))), (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 4), ((modelica_integer) 1))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 4), ((modelica_integer) 2))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfb, 1, ((modelica_integer) 3))) + ((_alpha) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJb, 2, ((modelica_integer) 4), ((modelica_integer) 3))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 4), ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 4), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 4), ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 4), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 4), ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERfg, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERJg, 2, ((modelica_integer) 4), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))));
  real_array_copy_data(tmp181, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff);

  tmp183 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp184 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp185 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp186 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp187 = (tmp183 * tmp183) + (tmp184 * tmp184) + (tmp185 * tmp185) + (tmp186 * tmp186);
  if(!(tmp187 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp187);
  }tmp188 = sqrt(tmp187) + 1e-15;
  if (tmp188 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[1] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp189 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp190 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp191 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp192 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp193 = (tmp189 * tmp189) + (tmp190 * tmp190) + (tmp191 * tmp191) + (tmp192 * tmp192);
  if(!(tmp193 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp193);
  }tmp194 = sqrt(tmp193) + 1e-15;
  if (tmp194 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[2] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp195 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp196 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp197 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp198 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp199 = (tmp195 * tmp195) + (tmp196 * tmp196) + (tmp197 * tmp197) + (tmp198 * tmp198);
  if(!(tmp199 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp199);
  }tmp200 = sqrt(tmp199) + 1e-15;
  if (tmp200 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[3] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp201 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp202 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp203 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp204 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp205 = (tmp201 * tmp201) + (tmp202 * tmp202) + (tmp203 * tmp203) + (tmp204 * tmp204);
  if(!(tmp205 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp205);
  }tmp206 = sqrt(tmp205) + 1e-15;
  if (tmp206 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[4] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  array_alloc_scalar_real_array(&tmp182, 4, (modelica_real)real_array_get(_q0, 1, ((modelica_integer) 1)) + (real_array_get(_qdot, 1, ((modelica_integer) 1)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 1)))) / tmp188)) * (_dt), (modelica_real)real_array_get(_q0, 1, ((modelica_integer) 2)) + (real_array_get(_qdot, 1, ((modelica_integer) 2)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 2)))) / tmp194)) * (_dt), (modelica_real)real_array_get(_q0, 1, ((modelica_integer) 3)) + (real_array_get(_qdot, 1, ((modelica_integer) 3)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 3)))) / tmp200)) * (_dt), (modelica_real)real_array_get(_q0, 1, ((modelica_integer) 4)) + (real_array_get(_qdot, 1, ((modelica_integer) 4)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 4)))) / tmp206)) * (_dt));
  real_array_copy_data(tmp182, _qnew);

  tmp208 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp209 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp210 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp211 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp212 = (tmp208 * tmp208) + (tmp209 * tmp209) + (tmp210 * tmp210) + (tmp211 * tmp211);
  if(!(tmp212 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp212);
  }tmp213 = sqrt(tmp212) + 1e-15;
  if (tmp213 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[1] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp214 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp215 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp216 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp217 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp218 = (tmp214 * tmp214) + (tmp215 * tmp215) + (tmp216 * tmp216) + (tmp217 * tmp217);
  if(!(tmp218 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp218);
  }tmp219 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp220 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp221 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp222 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp223 = (tmp219 * tmp219) + (tmp220 * tmp220) + (tmp221 * tmp221) + (tmp222 * tmp222);
  if(!(tmp223 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp223);
  }tmp224 = sqrt(tmp223);
  if (tmp224 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * delta_f[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[1] + 2.0 * delta_f[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[2] + 2.0 * delta_f[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[3] + 2.0 * delta_f[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[4]) / sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0)");}
  tmp225 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp226 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp227 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp228 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp229 = (tmp225 * tmp225) + (tmp226 * tmp226) + (tmp227 * tmp227) + (tmp228 * tmp228);
  if(!(tmp229 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp229);
  }tmp230 = sqrt(tmp229) + 1e-15;
  tmp231 = (tmp230 * tmp230);
  if (tmp231 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "((beta * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[1] + $RoverExample$PComponents$PMadgwickFusionStep$funDERbeta * delta_f[1]) * (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15) - beta * delta_f[1] * 0.5 * (2.0 * delta_f[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[1] + 2.0 * delta_f[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[2] + 2.0 * delta_f[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[3] + 2.0 * delta_f[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[4]) / sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0)) / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15) ^ 2.0");}
  tmp232 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp233 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp234 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp235 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp236 = (tmp232 * tmp232) + (tmp233 * tmp233) + (tmp234 * tmp234) + (tmp235 * tmp235);
  if(!(tmp236 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp236);
  }tmp237 = sqrt(tmp236) + 1e-15;
  if (tmp237 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[2] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp238 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp239 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp240 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp241 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp242 = (tmp238 * tmp238) + (tmp239 * tmp239) + (tmp240 * tmp240) + (tmp241 * tmp241);
  if(!(tmp242 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp242);
  }tmp243 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp244 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp245 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp246 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp247 = (tmp243 * tmp243) + (tmp244 * tmp244) + (tmp245 * tmp245) + (tmp246 * tmp246);
  if(!(tmp247 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp247);
  }tmp248 = sqrt(tmp247);
  if (tmp248 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * delta_f[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[1] + 2.0 * delta_f[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[2] + 2.0 * delta_f[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[3] + 2.0 * delta_f[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[4]) / sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0)");}
  tmp249 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp250 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp251 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp252 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp253 = (tmp249 * tmp249) + (tmp250 * tmp250) + (tmp251 * tmp251) + (tmp252 * tmp252);
  if(!(tmp253 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp253);
  }tmp254 = sqrt(tmp253) + 1e-15;
  tmp255 = (tmp254 * tmp254);
  if (tmp255 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "((beta * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[2] + $RoverExample$PComponents$PMadgwickFusionStep$funDERbeta * delta_f[2]) * (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15) - beta * delta_f[2] * 0.5 * (2.0 * delta_f[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[1] + 2.0 * delta_f[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[2] + 2.0 * delta_f[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[3] + 2.0 * delta_f[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[4]) / sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0)) / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15) ^ 2.0");}
  tmp256 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp257 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp258 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp259 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp260 = (tmp256 * tmp256) + (tmp257 * tmp257) + (tmp258 * tmp258) + (tmp259 * tmp259);
  if(!(tmp260 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp260);
  }tmp261 = sqrt(tmp260) + 1e-15;
  if (tmp261 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[3] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp262 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp263 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp264 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp265 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp266 = (tmp262 * tmp262) + (tmp263 * tmp263) + (tmp264 * tmp264) + (tmp265 * tmp265);
  if(!(tmp266 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp266);
  }tmp267 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp268 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp269 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp270 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp271 = (tmp267 * tmp267) + (tmp268 * tmp268) + (tmp269 * tmp269) + (tmp270 * tmp270);
  if(!(tmp271 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp271);
  }tmp272 = sqrt(tmp271);
  if (tmp272 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * delta_f[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[1] + 2.0 * delta_f[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[2] + 2.0 * delta_f[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[3] + 2.0 * delta_f[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[4]) / sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0)");}
  tmp273 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp274 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp275 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp276 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp277 = (tmp273 * tmp273) + (tmp274 * tmp274) + (tmp275 * tmp275) + (tmp276 * tmp276);
  if(!(tmp277 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp277);
  }tmp278 = sqrt(tmp277) + 1e-15;
  tmp279 = (tmp278 * tmp278);
  if (tmp279 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "((beta * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[3] + $RoverExample$PComponents$PMadgwickFusionStep$funDERbeta * delta_f[3]) * (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15) - beta * delta_f[3] * 0.5 * (2.0 * delta_f[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[1] + 2.0 * delta_f[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[2] + 2.0 * delta_f[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[3] + 2.0 * delta_f[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[4]) / sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0)) / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15) ^ 2.0");}
  tmp280 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp281 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp282 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp283 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp284 = (tmp280 * tmp280) + (tmp281 * tmp281) + (tmp282 * tmp282) + (tmp283 * tmp283);
  if(!(tmp284 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp284);
  }tmp285 = sqrt(tmp284) + 1e-15;
  if (tmp285 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[4] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp286 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp287 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp288 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp289 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp290 = (tmp286 * tmp286) + (tmp287 * tmp287) + (tmp288 * tmp288) + (tmp289 * tmp289);
  if(!(tmp290 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp290);
  }tmp291 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp292 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp293 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp294 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp295 = (tmp291 * tmp291) + (tmp292 * tmp292) + (tmp293 * tmp293) + (tmp294 * tmp294);
  if(!(tmp295 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp295);
  }tmp296 = sqrt(tmp295);
  if (tmp296 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * delta_f[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[1] + 2.0 * delta_f[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[2] + 2.0 * delta_f[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[3] + 2.0 * delta_f[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[4]) / sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0)");}
  tmp297 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp298 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp299 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp300 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp301 = (tmp297 * tmp297) + (tmp298 * tmp298) + (tmp299 * tmp299) + (tmp300 * tmp300);
  if(!(tmp301 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp301);
  }tmp302 = sqrt(tmp301) + 1e-15;
  tmp303 = (tmp302 * tmp302);
  if (tmp303 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "((beta * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[4] + $RoverExample$PComponents$PMadgwickFusionStep$funDERbeta * delta_f[4]) * (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15) - beta * delta_f[4] * 0.5 * (2.0 * delta_f[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[1] + 2.0 * delta_f[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[2] + 2.0 * delta_f[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[3] + 2.0 * delta_f[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERdelta_f[4]) / sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0)) / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15) ^ 2.0");}
  array_alloc_scalar_real_array(&tmp207, 4, (modelica_real)real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 1)) + (real_array_get(_qdot, 1, ((modelica_integer) 1)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 1)))) / tmp213)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdt) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqdot, 1, ((modelica_integer) 1)) - ((((_beta) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 1))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbeta) * (real_array_get(_delta_f, 1, ((modelica_integer) 1)))) * (sqrt(tmp218) + 1e-15) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 1)))) * (((0.5) * (((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 4))))) / tmp224))) / tmp231)) * (_dt), (modelica_real)real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 2)) + (real_array_get(_qdot, 1, ((modelica_integer) 2)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 2)))) / tmp237)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdt) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqdot, 1, ((modelica_integer) 2)) - ((((_beta) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 2))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbeta) * (real_array_get(_delta_f, 1, ((modelica_integer) 2)))) * (sqrt(tmp242) + 1e-15) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 2)))) * (((0.5) * (((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 4))))) / tmp248))) / tmp255)) * (_dt), (modelica_real)real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 3)) + (real_array_get(_qdot, 1, ((modelica_integer) 3)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 3)))) / tmp261)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdt) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqdot, 1, ((modelica_integer) 3)) - ((((_beta) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 3))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbeta) * (real_array_get(_delta_f, 1, ((modelica_integer) 3)))) * (sqrt(tmp266) + 1e-15) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 3)))) * (((0.5) * (((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 4))))) / tmp272))) / tmp279)) * (_dt), (modelica_real)real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, 1, ((modelica_integer) 4)) + (real_array_get(_qdot, 1, ((modelica_integer) 4)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 4)))) / tmp285)) * (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdt) + (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqdot, 1, ((modelica_integer) 4)) - ((((_beta) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 4))) + (__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbeta) * (real_array_get(_delta_f, 1, ((modelica_integer) 4)))) * (sqrt(tmp290) + 1e-15) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 4)))) * (((0.5) * (((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_delta_f, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdelta_5Ff, 1, ((modelica_integer) 4))))) / tmp296))) / tmp303)) * (_dt));
  real_array_copy_data(tmp207, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew);

  tmp305 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp306 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp307 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp308 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp309 = (tmp305 * tmp305) + (tmp306 * tmp306) + (tmp307 * tmp307) + (tmp308 * tmp308);
  if(!(tmp309 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp309);
  }tmp310 = sqrt(tmp309);
  if (tmp310 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "qnew[1] / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp311 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp312 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp313 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp314 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp315 = (tmp311 * tmp311) + (tmp312 * tmp312) + (tmp313 * tmp313) + (tmp314 * tmp314);
  if(!(tmp315 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp315);
  }tmp316 = sqrt(tmp315);
  if (tmp316 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "qnew[2] / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp317 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp318 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp319 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp320 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp321 = (tmp317 * tmp317) + (tmp318 * tmp318) + (tmp319 * tmp319) + (tmp320 * tmp320);
  if(!(tmp321 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp321);
  }tmp322 = sqrt(tmp321);
  if (tmp322 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "qnew[3] / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp323 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp324 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp325 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp326 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp327 = (tmp323 * tmp323) + (tmp324 * tmp324) + (tmp325 * tmp325) + (tmp326 * tmp326);
  if(!(tmp327 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp327);
  }tmp328 = sqrt(tmp327);
  if (tmp328 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "qnew[4] / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  array_alloc_scalar_real_array(&tmp304, 4, (modelica_real)(real_array_get(_qnew, 1, ((modelica_integer) 1))) / tmp310, (modelica_real)(real_array_get(_qnew, 1, ((modelica_integer) 2))) / tmp316, (modelica_real)(real_array_get(_qnew, 1, ((modelica_integer) 3))) / tmp322, (modelica_real)(real_array_get(_qnew, 1, ((modelica_integer) 4))) / tmp328);
  real_array_copy_data(tmp304, _qnew);

  tmp330 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp331 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp332 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp333 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp334 = (tmp330 * tmp330) + (tmp331 * tmp331) + (tmp332 * tmp332) + (tmp333 * tmp333);
  if(!(tmp334 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp334);
  }tmp335 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp336 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp337 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp338 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp339 = (tmp335 * tmp335) + (tmp336 * tmp336) + (tmp337 * tmp337) + (tmp338 * tmp338);
  if(!(tmp339 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp339);
  }tmp340 = sqrt(tmp339);
  if (tmp340 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * qnew[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[1] + 2.0 * qnew[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[2] + 2.0 * qnew[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[3] + 2.0 * qnew[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[4]) / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp341 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp342 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp343 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp344 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp345 = (tmp341 * tmp341) + (tmp342 * tmp342) + (tmp343 * tmp343) + (tmp344 * tmp344);
  if (tmp345 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[1] * sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) - qnew[1] * 0.5 * (2.0 * qnew[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[1] + 2.0 * qnew[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[2] + 2.0 * qnew[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[3] + 2.0 * qnew[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[4]) / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)) / (qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp346 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp347 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp348 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp349 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp350 = (tmp346 * tmp346) + (tmp347 * tmp347) + (tmp348 * tmp348) + (tmp349 * tmp349);
  if(!(tmp350 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp350);
  }tmp351 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp352 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp353 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp354 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp355 = (tmp351 * tmp351) + (tmp352 * tmp352) + (tmp353 * tmp353) + (tmp354 * tmp354);
  if(!(tmp355 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp355);
  }tmp356 = sqrt(tmp355);
  if (tmp356 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * qnew[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[1] + 2.0 * qnew[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[2] + 2.0 * qnew[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[3] + 2.0 * qnew[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[4]) / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp357 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp358 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp359 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp360 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp361 = (tmp357 * tmp357) + (tmp358 * tmp358) + (tmp359 * tmp359) + (tmp360 * tmp360);
  if (tmp361 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[2] * sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) - qnew[2] * 0.5 * (2.0 * qnew[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[1] + 2.0 * qnew[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[2] + 2.0 * qnew[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[3] + 2.0 * qnew[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[4]) / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)) / (qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp362 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp363 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp364 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp365 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp366 = (tmp362 * tmp362) + (tmp363 * tmp363) + (tmp364 * tmp364) + (tmp365 * tmp365);
  if(!(tmp366 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp366);
  }tmp367 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp368 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp369 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp370 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp371 = (tmp367 * tmp367) + (tmp368 * tmp368) + (tmp369 * tmp369) + (tmp370 * tmp370);
  if(!(tmp371 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp371);
  }tmp372 = sqrt(tmp371);
  if (tmp372 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * qnew[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[1] + 2.0 * qnew[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[2] + 2.0 * qnew[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[3] + 2.0 * qnew[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[4]) / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp373 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp374 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp375 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp376 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp377 = (tmp373 * tmp373) + (tmp374 * tmp374) + (tmp375 * tmp375) + (tmp376 * tmp376);
  if (tmp377 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[3] * sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) - qnew[3] * 0.5 * (2.0 * qnew[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[1] + 2.0 * qnew[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[2] + 2.0 * qnew[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[3] + 2.0 * qnew[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[4]) / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)) / (qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp378 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp379 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp380 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp381 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp382 = (tmp378 * tmp378) + (tmp379 * tmp379) + (tmp380 * tmp380) + (tmp381 * tmp381);
  if(!(tmp382 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp382);
  }tmp383 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp384 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp385 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp386 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp387 = (tmp383 * tmp383) + (tmp384 * tmp384) + (tmp385 * tmp385) + (tmp386 * tmp386);
  if(!(tmp387 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp387);
  }tmp388 = sqrt(tmp387);
  if (tmp388 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (2.0 * qnew[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[1] + 2.0 * qnew[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[2] + 2.0 * qnew[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[3] + 2.0 * qnew[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[4]) / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp389 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp390 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp391 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp392 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp393 = (tmp389 * tmp389) + (tmp390 * tmp390) + (tmp391 * tmp391) + (tmp392 * tmp392);
  if (tmp393 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "($RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[4] * sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) - qnew[4] * 0.5 * (2.0 * qnew[1] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[1] + 2.0 * qnew[2] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[2] + 2.0 * qnew[3] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[3] + 2.0 * qnew[4] * $RoverExample$PComponents$PMadgwickFusionStep$funDERqnew[4]) / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)) / (qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  array_alloc_scalar_real_array(&tmp329, 4, (modelica_real)((real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 1))) * (sqrt(tmp334)) - ((real_array_get(_qnew, 1, ((modelica_integer) 1))) * (((0.5) * (((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 4))))) / tmp340))) / tmp345, (modelica_real)((real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 2))) * (sqrt(tmp350)) - ((real_array_get(_qnew, 1, ((modelica_integer) 2))) * (((0.5) * (((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 4))))) / tmp356))) / tmp361, (modelica_real)((real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 3))) * (sqrt(tmp366)) - ((real_array_get(_qnew, 1, ((modelica_integer) 3))) * (((0.5) * (((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 4))))) / tmp372))) / tmp377, (modelica_real)((real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 4))) * (sqrt(tmp382)) - ((real_array_get(_qnew, 1, ((modelica_integer) 4))) * (((0.5) * (((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_qnew, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew, 1, ((modelica_integer) 4))))) / tmp388))) / tmp393);
  real_array_copy_data(tmp329, __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew);
  _return: OMC_LABEL_UNUSED
  return __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew;
}
modelica_metatype boxptr__omcQ_24DER_24RoverExample_24PComponents_24PMadgwickFusionStep(threadData_t *threadData, modelica_metatype _ax, modelica_metatype _ay, modelica_metatype _az, modelica_metatype _gx, modelica_metatype _gy, modelica_metatype _gz, modelica_metatype _mx, modelica_metatype _my, modelica_metatype _mz, modelica_metatype _q0, modelica_metatype _alpha, modelica_metatype _beta, modelica_metatype _dt, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERax, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERay, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERaz, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgx, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgy, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgz, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmx, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmy, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmz, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbeta, modelica_metatype __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdt)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  real_array __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew;
  modelica_metatype out__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew;
  tmp1 = mmc_unbox_real(_ax);
  tmp2 = mmc_unbox_real(_ay);
  tmp3 = mmc_unbox_real(_az);
  tmp4 = mmc_unbox_real(_gx);
  tmp5 = mmc_unbox_real(_gy);
  tmp6 = mmc_unbox_real(_gz);
  tmp7 = mmc_unbox_real(_mx);
  tmp8 = mmc_unbox_real(_my);
  tmp9 = mmc_unbox_real(_mz);
  tmp10 = mmc_unbox_real(_alpha);
  tmp11 = mmc_unbox_real(_beta);
  tmp12 = mmc_unbox_real(_dt);
  tmp13 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERax);
  tmp14 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERay);
  tmp15 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERaz);
  tmp16 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgx);
  tmp17 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgy);
  tmp18 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERgz);
  tmp19 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmx);
  tmp20 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmy);
  tmp21 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERmz);
  tmp22 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERalpha);
  tmp23 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERbeta);
  tmp24 = mmc_unbox_real(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERdt);
  __omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew = omc__omcQ_24DER_24RoverExample_24PComponents_24PMadgwickFusionStep(threadData, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9, *((base_array_t*)_q0), tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, *((base_array_t*)__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERq0), tmp22, tmp23, tmp24);
  out__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew = mmc_mk_modelica_array(__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew);
  return out__omcQ_24RoverExample_24PComponents_24PMadgwickFusionStep_24funDERqnew;
}

DLLDirection
real_array omc__omcQ_24DER_24RoverExample_24PUtils_24Pquat2eul(threadData_t *threadData, real_array _q, real_array __omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq)
{
  real_array __omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler;
  real_array _euler;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_boolean tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_real tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_real tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  modelica_boolean tmp39;
  modelica_real tmp40;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler), 1, (_index_t)3); // __omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler has no default value.
  alloc_real_array(&(_euler), 1, (_index_t)3); // _euler has no default value.
  tmp1 = real_array_get(_q, 1, ((modelica_integer) 1));
  tmp2 = real_array_get(_q, 1, ((modelica_integer) 4));
  real_array_get(_euler, 1, ((modelica_integer) 1)) = atan2(((2.0) * (real_array_get(_q, 1, ((modelica_integer) 3)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 2))), (2.0) * ((tmp1 * tmp1)) + (2.0) * ((tmp2 * tmp2)) - 1.0);

  tmp3 = real_array_get(_q, 1, ((modelica_integer) 1));
  tmp4 = real_array_get(_q, 1, ((modelica_integer) 4));
  tmp17 = (modelica_boolean)((2.0) * ((tmp3 * tmp3) + (tmp4 * tmp4)) - 1.0 == 0.0);
  if(tmp17)
  {
    tmp5 = real_array_get(_q, 1, ((modelica_integer) 1));
    tmp6 = real_array_get(_q, 1, ((modelica_integer) 4));
    tmp18 = (2.0) * ((tmp5 * tmp5) + (tmp6 * tmp6)) - 1.0;
  }
  else
  {
    tmp7 = real_array_get(_q, 1, ((modelica_integer) 1));
    tmp8 = real_array_get(_q, 1, ((modelica_integer) 4));
    tmp9 = real_array_get(_q, 1, ((modelica_integer) 1));
    tmp10 = real_array_get(_q, 1, ((modelica_integer) 4));
    tmp11 = (2.0) * ((tmp9 * tmp9) + (tmp10 * tmp10)) - 1.0;
    tmp12 = real_array_get(_q, 1, ((modelica_integer) 1));
    tmp13 = real_array_get(_q, 1, ((modelica_integer) 4));
    tmp14 = (2.0) * ((tmp12 * tmp12) + (tmp13 * tmp13)) - 1.0;
    if (tmp14 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(2.0 * q[3] * q[4] + 2.0 * q[1] * q[2]) / (2.0 * (q[1] ^ 2.0 + q[4] ^ 2.0) - 1.0)");}
    tmp15 = (((2.0) * (real_array_get(_q, 1, ((modelica_integer) 3)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 2)))) / tmp14;
    tmp16 = ((tmp11 * tmp11)) * (1.0 + (tmp15 * tmp15));
    if (tmp16 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "((2.0 * q[3] * $RoverExample$PUtils$Pquat2eul$funDERq[4] + 2.0 * $RoverExample$PUtils$Pquat2eul$funDERq[3] * q[4] + 2.0 * q[1] * $RoverExample$PUtils$Pquat2eul$funDERq[2] + 2.0 * $RoverExample$PUtils$Pquat2eul$funDERq[1] * q[2]) * (2.0 * (q[1] ^ 2.0 + q[4] ^ 2.0) - 1.0) - (2.0 * q[3] * q[4] + 2.0 * q[1] * q[2]) * 2.0 * (2.0 * q[1] * $RoverExample$PUtils$Pquat2eul$funDERq[1] + 2.0 * q[4] * $RoverExample$PUtils$Pquat2eul$funDERq[4])) / ((2.0 * (q[1] ^ 2.0 + q[4] ^ 2.0) - 1.0) ^ 2.0 * (1.0 + ((2.0 * q[3] * q[4] + 2.0 * q[1] * q[2]) / (2.0 * (q[1] ^ 2.0 + q[4] ^ 2.0) - 1.0)) ^ 2.0))");}
    tmp18 = ((((2.0) * (real_array_get(_q, 1, ((modelica_integer) 3)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 3)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * ((2.0) * ((tmp7 * tmp7) + (tmp8 * tmp8)) - 1.0) - ((((2.0) * (real_array_get(_q, 1, ((modelica_integer) 3)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * ((2.0) * (((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 4))))))) / tmp16;
  }
  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler, 1, ((modelica_integer) 1)) = tmp18;

  tmp19 = ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - (((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 3))));
  if(!(tmp19 >= -1.0 && tmp19 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of asin(2.0 * q[2] * q[4] - 2.0 * q[1] * q[3]) outside the domain -1.0 <= %g <= 1.0", tmp19);
  }
  real_array_get(_euler, 1, ((modelica_integer) 2)) = (-asin(tmp19));

  tmp20 = ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - (((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 3))));
  tmp21 = 1.0 - ((tmp20 * tmp20));
  if(!(tmp21 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(1.0 - (2.0 * q[2] * q[4] - 2.0 * q[1] * q[3]) ^ 2.0) was %g should be >= 0", tmp21);
  }tmp22 = sqrt(tmp21);
  if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(2.0 * q[1] * $RoverExample$PUtils$Pquat2eul$funDERq[3] + 2.0 * $RoverExample$PUtils$Pquat2eul$funDERq[1] * q[3] + (-2.0) * (q[2] * $RoverExample$PUtils$Pquat2eul$funDERq[4] + $RoverExample$PUtils$Pquat2eul$funDERq[2] * q[4])) / sqrt(1.0 - (2.0 * q[2] * q[4] - 2.0 * q[1] * q[3]) ^ 2.0)");}
  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler, 1, ((modelica_integer) 2)) = ((2.0) * ((real_array_get(_q, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 3)))) + (2.0) * ((real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 1))) * (real_array_get(_q, 1, ((modelica_integer) 3)))) + (-2.0) * ((real_array_get(_q, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 2))) * (real_array_get(_q, 1, ((modelica_integer) 4))))) / tmp22;

  tmp23 = real_array_get(_q, 1, ((modelica_integer) 1));
  tmp24 = real_array_get(_q, 1, ((modelica_integer) 2));
  real_array_get(_euler, 1, ((modelica_integer) 3)) = atan2(((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 4))), (2.0) * ((tmp23 * tmp23)) + (2.0) * ((tmp24 * tmp24)) - 1.0);

  tmp25 = real_array_get(_q, 1, ((modelica_integer) 1));
  tmp26 = real_array_get(_q, 1, ((modelica_integer) 2));
  tmp39 = (modelica_boolean)((2.0) * ((tmp25 * tmp25) + (tmp26 * tmp26)) - 1.0 == 0.0);
  if(tmp39)
  {
    tmp27 = real_array_get(_q, 1, ((modelica_integer) 1));
    tmp28 = real_array_get(_q, 1, ((modelica_integer) 2));
    tmp40 = (2.0) * ((tmp27 * tmp27) + (tmp28 * tmp28)) - 1.0;
  }
  else
  {
    tmp29 = real_array_get(_q, 1, ((modelica_integer) 1));
    tmp30 = real_array_get(_q, 1, ((modelica_integer) 2));
    tmp31 = real_array_get(_q, 1, ((modelica_integer) 1));
    tmp32 = real_array_get(_q, 1, ((modelica_integer) 2));
    tmp33 = (2.0) * ((tmp31 * tmp31) + (tmp32 * tmp32)) - 1.0;
    tmp34 = real_array_get(_q, 1, ((modelica_integer) 1));
    tmp35 = real_array_get(_q, 1, ((modelica_integer) 2));
    tmp36 = (2.0) * ((tmp34 * tmp34) + (tmp35 * tmp35)) - 1.0;
    if (tmp36 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(2.0 * q[2] * q[3] + 2.0 * q[1] * q[4]) / (2.0 * (q[1] ^ 2.0 + q[2] ^ 2.0) - 1.0)");}
    tmp37 = (((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 4)))) / tmp36;
    tmp38 = ((tmp33 * tmp33)) * (1.0 + (tmp37 * tmp37));
    if (tmp38 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "((2.0 * q[2] * $RoverExample$PUtils$Pquat2eul$funDERq[3] + 2.0 * $RoverExample$PUtils$Pquat2eul$funDERq[2] * q[3] + 2.0 * q[1] * $RoverExample$PUtils$Pquat2eul$funDERq[4] + 2.0 * $RoverExample$PUtils$Pquat2eul$funDERq[1] * q[4]) * (2.0 * (q[1] ^ 2.0 + q[2] ^ 2.0) - 1.0) - (2.0 * q[2] * q[3] + 2.0 * q[1] * q[4]) * 2.0 * (2.0 * q[1] * $RoverExample$PUtils$Pquat2eul$funDERq[1] + 2.0 * q[2] * $RoverExample$PUtils$Pquat2eul$funDERq[2])) / ((2.0 * (q[1] ^ 2.0 + q[2] ^ 2.0) - 1.0) ^ 2.0 * (1.0 + ((2.0 * q[2] * q[3] + 2.0 * q[1] * q[4]) / (2.0 * (q[1] ^ 2.0 + q[2] ^ 2.0) - 1.0)) ^ 2.0))");}
    tmp40 = ((((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 4)))) * ((2.0) * ((tmp29 * tmp29) + (tmp30 * tmp30)) - 1.0) - ((((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 4)))) * ((2.0) * (((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 1))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq, 1, ((modelica_integer) 2))))))) / tmp38;
  }
  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler, 1, ((modelica_integer) 3)) = tmp40;
  _return: OMC_LABEL_UNUSED
  return __omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler;
}
modelica_metatype boxptr__omcQ_24DER_24RoverExample_24PUtils_24Pquat2eul(threadData_t *threadData, modelica_metatype _q, modelica_metatype __omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq)
{
  real_array __omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler;
  modelica_metatype out__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler;
  __omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler = omc__omcQ_24DER_24RoverExample_24PUtils_24Pquat2eul(threadData, *((base_array_t*)_q), *((base_array_t*)__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDERq));
  out__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler = mmc_mk_modelica_array(__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler);
  return out__omcQ_24RoverExample_24PUtils_24Pquat2eul_24funDEReuler;
}

DLLDirection
real_array omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatinv(threadData_t *threadData, real_array _q_in, real_array __omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fin)
{
  real_array __omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout;
  real_array _q_out;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout), 1, (_index_t)4); // __omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout has no default value.
  alloc_real_array(&(_q_out), 1, (_index_t)4); // _q_out has no default value.
  real_array_get(_q_out, 1, ((modelica_integer) 1)) = real_array_get(_q_in, 1, ((modelica_integer) 1));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout, 1, ((modelica_integer) 1)) = real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fin, 1, ((modelica_integer) 1));

  real_array_get(_q_out, 1, ((modelica_integer) 2)) = (-real_array_get(_q_in, 1, ((modelica_integer) 2)));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout, 1, ((modelica_integer) 2)) = (-real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fin, 1, ((modelica_integer) 2)));

  real_array_get(_q_out, 1, ((modelica_integer) 3)) = (-real_array_get(_q_in, 1, ((modelica_integer) 3)));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout, 1, ((modelica_integer) 3)) = (-real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fin, 1, ((modelica_integer) 3)));

  real_array_get(_q_out, 1, ((modelica_integer) 4)) = (-real_array_get(_q_in, 1, ((modelica_integer) 4)));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout, 1, ((modelica_integer) 4)) = (-real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fin, 1, ((modelica_integer) 4)));
  _return: OMC_LABEL_UNUSED
  return __omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout;
}
modelica_metatype boxptr__omcQ_24DER_24RoverExample_24PUtils_24Pquatinv(threadData_t *threadData, modelica_metatype _q_in, modelica_metatype __omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fin)
{
  real_array __omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout;
  modelica_metatype out__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout;
  __omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout = omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatinv(threadData, *((base_array_t*)_q_in), *((base_array_t*)__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fin));
  out__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout = mmc_mk_modelica_array(__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout);
  return out__omcQ_24RoverExample_24PUtils_24Pquatinv_24funDERq_5Fout;
}

DLLDirection
real_array omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData_t *threadData, real_array _q_in1, real_array _q_in2, real_array __omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, real_array __omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2)
{
  real_array __omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout;
  real_array _q_out;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout), 1, (_index_t)4); // __omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout has no default value.
  alloc_real_array(&(_q_out), 1, (_index_t)4); // _q_out has no default value.
  real_array_get(_q_out, 1, ((modelica_integer) 1)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout, 1, ((modelica_integer) 1)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + ((-real_array_get(_q_in1, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 4))) - ((real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4)))) - ((real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 3)))) - ((real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 2))));

  real_array_get(_q_out, 1, ((modelica_integer) 2)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout, 1, ((modelica_integer) 2)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) + ((-real_array_get(_q_in1, 1, ((modelica_integer) 4)))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 3))) - ((real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))));

  real_array_get(_q_out, 1, ((modelica_integer) 3)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4)))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout, 1, ((modelica_integer) 3)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) + (real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 2))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2))) - ((real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 4))));

  real_array_get(_q_out, 1, ((modelica_integer) 4)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1)));

  real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout, 1, ((modelica_integer) 4)) = (real_array_get(_q_in1, 1, ((modelica_integer) 1))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 4))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 1))) * (real_array_get(_q_in2, 1, ((modelica_integer) 4))) + (real_array_get(_q_in1, 1, ((modelica_integer) 2))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 3))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 2))) * (real_array_get(_q_in2, 1, ((modelica_integer) 3))) + (real_array_get(_q_in1, 1, ((modelica_integer) 4))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 1))) + (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 4))) * (real_array_get(_q_in2, 1, ((modelica_integer) 1))) - ((real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, 1, ((modelica_integer) 3))) * (real_array_get(_q_in2, 1, ((modelica_integer) 2)))) - ((real_array_get(_q_in1, 1, ((modelica_integer) 3))) * (real_array_get(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2, 1, ((modelica_integer) 2))));
  _return: OMC_LABEL_UNUSED
  return __omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout;
}
modelica_metatype boxptr__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData_t *threadData, modelica_metatype _q_in1, modelica_metatype _q_in2, modelica_metatype __omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1, modelica_metatype __omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2)
{
  real_array __omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout;
  modelica_metatype out__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout;
  __omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout = omc__omcQ_24DER_24RoverExample_24PUtils_24Pquatprod(threadData, *((base_array_t*)_q_in1), *((base_array_t*)_q_in2), *((base_array_t*)__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin1), *((base_array_t*)__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fin2));
  out__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout = mmc_mk_modelica_array(__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout);
  return out__omcQ_24RoverExample_24PUtils_24Pquatprod_24funDERq_5Fout;
}

DLLDirection
real_array omc_RoverExample_Components_MadgwickFusionStep(threadData_t *threadData, modelica_real _ax, modelica_real _ay, modelica_real _az, modelica_real _gx, modelica_real _gy, modelica_real _gz, modelica_real _mx, modelica_real _my, modelica_real _mz, real_array _q0, modelica_real _alpha, modelica_real _beta, modelica_real _dt)
{
  real_array _qnew;
  real_array _qdot;
  real_array _acc_normalized;
  real_array _mag_normalized;
  real_array _hE_quat;
  real_array _bE_quat;
  real_array _fb;
  real_array _Jb;
  real_array _fg;
  real_array _Jg;
  real_array _delta_f;
  real_array tmp1;
  real_array tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  real_array tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_real tmp33;
  real_array tmp34;
  real_array tmp35;
  modelica_real tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  real_array tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  modelica_real tmp42;
  modelica_real tmp43;
  real_array tmp44;
  real_array tmp45;
  real_array tmp46;
  real_array tmp47;
  real_array tmp48;
  real_array tmp49;
  modelica_real tmp50;
  modelica_real tmp51;
  real_array tmp52;
  real_array tmp53;
  real_array tmp54;
  real_array tmp55;
  real_array tmp56;
  real_array tmp57;
  real_array tmp58;
  modelica_real tmp59;
  modelica_real tmp60;
  modelica_real tmp61;
  modelica_real tmp62;
  modelica_real tmp63;
  modelica_real tmp64;
  modelica_real tmp65;
  modelica_real tmp66;
  modelica_real tmp67;
  modelica_real tmp68;
  modelica_real tmp69;
  modelica_real tmp70;
  modelica_real tmp71;
  modelica_real tmp72;
  modelica_real tmp73;
  modelica_real tmp74;
  modelica_real tmp75;
  modelica_real tmp76;
  modelica_real tmp77;
  modelica_real tmp78;
  modelica_real tmp79;
  modelica_real tmp80;
  modelica_real tmp81;
  modelica_real tmp82;
  real_array tmp83;
  modelica_real tmp84;
  modelica_real tmp85;
  modelica_real tmp86;
  modelica_real tmp87;
  modelica_real tmp88;
  modelica_real tmp89;
  modelica_real tmp90;
  modelica_real tmp91;
  modelica_real tmp92;
  modelica_real tmp93;
  modelica_real tmp94;
  modelica_real tmp95;
  modelica_real tmp96;
  modelica_real tmp97;
  modelica_real tmp98;
  modelica_real tmp99;
  modelica_real tmp100;
  modelica_real tmp101;
  modelica_real tmp102;
  modelica_real tmp103;
  modelica_real tmp104;
  modelica_real tmp105;
  modelica_real tmp106;
  modelica_real tmp107;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_qnew), 1, (_index_t)4); // _qnew has no default value.
  alloc_real_array(&(_qdot), 1, (_index_t)4); // _qdot has no default value.
  alloc_real_array(&(_acc_normalized), 1, (_index_t)3); // _acc_normalized has no default value.
  alloc_real_array(&(_mag_normalized), 1, (_index_t)3); // _mag_normalized has no default value.
  alloc_real_array(&(_hE_quat), 1, (_index_t)4); // _hE_quat has no default value.
  alloc_real_array(&(_bE_quat), 1, (_index_t)4); // _bE_quat has no default value.
  alloc_real_array(&(_fb), 1, (_index_t)3); // _fb has no default value.
  alloc_real_array(&(_Jb), 2, (_index_t)4, (_index_t)3); // _Jb has no default value.
  alloc_real_array(&(_fg), 1, (_index_t)3); // _fg has no default value.
  alloc_real_array(&(_Jg), 2, (_index_t)4, (_index_t)3); // _Jg has no default value.
  alloc_real_array(&(_delta_f), 1, (_index_t)4); // _delta_f has no default value.
  array_alloc_scalar_real_array(&tmp1, 4, (modelica_real)0.0, (modelica_real)_gx, (modelica_real)_gy, (modelica_real)_gz);
  real_array_copy_data(mul_alloc_real_array_scalar(omc_RoverExample_Utils_quatprod(threadData, _q0, tmp1), 0.5), _qdot);

  tmp3 = _ax;
  tmp4 = _ay;
  tmp5 = _az;
  tmp6 = (tmp3 * tmp3) + (tmp4 * tmp4) + (tmp5 * tmp5);
  if(!(tmp6 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp6);
  }tmp7 = sqrt(tmp6) + 1e-15;
  if (tmp7 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "ax / (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15)");}
  tmp8 = _ax;
  tmp9 = _ay;
  tmp10 = _az;
  tmp11 = (tmp8 * tmp8) + (tmp9 * tmp9) + (tmp10 * tmp10);
  if(!(tmp11 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp11);
  }tmp12 = sqrt(tmp11) + 1e-15;
  if (tmp12 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "ay / (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15)");}
  tmp13 = _ax;
  tmp14 = _ay;
  tmp15 = _az;
  tmp16 = (tmp13 * tmp13) + (tmp14 * tmp14) + (tmp15 * tmp15);
  if(!(tmp16 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) was %g should be >= 0", tmp16);
  }tmp17 = sqrt(tmp16) + 1e-15;
  if (tmp17 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "az / (sqrt(ax ^ 2.0 + ay ^ 2.0 + az ^ 2.0) + 1e-15)");}
  array_alloc_scalar_real_array(&tmp2, 3, (modelica_real)(_ax) / tmp7, (modelica_real)(_ay) / tmp12, (modelica_real)(_az) / tmp17);
  real_array_copy_data(tmp2, _acc_normalized);

  tmp19 = _mx;
  tmp20 = _my;
  tmp21 = _mz;
  tmp22 = (tmp19 * tmp19) + (tmp20 * tmp20) + (tmp21 * tmp21);
  if(!(tmp22 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp22);
  }tmp23 = sqrt(tmp22) + 1e-15;
  if (tmp23 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "mx / (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15)");}
  tmp24 = _mx;
  tmp25 = _my;
  tmp26 = _mz;
  tmp27 = (tmp24 * tmp24) + (tmp25 * tmp25) + (tmp26 * tmp26);
  if(!(tmp27 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp27);
  }tmp28 = sqrt(tmp27) + 1e-15;
  if (tmp28 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "my / (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15)");}
  tmp29 = _mx;
  tmp30 = _my;
  tmp31 = _mz;
  tmp32 = (tmp29 * tmp29) + (tmp30 * tmp30) + (tmp31 * tmp31);
  if(!(tmp32 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) was %g should be >= 0", tmp32);
  }tmp33 = sqrt(tmp32) + 1e-15;
  if (tmp33 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "mz / (sqrt(mx ^ 2.0 + my ^ 2.0 + mz ^ 2.0) + 1e-15)");}
  array_alloc_scalar_real_array(&tmp18, 3, (modelica_real)(_mx) / tmp23, (modelica_real)(_my) / tmp28, (modelica_real)(_mz) / tmp33);
  real_array_copy_data(tmp18, _mag_normalized);

  array_alloc_scalar_real_array(&tmp34, 4, (modelica_real)0.0, (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  real_array_copy_data(omc_RoverExample_Utils_quatprod(threadData, omc_RoverExample_Utils_quatprod(threadData, _q0, tmp34), omc_RoverExample_Utils_quatinv(threadData, _q0)), _hE_quat);

  tmp36 = real_array_get(_hE_quat, 1, ((modelica_integer) 2));
  tmp37 = real_array_get(_hE_quat, 1, ((modelica_integer) 3));
  tmp38 = (tmp36 * tmp36) + (tmp37 * tmp37);
  if(!(tmp38 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(hE_quat[2] ^ 2.0 + hE_quat[3] ^ 2.0) was %g should be >= 0", tmp38);
  }array_alloc_scalar_real_array(&tmp35, 4, (modelica_real)0.0, (modelica_real)sqrt(tmp38), (modelica_real)0.0, (modelica_real)real_array_get(_hE_quat, 1, ((modelica_integer) 4)));
  real_array_copy_data(tmp35, _bE_quat);

  tmp40 = real_array_get(_q0, 1, ((modelica_integer) 3));
  tmp41 = real_array_get(_q0, 1, ((modelica_integer) 4));
  tmp42 = real_array_get(_q0, 1, ((modelica_integer) 2));
  tmp43 = real_array_get(_q0, 1, ((modelica_integer) 3));
  array_alloc_scalar_real_array(&tmp39, 3, (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (0.5 - ((tmp40 * tmp40)) - ((tmp41 * tmp41))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))))) - real_array_get(_mag_normalized, 1, ((modelica_integer) 1)), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 4))))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + (real_array_get(_q0, 1, ((modelica_integer) 3))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) - real_array_get(_mag_normalized, 1, ((modelica_integer) 2)), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) + (real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (0.5 - ((tmp42 * tmp42)) - ((tmp43 * tmp43))) - real_array_get(_mag_normalized, 1, ((modelica_integer) 3)));
  real_array_copy_data(tmp39, _fb);

  array_alloc_scalar_real_array(&tmp45, 3, (modelica_real)(-(((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) - (((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))));
  array_alloc_scalar_real_array(&tmp46, 3, (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 4))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 1))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - (((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 2)))));
  array_alloc_scalar_real_array(&tmp47, 3, (modelica_real)(-(((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 1))))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + ((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 4))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 1))) - (((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 3)))));
  array_alloc_scalar_real_array(&tmp48, 3, (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) - (((4.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 4)))) * (real_array_get(_q0, 1, ((modelica_integer) 3))) - (((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 1)))), (modelica_real)((2.0) * (real_array_get(_bE_quat, 1, ((modelica_integer) 2)))) * (real_array_get(_q0, 1, ((modelica_integer) 2))));
  array_alloc_real_array(&tmp44, 4, tmp45, tmp46, tmp47, tmp48);
  real_array_copy_data(tmp44, _Jb);

  tmp50 = real_array_get(_q0, 1, ((modelica_integer) 2));
  tmp51 = real_array_get(_q0, 1, ((modelica_integer) 3));
  array_alloc_scalar_real_array(&tmp49, 3, (modelica_real)(-((2.0) * ((real_array_get(_q0, 1, ((modelica_integer) 2))) * (real_array_get(_q0, 1, ((modelica_integer) 4))) - ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 3))))) + real_array_get(_acc_normalized, 1, ((modelica_integer) 1)))), (modelica_real)(-((2.0) * ((real_array_get(_q0, 1, ((modelica_integer) 1))) * (real_array_get(_q0, 1, ((modelica_integer) 2))) + (real_array_get(_q0, 1, ((modelica_integer) 3))) * (real_array_get(_q0, 1, ((modelica_integer) 4)))) + real_array_get(_acc_normalized, 1, ((modelica_integer) 2)))), (modelica_real)(-((2.0) * (0.5 - ((tmp50 * tmp50)) - ((tmp51 * tmp51))) + real_array_get(_acc_normalized, 1, ((modelica_integer) 3)))));
  real_array_copy_data(tmp49, _fg);

  array_alloc_scalar_real_array(&tmp53, 3, (modelica_real)(2.0) * (real_array_get(_q0, 1, ((modelica_integer) 3))), (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 2))))), (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp54, 3, (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 4))))), (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 1))))), (modelica_real)(4.0) * (real_array_get(_q0, 1, ((modelica_integer) 2))));
  array_alloc_scalar_real_array(&tmp55, 3, (modelica_real)(2.0) * (real_array_get(_q0, 1, ((modelica_integer) 1))), (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 4))))), (modelica_real)(4.0) * (real_array_get(_q0, 1, ((modelica_integer) 3))));
  array_alloc_scalar_real_array(&tmp56, 3, (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 2))))), (modelica_real)(-((2.0) * (real_array_get(_q0, 1, ((modelica_integer) 3))))), (modelica_real)0.0);
  array_alloc_real_array(&tmp52, 4, tmp53, tmp54, tmp55, tmp56);
  real_array_copy_data(tmp52, _Jg);

  array_alloc_scalar_real_array(&tmp57, 4, (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 1), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))), (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 2), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))), (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))), (modelica_real)((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 1)))) * (real_array_get(_fb, 1, ((modelica_integer) 1))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 2)))) * (real_array_get(_fb, 1, ((modelica_integer) 2))) + ((_alpha) * (real_array_get(_Jb, 2, ((modelica_integer) 4), ((modelica_integer) 3)))) * (real_array_get(_fb, 1, ((modelica_integer) 3))) + (real_array_get(_Jg, 2, ((modelica_integer) 4), ((modelica_integer) 1))) * (real_array_get(_fg, 1, ((modelica_integer) 1))) + (real_array_get(_Jg, 2, ((modelica_integer) 4), ((modelica_integer) 2))) * (real_array_get(_fg, 1, ((modelica_integer) 2))) + (real_array_get(_Jg, 2, ((modelica_integer) 4), ((modelica_integer) 3))) * (real_array_get(_fg, 1, ((modelica_integer) 3))));
  real_array_copy_data(tmp57, _delta_f);

  tmp59 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp60 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp61 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp62 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp63 = (tmp59 * tmp59) + (tmp60 * tmp60) + (tmp61 * tmp61) + (tmp62 * tmp62);
  if(!(tmp63 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp63);
  }tmp64 = sqrt(tmp63) + 1e-15;
  if (tmp64 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[1] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp65 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp66 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp67 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp68 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp69 = (tmp65 * tmp65) + (tmp66 * tmp66) + (tmp67 * tmp67) + (tmp68 * tmp68);
  if(!(tmp69 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp69);
  }tmp70 = sqrt(tmp69) + 1e-15;
  if (tmp70 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[2] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp71 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp72 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp73 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp74 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp75 = (tmp71 * tmp71) + (tmp72 * tmp72) + (tmp73 * tmp73) + (tmp74 * tmp74);
  if(!(tmp75 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp75);
  }tmp76 = sqrt(tmp75) + 1e-15;
  if (tmp76 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[3] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  tmp77 = real_array_get(_delta_f, 1, ((modelica_integer) 1));
  tmp78 = real_array_get(_delta_f, 1, ((modelica_integer) 2));
  tmp79 = real_array_get(_delta_f, 1, ((modelica_integer) 3));
  tmp80 = real_array_get(_delta_f, 1, ((modelica_integer) 4));
  tmp81 = (tmp77 * tmp77) + (tmp78 * tmp78) + (tmp79 * tmp79) + (tmp80 * tmp80);
  if(!(tmp81 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) was %g should be >= 0", tmp81);
  }tmp82 = sqrt(tmp81) + 1e-15;
  if (tmp82 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "beta * delta_f[4] / (sqrt(delta_f[1] ^ 2.0 + delta_f[2] ^ 2.0 + delta_f[3] ^ 2.0 + delta_f[4] ^ 2.0) + 1e-15)");}
  array_alloc_scalar_real_array(&tmp58, 4, (modelica_real)real_array_get(_q0, 1, ((modelica_integer) 1)) + (real_array_get(_qdot, 1, ((modelica_integer) 1)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 1)))) / tmp64)) * (_dt), (modelica_real)real_array_get(_q0, 1, ((modelica_integer) 2)) + (real_array_get(_qdot, 1, ((modelica_integer) 2)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 2)))) / tmp70)) * (_dt), (modelica_real)real_array_get(_q0, 1, ((modelica_integer) 3)) + (real_array_get(_qdot, 1, ((modelica_integer) 3)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 3)))) / tmp76)) * (_dt), (modelica_real)real_array_get(_q0, 1, ((modelica_integer) 4)) + (real_array_get(_qdot, 1, ((modelica_integer) 4)) - (((_beta) * (real_array_get(_delta_f, 1, ((modelica_integer) 4)))) / tmp82)) * (_dt));
  real_array_copy_data(tmp58, _qnew);

  tmp84 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp85 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp86 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp87 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp88 = (tmp84 * tmp84) + (tmp85 * tmp85) + (tmp86 * tmp86) + (tmp87 * tmp87);
  if(!(tmp88 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp88);
  }tmp89 = sqrt(tmp88);
  if (tmp89 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "qnew[1] / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp90 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp91 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp92 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp93 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp94 = (tmp90 * tmp90) + (tmp91 * tmp91) + (tmp92 * tmp92) + (tmp93 * tmp93);
  if(!(tmp94 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp94);
  }tmp95 = sqrt(tmp94);
  if (tmp95 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "qnew[2] / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp96 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp97 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp98 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp99 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp100 = (tmp96 * tmp96) + (tmp97 * tmp97) + (tmp98 * tmp98) + (tmp99 * tmp99);
  if(!(tmp100 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp100);
  }tmp101 = sqrt(tmp100);
  if (tmp101 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "qnew[3] / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  tmp102 = real_array_get(_qnew, 1, ((modelica_integer) 1));
  tmp103 = real_array_get(_qnew, 1, ((modelica_integer) 2));
  tmp104 = real_array_get(_qnew, 1, ((modelica_integer) 3));
  tmp105 = real_array_get(_qnew, 1, ((modelica_integer) 4));
  tmp106 = (tmp102 * tmp102) + (tmp103 * tmp103) + (tmp104 * tmp104) + (tmp105 * tmp105);
  if(!(tmp106 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0) was %g should be >= 0", tmp106);
  }tmp107 = sqrt(tmp106);
  if (tmp107 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "qnew[4] / sqrt(qnew[1] ^ 2.0 + qnew[2] ^ 2.0 + qnew[3] ^ 2.0 + qnew[4] ^ 2.0)");}
  array_alloc_scalar_real_array(&tmp83, 4, (modelica_real)(real_array_get(_qnew, 1, ((modelica_integer) 1))) / tmp89, (modelica_real)(real_array_get(_qnew, 1, ((modelica_integer) 2))) / tmp95, (modelica_real)(real_array_get(_qnew, 1, ((modelica_integer) 3))) / tmp101, (modelica_real)(real_array_get(_qnew, 1, ((modelica_integer) 4))) / tmp107);
  real_array_copy_data(tmp83, _qnew);
  _return: OMC_LABEL_UNUSED
  return _qnew;
}
modelica_metatype boxptr_RoverExample_Components_MadgwickFusionStep(threadData_t *threadData, modelica_metatype _ax, modelica_metatype _ay, modelica_metatype _az, modelica_metatype _gx, modelica_metatype _gy, modelica_metatype _gz, modelica_metatype _mx, modelica_metatype _my, modelica_metatype _mz, modelica_metatype _q0, modelica_metatype _alpha, modelica_metatype _beta, modelica_metatype _dt)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  real_array _qnew;
  modelica_metatype out_qnew;
  tmp1 = mmc_unbox_real(_ax);
  tmp2 = mmc_unbox_real(_ay);
  tmp3 = mmc_unbox_real(_az);
  tmp4 = mmc_unbox_real(_gx);
  tmp5 = mmc_unbox_real(_gy);
  tmp6 = mmc_unbox_real(_gz);
  tmp7 = mmc_unbox_real(_mx);
  tmp8 = mmc_unbox_real(_my);
  tmp9 = mmc_unbox_real(_mz);
  tmp10 = mmc_unbox_real(_alpha);
  tmp11 = mmc_unbox_real(_beta);
  tmp12 = mmc_unbox_real(_dt);
  _qnew = omc_RoverExample_Components_MadgwickFusionStep(threadData, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9, *((base_array_t*)_q0), tmp10, tmp11, tmp12);
  out_qnew = mmc_mk_modelica_array(_qnew);
  return out_qnew;
}

DLLDirection
real_array omc_RoverExample_Utils_quat2eul(threadData_t *threadData, real_array _q)
{
  real_array _euler;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_euler), 1, (_index_t)3); // _euler has no default value.
  tmp1 = real_array_get(_q, 1, ((modelica_integer) 1));
  tmp2 = real_array_get(_q, 1, ((modelica_integer) 4));
  real_array_get(_euler, 1, ((modelica_integer) 1)) = atan2(((2.0) * (real_array_get(_q, 1, ((modelica_integer) 3)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 2))), (2.0) * ((tmp1 * tmp1)) + (2.0) * ((tmp2 * tmp2)) - 1.0);

  tmp3 = ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 4))) - (((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 3))));
  if(!(tmp3 >= -1.0 && tmp3 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of asin(2.0 * q[2] * q[4] - 2.0 * q[1] * q[3]) outside the domain -1.0 <= %g <= 1.0", tmp3);
  }
  real_array_get(_euler, 1, ((modelica_integer) 2)) = (-asin(tmp3));

  tmp4 = real_array_get(_q, 1, ((modelica_integer) 1));
  tmp5 = real_array_get(_q, 1, ((modelica_integer) 2));
  real_array_get(_euler, 1, ((modelica_integer) 3)) = atan2(((2.0) * (real_array_get(_q, 1, ((modelica_integer) 2)))) * (real_array_get(_q, 1, ((modelica_integer) 3))) + ((2.0) * (real_array_get(_q, 1, ((modelica_integer) 1)))) * (real_array_get(_q, 1, ((modelica_integer) 4))), (2.0) * ((tmp4 * tmp4)) + (2.0) * ((tmp5 * tmp5)) - 1.0);
  _return: OMC_LABEL_UNUSED
  return _euler;
}
modelica_metatype boxptr_RoverExample_Utils_quat2eul(threadData_t *threadData, modelica_metatype _q)
{
  real_array _euler;
  modelica_metatype out_euler;
  _euler = omc_RoverExample_Utils_quat2eul(threadData, *((base_array_t*)_q));
  out_euler = mmc_mk_modelica_array(_euler);
  return out_euler;
}

DLLDirection
real_array omc_RoverExample_Utils_quatinv(threadData_t *threadData, real_array _q_in)
{
  real_array _q_out;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_q_out), 1, (_index_t)4); // _q_out has no default value.
  real_array_get(_q_out, 1, ((modelica_integer) 1)) = real_array_get(_q_in, 1, ((modelica_integer) 1));

  real_array_get(_q_out, 1, ((modelica_integer) 2)) = (-real_array_get(_q_in, 1, ((modelica_integer) 2)));

  real_array_get(_q_out, 1, ((modelica_integer) 3)) = (-real_array_get(_q_in, 1, ((modelica_integer) 3)));

  real_array_get(_q_out, 1, ((modelica_integer) 4)) = (-real_array_get(_q_in, 1, ((modelica_integer) 4)));
  _return: OMC_LABEL_UNUSED
  return _q_out;
}
modelica_metatype boxptr_RoverExample_Utils_quatinv(threadData_t *threadData, modelica_metatype _q_in)
{
  real_array _q_out;
  modelica_metatype out_q_out;
  _q_out = omc_RoverExample_Utils_quatinv(threadData, *((base_array_t*)_q_in));
  out_q_out = mmc_mk_modelica_array(_q_out);
  return out_q_out;
}

DLLDirection
real_array omc_RoverExample_Utils_quatprod(threadData_t *threadData, real_array _q_in1, real_array _q_in2)
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
modelica_metatype boxptr_RoverExample_Utils_quatprod(threadData_t *threadData, modelica_metatype _q_in1, modelica_metatype _q_in2)
{
  real_array _q_out;
  modelica_metatype out_q_out;
  _q_out = omc_RoverExample_Utils_quatprod(threadData, *((base_array_t*)_q_in1), *((base_array_t*)_q_in2));
  out_q_out = mmc_mk_modelica_array(_q_out);
  return out_q_out;
}

#ifdef __cplusplus
}
#endif
