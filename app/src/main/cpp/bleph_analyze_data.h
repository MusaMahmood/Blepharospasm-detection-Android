//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bleph_analyze_data.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 18-Sep-2018 17:05:52
//
#ifndef BLEPH_ANALYZE_DATA_H
#define BLEPH_ANALYZE_DATA_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "bleph_analyze_data_types.h"

// Function Declarations
extern void bleph_analyze_data(const float classifyIn_concat[480], double count
  [3], double symptoms[4]);
extern void bleph_analyze_data_initialize();
extern void bleph_analyze_data_terminate();

#endif

//
// File trailer for bleph_analyze_data.h
//
// [EOF]
//
