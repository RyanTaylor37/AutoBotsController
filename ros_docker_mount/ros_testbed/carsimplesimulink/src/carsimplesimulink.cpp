//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: carsimplesimulink.cpp
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
#include "carsimplesimulink.h"
#include "rtwtypes.h"
#include "carsimplesimulink_types.h"
#include "carsimplesimulink_private.h"

// Block signals (default storage)
B_carsimplesimulink_T carsimplesimulink_B;

// Continuous states
X_carsimplesimulink_T carsimplesimulink_X;

// Block states (default storage)
DW_carsimplesimulink_T carsimplesimulink_DW;

// Real-time model
RT_MODEL_carsimplesimulink_T carsimplesimulink_M_ = RT_MODEL_carsimplesimulink_T
  ();
RT_MODEL_carsimplesimulink_T *const carsimplesimulink_M = &carsimplesimulink_M_;

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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  carsimplesimulink_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  carsimplesimulink_step();
  carsimplesimulink_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  carsimplesimulink_step();
  carsimplesimulink_derivatives();

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
void carsimplesimulink_step(void)
{
  SL_Bus_carsimplesimulink_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_carsimplesimulink_std_msgs_Float64 rtb_BusAssignment1;
  real_T value;
  if (rtmIsMajorTimeStep(carsimplesimulink_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&carsimplesimulink_M->solverInfo,
                          ((carsimplesimulink_M->Timing.clockTick0+1)*
      carsimplesimulink_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(carsimplesimulink_M)) {
    carsimplesimulink_M->Timing.t[0] = rtsiGetT(&carsimplesimulink_M->solverInfo);
  }

  // MATLABSystem: '<Root>/Get Parameter'
  ParamGet_carsimplesimulink_31.get_parameter(&value);

  // Integrator: '<Root>/Integrator' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter'

  if (carsimplesimulink_DW.Integrator_IWORK != 0) {
    carsimplesimulink_X.Integrator_CSTATE = value;
  }

  // Saturate: '<Root>/Saturation' incorporates:
  //   Integrator: '<Root>/Integrator'

  if (carsimplesimulink_X.Integrator_CSTATE >
      carsimplesimulink_P.Saturation_UpperSat) {
    // Saturate: '<Root>/Saturation'
    carsimplesimulink_B.Saturation = carsimplesimulink_P.Saturation_UpperSat;
  } else if (carsimplesimulink_X.Integrator_CSTATE <
             carsimplesimulink_P.Saturation_LowerSat) {
    // Saturate: '<Root>/Saturation'
    carsimplesimulink_B.Saturation = carsimplesimulink_P.Saturation_LowerSat;
  } else {
    // Saturate: '<Root>/Saturation'
    carsimplesimulink_B.Saturation = carsimplesimulink_X.Integrator_CSTATE;
  }

  // End of Saturate: '<Root>/Saturation'

  // BusAssignment: '<Root>/Bus Assignment'
  rtb_BusAssignment.Data = carsimplesimulink_B.Saturation;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_carsimplesimulink_17.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // MATLABSystem: '<Root>/Get Parameter1'
  ParamGet_carsimplesimulink_37.get_parameter(&value);

  // Integrator: '<Root>/Integrator1' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter1'

  if (carsimplesimulink_DW.Integrator1_IWORK != 0) {
    carsimplesimulink_X.Integrator1_CSTATE = value;
  }

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Integrator: '<Root>/Integrator1'

  rtb_BusAssignment1.Data = carsimplesimulink_X.Integrator1_CSTATE;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_carsimplesimulink_35.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
  if (rtmIsMajorTimeStep(carsimplesimulink_M)) {
    boolean_T b_varargout_1;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S5>/SourceBlock'
    b_varargout_1 = Sub_carsimplesimulink_20.getLatestMessage(&rtb_BusAssignment);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S6>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S6>/In1'
      carsimplesimulink_B.In1 = rtb_BusAssignment;
    }

    // End of MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'
  }

  // TransferFcn: '<Root>/Transfer Fcn'
  carsimplesimulink_B.TransferFcn = carsimplesimulink_P.TransferFcn_C *
    carsimplesimulink_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(carsimplesimulink_M)) {
    // Update for Integrator: '<Root>/Integrator'
    carsimplesimulink_DW.Integrator_IWORK = 0;

    // Update for Integrator: '<Root>/Integrator1'
    carsimplesimulink_DW.Integrator1_IWORK = 0;
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(carsimplesimulink_M)) {
    rt_ertODEUpdateContinuousStates(&carsimplesimulink_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++carsimplesimulink_M->Timing.clockTick0;
    carsimplesimulink_M->Timing.t[0] = rtsiGetSolverStopTime
      (&carsimplesimulink_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      carsimplesimulink_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void carsimplesimulink_derivatives(void)
{
  XDot_carsimplesimulink_T *_rtXdot;
  _rtXdot = ((XDot_carsimplesimulink_T *) carsimplesimulink_M->derivs);

  // Derivatives for Integrator: '<Root>/Integrator'
  _rtXdot->Integrator_CSTATE = carsimplesimulink_B.TransferFcn;

  // Derivatives for Integrator: '<Root>/Integrator1'
  _rtXdot->Integrator1_CSTATE = carsimplesimulink_B.Saturation;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn'
  _rtXdot->TransferFcn_CSTATE = carsimplesimulink_P.TransferFcn_A *
    carsimplesimulink_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += carsimplesimulink_B.In1.Data;
}

// Model initialize function
void carsimplesimulink_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&carsimplesimulink_M->solverInfo,
                          &carsimplesimulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&carsimplesimulink_M->solverInfo, &rtmGetTPtr
                (carsimplesimulink_M));
    rtsiSetStepSizePtr(&carsimplesimulink_M->solverInfo,
                       &carsimplesimulink_M->Timing.stepSize0);
    rtsiSetdXPtr(&carsimplesimulink_M->solverInfo, &carsimplesimulink_M->derivs);
    rtsiSetContStatesPtr(&carsimplesimulink_M->solverInfo, (real_T **)
                         &carsimplesimulink_M->contStates);
    rtsiSetNumContStatesPtr(&carsimplesimulink_M->solverInfo,
      &carsimplesimulink_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&carsimplesimulink_M->solverInfo,
      &carsimplesimulink_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&carsimplesimulink_M->solverInfo,
      &carsimplesimulink_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&carsimplesimulink_M->solverInfo,
      &carsimplesimulink_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&carsimplesimulink_M->solverInfo, (&rtmGetErrorStatus
      (carsimplesimulink_M)));
    rtsiSetRTModelPtr(&carsimplesimulink_M->solverInfo, carsimplesimulink_M);
  }

  rtsiSetSimTimeStep(&carsimplesimulink_M->solverInfo, MAJOR_TIME_STEP);
  carsimplesimulink_M->intgData.y = carsimplesimulink_M->odeY;
  carsimplesimulink_M->intgData.f[0] = carsimplesimulink_M->odeF[0];
  carsimplesimulink_M->intgData.f[1] = carsimplesimulink_M->odeF[1];
  carsimplesimulink_M->intgData.f[2] = carsimplesimulink_M->odeF[2];
  carsimplesimulink_M->contStates = ((X_carsimplesimulink_T *)
    &carsimplesimulink_X);
  rtsiSetSolverData(&carsimplesimulink_M->solverInfo, static_cast<void *>
                    (&carsimplesimulink_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&carsimplesimulink_M->solverInfo, false);
  rtsiSetSolverName(&carsimplesimulink_M->solverInfo,"ode3");
  rtmSetTPtr(carsimplesimulink_M, &carsimplesimulink_M->Timing.tArray[0]);
  carsimplesimulink_M->Timing.stepSize0 = 0.05;
  rtmSetFirstInitCond(carsimplesimulink_M, 1);

  {
    char_T b_zeroDelimTopic_1[10];
    char_T b_zeroDelimTopic_0[7];
    char_T b_zeroDelimTopic[6];
    char_T b_zeroDelimName[3];
    static const char_T tmp[5] = { 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_0[6] = { 'o', 'd', 'o', 'm', '_', 'x' };

    static const char_T tmp_1[9] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l'
    };

    // InitializeConditions for Integrator: '<Root>/Integrator' incorporates:
    //   Integrator: '<Root>/Integrator1'

    if (rtmIsFirstInitCond(carsimplesimulink_M)) {
      carsimplesimulink_X.Integrator_CSTATE = 0.0;
      carsimplesimulink_X.Integrator1_CSTATE = 0.0;
    }

    carsimplesimulink_DW.Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<Root>/Integrator'

    // InitializeConditions for Integrator: '<Root>/Integrator1'
    carsimplesimulink_DW.Integrator1_IWORK = 1;

    // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn'
    carsimplesimulink_X.TransferFcn_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    carsimplesimulink_DW.obj_j.matlabCodegenIsDeleted = false;
    carsimplesimulink_DW.obj_j.isInitialized = 1;
    for (int32_T i = 0; i < 5; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[5] = '\x00';
    Pub_carsimplesimulink_17.createPublisher(&b_zeroDelimTopic[0], 1);
    carsimplesimulink_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    carsimplesimulink_DW.obj_l.matlabCodegenIsDeleted = false;
    carsimplesimulink_DW.obj_l.isInitialized = 1;
    for (int32_T i = 0; i < 6; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[6] = '\x00';
    Pub_carsimplesimulink_35.createPublisher(&b_zeroDelimTopic_0[0], 1);
    carsimplesimulink_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
    //   Outport: '<S6>/Out1'

    carsimplesimulink_B.In1 = carsimplesimulink_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    carsimplesimulink_DW.obj_e.matlabCodegenIsDeleted = false;
    carsimplesimulink_DW.obj_e.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[9] = '\x00';
    Sub_carsimplesimulink_20.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    carsimplesimulink_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // Start for MATLABSystem: '<Root>/Get Parameter'
    carsimplesimulink_DW.obj_k.matlabCodegenIsDeleted = false;
    carsimplesimulink_DW.obj_k.isInitialized = 1;
    b_zeroDelimName[0] = 'v';
    b_zeroDelimName[1] = '0';
    b_zeroDelimName[2] = '\x00';
    ParamGet_carsimplesimulink_31.initialize(&b_zeroDelimName[0]);
    ParamGet_carsimplesimulink_31.initialize_error_codes(0, 1, 2, 3);
    ParamGet_carsimplesimulink_31.set_initial_value(0.0);
    carsimplesimulink_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter1'
    carsimplesimulink_DW.obj.matlabCodegenIsDeleted = false;
    carsimplesimulink_DW.obj.isInitialized = 1;
    b_zeroDelimName[0] = 'x';
    b_zeroDelimName[1] = '0';
    b_zeroDelimName[2] = '\x00';
    ParamGet_carsimplesimulink_37.initialize(&b_zeroDelimName[0]);
    ParamGet_carsimplesimulink_37.initialize_error_codes(0, 1, 2, 3);
    ParamGet_carsimplesimulink_37.set_initial_value(0.0);
    carsimplesimulink_DW.obj.isSetupComplete = true;
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond(carsimplesimulink_M)) {
    rtmSetFirstInitCond(carsimplesimulink_M, 0);
  }
}

// Model terminate function
void carsimplesimulink_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/Get Parameter'
  if (!carsimplesimulink_DW.obj_k.matlabCodegenIsDeleted) {
    carsimplesimulink_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!carsimplesimulink_DW.obj_j.matlabCodegenIsDeleted) {
    carsimplesimulink_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for MATLABSystem: '<Root>/Get Parameter1'
  if (!carsimplesimulink_DW.obj.matlabCodegenIsDeleted) {
    carsimplesimulink_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter1'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!carsimplesimulink_DW.obj_l.matlabCodegenIsDeleted) {
    carsimplesimulink_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!carsimplesimulink_DW.obj_e.matlabCodegenIsDeleted) {
    carsimplesimulink_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'
}

//
// File trailer for generated code.
//
// [EOF]
//
