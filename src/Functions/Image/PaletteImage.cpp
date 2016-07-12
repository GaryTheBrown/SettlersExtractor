/*******************************************************************************
 * Settlers Extractor - A program To extract data file for the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/
#include "PaletteImage.h"

Functions::PaletteImage::~PaletteImage(){
	if (this->image != NULL)
		delete [] this->image;
	if (this->transparency != NULL)
		delete [] this->transparency;
}

void Functions::PaletteImage::SetPalette(RGBA* palette){
	if ((this->palette == NULL)||(this->palette != palette))
		this->palette = palette;
}

RGBA* Functions::PaletteImage::ConvertToRGBA(unsigned char* fromImage, bool* fromTransparency,	RGBA* fromPalette){

	if (fromImage == NULL) fromImage = this->image;
	if (fromTransparency == NULL) fromTransparency = this->transparency;
	if (fromPalette == NULL) fromPalette = this->palette;

	RGBA *imageRGBA = new RGBA[this->height*this->width];

	if(fromTransparency != NULL){
		for (int i = 0; i < (this->height*this->width);i++){
			if(fromTransparency[i] == true)
				imageRGBA[i] = {0,0,0,0};
			else
				imageRGBA[i] = fromPalette[fromImage[i]];
		}
	}else{
		for (int i = 0; i < (this->height*this->width);i++)
			imageRGBA[i] = fromPalette[fromImage[i]];
	}
	return imageRGBA;
}

void Functions::PaletteImage::SaveToFile(std::string filename){

	std::string data = "";
	data += "Width=" + Functions::ToString(this->width) + "\n";
	data += "Height=" + Functions::ToString(this->height) + "\n";
	data += "OffsetPositionX=" + Functions::ToString(this->xRel) + "\n";
	data += "OffsetPositionY=" + Functions::ToString(this->yRel);
	Functions::SaveToTextFile(filename + ".txt",data);

	filename.append(".bmp");
	Functions::FileImage* fileImage = new Functions::FileImage();
	fileImage->SaveToRGBImage(filename,this->ConvertToRGBA(),this->width,this->height);
	//fileImage->SaveToPaletteImage(filename,this->image,this->palette,this->width,this->height);
	delete fileImage;
}

void Functions::PaletteImage::RAWSAVETEMP(std::string filename){

	std::string data = "";
	data += "Width=" + Functions::ToString(this->width) + "\n";
	data += "Height=" + Functions::ToString(this->height) + "\n";
	data += "OffsetPositionX=" + Functions::ToString(this->xRel) + "\n";
	data += "OffsetPositionY=" + Functions::ToString(this->yRel) + "\n";
	Functions::SaveToTextFile(filename + ".txt",data);

	SaveToBinaryFile(filename + ".dat",(char*)this->image,this->tmpsize);
}