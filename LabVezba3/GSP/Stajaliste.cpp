#include "Stajaliste.h"
#include "GradskaLinija.h"
Stajaliste::Stajaliste(int id_, const std::string& name_, int zone_)
	:id(id_),name(name_),zone(zone_){}

Stajaliste::~Stajaliste()
{
	for (lines.setOnFirst(); !lines.currentIsNull(); ++lines) {
		lines.getCurrentData()->remove_stop(*this);
	}
}

int Stajaliste::getID() const
{
	return id;
}

const std::string& Stajaliste::getName() const
{
	return name;
}

int Stajaliste::getZone() const
{
	return zone;
}

const Lista3<GradskaLinija*>& Stajaliste::getLines() const
{
	return lines;
}

void Stajaliste::add_line(GradskaLinija* g)
{
	lines += g;
}

void Stajaliste::remove_line(GradskaLinija* g)
{
	for (lines.setOnFirst(); !lines.currentIsNull() && !(lines.getCurrentData() == g); ++lines);
	lines.removeCurrent();
}

bool operator==(const Stajaliste& s1, const Stajaliste& s2)
{
	return s1.id == s2.id;
}

bool operator!=(const Stajaliste& s1, const Stajaliste& s2)
{
	return !(s1 == s2);
}

std::ostream& operator<<(std::ostream& os, const Stajaliste& s)
{
	os << "["<<s.zone<<"]#"<<s.id<<" - "<<s.name;
	return os;
}
