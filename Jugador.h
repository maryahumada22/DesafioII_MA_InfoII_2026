#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

using namespace std;

class Jugador{

private:

    string nombre;
    string apellido;
    int numero;

    int partidosJugados;
    int goles;
    int minutosJugados;
    int asistencias;
    int amarillas;
    int rojas;
    int faltas;

public:

    Jugador();

    Jugador(string n, string a, int num);

    Jugador(const Jugador &j);

    void setNombre(string n);
    void setApellido(string a);

    string getNombre();
    string getApellido();
    int getNumero();

    int getGoles();
    int getMinutos();

    void registrarGol();
    void registrarMinutos(int m);

    void registrarAmarilla();
    void registrarRoja();
    void registrarFalta();

};

#endif
