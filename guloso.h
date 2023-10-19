#ifndef GULOSO_H
#define GULOSO_H

#include <iostream>
#include <vector>

#include "resultados.h"
#include "valores.h"

using namespace std;

class Guloso {
public:
    Guloso(); // Construtor
    ~Guloso(); // Destrutor

    void algoritmoGuloso(MeuArquivo valores); // Função para executar o algoritmo guloso

};

#endif // GULOSO_H
