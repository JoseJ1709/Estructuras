//
// Created by jose on 3/10/23.
//

#include <iostream>
#include "Arbol.h"
#include "Nodo.h"


Arbol::Arbol(Nodo* raiz) : raiz(raiz) {
}

bool Arbol::isEmpty() {
    if(raiz == NULL){
        return true;
    }else
        return false;
}
int Arbol::getFrec() {
    return raiz->GetFrecuencia();
}

int Arbol::getAscii() {
    return raiz->GetAscii();
}

Arbol Arbol::getDer() {

    return Arbol(raiz->GetDer());
}

Arbol Arbol::getIzq() {
    return Arbol(raiz->GetIzq());
}

void Arbol::setFrec(int frecuencia) {
    raiz->setFrecuencia(frecuencia);
}

void Arbol::setAscii(int ascii) {
    raiz->setAscii(ascii);
}

void Arbol::setIzq(Arbol izq) {
    raiz->setIzq(izq.raiz);
}

void Arbol::setDer(Arbol der) {
    raiz->setDer(der.raiz);
}
bool Arbol::esta(int ascii) {
    if(this->isEmpty()){
        return false;
    }else if(this->getAscii()==ascii){
        return true;
    }else{
        bool izq = this->getIzq().esta(ascii);
        if(izq)
            return true;
        bool der = this->getDer().esta(ascii);
        if(der)
            return true;
        return false;
    }
};