#ifndef CADASTRO_MIDIA_CPP
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

std::string cadastrarMidia(Midia &midia, DVD &dvd, Disco &disco, Jogo &jogo, FitaVideo &fitaVideo, Filme &filme);
void removerMidia(int codigo);

#endif