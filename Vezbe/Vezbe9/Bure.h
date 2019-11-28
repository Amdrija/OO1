//
// Created by Andrija Jelenkovic on 11/27/19.
//

//
// Created by Andrija Jelenkovic on 11/27/19.
//

#ifndef VEZBE8_BURE_H
#define VEZBE8_BURE_H

#include "Telo.h"
#include <iostream>
#include <string>

class Bure: public Telo {
public:
    Kutija(int r, int h)
            :r_(r), h_(h){}
    virtual double V() const override{
        return r_ * r_ * h_;
    }
    virtual char vrsta() const override{
        return 'B';
    }
    virtual string pisi(/*ostream& it*/) const override{
        //it<< ...
        return "(" + to_string(r_) + "," + to_string(h_) + ")";
    }
    virtual Bure* kopija() const override{
        return new Bure(*this);
    }
private:
    int r_, h_;
};

#endif //VEZBE8_BURE_H
