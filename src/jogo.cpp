#include "jogo.hpp"
#include <iostream>

Jogo::Jogo(const std::string& _tipo, const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _categoria, const std::string _grupo, const std::string _plataforma)
    : DVD(_tipo, _titulo, _codigo, _genero, _quantidadeTotal, _quantidadeDisponivel,_categoria,_grupo), plataforma(_plataforma) {}

void Jogo::exibirInfo() const {
    DVD::exibirInfo();
    std::cout << "Plataforma: " << plataforma << std:: endl;
}