#include "FileManip.h"
#include <sstream>

FileManip::FileManip(std::string _input, std::string _output)
{
	if(_input.empty() || _output.empty())
		throw std::logic_error(Messages::EmptyArguments);

	output = _output;
	file.open(_input, std::ios_base::in);

	if (!file)
		throw std::logic_error(Messages::FileDoesnExist);
}

void FileManip::createData(std::string _line)
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

	Data DataBuff(productName, price);
	data.push_back(DataBuff);
}

void FileManip::_setinfo(std::string _input, std::string _output)
{
	output = _output;
	file.open(_input, std::ios_base::in);

	if (!file)
		throw std::logic_error(Messages::FileDoesnExist);
}

void FileManip::ReadData()
{
	while (!file.eof()) {
		char buffer[100] = {};
		file.getline(buffer, 100);
		createData(buffer);
	}
	file.close();
}

void FileManip::WriteData()
{
	file.open(output, std::ios_base::out | std::ios_base::trunc);

	if (!file)
		throw std::logic_error(Messages::FileDoesnExist);

	for (auto i : data)
		file << i._getname() << " " << i._getprice() << std::endl;
}

FileManip::~FileManip()
{
	//for (auto i : data)
	//	delete i;
}
