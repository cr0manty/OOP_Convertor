#include "Data.h"

Data::Data(std::string _name, double _price) :
	name(_name), price(_price)
{
}

std::string Data::_getname() const
{
	return name;
}

double Data::_getprice() const
{
	return price;
}

void Data::convert(double _course)
{
	this->price = price * _course * 1.2;
}
