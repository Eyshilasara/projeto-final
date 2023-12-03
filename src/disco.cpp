#include "disco.hpp"
#include <iostream>

Disco::Disco(const std::string& _tipo, const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _categoria, const std::string _grupo, const std::string& _cantorBanda, int _numeroMusicas)
    : DVD(_tipo, _titulo, _codigo, _genero, _quantidadeTotal, _quantidadeDisponivel, _categoria, _grupo), cantorBanda(_cantorBanda), numeroMusicas(_numeroMusicas) {}

void Disco::exibirInfo() const {
    DVD::exibirInfo();
    std::cout << "Cantor/Banda: " << cantorBanda << std:: endl;
    std::cout << "Número de Músicas: " << numeroMusicas << std:: endl;
}