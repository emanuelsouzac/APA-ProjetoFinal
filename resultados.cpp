#include "resultados.h"

Resultados::Resultados(MeuArquivo valores) {
    custoTotal = 0;
    custoRota = 0;
    custoVeiculos = 0;
    custoTerceirizacao = 0;

    veiculo.resize(valores.k, valores.Q);
    rotas.resize(valores.k);

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