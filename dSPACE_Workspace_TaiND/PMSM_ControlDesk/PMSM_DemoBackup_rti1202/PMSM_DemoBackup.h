/*
 * PMSM_DemoBackup.h
 *
 * Code generation for model "PMSM_DemoBackup".
 *
 * Model version              : 1.532
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue May  7 13:37:16 2024
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMSM_DemoBackup_h_
#define RTW_HEADER_PMSM_DemoBackup_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef PMSM_DemoBackup_COMMON_INCLUDES_
# define PMSM_DemoBackup_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* PMSM_DemoBackup_COMMON_INCLUDES_ */

#include "PMSM_DemoBackup_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Choose_ref_value_i;           /* '<S6>/Choose_reference_Value_iq' */
  real_T Choose_ref_value_n;           /* '<S6>/Choose_reference_Value_n' */
  real_T Sig_gen_n;                    /* '<S6>/Sig_gen_n' */
  real_T ref_value_n;                  /* '<S6>/Multiport Switch' */
  real_T Sig_gen_iq;                   /* '<S6>/Sig_gen_iq' */
  real_T Sine_wave_ref_iq;             /* '<S6>/Sine_wave_ref_iq' */
  real_T ref_value_iq;                 /* '<S6>/Multiport Switch1' */
  real_T sim_time;                     /* '<S6>/Digital Clock' */
  real_T Gain;                         /* '<S6>/Gain' */
  real_T clock[6];                     /* '<S1>/clock' */
  real_T Sig_gen_n_i;                  /* '<S6>/Rate Transition' */
  real_T Choose_ref_value_n_g;         /* '<S6>/Rate Transition' */
  real_T ref_value_n_o;                /* '<S6>/Rate Transition' */
  real_T load_machine_ref;             /* '<S6>/Rate Transition' */
  real_T Choose_ref_value_i_m;         /* '<S6>/Rate Transition' */
  real_T ref_value_iq_i;               /* '<S6>/Rate Transition' */
  real_T Memory;                       /* '<S150>/Memory' */
  real_T Sum;                          /* '<S150>/Sum' */
  real_T Switch;                       /* '<S150>/Switch' */
  real_T Switch1;                      /* '<S150>/Switch1' */
  real_T Product;                      /* '<S150>/Product' */
  real_T DataTypeConversion;           /* '<S137>/Data Type Conversion' */
  real_T Product_k;                    /* '<S137>/Product' */
  real_T Product1;                     /* '<S137>/Product1' */
  real_T Product2;                     /* '<S137>/Product2' */
  real_T Sum_f;                        /* '<S137>/Sum' */
  real_T Saturation;                   /* '<S137>/Saturation' */
  real_T Sum1;                         /* '<S137>/Sum1' */
  real_T Saturation1;                  /* '<S137>/Saturation1' */
  real_T Sum2;                         /* '<S137>/Sum2' */
  real_T Saturation2;                  /* '<S137>/Saturation2' */
  real_T Ki_iq;                        /* '<S137>/Ki_iq' */
  real_T Kp_iq;                        /* '<S137>/Kp_iq' */
  real_T Vel_Src;                      /* '<S137>/Vel_Src' */
  real_T load_torque;                  /* '<S137>/load_torque' */
  real_T SFunction1_o1;                /* '<S120>/S-Function1' */
  real_T VoltageADC1V;                 /* '<S109>/Gain13' */
  real_T voltamp_i_a;                  /* '<S109>/volt->amp_i_a           ' */
  real_T currentPhaseAA;               /* '<S109>/Sum9' */
  real_T SFunction1_o1_i;              /* '<S124>/S-Function1' */
  real_T VoltageADC5V;                 /* '<S109>/Gain17' */
  real_T voltamp_i_b;                  /* '<S109>/volt->amp_i_b' */
  real_T currentPhaseBA;               /* '<S109>/Sum10' */
  real_T SFunction1_o1_g;              /* '<S126>/S-Function1' */
  real_T VoltageADC7V;                 /* '<S109>/Gain18' */
  real_T voltamp_i_c;                  /* '<S109>/volt->amp_i_c' */
  real_T currentPhaseCA;               /* '<S109>/Sum11' */
  real_T TmpSignalConversionAtGain1Inpor[3];/* '<S59>/Demux' */
  real_T Gain1[2];                     /* '<S60>/Gain1' */
  real_T Gain5[2];                     /* '<S135>/Gain5' */
  real_T UnitDelay1;                   /* '<S47>/Unit Delay1' */
  real_T UnitDelay2;                   /* '<S50>/Unit Delay2' */
  real_T Switch1_o;                    /* '<S47>/Switch1' */
  real_T UnitDelay;                    /* '<S37>/Unit Delay' */
  real_T Gain1_m[2];                   /* '<S59>/Gain1' */
  real_T SFunction1_o1_f;              /* '<S112>/S-Function1' */
  real_T SFunction1_o2;                /* '<S112>/S-Function1' */
  real_T SFunction1_o3;                /* '<S112>/S-Function1' */
  real_T Gain3;                        /* '<S119>/Gain3' */
  real_T Sum_k;                        /* '<S119>/Sum' */
  real_T Inc_elec_pos;                 /* '<S119>/Math Function' */
  real_T inc_valid;                    /* '<S12>/bool2double' */
  real_T SFunction1_o1_d;              /* '<S113>/S-Function1' */
  real_T Switch_n;                     /* '<S117>/Switch' */
  real_T SFunction1_o1_k;              /* '<S114>/S-Function1' */
  real_T SFunction1_o2_f;              /* '<S114>/S-Function1' */
  real_T Switch_e;                     /* '<S116>/Switch' */
  real_T MultiportSwitch1;             /* '<S12>/Multiport Switch1' */
  real_T to_rad;                       /* '<S12>/to_rad' */
  real_T Sum_e;                        /* '<S28>/Sum' */
  real_T MathFunction1;                /* '<S36>/Math Function1' */
  real_T cos_m;                        /* '<S59>/cos' */
  real_T Product1_d;                   /* '<S59>/Product1' */
  real_T sin_c;                        /* '<S59>/sin' */
  real_T Product2_n;                   /* '<S59>/Product2' */
  real_T Sum1_j;                       /* '<S59>/Sum1' */
  real_T Proportional;                 /* '<S37>/Proportional' */
  real_T Sum_j;                        /* '<S37>/Sum' */
  real_T Product_i;                    /* '<S47>/Product' */
  real_T UnitDelay_m;                  /* '<S47>/Unit Delay' */
  real_T Switch2;                      /* '<S47>/Switch2' */
  real_T Add;                          /* '<S47>/Add' */
  real_T Switch_d;                     /* '<S49>/Switch' */
  real_T Switch2_a;                    /* '<S49>/Switch2' */
  real_T uFilterTime;                  /* '<S37>/1|FilterTime' */
  real_T UnitDelay1_h;                 /* '<S61>/Unit Delay1' */
  real_T apu_vel;                      /* '<S12>/Gain' */
  real_T MultiportSwitch;              /* '<S12>/Multiport Switch' */
  real_T Memory_j;                     /* '<S25>/Memory' */
  real_T Memory1;                      /* '<S25>/Memory1' */
  real_T Memory2;                      /* '<S25>/Memory2' */
  real_T Memory3;                      /* '<S25>/Memory3' */
  real_T Sum_p;                        /* '<S25>/Sum' */
  real_T Gain_p;                       /* '<S25>/Gain' */
  real_T Kp_n_Cor;                     /* '<S9>/Kp_n_Cor' */
  real_T Ki_n_Cor;                     /* '<S9>/Ki_n_Cor' */
  real_T Gain3_p;                      /* '<S30>/Gain3' */
  real_T MultiportSwitch_e[2];         /* '<S30>/Multiport Switch' */
  real_T inv;                          /* '<S69>/inv' */
  real_T Switch_a;                     /* '<S71>/Switch' */
  real_T Switch2_j;                    /* '<S71>/Switch2' */
  real_T factor_id;                    /* '<S45>/factor_id' */
  real_T MultiportSwitch_b;            /* '<S45>/Multiport Switch' */
  real_T Gain3_e[2];                   /* '<S135>/Gain3' */
  real_T UnitDelay1_n;                 /* '<S53>/Unit Delay1' */
  real_T UnitDelay2_k;                 /* '<S56>/Unit Delay2' */
  real_T Switch1_j;                    /* '<S53>/Switch1' */
  real_T UnitDelay_f;                  /* '<S38>/Unit Delay' */
  real_T inv_k;                        /* '<S59>/inv' */
  real_T Product3;                     /* '<S59>/Product3' */
  real_T Product4;                     /* '<S59>/Product4' */
  real_T Sum_i;                        /* '<S59>/Sum' */
  real_T Proportional_g;               /* '<S38>/Proportional' */
  real_T Sum_pj;                       /* '<S38>/Sum' */
  real_T Product_m;                    /* '<S53>/Product' */
  real_T UnitDelay_o;                  /* '<S53>/Unit Delay' */
  real_T Switch2_e;                    /* '<S53>/Switch2' */
  real_T Add_g;                        /* '<S53>/Add' */
  real_T Switch_m;                     /* '<S55>/Switch' */
  real_T Switch2_d;                    /* '<S55>/Switch2' */
  real_T uFilterTime_m;                /* '<S38>/1|FilterTime' */
  real_T Gain1_h;                      /* '<S29>/Gain1' */
  real_T UnitDelay2_g;                 /* '<S61>/Unit Delay2' */
  real_T inv_h;                        /* '<S70>/inv' */
  real_T Switch_i;                     /* '<S72>/Switch' */
  real_T Switch2_b;                    /* '<S72>/Switch2' */
  real_T factor_id_e;                  /* '<S46>/factor_id' */
  real_T MultiportSwitch_a;            /* '<S46>/Multiport Switch' */
  real_T Gain3_a;                      /* '<S29>/Gain3' */
  real_T Gain4[2];                     /* '<S135>/Gain4' */
  real_T UnitDelay1_m;                 /* '<S128>/Unit Delay1' */
  real_T UnitDelay2_m;                 /* '<S131>/Unit Delay2' */
  real_T Switch1_f;                    /* '<S128>/Switch1' */
  real_T UnitDelay_fg;                 /* '<S110>/Unit Delay' */
  real_T SFunction1_o1_j;              /* '<S122>/S-Function1' */
  real_T VoltageADC3V;                 /* '<S109>/Gain15' */
  real_T Battery_VoltageV;             /* '<S109>/Gain9' */
  real_T Proportional_j;               /* '<S110>/Proportional' */
  real_T Sum_g;                        /* '<S110>/Sum' */
  real_T Product_e;                    /* '<S128>/Product' */
  real_T UnitDelay_d;                  /* '<S128>/Unit Delay' */
  real_T Switch2_m;                    /* '<S128>/Switch2' */
  real_T Add_b;                        /* '<S128>/Add' */
  real_T Switch_g;                     /* '<S130>/Switch' */
  real_T Switch2_p;                    /* '<S130>/Switch2' */
  real_T uFilterTime_g;                /* '<S110>/1|FilterTime' */
  real_T MinMax;                       /* '<S44>/MinMax' */
  real_T LimitingFactor;               /* '<S44>/LimitingFactor' */
  real_T Kp_i_Cor;                     /* '<S9>/Kp_i_Cor' */
  real_T error;                        /* '<S39>/Sum1' */
  real_T Product1_b;                   /* '<S39>/Product1' */
  real_T Ki_i_Cor;                     /* '<S9>/Ki_i_Cor' */
  real_T Product2_k;                   /* '<S39>/Product2' */
  real_T integral;                     /* '<S39>/Product' */
  real_T UnitDelay_i;                  /* '<S39>/Unit Delay' */
  real_T Sum_jb;                       /* '<S39>/Sum' */
  real_T Product2_g;                   /* '<S28>/Product2' */
  real_T toRads;                       /* '<S28>/toRad|s' */
  real_T Product_eb;                   /* '<S64>/Product' */
  real_T Const_LsdH;                   /* '<S64>/Const_Lsd[H]' */
  real_T Sum3;                         /* '<S64>/Sum3' */
  real_T inv_ho;                       /* '<S62>/inv' */
  real_T Switch_dr;                    /* '<S67>/Switch' */
  real_T Switch2_a3;                   /* '<S67>/Switch2' */
  real_T MathFunction1_n;              /* '<S44>/Math Function1' */
  real_T MathFunction;                 /* '<S44>/Math Function' */
  real_T Add_a;                        /* '<S44>/Add' */
  real_T MathFunction2;                /* '<S44>/Math Function2' */
  real_T error_a;                      /* '<S40>/Sum1' */
  real_T Product1_c;                   /* '<S40>/Product1' */
  real_T Product2_b;                   /* '<S40>/Product2' */
  real_T integral_p;                   /* '<S40>/Product' */
  real_T UnitDelay_l;                  /* '<S40>/Unit Delay' */
  real_T Sum_a;                        /* '<S40>/Sum' */
  real_T Product1_p;                   /* '<S64>/Product1' */
  real_T Const_LsqH;                   /* '<S64>/Const_Lsq[H]' */
  real_T Sum1_f;                       /* '<S64>/Sum1' */
  real_T Const_PsiWb;                  /* '<S64>/Const_Psi[Wb]' */
  real_T Sum4;                         /* '<S64>/Sum4' */
  real_T inv_e;                        /* '<S63>/inv' */
  real_T Switch_ii;                    /* '<S68>/Switch' */
  real_T Switch2_n;                    /* '<S68>/Switch2' */
  real_T UnitDelay1_f;                 /* '<S96>/Unit Delay1' */
  real_T UnitDelay2_p;                 /* '<S101>/Unit Delay2' */
  real_T Switch1_d;                    /* '<S96>/Switch1' */
  real_T torpm;                        /* '<S92>/torpm' */
  real_T Gain_l;                       /* '<S98>/Gain' */
  real_T Product_kx;                   /* '<S96>/Product' */
  real_T UnitDelay_j;                  /* '<S96>/Unit Delay' */
  real_T Switch2_f;                    /* '<S96>/Switch2' */
  real_T Add_ag;                       /* '<S96>/Add' */
  real_T Switch_l;                     /* '<S100>/Switch' */
  real_T Switch2_p2;                   /* '<S100>/Switch2' */
  real_T MathFunction1_i;              /* '<S97>/Math Function1' */
  real_T MultiportSwitch_h[3];         /* '<S32>/Multiport Switch' */
  real_T cos_i;                        /* '<S104>/cos' */
  real_T Product1_g;                   /* '<S104>/Product1' */
  real_T sin_k;                        /* '<S104>/sin' */
  real_T inv_p;                        /* '<S104>/inv' */
  real_T Product2_m;                   /* '<S104>/Product2' */
  real_T Sum1_e;                       /* '<S104>/Sum1' */
  real_T Gain1_k;                      /* '<S105>/Gain1' */
  real_T Gain2;                        /* '<S105>/Gain2' */
  real_T Product3_l;                   /* '<S104>/Product3' */
  real_T Product4_m;                   /* '<S104>/Product4' */
  real_T Sum_m;                        /* '<S104>/Sum' */
  real_T Gain3_k;                      /* '<S105>/Gain3' */
  real_T Sum_n;                        /* '<S105>/Sum' */
  real_T Sum1_i;                       /* '<S105>/Sum1' */
  real_T Product_ko[3];                /* '<S23>/Product' */
  real_T Min;                          /* '<S23>/Min' */
  real_T Max;                          /* '<S23>/Max' */
  real_T Sum_mb;                       /* '<S23>/Sum' */
  real_T Sum4_k;                       /* '<S23>/Sum4' */
  real_T half;                         /* '<S23>/half' */
  real_T Sum2_l[3];                    /* '<S23>/Sum2' */
  real_T Saturation_m[3];              /* '<S23>/Saturation' */
  real_T Gain6[3];                     /* '<S135>/Gain6' */
  real_T Sum3_i[3];                    /* '<S23>/Sum3' */
  real_T Gain7[3];                     /* '<S135>/Gain7' */
  real_T Gain16;                       /* '<S135>/Gain16' */
  real_T Gain17;                       /* '<S135>/Gain17' */
  real_T Gain10[2];                    /* '<S135>/Gain10' */
  real_T Gain8[3];                     /* '<S135>/Gain8' */
  real_T Product_ew;                   /* '<S65>/Product' */
  real_T Const_LsdH_e;                 /* '<S65>/Const_Lsd[H]' */
  real_T Sum3_b;                       /* '<S65>/Sum3' */
  real_T Gain1_c[3];                   /* '<S135>/Gain1' */
  real_T Product1_k;                   /* '<S65>/Product1' */
  real_T Const_LsqH_a;                 /* '<S65>/Const_Lsq[H]' */
  real_T Sum1_fm;                      /* '<S65>/Sum1' */
  real_T Const_PsiWb_k;                /* '<S65>/Const_Psi[Wb]' */
  real_T Sum4_c;                       /* '<S65>/Sum4' */
  real_T Gain2_l[3];                   /* '<S135>/Gain2' */
  real_T Plotter_trigger_var;          /* '<S135>/Switch' */
  real_T Gain15;                       /* '<S135>/Gain15' */
  real_T Gain9[3];                     /* '<S135>/Gain9' */
  real_T Switch_nv[3];                 /* '<S13>/Switch' */
  real_T Product1_dq;                  /* '<S28>/Product1' */
  real_T Sum2_h;                       /* '<S39>/Sum2' */
  real_T Sum2_ll;                      /* '<S40>/Sum2' */
  real_T MathFunction3;                /* '<S61>/Math Function3' */
  real_T MathFunction4;                /* '<S61>/Math Function4' */
  real_T Add1;                         /* '<S61>/Add1' */
  real_T MathFunction5;                /* '<S61>/Math Function5' */
  real_T Gain_j;                       /* '<S61>/Gain' */
  real_T Add2;                         /* '<S61>/Add2' */
  real_T Saturation_a;                 /* '<S61>/Saturation' */
  real_T UnitDelay_b;                  /* '<S61>/Unit Delay' */
  real_T Sum_c;                        /* '<S61>/Sum' */
  real_T Saturation1_m;                /* '<S61>/Saturation1' */
  real_T Gain_a;                       /* '<S66>/Gain' */
  real_T Sum_o;                        /* '<S66>/Sum' */
  real_T MultiportSwitch_g;            /* '<S61>/Multiport Switch' */
  real_T TrigonometricFunction;        /* '<S61>/Trigonometric Function' */
  real_T TrigonometricFunction1;       /* '<S61>/Trigonometric Function1' */
  real_T SFunction1_o1_p;              /* '<S121>/S-Function1' */
  real_T SFunction1_o1_h;              /* '<S123>/S-Function1' */
  real_T SFunction1_o1_gf;             /* '<S125>/S-Function1' */
  real_T SFunction1_o1_o;              /* '<S127>/S-Function1' */
  real_T VoltageADC6V;                 /* '<S109>/Gain20' */
  real_T PhaseB_VoltageV;              /* '<S109>/Gain10' */
  real_T VoltageADC8V;                 /* '<S109>/Gain21' */
  real_T PhaseC_VoltageV;              /* '<S109>/Gain11' */
  real_T VoltageADC4V;                 /* '<S109>/Gain16' */
  real_T not_used;                     /* '<S109>/Gain12' */
  real_T VoltageADC2V;                 /* '<S109>/Gain14' */
  real_T PhaseA_VoltageV;              /* '<S109>/Gain8' */
  real_T Gain_e;                       /* '<S109>/Gain' */
  real_T Gain1_a;                      /* '<S109>/Gain1' */
  real_T Gain2_lh;                     /* '<S109>/Gain2' */
  real_T Gain3_j;                      /* '<S109>/Gain3' */
  real_T Gain4_a;                      /* '<S109>/Gain4' */
  real_T Gain5_o;                      /* '<S109>/Gain5' */
  real_T Gain6_m;                      /* '<S109>/Gain6' */
  real_T Gain7_k;                      /* '<S109>/Gain7' */
  real_T hall_A;                       /* '<S12>/bool2double1' */
  real_T hall_B;                       /* '<S12>/bool2double2' */
  real_T hall_C;                       /* '<S12>/bool2double3' */
  real_T Load_gain;                    /* '<S8>/Load_gain' */
  real_T load_2_current4;              /* '<S18>/load_2_current4' */
  real_T current_2_voltage;            /* '<S18>/current_2_voltage' */
  real_T Divide;                       /* '<S21>/Divide' */
  real_T Saturation_f;                 /* '<S21>/Saturation' */
  real_T DataTypeConversion3;          /* '<S8>/Data Type Conversion3' */
  real_T load_2_current4_j;            /* '<S17>/load_2_current4' */
  real_T current_2_voltage_k;          /* '<S17>/current_2_voltage' */
  real_T Divide_b;                     /* '<S20>/Divide' */
  real_T Saturation_l;                 /* '<S20>/Saturation' */
  real_T Switch_iu;                    /* '<S8>/Switch' */
  real_T Product1_n;                   /* '<S8>/Product1' */
  real_T Saturation1_b;                /* '<S19>/Saturation1' */
  real_T Divide_f;                     /* '<S19>/Divide' */
  real_T Divide_e;                     /* '<S16>/Divide' */
  real_T current_2_load1;              /* '<S16>/current_2_load1' */
  real_T n_Limitrpm;
                   /* '<S31>/BusConversion_InsertedFor_SignalBus_at_inport_0' */
  real_T UnitDelay1_hl;                /* '<S78>/Unit Delay1' */
  real_T UnitDelay2_py;                /* '<S81>/Unit Delay2' */
  real_T Switch1_m;                    /* '<S78>/Switch1' */
  real_T UnitDelay_o3;                 /* '<S73>/Unit Delay' */
  real_T Gain1_j;                      /* '<S31>/Gain1' */
  real_T Proportional_b;               /* '<S73>/Proportional' */
  real_T Sum_l;                        /* '<S73>/Sum' */
  real_T Product_ml;                   /* '<S78>/Product' */
  real_T UnitDelay_il;                 /* '<S78>/Unit Delay' */
  real_T Switch2_b4;                   /* '<S78>/Switch2' */
  real_T Add_c;                        /* '<S78>/Add' */
  real_T Switch_j;                     /* '<S80>/Switch' */
  real_T Switch2_o;                    /* '<S80>/Switch2' */
  real_T uFilterTime_o;                /* '<S73>/1|FilterTime' */
  real_T UnitDelay1_p;                 /* '<S84>/Unit Delay1' */
  real_T UnitDelay2_j;                 /* '<S87>/Unit Delay2' */
  real_T Switch1_k;                    /* '<S84>/Switch1' */
  real_T UnitDelay_e;                  /* '<S74>/Unit Delay' */
  real_T Proportional_k;               /* '<S74>/Proportional' */
  real_T Sum_ke;                       /* '<S74>/Sum' */
  real_T Product_l;                    /* '<S84>/Product' */
  real_T UnitDelay_c;                  /* '<S84>/Unit Delay' */
  real_T Switch2_h;                    /* '<S84>/Switch2' */
  real_T Add_l;                        /* '<S84>/Add' */
  real_T Switch_gh;                    /* '<S86>/Switch' */
  real_T Switch2_l;                    /* '<S86>/Switch2' */
  real_T uFilterTime_i;                /* '<S74>/1|FilterTime' */
  real_T Gain_g;                       /* '<S31>/Gain' */
  real_T Switch_l1;                    /* '<S31>/Switch' */
  real_T inv_pp;                       /* '<S75>/inv' */
  real_T Switch_nt;                    /* '<S90>/Switch' */
  real_T Switch2_dh;                   /* '<S90>/Switch2' */
  real_T Gain2_g;                      /* '<S31>/Gain2' */
  real_T Gain3_l;                      /* '<S31>/Gain3' */
  real_T error_f;                      /* '<S76>/Sum1' */
  real_T Product2_e;                   /* '<S76>/Product2' */
  real_T integral_g;                   /* '<S76>/Product' */
  real_T Product1_o;                   /* '<S76>/Product1' */
  real_T UnitDelay_jj;                 /* '<S76>/Unit Delay' */
  real_T Sum_of;                       /* '<S76>/Sum' */
  real_T Switch_k;                     /* '<S91>/Switch' */
  real_T Switch2_hf;                   /* '<S91>/Switch2' */
  real_T Sum2_d;                       /* '<S76>/Sum2' */
  uint32_T SFunction1_o4;              /* '<S114>/S-Function1' */
  int32_T Gain22;                      /* '<S109>/Gain22' */
  int32_T Gain23;                      /* '<S109>/Gain23' */
  int32_T Gain24;                      /* '<S109>/Gain24' */
  int32_T Gain25;                      /* '<S109>/Gain25' */
  int32_T Gain26;                      /* '<S109>/Gain26' */
  int32_T Gain27;                      /* '<S109>/Gain27' */
  int32_T Gain28;                      /* '<S109>/Gain28' */
  int32_T Gain29;                      /* '<S109>/Gain29' */
  int16_T SFunction1_o2_p;             /* '<S120>/S-Function1' */
  int16_T SFunction1_o2_k;             /* '<S124>/S-Function1' */
  int16_T SFunction1_o2_g;             /* '<S126>/S-Function1' */
  int16_T SFunction1_o2_pt;            /* '<S122>/S-Function1' */
  int16_T SFunction1_o2_m;             /* '<S121>/S-Function1' */
  int16_T SFunction1_o2_p0;            /* '<S123>/S-Function1' */
  int16_T SFunction1_o2_c;             /* '<S125>/S-Function1' */
  int16_T SFunction1_o2_o;             /* '<S127>/S-Function1' */
  uint8_T Compare;                     /* '<S48>/Compare' */
  uint8_T Compare_i;                   /* '<S51>/Compare' */
  uint8_T Compare_d;                   /* '<S52>/Compare' */
  uint8_T Output;                      /* '<S33>/Output' */
  uint8_T LookupTable;                 /* '<S27>/Lookup Table' */
  uint8_T Compare_p;                   /* '<S54>/Compare' */
  uint8_T Compare_ph;                  /* '<S57>/Compare' */
  uint8_T Compare_pw;                  /* '<S58>/Compare' */
  uint8_T Compare_l;                   /* '<S129>/Compare' */
  uint8_T Compare_b;                   /* '<S132>/Compare' */
  uint8_T Compare_d4;                  /* '<S133>/Compare' */
  uint8_T Compare_iz;                  /* '<S99>/Compare' */
  uint8_T Compare_m;                   /* '<S102>/Compare' */
  uint8_T Compare_n;                   /* '<S103>/Compare' */
  uint8_T Compare_py;                  /* '<S138>/Compare' */
  uint8_T Compare_k;                   /* '<S139>/Compare' */
  uint8_T Compare_iv;                  /* '<S140>/Compare' */
  uint8_T Compare_dx;                  /* '<S141>/Compare' */
  uint8_T Compare_pwu;                 /* '<S142>/Compare' */
  uint8_T Compare_e;                   /* '<S143>/Compare' */
  uint8_T FixPtSum1;                   /* '<S34>/FixPt Sum1' */
  uint8_T FixPtSwitch;                 /* '<S35>/FixPt Switch' */
  uint8_T Compare_ih;                  /* '<S79>/Compare' */
  uint8_T Compare_n4;                  /* '<S82>/Compare' */
  uint8_T Compare_g;                   /* '<S83>/Compare' */
  uint8_T Compare_bk;                  /* '<S85>/Compare' */
  uint8_T Compare_eg;                  /* '<S88>/Compare' */
  uint8_T Compare_nj;                  /* '<S89>/Compare' */
  uint8_T Gain11;                      /* '<S135>/Gain11' */
  uint8_T Gain12;                      /* '<S135>/Gain12' */
  uint8_T Gain13;                      /* '<S135>/Gain13' */
  uint8_T Gain14;                      /* '<S135>/Gain14' */
  boolean_T DataTypeConversion_h;      /* '<S4>/Data Type Conversion' */
  boolean_T HitCrossing;               /* '<S150>/Hit  Crossing' */
  boolean_T RelationalOperator1;       /* '<S150>/Relational Operator1' */
  boolean_T RelationalOperator;        /* '<S150>/Relational Operator' */
  boolean_T LogicalOperator1;          /* '<S50>/Logical Operator1' */
  boolean_T LogicalOperator;           /* '<S47>/Logical Operator' */
  boolean_T SFunction1_o2_cq;          /* '<S113>/S-Function1' */
  boolean_T SFunction1_o3_f;           /* '<S113>/S-Function1' */
  boolean_T SFunction1_o4_b;           /* '<S113>/S-Function1' */
  boolean_T SFunction1_o5;             /* '<S113>/S-Function1' */
  boolean_T SFunction1_o3_k;           /* '<S114>/S-Function1' */
  boolean_T LowerRelop1;               /* '<S49>/LowerRelop1' */
  boolean_T UpperRelop;                /* '<S49>/UpperRelop' */
  boolean_T LowerRelop1_i;             /* '<S71>/LowerRelop1' */
  boolean_T UpperRelop_k;              /* '<S71>/UpperRelop' */
  boolean_T LogicalOperator1_b;        /* '<S56>/Logical Operator1' */
  boolean_T LogicalOperator_j;         /* '<S53>/Logical Operator' */
  boolean_T LowerRelop1_e;             /* '<S55>/LowerRelop1' */
  boolean_T UpperRelop_l;              /* '<S55>/UpperRelop' */
  boolean_T LowerRelop1_l;             /* '<S72>/LowerRelop1' */
  boolean_T UpperRelop_e;              /* '<S72>/UpperRelop' */
  boolean_T LogicalOperator1_l;        /* '<S131>/Logical Operator1' */
  boolean_T LogicalOperator_f;         /* '<S128>/Logical Operator' */
  boolean_T LowerRelop1_a;             /* '<S130>/LowerRelop1' */
  boolean_T UpperRelop_h;              /* '<S130>/UpperRelop' */
  boolean_T LowerRelop1_f;             /* '<S67>/LowerRelop1' */
  boolean_T UpperRelop_hi;             /* '<S67>/UpperRelop' */
  boolean_T LowerRelop1_b;             /* '<S68>/LowerRelop1' */
  boolean_T UpperRelop_i;              /* '<S68>/UpperRelop' */
  boolean_T LogicalOperator1_i;        /* '<S101>/Logical Operator1' */
  boolean_T LogicalOperator_n;         /* '<S96>/Logical Operator' */
  boolean_T LowerRelop1_g;             /* '<S100>/LowerRelop1' */
  boolean_T UpperRelop_j;              /* '<S100>/UpperRelop' */
  boolean_T Mode_n_manual;             /* '<S135>/Logical Operator1' */
  boolean_T Mode_n_sig_gen;            /* '<S135>/Logical Operator' */
  boolean_T Mode_i_sig_gen;            /* '<S135>/Logical Operator2' */
  boolean_T Mode_i_manual;             /* '<S135>/Logical Operator3' */
  boolean_T LogicalOperator1_a;        /* '<S81>/Logical Operator1' */
  boolean_T LogicalOperator_e;         /* '<S78>/Logical Operator' */
  boolean_T LowerRelop1_gv;            /* '<S80>/LowerRelop1' */
  boolean_T UpperRelop_d;              /* '<S80>/UpperRelop' */
  boolean_T LogicalOperator1_n;        /* '<S87>/Logical Operator1' */
  boolean_T LogicalOperator_g;         /* '<S84>/Logical Operator' */
  boolean_T LowerRelop1_k;             /* '<S86>/LowerRelop1' */
  boolean_T UpperRelop_p;              /* '<S86>/UpperRelop' */
  boolean_T LowerRelop1_a5;            /* '<S90>/LowerRelop1' */
  boolean_T UpperRelop_h1;             /* '<S90>/UpperRelop' */
  boolean_T LowerRelop1_bl;            /* '<S91>/LowerRelop1' */
  boolean_T UpperRelop_a;              /* '<S91>/UpperRelop' */
} B_PMSM_DemoBackup_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S47>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S50>/Unit Delay2' */
  real_T UnitDelay_DSTATE;             /* '<S37>/Unit Delay' */
  real_T UnitDelay_DSTATE_f;           /* '<S47>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S61>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_p;          /* '<S53>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_l;          /* '<S56>/Unit Delay2' */
  real_T UnitDelay_DSTATE_k;           /* '<S38>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S53>/Unit Delay' */
  real_T UnitDelay2_DSTATE_o;          /* '<S61>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_g;          /* '<S128>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_p;          /* '<S131>/Unit Delay2' */
  real_T UnitDelay_DSTATE_n;           /* '<S110>/Unit Delay' */
  real_T UnitDelay_DSTATE_hr;          /* '<S128>/Unit Delay' */
  real_T UnitDelay_DSTATE_nm;          /* '<S39>/Unit Delay' */
  real_T UnitDelay_DSTATE_j;           /* '<S40>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c;          /* '<S96>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_ot;         /* '<S101>/Unit Delay2' */
  real_T UnitDelay_DSTATE_hf;          /* '<S96>/Unit Delay' */
  real_T UnitDelay_DSTATE_l;           /* '<S61>/Unit Delay' */
  real_T UnitDelay1_DSTATE_m;          /* '<S78>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_f;          /* '<S81>/Unit Delay2' */
  real_T UnitDelay_DSTATE_i;           /* '<S73>/Unit Delay' */
  real_T UnitDelay_DSTATE_c;           /* '<S78>/Unit Delay' */
  real_T UnitDelay1_DSTATE_pt;         /* '<S84>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_i;          /* '<S87>/Unit Delay2' */
  real_T UnitDelay_DSTATE_io;          /* '<S74>/Unit Delay' */
  real_T UnitDelay_DSTATE_cf;          /* '<S84>/Unit Delay' */
  real_T UnitDelay_DSTATE_o;           /* '<S76>/Unit Delay' */
  volatile real_T RateTransition_1_Buffer0;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_1_Buffer1;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_2_Buffer0;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_2_Buffer1;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_3_Buffer0;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_3_Buffer1;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_4_Buffer0;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_4_Buffer1;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_5_Buffer0;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_5_Buffer1;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_6_Buffer0;/* '<S6>/Rate Transition' */
  volatile real_T RateTransition_6_Buffer1;/* '<S6>/Rate Transition' */
  real_T Memory_PreviousInput;         /* '<S150>/Memory' */
  real_T Memory_PreviousInput_m;       /* '<S25>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S25>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<S25>/Memory2' */
  real_T Memory3_PreviousInput;        /* '<S25>/Memory3' */
  int_T HitCrossing_MODE;              /* '<S150>/Hit  Crossing' */
  uint8_T Output_DSTATE;               /* '<S33>/Output' */
  volatile int8_T RateTransition_1_write_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_1_read_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_1_last_buf_wr;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_2_write_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_2_read_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_2_last_buf_wr;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_3_write_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_3_read_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_3_last_buf_wr;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_4_write_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_4_read_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_4_last_buf_wr;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_5_write_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_5_read_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_5_last_buf_wr;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_6_write_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_6_read_buf;/* '<S6>/Rate Transition' */
  volatile int8_T RateTransition_6_last_buf_wr;/* '<S6>/Rate Transition' */
} DW_PMSM_DemoBackup_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<S150>/Hit  Crossing' */
  ZCSigState speed_controller_Trig_ZCE;/* '<S22>/speed_controller' */
} PrevZCX_PMSM_DemoBackup_T;

/* Parameters (default storage) */
struct P_PMSM_DemoBackup_T_ {
  real_T Const_Id_Fieldweakening;      /* Variable: Const_Id_Fieldweakening
                                        * Referenced by: '<S30>/Const_Id_Fieldweakening[A]'
                                        */
  real_T Const_Ld_Stator;              /* Variable: Const_Ld_Stator
                                        * Referenced by:
                                        *   '<S64>/Const_Lsd[H]'
                                        *   '<S65>/Const_Lsd[H]'
                                        */
  real_T Const_Lq_Stator;              /* Variable: Const_Lq_Stator
                                        * Referenced by:
                                        *   '<S64>/Const_Lsq[H]'
                                        *   '<S65>/Const_Lsq[H]'
                                        */
  real_T Const_PolePairs;              /* Variable: Const_PolePairs
                                        * Referenced by: '<S28>/Const_PolePair[]'
                                        */
  real_T Const_Psi;                    /* Variable: Const_Psi
                                        * Referenced by:
                                        *   '<S64>/Const_Psi[Wb]'
                                        *   '<S65>/Const_Psi[Wb]'
                                        */
  real_T PMSM_Ctrl_Ctrl_mode_SW;       /* Variable: PMSM_Ctrl_Ctrl_mode_SW
                                        * Referenced by: '<S137>/Ctrl_mode_SW[1 n_ctrl | 2 i_ctrl | 3 v_ctrl]'
                                        */
  real_T PMSM_Ctrl_Ki_id;              /* Variable: PMSM_Ctrl_Ki_id
                                        * Referenced by: '<S137>/Ki_id'
                                        */
  real_T PMSM_Ctrl_Ki_iq;              /* Variable: PMSM_Ctrl_Ki_iq
                                        * Referenced by: '<S137>/Ki_iq'
                                        */
  real_T PMSM_Ctrl_Ki_n;               /* Variable: PMSM_Ctrl_Ki_n
                                        * Referenced by: '<S137>/Ki_n'
                                        */
  real_T PMSM_Ctrl_Kp_id;              /* Variable: PMSM_Ctrl_Kp_id
                                        * Referenced by: '<S137>/Kp_id'
                                        */
  real_T PMSM_Ctrl_Kp_iq;              /* Variable: PMSM_Ctrl_Kp_iq
                                        * Referenced by: '<S137>/Kp_iq'
                                        */
  real_T PMSM_Ctrl_Kp_n;               /* Variable: PMSM_Ctrl_Kp_n
                                        * Referenced by: '<S137>/Kp_n'
                                        */
  real_T PMSM_Ctrl_Limit_iq;           /* Variable: PMSM_Ctrl_Limit_iq
                                        * Referenced by: '<S137>/Limit_iq'
                                        */
  real_T PMSM_Ctrl_Pos_Src;            /* Variable: PMSM_Ctrl_Pos_Src
                                        * Referenced by: '<S137>/Pos_Src'
                                        */
  real_T PMSM_Ctrl_TF_Id;              /* Variable: PMSM_Ctrl_TF_Id
                                        * Referenced by: '<S137>/TF_Id[s]'
                                        */
  real_T PMSM_Ctrl_TF_Iq;              /* Variable: PMSM_Ctrl_TF_Iq
                                        * Referenced by: '<S137>/TF_Iq[s]'
                                        */
  real_T PMSM_Ctrl_TF_n;               /* Variable: PMSM_Ctrl_TF_n
                                        * Referenced by: '<S137>/TF_n[s]'
                                        */
  real_T PMSM_Ctrl_V_DCLink_Limit;     /* Variable: PMSM_Ctrl_V_DCLink_Limit
                                        * Referenced by: '<S137>/V_DCLink_Limit[V]'
                                        */
  real_T PMSM_Ctrl_Vel_Src;            /* Variable: PMSM_Ctrl_Vel_Src
                                        * Referenced by: '<S137>/Vel_Src'
                                        */
  real_T PMSM_Ctrl_fRS_Set;            /* Variable: PMSM_Ctrl_fRS_Set
                                        * Referenced by: '<S137>/fRS_Set[Hz]'
                                        */
  real_T PMSM_Ctrl_i_d_Set;            /* Variable: PMSM_Ctrl_i_d_Set
                                        * Referenced by: '<S137>/i_d_Set[A]'
                                        */
  real_T PMSM_Ctrl_i_d_Stroke;         /* Variable: PMSM_Ctrl_i_d_Stroke
                                        * Referenced by: '<S137>/i_d_Stroke[A]'
                                        */
  real_T PMSM_Ctrl_i_q_Set;            /* Variable: PMSM_Ctrl_i_q_Set
                                        * Referenced by: '<S137>/i_q_Set[A]'
                                        */
  real_T PMSM_Ctrl_i_q_Stroke;         /* Variable: PMSM_Ctrl_i_q_Stroke
                                        * Referenced by: '<S137>/i_q_Stroke[A]'
                                        */
  real_T PMSM_Ctrl_load_torque;        /* Variable: PMSM_Ctrl_load_torque
                                        * Referenced by: '<S137>/load_torque'
                                        */
  real_T PMSM_Ctrl_n_Limit;            /* Variable: PMSM_Ctrl_n_Limit
                                        * Referenced by: '<S137>/n_Limit [rpm]'
                                        */
  real_T PMSM_Ctrl_n_Set;              /* Variable: PMSM_Ctrl_n_Set
                                        * Referenced by: '<S137>/n_Set[rpm]'
                                        */
  real_T PMSM_Ctrl_n_Stroke;           /* Variable: PMSM_Ctrl_n_Stroke
                                        * Referenced by: '<S137>/n_Stroke[rpm]'
                                        */
  real_T PMSM_Ctrl_theta_offset;       /* Variable: PMSM_Ctrl_theta_offset
                                        * Referenced by: '<S137>/Theta_offset[rad]'
                                        */
  real_T PMSM_Ctrl_v_d_Set;            /* Variable: PMSM_Ctrl_v_d_Set
                                        * Referenced by: '<S137>/v_d_Set[V]'
                                        */
  real_T PMSM_Ctrl_v_q_Set;            /* Variable: PMSM_Ctrl_v_q_Set
                                        * Referenced by: '<S137>/v_q_Set[V]'
                                        */
  real_T SW_Fieldweakening;            /* Variable: SW_Fieldweakening
                                        * Referenced by: '<S61>/SW_Fieldweakening[1|2]'
                                        */
  real_T T_PWM;                        /* Variable: T_PWM
                                        * Referenced by: '<S137>/T_Sample[s]'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S79>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S82>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S83>/Constant'
                                      */
  real_T CompareToConstant_const_j; /* Mask Parameter: CompareToConstant_const_j
                                     * Referenced by: '<S85>/Constant'
                                     */
  real_T CompareToConstant1_const_m;
                                   /* Mask Parameter: CompareToConstant1_const_m
                                    * Referenced by: '<S88>/Constant'
                                    */
  real_T CompareToConstant2_const_d;
                                   /* Mask Parameter: CompareToConstant2_const_d
                                    * Referenced by: '<S89>/Constant'
                                    */
  real_T CompareToConstant_const_i; /* Mask Parameter: CompareToConstant_const_i
                                     * Referenced by: '<S48>/Constant'
                                     */
  real_T CompareToConstant1_const_d;
                                   /* Mask Parameter: CompareToConstant1_const_d
                                    * Referenced by: '<S51>/Constant'
                                    */
  real_T CompareToConstant2_const_a;
                                   /* Mask Parameter: CompareToConstant2_const_a
                                    * Referenced by: '<S52>/Constant'
                                    */
  real_T CompareToConstant_const_a; /* Mask Parameter: CompareToConstant_const_a
                                     * Referenced by: '<S54>/Constant'
                                     */
  real_T CompareToConstant1_const_i;
                                   /* Mask Parameter: CompareToConstant1_const_i
                                    * Referenced by: '<S57>/Constant'
                                    */
  real_T CompareToConstant2_const_az;
                                  /* Mask Parameter: CompareToConstant2_const_az
                                   * Referenced by: '<S58>/Constant'
                                   */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S129>/Constant'
                                     */
  real_T CompareToConstant1_const_l;
                                   /* Mask Parameter: CompareToConstant1_const_l
                                    * Referenced by: '<S132>/Constant'
                                    */
  real_T CompareToConstant2_const_j;
                                   /* Mask Parameter: CompareToConstant2_const_j
                                    * Referenced by: '<S133>/Constant'
                                    */
  real_T CompareToConstant_const_m; /* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S99>/Constant'
                                     */
  real_T CompareToConstant1_const_o;
                                   /* Mask Parameter: CompareToConstant1_const_o
                                    * Referenced by: '<S102>/Constant'
                                    */
  real_T CompareToConstant2_const_i;
                                   /* Mask Parameter: CompareToConstant2_const_i
                                    * Referenced by: '<S103>/Constant'
                                    */
  real_T CompareToConstant_const_hp;
                                   /* Mask Parameter: CompareToConstant_const_hp
                                    * Referenced by: '<S138>/Constant'
                                    */
  real_T CompareToConstant1_const_a;
                                   /* Mask Parameter: CompareToConstant1_const_a
                                    * Referenced by: '<S139>/Constant'
                                    */
  real_T CompareToConstant2_const_k;
                                   /* Mask Parameter: CompareToConstant2_const_k
                                    * Referenced by: '<S140>/Constant'
                                    */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S141>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S142>/Constant'
                                      */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S143>/Constant'
                                      */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_INTEGRATOR_lower_limit;
                              /* Mask Parameter: DISCRETE_INTEGRATOR_lower_limit
                               * Referenced by: '<S96>/lower_limit'
                               */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT1_lower_limit_int;
                                 /* Mask Parameter: DISCRETE_PT1_lower_limit_int
                                  * Referenced by: '<S78>/lower_limit'
                                  */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT1_SET_lower_limit_in;
                              /* Mask Parameter: DISCRETE_PT1_SET_lower_limit_in
                               * Referenced by: '<S84>/lower_limit'
                               */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT1_lower_limit_int_i;
                               /* Mask Parameter: DISCRETE_PT1_lower_limit_int_i
                                * Referenced by: '<S47>/lower_limit'
                                */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT2_lower_limit_int;
                                 /* Mask Parameter: DISCRETE_PT2_lower_limit_int
                                  * Referenced by: '<S53>/lower_limit'
                                  */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT1_lower_limit_int_a;
                               /* Mask Parameter: DISCRETE_PT1_lower_limit_int_a
                                * Referenced by: '<S128>/lower_limit'
                                */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_INTEGRATOR_upper_limit;
                              /* Mask Parameter: DISCRETE_INTEGRATOR_upper_limit
                               * Referenced by: '<S96>/upper_limit'
                               */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT1_upper_limit_int;
                                 /* Mask Parameter: DISCRETE_PT1_upper_limit_int
                                  * Referenced by: '<S78>/upper_limit'
                                  */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT1_SET_upper_limit_in;
                              /* Mask Parameter: DISCRETE_PT1_SET_upper_limit_in
                               * Referenced by: '<S84>/upper_limit'
                               */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT1_upper_limit_int_i;
                               /* Mask Parameter: DISCRETE_PT1_upper_limit_int_i
                                * Referenced by: '<S47>/upper_limit'
                                */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT2_upper_limit_int;
                                 /* Mask Parameter: DISCRETE_PT2_upper_limit_int
                                  * Referenced by: '<S53>/upper_limit'
                                  */
  struct_SPJi1DXfNcjd7Ee0UF7vjC DISCRETE_PT1_upper_limit_int_l;
                               /* Mask Parameter: DISCRETE_PT1_upper_limit_int_l
                                * Referenced by: '<S128>/upper_limit'
                                */
  uint8_T CounterLimited_uplimit;      /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S35>/FixPt Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0.001
                                        * Referenced by: '<S31>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S31>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S31>/Constant5'
                                        */
  real_T zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S73>/zero'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S78>/Unit Delay1'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S81>/Unit Delay2'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S78>/Constant1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S73>/Unit Delay'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S31>/Gain1'
                                        */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<S78>/Constant2'
                                        */
  real_T UnitDelay_InitialCondition_o; /* Expression: 0
                                        * Referenced by: '<S78>/Unit Delay'
                                        */
  real_T zero_Value_i;                 /* Expression: 0
                                        * Referenced by: '<S74>/zero'
                                        */
  real_T UnitDelay1_InitialCondition_p;/* Expression: 0
                                        * Referenced by: '<S84>/Unit Delay1'
                                        */
  real_T UnitDelay2_InitialCondition_m;/* Expression: 0
                                        * Referenced by: '<S87>/Unit Delay2'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S84>/Constant1'
                                        */
  real_T UnitDelay_InitialCondition_b; /* Expression: 0
                                        * Referenced by: '<S74>/Unit Delay'
                                        */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S84>/Constant2'
                                        */
  real_T UnitDelay_InitialCondition_g; /* Expression: 0
                                        * Referenced by: '<S84>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T switch_filter_Value;          /* Expression: 1
                                        * Referenced by: '<S31>/switch_filter'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S31>/Switch'
                                        */
  real_T inv_Gain;                     /* Expression: -1
                                        * Referenced by: '<S75>/inv'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S31>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S31>/Gain3'
                                        */
  real_T UnitDelay_InitialCondition_h; /* Expression: 0
                                        * Referenced by: '<S76>/Unit Delay'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1200
                                        * Referenced by: '<S137>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1200
                                        * Referenced by: '<S137>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 6
                                        * Referenced by: '<S137>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -6
                                        * Referenced by: '<S137>/Saturation1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 6
                                        * Referenced by: '<S137>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -6
                                        * Referenced by: '<S137>/Saturation2'
                                        */
  real_T Gain13_Gain;                  /* Expression: 10
                                        * Referenced by: '<S109>/Gain13'
                                        */
  real_T voltamp_i_a_Gain;             /* Expression: -12
                                        * Referenced by: '<S109>/volt->amp_i_a           '
                                        */
  real_T i_a_offset_Value;             /* Expression: -0.14
                                        * Referenced by: '<S109>/ i_a_offset'
                                        */
  real_T Gain17_Gain;                  /* Expression: 10
                                        * Referenced by: '<S109>/Gain17'
                                        */
  real_T voltamp_i_b_Gain;             /* Expression: -12
                                        * Referenced by: '<S109>/volt->amp_i_b'
                                        */
  real_T i_b_offset_Value;             /* Expression: -0.12
                                        * Referenced by: '<S109>/ i_b_offset  '
                                        */
  real_T Gain18_Gain;                  /* Expression: 10
                                        * Referenced by: '<S109>/Gain18'
                                        */
  real_T voltamp_i_c_Gain;             /* Expression: -12
                                        * Referenced by: '<S109>/volt->amp_i_c'
                                        */
  real_T i_c_offset_Value;             /* Expression: -0.13
                                        * Referenced by: '<S109>/i_c_offset'
                                        */
  real_T Gain1_Gain_o[6];
                   /* Expression: [[2/3 -1/3 -1/3]*1;[0 sqrt(3)/3 -sqrt(3)/3]*1]
                    * Referenced by: '<S60>/Gain1'
                    */
  real_T Gain5_Gain;                   /* Expression: 1
                                        * Referenced by: '<S135>/Gain5'
                                        */
  real_T zero_Value_m;                 /* Expression: 0
                                        * Referenced by: '<S37>/zero'
                                        */
  real_T UnitDelay1_InitialCondition_o;/* Expression: 0
                                        * Referenced by: '<S47>/Unit Delay1'
                                        */
  real_T UnitDelay2_InitialCondition_j;/* Expression: 0
                                        * Referenced by: '<S50>/Unit Delay2'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S47>/Constant1'
                                        */
  real_T UnitDelay_InitialCondition_f; /* Expression: 0
                                        * Referenced by: '<S37>/Unit Delay'
                                        */
  real_T Gain1_Gain_p[6];
  /* Expression: [[2/3 -1/3 -1/3]*transffactor;[0 sqrt(3)/3 -sqrt(3)/3]*transffactor]
   * Referenced by: '<S59>/Gain1'
   */
  real_T AngleOffset_Value;            /* Expression: 0
                                        * Referenced by: '<S12>/AngleOffset'
                                        */
  real_T Gain3_Gain_c;                 /* Expression: 4
                                        * Referenced by: '<S119>/Gain3'
                                        */
  real_T Constant4_Value_m;            /* Expression: 360
                                        * Referenced by: '<S119>/Constant4'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0.5
                                        * Referenced by: '<S117>/Switch'
                                        */
  real_T to_rad_Gain;                  /* Expression: pi/180
                                        * Referenced by: '<S12>/to_rad'
                                        */
  real_T Constant2_Value_f;            /* Expression: 2*pi
                                        * Referenced by: '<S36>/Constant2'
                                        */
  real_T Constant2_Value_e;            /* Expression: 1
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Constant2_Value_n0;           /* Expression: 0
                                        * Referenced by: '<S47>/Constant2'
                                        */
  real_T UnitDelay_InitialCondition_p; /* Expression: 0
                                        * Referenced by: '<S47>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_m;/* Expression: 0
                                        * Referenced by: '<S61>/Unit Delay1'
                                        */
  real_T UseIncSpeed_Value;            /* Expression: 1
                                        * Referenced by: '<S12>/UseIncSpeed'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1/4
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S25>/Memory'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S25>/Memory1'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S25>/Memory2'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S25>/Memory3'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 1/5
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Kp_n_Cor_Gain;                /* Expression: 1
                                        * Referenced by: '<S9>/Kp_n_Cor'
                                        */
  real_T Ki_n_Cor_Gain;                /* Expression: 1
                                        * Referenced by: '<S9>/Ki_n_Cor'
                                        */
  real_T Gain3_Gain_a;                 /* Expression: -1
                                        * Referenced by: '<S30>/Gain3'
                                        */
  real_T zero_Value_ia;                /* Expression: 0
                                        * Referenced by: '<S30>/zero'
                                        */
  real_T inv_Gain_i;                   /* Expression: -1
                                        * Referenced by: '<S69>/inv'
                                        */
  real_T Gain3_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S135>/Gain3'
                                        */
  real_T zero_Value_e;                 /* Expression: 0
                                        * Referenced by: '<S38>/zero'
                                        */
  real_T UnitDelay1_InitialCondition_c;/* Expression: 0
                                        * Referenced by: '<S53>/Unit Delay1'
                                        */
  real_T UnitDelay2_InitialCondition_i;/* Expression: 0
                                        * Referenced by: '<S56>/Unit Delay2'
                                        */
  real_T Constant3_Value_i;            /* Expression: 0
                                        * Referenced by: '<S29>/Constant3'
                                        */
  real_T Constant1_Value_ov;           /* Expression: 0
                                        * Referenced by: '<S53>/Constant1'
                                        */
  real_T UnitDelay_InitialCondition_i; /* Expression: 0
                                        * Referenced by: '<S38>/Unit Delay'
                                        */
  real_T inv_Gain_n;                   /* Expression: -1
                                        * Referenced by: '<S59>/inv'
                                        */
  real_T Constant4_Value_n;            /* Expression: 1
                                        * Referenced by: '<S29>/Constant4'
                                        */
  real_T Constant2_Value_m;            /* Expression: 0
                                        * Referenced by: '<S53>/Constant2'
                                        */
  real_T UnitDelay_InitialCondition_g5;/* Expression: 0
                                        * Referenced by: '<S53>/Unit Delay'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: -1
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T UnitDelay2_InitialCondition_a;/* Expression: 0
                                        * Referenced by: '<S61>/Unit Delay2'
                                        */
  real_T inv_Gain_i4;                  /* Expression: -1
                                        * Referenced by: '<S70>/inv'
                                        */
  real_T Gain3_Gain_b;                 /* Expression: -1
                                        * Referenced by: '<S29>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S135>/Gain4'
                                        */
  real_T zero_Value_c;                 /* Expression: 0
                                        * Referenced by: '<S110>/zero'
                                        */
  real_T UnitDelay1_InitialCondition_b;/* Expression: 0
                                        * Referenced by: '<S128>/Unit Delay1'
                                        */
  real_T UnitDelay2_InitialCondition_e;/* Expression: 0
                                        * Referenced by: '<S131>/Unit Delay2'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant1_Value_mp;           /* Expression: 0
                                        * Referenced by: '<S128>/Constant1'
                                        */
  real_T UnitDelay_InitialCondition_hx;/* Expression: 0
                                        * Referenced by: '<S110>/Unit Delay'
                                        */
  real_T Gain15_Gain;                  /* Expression: 10
                                        * Referenced by: '<S109>/Gain15'
                                        */
  real_T Gain9_Gain;                   /* Expression: 6
                                        * Referenced by: '<S109>/Gain9'
                                        */
  real_T Constant2_Value_g;            /* Expression: 1
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Constant2_Value_fk;           /* Expression: 0
                                        * Referenced by: '<S128>/Constant2'
                                        */
  real_T UnitDelay_InitialCondition_ic;/* Expression: 0
                                        * Referenced by: '<S128>/Unit Delay'
                                        */
  real_T Constant3_Value_ib;           /* Expression: 0.100
                                        * Referenced by: '<S12>/Constant3'
                                        */
  real_T LimitingFactor_Gain;          /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S44>/LimitingFactor'
                                        */
  real_T Kp_i_Cor_Gain;                /* Expression: 1
                                        * Referenced by: '<S9>/Kp_i_Cor'
                                        */
  real_T Ki_i_Cor_Gain;                /* Expression: 1
                                        * Referenced by: '<S9>/Ki_i_Cor'
                                        */
  real_T UnitDelay_InitialCondition_n; /* Expression: 0
                                        * Referenced by: '<S39>/Unit Delay'
                                        */
  real_T toRads_Gain;                  /* Expression: pi/30
                                        * Referenced by: '<S28>/toRad|s'
                                        */
  real_T inv_Gain_c;                   /* Expression: -1
                                        * Referenced by: '<S62>/inv'
                                        */
  real_T UnitDelay_InitialCondition_k; /* Expression: 0
                                        * Referenced by: '<S40>/Unit Delay'
                                        */
  real_T inv_Gain_i0;                  /* Expression: -1
                                        * Referenced by: '<S63>/inv'
                                        */
  real_T zero_Value_j;                 /* Expression: 0
                                        * Referenced by: '<S92>/zero'
                                        */
  real_T UnitDelay1_InitialCondition_i;/* Expression: 0
                                        * Referenced by: '<S96>/Unit Delay1'
                                        */
  real_T UnitDelay2_InitialCondition_p;/* Expression: 0
                                        * Referenced by: '<S101>/Unit Delay2'
                                        */
  real_T Reset01_Value;                /* Expression: 0
                                        * Referenced by: '<S92>/Reset[0|1]'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S96>/Constant1'
                                        */
  real_T torpm_Gain;                   /* Expression: 60
                                        * Referenced by: '<S92>/torpm'
                                        */
  real_T Gain_Gain_jr;                 /* Expression: Gain
                                        * Referenced by: '<S98>/Gain'
                                        */
  real_T Constant2_Value_gf;           /* Expression: 0
                                        * Referenced by: '<S96>/Constant2'
                                        */
  real_T UnitDelay_InitialCondition_oa;/* Expression: 0
                                        * Referenced by: '<S96>/Unit Delay'
                                        */
  real_T Constant2_Value_gg;           /* Expression: 2*pi
                                        * Referenced by: '<S97>/Constant2'
                                        */
  real_T inv_Gain_if;                  /* Expression: -1
                                        * Referenced by: '<S104>/inv'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 1/transffactor
                                        * Referenced by: '<S105>/Gain1'
                                        */
  real_T Gain2_Gain_c;                 /* Expression: -1/2/transffactor
                                        * Referenced by: '<S105>/Gain2'
                                        */
  real_T Gain3_Gain_ld;                /* Expression: sqrt(3)/2/transffactor
                                        * Referenced by: '<S105>/Gain3'
                                        */
  real_T one_Value;                    /* Expression: 1
                                        * Referenced by: '<S23>/one'
                                        */
  real_T half_Gain;                    /* Expression: 1/2
                                        * Referenced by: '<S23>/half'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 1
                                        * Referenced by: '<S23>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: 0
                                        * Referenced by: '<S23>/Saturation'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1
                                        * Referenced by: '<S135>/Gain6'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1
                                        * Referenced by: '<S135>/Gain7'
                                        */
  real_T Gain16_Gain;                  /* Expression: 1
                                        * Referenced by: '<S135>/Gain16'
                                        */
  real_T Gain17_Gain_h;                /* Expression: 1
                                        * Referenced by: '<S135>/Gain17'
                                        */
  real_T Gain10_Gain;                  /* Expression: 1
                                        * Referenced by: '<S135>/Gain10'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1
                                        * Referenced by: '<S135>/Gain8'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S135>/Gain1'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S135>/Gain2'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 1.5
                                        * Referenced by: '<S135>/Switch'
                                        */
  real_T Gain15_Gain_j;                /* Expression: 1
                                        * Referenced by: '<S135>/Gain15'
                                        */
  real_T Gain9_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S135>/Gain9'
                                        */
  real_T UseController_Value;          /* Expression: 1
                                        * Referenced by: '<S13>/UseController'
                                        */
  real_T Duty_A_Value;                 /* Expression: 0
                                        * Referenced by: '<S13>/Duty_A'
                                        */
  real_T Duty_B_Value;                 /* Expression: 0
                                        * Referenced by: '<S13>/Duty_B'
                                        */
  real_T Duty_C_Value;                 /* Expression: 0
                                        * Referenced by: '<S13>/Duty_C'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 0.92
                                        * Referenced by: '<S61>/Gain'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S61>/Zero'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 0.2
                                        * Referenced by: '<S61>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: -0.2
                                        * Referenced by: '<S61>/Saturation'
                                        */
  real_T UnitDelay_InitialCondition_j; /* Expression: 0
                                        * Referenced by: '<S61>/Unit Delay'
                                        */
  real_T Saturation1_UpperSat_a;       /* Expression: 0
                                        * Referenced by: '<S61>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_i;       /* Expression: -50
                                        * Referenced by: '<S61>/Saturation1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: Gain
                                        * Referenced by: '<S66>/Gain'
                                        */
  real_T Offset_Value;                 /* Expression: Offset
                                        * Referenced by: '<S66>/Offset'
                                        */
  real_T Gain20_Gain;                  /* Expression: 10
                                        * Referenced by: '<S109>/Gain20'
                                        */
  real_T Gain10_Gain_k;                /* Expression: 6
                                        * Referenced by: '<S109>/Gain10'
                                        */
  real_T Gain21_Gain;                  /* Expression: 10
                                        * Referenced by: '<S109>/Gain21'
                                        */
  real_T Gain11_Gain;                  /* Expression: 6
                                        * Referenced by: '<S109>/Gain11'
                                        */
  real_T Gain16_Gain_o;                /* Expression: 10
                                        * Referenced by: '<S109>/Gain16'
                                        */
  real_T Gain12_Gain;                  /* Expression: 1
                                        * Referenced by: '<S109>/Gain12'
                                        */
  real_T Gain14_Gain;                  /* Expression: 10
                                        * Referenced by: '<S109>/Gain14'
                                        */
  real_T Gain8_Gain_h;                 /* Expression: 6
                                        * Referenced by: '<S109>/Gain8'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1
                                        * Referenced by: '<S109>/Gain'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S109>/Gain1'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 1
                                        * Referenced by: '<S109>/Gain2'
                                        */
  real_T Gain3_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S109>/Gain3'
                                        */
  real_T Gain4_Gain_k;                 /* Expression: 1
                                        * Referenced by: '<S109>/Gain4'
                                        */
  real_T Gain5_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S109>/Gain5'
                                        */
  real_T Gain6_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S109>/Gain6'
                                        */
  real_T Gain7_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S109>/Gain7'
                                        */
  real_T BrakePeriod_Value;            /* Expression: 50e-6
                                        * Referenced by: '<S8>/BrakePeriod'
                                        */
  real_T Load_gain_Gain;               /* Expression: 0.4
                                        * Referenced by: '<S8>/Load_gain'
                                        */
  real_T load_2_current4_tableData[6];
                                    /* Expression: [0, 0.05, 0.1, 0.2, 0.3, 0.4]
                                     * Referenced by: '<S18>/load_2_current4'
                                     */
  real_T load_2_current4_bp01Data[6];
                                    /* Expression: [0, 0.05, 0.2, 0.7, 1.4, 1.9]
                                     * Referenced by: '<S18>/load_2_current4'
                                     */
  real_T current_2_voltage_Gain;       /* Expression: 24
                                        * Referenced by: '<S18>/current_2_voltage'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 1
                                        * Referenced by: '<S21>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: 0
                                        * Referenced by: '<S21>/Saturation'
                                        */
  real_T manual_Load_control_Value;    /* Expression: 0
                                        * Referenced by: '<S8>/manual_Load_control'
                                        */
  real_T load_value_manNm_Value;       /* Expression: 0
                                        * Referenced by: '<S8>/load_value_man[Nm]'
                                        */
  real_T load_2_current4_tableData_f[6];
                                    /* Expression: [0, 0.05, 0.1, 0.2, 0.3, 0.4]
                                     * Referenced by: '<S17>/load_2_current4'
                                     */
  real_T load_2_current4_bp01Data_j[6];
                                    /* Expression: [0, 0.05, 0.2, 0.7, 1.4, 1.9]
                                     * Referenced by: '<S17>/load_2_current4'
                                     */
  real_T current_2_voltage_Gain_k;     /* Expression: 24
                                        * Referenced by: '<S17>/current_2_voltage'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Saturation_LowerSat_n4;       /* Expression: 0
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Switch_Threshold_l;           /* Expression: 0.5
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T Load_enable_Value;            /* Expression: 0
                                        * Referenced by: '<S8>/Load_enable'
                                        */
  real_T Saturation1_UpperSat_e;       /* Expression: 1
                                        * Referenced by: '<S19>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_l;       /* Expression: 0
                                        * Referenced by: '<S19>/Saturation1'
                                        */
  real_T coil_resistance_Value;        /* Expression: 24
                                        * Referenced by: '<S16>/coil_resistance'
                                        */
  real_T current_2_load1_tableData[6];
                                    /* Expression: [0, 0.05, 0.2, 0.7, 1.4, 1.9]
                                     * Referenced by: '<S16>/current_2_load1'
                                     */
  real_T current_2_load1_bp01Data[6];
                                    /* Expression: [0, 0.05, 0.1, 0.2, 0.3, 0.4]
                                     * Referenced by: '<S16>/current_2_load1'
                                     */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S150>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S150>/Constant1'
                                        */
  real_T HitCrossing_Offset;           /* Expression: 0.5
                                        * Referenced by: '<S150>/Hit  Crossing'
                                        */
  real_T Memory_InitialCondition_p;    /* Expression: 0
                                        * Referenced by: '<S150>/Memory'
                                        */
  real_T switch_out_boarder_Value;     /* Expression: 0.5
                                        * Referenced by: '<S150>/switch_out_boarder'
                                        */
  real_T load_signal_0_Value;          /* Expression: 0
                                        * Referenced by: '<S150>/load_signal_0'
                                        */
  real_T start_time_samples_Value;     /* Expression: 1000
                                        * Referenced by: '<S150>/start_time_samples'
                                        */
  real_T load_signal_generator_Value;  /* Expression: 1
                                        * Referenced by: '<S150>/load_signal_generator'
                                        */
  real_T Choose_reference_Value_iq_Value;/* Expression: 2
                                          * Referenced by: '<S6>/Choose_reference_Value_iq'
                                          */
  real_T Choose_reference_Value_n_Value;/* Expression: 2
                                         * Referenced by: '<S6>/Choose_reference_Value_n'
                                         */
  real_T Const_ref_iq_Value;           /* Expression: 0
                                        * Referenced by: '<S6>/Const_ref_iq'
                                        */
  real_T Const_ref_n_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/Const_ref_n'
                                        */
  real_T Sig_gen_n_Amplitude;          /* Expression: 1
                                        * Referenced by: '<S6>/Sig_gen_n'
                                        */
  real_T Sig_gen_n_Frequency;          /* Expression: 0.2
                                        * Referenced by: '<S6>/Sig_gen_n'
                                        */
  real_T Sig_gen_iq_Amplitude;         /* Expression: 1
                                        * Referenced by: '<S6>/Sig_gen_iq'
                                        */
  real_T Sig_gen_iq_Frequency;         /* Expression: 0.2
                                        * Referenced by: '<S6>/Sig_gen_iq'
                                        */
  real_T Sine_wave_ref_iq_Amp;         /* Expression: 1
                                        * Referenced by: '<S6>/Sine_wave_ref_iq'
                                        */
  real_T Sine_wave_ref_iq_Bias;        /* Expression: 0
                                        * Referenced by: '<S6>/Sine_wave_ref_iq'
                                        */
  real_T Sine_wave_ref_iq_Freq;        /* Expression: 1
                                        * Referenced by: '<S6>/Sine_wave_ref_iq'
                                        */
  real_T Sine_wave_ref_iq_Phase;       /* Expression: 0
                                        * Referenced by: '<S6>/Sine_wave_ref_iq'
                                        */
  real_T RateTransition_1_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S6>/Rate Transition'
                                          */
  real_T RateTransition_2_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S6>/Rate Transition'
                                          */
  real_T RateTransition_3_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S6>/Rate Transition'
                                          */
  real_T RateTransition_4_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S6>/Rate Transition'
                                          */
  real_T RateTransition_5_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S6>/Rate Transition'
                                          */
  real_T RateTransition_6_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S6>/Rate Transition'
                                          */
  real_T Gain_Gain_jk;                 /* Expression: 1
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T clock_Value[6];               /* Expression: clock()
                                        * Referenced by: '<S1>/clock'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<S4>/Enable'
                                        */
  uint32_T Switch_Threshold_j;         /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S116>/Switch'
                                        */
  int16_T Gain22_Gain;                 /* Computed Parameter: Gain22_Gain
                                        * Referenced by: '<S109>/Gain22'
                                        */
  int16_T Gain23_Gain;                 /* Computed Parameter: Gain23_Gain
                                        * Referenced by: '<S109>/Gain23'
                                        */
  int16_T Gain24_Gain;                 /* Computed Parameter: Gain24_Gain
                                        * Referenced by: '<S109>/Gain24'
                                        */
  int16_T Gain25_Gain;                 /* Computed Parameter: Gain25_Gain
                                        * Referenced by: '<S109>/Gain25'
                                        */
  int16_T Gain26_Gain;                 /* Computed Parameter: Gain26_Gain
                                        * Referenced by: '<S109>/Gain26'
                                        */
  int16_T Gain27_Gain;                 /* Computed Parameter: Gain27_Gain
                                        * Referenced by: '<S109>/Gain27'
                                        */
  int16_T Gain28_Gain;                 /* Computed Parameter: Gain28_Gain
                                        * Referenced by: '<S109>/Gain28'
                                        */
  int16_T Gain29_Gain;                 /* Computed Parameter: Gain29_Gain
                                        * Referenced by: '<S109>/Gain29'
                                        */
  uint8_T Gain11_Gain_f;               /* Computed Parameter: Gain11_Gain_f
                                        * Referenced by: '<S135>/Gain11'
                                        */
  uint8_T Gain12_Gain_o;               /* Computed Parameter: Gain12_Gain_o
                                        * Referenced by: '<S135>/Gain12'
                                        */
  uint8_T Gain13_Gain_g;               /* Computed Parameter: Gain13_Gain_g
                                        * Referenced by: '<S135>/Gain13'
                                        */
  uint8_T Gain14_Gain_i;               /* Computed Parameter: Gain14_Gain_i
                                        * Referenced by: '<S135>/Gain14'
                                        */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S33>/Output'
                                   */
  uint8_T LookupTable_tableData[5]; /* Computed Parameter: LookupTable_tableData
                                     * Referenced by: '<S27>/Lookup Table'
                                     */
  uint8_T LookupTable_bp01Data[5];   /* Computed Parameter: LookupTable_bp01Data
                                      * Referenced by: '<S27>/Lookup Table'
                                      */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S34>/FixPt Constant'
                                       */
  uint8_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S35>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PMSM_DemoBackup_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PMSM_DemoBackup_T PMSM_DemoBackup_P;

/* Block signals (default storage) */
extern B_PMSM_DemoBackup_T PMSM_DemoBackup_B;

/* Block states (default storage) */
extern DW_PMSM_DemoBackup_T PMSM_DemoBackup_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_PMSM_DemoBackup_T PMSM_DemoBackup_PrevZCX;

/* Model entry point functions */
extern void PMSM_DemoBackup_initialize(void);
extern void PMSM_DemoBackup_output(void);
extern void PMSM_DemoBackup_update(void);
extern void PMSM_DemoBackup_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PMSM_DemoBackup_T *const PMSM_DemoBackup_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PMSM_DemoBackup'
 * '<S1>'   : 'PMSM_DemoBackup/BuildTimestamp'
 * '<S2>'   : 'PMSM_DemoBackup/Control'
 * '<S3>'   : 'PMSM_DemoBackup/DIO_CLASS1_HWINT_BL1'
 * '<S4>'   : 'PMSM_DemoBackup/Enable_Inverter'
 * '<S5>'   : 'PMSM_DemoBackup/RTI Data'
 * '<S6>'   : 'PMSM_DemoBackup/Ref_value_gen'
 * '<S7>'   : 'PMSM_DemoBackup/TimerTask'
 * '<S8>'   : 'PMSM_DemoBackup/Control/Control_load_machine'
 * '<S9>'   : 'PMSM_DemoBackup/Control/Controller'
 * '<S10>'  : 'PMSM_DemoBackup/Control/Data Capture'
 * '<S11>'  : 'PMSM_DemoBackup/Control/Data Capture_short'
 * '<S12>'  : 'PMSM_DemoBackup/Control/Input'
 * '<S13>'  : 'PMSM_DemoBackup/Control/Output'
 * '<S14>'  : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig'
 * '<S15>'  : 'PMSM_DemoBackup/Control/Control_load_machine/DIO_CLASS1_PWM_BL1'
 * '<S16>'  : 'PMSM_DemoBackup/Control/Control_load_machine/duty_cycle_2_torque'
 * '<S17>'  : 'PMSM_DemoBackup/Control/Control_load_machine/torque_2_duty_cycle'
 * '<S18>'  : 'PMSM_DemoBackup/Control/Control_load_machine/torque_2_duty_cycle1'
 * '<S19>'  : 'PMSM_DemoBackup/Control/Control_load_machine/duty_cycle_2_torque/duty_cycle_2_voltage'
 * '<S20>'  : 'PMSM_DemoBackup/Control/Control_load_machine/torque_2_duty_cycle/voltage_2_duty_cycle'
 * '<S21>'  : 'PMSM_DemoBackup/Control/Control_load_machine/torque_2_duty_cycle1/voltage_2_duty_cycle'
 * '<S22>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER'
 * '<S23>'  : 'PMSM_DemoBackup/Control/Controller/SPACE_VECTOR_MODULATOR'
 * '<S24>'  : 'PMSM_DemoBackup/Control/Controller/SignalCollector'
 * '<S25>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/5x_mean_value'
 * '<S26>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/SignalCollector'
 * '<S27>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/Trigger_250us'
 * '<S28>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/angle_calculation'
 * '<S29>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller'
 * '<S30>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/i_set_source_SW'
 * '<S31>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller'
 * '<S32>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW'
 * '<S33>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/Trigger_250us/Counter Limited'
 * '<S34>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/Trigger_250us/Counter Limited/Increment Real World'
 * '<S35>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/Trigger_250us/Counter Limited/Wrap To Zero'
 * '<S36>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/angle_calculation/Lim[0...2*pi]'
 * '<S37>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT1'
 * '<S38>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT2'
 * '<S39>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/PI_CONTROLLER_id'
 * '<S40>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/PI_CONTROLLER_iq'
 * '<S41>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/SignalCollector'
 * '<S42>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/current transformation'
 * '<S43>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/current_transformation_disp'
 * '<S44>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/decoupling_and_voltage_limitation'
 * '<S45>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/manip_i_d'
 * '<S46>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/manip_i_q'
 * '<S47>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT1/discrete_Integrator_Init'
 * '<S48>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT1/discrete_Integrator_Init/Compare To Constant'
 * '<S49>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT1/discrete_Integrator_Init/Saturation'
 * '<S50>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT1/discrete_Integrator_Init/only_rising_edge '
 * '<S51>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT1/discrete_Integrator_Init/only_rising_edge /Compare To Constant1'
 * '<S52>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT1/discrete_Integrator_Init/only_rising_edge /Compare To Constant2'
 * '<S53>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT2/discrete_Integrator_Init'
 * '<S54>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT2/discrete_Integrator_Init/Compare To Constant'
 * '<S55>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT2/discrete_Integrator_Init/Saturation'
 * '<S56>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT2/discrete_Integrator_Init/only_rising_edge '
 * '<S57>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT2/discrete_Integrator_Init/only_rising_edge /Compare To Constant1'
 * '<S58>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/DISCRETE_PT2/discrete_Integrator_Init/only_rising_edge /Compare To Constant2'
 * '<S59>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/current transformation/transf'
 * '<S60>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/current_transformation_disp/transf'
 * '<S61>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/decoupling_and_voltage_limitation/Fieldweakening_Controller'
 * '<S62>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/decoupling_and_voltage_limitation/Limit_v_d_Decoupling'
 * '<S63>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/decoupling_and_voltage_limitation/Limit_v_q_Decoupling'
 * '<S64>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/decoupling_and_voltage_limitation/PMSM_Decoupling'
 * '<S65>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/decoupling_and_voltage_limitation/reverse_PMSM_Decoupling'
 * '<S66>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/decoupling_and_voltage_limitation/Fieldweakening_Controller/UnitConversion'
 * '<S67>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/decoupling_and_voltage_limitation/Limit_v_d_Decoupling/Saturation Dynamic'
 * '<S68>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/current_controller/decoupling_and_voltage_limitation/Limit_v_q_Decoupling/Saturation Dynamic'
 * '<S69>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/i_set_source_SW/Limit_id_Set'
 * '<S70>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/i_set_source_SW/Limit_iq_Set'
 * '<S71>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/i_set_source_SW/Limit_id_Set/Saturation Dynamic'
 * '<S72>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/i_set_source_SW/Limit_iq_Set/Saturation Dynamic'
 * '<S73>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1'
 * '<S74>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1_SET'
 * '<S75>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/Limit_n_Set'
 * '<S76>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/PI_CONTROLLER'
 * '<S77>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/SignalCollector'
 * '<S78>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1/discrete_Integrator_Init'
 * '<S79>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1/discrete_Integrator_Init/Compare To Constant'
 * '<S80>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1/discrete_Integrator_Init/Saturation'
 * '<S81>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1/discrete_Integrator_Init/only_rising_edge '
 * '<S82>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1/discrete_Integrator_Init/only_rising_edge /Compare To Constant1'
 * '<S83>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1/discrete_Integrator_Init/only_rising_edge /Compare To Constant2'
 * '<S84>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1_SET/discrete_Integrator_Init'
 * '<S85>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1_SET/discrete_Integrator_Init/Compare To Constant'
 * '<S86>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1_SET/discrete_Integrator_Init/Saturation'
 * '<S87>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1_SET/discrete_Integrator_Init/only_rising_edge '
 * '<S88>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1_SET/discrete_Integrator_Init/only_rising_edge /Compare To Constant1'
 * '<S89>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/DISCRETE_PT1_SET/discrete_Integrator_Init/only_rising_edge /Compare To Constant2'
 * '<S90>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/Limit_n_Set/Saturation Dynamic'
 * '<S91>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/speed_controller/PI_CONTROLLER/Saturation Dynamic'
 * '<S92>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Calc_Angle'
 * '<S93>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Label_v_Stator[a;b;c][V]'
 * '<S94>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/voltage transformation'
 * '<S95>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/voltage transformation1'
 * '<S96>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Calc_Angle/DISCRETE_INTEGRATOR'
 * '<S97>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Calc_Angle/Lim[0...2*pi]'
 * '<S98>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Calc_Angle/[rpm]2[rad|s]'
 * '<S99>'  : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Calc_Angle/DISCRETE_INTEGRATOR/Compare To Constant'
 * '<S100>' : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Calc_Angle/DISCRETE_INTEGRATOR/Saturation'
 * '<S101>' : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Calc_Angle/DISCRETE_INTEGRATOR/only_rising_edge '
 * '<S102>' : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Calc_Angle/DISCRETE_INTEGRATOR/only_rising_edge /Compare To Constant1'
 * '<S103>' : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/Calc_Angle/DISCRETE_INTEGRATOR/only_rising_edge /Compare To Constant2'
 * '<S104>' : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/voltage transformation/transf'
 * '<S105>' : 'PMSM_DemoBackup/Control/Controller/PMSM_CONTROLLER/v_set_source_SW/voltage transformation1/transf'
 * '<S106>' : 'PMSM_DemoBackup/Control/Controller/SPACE_VECTOR_MODULATOR/Label_DutyCycle_HSD[a;b;c][0_1]'
 * '<S107>' : 'PMSM_DemoBackup/Control/Controller/SPACE_VECTOR_MODULATOR/Label_DutyCycle_LSD[a;b;c][0_1]'
 * '<S108>' : 'PMSM_DemoBackup/Control/Controller/SPACE_VECTOR_MODULATOR/SignalCollector'
 * '<S109>' : 'PMSM_DemoBackup/Control/Input/AD_Measurement'
 * '<S110>' : 'PMSM_DemoBackup/Control/Input/DISCRETE_PT1'
 * '<S111>' : 'PMSM_DemoBackup/Control/Input/DS1202_SENSOR_SUPPLY'
 * '<S112>' : 'PMSM_DemoBackup/Control/Input/EMC_ENCODER_BL2'
 * '<S113>' : 'PMSM_DemoBackup/Control/Input/EMC_HALL_BL2'
 * '<S114>' : 'PMSM_DemoBackup/Control/Input/EMC_MOTOR_SETUP_BL1'
 * '<S115>' : 'PMSM_DemoBackup/Control/Input/SignalCollector1'
 * '<S116>' : 'PMSM_DemoBackup/Control/Input/check_apu_sensor'
 * '<S117>' : 'PMSM_DemoBackup/Control/Input/check_inc_valid'
 * '<S118>' : 'PMSM_DemoBackup/Control/Input/dummy_hall_signals'
 * '<S119>' : 'PMSM_DemoBackup/Control/Input/mech2elec'
 * '<S120>' : 'PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL1'
 * '<S121>' : 'PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL2'
 * '<S122>' : 'PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL3'
 * '<S123>' : 'PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL4'
 * '<S124>' : 'PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL5'
 * '<S125>' : 'PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL6'
 * '<S126>' : 'PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL7'
 * '<S127>' : 'PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL8'
 * '<S128>' : 'PMSM_DemoBackup/Control/Input/DISCRETE_PT1/discrete_Integrator_Init'
 * '<S129>' : 'PMSM_DemoBackup/Control/Input/DISCRETE_PT1/discrete_Integrator_Init/Compare To Constant'
 * '<S130>' : 'PMSM_DemoBackup/Control/Input/DISCRETE_PT1/discrete_Integrator_Init/Saturation'
 * '<S131>' : 'PMSM_DemoBackup/Control/Input/DISCRETE_PT1/discrete_Integrator_Init/only_rising_edge '
 * '<S132>' : 'PMSM_DemoBackup/Control/Input/DISCRETE_PT1/discrete_Integrator_Init/only_rising_edge /Compare To Constant1'
 * '<S133>' : 'PMSM_DemoBackup/Control/Input/DISCRETE_PT1/discrete_Integrator_Init/only_rising_edge /Compare To Constant2'
 * '<S134>' : 'PMSM_DemoBackup/Control/Output/EMC_MC_PWM_BL1'
 * '<S135>' : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig/MDL_DISP'
 * '<S136>' : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig/MDL_DISP_INPUT'
 * '<S137>' : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig/MDL_PAR'
 * '<S138>' : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig/MDL_DISP/Compare To Constant'
 * '<S139>' : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig/MDL_DISP/Compare To Constant1'
 * '<S140>' : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig/MDL_DISP/Compare To Constant2'
 * '<S141>' : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig/MDL_DISP/Compare To Constant3'
 * '<S142>' : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig/MDL_DISP/Compare To Constant4'
 * '<S143>' : 'PMSM_DemoBackup/Control/pmsm_ctrl_par_sig/MDL_DISP/Compare To Constant5'
 * '<S144>' : 'PMSM_DemoBackup/DIO_CLASS1_HWINT_BL1/Common Hardware Interrupt Interface'
 * '<S145>' : 'PMSM_DemoBackup/Enable_Inverter/DIO_CLASS1_BIT_OUT_BL2'
 * '<S146>' : 'PMSM_DemoBackup/Enable_Inverter/TimerTask'
 * '<S147>' : 'PMSM_DemoBackup/RTI Data/RTI Data Store'
 * '<S148>' : 'PMSM_DemoBackup/RTI Data/RTI Data Store/RTI Data Store'
 * '<S149>' : 'PMSM_DemoBackup/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S150>' : 'PMSM_DemoBackup/Ref_value_gen/Enabled and Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_PMSM_DemoBackup_h_ */
