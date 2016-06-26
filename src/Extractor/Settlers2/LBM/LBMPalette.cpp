/*******************************************************************************
 * Settlers Extractor - A program To extract data file for the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#include "LBMPalette.h"

namespace Extractor {
	namespace Settlers2{
		LBMPalette::LBMPalette(Functions::DataReader* reader) {

			for(unsigned short i = 0; i < 256; i++){
				this->palette[i].R = reader->ReadChar();
				this->palette[i].G = reader->ReadChar();
				this->palette[i].B = reader->ReadChar();
			}
		}

		LBMPalette::~LBMPalette() {

		}
	}
}
