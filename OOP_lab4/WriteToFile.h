#pragma once
#include "FileManip.h"

class WriteToFile : public FileManip
{
	std::vector<Data*> data;
public:
	WriteToFile(std::string, std::vector<Data*>);
	void manip() override;
};

