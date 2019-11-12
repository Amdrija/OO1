#include "Complex.h"
#include "Complex.h"

Complex::Complex(double real, double imaginary)
{
	_real = real;
	_imaginary = imaginary;
}

double Complex::getReal() const
{
	return _real;
}

double Complex::getImaginary() const
{
	return _imaginary;
}

double Complex::modulus() const
{
	return sqrt(_real * _real + _imaginary * _imaginary);
}

double Complex::argument() const
{
	double arctg = atan(_imaginary / _real);

	if (_real < 0 && _imaginary < 0)
		return arctg - M_PI;
	
	return arctg + M_PI * (_real < 0 && _imaginary < 0);
}

Complex Complex::operator~() const
{
	return Complex(_real, - _imaginary);
}

Complex& Complex::operator+=(const Complex& z)
{
	return *this = *this + z;
}

Complex& Complex::operator-=(const Complex& z)
{
	return *this = *this - z;
}

Complex& Complex::operator*=(const Complex& z)
{
	return *this = *this * z;
}

Complex& Complex::operator/=(const Complex& z)
{
	return *this = *this / z;
}

Complex::operator double() const
{
	return modulus();
}

Complex operator+(const Complex& z, const Complex& w)
{
	return Complex(z._real + w._real, z._imaginary + w._imaginary);
}

Complex operator-(const Complex& z, const Complex& w)
{
	return Complex(z._real - w._real, z._imaginary - w._imaginary);
}

Complex operator*(const Complex& z, const Complex& w)
{
	return Complex(z._real * w._real - z._imaginary * w._imaginary, z._real * w._imaginary + z._imaginary * w._real);
}

Complex operator/(const Complex& z, const Complex& w)
{
	double modulus_w = w.modulus();
	Complex numerator = z * ~w;
	return Complex(numerator.getReal() / modulus_w / modulus_w, numerator.getImaginary() / modulus_w / modulus_w);
}

std::ostream& operator<<(std::ostream& os, const Complex& z)
{
	os << "( " << z._real << " , " << z._imaginary << " )";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& z)
{
	is >> z._real >> z._imaginary;
	return is;
}

bool operator==(const Complex& z, const Complex& w)
{
	return z._real == w._real && z._imaginary == w._imaginary;
}

bool operator!=(const Complex& z, const Complex& w)
{
	return !(z == w);
}
