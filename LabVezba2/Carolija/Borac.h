#ifndef BORAC_H
#define BORAC_H

#include <iostream>
#include "Karta.h"

class Borac: public Karta
{
public:
	Borac(const std::string& name, int mana_, int power_);
	/*Ostavljamo izbrisane konstruktore iz superklase Karta*/
	//u superklasi Karta koristimo default destruktor, mozemo i ovde
	int getPower() const override;
	friend bool operator>(const Borac& b1, const Borac& b2);
	friend bool operator<(const Borac& b1, const Borac& b2);
	Category getCategory() const override;
protected:
	void write(std::ostream& os) const override;
	Category category = BORAC;
	int power;
	bool summoning_sickness = true;
private:
};

#endif

