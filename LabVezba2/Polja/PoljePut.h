#ifndef POLJEPUT_H
#define POLJEPUT_H

#include <iostream>
#include "Polje.h"
class PoljePut :public Polje{
public:
	enum Category { ZEMLJANI, KAMENI };
	PoljePut(Category category_, int neprohodnost_ = 100);
	//Dovoljno je koristiti default konstruktore i destruktore
	Category getCategory()const;
	PoljePut* copy() const override;
protected:
	Category category;
	char getTag() const override;
private:
};
#endif