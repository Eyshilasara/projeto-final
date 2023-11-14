#ifndef FITA_DE_VIDEO_HPP
#define FITA_DE_VIDEO_HPP

#include "midia.hpp"

class FitaDeVideo : public Midia {
private:
    bool rebobinado;

public:
    FitaDeVideo(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, bool _rebobinado);
    void exibirInfo() const;
};

#endif 
