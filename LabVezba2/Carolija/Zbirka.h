#ifndef ZBIRKA_H
#define ZBIRKA_H

#include "Karta.h"
#include <iostream>
class Zbirka
{
public:
	struct Node {
		Karta* card;
		Node* next;
		Node(Karta* card_, Node* next_ = nullptr) 
			: card(card_), next(next_){}
	};

	Zbirka();
	Zbirka(const Zbirka&);
	Zbirka(Zbirka&&);
	Zbirka& operator=(const Zbirka&);
	Zbirka& operator=(Zbirka&&);
	~Zbirka();
	unsigned int getSize() const;
	Zbirka& addCard(Karta*);
	const Karta* getFighterWithMinPower() const;
	//vracamo pokazivac na konstantu kartu kako preko tog pokazivaca
	//ne bismo mogli da menjamo kartu
	Karta* operator[](int index);
	Karta* operator[](unsigned int ID);
	//ova 2 dole su da bi mogli da ih zovemo za cont objekte
	const Karta* operator[](int index) const;
	const Karta* operator[](unsigned int ID) const;
	void operator()(int index);
	void  operator()(unsigned int ID);
	void operator~();
	friend std::ostream& operator<<(std::ostream & os, const Zbirka& z);
	friend Igrac;
	//da bismo mogli da prebacujemo karte iz jedne zbirke u drugu
private:
	void copy(const Zbirka&);
	void move(Zbirka&);
	void delete_list();
	Node* first = nullptr;
	unsigned int size = 0;
	Karta* clone_card(const Karta*, bool clone_id = false);
	bool transfer_card(Zbirka* destination, const Karta* card);
};

#endif

