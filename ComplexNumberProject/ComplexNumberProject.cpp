#include <iostream>
#include "ComplexNumber.h"

int main()
{
	ComplexNumber c1;
	std::cin >> c1;

	ComplexNumber c2;
	std::cin >> c2;

	ComplexNumber result = c2 + c1;

	std::cout << result << std::endl;
}
