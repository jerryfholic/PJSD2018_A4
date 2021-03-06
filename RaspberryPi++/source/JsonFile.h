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
	JsonFile(const char* filePath);	//Constructor either parses the contents of an existing file or creates a new file with contents {"NULL":"null"} if none is found
	void fill(const char* input);
	void edit(const char* key, std::string newVal);
	void edit(const char* key, int newVal);
	void print(void);
	int getIntValue(const char* key);
	const char* getStringValue(const char* key);

private:
	const char* filePath;
	rapidjson::Document* doc;	//Model that simulates the JSON file within the program
	std::fstream* file;			//In/outputstream to the JSON file
	int updateFile();			//Updates the file with the current contents of doc
	int updateDoc();			//Updates the file with the current contents of file
};

#endif /* JSONFILE_H_ */
