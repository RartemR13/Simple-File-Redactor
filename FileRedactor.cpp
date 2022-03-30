#include "FileRedactor.hpp"

FileRedactor::FileRedactor(const std::string filePath) :
	storage_(),
	inpOutThread_(filePath, std::ios::in | std::ios::out)
{
	ReadFile();
	file_open_ = true;
}

FileRedactor::~FileRedactor() {
	if (file_open_)
		inpOutThread_.close();

	file_open_ = false;
}

void FileRedactor::ReadFile() {
	storage_.clear();

	std::string line;

	for (int i = 0; getline(inpOutThread_, line); ++i)
		storage_[i] = line;
} 

void FileRedactor::ReadFile(const std::string filePath) {
	if (file_open_)
		inpOutThread_.close();

	inpOutThread_.open(filePath, std::ios::in | std::ios::out);
	file_open_ = true;

	ReadFile();		
} 

void FileRedactor::CatFile() {
	for (auto it = storage_.begin(); it != storage_.end(); ++it)
			std::cout << it->second << std::endl;
}

std::string& FileRedactor::operator[] (unsigned int num) {
	return storage_[num];
}

