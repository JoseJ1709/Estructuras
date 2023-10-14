//
// Created by jose on 9/10/23.
//

#ifndef ESTRUCTURAS_ESTADOJUEGO_H
#define ESTRUCTURAS_ESTADOJUEGO_H
#include "../Estructura/continente.h"
#include "../Estructura/jugador.h"
#include "../Estructura/tarjeta.h"
#include <list>
#include <string>
#include <iostream>

using namespace std;

class EstadoJuego{
private:
    list<Jugador> jugadores;
    list<Tarjeta> mazo;
    list<Jugador>::iterator iterador_jugadores;
    int tarjetas_global;
public:
    EstadoJuego(){
    };

    int getTarjetasGlobal() const;

    void setTarjetasGlobal(int tarjetasGlobal);

    const list<Tarjeta> &getMazo() const;
    void setMazo(const list<Tarjeta> &mazo);

    void inicializar(list<Territorio>& territoriosDisponibles);
    void turno(int id_jugador,list<Continente> continentes);

    const list<Jugador> &getJugadores() const;

    void setJugadores(list<Jugador> &jugadores);

    const list<Tarjeta> &getmazo() const;

    void setmazo(const list<Tarjeta> &mazo);

    const list<Jugador>::iterator &getIteradorJugadores() const;

    void setIteradorJugadores( list<Jugador>::iterator &iteradorJugadores);

};

#endif //ESTRUCTURAS_ESTADOJUEGO_H
