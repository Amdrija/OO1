//
// Created by Andrija Jelenkovic on 12/18/19.
//

#ifndef VEZBE12_EXCEPTIONS_H
#define VEZBE12_EXCEPTIONS_H

#include <iostream>
class GreskaUzetElement{
public:
    friend std::ostream& operator<<(std::ostream& os, const GreskaUzetElement& g){
        os << "Greska: Pokusaj dodavanja elementa nakon sto je prvi uzet." << std::endl;
        return os;
    }
};


#endif //VEZBE12_EXCEPTIONS_H
