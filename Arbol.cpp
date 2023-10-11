//
// Created by jose on 3/10/23.
//

#include "Arbol.h"
#include "Nodo.h"
#include <iostream>

Arbol::Arbol(Nodo &raiz) : raiz(raiz) {}

bool Arbol::isEmpty() {
    if (raiz.GetDer() == nullptr && raiz.GetIzq() == nullptr){
        return true;
    }else{return false;}
}
int getFrec(){}
string getSimbol();
Nodo getDer();
Nodo getIzq();
void setFrec(int frecuencia);
void setSimbol(string simbolo);
void setIzq(Arbol izq);
void setDer(Arbol der);