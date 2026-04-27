#ifndef TORNEO_H
#define TORNEO_H

#include "Grupo.h"
#include "Partido.h"
#include <string>

using namespace std;

class Torneo {

private:

    Equipo equipos[32];
    Grupo grupos[8];

    int cantidadEquipos;

    Equipo octavos[16];
    Equipo cuartos[8];
    Equipo semifinal[4];
    Equipo finalistas[2];

    Equipo campeon;
    Equipo subcampeon;

public:

    Torneo();

    void cargarEquiposCSV(string nombreArchivo);

    void crearGrupos();

    void mostrarGrupos();

    void jugarFaseDeGrupos();

    void mostrarTablaGrupo(int g);

    void mostrarTablas();

    void ordenarGrupo(int g);

    void clasificarOctavos();

    void jugarOctavos();

    void jugarCuartos();

    void jugarSemifinal();

    void jugarFinal();

    void mostrarEstadisticas();

};

#endif
