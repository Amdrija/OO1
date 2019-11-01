#include "Set.h"

Set::Set()
{
	size = 0;
	elements = nullptr;
}

Set::Set(double element)
{
	size = 1;
	elements = new double[1];
	elements[0] = element;
}

Set::Set(Set& s)
{
	size = s.size;
	elements = new double[s.size];
	for (int i = 0; i < s.size; i++) {
		elements[i] = s.elements[i];
	}
}

Set::Set(Set&& s)
{
	size = s.size;
	elements = s.elements;
	s.elements = nullptr;
}

Set::~Set()
{
	delete[] elements;
	size = 0;
	elements = nullptr;
}

Set Set::_union(const Set& s) const
{
	Set u;
	int i = 0, j = 0;

	while (i < size){
		u.add(elements[i++]);
	}

	while (j < s.size) {
		u.add(s.elements[j++]);
	}

	return u;
}

Set Set::_intersection(const Set& s) const
{
	Set u;
	int i = 0, j = 0;

	while (i < size && j < s.size) {
		if (elements[i] == s.elements[j]) {
			u.add(elements[i]);
			i++;
			j++;
		}
		else if (elements[i] < s.elements[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	return u;
}

Set Set::_difference(const Set& s) const
{
	Set u;
	int i = 0, j = 0;
	while (i < size && j < s.size) {
		if (elements[i] == s.elements[j]) {
			i++;
			j++;
		} else if (elements[i] < s.elements[j]) {
			u.add(elements[i]);
			i++;
		}
		else {
			j++;
		}
		
	}
	while (i < size) {
		u.add(elements[i++]);
	}
	return u;
}

void Set::read()
{
	std::cout << "Type in the number of elements you want to add." << std::endl;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		double element;
		std::cout << "Type in the element you want to add." << std::endl;
		std::cin >> element;
		add(element);
	}
}

void Set::print() const
{
	std::cout << "{ ";
	for (int i = 0; i < size; i++) {
		std::cout << elements[i];
		if (i < size - 1) {
			std::cout << ", ";
		}
	}
	std::cout <<" }"<< std::endl;
}

Set& Set::add(double element)
{
	double* new_elements = new double[size + 1];
	int i = 0;
	while (i < size && elements[i] < element) {
		new_elements[i] = elements[i];
		i++;
	}

	if (i < size && elements[i] <= element) {
		delete new_elements;
		return *this;
	}
	new_elements[i] = element;
	while (i < size) {
		new_elements[i + 1] = elements[i];
		i++;
	}
	delete elements;
	elements = new_elements;
	size++;
	return *this;
}
