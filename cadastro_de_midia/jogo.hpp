#ifndef JOGO_HPP
#define JOGO_HPP

#include "dvd.hpp"

class Jogo : public DVD {
private:
    std::string plataforma;

public:
    Jogo(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, const std::string& _plataforma);
    void exibirInfo() const;
};

#endif 
