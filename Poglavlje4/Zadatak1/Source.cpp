#include "Complex.h"
#include <iostream>

int main()
{
	Complex a;
	Complex b(1, 1);
	Complex c(-1, -1);
	std::cout << a << std::endl;
	std::cin >> a;
	std::cout << a << std::endl;
	std::cout << b.getReal() << std::endl;
	std::cout << b.getImaginary() << std::endl;
	std::cout << b.modulus() << std::endl;
	std::cout << b.argument() << std::endl;
	std::cout << ~b << std::endl;
	std::cout << b + c << std::endl;
	std::cout << b - c << std::endl;
	std::cout << b * c << std::endl;
	std::cout << b / c << std::endl;
	std::cout << (double)a + 2.0 << std::endl;
	b += Complex(1, 0);
	b *= Complex(2, 0);
	c -= Complex(1, 0);
	b /= c;
	std::cout << b << std::endl;
	return 0;
}