#include "Convertor.h"
#include "ReadFromFile.h"
#include "WriteToFile.h"

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
	ReadFromFile inputFile(input);
	fileWork = &inputFile;
	fileWork->manip();
	
	WriteToFile outputFile(output, newData());
	fileWork = &outputFile;
	fileWork->manip();
}

std::vector<Data*> Convertor::newData()
{
	std::vector<Data*> newData;
	for (auto i : fileWork->getData()) {
		Data *DataBuff = new Data(i->getProductName(), convert(i->getPrice()));
		newData.push_back(DataBuff);
	}
	return newData;
}

double Convertor::convert(double _price)
{
	return _price * course * 1.2;
}

Convertor::~Convertor()
{
	delete FileManip;
}
