#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "valores.h"
#include "resultados.h"
#include "guloso.h"
#include "vnd.h" 

using namespace std;

int main() {   

    // auto start_time = chrono::high_resolution_clock::now();

    string instancia;

    cout << "Instancia: ";
    cin >> instancia;

    MeuArquivo valores(instancia);
    Resultados resultados(valores);
    Guloso guloso;
    VND vnd;

    cout << endl << ">>>>>>>>>> Guloso - " << instancia << " <<<<<<<<<<" << endl << endl;
    resultados = guloso.algoritmoGuloso(valores, resultados);
    resultados.mostraResultados(valores);

    cout << endl << ">>>>>>>>>> VND - " << instancia << " <<<<<<<<<<" << endl << endl;
    resultados = vnd.algoritmoVND(valores, resultados);
    resultados.mostraResultados(valores);

    // auto end_time = chrono::high_resolution_clock::now();

    // auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    // cout << "Tempo de execução: " << duration.count() << " milliseconds" << endl;

    return 0;
}
