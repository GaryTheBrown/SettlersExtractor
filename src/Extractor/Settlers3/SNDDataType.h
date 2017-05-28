/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#pragma once
#include <string>
#include "../../Log.h"
#include "../../Functions/To.h"
#include "../../Functions/File/Functions.h"
#include "../../Functions/File/Save.h"
#include "SND/SNDHeader.h"

namespace Extractor{
	namespace Settlers3{
		class SNDDataType{
		private:
			SNDHeader* header = NULL;

		public:
			explicit SNDDataType(std::string file);
			~SNDDataType();

			void SaveToFile(std::string location);
		};
	}
}
