#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Classes_cadastro.hpp"

std::string cadastrarMidia(Midia& midia) {
    std::string tipo;
    std::string titulo;
    int codigo;
    std::string genero;
    int quantidadeTotal;
    int quantidadeDisponivel;
    std::string categoria;
    std::string grupo;
    double nota_de_critica;
    std::string plataforma;
    std::string artista;
    int numeroMusicas;
    bool rebobinado;

    std::cout << "Qual o tipo da midia? " << "(As opções são DVD ou fita de video. Lembre-se de usar sempre letras minusculas!)" << std:: endl;
    std::cin >> tipo;
    midia.setTipo(tipo);

    std::cout << "Qual o titulo da midia? " << "(Sem caracteres especiais. Lembre-se de usar sempre letras minusculas!)" << std:: endl;
    std::cin >> titulo;
    midia.setTitulo(titulo);

    std::cout << "Qual o codigo da midia? " << "Use apenas numeros inteiros!" <<  std:: endl;
    std::cin >> codigo;
    midia.setCodigo(codigo);

    std::cout << "Qual o genero da midia? " << "Lembre-se de usar sempre letras minusculas!)" << std:: endl;
    std::cin >> genero;
    midia.setGenero(genero);

    std::cout << "Qual a quantidade total da midia? " << "Use apenas numeros inteiros!" << std:: endl;
    std::cin >> quantidadeTotal;
    midia.setQuantidadeTotal(quantidadeTotal);

    std::cout << "Qual a quantidade disponivel da midia? " << "Use apenas numeros inteiros!" << std:: endl;
    std::cin >> quantidadeDisponivel;
    midia.setQuantidadeDisponivel(quantidadeDisponivel);
    

    if( tipo == "DVD"){
        std::cout << "Qual a categoria da midia? " << "(As opções são lancamento, promocao ou estoque)" << std:: endl;
        std::cin >> categoria;
        dvd.setCategoria(categoria);

        std::cout << "Qual o grupo da midia? " << "(As opções são filme, jogo ou disco. Lembre-se de usar sempre letras minusculas!)" << std:: endl;
        std::cin >> grupo;
        dvd.setGrupo(grupo);

        if (grupo == "filme") {
            std::cout << "Qual a nota de critica?" << "Use apenas numeros sem casas decimais!" << std::endl;
            std::cin >> nota_de_critica;
            filme.setNotaDeCritica(nota_de_critica);
            std::cout << "Filme cadastrado com sucesso!" << std::endl;
        } 
        else if (grupo == "jogo") {
            std::cout << "Qual a plataforma do jogo?" << "(As opções são PS4, XBOX ou PC. Lembre-se de usar sempre letras maiusculas!)" << std::endl;
            std::cin >> plataforma;
            jogo.setPlataforma(plataforma);
            std::cout << "Jogo cadastrado com sucesso!" << std::endl;
        } 
        else if (grupo == "disco"){
            std::cout << "Qual o artista do disco?" << "(Lembre-se de usar sempre letras minusculas!)" << std:: endl;
            std::cin >> artista;
            disco.setArtista(artista);

            std::cout << "Qual o numero de musicas do disco?" << "Use apenas numeros inteiros!" << std:: endl;
            std::cin >> numeroMusicas;
            disco.setNumeroMusicas(numeroMusicas);
            std::cout << "Disco cadastrado com sucesso!" << std::endl;
        }
    }

    else if (tipo == "fita de video"){
        std::cout << "A fita é rebobinada? " << "(As opções são 1 para sim ou 0 para nao)" << std:: endl;
        std::cin >> rebobinado;
        fita_de_video.setRebobinado(rebobinado);
        std::cout << "Fita de video cadastrada com sucesso!" << std::endl;
    }

    // ...

    
}

void removerFilme(std::vector<Midia*>& catalogo, int codigo) {
    
}

