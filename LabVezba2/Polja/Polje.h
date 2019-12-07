#ifndef POLJE_H
#define POLJE_H

#include <iostream>

class Polje
{
public:
	Polje(int neprohodnost_ = 100);
	int getNeprohodnost() const;
	//dovoljno je koristit podrazumevane
	//kopirajuce i premestajuce konstruktore i operatore dodele
	// i destruktor, jer nemamo nijednu dinamicku strukturu u polju;
	Polje operator++(int);
	Polje operator--(int);
	Polje& operator+=(unsigned int difference);
	Polje& operator-=(unsigned int difference);
	friend std::ostream& operator<<(std::ostream& os, const Polje& p);
	virtual Polje* copy() const;
protected:
	virtual char getTag() const;
	virtual void write(std::ostream&) const {}
	static const int max_neprohodnost = 1000, min_neprohodnost = 0;
	int neprohodnost = 100;
	void setNeprohodnostInBounds();
private:
};
#endif

