#ifndef RUTA_H
#define RUTA_H

#include <string>
#include <iostream>
#include "Exceptions.h"
#include "Deonica.h"
#include "Lista4.h"
class Ruta
{
public:
	Ruta(const Lista4<Deonica*>& route_list);
	//dovoljno je koristiti default kopirajuce i premstajuce konstruktore
	// i operatore dodele i destruktore, jer kada kopiramo listu deonica
	//mi zelimo da imamo samo kopiranu referencu na tu deonicu
	// a ne i samu deonicu. Isto kada brisemo listu deonica, ne zelimo da izbrisemo
	//deonicu, jer je ona mozda deo neke druge liste
	Ruta(const Ruta&) = default;
	Ruta(Ruta&&) = default;
	Ruta& operator=(const Ruta&) = default;
	Ruta& operator=(Ruta&&) = default;
	~Ruta() = default;
	//postoje i za promenljive objekte getRoutes
	//ako zelimo da posle dodajemo deonice
	//ili na neki drugi nacin modifikujemo listu
	Lista4<Deonica*>& getRoutes();
	const Lista4<Deonica*>& getRoutes() const;
	double length() const;
	double operator()(double fuel_consumption)const;
	double operator()(Deonica::VehicleCategory vehicle_category) const;
	friend std::ostream& operator<<(std::ostream& os, const Ruta& r);
private:
	Lista4<Deonica*> routes;
	void write_routes(std::ostream& os) const;
};
#endif

