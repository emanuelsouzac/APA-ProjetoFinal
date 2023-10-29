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
    
    for (int elemento : terceirizados) {
        cout << elemento << ' ';
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

void Resultados::salvaResultados(string instancia){
    ofstream arquivo(instancia);

    if (arquivo.is_open()) {
        arquivo  << custoTotal << endl;
        arquivo  <<  custoRoteamento << endl;
        arquivo  << custoVeiculos << endl;
        arquivo << custoTerceirizacao << endl << endl;

        for (int elemento : terceirizados) {
            arquivo << elemento << ' ';
        }

        arquivo << endl << endl <<  contVeiculo << endl;
        for (int i = 0; i < contVeiculo; i++) {
            for (int j = 1; j < rota[i].size() - 1; j++) {
                arquivo << rota[i][j] << ' ';
            }
            arquivo << endl;
        }

        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
    }
}