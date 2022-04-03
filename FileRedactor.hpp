#pragma once 

#include <string>
#include <map>
#include <iostream>
#include <fstream>

#include "DTree/DTree.hpp"

class FileRedactor {
public:

	FileRedactor() = default;
	FileRedactor(const std::string);
	~FileRedactor();

    unsigned long long LinesCount();
    void AddLine(const std::string);
	void CatFile();
    void WriteFile();
	void ReadFile(const std::string);
	std::string& operator[] (unsigned long long);

private:
	DTree<std::string> storage_;
	std::fstream inpOutThread_;
    std::string filePath_;

	void ReadFile();

	bool fileOpen_;

};