//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: get_class_bleph.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 06-Sep-2018 13:20:58
//
#ifndef GET_CLASS_BLEPH_H
#define GET_CLASS_BLEPH_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "get_class_bleph_types.h"

// Function Declarations
extern void get_class_bleph_3c(const float input_array[6000], double *b_index,
                            float scores[3]);

extern void get_class_bleph(const float input_array[8000], double *b_index,
  float scores[4]);
extern void get_class_bleph_initialize();
extern void get_class_bleph_terminate();

#endif

//
// File trailer for get_class_bleph.h
//
// [EOF]
//
