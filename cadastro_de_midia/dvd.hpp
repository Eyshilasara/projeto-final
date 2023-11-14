#ifndef DVD_HPP
#define DVD_HPP

#include "midia.hpp"

class DVD : public Midia {
protected:
    std::string tipo;
    std::string categoria;

public:
    DVD(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, const std::string& _tipo, const std::string& _categoria);
    void exibirInfo() const;
};

#endif 
