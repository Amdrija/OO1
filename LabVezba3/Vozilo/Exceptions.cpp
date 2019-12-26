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

void NegativeDayDateDifferenceException::write(std::ostream& os) const
{
	os << "Difference in days between 2 dates is negative.";
}

void InvalidDateException::write(std::ostream& os) const
{
	os << "You have input an invalid date.";
}

void InvalidDateStringPickerException::write(std::ostream& os) const
{
	os << "You have not put \"month\" \"year\" or \"day\".";
}

void NominalVehiclePriceNegativeException::write(std::ostream& os) const
{
	os << "Nominal vehicle price per day cannot be negative.";
}

void VehicleRentStartDateException::write(std::ostream& os) const
{
	os << "Cannnot rent a vehicle before it is produced.";
}

void DriverPriceNegativeException::write(std::ostream& os) const
{
	os << "Driver price per day cannot be negative.";
}
