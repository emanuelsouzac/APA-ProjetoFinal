#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "valores.h"
#include "resultados.h"
#include "guloso.h"
#include "vnd.h"
#include "ils.h"

using namespace std;

int main() {   

    auto start_time = chrono::high_resolution_clock::now();

    string instancia = "n64k9_D";

    // cout << "Instancia: ";
    // cin >> instancia;

    MeuArquivo valores(instancia);
    Resultados resultados(valores);
    Guloso guloso;
    VND vnd;
    ILS ils;

    cout << endl << ">>>>>>>>>> Guloso <<<<<<<<<<" << endl << endl;
    resultados = guloso.algoritmoGuloso(valores, resultados);
    resultados.mostraResultados();
    resultados.salvaResultados("resultadosGuloso/" + instancia + ".txt");

    cout << endl << ">>>>>>>>>> VND <<<<<<<<<<" << endl << endl;
    resultados = vnd.algoritmoVND(valores, resultados);
    resultados.mostraResultados();
    resultados.salvaResultados("resultadosVND/" + instancia + ".txt");

    cout << endl << ">>>>>>>>>> ILS <<<<<<<<<<" << endl << endl;
    resultados = ils.algoritmoILS(valores, resultados);
    resultados.mostraResultados();
    resultados.salvaResultados("resultadosILS/" + instancia + ".txt");

    cout << endl << ">>>>>>>>>> Tempo de execucao <<<<<<<<<<" << endl << endl;
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << duration.count() << " miliseconds" << endl;

    return 0;
}
