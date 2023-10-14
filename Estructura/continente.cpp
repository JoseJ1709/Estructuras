/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include "continente.h"
#include <string>


Continente::Continente(int id, string nombre, int num_territorios) {
  id_contienente = id;
  nombre_continente = nombre;
  numero_territorios = num_territorios;
}

int Continente::getIdContienente() const {
    return id_contienente;
}

void Continente::setIdContienente(int idContienente) {
    id_contienente = idContienente;
}

const string &Continente::getNombreContinente() const {
    return nombre_continente;
}

void Continente::setNombreContinente(const string &nombreContinente) {
    nombre_continente = nombreContinente;
}

int Continente::getNumContinente() const {
    return numero_territorios;
}