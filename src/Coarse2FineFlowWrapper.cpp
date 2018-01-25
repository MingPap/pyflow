// This is a wrapper for Ce Liu's Coarse2Fine optical flow implementation.
// It converts the contiguous image array to the format needed by the optical
// flow code. Handling conversion in the wrapper makes the cythonization
// simpler.
// Author: Deepak Pathak (c) 2016

#include "Coarse2FineFlowWrapper.h"
#include "Image.h"
#include "OpticalFlow.h"
using namespace std;

void Coarse2FineFlowWrapper(double * vx, double * vy, double * warpI2,
                              const double * Im1, const double * Im2,
                              double alpha, double ratio, int minWidth,
                              int nOuterFPIterations, int nInnerFPIterations,
                              int nSORIterations, int colType,
                              int h, int w, int c,
                              bool verbose, double threshold) {
  DImage ImFormatted1, ImFormatted2;
  DImage vxFormatted, vyFormatted, warpI2Formatted;

  // format input in the format needed by backend
  ImFormatted1.allocate(w, h, c);
  ImFormatted2.allocate(w, h, c);
  memcpy(ImFormatted1.pData, Im1, h * w * c * sizeof(double));
  memcpy(ImFormatted2.pData, Im2, h * w * c * sizeof(double));
  ImFormatted1.setColorType(colType);
  ImFormatted2.setColorType(colType);

  // call optical flow backend
  OpticalFlow::Coarse2FineFlow(vxFormatted, vyFormatted, warpI2Formatted,
                                ImFormatted1, ImFormatted2,
                                alpha, ratio, minWidth,
                                nOuterFPIterations, nInnerFPIterations,
                                nSORIterations,
                                verbose, threshold);

  // copy formatted output to a contiguous memory to be returned
  memcpy(vx, vxFormatted.pData, h * w * sizeof(double));
  memcpy(vy, vyFormatted.pData, h * w * sizeof(double));
  memcpy(warpI2, warpI2Formatted.pData, h * w * c * sizeof(double));

  // clear c memory
  ImFormatted1.clear();
  ImFormatted2.clear();
  vxFormatted.clear();
  vyFormatted.clear();
  warpI2Formatted.clear();

  return;
}

void warpMaskFL(double *warpMask, const double *Mask,
                const double *vx, const double *vy,
                int colType, int h, int w, int c) {
  
  DImage MaskFormatted, vxFormatted, vyFormatted, warpMaskFormatted;

  // format input in the format needed by backend
  MaskFormatted.allocate(w, h, c);
  memcpy(MaskFormatted.pData, Mask, h * w * c * sizeof(double));
  MaskFormatted.setColorType(colType);
  vxFormatted.allocate(w, h);
  memcpy(vxFormatted.pData, vx, h * w * sizeof(double));
  vyFormatted.allocate(w, h);
  memcpy(vyFormatted.pData, vy, h * w * sizeof(double));

  // call optical flow backend
  OpticalFlow::warpMaskFL(warpMaskFormatted, MaskFormatted, vxFormatted, vyFormatted);

  // copy formatted output to a contiguous memory to be returned
  memcpy(warpMask, warpMaskFormatted.pData, h * w * c * sizeof(double));

  // clear c memory
  MaskFormatted.clear();
  vxFormatted.clear();
  vyFormatted.clear();
  warpMaskFormatted.clear();

  return;
}
