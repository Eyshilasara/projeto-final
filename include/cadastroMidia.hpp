#ifndef src\cadastroMidia.cpp
#define CADASTRO_MIDIA_CPP

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

void listarFilmes(std::vector<std::vector<std::string>>& midias, char entrada);

void lerArquivo(std::string midiastxt);


#endif