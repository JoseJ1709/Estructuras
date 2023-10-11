//
// Created by jose on 9/10/23.
//

#include "EstadoJuego.h"

void EstadoJuego::inicializar(list<Territorio>& territoriosDisponibles) {
    int numJugadores;
    string seleccion;
    list<string> colores = {"azul","rojo","verde","amarillo","negro","gris" };
    do {
        cout << "Ingrese el numero de jugadores: " << endl;
        cin >> seleccion;
        numJugadores = stoi(seleccion);
        if(numJugadores>6||numJugadores<3){
            cout<< "numero no valido" << endl;
        }
    }while (numJugadores>6||numJugadores<3);
    string nombre;
    int id;
    string color;
    list<string>::iterator itc = colores.begin();
    for (int i = 0; i < numJugadores; i++) {
        cout << "Ingrese el nombre del jugador " << i+1 << ": ";
        cin >> nombre;
        id=i+1;
        color = *itc;
        Jugador nuevoJugador(nombre,color,id);
        this->jugadores.push_back(nuevoJugador);
        itc++;
    }
    //lista de jugadores creada y lista
    //falta dar territorios
    list<Jugador>::iterator itj = this->jugadores.begin();
    while(!territoriosDisponibles.empty()){
        bool encontrado = false;
        cout << "Territorios disponibles:" << endl;
        for (const Territorio territorio : territoriosDisponibles) {
            cout << territorio.getNombreTerritorio() << endl;
        }
        do{
            cout<<"jugador " <<  itj->getNombreJugador() << "seleccione territorio por nombre" << endl;
            cin >> seleccion;
            for (auto itt = territoriosDisponibles.begin(); itt != territoriosDisponibles.end(); ++itt) {
                if ((*itt).getNombreTerritorio() == seleccion) {
                    itj->getTerritoriosJugador().push_back(*itt);
                    itt=territoriosDisponibles.erase(itt);
                    encontrado = true;
                }
            }
            if(!encontrado)
                cout<< "territorio no encontrado";
        }while(!encontrado);
        cout<<"territorio "<< seleccion << " encontrado" << endl;
        if(itj==this->jugadores.end())
            itj=this->jugadores.begin();
        else
            itj++;
    }
    //falta asignar tropas a esos territorios
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
    int seleccionTropas;
    for(itj=this->jugadores.begin();itj!=this->jugadores.end();itj++){
        int tropasRestantes =infanteriasPorJugador;
        //Darle a todos los territorios del jugador 1 tropa para asegurarse que ninguna queda vacia y calcular las tropas extra
        for(auto itt = itj->getTerritoriosJugador().begin(); itt != itj->getTerritoriosJugador().end();itt++){
            itt->setUnidadesDeEjercitoTerritorio(1);
        }
        tropasRestantes=tropasRestantes - itj->getTerritoriosJugador().size();

        //repartir las tropas extra en los territorios que el jugador elija

        while(tropasRestantes!=0){
            //mostrar territorios del jugador y preguntar en cual se va a poner tropas y mirar si se ingreso un territorio valido

            bool flag=false;
            for(auto itt = itj->getTerritoriosJugador().begin();itt != itj->getTerritoriosJugador().end();itt++){
                cout << itt->getNombreTerritorio() << endl;
            }
            do {
                cout << "le quedan " << tropasRestantes << " tropas restantes, escoja territorio para ingresar tropas" << endl;
                cin >> seleccion;
                for (auto itt = itj->getTerritoriosJugador().begin(); itt != itj->getTerritoriosJugador().end();itt++) {
                    if (itt->getNombreTerritorio()==seleccion)
                        flag = true;
                }
                if(!flag)
                    cout << "territorio no encontrado" << endl;
            } while (!flag);
            //con el territorio valido se pregunta la cantidad de tropas hasta ingresar un valor valido
            flag= false;
            do {
                cout << "cuantas tropas quiere ingresar" << endl;
                cin >> seleccionTropas;
                if((seleccionTropas<=tropasRestantes) && (seleccionTropas>0)){
                    flag=true;
                    for(auto itt = itj->getTerritoriosJugador().begin(); itt != itj->getTerritoriosJugador().end();itt++) {
                        if (itt->getNombreTerritorio() == seleccion) {
                            itt->setUnidadesDeEjercitoTerritorio(itt->getUnidadesDeEjercitoTerritorio() + seleccionTropas);
                            tropasRestantes = tropasRestantes - seleccionTropas;
                            cout << "tropas agregadas al territorio" << endl;
                        }
                    }
                }
            } while (!flag);
        }
    }
}


void EstadoJuego::turno(int id_jugador,list<Continente> continentes) {
    for (Jugador jugador : jugadores) {
        if (jugador.getIdJugador() == id_jugador) {
            jugador.Turno(this,continentes);
            return;
        }
    }
}

const list<Jugador> &EstadoJuego::getJugadores() const {
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

const list<Tarjeta> &EstadoJuego::getMazo() const {
    return mazo;
}

void EstadoJuego::setMazo(const list<Tarjeta> &m) {
    mazo = m;
}

int EstadoJuego::getTarjetasGlobal() const {
    return tarjetas_global;
}

void EstadoJuego::setTarjetasGlobal(int tarjetasGlobal) {
    tarjetas_global = tarjetasGlobal;
}
