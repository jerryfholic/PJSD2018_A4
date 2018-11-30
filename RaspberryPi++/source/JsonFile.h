/*
 * JsonFile.h
 *
 *  Created on: Nov 26, 2018
 *      Author: matthijs
 */
#include "document.h"
#include <fstream>

#ifndef JSONFILE_H_
#define JSONFILE_H_

class JsonFile {
public:
	JsonFile(const char* filePath);
	void fill(const char* input);
	void edit(const char* key, std::string newVal);
	void edit(const char* key, int newVal);
	void print(void);
	int getIntValue(const char* key);
	const char* getStringValue(const char* key);

private:
	const char* filePath;
	rapidjson::Document* doc;
	std::fstream* file;
	int updateFile();
	int updateDoc();
};

#endif /* JSONFILE_H_ */
