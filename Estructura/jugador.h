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

    EstadoJuego* Turno(EstadoJuego* partida, list <Continente> continentes);

    //Archivo//

    int Turno(EstadoJuego &partida, string territorioAtacante, string territorioVictima, string nombreTerritorio,
              int unidadesAñadir, int unidades_mover, string territorio_recipiente, string seleccion);

    EstadoJuego* fortificar(list <Continente> continentes, EstadoJuego* partida);
    EstadoJuego* fortificar(int unidades, int keyT,EstadoJuego* partida);

    EstadoJuego* atacar(EstadoJuego* partida);
    EstadoJuego* atacar(EstadoJuego* partida, int origen, int destino, int DR1,int DR2, int DR3, int DB1, int DB2,int keyDer,int uAgregar);

    EstadoJuego* mover(EstadoJuego* partida);
    EstadoJuego* mover(EstadoJuego* partida,int origen, int destino,int unidades);

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

    void setTerritorioJugador(Territorio territorio);

};

#endif // JUGADOR_H

