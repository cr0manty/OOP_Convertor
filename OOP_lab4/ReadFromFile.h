#pragma once
#include "FileManip.h"


class ReadFromFile : public FileManip
{
	void createData(std::string);
public:
	ReadFromFile(std::string);
	void manip() override;
};

