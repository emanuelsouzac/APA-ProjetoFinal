#include "vnd.h"

VND::VND() {
}

VND::~VND() {
}

Resultados VND::crossExchange(MeuArquivo valores, Resultados resultadosCopia){
    return resultadosCopia;
}

Resultados VND::algoritmoVND(MeuArquivo valores, Resultados resultados){
    int r = 3;
    int k = 2;
    Resultados resultadosCopia = resultados;
    // CORRIGIR DEPOIS: while(k<=r)
    while(k<=2){
        switch (k)
        {
        case 1:
            /* code */
            break;
        case 2:
            if(resultados.contVeiculo > 1){
                resultadosCopia = crossExchange(valores, resultadosCopia);
            }
            break;
        case 3:
            /* code */
            break;
        }
        if(resultadosCopia.custoTotal < resultados.custoTotal){
            resultados = resultadosCopia;
            // CORRIGIR DEPOIS: k = 1
            k = 2;
        }else{
            k++;
        }
    }
    return resultados;
}