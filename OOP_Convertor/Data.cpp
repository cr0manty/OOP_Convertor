#include "Data.h"

Data::Data(std::string const &_name, double _price) :
	productName(_name), price(_price)
{
}

std::string Data::getProductName() const
{
	return productName;
}

double Data::getPrice() const
{
	return price;
}

Data Data::convert(double _course)
{
	return Data(productName, _course);
}
