#include "FileLoader.h"

std::string loadFile(std::string fileName) {
	std::ifstream fs(fileName);
	
	std::string line;
	std::string fileData = "";

	while (std::getline(fs, line)) {
		fileData.append(line);
		fileData.append("\n");
	}

	return fileData;
}