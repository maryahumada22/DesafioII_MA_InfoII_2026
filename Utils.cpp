#include "Utils.h"
#include <cstdlib>

int Utils::randomInt(int min, int max){

    return min + rand() % (max - min + 1);
}

bool Utils::probabilidad(double p){

    double r = (double)rand() / RAND_MAX;

    if(r < p) return true;

    return false;
}
