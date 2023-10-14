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

    int id_tarjeta;
    string tipo_tarjeta;
    int key_territorio;
    string dibujo;

public:
    Tarjeta(int id,string t,int key_t, string dib);

    int getIdTarjeta() const;

    const string &getTipo() const;

    void setTipo(const string &tipo);

    int getKeyTerritorio() const;

    const string &getDibujo() const;


};

#endif // TARJETA_H
