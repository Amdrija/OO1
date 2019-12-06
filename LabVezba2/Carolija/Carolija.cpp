#include "Carolija.h"

Carolija::Carolija(const std::string& name, int mana_)
	: Karta(name, mana_){}

Karta::Category Carolija::getCategory() const
{
	return CAROLIJA;
}
