#include <iostream>
#include <fstream>
#include <vector>

#include "valores.h"
#include "resultados.h"
#include "guloso.h"

using namespace std;


int main() {   

    string instancia;

    cout << "Instancia: ";
    cin >> instancia;

    MeuArquivo valores(instancia);
    Guloso guloso;

    cout << endl << "Resultado guloso para a instancia " << instancia << endl << endl;
    guloso.algoritmoGuloso(valores);

    return 0;
}
