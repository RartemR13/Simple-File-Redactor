#include "FileRedactor.hpp"

FileRedactor::FileRedactor(const std::string filePath) {
	ReadFile(filePath);
}

FileRedactor::~FileRedactor() {
	if (fileOpen_)
		inpOutThread_.close();

	fileOpen_ = false;
}

void FileRedactor::ReadFile() {
	storage_.Clear();

	std::string line;

	for (int i = 0; getline(inpOutThread_, line); ++i)
		storage_.Insert(line, i);

    fileOpen_ = true;
} 

void FileRedactor::WriteFile() {
    if (!fileOpen_)
        throw std::runtime_error("");

    inpOutThread_.close();

    try {
        inpOutThread_.open(filePath_, std::ios::out | std::ios::trunc);
        if (!inpOutThread_)
            throw std::runtime_error("");

        for (int i = 0; i < storage_.Size(); ++i)
            inpOutThread_ << storage_[i] << std::endl;
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
    if (!fileOpen_)
        throw std::runtime_error("");

    for (int i = 0; i < storage_.Size(); ++i)
        std::cout << storage_[i] << std::endl;
}

std::string& FileRedactor::operator[] (unsigned long long num) {
    if (!fileOpen_)
        throw std::runtime_error("");

	return storage_[num];   
}

unsigned long long FileRedactor::LinesCount() {
    return storage_.Size();
}

void FileRedactor::AddLine(const std::string add_str, unsigned long long num) {
    if (!fileOpen_)
        throw std::runtime_error("");

    storage_.Insert(add_str, num);
}