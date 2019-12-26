#ifndef EVIDENCIJA_H
#define EVIDENCIJA_H

#include "Lista.h"
#include "Korisnik.h"
#include <string>
class Evidencija
{
public:
	Evidencija();
	Evidencija(const Evidencija&) = delete;
	Evidencija(Evidencija&&) = delete;
	Evidencija& operator=(const Evidencija&) = delete;
	Evidencija& operator=(Evidencija&&) = delete;
	//mozemo koristiti podrazumevani destruktor
	//jer ce on pozvati destruktor liste
	~Evidencija() = default;
	Evidencija& operator+=(const Korisnik& user);
	const Korisnik& operator[](const std::string& user_name)const;
	Korisnik& operator[](const std::string& user_name);
	void operator()(const std::string& user_name);
	void setPassword(const std::string& user_name, const std::string& old_password, const std::string& new_password);
	friend std::ostream& operator<<(std::ostream& os, const Evidencija& e);
private:
	Lista<Korisnik> users;
};

#endif

