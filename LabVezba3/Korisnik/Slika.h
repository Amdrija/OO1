#ifndef SLIKA_H
#define SLIKA_H
#include "Exceptions.h"
#include <string>
#include "Multimedija.h"
class Slika : public Multimedija
{
public:
	Slika(const std::string& name_, unsigned int height_, unsigned int width_, unsigned int pixel_size_);
	//Dovoljno je koristiti podrazumevane konstrutkore i desktrutkore
	Slika(const Slika&) = default;
	Slika(Slika&&) = default;
	Slika& operator=(const Slika&) = default;
	Slika& operator=(Slika&&) = default;
	~Slika() = default;
	unsigned int getSize() const;
	std::string getDescription() const override;
	Slika* copy() const override;
private:
	unsigned int width, height;
	unsigned int pixel_size;
};
#endif

