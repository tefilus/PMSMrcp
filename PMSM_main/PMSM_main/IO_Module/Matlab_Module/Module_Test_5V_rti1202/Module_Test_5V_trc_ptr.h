/*********************** dSPACE target specific file *************************

   Header file Module_Test_5V_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1202 7.15 (02-Nov-2020)
   Mon Jun 10 11:21:27 2024

   Copyright 2024, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_Module_Test_5V_trc_ptr_h_
#define RTI_HEADER_Module_Test_5V_trc_ptr_h_

/* Include the model header file. */
#include "Module_Test_5V.h"
#include "Module_Test_5V_private.h"
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
EXTERN_C volatile real_T *p_0_Module_Test_5V_real_T_0;
EXTERN_C volatile boolean_T *p_0_Module_Test_5V_boolean_T_1;
EXTERN_C volatile real_T *p_1_Module_Test_5V_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void Module_Test_5V_rti_init_trc_pointers(void);

#endif                                /* RTI_HEADER_Module_Test_5V_trc_ptr_h_ */
