#ifndef METRICAS_H
#define METRICAS_H

class Metricas{

private:

    static long iteraciones;
    static long memoria;

public:

    static void reset();

    static void sumarIteraciones(long n);

    static void registrarMemoria(long bytes);

    static long getIteraciones();

    static long getMemoria();

    static void mostrar();

};

#endif
