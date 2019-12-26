#include "GradskaLinija.h"

GradskaLinija::GradskaLinija(const std::string& id_, const Lista3<Stajaliste*>& list_stops)
	:id(id_), stops(list_stops){
	for (list_stops.setOnFirst(); !list_stops.currentIsNull(); ++list_stops) {
		(*list_stops.getCurrentData()).add_line(this);
	}
}

GradskaLinija::~GradskaLinija()
{
	for (stops.setOnFirst(); !stops.currentIsNull(); ++stops) {
		(*stops.getCurrentData()).remove_line(this);
	}
}

const std::string& GradskaLinija::getID() const
{
	return id;
}

Lista3<Stajaliste*>& GradskaLinija::getStops()
{
	return stops;
}

const Lista3<Stajaliste*>& GradskaLinija::getStops() const
{
	return stops;
}

void GradskaLinija::remove_stop(const Stajaliste& s)
{
	for (stops.setOnFirst(); !stops.currentIsNull() && !(*stops.getCurrentData() == s); ++stops);
	if (stops.currentIsNull())
		throw CurrentElementMissingException();

	stops.removeCurrent();
}

void GradskaLinija::write_stops(std::ostream& os) const
{
	for (stops.setOnFirst(); !stops.currentIsNull(); ++stops) {
		std::cout << *stops.getCurrentData() << std::endl;
	}
}

int operator&(const GradskaLinija& g1, const GradskaLinija& g2)
{
	int same_stops = 0;
	for (g1.stops.setOnFirst(); !g1.stops.currentIsNull(); ++g1.stops) {
		for (g2.stops.setOnFirst(); !g2.stops.currentIsNull(); ++g2.stops) {
			if (*g1.stops.getCurrentData() == *g2.stops.getCurrentData()) {
				same_stops++;
			}
		}
	}
	return same_stops;
}

std::ostream& operator<<(std::ostream& os, const GradskaLinija& g)
{
	os << g.id << std::endl;
	g.write_stops(os);
	return os;
}
