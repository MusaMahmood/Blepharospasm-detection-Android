//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsp_ftex_emxutil.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 22-Feb-2019 01:40:35
//
#ifndef BSP_FTEX_EMXUTIL_H
#define BSP_FTEX_EMXUTIL_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "bsp_ftex_types.h"

// Function Declarations
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, unsigned
  int elementSize);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_real_T1(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for bsp_ftex_emxutil.h
//
// [EOF]
//
