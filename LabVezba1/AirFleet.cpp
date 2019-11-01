#include "AirFleet.h"

AirFleet::AirFleet(std::string name_): name(name_),
													   first_plane(nullptr) {}

AirFleet::AirFleet(const AirFleet& a) {
	name = a.name;
	Element* temp = a.first_plane;
	while (temp) {
		add(temp->plane);
		temp = temp->next;
	}
}

AirFleet::AirFleet(AirFleet&& a) noexcept {
	name = a.name;
	first_plane = a.first_plane;
	a.first_plane = nullptr;
}

AirFleet::~AirFleet() {
	while (first_plane) {
		Element* t = first_plane;
		first_plane = first_plane->next;
		delete t;
	}
}

AirFleet& AirFleet::add(Plane* p) {
	Element* new_plane = new Element(p, first_plane);
	first_plane = new_plane;
	return *this;
}

std::string AirFleet::getName() {
	return name;
}

int AirFleet::totalPlanes() {
	Element* current_plane = first_plane;
	int total_planes = 0;
	while (current_plane) {
		total_planes++;
		current_plane = current_plane->next;
	}
	return total_planes;
}

int AirFleet::totalCapacity() {
	Element* current_plane = first_plane;
	int total_capacity = 0;
	while (current_plane) {
		total_capacity += current_plane->plane->getMaxPassengers();
		current_plane = current_plane->next;
	}
	return total_capacity;
}

int AirFleet::maximumPlaneCapacity() {
	Element* current_plane = first_plane;
	int max_capacity = 0;
	while (current_plane) {
		if (max_capacity < current_plane->plane->getMaxPassengers()) {
			max_capacity = current_plane->plane->getMaxPassengers();
		}
		current_plane = current_plane->next;
	}
	return max_capacity;
}

void AirFleet::print() {
	std::cout << name << std::endl;
	Element* current_plane = first_plane;
	while (current_plane) {
		current_plane->plane->print();
		current_plane = current_plane->next;
	}
}
