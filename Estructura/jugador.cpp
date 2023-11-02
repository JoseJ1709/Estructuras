/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/


#include <iostream>
#include <list>
#include <string>
#include "jugador.h"
#include "continente.h"
#include "tarjeta.h"
#include "../Juego/Dado.h"
#include "../Juego/EstadoJuego.h"

using namespace std;

Jugador::Jugador(){}
Jugador::Jugador(string n, string c, int id) {
  nombre_jugador = n;
  color_jugador = c;
  id_jugador = id;
}

//Consola//

EstadoJuego* Jugador::Turno(EstadoJuego* partida, list<Continente> continentes) {
    partida = fortificar( continentes , partida);
    cout << partida->getJugadores().front().getTerritoriosJugador().front().getUnidadesDeEjercitoTerritorio() << endl;
    partida = atacar(partida);
    cout << partida->getJugadores().front().getTerritoriosJugador().front().getUnidadesDeEjercitoTerritorio() << endl;
    partida = mover(partida);
    cout << partida->getJugadores().front().getTerritoriosJugador().front().getUnidadesDeEjercitoTerritorio() << endl;
    return partida;
}


int calcularUnidadesFortificar(int tarjetas_global) {
    int unidades_a_sumar = 0;

    if (tarjetas_global > 7) {
        tarjetas_global = 7;
    }

    switch (tarjetas_global) {
        case 1:
            unidades_a_sumar = 4;
            break;
        case 2:
            unidades_a_sumar = 6;
            break;
        case 3:
            unidades_a_sumar = 8;
            break;
        case 4:
            unidades_a_sumar = 10;
            break;
        case 5:
            unidades_a_sumar = 12;
            break;
        case 6:
            unidades_a_sumar = 15;
            break;
        case 7:
            for (int j = 1; j <= 6; ++j) {
                unidades_a_sumar += 5;
            }
            break;
        default:
            break;
    }

    return unidades_a_sumar;
}

EstadoJuego* Jugador::fortificar(list<Continente> continentes, EstadoJuego* partida ) {
    int opcion= 0;
    int unidades_fortifciar = territorios_jugador.size() / 3;
    string tipos_tarjeta[4] = {"Soldier", "Horse", "Canon", "comodin"};
    int contador[4] = {0, 0, 0, 0};
    int sum;
    bool ver = false;
    bool Comb1 = false;
    bool Comb2 = false;
    bool Comb3 = false;
    cout << "fortificando" << "\n";

    //-----verificacion de otras unidades------ //
    //verificaion de Tarjetas//

    //mirar cuantas tarjetas de que tipo tengo - clasificas //

    for ( Tarjeta tarjeta: tarjetas_jugador) {
        for (int i = 0; i < 4; i++) {
            if (tarjeta.getDibujo() == tipos_tarjeta[i]) {
                contador[i]++;
                break;
            }
        }
    }

    // imprimir # de cartas que tiene el usuario //

    cout<<"----Revisando tarjetas de jugador----"<<"\n";
    cout<<""<< "\n";
    for (int i = 0; i <3 ; ++i) {
        if(contador[i] > 0){
            cout<< "Tienes " << contador[i] << " tarjetas de " << tipos_tarjeta[i]<<"\n";
        }
    }

    //revisar que combinaciones tiene //


    //revisar si tiene tres cartas del mismo dibujo //
    for (int i = 0; i < 2; ++i) {
        if(contador[i] >= 3){
            cout<<"tienes una combinacion de 3 cartas del mismo dibujo"<< "\n";
            Comb1 = true;
        }
    }
    //revisar si tiene tres cartas de distito dibujo //

    if(contador[0] >=1 &&contador[1] >=1 && contador[2] >=1){
        cout<<"tienes una combinacion de 3 cartas del mismo dibujo"<< "\n";
        Comb2 = true;
    }
    //revisar si tiene dos cartas de distinto dibujo y un comodin //

    if (contador[3] >= 1 && ((contador[0] >= 1 && (contador[1] >= 1 || contador[2] >= 1)) || (contador[1] >= 1 && (contador[0] >= 1 || contador[2] >= 1)) || (contador[2] >= 1 && (contador[0] >= 1 || contador[1] >= 1)))) {
        cout << "Tienes una combinación de dos cartas de distinto dibujo y un comodín" << endl;
        Comb3 = true;
    }

    if (Comb1 == true || Comb2 == true || Comb3 == true) {
        do {
            cout << "Escoge una ocpion segun tus combinaciones"<< "\n";
            cout << "'1' tres cartas con mismo dibujo " << "\n";
            cout << "'2' tres cartas con distinto dibujo " << "\n";
            cout << "'3' dos cartas con distinto dibujo y un comodin" << "\n";
            cout << "'4' no quiero intercambiar tarjetas"<< "\n";
            cin >> opcion;
            //verificar que pueda realizar la opcion escogida || si si, borras lo pedido en la opcion //
            //tres cartas con el mismo dibujo //
            if (opcion == 1) {
                for (int i = 0; i < 3; ++i) {
                    if (contador[i] >= 3) {
                        cout << "Intercambiando tarjetas por unidades" << "\n";
                        //borrar trio de tarjetas //
                        bool intercambio_completado = false;
                        int este = 0;
                        for (int i = 0; i < 2; ++i) {
                            este = contador[i];
                            if (este >= 3) {
                                este = i;
                                break;
                            }
                        }
                        //ya sabemos el tipo de tarjeta que vamos a borrar ahora vamos a buscar en el usuario ese tipo y mirar si esa tarjeta la tiene
                        for (auto it = tarjetas_jugador.begin(); it != tarjetas_jugador.end();) {
                            int i;
                            //encontramos una tarjeta del mismo tipo //
                            if ((*it).getDibujo() == tipos_tarjeta[este]) {
                                // Verificar si el jugador tiene el territorio de la tarjeta.
                                for (const Territorio territorio: territorios_jugador) {
                                    if ((*it).getKeyTerritorio() == territorio.getKeyTerritorio()) {
                                        unidades_fortifciar += 2;
                                        cout<<"Tienes el mismo terriotorio de la tarjeta" <<"\n";
                                    }
                                }
                                // Borrar la tarjeta y obtener el siguiente iterador.
                                Tarjeta tarjetaActual = *it;
                                it = tarjetas_jugador.erase(it);
                                list<Tarjeta> mazo = partida->getMazo();
                                mazo.push_back(tarjetaActual);
                                partida->setMazo(mazo);
                                i++;
                                // Comprobar si hemos encontrado suficientes tarjetas coincidentes.
                                if (i >= 3) {
                                    int unidades_sumar = calcularUnidadesFortificar(partida->getTarjetasGlobal());
                                    unidades_fortifciar += unidades_sumar;
                                    cout<< "se sumaron " << unidades_sumar<<" unidades";
                                    partida->setTarjetasGlobal(partida->getTarjetasGlobal()+1);
                                    ver = true;
                                    cout << "unidades intercambiadas con exito" << "\n";
                                    opcion = 4;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if (opcion == 2) {
                // las 3 tarjetas distintas //
                if (contador[0] > 0 && contador[1] > 0 && contador[2] > 0) {
                    cout << "Intercambiando tarjetas por unidades" << "\n";
                    //borrar una tarjeta de cada tipo
                    bool intercambio_completado = false;

                    for (int i = 0; i < 2; ++i) {
                        //ya sabemos el tipo de tarjeta que vamos a borrar ahora vamos a buscar en el usuario ese tipo y mirar si esa tarjeta la tiene
                        for (auto it = tarjetas_jugador.begin(); it != tarjetas_jugador.end();) {
                            int i;
                            //encontramos una tarjeta del mismo tipo //
                            if ((*it).getDibujo() == tipos_tarjeta[i]) {
                                string nomTerr;
                                // Verificar si el jugador tiene el territorio de la tarjeta.
                                for (const Territorio territorio: territorios_jugador) {

                                    if ((*it).getKeyTerritorio() == territorio.getKeyTerritorio()) {
                                        unidades_fortifciar += 2;
                                        cout<<"Tienes el mismo terriotorio de la tarjeta" <<"\n";
                                    }
                                }
                                // Borrar la tarjeta y obtener el siguiente iterador.
                                Tarjeta tarjetaActual = *it;
                                it = tarjetas_jugador.erase(it);
                                list<Tarjeta> mazo = partida->getMazo();
                                mazo.push_back(tarjetaActual);
                                partida->setMazo(mazo);

                                break; // Salir del bucle ya que hemos borrado una
                            }
                        }
                    }
                    int unidades_sumar = calcularUnidadesFortificar(partida->getTarjetasGlobal());
                    unidades_fortifciar += unidades_sumar;
                    cout<< "se sumaron " << unidades_sumar<<" unidades";
                    partida->setTarjetasGlobal(partida->getTarjetasGlobal()+1);;
                    ver = true;
                    opcion = 4;
                    cout << "unidades intercambiadas con exito" << "\n";
                    break;
                }
            }
            if (opcion == 3) {
                //dos tarjetas distintas y un comodin
                if ((contador[0] > 1 && contador[1] > 1) || (contador[0] > 1 && contador[2] > 1) ||(contador[1] > 1 && contador[2] > 1) && contador[3] > 0) {
                    cout << "Intercambiando tarjetas por unidades" << "\n";
                    //borrar 2 tarjetas de distinto tipo //
                    int t = 0;
                    for (int i = 0; i < 2; ++i) {
                        //ya sabemos el tipo de tarjeta que vamos a borrar ahora vamos a buscar en el usuario ese tipo y mirar si esa tarjeta la tiene
                        for (auto it = tarjetas_jugador.begin(); it != tarjetas_jugador.end();) {
                            int i;
                            //encontramos una tarjeta del mismo tipo //
                            if ((*it).getDibujo() == tipos_tarjeta[i]) {
                                // Verificar si el jugador tiene el territorio de la tarjeta.
                                for (const Territorio territorio: territorios_jugador) {
                                    if ((*it).getKeyTerritorio() == territorio.getKeyTerritorio()) {
                                        unidades_fortifciar += 2;
                                        cout<<"Tienes el mismo terriotorio de la tarjeta" <<"\n";
                                    }
                                }
                                // Borrar la tarjeta y obtener el siguiente iterador.
                                Tarjeta tarjetaActual = *it;
                                it = tarjetas_jugador.erase(it);
                                list<Tarjeta> mazo = partida->getMazo();
                                mazo.push_back(tarjetaActual);
                                partida->setMazo(mazo);
                                t++;
                                break; // Salir del bucle ya que hemos borrado una
                            }
                        }
                        if (t >= 2) {
                            int unidades_sumar = calcularUnidadesFortificar(partida->getTarjetasGlobal());
                            unidades_fortifciar += unidades_sumar;
                            cout<< "se sumaron " << unidades_sumar<<" unidades";
                            partida->setTarjetasGlobal(partida->getTarjetasGlobal()+1);;
                            ver = true;
                            opcion = 4;
                            cout << "unidades intercambiadas con exito" << "\n";
                            break;
                        }
                    }
                }
            }
            if (opcion != 4 && opcion != 3 && opcion != 2 && opcion != 1) {
                cout << "opcion erronea, intente otra vez" << "\n";
            }
        } while (opcion != 4);
    } else{
        cout<<"no tienes combinaciones de tarjetas"<< "\n";
    }

    //verificacion de continentes//

    int territoriosXcontinente[6] ={0,0,0,0,0,0};
    bool territoriocupado = false;
    int KTerritorio;
    int unidadesAñadir;
    bool esValido = false;

    cout<<"----Revisando territorios de jugador----"<<"\n";
    cout<<""<< "\n";

    // Iterar sobre la lista de territorios del jugador para mirar cuantos territorios de un continente tiene
    for (Territorio territorio : territorios_jugador) {
        int continente = territorio.getIdContinente();
        switch (continente) {
            case 1 : //americaN//
                territoriosXcontinente[0]++;
                break;
            case 2 : //Europa//
                territoriosXcontinente[1]++;
                break;
            case 3 : //Asia//
                territoriosXcontinente[2]++;
                break;
            case 4 : //africa//
                territoriosXcontinente[3]++;
                break;
            case 5 : //americaS//
                territoriosXcontinente[4]++;
                break;
            case 6 : //australia//
                territoriosXcontinente[5]++;
                break;
            default:
                break;
        }
    }
    //mirar si el tamaño del continente[1] es igual que el numero de la lista del jugador en [1] que deberia ser 9

    for (const Continente continente : continentes ) {
        for (int i = 0; i < 5; i++) {
            if (territoriosXcontinente[i] == continente.getNumContinente()) {
                switch (continente.getNumContinente()) {
                    case 9 : //americaN//
                        unidades_fortifciar += 5;
                        territoriocupado = true;
                        cout << "Territorio America Norte ocupado.  +5 unidades"<<"\n";
                        break;
                    case 7 : //Europa//
                        territoriocupado = true;
                        unidades_fortifciar += 5;
                        cout << "Territorio Europa ocupado. +5 unidades"<<"\n";
                        break;
                    case 12 : //Asia//
                        territoriocupado = true;
                        unidades_fortifciar += 7;
                        cout << "Territorio Asia ocupado. +7 unidades"<<"\n";
                        break;
                    case 6 : //africa//
                        territoriocupado = true;
                        unidades_fortifciar += 3;
                        cout << "Territorio Africa ocupado. +3 unidades"<<"\n";
                        break;
                    case 4 : //americaS - australia//
                        territoriocupado = true;
                        unidades_fortifciar += 2;
                        break;
                }
            }
        }
    }
    if (territoriocupado = false){
        cout << "no tiene ningun continente ocupado "<<"\n";
    }
    cout<<""<< "\n";

    //-----seleccionar territorios al cual añadir----//
    //mostrar territorios //
    cout << "Territorios de " << nombre_jugador << ":" <<"\n";
    for (Territorio territorio : territorios_jugador) {
        cout << " - " << territorio.getNombreTerritorio() <<" key : "<<territorio.getKeyTerritorio() <<" tiene :" << territorio.getUnidadesDeEjercitoTerritorio() << " unidades" <<"\n";
    }

    //seleccionar y añaidir unidades a territorios //
    while (unidades_fortifciar > 0) {
        cout << "Usted tiene : " << unidades_fortifciar << " unidades para fortificar sus territorios, presiona enter para continuar" << endl;
        do {

            cout << "Dame la Key del territorio al que quieres fortificar" << endl;
            cin>>KTerritorio;

            for (Territorio &territorio : territorios_jugador) {
                if (territorio.getKeyTerritorio() == KTerritorio) {
                    esValido = true;
                    break;
                }
            }

            if (!esValido) {
                cout << "Key de territorio no válido. Intente nuevamente." << endl;
            }
        } while (!esValido);
        esValido = false;
        do {
            cout << "Dame la cantidad de unidades que le quieres añadir ";
            cin >> unidadesAñadir;
            if (unidadesAñadir <= unidades_fortifciar) {
                esValido= true;
                for (Territorio &territorio : territorios_jugador) {
                    if (KTerritorio == territorio.getKeyTerritorio()) {
                        territorio.setUnidadesDeEjercitoTerritorio(territorio.getUnidadesDeEjercitoTerritorio() + unidadesAñadir);
                        unidades_fortifciar -= unidadesAñadir;
                        cout << "Fortificación exitosa. " << territorio.getNombreTerritorio() << " ahora tiene " << territorio.getUnidadesDeEjercitoTerritorio() << " unidades." << endl;
                        break;
                    }
                }
            }
            if (!esValido) {
                cout << "Cantidad de unidades inválida. Intente nuevamente." << endl;
            }
        } while (!esValido);
    }
    cout << "Fortificación terminada" << endl;
    cout<<""<< "\n";
    list<Jugador> aux2 = partida->getJugadores();
    for(auto it =aux2.begin();it!=aux2.end();it++){
        if(it->getNombreJugador()== this->getNombreJugador()){
            *it = *this;
        }
    }
    partida->setJugadores(aux2);
    return partida;
}
EstadoJuego* Jugador::fortificar(int unidades, int keyT, EstadoJuego *partida) {

    list<Territorio> aux = this->getTerritoriosJugador();
    for(auto it = aux.begin() ; it!=aux.end();it++){
        if(it->getKeyTerritorio()== keyT){
            Territorio auxt = *it;
            auxt.setUnidadesDeEjercitoTerritorio(auxt.getUnidadesDeEjercitoTerritorio() + unidades);
            *it = auxt;
            cout << "OUD succesful" << endl;
        }
    }
    this->setTerritoriosJugador(aux);
    list<Jugador> aux2 = partida->getJugadores();
    for(auto it =aux2.begin();it!=aux2.end();it++){
        string nombre = this->getNombreJugador();
        if(it->getNombreJugador()== nombre){
            *it = *this;
        }
    }
    partida->setJugadores(aux2);
    return partida;
}

EstadoJuego* Jugador::atacar(EstadoJuego* partida) {
    cout<<"atacando"<< "\n";
    cout<<"" << "\n";

    cout << "Territorios disponibles:" << endl;
    for(Territorio it : this->getTerritoriosJugador()){
        cout << it.getNombreTerritorio() << " key: " << it.getKeyTerritorio() << endl;
    }
    string seleccion;
    bool flag = false;
    string territorioAtacante;
    string territorioVictima;
    do {
        int key;
        cout << "Ingrese territorio con el que desea atacar:";
        cin >> key;
        for(auto it : this->getTerritoriosJugador()){
            if(it.getKeyTerritorio() == key){
                cout << "Territorio encontrado" << endl;
                if(it.getUnidadesDeEjercitoTerritorio()>1){
                    cout << "Territorio valido" << endl;
                    list<string> territoriosAtacables;
                    bool flag2;
                    list<string> aux = it.getTerritoriosAlrededor();
                    for(string it2:aux){
                        flag2=true;
                        for(auto it3:this->getTerritoriosJugador()){
                            if(it2==it3.getNombreTerritorio())
                                flag2=false;
                        }
                        if (flag2) {
                            territoriosAtacables.push_front(it2);
                        }
                    }
                    if(!territoriosAtacables.empty()){
                        cout << "Desde " << it.getNombreTerritorio() << " se pueden atacar estos territorios:" << endl;
                        for(string it2:territoriosAtacables)
                            cout << it2 << endl;
                        do{
                            flag2= false;
                            cout << "Seleccione nombre de territorio que desea atacar ";
                            getline(cin,seleccion);
                            for(string it2:territoriosAtacables)
                                if(seleccion==it2){
                                    flag2=true;
                                    cout << "se va a atacar al territorio " << it2 << endl;
                                }
                            if(!flag2){
                                cout << " " << seleccion << " " << " no es un territorio atacable" << endl;
                            }
                        }while(!flag2);
                        flag= true;
                        territorioAtacante = it.getNombreTerritorio();
                        territorioVictima = seleccion;
                    }else{
                        cout<< "No hay territorios disponibles para atacar desde esta posicion" << endl;
                    }
                }else{
                    cout << "El territorio no cuenta con suficientes tropas"<< endl;
                }
            }
        }
    }while(!flag);


    //se tienen los nombres del territorio atacante y victima
    do{
        list<int> dadosAtacante;
        list<int> dadosDefensa;
        for (int i = 0; i < 3; i++)
            dadosAtacante.push_front(Dado::LanzarDado());
        for (int i = 0; i < 2; i++)
            dadosDefensa.push_front(Dado::LanzarDado());
        dadosAtacante.sort(greater<int>());
        dadosDefensa.sort(greater<int>());
        cout << "dados del atacante: " << endl;
        for (auto itA = dadosAtacante.begin(); itA != dadosAtacante.end(); itA++)
            cout << *itA << endl;
        cout << "dados del defensor" << endl;
        for (auto itD = dadosDefensa.begin(); itD != dadosDefensa.end(); itD++)
            cout << *itD << endl;


        auto itA = dadosAtacante.begin();
        auto itD = dadosDefensa.begin();
        int restarAtacante = 0;
        int restarDefensor = 0;
        for(int i = 0 ; i < 2; i++,itA++,itD++) {
            if (*itA > *itD) {
                restarDefensor++;
            } else if( *itA <= *itD){
                restarAtacante++;
            }
        }


        flag = true;
        bool flag2 = false;
        int restantes;
        int tropas = 0;
        //quitar tropas al atacante
        list<Territorio> aux = this->getTerritoriosJugador();
        for(auto it=aux.begin(); it != aux.end(); it++) {
            if (territorioAtacante == it->getNombreTerritorio()) {
                if (it->getUnidadesDeEjercitoTerritorio() - restarAtacante <= 1) {
                    it->setUnidadesDeEjercitoTerritorio(1);
                    cout << "el atacante no tiene tropas suficientes para seguir atacando" << endl;
                    flag = false;
                }else
                    it->setUnidadesDeEjercitoTerritorio(it->getUnidadesDeEjercitoTerritorio() - restarAtacante);
                restantes=it->getUnidadesDeEjercitoTerritorio();
            }
        }
        this->setTerritoriosJugador(aux);
        list<Jugador> aux2 = partida->getJugadores();
        for(auto it =aux2.begin();it!=aux2.end();it++){
            string nombre = this->getNombreJugador();
            if(it->getNombreJugador()== nombre){
                *it = *this;
            }
        }
        partida->setJugadores(aux2);

        //quitar tropas al defensor
        list<Jugador> jugadores = partida->getJugadores();
        for(auto it=jugadores.begin();it!=jugadores.end();it++){
            list<Territorio> aux = it->territorios_jugador;
            for(auto itt=aux.begin();itt!=aux.end();itt++) {
                if (territorioVictima == itt->getNombreTerritorio()) {
                    if (itt->getUnidadesDeEjercitoTerritorio() - restarDefensor <= 0) {
                        flag= false;
                        cout<< "el territorio defensor se ha quedado sin tropas !!!" << endl;
                        cout << "al territorio atacante tiene " << restantes-1 << " tropas que puede poner en el territorio conquistado" << endl;
                        do{
                            cout << "ingrese tropas para ingresar en el territorio conquistado" << endl;
                            cin >> tropas;
                            if (tropas>=1 && tropas <=restantes-1){
                                flag2= true;
                            }else
                                cout << "valor no valido" << endl;
                        }while(!flag2);
                        Territorio defensor = *itt;
                        defensor.setUnidadesDeEjercitoTerritorio(tropas);

                        list<Territorio> territoriosAux = this->getTerritoriosJugador();
                        territoriosAux.push_back(defensor);
                        this->setTerritoriosJugador(territoriosAux);

                        list<Territorio> territoriosAux2 = it->getTerritoriosJugador();
                        itt = territoriosAux2.erase(itt);
                        it->setTerritoriosJugador(territoriosAux2);
                        //dar tarjeta
                        list<Tarjeta> mazo = partida->getMazo();
                        list<Tarjeta>::iterator itT = mazo.begin();
                        Tarjeta tarjetaObtenida = *itT;
                        tarjetas_jugador.push_back(tarjetaObtenida);
                        mazo.pop_front();
                        partida->setMazo(mazo);

                        list<Jugador> aux2 = partida->getJugadores();
                        for(auto it3 =aux2.begin();it3!=aux2.end();it3++){
                            string nombre = this->getNombreJugador();
                            if(it3->getNombreJugador()== nombre){
                                *it3 = *this;
                            }
                        }
                        partida->setJugadores(aux2);
                        cout << "tarjeta entregada" << endl;
                    }else{
                        Territorio defensor = *itt;
                        defensor.setUnidadesDeEjercitoTerritorio(defensor.getUnidadesDeEjercitoTerritorio() - restarDefensor);
                        *itt = defensor;
                    }
                }
            }

            it->setTerritoriosJugador(aux);
            list<Jugador> aux2 = partida->getJugadores();
            for(auto it1 =aux2.begin();it1!=aux2.end();it1++){
                string nombre = it->getNombreJugador();
                if(it1->getNombreJugador()== nombre){
                    Jugador pointer = *it;
                    *it1 = pointer;
                }
            }
            partida->setJugadores(aux2);
        }

        if(flag){
            int decision;
            bool flag4 = true;
            do{
                cout << "Quiere seguir atacando? (1 = si, 0 = no" << endl;
                cin >> decision;
                if(decision == 1 || decision == 0){
                    flag4 = false;
                    cout << "respuesta valida" << endl;
                }
            }while(flag4);
            if(decision == 1){
                flag = true;
            }else if(decision == 0){
                flag = false;
            }
        }
    }while(flag);
    cout << "Ataque terminado" << endl;
    return partida;
}
EstadoJuego* Jugador::atacar(EstadoJuego *partida, int origen, int destino, int DR1, int DR2, int DR3, int DB1,
                             int DB2,int keyDer, int uAgregar) {
    int territorioAtacante = origen;
    int territorioVictima = destino;
    list<int> dadosA = { DR1,DR2,DR3};
    list<int> dadosD = { DB1,DB2};
    dadosA.sort(greater<int>());
    dadosD.sort(greater<int>());
    auto itA = dadosA.begin();
    auto itD = dadosD.begin();
    int restarAtacante = 0;
    int restarDefensor = 0;
    for(int i = 0 ; i < 2; i++,itA++,itD++) {
        if (*itA > *itD) {
            restarDefensor++;
        } else if( *itA <= *itD){
            restarAtacante++;
        }
    }
    //quitar al atacante
    bool flag2 = false;
    int restantes;
    int tropas = 0;
    Territorio atacante;
    //quitar tropas al atacante
    list<Territorio> aux = this->getTerritoriosJugador();
    for(auto it=aux.begin(); it != aux.end(); it++) {
        if (territorioAtacante == it->getKeyTerritorio()) {
            atacante = *it;
            if (it->getUnidadesDeEjercitoTerritorio() - restarAtacante <= 1) {
                it->setUnidadesDeEjercitoTerritorio(1);
            }else
                it->setUnidadesDeEjercitoTerritorio(it->getUnidadesDeEjercitoTerritorio() - restarAtacante);
            restantes=it->getUnidadesDeEjercitoTerritorio();
        }
    }
    this->setTerritoriosJugador(aux);
    list<Jugador> aux2 = partida->getJugadores();
    for(auto it =aux2.begin();it!=aux2.end();it++){
        string nombre = this->getNombreJugador();
        if(it->getNombreJugador()== nombre){
            *it = *this;
        }
    }
    partida->setJugadores(aux2);
    //quitar defensor
    list<Jugador> jugadores = partida->getJugadores();
    for(auto it=jugadores.begin();it!=jugadores.end();it++){
        list<Territorio> aux = it->territorios_jugador;
        for(auto itt=aux.begin();itt!=aux.end();itt++) {
            if (territorioVictima == itt->getKeyTerritorio()) {
                if (itt->getUnidadesDeEjercitoTerritorio() - restarDefensor <= 0) {
                    list<Territorio > aux3 = this->getTerritoriosJugador();
                    for(auto it2 = aux3.begin();it2!= aux3.end();it2++){
                        if(it2->getKeyTerritorio() == atacante.getKeyTerritorio()){
                            atacante.setUnidadesDeEjercitoTerritorio(atacante.getUnidadesDeEjercitoTerritorio()  - uAgregar);
                            *it2 = atacante;
                        }
                    }
                    this->setTerritoriosJugador(aux3);

                    tropas = uAgregar;
                    Territorio defensor = *itt;
                    defensor.setUnidadesDeEjercitoTerritorio(tropas);

                    list<Territorio> territoriosAux = this->getTerritoriosJugador();
                    territoriosAux.push_back(defensor);
                    this->setTerritoriosJugador(territoriosAux);

                    list<Territorio> territoriosAux2 = it->getTerritoriosJugador();
                    itt = territoriosAux2.erase(itt);
                    it->setTerritoriosJugador(territoriosAux2);

                    list<Jugador> aux2 = partida->getJugadores();
                    for(auto it3 =aux2.begin();it3!=aux2.end();it3++){
                        string nombre = this->getNombreJugador();
                        if(it3->getNombreJugador()== nombre){
                            *it3 = *this;
                        }
                    }
                    partida->setJugadores(aux2);

                }else{
                    Territorio defensor = *itt;
                    defensor.setUnidadesDeEjercitoTerritorio(defensor.getUnidadesDeEjercitoTerritorio() - restarDefensor);
                    *itt = defensor;
                }
                it->setTerritoriosJugador(aux);
                list<Jugador> aux3 = partida->getJugadores();
                for(auto it1 =aux3.begin();it1!=aux3.end();it1++){
                    string nombre = it->getNombreJugador();
                    if(it1->getNombreJugador()== nombre){
                        *it1 = *it;
                    }
                }
                partida->setJugadores(aux3);
            }
        }
    }

    cout << "ATK succesful" << endl;
    return partida;
}

EstadoJuego* Jugador::mover(EstadoJuego* partida) {
    cout<<"moviendo"<< "\n";
    cout<<"" << "\n";

    bool Valido = false;
    bool Valido2 = false;
    bool Valido3 = false;
    bool adyacente = true;
    int  territorio_obtener;
    int territorio_poner;
    int unidades_mover;
    int suma =0 ;
    int tamaño = territorios_jugador.size();

    for (Territorio territorio: territorios_jugador) {
        suma = suma + territorio.getUnidadesDeEjercitoTerritorio();
    }
    if(suma>tamaño){
        string nombreT;
        cout << "Territorios disponibles:" << "\n";
        for (Territorio it: this->getTerritoriosJugador()) {
            cout << it.getNombreTerritorio() << " : " <<"key "<<it.getKeyTerritorio()<<" : "<< it.getUnidadesDeEjercitoTerritorio() << "unidades" << "\n";
        }

        do {
            cout << "selecciona desde donde quieres mover unidades" << "\n";
            cin>> territorio_obtener;

            for (auto it = territorios_jugador.begin(); it != territorios_jugador.end(); ++it) {

                Territorio& territorio = *it;
                if (territorio.getKeyTerritorio() == territorio_obtener) {
                    cout<<"Territorios adyacentes a "<< territorio.getNombreTerritorio() << "\n";
                    for (string adyacente :territorio.getTerritoriosAlrededor()) {
                        cout<< adyacente ;
                        for (Territorio territorio: territorios_jugador) {
                            if (territorio.getNombreTerritorio() == adyacente) {
                                cout<< " key :" <<territorio.getKeyTerritorio();
                            }
                        }
                        cout<< "\n";
                    }
                    cout << "Seleccione territorio al que desea mover unidades" << "\n";
                    cin >>territorio_poner;

                    //verificamos que tenemos ese territorio //
                    for (Territorio territorio: territorios_jugador) {
                        if (territorio.getKeyTerritorio() == territorio_poner) {
                            Valido2 = true;
                            nombreT= territorio.getNombreTerritorio();
                            cout << "Territorio valido"<< "\n";
                        }
                    }
                    do {
                        cout << "dime cuantas unidades de " << territorio.getUnidadesDeEjercitoTerritorio()-1
                             << " quieres mover" << "\n";
                        cin >> unidades_mover;

                        if (unidades_mover >= territorio.getUnidadesDeEjercitoTerritorio()) {
                            cout << "unidades no aceptadas, intenta otra vez" << "\n";
                            Valido = false;
                        } else {
                            Valido = true;
                            territorio.setUnidadesDeEjercitoTerritorio(territorio.getUnidadesDeEjercitoTerritorio() - unidades_mover);
                            cout << "unidades de " << territorio.getNombreTerritorio() << " son " << territorio.getUnidadesDeEjercitoTerritorio() << "\n";
                        }
                    } while (!Valido);
                }
            }
            if (!Valido){
                cout<<"territorio no encontrado" << "\n";
            }
        } while (!Valido);
        do {
            if (Valido2 == true) {
                cout << "revisando si es adyacente "<< "\n";
                for (Territorio territorio: territorios_jugador) {
                    if (territorio.getKeyTerritorio() == territorio_obtener) {
                        for (string adyacente: territorio.getTerritoriosAlrededor()) {
                            if (adyacente == nombreT) {
                                for (Territorio &territorio: territorios_jugador) {
                                    if (territorio_poner == territorio.getKeyTerritorio()) {
                                        territorio.setUnidadesDeEjercitoTerritorio(territorio.getUnidadesDeEjercitoTerritorio() + unidades_mover);
                                        cout<<"territorio adyacente"<< "\n";
                                        Valido3 = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!Valido2){
                cout<<"no se encontro el territorio"<< "\n";
            }
            if(!Valido3){
                cout<<"el territorio no es adyacente"<< "\n";
            }
        } while (!Valido3);
    } else{
        cout<<"no puedes mover unidades"<< "\n";
    }
    list<Jugador> aux2 = partida->getJugadores();
    for(auto it =aux2.begin();it!=aux2.end();it++){
        if(it->getNombreJugador()== this->getNombreJugador()){
            *it = *this;
        }
    }
    partida->setJugadores(aux2);
    return partida;
}

EstadoJuego* Jugador::mover(EstadoJuego* partida, int origen, int destino, int unidades){
    list<Territorio> aux = this->getTerritoriosJugador();
    for(auto it = aux.begin() ; it!= aux.end();it++){
        if(it->getKeyTerritorio()== origen){
            list<string> adyacentes = it->getTerritoriosAlrededor();
            Territorio Quitar = *it;
            Quitar.setUnidadesDeEjercitoTerritorio(Quitar.getUnidadesDeEjercitoTerritorio() - unidades);
            *it = Quitar;
            for(auto itA : adyacentes){

                this->setTerritoriosJugador(aux);
                list<Territorio> aux2 = this->getTerritoriosJugador();
                for(auto it2 = aux2.begin() ; it2!= aux2.end();it2++){
                    if(it2->getNombreTerritorio() == itA && it2->getKeyTerritorio() == destino){
                        Territorio Agregar = *it2;
                        Agregar.setUnidadesDeEjercitoTerritorio(Agregar.getUnidadesDeEjercitoTerritorio() + unidades);
                        *it2 = Agregar;

                        this->setTerritoriosJugador(aux2);

                        list<Jugador> aux3 = partida->getJugadores();
                        for(auto it3 =aux3.begin();it3!=aux3.end();it3++){
                            if(it3->getNombreJugador()== this->getNombreJugador()){
                                *it3 = *this;
                            }
                        }
                        partida->setJugadores(aux3);
                        cout << "FRT succesful" << endl;
                        return partida;
                    }
                }
            }
            Quitar.setUnidadesDeEjercitoTerritorio(Quitar.getUnidadesDeEjercitoTerritorio() - unidades);
            *it = Quitar;
            cout << "el territorio destino no es adyacente al origen o no le pertenece al jugador" << endl;
        }
    }

    cout << "FRT not succesful" << endl;
    return partida;
}
string Jugador::getNombreJugador() {
    return nombre_jugador;
}

void Jugador::setNombreJugador( string &nombreJugador) {
    nombre_jugador = nombreJugador;
}

const int &Jugador::getIdJugador() {
    return id_jugador;
}

void Jugador::setIdJugador(int &idJugador) {
    id_jugador = idJugador;
}

const string &Jugador::getColorJugador() {
    return color_jugador;
}

void Jugador::setColorJugador( string &colorJugador) {
    color_jugador = colorJugador;
}

list<Tarjeta> Jugador::getTarjetasJugador()  {
    return tarjetas_jugador;
}

void Jugador::setTarjetasJugador( list<Tarjeta> tarjetasJugador) {
    tarjetas_jugador = tarjetasJugador;
}

 list<Territorio> Jugador::getTerritoriosJugador(){
    return territorios_jugador;
}

void Jugador::setTerritoriosJugador( list<Territorio> &territoriosJugador) {
    territorios_jugador = territoriosJugador;
}

void Jugador::setTerritorioJugador( Territorio territorio) {
    territorios_jugador.push_back(territorio);
}