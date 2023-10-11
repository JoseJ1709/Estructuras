//
// Created by jose on 3/10/23.
//

#ifndef ESTRUCTURAS_ARBOL_H
#define ESTRUCTURAS_ARBOL_H
#include "Nodo.h"
#include <list>
#include <iostream>

using namespace std;
class Arbol {
private:
    Nodo raiz;
public:
    Arbol(Nodo &raiz);
    bool isEmpty();
    int getFrec();
    string getSimbol();
    Nodo getDer();
    Nodo getIzq();
    void setFrec(int frecuencia);
    void setSimbol(string simbolo);
    void setIzq(Arbol izq);
    void setDer(Arbol der);
    //descolgar y colgar //
};


#endif //ESTRUCTURAS_ARBOL_H
