#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Torneo.h"

using namespace std;

int main(){

    srand(time(NULL));

    Torneo mundial;

    cout<<"==================================="<<endl;
    cout<<"SIMULADOR MUNDIAL FIFA"<<endl;
    cout<<"==================================="<<endl;

    cout<<endl;

    mundial.cargarEquiposCSV("selecciones_clasificadas_mundial.csv");

    cout<<endl;

    cout<<"CREANDO GRUPOS"<<endl;

    mundial.crearGrupos();

    cout<<endl;

    mundial.mostrarGrupos();

    cout<<endl;

    cout<<"==================================="<<endl;
    cout<<"FASE DE GRUPOS"<<endl;
    cout<<"==================================="<<endl;

    mundial.jugarFaseDeGrupos();

    cout<<endl;

    mundial.clasificarOctavos();

    cout<<endl;

    mundial.jugarOctavos();

    mundial.jugarCuartos();

    mundial.jugarSemifinal();

    mundial.jugarFinal();

    mundial.mostrarEstadisticas();

    cout<<endl;

    cout<<"SIMULACION FINALIZADA"<<endl;

    return 0;
}
