#ifndef LISTA4_H
#define LISTA4_H
#include "Exceptions.h"

template <typename T>
class Lista4 {
public:
	Lista4() {}
	Lista4(const Lista4& list);
	Lista4(Lista4&& list);
	Lista4& operator=(const Lista4& list);
	Lista4& operator=(Lista4&& list);
	~Lista4();
	Lista4& operator+=(const T& new_data);
	int getLength() const;
	void setOnFirst() const;
	const Lista4& operator++() const;
	const Lista4& next()const;
	bool currentIsNull() const;
	T& getCurrentData() const;
	void removeCurrent();
	friend std::ostream& operator<<(std::ostream& os, const Lista4& list) {
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
	void delete_list();
	void copy(const Lista4& list);
	void move(Lista4& list);
};

template <typename T>
Lista4<T>::Lista4<T>(const Lista4<T>& list) {
	copy(list);
}

template <typename T>
Lista4<T>::Lista4<T>(Lista4<T>&& list) {
	move(list);
}

template <typename T>
Lista4<T>& Lista4<T>::operator=(const Lista4<T>& list) {
	if (&list != this) {
		delete_list();
		copy(list);
	}
	return *this;
}

template <typename T>
Lista4<T>& Lista4<T>::operator=(Lista4<T>&& list) {
	if (&list != this) {
		delete_list();
		move(list);
	}
	return *this;
}

template <typename T>
Lista4<T>::~Lista4<T>() {
	delete_list();
}

template <typename T>
Lista4<T>& Lista4<T>::operator+=(const T& new_data) {
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
int Lista4<T>::getLength() const {
	return length;
}

template <typename T>
void Lista4<T>::setOnFirst() const {
	current = first;
}

template <typename T>
const Lista4<T>& Lista4<T>::operator++() const {
	if (currentIsNull())
		throw CurrentElementMissingException();

	current = current->next;
}

template <typename T>
const Lista4<T>& Lista4<T>::next()const {
	return ++(*this);
}

template <typename T>
bool Lista4<T>::currentIsNull() const {
	return current == nullptr;
}

template <typename T>
T& Lista4<T>::getCurrentData() const {
	if (currentIsNull())
		throw CurrentElementMissingException();

	return current->data;
}

template <typename T>
void Lista4<T>::removeCurrent() {
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

template <typename T>
void Lista4<T>::delete_list() {
	while (first != nullptr) {
		Node* temp = first;
		first = first->next;
		delete temp;
	}
	length = 0;
	first = last = current = nullptr;
}

template <typename T>
void Lista4<T>::copy(const Lista4<T>& list) {
	Node* temp = list.first;
	bool set_current = false;
	current = nullptr;
	while (temp != nullptr) {
		(*this) += temp->data;

		if (!set_current) {
			current = last;
		}

		if (temp == list.current) {
			set_current = true;
		}
		temp = temp->next;
	}
	if (set_current == false)
		current = nullptr;
}

template <typename T>
void Lista4<T>::move(Lista4<T>& list) {
	first = list.first;
	last = list.last;
	current = list.current;
	length = list.length;
	list.first = nullptr;
	list.last = nullptr;
}

#endif




