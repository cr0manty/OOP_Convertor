#include "Data.h"

Data::Data(std::string _name, double _price) :
	name(_name), price(_price)
{
}

std::string Data::getProductName() const
{
	return name;
}

double Data::getPrice() const
{
	return price;
}

Data Data::convert(double _course)
{
	this->price = price * _course * 1.2;
	return *this;
}
