#include "FileRedactor.hpp"

int main() {

	FileRedactor fr("test");

	fr.ReadFile();
	fr.CatFile();

	return 0;
}