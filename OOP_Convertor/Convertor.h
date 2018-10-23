#pragma once
#include "FileManip.h"

class Convertor : private FileManip
{
	double course;
	void newData();
public:

	Convertor(int, char**);
	void convert();
};

