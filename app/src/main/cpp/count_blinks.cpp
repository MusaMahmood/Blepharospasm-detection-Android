//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: count_blinks.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 12-Sep-2018 10:40:36
//

// Include Files
#include "rt_nonfinite.h"
#include "count_blinks.h"

// Function Declarations
static void assignFullOutputs(const float y[2000], const int iPk_data[], const
  int iPk_size[1], const double wxPk_data[], const int wxPk_size[2], const
  double bPk_data[], float YpkOut_data[], int YpkOut_size[1], double
  XpkOut_data[], int XpkOut_size[1], double WpkOut_data[], int WpkOut_size[1],
  float PpkOut_data[], int PpkOut_size[1]);
static void b_do_vectors(const int a_data[], const int a_size[1], const int
  b_data[], const int b_size[1], int c_data[], int c_size[1], int ia_data[], int
  ia_size[1], int ib_data[], int ib_size[1]);
static void c_findPeaksSeparatedByMoreThanM(const int iPk_size[1], int idx_data[],
  int idx_size[1]);
static void c_removePeaksBelowMinPeakPromin(const float y[2000], int iPk_data[],
  int iPk_size[1], float pbPk_data[], int pbPk_size[1], int iLB_data[], int
  iLB_size[1], int iRB_data[], int iRB_size[1]);
static void diff(const double x_data[], const int x_size[2], double y_data[],
                 int y_size[1]);
static void do_vectors(const int a_data[], const int a_size[1], const int
  b_data[], const int b_size[1], int c_data[], int c_size[1], int ia_data[], int
  ia_size[1], int ib_data[], int ib_size[1]);
static void fetchPeakExtents(const int idx_data[], const int idx_size[1], double
  bPk_data[], int bPk_size[1], double bxPk_data[], int bxPk_size[2], double
  byPk_data[], int byPk_size[2], double wxPk_data[], int wxPk_size[2]);
static void findExtents(const float y[2000], int iPk_data[], int iPk_size[1],
  const int iFin_data[], const int iFin_size[1], const int iInf_data[], const
  int iInf_size[1], const int iInflect_data[], const int iInflect_size[1],
  double bPk_data[], int bPk_size[1], double bxPk_data[], int bxPk_size[2],
  double byPk_data[], int byPk_size[2], double wxPk_data[], int wxPk_size[2]);
static void findLeftIntercept(const float y[2000], int *idx, int borderIdx,
  float refHeight);
static void findRightIntercept(const float y[2000], int *idx, int borderIdx,
  float refHeight);
static void flipud(int x_data[], int x_size[1]);
static void getAllPeaksCodegen(const float y[2000], int iPk_data[], int
  iPk_size[1], int iInf_data[], int iInf_size[1], int iInflect_data[], int
  iInflect_size[1]);
static void getHalfMaxBounds(const float y[2000], const int iPk_data[], const
  int iPk_size[1], const float base_data[], const int iLB_data[], const int
  iRB_data[], double bounds_data[], int bounds_size[2]);
static void getLeftBase(const float yTemp[2000], const int iPeak_data[], const
  int iPeak_size[1], const int iFinite_data[], const int iFinite_size[1], const
  int iInflect_data[], int iBase_data[], int iBase_size[1], int iSaddle_data[],
  int iSaddle_size[1]);
static void getPeakBase(const float yTemp[2000], const int iPk_data[], const int
  iPk_size[1], const int iFin_data[], const int iFin_size[1], const int
  iInflect_data[], const int iInflect_size[1], float peakBase_data[], int
  peakBase_size[1], int iLeftSaddle_data[], int iLeftSaddle_size[1], int
  iRightSaddle_data[], int iRightSaddle_size[1]);
static void getPeakWidth(const float y[2000], const int iPk_data[], const int
  iPk_size[1], const float pbPk_data[], const int pbPk_size[1], int iLB_data[],
  int iLB_size[1], int iRB_data[], int iRB_size[1], double wxPk_data[], int
  wxPk_size[2]);
static void keepAtMostNpPeaks(int idx_data[], int idx_size[1]);
static float linterp(double xa, double xb, float ya, float yb, float yc, float
                     bc);
static void removeSmallPeaks(const float y[2000], const int iFinite_data[],
  const int iFinite_size[1], int iPk_data[], int iPk_size[1]);

// Function Definitions

//
// Arguments    : const float y[2000]
//                const int iPk_data[]
//                const int iPk_size[1]
//                const double wxPk_data[]
//                const int wxPk_size[2]
//                const double bPk_data[]
//                float YpkOut_data[]
//                int YpkOut_size[1]
//                double XpkOut_data[]
//                int XpkOut_size[1]
//                double WpkOut_data[]
//                int WpkOut_size[1]
//                float PpkOut_data[]
//                int PpkOut_size[1]
// Return Type  : void
//
static void assignFullOutputs(const float y[2000], const int iPk_data[], const
  int iPk_size[1], const double wxPk_data[], const int wxPk_size[2], const
  double bPk_data[], float YpkOut_data[], int YpkOut_size[1], double
  XpkOut_data[], int XpkOut_size[1], double WpkOut_data[], int WpkOut_size[1],
  float PpkOut_data[], int PpkOut_size[1])
{
  int loop_ub;
  int i3;
  short tmp_data[4000];
  YpkOut_size[0] = iPk_size[0];
  loop_ub = iPk_size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    YpkOut_data[i3] = y[iPk_data[i3] - 1];
  }

  loop_ub = iPk_size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    tmp_data[i3] = (short)(1 + (short)(iPk_data[i3] - 1));
  }

  XpkOut_size[0] = iPk_size[0];
  loop_ub = iPk_size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    XpkOut_data[i3] = tmp_data[i3];
  }

  diff(wxPk_data, wxPk_size, WpkOut_data, WpkOut_size);
  PpkOut_size[0] = iPk_size[0];
  loop_ub = iPk_size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    PpkOut_data[i3] = YpkOut_data[i3] - (float)bPk_data[i3];
  }
}

//
// Arguments    : const int a_data[]
//                const int a_size[1]
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
static void b_do_vectors(const int a_data[], const int a_size[1], const int
  b_data[], const int b_size[1], int c_data[], int c_size[1], int ia_data[], int
  ia_size[1], int ib_data[], int ib_size[1])
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
  int b_ia_data[2000];
  int bk;
  iafirst = a_size[0];
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
  while ((ialast <= a_size[0]) && (iblast <= b_size[0])) {
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
// Arguments    : const int iPk_size[1]
//                int idx_data[]
//                int idx_size[1]
// Return Type  : void
//
static void c_findPeaksSeparatedByMoreThanM(const int iPk_size[1], int idx_data[],
  int idx_size[1])
{
  int n;
  int y_data[4000];
  int yk;
  int k;
  if (iPk_size[0] < 1) {
    n = 0;
  } else {
    n = iPk_size[0];
  }

  if (n > 0) {
    y_data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }

  idx_size[0] = n;
  for (yk = 0; yk < n; yk++) {
    idx_data[yk] = y_data[yk];
  }
}

//
// Arguments    : const float y[2000]
//                int iPk_data[]
//                int iPk_size[1]
//                float pbPk_data[]
//                int pbPk_size[1]
//                int iLB_data[]
//                int iLB_size[1]
//                int iRB_data[]
//                int iRB_size[1]
// Return Type  : void
//
static void c_removePeaksBelowMinPeakPromin(const float y[2000], int iPk_data[],
  int iPk_size[1], float pbPk_data[], int pbPk_size[1], int iLB_data[], int
  iLB_size[1], int iRB_data[], int iRB_size[1])
{
  int x_size_idx_0;
  int idx;
  int ii;
  boolean_T x_data[2000];
  boolean_T exitg1;
  int ii_data[2000];
  int idx_data[2000];
  float b_pbPk_data[2000];
  x_size_idx_0 = iPk_size[0];
  idx = iPk_size[0];
  for (ii = 0; ii < idx; ii++) {
    x_data[ii] = (y[iPk_data[ii] - 1] - pbPk_data[ii] >= 0.3339);
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

  for (ii = 0; ii < x_size_idx_0; ii++) {
    b_pbPk_data[ii] = pbPk_data[idx_data[ii] - 1];
  }

  pbPk_size[0] = x_size_idx_0;
  for (ii = 0; ii < x_size_idx_0; ii++) {
    pbPk_data[ii] = b_pbPk_data[ii];
  }

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
// Arguments    : const double x_data[]
//                const int x_size[2]
//                double y_data[]
//                int y_size[1]
// Return Type  : void
//
static void diff(const double x_data[], const int x_size[2], double y_data[],
                 int y_size[1])
{
  int stride;
  int ix;
  int iy;
  int s;
  y_size[0] = (short)x_size[0];
  if (!((short)x_size[0] == 0)) {
    stride = x_size[0];
    ix = 0;
    iy = 0;
    for (s = 1; s <= stride; s++) {
      y_data[iy] = x_data[ix + stride] - x_data[ix];
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
//                int c_data[]
//                int c_size[1]
//                int ia_data[]
//                int ia_size[1]
//                int ib_data[]
//                int ib_size[1]
// Return Type  : void
//
static void do_vectors(const int a_data[], const int a_size[1], const int
  b_data[], const int b_size[1], int c_data[], int c_size[1], int ia_data[], int
  ia_size[1], int ib_data[], int ib_size[1])
{
  int na;
  int nb;
  int ncmax;
  int nc;
  int nia;
  int nib;
  int iafirst;
  int ialast;
  int ibfirst;
  int iblast;
  int b_ialast;
  int ak;
  int b_iblast;
  int bk;
  int b_ia_data[2000];
  short b_ib_data[2000];
  int b_c_data[4000];
  na = a_size[0];
  nb = b_size[0];
  ncmax = a_size[0] + b_size[0];
  c_size[0] = (short)ncmax;
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
      c_data[nc] = ak;
      nia++;
      ia_data[nia] = iafirst;
      ialast = b_ialast + 1;
      iafirst = b_ialast + 1;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      nc++;
      nia++;
      c_data[nc] = ak;
      ia_data[nia] = iafirst;
      ialast = b_ialast + 1;
      iafirst = b_ialast + 1;
    } else {
      nc++;
      nib++;
      c_data[nc] = bk;
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
    c_data[nc] = a_data[ialast - 1];
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
    c_data[nc] = b_data[iblast - 1];
    ib_data[nib - 1] = iblast;
    iblast = b_iblast + 1;
  }

  if (a_size[0] > 0) {
    if (1 > nia + 1) {
      nb = -1;
    } else {
      nb = nia;
    }

    for (nia = 0; nia <= nb; nia++) {
      b_ia_data[nia] = ia_data[nia];
    }

    ia_size[0] = nb + 1;
    nb++;
    for (nia = 0; nia < nb; nia++) {
      ia_data[nia] = b_ia_data[nia];
    }
  }

  if (b_size[0] > 0) {
    if (1 > nib) {
      nb = 0;
    } else {
      nb = nib;
    }

    na = b_size[0];
    for (nia = 0; nia < na; nia++) {
      b_ib_data[nia] = (short)ib_data[nia];
    }

    ib_size[0] = nb;
    for (nia = 0; nia < nb; nia++) {
      ib_data[nia] = b_ib_data[nia];
    }
  }

  if (ncmax > 0) {
    if (1 > nc + 1) {
      nb = -1;
    } else {
      nb = nc;
    }

    for (nia = 0; nia <= nb; nia++) {
      b_c_data[nia] = c_data[nia];
    }

    c_size[0] = nb + 1;
    nb++;
    for (nia = 0; nia < nb; nia++) {
      c_data[nia] = b_c_data[nia];
    }
  }
}

//
// Arguments    : const int idx_data[]
//                const int idx_size[1]
//                double bPk_data[]
//                int bPk_size[1]
//                double bxPk_data[]
//                int bxPk_size[2]
//                double byPk_data[]
//                int byPk_size[2]
//                double wxPk_data[]
//                int wxPk_size[2]
// Return Type  : void
//
static void fetchPeakExtents(const int idx_data[], const int idx_size[1], double
  bPk_data[], int bPk_size[1], double bxPk_data[], int bxPk_size[2], double
  byPk_data[], int byPk_size[2], double wxPk_data[], int wxPk_size[2])
{
  int loop_ub;
  int i7;
  double b_bPk_data[4000];
  int bxPk_size_idx_0;
  int i8;
  int byPk_size_idx_0;
  static double b_bxPk_data[8000];
  int b_loop_ub;
  double b_byPk_data[8000];
  loop_ub = idx_size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    b_bPk_data[i7] = bPk_data[idx_data[i7] - 1];
  }

  bPk_size[0] = idx_size[0];
  loop_ub = idx_size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    bPk_data[i7] = b_bPk_data[i7];
  }

  bxPk_size_idx_0 = idx_size[0];
  loop_ub = idx_size[0];
  for (i7 = 0; i7 < 2; i7++) {
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_bxPk_data[i8 + bxPk_size_idx_0 * i7] = bxPk_data[(idx_data[i8] +
        bxPk_size[0] * i7) - 1];
    }
  }

  bxPk_size[0] = idx_size[0];
  bxPk_size[1] = 2;
  byPk_size_idx_0 = idx_size[0];
  loop_ub = idx_size[0];
  b_loop_ub = idx_size[0];
  for (i7 = 0; i7 < 2; i7++) {
    for (i8 = 0; i8 < loop_ub; i8++) {
      bxPk_data[i8 + bxPk_size[0] * i7] = b_bxPk_data[i8 + bxPk_size_idx_0 * i7];
    }

    for (i8 = 0; i8 < b_loop_ub; i8++) {
      b_byPk_data[i8 + byPk_size_idx_0 * i7] = byPk_data[(idx_data[i8] +
        byPk_size[0] * i7) - 1];
    }
  }

  byPk_size[0] = idx_size[0];
  byPk_size[1] = 2;
  bxPk_size_idx_0 = idx_size[0];
  loop_ub = idx_size[0];
  b_loop_ub = idx_size[0];
  for (i7 = 0; i7 < 2; i7++) {
    for (i8 = 0; i8 < loop_ub; i8++) {
      byPk_data[i8 + byPk_size[0] * i7] = b_byPk_data[i8 + byPk_size_idx_0 * i7];
    }

    for (i8 = 0; i8 < b_loop_ub; i8++) {
      b_bxPk_data[i8 + bxPk_size_idx_0 * i7] = wxPk_data[(idx_data[i8] +
        wxPk_size[0] * i7) - 1];
    }
  }

  wxPk_size[0] = idx_size[0];
  wxPk_size[1] = 2;
  loop_ub = idx_size[0];
  for (i7 = 0; i7 < 2; i7++) {
    for (i8 = 0; i8 < loop_ub; i8++) {
      wxPk_data[i8 + wxPk_size[0] * i7] = b_bxPk_data[i8 + bxPk_size_idx_0 * i7];
    }
  }
}

//
// Arguments    : const float y[2000]
//                int iPk_data[]
//                int iPk_size[1]
//                const int iFin_data[]
//                const int iFin_size[1]
//                const int iInf_data[]
//                const int iInf_size[1]
//                const int iInflect_data[]
//                const int iInflect_size[1]
//                double bPk_data[]
//                int bPk_size[1]
//                double bxPk_data[]
//                int bxPk_size[2]
//                double byPk_data[]
//                int byPk_size[2]
//                double wxPk_data[]
//                int wxPk_size[2]
// Return Type  : void
//
static void findExtents(const float y[2000], int iPk_data[], int iPk_size[1],
  const int iFin_data[], const int iFin_size[1], const int iInf_data[], const
  int iInf_size[1], const int iInflect_data[], const int iInflect_size[1],
  double bPk_data[], int bPk_size[1], double bxPk_data[], int bxPk_size[2],
  double byPk_data[], int byPk_size[2], double wxPk_data[], int wxPk_size[2])
{
  float yFinite[2000];
  int loop_ub;
  int u0;
  float b_bPk_data[2000];
  int b_bPk_size[1];
  int iLB_data[2000];
  int iLB_size[1];
  int iRB_data[2000];
  int iRB_size[1];
  int b_iPk_size[1];
  int b_iPk_data[2000];
  static double b_wxPk_data[4000];
  int b_wxPk_size[2];
  int iInfR_data[2000];
  int iInfR_size[1];
  int iInfL_data[2000];
  int iInfL_size[1];
  int c_data[2000];
  int c_size[1];
  int iFinite_data[2000];
  short unnamed_idx_0;
  int iInfinite_data[2000];
  short tmp_data[2000];
  int i4;
  memcpy(&yFinite[0], &y[0], 2000U * sizeof(float));
  loop_ub = iInf_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    yFinite[iInf_data[u0] - 1] = ((real32_T)rtNaN);
  }

  getPeakBase(yFinite, iPk_data, iPk_size, iFin_data, iFin_size, iInflect_data,
              iInflect_size, b_bPk_data, b_bPk_size, iLB_data, iLB_size,
              iRB_data, iRB_size);
  b_iPk_size[0] = iPk_size[0];
  loop_ub = iPk_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    b_iPk_data[u0] = iPk_data[u0];
  }

  c_removePeaksBelowMinPeakPromin(yFinite, b_iPk_data, b_iPk_size, b_bPk_data,
    b_bPk_size, iLB_data, iLB_size, iRB_data, iRB_size);
  getPeakWidth(yFinite, b_iPk_data, b_iPk_size, b_bPk_data, b_bPk_size, iLB_data,
               iLB_size, iRB_data, iRB_size, b_wxPk_data, b_wxPk_size);
  do_vectors(b_iPk_data, b_iPk_size, iInf_data, iInf_size, iPk_data, iPk_size,
             iInfR_data, iInfR_size, iInfL_data, iInfL_size);
  b_do_vectors(iPk_data, iPk_size, b_iPk_data, b_iPk_size, c_data, c_size,
               iInfR_data, iInfR_size, iInfL_data, iInfL_size);
  loop_ub = iInfR_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    iFinite_data[u0] = iInfR_data[u0];
  }

  b_do_vectors(iPk_data, iPk_size, iInf_data, iInf_size, c_data, c_size,
               iInfR_data, iInfR_size, iInfL_data, iInfL_size);
  loop_ub = iInfR_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    iInfinite_data[u0] = iInfR_data[u0];
  }

  unnamed_idx_0 = (short)iPk_size[0];
  bPk_size[0] = unnamed_idx_0;
  loop_ub = unnamed_idx_0;
  for (u0 = 0; u0 < loop_ub; u0++) {
    bPk_data[u0] = 0.0;
  }

  loop_ub = b_bPk_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    bPk_data[iFinite_data[u0] - 1] = b_bPk_data[u0];
  }

  loop_ub = iInfR_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    b_iPk_data[u0] = iInfinite_data[u0];
  }

  loop_ub = iInfR_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    bPk_data[b_iPk_data[u0] - 1] = 0.0;
  }

  loop_ub = iInf_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    b_iPk_data[u0] = iInf_data[u0] - 1;
  }

  for (loop_ub = 0; loop_ub + 1 <= (short)iInf_size[0]; loop_ub++) {
    if (b_iPk_data[loop_ub] < 1) {
      iInfL_data[loop_ub] = 1;
    } else {
      iInfL_data[loop_ub] = b_iPk_data[loop_ub];
    }
  }

  loop_ub = iInf_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    b_iPk_data[u0] = iInf_data[u0] + 1;
  }

  for (loop_ub = 0; loop_ub + 1 <= (short)iInf_size[0]; loop_ub++) {
    u0 = b_iPk_data[loop_ub];
    if (!(u0 < 2000)) {
      u0 = 2000;
    }

    iInfR_data[loop_ub] = u0;
  }

  bxPk_size[0] = iPk_size[0];
  bxPk_size[1] = 2;
  loop_ub = iPk_size[0] << 1;
  for (u0 = 0; u0 < loop_ub; u0++) {
    bxPk_data[u0] = 0.0;
  }

  loop_ub = iLB_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    tmp_data[u0] = (short)(1 + (short)(iLB_data[u0] - 1));
  }

  loop_ub = iLB_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    bxPk_data[iFinite_data[u0] - 1] = tmp_data[u0];
  }

  loop_ub = iRB_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    tmp_data[u0] = (short)(1 + (short)(iRB_data[u0] - 1));
  }

  loop_ub = iRB_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    bxPk_data[(iFinite_data[u0] + bxPk_size[0]) - 1] = tmp_data[u0];
  }

  loop_ub = iInf_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    bxPk_data[iInfinite_data[u0] - 1] = 0.5 * (double)(short)((short)((short)
      (iInf_data[u0] - 1) + (short)(iInfL_data[u0] - 1)) + 2);
  }

  loop_ub = iInf_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    bxPk_data[(iInfinite_data[u0] + bxPk_size[0]) - 1] = 0.5 * (double)(short)
      ((short)((short)(iInf_data[u0] - 1) + (short)(iInfR_data[u0] - 1)) + 2);
  }

  byPk_size[0] = iPk_size[0];
  byPk_size[1] = 2;
  loop_ub = iPk_size[0] << 1;
  for (u0 = 0; u0 < loop_ub; u0++) {
    byPk_data[u0] = 0.0;
  }

  loop_ub = iLB_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    byPk_data[iFinite_data[u0] - 1] = y[iLB_data[u0] - 1];
  }

  loop_ub = iRB_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    byPk_data[(iFinite_data[u0] + byPk_size[0]) - 1] = y[iRB_data[u0] - 1];
  }

  loop_ub = (short)iInf_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    byPk_data[iInfinite_data[u0] - 1] = y[iInfL_data[u0] - 1];
  }

  loop_ub = (short)iInf_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    byPk_data[(iInfinite_data[u0] + byPk_size[0]) - 1] = y[iInfR_data[u0] - 1];
  }

  wxPk_size[0] = iPk_size[0];
  wxPk_size[1] = 2;
  loop_ub = iPk_size[0] << 1;
  for (u0 = 0; u0 < loop_ub; u0++) {
    wxPk_data[u0] = 0.0;
  }

  loop_ub = b_wxPk_size[0];
  for (u0 = 0; u0 < 2; u0++) {
    for (i4 = 0; i4 < loop_ub; i4++) {
      wxPk_data[(iFinite_data[i4] + wxPk_size[0] * u0) - 1] = b_wxPk_data[i4 +
        b_wxPk_size[0] * u0];
    }
  }

  loop_ub = iInf_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    wxPk_data[iInfinite_data[u0] - 1] = 0.5 * (double)(short)((short)((short)
      (iInf_data[u0] - 1) + (short)(iInfL_data[u0] - 1)) + 2);
  }

  loop_ub = iInf_size[0];
  for (u0 = 0; u0 < loop_ub; u0++) {
    wxPk_data[(iInfinite_data[u0] + wxPk_size[0]) - 1] = 0.5 * (double)(short)
      ((short)((short)(iInf_data[u0] - 1) + (short)(iInfR_data[u0] - 1)) + 2);
  }
}

//
// Arguments    : const float y[2000]
//                int *idx
//                int borderIdx
//                float refHeight
// Return Type  : void
//
static void findLeftIntercept(const float y[2000], int *idx, int borderIdx,
  float refHeight)
{
  while ((*idx >= borderIdx) && (y[*idx - 1] > refHeight)) {
    (*idx)--;
  }
}

//
// Arguments    : const float y[2000]
//                int *idx
//                int borderIdx
//                float refHeight
// Return Type  : void
//
static void findRightIntercept(const float y[2000], int *idx, int borderIdx,
  float refHeight)
{
  while ((*idx <= borderIdx) && (y[*idx - 1] > refHeight)) {
    (*idx)++;
  }
}

//
// Arguments    : int x_data[]
//                int x_size[1]
// Return Type  : void
//
static void flipud(int x_data[], int x_size[1])
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
// Arguments    : const float y[2000]
//                int iPk_data[]
//                int iPk_size[1]
//                int iInf_data[]
//                int iInf_size[1]
//                int iInflect_data[]
//                int iInflect_size[1]
// Return Type  : void
//
static void getAllPeaksCodegen(const float y[2000], int iPk_data[], int
  iPk_size[1], int iInf_data[], int iInf_size[1], int iInflect_data[], int
  iInflect_size[1])
{
  int nPk;
  int nInf;
  int nInflect;
  char dir;
  int kfirst;
  float ykfirst;
  boolean_T isinfykfirst;
  int k;
  float yk;
  boolean_T isinfyk;
  char previousdir;
  int i1;
  nPk = 0;
  nInf = 0;
  nInflect = -1;
  dir = 'n';
  kfirst = 0;
  ykfirst = ((real32_T)rtInf);
  isinfykfirst = true;
  for (k = 0; k < 2000; k++) {
    yk = y[k];
    if (rtIsNaNF(y[k])) {
      yk = ((real32_T)rtInf);
      isinfyk = true;
    } else if (rtIsInfF(y[k]) && (y[k] > 0.0F)) {
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

  if ((!isinfykfirst) && ((nInflect + 1 == 0) || (iInflect_data[nInflect] < 2000)))
  {
    nInflect++;
    iInflect_data[nInflect] = 2000;
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
// Arguments    : const float y[2000]
//                const int iPk_data[]
//                const int iPk_size[1]
//                const float base_data[]
//                const int iLB_data[]
//                const int iRB_data[]
//                double bounds_data[]
//                int bounds_size[2]
// Return Type  : void
//
static void getHalfMaxBounds(const float y[2000], const int iPk_data[], const
  int iPk_size[1], const float base_data[], const int iLB_data[], const int
  iRB_data[], double bounds_data[], int bounds_size[2])
{
  int iLeft;
  int iRight;
  int i;
  float refHeight;
  bounds_size[0] = iPk_size[0];
  bounds_size[1] = 2;
  iLeft = iPk_size[0] << 1;
  for (iRight = 0; iRight < iLeft; iRight++) {
    bounds_data[iRight] = 0.0;
  }

  for (i = 0; i < iPk_size[0]; i++) {
    refHeight = (y[iPk_data[i] - 1] + base_data[i]) / 2.0F;
    iLeft = iPk_data[i];
    findLeftIntercept(y, &iLeft, iLB_data[i], refHeight);
    if (iLeft < iLB_data[i]) {
      bounds_data[i] = 1.0 + ((double)iLB_data[i] - 1.0);
    } else {
      bounds_data[i] = linterp(1.0 + ((double)iLeft - 1.0), 1.0 + ((double)
        (iLeft + 1) - 1.0), y[iLeft - 1], y[iLeft], y[iPk_data[i] - 1],
        base_data[i]);
    }

    iRight = iPk_data[i];
    findRightIntercept(y, &iRight, iRB_data[i], refHeight);
    if (iRight > iRB_data[i]) {
      bounds_data[i + bounds_size[0]] = 1.0 + ((double)iRB_data[i] - 1.0);
    } else {
      bounds_data[i + bounds_size[0]] = linterp(1.0 + ((double)iRight - 1.0),
        1.0 + ((double)(iRight - 1) - 1.0), y[iRight - 1], y[iRight - 2],
        y[iPk_data[i] - 1], base_data[i]);
    }
  }
}

//
// Arguments    : const float yTemp[2000]
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
static void getLeftBase(const float yTemp[2000], const int iPeak_data[], const
  int iPeak_size[1], const int iFinite_data[], const int iFinite_size[1], const
  int iInflect_data[], int iBase_data[], int iBase_size[1], int iSaddle_data[],
  int iSaddle_size[1])
{
  int n;
  int i;
  static double peak_data[2000];
  double valley_data[2000];
  int iValley_data[2000];
  int j;
  int k;
  float v;
  int iv;
  float p;
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

  n = (short)iFinite_size[0];
  for (i = 0; i < n; i++) {
    peak_data[i] = 0.0;
  }

  n = (short)iFinite_size[0];
  for (i = 0; i < n; i++) {
    valley_data[i] = 0.0;
  }

  n = (short)iFinite_size[0];
  for (i = 0; i < n; i++) {
    iValley_data[i] = 0;
  }

  n = -1;
  i = 0;
  j = 0;
  k = 0;
  v = ((real32_T)rtNaN);
  iv = 1;
  while (k + 1 <= iPeak_size[0]) {
    while (iInflect_data[i] != iFinite_data[j]) {
      v = yTemp[iInflect_data[i] - 1];
      iv = iInflect_data[i];
      if (rtIsNaNF(yTemp[iInflect_data[i] - 1])) {
        n = -1;
      } else {
        while ((n + 1 > 0) && (valley_data[n] > v)) {
          n--;
        }
      }

      i++;
    }

    p = yTemp[iInflect_data[i] - 1];
    while ((n + 1 > 0) && (peak_data[n] < p)) {
      if (valley_data[n] < v) {
        v = (float)valley_data[n];
        iv = iValley_data[n];
      }

      n--;
    }

    isv = iv;
    while ((n + 1 > 0) && (peak_data[n] <= p)) {
      if (valley_data[n] < v) {
        v = (float)valley_data[n];
        iv = iValley_data[n];
      }

      n--;
    }

    n++;
    peak_data[n] = yTemp[iInflect_data[i] - 1];
    valley_data[n] = v;
    iValley_data[n] = iv;
    if (iInflect_data[i] == iPeak_data[k]) {
      iBase_data[k] = iv;
      iSaddle_data[k] = isv;
      k++;
    }

    i++;
    j++;
  }
}

//
// Arguments    : const float yTemp[2000]
//                const int iPk_data[]
//                const int iPk_size[1]
//                const int iFin_data[]
//                const int iFin_size[1]
//                const int iInflect_data[]
//                const int iInflect_size[1]
//                float peakBase_data[]
//                int peakBase_size[1]
//                int iLeftSaddle_data[]
//                int iLeftSaddle_size[1]
//                int iRightSaddle_data[]
//                int iRightSaddle_size[1]
// Return Type  : void
//
static void getPeakBase(const float yTemp[2000], const int iPk_data[], const int
  iPk_size[1], const int iFin_data[], const int iFin_size[1], const int
  iInflect_data[], const int iInflect_size[1], float peakBase_data[], int
  peakBase_size[1], int iLeftSaddle_data[], int iLeftSaddle_size[1], int
  iRightSaddle_data[], int iRightSaddle_size[1])
{
  int iLeftBase_data[2000];
  int iLeftBase_size[1];
  int tmp_size[1];
  int loop_ub;
  int i2;
  int tmp_data[2000];
  int b_tmp_size[1];
  int b_tmp_data[2000];
  int c_tmp_size[1];
  int c_tmp_data[2000];
  int iRightBase_data[2000];
  short csz_idx_0;
  getLeftBase(yTemp, iPk_data, iPk_size, iFin_data, iFin_size, iInflect_data,
              iLeftBase_data, iLeftBase_size, iLeftSaddle_data, iLeftSaddle_size);
  tmp_size[0] = iPk_size[0];
  loop_ub = iPk_size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    tmp_data[i2] = iPk_data[i2];
  }

  flipud(tmp_data, tmp_size);
  b_tmp_size[0] = iFin_size[0];
  loop_ub = iFin_size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_tmp_data[i2] = iFin_data[i2];
  }

  flipud(b_tmp_data, b_tmp_size);
  c_tmp_size[0] = iInflect_size[0];
  loop_ub = iInflect_size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    c_tmp_data[i2] = iInflect_data[i2];
  }

  flipud(c_tmp_data, c_tmp_size);
  getLeftBase(yTemp, tmp_data, tmp_size, b_tmp_data, b_tmp_size, c_tmp_data,
              iRightBase_data, c_tmp_size, iRightSaddle_data, iRightSaddle_size);
  flipud(iRightBase_data, c_tmp_size);
  flipud(iRightSaddle_data, iRightSaddle_size);
  if (iLeftBase_size[0] <= c_tmp_size[0]) {
    csz_idx_0 = (short)iLeftBase_size[0];
    peakBase_size[0] = (short)iLeftBase_size[0];
  } else {
    csz_idx_0 = (short)c_tmp_size[0];
    peakBase_size[0] = (short)c_tmp_size[0];
  }

  for (loop_ub = 0; loop_ub + 1 <= csz_idx_0; loop_ub++) {
    if ((yTemp[iLeftBase_data[loop_ub] - 1] > yTemp[iRightBase_data[loop_ub] - 1])
        || rtIsNaNF(yTemp[iRightBase_data[loop_ub] - 1])) {
      peakBase_data[loop_ub] = yTemp[iLeftBase_data[loop_ub] - 1];
    } else {
      peakBase_data[loop_ub] = yTemp[iRightBase_data[loop_ub] - 1];
    }
  }
}

//
// Arguments    : const float y[2000]
//                const int iPk_data[]
//                const int iPk_size[1]
//                const float pbPk_data[]
//                const int pbPk_size[1]
//                int iLB_data[]
//                int iLB_size[1]
//                int iRB_data[]
//                int iRB_size[1]
//                double wxPk_data[]
//                int wxPk_size[2]
// Return Type  : void
//
static void getPeakWidth(const float y[2000], const int iPk_data[], const int
  iPk_size[1], const float pbPk_data[], const int pbPk_size[1], int iLB_data[],
  int iLB_size[1], int iRB_data[], int iRB_size[1], double wxPk_data[], int
  wxPk_size[2])
{
  int loop_ub;
  int i5;
  float base_data[2000];
  if (iPk_size[0] == 0) {
    iLB_size[0] = 0;
    iRB_size[0] = 0;
  } else {
    loop_ub = pbPk_size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      base_data[i5] = pbPk_data[i5];
    }
  }

  getHalfMaxBounds(y, iPk_data, iPk_size, base_data, iLB_data, iRB_data,
                   wxPk_data, wxPk_size);
}

//
// Arguments    : int idx_data[]
//                int idx_size[1]
// Return Type  : void
//
static void keepAtMostNpPeaks(int idx_data[], int idx_size[1])
{
  int b_idx_data[4000];
  int i6;
  if (idx_size[0] > 2000) {
    memcpy(&b_idx_data[0], &idx_data[0], 2000U * sizeof(int));
    idx_size[0] = 2000;
    for (i6 = 0; i6 < 2000; i6++) {
      idx_data[i6] = b_idx_data[i6];
    }
  }
}

//
// Arguments    : double xa
//                double xb
//                float ya
//                float yb
//                float yc
//                float bc
// Return Type  : float
//
static float linterp(double xa, double xb, float ya, float yb, float yc, float
                     bc)
{
  float xc;
  xc = (float)xa + (float)(xb - xa) * (0.5F * (yc + bc) - ya) / (yb - ya);
  if (rtIsNaNF(xc)) {
    if (rtIsInfF(bc)) {
      xc = (float)(0.5 * (xa + xb));
    } else {
      xc = (float)xb;
    }
  }

  return xc;
}

//
// Arguments    : const float y[2000]
//                const int iFinite_data[]
//                const int iFinite_size[1]
//                int iPk_data[]
//                int iPk_size[1]
// Return Type  : void
//
static void removeSmallPeaks(const float y[2000], const int iFinite_data[],
  const int iFinite_size[1], int iPk_data[], int iPk_size[1])
{
  int nPk;
  int k;
  float b_y;
  nPk = 0;
  for (k = 0; k + 1 <= iFinite_size[0]; k++) {
    if (y[iFinite_data[k] - 1] > ((real32_T)rtMinusInf)) {
      if ((y[iFinite_data[k] - 2] > y[iFinite_data[k]]) || rtIsNaNF
          (y[iFinite_data[k]])) {
        b_y = y[iFinite_data[k] - 2];
      } else {
        b_y = y[iFinite_data[k]];
      }

      if (y[iFinite_data[k] - 1] - b_y >= 0.0F) {
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
// count_blinks:
// Arguments    : const float X[2000]
// Return Type  : double
//
double count_blinks(const float X[2000])
{
  int iFinite_data[2000];
  int iFinite_size[1];
  int iInfinite_data[2000];
  int iInfinite_size[1];
  int iInflect_data[2000];
  int iInflect_size[1];
  int tmp_data[2000];
  int tmp_size[1];
  int iPk_size[1];
  int loop_ub;
  int i0;
  static int iPk_data[4000];
  static double bPk_data[4000];
  int bPk_size[1];
  static double bxPk_data[8000];
  int bxPk_size[2];
  static double byPk_data[8000];
  int byPk_size[2];
  static double wxPk_data[8000];
  int wxPk_size[2];
  static int idx_data[4000];
  int b_iPk_size[1];
  static int b_iPk_data[4000];
  static float Ypk_data[4000];
  static double Xpk_data[4000];
  static double Wpk_data[4000];
  static float Ppk_data[4000];
  getAllPeaksCodegen(X, iFinite_data, iFinite_size, iInfinite_data,
                     iInfinite_size, iInflect_data, iInflect_size);
  removeSmallPeaks(X, iFinite_data, iFinite_size, tmp_data, tmp_size);
  iPk_size[0] = tmp_size[0];
  loop_ub = tmp_size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    iPk_data[i0] = tmp_data[i0];
  }

  findExtents(X, iPk_data, iPk_size, iFinite_data, iFinite_size, iInfinite_data,
              iInfinite_size, iInflect_data, iInflect_size, bPk_data, bPk_size,
              bxPk_data, bxPk_size, byPk_data, byPk_size, wxPk_data, wxPk_size);
  c_findPeaksSeparatedByMoreThanM(iPk_size, idx_data, tmp_size);
  keepAtMostNpPeaks(idx_data, tmp_size);
  fetchPeakExtents(idx_data, tmp_size, bPk_data, bPk_size, bxPk_data, bxPk_size,
                   byPk_data, byPk_size, wxPk_data, wxPk_size);
  b_iPk_size[0] = tmp_size[0];
  loop_ub = tmp_size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_iPk_data[i0] = iPk_data[idx_data[i0] - 1];
  }

  assignFullOutputs(X, b_iPk_data, b_iPk_size, wxPk_data, wxPk_size, bPk_data,
                    Ypk_data, tmp_size, Xpk_data, iFinite_size, Wpk_data,
                    iInfinite_size, Ppk_data, iInflect_size);
  return tmp_size[0];
}

//
// Arguments    : void
// Return Type  : void
//
void count_blinks_initialize()
{
  rt_InitInfAndNaN(8U);
}

//
// Arguments    : void
// Return Type  : void
//
void count_blinks_terminate()
{
  // (no terminate code required)
}

//
// File trailer for count_blinks.cpp
//
// [EOF]
//
