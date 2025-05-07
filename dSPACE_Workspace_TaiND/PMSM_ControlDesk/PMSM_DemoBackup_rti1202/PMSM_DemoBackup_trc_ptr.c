/***************************************************************************

   Source file PMSM_DemoBackup_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1202 7.15 (02-Nov-2020)
   Tue May  7 13:37:16 2024

   Copyright 2024, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "PMSM_DemoBackup_trc_ptr.h"
#include "PMSM_DemoBackup.h"
#include "PMSM_DemoBackup_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_PMSM_DemoBackup_real_T_0 = NULL;
volatile uint32_T *p_0_PMSM_DemoBackup_uint32_T_1 = NULL;
volatile int32_T *p_0_PMSM_DemoBackup_int32_T_2 = NULL;
volatile int16_T *p_0_PMSM_DemoBackup_int16_T_3 = NULL;
volatile uint8_T *p_0_PMSM_DemoBackup_uint8_T_4 = NULL;
volatile boolean_T *p_0_PMSM_DemoBackup_boolean_T_5 = NULL;
volatile real_T *p_1_PMSM_DemoBackup_real_T_0 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_1 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_2 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_3 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_4 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_5 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_6 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_7 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_8 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_9 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_10 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_11 = NULL;
volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_12 = NULL;
volatile uint8_T *p_1_PMSM_DemoBackup_uint8_T_13 = NULL;
volatile real_T *p_1_PMSM_DemoBackup_real_T_14 = NULL;
volatile uint32_T *p_1_PMSM_DemoBackup_uint32_T_15 = NULL;
volatile int16_T *p_1_PMSM_DemoBackup_int16_T_16 = NULL;
volatile uint8_T *p_1_PMSM_DemoBackup_uint8_T_17 = NULL;
volatile real_T *p_2_PMSM_DemoBackup_real_T_0 = NULL;
volatile int_T *p_2_PMSM_DemoBackup_int_T_1 = NULL;
volatile uint8_T *p_2_PMSM_DemoBackup_uint8_T_2 = NULL;
volatile int8_T *p_2_PMSM_DemoBackup_int8_T_3 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_PMSM_DemoBackup_real_T_0 = &PMSM_DemoBackup_B.Choose_ref_value_i;
  p_0_PMSM_DemoBackup_uint32_T_1 = &PMSM_DemoBackup_B.SFunction1_o4;
  p_0_PMSM_DemoBackup_int32_T_2 = &PMSM_DemoBackup_B.Gain22;
  p_0_PMSM_DemoBackup_int16_T_3 = &PMSM_DemoBackup_B.SFunction1_o2_p;
  p_0_PMSM_DemoBackup_uint8_T_4 = &PMSM_DemoBackup_B.Compare;
  p_0_PMSM_DemoBackup_boolean_T_5 = &PMSM_DemoBackup_B.DataTypeConversion_h;
  p_1_PMSM_DemoBackup_real_T_0 = &PMSM_DemoBackup_P.Const_Id_Fieldweakening;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_1 =
    &PMSM_DemoBackup_P.DISCRETE_INTEGRATOR_lower_limit;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_2 =
    &PMSM_DemoBackup_P.DISCRETE_PT1_lower_limit_int;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_3 =
    &PMSM_DemoBackup_P.DISCRETE_PT1_SET_lower_limit_in;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_4 =
    &PMSM_DemoBackup_P.DISCRETE_PT1_lower_limit_int_i;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_5 =
    &PMSM_DemoBackup_P.DISCRETE_PT2_lower_limit_int;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_6 =
    &PMSM_DemoBackup_P.DISCRETE_PT1_lower_limit_int_a;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_7 =
    &PMSM_DemoBackup_P.DISCRETE_INTEGRATOR_upper_limit;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_8 =
    &PMSM_DemoBackup_P.DISCRETE_PT1_upper_limit_int;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_9 =
    &PMSM_DemoBackup_P.DISCRETE_PT1_SET_upper_limit_in;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_10 =
    &PMSM_DemoBackup_P.DISCRETE_PT1_upper_limit_int_i;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_11 =
    &PMSM_DemoBackup_P.DISCRETE_PT2_upper_limit_int;
  p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_12 =
    &PMSM_DemoBackup_P.DISCRETE_PT1_upper_limit_int_l;
  p_1_PMSM_DemoBackup_uint8_T_13 = &PMSM_DemoBackup_P.CounterLimited_uplimit;
  p_1_PMSM_DemoBackup_real_T_14 = &PMSM_DemoBackup_P.Constant1_Value;
  p_1_PMSM_DemoBackup_uint32_T_15 = &PMSM_DemoBackup_P.Switch_Threshold_j;
  p_1_PMSM_DemoBackup_int16_T_16 = &PMSM_DemoBackup_P.Gain22_Gain;
  p_1_PMSM_DemoBackup_uint8_T_17 = &PMSM_DemoBackup_P.Gain11_Gain_f;
  p_2_PMSM_DemoBackup_real_T_0 = &PMSM_DemoBackup_DW.UnitDelay1_DSTATE;
  p_2_PMSM_DemoBackup_int_T_1 = &PMSM_DemoBackup_DW.HitCrossing_MODE;
  p_2_PMSM_DemoBackup_uint8_T_2 = &PMSM_DemoBackup_DW.Output_DSTATE;
  p_2_PMSM_DemoBackup_int8_T_3 = &PMSM_DemoBackup_DW.RateTransition_1_write_buf;
}

void PMSM_DemoBackup_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
