#ifndef STAJALISTE_H
#define STAJALISTE_H
#include "Exceptions.h"
#include <string>
#include <iostream>
#include "Lista3.h"

//TODO: dodati kruznu zavisnost da svako stajaliste sadrzi listu pokazivaca na linije koje ga zadrze
class GradskaLinija;

class Stajaliste
{
public:
	Stajaliste(int id_, const std::string& name_, int zone_);
	//mozemo koristiti defualt kopirajuce i premestajuce konstruktore
	//operatore dodele i destrutkore
	Stajaliste(const Stajaliste&) = default;
	Stajaliste(Stajaliste&&) = default;
	Stajaliste& operator=(const Stajaliste&) = default;
	Stajaliste& operator=(Stajaliste&&) = default;
	//Kod kruzne zavisnosti ako brisemo stajaliste
	//onda moramo da razvezemo sve linije koje prolaze kroz njega?
	~Stajaliste();
	int getID()const;
	const std::string& getName() const;
	int getZone() const;
	friend bool operator==(const Stajaliste& s1, const Stajaliste& s2);
	friend bool operator!=(const Stajaliste& s1, const Stajaliste& s2);
	friend std::ostream& operator<<(std::ostream& os, const Stajaliste& s);
	friend GradskaLinija;
	const Lista3<GradskaLinija*>& getLines() const;
private:
	//da dodamo liniju koja prolazi kroz stajaliste
	void add_line(GradskaLinija* g);
	//da izbrisemo liniju koja prolazi kroz stajaliste
	void remove_line(GradskaLinija* g);
	int id;
	std::string name;
	int zone;
	Lista3<GradskaLinija*> lines;
};
#endif

