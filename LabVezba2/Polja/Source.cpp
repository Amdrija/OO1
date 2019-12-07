#include <iostream>
#include "Polje.h"
#include "PoljePut.h"
#include "PoljeSuma.h"
#include "Mapa.h"
void test_polje() {
	Polje p1;
	Polje p2(1);
	Polje p3(1020); //konstruktor ce staviti na default vrednost(100)
	std::cout << p1.getNeprohodnost() << std::endl;
	p1++;
	p2--;
	p2--;
	std::cout << p1++ << std::endl;
	std::cout << p1++ << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << (p1 -= 4) << std::endl;
	std::cout << (p3 += 5) << std::endl;
}

void test_Put() {
	PoljePut p1(PoljePut::ZEMLJANI);
	PoljePut p2(PoljePut::KAMENI, 50);
	PoljePut p3(p2);
	p3++;
	std::cout << (p1.getCategory() == PoljePut::ZEMLJANI ? "ZEMLJANI" : "KAMENI" )<< std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
}

void test_Suma() {
	PoljeSuma s1(50, 40);
	PoljeSuma s2(30);
	Polje* ps = &s1;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s1.getDensity() << std::endl;
	std::cout << s1.getNeprohodnost() << std::endl;
	std::cout << ps->getNeprohodnost() << std::endl;
	s2 = PoljeSuma(20, 30);
	std::cout << s2 << std::endl;
}

void testMapa() {
	Mapa m(5, 6);
	std::cout << m.getHeight() << " x " << m.getWidth() << std::endl;
	std::cout << m << std::endl;
	std::cout << m.changeTileWithForest(3, 4, 50);
	std::cout << m.changeTileWithRoad(2, 3, PoljePut::KAMENI);
	std::cout << m.changeTileWithForest(-1, 2, 35);
	std::cout << m.changeTileWithRoad(2, 250, PoljePut::KAMENI)<<std::endl;
	Mapa m2(m);
	Mapa m3(1, 1);
	std::cout << m3 << std::endl;
	m3 = Mapa(3, 3);
	std::cout << m3 << std::endl;
	std::cout << m2 << std::endl;
	m += 20;
	std::cout << m << std::endl;
	m -= 10;
	std::cout << m << std::endl;
	std::cout << m2 << std::endl;
}

int main() {
	//test_polje();
	//test_Put();
	//test_Suma();
	testMapa();
}
