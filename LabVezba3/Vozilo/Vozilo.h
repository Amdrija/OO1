#ifndef VOZILO_H
#define VOZILO_H

#include "Datum.h"
#include "Exceptions.h"
#include <iostream>
#include <string>

class Vozilo
{
public:
	Vozilo(const std::string& name, const Datum& manufactured, int price);
	Vozilo(const Vozilo&) = delete;
	Vozilo(Vozilo&&) = delete;
	Vozilo& operator=(const Vozilo&) = delete;
	Vozilo& operator=(Vozilo&&) = delete;
	//mozemo koristiti default destruktor, jer nemamo
	//dinamicki alociranih podataka
	~Vozilo() = default;
	const std::string& getModelName() const;
	const Datum& getManufacturingDate() const;
	virtual unsigned int getNumberOfPassengers() const = 0;
	virtual double getPricePerDay(const Datum& start_date, bool driver) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Vozilo& v);
	virtual Vozilo* copy() const = 0;
protected:
	std::string model_name;
	Datum manufacturing_date;
	int nominal_price_per_day; //Podrazumevana cena, nezavisno od datuma i potrebe za vozacem
	virtual void write(std::ostream& os) const;
};
#endif

