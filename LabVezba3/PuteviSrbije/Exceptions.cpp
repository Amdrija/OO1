#include "Exceptions.h"

void Exception::write(std::ostream& os) const
{
	os << "Unknown Error Occured.";
}

std::ostream& operator<<(std::ostream& os, const Exception& e)
{
	os << "Exception: ";
	e.write(os);
	return os;
}

void CurrentElementMissingException::write(std::ostream& os) const
{
	os << "Current elemnt doesn't exsist.";
}

void LongitudeOutOfBoundsException::write(std::ostream& os) const
{
	os << "Longitude should be in the interval from -180 to 180 degrees.";
}

void LatitudeOutOfBoundsException::write(std::ostream& os) const
{
	os << "Latitude should be in the interval from -90 to 90 degrees.";
}

void NegativeFuelConsumptionException::write(std::ostream& os) const
{
	os << "Fuel consumption cannot be negative.";
}
