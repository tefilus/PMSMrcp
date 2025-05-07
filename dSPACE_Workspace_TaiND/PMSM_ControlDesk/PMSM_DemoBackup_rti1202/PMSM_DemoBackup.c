/*
 * PMSM_DemoBackup.c
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

#include "PMSM_DemoBackup_trc_ptr.h"
#include "PMSM_DemoBackup.h"
#include "PMSM_DemoBackup_private.h"

/* Block signals (default storage) */
B_PMSM_DemoBackup_T PMSM_DemoBackup_B;

/* Block states (default storage) */
DW_PMSM_DemoBackup_T PMSM_DemoBackup_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_PMSM_DemoBackup_T PMSM_DemoBackup_PrevZCX;

/* Real-time model */
RT_MODEL_PMSM_DemoBackup_T PMSM_DemoBackup_M_;
RT_MODEL_PMSM_DemoBackup_T *const PMSM_DemoBackup_M = &PMSM_DemoBackup_M_;
uint8_T look1_iu8lu32n31Ds16_binlcf(uint8_T u0, const uint8_T bp0[], const
  uint8_T table[], uint32_T maxIndex)
{
  uint32_T frac;
  uint32_T iRght;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'floor'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'floor'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    frac = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = (iRght + iLeft) >> 1U;
    }

    frac = div_nzp_repeat_u32((uint32_T)(uint8_T)((uint32_T)u0 - bp0[iLeft]) <<
      24, (uint8_T)((uint32_T)bp0[iLeft + 1U] - bp0[iLeft]), 7U);
  } else {
    iLeft = maxIndex - 1U;
    frac = 2147483648U;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'floor'
     Overflow mode: 'wrapping'
   */
  return (uint8_T)((uint32_T)(uint8_T)mul_ssu32_loSR((int16_T)(table[iLeft + 1U]
    - table[iLeft]), frac, 31U) + table[iLeft]);
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                   *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T absIn0;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  in0Hi = absIn0 >> 16U;
  absIn0 &= 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = absIn0 * in1Hi;
  absIn0 *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << 16U) + absIn0;
  if (outBitsLo < absIn0) {
    in1Lo = 1U;
  }

  absIn0 = outBitsLo;
  outBitsLo += productHiLo << 16U;
  if (outBitsLo < absIn0) {
    in1Lo++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    in1Lo;
  if ((in1 != 0U) && (in0 < 0)) {
    absIn0 = ~absIn0;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if (outBitsLo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = outBitsLo;
}

int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator, uint32_T
  nRepeatSub)
{
  uint32_T quotient;
  uint32_T iRepeatSub;
  boolean_T numeratorExtraBit;
  quotient = numerator / denominator;
  numerator %= denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (numerator >= 2147483648U);
    numerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (numerator >= denominator)) {
      quotient++;
      numerator -= denominator;
    }
  }

  return quotient;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
    }
  }

  return y;
}

/* System initialize for function-call system: '<Root>/Control' */
void PMSM_DemoBackup_Control_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S47>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_o;

  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_j;

  /* InitializeConditions for UnitDelay: '<S37>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_f =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_f =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_m;

  /* InitializeConditions for Memory: '<S25>/Memory' */
  PMSM_DemoBackup_DW.Memory_PreviousInput_m =
    PMSM_DemoBackup_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S25>/Memory1' */
  PMSM_DemoBackup_DW.Memory1_PreviousInput =
    PMSM_DemoBackup_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S25>/Memory2' */
  PMSM_DemoBackup_DW.Memory2_PreviousInput =
    PMSM_DemoBackup_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<S25>/Memory3' */
  PMSM_DemoBackup_DW.Memory3_PreviousInput =
    PMSM_DemoBackup_P.Memory3_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S33>/Output' */
  PMSM_DemoBackup_DW.Output_DSTATE = PMSM_DemoBackup_P.Output_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_p =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_c;

  /* InitializeConditions for UnitDelay: '<S56>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_l =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_i;

  /* InitializeConditions for UnitDelay: '<S38>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_k =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_i;

  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_h =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_g5;

  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_o =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S128>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_g =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_b;

  /* InitializeConditions for UnitDelay: '<S131>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_p =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_e;

  /* InitializeConditions for UnitDelay: '<S110>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_n =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_hx;

  /* InitializeConditions for UnitDelay: '<S128>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_hr =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_ic;

  /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_nm =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_n;

  /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_j =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_k;

  /* InitializeConditions for UnitDelay: '<S96>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_c =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_i;

  /* InitializeConditions for UnitDelay: '<S101>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_ot =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S96>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_hf =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_oa;

  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_l =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_j;

  /* SystemInitialize for Triggered SubSystem: '<S22>/speed_controller' */
  /* InitializeConditions for UnitDelay: '<S78>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_m =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S81>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_f =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_i =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S78>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_c =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_o;

  /* InitializeConditions for UnitDelay: '<S84>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_pt =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_i =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_m;

  /* InitializeConditions for UnitDelay: '<S74>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_io =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_b;

  /* InitializeConditions for UnitDelay: '<S84>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_cf =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_g;

  /* InitializeConditions for UnitDelay: '<S76>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_o =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_h;

  /* End of SystemInitialize for SubSystem: '<S22>/speed_controller' */
}

/* System reset for function-call system: '<Root>/Control' */
void PMSM_DemoBackup_Control_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S47>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_o;

  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_j;

  /* InitializeConditions for UnitDelay: '<S37>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_f =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_f =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_m;

  /* InitializeConditions for Memory: '<S25>/Memory' */
  PMSM_DemoBackup_DW.Memory_PreviousInput_m =
    PMSM_DemoBackup_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S25>/Memory1' */
  PMSM_DemoBackup_DW.Memory1_PreviousInput =
    PMSM_DemoBackup_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S25>/Memory2' */
  PMSM_DemoBackup_DW.Memory2_PreviousInput =
    PMSM_DemoBackup_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<S25>/Memory3' */
  PMSM_DemoBackup_DW.Memory3_PreviousInput =
    PMSM_DemoBackup_P.Memory3_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S33>/Output' */
  PMSM_DemoBackup_DW.Output_DSTATE = PMSM_DemoBackup_P.Output_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_p =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_c;

  /* InitializeConditions for UnitDelay: '<S56>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_l =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_i;

  /* InitializeConditions for UnitDelay: '<S38>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_k =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_i;

  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_h =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_g5;

  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_o =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S128>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_g =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_b;

  /* InitializeConditions for UnitDelay: '<S131>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_p =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_e;

  /* InitializeConditions for UnitDelay: '<S110>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_n =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_hx;

  /* InitializeConditions for UnitDelay: '<S128>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_hr =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_ic;

  /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_nm =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_n;

  /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_j =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_k;

  /* InitializeConditions for UnitDelay: '<S96>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_c =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_i;

  /* InitializeConditions for UnitDelay: '<S101>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_ot =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S96>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_hf =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_oa;

  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_l =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_j;

  /* SystemReset for Triggered SubSystem: '<S22>/speed_controller' */
  /* InitializeConditions for UnitDelay: '<S78>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_m =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S81>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_f =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_i =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S78>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_c =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_o;

  /* InitializeConditions for UnitDelay: '<S84>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_pt =
    PMSM_DemoBackup_P.UnitDelay1_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_i =
    PMSM_DemoBackup_P.UnitDelay2_InitialCondition_m;

  /* InitializeConditions for UnitDelay: '<S74>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_io =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_b;

  /* InitializeConditions for UnitDelay: '<S84>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_cf =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_g;

  /* InitializeConditions for UnitDelay: '<S76>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_o =
    PMSM_DemoBackup_P.UnitDelay_InitialCondition_h;

  /* End of SystemReset for SubSystem: '<S22>/speed_controller' */
}

/* Output and update for function-call system: '<Root>/Control' */
void PMSM_DemoBackup_Control(void)
{
  boolean_T zcEvent;
  int32_T i;
  real_T u0;
  real_T u1;

  /* user code (Output function Body for TID2) */

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 */

  /* --- PMSM_DemoBackup/Control/Input/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 4 --- */
  {
    /* define variables required for encoder sensor realtime functions */
    Float64 positionOrAngle= 0.0, speedOrAngVelocity= 0.0;
    UInt32 isIndexRaised= 0;

    /* Reads complete input data from selected encoder input channels (update data from hardware) */
    DioCl1EncoderIn_read(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4);

    /* Gets encoder angle position (degree) */
    DioCl1EncoderIn_getMechPosition(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4,
      &positionOrAngle);

    /* Gets encoder angular velocity (revolutions/minute) */
    DioCl1EncoderIn_getMechVelocity(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4,
      &speedOrAngVelocity);
    PMSM_DemoBackup_B.SFunction1_o1_f = (real_T) positionOrAngle;
    PMSM_DemoBackup_B.SFunction1_o2 = (real_T) speedOrAngVelocity;

    /* Once the index signal is detected, this outport is raised high.   *
     * This value is retained until the end of the real-time application */
    DioCl1EncoderIn_getIsIndexRaised (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4,
      &isIndexRaised);
    PMSM_DemoBackup_B.SFunction1_o3 = (real_T) isIndexRaised ;
  }

  /* --- PMSM_DemoBackup/Control/Input/EMC_MOTOR_SETUP_BL1 --- */
  /* --- [RTIEMC, Motor Setup] - Unit: 1 --- */
  {
    /* get data from ACU Unit 1*/
    Acu_read(pRTIEmcAcu_Unit_1);
    Acu_getMotorSpeed(pRTIEmcAcu_Unit_1, (real_T*)
                      &PMSM_DemoBackup_B.SFunction1_o1_k);
    Acu_getElecPosition(pRTIEmcAcu_Unit_1, (real_T*)
                        &PMSM_DemoBackup_B.SFunction1_o2_f);
    UInt32 isElectrPosValid;
    Acu_getIsElecPosValid(pRTIEmcAcu_Unit_1, &isElectrPosValid);
    PMSM_DemoBackup_B.SFunction1_o3_k = (isElectrPosValid != 0);
    Acu_getCurrentInputSensorNo(pRTIEmcAcu_Unit_1, (uint32_T*)
      &PMSM_DemoBackup_B.SFunction1_o4);
  }

  /* DataTypeConversion: '<S137>/Data Type Conversion' */
  PMSM_DemoBackup_B.DataTypeConversion = PMSM_DemoBackup_B.load_machine_ref;

  /* Product: '<S137>/Product' incorporates:
   *  Constant: '<S137>/n_Stroke[rpm]'
   */
  PMSM_DemoBackup_B.Product_k = PMSM_DemoBackup_B.ref_value_n_o *
    PMSM_DemoBackup_P.PMSM_Ctrl_n_Stroke;

  /* Product: '<S137>/Product1' incorporates:
   *  Constant: '<S137>/i_d_Stroke[A]'
   */
  PMSM_DemoBackup_B.Product1 = PMSM_DemoBackup_B.ref_value_iq_i *
    PMSM_DemoBackup_P.PMSM_Ctrl_i_d_Stroke;

  /* Product: '<S137>/Product2' incorporates:
   *  Constant: '<S137>/i_q_Stroke[A]'
   */
  PMSM_DemoBackup_B.Product2 = PMSM_DemoBackup_B.ref_value_iq_i *
    PMSM_DemoBackup_P.PMSM_Ctrl_i_q_Stroke;

  /* Sum: '<S137>/Sum' incorporates:
   *  Constant: '<S137>/n_Set[rpm]'
   */
  PMSM_DemoBackup_B.Sum_f = PMSM_DemoBackup_B.Product_k +
    PMSM_DemoBackup_P.PMSM_Ctrl_n_Set;

  /* Saturate: '<S137>/Saturation' */
  if (PMSM_DemoBackup_B.Sum_f > PMSM_DemoBackup_P.Saturation_UpperSat) {
    PMSM_DemoBackup_B.Saturation = PMSM_DemoBackup_P.Saturation_UpperSat;
  } else if (PMSM_DemoBackup_B.Sum_f < PMSM_DemoBackup_P.Saturation_LowerSat) {
    PMSM_DemoBackup_B.Saturation = PMSM_DemoBackup_P.Saturation_LowerSat;
  } else {
    PMSM_DemoBackup_B.Saturation = PMSM_DemoBackup_B.Sum_f;
  }

  /* End of Saturate: '<S137>/Saturation' */

  /* Sum: '<S137>/Sum1' incorporates:
   *  Constant: '<S137>/i_d_Set[A]'
   */
  PMSM_DemoBackup_B.Sum1 = PMSM_DemoBackup_B.Product1 +
    PMSM_DemoBackup_P.PMSM_Ctrl_i_d_Set;

  /* Saturate: '<S137>/Saturation1' */
  if (PMSM_DemoBackup_B.Sum1 > PMSM_DemoBackup_P.Saturation1_UpperSat) {
    PMSM_DemoBackup_B.Saturation1 = PMSM_DemoBackup_P.Saturation1_UpperSat;
  } else if (PMSM_DemoBackup_B.Sum1 < PMSM_DemoBackup_P.Saturation1_LowerSat) {
    PMSM_DemoBackup_B.Saturation1 = PMSM_DemoBackup_P.Saturation1_LowerSat;
  } else {
    PMSM_DemoBackup_B.Saturation1 = PMSM_DemoBackup_B.Sum1;
  }

  /* End of Saturate: '<S137>/Saturation1' */

  /* Sum: '<S137>/Sum2' incorporates:
   *  Constant: '<S137>/i_q_Set[A]'
   */
  PMSM_DemoBackup_B.Sum2 = PMSM_DemoBackup_B.Product2 +
    PMSM_DemoBackup_P.PMSM_Ctrl_i_q_Set;

  /* Saturate: '<S137>/Saturation2' */
  if (PMSM_DemoBackup_B.Sum2 > PMSM_DemoBackup_P.Saturation2_UpperSat) {
    PMSM_DemoBackup_B.Saturation2 = PMSM_DemoBackup_P.Saturation2_UpperSat;
  } else if (PMSM_DemoBackup_B.Sum2 < PMSM_DemoBackup_P.Saturation2_LowerSat) {
    PMSM_DemoBackup_B.Saturation2 = PMSM_DemoBackup_P.Saturation2_LowerSat;
  } else {
    PMSM_DemoBackup_B.Saturation2 = PMSM_DemoBackup_B.Sum2;
  }

  /* End of Saturate: '<S137>/Saturation2' */

  /* Constant: '<S137>/Ki_iq' */
  PMSM_DemoBackup_B.Ki_iq = PMSM_DemoBackup_P.PMSM_Ctrl_Ki_iq;

  /* Constant: '<S137>/Kp_iq' */
  PMSM_DemoBackup_B.Kp_iq = PMSM_DemoBackup_P.PMSM_Ctrl_Kp_iq;

  /* Constant: '<S137>/Vel_Src' */
  PMSM_DemoBackup_B.Vel_Src = PMSM_DemoBackup_P.PMSM_Ctrl_Vel_Src;

  /* Constant: '<S137>/load_torque' */
  PMSM_DemoBackup_B.load_torque = PMSM_DemoBackup_P.PMSM_Ctrl_load_torque;

  /* S-Function (rti_commonblock): '<S120>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 1 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_1);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_1, readStateFlag, (real_T*)
      &PMSM_DemoBackup_B.SFunction1_o1);
    PMSM_DemoBackup_B.SFunction1_o2_p = (int16_T) readStateFlag[0];
  }

  /* Gain: '<S109>/Gain13' */
  PMSM_DemoBackup_B.VoltageADC1V = PMSM_DemoBackup_P.Gain13_Gain *
    PMSM_DemoBackup_B.SFunction1_o1;

  /* Gain: '<S109>/volt->amp_i_a           ' */
  PMSM_DemoBackup_B.voltamp_i_a = PMSM_DemoBackup_P.voltamp_i_a_Gain *
    PMSM_DemoBackup_B.VoltageADC1V;

  /* Sum: '<S109>/Sum9' incorporates:
   *  Constant: '<S109>/ i_a_offset'
   */
  PMSM_DemoBackup_B.currentPhaseAA = PMSM_DemoBackup_B.voltamp_i_a -
    PMSM_DemoBackup_P.i_a_offset_Value;

  /* S-Function (rti_commonblock): '<S124>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL5 --- */
  /* --- [RTI120X, ADC C1] - Channel: 5 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_5);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_5, readStateFlag, (real_T*)
      &PMSM_DemoBackup_B.SFunction1_o1_i);
    PMSM_DemoBackup_B.SFunction1_o2_k = (int16_T) readStateFlag[0];
  }

  /* Gain: '<S109>/Gain17' */
  PMSM_DemoBackup_B.VoltageADC5V = PMSM_DemoBackup_P.Gain17_Gain *
    PMSM_DemoBackup_B.SFunction1_o1_i;

  /* Gain: '<S109>/volt->amp_i_b' */
  PMSM_DemoBackup_B.voltamp_i_b = PMSM_DemoBackup_P.voltamp_i_b_Gain *
    PMSM_DemoBackup_B.VoltageADC5V;

  /* Sum: '<S109>/Sum10' incorporates:
   *  Constant: '<S109>/ i_b_offset  '
   */
  PMSM_DemoBackup_B.currentPhaseBA = PMSM_DemoBackup_B.voltamp_i_b -
    PMSM_DemoBackup_P.i_b_offset_Value;

  /* S-Function (rti_commonblock): '<S126>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL7 --- */
  /* --- [RTI120X, ADC C1] - Channel: 7 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_7);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_7, readStateFlag, (real_T*)
      &PMSM_DemoBackup_B.SFunction1_o1_g);
    PMSM_DemoBackup_B.SFunction1_o2_g = (int16_T) readStateFlag[0];
  }

  /* Gain: '<S109>/Gain18' */
  PMSM_DemoBackup_B.VoltageADC7V = PMSM_DemoBackup_P.Gain18_Gain *
    PMSM_DemoBackup_B.SFunction1_o1_g;

  /* Gain: '<S109>/volt->amp_i_c' */
  PMSM_DemoBackup_B.voltamp_i_c = PMSM_DemoBackup_P.voltamp_i_c_Gain *
    PMSM_DemoBackup_B.VoltageADC7V;

  /* Sum: '<S109>/Sum11' incorporates:
   *  Constant: '<S109>/i_c_offset'
   */
  PMSM_DemoBackup_B.currentPhaseCA = PMSM_DemoBackup_B.voltamp_i_c -
    PMSM_DemoBackup_P.i_c_offset_Value;

  /* SignalConversion generated from: '<S59>/Gain1' */
  PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[0] =
    PMSM_DemoBackup_B.currentPhaseAA;
  PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[1] =
    PMSM_DemoBackup_B.currentPhaseBA;
  PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[2] =
    PMSM_DemoBackup_B.currentPhaseCA;

  /* Gain: '<S60>/Gain1' */
  for (i = 0; i < 2; i++) {
    PMSM_DemoBackup_B.Gain1[i] = 0.0;
    PMSM_DemoBackup_B.Gain1[i] += PMSM_DemoBackup_P.Gain1_Gain_o[i] *
      PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[0];
    PMSM_DemoBackup_B.Gain1[i] += PMSM_DemoBackup_P.Gain1_Gain_o[i + 2] *
      PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[1];
    PMSM_DemoBackup_B.Gain1[i] += PMSM_DemoBackup_P.Gain1_Gain_o[i + 4] *
      PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[2];
  }

  /* End of Gain: '<S60>/Gain1' */

  /* Gain: '<S135>/Gain5' */
  PMSM_DemoBackup_B.Gain5[0] = PMSM_DemoBackup_P.Gain5_Gain *
    PMSM_DemoBackup_B.Gain1[0];
  PMSM_DemoBackup_B.Gain5[1] = PMSM_DemoBackup_P.Gain5_Gain *
    PMSM_DemoBackup_B.Gain1[1];

  /* UnitDelay: '<S47>/Unit Delay1' */
  PMSM_DemoBackup_B.UnitDelay1 = PMSM_DemoBackup_DW.UnitDelay1_DSTATE;

  /* RelationalOperator: '<S48>/Compare' incorporates:
   *  Constant: '<S48>/Constant'
   */
  PMSM_DemoBackup_B.Compare = (uint8_T)(PMSM_DemoBackup_B.UnitDelay1 ==
    PMSM_DemoBackup_P.CompareToConstant_const_i);

  /* UnitDelay: '<S50>/Unit Delay2' */
  PMSM_DemoBackup_B.UnitDelay2 = PMSM_DemoBackup_DW.UnitDelay2_DSTATE;

  /* RelationalOperator: '<S51>/Compare' incorporates:
   *  Constant: '<S51>/Constant'
   */
  PMSM_DemoBackup_B.Compare_i = (uint8_T)(PMSM_DemoBackup_B.UnitDelay2 ==
    PMSM_DemoBackup_P.CompareToConstant1_const_d);

  /* RelationalOperator: '<S52>/Compare' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S52>/Constant'
   */
  PMSM_DemoBackup_B.Compare_d = (uint8_T)(PMSM_DemoBackup_P.Constant1_Value_e ==
    PMSM_DemoBackup_P.CompareToConstant2_const_a);

  /* Logic: '<S50>/Logical Operator1' */
  PMSM_DemoBackup_B.LogicalOperator1 = ((PMSM_DemoBackup_B.Compare_i != 0) &&
    (PMSM_DemoBackup_B.Compare_d != 0));

  /* Logic: '<S47>/Logical Operator' */
  PMSM_DemoBackup_B.LogicalOperator = ((PMSM_DemoBackup_B.Compare != 0) ||
    PMSM_DemoBackup_B.LogicalOperator1);

  /* Switch: '<S47>/Switch1' incorporates:
   *  Constant: '<S37>/zero'
   *  Constant: '<S47>/Constant1'
   */
  if (PMSM_DemoBackup_B.LogicalOperator) {
    PMSM_DemoBackup_B.Switch1_o = PMSM_DemoBackup_P.zero_Value_m;
  } else {
    PMSM_DemoBackup_B.Switch1_o = PMSM_DemoBackup_P.Constant1_Value_m;
  }

  /* End of Switch: '<S47>/Switch1' */

  /* UnitDelay: '<S37>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay = PMSM_DemoBackup_DW.UnitDelay_DSTATE;

  /* Gain: '<S59>/Gain1' */
  for (i = 0; i < 2; i++) {
    PMSM_DemoBackup_B.Gain1_m[i] = 0.0;
    PMSM_DemoBackup_B.Gain1_m[i] += PMSM_DemoBackup_P.Gain1_Gain_p[i] *
      PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[0];
    PMSM_DemoBackup_B.Gain1_m[i] += PMSM_DemoBackup_P.Gain1_Gain_p[i + 2] *
      PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[1];
    PMSM_DemoBackup_B.Gain1_m[i] += PMSM_DemoBackup_P.Gain1_Gain_p[i + 4] *
      PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[2];
  }

  /* End of Gain: '<S59>/Gain1' */

  /* S-Function (rti_commonblock): '<S112>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S119>/Gain3' */
  PMSM_DemoBackup_B.Gain3 = PMSM_DemoBackup_P.Gain3_Gain_c *
    PMSM_DemoBackup_B.SFunction1_o1_f;

  /* Sum: '<S119>/Sum' incorporates:
   *  Constant: '<S12>/AngleOffset'
   */
  PMSM_DemoBackup_B.Sum_k = PMSM_DemoBackup_P.AngleOffset_Value +
    PMSM_DemoBackup_B.Gain3;

  /* Math: '<S119>/Math Function' incorporates:
   *  Constant: '<S119>/Constant4'
   */
  PMSM_DemoBackup_B.Inc_elec_pos = rt_modd_snf(PMSM_DemoBackup_B.Sum_k,
    PMSM_DemoBackup_P.Constant4_Value_m);

  /* DataTypeConversion: '<S12>/bool2double' */
  PMSM_DemoBackup_B.inc_valid = PMSM_DemoBackup_B.SFunction1_o3;

  /* S-Function (rti_commonblock): '<S113>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Input/EMC_HALL_BL2 --- */
  /* --- [RTIEMC, Hall] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* define variables required for Hall sensor realtime functions */
    Float64 position= 0.0;
    UInt32 isPositionValid= 0, SensorSignalStates[3]= { 0 };

    /* Reads complete measuring data of Hall sensor interface (update data from hardware) */
    DioCl1HallIn_read(pEmcHall_Unit1_DioCl1_Port1_Ch1);

    /* Gets the electrical sensor position */
    DioCl1HallIn_getPosition(pEmcHall_Unit1_DioCl1_Port1_Ch1, &position);
    PMSM_DemoBackup_B.SFunction1_o1_d = (real_T) position;

    /* Gets current states of Hall sensor signals */
    DioCl1HallIn_getSensorSignals(pEmcHall_Unit1_DioCl1_Port1_Ch1,
      SensorSignalStates);
    PMSM_DemoBackup_B.SFunction1_o2_cq = (boolean_T) SensorSignalStates[0];
    PMSM_DemoBackup_B.SFunction1_o3_f = (boolean_T) SensorSignalStates[1];
    PMSM_DemoBackup_B.SFunction1_o4_b = (boolean_T) SensorSignalStates[2];

    /* Gets information if sensor position delivered by Hall sensor interface is valid */
    DioCl1HallIn_getIsPositionValid(pEmcHall_Unit1_DioCl1_Port1_Ch1,
      &isPositionValid);
    PMSM_DemoBackup_B.SFunction1_o5 = (boolean_T) isPositionValid;
  }

  /* Switch: '<S117>/Switch' */
  if (PMSM_DemoBackup_B.inc_valid >= PMSM_DemoBackup_P.Switch_Threshold_g) {
    PMSM_DemoBackup_B.Switch_n = PMSM_DemoBackup_B.Inc_elec_pos;
  } else {
    PMSM_DemoBackup_B.Switch_n = PMSM_DemoBackup_B.SFunction1_o1_d;
  }

  /* End of Switch: '<S117>/Switch' */

  /* S-Function (rti_commonblock): '<S114>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Switch: '<S116>/Switch' */
  if (PMSM_DemoBackup_B.SFunction1_o4 >= PMSM_DemoBackup_P.Switch_Threshold_j) {
    PMSM_DemoBackup_B.Switch_e = PMSM_DemoBackup_B.Inc_elec_pos;
  } else {
    PMSM_DemoBackup_B.Switch_e = PMSM_DemoBackup_B.SFunction1_o1_d;
  }

  /* End of Switch: '<S116>/Switch' */

  /* MultiPortSwitch: '<S12>/Multiport Switch1' incorporates:
   *  Constant: '<S137>/Pos_Src'
   */
  switch ((int32_T)PMSM_DemoBackup_P.PMSM_Ctrl_Pos_Src) {
   case 1:
    PMSM_DemoBackup_B.MultiportSwitch1 = PMSM_DemoBackup_B.Switch_n;
    break;

   case 2:
    PMSM_DemoBackup_B.MultiportSwitch1 = PMSM_DemoBackup_B.Switch_e;
    break;

   case 3:
    PMSM_DemoBackup_B.MultiportSwitch1 = PMSM_DemoBackup_B.SFunction1_o1_d;
    break;

   default:
    PMSM_DemoBackup_B.MultiportSwitch1 = PMSM_DemoBackup_B.SFunction1_o2_f;
    break;
  }

  /* End of MultiPortSwitch: '<S12>/Multiport Switch1' */

  /* Gain: '<S12>/to_rad' */
  PMSM_DemoBackup_B.to_rad = PMSM_DemoBackup_P.to_rad_Gain *
    PMSM_DemoBackup_B.MultiportSwitch1;

  /* Sum: '<S28>/Sum' incorporates:
   *  Constant: '<S137>/Theta_offset[rad]'
   */
  PMSM_DemoBackup_B.Sum_e = PMSM_DemoBackup_B.to_rad +
    PMSM_DemoBackup_P.PMSM_Ctrl_theta_offset;

  /* Math: '<S36>/Math Function1' incorporates:
   *  Constant: '<S36>/Constant2'
   */
  PMSM_DemoBackup_B.MathFunction1 = rt_modd_snf(PMSM_DemoBackup_B.Sum_e,
    PMSM_DemoBackup_P.Constant2_Value_f);

  /* Fcn: '<S59>/cos' */
  PMSM_DemoBackup_B.cos_m = cos(PMSM_DemoBackup_B.MathFunction1);

  /* Product: '<S59>/Product1' */
  PMSM_DemoBackup_B.Product1_d = PMSM_DemoBackup_B.Gain1_m[0] *
    PMSM_DemoBackup_B.cos_m;

  /* Fcn: '<S59>/sin' */
  PMSM_DemoBackup_B.sin_c = sin(PMSM_DemoBackup_B.MathFunction1);

  /* Product: '<S59>/Product2' */
  PMSM_DemoBackup_B.Product2_n = PMSM_DemoBackup_B.Gain1_m[1] *
    PMSM_DemoBackup_B.sin_c;

  /* Sum: '<S59>/Sum1' */
  PMSM_DemoBackup_B.Sum1_j = PMSM_DemoBackup_B.Product1_d +
    PMSM_DemoBackup_B.Product2_n;

  /* Product: '<S37>/Proportional' incorporates:
   *  Constant: '<S29>/Constant2'
   */
  PMSM_DemoBackup_B.Proportional = PMSM_DemoBackup_B.Sum1_j *
    PMSM_DemoBackup_P.Constant2_Value_e;

  /* Sum: '<S37>/Sum' */
  PMSM_DemoBackup_B.Sum_j = PMSM_DemoBackup_B.Proportional -
    PMSM_DemoBackup_B.UnitDelay;

  /* Product: '<S47>/Product' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_B.Product_i = PMSM_DemoBackup_P.T_PWM *
    PMSM_DemoBackup_B.Sum_j;

  /* UnitDelay: '<S47>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay_m = PMSM_DemoBackup_DW.UnitDelay_DSTATE_f;

  /* Switch: '<S47>/Switch2' incorporates:
   *  Constant: '<S47>/Constant2'
   */
  if (PMSM_DemoBackup_B.LogicalOperator1) {
    PMSM_DemoBackup_B.Switch2 = PMSM_DemoBackup_P.Constant2_Value_n0;
  } else {
    PMSM_DemoBackup_B.Switch2 = PMSM_DemoBackup_B.UnitDelay_m;
  }

  /* End of Switch: '<S47>/Switch2' */

  /* Sum: '<S47>/Add' */
  PMSM_DemoBackup_B.Add = (PMSM_DemoBackup_B.Switch1_o +
    PMSM_DemoBackup_B.Product_i) + PMSM_DemoBackup_B.Switch2;

  /* RelationalOperator: '<S49>/LowerRelop1' incorporates:
   *  Constant: '<S47>/upper_limit'
   */
  PMSM_DemoBackup_B.LowerRelop1 = (PMSM_DemoBackup_B.Add >
    PMSM_DemoBackup_P.DISCRETE_PT1_upper_limit_int_i.v);

  /* RelationalOperator: '<S49>/UpperRelop' incorporates:
   *  Constant: '<S47>/lower_limit'
   */
  PMSM_DemoBackup_B.UpperRelop = (PMSM_DemoBackup_B.Add <
    PMSM_DemoBackup_P.DISCRETE_PT1_lower_limit_int_i.v);

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S47>/lower_limit'
   */
  if (PMSM_DemoBackup_B.UpperRelop) {
    PMSM_DemoBackup_B.Switch_d =
      PMSM_DemoBackup_P.DISCRETE_PT1_lower_limit_int_i.v;
  } else {
    PMSM_DemoBackup_B.Switch_d = PMSM_DemoBackup_B.Add;
  }

  /* End of Switch: '<S49>/Switch' */

  /* Switch: '<S49>/Switch2' incorporates:
   *  Constant: '<S47>/upper_limit'
   */
  if (PMSM_DemoBackup_B.LowerRelop1) {
    PMSM_DemoBackup_B.Switch2_a =
      PMSM_DemoBackup_P.DISCRETE_PT1_upper_limit_int_i.v;
  } else {
    PMSM_DemoBackup_B.Switch2_a = PMSM_DemoBackup_B.Switch_d;
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Product: '<S37>/1|FilterTime' incorporates:
   *  Constant: '<S137>/TF_Id[s]'
   */
  PMSM_DemoBackup_B.uFilterTime = PMSM_DemoBackup_B.Switch2_a /
    PMSM_DemoBackup_P.PMSM_Ctrl_TF_Id;

  /* UnitDelay: '<S61>/Unit Delay1' */
  PMSM_DemoBackup_B.UnitDelay1_h = PMSM_DemoBackup_DW.UnitDelay1_DSTATE_f;

  /* Gain: '<S12>/Gain' */
  PMSM_DemoBackup_B.apu_vel = PMSM_DemoBackup_P.Gain_Gain_a *
    PMSM_DemoBackup_B.SFunction1_o1_k;

  /* MultiPortSwitch: '<S12>/Multiport Switch' incorporates:
   *  Constant: '<S12>/UseIncSpeed'
   */
  if ((int32_T)PMSM_DemoBackup_P.UseIncSpeed_Value == 1) {
    PMSM_DemoBackup_B.MultiportSwitch = PMSM_DemoBackup_B.SFunction1_o2;
  } else {
    PMSM_DemoBackup_B.MultiportSwitch = PMSM_DemoBackup_B.apu_vel;
  }

  /* End of MultiPortSwitch: '<S12>/Multiport Switch' */

  /* Memory: '<S25>/Memory' */
  PMSM_DemoBackup_B.Memory_j = PMSM_DemoBackup_DW.Memory_PreviousInput_m;

  /* Memory: '<S25>/Memory1' */
  PMSM_DemoBackup_B.Memory1 = PMSM_DemoBackup_DW.Memory1_PreviousInput;

  /* Memory: '<S25>/Memory2' */
  PMSM_DemoBackup_B.Memory2 = PMSM_DemoBackup_DW.Memory2_PreviousInput;

  /* Memory: '<S25>/Memory3' */
  PMSM_DemoBackup_B.Memory3 = PMSM_DemoBackup_DW.Memory3_PreviousInput;

  /* Sum: '<S25>/Sum' */
  PMSM_DemoBackup_B.Sum_p = (((PMSM_DemoBackup_B.MultiportSwitch +
    PMSM_DemoBackup_B.Memory_j) + PMSM_DemoBackup_B.Memory1) +
    PMSM_DemoBackup_B.Memory2) + PMSM_DemoBackup_B.Memory3;

  /* Gain: '<S25>/Gain' */
  PMSM_DemoBackup_B.Gain_p = PMSM_DemoBackup_P.Gain_Gain_j *
    PMSM_DemoBackup_B.Sum_p;

  /* Gain: '<S9>/Kp_n_Cor' incorporates:
   *  Constant: '<S137>/Kp_n'
   */
  PMSM_DemoBackup_B.Kp_n_Cor = PMSM_DemoBackup_P.Kp_n_Cor_Gain *
    PMSM_DemoBackup_P.PMSM_Ctrl_Kp_n;

  /* Gain: '<S9>/Ki_n_Cor' incorporates:
   *  Constant: '<S137>/Ki_n'
   */
  PMSM_DemoBackup_B.Ki_n_Cor = PMSM_DemoBackup_P.Ki_n_Cor_Gain *
    PMSM_DemoBackup_P.PMSM_Ctrl_Ki_n;

  /* UnitDelay: '<S33>/Output' */
  PMSM_DemoBackup_B.Output = PMSM_DemoBackup_DW.Output_DSTATE;

  /* Lookup_n-D: '<S27>/Lookup Table' */
  PMSM_DemoBackup_B.LookupTable = look1_iu8lu32n31Ds16_binlcf
    (PMSM_DemoBackup_B.Output, PMSM_DemoBackup_P.LookupTable_bp01Data,
     PMSM_DemoBackup_P.LookupTable_tableData, 4U);

  /* Outputs for Triggered SubSystem: '<S22>/speed_controller' incorporates:
   *  TriggerPort: '<S31>/Trigger'
   */
  zcEvent = ((PMSM_DemoBackup_B.LookupTable > 0) &&
             (PMSM_DemoBackup_PrevZCX.speed_controller_Trig_ZCE != 1));
  if (zcEvent) {
    /* SignalConversion generated from: '<S31>/SignalBus' incorporates:
     *  Constant: '<S137>/n_Limit [rpm]'
     */
    PMSM_DemoBackup_B.n_Limitrpm = PMSM_DemoBackup_P.PMSM_Ctrl_n_Limit;

    /* UnitDelay: '<S78>/Unit Delay1' */
    PMSM_DemoBackup_B.UnitDelay1_hl = PMSM_DemoBackup_DW.UnitDelay1_DSTATE_m;

    /* RelationalOperator: '<S79>/Compare' incorporates:
     *  Constant: '<S79>/Constant'
     */
    PMSM_DemoBackup_B.Compare_ih = (uint8_T)(PMSM_DemoBackup_B.UnitDelay1_hl ==
      PMSM_DemoBackup_P.CompareToConstant_const);

    /* UnitDelay: '<S81>/Unit Delay2' */
    PMSM_DemoBackup_B.UnitDelay2_py = PMSM_DemoBackup_DW.UnitDelay2_DSTATE_f;

    /* RelationalOperator: '<S82>/Compare' incorporates:
     *  Constant: '<S82>/Constant'
     */
    PMSM_DemoBackup_B.Compare_n4 = (uint8_T)(PMSM_DemoBackup_B.UnitDelay2_py ==
      PMSM_DemoBackup_P.CompareToConstant1_const);

    /* RelationalOperator: '<S83>/Compare' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S83>/Constant'
     */
    PMSM_DemoBackup_B.Compare_g = (uint8_T)(PMSM_DemoBackup_P.Constant1_Value ==
      PMSM_DemoBackup_P.CompareToConstant2_const);

    /* Logic: '<S81>/Logical Operator1' */
    PMSM_DemoBackup_B.LogicalOperator1_a = ((PMSM_DemoBackup_B.Compare_n4 != 0) &&
      (PMSM_DemoBackup_B.Compare_g != 0));

    /* Logic: '<S78>/Logical Operator' */
    PMSM_DemoBackup_B.LogicalOperator_e = ((PMSM_DemoBackup_B.Compare_ih != 0) ||
      PMSM_DemoBackup_B.LogicalOperator1_a);

    /* Switch: '<S78>/Switch1' incorporates:
     *  Constant: '<S73>/zero'
     *  Constant: '<S78>/Constant1'
     */
    if (PMSM_DemoBackup_B.LogicalOperator_e) {
      PMSM_DemoBackup_B.Switch1_m = PMSM_DemoBackup_P.zero_Value;
    } else {
      PMSM_DemoBackup_B.Switch1_m = PMSM_DemoBackup_P.Constant1_Value_c;
    }

    /* End of Switch: '<S78>/Switch1' */

    /* UnitDelay: '<S73>/Unit Delay' */
    PMSM_DemoBackup_B.UnitDelay_o3 = PMSM_DemoBackup_DW.UnitDelay_DSTATE_i;

    /* Gain: '<S31>/Gain1' */
    PMSM_DemoBackup_B.Gain1_j = PMSM_DemoBackup_P.Gain1_Gain *
      PMSM_DemoBackup_B.Gain_p;

    /* Product: '<S73>/Proportional' incorporates:
     *  Constant: '<S31>/Constant2'
     */
    PMSM_DemoBackup_B.Proportional_b = PMSM_DemoBackup_B.Gain1_j *
      PMSM_DemoBackup_P.Constant2_Value;

    /* Sum: '<S73>/Sum' */
    PMSM_DemoBackup_B.Sum_l = PMSM_DemoBackup_B.Proportional_b -
      PMSM_DemoBackup_B.UnitDelay_o3;

    /* Product: '<S78>/Product' incorporates:
     *  Constant: '<S137>/T_Sample[s]'
     */
    PMSM_DemoBackup_B.Product_ml = PMSM_DemoBackup_P.T_PWM *
      PMSM_DemoBackup_B.Sum_l;

    /* UnitDelay: '<S78>/Unit Delay' */
    PMSM_DemoBackup_B.UnitDelay_il = PMSM_DemoBackup_DW.UnitDelay_DSTATE_c;

    /* Switch: '<S78>/Switch2' incorporates:
     *  Constant: '<S78>/Constant2'
     */
    if (PMSM_DemoBackup_B.LogicalOperator1_a) {
      PMSM_DemoBackup_B.Switch2_b4 = PMSM_DemoBackup_P.Constant2_Value_c;
    } else {
      PMSM_DemoBackup_B.Switch2_b4 = PMSM_DemoBackup_B.UnitDelay_il;
    }

    /* End of Switch: '<S78>/Switch2' */

    /* Sum: '<S78>/Add' */
    PMSM_DemoBackup_B.Add_c = (PMSM_DemoBackup_B.Switch1_m +
      PMSM_DemoBackup_B.Product_ml) + PMSM_DemoBackup_B.Switch2_b4;

    /* RelationalOperator: '<S80>/LowerRelop1' incorporates:
     *  Constant: '<S78>/upper_limit'
     */
    PMSM_DemoBackup_B.LowerRelop1_gv = (PMSM_DemoBackup_B.Add_c >
      PMSM_DemoBackup_P.DISCRETE_PT1_upper_limit_int.v);

    /* RelationalOperator: '<S80>/UpperRelop' incorporates:
     *  Constant: '<S78>/lower_limit'
     */
    PMSM_DemoBackup_B.UpperRelop_d = (PMSM_DemoBackup_B.Add_c <
      PMSM_DemoBackup_P.DISCRETE_PT1_lower_limit_int.v);

    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S78>/lower_limit'
     */
    if (PMSM_DemoBackup_B.UpperRelop_d) {
      PMSM_DemoBackup_B.Switch_j =
        PMSM_DemoBackup_P.DISCRETE_PT1_lower_limit_int.v;
    } else {
      PMSM_DemoBackup_B.Switch_j = PMSM_DemoBackup_B.Add_c;
    }

    /* End of Switch: '<S80>/Switch' */

    /* Switch: '<S80>/Switch2' incorporates:
     *  Constant: '<S78>/upper_limit'
     */
    if (PMSM_DemoBackup_B.LowerRelop1_gv) {
      PMSM_DemoBackup_B.Switch2_o =
        PMSM_DemoBackup_P.DISCRETE_PT1_upper_limit_int.v;
    } else {
      PMSM_DemoBackup_B.Switch2_o = PMSM_DemoBackup_B.Switch_j;
    }

    /* End of Switch: '<S80>/Switch2' */

    /* Product: '<S73>/1|FilterTime' incorporates:
     *  Constant: '<S137>/TF_n[s]'
     */
    PMSM_DemoBackup_B.uFilterTime_o = PMSM_DemoBackup_B.Switch2_o /
      PMSM_DemoBackup_P.PMSM_Ctrl_TF_n;

    /* UnitDelay: '<S84>/Unit Delay1' */
    PMSM_DemoBackup_B.UnitDelay1_p = PMSM_DemoBackup_DW.UnitDelay1_DSTATE_pt;

    /* RelationalOperator: '<S85>/Compare' incorporates:
     *  Constant: '<S85>/Constant'
     */
    PMSM_DemoBackup_B.Compare_bk = (uint8_T)(PMSM_DemoBackup_B.UnitDelay1_p ==
      PMSM_DemoBackup_P.CompareToConstant_const_j);

    /* UnitDelay: '<S87>/Unit Delay2' */
    PMSM_DemoBackup_B.UnitDelay2_j = PMSM_DemoBackup_DW.UnitDelay2_DSTATE_i;

    /* RelationalOperator: '<S88>/Compare' incorporates:
     *  Constant: '<S88>/Constant'
     */
    PMSM_DemoBackup_B.Compare_eg = (uint8_T)(PMSM_DemoBackup_B.UnitDelay2_j ==
      PMSM_DemoBackup_P.CompareToConstant1_const_m);

    /* RelationalOperator: '<S89>/Compare' incorporates:
     *  Constant: '<S31>/Constant5'
     *  Constant: '<S89>/Constant'
     */
    PMSM_DemoBackup_B.Compare_nj = (uint8_T)(PMSM_DemoBackup_P.Constant5_Value ==
      PMSM_DemoBackup_P.CompareToConstant2_const_d);

    /* Logic: '<S87>/Logical Operator1' */
    PMSM_DemoBackup_B.LogicalOperator1_n = ((PMSM_DemoBackup_B.Compare_eg != 0) &&
      (PMSM_DemoBackup_B.Compare_nj != 0));

    /* Logic: '<S84>/Logical Operator' */
    PMSM_DemoBackup_B.LogicalOperator_g = ((PMSM_DemoBackup_B.Compare_bk != 0) ||
      PMSM_DemoBackup_B.LogicalOperator1_n);

    /* Switch: '<S84>/Switch1' incorporates:
     *  Constant: '<S74>/zero'
     *  Constant: '<S84>/Constant1'
     */
    if (PMSM_DemoBackup_B.LogicalOperator_g) {
      PMSM_DemoBackup_B.Switch1_k = PMSM_DemoBackup_P.zero_Value_i;
    } else {
      PMSM_DemoBackup_B.Switch1_k = PMSM_DemoBackup_P.Constant1_Value_o;
    }

    /* End of Switch: '<S84>/Switch1' */

    /* UnitDelay: '<S74>/Unit Delay' */
    PMSM_DemoBackup_B.UnitDelay_e = PMSM_DemoBackup_DW.UnitDelay_DSTATE_io;

    /* Product: '<S74>/Proportional' incorporates:
     *  Constant: '<S31>/Constant4'
     */
    PMSM_DemoBackup_B.Proportional_k = PMSM_DemoBackup_B.Saturation *
      PMSM_DemoBackup_P.Constant4_Value;

    /* Sum: '<S74>/Sum' */
    PMSM_DemoBackup_B.Sum_ke = PMSM_DemoBackup_B.Proportional_k -
      PMSM_DemoBackup_B.UnitDelay_e;

    /* Product: '<S84>/Product' incorporates:
     *  Constant: '<S137>/T_Sample[s]'
     */
    PMSM_DemoBackup_B.Product_l = PMSM_DemoBackup_P.T_PWM *
      PMSM_DemoBackup_B.Sum_ke;

    /* UnitDelay: '<S84>/Unit Delay' */
    PMSM_DemoBackup_B.UnitDelay_c = PMSM_DemoBackup_DW.UnitDelay_DSTATE_cf;

    /* Switch: '<S84>/Switch2' incorporates:
     *  Constant: '<S84>/Constant2'
     */
    if (PMSM_DemoBackup_B.LogicalOperator1_n) {
      PMSM_DemoBackup_B.Switch2_h = PMSM_DemoBackup_P.Constant2_Value_n;
    } else {
      PMSM_DemoBackup_B.Switch2_h = PMSM_DemoBackup_B.UnitDelay_c;
    }

    /* End of Switch: '<S84>/Switch2' */

    /* Sum: '<S84>/Add' */
    PMSM_DemoBackup_B.Add_l = (PMSM_DemoBackup_B.Switch1_k +
      PMSM_DemoBackup_B.Product_l) + PMSM_DemoBackup_B.Switch2_h;

    /* RelationalOperator: '<S86>/LowerRelop1' incorporates:
     *  Constant: '<S84>/upper_limit'
     */
    PMSM_DemoBackup_B.LowerRelop1_k = (PMSM_DemoBackup_B.Add_l >
      PMSM_DemoBackup_P.DISCRETE_PT1_SET_upper_limit_in.v);

    /* RelationalOperator: '<S86>/UpperRelop' incorporates:
     *  Constant: '<S84>/lower_limit'
     */
    PMSM_DemoBackup_B.UpperRelop_p = (PMSM_DemoBackup_B.Add_l <
      PMSM_DemoBackup_P.DISCRETE_PT1_SET_lower_limit_in.v);

    /* Switch: '<S86>/Switch' incorporates:
     *  Constant: '<S84>/lower_limit'
     */
    if (PMSM_DemoBackup_B.UpperRelop_p) {
      PMSM_DemoBackup_B.Switch_gh =
        PMSM_DemoBackup_P.DISCRETE_PT1_SET_lower_limit_in.v;
    } else {
      PMSM_DemoBackup_B.Switch_gh = PMSM_DemoBackup_B.Add_l;
    }

    /* End of Switch: '<S86>/Switch' */

    /* Switch: '<S86>/Switch2' incorporates:
     *  Constant: '<S84>/upper_limit'
     */
    if (PMSM_DemoBackup_B.LowerRelop1_k) {
      PMSM_DemoBackup_B.Switch2_l =
        PMSM_DemoBackup_P.DISCRETE_PT1_SET_upper_limit_in.v;
    } else {
      PMSM_DemoBackup_B.Switch2_l = PMSM_DemoBackup_B.Switch_gh;
    }

    /* End of Switch: '<S86>/Switch2' */

    /* Product: '<S74>/1|FilterTime' incorporates:
     *  Constant: '<S31>/Constant3'
     */
    PMSM_DemoBackup_B.uFilterTime_i = PMSM_DemoBackup_B.Switch2_l /
      PMSM_DemoBackup_P.Constant3_Value;

    /* Gain: '<S31>/Gain' incorporates:
     *  Constant: '<S137>/Limit_iq'
     */
    PMSM_DemoBackup_B.Gain_g = PMSM_DemoBackup_P.Gain_Gain *
      PMSM_DemoBackup_P.PMSM_Ctrl_Limit_iq;

    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/switch_filter'
     */
    if (PMSM_DemoBackup_P.switch_filter_Value >=
        PMSM_DemoBackup_P.Switch_Threshold) {
      PMSM_DemoBackup_B.Switch_l1 = PMSM_DemoBackup_B.Saturation;
    } else {
      PMSM_DemoBackup_B.Switch_l1 = PMSM_DemoBackup_B.uFilterTime_i;
    }

    /* End of Switch: '<S31>/Switch' */

    /* RelationalOperator: '<S90>/LowerRelop1' incorporates:
     *  Constant: '<S137>/n_Limit [rpm]'
     */
    PMSM_DemoBackup_B.LowerRelop1_a5 = (PMSM_DemoBackup_B.Switch_l1 >
      PMSM_DemoBackup_P.PMSM_Ctrl_n_Limit);

    /* Gain: '<S75>/inv' incorporates:
     *  Constant: '<S137>/n_Limit [rpm]'
     */
    PMSM_DemoBackup_B.inv_pp = PMSM_DemoBackup_P.inv_Gain *
      PMSM_DemoBackup_P.PMSM_Ctrl_n_Limit;

    /* RelationalOperator: '<S90>/UpperRelop' */
    PMSM_DemoBackup_B.UpperRelop_h1 = (PMSM_DemoBackup_B.Switch_l1 <
      PMSM_DemoBackup_B.inv_pp);

    /* Switch: '<S90>/Switch' */
    if (PMSM_DemoBackup_B.UpperRelop_h1) {
      PMSM_DemoBackup_B.Switch_nt = PMSM_DemoBackup_B.inv_pp;
    } else {
      PMSM_DemoBackup_B.Switch_nt = PMSM_DemoBackup_B.Switch_l1;
    }

    /* End of Switch: '<S90>/Switch' */

    /* Switch: '<S90>/Switch2' incorporates:
     *  Constant: '<S137>/n_Limit [rpm]'
     */
    if (PMSM_DemoBackup_B.LowerRelop1_a5) {
      PMSM_DemoBackup_B.Switch2_dh = PMSM_DemoBackup_P.PMSM_Ctrl_n_Limit;
    } else {
      PMSM_DemoBackup_B.Switch2_dh = PMSM_DemoBackup_B.Switch_nt;
    }

    /* End of Switch: '<S90>/Switch2' */

    /* Gain: '<S31>/Gain2' */
    PMSM_DemoBackup_B.Gain2_g = PMSM_DemoBackup_P.Gain2_Gain *
      PMSM_DemoBackup_B.Switch2_dh;

    /* Gain: '<S31>/Gain3' */
    PMSM_DemoBackup_B.Gain3_l = PMSM_DemoBackup_P.Gain3_Gain *
      PMSM_DemoBackup_B.uFilterTime_o;

    /* Sum: '<S76>/Sum1' */
    PMSM_DemoBackup_B.error_f = PMSM_DemoBackup_B.Gain2_g -
      PMSM_DemoBackup_B.uFilterTime_o;

    /* Product: '<S76>/Product2' */
    PMSM_DemoBackup_B.Product2_e = PMSM_DemoBackup_B.error_f *
      PMSM_DemoBackup_B.Ki_n_Cor;

    /* Product: '<S76>/Product' incorporates:
     *  Constant: '<S137>/T_Sample[s]'
     */
    PMSM_DemoBackup_B.integral_g = PMSM_DemoBackup_B.Product2_e *
      PMSM_DemoBackup_P.T_PWM;

    /* Product: '<S76>/Product1' */
    PMSM_DemoBackup_B.Product1_o = PMSM_DemoBackup_B.Kp_n_Cor *
      PMSM_DemoBackup_B.error_f;

    /* UnitDelay: '<S76>/Unit Delay' */
    PMSM_DemoBackup_B.UnitDelay_jj = PMSM_DemoBackup_DW.UnitDelay_DSTATE_o;

    /* Sum: '<S76>/Sum' */
    PMSM_DemoBackup_B.Sum_of = (PMSM_DemoBackup_B.Product1_o +
      PMSM_DemoBackup_B.integral_g) + PMSM_DemoBackup_B.UnitDelay_jj;

    /* RelationalOperator: '<S91>/LowerRelop1' incorporates:
     *  Constant: '<S137>/Limit_iq'
     */
    PMSM_DemoBackup_B.LowerRelop1_bl = (PMSM_DemoBackup_B.Sum_of >
      PMSM_DemoBackup_P.PMSM_Ctrl_Limit_iq);

    /* RelationalOperator: '<S91>/UpperRelop' */
    PMSM_DemoBackup_B.UpperRelop_a = (PMSM_DemoBackup_B.Sum_of <
      PMSM_DemoBackup_B.Gain_g);

    /* Switch: '<S91>/Switch' */
    if (PMSM_DemoBackup_B.UpperRelop_a) {
      PMSM_DemoBackup_B.Switch_k = PMSM_DemoBackup_B.Gain_g;
    } else {
      PMSM_DemoBackup_B.Switch_k = PMSM_DemoBackup_B.Sum_of;
    }

    /* End of Switch: '<S91>/Switch' */

    /* Switch: '<S91>/Switch2' incorporates:
     *  Constant: '<S137>/Limit_iq'
     */
    if (PMSM_DemoBackup_B.LowerRelop1_bl) {
      PMSM_DemoBackup_B.Switch2_hf = PMSM_DemoBackup_P.PMSM_Ctrl_Limit_iq;
    } else {
      PMSM_DemoBackup_B.Switch2_hf = PMSM_DemoBackup_B.Switch_k;
    }

    /* End of Switch: '<S91>/Switch2' */

    /* Sum: '<S76>/Sum2' */
    PMSM_DemoBackup_B.Sum2_d = PMSM_DemoBackup_B.Switch2_hf -
      PMSM_DemoBackup_B.Product1_o;

    /* Update for UnitDelay: '<S78>/Unit Delay1' incorporates:
     *  Constant: '<S137>/T_Sample[s]'
     */
    PMSM_DemoBackup_DW.UnitDelay1_DSTATE_m = PMSM_DemoBackup_P.T_PWM;

    /* Update for UnitDelay: '<S81>/Unit Delay2' incorporates:
     *  Constant: '<S31>/Constant1'
     */
    PMSM_DemoBackup_DW.UnitDelay2_DSTATE_f = PMSM_DemoBackup_P.Constant1_Value;

    /* Update for UnitDelay: '<S73>/Unit Delay' */
    PMSM_DemoBackup_DW.UnitDelay_DSTATE_i = PMSM_DemoBackup_B.uFilterTime_o;

    /* Update for UnitDelay: '<S78>/Unit Delay' */
    PMSM_DemoBackup_DW.UnitDelay_DSTATE_c = PMSM_DemoBackup_B.Switch2_o;

    /* Update for UnitDelay: '<S84>/Unit Delay1' incorporates:
     *  Constant: '<S137>/T_Sample[s]'
     */
    PMSM_DemoBackup_DW.UnitDelay1_DSTATE_pt = PMSM_DemoBackup_P.T_PWM;

    /* Update for UnitDelay: '<S87>/Unit Delay2' incorporates:
     *  Constant: '<S31>/Constant5'
     */
    PMSM_DemoBackup_DW.UnitDelay2_DSTATE_i = PMSM_DemoBackup_P.Constant5_Value;

    /* Update for UnitDelay: '<S74>/Unit Delay' */
    PMSM_DemoBackup_DW.UnitDelay_DSTATE_io = PMSM_DemoBackup_B.uFilterTime_i;

    /* Update for UnitDelay: '<S84>/Unit Delay' */
    PMSM_DemoBackup_DW.UnitDelay_DSTATE_cf = PMSM_DemoBackup_B.Switch2_l;

    /* Update for UnitDelay: '<S76>/Unit Delay' */
    PMSM_DemoBackup_DW.UnitDelay_DSTATE_o = PMSM_DemoBackup_B.Sum2_d;
  }

  PMSM_DemoBackup_PrevZCX.speed_controller_Trig_ZCE = (ZCSigState)
    (PMSM_DemoBackup_B.LookupTable > 0);

  /* End of Outputs for SubSystem: '<S22>/speed_controller' */

  /* Gain: '<S30>/Gain3' */
  PMSM_DemoBackup_B.Gain3_p = PMSM_DemoBackup_P.Gain3_Gain_a *
    PMSM_DemoBackup_B.Saturation2;

  /* MultiPortSwitch: '<S30>/Multiport Switch' incorporates:
   *  Constant: '<S137>/Ctrl_mode_SW[1 n_ctrl | 2 i_ctrl | 3 v_ctrl]'
   *  Constant: '<S30>/Const_Id_Fieldweakening[A]'
   *  Constant: '<S30>/zero'
   */
  switch ((int32_T)PMSM_DemoBackup_P.PMSM_Ctrl_Ctrl_mode_SW) {
   case 1:
    PMSM_DemoBackup_B.MultiportSwitch_e[0] =
      PMSM_DemoBackup_P.Const_Id_Fieldweakening;
    PMSM_DemoBackup_B.MultiportSwitch_e[1] = PMSM_DemoBackup_B.Switch2_hf;
    break;

   case 2:
    PMSM_DemoBackup_B.MultiportSwitch_e[0] = PMSM_DemoBackup_B.Saturation1;
    PMSM_DemoBackup_B.MultiportSwitch_e[1] = PMSM_DemoBackup_B.Gain3_p;
    break;

   default:
    PMSM_DemoBackup_B.MultiportSwitch_e[0] = PMSM_DemoBackup_P.zero_Value_ia;
    PMSM_DemoBackup_B.MultiportSwitch_e[1] = PMSM_DemoBackup_P.zero_Value_ia;
    break;
  }

  /* End of MultiPortSwitch: '<S30>/Multiport Switch' */

  /* RelationalOperator: '<S71>/LowerRelop1' incorporates:
   *  Constant: '<S137>/Limit_iq'
   */
  PMSM_DemoBackup_B.LowerRelop1_i = (PMSM_DemoBackup_B.MultiportSwitch_e[0] >
    PMSM_DemoBackup_P.PMSM_Ctrl_Limit_iq);

  /* Gain: '<S69>/inv' incorporates:
   *  Constant: '<S137>/Limit_iq'
   */
  PMSM_DemoBackup_B.inv = PMSM_DemoBackup_P.inv_Gain_i *
    PMSM_DemoBackup_P.PMSM_Ctrl_Limit_iq;

  /* RelationalOperator: '<S71>/UpperRelop' */
  PMSM_DemoBackup_B.UpperRelop_k = (PMSM_DemoBackup_B.MultiportSwitch_e[0] <
    PMSM_DemoBackup_B.inv);

  /* Switch: '<S71>/Switch' */
  if (PMSM_DemoBackup_B.UpperRelop_k) {
    PMSM_DemoBackup_B.Switch_a = PMSM_DemoBackup_B.inv;
  } else {
    PMSM_DemoBackup_B.Switch_a = PMSM_DemoBackup_B.MultiportSwitch_e[0];
  }

  /* End of Switch: '<S71>/Switch' */

  /* Switch: '<S71>/Switch2' incorporates:
   *  Constant: '<S137>/Limit_iq'
   */
  if (PMSM_DemoBackup_B.LowerRelop1_i) {
    PMSM_DemoBackup_B.Switch2_j = PMSM_DemoBackup_P.PMSM_Ctrl_Limit_iq;
  } else {
    PMSM_DemoBackup_B.Switch2_j = PMSM_DemoBackup_B.Switch_a;
  }

  /* End of Switch: '<S71>/Switch2' */

  /* Product: '<S45>/factor_id' */
  PMSM_DemoBackup_B.factor_id = PMSM_DemoBackup_B.UnitDelay1_h *
    PMSM_DemoBackup_B.Switch2_j;

  /* MultiPortSwitch: '<S45>/Multiport Switch' incorporates:
   *  Constant: '<S137>/Ctrl_mode_SW[1 n_ctrl | 2 i_ctrl | 3 v_ctrl]'
   */
  switch ((int32_T)PMSM_DemoBackup_P.PMSM_Ctrl_Ctrl_mode_SW) {
   case 1:
    PMSM_DemoBackup_B.MultiportSwitch_b = PMSM_DemoBackup_B.factor_id;
    break;

   case 2:
    PMSM_DemoBackup_B.MultiportSwitch_b = PMSM_DemoBackup_B.Switch2_j;
    break;

   default:
    PMSM_DemoBackup_B.MultiportSwitch_b = PMSM_DemoBackup_B.Switch2_j;
    break;
  }

  /* End of MultiPortSwitch: '<S45>/Multiport Switch' */

  /* Gain: '<S135>/Gain3' */
  PMSM_DemoBackup_B.Gain3_e[0] = PMSM_DemoBackup_P.Gain3_Gain_l *
    PMSM_DemoBackup_B.uFilterTime;
  PMSM_DemoBackup_B.Gain3_e[1] = PMSM_DemoBackup_P.Gain3_Gain_l *
    PMSM_DemoBackup_B.MultiportSwitch_b;

  /* UnitDelay: '<S53>/Unit Delay1' */
  PMSM_DemoBackup_B.UnitDelay1_n = PMSM_DemoBackup_DW.UnitDelay1_DSTATE_p;

  /* RelationalOperator: '<S54>/Compare' incorporates:
   *  Constant: '<S54>/Constant'
   */
  PMSM_DemoBackup_B.Compare_p = (uint8_T)(PMSM_DemoBackup_B.UnitDelay1_n ==
    PMSM_DemoBackup_P.CompareToConstant_const_a);

  /* UnitDelay: '<S56>/Unit Delay2' */
  PMSM_DemoBackup_B.UnitDelay2_k = PMSM_DemoBackup_DW.UnitDelay2_DSTATE_l;

  /* RelationalOperator: '<S57>/Compare' incorporates:
   *  Constant: '<S57>/Constant'
   */
  PMSM_DemoBackup_B.Compare_ph = (uint8_T)(PMSM_DemoBackup_B.UnitDelay2_k ==
    PMSM_DemoBackup_P.CompareToConstant1_const_i);

  /* RelationalOperator: '<S58>/Compare' incorporates:
   *  Constant: '<S29>/Constant3'
   *  Constant: '<S58>/Constant'
   */
  PMSM_DemoBackup_B.Compare_pw = (uint8_T)(PMSM_DemoBackup_P.Constant3_Value_i ==
    PMSM_DemoBackup_P.CompareToConstant2_const_az);

  /* Logic: '<S56>/Logical Operator1' */
  PMSM_DemoBackup_B.LogicalOperator1_b = ((PMSM_DemoBackup_B.Compare_ph != 0) &&
    (PMSM_DemoBackup_B.Compare_pw != 0));

  /* Logic: '<S53>/Logical Operator' */
  PMSM_DemoBackup_B.LogicalOperator_j = ((PMSM_DemoBackup_B.Compare_p != 0) ||
    PMSM_DemoBackup_B.LogicalOperator1_b);

  /* Switch: '<S53>/Switch1' incorporates:
   *  Constant: '<S38>/zero'
   *  Constant: '<S53>/Constant1'
   */
  if (PMSM_DemoBackup_B.LogicalOperator_j) {
    PMSM_DemoBackup_B.Switch1_j = PMSM_DemoBackup_P.zero_Value_e;
  } else {
    PMSM_DemoBackup_B.Switch1_j = PMSM_DemoBackup_P.Constant1_Value_ov;
  }

  /* End of Switch: '<S53>/Switch1' */

  /* UnitDelay: '<S38>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay_f = PMSM_DemoBackup_DW.UnitDelay_DSTATE_k;

  /* Gain: '<S59>/inv' */
  PMSM_DemoBackup_B.inv_k = PMSM_DemoBackup_P.inv_Gain_n *
    PMSM_DemoBackup_B.sin_c;

  /* Product: '<S59>/Product3' */
  PMSM_DemoBackup_B.Product3 = PMSM_DemoBackup_B.Gain1_m[0] *
    PMSM_DemoBackup_B.inv_k;

  /* Product: '<S59>/Product4' */
  PMSM_DemoBackup_B.Product4 = PMSM_DemoBackup_B.Gain1_m[1] *
    PMSM_DemoBackup_B.cos_m;

  /* Sum: '<S59>/Sum' */
  PMSM_DemoBackup_B.Sum_i = PMSM_DemoBackup_B.Product3 +
    PMSM_DemoBackup_B.Product4;

  /* Product: '<S38>/Proportional' incorporates:
   *  Constant: '<S29>/Constant4'
   */
  PMSM_DemoBackup_B.Proportional_g = PMSM_DemoBackup_B.Sum_i *
    PMSM_DemoBackup_P.Constant4_Value_n;

  /* Sum: '<S38>/Sum' */
  PMSM_DemoBackup_B.Sum_pj = PMSM_DemoBackup_B.Proportional_g -
    PMSM_DemoBackup_B.UnitDelay_f;

  /* Product: '<S53>/Product' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_B.Product_m = PMSM_DemoBackup_P.T_PWM *
    PMSM_DemoBackup_B.Sum_pj;

  /* UnitDelay: '<S53>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay_o = PMSM_DemoBackup_DW.UnitDelay_DSTATE_h;

  /* Switch: '<S53>/Switch2' incorporates:
   *  Constant: '<S53>/Constant2'
   */
  if (PMSM_DemoBackup_B.LogicalOperator1_b) {
    PMSM_DemoBackup_B.Switch2_e = PMSM_DemoBackup_P.Constant2_Value_m;
  } else {
    PMSM_DemoBackup_B.Switch2_e = PMSM_DemoBackup_B.UnitDelay_o;
  }

  /* End of Switch: '<S53>/Switch2' */

  /* Sum: '<S53>/Add' */
  PMSM_DemoBackup_B.Add_g = (PMSM_DemoBackup_B.Switch1_j +
    PMSM_DemoBackup_B.Product_m) + PMSM_DemoBackup_B.Switch2_e;

  /* RelationalOperator: '<S55>/LowerRelop1' incorporates:
   *  Constant: '<S53>/upper_limit'
   */
  PMSM_DemoBackup_B.LowerRelop1_e = (PMSM_DemoBackup_B.Add_g >
    PMSM_DemoBackup_P.DISCRETE_PT2_upper_limit_int.v);

  /* RelationalOperator: '<S55>/UpperRelop' incorporates:
   *  Constant: '<S53>/lower_limit'
   */
  PMSM_DemoBackup_B.UpperRelop_l = (PMSM_DemoBackup_B.Add_g <
    PMSM_DemoBackup_P.DISCRETE_PT2_lower_limit_int.v);

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S53>/lower_limit'
   */
  if (PMSM_DemoBackup_B.UpperRelop_l) {
    PMSM_DemoBackup_B.Switch_m =
      PMSM_DemoBackup_P.DISCRETE_PT2_lower_limit_int.v;
  } else {
    PMSM_DemoBackup_B.Switch_m = PMSM_DemoBackup_B.Add_g;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Switch: '<S55>/Switch2' incorporates:
   *  Constant: '<S53>/upper_limit'
   */
  if (PMSM_DemoBackup_B.LowerRelop1_e) {
    PMSM_DemoBackup_B.Switch2_d =
      PMSM_DemoBackup_P.DISCRETE_PT2_upper_limit_int.v;
  } else {
    PMSM_DemoBackup_B.Switch2_d = PMSM_DemoBackup_B.Switch_m;
  }

  /* End of Switch: '<S55>/Switch2' */

  /* Product: '<S38>/1|FilterTime' incorporates:
   *  Constant: '<S137>/TF_Iq[s]'
   */
  PMSM_DemoBackup_B.uFilterTime_m = PMSM_DemoBackup_B.Switch2_d /
    PMSM_DemoBackup_P.PMSM_Ctrl_TF_Iq;

  /* Gain: '<S29>/Gain1' */
  PMSM_DemoBackup_B.Gain1_h = PMSM_DemoBackup_P.Gain1_Gain_b *
    PMSM_DemoBackup_B.uFilterTime_m;

  /* UnitDelay: '<S61>/Unit Delay2' */
  PMSM_DemoBackup_B.UnitDelay2_g = PMSM_DemoBackup_DW.UnitDelay2_DSTATE_o;

  /* RelationalOperator: '<S72>/LowerRelop1' incorporates:
   *  Constant: '<S137>/Limit_iq'
   */
  PMSM_DemoBackup_B.LowerRelop1_l = (PMSM_DemoBackup_B.MultiportSwitch_e[1] >
    PMSM_DemoBackup_P.PMSM_Ctrl_Limit_iq);

  /* Gain: '<S70>/inv' incorporates:
   *  Constant: '<S137>/Limit_iq'
   */
  PMSM_DemoBackup_B.inv_h = PMSM_DemoBackup_P.inv_Gain_i4 *
    PMSM_DemoBackup_P.PMSM_Ctrl_Limit_iq;

  /* RelationalOperator: '<S72>/UpperRelop' */
  PMSM_DemoBackup_B.UpperRelop_e = (PMSM_DemoBackup_B.MultiportSwitch_e[1] <
    PMSM_DemoBackup_B.inv_h);

  /* Switch: '<S72>/Switch' */
  if (PMSM_DemoBackup_B.UpperRelop_e) {
    PMSM_DemoBackup_B.Switch_i = PMSM_DemoBackup_B.inv_h;
  } else {
    PMSM_DemoBackup_B.Switch_i = PMSM_DemoBackup_B.MultiportSwitch_e[1];
  }

  /* End of Switch: '<S72>/Switch' */

  /* Switch: '<S72>/Switch2' incorporates:
   *  Constant: '<S137>/Limit_iq'
   */
  if (PMSM_DemoBackup_B.LowerRelop1_l) {
    PMSM_DemoBackup_B.Switch2_b = PMSM_DemoBackup_P.PMSM_Ctrl_Limit_iq;
  } else {
    PMSM_DemoBackup_B.Switch2_b = PMSM_DemoBackup_B.Switch_i;
  }

  /* End of Switch: '<S72>/Switch2' */

  /* Product: '<S46>/factor_id' */
  PMSM_DemoBackup_B.factor_id_e = PMSM_DemoBackup_B.UnitDelay2_g *
    PMSM_DemoBackup_B.Switch2_b;

  /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
   *  Constant: '<S137>/Ctrl_mode_SW[1 n_ctrl | 2 i_ctrl | 3 v_ctrl]'
   */
  switch ((int32_T)PMSM_DemoBackup_P.PMSM_Ctrl_Ctrl_mode_SW) {
   case 1:
    PMSM_DemoBackup_B.MultiportSwitch_a = PMSM_DemoBackup_B.factor_id_e;
    break;

   case 2:
    PMSM_DemoBackup_B.MultiportSwitch_a = PMSM_DemoBackup_B.Switch2_b;
    break;

   default:
    PMSM_DemoBackup_B.MultiportSwitch_a = PMSM_DemoBackup_B.Switch2_b;
    break;
  }

  /* End of MultiPortSwitch: '<S46>/Multiport Switch' */

  /* Gain: '<S29>/Gain3' */
  PMSM_DemoBackup_B.Gain3_a = PMSM_DemoBackup_P.Gain3_Gain_b *
    PMSM_DemoBackup_B.MultiportSwitch_a;

  /* Gain: '<S135>/Gain4' */
  PMSM_DemoBackup_B.Gain4[0] = PMSM_DemoBackup_P.Gain4_Gain *
    PMSM_DemoBackup_B.Gain1_h;
  PMSM_DemoBackup_B.Gain4[1] = PMSM_DemoBackup_P.Gain4_Gain *
    PMSM_DemoBackup_B.Gain3_a;

  /* UnitDelay: '<S128>/Unit Delay1' */
  PMSM_DemoBackup_B.UnitDelay1_m = PMSM_DemoBackup_DW.UnitDelay1_DSTATE_g;

  /* RelationalOperator: '<S129>/Compare' incorporates:
   *  Constant: '<S129>/Constant'
   */
  PMSM_DemoBackup_B.Compare_l = (uint8_T)(PMSM_DemoBackup_B.UnitDelay1_m ==
    PMSM_DemoBackup_P.CompareToConstant_const_h);

  /* UnitDelay: '<S131>/Unit Delay2' */
  PMSM_DemoBackup_B.UnitDelay2_m = PMSM_DemoBackup_DW.UnitDelay2_DSTATE_p;

  /* RelationalOperator: '<S132>/Compare' incorporates:
   *  Constant: '<S132>/Constant'
   */
  PMSM_DemoBackup_B.Compare_b = (uint8_T)(PMSM_DemoBackup_B.UnitDelay2_m ==
    PMSM_DemoBackup_P.CompareToConstant1_const_l);

  /* RelationalOperator: '<S133>/Compare' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S133>/Constant'
   */
  PMSM_DemoBackup_B.Compare_d4 = (uint8_T)(PMSM_DemoBackup_P.Constant1_Value_p ==
    PMSM_DemoBackup_P.CompareToConstant2_const_j);

  /* Logic: '<S131>/Logical Operator1' */
  PMSM_DemoBackup_B.LogicalOperator1_l = ((PMSM_DemoBackup_B.Compare_b != 0) &&
    (PMSM_DemoBackup_B.Compare_d4 != 0));

  /* Logic: '<S128>/Logical Operator' */
  PMSM_DemoBackup_B.LogicalOperator_f = ((PMSM_DemoBackup_B.Compare_l != 0) ||
    PMSM_DemoBackup_B.LogicalOperator1_l);

  /* Switch: '<S128>/Switch1' incorporates:
   *  Constant: '<S110>/zero'
   *  Constant: '<S128>/Constant1'
   */
  if (PMSM_DemoBackup_B.LogicalOperator_f) {
    PMSM_DemoBackup_B.Switch1_f = PMSM_DemoBackup_P.zero_Value_c;
  } else {
    PMSM_DemoBackup_B.Switch1_f = PMSM_DemoBackup_P.Constant1_Value_mp;
  }

  /* End of Switch: '<S128>/Switch1' */

  /* UnitDelay: '<S110>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay_fg = PMSM_DemoBackup_DW.UnitDelay_DSTATE_n;

  /* S-Function (rti_commonblock): '<S122>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL3 --- */
  /* --- [RTI120X, ADC C1] - Channel: 3 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_3);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_3, readStateFlag, (real_T*)
      &PMSM_DemoBackup_B.SFunction1_o1_j);
    PMSM_DemoBackup_B.SFunction1_o2_pt = (int16_T) readStateFlag[0];
  }

  /* Gain: '<S109>/Gain15' */
  PMSM_DemoBackup_B.VoltageADC3V = PMSM_DemoBackup_P.Gain15_Gain *
    PMSM_DemoBackup_B.SFunction1_o1_j;

  /* Gain: '<S109>/Gain9' */
  PMSM_DemoBackup_B.Battery_VoltageV = PMSM_DemoBackup_P.Gain9_Gain *
    PMSM_DemoBackup_B.VoltageADC3V;

  /* Product: '<S110>/Proportional' incorporates:
   *  Constant: '<S12>/Constant2'
   */
  PMSM_DemoBackup_B.Proportional_j = PMSM_DemoBackup_B.Battery_VoltageV *
    PMSM_DemoBackup_P.Constant2_Value_g;

  /* Sum: '<S110>/Sum' */
  PMSM_DemoBackup_B.Sum_g = PMSM_DemoBackup_B.Proportional_j -
    PMSM_DemoBackup_B.UnitDelay_fg;

  /* Product: '<S128>/Product' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_B.Product_e = PMSM_DemoBackup_P.T_PWM *
    PMSM_DemoBackup_B.Sum_g;

  /* UnitDelay: '<S128>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay_d = PMSM_DemoBackup_DW.UnitDelay_DSTATE_hr;

  /* Switch: '<S128>/Switch2' incorporates:
   *  Constant: '<S128>/Constant2'
   */
  if (PMSM_DemoBackup_B.LogicalOperator1_l) {
    PMSM_DemoBackup_B.Switch2_m = PMSM_DemoBackup_P.Constant2_Value_fk;
  } else {
    PMSM_DemoBackup_B.Switch2_m = PMSM_DemoBackup_B.UnitDelay_d;
  }

  /* End of Switch: '<S128>/Switch2' */

  /* Sum: '<S128>/Add' */
  PMSM_DemoBackup_B.Add_b = (PMSM_DemoBackup_B.Switch1_f +
    PMSM_DemoBackup_B.Product_e) + PMSM_DemoBackup_B.Switch2_m;

  /* RelationalOperator: '<S130>/LowerRelop1' incorporates:
   *  Constant: '<S128>/upper_limit'
   */
  PMSM_DemoBackup_B.LowerRelop1_a = (PMSM_DemoBackup_B.Add_b >
    PMSM_DemoBackup_P.DISCRETE_PT1_upper_limit_int_l.v);

  /* RelationalOperator: '<S130>/UpperRelop' incorporates:
   *  Constant: '<S128>/lower_limit'
   */
  PMSM_DemoBackup_B.UpperRelop_h = (PMSM_DemoBackup_B.Add_b <
    PMSM_DemoBackup_P.DISCRETE_PT1_lower_limit_int_a.v);

  /* Switch: '<S130>/Switch' incorporates:
   *  Constant: '<S128>/lower_limit'
   */
  if (PMSM_DemoBackup_B.UpperRelop_h) {
    PMSM_DemoBackup_B.Switch_g =
      PMSM_DemoBackup_P.DISCRETE_PT1_lower_limit_int_a.v;
  } else {
    PMSM_DemoBackup_B.Switch_g = PMSM_DemoBackup_B.Add_b;
  }

  /* End of Switch: '<S130>/Switch' */

  /* Switch: '<S130>/Switch2' incorporates:
   *  Constant: '<S128>/upper_limit'
   */
  if (PMSM_DemoBackup_B.LowerRelop1_a) {
    PMSM_DemoBackup_B.Switch2_p =
      PMSM_DemoBackup_P.DISCRETE_PT1_upper_limit_int_l.v;
  } else {
    PMSM_DemoBackup_B.Switch2_p = PMSM_DemoBackup_B.Switch_g;
  }

  /* End of Switch: '<S130>/Switch2' */

  /* Product: '<S110>/1|FilterTime' incorporates:
   *  Constant: '<S12>/Constant3'
   */
  PMSM_DemoBackup_B.uFilterTime_g = PMSM_DemoBackup_B.Switch2_p /
    PMSM_DemoBackup_P.Constant3_Value_ib;

  /* MinMax: '<S44>/MinMax' incorporates:
   *  Constant: '<S137>/V_DCLink_Limit[V]'
   */
  u0 = PMSM_DemoBackup_B.uFilterTime_g;
  u1 = PMSM_DemoBackup_P.PMSM_Ctrl_V_DCLink_Limit;
  if ((u0 < u1) || rtIsNaN(u1)) {
    u1 = u0;
  }

  PMSM_DemoBackup_B.MinMax = u1;

  /* End of MinMax: '<S44>/MinMax' */

  /* Gain: '<S44>/LimitingFactor' */
  PMSM_DemoBackup_B.LimitingFactor = PMSM_DemoBackup_P.LimitingFactor_Gain *
    PMSM_DemoBackup_B.MinMax;

  /* Gain: '<S9>/Kp_i_Cor' incorporates:
   *  Constant: '<S137>/Kp_id'
   */
  PMSM_DemoBackup_B.Kp_i_Cor = PMSM_DemoBackup_P.Kp_i_Cor_Gain *
    PMSM_DemoBackup_P.PMSM_Ctrl_Kp_id;

  /* Sum: '<S39>/Sum1' */
  PMSM_DemoBackup_B.error = PMSM_DemoBackup_B.MultiportSwitch_b -
    PMSM_DemoBackup_B.uFilterTime;

  /* Product: '<S39>/Product1' */
  PMSM_DemoBackup_B.Product1_b = PMSM_DemoBackup_B.Kp_i_Cor *
    PMSM_DemoBackup_B.error;

  /* Gain: '<S9>/Ki_i_Cor' incorporates:
   *  Constant: '<S137>/Ki_id'
   */
  PMSM_DemoBackup_B.Ki_i_Cor = PMSM_DemoBackup_P.Ki_i_Cor_Gain *
    PMSM_DemoBackup_P.PMSM_Ctrl_Ki_id;

  /* Product: '<S39>/Product2' */
  PMSM_DemoBackup_B.Product2_k = PMSM_DemoBackup_B.Ki_i_Cor *
    PMSM_DemoBackup_B.error;

  /* Product: '<S39>/Product' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_B.integral = PMSM_DemoBackup_B.Product2_k *
    PMSM_DemoBackup_P.T_PWM;

  /* UnitDelay: '<S39>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay_i = PMSM_DemoBackup_DW.UnitDelay_DSTATE_nm;

  /* Sum: '<S39>/Sum' */
  PMSM_DemoBackup_B.Sum_jb = (PMSM_DemoBackup_B.Product1_b +
    PMSM_DemoBackup_B.integral) + PMSM_DemoBackup_B.UnitDelay_i;

  /* Product: '<S28>/Product2' incorporates:
   *  Constant: '<S28>/Const_PolePair[]'
   */
  PMSM_DemoBackup_B.Product2_g = PMSM_DemoBackup_B.MultiportSwitch *
    PMSM_DemoBackup_P.Const_PolePairs;

  /* Gain: '<S28>/toRad|s' */
  PMSM_DemoBackup_B.toRads = PMSM_DemoBackup_P.toRads_Gain *
    PMSM_DemoBackup_B.Product2_g;

  /* Product: '<S64>/Product' */
  PMSM_DemoBackup_B.Product_eb = PMSM_DemoBackup_B.uFilterTime_m *
    PMSM_DemoBackup_B.toRads;

  /* Gain: '<S64>/Const_Lsd[H]' */
  PMSM_DemoBackup_B.Const_LsdH = PMSM_DemoBackup_P.Const_Ld_Stator *
    PMSM_DemoBackup_B.Product_eb;

  /* Sum: '<S64>/Sum3' */
  PMSM_DemoBackup_B.Sum3 = PMSM_DemoBackup_B.Sum_jb -
    PMSM_DemoBackup_B.Const_LsdH;

  /* RelationalOperator: '<S67>/LowerRelop1' */
  PMSM_DemoBackup_B.LowerRelop1_f = (PMSM_DemoBackup_B.Sum3 >
    PMSM_DemoBackup_B.LimitingFactor);

  /* Gain: '<S62>/inv' */
  PMSM_DemoBackup_B.inv_ho = PMSM_DemoBackup_P.inv_Gain_c *
    PMSM_DemoBackup_B.LimitingFactor;

  /* RelationalOperator: '<S67>/UpperRelop' */
  PMSM_DemoBackup_B.UpperRelop_hi = (PMSM_DemoBackup_B.Sum3 <
    PMSM_DemoBackup_B.inv_ho);

  /* Switch: '<S67>/Switch' */
  if (PMSM_DemoBackup_B.UpperRelop_hi) {
    PMSM_DemoBackup_B.Switch_dr = PMSM_DemoBackup_B.inv_ho;
  } else {
    PMSM_DemoBackup_B.Switch_dr = PMSM_DemoBackup_B.Sum3;
  }

  /* End of Switch: '<S67>/Switch' */

  /* Switch: '<S67>/Switch2' */
  if (PMSM_DemoBackup_B.LowerRelop1_f) {
    PMSM_DemoBackup_B.Switch2_a3 = PMSM_DemoBackup_B.LimitingFactor;
  } else {
    PMSM_DemoBackup_B.Switch2_a3 = PMSM_DemoBackup_B.Switch_dr;
  }

  /* End of Switch: '<S67>/Switch2' */

  /* Math: '<S44>/Math Function1' */
  PMSM_DemoBackup_B.MathFunction1_n = PMSM_DemoBackup_B.LimitingFactor *
    PMSM_DemoBackup_B.LimitingFactor;

  /* Math: '<S44>/Math Function' */
  PMSM_DemoBackup_B.MathFunction = PMSM_DemoBackup_B.Sum_jb *
    PMSM_DemoBackup_B.Sum_jb;

  /* Sum: '<S44>/Add' */
  PMSM_DemoBackup_B.Add_a = PMSM_DemoBackup_B.MathFunction1_n -
    PMSM_DemoBackup_B.MathFunction;

  /* Sqrt: '<S44>/Math Function2'
   *
   * About '<S44>/Math Function2':
   *  Operator: signedSqrt
   */
  u1 = PMSM_DemoBackup_B.Add_a;
  if (u1 < 0.0) {
    PMSM_DemoBackup_B.MathFunction2 = -sqrt(fabs(u1));
  } else {
    PMSM_DemoBackup_B.MathFunction2 = sqrt(u1);
  }

  /* End of Sqrt: '<S44>/Math Function2' */

  /* Sum: '<S40>/Sum1' */
  PMSM_DemoBackup_B.error_a = PMSM_DemoBackup_B.MultiportSwitch_a -
    PMSM_DemoBackup_B.uFilterTime_m;

  /* Product: '<S40>/Product1' */
  PMSM_DemoBackup_B.Product1_c = PMSM_DemoBackup_B.Kp_i_Cor *
    PMSM_DemoBackup_B.error_a;

  /* Product: '<S40>/Product2' */
  PMSM_DemoBackup_B.Product2_b = PMSM_DemoBackup_B.Ki_i_Cor *
    PMSM_DemoBackup_B.error_a;

  /* Product: '<S40>/Product' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_B.integral_p = PMSM_DemoBackup_B.Product2_b *
    PMSM_DemoBackup_P.T_PWM;

  /* UnitDelay: '<S40>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay_l = PMSM_DemoBackup_DW.UnitDelay_DSTATE_j;

  /* Sum: '<S40>/Sum' */
  PMSM_DemoBackup_B.Sum_a = (PMSM_DemoBackup_B.Product1_c +
    PMSM_DemoBackup_B.integral_p) + PMSM_DemoBackup_B.UnitDelay_l;

  /* Product: '<S64>/Product1' */
  PMSM_DemoBackup_B.Product1_p = PMSM_DemoBackup_B.toRads *
    PMSM_DemoBackup_B.uFilterTime;

  /* Gain: '<S64>/Const_Lsq[H]' */
  PMSM_DemoBackup_B.Const_LsqH = PMSM_DemoBackup_P.Const_Lq_Stator *
    PMSM_DemoBackup_B.Product1_p;

  /* Sum: '<S64>/Sum1' */
  PMSM_DemoBackup_B.Sum1_f = PMSM_DemoBackup_B.Sum_a +
    PMSM_DemoBackup_B.Const_LsqH;

  /* Gain: '<S64>/Const_Psi[Wb]' */
  PMSM_DemoBackup_B.Const_PsiWb = PMSM_DemoBackup_P.Const_Psi *
    PMSM_DemoBackup_B.toRads;

  /* Sum: '<S64>/Sum4' */
  PMSM_DemoBackup_B.Sum4 = PMSM_DemoBackup_B.Sum1_f +
    PMSM_DemoBackup_B.Const_PsiWb;

  /* RelationalOperator: '<S68>/LowerRelop1' */
  PMSM_DemoBackup_B.LowerRelop1_b = (PMSM_DemoBackup_B.Sum4 >
    PMSM_DemoBackup_B.MathFunction2);

  /* Gain: '<S63>/inv' */
  PMSM_DemoBackup_B.inv_e = PMSM_DemoBackup_P.inv_Gain_i0 *
    PMSM_DemoBackup_B.MathFunction2;

  /* RelationalOperator: '<S68>/UpperRelop' */
  PMSM_DemoBackup_B.UpperRelop_i = (PMSM_DemoBackup_B.Sum4 <
    PMSM_DemoBackup_B.inv_e);

  /* Switch: '<S68>/Switch' */
  if (PMSM_DemoBackup_B.UpperRelop_i) {
    PMSM_DemoBackup_B.Switch_ii = PMSM_DemoBackup_B.inv_e;
  } else {
    PMSM_DemoBackup_B.Switch_ii = PMSM_DemoBackup_B.Sum4;
  }

  /* End of Switch: '<S68>/Switch' */

  /* Switch: '<S68>/Switch2' */
  if (PMSM_DemoBackup_B.LowerRelop1_b) {
    PMSM_DemoBackup_B.Switch2_n = PMSM_DemoBackup_B.MathFunction2;
  } else {
    PMSM_DemoBackup_B.Switch2_n = PMSM_DemoBackup_B.Switch_ii;
  }

  /* End of Switch: '<S68>/Switch2' */

  /* UnitDelay: '<S96>/Unit Delay1' */
  PMSM_DemoBackup_B.UnitDelay1_f = PMSM_DemoBackup_DW.UnitDelay1_DSTATE_c;

  /* RelationalOperator: '<S99>/Compare' incorporates:
   *  Constant: '<S99>/Constant'
   */
  PMSM_DemoBackup_B.Compare_iz = (uint8_T)(PMSM_DemoBackup_B.UnitDelay1_f ==
    PMSM_DemoBackup_P.CompareToConstant_const_m);

  /* UnitDelay: '<S101>/Unit Delay2' */
  PMSM_DemoBackup_B.UnitDelay2_p = PMSM_DemoBackup_DW.UnitDelay2_DSTATE_ot;

  /* RelationalOperator: '<S102>/Compare' incorporates:
   *  Constant: '<S102>/Constant'
   */
  PMSM_DemoBackup_B.Compare_m = (uint8_T)(PMSM_DemoBackup_B.UnitDelay2_p ==
    PMSM_DemoBackup_P.CompareToConstant1_const_o);

  /* RelationalOperator: '<S103>/Compare' incorporates:
   *  Constant: '<S103>/Constant'
   *  Constant: '<S92>/Reset[0|1]'
   */
  PMSM_DemoBackup_B.Compare_n = (uint8_T)(PMSM_DemoBackup_P.Reset01_Value ==
    PMSM_DemoBackup_P.CompareToConstant2_const_i);

  /* Logic: '<S101>/Logical Operator1' */
  PMSM_DemoBackup_B.LogicalOperator1_i = ((PMSM_DemoBackup_B.Compare_m != 0) &&
    (PMSM_DemoBackup_B.Compare_n != 0));

  /* Logic: '<S96>/Logical Operator' */
  PMSM_DemoBackup_B.LogicalOperator_n = ((PMSM_DemoBackup_B.Compare_iz != 0) ||
    PMSM_DemoBackup_B.LogicalOperator1_i);

  /* Switch: '<S96>/Switch1' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S96>/Constant1'
   */
  if (PMSM_DemoBackup_B.LogicalOperator_n) {
    PMSM_DemoBackup_B.Switch1_d = PMSM_DemoBackup_P.zero_Value_j;
  } else {
    PMSM_DemoBackup_B.Switch1_d = PMSM_DemoBackup_P.Constant1_Value_g;
  }

  /* End of Switch: '<S96>/Switch1' */

  /* Gain: '<S92>/torpm' incorporates:
   *  Constant: '<S137>/fRS_Set[Hz]'
   */
  PMSM_DemoBackup_B.torpm = PMSM_DemoBackup_P.torpm_Gain *
    PMSM_DemoBackup_P.PMSM_Ctrl_fRS_Set;

  /* Gain: '<S98>/Gain' */
  PMSM_DemoBackup_B.Gain_l = PMSM_DemoBackup_P.Gain_Gain_jr *
    PMSM_DemoBackup_B.torpm;

  /* Product: '<S96>/Product' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_B.Product_kx = PMSM_DemoBackup_P.T_PWM *
    PMSM_DemoBackup_B.Gain_l;

  /* UnitDelay: '<S96>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay_j = PMSM_DemoBackup_DW.UnitDelay_DSTATE_hf;

  /* Switch: '<S96>/Switch2' incorporates:
   *  Constant: '<S96>/Constant2'
   */
  if (PMSM_DemoBackup_B.LogicalOperator1_i) {
    PMSM_DemoBackup_B.Switch2_f = PMSM_DemoBackup_P.Constant2_Value_gf;
  } else {
    PMSM_DemoBackup_B.Switch2_f = PMSM_DemoBackup_B.UnitDelay_j;
  }

  /* End of Switch: '<S96>/Switch2' */

  /* Sum: '<S96>/Add' */
  PMSM_DemoBackup_B.Add_ag = (PMSM_DemoBackup_B.Switch1_d +
    PMSM_DemoBackup_B.Product_kx) + PMSM_DemoBackup_B.Switch2_f;

  /* RelationalOperator: '<S100>/LowerRelop1' incorporates:
   *  Constant: '<S96>/upper_limit'
   */
  PMSM_DemoBackup_B.LowerRelop1_g = (PMSM_DemoBackup_B.Add_ag >
    PMSM_DemoBackup_P.DISCRETE_INTEGRATOR_upper_limit.v);

  /* RelationalOperator: '<S100>/UpperRelop' incorporates:
   *  Constant: '<S96>/lower_limit'
   */
  PMSM_DemoBackup_B.UpperRelop_j = (PMSM_DemoBackup_B.Add_ag <
    PMSM_DemoBackup_P.DISCRETE_INTEGRATOR_lower_limit.v);

  /* Switch: '<S100>/Switch' incorporates:
   *  Constant: '<S96>/lower_limit'
   */
  if (PMSM_DemoBackup_B.UpperRelop_j) {
    PMSM_DemoBackup_B.Switch_l =
      PMSM_DemoBackup_P.DISCRETE_INTEGRATOR_lower_limit.v;
  } else {
    PMSM_DemoBackup_B.Switch_l = PMSM_DemoBackup_B.Add_ag;
  }

  /* End of Switch: '<S100>/Switch' */

  /* Switch: '<S100>/Switch2' incorporates:
   *  Constant: '<S96>/upper_limit'
   */
  if (PMSM_DemoBackup_B.LowerRelop1_g) {
    PMSM_DemoBackup_B.Switch2_p2 =
      PMSM_DemoBackup_P.DISCRETE_INTEGRATOR_upper_limit.v;
  } else {
    PMSM_DemoBackup_B.Switch2_p2 = PMSM_DemoBackup_B.Switch_l;
  }

  /* End of Switch: '<S100>/Switch2' */

  /* Math: '<S97>/Math Function1' incorporates:
   *  Constant: '<S97>/Constant2'
   */
  PMSM_DemoBackup_B.MathFunction1_i = rt_modd_snf(PMSM_DemoBackup_B.Switch2_p2,
    PMSM_DemoBackup_P.Constant2_Value_gg);

  /* MultiPortSwitch: '<S32>/Multiport Switch' incorporates:
   *  Constant: '<S137>/Ctrl_mode_SW[1 n_ctrl | 2 i_ctrl | 3 v_ctrl]'
   *  Constant: '<S137>/v_d_Set[V]'
   *  Constant: '<S137>/v_q_Set[V]'
   */
  switch ((int32_T)PMSM_DemoBackup_P.PMSM_Ctrl_Ctrl_mode_SW) {
   case 1:
    PMSM_DemoBackup_B.MultiportSwitch_h[0] = PMSM_DemoBackup_B.Switch2_a3;
    PMSM_DemoBackup_B.MultiportSwitch_h[1] = PMSM_DemoBackup_B.Switch2_n;
    PMSM_DemoBackup_B.MultiportSwitch_h[2] = PMSM_DemoBackup_B.MathFunction1;
    break;

   case 2:
    PMSM_DemoBackup_B.MultiportSwitch_h[0] = PMSM_DemoBackup_B.Switch2_a3;
    PMSM_DemoBackup_B.MultiportSwitch_h[1] = PMSM_DemoBackup_B.Switch2_n;
    PMSM_DemoBackup_B.MultiportSwitch_h[2] = PMSM_DemoBackup_B.MathFunction1;
    break;

   default:
    PMSM_DemoBackup_B.MultiportSwitch_h[0] = PMSM_DemoBackup_P.PMSM_Ctrl_v_d_Set;
    PMSM_DemoBackup_B.MultiportSwitch_h[1] = PMSM_DemoBackup_P.PMSM_Ctrl_v_q_Set;
    PMSM_DemoBackup_B.MultiportSwitch_h[2] = PMSM_DemoBackup_B.MathFunction1_i;
    break;
  }

  /* End of MultiPortSwitch: '<S32>/Multiport Switch' */

  /* Fcn: '<S104>/cos' */
  PMSM_DemoBackup_B.cos_i = cos(PMSM_DemoBackup_B.MultiportSwitch_h[2]);

  /* Product: '<S104>/Product1' */
  PMSM_DemoBackup_B.Product1_g = PMSM_DemoBackup_B.MultiportSwitch_h[0] *
    PMSM_DemoBackup_B.cos_i;

  /* Fcn: '<S104>/sin' */
  PMSM_DemoBackup_B.sin_k = sin(PMSM_DemoBackup_B.MultiportSwitch_h[2]);

  /* Gain: '<S104>/inv' */
  PMSM_DemoBackup_B.inv_p = PMSM_DemoBackup_P.inv_Gain_if *
    PMSM_DemoBackup_B.sin_k;

  /* Product: '<S104>/Product2' */
  PMSM_DemoBackup_B.Product2_m = PMSM_DemoBackup_B.MultiportSwitch_h[1] *
    PMSM_DemoBackup_B.inv_p;

  /* Sum: '<S104>/Sum1' */
  PMSM_DemoBackup_B.Sum1_e = PMSM_DemoBackup_B.Product1_g +
    PMSM_DemoBackup_B.Product2_m;

  /* Gain: '<S105>/Gain1' */
  PMSM_DemoBackup_B.Gain1_k = PMSM_DemoBackup_P.Gain1_Gain_d *
    PMSM_DemoBackup_B.Sum1_e;

  /* Gain: '<S105>/Gain2' */
  PMSM_DemoBackup_B.Gain2 = PMSM_DemoBackup_P.Gain2_Gain_c *
    PMSM_DemoBackup_B.Sum1_e;

  /* Product: '<S104>/Product3' */
  PMSM_DemoBackup_B.Product3_l = PMSM_DemoBackup_B.MultiportSwitch_h[0] *
    PMSM_DemoBackup_B.sin_k;

  /* Product: '<S104>/Product4' */
  PMSM_DemoBackup_B.Product4_m = PMSM_DemoBackup_B.MultiportSwitch_h[1] *
    PMSM_DemoBackup_B.cos_i;

  /* Sum: '<S104>/Sum' */
  PMSM_DemoBackup_B.Sum_m = PMSM_DemoBackup_B.Product3_l +
    PMSM_DemoBackup_B.Product4_m;

  /* Gain: '<S105>/Gain3' */
  PMSM_DemoBackup_B.Gain3_k = PMSM_DemoBackup_P.Gain3_Gain_ld *
    PMSM_DemoBackup_B.Sum_m;

  /* Sum: '<S105>/Sum' */
  PMSM_DemoBackup_B.Sum_n = PMSM_DemoBackup_B.Gain2 + PMSM_DemoBackup_B.Gain3_k;

  /* Sum: '<S105>/Sum1' */
  PMSM_DemoBackup_B.Sum1_i = PMSM_DemoBackup_B.Gain2 - PMSM_DemoBackup_B.Gain3_k;

  /* Product: '<S23>/Product' */
  PMSM_DemoBackup_B.Product_ko[0] = PMSM_DemoBackup_B.Gain1_k /
    PMSM_DemoBackup_B.uFilterTime_g;
  PMSM_DemoBackup_B.Product_ko[1] = PMSM_DemoBackup_B.Sum_n /
    PMSM_DemoBackup_B.uFilterTime_g;
  PMSM_DemoBackup_B.Product_ko[2] = PMSM_DemoBackup_B.Sum1_i /
    PMSM_DemoBackup_B.uFilterTime_g;

  /* MinMax: '<S23>/Min' */
  u1 = PMSM_DemoBackup_B.Product_ko[0];
  u0 = PMSM_DemoBackup_B.Product_ko[1];
  if ((!(u1 < u0)) && (!rtIsNaN(u0))) {
    u1 = u0;
  }

  u0 = PMSM_DemoBackup_B.Product_ko[2];
  if ((!(u1 < u0)) && (!rtIsNaN(u0))) {
    u1 = u0;
  }

  PMSM_DemoBackup_B.Min = u1;

  /* End of MinMax: '<S23>/Min' */

  /* MinMax: '<S23>/Max' */
  u1 = PMSM_DemoBackup_B.Product_ko[0];
  u0 = PMSM_DemoBackup_B.Product_ko[1];
  if ((!(u1 > u0)) && (!rtIsNaN(u0))) {
    u1 = u0;
  }

  u0 = PMSM_DemoBackup_B.Product_ko[2];
  if ((!(u1 > u0)) && (!rtIsNaN(u0))) {
    u1 = u0;
  }

  PMSM_DemoBackup_B.Max = u1;

  /* End of MinMax: '<S23>/Max' */

  /* Sum: '<S23>/Sum' */
  PMSM_DemoBackup_B.Sum_mb = PMSM_DemoBackup_B.Max - PMSM_DemoBackup_B.Min;

  /* Sum: '<S23>/Sum4' incorporates:
   *  Constant: '<S23>/one'
   */
  PMSM_DemoBackup_B.Sum4_k = PMSM_DemoBackup_P.one_Value -
    PMSM_DemoBackup_B.Sum_mb;

  /* Gain: '<S23>/half' */
  PMSM_DemoBackup_B.half = PMSM_DemoBackup_P.half_Gain *
    PMSM_DemoBackup_B.Sum4_k;

  /* Sum: '<S23>/Sum2' */
  PMSM_DemoBackup_B.Sum2_l[0] = (PMSM_DemoBackup_B.Product_ko[0] -
    PMSM_DemoBackup_B.Min) + PMSM_DemoBackup_B.half;

  /* Saturate: '<S23>/Saturation' */
  u0 = PMSM_DemoBackup_B.Sum2_l[0];
  if (u0 > PMSM_DemoBackup_P.Saturation_UpperSat_p) {
    u0 = PMSM_DemoBackup_P.Saturation_UpperSat_p;
  } else {
    if (u0 < PMSM_DemoBackup_P.Saturation_LowerSat_k) {
      u0 = PMSM_DemoBackup_P.Saturation_LowerSat_k;
    }
  }

  PMSM_DemoBackup_B.Saturation_m[0] = u0;

  /* Sum: '<S23>/Sum2' */
  PMSM_DemoBackup_B.Sum2_l[1] = (PMSM_DemoBackup_B.Product_ko[1] -
    PMSM_DemoBackup_B.Min) + PMSM_DemoBackup_B.half;

  /* Saturate: '<S23>/Saturation' */
  u0 = PMSM_DemoBackup_B.Sum2_l[1];
  if (u0 > PMSM_DemoBackup_P.Saturation_UpperSat_p) {
    u0 = PMSM_DemoBackup_P.Saturation_UpperSat_p;
  } else {
    if (u0 < PMSM_DemoBackup_P.Saturation_LowerSat_k) {
      u0 = PMSM_DemoBackup_P.Saturation_LowerSat_k;
    }
  }

  PMSM_DemoBackup_B.Saturation_m[1] = u0;

  /* Sum: '<S23>/Sum2' */
  PMSM_DemoBackup_B.Sum2_l[2] = (PMSM_DemoBackup_B.Product_ko[2] -
    PMSM_DemoBackup_B.Min) + PMSM_DemoBackup_B.half;

  /* Saturate: '<S23>/Saturation' */
  u0 = PMSM_DemoBackup_B.Sum2_l[2];
  if (u0 > PMSM_DemoBackup_P.Saturation_UpperSat_p) {
    u0 = PMSM_DemoBackup_P.Saturation_UpperSat_p;
  } else {
    if (u0 < PMSM_DemoBackup_P.Saturation_LowerSat_k) {
      u0 = PMSM_DemoBackup_P.Saturation_LowerSat_k;
    }
  }

  PMSM_DemoBackup_B.Saturation_m[2] = u0;

  /* Gain: '<S135>/Gain6' */
  PMSM_DemoBackup_B.Gain6[0] = PMSM_DemoBackup_P.Gain6_Gain *
    PMSM_DemoBackup_B.Saturation_m[0];
  PMSM_DemoBackup_B.Gain6[1] = PMSM_DemoBackup_P.Gain6_Gain *
    PMSM_DemoBackup_B.Saturation_m[1];
  PMSM_DemoBackup_B.Gain6[2] = PMSM_DemoBackup_P.Gain6_Gain *
    PMSM_DemoBackup_B.Saturation_m[2];

  /* Sum: '<S23>/Sum3' incorporates:
   *  Constant: '<S23>/one'
   */
  PMSM_DemoBackup_B.Sum3_i[0] = PMSM_DemoBackup_P.one_Value -
    PMSM_DemoBackup_B.Saturation_m[0];
  PMSM_DemoBackup_B.Sum3_i[1] = PMSM_DemoBackup_P.one_Value -
    PMSM_DemoBackup_B.Saturation_m[1];
  PMSM_DemoBackup_B.Sum3_i[2] = PMSM_DemoBackup_P.one_Value -
    PMSM_DemoBackup_B.Saturation_m[2];

  /* Gain: '<S135>/Gain7' */
  PMSM_DemoBackup_B.Gain7[0] = PMSM_DemoBackup_P.Gain7_Gain *
    PMSM_DemoBackup_B.Sum3_i[0];
  PMSM_DemoBackup_B.Gain7[1] = PMSM_DemoBackup_P.Gain7_Gain *
    PMSM_DemoBackup_B.Sum3_i[1];
  PMSM_DemoBackup_B.Gain7[2] = PMSM_DemoBackup_P.Gain7_Gain *
    PMSM_DemoBackup_B.Sum3_i[2];

  /* Gain: '<S135>/Gain16' */
  PMSM_DemoBackup_B.Gain16 = PMSM_DemoBackup_P.Gain16_Gain *
    PMSM_DemoBackup_B.Gain3_l;

  /* Gain: '<S135>/Gain17' */
  PMSM_DemoBackup_B.Gain17 = PMSM_DemoBackup_P.Gain17_Gain_h *
    PMSM_DemoBackup_B.Switch2_dh;

  /* Gain: '<S135>/Gain10' */
  PMSM_DemoBackup_B.Gain10[0] = PMSM_DemoBackup_P.Gain10_Gain *
    PMSM_DemoBackup_B.Sum1_e;
  PMSM_DemoBackup_B.Gain10[1] = PMSM_DemoBackup_P.Gain10_Gain *
    PMSM_DemoBackup_B.Sum_m;

  /* Gain: '<S135>/Gain8' */
  PMSM_DemoBackup_B.Gain8[0] = PMSM_DemoBackup_P.Gain8_Gain *
    PMSM_DemoBackup_B.Gain1_k;
  PMSM_DemoBackup_B.Gain8[1] = PMSM_DemoBackup_P.Gain8_Gain *
    PMSM_DemoBackup_B.Sum_n;
  PMSM_DemoBackup_B.Gain8[2] = PMSM_DemoBackup_P.Gain8_Gain *
    PMSM_DemoBackup_B.Sum1_i;

  /* Product: '<S65>/Product' */
  PMSM_DemoBackup_B.Product_ew = PMSM_DemoBackup_B.uFilterTime_m *
    PMSM_DemoBackup_B.toRads;

  /* Gain: '<S65>/Const_Lsd[H]' */
  PMSM_DemoBackup_B.Const_LsdH_e = PMSM_DemoBackup_P.Const_Ld_Stator *
    PMSM_DemoBackup_B.Product_ew;

  /* Sum: '<S65>/Sum3' */
  PMSM_DemoBackup_B.Sum3_b = PMSM_DemoBackup_B.Switch2_a3 +
    PMSM_DemoBackup_B.Const_LsdH_e;

  /* Gain: '<S135>/Gain1' */
  PMSM_DemoBackup_B.Gain1_c[0] = PMSM_DemoBackup_P.Gain1_Gain_n *
    PMSM_DemoBackup_B.Sum_jb;
  PMSM_DemoBackup_B.Gain1_c[1] = PMSM_DemoBackup_P.Gain1_Gain_n *
    PMSM_DemoBackup_B.Sum3_b;
  PMSM_DemoBackup_B.Gain1_c[2] = PMSM_DemoBackup_P.Gain1_Gain_n *
    PMSM_DemoBackup_B.Switch2_a3;

  /* Product: '<S65>/Product1' */
  PMSM_DemoBackup_B.Product1_k = PMSM_DemoBackup_B.toRads *
    PMSM_DemoBackup_B.uFilterTime;

  /* Gain: '<S65>/Const_Lsq[H]' */
  PMSM_DemoBackup_B.Const_LsqH_a = PMSM_DemoBackup_P.Const_Lq_Stator *
    PMSM_DemoBackup_B.Product1_k;

  /* Sum: '<S65>/Sum1' */
  PMSM_DemoBackup_B.Sum1_fm = PMSM_DemoBackup_B.Switch2_n -
    PMSM_DemoBackup_B.Const_LsqH_a;

  /* Gain: '<S65>/Const_Psi[Wb]' */
  PMSM_DemoBackup_B.Const_PsiWb_k = PMSM_DemoBackup_P.Const_Psi *
    PMSM_DemoBackup_B.toRads;

  /* Sum: '<S65>/Sum4' */
  PMSM_DemoBackup_B.Sum4_c = PMSM_DemoBackup_B.Sum1_fm -
    PMSM_DemoBackup_B.Const_PsiWb_k;

  /* Gain: '<S135>/Gain2' */
  PMSM_DemoBackup_B.Gain2_l[0] = PMSM_DemoBackup_P.Gain2_Gain_f *
    PMSM_DemoBackup_B.Sum_a;
  PMSM_DemoBackup_B.Gain2_l[1] = PMSM_DemoBackup_P.Gain2_Gain_f *
    PMSM_DemoBackup_B.Sum4_c;
  PMSM_DemoBackup_B.Gain2_l[2] = PMSM_DemoBackup_P.Gain2_Gain_f *
    PMSM_DemoBackup_B.Switch2_n;

  /* RelationalOperator: '<S138>/Compare' incorporates:
   *  Constant: '<S137>/Ctrl_mode_SW[1 n_ctrl | 2 i_ctrl | 3 v_ctrl]'
   *  Constant: '<S138>/Constant'
   */
  PMSM_DemoBackup_B.Compare_py = (uint8_T)
    (PMSM_DemoBackup_P.PMSM_Ctrl_Ctrl_mode_SW ==
     PMSM_DemoBackup_P.CompareToConstant_const_hp);

  /* RelationalOperator: '<S139>/Compare' incorporates:
   *  Constant: '<S137>/Ctrl_mode_SW[1 n_ctrl | 2 i_ctrl | 3 v_ctrl]'
   *  Constant: '<S139>/Constant'
   */
  PMSM_DemoBackup_B.Compare_k = (uint8_T)
    (PMSM_DemoBackup_P.PMSM_Ctrl_Ctrl_mode_SW ==
     PMSM_DemoBackup_P.CompareToConstant1_const_a);

  /* RelationalOperator: '<S140>/Compare' incorporates:
   *  Constant: '<S140>/Constant'
   */
  PMSM_DemoBackup_B.Compare_iv = (uint8_T)
    (PMSM_DemoBackup_B.Choose_ref_value_n_g ==
     PMSM_DemoBackup_P.CompareToConstant2_const_k);

  /* RelationalOperator: '<S141>/Compare' incorporates:
   *  Constant: '<S141>/Constant'
   */
  PMSM_DemoBackup_B.Compare_dx = (uint8_T)
    (PMSM_DemoBackup_B.Choose_ref_value_n_g ==
     PMSM_DemoBackup_P.CompareToConstant3_const);

  /* RelationalOperator: '<S142>/Compare' incorporates:
   *  Constant: '<S142>/Constant'
   */
  PMSM_DemoBackup_B.Compare_pwu = (uint8_T)
    (PMSM_DemoBackup_B.Choose_ref_value_i_m ==
     PMSM_DemoBackup_P.CompareToConstant4_const);

  /* RelationalOperator: '<S143>/Compare' incorporates:
   *  Constant: '<S143>/Constant'
   */
  PMSM_DemoBackup_B.Compare_e = (uint8_T)(PMSM_DemoBackup_B.Choose_ref_value_i_m
    == PMSM_DemoBackup_P.CompareToConstant5_const);

  /* Logic: '<S135>/Logical Operator1' */
  PMSM_DemoBackup_B.Mode_n_manual = ((PMSM_DemoBackup_B.Compare_dx != 0) &&
    (PMSM_DemoBackup_B.Compare_py != 0));

  /* Gain: '<S135>/Gain11' */
  PMSM_DemoBackup_B.Gain11 = (uint8_T)(PMSM_DemoBackup_B.Mode_n_manual ?
    (int32_T)PMSM_DemoBackup_P.Gain11_Gain_f : 0);

  /* Logic: '<S135>/Logical Operator' */
  PMSM_DemoBackup_B.Mode_n_sig_gen = ((PMSM_DemoBackup_B.Compare_iv != 0) &&
    (PMSM_DemoBackup_B.Compare_py != 0));

  /* Gain: '<S135>/Gain12' */
  PMSM_DemoBackup_B.Gain12 = (uint8_T)(PMSM_DemoBackup_B.Mode_n_sig_gen ?
    (int32_T)PMSM_DemoBackup_P.Gain12_Gain_o : 0);

  /* Logic: '<S135>/Logical Operator2' */
  PMSM_DemoBackup_B.Mode_i_sig_gen = ((PMSM_DemoBackup_B.Compare_k != 0) &&
    (PMSM_DemoBackup_B.Compare_pwu != 0));

  /* Gain: '<S135>/Gain13' */
  PMSM_DemoBackup_B.Gain13 = (uint8_T)(PMSM_DemoBackup_B.Mode_i_sig_gen ?
    (int32_T)PMSM_DemoBackup_P.Gain13_Gain_g : 0);

  /* Logic: '<S135>/Logical Operator3' */
  PMSM_DemoBackup_B.Mode_i_manual = ((PMSM_DemoBackup_B.Compare_k != 0) &&
    (PMSM_DemoBackup_B.Compare_e != 0));

  /* Gain: '<S135>/Gain14' */
  PMSM_DemoBackup_B.Gain14 = (uint8_T)(PMSM_DemoBackup_B.Mode_i_manual ?
    (int32_T)PMSM_DemoBackup_P.Gain14_Gain_i : 0);

  /* Switch: '<S135>/Switch' incorporates:
   *  Constant: '<S137>/Ctrl_mode_SW[1 n_ctrl | 2 i_ctrl | 3 v_ctrl]'
   */
  if (PMSM_DemoBackup_P.PMSM_Ctrl_Ctrl_mode_SW >=
      PMSM_DemoBackup_P.Switch_Threshold_n) {
    PMSM_DemoBackup_B.Plotter_trigger_var = PMSM_DemoBackup_B.Saturation;
  } else {
    PMSM_DemoBackup_B.Plotter_trigger_var = PMSM_DemoBackup_B.Saturation2;
  }

  /* End of Switch: '<S135>/Switch' */

  /* Gain: '<S135>/Gain15' */
  PMSM_DemoBackup_B.Gain15 = PMSM_DemoBackup_P.Gain15_Gain_j *
    PMSM_DemoBackup_B.Plotter_trigger_var;

  /* Gain: '<S135>/Gain9' */
  PMSM_DemoBackup_B.Gain9[0] = PMSM_DemoBackup_P.Gain9_Gain_j *
    PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[0];
  PMSM_DemoBackup_B.Gain9[1] = PMSM_DemoBackup_P.Gain9_Gain_j *
    PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[1];
  PMSM_DemoBackup_B.Gain9[2] = PMSM_DemoBackup_P.Gain9_Gain_j *
    PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[2];

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Duty_A'
   *  Constant: '<S13>/Duty_B'
   *  Constant: '<S13>/Duty_C'
   *  Constant: '<S13>/UseController'
   */
  if (PMSM_DemoBackup_P.UseController_Value != 0.0) {
    PMSM_DemoBackup_B.Switch_nv[0] = PMSM_DemoBackup_B.Saturation_m[0];
    PMSM_DemoBackup_B.Switch_nv[1] = PMSM_DemoBackup_B.Saturation_m[1];
    PMSM_DemoBackup_B.Switch_nv[2] = PMSM_DemoBackup_B.Saturation_m[2];
  } else {
    PMSM_DemoBackup_B.Switch_nv[0] = PMSM_DemoBackup_P.Duty_A_Value;
    PMSM_DemoBackup_B.Switch_nv[1] = PMSM_DemoBackup_P.Duty_B_Value;
    PMSM_DemoBackup_B.Switch_nv[2] = PMSM_DemoBackup_P.Duty_C_Value;
  }

  /* End of Switch: '<S13>/Switch' */

  /* S-Function (rti_commonblock): '<S134>/S-Function1' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Output/EMC_MC_PWM_BL1 --- */
  /* --- [RTIEMC, MCPWM] - Port: 1 - Channel: 7 --- */
  {
    /* write Period for the MCPWM output channels 7-9 on port 1 */
    DioCl1MultiPwmOut_setPeriod(pRTIEmcMultiPwmOut_Port_1_Ch_7, (real_T)
      PMSM_DemoBackup_P.T_PWM);

    /* write DutyCycle for the MCPWM output channels 7-9 on port 1 */
    DioCl1MultiPwmOut_setDutyCycle(pRTIEmcMultiPwmOut_Port_1_Ch_7,
      &PMSM_DemoBackup_B.Switch_nv[0]);
    DioCl1MultiPwmOut_write(pRTIEmcMultiPwmOut_Port_1_Ch_7);
  }

  /* Sum: '<S34>/FixPt Sum1' incorporates:
   *  Constant: '<S34>/FixPt Constant'
   */
  PMSM_DemoBackup_B.FixPtSum1 = (uint8_T)((uint32_T)PMSM_DemoBackup_B.Output +
    PMSM_DemoBackup_P.FixPtConstant_Value);

  /* Switch: '<S35>/FixPt Switch' incorporates:
   *  Constant: '<S35>/Constant'
   */
  if (PMSM_DemoBackup_B.FixPtSum1 > PMSM_DemoBackup_P.CounterLimited_uplimit) {
    PMSM_DemoBackup_B.FixPtSwitch = PMSM_DemoBackup_P.Constant_Value_i;
  } else {
    PMSM_DemoBackup_B.FixPtSwitch = PMSM_DemoBackup_B.FixPtSum1;
  }

  /* End of Switch: '<S35>/FixPt Switch' */

  /* Product: '<S28>/Product1' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_B.Product1_dq = PMSM_DemoBackup_P.T_PWM *
    PMSM_DemoBackup_B.toRads;

  /* Sum: '<S39>/Sum2' */
  PMSM_DemoBackup_B.Sum2_h = PMSM_DemoBackup_B.Sum3_b -
    PMSM_DemoBackup_B.Product1_b;

  /* Sum: '<S40>/Sum2' */
  PMSM_DemoBackup_B.Sum2_ll = PMSM_DemoBackup_B.Sum4_c -
    PMSM_DemoBackup_B.Product1_c;

  /* Math: '<S61>/Math Function3' */
  PMSM_DemoBackup_B.MathFunction3 = PMSM_DemoBackup_B.Sum3 *
    PMSM_DemoBackup_B.Sum3;

  /* Math: '<S61>/Math Function4' */
  PMSM_DemoBackup_B.MathFunction4 = PMSM_DemoBackup_B.Sum4 *
    PMSM_DemoBackup_B.Sum4;

  /* Sum: '<S61>/Add1' */
  PMSM_DemoBackup_B.Add1 = PMSM_DemoBackup_B.MathFunction3 +
    PMSM_DemoBackup_B.MathFunction4;

  /* Sqrt: '<S61>/Math Function5'
   *
   * About '<S61>/Math Function5':
   *  Operator: signedSqrt
   */
  u1 = PMSM_DemoBackup_B.Add1;
  if (u1 < 0.0) {
    PMSM_DemoBackup_B.MathFunction5 = -sqrt(fabs(u1));
  } else {
    PMSM_DemoBackup_B.MathFunction5 = sqrt(u1);
  }

  /* End of Sqrt: '<S61>/Math Function5' */

  /* Gain: '<S61>/Gain' */
  PMSM_DemoBackup_B.Gain_j = PMSM_DemoBackup_P.Gain_Gain_k *
    PMSM_DemoBackup_B.LimitingFactor;

  /* Sum: '<S61>/Add2' */
  PMSM_DemoBackup_B.Add2 = PMSM_DemoBackup_B.Gain_j -
    PMSM_DemoBackup_B.MathFunction5;

  /* Saturate: '<S61>/Saturation' */
  if (PMSM_DemoBackup_B.Add2 > PMSM_DemoBackup_P.Saturation_UpperSat_a) {
    PMSM_DemoBackup_B.Saturation_a = PMSM_DemoBackup_P.Saturation_UpperSat_a;
  } else if (PMSM_DemoBackup_B.Add2 < PMSM_DemoBackup_P.Saturation_LowerSat_n) {
    PMSM_DemoBackup_B.Saturation_a = PMSM_DemoBackup_P.Saturation_LowerSat_n;
  } else {
    PMSM_DemoBackup_B.Saturation_a = PMSM_DemoBackup_B.Add2;
  }

  /* End of Saturate: '<S61>/Saturation' */

  /* UnitDelay: '<S61>/Unit Delay' */
  PMSM_DemoBackup_B.UnitDelay_b = PMSM_DemoBackup_DW.UnitDelay_DSTATE_l;

  /* Sum: '<S61>/Sum' */
  PMSM_DemoBackup_B.Sum_c = PMSM_DemoBackup_B.Saturation_a +
    PMSM_DemoBackup_B.UnitDelay_b;

  /* Saturate: '<S61>/Saturation1' */
  if (PMSM_DemoBackup_B.Sum_c > PMSM_DemoBackup_P.Saturation1_UpperSat_a) {
    PMSM_DemoBackup_B.Saturation1_m = PMSM_DemoBackup_P.Saturation1_UpperSat_a;
  } else if (PMSM_DemoBackup_B.Sum_c < PMSM_DemoBackup_P.Saturation1_LowerSat_i)
  {
    PMSM_DemoBackup_B.Saturation1_m = PMSM_DemoBackup_P.Saturation1_LowerSat_i;
  } else {
    PMSM_DemoBackup_B.Saturation1_m = PMSM_DemoBackup_B.Sum_c;
  }

  /* End of Saturate: '<S61>/Saturation1' */

  /* Gain: '<S66>/Gain' */
  PMSM_DemoBackup_B.Gain_a = PMSM_DemoBackup_P.Gain_Gain_m *
    PMSM_DemoBackup_B.Saturation1_m;

  /* Sum: '<S66>/Sum' incorporates:
   *  Constant: '<S66>/Offset'
   */
  PMSM_DemoBackup_B.Sum_o = PMSM_DemoBackup_B.Gain_a +
    PMSM_DemoBackup_P.Offset_Value;

  /* MultiPortSwitch: '<S61>/Multiport Switch' incorporates:
   *  Constant: '<S61>/SW_Fieldweakening[1|2]'
   *  Constant: '<S61>/Zero'
   */
  if ((int32_T)PMSM_DemoBackup_P.SW_Fieldweakening == 1) {
    PMSM_DemoBackup_B.MultiportSwitch_g = PMSM_DemoBackup_P.Zero_Value;
  } else {
    PMSM_DemoBackup_B.MultiportSwitch_g = PMSM_DemoBackup_B.Sum_o;
  }

  /* End of MultiPortSwitch: '<S61>/Multiport Switch' */

  /* Trigonometry: '<S61>/Trigonometric Function' */
  PMSM_DemoBackup_B.TrigonometricFunction = sin
    (PMSM_DemoBackup_B.MultiportSwitch_g);

  /* Trigonometry: '<S61>/Trigonometric Function1' */
  PMSM_DemoBackup_B.TrigonometricFunction1 = cos
    (PMSM_DemoBackup_B.MultiportSwitch_g);

  /* S-Function (rti_commonblock): '<S121>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL2 --- */
  /* --- [RTI120X, ADC C1] - Channel: 2 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_2);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_2, readStateFlag, (real_T*)
      &PMSM_DemoBackup_B.SFunction1_o1_p);
    PMSM_DemoBackup_B.SFunction1_o2_m = (int16_T) readStateFlag[0];
  }

  /* S-Function (rti_commonblock): '<S123>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL4 --- */
  /* --- [RTI120X, ADC C1] - Channel: 4 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_4);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_4, readStateFlag, (real_T*)
      &PMSM_DemoBackup_B.SFunction1_o1_h);
    PMSM_DemoBackup_B.SFunction1_o2_p0 = (int16_T) readStateFlag[0];
  }

  /* S-Function (rti_commonblock): '<S125>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL6 --- */
  /* --- [RTI120X, ADC C1] - Channel: 6 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_6);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_6, readStateFlag, (real_T*)
      &PMSM_DemoBackup_B.SFunction1_o1_gf);
    PMSM_DemoBackup_B.SFunction1_o2_c = (int16_T) readStateFlag[0];
  }

  /* S-Function (rti_commonblock): '<S127>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Input/AD_Measurement/ADC_CLASS1_BL8 --- */
  /* --- [RTI120X, ADC C1] - Channel: 8 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_8);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_8, readStateFlag, (real_T*)
      &PMSM_DemoBackup_B.SFunction1_o1_o);
    PMSM_DemoBackup_B.SFunction1_o2_o = (int16_T) readStateFlag[0];
  }

  /* Gain: '<S109>/Gain20' */
  PMSM_DemoBackup_B.VoltageADC6V = PMSM_DemoBackup_P.Gain20_Gain *
    PMSM_DemoBackup_B.SFunction1_o1_gf;

  /* Gain: '<S109>/Gain10' */
  PMSM_DemoBackup_B.PhaseB_VoltageV = PMSM_DemoBackup_P.Gain10_Gain_k *
    PMSM_DemoBackup_B.VoltageADC6V;

  /* Gain: '<S109>/Gain21' */
  PMSM_DemoBackup_B.VoltageADC8V = PMSM_DemoBackup_P.Gain21_Gain *
    PMSM_DemoBackup_B.SFunction1_o1_o;

  /* Gain: '<S109>/Gain11' */
  PMSM_DemoBackup_B.PhaseC_VoltageV = PMSM_DemoBackup_P.Gain11_Gain *
    PMSM_DemoBackup_B.VoltageADC8V;

  /* Gain: '<S109>/Gain16' */
  PMSM_DemoBackup_B.VoltageADC4V = PMSM_DemoBackup_P.Gain16_Gain_o *
    PMSM_DemoBackup_B.SFunction1_o1_h;

  /* Gain: '<S109>/Gain12' */
  PMSM_DemoBackup_B.not_used = PMSM_DemoBackup_P.Gain12_Gain *
    PMSM_DemoBackup_B.VoltageADC4V;

  /* Gain: '<S109>/Gain14' */
  PMSM_DemoBackup_B.VoltageADC2V = PMSM_DemoBackup_P.Gain14_Gain *
    PMSM_DemoBackup_B.SFunction1_o1_p;

  /* Gain: '<S109>/Gain22' */
  PMSM_DemoBackup_B.Gain22 = PMSM_DemoBackup_P.Gain22_Gain *
    PMSM_DemoBackup_B.SFunction1_o2_p;

  /* Gain: '<S109>/Gain23' */
  PMSM_DemoBackup_B.Gain23 = PMSM_DemoBackup_P.Gain23_Gain *
    PMSM_DemoBackup_B.SFunction1_o2_k;

  /* Gain: '<S109>/Gain24' */
  PMSM_DemoBackup_B.Gain24 = PMSM_DemoBackup_P.Gain24_Gain *
    PMSM_DemoBackup_B.SFunction1_o2_g;

  /* Gain: '<S109>/Gain25' */
  PMSM_DemoBackup_B.Gain25 = PMSM_DemoBackup_P.Gain25_Gain *
    PMSM_DemoBackup_B.SFunction1_o2_m;

  /* Gain: '<S109>/Gain26' */
  PMSM_DemoBackup_B.Gain26 = PMSM_DemoBackup_P.Gain26_Gain *
    PMSM_DemoBackup_B.SFunction1_o2_pt;

  /* Gain: '<S109>/Gain27' */
  PMSM_DemoBackup_B.Gain27 = PMSM_DemoBackup_P.Gain27_Gain *
    PMSM_DemoBackup_B.SFunction1_o2_p0;

  /* Gain: '<S109>/Gain28' */
  PMSM_DemoBackup_B.Gain28 = PMSM_DemoBackup_P.Gain28_Gain *
    PMSM_DemoBackup_B.SFunction1_o2_c;

  /* Gain: '<S109>/Gain29' */
  PMSM_DemoBackup_B.Gain29 = PMSM_DemoBackup_P.Gain29_Gain *
    PMSM_DemoBackup_B.SFunction1_o2_o;

  /* Gain: '<S109>/Gain8' */
  PMSM_DemoBackup_B.PhaseA_VoltageV = PMSM_DemoBackup_P.Gain8_Gain_h *
    PMSM_DemoBackup_B.VoltageADC2V;

  /* Gain: '<S109>/Gain' */
  PMSM_DemoBackup_B.Gain_e = PMSM_DemoBackup_P.Gain_Gain_o * 0.0;

  /* Gain: '<S109>/Gain1' */
  PMSM_DemoBackup_B.Gain1_a = PMSM_DemoBackup_P.Gain1_Gain_m * 0.0;

  /* Gain: '<S109>/Gain2' */
  PMSM_DemoBackup_B.Gain2_lh = PMSM_DemoBackup_P.Gain2_Gain_h * 0.0;

  /* Gain: '<S109>/Gain3' */
  PMSM_DemoBackup_B.Gain3_j = PMSM_DemoBackup_P.Gain3_Gain_m * 0.0;

  /* Gain: '<S109>/Gain4' */
  PMSM_DemoBackup_B.Gain4_a = PMSM_DemoBackup_P.Gain4_Gain_k * 0.0;

  /* Gain: '<S109>/Gain5' */
  PMSM_DemoBackup_B.Gain5_o = PMSM_DemoBackup_P.Gain5_Gain_b * 0.0;

  /* Gain: '<S109>/Gain6' */
  PMSM_DemoBackup_B.Gain6_m = PMSM_DemoBackup_P.Gain6_Gain_g * 0.0;

  /* Gain: '<S109>/Gain7' */
  PMSM_DemoBackup_B.Gain7_k = PMSM_DemoBackup_P.Gain7_Gain_j * 0.0;

  /* DataTypeConversion: '<S12>/bool2double1' */
  PMSM_DemoBackup_B.hall_A = PMSM_DemoBackup_B.SFunction1_o2_cq;

  /* DataTypeConversion: '<S12>/bool2double2' */
  PMSM_DemoBackup_B.hall_B = PMSM_DemoBackup_B.SFunction1_o3_f;

  /* DataTypeConversion: '<S12>/bool2double3' */
  PMSM_DemoBackup_B.hall_C = PMSM_DemoBackup_B.SFunction1_o4_b;

  /* S-Function (rti_commonblock): '<S111>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S8>/Load_gain' */
  PMSM_DemoBackup_B.Load_gain = PMSM_DemoBackup_P.Load_gain_Gain *
    PMSM_DemoBackup_B.DataTypeConversion;

  /* Lookup_n-D: '<S18>/load_2_current4' */
  PMSM_DemoBackup_B.load_2_current4 = look1_binlxpw(PMSM_DemoBackup_B.Load_gain,
    PMSM_DemoBackup_P.load_2_current4_bp01Data,
    PMSM_DemoBackup_P.load_2_current4_tableData, 5U);

  /* Gain: '<S18>/current_2_voltage' */
  PMSM_DemoBackup_B.current_2_voltage = PMSM_DemoBackup_P.current_2_voltage_Gain
    * PMSM_DemoBackup_B.load_2_current4;

  /* Product: '<S21>/Divide' */
  PMSM_DemoBackup_B.Divide = PMSM_DemoBackup_B.current_2_voltage /
    PMSM_DemoBackup_B.Battery_VoltageV;

  /* Saturate: '<S21>/Saturation' */
  if (PMSM_DemoBackup_B.Divide > PMSM_DemoBackup_P.Saturation_UpperSat_j) {
    PMSM_DemoBackup_B.Saturation_f = PMSM_DemoBackup_P.Saturation_UpperSat_j;
  } else if (PMSM_DemoBackup_B.Divide < PMSM_DemoBackup_P.Saturation_LowerSat_l)
  {
    PMSM_DemoBackup_B.Saturation_f = PMSM_DemoBackup_P.Saturation_LowerSat_l;
  } else {
    PMSM_DemoBackup_B.Saturation_f = PMSM_DemoBackup_B.Divide;
  }

  /* End of Saturate: '<S21>/Saturation' */

  /* DataTypeConversion: '<S8>/Data Type Conversion3' */
  PMSM_DemoBackup_B.DataTypeConversion3 = PMSM_DemoBackup_B.Saturation_f;

  /* Lookup_n-D: '<S17>/load_2_current4' incorporates:
   *  Constant: '<S8>/load_value_man[Nm]'
   */
  PMSM_DemoBackup_B.load_2_current4_j = look1_binlxpw
    (PMSM_DemoBackup_P.load_value_manNm_Value,
     PMSM_DemoBackup_P.load_2_current4_bp01Data_j,
     PMSM_DemoBackup_P.load_2_current4_tableData_f, 5U);

  /* Gain: '<S17>/current_2_voltage' */
  PMSM_DemoBackup_B.current_2_voltage_k =
    PMSM_DemoBackup_P.current_2_voltage_Gain_k *
    PMSM_DemoBackup_B.load_2_current4_j;

  /* Product: '<S20>/Divide' */
  PMSM_DemoBackup_B.Divide_b = PMSM_DemoBackup_B.current_2_voltage_k /
    PMSM_DemoBackup_B.Battery_VoltageV;

  /* Saturate: '<S20>/Saturation' */
  if (PMSM_DemoBackup_B.Divide_b > PMSM_DemoBackup_P.Saturation_UpperSat_l) {
    PMSM_DemoBackup_B.Saturation_l = PMSM_DemoBackup_P.Saturation_UpperSat_l;
  } else if (PMSM_DemoBackup_B.Divide_b <
             PMSM_DemoBackup_P.Saturation_LowerSat_n4) {
    PMSM_DemoBackup_B.Saturation_l = PMSM_DemoBackup_P.Saturation_LowerSat_n4;
  } else {
    PMSM_DemoBackup_B.Saturation_l = PMSM_DemoBackup_B.Divide_b;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/manual_Load_control'
   */
  if (PMSM_DemoBackup_P.manual_Load_control_Value >=
      PMSM_DemoBackup_P.Switch_Threshold_l) {
    PMSM_DemoBackup_B.Switch_iu = PMSM_DemoBackup_B.DataTypeConversion3;
  } else {
    PMSM_DemoBackup_B.Switch_iu = PMSM_DemoBackup_B.Saturation_l;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S8>/Load_enable'
   */
  PMSM_DemoBackup_B.Product1_n = PMSM_DemoBackup_B.Switch_iu *
    PMSM_DemoBackup_P.Load_enable_Value;

  /* S-Function (rti_commonblock): '<S15>/S-Function1' incorporates:
   *  Constant: '<S8>/BrakePeriod'
   */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Control/Control_load_machine/DIO_CLASS1_PWM_BL1 --- */
  /* --- [RTI120X, PWM OUT] - Port: 1 - Channel: 13 --- */

  /* write PWM Period and DutyCycle for output channel 13 on port 1 */
  DioCl1PwmOut_setPeriod(pRTIDioC1PwmOut_Port_1_Ch_13, (real_T)
    PMSM_DemoBackup_P.BrakePeriod_Value);
  DioCl1PwmOut_setDutyCycle(pRTIDioC1PwmOut_Port_1_Ch_13, (real_T)
    PMSM_DemoBackup_B.Product1_n);
  DioCl1PwmOut_write(pRTIDioC1PwmOut_Port_1_Ch_13);

  /* Saturate: '<S19>/Saturation1' */
  if (PMSM_DemoBackup_B.Product1_n > PMSM_DemoBackup_P.Saturation1_UpperSat_e) {
    PMSM_DemoBackup_B.Saturation1_b = PMSM_DemoBackup_P.Saturation1_UpperSat_e;
  } else if (PMSM_DemoBackup_B.Product1_n <
             PMSM_DemoBackup_P.Saturation1_LowerSat_l) {
    PMSM_DemoBackup_B.Saturation1_b = PMSM_DemoBackup_P.Saturation1_LowerSat_l;
  } else {
    PMSM_DemoBackup_B.Saturation1_b = PMSM_DemoBackup_B.Product1_n;
  }

  /* End of Saturate: '<S19>/Saturation1' */

  /* Product: '<S19>/Divide' */
  PMSM_DemoBackup_B.Divide_f = PMSM_DemoBackup_B.Saturation1_b *
    PMSM_DemoBackup_B.Battery_VoltageV;

  /* Product: '<S16>/Divide' incorporates:
   *  Constant: '<S16>/coil_resistance'
   */
  PMSM_DemoBackup_B.Divide_e = PMSM_DemoBackup_B.Divide_f /
    PMSM_DemoBackup_P.coil_resistance_Value;

  /* Lookup_n-D: '<S16>/current_2_load1' */
  PMSM_DemoBackup_B.current_2_load1 = look1_binlxpw(PMSM_DemoBackup_B.Divide_e,
    PMSM_DemoBackup_P.current_2_load1_bp01Data,
    PMSM_DemoBackup_P.current_2_load1_tableData, 5U);

  /* S-Function (rti_commonblock): '<S10>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S11>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* user code (Output function Trailer for TID2) */

  /* dSPACE Data Capture block: PMSM_DemoBackup/Control/Data Capture_short */
  /* ... Service number: 2 */
  /* ... Service name:   ASYNTask_short */
  {
    DsDaq_Service(0, 0, 2, (DsDaqSTimestampStruct *)
                  rtk_current_task_absolute_time_ptr_get());
  }

  /* dSPACE Data Capture block: PMSM_DemoBackup/Control/Data Capture */
  /* ... Service number: 1 */
  /* ... Service name:   ASYNTask */
  {
    DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                  rtk_current_task_absolute_time_ptr_get());
  }

  /* Update for UnitDelay: '<S47>/Unit Delay1' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE = PMSM_DemoBackup_P.T_PWM;

  /* Update for UnitDelay: '<S50>/Unit Delay2' incorporates:
   *  Constant: '<S29>/Constant1'
   */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE = PMSM_DemoBackup_P.Constant1_Value_e;

  /* Update for UnitDelay: '<S37>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE = PMSM_DemoBackup_B.uFilterTime;

  /* Update for UnitDelay: '<S47>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_f = PMSM_DemoBackup_B.Switch2_a;

  /* Update for UnitDelay: '<S61>/Unit Delay1' */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_f =
    PMSM_DemoBackup_B.TrigonometricFunction;

  /* Update for Memory: '<S25>/Memory' */
  PMSM_DemoBackup_DW.Memory_PreviousInput_m = PMSM_DemoBackup_B.MultiportSwitch;

  /* Update for Memory: '<S25>/Memory1' */
  PMSM_DemoBackup_DW.Memory1_PreviousInput = PMSM_DemoBackup_B.Memory_j;

  /* Update for Memory: '<S25>/Memory2' */
  PMSM_DemoBackup_DW.Memory2_PreviousInput = PMSM_DemoBackup_B.Memory1;

  /* Update for Memory: '<S25>/Memory3' */
  PMSM_DemoBackup_DW.Memory3_PreviousInput = PMSM_DemoBackup_B.Memory2;

  /* Update for UnitDelay: '<S33>/Output' */
  PMSM_DemoBackup_DW.Output_DSTATE = PMSM_DemoBackup_B.FixPtSwitch;

  /* Update for UnitDelay: '<S53>/Unit Delay1' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_p = PMSM_DemoBackup_P.T_PWM;

  /* Update for UnitDelay: '<S56>/Unit Delay2' incorporates:
   *  Constant: '<S29>/Constant3'
   */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_l = PMSM_DemoBackup_P.Constant3_Value_i;

  /* Update for UnitDelay: '<S38>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_k = PMSM_DemoBackup_B.uFilterTime_m;

  /* Update for UnitDelay: '<S53>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_h = PMSM_DemoBackup_B.Switch2_d;

  /* Update for UnitDelay: '<S61>/Unit Delay2' */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_o =
    PMSM_DemoBackup_B.TrigonometricFunction1;

  /* Update for UnitDelay: '<S128>/Unit Delay1' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_g = PMSM_DemoBackup_P.T_PWM;

  /* Update for UnitDelay: '<S131>/Unit Delay2' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_p = PMSM_DemoBackup_P.Constant1_Value_p;

  /* Update for UnitDelay: '<S110>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_n = PMSM_DemoBackup_B.uFilterTime_g;

  /* Update for UnitDelay: '<S128>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_hr = PMSM_DemoBackup_B.Switch2_p;

  /* Update for UnitDelay: '<S39>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_nm = PMSM_DemoBackup_B.Sum2_h;

  /* Update for UnitDelay: '<S40>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_j = PMSM_DemoBackup_B.Sum2_ll;

  /* Update for UnitDelay: '<S96>/Unit Delay1' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_c = PMSM_DemoBackup_P.T_PWM;

  /* Update for UnitDelay: '<S101>/Unit Delay2' incorporates:
   *  Constant: '<S92>/Reset[0|1]'
   */
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_ot = PMSM_DemoBackup_P.Reset01_Value;

  /* Update for UnitDelay: '<S96>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_hf = PMSM_DemoBackup_B.Switch2_p2;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_l = PMSM_DemoBackup_B.Saturation1_m;
}

/* Termination for function-call system: '<Root>/Control' */
void PMSM_DemoBackup_Control_Term(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S112>/S-Function1' */

  /* --- PMSM_DemoBackup/Control/Input/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 4 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl1EncoderIn_stop(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch4);
  }

  /* Terminate for S-Function (rti_commonblock): '<S134>/S-Function1' incorporates:
   *  Constant: '<S137>/T_Sample[s]'
   */

  /* --- PMSM_DemoBackup/Control/Output/EMC_MC_PWM_BL1 --- */
  /* --- [RTIEMC, MCPWM] - Port: 1 - Channel: 7 --- */
  {
    /* disable output channels 7-9 on port 1 (set to high-impedance), when the simulation terminates */
    DioCl1MultiPwmOut_setOutputHighZ(pRTIEmcMultiPwmOut_Port_1_Ch_7,
      DIO_CLASS1_HIGH_Z_ON);

    /* write data to related digital output channels */
    DioCl1MultiPwmOut_write(pRTIEmcMultiPwmOut_Port_1_Ch_7);
  }

  /* Terminate for S-Function (rti_commonblock): '<S15>/S-Function1' incorporates:
   *  Constant: '<S8>/BrakePeriod'
   */

  /* --- PMSM_DemoBackup/Control/Control_load_machine/DIO_CLASS1_PWM_BL1 --- */
  /* --- [RTI120X, PWM OUT] - Port: 1 - Channel: 13 --- */

  /* disable digital output channel 13 on port 1 *
   * (set to high-impedance), when the simulation terminates */
  DioCl1PwmOut_setOutputHighZ(pRTIDioC1PwmOut_Port_1_Ch_13, DIO_CLASS1_HIGH_Z_ON);
  DioCl1PwmOut_write(pRTIDioC1PwmOut_Port_1_Ch_13);
}

/* Model output function */
void PMSM_DemoBackup_output(void)
{
  int_T tid = 0;
  real_T temp;
  ZCEventType zcEvent;
  int32_T i;

  /* S-Function (rti_commonblock): '<S144>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* End of Outputs for S-Function (rti_commonblock): '<S144>/S-Function1' */

  /* Constant: '<S6>/Choose_reference_Value_iq' */
  PMSM_DemoBackup_B.Choose_ref_value_i =
    PMSM_DemoBackup_P.Choose_reference_Value_iq_Value;

  /* Constant: '<S6>/Choose_reference_Value_n' */
  PMSM_DemoBackup_B.Choose_ref_value_n =
    PMSM_DemoBackup_P.Choose_reference_Value_n_Value;

  /* SignalGenerator: '<S6>/Sig_gen_n' */
  temp = PMSM_DemoBackup_P.Sig_gen_n_Frequency * PMSM_DemoBackup_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    PMSM_DemoBackup_B.Sig_gen_n = PMSM_DemoBackup_P.Sig_gen_n_Amplitude;
  } else {
    PMSM_DemoBackup_B.Sig_gen_n = -PMSM_DemoBackup_P.Sig_gen_n_Amplitude;
  }

  /* End of SignalGenerator: '<S6>/Sig_gen_n' */

  /* Outputs for Atomic SubSystem: '<S6>/Enabled and Triggered Subsystem' */
  /* HitCross: '<S150>/Hit  Crossing' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &PMSM_DemoBackup_PrevZCX.HitCrossing_Input_ZCE,
                     (PMSM_DemoBackup_B.Sig_gen_n -
                      PMSM_DemoBackup_P.HitCrossing_Offset));
  if (PMSM_DemoBackup_DW.HitCrossing_MODE == 0) {
    if (zcEvent != NO_ZCEVENT) {
      PMSM_DemoBackup_B.HitCrossing = !PMSM_DemoBackup_B.HitCrossing;
      PMSM_DemoBackup_DW.HitCrossing_MODE = 1;
    } else {
      if (PMSM_DemoBackup_B.HitCrossing) {
        PMSM_DemoBackup_B.HitCrossing = ((!(PMSM_DemoBackup_B.Sig_gen_n !=
          PMSM_DemoBackup_P.HitCrossing_Offset)) &&
          PMSM_DemoBackup_B.HitCrossing);
      }
    }
  } else {
    PMSM_DemoBackup_B.HitCrossing = ((!(PMSM_DemoBackup_B.Sig_gen_n !=
      PMSM_DemoBackup_P.HitCrossing_Offset)) && PMSM_DemoBackup_B.HitCrossing);
    PMSM_DemoBackup_DW.HitCrossing_MODE = 0;
  }

  /* End of HitCross: '<S150>/Hit  Crossing' */

  /* Memory: '<S150>/Memory' */
  PMSM_DemoBackup_B.Memory = PMSM_DemoBackup_DW.Memory_PreviousInput;

  /* RelationalOperator: '<S150>/Relational Operator1' incorporates:
   *  Constant: '<S150>/switch_out_boarder'
   */
  PMSM_DemoBackup_B.RelationalOperator1 = (PMSM_DemoBackup_B.Sig_gen_n >=
    PMSM_DemoBackup_P.switch_out_boarder_Value);

  /* Sum: '<S150>/Sum' incorporates:
   *  Constant: '<S150>/Constant'
   */
  PMSM_DemoBackup_B.Sum = PMSM_DemoBackup_P.Constant_Value +
    PMSM_DemoBackup_B.Memory;

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Constant1'
   */
  if (PMSM_DemoBackup_B.HitCrossing) {
    PMSM_DemoBackup_B.Switch = PMSM_DemoBackup_P.Constant1_Value_n;
  } else {
    PMSM_DemoBackup_B.Switch = PMSM_DemoBackup_B.Sum;
  }

  /* End of Switch: '<S150>/Switch' */

  /* RelationalOperator: '<S150>/Relational Operator' incorporates:
   *  Constant: '<S150>/start_time_samples'
   */
  PMSM_DemoBackup_B.RelationalOperator = (PMSM_DemoBackup_B.Switch <=
    PMSM_DemoBackup_P.start_time_samples_Value);

  /* Switch: '<S150>/Switch1' incorporates:
   *  Constant: '<S150>/load_signal_0'
   *  Constant: '<S150>/load_signal_generator'
   */
  if (PMSM_DemoBackup_B.RelationalOperator) {
    PMSM_DemoBackup_B.Switch1 = PMSM_DemoBackup_P.load_signal_0_Value;
  } else {
    PMSM_DemoBackup_B.Switch1 = PMSM_DemoBackup_P.load_signal_generator_Value;
  }

  /* End of Switch: '<S150>/Switch1' */

  /* Product: '<S150>/Product' */
  PMSM_DemoBackup_B.Product = (real_T)PMSM_DemoBackup_B.RelationalOperator1 *
    PMSM_DemoBackup_B.Switch1;

  /* End of Outputs for SubSystem: '<S6>/Enabled and Triggered Subsystem' */

  /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
   *  Constant: '<S6>/Const_ref_n'
   */
  if ((int32_T)PMSM_DemoBackup_B.Choose_ref_value_n == 1) {
    PMSM_DemoBackup_B.ref_value_n = PMSM_DemoBackup_B.Sig_gen_n;
  } else {
    PMSM_DemoBackup_B.ref_value_n = PMSM_DemoBackup_P.Const_ref_n_Value;
  }

  /* End of MultiPortSwitch: '<S6>/Multiport Switch' */

  /* SignalGenerator: '<S6>/Sig_gen_iq' */
  temp = PMSM_DemoBackup_P.Sig_gen_iq_Frequency * PMSM_DemoBackup_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    PMSM_DemoBackup_B.Sig_gen_iq = PMSM_DemoBackup_P.Sig_gen_iq_Amplitude;
  } else {
    PMSM_DemoBackup_B.Sig_gen_iq = -PMSM_DemoBackup_P.Sig_gen_iq_Amplitude;
  }

  /* End of SignalGenerator: '<S6>/Sig_gen_iq' */

  /* Sin: '<S6>/Sine_wave_ref_iq' */
  PMSM_DemoBackup_B.Sine_wave_ref_iq = sin
    (PMSM_DemoBackup_P.Sine_wave_ref_iq_Freq * PMSM_DemoBackup_M->Timing.t[0] +
     PMSM_DemoBackup_P.Sine_wave_ref_iq_Phase) *
    PMSM_DemoBackup_P.Sine_wave_ref_iq_Amp +
    PMSM_DemoBackup_P.Sine_wave_ref_iq_Bias;

  /* MultiPortSwitch: '<S6>/Multiport Switch1' incorporates:
   *  Constant: '<S6>/Const_ref_iq'
   */
  switch ((int32_T)PMSM_DemoBackup_B.Choose_ref_value_i) {
   case 1:
    PMSM_DemoBackup_B.ref_value_iq = PMSM_DemoBackup_B.Sig_gen_iq;
    break;

   case 2:
    PMSM_DemoBackup_B.ref_value_iq = PMSM_DemoBackup_P.Const_ref_iq_Value;
    break;

   default:
    PMSM_DemoBackup_B.ref_value_iq = PMSM_DemoBackup_B.Sine_wave_ref_iq;
    break;
  }

  /* End of MultiPortSwitch: '<S6>/Multiport Switch1' */

  /* RateTransition generated from: '<S6>/Rate Transition' */
  switch (PMSM_DemoBackup_DW.RateTransition_1_read_buf) {
   case 0:
    PMSM_DemoBackup_DW.RateTransition_1_write_buf = 1;
    break;

   case 1:
    PMSM_DemoBackup_DW.RateTransition_1_write_buf = 0;
    break;

   default:
    PMSM_DemoBackup_DW.RateTransition_1_write_buf = (int8_T)
      (PMSM_DemoBackup_DW.RateTransition_1_last_buf_wr == 0);
    break;
  }

  if (PMSM_DemoBackup_DW.RateTransition_1_write_buf != 0) {
    PMSM_DemoBackup_DW.RateTransition_1_Buffer1 = PMSM_DemoBackup_B.Sig_gen_n;
  } else {
    PMSM_DemoBackup_DW.RateTransition_1_Buffer0 = PMSM_DemoBackup_B.Sig_gen_n;
  }

  PMSM_DemoBackup_DW.RateTransition_1_last_buf_wr =
    PMSM_DemoBackup_DW.RateTransition_1_write_buf;
  PMSM_DemoBackup_DW.RateTransition_1_write_buf = -1;

  /* RateTransition generated from: '<S6>/Rate Transition' */
  switch (PMSM_DemoBackup_DW.RateTransition_2_read_buf) {
   case 0:
    PMSM_DemoBackup_DW.RateTransition_2_write_buf = 1;
    break;

   case 1:
    PMSM_DemoBackup_DW.RateTransition_2_write_buf = 0;
    break;

   default:
    PMSM_DemoBackup_DW.RateTransition_2_write_buf = (int8_T)
      (PMSM_DemoBackup_DW.RateTransition_2_last_buf_wr == 0);
    break;
  }

  if (PMSM_DemoBackup_DW.RateTransition_2_write_buf != 0) {
    PMSM_DemoBackup_DW.RateTransition_2_Buffer1 =
      PMSM_DemoBackup_B.Choose_ref_value_n;
  } else {
    PMSM_DemoBackup_DW.RateTransition_2_Buffer0 =
      PMSM_DemoBackup_B.Choose_ref_value_n;
  }

  PMSM_DemoBackup_DW.RateTransition_2_last_buf_wr =
    PMSM_DemoBackup_DW.RateTransition_2_write_buf;
  PMSM_DemoBackup_DW.RateTransition_2_write_buf = -1;

  /* RateTransition generated from: '<S6>/Rate Transition' */
  switch (PMSM_DemoBackup_DW.RateTransition_3_read_buf) {
   case 0:
    PMSM_DemoBackup_DW.RateTransition_3_write_buf = 1;
    break;

   case 1:
    PMSM_DemoBackup_DW.RateTransition_3_write_buf = 0;
    break;

   default:
    PMSM_DemoBackup_DW.RateTransition_3_write_buf = (int8_T)
      (PMSM_DemoBackup_DW.RateTransition_3_last_buf_wr == 0);
    break;
  }

  if (PMSM_DemoBackup_DW.RateTransition_3_write_buf != 0) {
    PMSM_DemoBackup_DW.RateTransition_3_Buffer1 = PMSM_DemoBackup_B.ref_value_n;
  } else {
    PMSM_DemoBackup_DW.RateTransition_3_Buffer0 = PMSM_DemoBackup_B.ref_value_n;
  }

  PMSM_DemoBackup_DW.RateTransition_3_last_buf_wr =
    PMSM_DemoBackup_DW.RateTransition_3_write_buf;
  PMSM_DemoBackup_DW.RateTransition_3_write_buf = -1;

  /* RateTransition generated from: '<S6>/Rate Transition' */
  switch (PMSM_DemoBackup_DW.RateTransition_4_read_buf) {
   case 0:
    PMSM_DemoBackup_DW.RateTransition_4_write_buf = 1;
    break;

   case 1:
    PMSM_DemoBackup_DW.RateTransition_4_write_buf = 0;
    break;

   default:
    PMSM_DemoBackup_DW.RateTransition_4_write_buf = (int8_T)
      (PMSM_DemoBackup_DW.RateTransition_4_last_buf_wr == 0);
    break;
  }

  if (PMSM_DemoBackup_DW.RateTransition_4_write_buf != 0) {
    PMSM_DemoBackup_DW.RateTransition_4_Buffer1 = PMSM_DemoBackup_B.Product;
  } else {
    PMSM_DemoBackup_DW.RateTransition_4_Buffer0 = PMSM_DemoBackup_B.Product;
  }

  PMSM_DemoBackup_DW.RateTransition_4_last_buf_wr =
    PMSM_DemoBackup_DW.RateTransition_4_write_buf;
  PMSM_DemoBackup_DW.RateTransition_4_write_buf = -1;

  /* RateTransition generated from: '<S6>/Rate Transition' */
  switch (PMSM_DemoBackup_DW.RateTransition_5_read_buf) {
   case 0:
    PMSM_DemoBackup_DW.RateTransition_5_write_buf = 1;
    break;

   case 1:
    PMSM_DemoBackup_DW.RateTransition_5_write_buf = 0;
    break;

   default:
    PMSM_DemoBackup_DW.RateTransition_5_write_buf = (int8_T)
      (PMSM_DemoBackup_DW.RateTransition_5_last_buf_wr == 0);
    break;
  }

  if (PMSM_DemoBackup_DW.RateTransition_5_write_buf != 0) {
    PMSM_DemoBackup_DW.RateTransition_5_Buffer1 =
      PMSM_DemoBackup_B.Choose_ref_value_i;
  } else {
    PMSM_DemoBackup_DW.RateTransition_5_Buffer0 =
      PMSM_DemoBackup_B.Choose_ref_value_i;
  }

  PMSM_DemoBackup_DW.RateTransition_5_last_buf_wr =
    PMSM_DemoBackup_DW.RateTransition_5_write_buf;
  PMSM_DemoBackup_DW.RateTransition_5_write_buf = -1;

  /* RateTransition generated from: '<S6>/Rate Transition' */
  switch (PMSM_DemoBackup_DW.RateTransition_6_read_buf) {
   case 0:
    PMSM_DemoBackup_DW.RateTransition_6_write_buf = 1;
    break;

   case 1:
    PMSM_DemoBackup_DW.RateTransition_6_write_buf = 0;
    break;

   default:
    PMSM_DemoBackup_DW.RateTransition_6_write_buf = (int8_T)
      (PMSM_DemoBackup_DW.RateTransition_6_last_buf_wr == 0);
    break;
  }

  if (PMSM_DemoBackup_DW.RateTransition_6_write_buf != 0) {
    PMSM_DemoBackup_DW.RateTransition_6_Buffer1 = PMSM_DemoBackup_B.ref_value_iq;
  } else {
    PMSM_DemoBackup_DW.RateTransition_6_Buffer0 = PMSM_DemoBackup_B.ref_value_iq;
  }

  PMSM_DemoBackup_DW.RateTransition_6_last_buf_wr =
    PMSM_DemoBackup_DW.RateTransition_6_write_buf;
  PMSM_DemoBackup_DW.RateTransition_6_write_buf = -1;

  /* DigitalClock: '<S6>/Digital Clock' */
  PMSM_DemoBackup_B.sim_time = (((PMSM_DemoBackup_M->Timing.clockTick1+
    PMSM_DemoBackup_M->Timing.clockTickH1* 4294967296.0)) * 0.001);

  /* Gain: '<S6>/Gain' */
  PMSM_DemoBackup_B.Gain = PMSM_DemoBackup_P.Gain_Gain_jk *
    PMSM_DemoBackup_B.sim_time;

  /* Constant: '<S1>/clock' */
  for (i = 0; i < 6; i++) {
    PMSM_DemoBackup_B.clock[i] = PMSM_DemoBackup_P.clock_Value[i];
  }

  /* End of Constant: '<S1>/clock' */

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Constant: '<S4>/Enable'
   */
  PMSM_DemoBackup_B.DataTypeConversion_h = (PMSM_DemoBackup_P.Enable_Value !=
    0.0);

  /* S-Function (rti_commonblock): '<S145>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- PMSM_DemoBackup/Enable_Inverter/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 15 --- */
  {
    /* define variables required for BitOut realtime functions */
    UInt32 outputData = 0;

    /* write output state value to digital output channel 15-15 on port 1 */
    outputData = ( ( ( (UInt32)PMSM_DemoBackup_B.DataTypeConversion_h) << (15 -
      1)) | outputData);
    DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_15, outputData);
    DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_15);
  }

  /* S-Function (rti_commonblock): '<S146>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S7>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* user code (Output function Trailer for TID0) */

  /* dSPACE Data Capture block: PMSM_DemoBackup/TimerTask */
  /* ... Service number: 4 */
  /* ... Service name:   TimerTask_top */
  if (0 <= 1 && rtmIsMajorTimeStep(PMSM_DemoBackup_M)) {
    DsDaq_Service(0, 0, 4, (DsDaqSTimestampStruct *)
                  rtk_current_task_absolute_time_ptr_get());
  }

  /* dSPACE Data Capture block: PMSM_DemoBackup/Enable_Inverter/TimerTask */
  /* ... Service number: 3 */
  /* ... Service name:   TimerTask */
  if (0 <= 1 && rtmIsMajorTimeStep(PMSM_DemoBackup_M)) {
    DsDaq_Service(0, 0, 3, (DsDaqSTimestampStruct *)
                  rtk_current_task_absolute_time_ptr_get());
  }
}

/* Model update function */
void PMSM_DemoBackup_update(void)
{
  /* Update for Atomic SubSystem: '<S6>/Enabled and Triggered Subsystem' */
  /* Update for Memory: '<S150>/Memory' */
  PMSM_DemoBackup_DW.Memory_PreviousInput = PMSM_DemoBackup_B.Switch;

  /* End of Update for SubSystem: '<S6>/Enabled and Triggered Subsystem' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PMSM_DemoBackup_M->Timing.clockTick0)) {
    ++PMSM_DemoBackup_M->Timing.clockTickH0;
  }

  PMSM_DemoBackup_M->Timing.t[0] = PMSM_DemoBackup_M->Timing.clockTick0 *
    PMSM_DemoBackup_M->Timing.stepSize0 + PMSM_DemoBackup_M->Timing.clockTickH0 *
    PMSM_DemoBackup_M->Timing.stepSize0 * 4294967296.0;

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
    PMSM_DemoBackup_M->Timing.clockTick1++;
    if (!PMSM_DemoBackup_M->Timing.clockTick1) {
      PMSM_DemoBackup_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void PMSM_DemoBackup_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PMSM_DemoBackup_M, 0,
                sizeof(RT_MODEL_PMSM_DemoBackup_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PMSM_DemoBackup_M->solverInfo,
                          &PMSM_DemoBackup_M->Timing.simTimeStep);
    rtsiSetTPtr(&PMSM_DemoBackup_M->solverInfo, &rtmGetTPtr(PMSM_DemoBackup_M));
    rtsiSetStepSizePtr(&PMSM_DemoBackup_M->solverInfo,
                       &PMSM_DemoBackup_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&PMSM_DemoBackup_M->solverInfo, (&rtmGetErrorStatus
      (PMSM_DemoBackup_M)));
    rtsiSetRTModelPtr(&PMSM_DemoBackup_M->solverInfo, PMSM_DemoBackup_M);
  }

  rtsiSetSimTimeStep(&PMSM_DemoBackup_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&PMSM_DemoBackup_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(PMSM_DemoBackup_M, &PMSM_DemoBackup_M->Timing.tArray[0]);
  PMSM_DemoBackup_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &PMSM_DemoBackup_B), 0,
                sizeof(B_PMSM_DemoBackup_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      PMSM_DemoBackup_B.clock[i] = 0.0;
    }

    PMSM_DemoBackup_B.Choose_ref_value_i = 0.0;
    PMSM_DemoBackup_B.Choose_ref_value_n = 0.0;
    PMSM_DemoBackup_B.Sig_gen_n = 0.0;
    PMSM_DemoBackup_B.ref_value_n = 0.0;
    PMSM_DemoBackup_B.Sig_gen_iq = 0.0;
    PMSM_DemoBackup_B.Sine_wave_ref_iq = 0.0;
    PMSM_DemoBackup_B.ref_value_iq = 0.0;
    PMSM_DemoBackup_B.sim_time = 0.0;
    PMSM_DemoBackup_B.Gain = 0.0;
    PMSM_DemoBackup_B.Sig_gen_n_i = 0.0;
    PMSM_DemoBackup_B.Choose_ref_value_n_g = 0.0;
    PMSM_DemoBackup_B.ref_value_n_o = 0.0;
    PMSM_DemoBackup_B.load_machine_ref = 0.0;
    PMSM_DemoBackup_B.Choose_ref_value_i_m = 0.0;
    PMSM_DemoBackup_B.ref_value_iq_i = 0.0;
    PMSM_DemoBackup_B.Memory = 0.0;
    PMSM_DemoBackup_B.Sum = 0.0;
    PMSM_DemoBackup_B.Switch = 0.0;
    PMSM_DemoBackup_B.Switch1 = 0.0;
    PMSM_DemoBackup_B.Product = 0.0;
    PMSM_DemoBackup_B.DataTypeConversion = 0.0;
    PMSM_DemoBackup_B.Product_k = 0.0;
    PMSM_DemoBackup_B.Product1 = 0.0;
    PMSM_DemoBackup_B.Product2 = 0.0;
    PMSM_DemoBackup_B.Sum_f = 0.0;
    PMSM_DemoBackup_B.Saturation = 0.0;
    PMSM_DemoBackup_B.Sum1 = 0.0;
    PMSM_DemoBackup_B.Saturation1 = 0.0;
    PMSM_DemoBackup_B.Sum2 = 0.0;
    PMSM_DemoBackup_B.Saturation2 = 0.0;
    PMSM_DemoBackup_B.Ki_iq = 0.0;
    PMSM_DemoBackup_B.Kp_iq = 0.0;
    PMSM_DemoBackup_B.Vel_Src = 0.0;
    PMSM_DemoBackup_B.load_torque = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1 = 0.0;
    PMSM_DemoBackup_B.VoltageADC1V = 0.0;
    PMSM_DemoBackup_B.voltamp_i_a = 0.0;
    PMSM_DemoBackup_B.currentPhaseAA = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_i = 0.0;
    PMSM_DemoBackup_B.VoltageADC5V = 0.0;
    PMSM_DemoBackup_B.voltamp_i_b = 0.0;
    PMSM_DemoBackup_B.currentPhaseBA = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_g = 0.0;
    PMSM_DemoBackup_B.VoltageADC7V = 0.0;
    PMSM_DemoBackup_B.voltamp_i_c = 0.0;
    PMSM_DemoBackup_B.currentPhaseCA = 0.0;
    PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[0] = 0.0;
    PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[1] = 0.0;
    PMSM_DemoBackup_B.TmpSignalConversionAtGain1Inpor[2] = 0.0;
    PMSM_DemoBackup_B.Gain1[0] = 0.0;
    PMSM_DemoBackup_B.Gain1[1] = 0.0;
    PMSM_DemoBackup_B.Gain5[0] = 0.0;
    PMSM_DemoBackup_B.Gain5[1] = 0.0;
    PMSM_DemoBackup_B.UnitDelay1 = 0.0;
    PMSM_DemoBackup_B.UnitDelay2 = 0.0;
    PMSM_DemoBackup_B.Switch1_o = 0.0;
    PMSM_DemoBackup_B.UnitDelay = 0.0;
    PMSM_DemoBackup_B.Gain1_m[0] = 0.0;
    PMSM_DemoBackup_B.Gain1_m[1] = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_f = 0.0;
    PMSM_DemoBackup_B.SFunction1_o2 = 0.0;
    PMSM_DemoBackup_B.SFunction1_o3 = 0.0;
    PMSM_DemoBackup_B.Gain3 = 0.0;
    PMSM_DemoBackup_B.Sum_k = 0.0;
    PMSM_DemoBackup_B.Inc_elec_pos = 0.0;
    PMSM_DemoBackup_B.inc_valid = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_d = 0.0;
    PMSM_DemoBackup_B.Switch_n = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_k = 0.0;
    PMSM_DemoBackup_B.SFunction1_o2_f = 0.0;
    PMSM_DemoBackup_B.Switch_e = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch1 = 0.0;
    PMSM_DemoBackup_B.to_rad = 0.0;
    PMSM_DemoBackup_B.Sum_e = 0.0;
    PMSM_DemoBackup_B.MathFunction1 = 0.0;
    PMSM_DemoBackup_B.cos_m = 0.0;
    PMSM_DemoBackup_B.Product1_d = 0.0;
    PMSM_DemoBackup_B.sin_c = 0.0;
    PMSM_DemoBackup_B.Product2_n = 0.0;
    PMSM_DemoBackup_B.Sum1_j = 0.0;
    PMSM_DemoBackup_B.Proportional = 0.0;
    PMSM_DemoBackup_B.Sum_j = 0.0;
    PMSM_DemoBackup_B.Product_i = 0.0;
    PMSM_DemoBackup_B.UnitDelay_m = 0.0;
    PMSM_DemoBackup_B.Switch2 = 0.0;
    PMSM_DemoBackup_B.Add = 0.0;
    PMSM_DemoBackup_B.Switch_d = 0.0;
    PMSM_DemoBackup_B.Switch2_a = 0.0;
    PMSM_DemoBackup_B.uFilterTime = 0.0;
    PMSM_DemoBackup_B.UnitDelay1_h = 0.0;
    PMSM_DemoBackup_B.apu_vel = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch = 0.0;
    PMSM_DemoBackup_B.Memory_j = 0.0;
    PMSM_DemoBackup_B.Memory1 = 0.0;
    PMSM_DemoBackup_B.Memory2 = 0.0;
    PMSM_DemoBackup_B.Memory3 = 0.0;
    PMSM_DemoBackup_B.Sum_p = 0.0;
    PMSM_DemoBackup_B.Gain_p = 0.0;
    PMSM_DemoBackup_B.Kp_n_Cor = 0.0;
    PMSM_DemoBackup_B.Ki_n_Cor = 0.0;
    PMSM_DemoBackup_B.Gain3_p = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch_e[0] = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch_e[1] = 0.0;
    PMSM_DemoBackup_B.inv = 0.0;
    PMSM_DemoBackup_B.Switch_a = 0.0;
    PMSM_DemoBackup_B.Switch2_j = 0.0;
    PMSM_DemoBackup_B.factor_id = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch_b = 0.0;
    PMSM_DemoBackup_B.Gain3_e[0] = 0.0;
    PMSM_DemoBackup_B.Gain3_e[1] = 0.0;
    PMSM_DemoBackup_B.UnitDelay1_n = 0.0;
    PMSM_DemoBackup_B.UnitDelay2_k = 0.0;
    PMSM_DemoBackup_B.Switch1_j = 0.0;
    PMSM_DemoBackup_B.UnitDelay_f = 0.0;
    PMSM_DemoBackup_B.inv_k = 0.0;
    PMSM_DemoBackup_B.Product3 = 0.0;
    PMSM_DemoBackup_B.Product4 = 0.0;
    PMSM_DemoBackup_B.Sum_i = 0.0;
    PMSM_DemoBackup_B.Proportional_g = 0.0;
    PMSM_DemoBackup_B.Sum_pj = 0.0;
    PMSM_DemoBackup_B.Product_m = 0.0;
    PMSM_DemoBackup_B.UnitDelay_o = 0.0;
    PMSM_DemoBackup_B.Switch2_e = 0.0;
    PMSM_DemoBackup_B.Add_g = 0.0;
    PMSM_DemoBackup_B.Switch_m = 0.0;
    PMSM_DemoBackup_B.Switch2_d = 0.0;
    PMSM_DemoBackup_B.uFilterTime_m = 0.0;
    PMSM_DemoBackup_B.Gain1_h = 0.0;
    PMSM_DemoBackup_B.UnitDelay2_g = 0.0;
    PMSM_DemoBackup_B.inv_h = 0.0;
    PMSM_DemoBackup_B.Switch_i = 0.0;
    PMSM_DemoBackup_B.Switch2_b = 0.0;
    PMSM_DemoBackup_B.factor_id_e = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch_a = 0.0;
    PMSM_DemoBackup_B.Gain3_a = 0.0;
    PMSM_DemoBackup_B.Gain4[0] = 0.0;
    PMSM_DemoBackup_B.Gain4[1] = 0.0;
    PMSM_DemoBackup_B.UnitDelay1_m = 0.0;
    PMSM_DemoBackup_B.UnitDelay2_m = 0.0;
    PMSM_DemoBackup_B.Switch1_f = 0.0;
    PMSM_DemoBackup_B.UnitDelay_fg = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_j = 0.0;
    PMSM_DemoBackup_B.VoltageADC3V = 0.0;
    PMSM_DemoBackup_B.Battery_VoltageV = 0.0;
    PMSM_DemoBackup_B.Proportional_j = 0.0;
    PMSM_DemoBackup_B.Sum_g = 0.0;
    PMSM_DemoBackup_B.Product_e = 0.0;
    PMSM_DemoBackup_B.UnitDelay_d = 0.0;
    PMSM_DemoBackup_B.Switch2_m = 0.0;
    PMSM_DemoBackup_B.Add_b = 0.0;
    PMSM_DemoBackup_B.Switch_g = 0.0;
    PMSM_DemoBackup_B.Switch2_p = 0.0;
    PMSM_DemoBackup_B.uFilterTime_g = 0.0;
    PMSM_DemoBackup_B.MinMax = 0.0;
    PMSM_DemoBackup_B.LimitingFactor = 0.0;
    PMSM_DemoBackup_B.Kp_i_Cor = 0.0;
    PMSM_DemoBackup_B.error = 0.0;
    PMSM_DemoBackup_B.Product1_b = 0.0;
    PMSM_DemoBackup_B.Ki_i_Cor = 0.0;
    PMSM_DemoBackup_B.Product2_k = 0.0;
    PMSM_DemoBackup_B.integral = 0.0;
    PMSM_DemoBackup_B.UnitDelay_i = 0.0;
    PMSM_DemoBackup_B.Sum_jb = 0.0;
    PMSM_DemoBackup_B.Product2_g = 0.0;
    PMSM_DemoBackup_B.toRads = 0.0;
    PMSM_DemoBackup_B.Product_eb = 0.0;
    PMSM_DemoBackup_B.Const_LsdH = 0.0;
    PMSM_DemoBackup_B.Sum3 = 0.0;
    PMSM_DemoBackup_B.inv_ho = 0.0;
    PMSM_DemoBackup_B.Switch_dr = 0.0;
    PMSM_DemoBackup_B.Switch2_a3 = 0.0;
    PMSM_DemoBackup_B.MathFunction1_n = 0.0;
    PMSM_DemoBackup_B.MathFunction = 0.0;
    PMSM_DemoBackup_B.Add_a = 0.0;
    PMSM_DemoBackup_B.MathFunction2 = 0.0;
    PMSM_DemoBackup_B.error_a = 0.0;
    PMSM_DemoBackup_B.Product1_c = 0.0;
    PMSM_DemoBackup_B.Product2_b = 0.0;
    PMSM_DemoBackup_B.integral_p = 0.0;
    PMSM_DemoBackup_B.UnitDelay_l = 0.0;
    PMSM_DemoBackup_B.Sum_a = 0.0;
    PMSM_DemoBackup_B.Product1_p = 0.0;
    PMSM_DemoBackup_B.Const_LsqH = 0.0;
    PMSM_DemoBackup_B.Sum1_f = 0.0;
    PMSM_DemoBackup_B.Const_PsiWb = 0.0;
    PMSM_DemoBackup_B.Sum4 = 0.0;
    PMSM_DemoBackup_B.inv_e = 0.0;
    PMSM_DemoBackup_B.Switch_ii = 0.0;
    PMSM_DemoBackup_B.Switch2_n = 0.0;
    PMSM_DemoBackup_B.UnitDelay1_f = 0.0;
    PMSM_DemoBackup_B.UnitDelay2_p = 0.0;
    PMSM_DemoBackup_B.Switch1_d = 0.0;
    PMSM_DemoBackup_B.torpm = 0.0;
    PMSM_DemoBackup_B.Gain_l = 0.0;
    PMSM_DemoBackup_B.Product_kx = 0.0;
    PMSM_DemoBackup_B.UnitDelay_j = 0.0;
    PMSM_DemoBackup_B.Switch2_f = 0.0;
    PMSM_DemoBackup_B.Add_ag = 0.0;
    PMSM_DemoBackup_B.Switch_l = 0.0;
    PMSM_DemoBackup_B.Switch2_p2 = 0.0;
    PMSM_DemoBackup_B.MathFunction1_i = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch_h[0] = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch_h[1] = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch_h[2] = 0.0;
    PMSM_DemoBackup_B.cos_i = 0.0;
    PMSM_DemoBackup_B.Product1_g = 0.0;
    PMSM_DemoBackup_B.sin_k = 0.0;
    PMSM_DemoBackup_B.inv_p = 0.0;
    PMSM_DemoBackup_B.Product2_m = 0.0;
    PMSM_DemoBackup_B.Sum1_e = 0.0;
    PMSM_DemoBackup_B.Gain1_k = 0.0;
    PMSM_DemoBackup_B.Gain2 = 0.0;
    PMSM_DemoBackup_B.Product3_l = 0.0;
    PMSM_DemoBackup_B.Product4_m = 0.0;
    PMSM_DemoBackup_B.Sum_m = 0.0;
    PMSM_DemoBackup_B.Gain3_k = 0.0;
    PMSM_DemoBackup_B.Sum_n = 0.0;
    PMSM_DemoBackup_B.Sum1_i = 0.0;
    PMSM_DemoBackup_B.Product_ko[0] = 0.0;
    PMSM_DemoBackup_B.Product_ko[1] = 0.0;
    PMSM_DemoBackup_B.Product_ko[2] = 0.0;
    PMSM_DemoBackup_B.Min = 0.0;
    PMSM_DemoBackup_B.Max = 0.0;
    PMSM_DemoBackup_B.Sum_mb = 0.0;
    PMSM_DemoBackup_B.Sum4_k = 0.0;
    PMSM_DemoBackup_B.half = 0.0;
    PMSM_DemoBackup_B.Sum2_l[0] = 0.0;
    PMSM_DemoBackup_B.Sum2_l[1] = 0.0;
    PMSM_DemoBackup_B.Sum2_l[2] = 0.0;
    PMSM_DemoBackup_B.Saturation_m[0] = 0.0;
    PMSM_DemoBackup_B.Saturation_m[1] = 0.0;
    PMSM_DemoBackup_B.Saturation_m[2] = 0.0;
    PMSM_DemoBackup_B.Gain6[0] = 0.0;
    PMSM_DemoBackup_B.Gain6[1] = 0.0;
    PMSM_DemoBackup_B.Gain6[2] = 0.0;
    PMSM_DemoBackup_B.Sum3_i[0] = 0.0;
    PMSM_DemoBackup_B.Sum3_i[1] = 0.0;
    PMSM_DemoBackup_B.Sum3_i[2] = 0.0;
    PMSM_DemoBackup_B.Gain7[0] = 0.0;
    PMSM_DemoBackup_B.Gain7[1] = 0.0;
    PMSM_DemoBackup_B.Gain7[2] = 0.0;
    PMSM_DemoBackup_B.Gain16 = 0.0;
    PMSM_DemoBackup_B.Gain17 = 0.0;
    PMSM_DemoBackup_B.Gain10[0] = 0.0;
    PMSM_DemoBackup_B.Gain10[1] = 0.0;
    PMSM_DemoBackup_B.Gain8[0] = 0.0;
    PMSM_DemoBackup_B.Gain8[1] = 0.0;
    PMSM_DemoBackup_B.Gain8[2] = 0.0;
    PMSM_DemoBackup_B.Product_ew = 0.0;
    PMSM_DemoBackup_B.Const_LsdH_e = 0.0;
    PMSM_DemoBackup_B.Sum3_b = 0.0;
    PMSM_DemoBackup_B.Gain1_c[0] = 0.0;
    PMSM_DemoBackup_B.Gain1_c[1] = 0.0;
    PMSM_DemoBackup_B.Gain1_c[2] = 0.0;
    PMSM_DemoBackup_B.Product1_k = 0.0;
    PMSM_DemoBackup_B.Const_LsqH_a = 0.0;
    PMSM_DemoBackup_B.Sum1_fm = 0.0;
    PMSM_DemoBackup_B.Const_PsiWb_k = 0.0;
    PMSM_DemoBackup_B.Sum4_c = 0.0;
    PMSM_DemoBackup_B.Gain2_l[0] = 0.0;
    PMSM_DemoBackup_B.Gain2_l[1] = 0.0;
    PMSM_DemoBackup_B.Gain2_l[2] = 0.0;
    PMSM_DemoBackup_B.Plotter_trigger_var = 0.0;
    PMSM_DemoBackup_B.Gain15 = 0.0;
    PMSM_DemoBackup_B.Gain9[0] = 0.0;
    PMSM_DemoBackup_B.Gain9[1] = 0.0;
    PMSM_DemoBackup_B.Gain9[2] = 0.0;
    PMSM_DemoBackup_B.Switch_nv[0] = 0.0;
    PMSM_DemoBackup_B.Switch_nv[1] = 0.0;
    PMSM_DemoBackup_B.Switch_nv[2] = 0.0;
    PMSM_DemoBackup_B.Product1_dq = 0.0;
    PMSM_DemoBackup_B.Sum2_h = 0.0;
    PMSM_DemoBackup_B.Sum2_ll = 0.0;
    PMSM_DemoBackup_B.MathFunction3 = 0.0;
    PMSM_DemoBackup_B.MathFunction4 = 0.0;
    PMSM_DemoBackup_B.Add1 = 0.0;
    PMSM_DemoBackup_B.MathFunction5 = 0.0;
    PMSM_DemoBackup_B.Gain_j = 0.0;
    PMSM_DemoBackup_B.Add2 = 0.0;
    PMSM_DemoBackup_B.Saturation_a = 0.0;
    PMSM_DemoBackup_B.UnitDelay_b = 0.0;
    PMSM_DemoBackup_B.Sum_c = 0.0;
    PMSM_DemoBackup_B.Saturation1_m = 0.0;
    PMSM_DemoBackup_B.Gain_a = 0.0;
    PMSM_DemoBackup_B.Sum_o = 0.0;
    PMSM_DemoBackup_B.MultiportSwitch_g = 0.0;
    PMSM_DemoBackup_B.TrigonometricFunction = 0.0;
    PMSM_DemoBackup_B.TrigonometricFunction1 = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_p = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_h = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_gf = 0.0;
    PMSM_DemoBackup_B.SFunction1_o1_o = 0.0;
    PMSM_DemoBackup_B.VoltageADC6V = 0.0;
    PMSM_DemoBackup_B.PhaseB_VoltageV = 0.0;
    PMSM_DemoBackup_B.VoltageADC8V = 0.0;
    PMSM_DemoBackup_B.PhaseC_VoltageV = 0.0;
    PMSM_DemoBackup_B.VoltageADC4V = 0.0;
    PMSM_DemoBackup_B.not_used = 0.0;
    PMSM_DemoBackup_B.VoltageADC2V = 0.0;
    PMSM_DemoBackup_B.PhaseA_VoltageV = 0.0;
    PMSM_DemoBackup_B.Gain_e = 0.0;
    PMSM_DemoBackup_B.Gain1_a = 0.0;
    PMSM_DemoBackup_B.Gain2_lh = 0.0;
    PMSM_DemoBackup_B.Gain3_j = 0.0;
    PMSM_DemoBackup_B.Gain4_a = 0.0;
    PMSM_DemoBackup_B.Gain5_o = 0.0;
    PMSM_DemoBackup_B.Gain6_m = 0.0;
    PMSM_DemoBackup_B.Gain7_k = 0.0;
    PMSM_DemoBackup_B.hall_A = 0.0;
    PMSM_DemoBackup_B.hall_B = 0.0;
    PMSM_DemoBackup_B.hall_C = 0.0;
    PMSM_DemoBackup_B.Load_gain = 0.0;
    PMSM_DemoBackup_B.load_2_current4 = 0.0;
    PMSM_DemoBackup_B.current_2_voltage = 0.0;
    PMSM_DemoBackup_B.Divide = 0.0;
    PMSM_DemoBackup_B.Saturation_f = 0.0;
    PMSM_DemoBackup_B.DataTypeConversion3 = 0.0;
    PMSM_DemoBackup_B.load_2_current4_j = 0.0;
    PMSM_DemoBackup_B.current_2_voltage_k = 0.0;
    PMSM_DemoBackup_B.Divide_b = 0.0;
    PMSM_DemoBackup_B.Saturation_l = 0.0;
    PMSM_DemoBackup_B.Switch_iu = 0.0;
    PMSM_DemoBackup_B.Product1_n = 0.0;
    PMSM_DemoBackup_B.Saturation1_b = 0.0;
    PMSM_DemoBackup_B.Divide_f = 0.0;
    PMSM_DemoBackup_B.Divide_e = 0.0;
    PMSM_DemoBackup_B.current_2_load1 = 0.0;
    PMSM_DemoBackup_B.n_Limitrpm = 0.0;
    PMSM_DemoBackup_B.UnitDelay1_hl = 0.0;
    PMSM_DemoBackup_B.UnitDelay2_py = 0.0;
    PMSM_DemoBackup_B.Switch1_m = 0.0;
    PMSM_DemoBackup_B.UnitDelay_o3 = 0.0;
    PMSM_DemoBackup_B.Gain1_j = 0.0;
    PMSM_DemoBackup_B.Proportional_b = 0.0;
    PMSM_DemoBackup_B.Sum_l = 0.0;
    PMSM_DemoBackup_B.Product_ml = 0.0;
    PMSM_DemoBackup_B.UnitDelay_il = 0.0;
    PMSM_DemoBackup_B.Switch2_b4 = 0.0;
    PMSM_DemoBackup_B.Add_c = 0.0;
    PMSM_DemoBackup_B.Switch_j = 0.0;
    PMSM_DemoBackup_B.Switch2_o = 0.0;
    PMSM_DemoBackup_B.uFilterTime_o = 0.0;
    PMSM_DemoBackup_B.UnitDelay1_p = 0.0;
    PMSM_DemoBackup_B.UnitDelay2_j = 0.0;
    PMSM_DemoBackup_B.Switch1_k = 0.0;
    PMSM_DemoBackup_B.UnitDelay_e = 0.0;
    PMSM_DemoBackup_B.Proportional_k = 0.0;
    PMSM_DemoBackup_B.Sum_ke = 0.0;
    PMSM_DemoBackup_B.Product_l = 0.0;
    PMSM_DemoBackup_B.UnitDelay_c = 0.0;
    PMSM_DemoBackup_B.Switch2_h = 0.0;
    PMSM_DemoBackup_B.Add_l = 0.0;
    PMSM_DemoBackup_B.Switch_gh = 0.0;
    PMSM_DemoBackup_B.Switch2_l = 0.0;
    PMSM_DemoBackup_B.uFilterTime_i = 0.0;
    PMSM_DemoBackup_B.Gain_g = 0.0;
    PMSM_DemoBackup_B.Switch_l1 = 0.0;
    PMSM_DemoBackup_B.inv_pp = 0.0;
    PMSM_DemoBackup_B.Switch_nt = 0.0;
    PMSM_DemoBackup_B.Switch2_dh = 0.0;
    PMSM_DemoBackup_B.Gain2_g = 0.0;
    PMSM_DemoBackup_B.Gain3_l = 0.0;
    PMSM_DemoBackup_B.error_f = 0.0;
    PMSM_DemoBackup_B.Product2_e = 0.0;
    PMSM_DemoBackup_B.integral_g = 0.0;
    PMSM_DemoBackup_B.Product1_o = 0.0;
    PMSM_DemoBackup_B.UnitDelay_jj = 0.0;
    PMSM_DemoBackup_B.Sum_of = 0.0;
    PMSM_DemoBackup_B.Switch_k = 0.0;
    PMSM_DemoBackup_B.Switch2_hf = 0.0;
    PMSM_DemoBackup_B.Sum2_d = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&PMSM_DemoBackup_DW, 0,
                sizeof(DW_PMSM_DemoBackup_T));
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE = 0.0;
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_f = 0.0;
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_f = 0.0;
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_p = 0.0;
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_l = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_k = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_h = 0.0;
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_o = 0.0;
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_g = 0.0;
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_p = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_n = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_hr = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_nm = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_j = 0.0;
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_c = 0.0;
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_ot = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_hf = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_l = 0.0;
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_m = 0.0;
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_f = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_i = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_c = 0.0;
  PMSM_DemoBackup_DW.UnitDelay1_DSTATE_pt = 0.0;
  PMSM_DemoBackup_DW.UnitDelay2_DSTATE_i = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_io = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_cf = 0.0;
  PMSM_DemoBackup_DW.UnitDelay_DSTATE_o = 0.0;
  PMSM_DemoBackup_DW.RateTransition_1_Buffer0 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_1_Buffer1 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_2_Buffer0 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_2_Buffer1 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_3_Buffer0 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_3_Buffer1 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_4_Buffer0 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_4_Buffer1 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_5_Buffer0 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_5_Buffer1 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_6_Buffer0 = 0.0;
  PMSM_DemoBackup_DW.RateTransition_6_Buffer1 = 0.0;
  PMSM_DemoBackup_DW.Memory_PreviousInput = 0.0;
  PMSM_DemoBackup_DW.Memory_PreviousInput_m = 0.0;
  PMSM_DemoBackup_DW.Memory1_PreviousInput = 0.0;
  PMSM_DemoBackup_DW.Memory2_PreviousInput = 0.0;
  PMSM_DemoBackup_DW.Memory3_PreviousInput = 0.0;

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    PMSM_DemoBackup_rti_init_trc_pointers();
  }

  PMSM_DemoBackup_PrevZCX.speed_controller_Trig_ZCE = POS_ZCSIG;
  PMSM_DemoBackup_PrevZCX.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for RateTransition generated from: '<S6>/Rate Transition' */
  PMSM_DemoBackup_DW.RateTransition_1_Buffer0 =
    PMSM_DemoBackup_P.RateTransition_1_InitialConditi;
  PMSM_DemoBackup_DW.RateTransition_1_write_buf = -1;
  PMSM_DemoBackup_DW.RateTransition_1_read_buf = -1;

  /* InitializeConditions for RateTransition generated from: '<S6>/Rate Transition' */
  PMSM_DemoBackup_DW.RateTransition_2_Buffer0 =
    PMSM_DemoBackup_P.RateTransition_2_InitialConditi;
  PMSM_DemoBackup_DW.RateTransition_2_write_buf = -1;
  PMSM_DemoBackup_DW.RateTransition_2_read_buf = -1;

  /* InitializeConditions for RateTransition generated from: '<S6>/Rate Transition' */
  PMSM_DemoBackup_DW.RateTransition_3_Buffer0 =
    PMSM_DemoBackup_P.RateTransition_3_InitialConditi;
  PMSM_DemoBackup_DW.RateTransition_3_write_buf = -1;
  PMSM_DemoBackup_DW.RateTransition_3_read_buf = -1;

  /* InitializeConditions for RateTransition generated from: '<S6>/Rate Transition' */
  PMSM_DemoBackup_DW.RateTransition_4_Buffer0 =
    PMSM_DemoBackup_P.RateTransition_4_InitialConditi;
  PMSM_DemoBackup_DW.RateTransition_4_write_buf = -1;
  PMSM_DemoBackup_DW.RateTransition_4_read_buf = -1;

  /* InitializeConditions for RateTransition generated from: '<S6>/Rate Transition' */
  PMSM_DemoBackup_DW.RateTransition_5_Buffer0 =
    PMSM_DemoBackup_P.RateTransition_5_InitialConditi;
  PMSM_DemoBackup_DW.RateTransition_5_write_buf = -1;
  PMSM_DemoBackup_DW.RateTransition_5_read_buf = -1;

  /* InitializeConditions for RateTransition generated from: '<S6>/Rate Transition' */
  PMSM_DemoBackup_DW.RateTransition_6_Buffer0 =
    PMSM_DemoBackup_P.RateTransition_6_InitialConditi;
  PMSM_DemoBackup_DW.RateTransition_6_write_buf = -1;
  PMSM_DemoBackup_DW.RateTransition_6_read_buf = -1;

  /* SystemInitialize for S-Function (rti_commonblock): '<S144>/S-Function1' incorporates:
   *  SubSystem: '<Root>/Control'
   */
  PMSM_DemoBackup_Control_Init();

  /* End of SystemInitialize for S-Function (rti_commonblock): '<S144>/S-Function1' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/Enabled and Triggered Subsystem' */
  /* InitializeConditions for Memory: '<S150>/Memory' */
  PMSM_DemoBackup_DW.Memory_PreviousInput =
    PMSM_DemoBackup_P.Memory_InitialCondition_p;

  /* End of SystemInitialize for SubSystem: '<S6>/Enabled and Triggered Subsystem' */
}

/* Model terminate function */
void PMSM_DemoBackup_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S144>/S-Function1' incorporates:
   *  SubSystem: '<Root>/Control'
   */
  PMSM_DemoBackup_Control_Term();

  /* End of Terminate for S-Function (rti_commonblock): '<S144>/S-Function1' */

  /* Terminate for S-Function (rti_commonblock): '<S145>/S-Function1' */

  /* --- PMSM_DemoBackup/Enable_Inverter/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 15 --- */

  /* disable digital output channel 15-15 on port 1 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_15,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_15);
}
