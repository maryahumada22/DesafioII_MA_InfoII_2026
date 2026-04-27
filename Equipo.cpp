#include <iostream>
#include "Equipo.h"

using namespace std;

Equipo::Equipo() {

    pais="";
    directorTecnico="";
    federacion="";
    confederacion="";

    golesFavor=0;
    golesContra=0;

    partidosGanados=0;
    partidosEmpatados=0;
    partidosPerdidos=0;

    puntos=0;
}

Equipo::Equipo(string pais,string dt,string fed,string conf,int gf,int gc,int pg,int pe,int pp){

    this->pais=pais;
    directorTecnico=dt;
    federacion=fed;
    confederacion=conf;

    golesFavor=gf;
    golesContra=gc;

    partidosGanados=pg;
    partidosEmpatados=pe;
    partidosPerdidos=pp;

    calcularPuntos();
}

Equipo::Equipo(const Equipo &e){

    pais=e.pais;
    directorTecnico=e.directorTecnico;
    federacion=e.federacion;
    confederacion=e.confederacion;

    golesFavor=e.golesFavor;
    golesContra=e.golesContra;

    partidosGanados=e.partidosGanados;
    partidosEmpatados=e.partidosEmpatados;
    partidosPerdidos=e.partidosPerdidos;

    puntos=e.puntos;
}

string Equipo::getPais(){ return pais; }
string Equipo::getDirectorTecnico(){ return directorTecnico; }
string Equipo::getFederacion(){ return federacion; }
string Equipo::getConfederacion(){ return confederacion; }

int Equipo::getGolesFavor(){ return golesFavor; }
int Equipo::getGolesContra(){ return golesContra; }

int Equipo::getGanados(){ return partidosGanados; }
int Equipo::getEmpatados(){ return partidosEmpatados; }
int Equipo::getPerdidos(){ return partidosPerdidos; }

int Equipo::getPuntos(){ return puntos; }

void Equipo::setPais(string p){ pais=p; }
void Equipo::setDirectorTecnico(string d){ directorTecnico=d; }
void Equipo::setFederacion(string f){ federacion=f; }
void Equipo::setConfederacion(string c){ confederacion=c; }

void Equipo::setGolesFavor(int g){ golesFavor=g; }
void Equipo::setGolesContra(int g){ golesContra=g; }

void Equipo::setGanados(int g){ partidosGanados=g; }
void Equipo::setEmpatados(int e){ partidosEmpatados=e; }
void Equipo::setPerdidos(int p){ partidosPerdidos=p; }

void Equipo::calcularPuntos(){

    puntos = partidosGanados*3 + partidosEmpatados;
}

void Equipo::registrarVictoria(){

    partidosGanados++;
    calcularPuntos();
}

void Equipo::registrarEmpate(){

    partidosEmpatados++;
    calcularPuntos();
}

void Equipo::registrarDerrota(){

    partidosPerdidos++;
}

void Equipo::sumarGolesFavor(int g){

    golesFavor += g;
}

void Equipo::sumarGolesContra(int g){

    golesContra += g;
}

void Equipo::mostrarEquipo(){

    cout<<"Pais: "<<pais<<endl;
    cout<<"DT: "<<directorTecnico<<endl;
    cout<<"Federacion: "<<federacion<<endl;
    cout<<"Confederacion: "<<confederacion<<endl;

    cout<<"GF: "<<golesFavor<<" GC: "<<golesContra<<endl;

    cout<<"PG: "<<partidosGanados
         <<" PE: "<<partidosEmpatados
         <<" PP: "<<partidosPerdidos<<endl;

    cout<<"Puntos: "<<puntos<<endl;
}
