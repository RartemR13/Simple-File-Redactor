#include "FileRedactor.hpp"

int main() {
	std::string req;

	while (getline(std::cin, req)) {
		if (req == "help") {
			std::cout << "...\n";
		} else std::cout << "Incorrect command\n";
	}
	return 0;
}