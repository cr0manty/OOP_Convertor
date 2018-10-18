#include <iostream>
#include "Convertor.h"

int main(int argc, char *argv[])
{
	Convertor convert(argc, argv);
	
	try {
		convert.manip();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << Messages::SuccesfulConvert << std::endl;

	getchar();
	return 0;
}