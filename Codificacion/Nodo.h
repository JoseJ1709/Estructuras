//
// Created by jose on 3/10/23.
//

#ifndef ESTRUCTURAS_NODO_H
#define ESTRUCTURAS_NODO_H

#include <list>
#include <iostream>

using namespace std;

class Nodo {
private:
    int frecuencia;
    int ascii;
    Nodo *izq;
    Nodo *der;

public:

    Nodo(int frecuencia, int ascii) : frecuencia(frecuencia), ascii(ascii) {}
    Nodo(int frecuencia) : frecuencia(frecuencia) {}

    Nodo(int frecuencia, const int &ascii, Nodo *izq, Nodo *der);
    Nodo(int frecuencia, Nodo *izq, Nodo *der);

    Nodo(Nodo *izq, Nodo *der);

    int GetAscii();
    Nodo* GetIzq() ;
    Nodo* GetDer() ;
    int GetFrecuencia();

    void setFrecuencia(int frecuencia);

    void setAscii(int ascii);

    void setIzq(Nodo *izq);

    void setDer(Nodo *der);
};


#endif //ESTRUCTURAS_NODO_H
