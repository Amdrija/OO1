#include "Borac.h"

Borac::Borac(const std::string& name, int mana_, int power_)
	:Karta(name, mana_), power(power_){}

int Borac::getPower() const
{
	return power;
}

Karta::Category Borac::getCategory() const
{
	return category;
}

void Borac::write(std::ostream& os) const
{
	os << "(snaga: " << power << ") ";
}

bool operator>(const Borac& b1, const Borac& b2)
{
	return b1.power > b2.power;
}

bool operator<(const Borac& b1, const Borac& b2)
{
	return b2 > b1;
}
