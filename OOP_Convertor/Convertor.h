#pragma once
#include "FileManip.h"

class Convertor : private FileManip
{
	double course;
	void _convertdata();
	Data _newdata(Data);
public:

	Convertor(int, char**);
	void convert();
};

