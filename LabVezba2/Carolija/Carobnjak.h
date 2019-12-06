#ifndef CAROBNJAK_H
#define CAROBNJAK_H

#include "Borac.h"
#include <iostream>
class Carobnjak: public Borac
{
public:
	Carobnjak(const std::string& name, int mana_, int power_);
	/*Ostavljamo izbrisane konstruktore iz superklase Borac*/
	//U borcu koristimo defualt destruktor, mozemo i ovde
	void useCard(Igrac* controller, Igrac* opponent) const override;
protected:
	void write(std::ostream&) const override;
private:
};
#endif

