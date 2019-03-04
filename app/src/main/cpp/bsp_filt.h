//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsp_filt.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 04-Mar-2019 15:52:26
//
#ifndef BSP_FILT_H
#define BSP_FILT_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "bsp_filt_types.h"

// Function Declarations
extern void bsp_filt(const double X[2000], float Y[2000]);
extern void bsp_filt_initialize();
extern void bsp_filt_terminate();

#endif

//
// File trailer for bsp_filt.h
//
// [EOF]
//
