/*
 * File: vdp.c
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

#include "vdp.h"
#include "vdp_private.h"

/* Block signals (default storage) */
B_vdp_T vdp_B;

/* Continuous states */
X_vdp_T vdp_X;

/* Block states (default storage) */
DW_vdp_T vdp_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_vdp_T vdp_Y;

/* Real-time model */
RT_MODEL_vdp_T vdp_M_;
RT_MODEL_vdp_T *const vdp_M = &vdp_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
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
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  vdp_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  vdp_step();
  vdp_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  vdp_step();
  vdp_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void vdp_step(void)
{
  if (rtmIsMajorTimeStep(vdp_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&vdp_M->solverInfo,((vdp_M->Timing.clockTick0+1)*
      vdp_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(vdp_M)) {
    vdp_M->Timing.t[0] = rtsiGetT(&vdp_M->solverInfo);
  }

  /* Integrator: '<Root>/x1' */
  vdp_B.x1 = vdp_X.x1_CSTATE;

  /* Outport: '<Root>/Out1' */
  vdp_Y.Out1 = vdp_B.x1;

  /* Integrator: '<Root>/x2' */
  vdp_B.x2 = vdp_X.x2_CSTATE;
  if (rtmIsMajorTimeStep(vdp_M)) {
  }

  /* Outport: '<Root>/Out2' */
  vdp_Y.Out2 = vdp_B.x2;

  /* Sum: '<Root>/Sum' incorporates:
   *  Fcn: '<Root>/Fcn'
   *  Gain: '<Root>/Mu'
   *  Product: '<Root>/Product'
   */
  vdp_B.Sum = (1.0 - vdp_B.x1 * vdp_B.x1) * vdp_B.x2 * 1.0 - vdp_B.x1;
  if (rtmIsMajorTimeStep(vdp_M)) {
    rt_ertODEUpdateContinuousStates(&vdp_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++vdp_M->Timing.clockTick0;
    vdp_M->Timing.t[0] = rtsiGetSolverStopTime(&vdp_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.4s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.4, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      vdp_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void vdp_derivatives(void)
{
  XDot_vdp_T *_rtXdot;
  _rtXdot = ((XDot_vdp_T *) vdp_M->derivs);

  /* Derivatives for Integrator: '<Root>/x1' */
  _rtXdot->x1_CSTATE = vdp_B.x2;

  /* Derivatives for Integrator: '<Root>/x2' */
  _rtXdot->x2_CSTATE = vdp_B.Sum;
}

/* Model initialize function */
void vdp_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)vdp_M, 0,
                sizeof(RT_MODEL_vdp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&vdp_M->solverInfo, &vdp_M->Timing.simTimeStep);
    rtsiSetTPtr(&vdp_M->solverInfo, &rtmGetTPtr(vdp_M));
    rtsiSetStepSizePtr(&vdp_M->solverInfo, &vdp_M->Timing.stepSize0);
    rtsiSetdXPtr(&vdp_M->solverInfo, &vdp_M->derivs);
    rtsiSetContStatesPtr(&vdp_M->solverInfo, (real_T **) &vdp_M->contStates);
    rtsiSetNumContStatesPtr(&vdp_M->solverInfo, &vdp_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&vdp_M->solverInfo,
      &vdp_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&vdp_M->solverInfo,
      &vdp_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&vdp_M->solverInfo,
      &vdp_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&vdp_M->solverInfo, (&rtmGetErrorStatus(vdp_M)));
    rtsiSetRTModelPtr(&vdp_M->solverInfo, vdp_M);
  }

  rtsiSetSimTimeStep(&vdp_M->solverInfo, MAJOR_TIME_STEP);
  vdp_M->intgData.y = vdp_M->odeY;
  vdp_M->intgData.f[0] = vdp_M->odeF[0];
  vdp_M->intgData.f[1] = vdp_M->odeF[1];
  vdp_M->intgData.f[2] = vdp_M->odeF[2];
  vdp_M->contStates = ((X_vdp_T *) &vdp_X);
  rtsiSetSolverData(&vdp_M->solverInfo, (void *)&vdp_M->intgData);
  rtsiSetSolverName(&vdp_M->solverInfo,"ode3");
  rtmSetTPtr(vdp_M, &vdp_M->Timing.tArray[0]);
  vdp_M->Timing.stepSize0 = 0.4;

  /* block I/O */
  {
    vdp_B.x1 = 0.0;
    vdp_B.x2 = 0.0;
    vdp_B.Sum = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&vdp_X, 0,
                  sizeof(X_vdp_T));
  }

  /* states (dwork) */
  (void) memset((void *)&vdp_DW, 0,
                sizeof(DW_vdp_T));

  /* external outputs */
  vdp_Y.Out1 = 0.0;
  vdp_Y.Out2 = 0.0;

  /* InitializeConditions for Integrator: '<Root>/x1' */
  vdp_X.x1_CSTATE = 2.0;

  /* InitializeConditions for Integrator: '<Root>/x2' */
  vdp_X.x2_CSTATE = 0.0;
}

/* Model terminate function */
void vdp_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
