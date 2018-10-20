#pragma once
#include "FileManip.h"

class Convertor
{
	double course;
	FileManip *fileWork;
	std::string input;
	std::string output;
	std::vector<Data*> data;
	double convert(double);
	void newData();
	
public:

	Convertor(int, char**);
	void manip();
};

