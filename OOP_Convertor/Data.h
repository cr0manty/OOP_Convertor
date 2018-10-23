#pragma once
#include <string>

class Data
{
	std::string name;
	double price;
public:
	Data(std::string, double);
	std::string getProductName() const;
	double getPrice() const;
	Data convert(double);
};

