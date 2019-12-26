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

void InsecurePasswordException::write(std::ostream& os) const
{
	os << "Password must be at least 8 character long and contain at least 1 digit and 1 letter.";
}

void WrongPasswordException::write(std::ostream& os) const
{
	os << "Access denied. You have typed in the wrong password.";
}

void ElementIndexOutOfBoundsException::write(std::ostream& os) const
{
	os << "Index is out of bounds.";
}

void UserAlreadyExistsException::write(std::ostream& os) const
{
	os << "User with that username already exsists.";
}

void UserNotFoundException::write(std::ostream& os) const
{
	os << "User with that username not found.";
}
