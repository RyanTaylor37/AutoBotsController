//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: carsimplesimulink.h
//
// Code generated for Simulink model 'carsimplesimulink'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov  6 22:39:17 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_carsimplesimulink_h_
#define RTW_HEADER_carsimplesimulink_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "carsimplesimulink_types.h"
#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_carsimplesimulink_T {
  real_T Saturation;                   // '<Root>/Saturation'
  real_T TransferFcn;                  // '<Root>/Transfer Fcn'
  SL_Bus_carsimplesimulink_std_msgs_Float64 In1;// '<S6>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_carsimplesimulink_T {
  ros_slros_internal_block_GetP_T obj; // '<Root>/Get Parameter1'
  ros_slros_internal_block_GetP_T obj_k;// '<Root>/Get Parameter'
  ros_slroscpp_internal_block_P_T obj_l;// '<S4>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_j;// '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_e;// '<S5>/SourceBlock'
  int_T Integrator_IWORK;              // '<Root>/Integrator'
  int_T Integrator1_IWORK;             // '<Root>/Integrator1'
};

// Continuous states (default storage)
struct X_carsimplesimulink_T {
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
  real_T Integrator1_CSTATE;           // '<Root>/Integrator1'
  real_T TransferFcn_CSTATE;           // '<Root>/Transfer Fcn'
};

// State derivatives (default storage)
struct XDot_carsimplesimulink_T {
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
  real_T Integrator1_CSTATE;           // '<Root>/Integrator1'
  real_T TransferFcn_CSTATE;           // '<Root>/Transfer Fcn'
};

// State disabled
struct XDis_carsimplesimulink_T {
  boolean_T Integrator_CSTATE;         // '<Root>/Integrator'
  boolean_T Integrator1_CSTATE;        // '<Root>/Integrator1'
  boolean_T TransferFcn_CSTATE;        // '<Root>/Transfer Fcn'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_carsimplesimulink_T_ {
  SL_Bus_carsimplesimulink_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S1>/Constant'

  SL_Bus_carsimplesimulink_std_msgs_Float64 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                //  Referenced by: '<S2>/Constant'

  SL_Bus_carsimplesimulink_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S6>/Out1'

  SL_Bus_carsimplesimulink_std_msgs_Float64 Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                //  Referenced by: '<S5>/Constant'

  real_T Saturation_UpperSat;          // Expression: 40
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<Root>/Saturation'

  real_T TransferFcn_A;                // Computed Parameter: TransferFcn_A
                                          //  Referenced by: '<Root>/Transfer Fcn'

  real_T TransferFcn_C;                // Computed Parameter: TransferFcn_C
                                          //  Referenced by: '<Root>/Transfer Fcn'

};

// Real-time Model Data Structure
struct tag_RTM_carsimplesimulink_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_carsimplesimulink_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_carsimplesimulink_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_carsimplesimulink_T carsimplesimulink_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_carsimplesimulink_T carsimplesimulink_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_carsimplesimulink_T carsimplesimulink_X;

// Block states (default storage)
extern struct DW_carsimplesimulink_T carsimplesimulink_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void carsimplesimulink_initialize(void);
  extern void carsimplesimulink_step(void);
  extern void carsimplesimulink_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_carsimplesimulink_T *const carsimplesimulink_M;

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
//  '<Root>' : 'carsimplesimulink'
//  '<S1>'   : 'carsimplesimulink/Blank Message'
//  '<S2>'   : 'carsimplesimulink/Blank Message1'
//  '<S3>'   : 'carsimplesimulink/Publish'
//  '<S4>'   : 'carsimplesimulink/Publish1'
//  '<S5>'   : 'carsimplesimulink/Subscribe'
//  '<S6>'   : 'carsimplesimulink/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_carsimplesimulink_h_

//
// File trailer for generated code.
//
// [EOF]
//
