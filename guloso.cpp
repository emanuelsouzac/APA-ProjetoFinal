#include "guloso.h"

#define NUM 1000000;

Guloso::Guloso() {
}

Guloso::~Guloso() {
}

Resultados Guloso::algoritmoGuloso(MeuArquivo val, Resultados res) {

    int ref = 0;
    int menor;
    int pos;
    vector<bool> clienteAtendido(val.n, false);

    while (1)
    {
        menor = 100000000;
        for (int i = 0; i < val.n + 1; i++)
        {
            if (i != ref && i != 0 && clienteAtendido[i-1] == false && val.c[ref][i] < menor)
            {
                menor = val.c[ref][i];
                pos = i;
            }
        }
        if (res.capacVeiculo[res.contVeiculo] - val.d[pos - 1] < 0)
        {
            res.custoRoteamento += val.c[ref][0]; // adiciona a volta para a garagem ao custo total
            res.custoRota[res.contVeiculo] += val.c[ref][0]; // adiciona a volta para a garagem ao custo de cada rota
            res.rota[res.contVeiculo].push_back(0);
            res.contVeiculo++;
            if (res.contClientes > val.L)
            {
                break;
            }
            ref = 0;
        }
        else
        {
            if (res.capacVeiculo[res.contVeiculo] == val.Q) res.rota[res.contVeiculo].push_back(0); // adiciona 0 à rota se ele acabou de começar
            clienteAtendido[pos-1] = true;

            res.custoRoteamento += val.c[ref][pos]; // custo da rota total
            res.custoRota[res.contVeiculo] += val.c[ref][pos]; // custo de cada rota

            res.capacVeiculo[res.contVeiculo] -= val.d[pos - 1];
            res.contClientes++;
            ref = pos;
            res.rota[res.contVeiculo].push_back(pos);
        }
    }

    for (int i = 0; i < val.n; i++)
    {
        if (clienteAtendido[i] == false)
        {
            res.custoTerceirizacao += val.p[i];
            res.terceirizados.push_back(i);
        }
    }

    res.custoVeiculos = res.contVeiculo * val.r;

    res.custoTotal = res.custoRoteamento + res.custoTerceirizacao + res.custoVeiculos;

    return res;
}