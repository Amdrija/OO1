#include "Deonica.h"

Deonica::Deonica(Mesto* start_, Mesto* end_, Category category_)
	:start(start_), end(end_), category(category_) {}

const Mesto& Deonica::getStart() const
{
	return *start;
}

const Mesto& Deonica::getEnd() const
{
	return *end;
}

double Deonica::operator~() const
{
	return *start - *end;
}

double Deonica::tollPrice(VehicleCategory vehicle_category) const
{
	if (category == Deonica::MAGISTRALA)
		return 0;

	return (vehicle_category == Deonica::TESKO ? heavy_category_price : light_category_price) * ~*this;
}

double Deonica::operator()(VehicleCategory vehicle_category) const
{
	return tollPrice(vehicle_category);
}

std::string Deonica::getCategory() const
{
	return category == Deonica::AUTOPUT ? "Autoput" : "Magistrala";
}

std::ostream& operator<<(std::ostream& os, const Deonica& d)
{
	os << d.getCategory() << "[" << d.getStart() << " -> " << d.getEnd() << "] - " << ~d << "km";
	return os;
}
