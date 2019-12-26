#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include "Vozilo.h"
#include "Exceptions.h"
#include <iostream>
#include <string>

class Automobil : public Vozilo
{
public:
	enum Type { KUPE, LIMUIZINA };
	//TODO: Exception ako je cena vozaca negativna
	Automobil(const std::string& name, const Datum& manufactured, int car_price, Type type_, int driver_price);
	Automobil(const Automobil&) = delete;
	Automobil(Automobil&&) = delete;
	Automobil& operator=(const Automobil&) = delete;
	Automobil& operator=(Automobil&&) = delete;
	//mozemo koristiti default destruktor
	~Automobil() = default;
	unsigned int getNumberOfPassengers() const override;
	double getPricePerDay(const Datum& start_date, bool driver) const override;
	std::string getType() const;
	//polimorfna kopija automobila
	Automobil* copy() const override;
private:
	Type type;
	int driver_price_per_day;
	virtual void write(std::ostream& os) const override;
};
#endif

