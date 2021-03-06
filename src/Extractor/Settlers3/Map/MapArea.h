/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef EXTRACTOR_SETTLERS3_MAP_MAPAREA_H
#define EXTRACTOR_SETTLERS3_MAP_MAPAREA_H
#include <string>
#include "../../../Log.h"
#include "../../../Functions/File/DataReader.h"
#include "../../../Functions/File/Save.h"
#include "../../../Functions/To.h"
#include "MAPParts.h"
#include "../Lists/MapObjects.h"
#include "../Lists/Resources.h"

namespace Extractor{
	namespace Settlers3{
		class MAPArea : public MAPParts{
		public:
			struct MapTile{
				unsigned char height = 0;
				unsigned char type = 0;
				unsigned char object = 0;
				unsigned char playerClaim = 0;// -1 = NONE
				unsigned char accessible = 0;// 0 = YES 1 = NO
				unsigned char resources = 0;
			};
		private:
			//Map Info
			int mapSizeHeight = 0;
			int mapSizeWidth = 0;
			MapTile* mapData = NULL;

		public:
			MAPArea(Functions::DataReader* reader,unsigned int offset,unsigned int size,unsigned int cryptKey);
			virtual ~MAPArea(){delete [] this->mapData;};
			virtual std::string HeaderToString();
			void SaveToFile(std::string location);


			const int MapSizeHeight(){return this->mapSizeHeight;};
			const int MapSizeWidth(){return this->mapSizeWidth;};
			MapTile* MapData(){return this->mapData;}
		};
	}
}

#endif