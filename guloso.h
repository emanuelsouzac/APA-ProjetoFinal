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

    Resultados algoritmoGuloso(MeuArquivo, Resultados);

};

#endif // GULOSO_H
