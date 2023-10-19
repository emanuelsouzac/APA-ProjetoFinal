#include "valores.h"

MeuArquivo::MeuArquivo(const std::string& instancia) {
    std::ifstream arquivoEntrada("instancias/" + instancia + ".txt");

    if (!arquivoEntrada.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        exit(1);
    }

    arquivoEntrada >> n >> k >> Q >> L >> r;

    d.resize(n);
    for (int i = 0; i < n; i++) {
        arquivoEntrada >> d[i];
    }

    p.resize(n);
    for (int i = 0; i < n; i++) {
        arquivoEntrada >> p[i];
    }

    c.resize(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            arquivoEntrada >> c[i][j];
        }
    }

    arquivoEntrada.close();
}
