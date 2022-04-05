#include "FileRedactor.hpp"
#include "parser.hpp"

#include <sstream>

int main() {
	std::string req;

	FileRedactor file;

	while (getline(std::cin, req)) {
		bool quit = false;

		switch(Parse(req)) {
#define PARSE_CMD(name, parse_ret, check_code, code) \
			case ParseRet::parse_ret:    			 \
				code                     			 \
				break;           		
//----------------------------------------

#include "parser_code_gen"
#undef PARSE_CMD

			default:
				std::cout << "Incorrect command" << std::endl;
		}

		if (quit)
			break;
	}

	return 0;
}