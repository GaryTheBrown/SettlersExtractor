/*******************************************************************************
 * Open Settlers - A Game Engine to run the Settlers 1-4
 * Copyright (C) 2016   Gary The Brown
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; ONLY version 2
 * of the License.
 *******************************************************************************/

#ifndef LOGSYSTEM_LOGSYSTEM_H
#define LOGSYSTEM_LOGSYSTEM_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>

class LogSystem{
private:

	template <typename T> std::string ToString(T value){
		std::ostringstream os;
		os << value ;
		return os.str() ;
	}

	signed char verboseLevelCLI;
	signed char verboseLevelFile = -1;
	signed char verboseLevelConsole = -1;//in game console
	//-1 = no info 0 = errors and messages only 1-127 = all info

	std::ofstream logFile;
	std::string logFileName = "OpenSettlers.log";

	std::string TimeToString();
	void Out(std::string Text, signed char verboseLevel = 0);

public:
	LogSystem(signed char verboseLevelCLI, signed char verboseLevelFile = -1, signed char verboseLevelConsole = -1);
	~LogSystem(){};

	void Log(std::string info, signed char verboseLevel = 1, bool newLine = true);
	void Message(std::string info, bool newLine = true);
	void Error(std::string info);

	void Bool(std::string info, bool input){
		if (input){
			this->Log(info + ": TRUE" );
		}else{
			this->Log(info + ": FALSE" );
		}
	}
};

#endif