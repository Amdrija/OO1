//
// Created by Andrija Jelenkovic on 11/27/19.
//

#ifndef VEZBE8_SKLADISTE_H
#define VEZBE8_SKLADISTE_H

#include "Telo.h"

class Skladiste {
public:
    Skladiste(): prvi(nullptr), posl(nullptr){}
    Skladiste(const Skladiste& ){
        kopiraj(s);
    }
    Skladiste(Skladiste&&){
        premesti(s);
    }
    Skladiste& operator=(const Skladiste&){
        if(this != &s){
            brisi();
            kopiraj(s);
        }
        return *this;
    }
    Skladiste&operator=(Skladiste&&){
        if(this != &s){
            brisi();
            premesti(s);
        }
        return *this;
    }
    ~Skladiste();
private:
    void brisi();
    void premesti(Skladiste &&s){
        priv = s.prvi;
        posl = s.posl;
        s.prvi = s.posl = nullptr;
    }
    void kopiraj(const Skladiste &);

    struct Elem{
        Telo* t_;
        Elem* sled;
        Elem(Telo* t): sled(nullptr){
            t_ = t;
        }
    };
    Elem* prvi, *posl;
};


#endif //VEZBE8_SKLADISTE_H
