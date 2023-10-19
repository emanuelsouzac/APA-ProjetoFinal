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

    int custoRota;
    int custoVeiculos;
    int custoTerceirizacao;

    vector<int> terceirizados;
    vector<int> veiculo;
    vector<vector<int>> rotas;

    int contVeiculo;
    int contClientes;
};

#endif // RESULTADOS_H
