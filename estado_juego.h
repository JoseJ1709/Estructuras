#include "continente.h"
#include "jugador.h"
#include "tarjeta.h"
#include <list>
#include <string>
#include <vector>

#ifndef ESTADOJUEGO_H
#define ESTADOJUEGO_H

using namespace std;

// Definición de la clase EstadoJuego
class EstadoJuego {
private:
  vector<Jugador> jugadores_tablero;
  vector<Tarjeta> tarjetas_tablero;
  vector<Jugador>::iterator iterador_jugadores;

public:
  EstadoJuego(int numJugadores);
  // Método para inicializar el juego
  void inicializar();
  // Método para que un jugador realice su turno
  void turno(string id_jugador);
  // Agrega más métodos según sea necesario
};

#endif // ESTADOJUEGO_H
