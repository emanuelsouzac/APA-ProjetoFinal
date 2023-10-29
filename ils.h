#ifndef ILS_H
#define ILS_H

#include "resultados.h"
#include "valores.h"
#include "vnd.h"

class ILS {
public:
    ILS();
    ~ILS();

    Resultados pertubacao(MeuArquivo, Resultados);
    Resultados pertubacaoEntreRotas(MeuArquivo, Resultados);
    Resultados algoritmoILS(MeuArquivo, Resultados);
};

#endif // ILS_H