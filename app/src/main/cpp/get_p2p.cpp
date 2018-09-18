//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: get_p2p.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 07-Sep-2018 10:19:32
//

// Include Files
#include "rt_nonfinite.h"
#include "get_p2p.h"

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
  static const double dv1[4] = { 0.975179811634754, -2.9255394349042629,
    2.9255394349042629, -0.975179811634754 };

  double dv2[4];
  static const double dv3[4] = { 1.0, -2.949735839706348, 2.9007269883554381,
    -0.950975665016249 };

  double b_y[2018];
  double a[3];
  static const double b_a[3] = { -0.97517981162796985, 1.9503596232562816,
    -0.97517981162830258 };

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
// GET_P2P
//  Input raw 2000, 1 array
//  runs filter [bh, ah] = butter(3, 1*2/250, 'high'); % Fs = 250 Hz for this one.
//  gets p2p
// Arguments    : const double X[2000]
// Return Type  : double
//
double get_p2p(const double X[2000])
{
  double y[2000];
  int ixstart;
  double mtmp;
  int ix;
  boolean_T exitg1;
  double b_mtmp;
  filtfilt(X, y);
  ixstart = 1;
  mtmp = y[0];
  if (rtIsNaN(y[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 2001)) {
      ixstart = ix;
      if (!rtIsNaN(y[ix - 1])) {
        mtmp = y[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 2000) {
    while (ixstart + 1 < 2001) {
      if (y[ixstart] > mtmp) {
        mtmp = y[ixstart];
      }

      ixstart++;
    }
  }

  ixstart = 1;
  b_mtmp = y[0];
  if (rtIsNaN(y[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 2001)) {
      ixstart = ix;
      if (!rtIsNaN(y[ix - 1])) {
        b_mtmp = y[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 2000) {
    while (ixstart + 1 < 2001) {
      if (y[ixstart] < b_mtmp) {
        b_mtmp = y[ixstart];
      }

      ixstart++;
    }
  }

  return mtmp - b_mtmp;
}

//
// Arguments    : void
// Return Type  : void
//
void get_p2p_initialize()
{
  rt_InitInfAndNaN(8U);
}

//
// Arguments    : void
// Return Type  : void
//
void get_p2p_terminate()
{
  // (no terminate code required)
}

//
// File trailer for get_p2p.cpp
//
// [EOF]
//
