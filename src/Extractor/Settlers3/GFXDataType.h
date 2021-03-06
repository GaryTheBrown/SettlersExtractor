/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef EXTRACTOR_SETTLERS3_GFXDATATYPE_H
#define EXTRACTOR_SETTLERS3_GFXDATATYPE_H

#include <string>
#include "../../Log.h"
#include "../../Functions/To.h"
#include "../../Functions/File/Functions.h"
#include "../../Functions/File/Save.h"
#include "../../Functions/Image/RGBA.h"
#include "GFX/GFXHeader.h"
#include "GFX/GFXAnimation.h"
#include "GFX/GFXGUI.h"
#include "GFX/GFXLandscape.h"
#include "GFX/GFXObject.h"
#include "GFX/GFXPalette.h"
#include "GFX/GFXShadow.h"
#include "GFX/GFXText.h"
#include "GFX/GFXTorso.h"

namespace Extractor{
	namespace Settlers3{
		class GFXDataType{
		private:

			GFXHeader* header = NULL;
			GFXText* text = NULL;
			GFXLandscape* landscape = NULL;
			GFXGUI* gui = NULL;
			GFXObject* object = NULL;
			GFXTorso* torso = NULL;
			GFXShadow* shadow = NULL;
			GFXAnimation* animation = NULL;
			GFXPalette* palette = NULL;

			RGBA Palette[256] = {{0,0,0,255},{8,0,0,255},{24,0,0,255},{32,4,0,255},{49,4,0,255},{57,4,0,255},{74,8,0,255},{82,8,0,255},
								{98,8,0,255},{107,12,0,255},{123,12,0,255},{131,12,0,255},{148,16,0,255},{156,16,0,255},{173,20,0,255},{181,20,0,255},
								{197,20,0,255},{206,24,0,255},{222,24,0,255},{230,24,0,255},{247,28,0,255},{255,28,0,255},{123,40,41,255},{140,40,32,255},
								{156,36,24,255},{173,36,24,255},{189,36,16,255},{206,32,8,255},{222,32,8,255},{238,28,0,255},{255,28,0,255},{214,40,41,255},
								{222,40,32,255},{222,36,24,255},{230,36,24,255},{238,36,16,255},{238,32,8,255},{247,32,8,255},{255,28,0,255},{255,28,0,255},
								{41,125,41,255},{65,113,32,255},{90,101,24,255},{123,89,24,255},{148,76,16,255},{173,64,8,255},{206,52,8,255},{230,40,0,255},
								{255,28,0,255},{123,125,41,255},{140,113,32,255},{156,101,24,255},{173,89,24,255},{189,76,16,255},{206,64,8,255},{222,52,8,255},
								{238,40,0,255},{255,28,0,255},{214,125,41,255},{222,113,32,255},{222,101,24,255},{230,89,24,255},{238,76,16,255},{238,64,8,255},
								{247,52,8,255},{255,40,0,255},{255,28,0,255},{41,214,41,255},{65,190,32,255},{90,165,24,255},{123,141,24,255},{148,121,16,255},
								{173,97,8,255},{206,72,8,255},{230,52,0,255},{255,28,0,255},{123,214,41,255},{140,190,32,255},{156,165,24,255},{173,141,24,255},
								{189,121,16,255},{206,97,8,255},{222,72,8,255},{238,52,0,255},{255,28,0,255},{214,214,41,255},{222,190,32,255},{222,165,24,255},
								{230,141,24,255},{238,121,16,255},{238,97,8,255},{247,72,8,255},{255,52,0,255},{255,28,0,255},{41,40,123,255},{65,40,107,255},
								{90,36,90,255},{123,36,74,255},{148,36,57,255},{173,32,41,255},{206,32,24,255},{230,28,8,255},{255,28,0,255},{123,40,123,255},
								{140,40,107,255},{156,36,90,255},{173,36,74,255},{189,36,57,255},{206,32,41,255},{222,32,24,255},{238,28,8,255},{255,28,0,255},
								{214,40,123,255},{222,40,107,255},{222,36,90,255},{230,36,74,255},{238,36,57,255},{238,32,41,255},{247,32,24,255},{255,28,8,255},
								{255,28,0,255},{41,125,123,255},{65,113,107,255},{90,101,90,255},{123,89,74,255},{148,76,57,255},{173,64,41,255},{206,52,24,255},
								{230,40,8,255},{255,28,0,255},{123,125,123,255},{140,113,107,255},{156,101,90,255},{173,89,74,255},{189,76,57,255},{206,64,41,255},
								{222,52,24,255},{238,40,8,255},{255,28,0,255},{214,125,123,255},{222,113,107,255},{222,101,90,255},{230,89,74,255},{238,76,57,255},
								{238,64,41,255},{247,52,24,255},{255,40,8,255},{255,28,0,255},{41,214,123,255},{65,190,107,255},{90,165,90,255},{123,141,74,255},
								{148,121,57,255},{173,97,41,255},{206,72,24,255},{230,52,8,255},{255,28,0,255},{123,214,123,255},{140,190,107,255},{156,165,90,255},
								{173,141,74,255},{189,121,57,255},{206,97,41,255},{222,72,24,255},{238,52,8,255},{255,28,0,255},{214,214,123,255},{222,190,107,255},
								{222,165,90,255},{230,141,74,255},{238,121,57,255},{238,97,41,255},{247,72,24,255},{255,52,8,255},{255,28,0,255},{41,40,214,255},
								{65,40,189,255},{90,36,156,255},{123,36,131,255},{148,36,107,255},{173,32,74,255},{206,32,49,255},{230,28,24,255},{255,28,0,255},
								{123,40,214,255},{140,40,189,255},{156,36,156,255},{173,36,131,255},{189,36,107,255},{206,32,74,255},{222,32,49,255},{238,28,24,255},
								{255,28,0,255},{214,40,214,255},{222,40,189,255},{222,36,156,255},{230,36,131,255},{238,36,107,255},{238,32,74,255},{247,32,49,255},
								{255,28,24,255},{255,28,0,255},{41,125,214,255},{65,113,189,255},{90,101,156,255},{123,89,131,255},{148,76,107,255},{173,64,74,255},
								{206,52,49,255},{230,40,24,255},{255,28,0,255},{123,125,214,255},{140,113,189,255},{156,101,156,255},{173,89,131,255},{189,76,107,255},
								{206,64,74,255},{222,52,49,255},{238,40,24,255},{255,28,0,255},{214,125,214,255},{222,113,189,255},{222,101,156,255},{230,89,131,255},
								{238,76,107,255},{238,64,74,255},{247,52,49,255},{255,40,24,255},{255,28,0,255},{41,214,214,255},{65,190,189,255},{90,165,156,255},
								{123,141,131,255},{148,121,107,255},{173,97,74,255},{206,72,49,255},{230,52,24,255},{255,28,0,255},{123,214,214,255},{140,190,189,255},
								{156,165,156,255},{173,141,131,255},{189,121,107,255},{206,97,74,255},{222,72,49,255},{238,52,24,255},{255,28,0,255},{214,214,214,255},
								{222,190,189,255},{222,165,156,255},{230,141,131,255},{238,121,107,255},{238,97,74,255},{247,72,49,255},{255,52,24,255},{255,28,0,255}};
		public:

			explicit GFXDataType(std::string file);
			~GFXDataType();

			void SaveToFile(std::string location);

			RGBImageData* ReturnGUIImage(unsigned short image){return this->gui->ReturnImage(image);};
			RGBImageData* ReturnObjectImage(unsigned short image, unsigned short frame){return this->object->ReturnImage(image,frame);};

		};
	}
}

#endif