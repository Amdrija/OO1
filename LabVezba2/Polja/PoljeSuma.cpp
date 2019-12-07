#include "PoljeSuma.h"

PoljeSuma::PoljeSuma(unsigned int density_, int neprohodnost_)
	:Polje(neprohodnost_), density(density_){}

int PoljeSuma::getDensity() const
{
	return density;
}

PoljeSuma* PoljeSuma::copy() const
{
	return new PoljeSuma(density, neprohodnost);
}

char PoljeSuma::getTag() const
{
	return 'S';
}

void PoljeSuma::write(std::ostream&os) const
{
	os << " (" << density << ") ";
}
