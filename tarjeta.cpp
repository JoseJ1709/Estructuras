/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include "tarjeta.h"

Territorio::Territorio() {}

Tarjeta::Tarjeta(string t, Territorio te) {
    tipo = t;
    territorio = te;
}

Tarjeta::Tarjeta(string t) {
    tipo = t;
}

const string &Tarjeta::getTipo() const {
    return tipo;
}

void Tarjeta::setTipo(const string &tipo) {
    Tarjeta::tipo = tipo;
}

const Territorio &Tarjeta::getTerritorio() const {
    return territorio;
}

void Tarjeta::setTerritorio(const Territorio &territorio) {
    Tarjeta::territorio = territorio;
}

