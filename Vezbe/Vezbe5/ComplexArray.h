//
// Created by Andrija Jelenkovic on 11/6/19.
//

#ifndef COMPLEXARRAY_H
#define COMPLEXARRAY_H

#include "Complex.h"

class ComplexArray {
public:
    explicit ComplexArray(int k){
        kapacitet = k;
        popunjenost = 0;
        niz = new Complex[kapacitet];
    }
    ComplexArray(const ComplexArray& ca){
        kopiraj(ca);
    }
    ComplexArray(ComplexArray&& ca) noexcept{
        premesti(ca);
    }
    ~ComplexArray(){
        brisi();
    }
    ComplexArray& operator=(const ComplexArray& ca){
        if(this != &ca) {
            brisi();
            kopiraj(ca);
        }
        return *this;
    }
    ComplexArray& operator=(ComplexArray&& ca) noexcept{
        if(this != &ca) {
            brisi();
            premesti(ca);
        }
        return *this;
    }
private:
    int popunjenost;
    int kapacitet;
    Complex* niz;
    void kopiraj(const ComplexArray& ca){
        popunjenost = ca.popunjenost;
        kapacitet = ca.kapacitet;
        niz = new Complex[kapacitet];
        for(int i = 0; i < popunjenost; i++){
            niz[i] = ca.niz[i];
        }
    }

    void premesti(ComplexArray& ca){
        popunjenost = ca.popunjenost;
        kapacitet = ca.kapacitet;
        niz = ca.niz;
        ca.niz = nullptr;
    }

    void brisi(){
        delete[] niz;
        niz = nullptr;
    }
};


#endif //UNTITLED_COMPLEXARRAY_H
