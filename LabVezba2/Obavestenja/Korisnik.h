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
private:
	std::string username;
	ListaObavestenja notifications;
};
#endif

