#ifndef POLJESUMA_H
#define POLJESUMA_H

#include <iostream>
#include "Polje.h"

class PoljeSuma: public Polje{
public:
	PoljeSuma(unsigned int density_, int neprohodnost_ = 100);
	int getDensity() const;
	PoljeSuma* copy() const override;
protected:
	char getTag() const override;
	void write(std::ostream&) const override;
	unsigned int density;
private:
};
#endif

