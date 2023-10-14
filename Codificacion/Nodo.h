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
    string simbolo;
    Nodo *izq;
    Nodo *der;

public:

    Nodo(int frecuencia, const string &simbolo) : frecuencia(frecuencia), simbolo(simbolo) {}

    Nodo(int frecuencia, const string &simbolo, Nodo *izq, Nodo *der);

    Nodo(Nodo *izq, Nodo *der);

    void setIzq(Nodo *izq);
    void setDer(Nodo *der);
    void setFrecuencia(int frecuencia);
    void setSimbolo( string &simbolo);
    int Getfrecuencia() ;
    string GetSimbolo();
    Nodo *GetIzq() ;
    Nodo *GetDer() ;
    int getFrecuencia();
    string &getSimbolo();
    Nodo *getIzq();
    Nodo *getDer();


};


#endif //ESTRUCTURAS_NODO_H
