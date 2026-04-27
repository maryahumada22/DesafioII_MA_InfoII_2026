#include <iostream>
#include "Grupo.h"

using namespace std;

Grupo::Grupo(){

    letra='A';
}

Grupo::Grupo(char l){

    letra=l;
}

void Grupo::setLetra(char l){

    letra=l;
}

char Grupo::getLetra(){

    return letra;
}

void Grupo::agregarEquipo(Equipo e,int pos){

    if(pos>=0 && pos<4){

        equipos[pos]=e;
    }
}

Equipo& Grupo::getEquipo(int i){

    return equipos[i];
}

void Grupo::mostrarGrupo(){

    cout<<"Grupo "<<letra<<endl;

    for(int i=0;i<4;i++){

        equipos[i].mostrarEquipo();
        cout<<endl;
    }
}
