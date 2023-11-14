#include "dvd.hpp"
#include <iostream>

DVD::DVD(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, const std::string& _tipo, const std::string& _categoria)
    : Midia(_titulo, _codigo, _genero, _quantidadeTotal), tipo(_tipo), categoria(_categoria) {}

void DVD::exibirInfo() const {
    Midia::exibirInfo();
    std::cout << "Tipo: " << tipo << "\n";
    std::cout << "Categoria: " << categoria << "\n";
}
