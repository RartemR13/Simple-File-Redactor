#pragma once

#include <string>

enum ParseRet {
	HELP,
	SET_LINE,
	GET_LINE,
	INCORRECT,
	QUIT
};

bool CheckPrefStr(const std::string&, std::string);

ParseRet Parse(std::string&);