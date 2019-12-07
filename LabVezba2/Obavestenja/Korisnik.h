#ifndef KORISNIK_H
#define KORISNIK_H

#include <iostream>
#include "ListaObavestenja.h"
#include "Obavestenje.h"

class Korisnik
{
public:
	Korisnik(const std::string& s);
	Korisnik(const Korisnik&) = delete;
	Korisnik(Korisnik&&) = delete;
	Korisnik& operator=(const Korisnik&) = delete;
	Korisnik& operator=(Korisnik&&) = delete;
	//Moze default destruktor
	std::string getUserName() const;
	friend std::ostream& operator<< (std::ostream & os, const Korisnik & user);
	void send(Obavestenje* notification, Korisnik* receiver) const;
	void receive(Obavestenje* notification);
	ListaObavestenja& getNotifications();
	//ne moze da bude const jer vraca referencu na promenljivu lvrednost
	//pa onda dalje u programu mozemo da koristimo tu referencu
private:
	std::string username;
	ListaObavestenja notifications;
	//Koristimo da je lista obavestenja u korisnku, jer nema smisla da postoje obavestenja
	//koja nikoga ne obavestavaju
};
#endif

