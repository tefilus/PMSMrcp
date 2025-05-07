/*********************** dSPACE target specific file *************************

   Header file PMSM_DemoBackup_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1202 7.15 (02-Nov-2020)
   Tue May  7 13:37:16 2024

   Copyright 2024, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_PMSM_DemoBackup_trc_ptr_h_
#define RTI_HEADER_PMSM_DemoBackup_trc_ptr_h_

/* Include the model header file. */
#include "PMSM_DemoBackup.h"
#include "PMSM_DemoBackup_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_PMSM_DemoBackup_real_T_0;
EXTERN_C volatile uint32_T *p_0_PMSM_DemoBackup_uint32_T_1;
EXTERN_C volatile int32_T *p_0_PMSM_DemoBackup_int32_T_2;
EXTERN_C volatile int16_T *p_0_PMSM_DemoBackup_int16_T_3;
EXTERN_C volatile uint8_T *p_0_PMSM_DemoBackup_uint8_T_4;
EXTERN_C volatile boolean_T *p_0_PMSM_DemoBackup_boolean_T_5;
EXTERN_C volatile real_T *p_1_PMSM_DemoBackup_real_T_0;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_1;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_2;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_3;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_4;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_5;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_6;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_7;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_8;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_9;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_10;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_11;
EXTERN_C volatile struct_SPJi1DXfNcjd7Ee0UF7vjC
  *p_1_PMSM_DemoBackup_struct_SPJi1DXfNcjd7Ee0UF7vjC_12;
EXTERN_C volatile uint8_T *p_1_PMSM_DemoBackup_uint8_T_13;
EXTERN_C volatile real_T *p_1_PMSM_DemoBackup_real_T_14;
EXTERN_C volatile uint32_T *p_1_PMSM_DemoBackup_uint32_T_15;
EXTERN_C volatile int16_T *p_1_PMSM_DemoBackup_int16_T_16;
EXTERN_C volatile uint8_T *p_1_PMSM_DemoBackup_uint8_T_17;
EXTERN_C volatile real_T *p_2_PMSM_DemoBackup_real_T_0;
EXTERN_C volatile int_T *p_2_PMSM_DemoBackup_int_T_1;
EXTERN_C volatile uint8_T *p_2_PMSM_DemoBackup_uint8_T_2;
EXTERN_C volatile int8_T *p_2_PMSM_DemoBackup_int8_T_3;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void PMSM_DemoBackup_rti_init_trc_pointers(void);

#endif                               /* RTI_HEADER_PMSM_DemoBackup_trc_ptr_h_ */
