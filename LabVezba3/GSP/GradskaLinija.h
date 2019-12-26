#ifndef GRADKSA_LINIJA_H
#define GRADKSA_LINIJA_H
#include "Exceptions.h"
#include "Stajaliste.h"
#include "Lista3.h"
#include <string>
#include <iostream>

class GradskaLinija
{
public:
	GradskaLinija(const std::string& id_, const Lista3<Stajaliste*>& list_stops);
	//dovoljno je koristiti podrazumevane konstruktore 
	//operatore dodele i destrktor
	//jer kakda brisemo liniju ne zelimo da obrisemo stajalista koja se
	//u njoj nalaze, vec samo pokazivace na njih
	GradskaLinija(const GradskaLinija&) = default;
	GradskaLinija( GradskaLinija&&) = default;
	GradskaLinija& operator=(const GradskaLinija&) = default;
	GradskaLinija& operator=(GradskaLinija&&) = default;
	~GradskaLinija(); // ako dodamo kruznu zavisnost linije i stajalista
	//onda treba paziti kada se linija izbrise da se u stajalistu izbrise ta linija iz
	//liste gradskih linija
	const std::string& getID() const;
	Lista3<Stajaliste*>& getStops();
	const Lista3<Stajaliste*>& getStops()const;
	friend int operator&(const GradskaLinija& g1, const GradskaLinija& g2);
	friend std::ostream& operator<<(std::ostream& os, const GradskaLinija& g);
	void remove_stop(const Stajaliste& s);
private:
	std::string id;
	 Lista3<Stajaliste*> stops; //TODO: da li dodati mutable za listu stajalista?
	 void write_stops(std::ostream& os)const;
};
#endif

