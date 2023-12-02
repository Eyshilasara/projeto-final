#ifndef FILME_HPP
#define FILME_HPP

#include "dvd.hpp"

class Filme : public DVD {
protected:
    int notaCritica;

public:
    Filme(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _tipo, const std::string& _categoria, const std::string _grupo, int _notaCritica);
    void exibirInfo() const;

    void setNotaCritica(int notaCritica) {
        this->notaCritica = notaCritica;
    }
    int getNotaCritica() const {
        return notaCritica;
    }
};

#endif 
