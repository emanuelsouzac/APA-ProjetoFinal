#include "resultados.h"

Resultados::Resultados(MeuArquivo val) {
    custoTotal = 0;
    custoRoteamento = 0;
    custoRota.resize(val.k, 0);
    custoVeiculos = 0;
    custoTerceirizacao = 0;

    capacVeiculo.resize(val.k, val.Q);
    rota.resize(val.k);

    contVeiculo = 0;
    contClientes = 0;
}

Resultados::~Resultados() {

}

void Resultados::mostraResultados(MeuArquivo val){
    cout << "Valor total da solucao: " << custoTotal << endl;
    cout << "Custo de roteamento: " << custoRoteamento << endl;
    cout << "Custo associado a utilizacao dos veiculos: " << custoVeiculos << endl;
    cout << "Custo de terceirizacao: " << custoTerceirizacao << endl;
    cout << endl << "Lista de clientes terceirizados: ";
    
    cout << endl;
    for (int elemento : terceirizados) {
        cout << elemento + 1 << ' ';
    }

    cout << endl << endl << "Numero de rotas: " << contVeiculo << endl;
    for (int i = 0; i < contVeiculo; i++) {
        cout << "Rota " << i + 1 << ": ";
        for (int elemento : rota[i]) {
            cout << elemento << ' ';
        }
        cout << endl;
    }

    // cout << endl << "Custo de cada rota" << endl;
    // for (int i = 0; i < val.k; i++) {
    //     cout << "Rota " << i + 1 << ": " << custoRota[i] << endl;
    // }
    // cout << endl;

    // cout << endl << endl << "Capacidade restante dos veiculos" << endl;
    // for (int i = 0; i < val.k; i++) {
    //     cout << "Carro " << i + 1 << ": " << capacVeiculo[i] << endl;
    // }

    // cout << endl << endl << "O total de clientes atendidos foi de " << contClientes << " de no minimo " << val.L << endl;
}