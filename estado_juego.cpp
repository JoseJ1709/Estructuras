#include "estado_juego.h"

// Constructor de la clase EstadoJuego
EstadoJuego::EstadoJuego(int numJugadores) {
  // Inicializa el juego con el número de jugadores especificado
  for (int i = 0; i < numJugadores; i++) {
    // Crea y agrega jugadores al vector de jugadores_tablero
    // Puedes inicializar los jugadores con sus nombres, colores, etc., según sea necesario
    Jugador jugador("NombreJugador", "ColorJugador", "IDJugador");
    jugadores_tablero.push_back(jugador);
  }

  // Inicializa otros elementos del juego según sea necesario
}

// Método para la fase de inicialización del juego
void EstadoJuego::inicializar() {
  // Implementa la lógica de inicialización del juego, como la asignación de territorios, tarjetas, etc.
}

// Método para que un jugador realice su turno
void EstadoJuego::turno(string id_jugador) {
  // Busca al jugador con el ID especificado en el vector de jugadores_tablero
  for (auto& jugador : jugadores_tablero) {
    if (jugador.getId() == id_jugador) {
      // Realiza las tres partes del turno del jugador: jugador, fortificar y mover
      jugador.Turno();
      jugador.fortificar();
      jugador.atacar();
      jugador.mover();
      break;
    }
  }
}
