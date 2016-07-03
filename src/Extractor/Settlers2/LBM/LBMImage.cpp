/*******************************************************************************
 * Settlers Extractor - A program To extract data file for the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#include "LBMImage.h"

namespace Extractor {
	namespace Settlers2{

		LBMImage::LBMImage(Functions::DataReader* reader,unsigned short width,unsigned short height,RGBA* palette){
			this->width = width;
			this->height = height;
			this->palette = palette;

			bool exitLoop = false;
			unsigned int size = width*height;

			this->image = new unsigned char[size];
			unsigned int imageLocation = 0;

			while (exitLoop == false){
				if (imageLocation < size){
					unsigned char code = reader->ReadChar();
					if(code > 128){
						unsigned char count = (257 - code);
						unsigned char pixel = reader->ReadChar();
						for (unsigned char i = 0; i < count; i++){
							this->image[imageLocation] = pixel;
							imageLocation++;
						}
					}
					else if (code < 128){
						for (unsigned char i = 0; i <= code; i++){
							this->image[imageLocation] = reader->ReadChar();
							imageLocation++;
						}
					}
					else{ //if code == 128
						exitLoop = true;
					}
				}else{
					exitLoop = true;
				}
			}
		}

		void LBMImage::SaveToFile(std::string filename){

			RGBA* RGBImage = this->ConvertToRGBA();
			Functions::FileImage* fileImage = new Functions::FileImage();
			fileImage->SaveToPaletteImage(filename + "PAL.bmp",this->image,this->palette,this->width,this->height);
			fileImage->SaveToRGBImage(filename + "RGB.bmp",RGBImage,this->width,this->height);
			delete fileImage;
		}
	}
}
