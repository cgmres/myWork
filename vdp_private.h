/*
 * File: vdp_private.h
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

#ifndef RTW_HEADER_vdp_private_h_
#define RTW_HEADER_vdp_private_h_
#include "rtwtypes.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* private model entry point functions */
extern void vdp_derivatives(void);

#endif                                 /* RTW_HEADER_vdp_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
