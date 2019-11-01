#include <iostream>
#include "Angles.h"

int main() {
	Angle alpha(PI / 2);
	Angle beta;
	beta.readAngle();
	Angle gama(60, 0, 0);
	alpha.add(beta).add(gama);
	gama.multiply(3).multiply(0.5);
	alpha.printDegrees();
	alpha.printRadians();
	beta.printDegrees();
	beta.printRadians();
	gama.printDegrees();
	gama.printRadians();
	
	return 0;
}