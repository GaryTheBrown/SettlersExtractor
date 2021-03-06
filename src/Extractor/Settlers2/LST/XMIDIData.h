/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef EXTRACTOR_SETTLERS2_LST_XMIDIDATA_H
#define EXTRACTOR_SETTLERS2_LST_XMIDIDATA_H
#include "../../../Functions/File/DataReader.h"
#include "../../../Functions/Audio/XMIDIData.h"

namespace Extractor{
	namespace Settlers2{
		class XMIDIData : public Functions::XMIDIData{

		public:
			explicit XMIDIData(Functions::DataReader* reader);
		};
	}
}

#endif