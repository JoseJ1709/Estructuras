/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#ifndef JUGADOR_H
#define JUGADOR_H


#include "iostream"
#include <list>
#include "tarjeta.h"
#include "territorio.h"
#include <string>
#include "continente.h"

class EstadoJuego;

using namespace std;

class Jugador {
private:
    string nombre_jugador;
    int id_jugador;
    string color_jugador;
    list <Tarjeta> tarjetas_jugador;
    list <Territorio> territorios_jugador;

public:
    Jugador();

    Jugador(string n, string c, int id);

    //Consola//

    int Turno(EstadoJuego *partida, list <Continente> continentes);

    //Archivo//

    int Turno(EstadoJuego &partida, string territorioAtacante, string territorioVictima, string nombreTerritorio,
              int unidadesAñadir, int unidades_mover, string territorio_recipiente, string seleccion);

    void fortificar(list <Continente> continentes, EstadoJuego &partida);

    void atacar(EstadoJuego &partida);

    void mover();

     string getNombreJugador();

    void setNombreJugador(string &nombreJugador);

    const int &getIdJugador();

    void setIdJugador(int &idJugador);

    const string &getColorJugador();

    void setColorJugador(string &colorJugador);

     list <Tarjeta> getTarjetasJugador();

    void setTarjetasJugador(list <Tarjeta> tarjetasJugador);

    list <Territorio> getTerritoriosJugador();

    void setTerritoriosJugador(list <Territorio> &territoriosJugador);

};

#endif // JUGADOR_H

