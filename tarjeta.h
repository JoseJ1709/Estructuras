/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#ifndef TARJETA_H
#define TARJETA_H

#include <string>
#include "territorio.h"

using namespace std;

class Tarjeta {
private:
  int key;
  string tipo;
  string territorio;

public:
  Tarjeta(int k,string t, string te);

    Tarjeta();

    const string &getTipo() const;

    void setTipo(const string &tipo);

    void setTerritorio(const string territorio);

    const string &getTerritorio() const;

};

#endif // TARJETA_H
