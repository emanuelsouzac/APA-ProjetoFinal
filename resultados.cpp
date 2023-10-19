#include "resultados.h"

Resultados::Resultados(MeuArquivo valores) {
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
