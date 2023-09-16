#include "tarjeta.h"

// Constructor de la clase Tarjeta con territorio asociado
Tarjeta::Tarjeta(string t, Territorio* te, int e) {
  tipo = t;
  territorio = te;
  unidadesDeEjercito_tarjeta = e;
  utilizada = false; // Inicializa como no utilizada
}

// Constructor de la clase Tarjeta sin territorio asociado
Tarjeta::Tarjeta(string t, int e) {
  tipo = t;
  territorio = nullptr; // Sin territorio asociado
  unidadesDeEjercito_tarjeta = e;
  utilizada = false; // Inicializa como no utilizada
}

// Método para obtener el tipo de la tarjeta
string Tarjeta::getTipo() {
  return tipo;
}

// Método para obtener el territorio asociado a la tarjeta
Territorio* Tarjeta::getTerritorio() {
  return territorio;
}

// Método para obtener la cantidad de ejército en la tarjeta
int Tarjeta::getEjercito() {
  return unidadesDeEjercito_tarjeta;
}

// Método para establecer si la tarjeta ha sido utilizada
void Tarjeta::setUtilizada(bool v) {
  utilizada = v;
}

// Método para verificar si la tarjeta ha sido utilizada
bool Tarjeta::getUtilizada() {
  return utilizada;
}
