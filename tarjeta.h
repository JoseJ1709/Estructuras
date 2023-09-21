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
  string tipo;
  Territorio territorio;

public:
  Tarjeta(string t, Territorio te);
  Tarjeta(string t);
  const

    string &getTipo() const;

    void setTipo(const string &tipo);

    const Territorio &getTerritorio() const;

    void setTerritorio(const Territorio &territorio);


};

#endif // TARJETA_H
