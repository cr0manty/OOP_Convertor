#pragma once
#include "FileManip.h"

class Convertor : private FileManip
{
	double course;
	void _convertdata();
public:

	Convertor(int, char**);
	void convert();
};

