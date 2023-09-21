/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include <list>
#include "tarjeta.h"
#include "territorio.h" 
#include <string>

#ifndef JUGADOR_H
#define JUGADOR_H

using namespace std;

class Jugador {
private:
  string nombre_jugador;
  int id_jugador;
  string color_jugador; 
  list<Tarjeta*> tarjetas_jugador;
  list<Territorio*> territorios_jugador;

public:
  Jugador();
  Jugador(string n, string c, int id);

  int Turno();

  void fortificar();
  
  void atacar();
  void mover();
  
    const string &getNombreJugador() const;

    void setNombreJugador(const string &nombreJugador);

    const int &getIdJugador() const;

    void setIdJugador(const int &idJugador);

    const string &getColorJugador() const;

    void setColorJugador(const string &colorJugador);

    const list<Tarjeta *> &getTarjetasJugador() const;

    void setTarjetasJugador(const list<Tarjeta *> &tarjetasJugador);

    const list<Territorio *> &getTerritoriosJugador() const;

    void setTerritoriosJugador(const list<Territorio *> &territoriosJugador);

};

#endif // JUGADOR_H

