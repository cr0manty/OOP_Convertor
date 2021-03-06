#include "Convertor.h"
#include <algorithm>

Convertor::Convertor(int argc, char** argv)
{
	if (argc < 4)
		throw std::logic_error(Messages::MissArguments);

	for (int i = 0; i < 4; i++)
		if (!strlen(argv[i]))
			throw std::logic_error(Messages::EmptyArguments);

	FileManip::_setinfo(argv[1], argv[2]);

	if (std::stod(argv[3]) <= 0)
		throw std::logic_error(Messages::CourseMustBeNum);

	course = std::stod(argv[3]);
}

void Convertor::convert()
{
	FileManip::ReadData();
	_convertdata();
	FileManip::WriteData();
	throw std::logic_error(Messages::SuccesfulConvert);
}

void Convertor::_convertdata()
{
	std::vector<Data*> _mynewdata;
	std::transform(data.begin(), FileManip::data.end(), std::back_inserter(_mynewdata), [&](Data *_data) {
		_data->convert(course);
		return _data;
	});
	data = _mynewdata;
}