/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include <string>

#ifndef CONTINENTE_H
#define CONTINENTE_H

using namespace std;

class Continente {
private:
  int id_contienente;
  string nombre_continente;

public:
  Continente();
  Continente(int id, string nonmbre);

    int getIdContienente() const;

    void setIdContienente(int idContienente);

    const string &getNombreContinente() const;

    void setNombreContinente(const string &nombreContinente);
};

#endif // CONTINENTE_H

