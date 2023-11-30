//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: autobotscontroller_data.cpp
//
// Code generated for Simulink model 'autobotscontroller'.
//
// Model version                  : 1.10
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov 30 09:53:06 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "autobotscontroller.h"

// Block parameters (default storage)
P_autobotscontroller_T autobotscontroller_P = {
  // Mask Parameter: Car_Hunter_PID_D
  //  Referenced by: '<S93>/Derivative Gain'

  0.0,

  // Mask Parameter: Car_Follower_PID_D
  //  Referenced by: '<S42>/Derivative Gain'

  18.9516332486037,

  // Mask Parameter: Car_Hunter_PID_I
  //  Referenced by: '<S96>/Integral Gain'

  0.0,

  // Mask Parameter: Car_Follower_PID_I
  //  Referenced by: '<S45>/Integral Gain'

  1.1236136490315,

  // Mask Parameter: Car_Hunter_PID_InitialCondition
  //  Referenced by: '<S94>/Filter'

  0.0,

  // Mask Parameter: Car_Follower_PID_InitialConditi
  //  Referenced by: '<S43>/Filter'

  0.0,

  // Mask Parameter: Car_Hunter_PID_InitialConditi_c
  //  Referenced by: '<S99>/Integrator'

  0.0,

  // Mask Parameter: Car_Follower_PID_InitialCondi_d
  //  Referenced by: '<S48>/Integrator'

  0.0,

  // Mask Parameter: Car_Hunter_PID_LowerSaturationL
  //  Referenced by:
  //    '<S106>/Saturation'
  //    '<S92>/DeadZone'

  -3.0,

  // Mask Parameter: Car_Follower_PID_LowerSaturatio
  //  Referenced by:
  //    '<S55>/Saturation'
  //    '<S41>/DeadZone'

  -3.0,

  // Mask Parameter: Car_Hunter_PID_N
  //  Referenced by: '<S102>/Filter Coefficient'

  100.0,

  // Mask Parameter: Car_Follower_PID_N
  //  Referenced by: '<S51>/Filter Coefficient'

  10.8821013151988,

  // Mask Parameter: Car_Hunter_PID_P
  //  Referenced by: '<S104>/Proportional Gain'

  0.025,

  // Mask Parameter: Car_Follower_PID_P
  //  Referenced by: '<S53>/Proportional Gain'

  10.2457458282461,

  // Mask Parameter: Car_Hunter_PID_UpperSaturationL
  //  Referenced by:
  //    '<S106>/Saturation'
  //    '<S92>/DeadZone'

  1.5,

  // Mask Parameter: Car_Follower_PID_UpperSaturatio
  //  Referenced by:
  //    '<S55>/Saturation'
  //    '<S41>/DeadZone'

  1.5,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S2>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S116>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S4>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S117>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S5>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_dp
  //  Referenced by: '<S118>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_gg
  //  Referenced by: '<S6>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S119>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S7>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 0
  //  Referenced by: '<S11>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S90>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S90>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S39>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S39>/ZeroGain'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S9>/Constant'

  0.1,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S90>/Memory'

  false,

  // Computed Parameter: Memory_InitialCondition_d
  //  Referenced by: '<S39>/Memory'

  false
};

//
// File trailer for generated code.
//
// [EOF]
//
