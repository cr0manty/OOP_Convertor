#include "FileManip.h"

std::vector<Data*> FileManip::getData() const
{
	return data;
}

FileManip::~FileManip()
{
	for (auto i : data)
		delete i;
}
