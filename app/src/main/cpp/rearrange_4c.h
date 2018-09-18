//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rearrange_4c.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 06-Sep-2018 14:32:41
//
#ifndef REARRANGE_4C_H
#define REARRANGE_4C_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "rearrange_4c_types.h"

// Function Declarations
extern void rearrange_4c(const float input_array[8000], float rearranged[8000]);
extern void rearrange_3c(const float input_array[6000], float rearranged[6000]);
extern void rearrange_4c_initialize();
extern void rearrange_4c_terminate();

#endif

//
// File trailer for rearrange_4c.h
//
// [EOF]
//
