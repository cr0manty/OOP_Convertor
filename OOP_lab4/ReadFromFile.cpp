#include "ReadFromFile.h"
#include <sstream>


void ReadFromFile::createData(std::string _line)
{
	if (_line.empty())
		return;

	std::istringstream in(_line);
	std::string buffer;
	std::string productName;
	double price;
	in >> buffer;
	productName = buffer;
	buffer.clear();

	in >> buffer;
	if (buffer.empty())
		return;

	price = std::stod(buffer);
	buffer.clear();

	in >> buffer;
	if (!buffer.empty())
		return;

	Data *DataBuff = new Data(productName, price);
	data.push_back(DataBuff);
}

ReadFromFile::ReadFromFile(std::string _filePath)
{
	file.open(_filePath, std::ios_base::in);

	if (!file)
		throw std::logic_error(Messages::FileDoesnExist);
}

void ReadFromFile::manip()
{
	while (!file.eof()) {
		char buffer[100] = {};
		file.getline(buffer, 100);
		createData(buffer);
	}
}
