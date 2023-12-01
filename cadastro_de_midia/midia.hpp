#ifndef MIDIA_HPP
#define MIDIA_HPP

#include <string>
#include <iostream>

class Midia {
protected:
    std::string titulo;
    int codigo;
    std::string genero;
    int quantidadeDisponivel;
    int quantidadeTotal;

public:
    Midia(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal);

   /* const std::string& getTitulo() const;
    void setTitulo(const std::string& _titulo);

    int getCodigo() const;
    void setCodigo(int _codigo);

    const std::string& getGenero() const;
    void setGenero(const std::string& _genero);

    int getQuantidadeTotal() const;
    void setQuantidadeTotal(int _quantidadeTotal);

    int getQuantidadeDisponivel() const;
    void setQuantidadeDisponivel(int _quantidadeDisponivel);*/
};  

#endif 
