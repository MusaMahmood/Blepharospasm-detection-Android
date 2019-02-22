//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsp_ftex.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 22-Feb-2019 01:40:35
//
#ifndef BSP_FTEX_H
#define BSP_FTEX_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "bsp_ftex_types.h"

// Function Declarations
extern void bsp_ftex(const double X[10000], double FT[7]);
extern void bsp_ftex_initialize();
extern void bsp_ftex_terminate();

#endif

//
// File trailer for bsp_ftex.h
//
// [EOF]
//
