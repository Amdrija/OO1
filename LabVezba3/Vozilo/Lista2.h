#ifndef LISTA2_H
#define LISTA2_H
#include "Exceptions.h"
template <typename T>
class Lista2 {
public:
	Lista2() {}
	Lista2(const Lista2&) = delete;
	Lista2(Lista2&&) = delete;
	Lista2& operator=(const Lista2&) = delete;
	Lista2& operator=(Lista2&&) = delete;
	~Lista2();
	Lista2& operator+=(const T& new_data);
	int getLength() const;
	void setOnFirst() const;
	const Lista2& operator++() const;
	const Lista2& next()const;
	bool currentIsNull() const;
	T& getCurrentData();
	void removeCurrent();
	friend std::ostream& operator<<(std::ostream& os, const Lista2& list) {
		Node* temp = list.first;
		while (temp != nullptr) {
			os << temp->data << std::endl;
			temp = temp->next;
		}
		return os;
	}

private:
	struct Node {
		T data;
		Node* next, * prev;
		Node(const T& data_, Node* next_, Node* prev_) :data(data_), next(next_), prev(prev_) {}
	};
	Node* first = nullptr, * last = nullptr;
	mutable Node* current = nullptr;
	int length = 0;
};

template <typename T>
Lista2<T>::~Lista2<T>() {
	while (first != nullptr) {
		Node* temp = first;
		first = first->next;
		delete temp;
	}
	length = 0;
	first = last = current = nullptr;
}

template <typename T>
Lista2<T>& Lista2<T>::operator+=(const T& new_data) {
	Node* new_node = new Node(new_data, nullptr, last);
	if (last == nullptr) {
		first = new_node;
	}
	else {
		last->next = new_node;
	}
	last = new_node;

	length++;
	return *this;
}

template <typename T>
int Lista2<T>::getLength() const {
	return length;
}

template <typename T>
void Lista2<T>::setOnFirst() const {
	current = first;
}

template <typename T>
const Lista2<T>& Lista2<T>::operator++() const {
	if (currentIsNull())
		throw CurrentElementMissingException();

	current = current->next;
}

template <typename T>
const Lista2<T>& Lista2<T>::next()const {
	return ++(*this);
}

template <typename T>
bool Lista2<T>::currentIsNull() const {
	return current == nullptr;
}

template <typename T>
T& Lista2<T>::getCurrentData() {
	if (currentIsNull())
		throw CurrentElementMissingException();

	return current->data;
}

template <typename T>
void Lista2<T>::removeCurrent() {
	if (currentIsNull())
		throw CurrentElementMissingException();

	if (first == current) {
		first = current->next;
	}

	if (last == current) {
		last = current->prev;
	}

	if (current->next != nullptr) {
		current->next->prev = current->prev;
	}

	if (current->prev != nullptr) {
		current->prev->next = current->next;
	}

	delete current;
	current = nullptr;
	length--;
}


#endif

