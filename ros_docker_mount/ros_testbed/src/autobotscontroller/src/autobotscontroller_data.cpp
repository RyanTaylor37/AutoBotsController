//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: autobotscontroller_data.cpp
//
// Code generated for Simulink model 'autobotscontroller'.
//
// Model version                  : 1.12
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov 30 11:27:39 2023
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
  //  Referenced by: '<S91>/Derivative Gain'

  0.0,

  // Mask Parameter: Car_Follower_PID_D
  //  Referenced by: '<S40>/Derivative Gain'

  18.9516332486037,

  // Mask Parameter: Car_Hunter_PID_I
  //  Referenced by: '<S94>/Integral Gain'

  0.0,

  // Mask Parameter: Car_Follower_PID_I
  //  Referenced by: '<S43>/Integral Gain'

  1.1236136490315,

  // Mask Parameter: Car_Hunter_PID_InitialCondition
  //  Referenced by: '<S92>/Filter'

  0.0,

  // Mask Parameter: Car_Follower_PID_InitialConditi
  //  Referenced by: '<S41>/Filter'

  0.0,

  // Mask Parameter: Car_Hunter_PID_InitialConditi_c
  //  Referenced by: '<S97>/Integrator'

  0.0,

  // Mask Parameter: Car_Follower_PID_InitialCondi_d
  //  Referenced by: '<S46>/Integrator'

  0.0,

  // Mask Parameter: Car_Hunter_PID_LowerSaturationL
  //  Referenced by:
  //    '<S104>/Saturation'
  //    '<S90>/DeadZone'

  -3.0,

  // Mask Parameter: Car_Follower_PID_LowerSaturatio
  //  Referenced by:
  //    '<S53>/Saturation'
  //    '<S39>/DeadZone'

  -3.0,

  // Mask Parameter: Car_Hunter_PID_N
  //  Referenced by: '<S100>/Filter Coefficient'

  100.0,

  // Mask Parameter: Car_Follower_PID_N
  //  Referenced by: '<S49>/Filter Coefficient'

  10.8821013151988,

  // Mask Parameter: Car_Hunter_PID_P
  //  Referenced by: '<S102>/Proportional Gain'

  0.025,

  // Mask Parameter: Car_Follower_PID_P
  //  Referenced by: '<S51>/Proportional Gain'

  10.2457458282461,

  // Mask Parameter: Car_Hunter_PID_UpperSaturationL
  //  Referenced by:
  //    '<S104>/Saturation'
  //    '<S90>/DeadZone'

  1.5,

  // Mask Parameter: Car_Follower_PID_UpperSaturatio
  //  Referenced by:
  //    '<S53>/Saturation'
  //    '<S39>/DeadZone'

  1.5,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S2>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S114>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S4>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S115>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S5>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 0
  //  Referenced by: '<S9>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S88>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S88>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S37>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S37>/ZeroGain'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S7>/Constant'

  0.1,

  // Expression: 80
  //  Referenced by: '<Root>/Speed Limit'

  80.0,

  // Expression: 3
  //  Referenced by: '<Root>/Time Gap'

  3.0,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S88>/Memory'

  false,

  // Computed Parameter: Memory_InitialCondition_d
  //  Referenced by: '<S37>/Memory'

  false
};

//
// File trailer for generated code.
//
// [EOF]
//
