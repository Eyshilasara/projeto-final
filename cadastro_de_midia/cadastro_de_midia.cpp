#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "classes_cadastro.hpp"

std::string cadastrarMidia(Midia &midias)
{
    std::string tipo;
    std::string titulo;
    int codigo;
    std::string genero;
    int quantidadeTotal;
    int quantidadeDisponivel;
    std::string categoria;
    std::string grupo;
    double notaCritica;
    std::string plataforma;
    std::string cantorBanda;
    int numeroMusicas;
    bool rebobinado;

    std::cout << "Qual o codigo da midia? "
              << "Use apenas numeros inteiros!" << std::endl;
    std::cin >> codigo;
    midia.setCodigo(codigo);

    std::cout << "Qual o tipo da mídia? (As opções são dvd ou fita de vídeo. Lembre-se de usar sempre letras minúsculas!)" << std::endl;
    while (true)
    {
        std::cin >> tipo;

        if (tipo == "dvd" || tipo == "fita de video")
        {
            break;
        }
        else
        {
            std::cout << "Tipo de midia invalido. Por favor, insira novamente." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    midia.setTipo(tipo);

    if (tipo == "DVD")
    {
        while (true)
        {
            std::cout << "Qual o grupo da midia? (As opções são filme, jogo ou disco. Lembre-se de usar sempre letras minúsculas!)" << std::endl;
            std::cin >> grupo;

            if (grupo == "filme" || grupo == "jogo" || grupo == "disco")
            {
                break;
            }
            else
            {
                std::cout << "Grupo invalido. Por favor, insira novamente." << std::endl;
            }
        }
        std::cout << "Qual a categoria da mídia? (As opções são lancamento, promocao ou estoque. Lembre-se de usar sempre letras minúsculas!)" << std::endl;
        while (true)
        {
            std::cin >> categoria;

            if (categoria == "lancamento" || categoria == "promocao" || categoria == "estoque")
            {
                break;
            }
            else
            {
                std::cout << "Categoria invalida. Por favor, insira novamente." << std::endl;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        dvd.setCategoria(categoria);

        std::cout << "Qual o titulo da midia? "
                  << "(Sem caracteres especiais. Lembre-se de usar sempre letras minusculas!)" << std::endl;
        std::cin >> titulo;
        midia.setTitulo(titulo);

        std::cout << "Qual o genero da midia? "
                  << "Lembre-se de usar sempre letras minusculas!)" << std::endl;
        std::cin >> genero;
        midia.setGenero(genero);

        if (grupo == "filme")
        {
            std::cout << "Qual a nota de crítica? (Use apenas numeros inteiros)" << std::endl;
            if (std::cin >> notaCritica)
            {
                filme.setnotaCritica(notaCritica);
            }
            else
            {
                std::cout << "Entrada invalida. Por favor, insira um numero inteiro." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        
    }
    else if (grupo == "jogo")
    {
        while(true)
        {
        std::cout << "Qual a plataforma do jogo? (As opções são PS4, XBOX ou PC. Lembre-se de usar sempre letras maiusculas!)" << std::endl;
        std::cin >> plataforma;
        if(plataforma == "PS4" || plataforma == "XBOX" || plataforma == "PC")
        {
            break;
        }
        else
        {
            std::cout << "Plataforma invalida. Por favor, insira novamente." << std::endl;
        }
        jogo.setPlataforma(plataforma);
        }
    }
    else if (grupo == "disco")
    {
        std::cout << "Qual o cantor ou banda do disco? (Lembre-se de usar sempre letras minúsculas!)" << std::endl;
        std::cin >> cantorBanda;

        while (true)
        {
            std::cout << "Qual o numero de musicas do disco? (Use apenas numeros inteiros)" << std::endl;
            if (std::cin >> numeroMusicas)
            {
                break;
            }
            else
            {
                std::cout << "Entrada invalida. Por favor, insira novamente." << std::endl;
                // Limpar o estado de erro e o buffer de entrada
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        disco.setNumeroMusicas(numeroMusicas);
    }

    else if (tipo == "fita de video")
    {
        while (true)
        {
            std::cout << "A fita eh rebobinada? (As opções são 1 para sim ou 0 para nao)" << std::endl;
            if (std::cin >> rebobinado)
            {
                break;
            }
            else
            {
                std::cout << "Entrada invalida. Por favor, insira novamente." << std::endl;
                // Limpar o estado de erro e o buffer de entrada
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    fitaVideo.setRebobinado(bool rebobinado);
    }

    std::cout << "Qual a quantidade total da midia? "
              << "Use apenas numeros inteiros!" << std::endl;
    std::cin >> quantidadeTotal;
    midia.setQuantidadeTotal(quantidadeTotal);

    std::cout << "Qual a quantidade disponivel da midia? "
            << "Use apenas numeros inteiros!" << std::endl;
    std::cin >> quantidadeDisponivel;
    midia.setQuantidadeDisponivel(quantidadeDisponivel);

    std::cout << "Mídia cadastrada com sucesso!" << std::endl;
    return "Mídia cadastrada com sucesso!";
}

void excluirMidia(int codigo)
{
    // Encontrar a mídia com base no código
    std::vector<Midia> midias;

    auto it = std::find_if(midias.begin(), midias.end(), [codigo](const Midia &m)
                           { return m.getCodigo() == codigo; });

    if (it != midias.end())
    {
        // Remover a mídia se encontrada
        midias.erase(it);
        std::cout << "Mídia excluída com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Mídia não encontrada." << std::endl;
    }
}