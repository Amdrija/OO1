#include "Set.h"

int main() {
	Set s1;
	s1.read();
	s1.print();
	Set s2(4.5);
	s2.add(3);
	s2.print();
	Set s3 = s2._union(s1);
	s3.print();
	Set s4 = s2._intersection(s1);
	s4.print();
	s3._difference(s4).print();
	return 0;
}