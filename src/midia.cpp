#include "midia.hpp"
#include <iostream>

Midia::Midia(const std::string& _tipo, const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel)
    : tipo(_tipo), titulo(_titulo), codigo(_codigo), genero(_genero), quantidadeTotal(_quantidadeTotal), quantidadeDisponivel(_quantidadeDisponivel) {}

void Midia::exibirInfo() const {
    std::cout << "Tipo: "   << tipo   << std::endl;
    std::cout << "Título: " << titulo << std::endl;
    std::cout << "Código: " << codigo << std::endl;
    std::cout << "Gênero: " << genero << std::endl;
    std::cout << "Quantidade Disponível: " << quantidadeDisponivel << std::endl;
    std::cout << "Quantidade Total: " << quantidadeTotal << std::endl;
}

