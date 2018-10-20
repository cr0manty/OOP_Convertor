#pragma once
#include "FileManip.h"

class WriteToFile : public FileManip
{
public:
	WriteToFile(std::string, std::vector<Data*>&);
	void manip() override;
	~WriteToFile();
};

