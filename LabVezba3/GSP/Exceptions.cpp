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
