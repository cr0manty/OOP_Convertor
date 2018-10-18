#pragma once
#include "FileManip.h"

class Convertor : public FileManip
{
	double course;
	FileManip *fileWork;
	std::string input;
	std::string output;
	std::vector<Data*> newData();
	double convert(double);
	
public:

	Convertor(int, char**);
	void manip() override;
	~Convertor();
};

