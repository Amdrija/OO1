#include "Korisnik.h"

Korisnik::Korisnik(const std::string& user_name_, const std::string& password_):user_name(user_name_){
	if (!isSecurePassword(password_)) {
		throw InsecurePasswordException();
	}
	password = password_;
}

const std::string& Korisnik::getUserName() const
{
	return user_name;
}

const std::string& Korisnik::getPassword() const
{
	return password;
}

void Korisnik::setPassword(const std::string& old_password, const std::string& new_password)
{
	if (old_password != password) {
		throw WrongPasswordException();
	}
	if (!isSecurePassword(new_password)) {
		throw InsecurePasswordException();
	}
	password = new_password;
}

bool Korisnik::isSecurePassword(const std::string& new_password) const
{
	/*
	int length = new_password.length();
	if (length < 8)
		return false;

	bool digit = false, letter = false;
	for (int i = 0; i <= length; i++) {
		if (digit && letter)
			return true;
		if (isdigit(new_password[i]))
			digit = true;
		else if (isalpha(new_password[i]))
			letter = true;
	}
	return false;
	*/
	//Potreban je GCC 4.9+ da bi regex_match radio normalno
	//Kod gore je za svaki slucaj, ako regex ne radi, ali ovo sa regexom je elegnatnije
	return new_password.length() >= 8 && std::regex_match(new_password, std::regex("([0-9].*[a-zA-Z])|([a-zA-Z].*[0-9])"));
}

bool operator==(const Korisnik& k1, const Korisnik& k2)
{
	return k1.getUserName() == k2.getUserName();
}

bool operator!=(const Korisnik& k1, const Korisnik& k2)
{
	return !(k1 == k2);
}

std::ostream& operator<<(std::ostream& os, const Korisnik& user)
{
	os << user.user_name;
	return os;
}
