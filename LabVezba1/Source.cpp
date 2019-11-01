#include "Pilot.h"
#include "Plane.h"
#include "AirFleet.h"
void test_pilots() {
	Pilot milos("Milos Stojkovic", 4500, true);
	Pilot dusan("Dusan Tesanovic", 450, false);
	Pilot nina("Nina Nikolic", 6700);
	milos.print();
	dusan.print();
	nina.print();
	std::cout << milos.getFlightHours() << std::endl;
	std::cout << dusan.getName() << std::endl;
	std::cout << nina.isFlying() << std::endl;
	milos.incrementFlightHours(150);
	dusan.incrementFlightHours(-150);
	milos.print();
	dusan.print();
}

void test_planes() {
	Pilot milos("Milos Stojkovic", 4500, true);
	Pilot dusan("Dusan Tesanovic", 450, false);
	Pilot nina("Nina Nikolic", 6700);
	Pilot nikola("Nikola Cvetanovic", 55);

	Plane boing767("Boing 767", 181);
	Plane airbus320("Airbus A320", 180);
	boing767.print();

	boing767.setCaptain(&nina);
	boing767.setCopilot(&dusan);
	std::cout << boing767.setCaptain(&nikola) << std::endl;
	std::cout << boing767.setCopilot(&milos) << std::endl;
	std::cout << airbus320.getName() << std::endl;
	std::cout << airbus320.getMaxPassengers() << std::endl;
	boing767.print();
	boing767.getCaptain()->print();
	boing767.getCopilot()->print();
}

void test_airfleet() {
	Pilot milos("Milos Stojkovic", 4500, true);
	Pilot dusan("Dusan Tesanovic", 450, false);
	Pilot nina("Nina Nikolic", 6700);
	Pilot nikola("Nikola Cvetanovic", 55);

	Plane boing767("Boing 767", 181);
	Plane airbus320("Airbus A320", 180);
	Plane boing747("Boing 747", 660);
	Plane airbus380("Airbus A380", 644);
	Plane concorde("Concorde", 92);
	boing767.setCaptain(&nina);
	boing767.setCopilot(&dusan);

	AirFleet a("Air Serbia");
	AirFleet b("Fly Emirates");
	a.add(&boing767);
	a.add(&airbus320);
	a.add(&concorde);
	b.add(&boing747);
	b.add(&airbus380);
	AirFleet c = AirFleet("Air France").add(&concorde);

	std::cout << a.getName() << std::endl;
	std::cout << b.totalCapacity() << std::endl;
	std::cout << a.totalPlanes() << std::endl;
	std::cout << a.maximumPlaneCapacity() << std::endl;
	a.print();
	b.print();
	c.print();
}

int main() {
	//test_pilots();
	//test_planes();
	//test_airfleet();
	return 0;
}