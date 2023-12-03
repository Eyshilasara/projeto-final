#include "fitaVideo.hpp"
#include <iostream>

FitaVideo::FitaVideo(const std::string& _tipo, const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, bool _rebobinado)
    : Midia(_tipo, _titulo, _codigo, _genero, _quantidadeTotal, _quantidadeDisponivel), rebobinado(_rebobinado)
{
}

void FitaVideo::exibirInfo() const
{
    Midia::exibirInfo();
    std::cout << "Rebobinado: " << (rebobinado ? "Sim" : "Não") << std::endl;
}




