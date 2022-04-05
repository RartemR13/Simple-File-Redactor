#include "parser.hpp"
#include <iostream>

#include <sstream>

bool CheckPrefStr(const std::string& base_str, std::string search_str) {
	 std::stringstream str_stream(base_str);
	 std::string check_str;

	 str_stream >> check_str;

	return check_str == search_str;
}

ParseRet Parse(std::string& req) {

#define PARSE_CMD(name, parse_ret, check_code, code) \
	if (CheckPrefStr(req, #name)) {		 			 \
		bool correct = false;						 \
		check_code							 		 \
		if (correct)					 			 \
			return ParseRet::parse_ret;  			 \
	} else
//----------------------------------------------------

#include "../code_gen/parser_code_gen"     
#undef PARSE_CMD
	if (req == "")
		return ParseRet::SKIP_LINE;
	return ParseRet::INCORRECT;
}