#include "fita_de_video.hpp"
#include <iostream>

FitaDeVideo::FitaDeVideo(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, bool _rebobinado)
    : Midia(_titulo, _codigo, _genero, _quantidadeTotal), rebobinado(_rebobinado) {}

void FitaDeVideo::exibirInfo() const {
    Midia::exibirInfo();
    std::cout << "Rebobinado: " << (rebobinado ? "Sim" : "Não") << "\n";
}