//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: subtractor.cpp
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
#include "subtractor.h"
#include "rtwtypes.h"
#include "subtractor_types.h"

// Block signals (default storage)
B_subtractor_T subtractor_B;

// Block states (default storage)
DW_subtractor_T subtractor_DW;

// Real-time model
RT_MODEL_subtractor_T subtractor_M_ = RT_MODEL_subtractor_T();
RT_MODEL_subtractor_T *const subtractor_M = &subtractor_M_;

// Model step function
void subtractor_step(void)
{
  SL_Bus_subtractor_std_msgs_Float64 b_varargout_2;
  SL_Bus_subtractor_std_msgs_Float64 rtb_BusAssignment;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S3>/SourceBlock'
  b_varargout_1 = Sub_subtractor_1.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S5>/In1'
    subtractor_B.In1_m = b_varargout_2;
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = Sub_subtractor_15.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S6>/In1'
    subtractor_B.In1 = b_varargout_2;
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Sum: '<Root>/Add'

  rtb_BusAssignment.Data = subtractor_B.In1_m.Data - subtractor_B.In1.Data;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_subtractor_4.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void subtractor_initialize(void)
{
  {
    char_T b_zeroDelimTopic_0[5];
    char_T b_zeroDelimTopic[4];

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S5>/In1' incorporates:
    //   Outport: '<S5>/Out1'

    subtractor_B.In1_m = subtractor_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    subtractor_DW.obj_n.matlabCodegenIsDeleted = false;
    subtractor_DW.obj_n.isInitialized = 1;
    b_zeroDelimTopic[0] = 'i';
    b_zeroDelimTopic[1] = 'n';
    b_zeroDelimTopic[2] = '1';
    b_zeroDelimTopic[3] = '\x00';
    Sub_subtractor_1.createSubscriber(&b_zeroDelimTopic[0], 1);
    subtractor_DW.obj_n.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
    //   Outport: '<S6>/Out1'

    subtractor_B.In1 = subtractor_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    subtractor_DW.obj_c.matlabCodegenIsDeleted = false;
    subtractor_DW.obj_c.isInitialized = 1;
    b_zeroDelimTopic[0] = 'i';
    b_zeroDelimTopic[1] = 'n';
    b_zeroDelimTopic[2] = '2';
    b_zeroDelimTopic[3] = '\x00';
    Sub_subtractor_15.createSubscriber(&b_zeroDelimTopic[0], 1);
    subtractor_DW.obj_c.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    subtractor_DW.obj.matlabCodegenIsDeleted = false;
    subtractor_DW.obj.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 'd';
    b_zeroDelimTopic_0[1] = 'i';
    b_zeroDelimTopic_0[2] = 'f';
    b_zeroDelimTopic_0[3] = 'f';
    b_zeroDelimTopic_0[4] = '\x00';
    Pub_subtractor_4.createPublisher(&b_zeroDelimTopic_0[0], 1);
    subtractor_DW.obj.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void subtractor_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!subtractor_DW.obj_n.matlabCodegenIsDeleted) {
    subtractor_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!subtractor_DW.obj_c.matlabCodegenIsDeleted) {
    subtractor_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!subtractor_DW.obj.matlabCodegenIsDeleted) {
    subtractor_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
