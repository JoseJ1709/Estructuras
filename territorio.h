/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/
#include <string>
#include <list>

#ifndef TERRITORIO_H
#define TERRITORIO_H

using namespace std;

class Territorio {
private:
  int id_territorio;
  string nombre_territorio;
  int id_continente;
  list<Territorio*> territorios_alrededor;
  int unidadesDeEjercito_territorio;

public:
  Territorio(string nombre, int id, int idcontinente);

    Territorio();

    int getIdTerritorio() const;

    void setIdTerritorio(int idTerritorio);

    const string &getNombreTerritorio() const;

    void setNombreTerritorio(const string &nombreTerritorio);

    int getIdContinente() const;

    void setIdContinente(int idContinente);

    const list<Territorio *> &getTerritoriosAlrededor() const;

    void setTerritoriosAlrededor(const list<Territorio *> &territoriosAlrededor);

    int getUnidadesDeEjercitoTerritorio() const;

    void setUnidadesDeEjercitoTerritorio(int unidadesDeEjercitoTerritorio);

};

#endif // TERRITORIO_H
