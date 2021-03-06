/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#include "AnimationData.h"

Extractor::Settlers3::AnimationData::AnimationData(Functions::DataReader* reader, int offset){

	reader->SetOffset(offset);
	this->count = reader->ReadInt();
	this->frames = new AnimationDataFrame[this->count];
	for (unsigned int i = 0; i < this->count; i++){
		this->frames[i].posX =  reader->ReadSignedShort();
		this->frames[i].posY = reader->ReadSignedShort();
		this->frames[i].object_id = reader->ReadShort();
		this->frames[i].object_file = reader->ReadShort();
		this->frames[i].torso_id = reader->ReadShort();
		this->frames[i].torso_file = reader->ReadShort();
		this->frames[i].shadow_id = reader->ReadShort();
		this->frames[i].shadow_file = reader->ReadShort();
		this->frames[i].object_frame = reader->ReadShort();
		this->frames[i].torso_frame = reader->ReadShort();
		this->frames[i].sound_flag1 = reader->ReadSignedShort();
		this->frames[i].sound_flag2 = reader->ReadSignedShort();
	}
}

void Extractor::Settlers3::AnimationData::SaveToFile(std::string *filename){

	std::string data = "";
	for (unsigned int i = 0; i < this->count; i++){
		data += "PosX        =" + Functions::ToString(this->frames[i].posX) + "\t";
		data += "PosY        =" + Functions::ToString(this->frames[i].posY) + "\t";
		data += "Object ID   =" + Functions::ToString(this->frames[i].object_id) + "\t";
		data += "Object File =" + Functions::ToString(this->frames[i].object_file) + "\t";
		data += "Torso ID    =" + Functions::ToString(this->frames[i].torso_id) + "\t";
		data += "Torso File  =" + Functions::ToString(this->frames[i].torso_file) + "\t";
		data += "Shadow ID   =" + Functions::ToString(this->frames[i].shadow_id) + "\t";
		data += "Shadow File =" + Functions::ToString(this->frames[i].shadow_file) + "\t";
		data += "Object Frame=" + Functions::ToString(this->frames[i].object_frame) + "\t";
		data += "Torso Frame =" + Functions::ToString(this->frames[i].torso_frame) + "\t";
		data += "Sound Flag 1=" + Functions::ToString(this->frames[i].sound_flag1) + "\t";
		data += "Sound Flag 2=" + Functions::ToString(this->frames[i].sound_flag2) + "\t";
		data += "\n";
	}
	Functions::SaveToTextFile(*filename + ".txt",data);

}
