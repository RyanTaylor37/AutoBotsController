//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: autobotscontroller.h
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
  real_T FilterCoefficient;            // '<S49>/Filter Coefficient'
  real_T Switch;                       // '<S37>/Switch'
  real_T FilterCoefficient_b;          // '<S100>/Filter Coefficient'
  real_T Switch_k;                     // '<S88>/Switch'
  SL_Bus_autobotscontroller_std_msgs_Float64 In1;// '<S115>/In1'
  SL_Bus_autobotscontroller_std_msgs_Float64 In1_b;// '<S114>/In1'
  boolean_T AND3;                      // '<S37>/AND3'
  boolean_T Memory;                    // '<S37>/Memory'
  boolean_T AND3_g;                    // '<S88>/AND3'
  boolean_T Memory_d;                  // '<S88>/Memory'
};

// Block states (default storage) for system '<Root>'
struct DW_autobotscontroller_T {
  ros_slroscpp_internal_block_P_T obj; // '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_j;// '<S5>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S4>/SourceBlock'
  int8_T If1_ActiveSubsystem;          // '<S1>/If1'
  int8_T If_ActiveSubsystem;           // '<S1>/If'
  int8_T AbideBySpeedLimit_ActiveSubsyst;// '<S1>/Abide By Speed Limit'
  boolean_T Memory_PreviousInput;      // '<S37>/Memory'
  boolean_T Memory_PreviousInput_g;    // '<S88>/Memory'
};

// Continuous states (default storage)
struct X_autobotscontroller_T {
  real_T Integrator_CSTATE;            // '<S46>/Integrator'
  real_T Filter_CSTATE;                // '<S41>/Filter'
  real_T Integrator_CSTATE_e;          // '<S97>/Integrator'
  real_T Filter_CSTATE_f;              // '<S92>/Filter'
};

// State derivatives (default storage)
struct XDot_autobotscontroller_T {
  real_T Integrator_CSTATE;            // '<S46>/Integrator'
  real_T Filter_CSTATE;                // '<S41>/Filter'
  real_T Integrator_CSTATE_e;          // '<S97>/Integrator'
  real_T Filter_CSTATE_f;              // '<S92>/Filter'
};

// State disabled
struct XDis_autobotscontroller_T {
  boolean_T Integrator_CSTATE;         // '<S46>/Integrator'
  boolean_T Filter_CSTATE;             // '<S41>/Filter'
  boolean_T Integrator_CSTATE_e;       // '<S97>/Integrator'
  boolean_T Filter_CSTATE_f;           // '<S92>/Filter'
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
                                          //  Referenced by: '<S91>/Derivative Gain'

  real_T Car_Follower_PID_D;           // Mask Parameter: Car_Follower_PID_D
                                          //  Referenced by: '<S40>/Derivative Gain'

  real_T Car_Hunter_PID_I;             // Mask Parameter: Car_Hunter_PID_I
                                          //  Referenced by: '<S94>/Integral Gain'

  real_T Car_Follower_PID_I;           // Mask Parameter: Car_Follower_PID_I
                                          //  Referenced by: '<S43>/Integral Gain'

  real_T Car_Hunter_PID_InitialCondition;
                              // Mask Parameter: Car_Hunter_PID_InitialCondition
                                 //  Referenced by: '<S92>/Filter'

  real_T Car_Follower_PID_InitialConditi;
                              // Mask Parameter: Car_Follower_PID_InitialConditi
                                 //  Referenced by: '<S41>/Filter'

  real_T Car_Hunter_PID_InitialConditi_c;
                              // Mask Parameter: Car_Hunter_PID_InitialConditi_c
                                 //  Referenced by: '<S97>/Integrator'

  real_T Car_Follower_PID_InitialCondi_d;
                              // Mask Parameter: Car_Follower_PID_InitialCondi_d
                                 //  Referenced by: '<S46>/Integrator'

  real_T Car_Hunter_PID_LowerSaturationL;
                              // Mask Parameter: Car_Hunter_PID_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S104>/Saturation'
                                 //    '<S90>/DeadZone'

  real_T Car_Follower_PID_LowerSaturatio;
                              // Mask Parameter: Car_Follower_PID_LowerSaturatio
                                 //  Referenced by:
                                 //    '<S53>/Saturation'
                                 //    '<S39>/DeadZone'

  real_T Car_Hunter_PID_N;             // Mask Parameter: Car_Hunter_PID_N
                                          //  Referenced by: '<S100>/Filter Coefficient'

  real_T Car_Follower_PID_N;           // Mask Parameter: Car_Follower_PID_N
                                          //  Referenced by: '<S49>/Filter Coefficient'

  real_T Car_Hunter_PID_P;             // Mask Parameter: Car_Hunter_PID_P
                                          //  Referenced by: '<S102>/Proportional Gain'

  real_T Car_Follower_PID_P;           // Mask Parameter: Car_Follower_PID_P
                                          //  Referenced by: '<S51>/Proportional Gain'

  real_T Car_Hunter_PID_UpperSaturationL;
                              // Mask Parameter: Car_Hunter_PID_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S104>/Saturation'
                                 //    '<S90>/DeadZone'

  real_T Car_Follower_PID_UpperSaturatio;
                              // Mask Parameter: Car_Follower_PID_UpperSaturatio
                                 //  Referenced by:
                                 //    '<S53>/Saturation'
                                 //    '<S39>/DeadZone'

  SL_Bus_autobotscontroller_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                               //  Referenced by: '<S2>/Constant'

  SL_Bus_autobotscontroller_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                        //  Referenced by: '<S114>/Out1'

  SL_Bus_autobotscontroller_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                 //  Referenced by: '<S4>/Constant'

  SL_Bus_autobotscontroller_std_msgs_Float64 Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                          //  Referenced by: '<S115>/Out1'

  SL_Bus_autobotscontroller_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                 //  Referenced by: '<S5>/Constant'

  real_T Constant_Value_l;             // Expression: 0
                                          //  Referenced by: '<S9>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S88>/Constant1'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S88>/ZeroGain'

  real_T Constant1_Value_h;            // Expression: 0
                                          //  Referenced by: '<S37>/Constant1'

  real_T ZeroGain_Gain_l;              // Expression: 0
                                          //  Referenced by: '<S37>/ZeroGain'

  real_T Constant_Value_c;             // Expression: 0.1
                                          //  Referenced by: '<S7>/Constant'

  real_T SpeedLimit_Value;             // Expression: 80
                                          //  Referenced by: '<Root>/Speed Limit'

  real_T TimeGap_Value;                // Expression: 3
                                          //  Referenced by: '<Root>/Time Gap'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S88>/Memory'

  boolean_T Memory_InitialCondition_d;
                                // Computed Parameter: Memory_InitialCondition_d
                                   //  Referenced by: '<S37>/Memory'

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
//  '<S6>'   : 'autobotscontroller/Autobots Controller/NULL_Handler1'
//  '<S7>'   : 'autobotscontroller/Autobots Controller/Null_Handler2'
//  '<S8>'   : 'autobotscontroller/Autobots Controller/Pass As Normal'
//  '<S9>'   : 'autobotscontroller/Autobots Controller/Stop_Acceleratiing'
//  '<S10>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode'
//  '<S11>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode'
//  '<S12>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID'
//  '<S13>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Anti-windup'
//  '<S14>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/D Gain'
//  '<S15>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Filter'
//  '<S16>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Filter ICs'
//  '<S17>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/I Gain'
//  '<S18>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Ideal P Gain'
//  '<S19>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Ideal P Gain Fdbk'
//  '<S20>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Integrator'
//  '<S21>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Integrator ICs'
//  '<S22>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/N Copy'
//  '<S23>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/N Gain'
//  '<S24>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/P Copy'
//  '<S25>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Parallel P Gain'
//  '<S26>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Reset Signal'
//  '<S27>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Saturation'
//  '<S28>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Saturation Fdbk'
//  '<S29>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Sum'
//  '<S30>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Sum Fdbk'
//  '<S31>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tracking Mode'
//  '<S32>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tracking Mode Sum'
//  '<S33>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tsamp - Integral'
//  '<S34>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tsamp - Ngain'
//  '<S35>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/postSat Signal'
//  '<S36>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/preSat Signal'
//  '<S37>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Anti-windup/Cont. Clamping Parallel'
//  '<S38>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S39>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S40>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/D Gain/Internal Parameters'
//  '<S41>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Filter/Cont. Filter'
//  '<S42>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Filter ICs/Internal IC - Filter'
//  '<S43>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/I Gain/Internal Parameters'
//  '<S44>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Ideal P Gain/Passthrough'
//  '<S45>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Ideal P Gain Fdbk/Disabled'
//  '<S46>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Integrator/Continuous'
//  '<S47>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Integrator ICs/Internal IC'
//  '<S48>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/N Copy/Disabled'
//  '<S49>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/N Gain/Internal Parameters'
//  '<S50>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/P Copy/Disabled'
//  '<S51>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Parallel P Gain/Internal Parameters'
//  '<S52>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Reset Signal/Disabled'
//  '<S53>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Saturation/Enabled'
//  '<S54>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Saturation Fdbk/Disabled'
//  '<S55>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Sum/Sum_PID'
//  '<S56>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Sum Fdbk/Disabled'
//  '<S57>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tracking Mode/Disabled'
//  '<S58>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tracking Mode Sum/Passthrough'
//  '<S59>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tsamp - Integral/TsSignalSpecification'
//  '<S60>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/Tsamp - Ngain/Passthrough'
//  '<S61>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/postSat Signal/Forward_Path'
//  '<S62>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Follower Mode/Car_Follower_PID/preSat Signal/Forward_Path'
//  '<S63>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID'
//  '<S64>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Anti-windup'
//  '<S65>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/D Gain'
//  '<S66>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Filter'
//  '<S67>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Filter ICs'
//  '<S68>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/I Gain'
//  '<S69>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Ideal P Gain'
//  '<S70>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Ideal P Gain Fdbk'
//  '<S71>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Integrator'
//  '<S72>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Integrator ICs'
//  '<S73>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/N Copy'
//  '<S74>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/N Gain'
//  '<S75>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/P Copy'
//  '<S76>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Parallel P Gain'
//  '<S77>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Reset Signal'
//  '<S78>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Saturation'
//  '<S79>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Saturation Fdbk'
//  '<S80>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Sum'
//  '<S81>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Sum Fdbk'
//  '<S82>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tracking Mode'
//  '<S83>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tracking Mode Sum'
//  '<S84>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tsamp - Integral'
//  '<S85>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tsamp - Ngain'
//  '<S86>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/postSat Signal'
//  '<S87>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/preSat Signal'
//  '<S88>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Anti-windup/Cont. Clamping Parallel'
//  '<S89>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S90>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S91>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/D Gain/Internal Parameters'
//  '<S92>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Filter/Cont. Filter'
//  '<S93>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Filter ICs/Internal IC - Filter'
//  '<S94>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/I Gain/Internal Parameters'
//  '<S95>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Ideal P Gain/Passthrough'
//  '<S96>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Ideal P Gain Fdbk/Disabled'
//  '<S97>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Integrator/Continuous'
//  '<S98>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Integrator ICs/Internal IC'
//  '<S99>'  : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/N Copy/Disabled'
//  '<S100>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/N Gain/Internal Parameters'
//  '<S101>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/P Copy/Disabled'
//  '<S102>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Parallel P Gain/Internal Parameters'
//  '<S103>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Reset Signal/Disabled'
//  '<S104>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Saturation/Enabled'
//  '<S105>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Saturation Fdbk/Disabled'
//  '<S106>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Sum/Sum_PID'
//  '<S107>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Sum Fdbk/Disabled'
//  '<S108>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tracking Mode/Disabled'
//  '<S109>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tracking Mode Sum/Passthrough'
//  '<S110>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tsamp - Integral/TsSignalSpecification'
//  '<S111>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/Tsamp - Ngain/Passthrough'
//  '<S112>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/postSat Signal/Forward_Path'
//  '<S113>' : 'autobotscontroller/Autobots Controller/Switch Case: Car Hunter Mode/Car_Hunter_PID/preSat Signal/Forward_Path'
//  '<S114>' : 'autobotscontroller/Subscribe/Enabled Subsystem'
//  '<S115>' : 'autobotscontroller/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_autobotscontroller_h_

//
// File trailer for generated code.
//
// [EOF]
//
