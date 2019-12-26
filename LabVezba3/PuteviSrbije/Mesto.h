#ifndef MESTO_H
#define MESTO_H
#include "Exceptions.h"
#include<iostream>
#include <string>
#include <cmath>

class Mesto
{
public:
	Mesto(const std::string& name_, double deg_latitude, double deg_longitude);
	//dovoljno je koristiti podrazumevane kopirajuce konstruktore
	//operatore dodele i destrkutor
	Mesto(const Mesto&) = default;
	Mesto(Mesto&&) = default;
	Mesto& operator=(const Mesto&) = default;
	Mesto& operator=(Mesto&&) = default;
	~Mesto() = default;
	const std::string& getName() const;
	double getDegreesLatitude() const;
	double getDegreesLongitude() const;
	double getRadLatitude() const;
	double getRadLongitude() const;
	friend double operator-(const Mesto& m1, const Mesto& m2);
	friend std::ostream& operator<<(std::ostream& os, const Mesto& m);
private:
	std::string name;
	double degrees_latitude, degrees_longitude;
	static const int earth_radius = 6371;
	static double toRadians(double degrees);
	static const double PI;
	bool longitudeValid(double degrees);
	bool latitudeValid(double degrees);
};
#endif

