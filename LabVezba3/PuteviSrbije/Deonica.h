#ifndef DEONICA_H
#define DEONICA_H

#include <iostream>
#include <string>
#include "Exceptions.h"
#include "Mesto.h"

class Deonica
{
public:
	enum Category{MAGISTRALA, AUTOPUT};
	enum VehicleCategory{LAKO, TESKO};
	Deonica(Mesto* start_, Mesto* end_, Category category_);
	//koristimo ugradjene kopirajuce i premestajuce konstruktore
	//i operatore dodele i destruktor
	//odgovara da kada kopiramo ne radimo duboku kopiju
	//nego plitku, jer vise deonica moze da sadrzi isto mesto
	//takodje, odgovara nam da kada brisemo deonicu ne obrisemo
	// i mesto koje je sadrzano u deonici
	Deonica(const Deonica&) = default;
	Deonica(Deonica&&) = default;
	Deonica& operator=(const Deonica&) = default;
	Deonica& operator=(Deonica&&) = default;
	~Deonica() = default;
	const Mesto& getStart()const;
	const Mesto& getEnd()const;
	double operator~()const;
	double tollPrice(VehicleCategory vehicle_category)const;
	double operator()(VehicleCategory vehicle_category)const;
	std::string getCategory() const;
	friend std::ostream& operator<<(std::ostream& os, const Deonica& d);
private:
	//koristimo pokazivace na mesta, jer su mesta jedinstvena
	//i jedno mesto moze biti deo vise deonica
	Mesto* start;
	Mesto* end;
	Category category;
	static const int heavy_category_price = 22;
	static const int light_category_price = 12;
};
#endif

