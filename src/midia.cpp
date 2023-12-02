#include <iostream>
#include "midia.hpp"

Midia::Midia(const std::string& _titulo, std::string _codigo, const std::string& _genero, int _quantidadeTotal)
    : titulo(_titulo), codigo(_codigo), genero(_genero), quantidadeDisponivel(_quantidadeTotal), quantidadeTotal(_quantidadeTotal) {}

// Métodos get para as variáveis
std::string Midia::getTitulo() const {
    return titulo;
}

std::string Midia::getCodigo() const {
    return codigo;
}

std::string Midia::getGenero() const {
    return genero;
}

int Midia::getQuantidadeDisponivel() const {
    return quantidadeDisponivel;
}

int Midia::getQuantidadeTotal() const {
    return quantidadeTotal;
}

void Midia::exibirInfo() const {
    std::cout << "Título: " << titulo << "\n";
    std::cout << "Código: " << codigo << "\n";
    std::cout << "Gênero: " << genero << "\n";
    std::cout << "Quantidade Disponível: " << quantidadeDisponivel << "\n";
    std::cout << "Quantidade Total: " << quantidadeTotal << "\n";
}