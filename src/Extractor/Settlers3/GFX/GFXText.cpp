/*******************************************************************************
 * Settlers Extractor - A program To extract data file for the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/
#include "GFXText.h"
namespace Extractor{
	namespace Settlers3{
		GFXText::GFXText(Functions::DataReader* reader, unsigned int offset) {
			reader->SetOffset(offset);
				this->headerID = reader->ReadInt();
				LOGSYSTEM->Log("Reading:GFX:Text:Header ID:" + Functions::ToString(this->headerID),3);
				this->headerSize = reader->ReadInt();
				LOGSYSTEM->Log("Reading:GFX:Text:Header Size:" + Functions::ToString(this->headerSize),3);
				this->countA = reader->ReadShort();
				LOGSYSTEM->Log("Reading:GFX:Text:Count A:" + Functions::ToString(this->countA),3);
				this->countB = reader->ReadShort();
				LOGSYSTEM->Log("Reading:GFX:Text:Count B:" + Functions::ToString(this->countB),3);

				int offsets[this->countB][this->countA];
				LOGSYSTEM->Log("Reading:GFX:Text:Offsets:",3,false);
				for (unsigned short i = 0; i < this->countB; i++){
					for (unsigned short j = 0; j < this->countA; j++){
						offsets[i][j] = reader->ReadInt();
						LOGSYSTEM->LogCont(Functions::ToString(offsets[i][j]) + ",",4);
					}
				}
				LOGSYSTEM->newLine(3);

				unsigned int size;
				this->strings = new std::string*[this->countB];
				LOGSYSTEM->Log("Reading:GFX:Text:Strings:",3,false);
				for (unsigned short i = 0; i < this->countB; i++){
					this->strings[i] = new std::string[this->countA];
					for (unsigned short j = 0; j < this->countA; j++){
						if(i < this->countA)
							size = offsets[i][j+1] - offsets[i][j];
						else
							size = offsets[i+1][0] - offsets[i][j];

						this->strings[i][j] = reader->ReadString(size,offsets[i][j]);
						LOGSYSTEM->LogCont(".",4);
					}
				}
				LOGSYSTEM->newLine(3);
		}

		GFXText::~GFXText() {
			if(this->strings != NULL) delete[]this->strings;
		}

		bool GFXText::SaveFileData(std::string location){
			if(this->countA > 0){
				location += "/Text/";
				Functions::CreateDir(location);
				std::string filename;
				for (unsigned short i = 0; i < this->countB; i++){
					Functions::CreateDir(location + Languages[i] + "/");
					for (unsigned short j = 0; j < this->countA; j++){
						filename = location + Languages[i] + "/" + Functions::ToString(j) + ".txt";
						Functions::SaveToTextFile(filename,this->strings[i][j]);
					}
				}
				return true;
			}
			return false;
		}
	}
}