#include "dvd.hpp"
#include <iostream>

DVD::DVD(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidaDisponivel, const std::string& _tipo, const std::string& _categoria, const std::string _grupo)
    : Midia(_titulo, _codigo, _genero, _quantidadeTotal, _quantidaDisponivel, _tipo), grupo(_grupo), categoria(_categoria) {}

void DVD::exibirInfo() const {
    Midia::exibirInfo();
    std::cout << "Categoria: " << categoria << std:: endl;
    std::cout << "Grupo: " << grupo << std:: endl;
}
