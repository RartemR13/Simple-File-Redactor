#include "../FileRedactor/FileRedactor.hpp"
#include <cassert>
#include <iostream>

void TestReadFile() {
	system("touch UNIT_TEST &&"
		   "echo \"test 1\ntest 2\ntest 3\n\" > UNIT_TEST");

	FileRedactor file("UNIT_TEST");

	assert(file[0] == "test 1" && 
		   file[1] == "test 2" && 
		   file[2] == "test 3");

	std::cout << "TestReadFile: OK" << std::endl;
}

void TestModifyLine() {
	system("touch UNIT_TEST &&"
		   "echo \"test 1\ntest 2\ntest 3\n\" > UNIT_TEST");

	FileRedactor file("UNIT_TEST");

	file[0] = "zzz";

	assert(file[0] == "zzz" && 
		   file[1] == "test 2" && 
		   file[2] == "test 3");

	std::cout << "TestModifyLine: OK" << std::endl;
}

int main() {
	TestReadFile();
	TestModifyLine();
	return 0;
}