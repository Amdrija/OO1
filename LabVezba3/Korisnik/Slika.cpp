#include "Slika.h"

Slika::Slika(const std::string & name_, unsigned int width_, unsigned int height_, unsigned int pixel_size_)
	:Multimedija(name_), width(width_), height(height_), pixel_size(pixel_size_){}

unsigned int Slika::getSize() const
{
	return pixel_size * width * height;
}

std::string Slika::getDescription() const
{
	return "[" + std::to_string(width) + " x " + std::to_string(height)
		+ " -> " + std::to_string(getSize()) + "B]";
}

Slika* Slika::copy() const
{
	return new Slika(*this);
}
