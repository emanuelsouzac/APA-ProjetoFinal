#ifndef VND_H
#define VND_H

#include <vector>

#include "resultados.h"
#include "valores.h"

class VND {
public:
    VND();
    ~VND();

    Resultados algoritmoVND(MeuArquivo valores, Resultados resultados);
    Resultados crossExchange(MeuArquivo valores, Resultados resultadosCopia);
    Resultados swap(MeuArquivo valores, Resultados resultadosCopia);
    Resultados reInsertion(MeuArquivo val, Resultados resCopia);
    Resultados terceiriza(MeuArquivo valores, Resultados resultadosCopia);
    Resultados desterceiriza(MeuArquivo valores, Resultados resultadosCopia);
};

#endif // VND_H
