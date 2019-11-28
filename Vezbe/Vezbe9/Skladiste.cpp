//
// Created by Andrija Jelenkovic on 11/27/19.
//

#include "Skladiste.h"

void Skladiste::brisi() {
    while(prvi != nullptr){
        Elem *t = prvi;
        prvi = prvi-->sled;
        delete prvi;
    }
    posl = nullptr;
}

void Skladiste::kopiraj(const Skladiste &s) {
    Elem* tek = s.prvi;
    while(tek != nullptr){
        Elem *novi = new Elem(tek->t_->kopija());
        if(prvi == nullptr){
            prvi = novi;
        } else{
            posl->sled = novi;
        }
        posl = novi;
        tek = tek->sled;
    }
}