#pragma once
#include <iostream>

class Quad {
	static double maximum_volume, total_volume;
	double a, b, c;
	Quad(double a_, double b_, double c_) {
		a = a_;
		b = b_;
		c = c_;
		total_volume += a * b * c;
	};
public:
	Quad() = delete;
	Quad(const Quad& q) = delete;
	static bool canAddQuad(double a_, double b_, double c_) {
		return a_ > 0 && b_ > 0 && c_ > 0 && (a_ * b_ * c_ + total_volume) <= maximum_volume;
	}

	static bool setMaxVolume(double volume) {
		if (maximum_volume < total_volume) {
			return false;
		}
		maximum_volume = volume;
		return true;
	}

	static double getMaxVolume() {
		return maximum_volume;
	}

	static double getTotalVolume() {
		return total_volume;
	}

	static Quad* create(double a_, double b_, double c_) {
		if (!canAddQuad(a_, b_, c_)) {
			return nullptr;
		}

		return new Quad(a_, b_, c_);
	}

	static Quad* read() {
		double a_, b_, c_;
		do {
			std::cout << "Entere the dimensions of the quad." << std::endl;
			std::cin >> a_ >> b_ >> c_;
		} while (!canAddQuad(a_, b_, c_));
		return new Quad(a_, b_, c_);
	}

	~Quad() {
		total_volume -= volume();
	}

	double getA() {
		return a;
	}

	double getB() {
		return b;
	}

	double getC() {
		return c;
	}

	double volume() const {
		return a * b * c;
	}

	void write() const {
		std::cout << "Quad: " << a << ", " << b << ", " << c << std::endl;
	}
};

double Quad::total_volume = 0;
double Quad::maximum_volume = 0;
