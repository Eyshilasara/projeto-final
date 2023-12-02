#ifndef MIDIA_HPP
#define MIDIA_HPP

#include <string>
#include <iostream>

class Midia {
protected:
    std::string titulo;
    std::string codigo;
    std::string genero;
    int quantidadeDisponivel;
    int quantidadeTotal;

public:
    Midia(const std::string& _titulo, std::string _codigo, const std::string& _genero, int _quantidadeTotal);

    std::string getCodigo() const;
    std::string getGenero() const;
    std::string getTitulo() const;
    int getQuantidadeDisponivel() const;
    int getQuantidadeTotal() const;
    void exibirInfo() const;
};

#endif 