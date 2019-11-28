#include <iostream>
#include "Telo.h"
#include "Kutija.h"
#include "Bure.h"
int main() {
    Telo *t = new Bure(2,3);
    std::cout << *t;
    return 0;
}