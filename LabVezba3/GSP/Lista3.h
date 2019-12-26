#ifndef LISTA3_H
#define LISTA3_H
#include "Exceptions.h"

template <typename T>
class Lista3 {
public:
	Lista3() {}
	Lista3(const Lista3& list);
	Lista3(Lista3&& list);
	Lista3& operator=(const Lista3& list);
	Lista3& operator=(Lista3&& list);
	~Lista3();
	Lista3& operator+=(const T& new_data);
	int getLength() const;
	void setOnFirst() const;
	const Lista3& operator++() const;
	const Lista3& next()const;
	bool currentIsNull() const;
	T& getCurrentData() const;
	void removeCurrent();
	bool isCurrentLast() const;
	friend std::ostream& operator<<(std::ostream& os, const Lista3& list) {
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
	void copy(const Lista3& list);
	void move(Lista3& list);
};

template <typename T>
Lista3<T>::Lista3<T>(const Lista3<T>& list) {
	copy(list);
}

template <typename T>
Lista3<T>::Lista3<T>(Lista3<T>&& list) {
	move(list);
}

template <typename T>
Lista3<T>& Lista3<T>::operator=(const Lista3<T>& list) {
	if (&list != this) {
		delete_list();
		copy(list);
	}
	return *this;
}

template <typename T>
Lista3<T>& Lista3<T>::operator=(Lista3<T>&& list) {
	if (&list != this) {
		delete_list();
		move(list);
	}
	return *this;
}

template <typename T>
Lista3<T>::~Lista3<T>() {
	delete_list();
}

template <typename T>
Lista3<T>& Lista3<T>::operator+=(const T& new_data) {
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
int Lista3<T>::getLength() const {
	return length;
}

template <typename T>
void Lista3<T>::setOnFirst() const {
	current = first;
}

template <typename T>
const Lista3<T>& Lista3<T>::operator++() const {
	if (currentIsNull())
		throw CurrentElementMissingException();

	current = current->next;
}

template <typename T>
const Lista3<T>& Lista3<T>::next()const {
	return ++(*this);
}

template <typename T>
bool Lista3<T>::currentIsNull() const {
	return current == nullptr;
}

template <typename T>
T& Lista3<T>::getCurrentData() const{
	if (currentIsNull())
		throw CurrentElementMissingException();

	return current->data;
}

template <typename T>
void Lista3<T>::removeCurrent() {
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

template<typename T>
inline bool Lista3<T>::isCurrentLast() const
{
	return current == last;
}

template <typename T>
void Lista3<T>::delete_list() {
	while (first != nullptr) {
		Node* temp = first;
		first = first->next;
		delete temp;
	}
	length = 0;
	first = last = current = nullptr;
}

template <typename T>
void Lista3<T>::copy(const Lista3<T>& list) {
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
void Lista3<T>::move(Lista3<T>& list) {
	first = list.first;
	last = list.last;
	current = list.current;
	length = list.length;
	list.first = nullptr;
	list.last = nullptr;
}

#endif



