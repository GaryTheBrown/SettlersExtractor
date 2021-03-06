/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef OSDATAFILE_FILETYPES_LAYOUT_LOADINGSCREENLAYOUT_H
#define OSDATAFILE_FILETYPES_LAYOUT_LOADINGSCREENLAYOUT_H

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <libxml/tree.h>

#include "../../../Functions/Image/RGBA.h"
#include "../../../Functions/File/DataReader.h"
#include "../../../Functions/To.h"
#include "../../../Log.h"
#include "../../APILEVELS.h"
#include "../FileTypes.h"
#include "GUIItems/GUIImageData.h"

namespace OSData{
	class LoadingScreenLayout : public FileTypes {
	private:

		unsigned int APIVersion = APILEVEL::LOADINGSCREENLAYOUT;
		unsigned int menuID = 0;
		std::string title;
		RGBA backgroundColour;
		std::vector<GUIImageData*>* imageData = NULL;

		void CheckValues(std::string name, std::string value);
	public:


		LoadingScreenLayout(unsigned int menuID,std::string title,RGBA backgroundColour,std::vector<GUIImageData*>* itemData);
		explicit LoadingScreenLayout(Functions::DataReader* reader);
		explicit LoadingScreenLayout(xmlNode* node);

		virtual ~LoadingScreenLayout();

		const unsigned int MenuID(){return menuID;}
		const std::string Title(){return title;}
		const RGBA BackgroundColour(){return backgroundColour;}
		std::vector<GUIImageData*>* ImageData(){return this->imageData;};

		bool ToSaveToData(std::vector<char>* data = NULL);
		bool ImageToNumbers(std::vector<Functions::RGBImage*>* images, std::vector<std::string>* imageLocations = NULL);
		bool LinkNumbers(std::vector<Functions::RGBImage*>* images);
		std::string ToString();

		//Search and sort functions
	    bool operator < (const LoadingScreenLayout& str) const {return (this->menuID < str.menuID);};

	};
}

#endif