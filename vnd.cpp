#include "vnd.h"

VND::VND() {
}

VND::~VND() {
}

Resultados VND::swap(MeuArquivo val, Resultados resCopia){
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoRoteamento;
    int A, x, y;

    for(int rotaN = 0; rotaN < resCopia.contVeiculo; rotaN++){
        for(int i = 1; i < resCopia.rota[rotaN].size() - 2; i++){
            for(int j = i + 1; j < resCopia.rota[rotaN].size() - 1; j++){
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
                if(novoCusto < melhorCusto){
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
        resCopia.custoRoteamento = melhorCusto;
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        std::swap(resCopia.rota[A][x], resCopia.rota[A][y]);
    }

    return resCopia;
}

Resultados VND::reInsertion(MeuArquivo val, Resultados resCopia){
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoRoteamento;
    int A, x, y;

    for(int rotaN = 0; rotaN < resCopia.contVeiculo; rotaN++){
        for(int i = 1; i < resCopia.rota[rotaN].size() - 1; i++){
            for(int j = 0; j < resCopia.rota[rotaN].size() - 1; j++){
                if(j-i > 1 || j-i < -2){
                    int novoCusto = resCopia.custoRoteamento
                    - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]]
                    - val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]]
                    - val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][j+1]]
                    + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i+1]]
                    + val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][i]]
                    + val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][j+1]];
                    if(novoCusto < melhorCusto){
                        melhorCusto = novoCusto;
                        A = rotaN;
                        x = i;
                        y = j;
                        trocaFeita = true;
                    }
                }
            }
        }
    }

    if(trocaFeita == true){
        resCopia.custoRoteamento = melhorCusto;
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        resCopia.rota[A].insert(resCopia.rota[A].begin() + y + 1, resCopia.rota[A][x]);
        if(x>y){resCopia.rota[A].erase(resCopia.rota[A].begin() + x+1);}
        else{resCopia.rota[A].erase(resCopia.rota[A].begin() + x);}
    }

    return resCopia;
}

Resultados VND::crossExchange(MeuArquivo val, Resultados resCopia){
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoRoteamento;
    int A, B, x, y;
    
    for(int rotaN = 0; rotaN < resCopia.contVeiculo - 1; rotaN++){
        for(int rotaM = rotaN + 1; rotaM < resCopia.contVeiculo; rotaM++){
            for(int i = 1; i < resCopia.rota[rotaN].size() - 1; i++){
                for(int j = 1; j < resCopia.rota[rotaM].size() - 1; j++){
                    if((val.Q - resCopia.capacVeiculo[rotaN]) - val.d[resCopia.rota[rotaN][i] - 1] + val.d[resCopia.rota[rotaM][j] - 1] <= val.Q
                    && (val.Q - resCopia.capacVeiculo[rotaM]) - val.d[resCopia.rota[rotaM][j] - 1] + val.d[resCopia.rota[rotaN][i] - 1] <= val.Q){
                        int novoCusto = resCopia.custoRoteamento
                        - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]]
                        - val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]]
                        - val.c[resCopia.rota[rotaM][j-1]][resCopia.rota[rotaM][j]]
                        - val.c[resCopia.rota[rotaM][j]][resCopia.rota[rotaM][j+1]]
                        + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaM][j]]
                        + val.c[resCopia.rota[rotaM][j]][resCopia.rota[rotaN][i+1]]
                        + val.c[resCopia.rota[rotaM][j-1]][resCopia.rota[rotaN][i]]
                        + val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaM][j+1]];
                        if(novoCusto < melhorCusto){
                            melhorCusto = novoCusto;
                            A = rotaN;
                            B = rotaM;
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
        resCopia.custoRoteamento = melhorCusto;
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        resCopia.capacVeiculo[A] = resCopia.capacVeiculo[A] + val.d[resCopia.rota[A][x] - 1] - val.d[resCopia.rota[B][y] - 1];
        resCopia.capacVeiculo[B] = resCopia.capacVeiculo[B] + val.d[resCopia.rota[B][y] - 1] - val.d[resCopia.rota[A][x] - 1];
        std::swap(resCopia.rota[A][x], resCopia.rota[B][y]);
    }

    return resCopia;
}

Resultados VND::terceiriza(MeuArquivo val, Resultados resCopia){
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoTotal;
    int A, x;
    
    for(int rotaN = 0; rotaN < resCopia.contVeiculo; rotaN++){
        for(int i = 1; i < resCopia.rota[rotaN].size() - 1; i++){
            int novoCusto;
            novoCusto = resCopia.custoTotal
                - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]]
                - val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]]
                + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i+1]]
                + val.p[resCopia.rota[rotaN][i]-1];
            if(resCopia.rota[rotaN].size()==3){
                novoCusto -= val.r;
            }
            if(novoCusto < melhorCusto){
                melhorCusto = novoCusto;
                A = rotaN;
                x = i;
                trocaFeita = true;
            }
        }
    }

    if(trocaFeita == true){
        resCopia.capacVeiculo[A] += val.d[resCopia.rota[A][x]-1];
        resCopia.custoRoteamento = resCopia.custoRoteamento
                                - val.c[resCopia.rota[A][x-1]][resCopia.rota[A][x]]
                                - val.c[resCopia.rota[A][x]][resCopia.rota[A][x+1]]
                                + val.c[resCopia.rota[A][x-1]][resCopia.rota[A][x+1]];
        resCopia.custoTerceirizacao += val.p[resCopia.rota[A][x]-1];
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        resCopia.terceirizados.push_back(resCopia.rota[A][x]);
        resCopia.rota[A].erase(resCopia.rota[A].begin() + x);
        resCopia.contClientes--;
        if(resCopia.rota[A].size() == 2){
            // Tratamento para uma eventual rota vazia
            if(A == resCopia.contVeiculo - 1){
                resCopia.rota[A].clear();
                resCopia.contVeiculo--;
            }else{
                resCopia.contVeiculo--;
                for(int i = A; i < resCopia.contVeiculo; i++){
                    resCopia.rota[i] = resCopia.rota[i+1];
                    resCopia.capacVeiculo[i] = resCopia.capacVeiculo[i+1];
                }
                resCopia.rota[resCopia.contVeiculo].clear();
                resCopia.capacVeiculo[resCopia.contVeiculo] = val.Q;
            }
            resCopia.custoTotal -= val.r;
            resCopia.custoVeiculos -= val.r;
        }
    }

    return resCopia;
}

Resultados VND::desterceiriza(MeuArquivo val, Resultados resCopia){
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoTotal;
    int A, x, y;
    int parada;

    for(int i = 0; i < resCopia.terceirizados.size(); i++){
        // Se a rota para onde o contVeiculo apontar existir, parada = contVeiculo
        // Senão, parada = contVeiculo - 1
        // A ideia é analisar também o custo de inserir numa possível rota vazia
        if(resCopia.rota[resCopia.contVeiculo] ==  std::vector<int>()){
            parada = resCopia.contVeiculo;
        }else{
            parada = resCopia.contVeiculo - 1;
        }
        for(int rotaN = 0; rotaN <= parada; rotaN++){
            if(resCopia.capacVeiculo[rotaN] - val.d[resCopia.terceirizados[i] - 1] >= 0){
                int novoCusto;
                if(resCopia.rota[rotaN].size()==0){
                    novoCusto = resCopia.custoTotal
                    + val.c[0][resCopia.terceirizados[i]]
                    + val.c[resCopia.terceirizados[i]][0]
                    - val.p[resCopia.terceirizados[i] - 1]
                    + val.r;
                    if(novoCusto < melhorCusto){
                        melhorCusto = novoCusto;
                        A = rotaN;
                        x = i;
                        trocaFeita = true;
                    }
                }else{
                    for(int j = 0; j < resCopia.rota[rotaN].size() - 1; j++){
                        novoCusto = resCopia.custoTotal
                            - val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][j+1]]
                            + val.c[resCopia.rota[rotaN][j]][resCopia.terceirizados[i]]
                            + val.c[resCopia.terceirizados[i]][resCopia.rota[rotaN][j+1]]
                            - val.p[resCopia.terceirizados[i] - 1];
                        if(novoCusto < melhorCusto){
                            melhorCusto = novoCusto;
                            A = rotaN;
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
        if(resCopia.rota[A].size() == 0){
            resCopia.rota[A] = {0, resCopia.terceirizados[x], 0};
            resCopia.custoRoteamento = resCopia.custoRoteamento
                                        + val.c[0][resCopia.terceirizados[x]]
                                        + val.c[resCopia.terceirizados[x]][0];
            resCopia.custoVeiculos += val.r;
            resCopia.contVeiculo++;
        }else{
            resCopia.custoRoteamento = resCopia.custoRoteamento
                                        - val.c[resCopia.rota[A][y]][resCopia.rota[A][y+1]]
                                        + val.c[resCopia.rota[A][y]][resCopia.terceirizados[x]]
                                        + val.c[resCopia.terceirizados[x]][resCopia.rota[A][y+1]];
            resCopia.rota[A].insert(resCopia.rota[A].begin() + y + 1, resCopia.terceirizados[x]);
        }
        resCopia.capacVeiculo[A] -= val.d[resCopia.terceirizados[x] - 1];
        resCopia.custoTerceirizacao -= val.p[resCopia.terceirizados[x] - 1];
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        resCopia.terceirizados.erase(resCopia.terceirizados.begin() + x);
        resCopia.contClientes++;
    }

    return resCopia;
}

Resultados VND::terceirizaRota(MeuArquivo val, Resultados resCopia){
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoTotal;
    int A, custoDaRota, custoDeTerceirizar;

    for(int rotaN = 0; rotaN < resCopia.contVeiculo; rotaN++){
        if(resCopia.contClientes - (resCopia.rota[rotaN].size() - 2) >= val.L){
            custoDaRota = 0, custoDeTerceirizar = 0;
            for(int i = 0; i < resCopia.rota[rotaN].size() - 1; i++){
                custoDaRota += val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]];
            }
            for(int i = 1; i < resCopia.rota[rotaN].size() - 1; i++){
                custoDeTerceirizar += val.p[resCopia.rota[rotaN][i] - 1];
            }
            int novoCusto = resCopia.custoTotal - custoDaRota - val.r + custoDeTerceirizar;
            if(novoCusto < melhorCusto){
                melhorCusto = novoCusto;
                A = rotaN;
                trocaFeita = true;
            }
        }
    }

    if(trocaFeita == true){
        resCopia.custoRoteamento -= custoDaRota;
        resCopia.custoTerceirizacao += custoDeTerceirizar;
        resCopia.custoVeiculos -= val.r;
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        resCopia.contClientes -= (resCopia.rota[A].size() - 2);
        for(int i = 1; i < resCopia.rota[A].size() - 1; i++){
            resCopia.terceirizados.push_back(resCopia.rota[A][i]);
        }
        // Atualização e reorganização dos vetores das rotas
        if(A == resCopia.contVeiculo - 1){
            resCopia.rota[A].clear();
            resCopia.capacVeiculo[A] = val.Q;
            resCopia.contVeiculo--;
        }else{
            resCopia.contVeiculo--;
            for(int i = A; i < resCopia.contVeiculo; i++){
                resCopia.rota[i] = resCopia.rota[i+1];
                resCopia.capacVeiculo[i] = resCopia.capacVeiculo[i+1];
            }
            resCopia.rota[resCopia.contVeiculo].clear();
            resCopia.capacVeiculo[resCopia.contVeiculo] = val.Q;
        }
    }
    return resCopia;
}

Resultados VND::algoritmoVND(MeuArquivo val, Resultados res){
    int r = 6;
    int k = 1;
    Resultados resCopia = res;
    while(k<=r){
        switch (k)
        {
        case 1:
            resCopia = swap(val, resCopia);
            break;
        case 2:
            resCopia = reInsertion(val, resCopia);
            break;
        case 3:
            if(resCopia.contVeiculo > 1){resCopia = crossExchange(val, resCopia);}
            break;
        case 4:
            if(resCopia.contClientes > val.L){resCopia = terceirizaRota(val, resCopia);}
            break;
        case 5:
            if(resCopia.contClientes > val.L){resCopia = terceiriza(val, resCopia);}
            break;
        case 6:
            if(resCopia.contClientes < val.n){resCopia = desterceiriza(val, resCopia);}
            break;
        }
        if(resCopia.custoTotal < res.custoTotal){
            res = resCopia;
            k = 1;
        }else{
            k = k + 1;
        }
    }
    return res;
}