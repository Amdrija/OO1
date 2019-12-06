#include "Zbirka.h"
#include <ctime>
#include <cstdlib>
#include "Carobnjak.h"

Zbirka::Zbirka(){}

Zbirka::Zbirka(const Zbirka& z)
{
	copy(z);
}

Zbirka::Zbirka(Zbirka&& z)
{
	move(z);
}

Zbirka& Zbirka::operator=(const Zbirka& z)
{
	if (this != &z) {
		delete_list();
		copy(z);
	}

	return *this;
}

Zbirka& Zbirka::operator=(Zbirka&& z)
{
	if (this != &z) {
		delete_list();
		move(z);
	}

	return *this;
}

Zbirka::~Zbirka()
{
	delete_list();
}

unsigned int Zbirka::getSize() const
{
	return size;
}

Zbirka& Zbirka::addCard(Karta* card)
{
	if (card != nullptr) {
		Zbirka::Node* new_node = new Node(card, first);
		first = new_node;
		size++;
	}
	return *this;
}

const Karta* Zbirka::getFighterWithMinPower() const
{
	if (first == nullptr)
		return nullptr;
	const Karta* fighter_with_min_power = this->first->card;
	Node* current = first->next;
	while (current != nullptr) {
		if (current->card->getPower() < fighter_with_min_power->getPower()) {
			fighter_with_min_power = current->card;
		}
		current = current->next;
	}
	return fighter_with_min_power;
}

Karta* Zbirka::operator[](int index)
{
	if (index < 0 || index >= size)
		return nullptr;

	Zbirka::Node* temp = first;
	while (index > 0) {
		temp = temp->next;
		index--;
	}
	return temp->card;
}

Karta* Zbirka::operator[](unsigned int ID)
{
	Zbirka::Node* temp = first;
	while (temp != nullptr) {
		if (temp->card->getID() == ID) {
			return temp->card;
		}
		temp = temp->next;
	}
	return nullptr;
}

//ova 2 postoje samo da bi mogla da se pozovu za konst objekat
const Karta* Zbirka::operator[](int index) const
{
	if (index < 0 || index >= size)
		return nullptr;

	Zbirka::Node* temp = first;
	while (index > 0) {
		temp = temp->next;
		index--;
	}
	return temp->card;
}

const Karta* Zbirka::operator[](unsigned int ID) const
{
	Zbirka::Node* temp = first;
	while (temp != nullptr) {
		if (temp->card->getID() == ID) {
			return temp->card;
		}
		temp = temp->next;
	}
	return nullptr;
}

void Zbirka::operator()(int index)
{
	if (index < 0 || index >= size)
		return;

	Zbirka::Node *current = first, *last = nullptr;
	while (index > 0) {
		last = current;
		current = current->next;
		index--;
	}

	//ako je index 0, onda treba prvi element da izbacimo
	//pa ce last u tom slucaju biti nullptr
	if (last == nullptr) {
		first = current->next;
	}
	else {
		last->next = current->next;
	}

	size--;
	//trebda da obrisemo i kartu i trenutni element
	//jer je karta dinamicki alocirana
	delete current->card;
	delete current;
}

void Zbirka::operator()(unsigned int ID)
{
	Zbirka::Node* current = first, * last = nullptr;
	while (current != nullptr && current->card->getID() != ID) {
		last = current;
		current = current->next;
	}

	//to znaci da u listi ne postoji karta sa tim ID
	//jer smo prosli kroz celu listu i nismo nasli ID
	//pa je current postao nullptr
	if (current == nullptr)
		return;

	//ako treba prvi element da izbacimo
	//pa ce last u tom slucaju biti nullptr
	if (last == nullptr) {
		first = current->next;
	}
	else {
		last->next = current->next;
	}

	size--;

	//trebda da obrisemo i kartu i trenutni element
	//jer je karta dinamicki alocirana
	delete current->card;
	delete current;
}

void Zbirka::operator~()
{
	srand(time(NULL));
	(*this)((int)(rand() % size));
}

void Zbirka::copy(const Zbirka& z)
{
	size = 0;
	first = nullptr;
	for (int i = z.size - 1; i >= 0; i--) {
		this->addCard(clone_card(z[i]));
	}
}

void Zbirka::move( Zbirka& z)
{
	size = z.size;
	first = z.first;
	z.first = nullptr;
}

void Zbirka::delete_list()
{
	while (first != nullptr) {
		Node* temp = first;
		first = first->next;
		delete temp->card; //Ne moze karta da postoji bez zbirke
		delete temp;
	}
	first = nullptr;
	size = 0;
}

Karta* Zbirka::clone_card(const Karta* card, bool clone_id)
{
	Karta* clone = nullptr;
	if (typeid(*card) == typeid(Carobnjak)) {
		clone = new Carobnjak(card->getCardName(), card->getMana(), card->getPower());
		//Ova linija postoji samo da bismo omogucili da kada se karta premesta
		//iz 1 zbirke u drugu, da moze da se kopira i njen ID, umesto da se 
		//pravi novi
		if (clone_id)
			clone->id = card->getID();
	}

	return clone;
}

bool Zbirka::transfer_card(Zbirka* destination, const Karta* card)
{
	if (this->getSize() <= 0)
		return false;

	if ((*this)[(unsigned)card->getID()] == nullptr)
		return false;

	destination->addCard(this->clone_card(card, true));
	(*this)((unsigned)card->getID()); //izbacuje prvu kartu iz spila

	return true;
}


std::ostream& operator<<(std::ostream& os, const Zbirka& z)
{
	Zbirka::Node* temp = z.first;
	while (temp != nullptr) {
		os << *temp->card << std::endl;
		temp = temp->next;
	}
	return os;
}
