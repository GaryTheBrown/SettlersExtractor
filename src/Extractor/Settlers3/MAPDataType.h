/*******************************************************************************
 * Settlers Extractor - A program To extract data file for the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef EXTRACTOR_SETTLERS3_MAPDATATYPE_H_
#define EXTRACTOR_SETTLERS3_MAPDATATYPE_H_

#include <string>

#include "../../Log.h"
#include "../../LogSystem/LogSystem.h"

#include "../../Functions/To.h"
#include "../../Functions/File/Functions.h"
#include "../../Functions/File/Save.h"
#include "../../Functions/DataReader.h"

#include "Map/MAPHeader.h"

namespace Extractor{
	namespace Settlers3{
		class MAPDataType{
		private:
			MAPHeader* header = NULL;

		public:
			MAPDataType(std::string file);
			virtual ~MAPDataType();

			void SaveHeaderData(std::string location);
			void SaveFileData(std::string location);

		};
	}
}
#endif
