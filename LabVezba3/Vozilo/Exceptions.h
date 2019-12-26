#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <ostream>
class Exception {
	virtual void write(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, const Exception& e);
};

class CurrentElementMissingException : public Exception {
	void write(std::ostream& os) const;
};

class NegativeDayDateDifferenceException : public Exception {
	void write(std::ostream& os) const;
};

class InvalidDateException : public Exception {
	void write(std::ostream& os) const;
};
class InvalidDateStringPickerException : public Exception {
	void write(std::ostream& os) const;
};

class NominalVehiclePriceNegativeException : public Exception {
	void write(std::ostream& os) const;
};

class DriverPriceNegativeException : public Exception {
	void write(std::ostream& os) const;
};

class VehicleRentStartDateException : public Exception {
	void write(std::ostream& os) const;
};
#endif

