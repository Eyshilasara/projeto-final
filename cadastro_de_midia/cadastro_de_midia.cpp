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

    std::cout << "Qual o tipo da mídia? (As opções são DVD ou fita de vídeo. Lembre-se de usar sempre letras minúsculas!)" << std::endl;

    while (true) {
        std::cin >> tipo;

        if (tipo == "DVD" || tipo == "fita de video") {
            break;
        } else {
            std::cout << "Tipo de mídia inválido. Por favor, insira novamente." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    midia.setTipo(tipo);

    if (tipo == "DVD") {
        while (true) {
            std::cout << "Qual o grupo da mídia? (As opções são filme, jogo ou disco. Lembre-se de usar sempre letras minúsculas!)" << std::endl;
            std::cin >> grupo;

            if (grupo == "filme" || grupo == "jogo" || grupo == "disco") {
                break;
            } else {
                std::cout << "Grupo inválido. Por favor, insira novamente." << std::endl;
            }
        }
// while para categoria
        std::cout << "Qual a categoria da mídia? (As opções são lancamento, promocao ou estoque)" << std::endl;

        while (true) {
            std::cin >> categoria;

            if (categoria == "lancamento" || categoria == "promocao" || categoria == "estoque") {
                break;
            } else {
                std::cout << "Categoria inválida. Por favor, insira novamente." << std::endl;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        dvd.setCategoria(categoria);

        if (grupo == "filme") {
        while (true) {
                std::cout << "Qual a nota de crítica? (Use apenas números sem casas decimais)" << std::endl;
                if (std::cin >> nota_de_critica) {
                    break;
                } else {
                    std::cout << "Entrada inválida. Por favor, insira novamente." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            filme.setNotaDeCritica(nota_de_critica);
// while para plataforma
        } else if (grupo == "jogo") {
            std::cout << "Qual a plataforma do jogo? (As opções são PS4, XBOX ou PC. Lembre-se de usar sempre letras maiusculas!)" << std::endl;
            std::cin >> plataforma;
            jogo.setPlataforma(plataforma);

        } else if (grupo == "disco") {
            std::cout << "Qual o artista do disco? (Lembre-se de usar sempre letras minúsculas!)" << std::endl;
            std::cin >> artista;

            while (true) {
                std::cout << "Qual o número de músicas do disco? (Use apenas números inteiros)" << std::endl;
                if (std::cin >> numeroMusicas) {
                    break;
                } else {
                    std::cout << "Entrada inválida. Por favor, insira novamente." << std::endl;
                    // Limpar o estado de erro e o buffer de entrada
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            disco.setNumeroMusicas(numeroMusicas);
        }
    } 
    else if (tipo == "fita de video") {
        while (true) {
            std::cout << "A fita é rebobinada? (As opções são 1 para sim ou 0 para não)" << std::endl;
            if (std::cin >> rebobinado) {
                break;
            } else {
                std::cout << "Entrada inválida. Por favor, insira novamente." << std::endl;
                // Limpar o estado de erro e o buffer de entrada
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        fita_de_video.setRebobinado(rebobinado);
    }
// mudar ordem
    std::cout << "Qual o titulo da midia? " << "(Sem caracteres especiais. Lembre-se de usar sempre letras minusculas!)" << std:: endl;
    std::cin >> titulo;
    midia.setTitulo(titulo);
// caso base codigo ja existente
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

    std::cout << "Mídia cadastrada com sucesso!" << std::endl;
    return "Mídia cadastrada com sucesso!";
}

void Cadastro::excluirMidia(int codigo) {
    // Encontrar a mídia com base no código
    auto it = std::find_if(midias.begin(), midias.end(), [codigo](const Midia& m) {
        return m.getCodigo() == codigo;
    });

    if (it != midias.end()) {
        // Remover a mídia se encontrada
        midias.erase(it);
        std::cout << "Mídia excluída com sucesso." << std::endl;
    } else {
        std::cout << "Mídia não encontrada." << std::endl;
    }
}