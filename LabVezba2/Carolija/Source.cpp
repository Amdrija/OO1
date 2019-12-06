#include <iostream>
#include "Karta.h"
#include "Carolija.h"
#include "Borac.h"
#include "Carobnjak.h"
#include "Zbirka.h"
#include "Igrac.h"
/*
void test_Karta() {
	Karta sibirski("Sibirski Plavac", 7);
	Karta nikola("Nikola", 1);
	std::cout << sibirski.getCardName() << std::endl;
	std::cout << nikola.getMana() << std::endl;
	std::cout << sibirski.getID() << " " << nikola.getID() << std::endl;
	std::cout << sibirski << std::endl;
}*/

/*
void test_carolija() {
	Carolija crna_rupa("Crna Rupa", 5);
	Carolija sakurecu("Sakurecu", 0);
	std::cout << crna_rupa << std::endl;
	std::cout << sakurecu << std::endl;
	std::cout << crna_rupa.getCardName() << std::endl;
	std::cout << crna_rupa.getID() << std::endl;
	std::cout << (crna_rupa.getCategory() == Karta::CAROLIJA ? "Carolija" : 0)<< std::endl;
	std::cout << crna_rupa.getMana() << std::endl;
 }*/

/*
void test_borac() {
	Borac nikola("Nikola", 6, 10);
	Borac iva("Iva", 10, 1923);
	std::cout << nikola.getCardName() << std::endl;
	std::cout << (nikola.getCategory() == Karta::BORAC ? "Borac" : 0) << std::endl;
	std::cout << nikola.getID() << std::endl;
	std::cout << nikola.getMana() << std::endl;
	std::cout << nikola.getPower() << std::endl;
	std::cout << nikola << std::endl;
	std::cout << (nikola > iva) << std::endl;
	std::cout << (nikola < iva) << std::endl;
}*/

void test_zbirka() {
	Zbirka spil;
	std::cout << "Spil:" << std::endl << spil << " " << spil.getSize() << std::endl;
	spil.addCard(new Carobnjak("Yugi", 5, 10));
	spil.addCard(new Carobnjak("Dzoi", 6, 8));
	spil.addCard(new Carobnjak("Yaden", 3, 12));
	
	//test kopirajuceg konstruktora
	Zbirka groblje(spil);
	std::cout << "Groblje:" << std::endl << groblje << " " << groblje.getSize() << std::endl;

	//test raznih metoda zbirke
	std::cout << "Spil:" << std::endl << spil << " " << spil.getSize() << std::endl;
	std::cout << *spil[(int)0] << std::endl;
	std::cout << *spil[(unsigned)3] << std::endl << std::endl;;


	//test da li brise random
	~spil;
	std::cout << spil << " " << spil.getSize() << std::endl;

	//posle ove 2 metode, spil bi trebalo da je uvek prazna lista
	spil((unsigned)spil[(int)1]->getID());
	spil((int)0);
	std::cout << "Spil:" << std::endl << spil << " " << spil.getSize() << std::endl << std::endl;
	

	//Test kopirajuceg opreatora dodele
	spil = groblje;
	std::cout << "Spil:" << std::endl << spil << " " << spil.getSize() << std::endl << std::endl;

	//Test premestajuceg operator dodele
	Zbirka ruka;
	ruka = Zbirka(spil);
	std::cout << "Ruka:" << std::endl << ruka << " " << ruka.getSize() << std::endl << std::endl;
	std::cout << "Najslabiji borac:" << *ruka.getFighterWithMinPower() << std::endl;
	//posle ove 3 metode, spil bi trebalo da je uvek prazna lista
	~spil;
	~spil;
	~spil;
	std::cout << "Spil:" << std::endl << spil << " " << spil.getSize() << std::endl << std::endl;

	//ako prosledimo da doda nepostojecu kartu, nista se ne desava
	std::cout << spil.addCard(nullptr).getSize();
}

void test_igrac() {
	Zbirka* spil1 = new Zbirka;
	spil1->addCard(new Carobnjak("Yugi", 5, 10));
	spil1->addCard(new Carobnjak("Dzoi", 6, 8));
	spil1->addCard(new Carobnjak("Yaden", 3, 12));
	spil1->addCard(new Carobnjak("Baby Yoda", 0, 100000));
	Igrac andrija("Andrija", 10, 3, spil1);

	Zbirka* spil2 = new Zbirka;
	spil2->addCard(new Carobnjak("Kaiba", 2, 4));
	spil2->addCard(new Carobnjak("Pegaz", 6, 7));
	spil2->addCard(new Carobnjak("Dzos", 11, 9));
	Igrac  nikola("Nikola", 0, 5, spil2);
	std::cout << andrija.hasLostGame() << " " << nikola.hasLostGame() << std::endl;
	std::cout << andrija.canActivate((*spil1)[(int)0]) << " " << andrija.canActivate((*spil1)[(int)2]) << std::endl;
	andrija.changeHP(-2);
	nikola.changeHP(2);
	andrija.changeMana(-3);
	nikola.changeMana(3);
	std::cout << andrija.getName() << " " << nikola.getName() << std::endl;
	std::cout << andrija.getHP() << " " << nikola.getHP() << std::endl;
	std::cout << andrija.getMana() << " " << nikola.getMana() << std::endl;
	std::cout << *andrija.getDeck() << std::endl;
	std::cout << *andrija.getHand() << std::endl;
	std::cout << *andrija.getActive() << std::endl;
	std::cout << *andrija.getGraveyard() << std::endl;

	std::cout << "Vucemo karte." << std::endl;
	andrija.draw();
	andrija.draw();
	std::cout << andrija.draw() << std::endl;;
	std::cout << "DECK:\n"<<*andrija.getDeck() << std::endl;
	std::cout << "Ruka:\n"<< *andrija.getHand() << std::endl;

	andrija.changeMana(100);
	andrija.activateCard((*andrija.getHand())[(int)0]);
	andrija.activateCard((*andrija.getHand())[(int)0]);
	andrija.sendActiveCardToGraveyard((*andrija.getActive())[(int)0]);
	std::cout << "Andrija Spil:\n" << *andrija.getDeck() << std::endl;
	std::cout << "Andrija Ruka:\n" << *andrija.getHand() << std::endl;
	std::cout << "Andrija Aktivne:\n" << *andrija.getActive() << std::endl;
	std::cout << "Andrija Groblje:\n" << *andrija.getGraveyard() << std::endl;
	std::cout << andrija.getMana() << std::endl;

	/*Ovde kao da igramo igru malo*/
	nikola.draw();
	nikola.draw();
	nikola.activateCard((*nikola.getHand())[(int)0]);
	std::cout << "Nikola Spil:\n" << *nikola.getDeck() << std::endl;
	std::cout << "Nikola Ruka:\n" << *nikola.getHand() << std::endl;
	std::cout << "Nikola Aktivne:\n" << *nikola.getActive() << std::endl;
	std::cout << "Nikola Groblje:\n" << *nikola.getGraveyard() << std::endl;
	std::cout << "Nikolin zivot: " << nikola.getHP() << std::endl;
	(*andrija.getActive())[(int)0]->useCard(&andrija, &nikola);
	std::cout <<"Posle napada Andrije sa " << *(*andrija.getActive())[(int)0] << std::endl;
	std::cout << "Nikola Spil:\n" << *nikola.getDeck() << std::endl;
	std::cout << "Nikola Ruka:\n" << *nikola.getHand() << std::endl;
	std::cout << "Nikola Aktivne:\n" << *nikola.getActive() << std::endl;
	std::cout << "Nikola Groblje:\n" << *nikola.getGraveyard() << std::endl;
	std::cout << "Nikolin zivot: " << nikola.getHP() << std::endl << std::endl;
	(*andrija.getActive())[(int)0]->useCard(&andrija, &nikola);
	std::cout << "Posle napada Andrije sa " << *(*andrija.getActive())[(int)0] << std::endl;
	std::cout << "Nikola Spil:\n" << *nikola.getDeck() << std::endl;
	std::cout << "Nikola Ruka:\n" << *nikola.getHand() << std::endl;
	std::cout << "Nikola Aktivne:\n" << *nikola.getActive() << std::endl;
	std::cout << "Nikola Groblje:\n" << *nikola.getGraveyard() << std::endl;
	std::cout << "Nikolin zivot: " << nikola.getHP() << std::endl;
}
int main() {
	//test_zbirka();
	test_igrac();
	return 0;
}