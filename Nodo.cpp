//
// Created by jose on 3/10/23.
//

#include "Nodo.h"

Nodo::Nodo(Nodo *izq, Nodo *der) : izq(izq), der(der) {
}

int Nodo::getFrecuencia(){return frecuencia;}

string Nodo::GetSimbolo(){return simbolo;}

Nodo *Nodo::GetIzq(){return izq;}

Nodo *Nodo::GetDer(){return der;}
