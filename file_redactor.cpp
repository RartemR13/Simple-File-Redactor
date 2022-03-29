#include "FileRedactor.hpp"
#include "parser.hpp"

int main() {
	std::string req;

	while (getline(std::cin, req)) {
		bool quit = false;

		switch(Parse(req)) {
			case ParseRet::HELP:
				std::cout << "..." << std::endl;
				break;

			case ParseRet::INCORRECT:
				std::cout << "Incorrect command" << std::endl;
				break;

			case ParseRet::QUIT:
				quit = true;
				break;
		}

		if (quit)
			break;
	}

	return 0;
}