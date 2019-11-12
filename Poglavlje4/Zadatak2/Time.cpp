#include "Time.h"
#include "Time.h"

Time::Time(int hours, int minutes, int seconds)
	:_hours(hours), _minutes(minutes), _seconds(seconds)
{}

Time::Time(int seconds)
{
	_minutes = seconds / 60;
	_seconds = seconds % 60;

	_hours = _minutes / 60;
	_minutes %= 60;
}

int Time::getHours() const
{
	return _hours;
}

int Time::getMinutes() const
{
	return _minutes;
}

int Time::getSeconds() const
{
	return _seconds;
}

int Time::getTotalSeconds() const
{
	return _hours * 3600 + _minutes * 60 + _seconds;
}

Time& Time::operator+=(const Time& t)
{
	return *this = *this + t;
}

Time& Time::operator-=(const Time& t)
{
	return *this = *this - t;
}

Time& Time::operator++()
{
	return *this = *this + Time(0, 0, 1);
}

Time& Time::operator--()
{
	return *this = *this - Time(0, 0, 1);
}

Time Time::operator++(int)
{
	Time t = *this;
	++*this;
	return t;
}

Time Time::operator--(int)
{
	Time t = *this;
	--*this;
	return t;
}

Time::operator int() const
{
	return this->getTotalSeconds();
}

Time operator+(const Time& t1, const Time& t2)
{
	return Time((int)t1 + (int)t2);
}

Time operator-(const Time& t1, const Time& t2)
{
	return Time((int)t1 - (int)t2);
}

Time operator*(const Time& t, int n)
{
	return Time((int)t * n);
}

Time operator/(const Time& t, int n)
{
	return Time((int)t / n);
}

bool operator<(const Time& t1, const Time& t2)
{
	return t1.getTotalSeconds() < t2.getTotalSeconds();
}

bool operator>(const Time& t1, const Time& t2)
{
	return t1.getTotalSeconds() > t2.getTotalSeconds();
}

bool operator<=(const Time& t1, const Time& t2)
{
	return t1.getTotalSeconds() <= t2.getTotalSeconds();
}

bool operator>=(const Time& t1, const Time& t2)
{
	return t1.getTotalSeconds() >= t2.getTotalSeconds();
}

bool operator==(const Time& t1, const Time& t2)
{
	return t1.getTotalSeconds() == t2.getTotalSeconds();
}

bool operator!=(const Time& t1, const Time& t2)
{
	return t1.getTotalSeconds() != t2.getTotalSeconds();
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.getHours() << " : " << t.getMinutes() << " : " << t.getSeconds();
	return os;
}

std::istream& operator>>(std::istream& is, Time& t)
{
	is >> t._hours >> t._minutes >> t._seconds;
	return is;
}
