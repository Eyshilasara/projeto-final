#include "filme.hpp"

Filme::Filme(const std::string& _tipo, const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _categoria, const std::string _grupo, int _notaCritica)
    : DVD(_tipo, _titulo, _codigo, _genero, _quantidadeTotal, _quantidadeDisponivel, _categoria, _grupo), notaCritica(_notaCritica)  {}

void Filme::exibirInfo() const
{
    Midia::exibirInfo();
    std::cout << "Nota de critica: " << notaCritica << std::endl;
}

    