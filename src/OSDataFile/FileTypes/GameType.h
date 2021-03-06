/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef OSDATAFILE_FILETYPES_GAMETYPE_H
#define OSDATAFILE_FILETYPES_GAMETYPE_H

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <libxml/tree.h>

#include "GameData.h"
#include "FileTypes.h"

#include "../../Functions/File/DataReader.h"
#include "../../Log.h"

#include "Layout/MenuLayout.h"
#include "Layout/LoadingScreenLayout.h"
#include "GameOptions.h"
#include "MapSetup/MapSetup.h"

namespace OSData {
	class GameType : public FileTypes {
	private:
		std::string gameName = "";
		unsigned char gameNumber = 0;
		GameAddons addonsIncluded = eS2None; // BITSHIFT CODES
		unsigned int startMenuNumber = 0;

		//bool hasGameIcon;
		std::vector<MenuLayout*>* menuLayouts = NULL;
		std::vector<LoadingScreenLayout*>* loadingScreenLayouts = NULL;
		GameOptions* gameOptions = NULL;
		MapSetup* mapSetup = NULL;
		//List<Race>* raceList = NULL;
		//List<Resource>* resourceList = NULL;

		void CheckValues(std::string name, std::string value);
		void DoFileType(FileTypes::eFileType fileType, void* data, bool xml = false);

	public:
		GameType();
		GameType(std::string gameName, unsigned char gameNumber, GameAddons addonsIncluded, unsigned int startMenuNumber);
		GameType(std::string gameName, unsigned char gameNumber, GameAddons addonsIncluded, unsigned int startMenuNumber, std::vector<MenuLayout*>* menuLayouts, std::vector<LoadingScreenLayout*>* loadingScreenLayouts, GameOptions* gameOptions, MapSetup* mapSetup
	//			std::vector<Resource*>* resourceList,
	//			std::vector<Race*>* raceList
				 );
//KEEP WORKING ON ADDING GAME OPTIONS AND MAP SETUP
		explicit GameType(Functions::DataReader* reader);
		explicit GameType(xmlNode* node);

		virtual ~GameType();

		void SortAll();
		void StartMenuNumber(unsigned int startMenuNumber){this->startMenuNumber = startMenuNumber;};
		void AddMenuLayout(MenuLayout* menuLayout);//see GameType.cpp
		void AddLoadingScreenLayout(LoadingScreenLayout* loadingScreenLayout);//see GameType.cpp
		//void GameNumber(unsigned char gameNumber){this->gameNumber = gameNumber;}//Should this be available? thinking no can comment back in if so
		void AddonsIncluded(GameAddons addonsIncluded){this->addonsIncluded = static_cast<GameAddons>(static_cast<unsigned char>(this->addonsIncluded) | static_cast<unsigned char>(addonsIncluded));}

		const std::string GameName(){return this->gameName;}
		const unsigned int StartMenuNumber(){return this->startMenuNumber;}
		const unsigned char GameNumber(){return this->gameNumber;}
		const GameAddons AddonsIncluded(){return this->addonsIncluded;}
		std::vector<MenuLayout*>* MenuLayouts(){return this->menuLayouts;};

		bool ToSaveToData(std::vector<char>* data);
		bool ImageToNumbers(std::vector<Functions::RGBImage*>* images, std::vector<std::string>* imageLocations = NULL);
		bool LinkNumbers(std::vector<Functions::RGBImage*>* images);
		std::string ToString();

	};
}

#endif