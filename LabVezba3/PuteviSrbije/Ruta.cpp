#include "Ruta.h"

Ruta::Ruta(const Lista4<Deonica*>& route_list)
	:routes(route_list){}

Lista4<Deonica*>& Ruta::getRoutes()
{
	return routes;
}

const Lista4<Deonica*>& Ruta::getRoutes() const
{
	return routes;
}

double Ruta::length() const
{
	double length = 0;
	for (routes.setOnFirst(); !routes.currentIsNull(); ++routes) {
		length += (~*routes.getCurrentData());
	}
	return length;
}

double Ruta::operator()(double fuel_consumption) const
{
	if (fuel_consumption < 0)
		throw NegativeFuelConsumptionException();
	return length() * fuel_consumption / 100;
}

double Ruta::operator()(Deonica::VehicleCategory vehicle_category) const
{
	double toll_price = 0;
	for (routes.setOnFirst(); !routes.currentIsNull(); ++routes) {
		toll_price += (*routes.getCurrentData())(vehicle_category);
	}
	return toll_price;
}

void Ruta::write_routes(std::ostream& os) const
{
	for (routes.setOnFirst(); !routes.currentIsNull(); ++routes) {
		os << *routes.getCurrentData() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Ruta& r)
{
	r.write_routes(os);
	return os;
}
