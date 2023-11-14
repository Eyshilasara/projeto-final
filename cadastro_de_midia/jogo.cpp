#include "jogo.hpp"
#include <iostream>

Jogo::Jogo(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, const std::string& _plataforma)
    : DVD(_titulo, _codigo, _genero, _quantidadeTotal, "Jogo", "Sem Categoria"), plataforma(_plataforma) {}

void Jogo::exibirInfo() const {
    DVD::exibirInfo();
    std::cout << "Plataforma: " << plataforma << "\n";
}
