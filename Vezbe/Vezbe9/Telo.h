//
// Created by Andrija Jelenkovic on 11/27/19.
//

#ifndef VEZBE8_TELO_H
#define VEZBE8_TELO_H

#include <iostream>
#include <string>
using namespace std;

class Skladiste;
//MORAMO DA DEKLARISEMO KLASU, ALI NE SMEMO DA DEFINISEMO SKLADISTE
//JER CEMO IMATI KRUZNU ZAVISNOTST PA SE PROGRAM NECE PREVESTI

class Telo {
public:
    Telo(){}
    Telo(const Telo&){} //da ne bi kopirao ID
    Telo(Telo&&){}
    Telo& operator=(const Telo&){return *this;}
    Telo& operator=(Telo&&){return *this;}

    //mora da se definise da bi kasnije mogli da zovemo destruktor pokazivanog objekta
    //a ne destrukor tela ako imamo pokazivac na kutiju
    //uvek ga definisemo ako imamo izvedene klase
    virtual ~Telo(){}


    //KONSTRUKTOR NE MOZE DA BUDE VIRTUELAN
    //moramo da obezbedimo drugi nacain pozivanja virtuelnih konstruktora
    virtual Telo* kopija() const = 0;

    virtual double V() const = 0; //apstraktna metoda
    virtual char vrsta() const = 0;
    virtual string pisi() const = 0;
    //ne moze da bude virtuelna metoda
    friend ostream& operator<<(const ostream& os,const Telo& t){
        os << t.vrsta() << "_"<<t.id <<":"<< t.pisi();
    }

    void setSkladiste(Skladiste*s){
        s_ = s;
    }

private:
//Autoamtski generisani identifikator
    static int poslednji_ID;
    int id = ++poslednji_ID;

    Skladiste* s_ = nullptr;
};


#endif //VEZBE8_TELO_H
