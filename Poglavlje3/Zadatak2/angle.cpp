#include "Angles.h"
#include <iostream>
#include <math.h>

Angle::Angle(double rad) {
	radians = rad;
}
Angle::Angle(int degrees, int minutes, int seconds) {
	radians = (seconds / 3600.0 + minutes / 60.0 + degrees) / 180 * PI;
}
double Angle::getRadians() {
	return radians;
}

double Angle::getDegrees() {
	return radians * 180 / PI;
}

double Angle::getMinutes() {
	return getDegrees() * 60;
}

double Angle::getSeconds() {
	return getDegrees() * 3600;
}

int Angle::getRoundDegrees() {
	return round(getDegrees());
}

int Angle::getRoundMinutes() {
	return (int)round(getMinutes()) % 60;
}

int Angle::getRoundSeconds() {
	return (int)round(getSeconds()) % 60;
}

void Angle::getAllDegrees(int& degrees, int& minutes, int& seconds) {
	degrees = getRoundDegrees();
	minutes = getRoundMinutes();
	seconds = getRoundSeconds();
}

Angle& Angle::add(Angle a) {
	radians += a.radians;
	return *this;
}
Angle& Angle::multiply(double a){
	radians *= a;
	return *this;
}
void Angle::printRadians() {
	std::cout << radians << std::endl;
}
void  Angle::printDegrees() {
	int deg, min, sec;
	getAllDegrees(deg, min, sec);
	std::cout << deg << " " << min << "' " << sec << "'' " << std::endl;
}
void Angle::readAngle() {
	std::cout << "Type the angle in radians." << std::endl;
	std::cin >> radians;
}
