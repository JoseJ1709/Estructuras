
#include "territorio.h"

// Constructor de la clase Territorio
Territorio::Territorio(string n, string c) {
  nombre_territorio = n;
  unidadesDeEjercito_territorio = 0;
}

// Método para obtener el nombre del territorio
string Territorio::getNombre() {
  return nombre_territorio;
}

// Método para agregar un territorio adyacente alrededor del territorio actual
void Territorio::agregarTerritorioAlrededor(Territorio* ter) {
  territorios_alrededor.push_back(ter);
}

// Método para obtener la lista de territorios adyacentes
list<Territorio*> Territorio::getTerritorioAlrededor() {
  return territorios_alrededor;
}

// Método para obtener el número de unidades de ejército en el territorio
int Territorio::getUnidadesDeEjercito_territorio() {
  return unidadesDeEjercito_territorio;
}

// Método para establecer el número de unidades de ejército en el territorio
void Territorio::setUnidadesDeEjercito_territorio(int cantidad_unidades) {
  unidadesDeEjercito_territorio = cantidad_unidades;
}

// Método para eliminar una unidad del territorio
void Territorio::eliminarUnidadesTerritorio() {
  if (unidadesDeEjercito_territorio > 0) {
    unidadesDeEjercito_territorio--;
  }
}

// Método para agregar unidades adicionales al territorio
void Territorio::agregarUnidadesTerritorioAdicional(int cantidad_adicional) {
  unidadesDeEjercito_territorio += cantidad_adicional;
}