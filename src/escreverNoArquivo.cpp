#include <iostream>
#include <fstream>
#include "midia.hpp"
#include "filme.hpp"
#include "jogo.hpp"
#include "disco.hpp"
#include "fitaVideo.hpp"
#include "dvd.hpp"


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
    arquivo << midia.getCodigo() << " "
            << midia.getQuantidadeDisponivel() << " "
            << midia.getQuantidadeTotal() << " "
            << midia.getTipo() << " "
            << dvd.getGrupo() << " "
            << dvd.getCategoria() << " "
            << midia.getTitulo() << " "
            << midia.getGenero() << " "
            << filme.getNotaCritica() << " "
            << disco.getNumeroMusicas() << " "
            << disco.getCantorBanda() << " "
            << jogo.getPlataforma() << " "
            << fitaVideo.getRebobinado() << std::endl;

    arquivo.close();
    std::cout << "Mídia cadastrada com sucesso!" << std::endl;
}