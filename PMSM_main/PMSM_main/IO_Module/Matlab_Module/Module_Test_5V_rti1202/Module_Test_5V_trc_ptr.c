/***************************************************************************

   Source file Module_Test_5V_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1202 7.15 (02-Nov-2020)
   Mon Jun 10 11:21:27 2024

   Copyright 2024, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "Module_Test_5V_trc_ptr.h"
#include "Module_Test_5V.h"
#include "Module_Test_5V_private.h"

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
volatile real_T *p_0_Module_Test_5V_real_T_0 = NULL;
volatile boolean_T *p_0_Module_Test_5V_boolean_T_1 = NULL;
volatile real_T *p_1_Module_Test_5V_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_Module_Test_5V_real_T_0 = &Module_Test_5V_B.SFunction1;
  p_0_Module_Test_5V_boolean_T_1 = &Module_Test_5V_B.SFunction1_p[0];
  p_1_Module_Test_5V_real_T_0 = &Module_Test_5V_P.Gain_Gain;
}

void Module_Test_5V_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
