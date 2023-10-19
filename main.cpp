#include <iostream>
#include <fstream>
#include <vector>

#include "valores.h"
#include "resultados.h"
#include "guloso.h"
#include "vnd.h" 

using namespace std;


int main() {   

    string instancia;

    cout << "Instancia: ";
    cin >> instancia;

    MeuArquivo valores(instancia);
    Resultados resultados(valores);
    Guloso guloso;
    VND vnd;

    cout << endl << "Resultado guloso para a instancia " << instancia << endl << endl;
    guloso.algoritmoGuloso(valores, resultados);

    cout << endl << "Teste : " << resultados.custoRota << endl;

    cout << endl << "Resultado do VND para a instancia " << instancia << endl << endl;
    vnd.algoritmoVND(resultados);

    return 0;
}
