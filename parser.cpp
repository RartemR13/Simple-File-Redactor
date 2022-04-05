#include "parser.hpp"
#include <iostream>

#include <sstream>

bool CheckPrefStr(const std::string& base_str, std::string search_str) {
	if (base_str.length() < search_str.length())
		return false;	

	return base_str.substr(0, search_str.length()) == search_str;
}

ParseRet Parse(std::string& req) {

#define PARSE_CMD(name, parse_ret, code) \
	if (CheckPrefStr(req, #name))        \
		return ParseRet::parse_ret;
//----------------------------------------

#include "parser_code_gen"     
#undef PARSE_CMD
	else if (req == "")
		return ParseRet::SKIP_LINE;
	else return ParseRet::INCORRECT;
}