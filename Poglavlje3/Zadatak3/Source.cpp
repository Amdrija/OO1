#include "Queue.h"

int main() {
	Queue q;
	
	q.read();
	std::cout << q.shift() << std::endl;
	q.push(6);
	q.print();
	Queue r = q;
	q.empty();
	std::cout << q.isEmpty() << std::endl;
	r.print();
	return 0;
}