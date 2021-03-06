/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef FUNCTIONS_AUDIO_XMIDIDATA_H
#define FUNCTIONS_AUDIO_XMIDIDATA_H
#include <string>
#include "../File/Functions.h"

namespace Functions{
	class XMIDIData{
	protected:

		unsigned int length;
		unsigned char* data;

	public:

		virtual ~XMIDIData(){delete[] this->data;};
		void SaveToFile(std::string filename);
	};
}

#endif