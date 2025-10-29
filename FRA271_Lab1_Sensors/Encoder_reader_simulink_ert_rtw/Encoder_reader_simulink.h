/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.h
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

#ifndef Encoder_reader_simulink_h_
#define Encoder_reader_simulink_h_
#ifndef Encoder_reader_simulink_COMMON_INCLUDES_
#define Encoder_reader_simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#include "mw_stm32_utils.h"
#endif                            /* Encoder_reader_simulink_COMMON_INCLUDES_ */

#include "Encoder_reader_simulink_types.h"
#include "rtGetInf.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Count2Deg;                    /* '<Root>/Count2Deg' */
  real_T SpeedDEGREE;                  /* '<Root>/SpeedDEGREE' */
  real_T accDEGREE;                    /* '<Root>/accDEGREE' */
  real_T Count2Rad;                    /* '<Root>/Count2Rad' */
  real_T SpeedRAD;                     /* '<Root>/SpeedRAD' */
  real_T accRAD;                       /* '<Root>/accRAD' */
  real_T pos_cont;                     /* '<Root>/WrapAround' */
  uint32_T TIM3_Encoder;               /* '<Root>/TIM3_Encoder' */
  boolean_T DigitalPortRead;           /* '<S10>/Digital Port Read' */
  boolean_T DigitalPortRead_n;         /* '<S8>/Digital Port Read' */
  boolean_T DigitalPortRead_d;         /* '<S6>/Digital Port Read' */
} B_Encoder_reader_simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S10>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_l;/* '<S8>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_j;/* '<S6>/Digital Port Read' */
  stm32cube_blocks_EncoderBlock_T obj_p;/* '<Root>/TIM3_Encoder' */
  real_T TimeStampA;                   /* '<Root>/SpeedDEGREE' */
  real_T LastUAtTimeA;                 /* '<Root>/SpeedDEGREE' */
  real_T TimeStampB;                   /* '<Root>/SpeedDEGREE' */
  real_T LastUAtTimeB;                 /* '<Root>/SpeedDEGREE' */
  real_T TimeStampA_b;                 /* '<Root>/accDEGREE' */
  real_T LastUAtTimeA_d;               /* '<Root>/accDEGREE' */
  real_T TimeStampB_b;                 /* '<Root>/accDEGREE' */
  real_T LastUAtTimeB_l;               /* '<Root>/accDEGREE' */
  real_T TimeStampA_o;                 /* '<Root>/SpeedRAD' */
  real_T LastUAtTimeA_e;               /* '<Root>/SpeedRAD' */
  real_T TimeStampB_l;                 /* '<Root>/SpeedRAD' */
  real_T LastUAtTimeB_h;               /* '<Root>/SpeedRAD' */
  real_T TimeStampA_p;                 /* '<Root>/accRAD' */
  real_T LastUAtTimeA_g;               /* '<Root>/accRAD' */
  real_T TimeStampB_n;                 /* '<Root>/accRAD' */
  real_T LastUAtTimeB_c;               /* '<Root>/accRAD' */
  int64_T acc;                         /* '<Root>/WrapAround' */
  int32_T last_cnt;                    /* '<Root>/WrapAround' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/WrapAround' */
  boolean_T last_cnt_not_empty;        /* '<Root>/WrapAround' */
} DW_Encoder_reader_simulink_T;

/* Real-time Model Data Structure */
struct tag_RTM_Encoder_reader_simuli_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Encoder_reader_simulink_T Encoder_reader_simulink_B;

/* Block states (default storage) */
extern DW_Encoder_reader_simulink_T Encoder_reader_simulink_DW;

/* Model entry point functions */
extern void Encoder_reader_simulink_initialize(void);
extern void Encoder_reader_simulink_step(void);
extern void Encoder_reader_simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Encoder_reader_simul_T *const Encoder_reader_simulink_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Encoder_reader_simulink'
 * '<S1>'   : 'Encoder_reader_simulink/A'
 * '<S2>'   : 'Encoder_reader_simulink/B'
 * '<S3>'   : 'Encoder_reader_simulink/WrapAround'
 * '<S4>'   : 'Encoder_reader_simulink/input'
 * '<S5>'   : 'Encoder_reader_simulink/A/ECSoC'
 * '<S6>'   : 'Encoder_reader_simulink/A/ECSoC/ECSimCodegen'
 * '<S7>'   : 'Encoder_reader_simulink/B/ECSoC'
 * '<S8>'   : 'Encoder_reader_simulink/B/ECSoC/ECSimCodegen'
 * '<S9>'   : 'Encoder_reader_simulink/input/ECSoC'
 * '<S10>'  : 'Encoder_reader_simulink/input/ECSoC/ECSimCodegen'
 */
#endif                                 /* Encoder_reader_simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
