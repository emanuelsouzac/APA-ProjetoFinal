#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string arquivo;
    cout << "Nome do arquivo: ";
    cin >> arquivo;

    ifstream arquivoEntrada("instancias/" + arquivo + ".txt");

    if (!arquivoEntrada.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    int n, k, Q, L, r;

    // Lê os valores de n, k, Q, L e r a partir do arquivo
    arquivoEntrada >> n >> k >> Q >> L >> r;

    // Lê os valores do array d
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        arquivoEntrada >> d[i];
    }

    // Lê os valores do array p
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        arquivoEntrada >> p[i];
    }

    // Lê a matriz c
    vector<vector<int>> c(n+1, vector<int>(n+1));
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n+1; j++) {
            arquivoEntrada >> c[i][j];
        }
    }

    arquivoEntrada.close();

    // Agora, você pode imprimir os valores lidos ou realizar outras operações com eles
    cout << "n: " << n << endl;
    cout << "k: " << k << endl;
    cout << "Q: " << Q << endl;
    cout << "L: " << L << endl;
    cout << "r: " << r << endl;

    cout << "Array d:" << endl;
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    cout << "Array p:" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    cout << "Matriz c:" << endl;
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n+1; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
