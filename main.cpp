#include <iostream>
#include <string>
#include "estado_juego.h"


using namespace std;

void inicializarJuego() {
}

void salir() {
    cout << "Saliendo del juego..." << endl;
    
}

void guardar() {
    cout << "Guardando el estado del juego..." << endl;
    
}

void guardar_comprimido() {
    cout << "Guardando el estado del juego comprimido..." << endl;
    
}

void inicializar_a() {
    cout << "Inicializando el juego con argumento 'a'..." << endl;
    
}

void ayuda() {
    cout << "Lista de comandos disponibles:" << endl;
    cout << "  ayuda [0]" << endl;
    cout << "  inicializar [1]" << endl;
    cout << "  inicializar a [2]" << endl;
    cout << "  guardar [3]" << endl;
    cout << "  guardar comprimido [4]" << endl;
    cout << "  salir [5]" << endl;
}

int main() {
    string comando;
    cout << "Bienvenido al juego. Escribe 'ayuda' para ver la lista de comandos." << endl;
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
                guardar_comprimido();
                break;
            case '5':
                salir();
                return 0;
            default:
                cout << "Comando no reconocido. [0] para ver la lista de comandos." << endl;
                break;
        }
    }

    return 0;
}
