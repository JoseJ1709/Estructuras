#ifndef TARJETA_H
#define TARJETA_H

#include <string>
#include "territorio.h"

using namespace std;

// Definición de la clase Tarjeta
class Tarjeta {
private:
  string tipo;
  Territorio* territorio;
  int unidadesDeEjercito_tarjeta;
  bool utilizada; // Nueva variable para rastrear si la tarjeta ha sido utilizada

public:
  // Constructor de la clase Tarjeta con territorio
  Tarjeta(string t, Territorio* te, int e);

  // Constructor de la clase Tarjeta sin territorio
  Tarjeta(string t, int e);

  // Método para obtener el tipo de la tarjeta
  string getTipo();

  // Método para obtener el territorio asociado a la tarjeta
  Territorio* getTerritorio();

  // Método para obtener la cantidad de ejército en la tarjeta
  int getEjercito();

  // Método para establecer si la tarjeta ha sido utilizada
  void setUtilizada(bool v);

  // Método para verificar si la tarjeta ha sido utilizada
  bool getUtilizada();
};

#endif // TARJETA_H