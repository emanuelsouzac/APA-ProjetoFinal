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
    while(k<=r){
        switch (k)
        {
        case 1:
            /* code */
            break;
        case 2:
            resultadosCopia = crossExchange(valores, resultadosCopia);
            break;
        case 3:
            /* code */
            break;
        }
        if(resultadosCopia.custoTotal < resultados.custoTotal){
            resultados = resultadosCopia;
            k = 1;
        }else{
            k++;
        }
    }
    return resultados;
}