#ifndef JOGO_HPP
#define JOGO_HPP

#include "dvd.hpp"

class Jogo : public DVD {
protected:
    std::string plataforma = "0";

public:
    Jogo(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _tipo, const std::string& _categoria, const std::string _grupo, const std::string _plataforma);
    
    void exibirInfo() const;

    void setPlataforma(const std::string& plataforma) {
        this->plataforma = plataforma;
    }
    std::string getPlataforma() const {
        return plataforma;
    }
};

#endif 