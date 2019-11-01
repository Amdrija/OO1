#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <iostream>
#include "Pilot.h"

class Plane {
	std::string name;
	Pilot* captain;
	Pilot* copilot;
	int max_passengers;
public:
	std::string getName();
	Pilot* getCaptain();
	Pilot* getCopilot();
	int getMaxPassengers();
	Plane(std::string name_, int max_passengers_);
	Plane(const Plane& p) = delete;
	Plane(Plane&& p) = delete;
	//We don't want to delete pilot and copilot when we delete the plane, 
	//because they can fly another plane
	//So we just leave the deafult Destructor
	bool setCaptain(Pilot* captain_);
	bool setCopilot(Pilot* copilot_);
	void print();
};
#endif