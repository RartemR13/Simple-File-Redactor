#include "FileRedactor.hpp"

FileRedactor::FileRedactor(const std::string filePath) {
    inpOutThread_.exceptions(std::fstream::failbit | std::fstream::badbit);
	ReadFile(filePath);
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

    try {
        inpOutThread_.open(filePath_, std::ios::out | std::ios::trunc);
        if (!inpOutThread_)
            throw std::runtime_error("");
        for (auto it = storage_.begin(); it != storage_.end(); ++it)
            inpOutThread_ << it->second << std::endl;
    } catch(std::exception) {
        std::cout << "Runtime error: can't write in file." << std::endl;
    }
    inpOutThread_.close();

    inpOutThread_.open(filePath_, std::ios::in);
}

void FileRedactor::ReadFile(const std::string filePath) {
	if (fileOpen_)
		inpOutThread_.close();
    try {
	   inpOutThread_.open(filePath, std::ios::in);
       if (!inpOutThread_)
        throw std::runtime_error("");
    } catch(std::exception) {
        std::cout << "Runtime error: can't work with with file or file not exist." << std::endl;
        return;
    }
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

