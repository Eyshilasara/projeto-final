#include "disco.hpp"
#include <iostream>

Disco::Disco(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, const std::string& _cantorBanda, int _numeroMusicas)
    : DVD(_titulo, _codigo, _genero, _quantidadeTotal, "Disco", "Música"), cantorBanda(_cantorBanda), numeroMusicas(_numeroMusicas) {}

void Disco::exibirInfo() const {
    DVD::exibirInfo();
    std::cout << "Cantor/Banda: " << cantorBanda << "\n";
    std::cout << "Número de Músicas: " << numeroMusicas << "\n";
}
