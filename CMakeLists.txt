cmake_minimum_required(VERSION 3.26)
project(Estructuras)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Estructuras
        Codificacion/Arbol.cpp
        Codificacion/Arbol.h
        Estructura/continente.cpp
        Estructura/continente.h
        Juego/Dado.cpp
        Juego/Dado.h
        Juego/EstadoJuego.cpp
        Juego/EstadoJuego.h
        Estructura/jugador.cpp
        Estructura/jugador.h
        Juego/main.cpp
        Codificacion/Nodo.cpp
        Codificacion/Nodo.h
        Estructura/tarjeta.cpp
        Estructura/tarjeta.h
        Estructura/territorio.cpp
        Estructura/territorio.h)
