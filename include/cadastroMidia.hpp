#ifndef CADASTRO_MIDIA_HPP
#define CADASTRO_MIDIA_HPP

#include "cadastroMidia.hpp" 
#include "midia.hpp"
#include "filme.hpp"
#include "jogo.hpp"
#include "disco.hpp"
#include "fitaVideo.hpp"
#include "dvd.hpp"
#include <string>
#include <iostream> 
#include <vector> 
#include <algorithm>
#include <limits>


void cadastrarMidia(Midia &midia, DVD &dvd, Disco &disco, Jogo &jogo, FitaVideo &fitaVideo, Filme &filme);

void removerMidia(int codigo);

void listarFilmes();

void lerArquivo(std::string midiastxt);


#endif
