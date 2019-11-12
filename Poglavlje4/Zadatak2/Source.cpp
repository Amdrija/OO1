#include "Time.h"
#include <iostream>

int main() 
{
	Time t1(1, 2, 45);
	Time t2(7830);
	std::cout << t1 << std::endl;
	std::cout << t2<< std::endl;
	std::cout << t1.getTotalSeconds() << std::endl;
	std::cout << (int)t2 << std::endl;
	std::cout <<t1 + t2<< std::endl;
	std::cout << t2 - t1 << std::endl;
	t1 += t2;
	std::cout << t1++ << std::endl;
	Time t3(10, 0, 0);
	t3 -= t2;
	std::cout << t3-- << std::endl;
	std::cout << t1 << std::endl;
	std::cout << t3 << std::endl;
	std::cout << ++++t2 << std::endl;
	std::cout << ----t3 << std::endl;
	std::cout << "OPERATOR *" << std::endl;
	std::cout << t2 * 2 << std::endl;
	std::cout << "OPERATOR /" << std::endl;
	std::cout << t2 / 2 << std::endl;

	std::cout << "OPERATOR <" << std::endl;
	std::cout << (t1 < t2 )<< std::endl;
	std::cout << (t2 < t1) << std::endl;
	std::cout << "OPERATOR >" << std::endl;
	std::cout << (t1 > t2) << std::endl;
	std::cout << (t2 > t1) << std::endl;
	std::cout << "OPERATOR <=" << std::endl;
	std::cout << (t1 <= t2) << std::endl;
	std::cout << (t2 <= t1) << std::endl;
	std::cout << (t1 <= t1) << std::endl;
	std::cout << "OPERATOR >=" << std::endl;
	std::cout << (t1 >= t2) << std::endl;
	std::cout << (t2 >= t1) << std::endl;
	std::cout << (t1 >= t1) << std::endl;
	std::cout << "OPERATOR ==" << std::endl;
	std::cout << (t1 == t2) << std::endl;
	std::cout << (t1 == t1) << std::endl;
	std::cout << "OPERATOR !=" << std::endl;
	std::cout << (t1 != t2) << std::endl;
	std::cout << (t1 != t1) << std::endl;

	Time t4(0);
	std::cin >> t4;
	std::cout << t4 << std::endl;
	return 0;
}