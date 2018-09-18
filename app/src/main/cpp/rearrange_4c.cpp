//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rearrange_4c.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 06-Sep-2018 14:32:41
//

// Include Files
#include "rt_nonfinite.h"
#include "rearrange_4c.h"

// Function Definitions

//
// Arguments    : const float input_array[6000]
//                float rearranged[6000]
// Return Type  : void
//
void rearrange_3c(const float input_array[6000], float rearranged[6000])
{
  int i;
  int j;
  for (i = 0; i < 2000; i++) {
    for (j = 0; j < 3; j++) {
      rearranged[i + 2000 * j] = input_array[i * 3 + j];
    }
  }
}

//
// Arguments    : const float input_array[8000]
//                float rearranged[8000]
// Return Type  : void
//
void rearrange_4c(const float input_array[8000], float rearranged[8000])
{
  int i;
  int j;
  for (i = 0; i < 2000; i++) {
    for (j = 0; j < 4; j++) {
      rearranged[i + 2000 * j] = input_array[(i << 2) + j];
    }
  }
}

//
// Arguments    : void
// Return Type  : void
//
void rearrange_4c_initialize()
{
  rt_InitInfAndNaN(8U);
}

//
// Arguments    : void
// Return Type  : void
//
void rearrange_4c_terminate()
{
  // (no terminate code required)
}

//
// File trailer for rearrange_4c.cpp
//
// [EOF]
//
