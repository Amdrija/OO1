#include <iostream>
#include "dot.h"
int main() {
	Dot t1;
	t1.read();
	Dot t2;
	std::cout << t2.distance(t1) << std::endl;
	t2.read();
	std::cout << t2.distance(t1) << std::endl;

	return 0;
}