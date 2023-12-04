#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include "..\include\midia.hpp"
#include "filme.hpp"
#include "jogo.hpp"
#include "disco.hpp"
#include "fitaVideo.hpp"
#include "dvd.hpp"
#include "cadastroMidia.hpp"
#include "..\include\escreverNoArquivo.hpp"
#include "..\include\Gerenciador_de_arquivos.hpp"



void cadastrarMidia(Midia &midia, DVD &dvd, Disco &disco, Jogo &jogo, FitaVideo &fitaVideo, Filme &filme)
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

    std::vector<std::vector<std::string>> codigoFiltrado;
    while (true) {
        std::cout << "Qual o codigo da midia? "
                  << "O codigo deve conter exatamente 4 digitos. Lembre-se de usar apenas numeros inteiros!" << std::endl;

        if (!(std::cin >> codigo) || std::to_string(codigo).length() != 4) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "ERRO: Codigo invalido. Por favor, insira novamente." << std::endl;
            continue; 
        }

        codigoFiltrado = filtro("midias.txt", 0, std::to_string(codigo), true);

        
        if (codigoFiltrado.size() != 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ERRO: Codigo ja cadastrado. Por favor, insira novamente." << std::endl;
            continue;
        } else {
           midia.setCodigo(codigo);
            break;
        }
    }


    std::cout << "Qual o tipo da midia? (As opcoes sao dvd ou fita. Lembre-se de usar sempre letras minusculas!)" << std::endl;

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
            std::cout << "Qual o grupo da midia? (As opcoes sao filme, jogo ou disco. Lembre-se de usar sempre letras minusculas!)" << std::endl;
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
        std::cout << "Qual a categoria da midia? (As opcoes sao lancamento, promocao ou estoque. Lembre-se de usar sempre letras minusculas!)" << std::endl;
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
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        dvd.setCategoria(categoria);
    }

    std::cout << "Qual o titulo da midia? "
                  << "(Sem caracteres especiais (use _ no lugar de espaco). Lembre-se de usar sempre letras minusculas!)" << std::endl;
        
        std::cin>>titulo;

        // Verificar se o titulo contém apenas caracteres alfanumericos e minusculas
        while (std::cin)
        {
            if (std::all_of(titulo.begin(), titulo.end(), [](char c)
                            { return std::islower(c) || c == '_';}))
            {

                midia.setTitulo(titulo);
                break;
            }
            else
            {
                std::cout << "ERRO: Titulo invalido. Por favor, siga asco." << std::endl;
            }
        }

        std::cout << "Qual o genero da midia? "
                  << "Lembre-se de usar sempre letras minusculas e sem caracteres especiais!)" << std::endl;
        while (true)
        {
            std::cin >> genero;
            if (std::all_of(genero.begin(), genero.end(), [](char c)
                            { return std::islower(c) || std::isalnum(c); }))
            {
                midia.setGenero(genero);
                break;
            }
            else
            {
                std::cout << "ERRO: Genero invalido. Por favor, siga as instrucoes." << std::endl;
            }
        }

        if (grupo == "filme")
        {
            while (true)
            {
                std::cout << "Qual a nota de critica? (O valor minimo eh 0 e o maximo eh 10, use apenas numeros inteiros)" << std::endl;
                std::cin >> notaCritica;
                if (notaCritica < 0 || notaCritica > 10){
                    std::cout << "ERRO: Nota invalida. Por favor, insira novamente." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else if (notaCritica>=0 && notaCritica<=10){
                    filme.setNotaCritica(notaCritica);
                    break;
                }
            }
            
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
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                    std::cout << "ERRO: Cantor ou banda invalido. Por favor, siga as instrucoes." << std::endl;
                }
            }

            std::cout << "Qual o numero de musicas do disco? (Use apenas numeros inteiros)" << std::endl;
            std::cin >> numeroMusicas;

            while (true)
            {
                if (std::cin.fail())
                {
                    std::cout << "ERRO: Entrada invalida. Por favor, insira novamente." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                    std::cout << "ERRO: Entrada invalida. Por favor, insira novamente." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        }
        midia.setQuantidadeDisponivel(quantidadeDisponivel);
        escreverNoArquivo(midia,"midias.txt",dvd,filme,fitaVideo,disco,jogo);
        std::cout << "Midia cadastrada com sucesso!" << std::endl;
      
}


void removerMidia(int codigo)
{
    
    std::ifstream inputFile("midias.txt");
    std::ofstream outputFile("temp.txt");

    if (inputFile.is_open() && outputFile.is_open())
    {
        std::string line;
        bool found = false;

        while (std::getline(inputFile, line))
        {
            // Verificar se a linha contém o código da mídia
            if (line.find(std::to_string(codigo)) != std::string::npos)
            {
                found = true;
                continue; // Pular a linha a ser excluída
            }

            outputFile << line << std::endl;
        }
        inputFile.close();
        outputFile.close();

        if (found)
        {
            std::remove("midias.txt");
            std::rename("temp.txt", "midias.txt");
            std::cout << "Midia excluida com sucesso." << std::endl;
        }
        else
        {
            std::cout << "ERRO: codigo nao encontrado." << std::endl;
        }
    }
    else
    {
        std::cout << "Erro ao abrir os arquivos." << std::endl;
    }
}
void listarFilmes()
{
    std::vector<std::vector<std::string>> midias = PegarLinhasDoArquivo("midias.txt", true);
    char entrada;
    std::cout << "Como deseja ordenar as midias? (As opcoes sao: c para codigo ou t para titulo. Lembre-se de usar sempre letras minusculas!)" << std::endl;     
    std::cin >> entrada;

    do
    {
        if (entrada == 'c')
        {
            // Ordenar por código de forma crescente
            std::sort(midias.begin(), midias.end(), [](const std::vector<std::string> &a, const std::vector<std::string> &b)
                    { return a[0] < b[0]; });
            for (auto &midia : midias)
            {
                std::cout << "Codigo: " << midia[0] << " | " <<"Quantidade disponivel: "  << midia[1] << " | " << "Quantidade total: " << midia[2] << " | " << "Tipo: " << midia[3] << " | " << "Grupo: " << midia[4] << " | " << "Categoria: " << midia[5] << " | " << "Titulo: " << midia[6] << " | " << "Genero: " << midia[7] << " | " << "Nota de critica: " << midia[8] << " | " << "Numero de musicas: " << midia[9] << " | " << "Cantor/Banda: " << midia[10] << " | " << "Plataforma: " << midia[11] << " | " << "Rebobinado: " << midia[12] << std::endl;
            }
          break;
        }
        else if (entrada == 't')
        {
            // Ordenar em ordem alfabética pelo título
            std::sort(midias.begin(), midias.end(), [](const std::vector<std::string> &a, const std::vector<std::string> &b)
                    { return a[6] < b[6]; });
            for (auto &midia : midias)
            {
                std::cout << "Codigo: " << midia[0] << " | " <<"Quantidade disponivel: "  << midia[1] << " | " << "Quantidade total: " << midia[2] << " | " << "Tipo: " << midia[3] << " | " << "Grupo: " << midia[4] << " | " << "Categoria: " << midia[5] << " | " << "Titulo: " << midia[6] << " | " << "Genero: " << midia[7] << " | " << "Nota de critica: " << midia[8] << " | " << "Numero de musicas: " << midia[9] << " | " << "Cantor/Banda: " << midia[10] << " | " << "Plataforma: " << midia[11] << " | " << "Rebobinado: " << midia[12] << std::endl;
            }
          break;
        }

        else
        {
            std::cout << "ERRO: Opção inválida. Por favor, insira novamente." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }while (entrada == 'c' || entrada=='t');
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
