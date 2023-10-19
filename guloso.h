#ifndef GULOSO_H
#define GULOSO_H

#include <iostream>
#include <vector>

#include "resultados.h"
#include "valores.h"

using namespace std;

class Guloso {
public:
    Guloso();
    ~Guloso();

    Resultados algoritmoGuloso(MeuArquivo valores, Resultados resultados);

};

#endif // GULOSO_H
