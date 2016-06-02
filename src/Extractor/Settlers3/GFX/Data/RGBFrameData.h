/*******************************************************************************
 * Settlers Extractor - A program To extract data file for the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/
#ifndef EXTRACTOR_SETTLERS3_GFX_DATA_RGBFRAMEDATA_H_
#define EXTRACTOR_SETTLERS3_GFX_DATA_RGBFRAMEDATA_H_

#include <string>
#include "../../../../Functions/DataReader.h"
#include "../../../../Functions/To.h"
#include "RGBImageData.h"
namespace Extractor{
	namespace Settlers3{
		class RGBFrameData {
		private:

			unsigned int sequenceCode = 0;			//@offset:00(2) - 0x1402
			unsigned short sequenceHeaderSize = 0;	//@offset:04(2) - 8
			unsigned char sequenceUnknown06 = 0;	//@offset:06(1) - 0
			unsigned char count = 0;				//@offset:07(1)

			RGBImageData** frames=NULL;
		public:

			RGBFrameData(Functions::DataReader* reader, unsigned int offset, RGBImageData::enumIMGType gfxType,unsigned int colourCode = 0);
			virtual ~RGBFrameData();

			bool SaveFileData(std::string location);
			RGBImageData* ReturnImage(unsigned char frame){return this->frames[frame];};

		};
	}
}
#endif