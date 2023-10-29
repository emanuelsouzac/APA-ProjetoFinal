#ifndef MEUARQUIVO_H
#define MEUARQUIVO_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MeuArquivo {
public:
    MeuArquivo(const string&);

    int n, k, Q, L, r;
    vector<int> d, p;
    vector<vector<int>> c;
};

#endif // MINHACLASSE_H
