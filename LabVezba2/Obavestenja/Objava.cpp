#include "Objava.h"

Objava::Objava(Korisnik* user_, const std::string& text_)
	: Obavestenje(user_), text(text_){}

std::string Objava::getText() const
{
	return text;
}

void Objava::write(std::ostream& os) const
{
	os << text << std::endl;
}