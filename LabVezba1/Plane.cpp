#include "Plane.h"

std::string Plane::getName() {
	return name;
}

Pilot* Plane::getCaptain() {
	return captain;
}

Pilot* Plane::getCopilot() {
	return copilot;
}

int Plane::getMaxPassengers() {
	return max_passengers;
}

Plane::Plane(std::string name_, int max_passengers_): name(name_), 
																				  max_passengers(max_passengers_),
																				  captain(nullptr), 
																				  copilot(nullptr) {}

bool Plane::setCaptain(Pilot* captain_) {
	if (captain_->isFlying() || captain_->getFlightHours() < 100) {
		return false;
	}
	captain = captain_;
	return captain->setIsOnFlight(true);
}

bool Plane::setCopilot(Pilot* copilot_)
{
	if (copilot_->isFlying()) {
		return false;
	}
	copilot = copilot_;
	return copilot->setIsOnFlight(true);
}

void Plane::print() {
	std::cout << name << " - " << max_passengers << std::endl;
}
