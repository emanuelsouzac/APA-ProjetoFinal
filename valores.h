#ifndef MEUARQUIVO_H
#define MEUARQUIVO_H

#include <iostream>
#include <fstream>
#include <vector>

class MeuArquivo {
public:
    MeuArquivo(const std::string& instancia);

    int n, k, Q, L, r;
    std::vector<int> d, p;
    std::vector<std::vector<int>> c;
};

#endif // MINHACLASSE_H
