#include "valores.h"

MeuArquivo::MeuArquivo(const std::string& arquivo) {
    std::ifstream arquivoEntrada("instancias/" + arquivo + ".txt");

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

void MeuArquivo::imprimirValores() const {
    std::cout << "n: " << n << std::endl;
    std::cout << "k: " << k << std::endl;
    std::cout << "Q: " << Q << std::endl;
    std::cout << "L: " << L << std::endl;
    std::cout << "r: " << r << std::endl;

    std::cout << "Array d:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array p:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Matriz c:" << std::endl;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
