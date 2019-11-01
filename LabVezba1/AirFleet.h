#ifndef AIRFLEET_H
#define AIRFLEET_H

#include "Plane.h"

class AirFleet {
	std::string name;
	struct Element {
		Plane* plane;
		Element* next;
		Element(Plane* p, Element* n = nullptr) {
			plane = p;
			next = n;
		}
	};
	Element* first_plane;
public:
	AirFleet(std::string name_);
	AirFleet(const AirFleet& a);
	AirFleet(AirFleet&& a) noexcept;
	~AirFleet();
	AirFleet& add(Plane* p);
	std::string getName();
	int totalPlanes();
	int totalCapacity();
	int maximumPlaneCapacity();
	void print();
};
#endif
