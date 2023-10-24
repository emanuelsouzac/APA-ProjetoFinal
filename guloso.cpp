#include "guloso.h"

#define NUM 1000000;

Guloso::Guloso() {
}

Guloso::~Guloso() {
}

Resultados Guloso::algoritmoGuloso(MeuArquivo valores, Resultados resultados) {

    int referencial = 0;
    int menor;
    int pos;
    vector<bool> clienteAtendido(valores.n, false);

    while (1)
    {
        menor = 100000000;
        for (int i = 0; i < valores.n + 1; i++)
        {
            if (i != referencial && i != 0 && clienteAtendido[i-1] == false && valores.c[referencial][i] < menor)
            {
                menor = valores.c[referencial][i];
                pos = i;
            }
        }
        if (resultados.capacVeiculo[resultados.contVeiculo] - valores.d[pos - 1] < 0)
        {
            resultados.custoRota += valores.c[referencial][0];
            resultados.rota[resultados.contVeiculo].push_back(0);
            resultados.contVeiculo++;
            if (resultados.contClientes > valores.L)
            {
                break;
            }
            referencial = 0;
        }
        else
        {
            if (resultados.capacVeiculo[resultados.contVeiculo] == valores.Q) resultados.rota[resultados.contVeiculo].push_back(0);
            clienteAtendido[pos-1] = true;
            resultados.custoRota += valores.c[referencial][pos];
            resultados.capacVeiculo[resultados.contVeiculo] -= valores.d[pos - 1];
            resultados.contClientes++;
            referencial = pos;
            resultados.rota[resultados.contVeiculo].push_back(pos);
        }
    }

    for (int i = 0; i < valores.n; i++)
    {
        if (clienteAtendido[i] == false)
        {
            resultados.custoTerceirizacao += valores.p[i];
            resultados.terceirizados.push_back(i);
        }
    }

    resultados.custoVeiculos = resultados.contVeiculo * valores.r;

    resultados.custoTotal = resultados.custoRota + resultados.custoTerceirizacao + resultados.custoVeiculos;

    return resultados;
}