//
// Created by jose on 3/10/23.
//

#include <iostream>
#include "Arbol.h"
#include "Nodo.h"


Arbol::Arbol(Nodo raiz) : raiz(raiz) {}
Arbol::Arbol(Nodo* raiz) : raiz(*raiz) {}

bool Arbol::isEmpty() {

}
int Arbol::getFrec() {
    return raiz.GetFrecuencia();
}

int Arbol::getAscii() {
    return raiz.GetAscii();
}

Arbol Arbol::getDer() {

    Nodo ax = *raiz.GetDer();
    return Arbol(ax);
}

Arbol Arbol::getIzq() {
    return Arbol(*raiz.GetIzq());
}

void Arbol::setFrec(int frecuencia) {
    raiz.setFrecuencia(frecuencia);
}

void Arbol::setAscii(int ascii) {
    raiz.setAscii(ascii);
}

void Arbol::setIzq(Arbol izq) {
    raiz.setIzq(&izq.raiz);
}

void Arbol::setDer(Arbol der) {
    raiz.setDer(&der.raiz);
}
bool Arbol::esta(int ascii) {
    if(this->getAscii()==ascii){
        return true;
    }else if(this->isEmpty()){
        return false;
    }else if(this->getIzq().raiz.GetIzq() == nullptr && this->getDer().raiz.GetDer()!= nullptr){
        return this->getDer().esta(ascii);
    }
    else if(this->getIzq().raiz.GetIzq() != nullptr && this->getDer().raiz.GetDer() == nullptr){
        return this->getIzq().esta(ascii);
    }else{
        return this->getIzq().esta(ascii) || this->getDer().esta(ascii);
    }
};