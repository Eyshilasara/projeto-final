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
    arquivo << midia.getCodigo() << "\t"
            << midia.getQuantidadeDisponivel() << "\t"
            << midia.getQuantidadeTotal() << "\t"
            << midia.getTipo() << "\t"
            << dvd.getGrupo() << "\t"
            << dvd.getCategoria() << "\t"
            << midia.getTitulo() << "\t"
            << midia.getGenero() << "\t"
            << filme.getNotaCritica() << "\t"
            << disco.getNumeroMusicas() << "\t"
            << disco.getCantorBanda() << "\t"
            << jogo.getPlataforma() << "\t"
            << fitaVideo.getRebobinado() << "\t"
            << std::endl;

    arquivo.close();
    std::cout << "Mídia cadastrada com sucesso!" << std::endl;
}