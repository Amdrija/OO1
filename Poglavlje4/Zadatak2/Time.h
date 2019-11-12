#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
public:
	Time(int hours, int minutes, int seconds);
	Time(int seconds);
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	int getTotalSeconds() const;
	friend Time operator+(const Time& t1, const Time& t2);
	friend Time operator-(const Time& t1, const Time& t2);
	Time& operator+=(const Time& t);
	Time& operator-=(const Time& t);
	Time& operator++();
	Time& operator--();
	Time operator++(int);
	Time operator--(int);
	friend Time operator*(const Time& t, int n);
	friend Time operator/(const Time& t, int n);
	friend bool operator<(const Time& t1, const Time& t2);
	friend bool operator>(const Time& t1, const Time& t2);
	friend bool operator<=(const Time& t1, const Time& t2);
	friend bool operator>=(const Time& t1, const Time& t2);
	friend bool operator==(const Time& t1, const Time& t2);
	friend bool operator!=(const Time& t1,const Time& t2);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
	friend std::istream& operator>>(std::istream& is, Time& t);
	operator int() const;
private:
	int _hours, _minutes, _seconds;
};

#endif

