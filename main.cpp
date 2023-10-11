/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include <iostream>
#include <string>
#include "EstadoJuego.h"


using namespace std;

void ayuda();
EstadoJuego* inicializarJuego(list<Tarjeta> lista_tarjetas, list<Territorio> territorios);
EstadoJuego* inicializar_a(string archivo);
void guardar();
void guardar_Comprimido();
void salir();
list<Continente> Preparar_continentes();
list<Territorio> Preparar_territorios();
list<Tarjeta> Preparar_Tarjetas();


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
        } else if (comando == "iniciar juego nuevo") {
            comando1 = 1;
        } else if (comando == "Cargar archivo") {
            comando1 = 2;
        } else if (comando == "Guardar partida .txt") {
            comando1 = 3;
        } else if (comando == "Guardar partida .bin") {
            comando1 = 4;
        } else if (comando == "Turno") {
            comando1 = 5;
        }else if(comando == "Salir"){
            comando1 = 6;
        }
        else {
            cout << "Comando no reconocido. 0 para ver la lista de comandos." << endl;
            continue;
        }

        switch (comando1) {
            case '0':
                ayuda();
                break;
            case '1':
                partida = inicializarJuego(tarjetas,territorios);
                break;
            case '2':
                cout << "ingrese nombre de archivo";
                cin >> archivo;
                partida = inicializar_a(archivo);
                break;
            case '3':
                guardar();
                break;
            case '4':
                guardar_Comprimido();
                break;
            case '5':

                break;
            case 6:
                return 0;
            default:
                cout << "Comando no reconocido. 0 para ver la lista de comandos." << endl;
                break;
        }
    }
    return 0;
}
void salir() {
    cout << "Saliendo del juego..." << endl;
    exit(0);
}

void guardar() {
    cout << "Guardando el estado del juego..." << endl;

}

void guardar_Comprimido() {
    cout << "Guardando el estado del juego comprimido..." << endl;

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

        Tarjeta tarjeta1(1, "infanteria", "Alaska");
        Tarjeta tarjeta2(2, "infanteria", "Alberta");
        Tarjeta tarjeta3(3, "infanteria", "América Central");
        Tarjeta tarjeta4(4, "infanteria", "Estados Unidos Orientales");
        Tarjeta tarjeta5(5, "infanteria", "Groenlandia");
        Tarjeta tarjeta6(6, "infanteria", "Territorio Noroccidental");
        Tarjeta tarjeta7(7, "infanteria", "Ontario");
        Tarjeta tarjeta8(8, "infanteria", "Quebec");
        Tarjeta tarjeta9(9, "infanteria", "Estados Unidos Occidentales");
        Tarjeta tarjeta10(10, "infanteria", "Gran Bretaña");
        Tarjeta tarjeta11(11, "infanteria", "Islandia");
        Tarjeta tarjeta12(12, "infanteria", "Europa del Norte");
        Tarjeta tarjeta13(13, "infanteria", "Escandinavia");
        Tarjeta tarjeta14(14, "infanteria", "Europa del Sur");
        Tarjeta tarjeta15(15, "caballeria", "Ucrania");
        Tarjeta tarjeta16(16, "caballeria", "Europa Occidental");
        Tarjeta tarjeta17(17, "caballeria", "Afganistán");
        Tarjeta tarjeta18(18, "caballeria", "China");
        Tarjeta tarjeta19(19, "caballeria", "India");
        Tarjeta tarjeta20(20, "caballeria", "Irkutsk");
        Tarjeta tarjeta21(21, "caballeria", "Japón");
        Tarjeta tarjeta22(22, "caballeria", "Kamchatka");
        Tarjeta tarjeta23(23, "caballeria", "Medio Oriente");
        Tarjeta tarjeta24(24, "caballeria", "Mongolia");
        Tarjeta tarjeta25(25, "caballeria", "Siam");
        Tarjeta tarjeta26(26, "caballeria", "Siberia");
        Tarjeta tarjeta27(27, "caballeria", "Ural");
        Tarjeta tarjeta28(28, "artilleria", "Yakutsk");
        Tarjeta tarjeta29(29, "artilleria", "Congo");
        Tarjeta tarjeta30(30, "artilleria", "África Oriental");
        Tarjeta tarjeta31(31, "artilleria", "Egipto");
        Tarjeta tarjeta32(32, "artilleria", "Madagascar");
        Tarjeta tarjeta33(33, "artilleria", "África del Norte");
        Tarjeta tarjeta34(34, "artilleria", "África del Sur");
        Tarjeta tarjeta35(35, "artilleria", "Argentina");
        Tarjeta tarjeta36(36, "artilleria", "Brasil");
        Tarjeta tarjeta37(37, "artilleria", "Perú");
        Tarjeta tarjeta38(38, "artilleria", "Venezuela");
        Tarjeta tarjeta39(39, "artilleria", "Australia Oriental");
        Tarjeta tarjeta40(40, "artilleria", "Indonesia");
        Tarjeta tarjeta41(41, "artilleria", "Nueva Guinea");
        Tarjeta tarjeta42(42, "artilleria", "Australia Occidental");
        Tarjeta tarjeta43(43, "Comodín", "Comodín");
        Tarjeta tarjeta44(44, "Comodín", "Comodín");

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