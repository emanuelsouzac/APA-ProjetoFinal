#include "resultados.h"

Resultados::Resultados(MeuArquivo valores) {
    custoTotal = 0;
    custoRota = 0;
    custoVeiculos = 0;
    custoTerceirizacao = 0;

    capacVeiculo.resize(valores.k, valores.Q);
    rota.resize(valores.k);

    contVeiculo = 0;
    contClientes = 0;
}

Resultados::~Resultados() {

}

void Resultados::mostraResultados(MeuArquivo valores){
    cout << "Valor total da solucao: " << custoTotal << endl;
    cout << "Custo de roteamento: " << custoRota << endl;
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

    cout << endl << endl << "Capacidade restante dos veiculos" << endl;
    for (int i = 0; i < valores.k; i++) {
        cout << "Carro " << i + 1 << ": " << capacVeiculo[i] << endl;
    }

    cout << endl << endl << "O total de clientes atendidos foi de " << contClientes << " de no minimo " << valores.L << endl;
}