/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef EXTRACTOR_SETTLERS3_GFX_GFXPALETTE_H
#define EXTRACTOR_SETTLERS3_GFX_GFXPALETTE_H
#include <string>
#include "../../../Functions/To.h"
#include "../../../Functions/File/Functions.h"
#include "../../../Functions/File/Save.h"
#include "../../../Functions/File/DataReader.h"
#include "../../../Functions/Image/RGBA.h"
#include "../../../Functions/Image/Palette.h"

namespace Extractor{
	namespace Settlers3{
		class GFXPalette{
		private:
			//Header
			unsigned int headerID;		//- @offset:00(4)
			unsigned short headerSize;	//- @offset:04(2)
			unsigned short count=0;		//- @offset:06(2)
			unsigned int sizeofPalette;	//- @offset:08(4)

			RGBA*** palettes = NULL;

		public:
			GFXPalette(Functions::DataReader* reader, unsigned int offset,unsigned int colourCode);
			~GFXPalette();

			bool SaveToFile(std::string location);
			RGBA*** ReturnPalettes(){return this->palettes;};
		};
	}
}

#endif