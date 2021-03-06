/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef EXTRACTOR_SETTLERS2_LBM_LBMHEADER_H
#define EXTRACTOR_SETTLERS2_LBM_LBMHEADER_H
#include "../../../Functions/File/DataReader.h"

namespace Extractor{
	namespace Settlers2{
		class LBMHeader{
		private:
			unsigned int chunkID; //"FORM"  uint 1297239878
			unsigned int lenChunk;//Length of chunk data, in bytes. Does not include the pad byte. Will be the same as the file size minus eight bytes (this field and chunkID are not included in the count)
			unsigned int formatID;//"ILBM"/ "PBM " uint 541934160

		public:
			explicit LBMHeader(Functions::DataReader* reader);
		};
	}
}

#endif