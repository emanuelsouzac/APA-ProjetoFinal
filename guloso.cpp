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
        menor = NUM;
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
            res.custoRoteamento += val.c[ref][0];
            res.rota[res.contVeiculo].push_back(0);
            res.contVeiculo++;
            if (res.contClientes >= val.L)
            {
                break;
            }
            ref = 0;
        }
        else
        {
            if (res.capacVeiculo[res.contVeiculo] == val.Q) res.rota[res.contVeiculo].push_back(0);
            clienteAtendido[pos-1] = true;
            res.custoRoteamento += val.c[ref][pos];
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
            res.terceirizados.push_back(i + 1);
        }
    }

    res.custoVeiculos = res.contVeiculo * val.r;

    res.custoTotal = res.custoRoteamento + res.custoTerceirizacao + res.custoVeiculos;

    return res;
}