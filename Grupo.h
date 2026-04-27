#ifndef GRUPO_H
#define GRUPO_H

#include "Equipo.h"

class Grupo {

private:

    char letra;

    Equipo equipos[4];

public:

    Grupo();
    Grupo(char letra);

    void setLetra(char);
    char getLetra();

    void agregarEquipo(Equipo e,int pos);

    Equipo& getEquipo(int i);

    void mostrarGrupo();

};

#endif
