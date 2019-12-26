#include "Exceptions.h"
#include "Mesto.h"
#include "Lista4.h"
#include "Deonica.h"
#include "Ruta.h"
void test_Lista() {
	try {
		Lista4<int> list;
		list += 3;
		list += 4;
		list += 5;
		list += 7;
		list += 8;
		std::cout << list << "******" << std::endl;
		std::cout << list.getLength() << std::endl;
		std::cout << list.currentIsNull() << std::endl;
		//++list;
		//list.getCurrentData();
		//list.removeCurrent();
		//list.next();
		list.setOnFirst();
		std::cout << list.getCurrentData() << std::endl;
		++list;
		std::cout << list.getCurrentData() << std::endl;
		list.removeCurrent();
		list.setOnFirst();
		std::cout << "******\n" << list << "******" << std::endl;
		list.removeCurrent();
		list += 6;
		list.setOnFirst();
		++list;
		++list;
		Lista4<int> kopija(list);
		list.removeCurrent();
		std::cout << list << "******" << std::endl;
		std::cout << kopija << "******" << std::endl;
		std::cout << kopija.getCurrentData() << std::endl;
	}
	catch (const Exception & e) {
		std::cout << e << std::endl;
	}
}

void test_Mesto() {
	Mesto bg("Beograd", 20.457273, 44.787197);
	Mesto nis("Nis", 21.895759, 43.320902);
	std::cout << bg.getName() << std::endl;
	std::cout << bg.getDegreesLatitude() << " " << bg.getDegreesLongitude() << std::endl;
	std::cout << bg.getRadLatitude() << " " << bg.getRadLongitude() << std::endl;
	std::cout << nis << std::endl;
	std::cout << bg - nis << std::endl;
}

void test_Deonica() {
	Mesto bg("Beograd", 20.457273, 44.787197);
	Mesto nis("Nis", 21.895759, 43.320902);
	Mesto sabac("Sabac", 19.6908, 44.7489);
	Deonica e75(&bg, &nis, Deonica::AUTOPUT);
	Deonica bgsa(&bg, &sabac, Deonica::MAGISTRALA);
	std::cout << e75 << std::endl;
	std::cout << bgsa << std::endl;
	std::cout << e75.tollPrice(Deonica::TESKO) << std::endl;
	std::cout << e75.tollPrice(Deonica::LAKO) << std::endl;
	std::cout << bgsa.tollPrice(Deonica::TESKO) << std::endl;
}

void test_Ruta() {
	Mesto bg("Beograd", 20.457273, 44.787197);
	Mesto nis("Nis", 21.895759, 43.320902);
	Mesto sabac("Sabac", 19.6908, 44.7489);
	Deonica e75(&bg, &nis, Deonica::AUTOPUT);
	Deonica bgsa(&bg, &sabac, Deonica::MAGISTRALA);
	Ruta ruta = Lista4<Deonica*>();
	ruta.getRoutes() += &e75;
	ruta.getRoutes() += &bgsa;
	std::cout << ruta;
	std::cout << ruta.length() << std::endl;
	std::cout << ruta(6.5) << std::endl;
	std::cout << ruta(Deonica::LAKO) << std::endl;
}

int main() {
	//test_Lista();
	//test_Mesto();
	//test_Deonica();
	test_Ruta();
	return 0;
}