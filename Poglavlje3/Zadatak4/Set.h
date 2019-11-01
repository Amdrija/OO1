#pragma once
#include <iostream>

class Set {
	int size;
	double* elements;

public:
	Set();
	Set(double element);
	Set(Set& s);
	Set(Set&& s);
	~Set();
	Set _union(const Set &s) const;
	Set _intersection(const Set& s) const;
	Set _difference(const Set& s) const;
	void read();
	void print() const;
	int getSize();
	Set& add(double element);
};
