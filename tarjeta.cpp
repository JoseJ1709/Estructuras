/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include "tarjeta.h"
#include <string>


Tarjeta::Tarjeta(int k,string t, string te) {
    key = k;
    tipo = t;
    territorio = te;
}

const string &Tarjeta::getTipo() const {
    return tipo;
}

void Tarjeta::setTipo(const string &tipo) {
    Tarjeta::tipo = tipo;
}

const string &Tarjeta::getTerritorio() const {
    return territorio;
}

void Tarjeta::setTerritorio(string territorio)  {
    territorio = territorio;
}

