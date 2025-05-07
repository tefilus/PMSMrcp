/*
 * PMSM_DemoBackup_data.c
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

#include "PMSM_DemoBackup.h"
#include "PMSM_DemoBackup_private.h"

/* Block parameters (default storage) */
P_PMSM_DemoBackup_T PMSM_DemoBackup_P = {
  /* Variable: Const_Id_Fieldweakening
   * Referenced by: '<S30>/Const_Id_Fieldweakening[A]'
   */
  0.0,

  /* Variable: Const_Ld_Stator
   * Referenced by:
   *   '<S64>/Const_Lsd[H]'
   *   '<S65>/Const_Lsd[H]'
   */
  0.0004,

  /* Variable: Const_Lq_Stator
   * Referenced by:
   *   '<S64>/Const_Lsq[H]'
   *   '<S65>/Const_Lsq[H]'
   */
  0.0004,

  /* Variable: Const_PolePairs
   * Referenced by: '<S28>/Const_PolePair[]'
   */
  4.0,

  /* Variable: Const_Psi
   * Referenced by:
   *   '<S64>/Const_Psi[Wb]'
   *   '<S65>/Const_Psi[Wb]'
   */
  0.017,

  /* Variable: PMSM_Ctrl_Ctrl_mode_SW
   * Referenced by: '<S137>/Ctrl_mode_SW[1 n_ctrl | 2 i_ctrl | 3 v_ctrl]'
   */
  3.0,

  /* Variable: PMSM_Ctrl_Ki_id
   * Referenced by: '<S137>/Ki_id'
   */
  3595.0202934767408,

  /* Variable: PMSM_Ctrl_Ki_iq
   * Referenced by: '<S137>/Ki_iq'
   */
  3595.0202934767408,

  /* Variable: PMSM_Ctrl_Ki_n
   * Referenced by: '<S137>/Ki_n'
   */
  50.086111832693042,

  /* Variable: PMSM_Ctrl_Kp_id
   * Referenced by: '<S137>/Kp_id'
   */
  1.5499570539574477,

  /* Variable: PMSM_Ctrl_Kp_iq
   * Referenced by: '<S137>/Kp_iq'
   */
  1.5499570539574477,

  /* Variable: PMSM_Ctrl_Kp_n
   * Referenced by: '<S137>/Kp_n'
   */
  0.0775235575931134,

  /* Variable: PMSM_Ctrl_Limit_iq
   * Referenced by: '<S137>/Limit_iq'
   */
  10.6,

  /* Variable: PMSM_Ctrl_Pos_Src
   * Referenced by: '<S137>/Pos_Src'
   */
  1.0,

  /* Variable: PMSM_Ctrl_TF_Id
   * Referenced by: '<S137>/TF_Id[s]'
   */
  7.9577471545947675E-5,

  /* Variable: PMSM_Ctrl_TF_Iq
   * Referenced by: '<S137>/TF_Iq[s]'
   */
  7.9577471545947675E-5,

  /* Variable: PMSM_Ctrl_TF_n
   * Referenced by: '<S137>/TF_n[s]'
   */
  0.001061032953945969,

  /* Variable: PMSM_Ctrl_V_DCLink_Limit
   * Referenced by: '<S137>/V_DCLink_Limit[V]'
   */
  15.0,

  /* Variable: PMSM_Ctrl_Vel_Src
   * Referenced by: '<S137>/Vel_Src'
   */
  4.0,

  /* Variable: PMSM_Ctrl_fRS_Set
   * Referenced by: '<S137>/fRS_Set[Hz]'
   */
  0.0,

  /* Variable: PMSM_Ctrl_i_d_Set
   * Referenced by: '<S137>/i_d_Set[A]'
   */
  0.0,

  /* Variable: PMSM_Ctrl_i_d_Stroke
   * Referenced by: '<S137>/i_d_Stroke[A]'
   */
  0.0,

  /* Variable: PMSM_Ctrl_i_q_Set
   * Referenced by: '<S137>/i_q_Set[A]'
   */
  0.0,

  /* Variable: PMSM_Ctrl_i_q_Stroke
   * Referenced by: '<S137>/i_q_Stroke[A]'
   */
  0.0,

  /* Variable: PMSM_Ctrl_load_torque
   * Referenced by: '<S137>/load_torque'
   */
  0.0,

  /* Variable: PMSM_Ctrl_n_Limit
   * Referenced by: '<S137>/n_Limit [rpm]'
   */
  3000.0,

  /* Variable: PMSM_Ctrl_n_Set
   * Referenced by: '<S137>/n_Set[rpm]'
   */
  0.0,

  /* Variable: PMSM_Ctrl_n_Stroke
   * Referenced by: '<S137>/n_Stroke[rpm]'
   */
  0.0,

  /* Variable: PMSM_Ctrl_theta_offset
   * Referenced by: '<S137>/Theta_offset[rad]'
   */
  0.5,

  /* Variable: PMSM_Ctrl_v_d_Set
   * Referenced by: '<S137>/v_d_Set[V]'
   */
  0.0,

  /* Variable: PMSM_Ctrl_v_q_Set
   * Referenced by: '<S137>/v_q_Set[V]'
   */
  0.0,

  /* Variable: SW_Fieldweakening
   * Referenced by: '<S61>/SW_Fieldweakening[1|2]'
   */
  2.0,

  /* Variable: T_PWM
   * Referenced by: '<S137>/T_Sample[s]'
   */
  5.0E-5,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S79>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S82>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S83>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_j
   * Referenced by: '<S85>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const_m
   * Referenced by: '<S88>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant2_const_d
   * Referenced by: '<S89>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_i
   * Referenced by: '<S48>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const_d
   * Referenced by: '<S51>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant2_const_a
   * Referenced by: '<S52>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_a
   * Referenced by: '<S54>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const_i
   * Referenced by: '<S57>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant2_const_az
   * Referenced by: '<S58>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_h
   * Referenced by: '<S129>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const_l
   * Referenced by: '<S132>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant2_const_j
   * Referenced by: '<S133>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_m
   * Referenced by: '<S99>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const_o
   * Referenced by: '<S102>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant2_const_i
   * Referenced by: '<S103>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_hp
   * Referenced by: '<S138>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const_a
   * Referenced by: '<S139>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant2_const_k
   * Referenced by: '<S140>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S141>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S142>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant5_const
   * Referenced by: '<S143>/Constant'
   */
  2.0,

  /* Mask Parameter: DISCRETE_INTEGRATOR_lower_limit
   * Referenced by: '<S96>/lower_limit'
   */
  {
    -1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT1_lower_limit_int
   * Referenced by: '<S78>/lower_limit'
   */
  {
    -1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT1_SET_lower_limit_in
   * Referenced by: '<S84>/lower_limit'
   */
  {
    -1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT1_lower_limit_int_i
   * Referenced by: '<S47>/lower_limit'
   */
  {
    -1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT2_lower_limit_int
   * Referenced by: '<S53>/lower_limit'
   */
  {
    -1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT1_lower_limit_int_a
   * Referenced by: '<S128>/lower_limit'
   */
  {
    -1.0e+300
  },

  /* Mask Parameter: DISCRETE_INTEGRATOR_upper_limit
   * Referenced by: '<S96>/upper_limit'
   */
  {
    1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT1_upper_limit_int
   * Referenced by: '<S78>/upper_limit'
   */
  {
    1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT1_SET_upper_limit_in
   * Referenced by: '<S84>/upper_limit'
   */
  {
    1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT1_upper_limit_int_i
   * Referenced by: '<S47>/upper_limit'
   */
  {
    1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT2_upper_limit_int
   * Referenced by: '<S53>/upper_limit'
   */
  {
    1.0e+300
  },

  /* Mask Parameter: DISCRETE_PT1_upper_limit_int_l
   * Referenced by: '<S128>/upper_limit'
   */
  {
    1.0e+300
  },

  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S35>/FixPt Switch'
   */
  4U,

  /* Expression: 0
   * Referenced by: '<S31>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S31>/Constant2'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S31>/Constant3'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<S31>/Constant4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S31>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S73>/zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S78>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S81>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S78>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S73>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S31>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S78>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S78>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S74>/zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S84>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S87>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S84>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S74>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S84>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S84>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S31>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S31>/switch_filter'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S31>/Switch'
   */
  0.5,

  /* Expression: -1
   * Referenced by: '<S75>/inv'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S31>/Gain2'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S31>/Gain3'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S76>/Unit Delay'
   */
  0.0,

  /* Expression: 1200
   * Referenced by: '<S137>/Saturation'
   */
  1200.0,

  /* Expression: -1200
   * Referenced by: '<S137>/Saturation'
   */
  -1200.0,

  /* Expression: 6
   * Referenced by: '<S137>/Saturation1'
   */
  6.0,

  /* Expression: -6
   * Referenced by: '<S137>/Saturation1'
   */
  -6.0,

  /* Expression: 6
   * Referenced by: '<S137>/Saturation2'
   */
  6.0,

  /* Expression: -6
   * Referenced by: '<S137>/Saturation2'
   */
  -6.0,

  /* Expression: 10
   * Referenced by: '<S109>/Gain13'
   */
  10.0,

  /* Expression: -12
   * Referenced by: '<S109>/volt->amp_i_a           '
   */
  -12.0,

  /* Expression: -0.14
   * Referenced by: '<S109>/ i_a_offset'
   */
  -0.14,

  /* Expression: 10
   * Referenced by: '<S109>/Gain17'
   */
  10.0,

  /* Expression: -12
   * Referenced by: '<S109>/volt->amp_i_b'
   */
  -12.0,

  /* Expression: -0.12
   * Referenced by: '<S109>/ i_b_offset  '
   */
  -0.12,

  /* Expression: 10
   * Referenced by: '<S109>/Gain18'
   */
  10.0,

  /* Expression: -12
   * Referenced by: '<S109>/volt->amp_i_c'
   */
  -12.0,

  /* Expression: -0.13
   * Referenced by: '<S109>/i_c_offset'
   */
  -0.13,

  /* Expression: [[2/3 -1/3 -1/3]*1;[0 sqrt(3)/3 -sqrt(3)/3]*1]
   * Referenced by: '<S60>/Gain1'
   */
  { 0.66666666666666663, 0.0, -0.33333333333333331, 0.57735026918962573,
    -0.33333333333333331, -0.57735026918962573 },

  /* Expression: 1
   * Referenced by: '<S135>/Gain5'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S37>/zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S47>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S50>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S47>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S37>/Unit Delay'
   */
  0.0,

  /* Expression: [[2/3 -1/3 -1/3]*transffactor;[0 sqrt(3)/3 -sqrt(3)/3]*transffactor]
   * Referenced by: '<S59>/Gain1'
   */
  { 0.66666666666666663, 0.0, -0.33333333333333331, 0.57735026918962573,
    -0.33333333333333331, -0.57735026918962573 },

  /* Expression: 0
   * Referenced by: '<S12>/AngleOffset'
   */
  0.0,

  /* Expression: 4
   * Referenced by: '<S119>/Gain3'
   */
  4.0,

  /* Expression: 360
   * Referenced by: '<S119>/Constant4'
   */
  360.0,

  /* Expression: 0.5
   * Referenced by: '<S117>/Switch'
   */
  0.5,

  /* Expression: pi/180
   * Referenced by: '<S12>/to_rad'
   */
  0.017453292519943295,

  /* Expression: 2*pi
   * Referenced by: '<S36>/Constant2'
   */
  6.2831853071795862,

  /* Expression: 1
   * Referenced by: '<S29>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S47>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S47>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S61>/Unit Delay1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S12>/UseIncSpeed'
   */
  1.0,

  /* Expression: 1/4
   * Referenced by: '<S12>/Gain'
   */
  0.25,

  /* Expression: 0
   * Referenced by: '<S25>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S25>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S25>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S25>/Memory3'
   */
  0.0,

  /* Expression: 1/5
   * Referenced by: '<S25>/Gain'
   */
  0.2,

  /* Expression: 1
   * Referenced by: '<S9>/Kp_n_Cor'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S9>/Ki_n_Cor'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S30>/Gain3'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S30>/zero'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S69>/inv'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S38>/zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S53>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S56>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S53>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S38>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S59>/inv'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S29>/Constant4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S53>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S53>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S29>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S61>/Unit Delay2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S70>/inv'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S29>/Gain3'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S110>/zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S128>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S131>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S128>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S110>/Unit Delay'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S109>/Gain15'
   */
  10.0,

  /* Expression: 6
   * Referenced by: '<S109>/Gain9'
   */
  6.0,

  /* Expression: 1
   * Referenced by: '<S12>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S128>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S128>/Unit Delay'
   */
  0.0,

  /* Expression: 0.100
   * Referenced by: '<S12>/Constant3'
   */
  0.1,

  /* Expression: 1/sqrt(3)
   * Referenced by: '<S44>/LimitingFactor'
   */
  0.57735026918962584,

  /* Expression: 1
   * Referenced by: '<S9>/Kp_i_Cor'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S9>/Ki_i_Cor'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S39>/Unit Delay'
   */
  0.0,

  /* Expression: pi/30
   * Referenced by: '<S28>/toRad|s'
   */
  0.10471975511965977,

  /* Expression: -1
   * Referenced by: '<S62>/inv'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S40>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S63>/inv'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S92>/zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S96>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S101>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S92>/Reset[0|1]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S96>/Constant1'
   */
  0.0,

  /* Expression: 60
   * Referenced by: '<S92>/torpm'
   */
  60.0,

  /* Expression: Gain
   * Referenced by: '<S98>/Gain'
   */
  0.10471975511965977,

  /* Expression: 0
   * Referenced by: '<S96>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S96>/Unit Delay'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S97>/Constant2'
   */
  6.2831853071795862,

  /* Expression: -1
   * Referenced by: '<S104>/inv'
   */
  -1.0,

  /* Expression: 1/transffactor
   * Referenced by: '<S105>/Gain1'
   */
  1.0,

  /* Expression: -1/2/transffactor
   * Referenced by: '<S105>/Gain2'
   */
  -0.5,

  /* Expression: sqrt(3)/2/transffactor
   * Referenced by: '<S105>/Gain3'
   */
  0.8660254037844386,

  /* Expression: 1
   * Referenced by: '<S23>/one'
   */
  1.0,

  /* Expression: 1/2
   * Referenced by: '<S23>/half'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S23>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S23>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain6'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain7'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain16'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain17'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain10'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain8'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain2'
   */
  1.0,

  /* Expression: 1.5
   * Referenced by: '<S135>/Switch'
   */
  1.5,

  /* Expression: 1
   * Referenced by: '<S135>/Gain15'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S135>/Gain9'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S13>/UseController'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S13>/Duty_A'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Duty_B'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Duty_C'
   */
  0.0,

  /* Expression: 0.92
   * Referenced by: '<S61>/Gain'
   */
  0.92,

  /* Expression: 0
   * Referenced by: '<S61>/Zero'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S61>/Saturation'
   */
  0.2,

  /* Expression: -0.2
   * Referenced by: '<S61>/Saturation'
   */
  -0.2,

  /* Expression: 0
   * Referenced by: '<S61>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S61>/Saturation1'
   */
  0.0,

  /* Expression: -50
   * Referenced by: '<S61>/Saturation1'
   */
  -50.0,

  /* Expression: Gain
   * Referenced by: '<S66>/Gain'
   */
  0.017453292519943295,

  /* Expression: Offset
   * Referenced by: '<S66>/Offset'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S109>/Gain20'
   */
  10.0,

  /* Expression: 6
   * Referenced by: '<S109>/Gain10'
   */
  6.0,

  /* Expression: 10
   * Referenced by: '<S109>/Gain21'
   */
  10.0,

  /* Expression: 6
   * Referenced by: '<S109>/Gain11'
   */
  6.0,

  /* Expression: 10
   * Referenced by: '<S109>/Gain16'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<S109>/Gain12'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S109>/Gain14'
   */
  10.0,

  /* Expression: 6
   * Referenced by: '<S109>/Gain8'
   */
  6.0,

  /* Expression: 1
   * Referenced by: '<S109>/Gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S109>/Gain1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S109>/Gain2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S109>/Gain3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S109>/Gain4'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S109>/Gain5'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S109>/Gain6'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S109>/Gain7'
   */
  1.0,

  /* Expression: 50e-6
   * Referenced by: '<S8>/BrakePeriod'
   */
  5.0E-5,

  /* Expression: 0.4
   * Referenced by: '<S8>/Load_gain'
   */
  0.4,

  /* Expression: [0, 0.05, 0.1, 0.2, 0.3, 0.4]
   * Referenced by: '<S18>/load_2_current4'
   */
  { 0.0, 0.05, 0.1, 0.2, 0.3, 0.4 },

  /* Expression: [0, 0.05, 0.2, 0.7, 1.4, 1.9]
   * Referenced by: '<S18>/load_2_current4'
   */
  { 0.0, 0.05, 0.2, 0.7, 1.4, 1.9 },

  /* Expression: 24
   * Referenced by: '<S18>/current_2_voltage'
   */
  24.0,

  /* Expression: 1
   * Referenced by: '<S21>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S21>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/manual_Load_control'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/load_value_man[Nm]'
   */
  0.0,

  /* Expression: [0, 0.05, 0.1, 0.2, 0.3, 0.4]
   * Referenced by: '<S17>/load_2_current4'
   */
  { 0.0, 0.05, 0.1, 0.2, 0.3, 0.4 },

  /* Expression: [0, 0.05, 0.2, 0.7, 1.4, 1.9]
   * Referenced by: '<S17>/load_2_current4'
   */
  { 0.0, 0.05, 0.2, 0.7, 1.4, 1.9 },

  /* Expression: 24
   * Referenced by: '<S17>/current_2_voltage'
   */
  24.0,

  /* Expression: 1
   * Referenced by: '<S20>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S20>/Saturation'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S8>/Switch'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S8>/Load_enable'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S19>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S19>/Saturation1'
   */
  0.0,

  /* Expression: 24
   * Referenced by: '<S16>/coil_resistance'
   */
  24.0,

  /* Expression: [0, 0.05, 0.2, 0.7, 1.4, 1.9]
   * Referenced by: '<S16>/current_2_load1'
   */
  { 0.0, 0.05, 0.2, 0.7, 1.4, 1.9 },

  /* Expression: [0, 0.05, 0.1, 0.2, 0.3, 0.4]
   * Referenced by: '<S16>/current_2_load1'
   */
  { 0.0, 0.05, 0.1, 0.2, 0.3, 0.4 },

  /* Expression: 1
   * Referenced by: '<S150>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S150>/Constant1'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S150>/Hit  Crossing'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S150>/Memory'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S150>/switch_out_boarder'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S150>/load_signal_0'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S150>/start_time_samples'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<S150>/load_signal_generator'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S6>/Choose_reference_Value_iq'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S6>/Choose_reference_Value_n'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S6>/Const_ref_iq'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Const_ref_n'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Sig_gen_n'
   */
  1.0,

  /* Expression: 0.2
   * Referenced by: '<S6>/Sig_gen_n'
   */
  0.2,

  /* Expression: 1
   * Referenced by: '<S6>/Sig_gen_iq'
   */
  1.0,

  /* Expression: 0.2
   * Referenced by: '<S6>/Sig_gen_iq'
   */
  0.2,

  /* Expression: 1
   * Referenced by: '<S6>/Sine_wave_ref_iq'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Sine_wave_ref_iq'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Sine_wave_ref_iq'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Sine_wave_ref_iq'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Gain'
   */
  1.0,

  /* Expression: clock()
   * Referenced by: '<S1>/clock'
   */
  { 2024.0, 5.0, 7.0, 13.0, 37.0, 13.623 },

  /* Expression: 1
   * Referenced by: '<S4>/Enable'
   */
  1.0,

  /* Computed Parameter: Switch_Threshold_j
   * Referenced by: '<S116>/Switch'
   */
  2U,

  /* Computed Parameter: Gain22_Gain
   * Referenced by: '<S109>/Gain22'
   */
  16384,

  /* Computed Parameter: Gain23_Gain
   * Referenced by: '<S109>/Gain23'
   */
  16384,

  /* Computed Parameter: Gain24_Gain
   * Referenced by: '<S109>/Gain24'
   */
  16384,

  /* Computed Parameter: Gain25_Gain
   * Referenced by: '<S109>/Gain25'
   */
  16384,

  /* Computed Parameter: Gain26_Gain
   * Referenced by: '<S109>/Gain26'
   */
  16384,

  /* Computed Parameter: Gain27_Gain
   * Referenced by: '<S109>/Gain27'
   */
  16384,

  /* Computed Parameter: Gain28_Gain
   * Referenced by: '<S109>/Gain28'
   */
  16384,

  /* Computed Parameter: Gain29_Gain
   * Referenced by: '<S109>/Gain29'
   */
  16384,

  /* Computed Parameter: Gain11_Gain_f
   * Referenced by: '<S135>/Gain11'
   */
  128U,

  /* Computed Parameter: Gain12_Gain_o
   * Referenced by: '<S135>/Gain12'
   */
  128U,

  /* Computed Parameter: Gain13_Gain_g
   * Referenced by: '<S135>/Gain13'
   */
  128U,

  /* Computed Parameter: Gain14_Gain_i
   * Referenced by: '<S135>/Gain14'
   */
  128U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S33>/Output'
   */
  0U,

  /* Computed Parameter: LookupTable_tableData
   * Referenced by: '<S27>/Lookup Table'
   */
  { 1U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: LookupTable_bp01Data
   * Referenced by: '<S27>/Lookup Table'
   */
  { 0U, 1U, 2U, 3U, 4U },

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S34>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S35>/Constant'
   */
  0U
};
