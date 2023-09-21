/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include "continente.h"
#include "jugador.h"
#include "tarjeta.h"
#include <list>
#include <string>
#include <vector>

#ifndef ESTADOJUEGO_H
#define ESTADOJUEGO_H

using namespace std;

class EstadoJuego {
private:
  list<Jugador> jugadores;
  list<Tarjeta> mazo;
  list<Jugador>::iterator iterador_jugadores;
public:
    const list<Tarjeta> &getMazo() const;

    void setMazo(const list<Tarjeta> &mazo);

public:
  EstadoJuego();

    EstadoJuego(list<Jugador> j, list<Tarjeta> m, list<Jugador>::iterator iteradorJugadores);

  void inicializar();
  void turno(int id_jugador);

    const list<Jugador> &getJugadores() const;

    void setjugadores(const list<Jugador> &jugadores);

    const list<Tarjeta> &getmazo() const;

    void setmazo(const list<Tarjeta> &mazo);

    const list<Jugador>::iterator &getIteradorJugadores() const;

    void setIteradorJugadores(const list<Jugador>::iterator &iteradorJugadores);

};

#endif // ESTADOJUEGO_H
