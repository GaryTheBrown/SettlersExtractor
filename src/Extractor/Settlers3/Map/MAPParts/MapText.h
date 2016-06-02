//============================================================================
// Name        : MAPText.h
// Author      : Gary_The_Brown
// Description :
//============================================================================

#ifndef EXTRACTOR_SETTLERS3_MAP_MAPPARTS_MAPTEXT_H_
#define EXTRACTOR_SETTLERS3_MAP_MAPPARTS_MAPTEXT_H_

#include <string>
#include "../../../../Log.h"
#include "../../../../LogSystem/LogSystem.h"
#include "../../../../Functions/DataReader.h"
#include "../../../../Functions/OutputVar.h"
#include "../MAPParts.h"
namespace Extractor{
	namespace Settlers3{
		class MAPText: public MAPParts{
		private:
			std::string text;
		public:
			MAPText(Functions::DataReader* reader,unsigned int offset,unsigned int size,unsigned int cryptKey);
			virtual ~MAPText();
			virtual std::string ToString();
		};
	}
}
#endif