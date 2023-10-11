/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include "territorio.h"

Territorio::Territorio(int key,int id,string nombre, int idcontinente) {
    key_territorio = key;
    nombre_territorio = nombre;
    id_territorio = id;
    id_continente = idcontinente;
}

int Territorio::getIdTerritorio() const {
    return id_territorio;
}

void Territorio::setIdTerritorio(int idTerritorio) {
    id_territorio = idTerritorio;
}

const string &Territorio::getNombreTerritorio() const {
    return nombre_territorio;
}

void Territorio::setNombreTerritorio(const string &nombreTerritorio) {
    nombre_territorio = nombreTerritorio;
}

int Territorio::getIdContinente() const {
    return id_continente;
}

void Territorio::setIdContinente(int idContinente) {
    id_continente = idContinente;
}

const list<string> &Territorio::getTerritoriosAlrededor() const {
    return territorios_alrededor;
}

void Territorio::setTerritoriosAlrededor(const list<string> &territoriosAlrededor) {
    territorios_alrededor = territoriosAlrededor;
}

int Territorio::getUnidadesDeEjercitoTerritorio() const {
    return unidadesDeEjercito_territorio;
}

void Territorio::setUnidadesDeEjercitoTerritorio(int unidadesDeEjercitoTerritorio) {
    unidadesDeEjercito_territorio = unidadesDeEjercitoTerritorio;
}
