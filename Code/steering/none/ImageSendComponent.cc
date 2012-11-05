// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "steering/ImageSendComponent.h"

namespace hemelb
{
  namespace steering
  {
    ImageSendComponent::ImageSendComponent(lb::SimulationState* iSimState,
                                           vis::Control* iControl,
                                           const lb::LbmParameters* iLbmParams,
                                           Network* iNetwork,
                                           unsigned int inletCountIn): inletCount(inletCountIn), MaxFramerate(25.0)
    {

    }

    ImageSendComponent::~ImageSendComponent()
    {
    }

    void ImageSendComponent::DoWork(const vis::PixelSet<vis::ResultPixel>* pix)
    {

    }

    bool ImageSendComponent::ShouldRenderNewNetworkImage()
    {
      return false;
    }
  }
}
