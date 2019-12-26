#ifndef MULTIMEDIJA_H
#define MULTIMEDIJA_H
#include <string>
#include "Exceptions.h"
class Multimedija
{
public:
	Multimedija(const std::string& name_);
	//Dovoljno je koristiti podrazumevane konstruktore i destruktore
	Multimedija(const Multimedija&) = default;
	Multimedija(Multimedija&&) = default;
	Multimedija& operator=(const Multimedija&) = default;
	Multimedija& operator=(Multimedija&&) = default;
	~Multimedija() = default;
	virtual unsigned int getSize() const = 0;
	virtual std::string getDescription() const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Multimedija& m);
	virtual Multimedija* copy() const = 0;
private:
	std::string name;
};
#endif

