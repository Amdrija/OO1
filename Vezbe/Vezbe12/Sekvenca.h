//
// Created by Andrija Jelenkovic on 12/18/19.
//

#ifndef VEZBE12_SEKVENCA_H
#define VEZBE12_SEKVENCA_H

#include <cstdlib> //da bi koristili exit
#include "Exceptions.h"
template <typename T>
class Sekvenca {
public:
    Sekvenca(const Sekvenca& s){
        kopiraj(s);
    }
    Sekvenca(Sekvenca&& s){
        premesti(s);
    }
    ~Sekvenca() {
        brisi();
    }
    Sekvenca&operator=(const Sekvenca& s){
        if(this != &s) {
            brisi();
            kopiraj(s);
        }

        return *this;
    }

    Sekvenca&operator=(Sekvenca&& s){
        if(this != &s) {
            brisi();
            premesti(s);
        }

        return *this;
    }

    Sekvenca& dodaj(const T& t){
        if(uzet)
            throw GreskaUzetElement();
        Element* novi = new Element(t);
        posl = (!prvi ? prvi : posl->sled) = novi;
        duzina++;
        return *this;
    }

    T uzmi(){
        if (!prvi) {
            exit(1); //mozemo da bacimo i neki genericki izuzetak
        }

        Element* tek = prvi;
        prvi = prvi->sled;
        if(!prvi)
            posl = nullptr;

        T t = tek->t;
        delete tek;
        duzina--;
        uzet = true;
        return t;
    }

    int dohvatiDuzinu() const {
        return duzina;
    }

    const T& dohvatiElement(int i) const{
        if(i < 0 || i >= duzina) {
            throw 1; //treba napisati novu klasu, ali on sad nije imao vremena
        }
        Element* tek = prvi;
        while(i > 0){
            tek = tek->sled;
            i--;
        }
        return tek->t;
    }
private:
    struct Element{
        //ako koristimo pokazivac, ove cemo samo kopirati pokazivace,
        // pa ce 2 cvora pokazivati na isti element
        T t; //koristiti ovo jednostavno, da bi se izbeglo kod pravljenja sekvence pokazivaca
        //prosledjivanje pokazivaca na pokazivac itd.
        Element* sled;
        Element(const T& tt): t(tt), sled(nullptr){}
    };
    bool uzet = false;
    Element* prvi = nullptr, *posl = nullptr;
    int duzina = 0;
    void brisi();
    void kopiraj(const Sekvenca& s);
    void premesti(Sekvenca& s){
        duzina = s.duzina;
        prvi = s.prvi;
        posl = s.posl;
        s.prvi = s.posl = nullptr;
    }
};

template<typename T>
void Sekvenca<T>::brisi() {
    while(prvi){
        Element* t = prvi;
        prvi = prvi -> sled;
        delete t;
    }
    posl = nullptr;
    duzina = 0;
}

template<typename T>
void Sekvenca<T>::kopiraj(const Sekvenca &s) {
    duzina = s.duzina;
    Element* tek = s.prvi;
    while(tek){
        Element* novi = new Element(tek->t);
        posl = (!prvi ? prvi : posl->sled) = novi;
        tek = tek->sled;
    }
}


#endif //VEZBE12_SEKVENCA_H
