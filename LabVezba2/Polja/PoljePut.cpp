#include "PoljePut.h"

PoljePut::PoljePut(Category category_, int neprohodnost_)
	:Polje(neprohodnost_),category(category_){}

PoljePut::Category PoljePut::getCategory() const
{
	return category;
}

PoljePut* PoljePut::copy() const
{
	return new PoljePut(category, neprohodnost);
}

char PoljePut::getTag() const
{
	return category == ZEMLJANI ? 'Z' : 'K';
}
