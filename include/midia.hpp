#ifndef MIDIA_HPP
#define MIDIA_HPP

#include <string>
#include <iostream>

class Midia {
protected:
    std::string tipo;  // DVD ou FITA
    std::string titulo;
    int codigo;
    std::string genero;// terror, comedia,etc.
    int quantidadeTotal;
    int quantidadeDisponivel;

public:
    Midia(const std::string& _tipo, const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel);

    Midia(){};

    void exibirInfo() const;

    void setTipo(const std::string& tipo) {
        this->tipo = tipo;
    }
    std::string getTipo() const {
        return tipo;
    }

    void setTitulo(const std::string& titulo) {
        this->titulo = "\"" + titulo + "\"";
    }   
    std::string getTitulo() const {
        return titulo;
    }

    void setCodigo(int codigo) {
        this->codigo = codigo;
    }
    int getCodigo() const {
        return codigo;
    }

    void setGenero(const std::string& genero) {
        this->genero = "\"" + genero + "\"";
    }
    std::string getGenero() const {
        return genero;
    }

    void setQuantidadeDisponivel(int quantidadeDisponivel) {
        this->quantidadeDisponivel = quantidadeDisponivel;
    }
    int getQuantidadeDisponivel() const {
        return quantidadeDisponivel;
    }

    void setQuantidadeTotal(int quantidadeTotal) {
        this->quantidadeTotal = quantidadeTotal;
    }
    int getQuantidadeTotal() const {
        return quantidadeTotal;
    }
};

#endif 