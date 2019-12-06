#include "Obavestenje.h"
#include "Korisnik.h"
int Obavestenje::setID = 0;

Obavestenje::Obavestenje(Korisnik* user_)
	: user(user_){}


Obavestenje::Obavestenje(const Obavestenje& o)
{
	copy(o);
}


Obavestenje::Obavestenje(Obavestenje&& o)
{
	move(o);
}


Obavestenje& Obavestenje::operator=(const Obavestenje& o)
{
	if (this != &o) {
		copy(o);
	}
	return *this;
}

Obavestenje& Obavestenje::operator=(Obavestenje&& o)
{
	if (this != &o) {
		move(o);
	}
	return *this;
}

int Obavestenje::getID() const
{
	return id;
}

Korisnik* Obavestenje::getUser() const
{
	return user;
}

bool Obavestenje::isRead() const
{
	return read;
}

bool Obavestenje::readNotification()
{
	return read = true;
}

//Kod kopiranja ne zelimo da kopiramo ID i
// vreme kada je nastalo obavestenje
void Obavestenje::copy(const Obavestenje& o)
{
	read = o.read;
	user = o.user;
}

//Kod premestanja zelimo da kopiramo i ID i
//vreme kada je nastalo obavestenje, jer taj objekat nestaje
void Obavestenje::move(Obavestenje& o)
{
	id = o.id;
	creation_time = o.creation_time;
	read = o.read;
	user = o.user;
	o.user = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Obavestenje& o)
{
	//_CRT_NO_WARNINGS
	//Inace mora da se koristi localtime_s
	struct tm* ptm = localtime(&o.creation_time);
	std::string user_name = o.user == nullptr ? "USER_MISSING" : o.user->getUserName();

	os << o.id << " | " << user_name<<" - " << ptm->tm_hour
		<< ":" << ptm->tm_min<< ":" << ptm->tm_sec << std::endl;
	o.write(os);
	return os;
}
