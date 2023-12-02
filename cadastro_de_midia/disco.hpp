#ifndef DISCO_HPP
#define DISCO_HPP

#include "dvd.hpp"

class Disco : public DVD {
protected:
    std::string cantorBanda;
    int numeroMusicas;
    
public:
    Disco(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _tipo, const std::string& _categoria, const std::string _grupo, const std::string& _CantorBanda, int _numeroMusicas);
    void exibirInfo() const;

    void setCantorBanda(const std::string& cantorBanda) {
        this->cantorBanda = cantorBanda;
    }
    std::string getCantorBanda() const {
        return cantorBanda;
    }

    void setNumeroMusicas(int numeroMusicas) {
        this->numeroMusicas = numeroMusicas;
    }
    int getNumeroMusicas() const {
        return numeroMusicas;
    }
};

#endif 