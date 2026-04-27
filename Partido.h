#ifndef PARTIDO_H
#define PARTIDO_H

#include "Equipo.h"

class Partido {

private:

    Equipo *equipo1;
    Equipo *equipo2;

    int goles1;
    int goles2;

public:

    Partido();

    void setEquipos(Equipo *e1,Equipo *e2);

    void jugarPartido();

    void mostrarResultado();

};

#endif
