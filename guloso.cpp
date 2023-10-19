#include "guloso.h"

#define NUM 1000000;

Guloso::Guloso() {
    // Inicialize os membros privados, se houver algum
}

Guloso::~Guloso() {
    // Destrutor vazio
}

void Guloso::algoritmoGuloso(MeuArquivo valores) {
    
    Resultados resultados(valores);

    vector<bool> clienteAtendido(valores.n, false);
    vector<int> veiculo(valores.k, valores.Q);
    int contVeiculo = 0;
    int contClientes = 0;

    vector<vector<int>> rotas(valores.k);

    int referencial = 0;
    int menor;
    int pos;

    while (1)
    {
        menor = NUM;
        for (int i = 0; i < valores.n; i++)
        {
            if (clienteAtendido[i] == false && valores.d[i] < menor)
            {
                menor = valores.d[i];
                pos = i;
            }
        }
        if (veiculo[contVeiculo] - menor < 0)
        {
            contVeiculo++;
            resultados.custoRota += valores.c[referencial][0];
            if (contClientes > valores.L)
            {
                break;
            }
            referencial = 0;
        }
        else
        {
            clienteAtendido[pos] = true;
            resultados.custoRota += valores.c[referencial][pos + 1];
            veiculo[contVeiculo] -= menor;
            contClientes++;
            referencial = pos;
            rotas[contVeiculo].push_back(pos + 1);
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

    resultados.custoVeiculos = contVeiculo * valores.r;

    cout << "Valor total da solucao: " << resultados.custoRota + resultados.custoTerceirizacao + resultados.custoVeiculos << endl;
    cout << "Custo de roteamento: " << resultados.custoRota << endl;
    cout << "Custo associado a utilizacao dos veiculos: " << resultados.custoVeiculos << endl;
    cout << "Custo de terceirizacao: " << resultados.custoTerceirizacao << endl;
    cout << endl << "Lista de clientes terceirizados: ";

    //for (int i = 0; i < valores.n; i++)
    //{
    //    if (clienteAtendido[i] == false)
    //    {
    //        cout << i + 1 << " ";
    //    }
    //}
    
    cout << endl;
    for (int elemento : resultados.terceirizados) {
        cout << elemento + 1 << ' ';
    }

    cout << endl << endl << "Numero de rotas: " << contVeiculo << endl;
    for (int i = 0; i < valores.k; i++) {
        if(!rotas[i].empty()){
            cout << "Rota " << i + 1 << ": ";
            for (int elemento : rotas[i]) {
                cout << elemento << ' ';
            }
            cout << endl;
        }
    }
}