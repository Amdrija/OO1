#include "Quad.h"

int main() {
	Quad::setMaxVolume(45);
	Quad* q1 = Quad::create(1, 0.5, 4);
	q1->write();
	std::cout << q1->volume() << std::endl;
	std::cout << Quad::getMaxVolume() << std::endl;
	std::cout << Quad::getTotalVolume() << std::endl;
	Quad* q2 = Quad::read();
	q2->write();
	std::cout << Quad::getTotalVolume() << std::endl;
	delete q1;
	delete q2;
	return 0;
}