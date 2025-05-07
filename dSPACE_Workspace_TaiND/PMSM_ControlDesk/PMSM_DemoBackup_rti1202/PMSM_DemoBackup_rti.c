/*********************** dSPACE target specific file *************************

   Include file PMSM_DemoBackup_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1202 7.15 (02-Nov-2020)
   Tue May  7 13:37:16 2024

   Copyright 2024, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "PMSM_DemoBackup.h"
#include "PMSM_DemoBackup_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             PMSM_DemoBackup_B
#define RTP_STRUCTURE_NAME             PMSM_DemoBackup_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#ifndef dsRtmGetNumSampleTimes
# define dsRtmGetNumSampleTimes(rtm)   3
#endif

#ifndef dsRtmGetTPtr
# define dsRtmGetTPtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef dsRtmSetTaskTime
# define dsRtmSetTaskTime(rtm, sti, val) (dsRtmGetTPtr((rtm))[sti] = (val))
#endif

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/****** Definitions: task functions for HW interrupts *******************/

/* HW Interrupt: <S3>/Common Hardware Interrupt Interface */
static void rti_120XDIOCL1MCPWM_MID_OF_PERIODP1Ch7(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  {
    /* {S!d2362}RateTransition generated from: '<S6>/Rate Transition' */
    switch (PMSM_DemoBackup_DW.RateTransition_1_write_buf) {
     case 0:
      PMSM_DemoBackup_DW.RateTransition_1_read_buf = 1;
      break;

     case 1:
      PMSM_DemoBackup_DW.RateTransition_1_read_buf = 0;
      break;

     default:
      PMSM_DemoBackup_DW.RateTransition_1_read_buf =
        PMSM_DemoBackup_DW.RateTransition_1_last_buf_wr;
      break;
    }

    if (PMSM_DemoBackup_DW.RateTransition_1_read_buf != 0) {
      PMSM_DemoBackup_B.Sig_gen_n_i =
        PMSM_DemoBackup_DW.RateTransition_1_Buffer1;
    } else {
      PMSM_DemoBackup_B.Sig_gen_n_i =
        PMSM_DemoBackup_DW.RateTransition_1_Buffer0;
    }

    PMSM_DemoBackup_DW.RateTransition_1_read_buf = -1;

    /* {S!d2364}RateTransition generated from: '<S6>/Rate Transition' */
    switch (PMSM_DemoBackup_DW.RateTransition_2_write_buf) {
     case 0:
      PMSM_DemoBackup_DW.RateTransition_2_read_buf = 1;
      break;

     case 1:
      PMSM_DemoBackup_DW.RateTransition_2_read_buf = 0;
      break;

     default:
      PMSM_DemoBackup_DW.RateTransition_2_read_buf =
        PMSM_DemoBackup_DW.RateTransition_2_last_buf_wr;
      break;
    }

    if (PMSM_DemoBackup_DW.RateTransition_2_read_buf != 0) {
      PMSM_DemoBackup_B.Choose_ref_value_n_g =
        PMSM_DemoBackup_DW.RateTransition_2_Buffer1;
    } else {
      PMSM_DemoBackup_B.Choose_ref_value_n_g =
        PMSM_DemoBackup_DW.RateTransition_2_Buffer0;
    }

    PMSM_DemoBackup_DW.RateTransition_2_read_buf = -1;

    /* {S!d2366}RateTransition generated from: '<S6>/Rate Transition' */
    switch (PMSM_DemoBackup_DW.RateTransition_3_write_buf) {
     case 0:
      PMSM_DemoBackup_DW.RateTransition_3_read_buf = 1;
      break;

     case 1:
      PMSM_DemoBackup_DW.RateTransition_3_read_buf = 0;
      break;

     default:
      PMSM_DemoBackup_DW.RateTransition_3_read_buf =
        PMSM_DemoBackup_DW.RateTransition_3_last_buf_wr;
      break;
    }

    if (PMSM_DemoBackup_DW.RateTransition_3_read_buf != 0) {
      PMSM_DemoBackup_B.ref_value_n_o =
        PMSM_DemoBackup_DW.RateTransition_3_Buffer1;
    } else {
      PMSM_DemoBackup_B.ref_value_n_o =
        PMSM_DemoBackup_DW.RateTransition_3_Buffer0;
    }

    PMSM_DemoBackup_DW.RateTransition_3_read_buf = -1;

    /* {S!d2368}RateTransition generated from: '<S6>/Rate Transition' */
    switch (PMSM_DemoBackup_DW.RateTransition_4_write_buf) {
     case 0:
      PMSM_DemoBackup_DW.RateTransition_4_read_buf = 1;
      break;

     case 1:
      PMSM_DemoBackup_DW.RateTransition_4_read_buf = 0;
      break;

     default:
      PMSM_DemoBackup_DW.RateTransition_4_read_buf =
        PMSM_DemoBackup_DW.RateTransition_4_last_buf_wr;
      break;
    }

    if (PMSM_DemoBackup_DW.RateTransition_4_read_buf != 0) {
      PMSM_DemoBackup_B.load_machine_ref =
        PMSM_DemoBackup_DW.RateTransition_4_Buffer1;
    } else {
      PMSM_DemoBackup_B.load_machine_ref =
        PMSM_DemoBackup_DW.RateTransition_4_Buffer0;
    }

    PMSM_DemoBackup_DW.RateTransition_4_read_buf = -1;

    /* {S!d2370}RateTransition generated from: '<S6>/Rate Transition' */
    switch (PMSM_DemoBackup_DW.RateTransition_5_write_buf) {
     case 0:
      PMSM_DemoBackup_DW.RateTransition_5_read_buf = 1;
      break;

     case 1:
      PMSM_DemoBackup_DW.RateTransition_5_read_buf = 0;
      break;

     default:
      PMSM_DemoBackup_DW.RateTransition_5_read_buf =
        PMSM_DemoBackup_DW.RateTransition_5_last_buf_wr;
      break;
    }

    if (PMSM_DemoBackup_DW.RateTransition_5_read_buf != 0) {
      PMSM_DemoBackup_B.Choose_ref_value_i_m =
        PMSM_DemoBackup_DW.RateTransition_5_Buffer1;
    } else {
      PMSM_DemoBackup_B.Choose_ref_value_i_m =
        PMSM_DemoBackup_DW.RateTransition_5_Buffer0;
    }

    PMSM_DemoBackup_DW.RateTransition_5_read_buf = -1;

    /* {S!d2372}RateTransition generated from: '<S6>/Rate Transition' */
    switch (PMSM_DemoBackup_DW.RateTransition_6_write_buf) {
     case 0:
      PMSM_DemoBackup_DW.RateTransition_6_read_buf = 1;
      break;

     case 1:
      PMSM_DemoBackup_DW.RateTransition_6_read_buf = 0;
      break;

     default:
      PMSM_DemoBackup_DW.RateTransition_6_read_buf =
        PMSM_DemoBackup_DW.RateTransition_6_last_buf_wr;
      break;
    }

    if (PMSM_DemoBackup_DW.RateTransition_6_read_buf != 0) {
      PMSM_DemoBackup_B.ref_value_iq_i =
        PMSM_DemoBackup_DW.RateTransition_6_Buffer1;
    } else {
      PMSM_DemoBackup_B.ref_value_iq_i =
        PMSM_DemoBackup_DW.RateTransition_6_Buffer0;
    }

    PMSM_DemoBackup_DW.RateTransition_6_read_buf = -1;

    /* {S!d2359}S-Function (rti_commonblock): '<S144>/S-Function1' */
    PMSM_DemoBackup_Control();

    /* {E!d2359}End of Outputs for S-Function (rti_commonblock): '<S144>/S-Function1' */
  }

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_1;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_5;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_7;
DioCl1EncoderInSDrvObject *pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4;
DioCl1HallInSDrvObject *pEmcHall_Unit1_DioCl1_Port1_Ch1;
AcuSDrvObject *pRTIEmcAcu_Unit_1;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_3;
DioCl1MultiPwmOutSDrvObject *pRTIEmcMultiPwmOut_Port_1_Ch_7;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_2;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_4;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_6;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_8;
SensorSupplySDrvObject *pRTI_Sensor_Supply;
DioCl1PwmOutSDrvObject *pRTIDioC1PwmOut_Port_1_Ch_13;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_15;

/* ===== Definition of interface functions for simulation engine =========== */
#if GRTINTERFACE == 1
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#else
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

# define dsIsSampleHit(RTM,sti)        rtmStepTask(RTM, sti)
#endif

#undef __INLINE
#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

/*Define additional variables*/
static time_T dsTFinal = -1.0;

#define dsGetTFinal(rtm)               (dsTFinal)

static time_T dsStepSize = 0.001;

# define dsGetStepSize(rtm)            (dsStepSize)

static void rti_mdl_initialize_host_services(void)
{
  DsDaq_Init(0, 32, 1);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1202, (void *) 0,
                        VCM_TXT_RTI1202, 7, 15, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 9, 8, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 10, 1, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 9, 3, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW, msg_mod_ptr,
                          VCM_TXT_STATEFLOW, 10, 2, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW_CODER, msg_mod_ptr,
                          VCM_TXT_STATEFLOW_CODER, 9, 3, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS120XSTDADCC1 #0 */
  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_1 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_1,
      ADC_CLASS1_CHANNEL_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_1 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_1,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_1,
      ADC_CLASS1_TRIGGER_TRIG_LINE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setTriggerLineIn(pRTIAdcC1AnalogIn_Ch_1,
      ADC_CLASS1_TRIGGER_LINE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL5 --- */
  /* --- [RTI120X, ADC C1] - Channel: 5 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_5 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_5,
      ADC_CLASS1_CHANNEL_5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_5 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_5,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_5,
      ADC_CLASS1_TRIGGER_TRIG_LINE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setTriggerLineIn(pRTIAdcC1AnalogIn_Ch_5,
      ADC_CLASS1_TRIGGER_LINE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL7 --- */
  /* --- [RTI120X, ADC C1] - Channel: 7 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_7 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_7,
      ADC_CLASS1_CHANNEL_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_7 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_7,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_7,
      ADC_CLASS1_TRIGGER_TRIG_LINE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setTriggerLineIn(pRTIAdcC1AnalogIn_Ch_7,
      ADC_CLASS1_TRIGGER_LINE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL3 --- */
  /* --- [RTI120X, ADC C1] - Channel: 3 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_3 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_3,
      ADC_CLASS1_CHANNEL_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_3 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_3,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_3,
      ADC_CLASS1_TRIGGER_TRIG_LINE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setTriggerLineIn(pRTIAdcC1AnalogIn_Ch_3,
      ADC_CLASS1_TRIGGER_LINE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL2 --- */
  /* --- [RTI120X, ADC C1] - Channel: 2 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_2 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_2,
      ADC_CLASS1_CHANNEL_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_2 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_2,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_2,
      ADC_CLASS1_TRIGGER_TRIG_LINE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setTriggerLineIn(pRTIAdcC1AnalogIn_Ch_2,
      ADC_CLASS1_TRIGGER_LINE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL4 --- */
  /* --- [RTI120X, ADC C1] - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_4 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_4,
      ADC_CLASS1_CHANNEL_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_4 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_4,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_4,
      ADC_CLASS1_TRIGGER_TRIG_LINE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setTriggerLineIn(pRTIAdcC1AnalogIn_Ch_4,
      ADC_CLASS1_TRIGGER_LINE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL6 --- */
  /* --- [RTI120X, ADC C1] - Channel: 6 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_6 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_6,
      ADC_CLASS1_CHANNEL_6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_6 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_6,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_6,
      ADC_CLASS1_TRIGGER_TRIG_LINE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setTriggerLineIn(pRTIAdcC1AnalogIn_Ch_6,
      ADC_CLASS1_TRIGGER_LINE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL8 --- */
  /* --- [RTI120X, ADC C1] - Channel: 8 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_8 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_8,
      ADC_CLASS1_CHANNEL_8);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_8 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_8,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_8,
      ADC_CLASS1_TRIGGER_TRIG_LINE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setTriggerLineIn(pRTIAdcC1AnalogIn_Ch_8,
      ADC_CLASS1_TRIGGER_LINE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 */

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 Group:ADC */
  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_1 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL5 --- */
  /* --- [RTI120X, ADC C1] - Channel: 5 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_5 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL7 --- */
  /* --- [RTI120X, ADC C1] - Channel: 7 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_7 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL3 --- */
  /* --- [RTI120X, ADC C1] - Channel: 3 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_3 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL2 --- */
  /* --- [RTI120X, ADC C1] - Channel: 2 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_2 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL4 --- */
  /* --- [RTI120X, ADC C1] - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_4 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL6 --- */
  /* --- [RTI120X, ADC C1] - Channel: 6 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_6 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL8 --- */
  /* --- [RTI120X, ADC C1] - Channel: 8 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_8 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_8);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_8);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Create EMC Encoder driver object pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4 */
    ioErrorRetValue = DioCl1EncoderIn_create
      (&pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4, DIO_CLASS1_PORT_1,
       DIO_CLASS1_CHANNEL_4, DIO_ENC_INSTANCE_1, DIO_ENC_IUSAGE_ENABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* -- Angle measurement enabled -- */

    /* Sets number of encoder lines for the selected incremental Encoder */
    ioErrorRetValue = DioCl1EncoderIn_setEncoderLines
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4, (UInt32) 2500U);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets minimum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl1EncoderIn_setMinPosition
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4, (Float64) 0.0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets maximum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl1EncoderIn_setMaxPosition
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4, (Float64) 2499.75);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets index signal usage mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl1EncoderIn_setIndexMode
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4, (Float64)
       DIO_ENC_IMODE_EVERY_INDEX);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets index position for the selected incremental Encoder on index signal detection (in lines) */
    ioErrorRetValue = DioCl1EncoderIn_setIndexPosition
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4, (Float64) 2451.3888888888891);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* no user specific minimum mechanical velocity used */

    /* Sets gated mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl1EncoderIn_setGatedMode
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4, DIO_ENC_IUSAGE_ENABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorRetValue = DioCl1EncoderIn_setMeasurementInterval
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4, 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the Encoder Obj driver object */
    ioErrorRetValue = DioCl1EncoderIn_apply
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/EMC_HALL_BL2 --- */
  /* --- [RTIEMC, Hall] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Create EMC Hall driver object pEmcHall_Unit1_DioCl1_Port1_Ch1 */
    ioErrorRetValue = DioCl1HallIn_create(&pEmcHall_Unit1_DioCl1_Port1_Ch1,
      DIO_HALL_IN_UNIT_1, DIO_CLASS1_PORT_1, DIO_CLASS1_CHANNEL_1,
      DIO_HALL_SENSOR_COUNT_3);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Selects if the rotational direction is to be reversed via software  */
    ioErrorRetValue = DioCl1HallIn_setReverseDirection
      (pEmcHall_Unit1_DioCl1_Port1_Ch1, (UInt32) DIO_HALL_REVERSE_INACTIVE);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* fill an array with positions of the signal edges of the Hall sensors and assign the address of the array to a pointer variable */
    Float64 sigEdgePositions[6] = { 353, 173, 113, 293, 233, 53 };

    /* Specifies the positions of the signal edges of the Hall sensors mounted on the motor */
    ioErrorRetValue = DioCl1HallIn_setSigEdgePositions
      (pEmcHall_Unit1_DioCl1_Port1_Ch1, sigEdgePositions);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Configures position offset added to Hall sensor signal based position to get shifted position */
    ioErrorRetValue = DioCl1HallIn_setPositionOffset
      (pEmcHall_Unit1_DioCl1_Port1_Ch1, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the Hall Obj driver object */
    ioErrorRetValue = DioCl1HallIn_apply(pEmcHall_Unit1_DioCl1_Port1_Ch1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activates Hall sensor interface functionality */
    ioErrorRetValue = DioCl1HallIn_start(pEmcHall_Unit1_DioCl1_Port1_Ch1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Output/EMC_MC_PWM_BL1 --- */
  /* --- [RTIEMC, MCPWM] - Port: 1 - Channel: 7 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for McPwm initial functions */
    Float64 initValArray[3];

    /* Init EMC MultiPwmOut driver object pRTIEmcMultiPwmOut_Port_1_Ch_7 */
    ioErrorCode = DioCl1MultiPwmOut_create(&pRTIEmcMultiPwmOut_Port_1_Ch_7,
      DIO_CLASS1_PORT_1, DIO_CLASS1_CHANNEL_7, 3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setInvertingMode
      (pRTIEmcMultiPwmOut_Port_1_Ch_7, DIO_CLASS1_INVERTED);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setSignalVoltage
      (pRTIEmcMultiPwmOut_Port_1_Ch_7, DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setAlignmentMode
      (pRTIEmcMultiPwmOut_Port_1_Ch_7, DIO_PWM_ALIGNMENT_CENTER);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setUpdateMode(pRTIEmcMultiPwmOut_Port_1_Ch_7,
      DIO_PWM_ANY_UPDATE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setRisingEdgeDelay
      (pRTIEmcMultiPwmOut_Port_1_Ch_7, (Float64) 1.0E-6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setInterruptMode
      (pRTIEmcMultiPwmOut_Port_1_Ch_7, DIO_CLASS1_INT_MID_PERIOD);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setTriggerLineOut
      (pRTIEmcMultiPwmOut_Port_1_Ch_7, DIO_CLASS1_TRIGGER_LINE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setTriggerMode
      (pRTIEmcMultiPwmOut_Port_1_Ch_7, DIO_CLASS1_INT_MID_PERIOD);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setEventDelay(pRTIEmcMultiPwmOut_Port_1_Ch_7,
      (Float64) 0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setEventDownsample
      (pRTIEmcMultiPwmOut_Port_1_Ch_7, (UInt32) 1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setPeriod(pRTIEmcMultiPwmOut_Port_1_Ch_7,
      (Float64) 5.0E-5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    initValArray[0] = 0;
    initValArray[1] = 0;
    initValArray[2] = 0;
    ioErrorCode = DioCl1MultiPwmOut_setDutyCycle(pRTIEmcMultiPwmOut_Port_1_Ch_7,
      initValArray);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_apply(pRTIEmcMultiPwmOut_Port_1_Ch_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_start(pRTIEmcMultiPwmOut_Port_1_Ch_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/DS1202_SENSOR_SUPPLY --- */
  /* --- [RTI120X, Sensor Supply] --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init Sensor Supply driver object pRTI_Sensor_Supply */
    ioErrorCode = SensorSupply_create(&pRTI_Sensor_Supply, SENSOR_SUPPLY_NO_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = SensorSupply_setVoltage(pRTI_Sensor_Supply, 5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = SensorSupply_setSensorState(pRTI_Sensor_Supply,
      SENSOR_STATE_ENABLE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = SensorSupply_apply(pRTI_Sensor_Supply);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = SensorSupply_start(pRTI_Sensor_Supply);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Control_load_machine/DIO_CLASS1_PWM_BL1 --- */
  /* --- [RTI120X, PWM OUT] - Port: 1 - Channel: 13 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init DIO CL1 PwmOut driver object pRTIDioC1PwmOut_Port_1_Ch_13 */
    ioErrorCode = DioCl1PwmOut_create(&pRTIDioC1PwmOut_Port_1_Ch_13,
      DIO_CLASS1_PORT_1, DIO_CLASS1_CHANNEL_13);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1PwmOut_setSignalVoltage(pRTIDioC1PwmOut_Port_1_Ch_13,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1PwmOut_setUpdateMode(pRTIDioC1PwmOut_Port_1_Ch_13,
      DIO_PWM_SYNC_UPDATE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1PwmOut_setInvertingMode(pRTIDioC1PwmOut_Port_1_Ch_13,
      DIO_CLASS1_NOT_INVERTED);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1PwmOut_setPeriod(pRTIDioC1PwmOut_Port_1_Ch_13, 5.0E-5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1PwmOut_setDutyCycle(pRTIDioC1PwmOut_Port_1_Ch_13, 0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1PwmOut_apply(pRTIDioC1PwmOut_Port_1_Ch_13);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1PwmOut_start(pRTIDioC1PwmOut_Port_1_Ch_13);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Enable_Inverter/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 15 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_1_Ch_15 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_1_Ch_15,
      DIO_CLASS1_PORT_1, DIO_CLASS1_MASK_CH_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_1_Ch_15,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (15 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 15-15 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_15,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_1_Ch_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_1_Ch_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* dSPACE I/O Board DSEMC_MOTORSETUP #0 */
  /* --- PMSM_DemoBackup/Control/Input/EMC_MOTOR_SETUP_BL1 --- */
  /* --- [RTIEMC, Motor Setup] - Unit: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init EMC Acu driver object pRTIEmcAcu_Unit_1 */
    ioErrorCode = Acu_create(&pRTIEmcAcu_Unit_1, ACU_INSTANCE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = Acu_setMotorPolePairCount(pRTIEmcAcu_Unit_1,
      ACU_MOTOR_POLE_PAIRS_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = Acu_setInputSensor(pRTIEmcAcu_Unit_1, ACU_SENSOR_A,
      ACU_SENSOR_HALL, ACU_HALL_INSTANCE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = Acu_setSensorPolePairCount(pRTIEmcAcu_Unit_1, ACU_SENSOR_A,
      ACU_SENSOR_POLE_PAIRS_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = Acu_setInputSensor(pRTIEmcAcu_Unit_1, ACU_SENSOR_B,
      ACU_SENSOR_ENCODER, ACU_ENCODER_INSTANCE_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* dSPACE I/O Board DSEMC_MOTORSETUP #0 Unit:DSEMC_POSSET */

  /* dSPACE I/O Board DSEMC_MOTORSETUP #0 Unit:DSEMC_POSSET Group:DSEMC_MOTORSETUP_FINALIZE */
  /* --- PMSM_DemoBackup/Control/Input/EMC_MOTOR_SETUP_BL1 --- */
  /* --- [RTIEMC, Motor Setup] - Unit: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;
    ioErrorCode = Acu_apply(pRTIEmcAcu_Unit_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = Acu_start(pRTIEmcAcu_Unit_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* --- PMSM_DemoBackup/Control/Input/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Resets start (initial) position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl1EncoderIn_setEncPosition
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4, (Float64) 2451.3888888888891);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activate Encoder signals read */
    ioErrorRetValue = DioCl1EncoderIn_start
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Input/EMC_HALL_BL2 --- */
  /* --- [RTIEMC, Hall] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Configures position offset added to Hall sensor signal based position to get shifted position */
    ioErrorRetValue = DioCl1HallIn_setPositionOffset
      (pEmcHall_Unit1_DioCl1_Port1_Ch1, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Writes data to Hall sensor interface unit */
    DioCl1HallIn_write(pEmcHall_Unit1_DioCl1_Port1_Ch1);
  }

  /* --- PMSM_DemoBackup/Control/Output/EMC_MC_PWM_BL1 --- */
  /* --- [RTIEMC, MCPWM] - Port: 1 - Channel: 7 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for McPwm initial functions */
    Float64 initValArray[3];

    /* enable output channels 7-9 on port 1 (always disable state of high-impedance) during initialization */
    ioErrorCode = DioCl1MultiPwmOut_setOutputHighZ
      (pRTIEmcMultiPwmOut_Port_1_Ch_7, DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial values of MCPWM Period and DutyCycle for output channel 7-9 on port 1 */
    ioErrorCode = DioCl1MultiPwmOut_setPeriod(pRTIEmcMultiPwmOut_Port_1_Ch_7,
      (Float64) 5.0E-5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    initValArray[0] = 0;
    initValArray[1] = 0;
    initValArray[2] = 0;
    ioErrorCode = DioCl1MultiPwmOut_setDutyCycle(pRTIEmcMultiPwmOut_Port_1_Ch_7,
      initValArray);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_write(pRTIEmcMultiPwmOut_Port_1_Ch_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Control/Control_load_machine/DIO_CLASS1_PWM_BL1 --- */
  /* --- [RTI120X, PWM OUT] - Port: 1 - Channel: 13 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;
    ioErrorCode = DioCl1PwmOut_setOutputHighZ(pRTIDioC1PwmOut_Port_1_Ch_13,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial values of PWM Period and DutyCycle for output channel 13 on port 1 */
    ioErrorCode = DioCl1PwmOut_setPeriod(pRTIDioC1PwmOut_Port_1_Ch_13, 5.0E-5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1PwmOut_setDutyCycle(pRTIDioC1PwmOut_Port_1_Ch_13, 0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1PwmOut_write(pRTIDioC1PwmOut_Port_1_Ch_13);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- PMSM_DemoBackup/Enable_Inverter/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 15 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_15,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (15 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 15-15 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_15,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

static void rti_mdl_background(void)
{
  /* DsDaq background call */
  DsDaq_Background(0);
}

/* Function rti_mdl_sample_input() is empty */
#define rti_mdl_sample_input()

/* Function rti_mdl_daq_service() is empty */
#define rti_mdl_daq_service()
#undef __INLINE

/****** [EOF] ****************************************************************/
