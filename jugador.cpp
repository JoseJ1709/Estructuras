/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include "jugador.h"

Jugador::Jugador(){}
Jugador::Jugador(string n, string c, int id) {
  nombre_jugador = n;
  color_jugador = c;
  id_jugador = id;
}

int Jugador::Turno() {
return 0;
}

void Jugador::fortificar() {

}

void Jugador::atacar() {

}

void Jugador::mover() {

}

const string &Jugador::getNombreJugador() const {
    return nombre_jugador;
}

void Jugador::setNombreJugador(const string &nombreJugador) {
    nombre_jugador = nombreJugador;
}

const int &Jugador::getIdJugador() const {
    return id_jugador;
}

void Jugador::setIdJugador(const int &idJugador) {
    id_jugador = idJugador;
}

const string &Jugador::getColorJugador() const {
    return color_jugador;
}

void Jugador::setColorJugador(const string &colorJugador) {
    color_jugador = colorJugador;
}

const list<Tarjeta *> &Jugador::getTarjetasJugador() const {
    return tarjetas_jugador;
}

void Jugador::setTarjetasJugador(const list<Tarjeta *> &tarjetasJugador) {
    tarjetas_jugador = tarjetasJugador;
}

const list<Territorio *> &Jugador::getTerritoriosJugador() const {
    return territorios_jugador;
}

void Jugador::setTerritoriosJugador(const list<Territorio *> &territoriosJugador) {
    territorios_jugador = territoriosJugador;
}
