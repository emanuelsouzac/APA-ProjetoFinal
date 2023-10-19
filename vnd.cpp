#include "vnd.h"

VND::VND() {
}

VND::~VND() {
}

void VND::algoritmoVND(Resultados resultados){
    cout << "Valor total da solucao: " << resultados.custoRota + resultados.custoTerceirizacao + resultados.custoVeiculos << endl;
    cout << "Custo de roteamento: " << resultados.custoRota << endl;
    cout << "Custo associado a utilizacao dos veiculos: " << resultados.custoVeiculos << endl;
    cout << "Custo de terceirizacao: " << resultados.custoTerceirizacao << endl;
}