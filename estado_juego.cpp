/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include "estado_juego.h"

EstadoJuego::EstadoJuego() {}
EstadoJuego::EstadoJuego(list<Jugador> j, list<Tarjeta> m, list<Jugador>::iterator iteradorJugadores) {
    jugadores = j;
    mazo = m;
    iterador_jugadores = iteradorJugadores;
}

void EstadoJuego::inicializar() {

}

void EstadoJuego::turno(int id_jugador) {

  for (Jugador jugador : jugadores) {
    if (jugador.getIdJugador() == id_jugador) {
      jugador.Turno();
      break;
    }
  }
}

const list<Jugador> &EstadoJuego::getJugadores() const {
    return jugadores;
}

void EstadoJuego::setjugadores(const list<Jugador> &j) {
    jugadores = j;
}

const list<Jugador>::iterator &EstadoJuego::getIteradorJugadores() const {
    return iterador_jugadores;
}

void EstadoJuego::setIteradorJugadores(const list<Jugador>::iterator &iteradorJugadores) {
    iterador_jugadores = iteradorJugadores;
}

const list<Tarjeta> &EstadoJuego::getMazo() const {
    return mazo;
}

void EstadoJuego::setMazo(const list<Tarjeta> &m) {
    mazo = m;
}
