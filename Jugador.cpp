#include "Jugador.h"

Jugador::Jugador(){

    nombre="";
    apellido="";
    numero=0;

    partidosJugados=0;
    goles=0;
    minutosJugados=0;
    asistencias=0;
    amarillas=0;
    rojas=0;
    faltas=0;
}

Jugador::Jugador(string n,string a,int num){

    nombre=n;
    apellido=a;
    numero=num;

    partidosJugados=0;
    goles=0;
    minutosJugados=0;
    asistencias=0;
    amarillas=0;
    rojas=0;
    faltas=0;
}

Jugador::Jugador(const Jugador &j){

    nombre=j.nombre;
    apellido=j.apellido;
    numero=j.numero;

    partidosJugados=j.partidosJugados;
    goles=j.goles;
    minutosJugados=j.minutosJugados;
    asistencias=j.asistencias;
    amarillas=j.amarillas;
    rojas=j.rojas;
    faltas=j.faltas;
}

void Jugador::setNombre(string n){
    nombre=n;
}

void Jugador::setApellido(string a){
    apellido=a;
}

string Jugador::getNombre(){
    return nombre;
}

string Jugador::getApellido(){
    return apellido;
}

int Jugador::getNumero(){
    return numero;
}

int Jugador::getGoles(){
    return goles;
}

int Jugador::getMinutos(){
    return minutosJugados;
}

void Jugador::registrarGol(){
    goles++;
}

void Jugador::registrarMinutos(int m){
    minutosJugados += m;
}

void Jugador::registrarAmarilla(){
    amarillas++;
}

void Jugador::registrarRoja(){
    rojas++;
}

void Jugador::registrarFalta(){
    faltas++;
}
