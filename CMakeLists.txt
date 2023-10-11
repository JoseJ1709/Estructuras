cmake_minimum_required(VERSION 3.26)
project(Estructuras)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Estructuras
        Arbol.cpp
        Arbol.h
        continente.cpp
        continente.h
        Dado.cpp
        Dado.h
        EstadoJuego.cpp
        EstadoJuego.h
        jugador.cpp
        jugador.h
        main.cpp
        Nodo.cpp
        Nodo.h
        tarjeta.cpp
        tarjeta.h
        territorio.cpp
        territorio.h)
