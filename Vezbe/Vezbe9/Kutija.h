//
// Created by Andrija Jelenkovic on 11/27/19.
//

#ifndef VEZBE8_KUTIJA_H
#define VEZBE8_KUTIJA_H

#include "Telo.h"
#include <iostream>
#include <string>

class Kutija: public Telo {
public:
    Kutija(int a, int b, int c)
        :a_(a), b_(b), c_(c){}
    virtual double V() const override{
        return a_ * b_ * c_;
    }
    virtual char vrsta() const override{
        return 'K';
    }
    virtual string pisi(/*ostream& it*/) const override{
        //it<< ...
        return "(" + to_string(a_) + "," + to_string(b_) + ","+ to_string(c) + ")";
    }
    //POVRATNE VREDNOSTI SMEJU DA SE MENJAJU SAMO AKO U OSNOVNOJ KLASI
    // IMAMO POVRATNU VREDNOST POKAZIVAC/ REFERENCU NA OSNOVNU KLASU
    // ONDA U IZVEDENOJ KLASI SMEMO DA PROEMNIMO U POKAZIVAC/REFERENCU NA IZVEDENU KLASU
    virtual Kutija* kopija() const override{
        return new Kutija(*this);
    }
private:
    int a_, b_, c_;
};


#endif //VEZBE8_KUTIJA_H
