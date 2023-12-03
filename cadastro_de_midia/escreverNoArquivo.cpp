#include <iostream>
#include <fstream>
#include "classesCadastro.hpp"

void escreverNoArquivo(Midia &midia, const std::string &nomeArquivo, DVD &dvd, Filme &filme, FitaVideo &fitaVideo, Disco &disco, Jogo &jogo)
{
    std::ofstream arquivo;
    arquivo.open("midias.txt", std::ios::app);

    if (arquivo.fail())
    {
        std::cout << "Erro ao abrir o arquivo para escrita." << std::endl;
        return;
    }

    // Escrever no arquivo
    arquivo << midia.getCodigo() << "\n"
            << midia.getQuantidadeDisponivel() << "\n"
            << midia.getQuantidadeTotal() << "\n"
            << midia.getTipo() << "\n"
            << dvd.getGrupo() << "\n"
            << dvd.getCategoria() << "\n"
            << midia.getTitulo() << "\n"
            << midia.getGenero() << "\n"
            << filme.getNotaCritica() << "\n"
            << disco.getNumeroMusicas() << "\n"
            << disco.getCantorBanda() << "\n"
            << jogo.getPlataforma() << "\n"
            << fitaVideo.getRebobinado() << "\n"
            << std::endl;

    arquivo.close();
    std::cout << "Mídia cadastrada com sucesso!" << std::endl;
}