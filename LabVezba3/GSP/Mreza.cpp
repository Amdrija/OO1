#include "Mreza.h"

Mreza::Mreza()
	:lines(){}

Mreza& Mreza::operator+=(const GradskaLinija& g)
{
	lines += g;
	return *this;
}

Lista3<GradskaLinija>& Mreza::getLines()
{
	return lines;
}

std::ostream& operator<<(std::ostream& os, const Mreza& m)
{
	for (m.lines.setOnFirst(); !m.lines.currentIsNull(); ++m.lines) {
		GradskaLinija* line = &m.lines.getCurrentData();
		os << line->getID() << " : ";
		line->getStops().setOnFirst();
		if (!line->getStops().currentIsNull()) {
			os << *line->getStops().getCurrentData() << " -> ";

			//for sluzi samo da iteriramo do poslednjeg stajalista
			for (line->getStops().setOnFirst(); !line->getStops().currentIsNull() && !line->getStops().isCurrentLast(); ++line->getStops());
			
			if (line->getStops().isCurrentLast())
				os << *line->getStops().getCurrentData();
		}
		os << std::endl;
	}
	return os;
}
