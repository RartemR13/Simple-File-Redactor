#include "FileRedactor.hpp"

FileRedactor::FileRedactor(const std::string filePath) :
	storage_(),
	inpOutThread_(filePath, std::ios::in | std::ios::out)
{
	ReadFile();
}

FileRedactor::~FileRedactor() {
	inpOutThread_.close();
}

void FileRedactor::ReadFile() {
	std::string line;

	for (int i = 0; getline(inpOutThread_, line); ++i)
		storage_[i] = line;
} 

void FileRedactor::CatFile() {
	for (auto it = storage_.begin(); it != storage_.end(); ++it)
			std::cout << it->second << std::endl;
}