/*
 * PMSM_DemoBackup_private.h
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

#ifndef RTW_HEADER_PMSM_DemoBackup_private_h_
#define RTW_HEADER_PMSM_DemoBackup_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "PMSM_DemoBackup.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_1;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_5;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_7;
extern DioCl1EncoderInSDrvObject *pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4;
extern DioCl1HallInSDrvObject *pEmcHall_Unit1_DioCl1_Port1_Ch1;
extern AcuSDrvObject *pRTIEmcAcu_Unit_1;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_3;
extern DioCl1MultiPwmOutSDrvObject *pRTIEmcMultiPwmOut_Port_1_Ch_7;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_2;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_4;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_6;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_8;
extern SensorSupplySDrvObject *pRTI_Sensor_Supply;
extern DioCl1PwmOutSDrvObject *pRTIDioC1PwmOut_Port_1_Ch_13;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_15;
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern uint8_T look1_iu8lu32n31Ds16_binlcf(uint8_T u0, const uint8_T bp0[],
  const uint8_T table[], uint32_T maxIndex);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift);
extern uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator,
  uint32_T nRepeatSub);
extern void PMSM_DemoBackup_Control_Init(void);
extern void PMSM_DemoBackup_Control_Reset(void);
extern void PMSM_DemoBackup_Control(void);
extern void PMSM_DemoBackup_Control_Term(void);

#endif                               /* RTW_HEADER_PMSM_DemoBackup_private_h_ */
