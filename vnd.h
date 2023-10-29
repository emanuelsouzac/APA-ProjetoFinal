#ifndef VND_H
#define VND_H

#include <vector>

#include "resultados.h"
#include "valores.h"

class VND {
public:
    VND();
    ~VND();

    Resultados algoritmoVND(MeuArquivo, Resultados);
    Resultados crossExchange(MeuArquivo, Resultados);
    Resultados swap(MeuArquivo, Resultados);
    Resultados reInsertion(MeuArquivo, Resultados);
    Resultados terceiriza(MeuArquivo, Resultados);
    Resultados desterceiriza(MeuArquivo, Resultados);
    Resultados terceirizaRota(MeuArquivo, Resultados);
};

#endif // VND_H
