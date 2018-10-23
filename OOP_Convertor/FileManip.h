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
	std::vector<Data> data;
	void getInfo(std::string, std::string);
	FileManip(std::string, std::string);
	void ReadData();
	void WriteData();
	~FileManip();
};
