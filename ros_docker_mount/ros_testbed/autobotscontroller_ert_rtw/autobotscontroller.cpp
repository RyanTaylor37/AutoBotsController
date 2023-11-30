//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: autobotscontroller.cpp
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

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "rtwtypes.h"
#include "autobotscontroller_types.h"
#include "autobotscontroller_private.h"

// Block signals (default storage)
B_autobotscontroller_T autobotscontroller_B;

// Continuous states
X_autobotscontroller_T autobotscontroller_X;

// Disabled State Vector
XDis_autobotscontroller_T autobotscontroller_XDis;

// Block states (default storage)
DW_autobotscontroller_T autobotscontroller_DW;

// Real-time model
RT_MODEL_autobotscontroller_T autobotscontroller_M_ =
  RT_MODEL_autobotscontroller_T();
RT_MODEL_autobotscontroller_T *const autobotscontroller_M =
  &autobotscontroller_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  autobotscontroller_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  autobotscontroller_step();
  autobotscontroller_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  autobotscontroller_step();
  autobotscontroller_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void autobotscontroller_step(void)
{
  SL_Bus_autobotscontroller_std_msgs_Float64 b_varargout_2;
  SL_Bus_autobotscontroller_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_Data;
  real_T rtb_Sum_j;
  real_T tmp_1;
  int32_T tmp;
  int32_T tmp_0;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T rtb_NotEqual;
  if (rtmIsMajorTimeStep(autobotscontroller_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&autobotscontroller_M->solverInfo,
                          ((autobotscontroller_M->Timing.clockTick0+1)*
      autobotscontroller_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(autobotscontroller_M)) {
    autobotscontroller_M->Timing.t[0] = rtsiGetT
      (&autobotscontroller_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(autobotscontroller_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S4>/SourceBlock'
    rtb_NotEqual = Sub_autobotscontroller_36.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S116>/Enable'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    if (rtb_NotEqual) {
      // SignalConversion generated from: '<S116>/In1'
      autobotscontroller_B.In1_b = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // SignalConversion generated from: '<Root>/Bus Selector'
    rtb_Data = autobotscontroller_B.In1_b.Data;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S6>/SourceBlock'
    rtb_NotEqual = Sub_autobotscontroller_121.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S118>/Enable'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    if (rtb_NotEqual) {
      // SignalConversion generated from: '<S118>/In1'
      autobotscontroller_B.In1_c = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // If: '<S1>/If1' incorporates:
    //   SignalConversion generated from: '<Root>/Bus Selector'

    if (rtsiIsModeUpdateTimeStep(&autobotscontroller_M->solverInfo)) {
      autobotscontroller_DW.If1_ActiveSubsystem = static_cast<int8_T>
        (!(autobotscontroller_B.In1_b.Data > 0.1));
    }

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S5>/SourceBlock'
    rtb_NotEqual = Sub_autobotscontroller_48.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S117>/Enable'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    if (rtb_NotEqual) {
      // SignalConversion generated from: '<S117>/In1'
      autobotscontroller_B.In1_p = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
    // MATLABSystem: '<S7>/SourceBlock'
    rtb_NotEqual = Sub_autobotscontroller_123.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S119>/Enable'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    if (rtb_NotEqual) {
      // SignalConversion generated from: '<S119>/In1'
      autobotscontroller_B.In1 = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe3'

    // If: '<S1>/If1' incorporates:
    //   Constant: '<S9>/Constant'
    //   Product: '<S1>/Divide'
    //   SignalConversion generated from: '<Root>/Bus Selector'
    //   Sum: '<S1>/Subtract'
    //   Sum: '<S9>/Add'

    if (autobotscontroller_DW.If1_ActiveSubsystem == 0) {
      tmp_1 = autobotscontroller_B.In1_b.Data;
    } else {
      // Outputs for IfAction SubSystem: '<S1>/Null_Handler2' incorporates:
      //   ActionPort: '<S9>/Action Port'

      tmp_1 = autobotscontroller_B.In1_b.Data +
        autobotscontroller_P.Constant_Value_c;

      // End of Outputs for SubSystem: '<S1>/Null_Handler2'
    }

    autobotscontroller_B.error = autobotscontroller_B.In1_p.Data / tmp_1 -
      autobotscontroller_B.In1.Data;
  }

  // If: '<S1>/If'
  rtPrevAction = autobotscontroller_DW.If_ActiveSubsystem;
  if (rtsiIsModeUpdateTimeStep(&autobotscontroller_M->solverInfo)) {
    rtAction = static_cast<int8_T>(!(autobotscontroller_B.error > 0.0));
    autobotscontroller_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = autobotscontroller_DW.If_ActiveSubsystem;
  }

  if (rtPrevAction != rtAction) {
    if (autobotscontroller_M->Timing.t[0] == rtmGetTStart(autobotscontroller_M))
    {
      (void) memset(&(autobotscontroller_XDis.Integrator_CSTATE_e), 1,
                    2*sizeof(boolean_T));
      (void) memset(&(autobotscontroller_XDis.Integrator_CSTATE), 1,
                    2*sizeof(boolean_T));
    }

    switch (rtPrevAction) {
     case 0:
      (void) memset(&(autobotscontroller_XDis.Integrator_CSTATE_e), 1,
                    2*sizeof(boolean_T));
      break;

     case 1:
      (void) memset(&(autobotscontroller_XDis.Integrator_CSTATE), 1,
                    2*sizeof(boolean_T));
      break;
    }
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      // Enable for IfAction SubSystem: '<S1>/Switch Case: Car Hunter Mode' incorporates:
      //   ActionPort: '<S13>/Action Port'

      // Enable for If: '<S1>/If'
      (void) memset(&(autobotscontroller_XDis.Integrator_CSTATE_e), 0,
                    2*sizeof(boolean_T));

      // End of Enable for SubSystem: '<S1>/Switch Case: Car Hunter Mode'
    }

    // Outputs for IfAction SubSystem: '<S1>/Switch Case: Car Hunter Mode' incorporates:
    //   ActionPort: '<S13>/Action Port'

    // Gain: '<S102>/Filter Coefficient' incorporates:
    //   Gain: '<S93>/Derivative Gain'
    //   Integrator: '<S94>/Filter'
    //   Sum: '<S94>/SumD'

    autobotscontroller_B.FilterCoefficient_b =
      (autobotscontroller_P.Car_Hunter_PID_D * autobotscontroller_B.error -
       autobotscontroller_X.Filter_CSTATE_f) *
      autobotscontroller_P.Car_Hunter_PID_N;

    // Sum: '<S108>/Sum' incorporates:
    //   Gain: '<S104>/Proportional Gain'
    //   Integrator: '<S99>/Integrator'

    rtb_Sum_j = (autobotscontroller_P.Car_Hunter_PID_P *
                 autobotscontroller_B.error +
                 autobotscontroller_X.Integrator_CSTATE_e) +
      autobotscontroller_B.FilterCoefficient_b;

    // DeadZone: '<S92>/DeadZone'
    if (rtb_Sum_j > autobotscontroller_P.Car_Hunter_PID_UpperSaturationL) {
      // Gain: '<S96>/Integral Gain'
      autobotscontroller_B.Switch_k = rtb_Sum_j -
        autobotscontroller_P.Car_Hunter_PID_UpperSaturationL;
    } else if (rtb_Sum_j >= autobotscontroller_P.Car_Hunter_PID_LowerSaturationL)
    {
      // Gain: '<S96>/Integral Gain'
      autobotscontroller_B.Switch_k = 0.0;
    } else {
      // Gain: '<S96>/Integral Gain'
      autobotscontroller_B.Switch_k = rtb_Sum_j -
        autobotscontroller_P.Car_Hunter_PID_LowerSaturationL;
    }

    // End of DeadZone: '<S92>/DeadZone'

    // RelationalOperator: '<S90>/NotEqual' incorporates:
    //   Gain: '<S90>/ZeroGain'

    rtb_NotEqual = (autobotscontroller_P.ZeroGain_Gain * rtb_Sum_j !=
                    autobotscontroller_B.Switch_k);

    // Signum: '<S90>/SignPreSat'
    if (rtIsNaN(autobotscontroller_B.Switch_k)) {
      // DataTypeConversion: '<S90>/DataTypeConv1'
      tmp_1 = (rtNaN);
    } else if (autobotscontroller_B.Switch_k < 0.0) {
      // DataTypeConversion: '<S90>/DataTypeConv1'
      tmp_1 = -1.0;
    } else {
      // DataTypeConversion: '<S90>/DataTypeConv1'
      tmp_1 = (autobotscontroller_B.Switch_k > 0.0);
    }

    // End of Signum: '<S90>/SignPreSat'

    // DataTypeConversion: '<S90>/DataTypeConv1'
    if (rtIsNaN(tmp_1)) {
      tmp_0 = 0;
    } else {
      tmp_0 = static_cast<int32_T>(fmod(tmp_1, 256.0));
    }

    // Gain: '<S96>/Integral Gain'
    autobotscontroller_B.Switch_k = autobotscontroller_P.Car_Hunter_PID_I *
      autobotscontroller_B.error;

    // Signum: '<S90>/SignPreIntegrator'
    if (rtIsNaN(autobotscontroller_B.Switch_k)) {
      // DataTypeConversion: '<S90>/DataTypeConv2'
      tmp_1 = (rtNaN);
    } else if (autobotscontroller_B.Switch_k < 0.0) {
      // DataTypeConversion: '<S90>/DataTypeConv2'
      tmp_1 = -1.0;
    } else {
      // DataTypeConversion: '<S90>/DataTypeConv2'
      tmp_1 = (autobotscontroller_B.Switch_k > 0.0);
    }

    // End of Signum: '<S90>/SignPreIntegrator'

    // DataTypeConversion: '<S90>/DataTypeConv2'
    if (rtIsNaN(tmp_1)) {
      tmp = 0;
    } else {
      tmp = static_cast<int32_T>(fmod(tmp_1, 256.0));
    }

    // Logic: '<S90>/AND3' incorporates:
    //   DataTypeConversion: '<S90>/DataTypeConv1'
    //   DataTypeConversion: '<S90>/DataTypeConv2'
    //   RelationalOperator: '<S90>/Equal1'

    autobotscontroller_B.AND3_g = (rtb_NotEqual && ((tmp_0 < 0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-static_cast<real_T>(tmp_0))))) : tmp_0) == (tmp < 0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
      (static_cast<uint8_T>(-static_cast<real_T>(tmp))))) : tmp)));
    if (rtmIsMajorTimeStep(autobotscontroller_M)) {
      // Memory: '<S90>/Memory'
      autobotscontroller_B.Memory_d =
        autobotscontroller_DW.Memory_PreviousInput_g;
    }

    // Switch: '<S90>/Switch'
    if (autobotscontroller_B.Memory_d) {
      // Gain: '<S96>/Integral Gain' incorporates:
      //   Constant: '<S90>/Constant1'
      //   Switch: '<S90>/Switch'

      autobotscontroller_B.Switch_k = autobotscontroller_P.Constant1_Value;
    }

    // End of Switch: '<S90>/Switch'

    // Saturate: '<S106>/Saturation'
    if (rtb_Sum_j > autobotscontroller_P.Car_Hunter_PID_UpperSaturationL) {
      // Merge: '<S1>/Merge'
      rtb_Sum_j = autobotscontroller_P.Car_Hunter_PID_UpperSaturationL;
    } else if (rtb_Sum_j < autobotscontroller_P.Car_Hunter_PID_LowerSaturationL)
    {
      // Merge: '<S1>/Merge'
      rtb_Sum_j = autobotscontroller_P.Car_Hunter_PID_LowerSaturationL;
    }

    // End of Saturate: '<S106>/Saturation'
    // End of Outputs for SubSystem: '<S1>/Switch Case: Car Hunter Mode'
  } else {
    if (rtAction != rtPrevAction) {
      // Enable for IfAction SubSystem: '<S1>/Switch Case: Car Follower Mode' incorporates:
      //   ActionPort: '<S12>/Action Port'

      // Enable for If: '<S1>/If'
      (void) memset(&(autobotscontroller_XDis.Integrator_CSTATE), 0,
                    2*sizeof(boolean_T));

      // End of Enable for SubSystem: '<S1>/Switch Case: Car Follower Mode'
    }

    // Outputs for IfAction SubSystem: '<S1>/Switch Case: Car Follower Mode' incorporates:
    //   ActionPort: '<S12>/Action Port'

    // Gain: '<S51>/Filter Coefficient' incorporates:
    //   Gain: '<S42>/Derivative Gain'
    //   Integrator: '<S43>/Filter'
    //   Sum: '<S43>/SumD'

    autobotscontroller_B.FilterCoefficient =
      (autobotscontroller_P.Car_Follower_PID_D * autobotscontroller_B.error -
       autobotscontroller_X.Filter_CSTATE) *
      autobotscontroller_P.Car_Follower_PID_N;

    // Sum: '<S57>/Sum' incorporates:
    //   Gain: '<S53>/Proportional Gain'
    //   Integrator: '<S48>/Integrator'

    rtb_Sum_j = (autobotscontroller_P.Car_Follower_PID_P *
                 autobotscontroller_B.error +
                 autobotscontroller_X.Integrator_CSTATE) +
      autobotscontroller_B.FilterCoefficient;

    // DeadZone: '<S41>/DeadZone'
    if (rtb_Sum_j > autobotscontroller_P.Car_Follower_PID_UpperSaturatio) {
      // Gain: '<S45>/Integral Gain'
      autobotscontroller_B.Switch = rtb_Sum_j -
        autobotscontroller_P.Car_Follower_PID_UpperSaturatio;
    } else if (rtb_Sum_j >= autobotscontroller_P.Car_Follower_PID_LowerSaturatio)
    {
      // Gain: '<S45>/Integral Gain'
      autobotscontroller_B.Switch = 0.0;
    } else {
      // Gain: '<S45>/Integral Gain'
      autobotscontroller_B.Switch = rtb_Sum_j -
        autobotscontroller_P.Car_Follower_PID_LowerSaturatio;
    }

    // End of DeadZone: '<S41>/DeadZone'

    // RelationalOperator: '<S39>/NotEqual' incorporates:
    //   Gain: '<S39>/ZeroGain'

    rtb_NotEqual = (autobotscontroller_P.ZeroGain_Gain_l * rtb_Sum_j !=
                    autobotscontroller_B.Switch);

    // Signum: '<S39>/SignPreSat'
    if (rtIsNaN(autobotscontroller_B.Switch)) {
      // DataTypeConversion: '<S39>/DataTypeConv1'
      tmp_1 = (rtNaN);
    } else if (autobotscontroller_B.Switch < 0.0) {
      // DataTypeConversion: '<S39>/DataTypeConv1'
      tmp_1 = -1.0;
    } else {
      // DataTypeConversion: '<S39>/DataTypeConv1'
      tmp_1 = (autobotscontroller_B.Switch > 0.0);
    }

    // End of Signum: '<S39>/SignPreSat'

    // DataTypeConversion: '<S39>/DataTypeConv1'
    if (rtIsNaN(tmp_1)) {
      tmp_0 = 0;
    } else {
      tmp_0 = static_cast<int32_T>(fmod(tmp_1, 256.0));
    }

    // Gain: '<S45>/Integral Gain'
    autobotscontroller_B.Switch = autobotscontroller_P.Car_Follower_PID_I *
      autobotscontroller_B.error;

    // Signum: '<S39>/SignPreIntegrator'
    if (rtIsNaN(autobotscontroller_B.Switch)) {
      // DataTypeConversion: '<S39>/DataTypeConv2'
      tmp_1 = (rtNaN);
    } else if (autobotscontroller_B.Switch < 0.0) {
      // DataTypeConversion: '<S39>/DataTypeConv2'
      tmp_1 = -1.0;
    } else {
      // DataTypeConversion: '<S39>/DataTypeConv2'
      tmp_1 = (autobotscontroller_B.Switch > 0.0);
    }

    // End of Signum: '<S39>/SignPreIntegrator'

    // DataTypeConversion: '<S39>/DataTypeConv2'
    if (rtIsNaN(tmp_1)) {
      tmp = 0;
    } else {
      tmp = static_cast<int32_T>(fmod(tmp_1, 256.0));
    }

    // Logic: '<S39>/AND3' incorporates:
    //   DataTypeConversion: '<S39>/DataTypeConv1'
    //   DataTypeConversion: '<S39>/DataTypeConv2'
    //   RelationalOperator: '<S39>/Equal1'

    autobotscontroller_B.AND3 = (rtb_NotEqual && ((tmp_0 < 0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-static_cast<real_T>(tmp_0))))) : tmp_0) == (tmp < 0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
      (static_cast<uint8_T>(-static_cast<real_T>(tmp))))) : tmp)));
    if (rtmIsMajorTimeStep(autobotscontroller_M)) {
      // Memory: '<S39>/Memory'
      autobotscontroller_B.Memory = autobotscontroller_DW.Memory_PreviousInput;
    }

    // Switch: '<S39>/Switch'
    if (autobotscontroller_B.Memory) {
      // Gain: '<S45>/Integral Gain' incorporates:
      //   Constant: '<S39>/Constant1'
      //   Switch: '<S39>/Switch'

      autobotscontroller_B.Switch = autobotscontroller_P.Constant1_Value_h;
    }

    // End of Switch: '<S39>/Switch'

    // Saturate: '<S55>/Saturation'
    if (rtb_Sum_j > autobotscontroller_P.Car_Follower_PID_UpperSaturatio) {
      // Merge: '<S1>/Merge'
      rtb_Sum_j = autobotscontroller_P.Car_Follower_PID_UpperSaturatio;
    } else if (rtb_Sum_j < autobotscontroller_P.Car_Follower_PID_LowerSaturatio)
    {
      // Merge: '<S1>/Merge'
      rtb_Sum_j = autobotscontroller_P.Car_Follower_PID_LowerSaturatio;
    }

    // End of Saturate: '<S55>/Saturation'
    // End of Outputs for SubSystem: '<S1>/Switch Case: Car Follower Mode'
  }

  // End of If: '<S1>/If'
  if (rtmIsMajorTimeStep(autobotscontroller_M)) {
    // If: '<S1>/Abide By Speed Limit'
    if (rtsiIsModeUpdateTimeStep(&autobotscontroller_M->solverInfo)) {
      autobotscontroller_DW.AbideBySpeedLimit_ActiveSubsyst = static_cast<int8_T>
        (!(rtb_Data >= autobotscontroller_B.In1_c.Data));
    }

    if (autobotscontroller_DW.AbideBySpeedLimit_ActiveSubsyst == 0) {
      // Outputs for IfAction SubSystem: '<S1>/Stop_Acceleratiing' incorporates:
      //   ActionPort: '<S11>/Action Port'

      // BusAssignment: '<Root>/Bus Assignment' incorporates:
      //   Constant: '<S11>/Constant'
      //   SignalConversion generated from: '<S11>/Out1'

      rtb_BusAssignment.Data = autobotscontroller_P.Constant_Value_l;

      // End of Outputs for SubSystem: '<S1>/Stop_Acceleratiing'
    } else {
      // Outputs for IfAction SubSystem: '<S1>/Pass As Normal' incorporates:
      //   ActionPort: '<S10>/Action Port'

      // BusAssignment: '<Root>/Bus Assignment' incorporates:
      //   SignalConversion generated from: '<S10>/V1'

      rtb_BusAssignment.Data = rtb_Sum_j;

      // End of Outputs for SubSystem: '<S1>/Pass As Normal'
    }

    // End of If: '<S1>/Abide By Speed Limit'

    // Outputs for Atomic SubSystem: '<Root>/Publish'
    // MATLABSystem: '<S3>/SinkBlock'
    Pub_autobotscontroller_37.publish(&rtb_BusAssignment);

    // End of Outputs for SubSystem: '<Root>/Publish'
  }

  if (rtmIsMajorTimeStep(autobotscontroller_M)) {
    // Update for If: '<S1>/If'
    if (autobotscontroller_DW.If_ActiveSubsystem == 0) {
      // Update for IfAction SubSystem: '<S1>/Switch Case: Car Hunter Mode' incorporates:
      //   ActionPort: '<S13>/Action Port'

      if (rtmIsMajorTimeStep(autobotscontroller_M)) {
        // Update for Memory: '<S90>/Memory'
        autobotscontroller_DW.Memory_PreviousInput_g =
          autobotscontroller_B.AND3_g;
      }

      // End of Update for SubSystem: '<S1>/Switch Case: Car Hunter Mode'

      // Update for IfAction SubSystem: '<S1>/Switch Case: Car Follower Mode' incorporates:
      //   ActionPort: '<S12>/Action Port'

    } else if (rtmIsMajorTimeStep(autobotscontroller_M)) {
      // Update for Memory: '<S39>/Memory'
      autobotscontroller_DW.Memory_PreviousInput = autobotscontroller_B.AND3;

      // End of Update for SubSystem: '<S1>/Switch Case: Car Follower Mode'
    }

    // End of Update for If: '<S1>/If'
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(autobotscontroller_M)) {
    rt_ertODEUpdateContinuousStates(&autobotscontroller_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++autobotscontroller_M->Timing.clockTick0;
    autobotscontroller_M->Timing.t[0] = rtsiGetSolverStopTime
      (&autobotscontroller_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.2s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.2, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      autobotscontroller_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void autobotscontroller_derivatives(void)
{
  XDot_autobotscontroller_T *_rtXdot;
  _rtXdot = ((XDot_autobotscontroller_T *) autobotscontroller_M->derivs);

  // Derivatives for If: '<S1>/If'
  {
    real_T *dx;
    int_T i;
    dx = &(((XDot_autobotscontroller_T *) autobotscontroller_M->derivs)
           ->Integrator_CSTATE_e);
    for (i=0; i < 2; i++) {
      dx[i] = 0.0;
    }
  }

  {
    real_T *dx;
    int_T i;
    dx = &(((XDot_autobotscontroller_T *) autobotscontroller_M->derivs)
           ->Integrator_CSTATE);
    for (i=0; i < 2; i++) {
      dx[i] = 0.0;
    }
  }

  switch (autobotscontroller_DW.If_ActiveSubsystem) {
   case 0:
    // Derivatives for IfAction SubSystem: '<S1>/Switch Case: Car Hunter Mode' incorporates:
    //   ActionPort: '<S13>/Action Port'

    // Derivatives for Integrator: '<S99>/Integrator'
    _rtXdot->Integrator_CSTATE_e = autobotscontroller_B.Switch_k;

    // Derivatives for Integrator: '<S94>/Filter'
    _rtXdot->Filter_CSTATE_f = autobotscontroller_B.FilterCoefficient_b;

    // End of Derivatives for SubSystem: '<S1>/Switch Case: Car Hunter Mode'
    break;

   case 1:
    // Derivatives for IfAction SubSystem: '<S1>/Switch Case: Car Follower Mode' incorporates:
    //   ActionPort: '<S12>/Action Port'

    // Derivatives for Integrator: '<S48>/Integrator'
    _rtXdot->Integrator_CSTATE = autobotscontroller_B.Switch;

    // Derivatives for Integrator: '<S43>/Filter'
    _rtXdot->Filter_CSTATE = autobotscontroller_B.FilterCoefficient;

    // End of Derivatives for SubSystem: '<S1>/Switch Case: Car Follower Mode'
    break;
  }

  // End of Derivatives for If: '<S1>/If'
}

// Model initialize function
void autobotscontroller_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&autobotscontroller_M->solverInfo,
                          &autobotscontroller_M->Timing.simTimeStep);
    rtsiSetTPtr(&autobotscontroller_M->solverInfo, &rtmGetTPtr
                (autobotscontroller_M));
    rtsiSetStepSizePtr(&autobotscontroller_M->solverInfo,
                       &autobotscontroller_M->Timing.stepSize0);
    rtsiSetdXPtr(&autobotscontroller_M->solverInfo,
                 &autobotscontroller_M->derivs);
    rtsiSetContStatesPtr(&autobotscontroller_M->solverInfo, (real_T **)
                         &autobotscontroller_M->contStates);
    rtsiSetNumContStatesPtr(&autobotscontroller_M->solverInfo,
      &autobotscontroller_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&autobotscontroller_M->solverInfo,
      &autobotscontroller_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&autobotscontroller_M->solverInfo,
      &autobotscontroller_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&autobotscontroller_M->solverInfo,
      &autobotscontroller_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&autobotscontroller_M->solverInfo, (boolean_T**)
      &autobotscontroller_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&autobotscontroller_M->solverInfo, (&rtmGetErrorStatus
      (autobotscontroller_M)));
    rtsiSetRTModelPtr(&autobotscontroller_M->solverInfo, autobotscontroller_M);
  }

  rtsiSetSimTimeStep(&autobotscontroller_M->solverInfo, MAJOR_TIME_STEP);
  autobotscontroller_M->intgData.y = autobotscontroller_M->odeY;
  autobotscontroller_M->intgData.f[0] = autobotscontroller_M->odeF[0];
  autobotscontroller_M->intgData.f[1] = autobotscontroller_M->odeF[1];
  autobotscontroller_M->intgData.f[2] = autobotscontroller_M->odeF[2];
  autobotscontroller_M->contStates = ((X_autobotscontroller_T *)
    &autobotscontroller_X);
  autobotscontroller_M->contStateDisabled = ((XDis_autobotscontroller_T *)
    &autobotscontroller_XDis);
  autobotscontroller_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&autobotscontroller_M->solverInfo, static_cast<void *>
                    (&autobotscontroller_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&autobotscontroller_M->solverInfo, false);
  rtsiSetSolverName(&autobotscontroller_M->solverInfo,"ode3");
  rtmSetTPtr(autobotscontroller_M, &autobotscontroller_M->Timing.tArray[0]);
  autobotscontroller_M->Timing.stepSize0 = 0.2;

  {
    int32_T i;
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_0[16];
    char_T b_zeroDelimTopic_1[11];
    static const char_T b_zeroDelimTopic_2[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_3[16] = "/speed_limit/v0";
    static const char_T b_zeroDelimTopic_4[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_5[21] = "/optimal_time_gap/t0";
    static const char_T b_zeroDelimTopic_6[18] = "/egocar/cmd_accel";

    // Start for If: '<S1>/If1'
    autobotscontroller_DW.If1_ActiveSubsystem = -1;

    // Start for If: '<S1>/If'
    (void) memset(&(autobotscontroller_XDis.Integrator_CSTATE_e), 1,
                  2*sizeof(boolean_T));
    (void) memset(&(autobotscontroller_XDis.Integrator_CSTATE), 1,
                  2*sizeof(boolean_T));
    autobotscontroller_DW.If_ActiveSubsystem = -1;

    // Start for If: '<S1>/Abide By Speed Limit'
    autobotscontroller_DW.AbideBySpeedLimit_ActiveSubsyst = -1;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S116>/In1' incorporates:
    //   Outport: '<S116>/Out1'

    autobotscontroller_B.In1_b = autobotscontroller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    autobotscontroller_DW.obj_g.matlabCodegenIsDeleted = false;
    autobotscontroller_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_autobotscontroller_36.createSubscriber(&b_zeroDelimTopic[0], 1);
    autobotscontroller_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S118>/In1' incorporates:
    //   Outport: '<S118>/Out1'

    autobotscontroller_B.In1_c = autobotscontroller_P.Out1_Y0_dp;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    autobotscontroller_DW.obj_n.matlabCodegenIsDeleted = false;
    autobotscontroller_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_autobotscontroller_121.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    autobotscontroller_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S117>/In1' incorporates:
    //   Outport: '<S117>/Out1'

    autobotscontroller_B.In1_p = autobotscontroller_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    autobotscontroller_DW.obj_j.matlabCodegenIsDeleted = false;
    autobotscontroller_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Sub_autobotscontroller_48.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    autobotscontroller_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S119>/In1' incorporates:
    //   Outport: '<S119>/Out1'

    autobotscontroller_B.In1 = autobotscontroller_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    autobotscontroller_DW.obj_b.matlabCodegenIsDeleted = false;
    autobotscontroller_DW.obj_b.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      autobotscontroller_B.b_zeroDelimTopic[i] = b_zeroDelimTopic_5[i];
    }

    Sub_autobotscontroller_123.createSubscriber
      (&autobotscontroller_B.b_zeroDelimTopic[0], 1);
    autobotscontroller_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for IfAction SubSystem: '<S1>/Switch Case: Car Hunter Mode' 
    // InitializeConditions for Integrator: '<S99>/Integrator'
    autobotscontroller_X.Integrator_CSTATE_e =
      autobotscontroller_P.Car_Hunter_PID_InitialConditi_c;

    // InitializeConditions for Integrator: '<S94>/Filter'
    autobotscontroller_X.Filter_CSTATE_f =
      autobotscontroller_P.Car_Hunter_PID_InitialCondition;

    // InitializeConditions for Memory: '<S90>/Memory'
    autobotscontroller_DW.Memory_PreviousInput_g =
      autobotscontroller_P.Memory_InitialCondition;

    // End of SystemInitialize for SubSystem: '<S1>/Switch Case: Car Hunter Mode' 

    // SystemInitialize for IfAction SubSystem: '<S1>/Switch Case: Car Follower Mode' 
    // InitializeConditions for Integrator: '<S48>/Integrator'
    autobotscontroller_X.Integrator_CSTATE =
      autobotscontroller_P.Car_Follower_PID_InitialCondi_d;

    // InitializeConditions for Integrator: '<S43>/Filter'
    autobotscontroller_X.Filter_CSTATE =
      autobotscontroller_P.Car_Follower_PID_InitialConditi;

    // InitializeConditions for Memory: '<S39>/Memory'
    autobotscontroller_DW.Memory_PreviousInput =
      autobotscontroller_P.Memory_InitialCondition_d;

    // End of SystemInitialize for SubSystem: '<S1>/Switch Case: Car Follower Mode' 

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    autobotscontroller_DW.obj.matlabCodegenIsDeleted = false;
    autobotscontroller_DW.obj.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      autobotscontroller_B.b_zeroDelimTopic_m[i] = b_zeroDelimTopic_6[i];
    }

    Pub_autobotscontroller_37.createPublisher
      (&autobotscontroller_B.b_zeroDelimTopic_m[0], 1);
    autobotscontroller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void autobotscontroller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!autobotscontroller_DW.obj_g.matlabCodegenIsDeleted) {
    autobotscontroller_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!autobotscontroller_DW.obj_n.matlabCodegenIsDeleted) {
    autobotscontroller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!autobotscontroller_DW.obj_j.matlabCodegenIsDeleted) {
    autobotscontroller_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!autobotscontroller_DW.obj_b.matlabCodegenIsDeleted) {
    autobotscontroller_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!autobotscontroller_DW.obj.matlabCodegenIsDeleted) {
    autobotscontroller_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
