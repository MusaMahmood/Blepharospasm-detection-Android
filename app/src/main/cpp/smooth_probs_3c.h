//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: smooth_probs_3c.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 04-Mar-2019 16:19:36
//
#ifndef SMOOTH_PROBS_3C_H
#define SMOOTH_PROBS_3C_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "smooth_probs_3c_types.h"

// Function Declarations
extern void smooth_probs_3c(const float max_prob[6000], float max_prob_smoothed
  [10000]);
extern void smooth_probs_3c_initialize();
extern void smooth_probs_3c_terminate();

#endif

//
// File trailer for smooth_probs_3c.h
//
// [EOF]
//
