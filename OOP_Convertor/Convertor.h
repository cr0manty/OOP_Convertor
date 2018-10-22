#pragma once
#include "FileManip.h"

class Convertor
{
	double course;
	FileManip *fileWork;
	std::string input;
	std::string output;
	std::vector<Data*> data;
	Data convert(std::string,double);
	void newData();
	
public:

	Convertor(int, char**);
	void manip();
};

