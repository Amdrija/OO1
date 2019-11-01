#pragma once

const double PI = 3.14159265358979323846;

// class for angle manipulation
class Angle {
public:
	Angle(double rad = 0);
	Angle(int degrees, int minutes, int seconds);
	double getRadians();
	double getDegrees();
	double getMinutes();
	double getSeconds();
	int getRoundDegrees();
	int getRoundMinutes();
	int getRoundSeconds();
	void getAllDegrees(int &degrees, int &minutes, int &seconds);
	Angle &add(Angle a);
	Angle& multiply(double a);
	void printRadians();
	void printDegrees();
	void readAngle();
private:
	double radians;
};