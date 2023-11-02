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
    Arbol(Nodo *raiz);

    Nodo raiz;
public:
    Arbol(Nodo raiz);
    bool isEmpty();
    int getFrec();
    int getAscii();
    Arbol getDer();
    Arbol getIzq();
    void setFrec(int frecuencia);
    void setAscii(int ascii);
    void setIzq(Arbol izq);
    void setDer(Arbol der);
    bool esta(int ascii);
    //descolgar y colgar //
};


#endif //ESTRUCTURAS_ARBOL_H
