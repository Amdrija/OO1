#include "Multimedija.h"

Multimedija::Multimedija(const std::string& name_): name(name_){}

std::ostream& operator<<(std::ostream& os, const Multimedija& m)
{
	os << m.name << ": "<<m.getDescription();
	return os;
}
