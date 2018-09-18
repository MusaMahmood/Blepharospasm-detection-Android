//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bleph_analyze_data.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 18-Sep-2018 17:05:52
//

// Include Files
#include "rt_nonfinite.h"
#include "bleph_analyze_data.h"

// Function Declarations
static float mean(const float x_data[], const int x_size[1]);

// Function Definitions

//
// Arguments    : const float x_data[]
//                const int x_size[1]
// Return Type  : float
//
static float mean(const float x_data[], const int x_size[1])
{
  float y;
  int k;
  if (x_size[0] == 0) {
    y = 0.0F;
  } else {
    y = x_data[0];
    for (k = 2; k <= x_size[0]; k++) {
      y += x_data[k - 1];
    }
  }

  y /= (float)x_size[0];
  return y;
}

//
// bleph_analyze_data Creates a summary from classification data
//  Input = (60, 8) in the form of [480, 1] concatenated together:
// Arguments    : const float classifyIn_concat[480]
//                double count[3]
//                double symptoms[4]
// Return Type  : void
//
void bleph_analyze_data(const float classifyIn_concat[480], double count[3],
  double symptoms[4])
{
  int i;
  boolean_T idx[480];
  int itmp;
  double mtmp;
  int trueCount;
  int classifyIn_concat_size[1];
  signed char tmp_data[60];
  float classifyIn_concat_data[60];

  //  Columns are as follows:
  //     1   |    2    |    3    |    4    |      5      |    6     |       7       |    8                               
  //  p2p mV | class 1 | class 2 | class 3 | outputClass | Severity | Number Blinks | Wavelet Energy (Haar mother wavelet) 
  //  we only really need 1, 5:8, rest is exported for good measure
  //  relevant_data = classifyIn(:, [~,5,6,7,8]);
  for (i = 0; i < 4; i++) {
    symptoms[i] = 0.0;
  }

  //   [ {Condition}, {Severity(1)}, {Severity(2)},  {Apraxia(probability)} ]
  //  Counts for each of the classes
  //  number_peaks = classifyIn(:, 7);
  //  energy = classifyIn(:, 8);
  memset(&idx[0], 0, 480U * sizeof(boolean_T));

  //  Normal
  //  Pathological Blink
  for (itmp = 0; itmp < 60; itmp++) {
    idx[itmp] = (classifyIn_concat[240 + itmp] == 0.0F);
    idx[60 + itmp] = (classifyIn_concat[240 + itmp] == 1.0F);
    idx[120 + itmp] = (classifyIn_concat[240 + itmp] == 2.0F);
  }

  //  Blepharospasm
  //  Separate Severities into Relevant classes
  for (i = 0; i < 3; i++) {
    mtmp = idx[60 * i];
    for (itmp = 0; itmp < 59; itmp++) {
      mtmp += (double)idx[(itmp + 60 * i) + 1];
    }

    count[i] = mtmp;
  }

  //  Primary Output Class:
  mtmp = count[0];
  itmp = 1;
  for (i = 0; i < 2; i++) {
    if (count[i + 1] > mtmp) {
      mtmp = count[i + 1];
      itmp = i + 2;
    }
  }

  symptoms[0] = (double)itmp - 1.0;

  //  Convert to zero-index
  if (itmp == 2) {
    //  Pathological Blinking
    trueCount = 0;
    for (i = 0; i < 60; i++) {
      if (idx[60 + i]) {
        trueCount++;
      }
    }

    itmp = 0;
    for (i = 0; i < 60; i++) {
      if (idx[60 + i]) {
        tmp_data[itmp] = (signed char)(i + 1);
        itmp++;
      }
    }

    classifyIn_concat_size[0] = trueCount;
    for (itmp = 0; itmp < trueCount; itmp++) {
      classifyIn_concat_data[itmp] = classifyIn_concat[tmp_data[itmp] + 299];
    }

    symptoms[1] = mean(classifyIn_concat_data, classifyIn_concat_size);
  } else {
    if (itmp == 3) {
      trueCount = 0;
      for (i = 0; i < 60; i++) {
        if (idx[120 + i]) {
          trueCount++;
        }
      }

      itmp = 0;
      for (i = 0; i < 60; i++) {
        if (idx[120 + i]) {
          tmp_data[itmp] = (signed char)(i + 1);
          itmp++;
        }
      }

      classifyIn_concat_size[0] = trueCount;
      for (itmp = 0; itmp < trueCount; itmp++) {
        classifyIn_concat_data[itmp] = classifyIn_concat[tmp_data[itmp] + 299];
      }

      symptoms[2] = mean(classifyIn_concat_data, classifyIn_concat_size);

      //  Blepharospasm
    }
  }
}

//
// Arguments    : void
// Return Type  : void
//
void bleph_analyze_data_initialize()
{
  rt_InitInfAndNaN(8U);
}

//
// Arguments    : void
// Return Type  : void
//
void bleph_analyze_data_terminate()
{
  // (no terminate code required)
}

//
// File trailer for bleph_analyze_data.cpp
//
// [EOF]
//
