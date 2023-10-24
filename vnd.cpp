#include "vnd.h"

VND::VND() {
}

VND::~VND() {
}

Resultados VND::crossExchange(MeuArquivo valores, Resultados resultadosCopia){
    bool trocaFeita = false;
    int melhorCustoRota = resultadosCopia.custoRota;
    int A, B, x, y;
    ///cout << "passando pelo troca cruzada" << endl;
    for(int rotaA = 0; rotaA < resultadosCopia.contVeiculo - 1; rotaA++){
        for(int rotaB = rotaA + 1; rotaB < resultadosCopia.contVeiculo; rotaB++){
            for(int i = 1; i < resultadosCopia.rota[rotaA].size() - 1; i++){
                for(int j = 1; j < resultadosCopia.rota[rotaB].size() - 1; j++){
                    if(resultadosCopia.capacVeiculo[rotaA] - valores.d[(resultadosCopia.rota[rotaA][i])-1] + valores.d[(resultadosCopia.rota[rotaB][j])-1] >= 0  
                    && resultadosCopia.capacVeiculo[rotaB] - valores.d[(resultadosCopia.rota[rotaB][j])-1] + valores.d[(resultadosCopia.rota[rotaA][i])-1] >= 0){
                        int novoCusto = (resultadosCopia.custoRota
                        - valores.c[resultadosCopia.rota[rotaA][i-1]][resultadosCopia.rota[rotaA][i]] - valores.c[resultadosCopia.rota[rotaA][i]][resultadosCopia.rota[rotaA][i+1]]
                        - valores.c[resultadosCopia.rota[rotaB][j-1]][resultadosCopia.rota[rotaB][j]] - valores.c[resultadosCopia.rota[rotaB][j]][resultadosCopia.rota[rotaB][j+1]]
                        + valores.c[resultadosCopia.rota[rotaA][i-1]][resultadosCopia.rota[rotaB][j]] + valores.c[resultadosCopia.rota[rotaB][j]][resultadosCopia.rota[rotaA][i+1]]
                        + valores.c[resultadosCopia.rota[rotaB][j-1]][resultadosCopia.rota[rotaA][i]] + valores.c[resultadosCopia.rota[rotaA][i]][resultadosCopia.rota[rotaB][j+1]]);

                        
                        if(novoCusto < melhorCustoRota){
                            melhorCustoRota = novoCusto;
                            A = rotaA;
                            B = rotaB;
                            x = i;
                            y = j;
                            trocaFeita = true;
                        }
                        
                    }
                }
            }
        }
    }
    if(trocaFeita == true){
        swap(resultadosCopia.rota[A][x], resultadosCopia.rota[B][y]);
        resultadosCopia.custoRota = melhorCustoRota;
        resultadosCopia.custoTotal = resultadosCopia.custoRota + resultadosCopia.custoTerceirizacao + resultadosCopia.custoVeiculos;
        resultadosCopia.capacVeiculo[A] = resultadosCopia.capacVeiculo[A] - valores.d[(resultadosCopia.rota[A][x])-1] + valores.d[(resultadosCopia.rota[B][y])-1]; 
        resultadosCopia.capacVeiculo[B] = resultadosCopia.capacVeiculo[B] - valores.d[(resultadosCopia.rota[B][y])-1] + valores.d[(resultadosCopia.rota[A][x])-1];
    }
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
                break;
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