#ifndef LISTA_H
#define LISTA_H

#include "Exceptions.h"

template <typename T>
class Lista
{
public:
	Lista() {}
	Lista(const Lista& list);
	Lista(Lista&& list);
	Lista& operator=(const Lista& list);
	Lista& operator=(Lista&& list);
	~Lista();
	int getLength() const;
	Lista& operator+=(const T& new_data);
	const T& operator[](int i) const;
	T& operator[](int i);
	void operator()(int i);
	friend std::ostream& operator<<(std::ostream& os, const Lista& list) {
		Node* current = list.first;
		while (current != nullptr) {
			os << current->data << " ,";
			current = current->next;
		}
		return os;
	}
private:
	struct Node {
		T data;
		Node* next;
		Node(const T& data_, Node* next_ = nullptr):data(data_), next(next_){}
	};
	Node* first = nullptr, * last = nullptr;
	void copy(const Lista& list);
	void move(Lista& list);
	void delete_list();
	int length = 0;
};

template<typename T>
Lista<T>::Lista<T>(const Lista<T>& list) {
	copy(list);
}

template<typename T>
Lista<T>::Lista<T>(Lista<T>&& list) {
	move(list);
}

template<typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& list) {
	if (&list != this) {
		delete_list();
		copy(list);
	}
	return *this;
}

template<typename T>
Lista<T>& Lista<T>::operator=(Lista<T>&& list) {
	if (&list != this) {
		delete_list();
		move(list);
	}
	return *this;
}

template<typename T>
Lista<T>::~Lista<T>() {
	delete_list();
}

template<typename T>
inline int Lista<T>::getLength() const
{
	return length;
}

template<typename T>
inline Lista<T>& Lista<T>::operator+=(const T& new_data)
{
	Node* new_node = new Node(new_data);
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

template<typename T>
inline const T& Lista<T>::operator[](int i) const
{
	if (i < 0)
		throw ElementIndexOutOfBoundsException();

	Node* current = first;
	while (current && i > 0)
	{
		current = current->next;
		i--;
	}
	if (current == nullptr)
		throw ElementIndexOutOfBoundsException();

	return current->data;
}

template<typename T>
inline T& Lista<T>::operator[](int i)
{
	if (i < 0)
		throw ElementIndexOutOfBoundsException();

	Node* current = first;
	while (current && i > 0)
	{
		current = current->next;
		i--;
	}
	if (current == nullptr)
		throw ElementIndexOutOfBoundsException();

	return current->data;
}

template<typename T>
inline void Lista<T>::operator()(int i)
{
	if (i < 0)
		throw ElementIndexOutOfBoundsException();

	Node* current = first, *previous = nullptr;
	while (current && i > 0)
	{
		previous = current;
		current = current->next;
		i--;
	}
	if (current == nullptr)
		throw ElementIndexOutOfBoundsException();

	//ako izbacujemo prvi element
	if (previous == nullptr) {
		first = current->next;
	}
	else {
		previous->next = current->next;
	}

	//ako izbacujemo poslednji element onda treba last da prebacimo na pretposlednji
	if (current->next == nullptr) {
		last = previous;
	}

	delete current;
	length--;
}

template<typename T>
inline void Lista<T>::copy(const Lista<T>& list)
{
	Node* current = list.first;
	while (current != nullptr) {
		(*this) += current->data;
		current = current->next;
	}
}

template<typename T>
inline void Lista<T>::move(Lista<T>& list) {
	first = list.first;
	last = list.last;
	length = list.length;
	list.first = nullptr;
	list.last = nullptr;
}

template<typename T>
inline void Lista<T>::delete_list()
{
	while (first != nullptr) {
		Node* current = first;
		first = first->next;
		delete current;
	}
	last = nullptr;
	length = 0;
}

#endif
