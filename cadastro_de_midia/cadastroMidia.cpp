#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include "controle_locacao.hpp"
#include "midia.hpp"
#include "filme.hpp"
#include "jogo.hpp"
#include "disco.hpp"
#include "fitaVideo.hpp"
#include "dvd.hpp"
#include "Gerenciador_de_arquivos.hpp"

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
    while (std::cin.fail() || std::to_string(codigo).length() != 4)
    {
        std::cout << "ERRO: Codigo invalido. Por favor, insira novamente." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> codigo; // Leia dentro do loop para corrigir o problema
    }
    midia.setCodigo(codigo);

    std::cout << "Qual o tipo da mídia? (As opções são dvd ou fita. Lembre-se de usar sempre letras minúsculas!)" << std::endl;
    while (true)
    {
        std::cin >> tipo;

        if (tipo == "dvd" || tipo == "fita")
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
              << "(Sem caracteres especiais. Lembre-se de usar sempre letras minusculas e colocar o titulo entre aspas duplas!)" << std::endl;
    std::cin >> titulo;
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

    std::cout << "Qual o genero da midia? (Lembre-se de usar sempre letras minusculas e sem caracteres especiais!)" << std::endl;
    std::cin >> genero;

    while (!std::all_of(genero.begin(), genero.end(), [](char c)
                        { return std::islower(c) || std::isalnum(c); }))
    {

        std::cout << "ERRO: Genero inválido. Por favor, siga as instruções." << std::endl;
        std::cin.clear();                                                   // Limpar o estado de erro
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar entrada inválida
        std::cin >> genero;                                                 // Ler novamente
    }

    midia.setGenero(genero);

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
        std::cout << "Qual o cantor ou banda do disco? (Sem caracteres especiais. Lembre-se de usar sempre letras minúsculas e colocar o nome do cantor/banda entre aspas duplas!)" << std::endl;
        std::cin >> cantorBanda;

        while (true)
        {
            if (std::all_of(cantorBanda.begin(), cantorBanda.end(), [](char c)
                            { return std::islower(c) || std::isalnum(c); }) &&
                cantorBanda[0] == '"' && cantorBanda.back() == '"')
            {
                disco.setCantorBanda(cantorBanda);
                break;
            }
            else
            {
                std::cout << "ERRO: Cantor ou banda inválido. Por favor, siga as instruções." << std::endl;
                std::cin.clear();                                                   // Limpar o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar entrada inválida
                std::cin >> cantorBanda;                                            // Ler novamente
            }
        }

        std::cout << "Qual o número de músicas do disco? (Use apenas números inteiros)" << std::endl;
        std::cin >> numeroMusicas;

        while (true)
        {
            if (std::cin.fail())
            {
                std::cout << "ERRO: Entrada inválida. Por favor, insira novamente." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Correção aqui
            }
            else
            {
                break;
            }
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
                    std::cout << "ERRO: Entrada inválida. Por favor, insira novamente." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Correção aqui
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
                std::cout << "ERRO: Entrada inválida. Por favor, insira novamente." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Correção aqui
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
                std::cout << "ERRO: Entrada inválida. Por favor, insira novamente." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Correção aqui
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
                std::cout << "ERRO: Mídia não encontrada." << std::endl;
            }
        }

        void listarFilmes(std::vector<std::vector<std::string>> & midias, char opcao)
        {
            std::vector<std::vector<std::string>> midiasOrdenadas;
            std::vector<std::string> midia;
            char entrada;
            std::cout << "Como deseja ordenar as midias? (As opções são c para código ou t para título. Lembre-se de usar sempre letras minúsculas!)" << std::endl;     
            std::cin >> entrada;

            while (entrada == 'c' || entrada == 't')
            {
                if (entrada == 'c')
                {
                    // Ordenar por código de forma crescente
                    std::sort(midias.begin(), midias.end(), [](const std::vector<std::string> &a, const std::vector<std::string> &b)
                            { return a[0] < b[0]; });
                }
                else if (entrada == 't')
                {
                    // Ordenar em ordem alfabética pelo título
                    std::sort(midias.begin(), midias.end(), [](const std::vector<std::string> &a, const std::vector<std::string> &b)
                            { return a[6] < b[6]; });
                }

                else
                {
                    std::cout << "ERRO: Opção inválida. Por favor, insira novamente." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }

        void lerArquivo(std::string midiastxt)
        {
            std::ifstream arquivo;
            arquivo.open(midiastxt);

            if (arquivo.fail())
            {
                std::cout << "ERRO: arquivo inexistente" << std::endl;
                return;
            }

            std::string linha;
            while (std::getline(arquivo, linha))
            {
                std::cout << linha << std::endl;
            }

            arquivo.close();
        }
