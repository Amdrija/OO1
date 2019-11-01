#pragma once
#include <stdlib.h>
#include <iostream>
struct Element {
	int number;
	Element* next;
};

class Queue {
public:
	Queue();
	Queue(Queue& q);
	Queue(Queue&& q)noexcept;
	~Queue();
	int shift();
	void push(int number);
	bool isEmpty() const;
	void print() const;
	void read();
	void empty();

private:
	int length;
	Element* first, * last;
};
