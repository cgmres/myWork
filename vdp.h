/*
 * File: vdp.h
 *
 * Code generated for Simulink model 'vdp'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 10 11:52:59 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_vdp_h_
#define RTW_HEADER_vdp_h_
#include <string.h>
#ifndef vdp_COMMON_INCLUDES_
# define vdp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* vdp_COMMON_INCLUDES_ */

#include "vdp_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T x1;                           /* '<Root>/x1' */
  real_T x2;                           /* '<Root>/x2' */
  real_T Sum;                          /* '<Root>/Sum' */
} B_vdp_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_vdp_T;

/* Continuous states (default storage) */
typedef struct {
  real_T x1_CSTATE;                    /* '<Root>/x1' */
  real_T x2_CSTATE;                    /* '<Root>/x2' */
} X_vdp_T;

/* State derivatives (default storage) */
typedef struct {
  real_T x1_CSTATE;                    /* '<Root>/x1' */
  real_T x2_CSTATE;                    /* '<Root>/x2' */
} XDot_vdp_T;

/* State disabled  */
typedef struct {
  boolean_T x1_CSTATE;                 /* '<Root>/x1' */
  boolean_T x2_CSTATE;                 /* '<Root>/x2' */
} XDis_vdp_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
} ExtY_vdp_T;

/* Real-time Model Data Structure */
struct tag_RTM_vdp_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_vdp_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_vdp_T vdp_B;

/* Continuous states (default storage) */
extern X_vdp_T vdp_X;

/* Block states (default storage) */
extern DW_vdp_T vdp_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_vdp_T vdp_Y;

/* Model entry point functions */
extern void vdp_initialize(void);
extern void vdp_step(void);
extern void vdp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_vdp_T *const vdp_M;

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
 * '<Root>' : 'vdp'
 * '<S1>'   : 'vdp/More Info'
 * '<S2>'   : 'vdp/More Info/Model Info'
 */
#endif                                 /* RTW_HEADER_vdp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
