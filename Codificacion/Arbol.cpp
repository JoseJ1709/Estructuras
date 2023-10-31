//
// Created by jose on 3/10/23.
//

#include <iostream>
#include "Arbol.h"
#include "Nodo.h"


Arbol::Arbol(Nodo raiz) : raiz(raiz) {}

bool Arbol::isEmpty() {
    if (raiz.GetDer() == nullptr && raiz.GetIzq() == nullptr){
        return true;
    }else{return false;}
}
int Arbol::getFrec() {
    return raiz.GetFrecuencia();
}

int Arbol::getAscii() {
    return raiz.GetAscii();
}

Nodo Arbol::getDer() {
    return *raiz.GetDer();
}

Nodo Arbol::getIzq() {
    return *raiz.GetIzq();
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
};