//
// Created by jose on 9/10/23.
//

#include "EstadoJuego.h"
#include "../Estructura/territorio.h"
#include "../Estructura/jugador.h"
#include "../Estructura/continente.h"
#include "../Estructura/tarjeta.h"
#include <iostream>
#include <list>
#include "cstdlib"

using namespace std;

void EstadoJuego::inicializar(list<Territorio>& territoriosDisponibles) {


    int numJugadores;
    string seleccion;
    list<string> colores = {"azul", "rojo", "verde", "amarillo", "negro", "gris"};
    do {
        cout << "Ingrese el numero de jugadores: " << endl;
        cin >> seleccion;
        numJugadores = stoi(seleccion);
        if (numJugadores > 6 || numJugadores < 3) {
            cout << "numero no valido" << endl;
        }
    } while (numJugadores > 6 || numJugadores < 3);
    string nombre;
    int id;
    string color;
    list<string>::iterator itc = colores.begin();
    for (int i = 0; i < numJugadores; i++) {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> nombre;
        id = i + 1;
        color = *itc;
        Jugador nuevoJugador(nombre, color, id);
        this->jugadores.push_back(nuevoJugador);
        itc++;
    }
    //lista de jugadores creada y lista
    //falta dar territorios

    int infanteriasPorJugador;
    switch (numJugadores) {
        case 3:
            infanteriasPorJugador = 35;
            break;
        case 4:
            infanteriasPorJugador = 30;
            break;
        case 5:
            infanteriasPorJugador = 25;
            break;
        case 6:
            infanteriasPorJugador = 20;
            break;
    }
    list<string> adyacentes2 = {"p1"};
    list<string> adyacentes1 = {"p2","p4"};
    Territorio aux1 = Territorio(1, 1, "p1", 0);
    aux1.setTerritoriosAlrededor(adyacentes1);
    Territorio aux2 = Territorio(2, 1, "p2", 0);
    aux2.setTerritoriosAlrededor(adyacentes2);
    Territorio aux3 = Territorio(3, 1, "p3", 0);
    Territorio aux4 = Territorio(4, 1, "p4", 0);

    territoriosDisponibles = {};
    territoriosDisponibles.push_back(aux1);
    territoriosDisponibles.push_back(aux2);
    territoriosDisponibles.push_back(aux3);
    territoriosDisponibles.push_back(aux4);


    list<Jugador>::iterator itj = this->jugadores.begin();
    while (!territoriosDisponibles.empty()) {

        bool encontrado = false;
        cout << "Territorios disponibles:" << endl;
        for (const Territorio territorio: territoriosDisponibles) {
            cout << territorio.getNombreTerritorio() << " key: " << territorio.getKeyTerritorio() << endl;
        }
        while (!encontrado) {
            cout << "jugador " << itj->getNombreJugador() << " seleccione territorio por key: " << endl;
            cin >> seleccion;
            int key = stoi(seleccion);
            list<Territorio>::iterator itt;
            for (itt = territoriosDisponibles.begin(); itt != territoriosDisponibles.end(); itt++) {
                if (itt->getKeyTerritorio() == key) {
                    itj->setTerritorioJugador(*itt);
                    itt = territoriosDisponibles.erase(itt);
                    encontrado = true;
                }
            }
            if (!encontrado)
                cout << "territorio no encontrado" << endl;
        };
        cout << "territorio " << seleccion << " encontrado"<<endl;

        list<Jugador>::iterator aux = itj;
        aux++;
        if (aux == this->jugadores.end())
            itj = this->jugadores.begin();
        else
            itj++;
    }


    for (Jugador& jugador : this->jugadores) {


        list<Territorio> territoriosJugador = jugador.getTerritoriosJugador();
        int tropasRestantes = infanteriasPorJugador;
        int seleccionTropas;
        cout<<"Jugador "<< jugador.getNombreJugador()<< endl;
        cout<<"Tus territorios son :" << endl;
        for (Territorio territorio : territoriosJugador) {
            cout<<territorio.getNombreTerritorio();
            cout<<" key: ";
            cout<<territorio.getKeyTerritorio()<<endl;
        }

        for (Territorio& territorio : territoriosJugador) {
            territorio.setUnidadesDeEjercitoTerritorio(1);
            tropasRestantes--;
        }

        while (tropasRestantes > 0) {
            cout << jugador.getNombreJugador() << " le quedan " << tropasRestantes << " tropas restantes" << endl;
            cout << "Escoja territorio por key para ingresar tropas" << endl;
            cin >> seleccion;

            for (Territorio& territorio : territoriosJugador) {
                if (territorio.getKeyTerritorio() == stoi(seleccion)) {
                    cout << "Cuántas tropas quiere ingresar" << endl;
                    cin >> seleccionTropas;
                    if (seleccionTropas <= tropasRestantes && seleccionTropas > 0) {
                        territorio.setUnidadesDeEjercitoTerritorio(
                                territorio.getUnidadesDeEjercitoTerritorio() + seleccionTropas
                        );
                        tropasRestantes -= seleccionTropas;
                        cout << seleccionTropas << " Tropas agregadas al territorio" << endl;
                    } else {
                        cout << "Cantidad de tropas no válida" << endl;
                    }
                }
            }
        }
        jugador.setTerritoriosJugador(territoriosJugador);
        cout << jugador.getNombreJugador() << " termino de poner tropas exitosamente" << endl;
    }
    cout << "inicializacion exitosa" << endl;
}

EstadoJuego* EstadoJuego::turno(int id_jugador,list<Continente> continentes) {
    for (Jugador jugador : jugadores) {
        if (jugador.getIdJugador() == id_jugador) {
            EstadoJuego* juego = new EstadoJuego;
            juego = jugador.Turno(this,continentes);
            return juego;
        }
    }
}

 list<Jugador> EstadoJuego::getJugadores() {
    return jugadores;
}

void EstadoJuego::setJugadores( list<Jugador>& jugadores) {
    this->jugadores = jugadores;
}

const list<Jugador>::iterator &EstadoJuego::getIteradorJugadores() const {
    return iterador_jugadores;
}

void EstadoJuego::setIteradorJugadores( list<Jugador>::iterator &iteradorJugadores) {
    iterador_jugadores = iteradorJugadores;
}

list<Tarjeta> EstadoJuego::getMazo()  {
    return mazo;
}

void EstadoJuego::setMazo( list<Tarjeta> m) {
    mazo = m;
}

int EstadoJuego::getTarjetasGlobal() {
    return tarjetas_global;
}

void EstadoJuego::setTarjetasGlobal(int tarjetasGlobal) {
    tarjetas_global = tarjetasGlobal;
}

EstadoJuego *EstadoJuego::fortificar(string color, int unidades, int key) {
    for (Jugador jugador : jugadores) {
        if (jugador.getColorJugador() == color) {
            EstadoJuego* juego = new EstadoJuego();
            juego = jugador.fortificar(unidades,key,this);
            return juego;
        }
    }
}

EstadoJuego *EstadoJuego::atacar(string color, int origen, int destino, int DR1, int DR2, int DR3, int DB1, int DB2) {
    for (Jugador jugador : jugadores) {
        if (jugador.getColorJugador() == color) {
            EstadoJuego* juego = new EstadoJuego();
            juego = jugador.atacar(this,origen,destino,DR1,DR2,DR3,DB1,DB2,0,0);
            return juego;
        }
    }
}
EstadoJuego *EstadoJuego::atacar(string color, int origen, int destino, int DR1, int DR2, int DR3, int DB1, int DB2,int keyDer,int uAgregar) {
    for (Jugador jugador : jugadores) {
        if (jugador.getColorJugador() == color) {
            EstadoJuego* juego = new EstadoJuego();
            juego = jugador.atacar(this,origen,destino,DR1,DR2,DR3,DB1,DB2,keyDer,uAgregar);
            return juego;
        }
    }
}

EstadoJuego *EstadoJuego::mover(string color, int origen, int destino, int unidades) {
    for (Jugador jugador : jugadores) {
        if (jugador.getColorJugador() == color) {
            EstadoJuego* juego = new EstadoJuego();
            juego = jugador.mover(this,origen,destino,unidades);
            return juego;
        }
    }
}
