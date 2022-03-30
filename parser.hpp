#pragma once

#include <string>

enum ParseRet {
	HELP,
	SET_FILE,
	SET_LINE,
	GET_LINE,
	CAT_FILE,
    SAVE_FILE,
	INCORRECT,
	QUIT,
    CLEAR
};

bool CheckPrefStr(const std::string&, std::string);

ParseRet Parse(std::string&);