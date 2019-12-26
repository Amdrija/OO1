#include "Datum.h"

const short Datum::days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Datum::Datum(unsigned int day_, unsigned int month_, int year_) {
	if (isDateValid(day_, month_, year_)) {
		day = day_;
		month = month_;
		year = year_;
	}
	else {
		throw InvalidDateException();
	}
}

int Datum::operator[](const std::string& s)const
{
	//treba obratiti paznju da nisam proveravao ako neko ukuca DaY
	if (s == "day")
		return day;
	if (s == "month")
		return month;
	if (s == "year")
		return year;

	throw InvalidDateStringPickerException();
	return 0;
}

bool Datum::isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year != 0;
}

int Datum::toJDN() const
{
	return (1461 *(year + 4800 + (month - 14) / 12)) / 4 + (367 *(month - 2 -12 *((month - 14) / 12))) / 12 -(3 *((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;
}

bool Datum::isDayValid(unsigned int day,unsigned int month, int year)
{
	return day > 0 && (day <= (days_in_month[month - 1] + (month == 2 && isLeapYear(year))));
}

bool Datum::isMonthValid(unsigned int month)
{
	return month <= 12 && month > 0;
}

bool Datum::isDateValid(unsigned int day_, unsigned int month_, int year_)
{
	return isDayValid(day_,month_,year_) && isMonthValid(month_);
}

bool operator<(const Datum& d1, const Datum& d2)
{
	return d1.toJDN() < d2.toJDN();
}

bool operator>(const Datum& d1, const Datum& d2)
{
	return d2 < d1;
}

bool operator==(const Datum& d1, const Datum& d2)
{
	return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year;
}

bool operator!=(const Datum& d1, const Datum& d2)
{
	return !(d1 == d2);
}

bool operator>=(const Datum& d1, const Datum& d2)
{
	return d1 > d2 || d1 == d2;
}

bool operator<=(const Datum& d1, const Datum& d2)
{
	return d1 < d2 || d1 == d2;
}

int operator-(const Datum& d1, const Datum& d2)
{
	if (d1 < d2)
		throw NegativeDayDateDifferenceException();
	return d1.toJDN() - d2.toJDN();
}

std::ostream& operator<<(std::ostream& os, const Datum& d)
{
	os << d.day << "." << d.month << "." << d.year <<".";
	return os;
}
