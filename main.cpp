/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include <iostream>
#include <string>
#include "estado_juego.h"


using namespace std;
void ayuda();
void inicializarJuego();
void inicializar_a();
void guardar();
void guardar_Comprimido();
void salir();

int main() {
    string comando;
    cout << "Bienvenido al juego. Escribe '0' para ver la lista de comandos." << endl;
    while (true) {
        cout << "Ingrese un comando: ";
        cin >> comando;


        switch (comando[0]) {
            case '0':
                ayuda();
                break;
            case '1':
                inicializarJuego(); // Pasar la instancia de EstadoJuego
                break;
            case '2':
                inicializar_a();
                break;
            case '3':
                guardar();
                break;
            case '4':
                guardar_Comprimido();
                break;
            case '5':
                salir();
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

void inicializarJuego(){

}

void inicializar_a() {
    cout << "Inicializando el juego del archivo " << endl;

}

void ayuda() {
    cout << "Lista de comandos disponibles:" << endl;
    cout << "  ayuda [0]" << endl;
    cout << "  iniciar nuevo juego [1]" << endl;
    cout << "  Cargar archivo [2]" << endl;
    cout << "  guardar partida en formato .txt [3]" << endl;
    cout << "  guardar partida en formato .bin [4]" << endl;
    cout << "  salir [5]" << endl;
}
