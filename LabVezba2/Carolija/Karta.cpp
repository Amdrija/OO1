#include "Karta.h"
unsigned int Karta::setID = 0;

Karta::Karta(const std::string& name, int mana_)
	:card_name(name), mana(mana_){}

std::string Karta::getCardName() const
{
	return card_name;
}

int Karta::getMana() const
{
	return mana;
}

unsigned int Karta::getID() const
{
	return id;
}

std::ostream& operator<<(std::ostream& os, const Karta& k)
{
	os << "[" << k.id << "]" << "\"" << k.card_name << "\" (cena: " << k.mana << ")";
	k.write(os);
	return os;
}
