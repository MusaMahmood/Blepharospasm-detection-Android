//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: maximize_probs.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 04-Mar-2019 16:27:27
//

// Include Files
#include "rt_nonfinite.h"
#include "maximize_probs.h"

// Function Definitions

//
// Input = [2000, n], where n is the number of classes:
// Arguments    : const float X[6000]
//                float max_prob[6000]
// Return Type  : void
//
void maximize_probs(const float X[6000], float max_prob[6000])
{
  signed char b_max_prob[6000];
  int i;
  int ixstart;
  float mtmp;
  int itmp;
  int ix;
  boolean_T exitg1;
  memset(&b_max_prob[0], 0, 6000U * sizeof(signed char));
  for (i = 0; i < 2000; i++) {
    ixstart = 1;
    mtmp = X[i];
    itmp = 0;
    if (rtIsNaNF(X[i])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix < 4)) {
        ixstart = ix;
        if (!rtIsNaNF(X[i + 2000 * (ix - 1)])) {
          mtmp = X[i + 2000 * (ix - 1)];
          itmp = ix - 1;
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < 3) {
      while (ixstart + 1 < 4) {
        if (X[i + 2000 * ixstart] > mtmp) {
          mtmp = X[i + 2000 * ixstart];
          itmp = ixstart;
        }

        ixstart++;
      }
    }

    b_max_prob[i + 2000 * itmp] = 1;
  }

  for (i = 0; i < 6000; i++) {
    max_prob[i] = b_max_prob[i];
  }
}

//
// Arguments    : void
// Return Type  : void
//
void maximize_probs_initialize()
{
  rt_InitInfAndNaN(8U);
}

//
// Arguments    : void
// Return Type  : void
//
void maximize_probs_terminate()
{
  // (no terminate code required)
}

//
// File trailer for maximize_probs.cpp
//
// [EOF]
//
