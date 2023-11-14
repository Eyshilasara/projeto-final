#include "filme.hpp"

Filme::Filme(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal)
    : DVD(_titulo, _codigo, _genero, _quantidadeTotal, "Filme", "Sem Categoria") {}

void Filme::exibirInfo() const {
    Midia::exibirInfo();
    std::cout << "Título: " << titulo << "\n";
    std::cout << "Código: " << codigo << "\n";
    std::cout << "Gênero: " << genero << "\n";
    std::cout << "Quantidade Total: " << quantidadeTotal << "\n";
}
