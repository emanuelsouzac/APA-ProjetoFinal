#ifndef RESULTADOS_H
#define RESULTADOS_H

#include <vector>
#include <iostream>

#include "valores.h"

using namespace std;

class Resultados {
public:
    Resultados(MeuArquivo valores);
    ~Resultados();

    void mostraResultados(MeuArquivo valores);

    int custoTotal;
    int custoRota;
    int custoVeiculos;
    int custoTerceirizacao;

    vector<int> terceirizados;
    vector<int> capacVeiculo;
    vector<vector<int>> rota;

    int contVeiculo;
    int contClientes;
};

#endif // RESULTADOS_H
