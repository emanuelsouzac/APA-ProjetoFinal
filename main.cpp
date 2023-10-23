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
    resultados = guloso.algoritmoGuloso(valores, resultados);
    resultados.mostraResultados(valores);

    //cout << endl << "Resultado VND para a instancia " << instancia << endl << endl;
    //resultados = vnd.algoritmoVND(valores, resultados);
    //resultados.mostraResultados(valores);

    return 0;
}
