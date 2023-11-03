//
// Created by jose on 3/10/23.
//

#include "Nodo.h"

Nodo::Nodo(Nodo *izq, Nodo *der) : izq(izq), der(der) {
}
Nodo::Nodo(int frecuencia, Nodo *izq, Nodo *der) :frecuencia(frecuencia), izq(izq), der(der) {
}
Nodo::Nodo(int frec, int Ascii) {
        frecuencia =frec;
        ascii=Ascii;
        izq=NULL;
        der=NULL;
}
Nodo::Nodo(int frec) {
    frecuencia =frec;
    ascii=-1;
    izq=NULL;
    der=NULL;
}
int Nodo::GetFrecuencia(){return frecuencia;}

int Nodo::GetAscii(){

    return ascii;
}

Nodo* Nodo::GetIzq(){return izq;}

Nodo* Nodo::GetDer(){return der;}

void Nodo::setFrecuencia(int frecuencia) {
    Nodo::frecuencia = frecuencia;
}

void Nodo::setAscii(int ascii) {
    Nodo::ascii = ascii;
}

void Nodo::setIzq(Nodo *izq) {
    Nodo::izq = izq;
}

void Nodo::setDer(Nodo *der) {
    Nodo::der = der;
}


