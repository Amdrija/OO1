#include "ListaObavestenja.h"

ListaObavestenja::~ListaObavestenja()
{
	~(*this);
}

ListaObavestenja& ListaObavestenja::operator+=(Obavestenje* o)
{
	Node* new_node = new Node(o, first);
	first = new_node;
	return *this;
}

void ListaObavestenja::operator()() const
{
	Node* temp = first;
	while (temp != nullptr) {
		if (!temp->notification->isRead()) {
			std::cout << *(temp->notification);
		}
		temp = temp->next;
	}
}

int ListaObavestenja::operator+() const
{
	Node* temp = first;
	int number_unread = 0;
	while (temp != nullptr) {
		number_unread += !temp->notification->isRead();
		temp = temp->next;
	}
	return number_unread;
}

void ListaObavestenja::operator!()
{
	Node* temp = first;
	while (temp != nullptr) {
		if (!temp->notification->isRead()) {
			temp->notification->readNotification();
		}
		temp = temp->next;
	}
}

void ListaObavestenja::operator~()
{
	while (first != nullptr) {
		Node* temp = first;
		first = first->next;
		//Ovde brisemo i obavestenje, jer obavestenje samo po sebi nema smisla
		// bez liste korisnika
		delete temp->notification;
		delete temp;
	}
}

Obavestenje* ListaObavestenja::operator[](int ID)
{
	Node* temp = first;
	while (temp != nullptr) {
		if (temp->notification->getID() == ID && !temp->notification->isRead()) {
			return temp->notification;
		}
		temp = temp->next;
	}
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const ListaObavestenja& list)
{
	ListaObavestenja::Node* temp = list.first;
	while (temp != nullptr) {
		std::cout << *(temp->notification);
		temp = temp->next;
	}
	return os;
}
