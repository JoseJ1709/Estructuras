#include "continente.h"

// Constructor de la clase Continente
Continente::Continente(int id, string n) {
  id_contienente = id;
  nombre_continente = n;
}

// Método para obtener el nombre del continente
string Continente::getNombre() {
  return nombre_continente;
}

// Método para obtener el ID del continente
int Continente::getId() {
  return id_contienente;
}
