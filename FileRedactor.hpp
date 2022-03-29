#pragma once 

#include <string>
#include <map>
#include <fstream>

class FileRedactor {
public:
	FileRedactor(std::fstream& InpOutThread) :
		InpOutThread_(InpOutThread)
	{}

	FileRedactor(std::string FilePath) {
		InpOutThread_.open(FilePath);
	}

private:
	std::map<unsigned long long, std::string> storage_;
	std::fstream InpOutThread_;
};