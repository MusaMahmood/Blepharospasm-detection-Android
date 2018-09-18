//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: get_class_bleph.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 06-Sep-2018 14:34:17
//

// Include Files
#include "rt_nonfinite.h"
#include "get_class_bleph.h"

// Function Definitions

//
// get_class_bleph_3c - input a
//  input [2000, 3] class array
// Arguments    : const float input_array[6000]
//                double *b_index
//                float scores[3]
// Return Type  : void
//
void get_class_bleph_3c(const float input_array[6000], double *b_index, float scores[3]) {
    int ixstart;
    int xoffset;
    float s;
    int ix;
    boolean_T exitg1;
    for (ixstart = 0; ixstart < 3; ixstart++) {
        xoffset = ixstart * 2000;
        s = input_array[xoffset];
        for (ix = 0; ix < 1999; ix++) {
            s += input_array[(xoffset + ix) + 1];
        }

        scores[ixstart] = s;
    }

    ixstart = 1;
    s = scores[0];
    xoffset = 1;
    if (rtIsNaNF(scores[0])) {
        ix = 2;
        exitg1 = false;
        while ((!exitg1) && (ix < 4)) {
            ixstart = ix;
            if (!rtIsNaNF(scores[ix - 1])) {
                s = scores[ix - 1];
                xoffset = ix;
                exitg1 = true;
            } else {
                ix++;
            }
        }
    }

    if (ixstart < 3) {
        while (ixstart + 1 < 4) {
            if (scores[ixstart] > s) {
                s = scores[ixstart];
                xoffset = ixstart + 1;
            }

            ixstart++;
        }
    }

    *b_index = (double)xoffset - 1.0;
}

//
// get_class_bleph - input a
//  input [2000, 4] class array
// Arguments    : const float input_array[8000]
//                double *b_index
//                float scores[4]
// Return Type  : void
//
void get_class_bleph(const float input_array[8000], double *b_index, float
scores[4])
{
    int ixstart;
    int xoffset;
    float s;
    int ix;
    boolean_T exitg1;
    for (ixstart = 0; ixstart < 4; ixstart++) {
        xoffset = ixstart * 2000;
        s = input_array[xoffset];
        for (ix = 0; ix < 1999; ix++) {
            s += input_array[(xoffset + ix) + 1];
        }

        scores[ixstart] = s;
    }

    ixstart = 1;
    s = scores[0];
    xoffset = 1;
    if (rtIsNaNF(scores[0])) {
        ix = 2;
        exitg1 = false;
        while ((!exitg1) && (ix < 5)) {
            ixstart = ix;
            if (!rtIsNaNF(scores[ix - 1])) {
                s = scores[ix - 1];
                xoffset = ix;
                exitg1 = true;
            } else {
                ix++;
            }
        }
    }

    if (ixstart < 4) {
        while (ixstart + 1 < 5) {
            if (scores[ixstart] > s) {
                s = scores[ixstart];
                xoffset = ixstart + 1;
            }

            ixstart++;
        }
    }

    *b_index = (double)xoffset - 1.0;
}

//
// Arguments    : void
// Return Type  : void
//
void get_class_bleph_initialize()
{
    rt_InitInfAndNaN(8U);
}

//
// Arguments    : void
// Return Type  : void
//
void get_class_bleph_terminate()
{
    // (no terminate code required)
}

//
// File trailer for get_class_bleph.cpp
//
// [EOF]
//
