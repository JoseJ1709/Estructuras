/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo
  Universidad Javeriana - Tercer periodo 2023
*/
#include <string>

#ifndef CONTINENTE_H
#define CONTINENTE_H

using namespace std;

// Definición de la clase Continente
class Continente {
private:
  int id_contienente;
  string nombre_continente;

public:
  // Constructor de la clase Continente
  Continente(int id, string n);
  // Método para obtener el nombre del continente
  string getNombre();
  // Método para obtener el ID del continente
  int getId();
};

#endif // CONTINENTE_H

