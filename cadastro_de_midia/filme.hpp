#ifndef FILME_HPP
#define FILME_HPP

#include "dvd.hpp"

class Filme : public DVD {
protected:
    int Nota_de_Critica;

public:
    Filme(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _tipo, const std::string& _categoria, const std::string _grupo, int _Nota_de_Critica);
    void exibirInfo() const;
};

#endif 
