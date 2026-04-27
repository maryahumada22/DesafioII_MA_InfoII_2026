#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Partido.h"

using namespace std;

Partido::Partido(){

    equipo1=NULL;
    equipo2=NULL;

    goles1=0;
    goles2=0;
}

void Partido::setEquipos(Equipo *e1,Equipo *e2){

    equipo1=e1;
    equipo2=e2;
}

void Partido::jugarPartido(){

    goles1 = rand()%5;
    goles2 = rand()%5;

    equipo1->sumarGolesFavor(goles1);
    equipo1->sumarGolesContra(goles2);

    equipo2->sumarGolesFavor(goles2);
    equipo2->sumarGolesContra(goles1);

    if(goles1>goles2){

        equipo1->registrarVictoria();
        equipo2->registrarDerrota();
    }

    else if(goles2>goles1){

        equipo2->registrarVictoria();
        equipo1->registrarDerrota();
    }

    else{

        equipo1->registrarEmpate();
        equipo2->registrarEmpate();
    }
}

void Partido::mostrarResultado(){

    cout<<equipo1->getPais()<<" "
         <<goles1<<" - "
         <<goles2<<" "
         <<equipo2->getPais()<<endl;
}
