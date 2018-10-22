#include "Convertor.h"
#include "ReadFromFile.h"
#include "WriteToFile.h"
#include <algorithm>

Convertor::Convertor(int argc, char** argv)
{
	if (argc < 4)
		throw std::logic_error(Messages::MissArguments);
	

	for(int i =0;i<4;i++)
		if(!strlen(argv[i]))
			throw std::logic_error(Messages::EmptyArguments);

	if (std::stod(argv[3]) <= 0)
		throw std::logic_error(Messages::CourseMustBeNum);

	input = argv[1];
	output = argv[2];
	course = std::stod(argv[3]);
}

void Convertor::manip()
{
	ReadFromFile inputFile(input, data);
	fileWork = &inputFile;
	fileWork->manip();
	this->data = fileWork->getData();
	newData();

	WriteToFile outputFile(output, this->data);
	fileWork = &outputFile;
	fileWork->manip();
	throw std::logic_error(Messages::SuccesfulConvert);
}

Data Convertor::convert(std::string name, double _price)
{
	return Data(name, _price * course * 1.2);
}

void Convertor::newData()
{
	std::vector<Data*>::iterator it = data.begin();
	std::transform(it, data.end(), data.begin(), [](Data _d,double _course) {
		_d.convert(_course);
		return _d;
	}
	);
	/*std::vector<Data*> newData;
	for (auto i : this->data) {
		Data *DataBuff = new Data(i->getProductName(), convert(i->getPrice()));
		newData.push_back(DataBuff);
	}
	this->data = newData;*/
}

