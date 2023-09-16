#include "jugador.h"

// Constructor de la clase Jugador
Jugador::Jugador(string n, string c, string id) {
  nombre_jugador = n;
  color_jugador = c;
  id_jugador = id;
}

// Método para obtener el nombre del jugador
string Jugador::getNombre() {
  return nombre_jugador;
}

// Método para obtener el color del jugador
string Jugador::getColor() {
  return color_jugador;
}

// Método para obtener el ID del jugador
string Jugador::getId() {
  return id_jugador;
}

// Método para establecer el ID del jugador
void Jugador::setId(string id) {
  id_jugador = id;
}

// Función para jugar el turno del jugador
int Jugador::Turno() {
  // Implementa la lógica de juego del turno del jugador
  // Retorna un valor que indique el resultado del turno (puede ser un código de éxito o error)
  return 0; // Cambia esto a un valor apropiado
}

// Función para fortificar territorios
void Jugador::fortificar() {
  // Implementa la lógica de fortificación de territorios
}

// Función para atacar territorios
void Jugador::atacar() {
  // Implementa la lógica de ataque a territorios
}

// Función para mover unidades entre territorios
void Jugador::mover() {
  // Implementa la lógica de movimiento de unidades entre territorios
}

// Método para agregar una tarjeta al jugador
void Jugador::agregarTarjeta(Tarjeta* t) {
  tarjetas_jugador.push_back(t);
}

// Método para obtener la lista de tarjetas del jugador
list<Tarjeta*> Jugador::getTarjetas() {
  list<Tarjeta*> tarjetas;
  for (Tarjeta* t : tarjetas_jugador) {
    tarjetas.push_back(t);
  }
  return tarjetas;
}

// Método para calcular combinaciones posibles de tarjetas
list<string> Jugador::calcularCombinacionesTarjetas() {
  // Implementa la lógica para calcular combinaciones de tarjetas
  list<string> combinaciones;
  // ...
  return combinaciones;
}

// Método para agregar un territorio al jugador
void Jugador::agregarTerritorio(Territorio* t) {
  territorios_jugador.push_back(t);
}

// Método para obtener la lista de territorios del jugador
list<Territorio*> Jugador::getTerritorios_jugador() {
  list<Territorio*> territorios;
  for (Territorio* t : territorios_jugador) {
    territorios.push_back(t);
  }
  return territorios;
}

// Método para agregar unidades adicionales al jugador
void Jugador::agregarUnidadesAdicionales(int cant_adicional) {
  // Implementa la lógica para agregar unidades adicionales al jugador
}

// Método para eliminar unidades del ejército del jugador
void Jugador::eliminarUnidadesEjercito() {
  // Implementa la lógica para eliminar unidades del ejército del jugador
}