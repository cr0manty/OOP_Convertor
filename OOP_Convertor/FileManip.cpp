#include "FileManip.h"

FileManip::FileManip(std::vector<Data*> &_data) :
	data(_data)
{
}

std::vector<Data*> FileManip::getData() const
{
	return data;
}

FileManip::~FileManip()
{
	file.close();
}
