#ifndef FILME_HPP
#define FILME_HPP

#include "dvd.hpp"

class Filme : public DVD {
public:
    Filme(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal);
    void exibirInfo() const;
};

#endif 
