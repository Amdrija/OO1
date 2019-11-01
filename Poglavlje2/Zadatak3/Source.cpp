#include <iostream>

using namespace std;

struct element {
	int inf;
	element* next;
};

void read_list(element* &head) {
	cout << "Input number of elements in the list." << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		element* new_element = new element;
		cout << "List elements: " << endl;
		cin >> new_element->inf;
		new_element->next = head;
		head = new_element;
	}
}

void write_list(element* head) {
	while (head) {
		cout << head->inf << ", ";
		head = head->next;
	}
	cout << endl;
}

void delete_list(element* head) {
	while (head) {
		element* p = head;
		head = head->next;
		delete p;
	}
	cout << "List deleted." << endl;
}

int main() {
	element* head = nullptr;
	read_list(head);
	write_list(head);
	delete_list(head);
	return 0;
}