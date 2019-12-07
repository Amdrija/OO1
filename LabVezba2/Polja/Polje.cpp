#include "Polje.h"

Polje::Polje(int neprohodnost_)
	:neprohodnost(neprohodnost_){
	if (neprohodnost < min_neprohodnost || neprohodnost > max_neprohodnost)
		neprohodnost = 100;
}

int Polje::getNeprohodnost() const
{
	return neprohodnost;
}

Polje Polje::operator++(int)
{
	Polje p = *this;
	neprohodnost++;
	setNeprohodnostInBounds();
	return p;
}

Polje Polje::operator--(int)
{
	Polje p = *this;
	neprohodnost--;
	setNeprohodnostInBounds();
	return p;
}

Polje& Polje::operator+=(unsigned int difference)
{
	neprohodnost += difference;
	setNeprohodnostInBounds();
	return *this;
}

Polje& Polje::operator-=(unsigned int difference)
{
	neprohodnost -= difference;
	setNeprohodnostInBounds();
	return *this;
}

Polje* Polje::copy() const
{
	return new Polje(neprohodnost);
}

char Polje::getTag() const
{
	return 'P';
}

//sluzi da ne moram stalno da ponavljam ifove
void Polje::setNeprohodnostInBounds()
{
	if (neprohodnost < min_neprohodnost)
		neprohodnost = min_neprohodnost;

	if (neprohodnost > max_neprohodnost)
		neprohodnost = max_neprohodnost;
}

std::ostream& operator<<(std::ostream& os, const Polje& p)
{
	os << p.getTag()<< "_" << p.neprohodnost;
	p.write(os);
	return os;
}
