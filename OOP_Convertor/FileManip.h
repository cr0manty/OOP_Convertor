#pragma once
#include "Data.h"
#include <fstream>
#include <vector>
#include "Messages.h"

class FileManip
{
private:
	std::fstream file;
	std::string output;
	void createData(std::string);
protected:
	FileManip() {}
	std::vector<Data*> data;
	void _setinfo(std::string, std::string);
	void ReadData();
	void WriteData();
	~FileManip();
};
