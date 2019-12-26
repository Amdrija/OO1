#include <iostream>
#include "Exceptions.h"
#include "Lista2.h"
#include "Datum.h"
#include "Automobil.h"
void test_Lista() {
	try {
		Lista2<int> list;
		list += 3;
		list += 4;
		list += 5;
		std::cout << list << std::endl;
		std::cout << list.getLength() << std::endl;
		std::cout << list.currentIsNull()<< std::endl;
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
		std::cout << list<< std::endl;
		list.removeCurrent();
		list += 6;
		std::cout << list << std::endl;
	}
	catch (const Exception& e) {
		std::cout << e << std::endl;
	}
}

void test_Datum() {
	Datum d1(25, 5, 2019);
	Datum d2(14, 5, 2019);
	Datum d3 = d1;
	Datum d4;
	std::cout << d4 << std::endl;
	std::cout << d1 << std::endl;
	std::cout << (d1 < d2 )<< std::endl;
	std::cout << d1 - d2 << std::endl;
	std::cout << d2["day"] <<"  " << d2["month"] << " "<< d2["year"] << std::endl;
	std::cout << d4["day"] << "  " << d4["month"] << " " << d4["year"] << std::endl;
	std::cout << (Datum::isLeapYear(2020));
	std::cout << (Datum::isLeapYear(2100));
	std::cout << (Datum::isLeapYear(2400));
	std::cout << (Datum::isLeapYear(2009))<<std::endl;
	std::cout << Datum::isDayValid(35, 5, 2009);
	std::cout << Datum::isDayValid(31, 5, 2009);
	std::cout << Datum::isDayValid(30, 4, 2009);
	std::cout << Datum::isDayValid(29, 2, 2009);
	std::cout << Datum::isDayValid(29, 2, 2008) << std::endl;
	std::cout << Datum::isMonthValid(0) << std::endl;
	try {
		//Datum d3(30, -5, -1);
		//d2["asfsd"];
		//Datum d4(0, 1, 3);
		//std::cout << d2 - d1;
	}
	catch (const Exception & e) {
		std::cout << e;
	}
}

void test_automobil() {
	try {
		Automobil audi("Audi A3", Datum(), 250, Automobil::LIMUIZINA, 125);
		std::cout << audi << std::endl;
		std::cout << audi.getManufacturingDate() << std::endl;
		std::cout << audi.getModelName() << std::endl;
		std::cout << audi.getNumberOfPassengers() << std::endl;
		std::cout << audi.getPricePerDay(Datum(30, 3, 2024), false) << std::endl;
		std::cout << audi.getPricePerDay(Datum(30, 3, 2020), false) << std::endl;
		std::cout << audi.getPricePerDay(Datum(30, 3, 2020), true) << std::endl;
		std::cout << audi.getType() << std::endl;
		Vozilo* pok = &audi;
		Vozilo* kopija = pok->copy();
		std::cout << *kopija << std::endl;
		std::cout << (kopija == pok) << std::endl;
		delete kopija;
	}
	catch (const Exception & e) {
		std::cout << e;
	}
}

int main() {
	test_Lista();
	test_Datum();
	test_automobil();
}