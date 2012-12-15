#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "Exception.h"
#include <algorithm>

typedef std::map<std::string,std::string> valueMap;
typedef std::pair<std::string,std::string> strPair;

class FileParser
{
private:
	valueMap map;
	void parseFile(std::string path);
	void parseLine(std::string& line);
	valueMap getMap();
public:
	FileParser(std::string path);
	std::string getValue(std::string);
	
	virtual ~FileParser(void);
};
