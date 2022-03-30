#include "FileRedactor.hpp"

FileRedactor::FileRedactor(const std::string filePath) :
	storage_(),
	inpOutThread_(filePath, std::ios::in),
    filePath_(filePath),
    fileOpen_(false)
{
	ReadFile();
}

FileRedactor::~FileRedactor() {
	if (fileOpen_)
		inpOutThread_.close();

	fileOpen_ = false;
}

void FileRedactor::ReadFile() {
	storage_.clear();

	std::string line;

	for (int i = 0; getline(inpOutThread_, line); ++i)
		storage_[i] = line;

    fileOpen_ = true;
} 

void FileRedactor::WriteFile() {
    inpOutThread_.close();

    inpOutThread_.open(filePath_, std::ios::out | std::ios::trunc);
    for (auto it = storage_.begin(); it != storage_.end(); ++it)
        inpOutThread_ << it->second << std::endl;
    inpOutThread_.close();

    inpOutThread_.open(filePath_, std::ios::in);
}

void FileRedactor::ReadFile(const std::string filePath) {
	if (fileOpen_)
		inpOutThread_.close();

	inpOutThread_.open(filePath, std::ios::in);
    filePath_ = filePath;

	ReadFile();		
} 

void FileRedactor::CatFile() {
	for (auto it = storage_.begin(); it != storage_.end(); ++it)
			std::cout << it->second << std::endl;
}

std::string& FileRedactor::operator[] (unsigned long long num) {
	return storage_[num];
}

