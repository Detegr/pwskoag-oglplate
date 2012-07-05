#include "filereader.h"

std::string C_FileReader::M_ReadToStr(const std::string& path)
{
	std::ifstream i(path.c_str(), std::ifstream::in);
	std::string out;
	if(i.is_open())
	{
		std::string line;
		while(i.good())
		{
			while(getline(i, line))
			{
				out += "\n" + line;
			}
		}
	}
	i.close();
	return out;
}
#include <iostream>
std::vector<std::string> C_FileReader::M_ReadToArray(const std::string& path)
{
	std::ifstream i(path.c_str(), std::ifstream::in);
	std::vector<std::string> out;
	if(i.is_open())
	{
		std::string line;
		while(i.good())
		{
			while(getline(i, line))
			{
				out.push_back(line);
			}
		}
	}
	i.close();
	return out;
}
