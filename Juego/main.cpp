/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/


#include <iostream>
#include <string>
#include "../Estructura/jugador.h"
#include "../Estructura/continente.h"
#include "../Estructura/territorio.h"
#include "../Estructura/tarjeta.h"
#include "../Codificacion/Arbol.h"
#include "../Codificacion/Nodo.h"
#include "EstadoJuego.h"
#include <fstream>

using namespace std;

void ayuda();
EstadoJuego* inicializarJuego(list<Tarjeta> lista_tarjetas, list<Territorio> territorios);
EstadoJuego* inicializar_a(string archivo);
void Guardartxt(EstadoJuego partida);
void GuardarJugador(const Jugador jugador);
void guardar_Comprimido(EstadoJuego);
void salir();
list<Continente> Preparar_continentes();
list<Territorio> Preparar_territorios();
list<Tarjeta> Preparar_Tarjetas();
void GuardarBin();


int main() {

    EstadoJuego* partida = new EstadoJuego();
    list<Territorio> territorios = Preparar_territorios();
    list<Continente> continentes = Preparar_continentes();
    list<Tarjeta> tarjetas = Preparar_Tarjetas();

    string comando;
    int comando1;
    cout << "Bienvenido al juego. Escribe 'ayuda' para ver la lista de comandos." << endl;

    while (true) {
        cout << "Ingrese un comando: ";
        cin >> comando;
        string archivo;

        if (comando == "ayuda") {
            comando1 = 0;
        } else if (comando == "nuevo") {
            comando1 = 1;
        } else if (comando == "Cargar archivo") {
            comando1 = 2;
        } else if (comando == "Guardar partida .txt") {
            comando1 = 3;
        } else if (comando == "Guardar partida .bin") {
            comando1 = 4;
        } else if (comando == "Turno") {
            comando1 = 5;
        } else if (comando == "Salir") {
            comando1 = 6;
        } else {
            cout << "Comando no reconocido. 0 para ver la lista de comandos." << endl;
            continue;
        }

        switch (comando1) {
            case 0:
                ayuda();
                break;
            case 1:
                partida = inicializarJuego(tarjetas, territorios);
                break;
            case 2:
                cout << "ingrese nombre de archivo";
                cin >> archivo;
                partida = inicializar_a(archivo);
                break;
            case 3:
                Guardartxt(*partida);
                break;
            case 4:
                //guardar_Comprimido(*partida);
                break;
            case 5:
                break;
            case 6:
                return 0;
            default:
                cout<<"comando no reconocido";
        }
    }
}

void salir() {
    cout << "Saliendo del juego..." << endl;
    exit(0);
}


EstadoJuego* inicializarJuego(list<Tarjeta> lista_tarjetas, list<Territorio> territorios){
    EstadoJuego* juego = new EstadoJuego();
    juego->setMazo(lista_tarjetas);
    juego->inicializar(territorios);
    return juego;

}

EstadoJuego* inicializar_a(string archivo) {
    EstadoJuego* ba  = new EstadoJuego();
    cout << "Inicializando el juego del archivo " << endl;
    return ba;
}

void ayuda() {
    cout << "Lista de comandos disponibles:" << endl;
    cout << "  ayuda " << endl;
    cout << "  iniciar nuevo juego " << endl;
    cout << "  Cargar archivo " << endl;
    cout << "  guardar partida en formato .txt " << endl;
    cout << "  guardar partida en formato .bin " << endl;
    cout << "  Turno <id jugador>" << endl;
    cout << "  salir" << endl;
}

list<Continente> Preparar_continentes(){
    list<Continente> continentes;

    Continente americaDelNorte(1, "América del Norte", 9);
    Continente europa(2, "Europa", 7);
    Continente asia(3, "Asia", 12);
    Continente africa(4, "África", 6);
    Continente americaDelSur(5, "América del Sur", 4);
    Continente australia(6, "Australia", 4);

    continentes.push_back(americaDelNorte);
    continentes.push_back(europa);
    continentes.push_back(asia);
    continentes.push_back(africa);
    continentes.push_back(americaDelSur);
    continentes.push_back(australia);
    
    return continentes;

}

list<Territorio> Preparar_territorios(){
list<Territorio> territorios;
    
        // Continente: América del Norte

        Territorio alaska(1,1, "Alaska", 1);
        Territorio alberta(2,2, "Alberta", 1);
        Territorio americaCen(3,3, "América Central", 1);
        Territorio estadosUnidosOri(4,4, "Estados Unidos Orientales", 1);
        Territorio groenlandia(5,5, "Groenlandia", 1);
        Territorio territorioNoroc(6,6, "Territorio Noroccidental", 1);
        Territorio ontario(7,7, "Ontario", 1);
        Territorio quebec(8,8, "Quebec", 1);
        Territorio estadosUnidosOc(9,9, "Estados Unidos Occidentales", 1);

        // Continente: Europa

        Territorio granBretana(10, 1, "Gran Bretaña", 2);
        Territorio islandia(11, 2, "Islandia", 2);
        Territorio europaDelNorte(12, 3, "Europa del Norte", 2);
        Territorio escandinavia(13, 4, "Escandinavia", 2);
        Territorio europaDelSur(14, 5, "Europa del Sur", 2);
        Territorio ucrania(15, 6, "Ucrania", 2);
        Territorio europaOc(16, 7, "Europa Occidental", 2);

        // Continente: Asia

        Territorio afghanistan(17, 1, "Afganistán", 3);
        Territorio china(18, 2, "China", 3);
        Territorio india(19, 3, "India", 3);
        Territorio irkutsk(20, 4, "Irkutsk", 3);
        Territorio japon(21, 5, "Japón", 3);
        Territorio kamchatka(22, 6, "Kamchatka", 3);
        Territorio medioOriente(23, 7, "Medio Oriente", 3);
        Territorio mongolia(24, 8, "Mongolia", 3);
        Territorio siam(25, 9, "Siam", 3);
        Territorio siberia(26, 10, "Siberia", 3);
        Territorio ural(27, 11, "Ural", 3);
        Territorio yakutsk(28, 12, "Yakutsk", 3);

        // Continente: África

        Territorio congo(29, 1, "Congo", 4);
        Territorio africaOrien(30, 2, "África Oriental", 4);
        Territorio egipto(31, 3, "Egipto", 4);
        Territorio madagascar(32, 4, "Madagascar", 4);
        Territorio africaDelNorte(33, 5, "África del Norte", 4);
        Territorio africaDelSur(34, 6, "África del Sur", 4);

        // Continente: América del Sur

        // Continente: América del Sur
        Territorio argentina(35, 1, "Argentina", 5);
        Territorio brasil(36, 3, "Brasil", 5);
        Territorio peru(37, 4, "Perú", 5);
        Territorio venezuela(38, 5, "Venezuela", 5);

        // Continente: Australia

        Territorio australiaOriental(39, 1, "Australia Oriental", 6);
        Territorio indonesia(40, 2, "Indonesia", 6);
        Territorio nuevaGuinea(41, 3, "Nueva Guinea", 6);
        Territorio australiaOc(42, 4, "Australia Occidental", 6);

    //Adyacentes Usa
    list<string> TAalaska = {"Territorio Noroccidental","Alberta","Kamchatka"};
    list<string> TAalberta = {"Territorio Noroccidental", "Ontario"};
    list<string> TAamericaC = {"Estados Unidos Occidentales", "Estados Unidos Orientales","Venezuela"};
    list<string> TAestadosUOr = {"América Central", "Estados Unidos Occidentales","Ontario","Quebec"};
    list<string> TAgroenlandia = {"Territorio Noroccidental","Ontario","Quebec","Islandia"};
    list<string> TAteritorioNO = {"Alaska","Alberta","Ontario","Groenlandia"};
    list<string> TAontario = {"Territorio Noroccidental","Alberta","Estados Unidos Occidentales","Estados Unidos Orientales","Quebec","Groenlandia"};
    list<string> TAquebec = {"Ontario","Estados Unidos Orientales","Groenlandia"};
    list<string> TAestadosUOc = {"Alberta","Ontario","Estados Unidos Orientales","América Central"};
    //Adyacentes Europa
    list<string> TAgranB ={"Islandia","Europa del Norte","Escandinavia","Europa Occidental"};
    list<string> TAislandia ={"Gran Bretaña","Escandinavia","Groenlandia"};
    list<string> TAeuropaN ={"Gran Bretaña","Escandinavia","Europa del Sur","Ucrania","Europa Occidental"};
    list<string> TAescandinavia ={"Gran Bretaña","Islandia","Europa del Norte","Ucrania"};
    list<string> TAeuropaS ={"Europa del Norte","Ucrania", "Europa Occidental","Medio Oriente","Egipto","África del Norte"};
    list<string> TAucrania ={"Europa del Norte", "Escandinavia","Europa del Sur","Afghanistán","Medio Oriente","Ural"};
    list<string> TAeuropaOc ={"Gran Bretaña", "Europa del Norte","Europa del Sur","África del Norte"};

    //Adyacentes Asia //
    list<string> TAafganis ={"China","India","Medio Oriente","Ucrania","Ural",};
    list<string> TAchina ={"Afghanistán","India","Siam","Mongolia","Ural","Siberia"};
    list<string> TAindia ={"Afghanistán","China","Medio Oriente","Siam"};
    list<string> TAirkutsk ={"Kamchatka","Mongolia","Siberia","Yakutsk"};
    list<string> TAjapon ={"Kamchatka","Mongolia"};
    list<string> TAkamchatka ={"Irkutsk","Japón","Mongolia","Yakutsk","Alaska"};
    list<string> TAmedio_O ={"Afghanistán","India","Ucrania","Europa del Sur","Egipto"};
    list<string> TAmongolia ={"China","Irkutsk","Japón","Kamchatka","Siberia"};
    list<string> TAsiam ={"China","India","Indonesia"};
    list<string> TAsiberia ={"China","Irkutsk","Mongolia","Ural","Yakutsk"};
    list<string> TAural ={"Afghanistán","China","Siberia","Ucrania"};
    list<string> TAyakutsk ={"Irkutsk","Kamchatka","Siberia"};
    //Adyacentes America Sur//
    list<string> TAyargentina ={"Brazil","Perú"};
    list<string> TAbrazil ={"Argentina","Perú","Venezuela","África del Norte"};
    list<string> TAperu ={"Argentina","Brazil","Venezuela"};
    list<string> TAvenezuela ={"Brazil","Perú","América Central"};
    //Adyacentes Africa //
    list<string> TAycongo ={"África Oriental","África del Norte","África del Sur"};
    list<string> TAyafrica_O ={"Congo","Egipto","Madagascar","África de Sur"};
    list<string> TAyegipto ={"África Oriental","África del Norte","Europa del Sur","Medio Oriente"};
    list<string> TAmadagascar ={"África Oriental","África del Norte"};
    list<string> TAyafrica_N ={"Brazil","Congo","África Oriental","Egipto","Europa del Sur","Europa Occidental"};
    list<string> TAyafrica_S ={"Congo","África Oriental","Madagascar"};
    //Adyacentes Australia //
    list<string> TAyaust_Or ={"Australia Occidental","Nueva Guinea"};
    list<string> TAindonesia ={"Siam","Nueva Guinea","Australia Occidental"};
    list<string> TAnueva_guinea ={"Australia Oriental","Indonesia","Australia Occidental"};
    list<string> TAyaust_Oc ={"Australia Oriental","Indonesia","Nueva Guinea"};

    alaska.setTerritoriosAlrededor(TAalaska);
    alaska.setTerritoriosAlrededor(TAalaska);
    alberta.setTerritoriosAlrededor(TAalberta);
    americaCen.setTerritoriosAlrededor(TAamericaC);
    estadosUnidosOri.setTerritoriosAlrededor(TAestadosUOr);
    groenlandia.setTerritoriosAlrededor(TAgroenlandia);
    territorioNoroc.setTerritoriosAlrededor(TAteritorioNO);
    ontario.setTerritoriosAlrededor(TAontario);
    quebec.setTerritoriosAlrededor(TAquebec);
    estadosUnidosOc.setTerritoriosAlrededor(TAestadosUOc);
    granBretana.setTerritoriosAlrededor(TAgranB);
    islandia.setTerritoriosAlrededor(TAislandia);
    europaDelNorte.setTerritoriosAlrededor(TAeuropaN);
    escandinavia.setTerritoriosAlrededor(TAescandinavia);
    europaDelSur.setTerritoriosAlrededor(TAeuropaS);
    ucrania.setTerritoriosAlrededor(TAucrania);
    europaOc.setTerritoriosAlrededor(TAeuropaOc);
    afghanistan.setTerritoriosAlrededor(TAafganis);
    china.setTerritoriosAlrededor(TAchina);
    india.setTerritoriosAlrededor(TAindia);
    irkutsk.setTerritoriosAlrededor(TAirkutsk);
    japon.setTerritoriosAlrededor(TAjapon);
    kamchatka.setTerritoriosAlrededor(TAkamchatka);
    medioOriente.setTerritoriosAlrededor(TAmedio_O);
    mongolia.setTerritoriosAlrededor(TAmongolia);
    siam.setTerritoriosAlrededor(TAsiam);
    siberia.setTerritoriosAlrededor(TAsiberia);
    ural.setTerritoriosAlrededor(TAural);
    yakutsk.setTerritoriosAlrededor(TAyakutsk);
    argentina.setTerritoriosAlrededor(TAyargentina);
    brasil.setTerritoriosAlrededor(TAbrazil);
    peru.setTerritoriosAlrededor(TAperu);
    venezuela.setTerritoriosAlrededor(TAvenezuela);
    congo.setTerritoriosAlrededor(TAycongo);
    africaOrien.setTerritoriosAlrededor(TAyafrica_O);
    egipto.setTerritoriosAlrededor(TAyegipto);
    madagascar.setTerritoriosAlrededor(TAmadagascar);
    africaDelNorte.setTerritoriosAlrededor(TAyafrica_N);
    africaDelSur.setTerritoriosAlrededor(TAyafrica_S);
    australiaOriental.setTerritoriosAlrededor(TAyaust_Or);
    indonesia.setTerritoriosAlrededor(TAindonesia);
    nuevaGuinea.setTerritoriosAlrededor(TAnueva_guinea);
    australiaOc.setTerritoriosAlrededor(TAyaust_Oc);

        territorios.push_back(alaska);
        territorios.push_back(alberta);
        territorios.push_back(americaCen);
        territorios.push_back(estadosUnidosOri);
        territorios.push_back(groenlandia);
        territorios.push_back(territorioNoroc);
        territorios.push_back(ontario);
        territorios.push_back(quebec);
        territorios.push_back(estadosUnidosOc);
        territorios.push_back(granBretana);
        territorios.push_back(islandia);
        territorios.push_back(europaDelNorte);
        territorios.push_back(escandinavia);
        territorios.push_back(europaDelSur);
        territorios.push_back(ucrania);
        territorios.push_back(europaOc);
        territorios.push_back(afghanistan);
        territorios.push_back(china);
        territorios.push_back(india);
        territorios.push_back(irkutsk);
        territorios.push_back(japon);
        territorios.push_back(kamchatka);
        territorios.push_back(medioOriente);
        territorios.push_back(mongolia);
        territorios.push_back(siam);
        territorios.push_back(siberia);
        territorios.push_back(ural);
        territorios.push_back(yakutsk);
        territorios.push_back(congo);
        territorios.push_back(africaOrien);
        territorios.push_back(egipto);
        territorios.push_back(madagascar);
        territorios.push_back(africaDelNorte);
        territorios.push_back(africaDelSur);
        territorios.push_back(argentina);
        territorios.push_back(brasil);
        territorios.push_back(peru);
        territorios.push_back(venezuela);
        territorios.push_back(australiaOriental);
        territorios.push_back(indonesia);
        territorios.push_back(nuevaGuinea);
        territorios.push_back(australiaOc);

        return territorios;
    }

list<Tarjeta> Preparar_Tarjetas(){

        // inicializar Tarjetas//

    Tarjeta tarjeta1(1, "TR", 27, "Soldier");
    Tarjeta tarjeta2(2, "TR", 1, "Canon");
    Tarjeta tarjeta3(3, "TR", 2, "Canon");
    Tarjeta tarjeta4(4, "TR", 10, "Soldier");
    Tarjeta tarjeta5(5, "TR", 11, "Soldier");
    Tarjeta tarjeta6(6, "TR", 9, "Soldier");
    Tarjeta tarjeta7(7, "TR", 28, "Canon");
    Tarjeta tarjeta8(8, "TR", 24, "Canon");
    Tarjeta tarjeta9(9, "TR", 23, "Soldier");
    Tarjeta tarjeta10(10, "TR", 40, "Horse");
    Tarjeta tarjeta11(11, "TR", 4, "Canon");
    Tarjeta tarjeta12(12, "TR", 25, "Horse");
    Tarjeta tarjeta13(13, "TR", 18, "Soldier");
    Tarjeta tarjeta14(14, "TR", 5, "Horse");
    Tarjeta tarjeta15(15, "TR", 19, "Horse");
    Tarjeta tarjeta16(16, "TR", 29, "Horse");
    Tarjeta tarjeta17(17, "TR", 41, "Soldier");
    Tarjeta tarjeta18(18, "TR", 30, "Canon");
    Tarjeta tarjeta19(19, "TR", 31, "Horse");
    Tarjeta tarjeta20(20, "TR", 32, "Canon");
    Tarjeta tarjeta21(21, "TR", 26, "Horse");
    Tarjeta tarjeta22(22, "TR", 33, "Canon");
    Tarjeta tarjeta23(23, "TR", 34, "Horse");
    Tarjeta tarjeta24(24, "TR", 42, "Horse");
    Tarjeta tarjeta25(25, "TR", 21, "Soldier");
    Tarjeta tarjeta26(26, "TR", 15, "Horse");
    Tarjeta tarjeta27(27, "TR", 8, "Horse");
    Tarjeta tarjeta28(28, "TR", 6, "Canon");
    Tarjeta tarjeta29(29, "TR", 12, "Horse");
    Tarjeta tarjeta30(30, "TR", 7, "Canon");
    Tarjeta tarjeta31(31, "TR", 14, "Soldier");
    Tarjeta tarjeta32(32, "TR", 35, "Horse");
    Tarjeta tarjeta33(33, "TR", 36, "Soldier");
    Tarjeta tarjeta34(34, "TR", 22, "Canon");
    Tarjeta tarjeta35(35, "TR", 16, "Soldier");
    Tarjeta tarjeta36(36, "TR", 20, "Soldier");
    Tarjeta tarjeta37(37, "TR", 37, "Soldier");
    Tarjeta tarjeta38(38, "TR", 13, "Horse");
    Tarjeta tarjeta39(39, "TR", 39, "Canon");
    Tarjeta tarjeta40(40, "TR", 17, "Soldier");
    Tarjeta tarjeta41(41, "TR", 3, "Canon");
    Tarjeta tarjeta42(42, "TR", 38, "Canon");
    Tarjeta tarjeta43(43, "CM", -1, "Las Tres");
    Tarjeta tarjeta44(44, "CM", -1, "Las Tres");


    list<Tarjeta> lista_tarjetas;

        //Insercion de tarjetas a la lista //
        lista_tarjetas.push_back(tarjeta1);
        lista_tarjetas.push_back(tarjeta2);
        lista_tarjetas.push_back(tarjeta3);
        lista_tarjetas.push_back(tarjeta4);
        lista_tarjetas.push_back(tarjeta5);
        lista_tarjetas.push_back(tarjeta6);
        lista_tarjetas.push_back(tarjeta7);
        lista_tarjetas.push_back(tarjeta8);
        lista_tarjetas.push_back(tarjeta9);
        lista_tarjetas.push_back(tarjeta10);
        lista_tarjetas.push_back(tarjeta11);
        lista_tarjetas.push_back(tarjeta12);
        lista_tarjetas.push_back(tarjeta13);
        lista_tarjetas.push_back(tarjeta14);
        lista_tarjetas.push_back(tarjeta15);
        lista_tarjetas.push_back(tarjeta16);
        lista_tarjetas.push_back(tarjeta17);
        lista_tarjetas.push_back(tarjeta18);
        lista_tarjetas.push_back(tarjeta19);
        lista_tarjetas.push_back(tarjeta20);
        lista_tarjetas.push_back(tarjeta21);
        lista_tarjetas.push_back(tarjeta22);
        lista_tarjetas.push_back(tarjeta23);
        lista_tarjetas.push_back(tarjeta24);
        lista_tarjetas.push_back(tarjeta25);
        lista_tarjetas.push_back(tarjeta26);
        lista_tarjetas.push_back(tarjeta27);
        lista_tarjetas.push_back(tarjeta28);
        lista_tarjetas.push_back(tarjeta29);
        lista_tarjetas.push_back(tarjeta30);
        lista_tarjetas.push_back(tarjeta31);
        lista_tarjetas.push_back(tarjeta32);
        lista_tarjetas.push_back(tarjeta33);
        lista_tarjetas.push_back(tarjeta34);
        lista_tarjetas.push_back(tarjeta35);
        lista_tarjetas.push_back(tarjeta36);
        lista_tarjetas.push_back(tarjeta37);
        lista_tarjetas.push_back(tarjeta38);
        lista_tarjetas.push_back(tarjeta39);
        lista_tarjetas.push_back(tarjeta40);
        lista_tarjetas.push_back(tarjeta41);
        lista_tarjetas.push_back(tarjeta42);
        lista_tarjetas.push_back(tarjeta43);
        lista_tarjetas.push_back(tarjeta44);
    return lista_tarjetas;
}

void GuardarJugador(Jugador jugador) {
    //JUGADOR//
    ofstream archivo_guardar("/home/jose/Probar/Estructuras1/Juego/partida_guardada.txt");
    if (archivo_guardar.is_open()) {
        archivo_guardar << jugador.getNombreJugador() << ";"; //nombre
        archivo_guardar << jugador.getColorJugador() <<  ";"; //color

        archivo_guardar << jugador.getTerritoriosJugador().size() << ";"; // numero
        for ( Territorio territorio : jugador.getTerritoriosJugador()) {
            archivo_guardar << territorio.getKeyTerritorio() << ";"
            << territorio.getUnidadesDeEjercitoTerritorio() << ";";
        }

        archivo_guardar << jugador.getTarjetasJugador().size() << ";";
        for ( Tarjeta tarjeta : jugador.getTarjetasJugador()) {
            archivo_guardar << tarjeta.getIdTarjeta() << ";";
        }
        archivo_guardar << endl;
        archivo_guardar.close();
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos del jugador." << endl;
    }
}

void Guardartxt(EstadoJuego partida){
    ofstream archivo_guardar("/home/jose/Probar/Estructuras1/Juego/partida_guardada.txt");
    if (archivo_guardar.is_open()){
        archivo_guardar << partida.getJugadores().size() << endl;
        archivo_guardar.close();
        for(auto it : partida.getJugadores()){
            GuardarJugador(it);
        }
        cout << "Datos del jugador guardados exitosamente en 'partida_guardada.txt'." << endl;
    }else {
        cout << "No se pudo abrir el archivo para guardar los datos del jugador." << endl;
    }
}

void guardar_Comprimido(EstadoJuego partida) {
    Guardartxt(partida);

    ifstream archivo("partida_guardada.txt");
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo " << std::endl;
        return ;
    }

    string linea;
    list<Arbol> queue;
    while (getline(archivo, linea)) {
        int tamano = linea.size();
        char caracteres[tamano + 1];
        linea.copy(caracteres, tamano);
        caracteres[tamano] = '\0';


        for (int i = 0; i < tamano; i++) {
            bool flag = false;
            int valor = static_cast<int>(caracteres[i]); // Convierte el carácter a valor ASCII
            for (auto it: queue) {
                if (valor == it.getAscii()) {
                    flag = true;
                    it.setFrec(it.getFrec() + 1);
                }
            }
            if (!flag) {
                queue.push_back(Arbol(Nodo(1, valor)));
            }
        }
    }
    //en teoría queue es una lista de arboles, cada uno siendo un caracter y su frecuencia
    //se ordena de menor a mayor frecuencia
    while(queue.size()>1){
    }
    archivo.close();
}


