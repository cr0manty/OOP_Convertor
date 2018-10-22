#pragma once
#include <string>

class Data
{
	std::string productName;
	double price;
public:
	Data(std::string const &, double);
	std::string getProductName() const;
	double getPrice() const;
	Data convert(double);
};

