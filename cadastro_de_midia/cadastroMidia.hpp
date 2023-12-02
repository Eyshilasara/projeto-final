#ifndef CADASTRO_MIDIA_CPP
#define CADASTRO_MIDIA_CPP

#include "cadastroMidia.hpp" 
#include "classesCadastro.hpp" 
#include <string>
#include <iostream>  

std::string cadastrarMidia(Midia &midia, DVD &dvd, Disco &disco, Jogo &jogo, FitaVideo &fitaVideo, Filme &filme);
void removerMidia(int codigo);

#endif