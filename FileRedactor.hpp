#pragma once 

#include <string>
#include <map>
#include <iostream>
#include <fstream>

class FileRedactor {
public:

	FileRedactor(const std::string filePath);
	~FileRedactor();

	void CatFile();
	std::string& operator[] (unsigned int num);


private:
	void ReadFile();

	std::map<unsigned long long, std::string> storage_;
	std::fstream inpOutThread_;
};