//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: autobotscontroller.h
//
// Code generated for Simulink model 'autobotscontroller'.
//
// Model version                  : 1.10
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov 30 00:03:15 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_autobotscontroller_h_
#define RTW_HEADER_autobotscontroller_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "autobotscontroller_types.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

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

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

// Block signals (default storage)
struct B_autobotscontroller_T {
  real_T error;                        // '<S1>/Subtract'
  real_T FilterCoefficient;            // '<S51>/Filter Coefficient'
  real_T Switch;                       // '<S39>/Switch'
  real_T FilterCoefficient_b;          // '<S102>/Filter Coefficient'
  real_T Switch_k;                     // '<S90>/Switch'
  SL_Bus_autobotscontroller_std_msgs_Float64 In1;// '<S119>/In1'
  SL_Bus_autobotscontroller_std_msgs_Float64 In1_c;// '<S118>/In1'
  SL_Bus_autobotscontroller_std_msgs_Float64 In1_p;// '<S117>/In1'
  SL_Bus_autobotscontroller_std_msgs_Float64 In1_b;// '<S116>/In1'
  boolean_T AND3;                      // '<S39>/AND3'
  boolean_T Memory;                    // '<S39>/Memory'
  boolean_T AND3_g;                    // '<S90>/AND3'
  boolean_T Memory_d;                  // '<S90>/Memory'
};

// Block states (default storage) for system '<Root>'
struct DW_autobotscontroller_T {
  ros_slroscpp_internal_block_P_T obj; // '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_b;// '<S7>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S6>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_j;// '<S5>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S4>/SourceBlock'
  int8_T If1_ActiveSubsystem;          // '<S1>/If1'
  int8_T If_ActiveSubsystem;           // '<S1>/If'
  int8_T AbideBySpeedLimit_ActiveSubsyst;// '<S1>/Abide By Speed Limit'
  boolean_T Memory_PreviousInput;      // '<S39>/Memory'
  boolean_T Memory_PreviousInput_g;    // '<S90>/Memory'
};

// Continuous states (default storage)
struct X_autobotscontroller_T {
  real_T Integrator_CSTATE;            // '<S48>/Integrator'
  real_T Filter_CSTATE;                // '<S43>/Filter'
  real_T Integrator_CSTATE_e;          // '<S99>/Integrator'
  real_T Filter_CSTATE_f;              // '<S94>/Filter'
};

// State derivatives (default storage)
struct XDot_autobotscontroller_T {
  real_T Integrator_CSTATE;            // '<S48>/Integrator'
  real_T Filter_CSTATE;                // '<S43>/Filter'
  real_T Integrator_CSTATE_e;          // '<S99>/Integrator'
  real_T Filter_CSTATE_f;              // '<S94>/Filter'
};

// State disabled
struct XDis_autobotscontroller_T {
  boolean_T Integrator_CSTATE;         // '<S48>/Integrator'
  boolean_T Filter_CSTATE;             // '<S43>/Filter'
  boolean_T Integrator_CSTATE_e;       // '<S99>/Integrator'
  boolean_T Filter_CSTATE_f;           // '<S94>/Filter'
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
struct P_autobotscontroller_T_ {
  real_T Car_Hunter_PID_D;             // Mask Parameter: Car_Hunter_PID_D
                                          //  Referenced by: '<S93>/Derivative Gain'

  real_T Car_Follower_PID_D;           // Mask Parameter: Car_Follower_PID_D
                                          //  Referenced by: '<S42>/Derivative Gain'

  real_T Car_Hunter_PID_I;             // Mask Parameter: Car_Hunter_PID_I
                                          //  Referenced by: '<S96>/Integral Gain'

  real_T Car_Follower_PID_I;           // Mask Parameter: Car_Follower_PID_I
                                          //  Referenced by: '<S45>/Integral Gain'

  real_T Car_Hunter_PID_InitialCondition;
                              // Mask Parameter: Car_Hunter_PID_InitialCondition
                                 //  Referenced by: '<S94>/Filter'

  real_T Car_Follower_PID_InitialConditi;
                              // Mask Parameter: Car_Follower_PID_InitialConditi
                                 //  Referenced by: '<S43>/Filter'

  real_T Car_Hunter_PID_InitialConditi_c;
                              // Mask Parameter: Car_Hunter_PID_InitialConditi_c
                                 //  Referenced by: '<S99>/Integrator'

  real_T Car_Follower_PID_InitialCondi_d;
                              // Mask Parameter: Car_Follower_PID_InitialCondi_d
                                 //  Referenced by: '<S48>/Integrator'

  real_T Car_Hunter_PID_LowerSaturationL;
                              // Mask Parameter: Car_Hunter_PID_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S106>/Saturation'
                                 //    '<S92>/DeadZone'

  real_T Car_Follower_PID_LowerSaturatio;
                              // Mask Parameter: Car_Follower_PID_LowerSaturatio
                                 //  Referenced by:
                                 //    '<S55>/Saturation'
                                 //    '<S41>/DeadZone'

  real_T Car_Hunter_PID_N;             // Mask Parameter: Car_Hunter_PID_N
                                          //  Referenced by: '<S102>/Filter Coefficient'

  real_T Car_Follower_PID_N;           // Mask Parameter: Car_Follower_PID_N
                                          //  Referenced by: '<S51>/Filter Coefficient'

  real_T Car_Hunter_PID_P;             // Mask Parameter: Car_Hunter_PID_P
                                          //  Referenced by: '<S104>/Proportional Gain'

  real_T Car_Follower_PID_P;           // Mask Parameter: Car_Follower_PID_P
                                          //  Referenced by: '<S53>/Proportional Gain'

  real_T Car_Hunter_PID_UpperSaturationL;
                              // Mask Parameter: Car_Hunter_PID_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S106>/Saturation'
                                 //    '<S92>/DeadZone'

  real_T Car_Follower_PID_UpperSaturatio;
                              // Mask Parameter: Car_Follower_PID_UpperSaturatio
                                 //  Referenced by:
                                 //    '<S55>/Saturation'
                                 //    '<S41>/DeadZone'

  SL_Bus_autobotscontroller_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                               //  Referenced by: '<S2>/Constant'

  SL_Bus_autobotscontroller_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                        //  Referenced by: '<S116>/Out1'

  SL_Bus_autobotscontroller_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                 //  Referenced by: '<S4>/Constant'

  SL_Bus_autobotscontroller_std_msgs_Float64 Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                          //  Referenced by: '<S117>/Out1'

  SL_Bus_autobotscontroller_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                 //  Referenced by: '<S5>/Constant'

  SL_Bus_autobotscontroller_std_msgs_Float64 Out1_Y0_dp;// Computed Parameter: Out1_Y0_dp
                                                           //  Referenced by: '<S118>/Out1'

  SL_Bus_autobotscontroller_std_msgs_Float64 Constant_Value_gg;// Computed Parameter: Constant_Value_gg
                                                                  //  Referenced by: '<S6>/Constant'

  SL_Bus_autobotscontroller_std_msgs_Float64 Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                          //  Referenced by: '<S119>/Out1'

  SL_Bus_autobotscontroller_std_msgs_Float64 Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                 //  Referenced by: '<S7>/Constant'

  real_T Constant_Value_l;             // Expression: 0
                                          //  Referenced by: '<S11>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S90>/Constant1'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S90>/ZeroGain'

  real_T Constant1_Value_h;            // Expression: 0
                                          //  Referenced by: '<S39>/Constant1'

  real_T ZeroGain_Gain_l;              // Expression: 0
                                          //  Referenced by: '<S39>/ZeroGain'

  real_T Constant_Value_c;             // Expression: 0.1
                                          //  Referenced by: '<S9>/Constant'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S90>/Memory'

  boolean_T Memory_InitialCondition_d;
                                // Computed Parameter: Memory_InitialCondition_d
                                   //  Referenced by: '<S39>/Memory'

};

// Real-time Model Data Structure
struct tag_RTM_autobotscontroller_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_autobotscontroller_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_autobotscontroller_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
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
    time_T tStart;
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

  extern P_autobotscontroller_T autobotscontroller_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_autobotscontroller_T autobotscontroller_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_autobotscontroller_T autobotscontroller_X;

// Disabled states (default storage)
extern XDis_autobotscontroller_T autobotscontroller_XDis;

// Block states (default storage)
extern struct DW_autobotscontroller_T autobotscontroller_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void autobotscontroller_initialize(void);
  extern void autobotscontroller_step(void);
  extern void autobotscontroller_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_autobotscontroller_T *const autobotscontroller_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


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
//  '<Root>' : 'autobotscontroller'
//  '<S1>'   : 'autobotscontroller/Autobots Controller'
//  '<S2>'   : 'autobotscontroller/Blank Message'
//  '<S3>'   : 'autobotscontroller/Publish'
//  '<S4>'   : 'autobotscontroller/Subscribe'
//  '<S5>'   : 'autobotscontroller/Subscribe1'
//  '<S6>'   : 'autobotscontroller/Subscribe2'
//  '<S7>'   : 'autobotscontroller/Subscribe3'
//  '<S8>'   : 'autobotscontroller/Autobots Controller/NULL_Handler1'
//  '<S9>'   : 'autobotscontroller/Autobots Controller/Null_Handler2'
//  '<S10>'  : 'autobotscontroller/Autobots Controller/Pass As Normal'
//  '<S11>'  : 'autobotscontroller/Autobots Controller/Stop_Acceleratiing'
//  '<S12>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode'
//  '<S13>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode'
//  '<S14>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID'
//  '<S15>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Anti-windup'
//  '<S16>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/D Gain'
//  '<S17>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Filter'
//  '<S18>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Filter ICs'
//  '<S19>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/I Gain'
//  '<S20>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Ideal P Gain'
//  '<S21>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Ideal P Gain Fdbk'
//  '<S22>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Integrator'
//  '<S23>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Integrator ICs'
//  '<S24>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/N Copy'
//  '<S25>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/N Gain'
//  '<S26>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/P Copy'
//  '<S27>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Parallel P Gain'
//  '<S28>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Reset Signal'
//  '<S29>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Saturation'
//  '<S30>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Saturation Fdbk'
//  '<S31>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Sum'
//  '<S32>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Sum Fdbk'
//  '<S33>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tracking Mode'
//  '<S34>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tracking Mode Sum'
//  '<S35>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tsamp - Integral'
//  '<S36>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tsamp - Ngain'
//  '<S37>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/postSat Signal'
//  '<S38>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/preSat Signal'
//  '<S39>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Anti-windup/Cont. Clamping Parallel'
//  '<S40>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S41>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S42>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/D Gain/Internal Parameters'
//  '<S43>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Filter/Cont. Filter'
//  '<S44>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Filter ICs/Internal IC - Filter'
//  '<S45>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/I Gain/Internal Parameters'
//  '<S46>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Ideal P Gain/Passthrough'
//  '<S47>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Ideal P Gain Fdbk/Disabled'
//  '<S48>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Integrator/Continuous'
//  '<S49>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Integrator ICs/Internal IC'
//  '<S50>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/N Copy/Disabled'
//  '<S51>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/N Gain/Internal Parameters'
//  '<S52>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/P Copy/Disabled'
//  '<S53>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Parallel P Gain/Internal Parameters'
//  '<S54>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Reset Signal/Disabled'
//  '<S55>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Saturation/Enabled'
//  '<S56>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Saturation Fdbk/Disabled'
//  '<S57>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Sum/Sum_PID'
//  '<S58>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Sum Fdbk/Disabled'
//  '<S59>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tracking Mode/Disabled'
//  '<S60>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tracking Mode Sum/Passthrough'
//  '<S61>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tsamp - Integral/TsSignalSpecification'
//  '<S62>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tsamp - Ngain/Passthrough'
//  '<S63>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/postSat Signal/Forward_Path'
//  '<S64>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/preSat Signal/Forward_Path'
//  '<S65>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID'
//  '<S66>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Anti-windup'
//  '<S67>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/D Gain'
//  '<S68>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Filter'
//  '<S69>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Filter ICs'
//  '<S70>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/I Gain'
//  '<S71>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Ideal P Gain'
//  '<S72>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Ideal P Gain Fdbk'
//  '<S73>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Integrator'
//  '<S74>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Integrator ICs'
//  '<S75>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/N Copy'
//  '<S76>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/N Gain'
//  '<S77>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/P Copy'
//  '<S78>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Parallel P Gain'
//  '<S79>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Reset Signal'
//  '<S80>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Saturation'
//  '<S81>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Saturation Fdbk'
//  '<S82>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Sum'
//  '<S83>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Sum Fdbk'
//  '<S84>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tracking Mode'
//  '<S85>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tracking Mode Sum'
//  '<S86>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tsamp - Integral'
//  '<S87>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tsamp - Ngain'
//  '<S88>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/postSat Signal'
//  '<S89>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/preSat Signal'
//  '<S90>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Anti-windup/Cont. Clamping Parallel'
//  '<S91>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S92>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S93>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/D Gain/Internal Parameters'
//  '<S94>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Filter/Cont. Filter'
//  '<S95>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Filter ICs/Internal IC - Filter'
//  '<S96>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/I Gain/Internal Parameters'
//  '<S97>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Ideal P Gain/Passthrough'
//  '<S98>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Ideal P Gain Fdbk/Disabled'
//  '<S99>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Integrator/Continuous'
//  '<S100>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Integrator ICs/Internal IC'
//  '<S101>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/N Copy/Disabled'
//  '<S102>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/N Gain/Internal Parameters'
//  '<S103>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/P Copy/Disabled'
//  '<S104>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Parallel P Gain/Internal Parameters'
//  '<S105>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Reset Signal/Disabled'
//  '<S106>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Saturation/Enabled'
//  '<S107>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Saturation Fdbk/Disabled'
//  '<S108>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Sum/Sum_PID'
//  '<S109>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Sum Fdbk/Disabled'
//  '<S110>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tracking Mode/Disabled'
//  '<S111>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tracking Mode Sum/Passthrough'
//  '<S112>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tsamp - Integral/TsSignalSpecification'
//  '<S113>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tsamp - Ngain/Passthrough'
//  '<S114>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/postSat Signal/Forward_Path'
//  '<S115>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/preSat Signal/Forward_Path'
//  '<S116>' : 'autobotscontroller/Subscribe/Enabled Subsystem'
//  '<S117>' : 'autobotscontroller/Subscribe1/Enabled Subsystem'
//  '<S118>' : 'autobotscontroller/Subscribe2/Enabled Subsystem'
//  '<S119>' : 'autobotscontroller/Subscribe3/Enabled Subsystem'

#endif                                 // RTW_HEADER_autobotscontroller_h_

//
// File trailer for generated code.
//
// [EOF]
//
