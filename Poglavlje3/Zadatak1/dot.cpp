#include "dot.h"
#include <math.h>
#include <iostream>
Dot::Dot(double x_ , double y_ ) {
	setX(x_);
	setY(y_);
}

double Dot::getX() {
	return x;
}

double Dot::getY() {
	return y;
}

void Dot::setX(double x_) {
	x = x_;
}

void Dot::setY(double y_) {
	y = y_;
}

void Dot::print() {
	std::cout << "( " << x << " , " << y << " )" << std::endl;
}

double Dot::distance(Dot t) {
	return sqrt((t.x - x) * (t.x - x) + (t.y - y) * (t.y - y));
}

void Dot::read() {
	std::cout << "Type in the coordinates of the dot." << std::endl;
	std::cin >> x >> y;
}