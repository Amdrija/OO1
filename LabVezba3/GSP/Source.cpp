#include "Exceptions.h"
#include "Lista3.h"
#include <iostream>
#include "Stajaliste.h"
#include "GradskaLinija.h"
#include "Mreza.h"
void test_Lista() {
	try {
		Lista3<int> list;
		list += 3;
		list += 4;
		list += 5;
		list += 7;
		list += 8;
		std::cout << list <<  "******"<<std::endl;
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
		Lista3<int> kopija(list);
		list.removeCurrent();
		std::cout << list << "******" << std::endl;
		std::cout << kopija << "******" << std::endl;
		std::cout << kopija.getCurrentData() << std::endl;
	}
	catch (const Exception & e) {
		std::cout << e << std::endl;
	}
}

void test_Stajaliste() {
	Stajaliste s1(558, "Juzni Bulevar", 1);
	Stajaliste s2(557, "Juzni Bulevar", 1);
	Stajaliste s3(558, "Juzsdfni Bulevar", 134);
	std::cout << s1 << std::endl;
	std::cout << s1.getID() << std::endl;
	std::cout << s1.getName() << std::endl;
	std::cout << s1.getZone() << std::endl;
	std::cout << (s1 == s2) << " " << (s1 == s3) << std::endl;
}

void test_GradskaLinija() {
	Stajaliste s1(551, "Juzni Bulevar", 1);
	Stajaliste s2(552, "Kalenic Pijaca", 1);
	Stajaliste s3(553, "Tehnicki Fakulteti", 1);
	Stajaliste s4(554, "Pravni Fakultet", 1);
	Stajaliste s5(555, "Glavna Posta", 1);
	Stajaliste s6(556, "Trg Republike", 1);
	Stajaliste* s7 = new Stajaliste(1, "Dinamik", 1);
	Lista3<Stajaliste*> lista1, lista2;
	lista1 += &s1;
	lista1 += &s2;
	lista1 += &s3;
	lista1 += &s4;
	lista2 += &s5;
	lista2 += &s2;
	lista2 += &s6;
	lista2 += &s3;
	lista1 += s7;
	lista2 += s7;
	GradskaLinija g26("26",lista1);
	GradskaLinija* g24 = new GradskaLinija("24", lista2);
	std::cout << g24->getID() << std::endl;
	std::cout << (g26 & *g24 )<< std::endl;
	std::cout << g26;
	std::cout << *g24 << "*************\n";
	delete s7;
	std::cout << g26;
	std::cout << *g24 << "*************\n";
	delete g24;
	for (s2.getLines().setOnFirst(); !s2.getLines().currentIsNull(); ++s2.getLines()) {
		std::cout << *s2.getLines().getCurrentData() << std::endl;
	}
	
}

void test_mreza() {
	Stajaliste s1(551, "Juzni Bulevar", 1);
	Stajaliste s2(552, "Kalenic Pijaca", 1);
	Stajaliste s3(553, "Tehnicki Fakulteti", 1);
	Stajaliste s4(554, "Pravni Fakultet", 1);
	Stajaliste s5(555, "Glavna Posta", 1);
	Stajaliste s6(556, "Trg Republike", 1);
	Lista3<Stajaliste*> lista1, lista2;
	lista1 += &s1;
	lista1+= &s2;
	lista1 += &s3;
	lista1 += &s4;
	lista2 += &s5;
	lista2 += &s2;
	lista2 += &s6;
	lista2 += &s3;
	GradskaLinija g26("26", lista1);
	GradskaLinija g24("24", lista2);
	Mreza m;
	m += g26;
	m += g24;
	std::cout << m << std::endl;
}

int main() {
	//test_Lista();
	//test_Stajaliste();
	test_GradskaLinija();
	//test_mreza();
	return 0;
}