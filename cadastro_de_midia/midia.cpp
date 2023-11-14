#include "midia.hpp"
#include <iostream>

Midia::Midia(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal)
    : titulo(_titulo), codigo(_codigo), genero(_genero), quantidadeDisponivel(_quantidadeTotal), quantidadeTotal(_quantidadeTotal) {}

void Midia::exibirInfo() const {
    std::cout << "Título: " << titulo << "\n";
    std::cout << "Código: " << codigo << "\n";
    std::cout << "Gênero: " << genero << "\n";
    std::cout << "Quantidade Disponível: " << quantidadeDisponivel << "\n";
    std::cout << "Quantidade Total: " << quantidadeTotal << "\n";
}
