#pragma once 

#include <string>
#include <map>
#include <iostream>
#include <fstream>

class FileRedactor {
public:

	FileRedactor() = default;
	FileRedactor(const std::string filePath);
	~FileRedactor();

	void CatFile();
	void ReadFile(const std::string);
	std::string& operator[] (unsigned int num);

private:
	std::map<unsigned long long, std::string> storage_;
	std::fstream inpOutThread_;

	void ReadFile();

	bool file_open_;
};