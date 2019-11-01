#include "Pilot.h"

Pilot::Pilot(std::string name_, int flight_hours_, bool is_on_flight_) : name(name_), 
																									 flight_hours(flight_hours_), 
																									 is_on_flight(is_on_flight_) {}

std::string Pilot::getName() { 
	return name;
}

int Pilot::getFlightHours() { 
	return flight_hours;
}
bool Pilot::isFlying() {
	return is_on_flight;
}

int Pilot::incrementFlightHours(int hours) {
	if (hours > 0) {
		flight_hours += hours;
	}
	return flight_hours;
}

bool Pilot::setIsOnFlight(bool is_on_flight_) {
	is_on_flight = is_on_flight_;
	return is_on_flight;
}

void Pilot::print() {
	std::cout << name << " ( " << flight_hours << " ) - " << (is_on_flight ? "L" : "N") << std::endl;
}