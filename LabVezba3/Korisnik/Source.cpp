#include "Korisnik.h"
#include <iostream>
#include "Exceptions.h"
#include "Lista.h"
#include "Slika.h"
#include "Multimedija.h"
#include "Evidencija.h"

void test_korisnik() {
	try {
		Korisnik k1("andrija", "nikola21");
		Korisnik k2("andrija", "34lolsdfsdfdsfg");
		std::cout << k1.getUserName() << " " << k1.getPassword() << std::endl;
		std::cout << k2 << std::endl;
		k2.setPassword("34lolsdfsdfdsfg","12345678o");
		std::cout << (k1 == k2) <<" " << k2.getPassword()<< std::endl;
	}
	catch (const Exception & e) {
		std::cout << e;
	}
}

void test_Lista() {
	try {
		Lista<int> list;
		list += 2;
		list += 3;
		list += 4;
		std::cout << list.getLength() << " " << list << std::endl;
		std::cout << list[1] << std::endl;
		Lista<int> l2(list);
		list(0);
		std::cout << list.getLength() << " " << list << std::endl;
		std::cout << l2.getLength() << " " << l2 << std::endl;
		l2 = list;
		std::cout << l2.getLength() << " " << l2 << std::endl;
	}
	catch (const Exception & e) {
		std::cout << e << std::endl;
	}
}

void test_Slika() {
	Slika s1("Slika1",20, 30, 1);
	std::cout << s1 << std::endl;
	Multimedija* m = &s1;
	Multimedija* kopija = m->copy();
	std::cout << *kopija << std::endl;
	std::cout << (kopija == m) << std::endl;
	delete kopija;
}

void test_Evidencija() {
	Evidencija ek;
	std::cout << ek << std::endl;
	try {
		ek += Korisnik("andrija", "nikola123");
		ek += Korisnik("nikola", "andrija123");
		ek += Korisnik("iva", "anrija123");
		//ek += Korisnik("andrija", "asdfdfgf234235");
		std::cout << ek << std::endl;
		std::cout << ek["andrija"] << std::endl;
		ek("andrija");
		std::cout << ek << std::endl;
		//ek("asdf");
		//ek["asd"];
		ek.setPassword("nikola", "andrija123", "dfgfdg2334");
		std::cout << ek["nikola"].getPassword() << std::endl;
	}
	catch (const Exception & e) {
		std::cout << e;
	}
}
int main() {
	test_korisnik();
	test_Lista();
	test_Slika();
	test_Evidencija();
	return 0;
}