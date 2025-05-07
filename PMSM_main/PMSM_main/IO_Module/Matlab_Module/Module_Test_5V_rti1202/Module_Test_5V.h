/*
 * Module_Test_5V.h
 *
 * Code generation for model "Module_Test_5V".
 *
 * Model version              : 1.26
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Mon Jun 10 11:21:27 2024
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Module_Test_5V_h_
#define RTW_HEADER_Module_Test_5V_h_
#include <string.h>
#ifndef Module_Test_5V_COMMON_INCLUDES_
# define Module_Test_5V_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Module_Test_5V_COMMON_INCLUDES_ */

#include "Module_Test_5V_types.h"

/* Shared type includes */
#include "multiword_types.h"

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
  real_T SFunction1;                   /* '<S7>/S-Function1' */
  real_T ADC1;                         /* '<S1>/Gain' */
  real_T SFunction1_k;                 /* '<S8>/S-Function1' */
  real_T ADC2;                         /* '<S1>/Gain1' */
  real_T SFunction1_h;                 /* '<S9>/S-Function1' */
  real_T ADC3;                         /* '<S1>/Gain2' */
  real_T SFunction1_a;                 /* '<S10>/S-Function1' */
  real_T ADC4;                         /* '<S1>/Gain3' */
  real_T SFunction1_e;                 /* '<S11>/S-Function1' */
  real_T ADC5;                         /* '<S1>/Gain4' */
  real_T SFunction1_em;                /* '<S12>/S-Function1' */
  real_T ADC6;                         /* '<S1>/Gain5' */
  real_T SFunction1_i;                 /* '<S13>/S-Function1' */
  real_T ADC7;                         /* '<S1>/Gain6' */
  real_T SFunction1_g;                 /* '<S14>/S-Function1' */
  real_T ADC8;                         /* '<S1>/Gain7' */
  real_T Gain[16];                     /* '<S2>/Gain' */
  real_T DataTypeConversion[16];       /* '<S2>/Data Type Conversion' */
  real_T DataTypeConversion_a[8];      /* '<S3>/Data Type Conversion' */
  real_T Step;                         /* '<S4>/Step' */
  real_T Switch[16];                   /* '<S4>/Switch' */
  real_T Step1;                        /* '<S4>/Step1' */
  real_T Switch1[8];                   /* '<S4>/Switch1' */
  boolean_T SFunction1_p[8];           /* '<S16>/S-Function1' */
  boolean_T NOT[16];                   /* '<S4>/NOT' */
  boolean_T DataTypeConversion_i[16];  /* '<S4>/Data Type Conversion' */
  boolean_T NOT1[8];                   /* '<S4>/NOT1' */
  boolean_T DataTypeConversion1[8];    /* '<S4>/Data Type Conversion1' */
} B_Module_Test_5V_T;

/* Parameters (default storage) */
struct P_Module_Test_5V_T_ {
  real_T Gain_Gain;                    /* Expression: 10
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 10
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 10
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 10
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 10
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 10
                                        * Referenced by: '<S1>/Gain5'
                                        */
  real_T Gain6_Gain;                   /* Expression: 10
                                        * Referenced by: '<S1>/Gain6'
                                        */
  real_T Gain7_Gain;                   /* Expression: 10
                                        * Referenced by: '<S1>/Gain7'
                                        */
  real_T Constant_Value[16];           /* Expression: zeros(1,16)
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 0.1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Constant_Value_b[16];         /* Expression: zeros(1,16)
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Step_Time;                    /* Expression: 2
                                        * Referenced by: '<S4>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S4>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S4>/Step'
                                        */
  real_T Constant1_Value[16];          /* Expression: zeros(1,16)
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Constant2_Value[8];           /* Expression: zeros(1,8)
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Step1_Time;                   /* Expression: 2
                                        * Referenced by: '<S4>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S4>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S4>/Step1'
                                        */
  real_T Constant3_Value[8];           /* Expression: zeros(1,8)
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S4>/Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Module_Test_5V_T {
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
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Module_Test_5V_T Module_Test_5V_P;

/* Block signals (default storage) */
extern B_Module_Test_5V_T Module_Test_5V_B;

/* Model entry point functions */
extern void Module_Test_5V_initialize(void);
extern void Module_Test_5V_output(void);
extern void Module_Test_5V_update(void);
extern void Module_Test_5V_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Module_Test_5V_T *const Module_Test_5V_M;

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
 * '<Root>' : 'Module_Test_5V'
 * '<S1>'   : 'Module_Test_5V/ANALOG_IN'
 * '<S2>'   : 'Module_Test_5V/ANALOG_OUT'
 * '<S3>'   : 'Module_Test_5V/DIGITAL_IN'
 * '<S4>'   : 'Module_Test_5V/DIGITAL_OUT'
 * '<S5>'   : 'Module_Test_5V/DS1202_SENSOR_SUPPLY'
 * '<S6>'   : 'Module_Test_5V/RTI Data'
 * '<S7>'   : 'Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL1'
 * '<S8>'   : 'Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL2'
 * '<S9>'   : 'Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL3'
 * '<S10>'  : 'Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL4'
 * '<S11>'  : 'Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL5'
 * '<S12>'  : 'Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL6'
 * '<S13>'  : 'Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL7'
 * '<S14>'  : 'Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL8'
 * '<S15>'  : 'Module_Test_5V/ANALOG_OUT/DAC_CLASS1_BL1'
 * '<S16>'  : 'Module_Test_5V/DIGITAL_IN/DIO_CLASS1_BIT_IN_BL1'
 * '<S17>'  : 'Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL1'
 * '<S18>'  : 'Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL2'
 * '<S19>'  : 'Module_Test_5V/RTI Data/RTI Data Store'
 * '<S20>'  : 'Module_Test_5V/RTI Data/RTI Data Store/RTI Data Store'
 * '<S21>'  : 'Module_Test_5V/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_Module_Test_5V_h_ */
