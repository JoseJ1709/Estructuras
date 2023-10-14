/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include <list>
#include "tarjeta.h"
#include "territorio.h"
#include <string>
#include "Estructura/continente.h"
#ifndef JUGADOR_H
#define JUGADOR_H
#include "Juego/EstadoJuego.h"

using namespace std;

class Jugador {
private:
  string nombre_jugador;
  int id_jugador;
  string color_jugador; 
  list<Tarjeta> tarjetas_jugador;
  list<Territorio> territorios_jugador;

public:
    Jugador();
    Jugador(string n, string c, int id);

    //Consola//

    int Turno(EstadoJuego &partida,list<Continente> continentes);

    //Archivo//

    int Turno(EstadoJuego &partida,string territorioAtacante,string territorioVictima, string nombreTerritorio, int unidadesAñadir, int unidades_mover, string territorio_recipiente, string seleccion);

    void fortificar( list<Continente> continentes, int tarjetas_global );

    void atacar(list<Jugador> &jugadores);

    void mover();
  
    const string &getNombreJugador() const;

    void setNombreJugador(const string &nombreJugador);

    const int &getIdJugador() const;

    void setIdJugador(const int &idJugador);

    const string &getColorJugador() const;

    void setColorJugador(const string &colorJugador);

    const list<Tarjeta> &getTarjetasJugador() const;

    void setTarjetasJugador(const list<Tarjeta> &tarjetasJugador);

    const list<Territorio> &getTerritoriosJugador() const;

    void setTerritoriosJugador( list<Territorio> &territoriosJugador);

};

#endif // JUGADOR_H

