/*
 * Module_Test_5V_private.h
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

#ifndef RTW_HEADER_Module_Test_5V_private_h_
#define RTW_HEADER_Module_Test_5V_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

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

extern AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_1;
extern AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_2;
extern AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_3;
extern AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_4;
extern AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_5;
extern AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_6;
extern AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_7;
extern AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_8;
extern DacCl1AnalogOutSDrvObject *pRTIDacC1AnalogOut_Ch_1;
extern DioCl1DigInSDrvObject *pRTIDioC1DigIn_Port_2_Ch_9;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_1;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_2_Ch_1;
extern SensorSupplySDrvObject *pRTI_Sensor_Supply;

#endif                                /* RTW_HEADER_Module_Test_5V_private_h_ */
