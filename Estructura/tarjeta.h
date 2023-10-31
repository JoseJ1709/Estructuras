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

    int getIdTarjeta() ;

    const string &getTipo() ;

    void setTipo( string &tipo);

    int getKeyTerritorio() ;

    const string &getDibujo();


};

#endif // TARJETA_H
