/*******************************************************************************
 * Settlers Extractor - A program To extract data file for the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#pragma once
#include <string>
#include <vector>
#include "../../../Functions/File/DataReader.h"
#include "../../../Functions/File/Image.h"
#include "../../../Functions/Image/PaletteImage.h"
#include "../../../Functions/To.h"
#include "../../../Log.h"

namespace Extractor{
	namespace Settlers2{
		class PlayerColouredBitmap : public Functions::PaletteImage{
		private:
			unsigned char* image2 = NULL;
			bool* transparency2 = NULL;
		public:
			PlayerColouredBitmap(Functions::DataReader* reader);
			void SaveToFile(std::string filename);

		};
	}
}
