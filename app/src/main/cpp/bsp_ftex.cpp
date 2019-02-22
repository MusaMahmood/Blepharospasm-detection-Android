//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsp_ftex.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 22-Feb-2019 01:40:35
//

// Include Files
#include "rt_nonfinite.h"
#include "bsp_ftex.h"
#include "bsp_ftex_emxutil.h"

// Function Declarations
static void assignFullOutputs(const double y[10000], const emxArray_int32_T *iPk,
  const emxArray_real_T *wxPk, const emxArray_real_T *bPk, emxArray_real_T
  *YpkOut, emxArray_real_T *XpkOut, emxArray_real_T *WpkOut, emxArray_real_T
  *PpkOut);
static void b_do_vectors(const emxArray_int32_T *a, const int b_data[], const
  int b_size[1], int c_data[], int c_size[1], int ia_data[], int ia_size[1], int
  ib_data[], int ib_size[1]);
static void b_filtfilt(const double x_in[10000], double y_out[10000]);
static void b_flipud(int x_data[], int x_size[1]);
static void c_findPeaksSeparatedByMoreThanM(const emxArray_int32_T *iPk,
  emxArray_int32_T *idx);
static void c_removePeaksBelowMinPeakPromin(const double y[10000], int iPk_data[],
  int iPk_size[1], emxArray_real_T *pbPk, int iLB_data[], int iLB_size[1], int
  iRB_data[], int iRB_size[1]);
static void combineFullPeaks(const double y[10000], const int iPk_data[], const
  int iPk_size[1], const emxArray_real_T *bPk, const int iLBw_data[], const int
  iLBw_size[1], const int iRBw_data[], const int iRBw_size[1], const
  emxArray_real_T *wPk, const int iInf_data[], const int iInf_size[1],
  emxArray_int32_T *iPkOut, emxArray_real_T *bPkOut, emxArray_real_T *bxPkOut,
  emxArray_real_T *byPkOut, emxArray_real_T *wxPkOut);
static void diff(const emxArray_real_T *x, emxArray_real_T *y);
static void do_vectors(const int a_data[], const int a_size[1], const int
  b_data[], const int b_size[1], emxArray_int32_T *c, int ia_data[], int
  ia_size[1], int ib_data[], int ib_size[1]);
static void fetchPeakExtents(const emxArray_int32_T *idx, emxArray_real_T *bPk,
  emxArray_real_T *bxPk, emxArray_real_T *byPk, emxArray_real_T *wxPk);
static void filter(const double b[4], const double a[4], const double x[10018],
                   const double zi[3], double y[10018]);
static void filtfilt(const double x_in[10000], double y_out[10000]);
static void findExtents(const double y[10000], emxArray_int32_T *iPk, const int
  iFin_data[], const int iFin_size[1], const int iInf_data[], const int
  iInf_size[1], const int iInflect_data[], const int iInflect_size[1],
  emxArray_real_T *bPk, emxArray_real_T *bxPk, emxArray_real_T *byPk,
  emxArray_real_T *wxPk);
static void findLeftIntercept(const double y[10000], int *idx, int borderIdx,
  double refHeight);
static void findRightIntercept(const double y[10000], int *idx, int borderIdx,
  double refHeight);
static void findpeaks(const double Yin[10000], emxArray_real_T *Ypk,
                      emxArray_real_T *Xpk, emxArray_real_T *Wpk);
static void flipud(double x[10018]);
static void getAllPeaksCodegen(const double y[10000], int iPk_data[], int
  iPk_size[1], int iInf_data[], int iInf_size[1], int iInflect_data[], int
  iInflect_size[1]);
static void getHalfMaxBounds(const double y[10000], const int iPk_data[], const
  int iPk_size[1], const int iLB_data[], const int iRB_data[], emxArray_real_T
  *bounds);
static void getLeftBase(const double yTemp[10000], const int iPeak_data[], const
  int iPeak_size[1], const int iFinite_data[], const int iFinite_size[1], const
  int iInflect_data[], int iBase_data[], int iBase_size[1], int iSaddle_data[],
  int iSaddle_size[1]);
static void getPeakBase(const double yTemp[10000], const int iPk_data[], const
  int iPk_size[1], const int iFin_data[], const int iFin_size[1], const int
  iInflect_data[], const int iInflect_size[1], emxArray_real_T *peakBase, int
  iLeftSaddle_data[], int iLeftSaddle_size[1], int iRightSaddle_data[], int
  iRightSaddle_size[1]);
static void getPeakWidth(const double y[10000], const int iPk_data[], const int
  iPk_size[1], const int iLB_data[], const int iLB_size[1], const int iRB_data[],
  const int iRB_size[1], emxArray_real_T *wxPk, int iLBh_data[], int iLBh_size[1],
  int iRBh_data[], int iRBh_size[1]);
static void keepAtMostNpPeaks(emxArray_int32_T *idx);
static double linterp(double xa, double xb, double ya, double yb, double yc);
static double mean(const emxArray_real_T *x);
static void removeSmallPeaks(const double y[10000], const int iFinite_data[],
  const int iFinite_size[1], int iPk_data[], int iPk_size[1]);
static void rescale_minmax(const double X[10000], double Y[10000]);

// Function Definitions

//
// Arguments    : const double y[10000]
//                const emxArray_int32_T *iPk
//                const emxArray_real_T *wxPk
//                const emxArray_real_T *bPk
//                emxArray_real_T *YpkOut
//                emxArray_real_T *XpkOut
//                emxArray_real_T *WpkOut
//                emxArray_real_T *PpkOut
// Return Type  : void
//
static void assignFullOutputs(const double y[10000], const emxArray_int32_T *iPk,
  const emxArray_real_T *wxPk, const emxArray_real_T *bPk, emxArray_real_T
  *YpkOut, emxArray_real_T *XpkOut, emxArray_real_T *WpkOut, emxArray_real_T
  *PpkOut)
{
  int i5;
  int loop_ub;
  emxArray_real_T *r4;
  i5 = YpkOut->size[0];
  YpkOut->size[0] = iPk->size[0];
  emxEnsureCapacity((emxArray__common *)YpkOut, i5, sizeof(double));
  loop_ub = iPk->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    YpkOut->data[i5] = y[iPk->data[i5] - 1];
  }

  emxInit_real_T(&r4, 1);
  i5 = r4->size[0];
  r4->size[0] = iPk->size[0];
  emxEnsureCapacity((emxArray__common *)r4, i5, sizeof(double));
  loop_ub = iPk->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    r4->data[i5] = (short)(1 + (short)(iPk->data[i5] - 1));
  }

  i5 = XpkOut->size[0];
  XpkOut->size[0] = r4->size[0];
  emxEnsureCapacity((emxArray__common *)XpkOut, i5, sizeof(double));
  loop_ub = r4->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    XpkOut->data[i5] = r4->data[i5];
  }

  emxFree_real_T(&r4);
  diff(wxPk, WpkOut);
  i5 = PpkOut->size[0];
  PpkOut->size[0] = YpkOut->size[0];
  emxEnsureCapacity((emxArray__common *)PpkOut, i5, sizeof(double));
  loop_ub = YpkOut->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    PpkOut->data[i5] = YpkOut->data[i5] - bPk->data[i5];
  }
}

//
// Arguments    : const emxArray_int32_T *a
//                const int b_data[]
//                const int b_size[1]
//                int c_data[]
//                int c_size[1]
//                int ia_data[]
//                int ia_size[1]
//                int ib_data[]
//                int ib_size[1]
// Return Type  : void
//
static void b_do_vectors(const emxArray_int32_T *a, const int b_data[], const
  int b_size[1], int c_data[], int c_size[1], int ia_data[], int ia_size[1], int
  ib_data[], int ib_size[1])
{
  int iafirst;
  int ncmax;
  int nc;
  int ialast;
  int ibfirst;
  int iblast;
  int b_ialast;
  int ak;
  int b_iblast;
  int b_ia_data[10000];
  int bk;
  iafirst = a->size[0];
  ncmax = b_size[0];
  if (iafirst < ncmax) {
    ncmax = iafirst;
  }

  c_size[0] = (short)ncmax;
  ia_size[0] = ncmax;
  ib_size[0] = ncmax;
  nc = 0;
  iafirst = 0;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= a->size[0]) && (iblast <= b_size[0])) {
    b_ialast = ialast;
    ak = a->data[ialast - 1];
    while ((b_ialast < a->size[0]) && (a->data[b_ialast] == ak)) {
      b_ialast++;
    }

    ialast = b_ialast;
    b_iblast = iblast;
    bk = b_data[iblast - 1];
    while ((b_iblast < b_size[0]) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }

    iblast = b_iblast;
    if (ak == bk) {
      nc++;
      c_data[nc - 1] = ak;
      ia_data[nc - 1] = iafirst + 1;
      ib_data[nc - 1] = ibfirst + 1;
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
    } else {
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    }
  }

  if (ncmax > 0) {
    if (1 > nc) {
      iafirst = 0;
    } else {
      iafirst = nc;
    }

    for (ialast = 0; ialast < iafirst; ialast++) {
      b_ia_data[ialast] = ia_data[ialast];
    }

    ia_size[0] = iafirst;
    for (ialast = 0; ialast < iafirst; ialast++) {
      ia_data[ialast] = b_ia_data[ialast];
    }

    if (1 > nc) {
      iafirst = 0;
    } else {
      iafirst = nc;
    }

    for (ialast = 0; ialast < iafirst; ialast++) {
      b_ia_data[ialast] = ib_data[ialast];
    }

    ib_size[0] = iafirst;
    for (ialast = 0; ialast < iafirst; ialast++) {
      ib_data[ialast] = b_ia_data[ialast];
    }

    if (1 > nc) {
      iafirst = 0;
    } else {
      iafirst = nc;
    }

    for (ialast = 0; ialast < iafirst; ialast++) {
      b_ia_data[ialast] = c_data[ialast];
    }

    c_size[0] = iafirst;
    for (ialast = 0; ialast < iafirst; ialast++) {
      c_data[ialast] = b_ia_data[ialast];
    }
  }
}

//
// Arguments    : const double x_in[10000]
//                double y_out[10000]
// Return Type  : void
//
static void b_filtfilt(const double x_in[10000], double y_out[10000])
{
  double d2;
  double d3;
  int i;
  static double y[10018];
  double b_y[10018];
  double a[3];
  static const double b_a[3] = { 0.99935717524067524, -1.6371358449653239,
    0.69383535406560293 };

  static const double dv3[4] = { 0.000642824759458871, 0.001928474278377,
    0.001928474278377, 0.000642824759458871 };

  static const double dv4[4] = { 1.0, -2.6345645459272689, 2.3328996733089911,
    -0.693192529306051 };

  d2 = 2.0 * x_in[0];
  d3 = 2.0 * x_in[9999];
  for (i = 0; i < 9; i++) {
    y[i] = d2 - x_in[9 - i];
  }

  memcpy(&y[9], &x_in[0], 10000U * sizeof(double));
  for (i = 0; i < 9; i++) {
    y[i + 10009] = d3 - x_in[9998 - i];
  }

  for (i = 0; i < 3; i++) {
    a[i] = b_a[i] * y[0];
  }

  memcpy(&b_y[0], &y[0], 10018U * sizeof(double));
  filter(dv3, dv4, b_y, a, y);
  flipud(y);
  for (i = 0; i < 3; i++) {
    a[i] = b_a[i] * y[0];
  }

  memcpy(&b_y[0], &y[0], 10018U * sizeof(double));
  filter(dv3, dv4, b_y, a, y);
  flipud(y);
  memcpy(&y_out[0], &y[9], 10000U * sizeof(double));
}

//
// Arguments    : int x_data[]
//                int x_size[1]
// Return Type  : void
//
static void b_flipud(int x_data[], int x_size[1])
{
  int m;
  int md2;
  int i;
  int xtmp;
  m = x_size[0];
  md2 = x_size[0] >> 1;
  for (i = 1; i <= md2; i++) {
    xtmp = x_data[i - 1];
    x_data[i - 1] = x_data[m - i];
    x_data[m - i] = xtmp;
  }
}

//
// Arguments    : const emxArray_int32_T *iPk
//                emxArray_int32_T *idx
// Return Type  : void
//
static void c_findPeaksSeparatedByMoreThanM(const emxArray_int32_T *iPk,
  emxArray_int32_T *idx)
{
  emxArray_int32_T *y;
  int bi;
  int n;
  int k;
  emxInit_int32_T1(&y, 2);
  bi = iPk->size[0];
  if (bi < 1) {
    n = 0;
  } else {
    n = bi;
  }

  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity((emxArray__common *)y, k, sizeof(int));
  if (n > 0) {
    y->data[0] = 1;
    bi = 1;
    for (k = 2; k <= n; k++) {
      bi++;
      y->data[k - 1] = bi;
    }
  }

  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, k, sizeof(int));
  bi = y->size[1];
  for (k = 0; k < bi; k++) {
    idx->data[k] = y->data[y->size[0] * k];
  }

  emxFree_int32_T(&y);
}

//
// Arguments    : const double y[10000]
//                int iPk_data[]
//                int iPk_size[1]
//                emxArray_real_T *pbPk
//                int iLB_data[]
//                int iLB_size[1]
//                int iRB_data[]
//                int iRB_size[1]
// Return Type  : void
//
static void c_removePeaksBelowMinPeakPromin(const double y[10000], int iPk_data[],
  int iPk_size[1], emxArray_real_T *pbPk, int iLB_data[], int iLB_size[1], int
  iRB_data[], int iRB_size[1])
{
  int x_size_idx_0;
  int idx;
  int ii;
  boolean_T x_data[10000];
  boolean_T exitg1;
  int ii_data[10000];
  int idx_data[10000];
  emxArray_real_T *b_pbPk;
  x_size_idx_0 = iPk_size[0];
  idx = iPk_size[0];
  for (ii = 0; ii < idx; ii++) {
    x_data[ii] = (y[iPk_data[ii] - 1] - pbPk->data[ii] >= 0.15);
  }

  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= x_size_idx_0)) {
    if (x_data[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= x_size_idx_0) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (x_size_idx_0 == 1) {
    if (idx == 0) {
      x_size_idx_0 = 0;
    }
  } else if (1 > idx) {
    x_size_idx_0 = 0;
  } else {
    x_size_idx_0 = idx;
  }

  for (ii = 0; ii < x_size_idx_0; ii++) {
    idx_data[ii] = ii_data[ii];
  }

  for (ii = 0; ii < x_size_idx_0; ii++) {
    ii_data[ii] = iPk_data[idx_data[ii] - 1];
  }

  iPk_size[0] = x_size_idx_0;
  for (ii = 0; ii < x_size_idx_0; ii++) {
    iPk_data[ii] = ii_data[ii];
  }

  emxInit_real_T(&b_pbPk, 1);
  ii = b_pbPk->size[0];
  b_pbPk->size[0] = x_size_idx_0;
  emxEnsureCapacity((emxArray__common *)b_pbPk, ii, sizeof(double));
  for (ii = 0; ii < x_size_idx_0; ii++) {
    b_pbPk->data[ii] = pbPk->data[idx_data[ii] - 1];
  }

  ii = pbPk->size[0];
  pbPk->size[0] = b_pbPk->size[0];
  emxEnsureCapacity((emxArray__common *)pbPk, ii, sizeof(double));
  idx = b_pbPk->size[0];
  for (ii = 0; ii < idx; ii++) {
    pbPk->data[ii] = b_pbPk->data[ii];
  }

  emxFree_real_T(&b_pbPk);
  for (ii = 0; ii < x_size_idx_0; ii++) {
    ii_data[ii] = iLB_data[idx_data[ii] - 1];
  }

  iLB_size[0] = x_size_idx_0;
  for (ii = 0; ii < x_size_idx_0; ii++) {
    iLB_data[ii] = ii_data[ii];
  }

  for (ii = 0; ii < x_size_idx_0; ii++) {
    ii_data[ii] = iRB_data[idx_data[ii] - 1];
  }

  iRB_size[0] = x_size_idx_0;
  for (ii = 0; ii < x_size_idx_0; ii++) {
    iRB_data[ii] = ii_data[ii];
  }
}

//
// Arguments    : const double y[10000]
//                const int iPk_data[]
//                const int iPk_size[1]
//                const emxArray_real_T *bPk
//                const int iLBw_data[]
//                const int iLBw_size[1]
//                const int iRBw_data[]
//                const int iRBw_size[1]
//                const emxArray_real_T *wPk
//                const int iInf_data[]
//                const int iInf_size[1]
//                emxArray_int32_T *iPkOut
//                emxArray_real_T *bPkOut
//                emxArray_real_T *bxPkOut
//                emxArray_real_T *byPkOut
//                emxArray_real_T *wxPkOut
// Return Type  : void
//
static void combineFullPeaks(const double y[10000], const int iPk_data[], const
  int iPk_size[1], const emxArray_real_T *bPk, const int iLBw_data[], const int
  iLBw_size[1], const int iRBw_data[], const int iRBw_size[1], const
  emxArray_real_T *wPk, const int iInf_data[], const int iInf_size[1],
  emxArray_int32_T *iPkOut, emxArray_real_T *bPkOut, emxArray_real_T *bxPkOut,
  emxArray_real_T *byPkOut, emxArray_real_T *wxPkOut)
{
  static int ia_data[10000];
  int ia_size[1];
  static int iInfR_data[10000];
  int iInfR_size[1];
  static int iInfL_data[10000];
  int iInfL_size[1];
  int loop_ub;
  int i4;
  int iFinite_data[10000];
  int iInfinite_data[10000];
  short unnamed_idx_0;
  int u0;
  emxArray_real_T *r2;
  emxArray_real_T *r3;
  do_vectors(iPk_data, iPk_size, iInf_data, iInf_size, iPkOut, ia_data, ia_size,
             iInfR_data, iInfR_size);
  b_do_vectors(iPkOut, iPk_data, iPk_size, iInfL_data, iInfL_size, ia_data,
               ia_size, iInfR_data, iInfR_size);
  loop_ub = ia_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    iFinite_data[i4] = ia_data[i4];
  }

  b_do_vectors(iPkOut, iInf_data, iInf_size, iInfL_data, iInfL_size, ia_data,
               ia_size, iInfR_data, iInfR_size);
  loop_ub = ia_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    iInfinite_data[i4] = ia_data[i4];
  }

  loop_ub = iPkOut->size[0];
  i4 = iPkOut->size[0];
  iPkOut->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)iPkOut, i4, sizeof(int));
  unnamed_idx_0 = (short)iPkOut->size[0];
  i4 = bPkOut->size[0];
  bPkOut->size[0] = unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)bPkOut, i4, sizeof(double));
  loop_ub = unnamed_idx_0;
  for (i4 = 0; i4 < loop_ub; i4++) {
    bPkOut->data[i4] = 0.0;
  }

  loop_ub = bPk->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    bPkOut->data[iFinite_data[i4] - 1] = bPk->data[i4];
  }

  loop_ub = ia_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    ia_data[i4] = iInfinite_data[i4];
  }

  loop_ub = ia_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    bPkOut->data[ia_data[i4] - 1] = 0.0;
  }

  loop_ub = iInf_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    ia_data[i4] = iInf_data[i4] - 1;
  }

  for (loop_ub = 0; loop_ub + 1 <= (short)iInf_size[0]; loop_ub++) {
    if (ia_data[loop_ub] < 1) {
      iInfL_data[loop_ub] = 1;
    } else {
      iInfL_data[loop_ub] = ia_data[loop_ub];
    }
  }

  loop_ub = iInf_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    ia_data[i4] = iInf_data[i4] + 1;
  }

  for (loop_ub = 0; loop_ub + 1 <= (short)iInf_size[0]; loop_ub++) {
    u0 = ia_data[loop_ub];
    if (!(u0 < 10000)) {
      u0 = 10000;
    }

    iInfR_data[loop_ub] = u0;
  }

  i4 = bxPkOut->size[0] * bxPkOut->size[1];
  bxPkOut->size[0] = iPkOut->size[0];
  bxPkOut->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)bxPkOut, i4, sizeof(double));
  loop_ub = iPkOut->size[0] << 1;
  for (i4 = 0; i4 < loop_ub; i4++) {
    bxPkOut->data[i4] = 0.0;
  }

  emxInit_real_T(&r2, 1);
  i4 = r2->size[0];
  r2->size[0] = iLBw_size[0];
  emxEnsureCapacity((emxArray__common *)r2, i4, sizeof(double));
  loop_ub = iLBw_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    r2->data[i4] = (short)(1 + (short)(iLBw_data[i4] - 1));
  }

  loop_ub = r2->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    bxPkOut->data[iFinite_data[i4] - 1] = r2->data[i4];
  }

  emxFree_real_T(&r2);
  emxInit_real_T(&r3, 1);
  i4 = r3->size[0];
  r3->size[0] = iRBw_size[0];
  emxEnsureCapacity((emxArray__common *)r3, i4, sizeof(double));
  loop_ub = iRBw_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    r3->data[i4] = (short)(1 + (short)(iRBw_data[i4] - 1));
  }

  loop_ub = r3->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    bxPkOut->data[(iFinite_data[i4] + bxPkOut->size[0]) - 1] = r3->data[i4];
  }

  emxFree_real_T(&r3);
  loop_ub = iInf_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    bxPkOut->data[iInfinite_data[i4] - 1] = 0.5 * (double)(short)((short)((short)
      (iInf_data[i4] - 1) + (short)(iInfL_data[i4] - 1)) + 2);
  }

  loop_ub = iInf_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    bxPkOut->data[(iInfinite_data[i4] + bxPkOut->size[0]) - 1] = 0.5 * (double)
      (short)((short)((short)(iInf_data[i4] - 1) + (short)(iInfR_data[i4] - 1))
              + 2);
  }

  i4 = byPkOut->size[0] * byPkOut->size[1];
  byPkOut->size[0] = iPkOut->size[0];
  byPkOut->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)byPkOut, i4, sizeof(double));
  loop_ub = iPkOut->size[0] << 1;
  for (i4 = 0; i4 < loop_ub; i4++) {
    byPkOut->data[i4] = 0.0;
  }

  loop_ub = iLBw_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    byPkOut->data[iFinite_data[i4] - 1] = y[iLBw_data[i4] - 1];
  }

  loop_ub = iRBw_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    byPkOut->data[(iFinite_data[i4] + byPkOut->size[0]) - 1] = y[iRBw_data[i4] -
      1];
  }

  loop_ub = (short)iInf_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    byPkOut->data[iInfinite_data[i4] - 1] = y[iInfL_data[i4] - 1];
  }

  loop_ub = (short)iInf_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    byPkOut->data[(iInfinite_data[i4] + byPkOut->size[0]) - 1] = y[iInfR_data[i4]
      - 1];
  }

  i4 = wxPkOut->size[0] * wxPkOut->size[1];
  wxPkOut->size[0] = iPkOut->size[0];
  wxPkOut->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)wxPkOut, i4, sizeof(double));
  loop_ub = iPkOut->size[0] << 1;
  for (i4 = 0; i4 < loop_ub; i4++) {
    wxPkOut->data[i4] = 0.0;
  }

  for (i4 = 0; i4 < 2; i4++) {
    loop_ub = wPk->size[0];
    for (u0 = 0; u0 < loop_ub; u0++) {
      wxPkOut->data[(iFinite_data[u0] + wxPkOut->size[0] * i4) - 1] = wPk->
        data[u0 + wPk->size[0] * i4];
    }
  }

  loop_ub = iInf_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    wxPkOut->data[iInfinite_data[i4] - 1] = 0.5 * (double)(short)((short)((short)
      (iInf_data[i4] - 1) + (short)(iInfL_data[i4] - 1)) + 2);
  }

  loop_ub = iInf_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    wxPkOut->data[(iInfinite_data[i4] + wxPkOut->size[0]) - 1] = 0.5 * (double)
      (short)((short)((short)(iInf_data[i4] - 1) + (short)(iInfR_data[i4] - 1))
              + 2);
  }
}

//
// Arguments    : const emxArray_real_T *x
//                emxArray_real_T *y
// Return Type  : void
//
static void diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  int stride;
  int ix;
  int iy;
  int s;
  stride = y->size[0];
  y->size[0] = (short)x->size[0];
  emxEnsureCapacity((emxArray__common *)y, stride, sizeof(double));
  if (!(y->size[0] == 0)) {
    stride = x->size[0];
    ix = 0;
    iy = 0;
    for (s = 1; s <= stride; s++) {
      y->data[iy] = x->data[ix + stride] - x->data[ix];
      ix++;
      iy++;
    }
  }
}

//
// Arguments    : const int a_data[]
//                const int a_size[1]
//                const int b_data[]
//                const int b_size[1]
//                emxArray_int32_T *c
//                int ia_data[]
//                int ia_size[1]
//                int ib_data[]
//                int ib_size[1]
// Return Type  : void
//
static void do_vectors(const int a_data[], const int a_size[1], const int
  b_data[], const int b_size[1], emxArray_int32_T *c, int ia_data[], int
  ia_size[1], int ib_data[], int ib_size[1])
{
  int na;
  int nb;
  int ncmax;
  int ialast;
  int nc;
  int nia;
  int nib;
  int iafirst;
  int ibfirst;
  int iblast;
  int b_ialast;
  int ak;
  int b_iblast;
  int bk;
  int b_ia_data[10000];
  emxArray_int32_T *b_c;
  short b_ib_data[10000];
  na = a_size[0];
  nb = b_size[0];
  ncmax = a_size[0] + b_size[0];
  ialast = c->size[0];
  c->size[0] = (short)ncmax;
  emxEnsureCapacity((emxArray__common *)c, ialast, sizeof(int));
  ia_size[0] = a_size[0];
  ib_size[0] = b_size[0];
  nc = -1;
  nia = -1;
  nib = 0;
  iafirst = 1;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= na) && (iblast <= nb)) {
    b_ialast = ialast;
    ak = a_data[ialast - 1];
    while ((b_ialast < a_size[0]) && (a_data[b_ialast] == ak)) {
      b_ialast++;
    }

    ialast = b_ialast;
    b_iblast = iblast;
    bk = b_data[iblast - 1];
    while ((b_iblast < b_size[0]) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }

    iblast = b_iblast;
    if (ak == bk) {
      nc++;
      c->data[nc] = ak;
      nia++;
      ia_data[nia] = iafirst;
      ialast = b_ialast + 1;
      iafirst = b_ialast + 1;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      nc++;
      nia++;
      c->data[nc] = ak;
      ia_data[nia] = iafirst;
      ialast = b_ialast + 1;
      iafirst = b_ialast + 1;
    } else {
      nc++;
      nib++;
      c->data[nc] = bk;
      ib_data[nib - 1] = ibfirst + 1;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    }
  }

  while (ialast <= na) {
    b_ialast = ialast;
    while ((b_ialast < a_size[0]) && (a_data[b_ialast] == a_data[ialast - 1])) {
      b_ialast++;
    }

    nc++;
    nia++;
    c->data[nc] = a_data[ialast - 1];
    ia_data[nia] = ialast;
    ialast = b_ialast + 1;
  }

  while (iblast <= nb) {
    b_iblast = iblast;
    while ((b_iblast < b_size[0]) && (b_data[b_iblast] == b_data[iblast - 1])) {
      b_iblast++;
    }

    nc++;
    nib++;
    c->data[nc] = b_data[iblast - 1];
    ib_data[nib - 1] = iblast;
    iblast = b_iblast + 1;
  }

  if (a_size[0] > 0) {
    if (1 > nia + 1) {
      iafirst = -1;
    } else {
      iafirst = nia;
    }

    for (ialast = 0; ialast <= iafirst; ialast++) {
      b_ia_data[ialast] = ia_data[ialast];
    }

    ia_size[0] = iafirst + 1;
    iafirst++;
    for (ialast = 0; ialast < iafirst; ialast++) {
      ia_data[ialast] = b_ia_data[ialast];
    }
  }

  if (b_size[0] > 0) {
    if (1 > nib) {
      iafirst = 0;
    } else {
      iafirst = nib;
    }

    nia = ib_size[0];
    for (ialast = 0; ialast < nia; ialast++) {
      b_ib_data[ialast] = (short)ib_data[ialast];
    }

    ib_size[0] = iafirst;
    for (ialast = 0; ialast < iafirst; ialast++) {
      ib_data[ialast] = b_ib_data[ialast];
    }
  }

  if (ncmax > 0) {
    if (1 > nc + 1) {
      iafirst = -1;
    } else {
      iafirst = nc;
    }

    emxInit_int32_T(&b_c, 1);
    ialast = b_c->size[0];
    b_c->size[0] = iafirst + 1;
    emxEnsureCapacity((emxArray__common *)b_c, ialast, sizeof(int));
    for (ialast = 0; ialast <= iafirst; ialast++) {
      b_c->data[ialast] = c->data[ialast];
    }

    ialast = c->size[0];
    c->size[0] = b_c->size[0];
    emxEnsureCapacity((emxArray__common *)c, ialast, sizeof(int));
    iafirst = b_c->size[0];
    for (ialast = 0; ialast < iafirst; ialast++) {
      c->data[ialast] = b_c->data[ialast];
    }

    emxFree_int32_T(&b_c);
  }
}

//
// Arguments    : const emxArray_int32_T *idx
//                emxArray_real_T *bPk
//                emxArray_real_T *bxPk
//                emxArray_real_T *byPk
//                emxArray_real_T *wxPk
// Return Type  : void
//
static void fetchPeakExtents(const emxArray_int32_T *idx, emxArray_real_T *bPk,
  emxArray_real_T *bxPk, emxArray_real_T *byPk, emxArray_real_T *wxPk)
{
  emxArray_real_T *b_bPk;
  int i8;
  int loop_ub;
  emxArray_real_T *b_bxPk;
  int i9;
  emxArray_real_T *b_byPk;
  emxArray_real_T *b_wxPk;
  emxInit_real_T(&b_bPk, 1);
  i8 = b_bPk->size[0];
  b_bPk->size[0] = idx->size[0];
  emxEnsureCapacity((emxArray__common *)b_bPk, i8, sizeof(double));
  loop_ub = idx->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_bPk->data[i8] = bPk->data[idx->data[i8] - 1];
  }

  i8 = bPk->size[0];
  bPk->size[0] = b_bPk->size[0];
  emxEnsureCapacity((emxArray__common *)bPk, i8, sizeof(double));
  loop_ub = b_bPk->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    bPk->data[i8] = b_bPk->data[i8];
  }

  emxFree_real_T(&b_bPk);
  emxInit_real_T1(&b_bxPk, 2);
  i8 = b_bxPk->size[0] * b_bxPk->size[1];
  b_bxPk->size[0] = idx->size[0];
  b_bxPk->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)b_bxPk, i8, sizeof(double));
  for (i8 = 0; i8 < 2; i8++) {
    loop_ub = idx->size[0];
    for (i9 = 0; i9 < loop_ub; i9++) {
      b_bxPk->data[i9 + b_bxPk->size[0] * i8] = bxPk->data[(idx->data[i9] +
        bxPk->size[0] * i8) - 1];
    }
  }

  i8 = bxPk->size[0] * bxPk->size[1];
  bxPk->size[0] = b_bxPk->size[0];
  bxPk->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)bxPk, i8, sizeof(double));
  for (i8 = 0; i8 < 2; i8++) {
    loop_ub = b_bxPk->size[0];
    for (i9 = 0; i9 < loop_ub; i9++) {
      bxPk->data[i9 + bxPk->size[0] * i8] = b_bxPk->data[i9 + b_bxPk->size[0] *
        i8];
    }
  }

  emxFree_real_T(&b_bxPk);
  emxInit_real_T1(&b_byPk, 2);
  i8 = b_byPk->size[0] * b_byPk->size[1];
  b_byPk->size[0] = idx->size[0];
  b_byPk->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)b_byPk, i8, sizeof(double));
  for (i8 = 0; i8 < 2; i8++) {
    loop_ub = idx->size[0];
    for (i9 = 0; i9 < loop_ub; i9++) {
      b_byPk->data[i9 + b_byPk->size[0] * i8] = byPk->data[(idx->data[i9] +
        byPk->size[0] * i8) - 1];
    }
  }

  i8 = byPk->size[0] * byPk->size[1];
  byPk->size[0] = b_byPk->size[0];
  byPk->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)byPk, i8, sizeof(double));
  for (i8 = 0; i8 < 2; i8++) {
    loop_ub = b_byPk->size[0];
    for (i9 = 0; i9 < loop_ub; i9++) {
      byPk->data[i9 + byPk->size[0] * i8] = b_byPk->data[i9 + b_byPk->size[0] *
        i8];
    }
  }

  emxFree_real_T(&b_byPk);
  emxInit_real_T1(&b_wxPk, 2);
  i8 = b_wxPk->size[0] * b_wxPk->size[1];
  b_wxPk->size[0] = idx->size[0];
  b_wxPk->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)b_wxPk, i8, sizeof(double));
  for (i8 = 0; i8 < 2; i8++) {
    loop_ub = idx->size[0];
    for (i9 = 0; i9 < loop_ub; i9++) {
      b_wxPk->data[i9 + b_wxPk->size[0] * i8] = wxPk->data[(idx->data[i9] +
        wxPk->size[0] * i8) - 1];
    }
  }

  i8 = wxPk->size[0] * wxPk->size[1];
  wxPk->size[0] = b_wxPk->size[0];
  wxPk->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)wxPk, i8, sizeof(double));
  for (i8 = 0; i8 < 2; i8++) {
    loop_ub = b_wxPk->size[0];
    for (i9 = 0; i9 < loop_ub; i9++) {
      wxPk->data[i9 + wxPk->size[0] * i8] = b_wxPk->data[i9 + b_wxPk->size[0] *
        i8];
    }
  }

  emxFree_real_T(&b_wxPk);
}

//
// Arguments    : const double b[4]
//                const double a[4]
//                const double x[10018]
//                const double zi[3]
//                double y[10018]
// Return Type  : void
//
static void filter(const double b[4], const double a[4], const double x[10018],
                   const double zi[3], double y[10018])
{
  int k;
  int naxpy;
  int j;
  double as;
  for (k = 0; k < 3; k++) {
    y[k] = zi[k];
  }

  memset(&y[3], 0, 10015U * sizeof(double));
  for (k = 0; k < 10018; k++) {
    naxpy = 10018 - k;
    if (!(naxpy < 4)) {
      naxpy = 4;
    }

    for (j = 0; j + 1 <= naxpy; j++) {
      y[k + j] += x[k] * b[j];
    }

    naxpy = 10017 - k;
    if (!(naxpy < 3)) {
      naxpy = 3;
    }

    as = -y[k];
    for (j = 1; j <= naxpy; j++) {
      y[k + j] += as * a[j];
    }
  }
}

//
// Arguments    : const double x_in[10000]
//                double y_out[10000]
// Return Type  : void
//
static void filtfilt(const double x_in[10000], double y_out[10000])
{
  double d0;
  double d1;
  int i;
  static double y[10018];
  double b_y[10018];
  double a[3];
  static const double b_a[3] = { -0.99748988926171522, 1.9949797784811321,
    -0.997489889219522 };

  static const double dv1[4] = { 0.997489880846521, -2.992469642539564,
    2.992469642539564, -0.997489880846521 };

  static const double dv2[4] = { 1.0, -2.9949734530771832, 2.9899595313037808,
    -0.994986062391208 };

  d0 = 2.0 * x_in[0];
  d1 = 2.0 * x_in[9999];
  for (i = 0; i < 9; i++) {
    y[i] = d0 - x_in[9 - i];
  }

  memcpy(&y[9], &x_in[0], 10000U * sizeof(double));
  for (i = 0; i < 9; i++) {
    y[i + 10009] = d1 - x_in[9998 - i];
  }

  for (i = 0; i < 3; i++) {
    a[i] = b_a[i] * y[0];
  }

  memcpy(&b_y[0], &y[0], 10018U * sizeof(double));
  filter(dv1, dv2, b_y, a, y);
  flipud(y);
  for (i = 0; i < 3; i++) {
    a[i] = b_a[i] * y[0];
  }

  memcpy(&b_y[0], &y[0], 10018U * sizeof(double));
  filter(dv1, dv2, b_y, a, y);
  flipud(y);
  memcpy(&y_out[0], &y[9], 10000U * sizeof(double));
}

//
// Arguments    : const double y[10000]
//                emxArray_int32_T *iPk
//                const int iFin_data[]
//                const int iFin_size[1]
//                const int iInf_data[]
//                const int iInf_size[1]
//                const int iInflect_data[]
//                const int iInflect_size[1]
//                emxArray_real_T *bPk
//                emxArray_real_T *bxPk
//                emxArray_real_T *byPk
//                emxArray_real_T *wxPk
// Return Type  : void
//
static void findExtents(const double y[10000], emxArray_int32_T *iPk, const int
  iFin_data[], const int iFin_size[1], const int iInf_data[], const int
  iInf_size[1], const int iInflect_data[], const int iInflect_size[1],
  emxArray_real_T *bPk, emxArray_real_T *bxPk, emxArray_real_T *byPk,
  emxArray_real_T *wxPk)
{
  static double yFinite[10000];
  int loop_ub;
  int i6;
  emxArray_real_T *b_bPk;
  static int iLB_data[10000];
  int iLB_size[1];
  static int iRB_data[10000];
  int iRB_size[1];
  int iPk_size[1];
  emxArray_real_T *b_wxPk;
  static int iPk_data[10000];
  static int iLBh_data[10000];
  int iLBh_size[1];
  static int iRBh_data[10000];
  int iRBh_size[1];
  memcpy(&yFinite[0], &y[0], 10000U * sizeof(double));
  loop_ub = iInf_size[0];
  for (i6 = 0; i6 < loop_ub; i6++) {
    yFinite[iInf_data[i6] - 1] = rtNaN;
  }

  emxInit_real_T(&b_bPk, 1);
  getPeakBase(yFinite, iPk->data, iPk->size, iFin_data, iFin_size, iInflect_data,
              iInflect_size, b_bPk, iLB_data, iLB_size, iRB_data, iRB_size);
  iPk_size[0] = iPk->size[0];
  loop_ub = iPk->size[0];
  for (i6 = 0; i6 < loop_ub; i6++) {
    iPk_data[i6] = iPk->data[i6];
  }

  emxInit_real_T1(&b_wxPk, 2);
  c_removePeaksBelowMinPeakPromin(yFinite, iPk_data, iPk_size, b_bPk, iLB_data,
    iLB_size, iRB_data, iRB_size);
  getPeakWidth(yFinite, iPk_data, iPk_size, iLB_data, iLB_size, iRB_data,
               iRB_size, b_wxPk, iLBh_data, iLBh_size, iRBh_data, iRBh_size);
  combineFullPeaks(y, iPk_data, iPk_size, b_bPk, iLBh_data, iLBh_size, iRBh_data,
                   iRBh_size, b_wxPk, iInf_data, iInf_size, iPk, bPk, bxPk, byPk,
                   wxPk);
  emxFree_real_T(&b_wxPk);
  emxFree_real_T(&b_bPk);
}

//
// Arguments    : const double y[10000]
//                int *idx
//                int borderIdx
//                double refHeight
// Return Type  : void
//
static void findLeftIntercept(const double y[10000], int *idx, int borderIdx,
  double refHeight)
{
  while ((*idx >= borderIdx) && (y[*idx - 1] > refHeight)) {
    (*idx)--;
  }
}

//
// Arguments    : const double y[10000]
//                int *idx
//                int borderIdx
//                double refHeight
// Return Type  : void
//
static void findRightIntercept(const double y[10000], int *idx, int borderIdx,
  double refHeight)
{
  while ((*idx <= borderIdx) && (y[*idx - 1] > refHeight)) {
    (*idx)++;
  }
}

//
// Arguments    : const double Yin[10000]
//                emxArray_real_T *Ypk
//                emxArray_real_T *Xpk
//                emxArray_real_T *Wpk
// Return Type  : void
//
static void findpeaks(const double Yin[10000], emxArray_real_T *Ypk,
                      emxArray_real_T *Xpk, emxArray_real_T *Wpk)
{
  emxArray_int32_T *iPk;
  static int iFinite_data[10000];
  int iFinite_size[1];
  static int iInfinite_data[10000];
  int iInfinite_size[1];
  static int iInflect_data[10000];
  int iInflect_size[1];
  static int tmp_data[10000];
  int tmp_size[1];
  int i0;
  int loop_ub;
  emxArray_int32_T *idx;
  emxArray_real_T *bPk;
  emxArray_real_T *bxPk;
  emxArray_real_T *byPk;
  emxArray_real_T *wxPk;
  emxArray_int32_T *b_iPk;
  emxArray_real_T *Ppk;
  emxInit_int32_T(&iPk, 1);
  getAllPeaksCodegen(Yin, iFinite_data, iFinite_size, iInfinite_data,
                     iInfinite_size, iInflect_data, iInflect_size);
  removeSmallPeaks(Yin, iFinite_data, iFinite_size, tmp_data, tmp_size);
  i0 = iPk->size[0];
  iPk->size[0] = tmp_size[0];
  emxEnsureCapacity((emxArray__common *)iPk, i0, sizeof(int));
  loop_ub = tmp_size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    iPk->data[i0] = tmp_data[i0];
  }

  emxInit_int32_T(&idx, 1);
  emxInit_real_T(&bPk, 1);
  emxInit_real_T1(&bxPk, 2);
  emxInit_real_T1(&byPk, 2);
  emxInit_real_T1(&wxPk, 2);
  emxInit_int32_T(&b_iPk, 1);
  findExtents(Yin, iPk, iFinite_data, iFinite_size, iInfinite_data,
              iInfinite_size, iInflect_data, iInflect_size, bPk, bxPk, byPk,
              wxPk);
  c_findPeaksSeparatedByMoreThanM(iPk, idx);
  keepAtMostNpPeaks(idx);
  fetchPeakExtents(idx, bPk, bxPk, byPk, wxPk);
  i0 = b_iPk->size[0];
  b_iPk->size[0] = idx->size[0];
  emxEnsureCapacity((emxArray__common *)b_iPk, i0, sizeof(int));
  loop_ub = idx->size[0];
  emxFree_real_T(&byPk);
  emxFree_real_T(&bxPk);
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_iPk->data[i0] = iPk->data[idx->data[i0] - 1];
  }

  emxFree_int32_T(&idx);
  emxFree_int32_T(&iPk);
  emxInit_real_T(&Ppk, 1);
  assignFullOutputs(Yin, b_iPk, wxPk, bPk, Ypk, Xpk, Wpk, Ppk);
  emxFree_int32_T(&b_iPk);
  emxFree_real_T(&Ppk);
  emxFree_real_T(&wxPk);
  emxFree_real_T(&bPk);
}

//
// Arguments    : double x[10018]
// Return Type  : void
//
static void flipud(double x[10018])
{
  int i;
  double xtmp;
  for (i = 0; i < 5009; i++) {
    xtmp = x[i];
    x[i] = x[10017 - i];
    x[10017 - i] = xtmp;
  }
}

//
// Arguments    : const double y[10000]
//                int iPk_data[]
//                int iPk_size[1]
//                int iInf_data[]
//                int iInf_size[1]
//                int iInflect_data[]
//                int iInflect_size[1]
// Return Type  : void
//
static void getAllPeaksCodegen(const double y[10000], int iPk_data[], int
  iPk_size[1], int iInf_data[], int iInf_size[1], int iInflect_data[], int
  iInflect_size[1])
{
  int nPk;
  int nInf;
  int nInflect;
  char dir;
  int kfirst;
  double ykfirst;
  boolean_T isinfykfirst;
  int k;
  double yk;
  boolean_T isinfyk;
  char previousdir;
  int i1;
  nPk = 0;
  nInf = 0;
  nInflect = -1;
  dir = 'n';
  kfirst = 0;
  ykfirst = rtInf;
  isinfykfirst = true;
  for (k = 0; k < 10000; k++) {
    yk = y[k];
    if (rtIsNaN(y[k])) {
      yk = rtInf;
      isinfyk = true;
    } else if (rtIsInf(y[k]) && (y[k] > 0.0)) {
      isinfyk = true;
      nInf++;
      iInf_data[nInf - 1] = k + 1;
    } else {
      isinfyk = false;
    }

    if (yk != ykfirst) {
      previousdir = dir;
      if (isinfyk || isinfykfirst) {
        dir = 'n';
        if (kfirst >= 1) {
          nInflect++;
          iInflect_data[nInflect] = kfirst;
        }
      } else if (yk < ykfirst) {
        dir = 'd';
        if ('d' != previousdir) {
          nInflect++;
          iInflect_data[nInflect] = kfirst;
          if (previousdir == 'i') {
            nPk++;
            iPk_data[nPk - 1] = kfirst;
          }
        }
      } else {
        dir = 'i';
        if ('i' != previousdir) {
          nInflect++;
          iInflect_data[nInflect] = kfirst;
        }
      }

      ykfirst = yk;
      kfirst = k + 1;
      isinfykfirst = isinfyk;
    }
  }

  if ((!isinfykfirst) && ((nInflect + 1 == 0) || (iInflect_data[nInflect] <
        10000))) {
    nInflect++;
    iInflect_data[nInflect] = 10000;
  }

  if (1 > nPk) {
    iPk_size[0] = 0;
  } else {
    iPk_size[0] = nPk;
  }

  if (1 > nInf) {
    iInf_size[0] = 0;
  } else {
    iInf_size[0] = nInf;
  }

  if (1 > nInflect + 1) {
    i1 = -1;
  } else {
    i1 = nInflect;
  }

  iInflect_size[0] = i1 + 1;
}

//
// Arguments    : const double y[10000]
//                const int iPk_data[]
//                const int iPk_size[1]
//                const int iLB_data[]
//                const int iRB_data[]
//                emxArray_real_T *bounds
// Return Type  : void
//
static void getHalfMaxBounds(const double y[10000], const int iPk_data[], const
  int iPk_size[1], const int iLB_data[], const int iRB_data[], emxArray_real_T
  *bounds)
{
  int iLeft;
  int iRight;
  int i;
  double refHeight;
  iLeft = bounds->size[0] * bounds->size[1];
  bounds->size[0] = iPk_size[0];
  bounds->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)bounds, iLeft, sizeof(double));
  iRight = iPk_size[0] << 1;
  for (iLeft = 0; iLeft < iRight; iLeft++) {
    bounds->data[iLeft] = 0.0;
  }

  for (i = 0; i < iPk_size[0]; i++) {
    refHeight = y[iPk_data[i] - 1] / 2.0;
    iLeft = iPk_data[i];
    findLeftIntercept(y, &iLeft, iLB_data[i], refHeight);
    if (iLeft < iLB_data[i]) {
      bounds->data[i] = 1.0 + ((double)iLB_data[i] - 1.0);
    } else {
      bounds->data[i] = linterp(1.0 + ((double)iLeft - 1.0), 1.0 + ((double)
        (iLeft + 1) - 1.0), y[iLeft - 1], y[iLeft], y[iPk_data[i] - 1]);
    }

    iRight = iPk_data[i];
    findRightIntercept(y, &iRight, iRB_data[i], refHeight);
    if (iRight > iRB_data[i]) {
      bounds->data[i + bounds->size[0]] = 1.0 + ((double)iRB_data[i] - 1.0);
    } else {
      bounds->data[i + bounds->size[0]] = linterp(1.0 + ((double)iRight - 1.0),
        1.0 + ((double)(iRight - 1) - 1.0), y[iRight - 1], y[iRight - 2],
        y[iPk_data[i] - 1]);
    }
  }
}

//
// Arguments    : const double yTemp[10000]
//                const int iPeak_data[]
//                const int iPeak_size[1]
//                const int iFinite_data[]
//                const int iFinite_size[1]
//                const int iInflect_data[]
//                int iBase_data[]
//                int iBase_size[1]
//                int iSaddle_data[]
//                int iSaddle_size[1]
// Return Type  : void
//
static void getLeftBase(const double yTemp[10000], const int iPeak_data[], const
  int iPeak_size[1], const int iFinite_data[], const int iFinite_size[1], const
  int iInflect_data[], int iBase_data[], int iBase_size[1], int iSaddle_data[],
  int iSaddle_size[1])
{
  int n;
  int i;
  emxArray_real_T *peak;
  emxArray_real_T *valley;
  int iValley_data[10000];
  int j;
  int k;
  double v;
  int iv;
  double p;
  int isv;
  iBase_size[0] = (short)iPeak_size[0];
  n = (short)iPeak_size[0];
  for (i = 0; i < n; i++) {
    iBase_data[i] = 0;
  }

  iSaddle_size[0] = (short)iPeak_size[0];
  n = (short)iPeak_size[0];
  for (i = 0; i < n; i++) {
    iSaddle_data[i] = 0;
  }

  emxInit_real_T(&peak, 1);
  i = peak->size[0];
  peak->size[0] = (short)iFinite_size[0];
  emxEnsureCapacity((emxArray__common *)peak, i, sizeof(double));
  n = (short)iFinite_size[0];
  for (i = 0; i < n; i++) {
    peak->data[i] = 0.0;
  }

  emxInit_real_T(&valley, 1);
  i = valley->size[0];
  valley->size[0] = (short)iFinite_size[0];
  emxEnsureCapacity((emxArray__common *)valley, i, sizeof(double));
  n = (short)iFinite_size[0];
  for (i = 0; i < n; i++) {
    valley->data[i] = 0.0;
  }

  n = (short)iFinite_size[0];
  for (i = 0; i < n; i++) {
    iValley_data[i] = 0;
  }

  n = -1;
  i = 0;
  j = 0;
  k = 0;
  v = rtNaN;
  iv = 1;
  while (k + 1 <= iPeak_size[0]) {
    while (iInflect_data[i] != iFinite_data[j]) {
      v = yTemp[iInflect_data[i] - 1];
      iv = iInflect_data[i];
      if (rtIsNaN(yTemp[iInflect_data[i] - 1])) {
        n = -1;
      } else {
        while ((n + 1 > 0) && (valley->data[n] > v)) {
          n--;
        }
      }

      i++;
    }

    p = yTemp[iInflect_data[i] - 1];
    while ((n + 1 > 0) && (peak->data[n] < p)) {
      if (valley->data[n] < v) {
        v = valley->data[n];
        iv = iValley_data[n];
      }

      n--;
    }

    isv = iv;
    while ((n + 1 > 0) && (peak->data[n] <= p)) {
      if (valley->data[n] < v) {
        v = valley->data[n];
        iv = iValley_data[n];
      }

      n--;
    }

    n++;
    peak->data[n] = yTemp[iInflect_data[i] - 1];
    valley->data[n] = v;
    iValley_data[n] = iv;
    if (iInflect_data[i] == iPeak_data[k]) {
      iBase_data[k] = iv;
      iSaddle_data[k] = isv;
      k++;
    }

    i++;
    j++;
  }

  emxFree_real_T(&valley);
  emxFree_real_T(&peak);
}

//
// Arguments    : const double yTemp[10000]
//                const int iPk_data[]
//                const int iPk_size[1]
//                const int iFin_data[]
//                const int iFin_size[1]
//                const int iInflect_data[]
//                const int iInflect_size[1]
//                emxArray_real_T *peakBase
//                int iLeftSaddle_data[]
//                int iLeftSaddle_size[1]
//                int iRightSaddle_data[]
//                int iRightSaddle_size[1]
// Return Type  : void
//
static void getPeakBase(const double yTemp[10000], const int iPk_data[], const
  int iPk_size[1], const int iFin_data[], const int iFin_size[1], const int
  iInflect_data[], const int iInflect_size[1], emxArray_real_T *peakBase, int
  iLeftSaddle_data[], int iLeftSaddle_size[1], int iRightSaddle_data[], int
  iRightSaddle_size[1])
{
  static int iLeftBase_data[10000];
  int iLeftBase_size[1];
  int tmp_size[1];
  int loop_ub;
  int i2;
  static int tmp_data[10000];
  int b_tmp_size[1];
  static int b_tmp_data[10000];
  int c_tmp_size[1];
  int c_tmp_data[10000];
  int iRightBase_data[10000];
  short csz_idx_0;
  getLeftBase(yTemp, iPk_data, iPk_size, iFin_data, iFin_size, iInflect_data,
              iLeftBase_data, iLeftBase_size, iLeftSaddle_data, iLeftSaddle_size);
  tmp_size[0] = iPk_size[0];
  loop_ub = iPk_size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    tmp_data[i2] = iPk_data[i2];
  }

  b_flipud(tmp_data, tmp_size);
  b_tmp_size[0] = iFin_size[0];
  loop_ub = iFin_size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_tmp_data[i2] = iFin_data[i2];
  }

  b_flipud(b_tmp_data, b_tmp_size);
  c_tmp_size[0] = iInflect_size[0];
  loop_ub = iInflect_size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    c_tmp_data[i2] = iInflect_data[i2];
  }

  b_flipud(c_tmp_data, c_tmp_size);
  getLeftBase(yTemp, tmp_data, tmp_size, b_tmp_data, b_tmp_size, c_tmp_data,
              iRightBase_data, c_tmp_size, iRightSaddle_data, iRightSaddle_size);
  b_flipud(iRightBase_data, c_tmp_size);
  b_flipud(iRightSaddle_data, iRightSaddle_size);
  if (iLeftBase_size[0] <= c_tmp_size[0]) {
    csz_idx_0 = (short)iLeftBase_size[0];
  } else {
    csz_idx_0 = (short)c_tmp_size[0];
  }

  i2 = peakBase->size[0];
  if (iLeftBase_size[0] <= c_tmp_size[0]) {
    peakBase->size[0] = (short)iLeftBase_size[0];
  } else {
    peakBase->size[0] = (short)c_tmp_size[0];
  }

  emxEnsureCapacity((emxArray__common *)peakBase, i2, sizeof(double));
  for (loop_ub = 0; loop_ub + 1 <= csz_idx_0; loop_ub++) {
    if ((yTemp[iLeftBase_data[loop_ub] - 1] > yTemp[iRightBase_data[loop_ub] - 1])
        || rtIsNaN(yTemp[iRightBase_data[loop_ub] - 1])) {
      peakBase->data[loop_ub] = yTemp[iLeftBase_data[loop_ub] - 1];
    } else {
      peakBase->data[loop_ub] = yTemp[iRightBase_data[loop_ub] - 1];
    }
  }
}

//
// Arguments    : const double y[10000]
//                const int iPk_data[]
//                const int iPk_size[1]
//                const int iLB_data[]
//                const int iLB_size[1]
//                const int iRB_data[]
//                const int iRB_size[1]
//                emxArray_real_T *wxPk
//                int iLBh_data[]
//                int iLBh_size[1]
//                int iRBh_data[]
//                int iRBh_size[1]
// Return Type  : void
//
static void getPeakWidth(const double y[10000], const int iPk_data[], const int
  iPk_size[1], const int iLB_data[], const int iLB_size[1], const int iRB_data[],
  const int iRB_size[1], emxArray_real_T *wxPk, int iLBh_data[], int iLBh_size[1],
  int iRBh_data[], int iRBh_size[1])
{
  emxArray_real_T *base;
  int i3;
  int loop_ub;
  int k;
  int c;
  int u1;
  int maxval_data[9999];
  emxInit_real_T(&base, 1);
  if (iPk_size[0] == 0) {
    i3 = base->size[0];
    base->size[0] = 0;
    emxEnsureCapacity((emxArray__common *)base, i3, sizeof(double));
    iLBh_size[0] = 0;
    iRBh_size[0] = 0;
  } else {
    i3 = base->size[0];
    base->size[0] = (short)iPk_size[0];
    emxEnsureCapacity((emxArray__common *)base, i3, sizeof(double));
    loop_ub = (short)iPk_size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      base->data[i3] = 0.0;
    }

    if (2 > iLB_size[0]) {
      i3 = 0;
      k = 1;
    } else {
      i3 = 1;
      k = iLB_size[0] + 1;
    }

    if (1 > iRB_size[0] - 1) {
      c = 0;
    } else {
      c = iRB_size[0] - 1;
    }

    if ((k - i3) - 1 <= c) {
      c = (k - i3) - 1;
    }

    for (k = 0; k + 1 <= (short)c; k++) {
      loop_ub = iLB_data[i3 + k];
      u1 = iRB_data[k];
      if (loop_ub > u1) {
        u1 = loop_ub;
      }

      maxval_data[k] = u1;
    }

    iLBh_size[0] = 1 + (short)c;
    iLBh_data[0] = iLB_data[0];
    loop_ub = (short)c;
    for (i3 = 0; i3 < loop_ub; i3++) {
      iLBh_data[i3 + 1] = maxval_data[i3];
    }

    if (1 > iRB_size[0] - 1) {
      c = 0;
    } else {
      c = iRB_size[0] - 1;
    }

    if (2 > iLB_size[0]) {
      i3 = 0;
      k = 1;
    } else {
      i3 = 1;
      k = iLB_size[0] + 1;
    }

    if (!(c <= (k - i3) - 1)) {
      c = (k - i3) - 1;
    }

    for (k = 0; k + 1 <= (short)c; k++) {
      loop_ub = iRB_data[k];
      u1 = iLB_data[i3 + k];
      if (loop_ub < u1) {
        u1 = loop_ub;
      }

      maxval_data[k] = u1;
    }

    iRBh_size[0] = (short)c + 1;
    loop_ub = (short)c;
    for (i3 = 0; i3 < loop_ub; i3++) {
      iRBh_data[i3] = maxval_data[i3];
    }

    iRBh_data[(short)c] = iRB_data[iRB_size[0] - 1];
    loop_ub = iLBh_size[0];
    for (k = 0; k < loop_ub; k++) {
      if (iLBh_data[k] > iPk_data[k]) {
        iLBh_data[k] = iLB_data[k];
      }
    }

    loop_ub = iRBh_size[0];
    for (k = 0; k < loop_ub; k++) {
      if (iRBh_data[k] < iPk_data[k]) {
        iRBh_data[k] = iRB_data[k];
      }
    }
  }

  getHalfMaxBounds(y, iPk_data, iPk_size, iLBh_data, iRBh_data, wxPk);
  emxFree_real_T(&base);
}

//
// Arguments    : emxArray_int32_T *idx
// Return Type  : void
//
static void keepAtMostNpPeaks(emxArray_int32_T *idx)
{
  emxArray_int32_T *b_idx;
  int i7;
  int loop_ub;
  if (idx->size[0] > 10000) {
    emxInit_int32_T(&b_idx, 1);
    i7 = b_idx->size[0];
    b_idx->size[0] = 10000;
    emxEnsureCapacity((emxArray__common *)b_idx, i7, sizeof(int));
    for (i7 = 0; i7 < 10000; i7++) {
      b_idx->data[i7] = idx->data[i7];
    }

    i7 = idx->size[0];
    idx->size[0] = b_idx->size[0];
    emxEnsureCapacity((emxArray__common *)idx, i7, sizeof(int));
    loop_ub = b_idx->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      idx->data[i7] = b_idx->data[i7];
    }

    emxFree_int32_T(&b_idx);
  }
}

//
// Arguments    : double xa
//                double xb
//                double ya
//                double yb
//                double yc
// Return Type  : double
//
static double linterp(double xa, double xb, double ya, double yb, double yc)
{
  double xc;
  xc = xa + (xb - xa) * (0.5 * yc - ya) / (yb - ya);
  if (rtIsNaN(xc)) {
    xc = xb;
  }

  return xc;
}

//
// Arguments    : const emxArray_real_T *x
// Return Type  : double
//
static double mean(const emxArray_real_T *x)
{
  double y;
  int k;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= x->size[0]; k++) {
      y += x->data[k - 1];
    }
  }

  y /= (double)x->size[0];
  return y;
}

//
// Arguments    : const double y[10000]
//                const int iFinite_data[]
//                const int iFinite_size[1]
//                int iPk_data[]
//                int iPk_size[1]
// Return Type  : void
//
static void removeSmallPeaks(const double y[10000], const int iFinite_data[],
  const int iFinite_size[1], int iPk_data[], int iPk_size[1])
{
  int nPk;
  int k;
  double b_y;
  nPk = 0;
  for (k = 0; k + 1 <= iFinite_size[0]; k++) {
    if (y[iFinite_data[k] - 1] > 0.0) {
      if ((y[iFinite_data[k] - 2] > y[iFinite_data[k]]) || rtIsNaN
          (y[iFinite_data[k]])) {
        b_y = y[iFinite_data[k] - 2];
      } else {
        b_y = y[iFinite_data[k]];
      }

      if (y[iFinite_data[k] - 1] - b_y >= 0.0) {
        nPk++;
        iPk_data[nPk - 1] = iFinite_data[k];
      }
    }
  }

  if (1 > nPk) {
    iPk_size[0] = 0;
  } else {
    iPk_size[0] = nPk;
  }
}

//
// Arguments    : const double X[10000]
//                double Y[10000]
// Return Type  : void
//
static void rescale_minmax(const double X[10000], double Y[10000])
{
  int ixstart;
  double mtmp;
  int ix;
  boolean_T exitg1;
  double b_mtmp;
  ixstart = 1;
  mtmp = X[0];
  if (rtIsNaN(X[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 10001)) {
      ixstart = ix;
      if (!rtIsNaN(X[ix - 1])) {
        mtmp = X[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 10000) {
    while (ixstart + 1 < 10001) {
      if (X[ixstart] < mtmp) {
        mtmp = X[ixstart];
      }

      ixstart++;
    }
  }

  ixstart = 1;
  b_mtmp = X[0];
  if (rtIsNaN(X[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 10001)) {
      ixstart = ix;
      if (!rtIsNaN(X[ix - 1])) {
        b_mtmp = X[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 10000) {
    while (ixstart + 1 < 10001) {
      if (X[ixstart] > b_mtmp) {
        b_mtmp = X[ixstart];
      }

      ixstart++;
    }
  }

  b_mtmp -= mtmp;
  for (ixstart = 0; ixstart < 10000; ixstart++) {
    Y[ixstart] = (X[ixstart] - mtmp) / b_mtmp;
  }
}

//
// BSP_FT_EX Extracts features for BSP analysis
//    X: Input vector, 1ch EOG (N, 1), raw, no preproces, size TBD
//    FT: Output array of features. (FT, 1).
// Arguments    : const double X[10000]
//                double FT[7]
// Return Type  : void
//
void bsp_ftex(const double X[10000], double FT[7])
{
  emxArray_real_T *P;
  emxArray_real_T *L;
  emxArray_real_T *w;
  static double X_h[10000];
  static double X_bp[10000];
  static double dv0[10000];
  int tmp_size_idx_0;
  int ixstart;
  int n;
  boolean_T tmp_data[20000];
  boolean_T b_tmp_data[20000];
  int trueCount;
  int end;
  int b_trueCount;
  double mtmp;
  double x;
  boolean_T exitg1;
  emxArray_int32_T *r0;
  emxArray_real_T *b_w;
  double b_x;
  emxArray_int32_T *r1;
  emxArray_real_T *c_w;
  double c_x;
  emxInit_real_T(&P, 1);
  emxInit_real_T(&L, 1);
  emxInit_real_T(&w, 1);

  //  Varsize Arrays:
  //    P, L, w, pr (peak finding method)
  //    dist (used in peak finding)
  //  FT = [];
  //  1. Filter.
  //  [bh, ah] = butter(3, 0.1*2/250, 'high');
  //  [bl, al] = butter(3, 10*2/250, 'low');
  //  Filter data
  filtfilt(X, X_h);
  b_filtfilt(X_h, X_bp);

  //  Other preprocess - rescale
  //  Smoothing (averages):
  //  Extract features:
  rescale_minmax(X_bp, dv0);
  findpeaks(dv0, P, L, w);
  tmp_size_idx_0 = w->size[0];
  ixstart = w->size[0];
  emxFree_real_T(&L);
  for (n = 0; n < ixstart; n++) {
    tmp_data[n] = (w->data[n] > 30.0);
  }

  ixstart = w->size[0];
  for (n = 0; n < ixstart; n++) {
    b_tmp_data[n] = (w->data[n] < 70.0);
  }

  //  Other features; usefulness tbd
  //  seconds
  //  dist = L(2:end) - L(1:end-1); % Distance between consecutive peaks
  //  METRICS
  //  events/second
  trueCount = 0;
  for (n = 0; n < tmp_size_idx_0; n++) {
    if (tmp_data[n] && b_tmp_data[n]) {
      trueCount++;
    }
  }

  end = w->size[0];
  b_trueCount = 0;
  for (n = 0; n < end; n++) {
    if (w->data[n] >= 90.0) {
      b_trueCount++;
    }
  }

  ixstart = 1;
  n = w->size[0];
  mtmp = w->data[0];
  if (w->size[0] > 1) {
    if (rtIsNaN(w->data[0])) {
      end = 2;
      exitg1 = false;
      while ((!exitg1) && (end <= n)) {
        ixstart = end;
        if (!rtIsNaN(w->data[end - 1])) {
          mtmp = w->data[end - 1];
          exitg1 = true;
        } else {
          end++;
        }
      }
    }

    if (ixstart < w->size[0]) {
      while (ixstart + 1 <= n) {
        if (w->data[ixstart] > mtmp) {
          mtmp = w->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  x = mean(w);
  end = tmp_size_idx_0 - 1;
  ixstart = 0;
  for (n = 0; n <= end; n++) {
    if (tmp_data[n] && b_tmp_data[n]) {
      ixstart++;
    }
  }

  emxInit_int32_T(&r0, 1);
  n = r0->size[0];
  r0->size[0] = ixstart;
  emxEnsureCapacity((emxArray__common *)r0, n, sizeof(int));
  ixstart = 0;
  for (n = 0; n <= end; n++) {
    if (tmp_data[n] && b_tmp_data[n]) {
      r0->data[ixstart] = n + 1;
      ixstart++;
    }
  }

  emxInit_real_T(&b_w, 1);
  n = b_w->size[0];
  b_w->size[0] = r0->size[0];
  emxEnsureCapacity((emxArray__common *)b_w, n, sizeof(double));
  ixstart = r0->size[0];
  for (n = 0; n < ixstart; n++) {
    b_w->data[n] = w->data[r0->data[n] - 1];
  }

  emxFree_int32_T(&r0);
  b_x = mean(b_w);
  end = w->size[0] - 1;
  ixstart = 0;
  emxFree_real_T(&b_w);
  for (n = 0; n <= end; n++) {
    if (w->data[n] >= 90.0) {
      ixstart++;
    }
  }

  emxInit_int32_T(&r1, 1);
  n = r1->size[0];
  r1->size[0] = ixstart;
  emxEnsureCapacity((emxArray__common *)r1, n, sizeof(int));
  ixstart = 0;
  for (n = 0; n <= end; n++) {
    if (w->data[n] >= 90.0) {
      r1->data[ixstart] = n + 1;
      ixstart++;
    }
  }

  emxInit_real_T(&c_w, 1);
  n = c_w->size[0];
  c_w->size[0] = r1->size[0];
  emxEnsureCapacity((emxArray__common *)c_w, n, sizeof(double));
  ixstart = r1->size[0];
  for (n = 0; n < ixstart; n++) {
    c_w->data[n] = w->data[r1->data[n] - 1];
  }

  emxFree_int32_T(&r1);
  emxFree_real_T(&w);
  c_x = mean(c_w);

  //  in seconds
  //  how to detect spasm
  //  TODO: Average Spasm Frequency
  //  TODO: Average Spasm Length
  FT[0] = (double)P->size[0] / 40.0;
  FT[1] = (double)trueCount / 40.0;
  FT[2] = (double)b_trueCount / 40.0;
  FT[3] = mtmp / 250.0;
  FT[4] = x / 250.0;
  FT[5] = b_x / 250.0;
  FT[6] = c_x / 250.0;
  emxFree_real_T(&c_w);
  emxFree_real_T(&P);
}

//
// Arguments    : void
// Return Type  : void
//
void bsp_ftex_initialize()
{
  rt_InitInfAndNaN(8U);
}

//
// Arguments    : void
// Return Type  : void
//
void bsp_ftex_terminate()
{
  // (no terminate code required)
}

//
// File trailer for bsp_ftex.cpp
//
// [EOF]
//
