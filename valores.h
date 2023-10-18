#ifndef MINHACLASSE_H
#define MINHACLASSE_H

#include <iostream>
#include <fstream>
#include <vector>

class MeuArquivo {
public:
    MeuArquivo(const std::string& arquivo);
    void imprimirValores() const;

    int n, k, Q, L, r;
    std::vector<int> d, p;
    std::vector<std::vector<int>> c;
};

#endif // MINHACLASSE_H
