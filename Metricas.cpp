#include "Metricas.h"
#include <iostream>

using namespace std;

long Metricas::iteraciones = 0;
long Metricas::memoria = 0;

void Metricas::reset(){

    iteraciones = 0;
    memoria = 0;
}

void Metricas::sumarIteraciones(long n){

    iteraciones += n;
}

void Metricas::registrarMemoria(long bytes){

    memoria += bytes;
}

long Metricas::getIteraciones(){

    return iteraciones;
}

long Metricas::getMemoria(){

    return memoria;
}

void Metricas::mostrar(){

    cout << "Iteraciones: " << iteraciones << endl;
    cout << "Memoria usada (bytes): " << memoria << endl;
}
