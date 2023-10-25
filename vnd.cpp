#include "vnd.h"

VND::VND() {
}

VND::~VND() {
}

Resultados VND::crossExchange(MeuArquivo valores, Resultados resultadosCopia){
    // bool trocaFeita = false;
    // int melhorCustoRota = resultadosCopia.custoRota;
    // int A, B, x, y;
    // for(int rotaA = 0; rotaA < resultadosCopia.contVeiculo - 1; rotaA++){
    //     for(int rotaB = rotaA + 1; rotaB < resultadosCopia.contVeiculo; rotaB++){
    //         for(int i = 1; i < resultadosCopia.rota[rotaA].size() - 1; i++){
    //             for(int j = 1; j < resultadosCopia.rota[rotaB].size() - 1; j++){
    //                 if(resultadosCopia.capacVeiculo[rotaA] - valores.d[(resultadosCopia.rota[rotaA][i])-1] + valores.d[(resultadosCopia.rota[rotaB][j])-1] >= 0  
    //                 && resultadosCopia.capacVeiculo[rotaB] - valores.d[(resultadosCopia.rota[rotaB][j])-1] + valores.d[(resultadosCopia.rota[rotaA][i])-1] >= 0){
    //                     int novoCusto = (resultadosCopia.custoRota
    //                     - valores.c[resultadosCopia.rota[rotaA][i-1]][resultadosCopia.rota[rotaA][i]] - valores.c[resultadosCopia.rota[rotaA][i]][resultadosCopia.rota[rotaA][i+1]]
    //                     - valores.c[resultadosCopia.rota[rotaB][j-1]][resultadosCopia.rota[rotaB][j]] - valores.c[resultadosCopia.rota[rotaB][j]][resultadosCopia.rota[rotaB][j+1]]
    //                     + valores.c[resultadosCopia.rota[rotaA][i-1]][resultadosCopia.rota[rotaB][j]] + valores.c[resultadosCopia.rota[rotaB][j]][resultadosCopia.rota[rotaA][i+1]]
    //                     + valores.c[resultadosCopia.rota[rotaB][j-1]][resultadosCopia.rota[rotaA][i]] + valores.c[resultadosCopia.rota[rotaA][i]][resultadosCopia.rota[rotaB][j+1]]);

                        
    //                     if(novoCusto < melhorCustoRota){
    //                         melhorCustoRota = novoCusto;
    //                         A = rotaA;
    //                         B = rotaB;
    //                         x = i;
    //                         y = j;
    //                         trocaFeita = true;
    //                     }
                        
    //                 }
    //             }
    //         }
    //     }
    // }
    // if(trocaFeita == true){
    //     swap(resultadosCopia.rota[A][x], resultadosCopia.rota[B][y]);
    //     resultadosCopia.custoRota = melhorCustoRota;
    //     resultadosCopia.custoTotal = resultadosCopia.custoRota + resultadosCopia.custoTerceirizacao + resultadosCopia.custoVeiculos;
    //     resultadosCopia.capacVeiculo[A] = resultadosCopia.capacVeiculo[A] - valores.d[(resultadosCopia.rota[A][x])-1] + valores.d[(resultadosCopia.rota[B][y])-1]; 
    //     resultadosCopia.capacVeiculo[B] = resultadosCopia.capacVeiculo[B] - valores.d[(resultadosCopia.rota[B][y])-1] + valores.d[(resultadosCopia.rota[A][x])-1];
    // }
    return resultadosCopia;
}

Resultados VND::swap(MeuArquivo val, Resultados resCopia){
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoRoteamento;
    int A, x, y;
    for(int rotaN = 0; rotaN < resCopia.contVeiculo; rotaN++){
        // cout << "Rota: " << rotaN + 1 << endl;
        for(int i = 1; i < resCopia.rota[rotaN].size() - 2; i++){
            for(int j = i + 1; j < resCopia.rota[rotaN].size() - 1; j++){
                // cout << "Comparando " << resCopia.rota[rotaN][i] << " com " << resCopia.rota[rotaN][j] << endl;
                int novoCusto;
                if(j == i + 1 || j == i + 2){
                    novoCusto = resCopia.custoRoteamento
                    - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]]
                    - val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][j+1]]
                    + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][j]]
                    + val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][j+1]];
                }else{
                    novoCusto = resCopia.custoRoteamento
                    - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]]
                    - val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]]
                    - val.c[resCopia.rota[rotaN][j-1]][resCopia.rota[rotaN][j]]
                    - val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][j+1]]
                    + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][j]]
                    + val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][i+1]]
                    + val.c[resCopia.rota[rotaN][j-1]][resCopia.rota[rotaN][i]]
                    + val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][j+1]];
                }
                // cout << "Melhor custo ate entao: " << melhorCusto << " - Novo custo encontrado: " << novoCusto << endl;
                if(novoCusto < melhorCusto){
                    // cout << ">>>>>>>>>>>>>>>>>>> Novo custo encontrado é melhor <<<<<<<<<<<<<<<<<<<<<" << endl;
                    melhorCusto = novoCusto;
                    A = rotaN;
                    x = i;
                    y = j;
                    trocaFeita = true;
                }
            }
        }
    }
    if(trocaFeita == true){
        std::swap(resCopia.rota[A][x], resCopia.rota[A][y]);
        resCopia.custoRoteamento = melhorCusto;
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        // resCopia.custoRota[A] = melhorCusto;
    }
    return resCopia;
}

Resultados VND::algoritmoVND(MeuArquivo val, Resultados res){
    int r = 3;
    int k = 1;
    Resultados resCopia = res;
    // CORRIGIR DEPOIS: while(k<=r)
    while(k<=1){
        switch (k)
        {
        case 1:
            // cout << "Vai fazer o swap" << endl;
            resCopia = swap(val, resCopia);
            break;
        case 2:
            if(res.contVeiculo > 1){
                resCopia = crossExchange(val, resCopia);
                break;
            }
            break;
        case 3:
            
            break;
        }
        if(resCopia.custoTotal < res.custoTotal){
            res = resCopia;
            // CORRIGIR DEPOIS: k = 1
            k = 1;
        }else{
            k++;
        }
    }
    return res;
}