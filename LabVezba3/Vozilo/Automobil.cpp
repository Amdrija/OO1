#include "Automobil.h"

Automobil::Automobil(const std::string& name, const Datum& manufactured, int car_price, Type type_, int driver_price)
	:Vozilo(name, manufactured, car_price), type(type_), driver_price_per_day(driver_price){
	if (driver_price < 0)
		throw DriverPriceNegativeException();
}

unsigned int Automobil::getNumberOfPassengers() const
{
	return type == Automobil::KUPE ? 2 : 5;
}

double Automobil::getPricePerDay(const Datum& start_date, bool driver) const
{
	if (start_date < manufacturing_date)
		throw VehicleRentStartDateException();

	Datum two_years_after_manufacture(manufacturing_date["day"], manufacturing_date["month"], manufacturing_date["year"] + 2);


	if (manufacturing_date["day"] == 29 && manufacturing_date["month"] == 2) {
		two_years_after_manufacture = Datum(1, 3, manufacturing_date["year"] + 2);
	}
	
	//prijavljuje neki overflow warning, ali nemam ideju kako to da ispravim, ne bi trebalo da pravi problem svakako
	return nominal_price_per_day * (1 + 0.15 * (start_date <= two_years_after_manufacture)) + driver_price_per_day * driver;
}

std::string Automobil::getType() const
{
	return type == Automobil::KUPE ? "Kupe" : "Limuzina";
}

Automobil* Automobil::copy() const
{
	return new Automobil(
		this->model_name, 
		this->manufacturing_date, 
		this->nominal_price_per_day, 
		this->type, 
		this->driver_price_per_day);
}

void Automobil::write(std::ostream& os) const
{
	os << " - " << getType();
}
