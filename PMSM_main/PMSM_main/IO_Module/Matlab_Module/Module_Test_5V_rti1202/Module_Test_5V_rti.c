/*********************** dSPACE target specific file *************************

   Include file Module_Test_5V_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1202 7.15 (02-Nov-2020)
   Mon Jun 10 11:21:27 2024

   Copyright 2024, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "Module_Test_5V.h"
#include "Module_Test_5V_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             Module_Test_5V_B
#define RTP_STRUCTURE_NAME             Module_Test_5V_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#ifndef dsRtmGetNumSampleTimes
# define dsRtmGetNumSampleTimes(rtm)   2
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

/* ===== Declarations of RTI blocks ======================================== */
AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_1;
AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_2;
AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_3;
AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_4;
AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_5;
AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_6;
AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_7;
AdcCl2AnalogInSDrvObject *pRTIAdcC2AnalogIn_Ch_8;
DacCl1AnalogOutSDrvObject *pRTIDacC1AnalogOut_Ch_1;
DioCl1DigInSDrvObject *pRTIDioC1DigIn_Port_2_Ch_9;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_1;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_2_Ch_1;
SensorSupplySDrvObject *pRTI_Sensor_Supply;

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

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL1 --- */
  /* --- [RTI120X, ADC C2] - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL2 AnalogIn driver object pRTIAdcC2AnalogIn_Ch_1 */
    ioErrorCode = AdcCl2AnalogIn_create(&pRTIAdcC2AnalogIn_Ch_1,
      ADC_CLASS2_CHANNEL_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_apply(pRTIAdcC2AnalogIn_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_start(pRTIAdcC2AnalogIn_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL2 --- */
  /* --- [RTI120X, ADC C2] - Channel: 2 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL2 AnalogIn driver object pRTIAdcC2AnalogIn_Ch_2 */
    ioErrorCode = AdcCl2AnalogIn_create(&pRTIAdcC2AnalogIn_Ch_2,
      ADC_CLASS2_CHANNEL_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_apply(pRTIAdcC2AnalogIn_Ch_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_start(pRTIAdcC2AnalogIn_Ch_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL3 --- */
  /* --- [RTI120X, ADC C2] - Channel: 3 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL2 AnalogIn driver object pRTIAdcC2AnalogIn_Ch_3 */
    ioErrorCode = AdcCl2AnalogIn_create(&pRTIAdcC2AnalogIn_Ch_3,
      ADC_CLASS2_CHANNEL_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_apply(pRTIAdcC2AnalogIn_Ch_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_start(pRTIAdcC2AnalogIn_Ch_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL4 --- */
  /* --- [RTI120X, ADC C2] - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL2 AnalogIn driver object pRTIAdcC2AnalogIn_Ch_4 */
    ioErrorCode = AdcCl2AnalogIn_create(&pRTIAdcC2AnalogIn_Ch_4,
      ADC_CLASS2_CHANNEL_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_apply(pRTIAdcC2AnalogIn_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_start(pRTIAdcC2AnalogIn_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL5 --- */
  /* --- [RTI120X, ADC C2] - Channel: 5 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL2 AnalogIn driver object pRTIAdcC2AnalogIn_Ch_5 */
    ioErrorCode = AdcCl2AnalogIn_create(&pRTIAdcC2AnalogIn_Ch_5,
      ADC_CLASS2_CHANNEL_5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_apply(pRTIAdcC2AnalogIn_Ch_5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_start(pRTIAdcC2AnalogIn_Ch_5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL6 --- */
  /* --- [RTI120X, ADC C2] - Channel: 6 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL2 AnalogIn driver object pRTIAdcC2AnalogIn_Ch_6 */
    ioErrorCode = AdcCl2AnalogIn_create(&pRTIAdcC2AnalogIn_Ch_6,
      ADC_CLASS2_CHANNEL_6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_apply(pRTIAdcC2AnalogIn_Ch_6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_start(pRTIAdcC2AnalogIn_Ch_6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL7 --- */
  /* --- [RTI120X, ADC C2] - Channel: 7 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL2 AnalogIn driver object pRTIAdcC2AnalogIn_Ch_7 */
    ioErrorCode = AdcCl2AnalogIn_create(&pRTIAdcC2AnalogIn_Ch_7,
      ADC_CLASS2_CHANNEL_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_apply(pRTIAdcC2AnalogIn_Ch_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_start(pRTIAdcC2AnalogIn_Ch_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL8 --- */
  /* --- [RTI120X, ADC C2] - Channel: 8 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL2 AnalogIn driver object pRTIAdcC2AnalogIn_Ch_8 */
    ioErrorCode = AdcCl2AnalogIn_create(&pRTIAdcC2AnalogIn_Ch_8,
      ADC_CLASS2_CHANNEL_8);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_apply(pRTIAdcC2AnalogIn_Ch_8);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl2AnalogIn_start(pRTIAdcC2AnalogIn_Ch_8);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/ANALOG_OUT/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init DAC CL1 AnalogOut driver object pRTIDacC1AnalogOut_Ch_1 */
    ioErrorCode = DacCl1AnalogOut_create(&pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_MASK_CH_1|DAC_CLASS1_MASK_CH_2|DAC_CLASS1_MASK_CH_3|
      DAC_CLASS1_MASK_CH_4|DAC_CLASS1_MASK_CH_5|DAC_CLASS1_MASK_CH_6|
      DAC_CLASS1_MASK_CH_7|DAC_CLASS1_MASK_CH_8|DAC_CLASS1_MASK_CH_9|
      DAC_CLASS1_MASK_CH_10|DAC_CLASS1_MASK_CH_11|DAC_CLASS1_MASK_CH_12|
      DAC_CLASS1_MASK_CH_13|DAC_CLASS1_MASK_CH_14|DAC_CLASS1_MASK_CH_15|
      DAC_CLASS1_MASK_CH_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the AnalogOut driver object */
    ioErrorCode = DacCl1AnalogOut_apply(pRTIDacC1AnalogOut_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/DIGITAL_IN/DIO_CLASS1_BIT_IN_BL1 --- */
  /* --- [RTI120X, BITIN] - Port: 2 - Channel: 9 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init DIO CL1 DigIn driver object pRTIDioC1DigIn_Port_2_Ch_9 */
    ioErrorCode = DioCl1DigIn_create(&pRTIDioC1DigIn_Port_2_Ch_9,
      DIO_CLASS1_PORT_2, DIO_CLASS1_MASK_CH_9|DIO_CLASS1_MASK_CH_10|
      DIO_CLASS1_MASK_CH_11|DIO_CLASS1_MASK_CH_12|DIO_CLASS1_MASK_CH_13|
      DIO_CLASS1_MASK_CH_14|DIO_CLASS1_MASK_CH_15|DIO_CLASS1_MASK_CH_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigIn_apply(pRTIDioC1DigIn_Port_2_Ch_9);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigIn_start(pRTIDioC1DigIn_Port_2_Ch_9);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_1_Ch_1 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_1_Ch_1,
      DIO_CLASS1_PORT_1, DIO_CLASS1_MASK_CH_1|DIO_CLASS1_MASK_CH_2|
      DIO_CLASS1_MASK_CH_3|DIO_CLASS1_MASK_CH_4|DIO_CLASS1_MASK_CH_5|
      DIO_CLASS1_MASK_CH_6|DIO_CLASS1_MASK_CH_7|DIO_CLASS1_MASK_CH_8|
      DIO_CLASS1_MASK_CH_9|DIO_CLASS1_MASK_CH_10|DIO_CLASS1_MASK_CH_11|
      DIO_CLASS1_MASK_CH_12|DIO_CLASS1_MASK_CH_13|DIO_CLASS1_MASK_CH_14|
      DIO_CLASS1_MASK_CH_15|DIO_CLASS1_MASK_CH_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_1_Ch_1,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (1 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (2 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (3 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (4 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (5 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (6 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (7 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (8 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (9 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (10 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (11 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (12 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (13 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (14 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (15 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (16 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 1-16 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_1,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_1_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_1_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 2 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_2_Ch_1 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_2_Ch_1,
      DIO_CLASS1_PORT_2, DIO_CLASS1_MASK_CH_1|DIO_CLASS1_MASK_CH_2|
      DIO_CLASS1_MASK_CH_3|DIO_CLASS1_MASK_CH_4|DIO_CLASS1_MASK_CH_5|
      DIO_CLASS1_MASK_CH_6|DIO_CLASS1_MASK_CH_7|DIO_CLASS1_MASK_CH_8);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_2_Ch_1,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (1 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (2 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (3 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (4 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (5 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (6 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (7 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (8 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 1-8 on port 2 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_2_Ch_1,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_2_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_2_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/DS1202_SENSOR_SUPPLY --- */
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
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* --- Module_Test_5V/ANALOG_OUT/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* All channel outputs are released from high impedance state */
    DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_HIGH_Z_OFF);

    /* write initial value of CL1 DAC for output channel 1 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_1, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 2 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_2, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 3 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_3, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 4 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_4, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 5 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_5, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 6 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_6, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 7 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_7, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 8 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_8, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 9 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_9, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 10 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_10, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 11 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_11, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 12 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_12, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 13 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_13, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 14 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_14, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 15 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_15, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial value of CL1 DAC for output channel 16 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
      DAC_CLASS1_CHANNEL_16, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activates AnalogOut functionality */
    ioErrorCode = DacCl1AnalogOut_start(pRTIDacC1AnalogOut_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_1,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (1 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (2 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (3 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (4 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (5 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (6 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (7 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (8 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (9 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (10 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (11 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (12 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (13 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (14 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (15 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (16 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 1-16 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_1,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Module_Test_5V/DIGITAL_OUT/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 2 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_2_Ch_1,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (1 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (2 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (3 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (4 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (5 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (6 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (7 - 1)) | outputDataInit);
    outputDataInit = ( ( ( (UInt32)0) << (8 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 1-8 on port 2 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_2_Ch_1,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_2_Ch_1);
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

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.001, 0] */

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL1 --- */
  /* --- [RTI120X, ADC C2] - Channel: 1 --- */

  /* get the value of analog signal from channel 1 */
  AdcCl2AnalogIn_read(pRTIAdcC2AnalogIn_Ch_1);
  AdcCl2AnalogIn_getInputValue(pRTIAdcC2AnalogIn_Ch_1, (real_T*)
    &Module_Test_5V_B.SFunction1);

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL2 --- */
  /* --- [RTI120X, ADC C2] - Channel: 2 --- */

  /* get the value of analog signal from channel 2 */
  AdcCl2AnalogIn_read(pRTIAdcC2AnalogIn_Ch_2);
  AdcCl2AnalogIn_getInputValue(pRTIAdcC2AnalogIn_Ch_2, (real_T*)
    &Module_Test_5V_B.SFunction1_k);

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL3 --- */
  /* --- [RTI120X, ADC C2] - Channel: 3 --- */

  /* get the value of analog signal from channel 3 */
  AdcCl2AnalogIn_read(pRTIAdcC2AnalogIn_Ch_3);
  AdcCl2AnalogIn_getInputValue(pRTIAdcC2AnalogIn_Ch_3, (real_T*)
    &Module_Test_5V_B.SFunction1_h);

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL4 --- */
  /* --- [RTI120X, ADC C2] - Channel: 4 --- */

  /* get the value of analog signal from channel 4 */
  AdcCl2AnalogIn_read(pRTIAdcC2AnalogIn_Ch_4);
  AdcCl2AnalogIn_getInputValue(pRTIAdcC2AnalogIn_Ch_4, (real_T*)
    &Module_Test_5V_B.SFunction1_a);

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL5 --- */
  /* --- [RTI120X, ADC C2] - Channel: 5 --- */

  /* get the value of analog signal from channel 5 */
  AdcCl2AnalogIn_read(pRTIAdcC2AnalogIn_Ch_5);
  AdcCl2AnalogIn_getInputValue(pRTIAdcC2AnalogIn_Ch_5, (real_T*)
    &Module_Test_5V_B.SFunction1_e);

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL6 --- */
  /* --- [RTI120X, ADC C2] - Channel: 6 --- */

  /* get the value of analog signal from channel 6 */
  AdcCl2AnalogIn_read(pRTIAdcC2AnalogIn_Ch_6);
  AdcCl2AnalogIn_getInputValue(pRTIAdcC2AnalogIn_Ch_6, (real_T*)
    &Module_Test_5V_B.SFunction1_em);

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL7 --- */
  /* --- [RTI120X, ADC C2] - Channel: 7 --- */

  /* get the value of analog signal from channel 7 */
  AdcCl2AnalogIn_read(pRTIAdcC2AnalogIn_Ch_7);
  AdcCl2AnalogIn_getInputValue(pRTIAdcC2AnalogIn_Ch_7, (real_T*)
    &Module_Test_5V_B.SFunction1_i);

  /* --- Module_Test_5V/ANALOG_IN/ADC_CLASS2_BL8 --- */
  /* --- [RTI120X, ADC C2] - Channel: 8 --- */

  /* get the value of analog signal from channel 8 */
  AdcCl2AnalogIn_read(pRTIAdcC2AnalogIn_Ch_8);
  AdcCl2AnalogIn_getInputValue(pRTIAdcC2AnalogIn_Ch_8, (real_T*)
    &Module_Test_5V_B.SFunction1_g);

  /* --- Module_Test_5V/DIGITAL_IN/DIO_CLASS1_BIT_IN_BL1 --- */
  /* --- [RTI120X, BITIN] - Port: 2 - Channel: 9 --- */
  {
    UInt32 inputDataUInt32;

    /* get digital signal state on channel 9-16 on port 2 */
    DioCl1DigIn_read(pRTIDioC1DigIn_Port_2_Ch_9);
    DioCl1DigIn_getChMaskInData(pRTIDioC1DigIn_Port_2_Ch_9, &inputDataUInt32);
    Module_Test_5V_B.SFunction1_p[0] = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_9) >> 8);
    Module_Test_5V_B.SFunction1_p[1] = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_10) >> 9);
    Module_Test_5V_B.SFunction1_p[2] = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_11) >> 10);
    Module_Test_5V_B.SFunction1_p[3] = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_12) >> 11);
    Module_Test_5V_B.SFunction1_p[4] = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_13) >> 12);
    Module_Test_5V_B.SFunction1_p[5] = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_14) >> 13);
    Module_Test_5V_B.SFunction1_p[6] = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_15) >> 14);
    Module_Test_5V_B.SFunction1_p[7] = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_16) >> 15);
  }
}

static void rti_mdl_daq_service()
{
  /* dSPACE Host Service */
  DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                rtk_current_task_absolute_time_ptr_get());
}

#undef __INLINE

/****** [EOF] ****************************************************************/
