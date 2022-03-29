#include "parser.hpp"

bool CheckPrefStr(const std::string& base_str, std::string search_str) {
	if (base_str.length() < search_str.length())
		return false;

	return base_str.substr(0, search_str.length()) == search_str;
}

ParseRet Parse(std::string& req) {
	if (CheckPrefStr(req, "help")) {
		return ParseRet::HELP;
	} else if (CheckPrefStr(req, "quit")) {
		return ParseRet::QUIT;
	} else
		return ParseRet::INCORRECT;
}