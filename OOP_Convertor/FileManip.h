#pragma once
#include "Data.h"
#include <fstream>
#include <vector>
#include "Messages.h"

class FileManip
{
protected:
	std::fstream file;
	std::vector<Data*> data;
public:
	FileManip(std::vector<Data*>&);
	std::vector<Data*> getData() const;
	virtual void manip() = 0;
	
	~FileManip();
};


