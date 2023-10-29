#include "ils.h"

#include <random>

ILS::ILS() {
}

ILS::~ILS() {
}

Resultados ILS::pertubacao(MeuArquivo val, Resultados resCopia){
    // cout << "Entrou na pertubacao" << endl;
    for(int rotaN = 0; rotaN < resCopia.contVeiculo; rotaN++){
        // cout << "Pertubacao na rota " << rotaN + 1 << endl;
        // Gerar um índice aleatório entre 1 e rota.size() - 2
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribuicao(1, resCopia.rota[rotaN].size() - 2);
        
        int indice1 = distribuicao(gen);
        int indice2 = distribuicao(gen);
        
        // Garantir que os índices gerados são diferentes
        while (indice1 == indice2) {
            indice2 = distribuicao(gen);
            // cout << "teste" << endl;
        }

        int i, j;
        if(indice2>indice1){
            i = indice1;
            j = indice2;
        }else{
            i = indice2;
            j = indice1;
        }

        // cout << "Vai trocar " << i << " com " << j << endl;

        // cout << "Rota " << rotaN + 1 << " antes da pertubacao: ";
        // for (int elemento : resCopia.rota[rotaN]) {
        //     cout << elemento << ' ';
        // }
        // cout << endl;

        if(j == i + 1 || j == i + 2){
            resCopia.custoRoteamento = resCopia.custoRoteamento
            - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]]
            - val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][j+1]]
            + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][j]]
            + val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][j+1]];
        }else{
            resCopia.custoRoteamento = resCopia.custoRoteamento
            - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]]
            - val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]]
            - val.c[resCopia.rota[rotaN][j-1]][resCopia.rota[rotaN][j]]
            - val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][j+1]]
            + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][j]]
            + val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][i+1]]
            + val.c[resCopia.rota[rotaN][j-1]][resCopia.rota[rotaN][i]]
            + val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][j+1]];
        }

        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        std::swap(resCopia.rota[rotaN][indice1], resCopia.rota[rotaN][indice2]);

        // cout << "Rota " << rotaN + 1 << " depois da pertubacao: ";
        // for (int elemento : resCopia.rota[rotaN]) {
        //     cout << elemento << ' ';
        // }
        // cout << endl;
    }

    return resCopia;
}

Resultados ILS::pertubacaoEntreRotas(MeuArquivo val, Resultados resCopia){
    // cout << "Entrou na pertubacao entre rotas" << endl;

    bool trocou = false;

    while(trocou == false){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribuicao(0, resCopia.contVeiculo - 1);
        
        int rotaN = distribuicao(gen);
        int rotaM = distribuicao(gen);

        while (rotaN == rotaM) {
            rotaM = distribuicao(gen);
        }

        uniform_int_distribution<int> distribuicao2(1, resCopia.rota[rotaN].size() - 2);
        uniform_int_distribution<int> distribuicao3(1, resCopia.rota[rotaM].size() - 2);
            
        int i = distribuicao2(gen);
        int j = distribuicao3(gen);

        // cout << "Vai trocar " << i << " da rota " << rotaN << " com " << j << " da rota " << rotaM << endl;

        // cout << "Rota " << rotaN + 1 << " antes da pertubacao: ";
        // for (int elemento : resCopia.rota[rotaN]) {
        //     cout << elemento << ' ';
        // }
        // cout << endl;

        // cout << "Rota " << rotaM + 1 << " antes da pertubacao: ";
        // for (int elemento : resCopia.rota[rotaM]) {
        //     cout << elemento << ' ';
        // }
        // cout << endl;

        if((val.Q - resCopia.capacVeiculo[rotaN]) - val.d[resCopia.rota[rotaN][i] - 1] + val.d[resCopia.rota[rotaM][j] - 1] <= val.Q
            && (val.Q - resCopia.capacVeiculo[rotaM]) - val.d[resCopia.rota[rotaM][j] - 1] + val.d[resCopia.rota[rotaN][i] - 1] <= val.Q){
                resCopia.custoRoteamento = resCopia.custoRoteamento
                - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]]
                - val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]]
                - val.c[resCopia.rota[rotaM][j-1]][resCopia.rota[rotaM][j]]
                - val.c[resCopia.rota[rotaM][j]][resCopia.rota[rotaM][j+1]]
                + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaM][j]]
                + val.c[resCopia.rota[rotaM][j]][resCopia.rota[rotaN][i+1]]
                + val.c[resCopia.rota[rotaM][j-1]][resCopia.rota[rotaN][i]]
                + val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaM][j+1]];
                resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
                resCopia.capacVeiculo[rotaN] = resCopia.capacVeiculo[rotaN] + val.d[resCopia.rota[rotaN][i] - 1] - val.d[resCopia.rota[rotaM][j] - 1];
                resCopia.capacVeiculo[rotaM] = resCopia.capacVeiculo[rotaM] + val.d[resCopia.rota[rotaM][j] - 1] - val.d[resCopia.rota[rotaN][i] - 1];
                std::swap(resCopia.rota[rotaN][i], resCopia.rota[rotaM][j]);
                trocou = true;
        }

        // cout << "Rota " << rotaN + 1 << " antes da pertubacao: ";
        // for (int elemento : resCopia.rota[rotaN]) {
        //     cout << elemento << ' ';
        // }
        // cout << endl;

        // cout << "Rota " << rotaM + 1 << " antes da pertubacao: ";
        // for (int elemento : resCopia.rota[rotaM]) {
        //     cout << elemento << ' ';
        // }
        // cout << endl;
    }

    return resCopia;
}

Resultados ILS::algoritmoILS(MeuArquivo val, Resultados res){
    Resultados resCopia;
    VND vnd;
    int n = 0;
    while(n < 1000){
        // cout << "ILS: " << n << endl;
        
        // cout << endl;
        resCopia = pertubacao(val, res);
        if(resCopia.contVeiculo>1){resCopia = pertubacaoEntreRotas(val, resCopia);}
        // cout << endl;

        resCopia = vnd.algoritmoVND(val, resCopia);

        if(resCopia.custoTotal < res.custoTotal){
            res = resCopia;
            n = 0;
        }else{
            n = n + 1;
        }
    }
    return res;
}