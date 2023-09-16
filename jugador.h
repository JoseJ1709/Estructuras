/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo
  Universidad Javeriana - Tercer periodo 2023
*/
#include <list>
#include "tarjeta.h"
#include "territorio.h" // Agregado "territorio.h"
#include <string>

#ifndef JUGADOR_H
#define JUGADOR_H

using namespace std;

// Definición de la clase Jugador
class Jugador {
private:
  string nombre_jugador;
  string id_jugador;
  string color_jugador; 
  list<Tarjeta*> tarjetas_jugador;
  list<Territorio*> territorios_jugador;

public:
  // Constructor de la clase Jugador
  Jugador(string n, string c, string id);

  // Método para obtener el nombre del jugador
  string getNombre();
  // Método para obtener el color del jugador
  string getColor();
  // Método para obtener el ID del jugador
  string getId();
  // Método para establecer el ID del jugador
  void setId(string id);
  // Función para jugar el turno del jugador
  int Turno();
  // Función para fortificar territorios
  void fortificar();
  // Función para atacar territorios
  void atacar();
  // Función para mover unidades entre territorios
  void mover();
  // Método para agregar una tarjeta al jugador
  void agregarTarjeta(Tarjeta* t);
  // Método para obtener la lista de tarjetas del jugador
  list<Tarjeta*> getTarjetas();
  // Método para calcular combinaciones posibles de tarjetas
  list<string> calcularCombinacionesTarjetas();
  // Método para agregar un territorio al jugador
  void agregarTerritorio(Territorio* t);
  // Método para obtener la lista de territorios del jugador
  list<Territorio*> getTerritorios_jugador();
  // Método para agregar unidades adicionales al jugador
  void agregarUnidadesAdicionales(int cant_adicional);
  // Método para eliminar unidades del ejército del jugador
  void eliminarUnidadesEjercito();
};

#endif // JUGADOR_H

