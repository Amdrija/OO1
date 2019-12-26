#ifndef DATUM_H
#define DATUM_H

#include <string>
#include "Exceptions.h"
class Datum
{
public:
	Datum(unsigned int day_ = 28, unsigned int month_ = 12, int year_ = 2019);
	//mozemo koristiti default kopirajuce i prem konstruktore i op dodele i destrutkor
	Datum(const Datum&) = default;
	Datum(Datum&&) = default;
	Datum& operator=(const Datum&) = default;
	Datum& operator=(Datum&&) = default;
	~Datum() = default;
	friend bool operator<(const Datum& d1, const Datum& d2);
	friend bool operator>(const Datum& d1, const Datum& d2);
	friend bool operator==(const Datum& d1, const Datum& d2);
	friend bool operator!=(const Datum& d1, const Datum& d2);
	friend bool operator>=(const Datum& d1, const Datum& d2);
	friend bool operator<=(const Datum& d1, const Datum& d2);
	friend int operator-(const Datum& d1, const Datum& d2);
	int operator[](const std::string&)const;
	friend std::ostream& operator<<(std::ostream&, const Datum& d1);
	int toJDN() const;
	static bool isLeapYear(int year);
	static bool isDayValid(unsigned int day, unsigned int month, int year);
	static bool isMonthValid(unsigned int month);
	static bool isDateValid(unsigned int day_, unsigned int month_, int year_);
private:
	unsigned int month, day;
	static const short days_in_month[12]; 
	int year; // negativne godine su pre nove ere
};

#endif

