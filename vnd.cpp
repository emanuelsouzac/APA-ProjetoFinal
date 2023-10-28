#include "vnd.h"

VND::VND() {
}

VND::~VND() {
}

Resultados VND::swap(MeuArquivo val, Resultados resCopia){
    // cout << "Entrou no swap" << endl;
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
        // cout << "Fez o swap entre o " << resCopia.rota[A][x] << " e o " << resCopia.rota[A][y] << endl;
        resCopia.custoRoteamento = melhorCusto;
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        std::swap(resCopia.rota[A][x], resCopia.rota[A][y]);
        // resCopia.custoRota[A] = melhorCusto;
    }
    return resCopia;
}

Resultados VND::reInsertion(MeuArquivo val, Resultados resCopia){
    // cout << "Entrou no reInsertion" << endl;
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoRoteamento;
    int A, x, y;
    for(int rotaN = 0; rotaN < resCopia.contVeiculo; rotaN++){
        // cout << "Rota: " << rotaN + 1 << endl;
        for(int i = 1; i < resCopia.rota[rotaN].size() - 1; i++){
            for(int j = 0; j < resCopia.rota[rotaN].size() - 1; j++){
                if(j-i > 1 || j-i < -2){
                    // cout << resCopia.rota[rotaN][i] << " " << resCopia.rota[rotaN][j] << endl;
                    int novoCusto = resCopia.custoRoteamento
                    - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]] // i-1 até o i
                    - val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]] // i até o i+1
                    - val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][j+1]] // j até o j+1
                    + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i+1]] // i-1 até o i+1
                    + val.c[resCopia.rota[rotaN][j]][resCopia.rota[rotaN][i]] // j até o i
                    + val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][j+1]]; // i até o j+1
                    // cout << "Melhor custo ate entao: " << melhorCusto << " - Novo custo encontrado: " << novoCusto << endl;
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
        // cout << "Fez o reinsertion de " << resCopia.rota[A][x] << " na frente de " << resCopia.rota[A][y] << " e o custo ficou " << melhorCusto << endl;
        resCopia.custoRoteamento = melhorCusto;
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        resCopia.rota[A].insert(resCopia.rota[A].begin() + y + 1, resCopia.rota[A][x]);
        if(x>y){resCopia.rota[A].erase(resCopia.rota[A].begin() + x+1);}
        else{resCopia.rota[A].erase(resCopia.rota[A].begin() + x);}
    }
    return resCopia;
}

Resultados VND::crossExchange(MeuArquivo val, Resultados resCopia){
    // cout << "Entrou na troca cruzada" << endl;
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoRoteamento;
    int A, B, x, y;
    for(int rotaN = 0; rotaN < resCopia.contVeiculo - 1; rotaN++){
        for(int rotaM = rotaN + 1; rotaM < resCopia.contVeiculo; rotaM++){
            for(int i = 1; i < resCopia.rota[rotaN].size() - 1; i++){
                for(int j = 1; j < resCopia.rota[rotaM].size() - 1; j++){
                    if((val.Q - resCopia.capacVeiculo[rotaN]) - val.d[resCopia.rota[rotaN][i] - 1] + val.d[resCopia.rota[rotaM][j] - 1] <= val.Q
                    && (val.Q - resCopia.capacVeiculo[rotaM]) - val.d[resCopia.rota[rotaM][j] - 1] + val.d[resCopia.rota[rotaN][i] - 1] <= val.Q){
                        // cout << resCopia.rota[rotaN][i] << " (d = " << val.d[resCopia.rota[rotaN][i] - 1] << ")" << " consegue trocar com " << resCopia.rota[rotaM][j] << " (d = " << val.d[resCopia.rota[rotaM][j] - 1] << ")" << endl;
                        
                        // cout << "Conta para a rota " << rotaN + 1 << ": "
                        // << val.Q - resCopia.capacVeiculo[rotaN] << " - "
                        // << val.d[resCopia.rota[rotaN][i] - 1] << " + "
                        // << val.d[resCopia.rota[rotaM][j] - 1] << " = "
                        // << val.Q - resCopia.capacVeiculo[rotaN] - val.d[resCopia.rota[rotaN][i] - 1] + val.d[resCopia.rota[rotaM][j] - 1]
                        // << endl;
                        
                        // cout << "Conta para a rota " << rotaM + 1 << ": "
                        // << val.Q - resCopia.capacVeiculo[rotaM] << " - "
                        // << val.d[resCopia.rota[rotaM][j] - 1] << " + "
                        // << val.d[resCopia.rota[rotaN][i] - 1] << " = "
                        // << val.Q - resCopia.capacVeiculo[rotaM] - val.d[resCopia.rota[rotaM][j] - 1] + val.d[resCopia.rota[rotaN][i] - 1]
                        // << endl;
                        
                        int novoCusto = resCopia.custoRoteamento
                        - val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaN][i]]
                        - val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]]
                        - val.c[resCopia.rota[rotaM][j-1]][resCopia.rota[rotaM][j]]
                        - val.c[resCopia.rota[rotaM][j]][resCopia.rota[rotaM][j+1]]
                        + val.c[resCopia.rota[rotaN][i-1]][resCopia.rota[rotaM][j]]
                        + val.c[resCopia.rota[rotaM][j]][resCopia.rota[rotaN][i+1]]
                        + val.c[resCopia.rota[rotaM][j-1]][resCopia.rota[rotaN][i]]
                        + val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaM][j+1]];
                        // cout << "Melhor custo ate entao: " << melhorCusto << " - Novo custo encontrado: " << novoCusto << endl;
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
        // cout << "Fez a troca cruzada entre o " << resCopia.rota[A][x] << " e o " << resCopia.rota[B][y] << endl;
        resCopia.custoRoteamento = melhorCusto;
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        resCopia.capacVeiculo[A] = resCopia.capacVeiculo[A] + val.d[resCopia.rota[A][x] - 1] - val.d[resCopia.rota[B][y] - 1];
        resCopia.capacVeiculo[B] = resCopia.capacVeiculo[B] + val.d[resCopia.rota[B][y] - 1] - val.d[resCopia.rota[A][x] - 1];
        std::swap(resCopia.rota[A][x], resCopia.rota[B][y]);
    }
    return resCopia;
}

Resultados VND::terceiriza(MeuArquivo val, Resultados resCopia){
    // cout << "Entrou no terceiriza" << endl;
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
                novoCusto -= val.r; // se a rota for acabar, decrementar o custo do carro
            }
            // cout << "Melhor custo ate entao: " << melhorCusto << " - Novo custo encontrado: " << novoCusto << endl;
            if(novoCusto < melhorCusto){
                melhorCusto = novoCusto;
                A = rotaN;
                x = i;
                trocaFeita = true;
            }
        }
    }
    if(trocaFeita == true){
        // cout << "Terceirizando o cliente " << resCopia.rota[A][x] << " da rota " << A + 1 << endl;
        resCopia.capacVeiculo[A] += val.d[resCopia.rota[A][x]-1]; // atualizar a capacidade do veiculo/rota
        resCopia.custoRoteamento = resCopia.custoRoteamento - val.c[resCopia.rota[A][x-1]][resCopia.rota[A][x]] - val.c[resCopia.rota[A][x]][resCopia.rota[A][x+1]] + val.c[resCopia.rota[A][x-1]][resCopia.rota[A][x+1]]; // atualizar o custo da rota
        resCopia.custoTerceirizacao += val.p[resCopia.rota[A][x]-1]; // atualizar o custo da terceirizacao
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos; // atualizar o custo total
        resCopia.terceirizados.push_back(resCopia.rota[A][x]); // adicionar na lista de terceirizados
        resCopia.rota[A].erase(resCopia.rota[A].begin() + x); // remover na lista da rota
        resCopia.contClientes--;
        // cout << "Numero de itens na rota " << A << ": " << resCopia.rota[A].size() << endl;
        if(resCopia.rota[A].size() == 2){
            // cout << "!!!!!!!!!!!!!!!!! Uma rota ficou vazia !!!!!!!!!!!!!!!!!" << endl;
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
    // cout << "Entrou no desterceiriza" << endl;
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoTotal;
    int A, x, y;
    int parada;
    for(int i = 0; i < resCopia.terceirizados.size(); i++){
        // se a rota para onde o contVeiculo ta apontando existe, parada = contVeiculo
        // senão, parada = contVeiculo - 1
        if(resCopia.rota[resCopia.contVeiculo] ==  std::vector<int>()){
            parada = resCopia.contVeiculo;
        }else{
            parada = resCopia.contVeiculo - 1;
        }
        for(int rotaN = 0; rotaN <= parada; rotaN++){
            if(resCopia.capacVeiculo[rotaN] - val.d[resCopia.terceirizados[i] - 1] >= 0){
                // cout << resCopia.terceirizados[i] << " cabe na rota " << rotaN + 1 << endl;
                int novoCusto;
                if(resCopia.rota[rotaN].size()==0){
                    novoCusto = resCopia.custoTotal
                    + val.c[0][resCopia.terceirizados[i]]
                    + val.c[resCopia.terceirizados[i]][0]
                    - val.p[resCopia.terceirizados[i] - 1]
                    + val.r; // custo de usar um novo carro (ou nova rota)
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
        // cout << "Desterceirizou o " << resCopia.terceirizados[x] << " e colocou na rota " << A + 1 << endl;
        if(resCopia.rota[A].size() == 0){
            // cout << "!!!!!!!!!!!!!!!!! Uma rota nova apareceu !!!!!!!!!!!!!!!!!" << endl;
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
                                        + val.c[resCopia.terceirizados[x]][resCopia.rota[A][y+1]]; // atualizar o custo da rota
            resCopia.rota[A].insert(resCopia.rota[A].begin() + y + 1, resCopia.terceirizados[x]); // adicionar na lista da rota
        }
        resCopia.capacVeiculo[A] -= val.d[resCopia.terceirizados[x] - 1]; // atualizar a capacidade do veiculo/rota
        resCopia.custoTerceirizacao -= val.p[resCopia.terceirizados[x] - 1]; // atualizar o custo da terceirizacao
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos; // atualizar o custo total
        resCopia.terceirizados.erase(resCopia.terceirizados.begin() + x); // remover na lista de terceirizados
        resCopia.contClientes++;
    }
    return resCopia;
}

Resultados VND::terceirizaRota(MeuArquivo val, Resultados resCopia){
    // cout << "Entrou no terceirizaRota" << endl;
    bool trocaFeita = false;
    int melhorCusto = resCopia.custoTotal;
    int A, custoDaRota, custoDeTerceirizar;
    for(int rotaN = 0; rotaN < resCopia.contVeiculo; rotaN++){
        if(resCopia.contClientes - (resCopia.rota[rotaN].size() - 2) >= val.L){
            custoDaRota = 0, custoDeTerceirizar = 0;
            // Calcula o custo da rota
            for(int i = 0; i < resCopia.rota[rotaN].size() - 1; i++){
                custoDaRota += val.c[resCopia.rota[rotaN][i]][resCopia.rota[rotaN][i+1]];
            }
            // Calcula o custo de terceirizar aquela rota
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
        // cout << "FEZ A TERCEIRIZACAO DA ROTA " << A + 1 << endl;
        // atualiza os valores dos custos
        resCopia.custoRoteamento -= custoDaRota;
        resCopia.custoTerceirizacao += custoDeTerceirizar;
        resCopia.custoVeiculos -= val.r;
        resCopia.custoTotal = resCopia.custoRoteamento + resCopia.custoTerceirizacao + resCopia.custoVeiculos;
        // atualiza o contador de clientes
        resCopia.contClientes -= (resCopia.rota[A].size() - 2);
        // atualiza a lista de terceirizados
        for(int i = 1; i < resCopia.rota[A].size() - 1; i++){
            resCopia.terceirizados.push_back(resCopia.rota[A][i]);
        }
        // atualiza as rotas
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
    Resultados resCopia = res; // Resultados &resCopia = res;
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
            // cout << resCopia.contClientes << " - " << val.L << endl;
            if(resCopia.contClientes > val.L){resCopia = terceirizaRota(val, resCopia);}
            break;
        case 5:
            // cout << resCopia.contClientes << " - " << val.L << endl;
            if(resCopia.contClientes > val.L){resCopia = terceiriza(val, resCopia);}
            break;
        case 6:
            // cout << resCopia.contClientes << " - " << val.n << endl;
            if(resCopia.contClientes < val.n){resCopia = desterceiriza(val, resCopia);}
            break;
        }
        if(resCopia.custoTotal < res.custoTotal){
            // cout << "Voltando para o começo" << endl;
            res = resCopia;
            k = 1;
        }else{
            // cout << "Avançando nas estruturas" << endl;
            k = k + 1;
        }
    }
    cout << endl;
    return res;
}