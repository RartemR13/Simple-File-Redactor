#pragma once 

#include <string>
#include <map>
#include <iostream>
#include <fstream>

class FileRedactor {
public:

	FileRedactor(const std::string filePath) :
		storage_(),
		inpOutThread_(filePath, std::ios::in | std::ios::out)
	{}

	~FileRedactor() {
		inpOutThread_.close();
	}

	void ReadFile() {
		std::string line;

		for (int i = 0; getline(inpOutThread_, line); ++i)
			storage_[i] = line;
	}

	void CatFile() {
		for (auto it = storage_.begin(); it != storage_.end(); ++it)
			std::cout << it->second << std::endl;
	}


private:
	std::map<unsigned long long, std::string> storage_;
	std::fstream inpOutThread_;

	bool fileWasOpened_;
};