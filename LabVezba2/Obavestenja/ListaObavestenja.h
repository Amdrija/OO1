#ifndef LISTA_OBAVESTENJA_H
#define LISTA_OBAVESTENJA_H

#include "Obavestenje.h"
#include <iostream>
class ListaObavestenja
{
	struct Node {
		Obavestenje* notification;
		Node* next;
		Node(Obavestenje* notification_, Node* next_ = nullptr)
			: notification(notification_), next(next_) {}
	};
public:
	//kreira se prazna, pa moze default konstruktor da se koristi
	ListaObavestenja() = default;
	ListaObavestenja(const ListaObavestenja&) = delete;
	ListaObavestenja(ListaObavestenja&&) = delete;
	ListaObavestenja& operator= (const ListaObavestenja&) = delete;
	ListaObavestenja& operator=(ListaObavestenja&&) = delete;
	~ListaObavestenja();
	ListaObavestenja& operator+=(Obavestenje*); 
	void operator()() const;
	int operator+() const;
	void operator!();
	void operator~();
	Obavestenje* operator[](int ID);
	//takodje ne moze da postavimo const, jer se moze menjati obavestenje koja vratimo
	//preko pokazivaca
	friend std::ostream& operator<<(std::ostream& os, const ListaObavestenja& list);
private:
	Node* first = nullptr;
};
#endif

