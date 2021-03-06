/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef EXTRACTOR_SETTLERS3_GFX_PALETTEFRAMEDATA_H
#define EXTRACTOR_SETTLERS3_GFX_PALETTEFRAMEDATA_H
#include <string>
#include "../../../Functions/File/DataReader.h"
#include "../../../Functions/To.h"
#include "PaletteImageData.h"

namespace Extractor{
	namespace Settlers3{
		class PaletteFrameData{
		private:

			unsigned int sequenceCode = 0;			//@offset:00(4) - 0x1402
			unsigned short sequenceHeaderSize = 0;	//@offset:04(2) - 8
			unsigned char sequenceUnknown06;		//@offset:06(1)
			unsigned char count = 0;				//@offset:07(1)

			PaletteImageData** frames=NULL;

		public:

			PaletteFrameData(Functions::DataReader* reader, unsigned int offset,RGBA* Palette = NULL);
			~PaletteFrameData();

			bool SaveToFile(std::string location);
			PaletteImageData* ReturnImage(unsigned char frame){return this->frames[frame]->ReturnImage();};
		};
	}
}

#endif