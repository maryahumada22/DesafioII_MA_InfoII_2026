#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Torneo.h"

using namespace std;

Torneo::Torneo(){

    cantidadEquipos=0;

    for(int i=0;i<8;i++){

        char letra = 'A'+i;

        grupos[i].setLetra(letra);
    }
}

void Torneo::cargarEquiposCSV(string nombreArchivo){

    ifstream archivo(nombreArchivo.c_str());

    if(!archivo){

        cout<<"Error abriendo archivo"<<endl;
        return;
    }

    while(!archivo.eof() && cantidadEquipos<32){

        string pais;
        string dt;
        string federacion;
        string conf;

        int gf;
        int gc;

        int pg;
        int pe;
        int pp;

        getline(archivo,pais,';');
        getline(archivo,dt,';');
        getline(archivo,federacion,';');
        getline(archivo,conf,';');

        archivo>>gf;
        archivo.ignore();

        archivo>>gc;
        archivo.ignore();

        archivo>>pg;
        archivo.ignore();

        archivo>>pe;
        archivo.ignore();

        archivo>>pp;

        archivo.ignore();

        Equipo e(
            pais,
            dt,
            federacion,
            conf,
            gf,
            gc,
            pg,
            pe,
            pp
            );

        equipos[cantidadEquipos]=e;

        cantidadEquipos++;
    }

    archivo.close();

    cout<<"Equipos cargados: "<<cantidadEquipos<<endl;
}

void Torneo::crearGrupos(){

    int indice=0;

    for(int g=0;g<8;g++){

        for(int i=0;i<4;i++){

            grupos[g].agregarEquipo(equipos[indice],i);

            indice++;
        }
    }
}

void Torneo::mostrarGrupos(){

    for(int i=0;i<8;i++){

        grupos[i].mostrarGrupo();

        cout<<endl;
    }
}

void Torneo::jugarFaseDeGrupos(){

    for(int g=0; g<8; g++){

        cout<<"===================="<<endl;
        cout<<"Grupo "<<grupos[g].getLetra()<<endl;
        cout<<"===================="<<endl;

        Equipo *e1 = &grupos[g].getEquipo(0);
        Equipo *e2 = &grupos[g].getEquipo(1);
        Equipo *e3 = &grupos[g].getEquipo(2);
        Equipo *e4 = &grupos[g].getEquipo(3);

        Partido p;

        p.setEquipos(e1,e2);
        p.jugarPartido();
        p.mostrarResultado();

        p.setEquipos(e1,e3);
        p.jugarPartido();
        p.mostrarResultado();

        p.setEquipos(e1,e4);
        p.jugarPartido();
        p.mostrarResultado();

        p.setEquipos(e2,e3);
        p.jugarPartido();
        p.mostrarResultado();

        p.setEquipos(e2,e4);
        p.jugarPartido();
        p.mostrarResultado();

        p.setEquipos(e3,e4);
        p.jugarPartido();
        p.mostrarResultado();

        cout<<endl;

        ordenarGrupo(g);

        mostrarTablaGrupo(g);

        cout<<endl;
    }
}

void Torneo::ordenarGrupo(int g){

    for(int i=0;i<4;i++){

        for(int j=i+1;j<4;j++){

            if(grupos[g].getEquipo(j).getPuntos() >
                grupos[g].getEquipo(i).getPuntos()){

                Equipo temp = grupos[g].getEquipo(i);

                grupos[g].agregarEquipo(
                    grupos[g].getEquipo(j),i);

                grupos[g].agregarEquipo(temp,j);
            }
        }
    }
}

void Torneo::mostrarTablaGrupo(int g){

    cout<<"Tabla Grupo "<<grupos[g].getLetra()<<endl;

    cout<<"Pais   Pts  GF  GC  PG  PE  PP"<<endl;

    for(int i=0;i<4;i++){

        Equipo &e = grupos[g].getEquipo(i);

        cout<<e.getPais()<<"   "
             <<e.getPuntos()<<"   "
             <<e.getGolesFavor()<<"   "
             <<e.getGolesContra()<<"   "
             <<e.getGanados()<<"   "
             <<e.getEmpatados()<<"   "
             <<e.getPerdidos()
             <<endl;
    }
}

void Torneo::mostrarTablas(){

    for(int i=0;i<8;i++){

        mostrarTablaGrupo(i);

        cout<<endl;
    }
}

void Torneo::clasificarOctavos(){

    int indice=0;

    for(int g=0; g<8; g++){

        octavos[indice] = grupos[g].getEquipo(0);
        indice++;

        octavos[indice] = grupos[g].getEquipo(1);
        indice++;
    }

    cout<<"Equipos clasificados a octavos:"<<endl;

    for(int i=0;i<16;i++){

        cout<<octavos[i].getPais()<<endl;
    }

    cout<<endl;
}

void Torneo::jugarOctavos(){

    cout<<"===== OCTAVOS DE FINAL ====="<<endl;

    int indice=0;

    for(int i=0;i<16;i+=2){

        Partido p;

        p.setEquipos(&octavos[i],&octavos[i+1]);

        p.jugarPartido();

        p.mostrarResultado();

        if(octavos[i].getPuntos() >= octavos[i+1].getPuntos()){

            cuartos[indice] = octavos[i];
        }
        else{

            cuartos[indice] = octavos[i+1];
        }

        indice++;
    }

    cout<<endl;
}

void Torneo::jugarCuartos(){

    cout<<"===== CUARTOS DE FINAL ====="<<endl;

    int indice=0;

    for(int i=0;i<8;i+=2){

        Partido p;

        p.setEquipos(&cuartos[i],&cuartos[i+1]);

        p.jugarPartido();

        p.mostrarResultado();

        if(cuartos[i].getPuntos() >= cuartos[i+1].getPuntos()){

            semifinal[indice] = cuartos[i];
        }
        else{

            semifinal[indice] = cuartos[i+1];
        }

        indice++;
    }

    cout<<endl;
}

void Torneo::jugarSemifinal(){

    cout<<"===== SEMIFINAL ====="<<endl;

    int indice=0;

    for(int i=0;i<4;i+=2){

        Partido p;

        p.setEquipos(&semifinal[i],&semifinal[i+1]);

        p.jugarPartido();

        p.mostrarResultado();

        if(semifinal[i].getPuntos() >= semifinal[i+1].getPuntos()){

            finalistas[indice] = semifinal[i];
        }
        else{

            finalistas[indice] = semifinal[i+1];
        }

        indice++;
    }

    cout<<endl;
}

void Torneo::jugarFinal(){

    cout<<"===== FINAL ====="<<endl;

    Partido p;

    p.setEquipos(&finalistas[0],&finalistas[1]);

    p.jugarPartido();

    p.mostrarResultado();

    if(finalistas[0].getPuntos() >= finalistas[1].getPuntos()){

        campeon = finalistas[0];
        subcampeon = finalistas[1];
    }
    else{

        campeon = finalistas[1];
        subcampeon = finalistas[0];
    }

    cout<<endl;

    cout<<"CAMPEON DEL TORNEO: "<<campeon.getPais()<<endl;
    cout<<"SUBCAMPEON: "<<subcampeon.getPais()<<endl;

    cout<<endl;
}

void Torneo::mostrarEstadisticas(){

    cout<<"============================"<<endl;
    cout<<"ESTADISTICAS DEL TORNEO"<<endl;
    cout<<"============================"<<endl;

    int totalGoles=0;

    Equipo masGoleador = equipos[0];
    Equipo menosGoleado = equipos[0];

    for(int i=0;i<32;i++){

        totalGoles += equipos[i].getGolesFavor();

        if(equipos[i].getGolesFavor() > masGoleador.getGolesFavor()){

            masGoleador = equipos[i];
        }

        if(equipos[i].getGolesContra() < menosGoleado.getGolesContra()){

            menosGoleado = equipos[i];
        }
    }

    float promedio = totalGoles / 32.0;

    cout<<"Total de goles del torneo: "<<totalGoles<<endl;

    cout<<"Promedio de goles por equipo: "<<promedio<<endl;

    cout<<"Equipo mas goleador: "<<masGoleador.getPais()
         <<" ("<<masGoleador.getGolesFavor()<<" goles)"<<endl;

    cout<<"Equipo menos goleado: "<<menosGoleado.getPais()
         <<" ("<<menosGoleado.getGolesContra()<<" goles)"<<endl;

    cout<<endl;

    cout<<"Campeon del torneo: "<<campeon.getPais()<<endl;

    cout<<"Subcampeon: "<<subcampeon.getPais()<<endl;
}
