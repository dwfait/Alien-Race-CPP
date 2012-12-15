#include "FileParser.h"

FileParser::FileParser(std::string path)
{
	parseFile(path);
}

FileParser::~FileParser(void)
{
}


void FileParser::parseFile(std::string path)
{
	std::ifstream file(path.c_str());
	if (file.is_open())
	{
		std::string line;
		while (! file.eof() )
		{
			std::getline(file,line);
			parseLine(line);
		}
		file.close();
	} else {
		throw Exception("Can't open file: "+path);
		//throw 20;
	}

}



void FileParser::parseLine(std::string& line)
{
	if (line.length() < 3) return;

	line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
	size_t equals = line.find_first_of("=");
	
	std::string lhs,rhs;
	lhs = line.substr(0,equals);
	rhs = line.substr(equals+1);
	//std::cout << "'" << lhs << "=" << rhs << "'" <<std::endl;
	map.insert(strPair(lhs,rhs));


}


valueMap FileParser::getMap()
{
	return map;
}


std::string FileParser::getValue(std::string key)
{
	std::transform(key.begin(),key.end(),key.begin(),::tolower);
	valueMap::iterator it;

	it = map.find(key);

	std::string rtn;

	if (it != map.end())
		rtn = it->second;

	return rtn;


}
