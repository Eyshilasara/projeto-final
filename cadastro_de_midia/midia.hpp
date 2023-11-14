#ifndef MIDIA_HPP
#define MIDIA_HPP

#include <string>
#include <iostream>

class Midia {
protected:
    std::string titulo;
    int codigo;
    std::string genero;
    int quantidadeDisponivel;
    int quantidadeTotal;

public:
    Midia(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal);

    void exibirInfo() const;
};

#endif 
