#ifndef KARTA_H
#define KARTA_H

#include <iostream>
#include <string>
class Igrac;

class Karta
{
public:
	enum Category { CAROLIJA, BORAC};
	Karta(const std::string& name,  int mana_);
	Karta(Karta&) = delete;
	Karta(Karta&&) = delete;
	Karta& operator=(Karta&) = delete;
	Karta& operator=(Karta&&) = delete;
	//Mozemo koristiti default destruktor
	std::string getCardName() const;
	int getMana() const;
	unsigned int getID() const;
	virtual void useCard(Igrac* controller, Igrac* opponent) const = 0; // apstraktna
	virtual Category getCategory() const = 0; // apstraktna
	virtual int getPower() const = 0; // apstraktna, mora da postoji kako bismo mogli preko pokazivaca na kartu da je pozivamo
	friend std::ostream& operator<<(std::ostream& os, const Karta&);
	friend class Zbirka;
protected:
	virtual void write(std::ostream&) const {};
	int id = ++setID;
	std::string card_name;
	int mana;
private:
	static unsigned int setID;
};
#endif

