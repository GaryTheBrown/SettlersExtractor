/*******************************************************************************
 * Settlers Extractor - A program To extract data file for the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/
#ifndef EXTRACTOR_SETTLERS3_EXTRACTOR_H_
#define EXTRACTOR_SETTLERS3_EXTRACTOR_H_

#include <string>
#include <vector>
#include "../eType.h"
#include "../../Log.h"
//#include "../main_Extractor.h"
#include "../../Functions/FileFunctions.h"
#include "../../Functions/FileRun.h"
#include "GFXDataType.h"
#include "SNDDataType.h"
#include "MAPDataType.h"

namespace Extractor{
	namespace Settlers3{
		class Extract {
		public:
			enum VersionS3{
				VersionNONE,
				VersionS3CD1,
				VersionS3CD2,
				VersionS3MCD1,
				VersionS3QOTA1,
				VersionS3GOLD1,
				VersionS3GOLD2,
				VersionS3GOG,
				VersionS3DISCINSTALL,
				VersionS3GOLDINSTALL,
				VersionS3GOGINSTALL
			};

		private:

			enum MapType{
				MT_UNKNOWN,
				MT_ORIGINALMISSIONS,
				MT_MCDMISSIONS,
				MT_QOTAMISSIONS,
				MT_MULTI,
				MT_SINGLE,
				MT_TUTORIAL,
				MT_USER
			};

			VersionS3 gameVersion = VersionNONE;
			std::string location = "";
			std::string locationExtra = "";

			bool RAWGFXFileExtract(std::string folder, std::string file);
			bool RAWSNDFileExtract(std::string folder, std::string file);
			bool RAWMAPFileExtract(std::string folder, std::string file, MapType mapType = MT_UNKNOWN);
			void RAWGFXFolderExtract(std::string folder);
			void RAWSNDFolderExtract(std::string folder);
			void RAWMAPFolderExtract(std::string folder, MapType mapType = MT_UNKNOWN);

			void CheckGameVersion(bool GOG);

		public:
			Extract(std::string location,bool GOG);
			Extract(){};

			virtual ~Extract();

			bool FullRAWExtract();

			bool ManualExtract(eType fileType,std::string location);


		};
	}
}
#endif
