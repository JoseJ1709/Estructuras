/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include "tarjeta.h"
#include <string>


Tarjeta::Tarjeta(int id,string t,int key_t, string dib) {
    id_tarjeta = id;
    tipo_tarjeta = t;
    key_territorio = key_t;
    dibujo = dib;
}

int Tarjeta::getIdTarjeta() {
    return id_tarjeta;
}

const string &Tarjeta::getTipo() {
    return tipo_tarjeta;
}

void Tarjeta::setTipo( string &tipo) {
    Tarjeta::tipo_tarjeta = tipo;
}

int Tarjeta::getKeyTerritorio()  {
    return key_territorio;
}
const string &Tarjeta::getDibujo()  {
    return dibujo;
}

