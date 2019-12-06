#ifndef OBJAVA_H
#define OBJAVA_H

#include "Obavestenje.h"
#include <string>

class Objava : public Obavestenje
{
public:
	Objava(Korisnik*, const std::string&);
	/*
	Dovoljni je podrazumevani kopirajuci i premestajuci konstruktor itd.
	jer ce kompajler svakako da pozove kopirajuce i premestajuce konstruktore
	superklase kada generise podrazumevane kopirajuce i premestajuec konstruktore.
	*/
	std::string getText() const;
protected:
	void write(std::ostream&) const override;
private:
	std::string text;
};
#endif

