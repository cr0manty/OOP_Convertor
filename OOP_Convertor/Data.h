#pragma once
#include <string>

class Data
{
	std::string name;
	double price;
public:
	Data(std::string, double);
	std::string _getname() const;
	double _getprice() const;
	Data convert(double);
};

