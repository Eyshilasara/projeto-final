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
/*const std::string& getTitulo() const { return titulo; }
void setTitulo(const std::string& _titulo) { titulo = _titulo; }

int getCodigo() const { return codigo; }
void setCodigo(int _codigo) { codigo = _codigo; }

const std::string& getGenero() const { return genero; }
void setGenero(const std::string& _genero) { genero = _genero; }

int getQuantidadeTotal() const { return quantidadeTotal; }
void setQuantidadeTotal(int _quantidadeTotal) { quantidadeTotal = _quantidadeTotal; }

int getQuantidadeDisponivel() const { return quantidadeDisponivel; }
void setQuantidadeDisponivel(int _quantidadeDisponivel) { quantidadeDisponivel = _quantidadeDisponivel; }*\S
