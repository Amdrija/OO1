#ifndef PILOT_H
#define PILOT_H

#include <string>
#include <iostream>
class Pilot {
	std::string name;
	int flight_hours;
	bool is_on_flight;
public:
	Pilot(std::string name_, int flight_hours_, bool is_on_flight_ = false);
	Pilot(const Pilot& p) = delete;
	Pilot(Pilot&& p) = delete;
	std::string getName();
	int getFlightHours();
	bool isFlying();
	int incrementFlightHours(int hours);
	bool setIsOnFlight(bool is_on_flight_);
	void print();
};
#endif

