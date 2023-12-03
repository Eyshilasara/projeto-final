#ifndef CADASTRO_MIDIA_HPP
#define CADASTRO_MIDIA_HPP

#include "classesCadastro.hpp" 
#include <string>
#include <iostream>
#include <vector>

std::string cadastrarMidia(Midia &midia, DVD &dvd, Disco &disco, Jogo &jogo, FitaVideo &fitaVideo, Filme &filme);

void removerMidia(int codigo);

void listarFilmes(std::vector<std::vector<std::string>>& midias);

void lerArquivo(std::string midiastxt);


#endif
