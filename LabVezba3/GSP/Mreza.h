#ifndef MREZA_H
#define MREZA_H
#include <iostream>
#include <string>
#include "Exceptions.h"
#include "GradskaLinija.h"
#include "Lista3.h"
class Mreza
{
public:
	Mreza();
	//mozemo koristiti podrazumevane kopirajuce i premestajuce konstruktore
	//operatore dodele i destruktore, jer mreza sadrzi liniju po vrednosti
	//a GradskaLinija sama po sebi ima te konstruktore definisane
	//pa ce program samo pozitvati njih
	Mreza(const Mreza&) = default;
	Mreza(Mreza&&) = default;
	Mreza& operator=(const Mreza&) = default;
	Mreza& operator=(Mreza&&) = default;
	~Mreza() = default;
	Mreza& operator+=(const GradskaLinija& g);
	friend std::ostream& operator<<(std::ostream& os, const Mreza& m);
	Lista3<GradskaLinija>& getLines();
private:
	Lista3<GradskaLinija> lines;
};
#endif

