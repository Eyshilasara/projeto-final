#ifndef DVD_HPP
#define DVD_HPP

#include "midia.hpp"

class DVD : public Midia {
protected:
    std::string categoria;// Lançamento, promoção ou estoque.
    std::string grupo;// jogo, filme ou disco.
public:
    DVD(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidaDisponivel, const std::string& _tipo, const std::string& _categoria, const std::string _grupo);
    
    void exibirInfo() const;

    void setCategoria(const std::string& categoria) {
        this->categoria = categoria;
    }
    std::string getCategoria() const {
        return categoria;
    }

    void setGrupo(const std::string& grupo) {
        this->grupo = grupo;
    }
    std::string getGrupo() const {
        return grupo;
    }
    
};

#endif 