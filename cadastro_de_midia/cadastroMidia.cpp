#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "classesCadastro.hpp"

std::string cadastrarMidia(Midia &midia, DVD &dvd, Disco &disco, Jogo &jogo, FitaVideo &fitaVideo, Filme &filme)
{
    std::string tipo;
    std::string titulo;
    int codigo;
    std::string genero;
    int quantidadeTotal;
    int quantidadeDisponivel;
    std::string categoria;
    std::string grupo;
    int notaCritica;
    std::string plataforma;
    std::string cantorBanda;
    int numeroMusicas;
    bool rebobinado;

    std::cout << "Qual o codigo da midia? "
              << "O codigo deve conter exatamente 4 digitos. Lembre-se de usar apenas numeros inteiros!" << std::endl;
    std::cin >> codigo;
    while (true)
    {
        std::cin >> codigo;
        if (std::cin.fail() || std::to_string(codigo).length() != 4)
        {
            std::cout << "ERRO: Codigo invalido. Por favor, insira novamente." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

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
            std::cout << "ERRO: Tipo de midia invalido. Por favor, insira novamente." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    midia.setTipo(tipo);

    if (tipo == "dvd")
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
                std::cout << "ERRO: Grupo invalido. Por favor, insira novamente." << std::endl;
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
                std::cout << "ERRO: Categoria invalida. Por favor, insira novamente." << std::endl;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n');
            }
        }
        dvd.setCategoria(categoria);
    }
    std::cout << "Qual o titulo da midia? "
                  << "(Sem caracteres especiais. Lembre-se de usar sempre letras minusculas e colocar o titulo entre aspas!)" << std::endl;
        std::cin >> titulo;

        // Verificar se o título contém apenas caracteres alfanuméricos e minúsculas
        while (true)
        {
            if (std::all_of(titulo.begin(), titulo.end(), [](char c)
                            { return std::islower(c) || std::isalnum(c); }) &&
                titulo[0] == '"' && titulo.back() == '"')
            {
                midia.setTitulo(titulo);
                break;
            }
            else
            {
                std::cout << "ERRO: Título inválido. Por favor, siga as instruções." << std::endl;
            }
        }
        std::cout << "Qual o genero da midia? "
                  << "Lembre-se de usar sempre letras minusculas e sem caracteres especiais!)" << std::endl;
        while (true)
        {
            if (std::all_of(genero.begin(), genero.end(), [](char c)
                            { return std::islower(c) || std::isalnum(c); }))
            {
                midia.setGenero(genero);
                break;
            }
            else
            {
                std::cout << "ERRO: Genero inválido. Por favor, siga as instruções." << std::endl;
            }
        }
        if (grupo == "filme")
        {
            std::cout << "Qual a nota de crítica? (Use apenas numeros inteiros)" << std::endl;
            std::cin >> notaCritica;
            while (true)
            {
                if (std::cin.fail())
                {
                    std::cout << "ERRO: Entrada invalida. Por favor, insira novamente." << std::endl;
                    // Limpar o estado de erro e o buffer de entrada
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n');
                }
                else
                {
                    break;
                }
            }

            filme.setNotaCritica(notaCritica);
        }
    
        else if (grupo == "jogo")
        {
            while (true)
            {
                std::cout << "Qual a plataforma do jogo? (As opções são PS4, XBOX ou PC. Lembre-se de usar sempre letras maiusculas!)" << std::endl;
                std::cin >> plataforma;
                if (plataforma == "PS4" || plataforma == "XBOX" || plataforma == "PC")
                {
                    break;
                }
                else
                {
                    std::cout << "ERRO: Plataforma invalida. Por favor, insira novamente." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n');
                }
                jogo.setPlataforma(plataforma);
            }
        }
        else if (grupo == "disco")
        {
            std::cout << "Qual o cantor ou banda do disco? (Sem caracteres especiais. Lembre-se de usar sempre letras minusculas e colocar o nome do cantor/banda entre aspas!)" << std::endl;
            std::cin >> cantorBanda;
            while (true)
            {
                if (std::all_of(cantorBanda.begin(), cantorBanda.end(), [](char c)
                                { return std::islower(c) || std::isalnum(c); }) &&
                    titulo[0] == '"' && titulo.back() == '"')
                {
                    disco.setCantorBanda(cantorBanda);
                    break;
                }
                else
                {
                    std::cout << "ERRO: Cantor ou banda inválido. Por favor, siga as instruções." << std::endl;
                }
            }

            std::cout << "Qual o numero de musicas do disco? (Use apenas numeros inteiros)" << std::endl;
            std::cin >> numeroMusicas;

            while (true)
            {
                if (std::cin.fail())
                {
                    std::cout << "ERRO: Entrada invalida. Por favor, insira novamente." << std::endl;
                    // Limpar o estado de erro e o buffer de entrada
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n');
                }
                else
                {
                    break;
                }
            }

        if (tipo == "fita de video")
        {
            std::cout << "A fita eh rebobinada? (As opções são 1 para sim ou 0 para nao)" << std::endl;
            std::cin >> rebobinado;
            while (true)
            {
                if (rebobinado == 1 || rebobinado == 0)
                {
                    break;
                }
                else
                {
                    std::cout << "ERRO: Entrada invalida. Por favor, insira novamente." << std::endl;
                    // Limpar o estado de erro e o buffer de entrada
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n');
                }
            }
            fitaVideo.setRebobinado(rebobinado);
        }

        std::cout << "Qual a quantidade total da midia? "
                  << "Use apenas numeros inteiros!" << std::endl;
        std::cin >> quantidadeTotal;
        while (true)
        {
            if (std::cin.fail())
            {
                std::cout << "ERRO: Entrada invalida. Por favor, insira novamente." << std::endl;
                // Limpar o estado de erro e o buffer de entrada
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n');
            }
            else
            {
                break;
            }
        }
        midia.setQuantidadeTotal(quantidadeTotal);

        std::cout << "Qual a quantidade disponivel da midia? "
                  << "Use apenas numeros inteiros!" << std::endl;
        std::cin >> quantidadeDisponivel;
        while (true)
        {
            if (std::cin.fail())
            {
                std::cout << "ERRO: Entrada invalida. Por favor, insira novamente." << std::endl;
                // Limpar o estado de erro e o buffer de entrada
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n');
            }
            else
            {
                break;
            }
        }
        midia.setQuantidadeDisponivel(quantidadeDisponivel);

        std::cout << "Mídia cadastrada com sucesso!" << std::endl;
        return "Mídia cadastrada com sucesso!";
    }
}
void removerMidia(int codigo)
{
// Encontrar a mídia com base no código
    std::vector<Midia> midia;

    auto it = std::find_if(midia.begin(), midia.end(), [codigo](const Midia &m)
                           { return m.getCodigo() == codigo; });

    if (it != midia.end())
    {
        // Remover a mídia se encontrada
        midia.erase(it);
        std::cout << "Mídia excluída com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Mídia não encontrada." << std::endl;
    }
}
