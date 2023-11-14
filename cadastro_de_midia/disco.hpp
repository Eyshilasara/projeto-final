#ifndef DISCO_HPP
#define DISCO_HPP

#include "dvd.hpp"

class Disco : public DVD {
private:
    std::string cantorBanda;
    int numeroMusicas;

public:
    Disco(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, const std::string& _cantorBanda, int _numeroMusicas);
    void exibirInfo() const;
};

#endif 
