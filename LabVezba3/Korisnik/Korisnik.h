#ifndef KORISNIK_H
#define KORISNIK_H
#include <string>
#include <regex>
#include "Exceptions.h"
#include <iostream>
class Korisnik
{
public:
	Korisnik(const std::string& user_name_, const std::string& password_);
	//Mozemo koristiti ugradjene kopirajuce konstrkutore i operatore dodele
	//kao i ugradjeni destrkutor
	Korisnik(const Korisnik&) = default;
	Korisnik(Korisnik&&) = default;
	Korisnik& operator=(const Korisnik&) = default;
	Korisnik& operator=(Korisnik&&) = default;
	~Korisnik() = default;
	//Lozinka treba da bude bar 8 karaktera, 1 karakter mora biti slovo i bar 1 karakter cifra
	const std::string& getUserName() const;
	const std::string& getPassword() const;
	void setPassword(const std::string& old_password, const std::string& new_password);
	friend bool operator==(const Korisnik& k1, const Korisnik& k2);
	friend bool operator!=(const Korisnik& k1, const Korisnik& k2);
	friend std::ostream& operator<<(std::ostream& os, const Korisnik& user);
private:
	std::string user_name;
	std::string password;
	bool isSecurePassword(const std::string&) const;
};
#endif

