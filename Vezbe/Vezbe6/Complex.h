//
// Created by Andrija Jelenkovic on 11/6/19.
//

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <math.h>

class Complex {
public:
    Complex(): re(0), im(0){}
    Complex(double real, double imaginary): re(real), im(imaginary){}

    friend Complex operator+(const Complex& z1, const Complex& z2){
        return Complex(z1.re + z2.re, z1.im + z2.im);
    }

    friend Complex operator-(const Complex& z1, const Complex& z2){
        return Complex(z1.re - z2.re, z1.im - z2.im);
    }

    friend Complex operator*(const Complex& z1, const Complex& z2){
        return Complex(z1.re * z2.re - z1.im * z2.im, z1.im * z2.re + z1.re * z2.im);
    }

    Complex& operator+=(const Complex& z){
        return *this = *this + z;
    }

    Complex operator~() const{
        return Complex(re, -im);
    }

    //ne treba const ispred ostream jer se taj objekat menja
    friend std::ostream& operator<<(std::ostream& os, const Complex& z){
        os << "(" << z.re << ", " << z.im <<")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Complex& z){
        return is >> z.re >> z.im;
    }

    //PREFIKSNI ++
    Complex& operator++(){
        re++;
        return *this;
    }

    //POSTFIKSNI ++
    Complex operator++(int){
        Complex e = *this;
        ++(*this);
        return e;
    }

    //MORA DA SE DEFINISE KAO NESTATICKA METODA
    //IMA 5 TAKVIH OPERATORA
    double operator[](char c) {
        if(c == 'r')
            return re;
        if(c == 'i')
            return im;

        std::cout<<"Greska u indeksu!"<<std::endl;
        return -9999;
    }

    //obicno se kreira i za const
    const double operator[](char c) const{
        if(c == 'r')
            return re;
        if(c == 'i')
            return im;

        std::cout<<"Greska u indeksu!"<<std::endl;
        return -9999;
    }

    operator double() const{
        return sqrt(re * re + im * im);
    }

    /*operator()(int a, int b, int c){

    }*/
    //NPR imamo klasu polinoma i hocemo da za polinom p
    //izracunamo u odredjenoj tacki izracunamo njegovu vrednost
    //tzv. funkcijski operator
    //Koliko god hocemo operanada



    //SAMO KAO PRIJATELJSKE FUNKCIJE: <<, >>
    //SAMO KAO NESTATICKE METODE: [] , (tip), (), ->, =
    //SAMO KAO STATICKE METODE: new, delete
private:
    double re, im;
};


#endif //UNTITLED_COMPLEX_H
