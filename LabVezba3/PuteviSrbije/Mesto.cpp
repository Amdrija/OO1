#include "Mesto.h"

const double Mesto::PI = 3.14159265358979323846;
Mesto::Mesto(const std::string& name_, double deg_longitude, double deg_latitude)
	:name(name_), degrees_latitude(deg_latitude), degrees_longitude(deg_longitude){
	if (!longitudeValid(deg_longitude))
		throw LongitudeOutOfBoundsException();

	if (!latitudeValid(deg_latitude))
		throw LatitudeOutOfBoundsException();
}

const std::string& Mesto::getName() const
{
	return name;
}

double Mesto::getDegreesLatitude() const
{
	return degrees_latitude;
}

double Mesto::getDegreesLongitude() const
{
	return degrees_longitude;
}

double Mesto::getRadLatitude() const
{
	return Mesto::toRadians(degrees_latitude);
}

double Mesto::getRadLongitude() const
{
	return Mesto::toRadians(degrees_longitude);
}

double Mesto::toRadians(double degrees)
{
	return degrees / 180 * Mesto::PI;
}

bool Mesto::longitudeValid(double degrees)
{
	//ovih 0.0005 je za granicni slucaj ako ukucamo 180 da prodje
	return degrees >= -180.0005 && degrees <= 180.0005;
}

bool Mesto::latitudeValid(double degrees)
{
	//da bi u granicnom slucaju racunalo -90 i 90
	return degrees >= -90.0005 && degrees <= 90.0005;
}

double operator-(const Mesto& m1, const Mesto& m2)
{
	return 2.0 * Mesto::earth_radius
		* asin(sqrt(pow(sin((m1.getRadLatitude() - m2.getRadLatitude()) / 2), 2)
			+ cos(m1.getRadLatitude()) * cos(m2.getRadLatitude())
			* pow(sin((m1.getRadLongitude() - m2.getRadLongitude()) / 2), 2)));
}

std::ostream& operator<<(std::ostream& os, const Mesto& m)
{
	os <<m.name<< "(" << m.degrees_longitude << ", " << m.degrees_latitude<< ")";
	return os;
}
