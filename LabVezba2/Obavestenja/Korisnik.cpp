#include "Korisnik.h"

Korisnik::Korisnik(const std::string& s): username(s){}


std::string Korisnik::getUserName() const
{
	return username;
}

void Korisnik::send(Obavestenje* notification, Korisnik* receiver) const
{
	receiver->receive(notification);
}

void Korisnik::receive(Obavestenje* notification)
{
	notifications += notification;
	notification->user = this;
}

ListaObavestenja& Korisnik::getNotifications()
{
	return notifications;
}

std::ostream& operator<<(std::ostream& os, const Korisnik& user)
{
	os << user.username << std::endl << user.notifications;
	return os;
}
