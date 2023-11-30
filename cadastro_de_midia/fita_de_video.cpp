#include "fita_de_video.hpp"
#include <iostream>

FitaDeVideo::FitaDeVideo(const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, std::string& _tipo, bool _rebobinado)
    : Midia(_titulo, _codigo, _genero, _quantidadeTotal, _quantidadeDisponivel, _tipo), rebobinado(_rebobinado) {}

void FitaDeVideo::exibirInfo() const {
    Midia::exibirInfo();
    std::cout << "Rebobinado: " << (rebobinado ? "Sim" : "Não") << std:: endl;
}