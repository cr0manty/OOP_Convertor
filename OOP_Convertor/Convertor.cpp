#include "Convertor.h"
#include <algorithm>

Convertor::Convertor(int argc, char** argv)
{
	if (argc < 4)
		throw std::logic_error(Messages::MissArguments);

	for (int i = 0; i < 4; i++)
		if (!strlen(argv[i]))
			throw std::logic_error(Messages::EmptyArguments);

	FileManip::getInfo(argv[1], argv[2]);

	if (std::stod(argv[3]) <= 0)
		throw std::logic_error(Messages::CourseMustBeNum);

	course = std::stod(argv[3]);
}

void Convertor::convert()
{
	FileManip::ReadData();
	newData();
	FileManip::WriteData();
	throw std::logic_error(Messages::SuccesfulConvert);
}

void Convertor::newData()
{
	std::vector<Data>::iterator it = FileManip::data.begin();
	std::transform(it, FileManip::data.end(), FileManip::data.begin(), convert(*it));
}

Data Convertor::convert(Data & _data)
{
	_data.convert(course);
	return _data;
}

