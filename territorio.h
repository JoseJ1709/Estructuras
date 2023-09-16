/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo
  Universidad Javeriana - Tercer periodo 2023
*/
#include <string>
#include <list>

#ifndef TERRITORIO_H
#define TERRITORIO_H

using namespace std;

// Definición de la clase Territorio
class Territorio {
private:
  int id_territorio;
  string nombre_territorio;
  int id_continente; // Cambiado de "id_contiente" a "id_continente"
  list<Territorio*> territorios_alrededor;
  int unidadesDeEjercito_territorio;

public:
  // Constructor de la clase Territorio
  Territorio(string n, string c);
  // Método para obtener el nombre del territorio
  string getNombre();
  // Método para agregar un territorio adyacente alrededor del territorio actual
  void agregarTerritorioAlrededor(Territorio* ter);
  // Método para obtener la lista de territorios adyacentes
  list<Territorio*> getTerritorioAlrededor();
  // Método para obtener el número de unidades de ejército en el territorio
  int getUnidadesDeEjercito_territorio();
  // Método para establecer el número de unidades de ejército en el territorio
  void setUnidadesDeEjercito_territorio(int cantidad_unidades);
  // Método para eliminar una unidad del territorio
  void eliminarUnidadesTerritorio();
  // Método para agregar unidades adicionales al territorio
  void agregarUnidadesTerritorioAdicional(int cantidad_adicional);
};

#endif // TERRITORIO_H
