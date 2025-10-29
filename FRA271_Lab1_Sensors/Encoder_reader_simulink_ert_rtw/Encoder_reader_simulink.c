/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.c
 *
 * Code generated for Simulink model 'Encoder_reader_simulink'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Mon Oct 13 18:13:48 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Encoder_reader_simulink.h"
#include "Encoder_reader_simulink_types.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "Encoder_reader_simulink_private.h"

/* Block signals (default storage) */
B_Encoder_reader_simulink_T Encoder_reader_simulink_B;

/* Block states (default storage) */
DW_Encoder_reader_simulink_T Encoder_reader_simulink_DW;

/* Real-time model */
static RT_MODEL_Encoder_reader_simul_T Encoder_reader_simulink_M_;
RT_MODEL_Encoder_reader_simul_T *const Encoder_reader_simulink_M =
  &Encoder_reader_simulink_M_;

/* Forward declaration for local functions */
static void Enc_EncoderBlockForG4_setupImpl(stm32cube_blocks_EncoderBlock_T *obj);
static void Enc_EncoderBlockForG4_setupImpl(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Encoder_reader_simulink_step(void)
{
  {
    real_T lastTime;
    real_T tmp;
    real_T *lastU;
    int32_T delta;
    uint32_T pinReadLoc;

    /* MATLABSystem: '<S6>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* MATLABSystem: '<S6>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_d = ((pinReadLoc & 64U) != 0U);

    /* MATLABSystem: '<S8>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* MATLABSystem: '<S8>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_n = ((pinReadLoc & 16U) != 0U);

    /* MATLABSystem: '<S10>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S10>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead = ((pinReadLoc & 8192U) != 0U);

    /* MATLABSystem: '<Root>/TIM3_Encoder' */
    resetCounterAccToInput(Encoder_reader_simulink_DW.obj_p.TimerHandle,
      Encoder_reader_simulink_B.DigitalPortRead);

    /* MATLABSystem: '<Root>/TIM3_Encoder' */
    Encoder_reader_simulink_B.TIM3_Encoder = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_p.TimerHandle, false, NULL);

    /* MATLAB Function: '<Root>/WrapAround' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    if (!Encoder_reader_simulink_DW.last_cnt_not_empty) {
      pinReadLoc = Encoder_reader_simulink_B.TIM3_Encoder;
      if (Encoder_reader_simulink_B.TIM3_Encoder > 2147483647U) {
        pinReadLoc = 2147483647U;
      }

      Encoder_reader_simulink_DW.last_cnt = (int32_T)pinReadLoc;
      Encoder_reader_simulink_DW.last_cnt_not_empty = true;
    }

    if (Encoder_reader_simulink_B.DigitalPortRead) {
      Encoder_reader_simulink_DW.last_cnt = 0;
      Encoder_reader_simulink_DW.acc = 0LL;
    }

    pinReadLoc = Encoder_reader_simulink_B.TIM3_Encoder;
    if (Encoder_reader_simulink_B.TIM3_Encoder > 2147483647U) {
      pinReadLoc = 2147483647U;
    }

    if (Encoder_reader_simulink_DW.last_cnt < (int32_T)pinReadLoc - MAX_int32_T)
    {
      delta = MAX_int32_T;
    } else {
      delta = (int32_T)pinReadLoc - Encoder_reader_simulink_DW.last_cnt;
    }

    if (delta > 30720) {
      delta -= 61440;
    } else if (delta < -30720) {
      delta += 61440;
    }

    if ((Encoder_reader_simulink_DW.acc < 0LL) && (delta < MIN_int64_T
         - Encoder_reader_simulink_DW.acc)) {
      Encoder_reader_simulink_DW.acc = MIN_int64_T;
    } else if ((Encoder_reader_simulink_DW.acc > 0LL) && (delta > MAX_int64_T
                - Encoder_reader_simulink_DW.acc)) {
      Encoder_reader_simulink_DW.acc = MAX_int64_T;
    } else {
      Encoder_reader_simulink_DW.acc += delta;
    }

    Encoder_reader_simulink_B.pos_cont = (real_T)Encoder_reader_simulink_DW.acc;
    pinReadLoc = Encoder_reader_simulink_B.TIM3_Encoder;
    if (Encoder_reader_simulink_B.TIM3_Encoder > 2147483647U) {
      pinReadLoc = 2147483647U;
    }

    Encoder_reader_simulink_DW.last_cnt = (int32_T)pinReadLoc;

    /* End of MATLAB Function: '<Root>/WrapAround' */

    /* Gain: '<Root>/Count2Deg' */
    Encoder_reader_simulink_B.Count2Deg = 57.295779513082323 *
      Encoder_reader_simulink_B.pos_cont;

    /* Derivative: '<Root>/SpeedDEGREE' incorporates:
     *  Derivative: '<Root>/SpeedRAD'
     *  Derivative: '<Root>/accDEGREE'
     *  Derivative: '<Root>/accRAD'
     */
    tmp = Encoder_reader_simulink_M->Timing.t[0];
    if ((Encoder_reader_simulink_DW.TimeStampA >= tmp) &&
        (Encoder_reader_simulink_DW.TimeStampB >= tmp)) {
      /* Derivative: '<Root>/SpeedDEGREE' */
      Encoder_reader_simulink_B.SpeedDEGREE = 0.0;
    } else {
      lastTime = Encoder_reader_simulink_DW.TimeStampA;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
      if (Encoder_reader_simulink_DW.TimeStampA <
          Encoder_reader_simulink_DW.TimeStampB) {
        if (Encoder_reader_simulink_DW.TimeStampB < tmp) {
          lastTime = Encoder_reader_simulink_DW.TimeStampB;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA >= tmp) {
        lastTime = Encoder_reader_simulink_DW.TimeStampB;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/SpeedDEGREE' */
      Encoder_reader_simulink_B.SpeedDEGREE =
        (Encoder_reader_simulink_B.Count2Deg - *lastU) / (tmp - lastTime);
    }

    /* End of Derivative: '<Root>/SpeedDEGREE' */
    /* Derivative: '<Root>/accDEGREE' */
    if ((Encoder_reader_simulink_DW.TimeStampA_b >= tmp) &&
        (Encoder_reader_simulink_DW.TimeStampB_b >= tmp)) {
      /* Derivative: '<Root>/accDEGREE' */
      Encoder_reader_simulink_B.accDEGREE = 0.0;
    } else {
      lastTime = Encoder_reader_simulink_DW.TimeStampA_b;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
      if (Encoder_reader_simulink_DW.TimeStampA_b <
          Encoder_reader_simulink_DW.TimeStampB_b) {
        if (Encoder_reader_simulink_DW.TimeStampB_b < tmp) {
          lastTime = Encoder_reader_simulink_DW.TimeStampB_b;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_b >= tmp) {
        lastTime = Encoder_reader_simulink_DW.TimeStampB_b;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
      }

      /* Derivative: '<Root>/accDEGREE' */
      Encoder_reader_simulink_B.accDEGREE =
        (Encoder_reader_simulink_B.SpeedDEGREE - *lastU) / (tmp - lastTime);
    }

    /* Gain: '<Root>/Count2Rad' */
    Encoder_reader_simulink_B.Count2Rad = 0.017453292519943295 *
      Encoder_reader_simulink_B.pos_cont;

    /* Derivative: '<Root>/SpeedRAD' */
    if ((Encoder_reader_simulink_DW.TimeStampA_o >= tmp) &&
        (Encoder_reader_simulink_DW.TimeStampB_l >= tmp)) {
      /* Derivative: '<Root>/SpeedRAD' */
      Encoder_reader_simulink_B.SpeedRAD = 0.0;
    } else {
      lastTime = Encoder_reader_simulink_DW.TimeStampA_o;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_e;
      if (Encoder_reader_simulink_DW.TimeStampA_o <
          Encoder_reader_simulink_DW.TimeStampB_l) {
        if (Encoder_reader_simulink_DW.TimeStampB_l < tmp) {
          lastTime = Encoder_reader_simulink_DW.TimeStampB_l;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_o >= tmp) {
        lastTime = Encoder_reader_simulink_DW.TimeStampB_l;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
      }

      /* Derivative: '<Root>/SpeedRAD' */
      Encoder_reader_simulink_B.SpeedRAD = (Encoder_reader_simulink_B.Count2Rad
        - *lastU) / (tmp - lastTime);
    }

    /* Derivative: '<Root>/accRAD' */
    if ((Encoder_reader_simulink_DW.TimeStampA_p >= tmp) &&
        (Encoder_reader_simulink_DW.TimeStampB_n >= tmp)) {
      /* Derivative: '<Root>/accRAD' */
      Encoder_reader_simulink_B.accRAD = 0.0;
    } else {
      lastTime = Encoder_reader_simulink_DW.TimeStampA_p;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
      if (Encoder_reader_simulink_DW.TimeStampA_p <
          Encoder_reader_simulink_DW.TimeStampB_n) {
        if (Encoder_reader_simulink_DW.TimeStampB_n < tmp) {
          lastTime = Encoder_reader_simulink_DW.TimeStampB_n;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_p >= tmp) {
        lastTime = Encoder_reader_simulink_DW.TimeStampB_n;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<Root>/accRAD' */
      Encoder_reader_simulink_B.accRAD = (Encoder_reader_simulink_B.SpeedRAD -
        *lastU) / (tmp - lastTime);
    }
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/SpeedDEGREE' */
    if (Encoder_reader_simulink_DW.TimeStampA == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
    } else if (Encoder_reader_simulink_DW.TimeStampB == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
    } else if (Encoder_reader_simulink_DW.TimeStampA <
               Encoder_reader_simulink_DW.TimeStampB) {
      Encoder_reader_simulink_DW.TimeStampA =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
    } else {
      Encoder_reader_simulink_DW.TimeStampB =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
    }

    *lastU = Encoder_reader_simulink_B.Count2Deg;

    /* End of Update for Derivative: '<Root>/SpeedDEGREE' */

    /* Update for Derivative: '<Root>/accDEGREE' */
    if (Encoder_reader_simulink_DW.TimeStampA_b == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
    } else if (Encoder_reader_simulink_DW.TimeStampB_b == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
    } else if (Encoder_reader_simulink_DW.TimeStampA_b <
               Encoder_reader_simulink_DW.TimeStampB_b) {
      Encoder_reader_simulink_DW.TimeStampA_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
    }

    *lastU = Encoder_reader_simulink_B.SpeedDEGREE;

    /* End of Update for Derivative: '<Root>/accDEGREE' */

    /* Update for Derivative: '<Root>/SpeedRAD' */
    if (Encoder_reader_simulink_DW.TimeStampA_o == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_o =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_e;
    } else if (Encoder_reader_simulink_DW.TimeStampB_l == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_l =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
    } else if (Encoder_reader_simulink_DW.TimeStampA_o <
               Encoder_reader_simulink_DW.TimeStampB_l) {
      Encoder_reader_simulink_DW.TimeStampA_o =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_e;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_l =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
    }

    *lastU = Encoder_reader_simulink_B.Count2Rad;

    /* End of Update for Derivative: '<Root>/SpeedRAD' */

    /* Update for Derivative: '<Root>/accRAD' */
    if (Encoder_reader_simulink_DW.TimeStampA_p == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
    } else if (Encoder_reader_simulink_DW.TimeStampB_n == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
    } else if (Encoder_reader_simulink_DW.TimeStampA_p <
               Encoder_reader_simulink_DW.TimeStampB_n) {
      Encoder_reader_simulink_DW.TimeStampA_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
    }

    *lastU = Encoder_reader_simulink_B.SpeedRAD;

    /* End of Update for Derivative: '<Root>/accRAD' */
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Encoder_reader_simulink_M->Timing.clockTick1) * 0.001);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Encoder_reader_simulink_M->Timing.t[0] =
    ((time_T)(++Encoder_reader_simulink_M->Timing.clockTick0)) *
    Encoder_reader_simulink_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Encoder_reader_simulink_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Encoder_reader_simulink_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Encoder_reader_simulink_M->solverInfo,
                          &Encoder_reader_simulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&Encoder_reader_simulink_M->solverInfo, &rtmGetTPtr
                (Encoder_reader_simulink_M));
    rtsiSetStepSizePtr(&Encoder_reader_simulink_M->solverInfo,
                       &Encoder_reader_simulink_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Encoder_reader_simulink_M->solverInfo,
                          (&rtmGetErrorStatus(Encoder_reader_simulink_M)));
    rtsiSetRTModelPtr(&Encoder_reader_simulink_M->solverInfo,
                      Encoder_reader_simulink_M);
  }

  rtsiSetSimTimeStep(&Encoder_reader_simulink_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Encoder_reader_simulink_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&Encoder_reader_simulink_M->solverInfo, false);
  rtsiSetSolverName(&Encoder_reader_simulink_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Encoder_reader_simulink_M,
             &Encoder_reader_simulink_M->Timing.tArray[0]);
  rtmSetTFinal(Encoder_reader_simulink_M, -1);
  Encoder_reader_simulink_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Encoder_reader_simulink_M->Sizes.checksums[0] = (3863634953U);
  Encoder_reader_simulink_M->Sizes.checksums[1] = (3876609009U);
  Encoder_reader_simulink_M->Sizes.checksums[2] = (3949420639U);
  Encoder_reader_simulink_M->Sizes.checksums[3] = (2775433247U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Encoder_reader_simulink_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Encoder_reader_simulink_M->extModeInfo,
      &Encoder_reader_simulink_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Encoder_reader_simulink_M->extModeInfo,
                        Encoder_reader_simulink_M->Sizes.checksums);
    rteiSetTPtr(Encoder_reader_simulink_M->extModeInfo, rtmGetTPtr
                (Encoder_reader_simulink_M));
  }

  /* InitializeConditions for Derivative: '<Root>/SpeedDEGREE' */
  Encoder_reader_simulink_DW.TimeStampA = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/accDEGREE' */
  Encoder_reader_simulink_DW.TimeStampA_b = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_b = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/SpeedRAD' */
  Encoder_reader_simulink_DW.TimeStampA_o = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_l = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/accRAD' */
  Encoder_reader_simulink_DW.TimeStampA_p = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_n = (rtInf);

  /* Start for MATLABSystem: '<S6>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_j.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_j.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_l.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_l.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S10>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj.isInitialized = 1;
  Encoder_reader_simulink_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_p.isSetupComplete = false;
  Encoder_reader_simulink_DW.obj_p.isInitialized = 1;
  Enc_EncoderBlockForG4_setupImpl(&Encoder_reader_simulink_DW.obj_p);
  Encoder_reader_simulink_DW.obj_p.isSetupComplete = true;
}

/* Model terminate function */
void Encoder_reader_simulink_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<S6>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_j.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S8>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_l.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S10>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S10>/Digital Port Read' */

  /* Terminate for MATLABSystem: '<Root>/TIM3_Encoder' */
  if (!Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_p.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_p.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_p.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_p.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_p.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_p.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM3_Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
