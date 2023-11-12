//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: subtractor.h
//
// Code generated for Simulink model 'subtractor'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov  6 21:59:00 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_subtractor_h_
#define RTW_HEADER_subtractor_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "subtractor_types.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_subtractor_T {
  SL_Bus_subtractor_std_msgs_Float64 In1;// '<S6>/In1'
  SL_Bus_subtractor_std_msgs_Float64 In1_m;// '<S5>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_subtractor_T {
  ros_slroscpp_internal_block_P_T obj; // '<S2>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_c;// '<S4>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S3>/SourceBlock'
};

// Parameters (default storage)
struct P_subtractor_T_ {
  SL_Bus_subtractor_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                       //  Referenced by: '<S1>/Constant'

  SL_Bus_subtractor_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                //  Referenced by: '<S5>/Out1'

  SL_Bus_subtractor_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                         //  Referenced by: '<S3>/Constant'

  SL_Bus_subtractor_std_msgs_Float64 Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                  //  Referenced by: '<S6>/Out1'

  SL_Bus_subtractor_std_msgs_Float64 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                         //  Referenced by: '<S4>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_subtractor_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_subtractor_T subtractor_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_subtractor_T subtractor_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_subtractor_T subtractor_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void subtractor_initialize(void);
  extern void subtractor_step(void);
  extern void subtractor_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_subtractor_T *const subtractor_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'subtractor'
//  '<S1>'   : 'subtractor/Blank Message'
//  '<S2>'   : 'subtractor/Publish'
//  '<S3>'   : 'subtractor/Subscribe'
//  '<S4>'   : 'subtractor/Subscribe1'
//  '<S5>'   : 'subtractor/Subscribe/Enabled Subsystem'
//  '<S6>'   : 'subtractor/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_subtractor_h_

//
// File trailer for generated code.
//
// [EOF]
//
