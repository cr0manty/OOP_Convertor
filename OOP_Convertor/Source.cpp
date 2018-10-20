#include <iostream>
#include "Convertor.h"

int main(int argc, char *argv[])
{
	try {
		Convertor convert(argc, argv);
		convert.manip();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	getchar();
	return 0;
}