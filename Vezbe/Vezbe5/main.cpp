#include <iostream>
#include "Complex.h"
int main() {
    Complex z1(1, -1);
    Complex z2(0, 9);

    Complex z3 = z1 + z2;
    (z1 += z2) += z3;
    //u ovom slucaju ako += vraca kopiju objekta a ne referencu
    //onda ce se promeniti kopija z1, ali se z1 nece promeniti,
    //a trebalo je

    std::cout<< z1;
    return 0;
}