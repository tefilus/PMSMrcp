/*
 * Module_Test_5V.c
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

#include "Module_Test_5V_trc_ptr.h"
#include "Module_Test_5V.h"
#include "Module_Test_5V_private.h"

/* Block signals (default storage) */
B_Module_Test_5V_T Module_Test_5V_B;

/* Real-time model */
RT_MODEL_Module_Test_5V_T Module_Test_5V_M_;
RT_MODEL_Module_Test_5V_T *const Module_Test_5V_M = &Module_Test_5V_M_;

/* Model output function */
void Module_Test_5V_output(void)
{
  real_T currentTime;
  int32_T i;

  /* S-Function (rti_commonblock): '<S7>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S1>/Gain' */
  Module_Test_5V_B.ADC1 = Module_Test_5V_P.Gain_Gain *
    Module_Test_5V_B.SFunction1;

  /* S-Function (rti_commonblock): '<S8>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S1>/Gain1' */
  Module_Test_5V_B.ADC2 = Module_Test_5V_P.Gain1_Gain *
    Module_Test_5V_B.SFunction1_k;

  /* S-Function (rti_commonblock): '<S9>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S1>/Gain2' */
  Module_Test_5V_B.ADC3 = Module_Test_5V_P.Gain2_Gain *
    Module_Test_5V_B.SFunction1_h;

  /* S-Function (rti_commonblock): '<S10>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S1>/Gain3' */
  Module_Test_5V_B.ADC4 = Module_Test_5V_P.Gain3_Gain *
    Module_Test_5V_B.SFunction1_a;

  /* S-Function (rti_commonblock): '<S11>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S1>/Gain4' */
  Module_Test_5V_B.ADC5 = Module_Test_5V_P.Gain4_Gain *
    Module_Test_5V_B.SFunction1_e;

  /* S-Function (rti_commonblock): '<S12>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S1>/Gain5' */
  Module_Test_5V_B.ADC6 = Module_Test_5V_P.Gain5_Gain *
    Module_Test_5V_B.SFunction1_em;

  /* S-Function (rti_commonblock): '<S13>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S1>/Gain6' */
  Module_Test_5V_B.ADC7 = Module_Test_5V_P.Gain6_Gain *
    Module_Test_5V_B.SFunction1_i;

  /* S-Function (rti_commonblock): '<S14>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S1>/Gain7' */
  Module_Test_5V_B.ADC8 = Module_Test_5V_P.Gain7_Gain *
    Module_Test_5V_B.SFunction1_g;

  /* Gain: '<S2>/Gain' incorporates:
   *  Constant: '<S2>/Constant'
   */
  for (i = 0; i < 16; i++) {
    Module_Test_5V_B.Gain[i] = Module_Test_5V_P.Gain_Gain_c *
      Module_Test_5V_P.Constant_Value[i];
  }

  /* End of Gain: '<S2>/Gain' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  memcpy(&Module_Test_5V_B.DataTypeConversion[0], &Module_Test_5V_B.Gain[0],
         sizeof(real_T) << 4U);

  /* S-Function (rti_commonblock): '<S15>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- Module_Test_5V/ANALOG_OUT/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 1 --- */
  {
    /* define variables required for DAC realtime functions */
    Float64 inportDacData= 0.0;
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[0];

    /* write value of CL1 DAC for output channel 1 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_CHANNEL_1,
      inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[1];

    /* write value of CL1 DAC for output channel 2 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_CHANNEL_2,
      inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[2];

    /* write value of CL1 DAC for output channel 3 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_CHANNEL_3,
      inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[3];

    /* write value of CL1 DAC for output channel 4 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_CHANNEL_4,
      inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[4];

    /* write value of CL1 DAC for output channel 5 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_CHANNEL_5,
      inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[5];

    /* write value of CL1 DAC for output channel 6 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_CHANNEL_6,
      inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[6];

    /* write value of CL1 DAC for output channel 7 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_CHANNEL_7,
      inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[7];

    /* write value of CL1 DAC for output channel 8 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_CHANNEL_8,
      inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[8];

    /* write value of CL1 DAC for output channel 9 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_CHANNEL_9,
      inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[9];

    /* write value of CL1 DAC for output channel 10 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_10, inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[10];

    /* write value of CL1 DAC for output channel 11 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_11, inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[11];

    /* write value of CL1 DAC for output channel 12 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_12, inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[12];

    /* write value of CL1 DAC for output channel 13 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_13, inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[13];

    /* write value of CL1 DAC for output channel 14 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_14, inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[14];

    /* write value of CL1 DAC for output channel 15 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_15, inportDacData);
    inportDacData = (real_T) Module_Test_5V_B.DataTypeConversion[15];

    /* write value of CL1 DAC for output channel 16 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_16, inportDacData);
    DacCl1AnalogOut_write(pRTIDacC1AnalogOut_Ch_1);
  }

  /* S-Function (rti_commonblock): '<S16>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  for (i = 0; i < 8; i++) {
    Module_Test_5V_B.DataTypeConversion_a[i] = Module_Test_5V_B.SFunction1_p[i];
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* Step: '<S4>/Step' */
  currentTime = Module_Test_5V_M->Timing.t[0];
  if (currentTime < Module_Test_5V_P.Step_Time) {
    Module_Test_5V_B.Step = Module_Test_5V_P.Step_Y0;
  } else {
    Module_Test_5V_B.Step = Module_Test_5V_P.Step_YFinal;
  }

  /* End of Step: '<S4>/Step' */
  for (i = 0; i < 16; i++) {
    /* Logic: '<S4>/NOT' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    Module_Test_5V_B.NOT[i] = !(Module_Test_5V_P.Constant1_Value[i] != 0.0);

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    if (Module_Test_5V_B.Step > Module_Test_5V_P.Switch_Threshold) {
      Module_Test_5V_B.Switch[i] = Module_Test_5V_P.Constant_Value_b[i];
    } else {
      Module_Test_5V_B.Switch[i] = Module_Test_5V_B.NOT[i];
    }

    /* End of Switch: '<S4>/Switch' */
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  for (i = 0; i < 16; i++) {
    Module_Test_5V_B.DataTypeConversion_i[i] = (Module_Test_5V_B.Switch[i] !=
      0.0);
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (rti_commonblock): '<S17>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 1 --- */
  {
    /* define variables required for BitOut realtime functions */
    UInt32 outputData = 0;

    /* write output state value to digital output channel 1-16 on port 1 */
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[0]) << (1 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[1]) << (2 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[2]) << (3 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[3]) << (4 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[4]) << (5 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[5]) << (6 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[6]) << (7 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[7]) << (8 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[8]) << (9 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[9]) << (10
      - 1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[10]) << (11
      - 1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[11]) << (12
      - 1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[12]) << (13
      - 1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[13]) << (14
      - 1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[14]) << (15
      - 1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion_i[15]) << (16
      - 1)) | outputData);
    DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_1, outputData);
    DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_1);
  }

  /* Step: '<S4>/Step1' */
  currentTime = Module_Test_5V_M->Timing.t[0];
  if (currentTime < Module_Test_5V_P.Step1_Time) {
    Module_Test_5V_B.Step1 = Module_Test_5V_P.Step1_Y0;
  } else {
    Module_Test_5V_B.Step1 = Module_Test_5V_P.Step1_YFinal;
  }

  /* End of Step: '<S4>/Step1' */
  for (i = 0; i < 8; i++) {
    /* Logic: '<S4>/NOT1' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    Module_Test_5V_B.NOT1[i] = !(Module_Test_5V_P.Constant3_Value[i] != 0.0);

    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S4>/Constant2'
     */
    if (Module_Test_5V_B.Step1 > Module_Test_5V_P.Switch1_Threshold) {
      Module_Test_5V_B.Switch1[i] = Module_Test_5V_P.Constant2_Value[i];
    } else {
      Module_Test_5V_B.Switch1[i] = Module_Test_5V_B.NOT1[i];
    }

    /* End of Switch: '<S4>/Switch1' */
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  for (i = 0; i < 8; i++) {
    Module_Test_5V_B.DataTypeConversion1[i] = (Module_Test_5V_B.Switch1[i] !=
      0.0);
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion1' */

  /* S-Function (rti_commonblock): '<S18>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 2 - Channel: 1 --- */
  {
    /* define variables required for BitOut realtime functions */
    UInt32 outputData = 0;

    /* write output state value to digital output channel 1-8 on port 2 */
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion1[0]) << (1 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion1[1]) << (2 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion1[2]) << (3 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion1[3]) << (4 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion1[4]) << (5 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion1[5]) << (6 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion1[6]) << (7 -
      1)) | outputData);
    outputData = ( ( ( (UInt32)Module_Test_5V_B.DataTypeConversion1[7]) << (8 -
      1)) | outputData);
    DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_2_Ch_1, outputData);
    DioCl1DigOut_write(pRTIDioC1DigOut_Port_2_Ch_1);
  }

  /* S-Function (rti_commonblock): '<S5>/S-Function1' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
void Module_Test_5V_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Module_Test_5V_M->Timing.clockTick0)) {
    ++Module_Test_5V_M->Timing.clockTickH0;
  }

  Module_Test_5V_M->Timing.t[0] = Module_Test_5V_M->Timing.clockTick0 *
    Module_Test_5V_M->Timing.stepSize0 + Module_Test_5V_M->Timing.clockTickH0 *
    Module_Test_5V_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Module_Test_5V_M->Timing.clockTick1++;
    if (!Module_Test_5V_M->Timing.clockTick1) {
      Module_Test_5V_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void Module_Test_5V_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Module_Test_5V_M, 0,
                sizeof(RT_MODEL_Module_Test_5V_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Module_Test_5V_M->solverInfo,
                          &Module_Test_5V_M->Timing.simTimeStep);
    rtsiSetTPtr(&Module_Test_5V_M->solverInfo, &rtmGetTPtr(Module_Test_5V_M));
    rtsiSetStepSizePtr(&Module_Test_5V_M->solverInfo,
                       &Module_Test_5V_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Module_Test_5V_M->solverInfo, (&rtmGetErrorStatus
      (Module_Test_5V_M)));
    rtsiSetRTModelPtr(&Module_Test_5V_M->solverInfo, Module_Test_5V_M);
  }

  rtsiSetSimTimeStep(&Module_Test_5V_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Module_Test_5V_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Module_Test_5V_M, &Module_Test_5V_M->Timing.tArray[0]);
  Module_Test_5V_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &Module_Test_5V_B), 0,
                sizeof(B_Module_Test_5V_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Module_Test_5V_rti_init_trc_pointers();
  }
}

/* Model terminate function */
void Module_Test_5V_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S15>/S-Function1' */

  /* --- Module_Test_5V/ANALOG_OUT/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 1 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_1);

  /* Terminate for S-Function (rti_commonblock): '<S17>/S-Function1' */

  /* --- Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 1 --- */

  /* disable digital output channel 1-16 on port 1 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_1,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_1);

  /* Terminate for S-Function (rti_commonblock): '<S18>/S-Function1' */

  /* --- Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 2 - Channel: 1 --- */

  /* disable digital output channel 1-8 on port 2 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_2_Ch_1,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_2_Ch_1);
}
