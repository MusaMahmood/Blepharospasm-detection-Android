//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: maximize_probs.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 04-Mar-2019 16:27:27
//
#ifndef MAXIMIZE_PROBS_H
#define MAXIMIZE_PROBS_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "maximize_probs_types.h"

// Function Declarations
extern void maximize_probs(const float X[6000], float max_prob[6000]);
extern void maximize_probs_initialize();
extern void maximize_probs_terminate();

#endif

//
// File trailer for maximize_probs.h
//
// [EOF]
//
