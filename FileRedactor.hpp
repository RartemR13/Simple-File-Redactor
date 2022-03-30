#pragma once 

#include <string>
#include <map>
#include <iostream>
#include <fstream>

class FileRedactor {
public:

	FileRedactor() = default;
	FileRedactor(const std::string);
	~FileRedactor();

	void CatFile();
    void WriteFile();
	void ReadFile(const std::string);
	std::string& operator[] (unsigned long long);

private:
	std::map<unsigned long long, std::string> storage_;
	std::fstream inpOutThread_;
    std::string filePath_;

	void ReadFile();

	bool fileOpen_;

};