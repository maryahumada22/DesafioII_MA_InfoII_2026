#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

using namespace std;

class Equipo {

private:

    string pais;
    string directorTecnico;
    string federacion;
    string confederacion;

    int golesFavor;
    int golesContra;

    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;

    int puntos;

public:

    Equipo();
    Equipo(string pais,string dt,string fed,string conf,int gf,int gc,int pg,int pe,int pp);
    Equipo(const Equipo &e);

    string getPais();
    string getDirectorTecnico();
    string getFederacion();
    string getConfederacion();

    int getGolesFavor();
    int getGolesContra();
    int getGanados();
    int getEmpatados();
    int getPerdidos();
    int getPuntos();

    void setPais(string);
    void setDirectorTecnico(string);
    void setFederacion(string);
    void setConfederacion(string);

    void setGolesFavor(int);
    void setGolesContra(int);

    void setGanados(int);
    void setEmpatados(int);
    void setPerdidos(int);

    void calcularPuntos();

    void registrarVictoria();
    void registrarEmpate();
    void registrarDerrota();

    void sumarGolesFavor(int);
    void sumarGolesContra(int);

    void mostrarEquipo();

};

#endif
