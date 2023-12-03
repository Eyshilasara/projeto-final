#include "dvd.hpp"
#include <iostream>

DVD::DVD(const std::string& _tipo, const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _categoria, const std::string _grupo)
    : Midia(_tipo, _titulo, _codigo, _genero, _quantidadeTotal, _quantidadeDisponivel), categoria(_categoria), grupo(_grupo) {}

void DVD::exibirInfo() const {
    Midia::exibirInfo();
    std::cout << "Categoria: " << categoria << std:: endl;
    std::cout << "Grupo: " << grupo << std:: endl;
}
