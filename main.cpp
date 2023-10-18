#include <iostream>
#include <fstream>
#include <vector>
#include "valores.h"

using namespace std;


int main() {

    //MeuArquivo minhaInstancia(arquivo);
    //minhaInstancia.imprimirValores();
    


    string arquivo = "n9k5_A";
    //cout << "Nome do arquivo: ";
    //cin >> arquivo;

    MeuArquivo valores(arquivo);


    vector<bool> clienteAtendido(valores.n, false);
    vector<int> veiculo(valores.k, valores.Q);
    int contVeiculo = 0;
    int contClientes = 0;

    vector<vector<int>> rotas(valores.k);

    int custoRota = 0;
    int custoTerceirizacao = 0;

    int referencial = 0;
    int menor;
    int pos;

    while (1)
    {
        menor = 100000000;
        for (int i = 0; i < valores.n + 1; i++)
        {
            if (i != referencial && i != 0 && clienteAtendido[i-1] == false && valores.c[referencial][i] < menor)
            {
                menor = valores.c[referencial][i];
                pos = i;
            }
        }
        if (veiculo[contVeiculo] - valores.d[pos - 1] < 0)
        {
            contVeiculo++;
            custoRota += valores.c[referencial][0];
            if (contClientes > valores.L)
            {
                break;
            }
            referencial = 0;
        }
        else
        {
            clienteAtendido[pos-1] = true;
            custoRota += valores.c[referencial][pos];
            veiculo[contVeiculo] -= valores.d[pos - 1];
            contClientes++;
            referencial = pos;
            rotas[contVeiculo].push_back(pos);
        }
    }

    for (int i = 0; i < valores.n; i++)
    {
        if (clienteAtendido[i] == false)
        {
            custoTerceirizacao += valores.p[i];
        }
    }

    cout << endl << "Resultado guloso" << endl << endl;

    cout << "Valor total da solucao: " << custoRota + custoTerceirizacao + contVeiculo * valores.r << endl;
    cout << "Custo de roteamento: " << custoRota << endl;
    cout << "Custo associado a utilizacao dos veiculos: " << contVeiculo  * valores.r << endl;
    cout << "Custo de terceirizacao: " << custoTerceirizacao << endl;
    cout << endl << "Lista de clientes terceirizados: ";
    for (int i = 0; i < valores.n; i++)
    {
        if (clienteAtendido[i] == false)
        {
            cout << i + 1 << " ";
        }
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


    return 0;
}
