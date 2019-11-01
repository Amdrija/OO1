#include "Queue.h"

Queue::Queue()
{
	first = last = nullptr;
	length = 0;
}

Queue::Queue(Queue& q)
{
	Element* t = q.first;
	first = last = nullptr;
	while (t) {
		push(t->number);
		t = t->next;
	}

	length = q.length;
}

Queue::Queue(Queue&& q)noexcept
{
	length = q.length;
	first = q.first;
	last = q.last;
	q.first = nullptr;
	q.last = nullptr;
}

Queue::~Queue()
{
	empty();
}

int Queue::shift()
{
	if (isEmpty()) {
		exit(1);
	}
	Element* t = first;
	first = first -> next;
	
	int number = t->number;
	if (first == nullptr) {
		last = nullptr;
	}
	length--;

	return number;
}

void Queue::push(int number)
{
	Element* new_element = new Element;
	new_element->next = nullptr;
	new_element->number = number;

	if (isEmpty()) {
		first = new_element;
	}
	else {
		last->next = new_element;
	}
	last = new_element;

	length++;
}

bool Queue::isEmpty() const
{
	return length == 0;
}

void Queue::print() const
{
	Element* t = first;
	while (t) {
		std::cout << t->number;
		if (t->next) std::cout << ", ";

		t = t->next;
	}
	std::cout << std::endl;
}

void Queue::read()
{
	std::cout << "How many elements do you want to add to the list." << std::endl;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		std::cout << "Type in the number you want to add." << std::endl;
		std::cin >> number;
		push(number);
	}
}

void Queue::empty()
{
	while (first) {
		Element* t = first;
		first = first->next;
		delete t;
	}
	last = nullptr;
	length = 0;
}

