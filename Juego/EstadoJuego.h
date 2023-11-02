    //
// Created by jose on 9/10/23.
//

#ifndef ESTRUCTURAS_ESTADOJUEGO_H
#define ESTRUCTURAS_ESTADOJUEGO_H

#include <list>
#include <string>
#include <iostream>
#include "../Estructura/continente.h"
#include "../Estructura/jugador.h"
#include "../Estructura/tarjeta.h"


using namespace std;

class EstadoJuego{
private:
    list<Jugador> jugadores;
    list<Tarjeta> mazo;
    list<Jugador>::iterator iterador_jugadores;
    int tarjetas_global;
public:
    EstadoJuego(){};

    int getTarjetasGlobal();

    void setTarjetasGlobal(int tarjetasGlobal);

    list<Tarjeta> getMazo();
    void setMazo(list<Tarjeta> mazo);

    void inicializar(list<Territorio>& territoriosDisponibles);
    EstadoJuego* turno(int id_jugador,list<Continente> continentes);

     list<Jugador> getJugadores();

    void setJugadores(list<Jugador> &jugadores);

    const list<Jugador>::iterator &getIteradorJugadores() const;

    void setIteradorJugadores( list<Jugador>::iterator &iteradorJugadores);

};

#endif //ESTRUCTURAS_ESTADOJUEGO_H
