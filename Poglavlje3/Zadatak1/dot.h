#pragma once

class Dot {
public:
	Dot(double x_ = 0, double y_ = 0);
	double getX();
	double getY();
	void setX(double);
	void setY(double);
	void print();
	double distance(Dot);
	void read();
private:
	double x, y;
};
