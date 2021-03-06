/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef OSDATAFILE_FILETYPES_FILETYPES_H
#define OSDATAFILE_FILETYPES_FILETYPES_H

#include <string>
#include <vector>
#include "../../Functions/Image/RGBImage.h"

namespace OSData{
	class FileTypes {
	public:
		enum eFileType: unsigned short{
			eNone = 0,
			eFull = 1,
			eArchive = 2,
			eMenuLayout = 3,
			eLoadingScreenLayout = 4,
			eGameOptions = 5,
			eMapSetup = 6,
			eTerrain = 7
		};

	protected:
		eFileType fileType;

		eFileType GetFileType(std::string data);
	public:
		explicit FileTypes(eFileType fileType):fileType(fileType){};
		virtual ~FileTypes(){};

		virtual bool ToSaveToData(std::vector<char>* data);
		virtual bool ImageToNumbers(std::vector<Functions::RGBImage*>* images, std::vector<std::string>* imageLocations = NULL){return false;};
		virtual bool LinkNumbers(std::vector<Functions::RGBImage*>* images){return false;};
		virtual std::string ToString(){return "ERROR";};

		const eFileType FileType(){return this->fileType;};
	};
}

#endif