#include "Evidencija.h"

Evidencija::Evidencija(){}

Evidencija& Evidencija::operator+=(const Korisnik& user)
{
	for (int i = 0; i < users.getLength(); i++) {
		if (users[i] == user)
			throw UserAlreadyExistsException();
	}
	users += user;
	return *this;
}

const Korisnik& Evidencija::operator[](const std::string& user_name) const
{
	for (int i = 0; i < users.getLength(); i++) {
		if (users[i].getUserName() == user_name) {
			return users[i];
		}
	}

	throw UserNotFoundException();
}

Korisnik& Evidencija::operator[](const std::string& user_name)
{
	for (int i = 0; i < users.getLength(); i++) {
		if (users[i].getUserName() == user_name) {
			return users[i];
		}
	}

	throw UserNotFoundException();
}

void Evidencija::operator()(const std::string& user_name)
{
	for (int i = 0; i < users.getLength(); i++) {
		if (users[i].getUserName() == user_name) {
			users(i);
			return;
		}
	}

	throw UserNotFoundException();
}

void Evidencija::setPassword(const std::string& user_name, const std::string& old_password, const std::string& new_password)
{
	try { 
		(*this)[user_name].setPassword(old_password, new_password);
	}
	catch (UserNotFoundException & e) {
		std::cout << e << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Evidencija& e)
{
	os <<e. users;
	return os;
}
