#ifndef COMPLEX_H
#define COMPLEX_H

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
class Complex
{
public:
	explicit Complex(double real = 0, double imaginary = 0);
	double getReal() const;
	double getImaginary() const;
	double modulus() const;
	double argument() const;
	Complex operator~() const;
	friend Complex operator+(const Complex& z, const Complex& w);
	friend Complex operator-	(const Complex& z, const Complex& w);
	friend Complex operator*(const Complex& z, const Complex& w);
	friend Complex operator/(const Complex& z, const Complex& w);
	friend std::ostream& operator<<(std::ostream& os, const Complex& z);
	friend std::istream& operator>>(std::istream& is, Complex& z);
	Complex& operator+=(const Complex& z);
	Complex& operator-=(const Complex& z);
	Complex& operator*=(const Complex& z);
	Complex& operator/=(const Complex& z);
	friend bool operator==(const Complex& z, const Complex& w);
	friend bool operator!=(const Complex& z, const Complex& w);
	operator double() const;
private:
	double _real, _imaginary;
};

#endif

