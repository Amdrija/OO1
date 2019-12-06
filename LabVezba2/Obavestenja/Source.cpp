#include <iostream>
#include "Obavestenje.h"
#include "Objava.h"
#include "Korisnik.h"
#include "ListaObavestenja.h"

void testObavestenje() {
	Obavestenje o1(nullptr);
	Obavestenje o2(nullptr);
	Obavestenje o3(o2);
	Obavestenje o4 = Obavestenje(nullptr);
	o3 = o1;
	o2 = Obavestenje(nullptr);
	std::cout << o1;
	std::cout << o2;
	std::cout << o3;
	std::cout << o4;
	std::cout << o1.getID() << std::endl;
	std::cout << (o1.getUser() == nullptr) << std::endl;
	std::cout<< o1.isRead()<<std::endl;
}

void testObjava() {
	std::cout << "*********************" << std::endl;
	Objava o1(nullptr, "Andrija vas je bocnuo.");
	Objava o2(nullptr, "Banovani ste sa platforme.");
	Objava o3 = o2;
	Objava o4 = Objava(nullptr, "Napustite prostoriju.");
	Objava o5(nullptr, "");
	Objava o6(nullptr, "");
	o5 = o1;
	o6 = Objava(nullptr, "Mark Zakerberg vas je dodao za prijatelja.");
	std::cout << o1;
	std::cout << o2;
	std::cout << o3;
	std::cout << o4;
	std::cout << o5;
	std::cout << o6; //ispisivace 12 za id jer ce se premestanjem promeniti ID
}

void testKorisnik() {
	std::cout << "************************" << std::endl;
	Korisnik andrija("Andrija");
	Korisnik nikola("Nikola");
	Objava* o = new Objava(nullptr, "Mark Zakerberg vas je dodao za prijatelja.");
	andrija.send(new Objava(nullptr, "Lajk."), &nikola);
	andrija.send(o, &nikola);
	andrija.send(new Objava(nullptr, "Banovani ste."), &nikola);
	std::cout << andrija;
	std::cout << nikola;
	std::cout << +nikola.getNotifications() << std::endl;
	nikola.getNotifications()();
	nikola.getNotifications()[o->getID()]->readNotification();
	std::cout << +nikola.getNotifications() << std::endl;
	nikola.getNotifications()();
	!nikola.getNotifications();
	std::cout << +nikola.getNotifications() << std::endl;
	~nikola.getNotifications();
	std::cout << nikola.getNotifications();
}

int main() {
	testObavestenje();
	testObjava();
	testKorisnik();
	return 0;
}