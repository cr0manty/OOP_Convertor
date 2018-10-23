#pragma once
#include "FileManip.h"

class Convertor : private FileManip
{
	double course;
	void newData();
	Data convert(Data&);
public:

	Convertor(int, char**);
	void convert();
};

