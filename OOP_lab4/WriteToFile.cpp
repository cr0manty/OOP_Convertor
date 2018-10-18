#include "WriteToFile.h"

WriteToFile::WriteToFile(std::string _filePath, std::vector<Data*> _data) :
	data(_data)
{
	if (_filePath.empty())
		throw std::logic_error(Messages::WrongPath);

	file.open(_filePath, std::ios_base::out | std::ios_base::trunc);
	if (!file)
		throw std::logic_error(Messages::FileDoesnExist);
}

void WriteToFile::manip()
{
	for (auto i : data)
		file << i->getProductName() << " " << i->getPrice() << std::endl;
}