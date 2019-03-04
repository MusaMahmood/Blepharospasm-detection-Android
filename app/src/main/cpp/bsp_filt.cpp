//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsp_filt.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 04-Mar-2019 15:52:26
//

// Include Files
#include "rt_nonfinite.h"
#include "bsp_filt.h"

// Function Declarations
static void filter(double b[4], double a[4], const double x[2018], const double
                   zi[3], double y[2018]);
static void filtfilt(const double x_in[2000], double y_out[2000]);
static void flipud(double x[2018]);

// Function Definitions

//
// Arguments    : double b[4]
//                double a[4]
//                const double x[2018]
//                const double zi[3]
//                double y[2018]
// Return Type  : void
//
static void filter(double b[4], double a[4], const double x[2018], const double
                   zi[3], double y[2018])
{
  double a1;
  int k;
  int naxpy;
  int j;
  a1 = a[0];
  if ((!rtIsInf(a[0])) && (!rtIsNaN(a[0])) && (!(a[0] == 0.0)) && (a[0] != 1.0))
  {
    for (k = 0; k < 4; k++) {
      b[k] /= a1;
    }

    for (k = 0; k < 3; k++) {
      a[k + 1] /= a1;
    }

    a[0] = 1.0;
  }

  for (k = 0; k < 3; k++) {
    y[k] = zi[k];
  }

  memset(&y[3], 0, 2015U * sizeof(double));
  for (k = 0; k < 2018; k++) {
    naxpy = 2018 - k;
    if (!(naxpy < 4)) {
      naxpy = 4;
    }

    for (j = 0; j + 1 <= naxpy; j++) {
      y[k + j] += x[k] * b[j];
    }

    naxpy = 2017 - k;
    if (!(naxpy < 3)) {
      naxpy = 3;
    }

    a1 = -y[k];
    for (j = 1; j <= naxpy; j++) {
      y[k + j] += a1 * a[j];
    }
  }
}

//
// Arguments    : const double x_in[2000]
//                double y_out[2000]
// Return Type  : void
//
static void filtfilt(const double x_in[2000], double y_out[2000])
{
  double d0;
  double d1;
  int i;
  double y[2018];
  double dv0[4];
  static const double dv1[4] = { 0.994986058442272, -2.984958175326816,
    2.984958175326816, -0.994986058442272 };

  double dv2[4];
  static const double dv3[4] = { 1.0, -2.9899469140917359, 2.979944296951953,
    -0.989997256494488 };

  double b_y[2018];
  double a[3];
  static const double b_a[3] = { -0.9949860571238005, 1.9899721142608557,
    -0.99498605713698873 };

  d0 = 2.0 * x_in[0];
  d1 = 2.0 * x_in[1999];
  for (i = 0; i < 9; i++) {
    y[i] = d0 - x_in[9 - i];
  }

  memcpy(&y[9], &x_in[0], 2000U * sizeof(double));
  for (i = 0; i < 9; i++) {
    y[i + 2009] = d1 - x_in[1998 - i];
  }

  for (i = 0; i < 4; i++) {
    dv0[i] = dv1[i];
    dv2[i] = dv3[i];
  }

  for (i = 0; i < 3; i++) {
    a[i] = b_a[i] * y[0];
  }

  memcpy(&b_y[0], &y[0], 2018U * sizeof(double));
  filter(dv0, dv2, b_y, a, y);
  flipud(y);
  for (i = 0; i < 4; i++) {
    dv0[i] = dv1[i];
    dv2[i] = dv3[i];
  }

  for (i = 0; i < 3; i++) {
    a[i] = b_a[i] * y[0];
  }

  memcpy(&b_y[0], &y[0], 2018U * sizeof(double));
  filter(dv0, dv2, b_y, a, y);
  flipud(y);
  memcpy(&y_out[0], &y[9], 2000U * sizeof(double));
}

//
// Arguments    : double x[2018]
// Return Type  : void
//
static void flipud(double x[2018])
{
  int i;
  double xtmp;
  for (i = 0; i < 1009; i++) {
    xtmp = x[i];
    x[i] = x[2017 - i];
    x[2017 - i] = xtmp;
  }
}

//
// BSP_FILT Preprocessing for Tensorflow model:
//  Stage 1: Butterworth High pass @ 0.2 Hz, Order 3
//  Stage 2: Rescale ? [0, 1]
// Arguments    : const double X[2000]
//                float Y[2000]
// Return Type  : void
//
void bsp_filt(const double X[2000], float Y[2000])
{
  double X1[2000];
  int ixstart;
  double mtmp;
  int ix;
  boolean_T exitg1;
  double b_mtmp;
  filtfilt(X, X1);
  ixstart = 1;
  mtmp = X1[0];
  if (rtIsNaN(X1[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 2001)) {
      ixstart = ix;
      if (!rtIsNaN(X1[ix - 1])) {
        mtmp = X1[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 2000) {
    while (ixstart + 1 < 2001) {
      if (X1[ixstart] < mtmp) {
        mtmp = X1[ixstart];
      }

      ixstart++;
    }
  }

  ixstart = 1;
  b_mtmp = X1[0];
  if (rtIsNaN(X1[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 2001)) {
      ixstart = ix;
      if (!rtIsNaN(X1[ix - 1])) {
        b_mtmp = X1[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 2000) {
    while (ixstart + 1 < 2001) {
      if (X1[ixstart] > b_mtmp) {
        b_mtmp = X1[ixstart];
      }

      ixstart++;
    }
  }

  b_mtmp -= mtmp;
  for (ixstart = 0; ixstart < 2000; ixstart++) {
    Y[ixstart] = (float)((X1[ixstart] - mtmp) / b_mtmp);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void bsp_filt_initialize()
{
  rt_InitInfAndNaN(8U);
}

//
// Arguments    : void
// Return Type  : void
//
void bsp_filt_terminate()
{
  // (no terminate code required)
}

//
// File trailer for bsp_filt.cpp
//
// [EOF]
//
