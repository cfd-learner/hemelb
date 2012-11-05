// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "topology/NetworkTopology.h"
#include "util/utilityFunctions.h"
#include "vis/Screen.h"

namespace hemelb
{
  namespace vis
  {

    Screen::Screen()
    {
    }

    Screen::~Screen()
    {
    }

    void Screen::Set(float maxX,
                     float maxY,
                     int pixelsX,
                     int pixelsY,
                     float rad,
                     const Viewpoint* viewpoint)
    {
      MaxXValue = maxX;
      MaxYValue = maxY;

      mPixelUnitVectorProjectionX
          = viewpoint->RotateCameraCoordinatesToWorldCoordinates(util::Vector3D<float>(MaxXValue,
                                                                                       0.0F,
                                                                                       0.0F));
      mPixelUnitVectorProjectionY
          = viewpoint-> RotateCameraCoordinatesToWorldCoordinates(util::Vector3D<float>(0.0F,
                                                                                        MaxYValue,
                                                                                        0.0F));

      Resize(pixelsX, pixelsY);

      mPixelsPerUnitX = (float) GetPixelsX() / (2.F * MaxXValue);
      mPixelsPerUnitY = (float) GetPixelsY() / (2.F * MaxYValue);

      util::Vector3D<float>
          lCameraToLocalCentreVector =
              viewpoint->RotateCameraCoordinatesToWorldCoordinates(util::Vector3D<float>(0.F,
                                                                                         0.F,
                                                                                         -viewpoint->GetDistanceFromCameraToScreen()));

      util::Vector3D<float> lMiddleCentreToMiddleRightOfScreen =
          viewpoint->RotateCameraCoordinatesToWorldCoordinates(util::Vector3D<float>(MaxXValue,
                                                                                     0.0F,
                                                                                     0.0F));

      util::Vector3D<float> lLowerCentreToTopCentreOfScreen =
          viewpoint->RotateCameraCoordinatesToWorldCoordinates(util::Vector3D<float>(0.0F,
                                                                                     MaxYValue,
                                                                                     0.0F));

      mCameraToBottomLeftOfScreen = (lCameraToLocalCentreVector
          - lMiddleCentreToMiddleRightOfScreen) - lLowerCentreToTopCentreOfScreen;

      mPixelUnitVectorProjectionX = lMiddleCentreToMiddleRightOfScreen * (2.F
          / (float) GetPixelsX());

      mPixelUnitVectorProjectionY = lLowerCentreToTopCentreOfScreen * (2.F / (float) GetPixelsY());
    }

    void Screen::Resize(unsigned int newPixelsX, unsigned int newPixelsY)
    {
      if (newPixelsX * newPixelsY <= COLOURED_PIXELS_MAX)
      {
        xPixels = newPixelsX;
        yPixels = newPixelsY;
      }
    }

    const util::Vector3D<float>& Screen::GetCameraToBottomLeftOfScreenVector() const
    {
      return mCameraToBottomLeftOfScreen;
    }
    const util::Vector3D<float>& Screen::GetPixelUnitVectorProjectionX() const
    {
      return mPixelUnitVectorProjectionX;
    }
    const util::Vector3D<float>& Screen::GetPixelUnitVectorProjectionY() const
    {
      return mPixelUnitVectorProjectionY;
    }
    int Screen::GetPixelsX() const
    {
      return xPixels;
    }
    int Screen::GetPixelsY() const
    {
      return yPixels;
    }
  }
}
