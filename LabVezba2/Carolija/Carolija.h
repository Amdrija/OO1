#ifndef CAROLIJA_H
#define CAROLIJA_H

#include "Karta.h"
#include <string>
class Carolija: public Karta
{
public:
	Carolija(const std::string& name, int mana_);
	Category getCategory() const override;
private:
	Category category = CAROLIJA;
};

#endif

