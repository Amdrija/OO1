#include "Vozilo.h"

Vozilo::Vozilo(const std::string& name, const Datum& manufactured, int price)
	:model_name(name), manufacturing_date(manufactured), nominal_price_per_day(price){
	if (price < 0)
		throw NominalVehiclePriceNegativeException();
}

std::ostream& operator<<(std::ostream& os, const Vozilo& v)
{
	os << v.model_name << " - " << v.getNumberOfPassengers() << " - " << v.manufacturing_date;
	v.write(os);
	return os;
}

void Vozilo::write(std::ostream& os) const
{
}

const std::string& Vozilo::getModelName() const
{
	return model_name;
}

const Datum& Vozilo::getManufacturingDate() const
{
	return manufacturing_date;
}
