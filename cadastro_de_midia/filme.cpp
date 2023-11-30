#include "filme.hpp"

Filme::Filme(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _tipo, const std::string& _categoria, const std::string _grupo, int _Nota_de_Critica)
    : DVD(_titulo, _codigo, _genero, _quantidadeTotal, _quantidadeDisponivel, _tipo, _categoria, _grupo), Nota_de_Critica(_Nota_de_Critica) {}

void Filme::exibirInfo() const
{
    Midia::exibirInfo();
    std::cout << "Nota de critica: " << Nota_de_Critica << std::endl;
}

    