#include <iostream>
#include "..\include\cadastroMidia.hpp"
#include "..\include\Gerenciador_de_arquivos.hpp"
#include "..\include\controle_locacao.hpp"
#include "..\include\ArquivoClientes.hpp"



int main(){

    BancoClientes banco;
    std::string entrada;
    char opcao;
    std::string nome;
    std::string cpf;
    char ordem;
    std::vector<std::string> codigos;
    Midia midia;
    Jogo jogo;
    FitaVideo fitaVideo;
    Filme filme;
    Disco disco;
    DVD dvd;
    int codigo;
    
        std::cout << "                       (####)                                                   " << std::endl;
        std::cout << "                     (#######)                                                  " << std::endl;
        std::cout << "                    (#########)                                                 " << std::endl;
        std::cout << "                   (#########)                                                  " << std::endl;
        std::cout << "                    (#########)                                                 " << std::endl;
        std::cout << "                   (#########)                                                  " << std::endl;
        std::cout << "     __&__          (#########)                                                 " << std::endl;
        std::cout << "    /     \        (#########)   | / / /|     /\ /\  /\               /\        " << std::endl;
        std::cout << "   |       |      (#########)    |      |     | V  \/  \---.    .----/  \----.  " << std::endl;
        std::cout << "   |  (o)(o)       (o)(o)(##)    |      |      \_        /       \          /   " << std::endl;
        std::cout << "   C   .---_)    ,_C     (##)    | (o)(o)       (o)(o)  <__.   .--\ (o)(o) /__. " << std::endl;
        std::cout << "   | |.___|    /___,   (##)     C      _)     _C         /     \     ()     /   " << std::endl;
        std::cout << "   |  \__/       \     (#)       | ,___|     /____,   )  \      >   (C_)   <    " << std::endl;  
        std::cout << "   /_____\        |    |         |   /         \     /----'    /___\____/___\   " << std::endl; 
        std::cout << "  /_____/ \       OOOOOO        /____\          ooooo             /|    |\      " << std::endl;
        std::cout << " /         \     /      \      /      \        /     \           /        \     " << std::endl;
        std::cout << "____________________________________________________________________________    " << std::endl;
        std::cout << "|                                                                           |   " << std::endl;
        std::cout << "|                Digite um comando para iniciar o sistema                   |   " << std::endl;
        std::cout << "|                          Lista de comandos:                               |   " << std::endl;
        std::cout << "|  LA ---------------------------------- Ler arquivo de cadastro de midias  |   " << std::endl;
        std::cout << "|  CF ---------------------------------------------------- Cadastrar midia  |   " << std::endl;
        std::cout << "|  RF ------------------------------------------------------ Remover midia  |   " << std::endl;
        std::cout << "|  LF ----------------------- Listar filmes ordenados por titulo ou codigo  |   " << std::endl;
        std::cout << "|  CC ----------------------------------------------- Cadastrar cliente(s)  |   " << std::endl;
        std::cout << "|  RC ------------------------------------------------- Remover cliente(s)  |   " << std::endl;
        std::cout << "|  LC -------------------------- Listar Clientes ordenados por CPF ou Nome  |   " << std::endl;
        std::cout << "|  AL ---------------------------------------------------- Alugar midia(s)  |   " << std::endl;
        std::cout << "|  DV ------------------------------------------- Devolver midias alugadas  |   " << std::endl;
        std::cout << "|  FS -------------------------------------------------- Finalizar sistema  |   " << std::endl;
        std::cout << "|___________________________________________________________________________|   " << std::endl;

 
    do{
        
        
        std::cin >> entrada;
        if(entrada == "CC"){
            std::cout << "Cadastro de Clientes." << endl;
            std::cout << "Digite um CPF: ";
            std::cin >> cpf;
            cout << "Digite um nome: ";
            std::cin >> nome;
            try{
                banco.cadastrarCliente(cpf, nome);
            }
            catch(std::invalid_argument &e){
                std::cout << "ERRO: " << e.what() << std::endl;

            }
        }

        else if(entrada == "RC"){
            std::cout << "Remocao de Clientes." << endl;
            std::cout << "Digite um CPF: ";
            std::cin >> cpf;
            try{
                banco.removerCliente(cpf);
            }
            catch(std::invalid_argument &e){
                std::cout << "ERRO: " << e.what() << std::endl;

            }
        }

        else if(entrada == "LC"){
            try{
            std::cout << "Listagem de Clientes." << endl;
            std::cout << "Digite C para ordenar de acordo com o codigo ou N para ordem alfabetica dos nomes: ";
            std::cin >> ordem;
            banco.imprimirRelatorio(ordem);

            }
            catch (std::invalid_argument &e){
                std::cout << "ERRO: " << e.what() << std::endl;
            }
            
            
        }

        else if(entrada == "LF"){
            listarFilmes();
        }

        else if(entrada == "LA"){
            std::cout << "Midias cadastradas:" << std::endl;
            lerArquivo("midias.txt");
        }
        
        else if(entrada == "CF"){
            //!> cin e cout incluso na função abaixo  
            cadastrarMidia(midia, dvd, disco, jogo, fitaVideo, filme);
        }
        
        
        else if(entrada == "RF"){
            removerMidia(codigo);
        }
        

        else if(entrada == "AL"){
            int numFilmes;
            std::cout << "Digite o CPF (apenas numeros) do cliente:" << std::endl;
            std::cin >> cpf;
            

            if(banco.Pesquisar(cpf)){
                std::cout << "Informe quantos filmes serao alugados (separados por espaco): " << std::endl;
                std::cin >>  numFilmes;
                std::vector<std::string> codigos(numFilmes);
                std::vector<std::vector<std::string>> midia;
                for (int i = 0; i < numFilmes; ++i) {
                    do
                    {
                        std::cout << "Digite o codigo do filme " << i + 1 << ": ";
                        std::cin >> codigo;

                        midia = filtro("midias.txt", 0, std::to_string(codigo), true);

                        if(midia.size() == 0){
                            std::cout << "ERRO: Codigo nao encontrado. Por favor insira novamente." << std::endl;
                            std::cout << "Deseja ver a lista de midias cadastradas? (Insira s para sim ou n para nao) " << endl;
                            std::cin >> opcao;

                            if(opcao == 's'){
                                std::cout << "Midias cadastradas:" << std::endl;
                                lerArquivo("midias.txt");
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                        }
                        else break;
                        midia.clear();
                    
                    }
                    while(true);

                    codigos[i] = std::to_string(codigo);  
                }
                locacaoMidia(codigos, cpf);
               
                codigos.clear();           
            }
        
            else{
                std::cout <<"CPF nao encontrado. Voltando ao menu principal!" <<std::endl;
            }
        }
        

        else if(entrada == "DV"){
            int numFilmes;
            std::cout << "Digite o CPF (apenas numeros) do cliente:" << std::endl;
            std::cin >> cpf;
            
            if(!banco.Pesquisar(cpf)){
                std::cout <<"CPF nao encontrado. Voltando ao menu principal!" <<std::endl;
            }

            else{
                std::cout << "Informe quantos filmes serao devolvidos (separados por espaco): " << std::endl;
                std::cin >>  numFilmes;
                std::vector<std::string> codigos(numFilmes);
                std::vector<std::vector<std::string>> midia;
                for (int i = 0; i < numFilmes; ++i) {
                    do
                    {
                        std::cout << "Digite o codigo do filme " << i + 1 << ": ";
                        std::cin >> codigo;

                        midia = filtro("midias.txt", 0, std::to_string(codigo), true);

                        if(midia.size() == 0){
                            std::cout << "ERRO: Codigo nao encontrado. Por favor insira novamente." << std::endl;
                            std::cout << "Deseja ver a lista de midias alugadas? (Insira s para sim ou n para nao) " << endl;
                            std::cin >> opcao;

                            if(opcao == 's'){
                                std::cout << "Midias registradas:" << std::endl;
                                lerArquivo("midias.txt");
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                        }
                        else break;
                        midia.clear();

                    }
                    while(true);

                    codigos[i] = std::to_string(codigo);  
                }
                
                Devolver_Midia(codigos, cpf);
                codigos.clear();           

                std::cout << "Deseja gerar relatorio das suas locacoes? (Insira s para sim ou n para nao)" << std::endl;
                std::cin >> opcao;

                if(opcao == 's'){
                    std::cout << "Midias alugadas:" << std::endl;
                    relatorio(1, cpf);
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }

        else if(entrada == "FS"){
            std::cout << "Deseja gerar relatorio de locacoes? Insira s para sim ou n para nao" << std::endl;
            std::cin >> opcao;
            string op;
            
            if(opcao == 's'){
                std::cout << "Qual tipo de relatorio deseja gerar?" << std::endl;
                std::cout << "0 - Todas as locacoes" << std::endl;
                std::cout << "1 - Locacoes por cliente" << std::endl;
                std::cout << "2 - Locacoes em aberto ou concluidas" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> opcao;
                switch (opcao)
                {
                    case '0':
                        relatorio(0, "");
                        break;
                    case '1':
                        std::cout << "Digite o CPF do cliente: " << std::endl;
                        std::cin >> cpf;
                        relatorio(1, cpf);
                        break;
                    case '2':
                        std::cout << "Digite 0 para locacoes em aberto ou 1 para locacoes concluidas: " << std::endl;
                        std::cin >> op;
                        relatorio(2, op);
                        break;
                    default: break;
                }

             std::cout << "Voltando ao menu principal!" << std::endl;   
            }
            else{
                std::cout << "Finalizando sistema..." << std::endl;
                break;
            }
        }

        else {
            std::cout << "Entre com algum dos comando:" << std::endl;
            std::cout << "LA <Nome do Arquivo> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Ler arquivo de cadastro de filme" << std::endl;
            std::cout << "CF <Tipo: F|D> <quantidade> <codigo> <titulo> <categoria no caso de DVD> - -- Cadastrar filme" << std::endl;
            std::cout << "RF <codigo> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Remover filme" << std::endl;
            std::cout << "LF [C|T] -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Listar Filmes ordenados por Código ou Título:" << std::endl;
            std::cout << "CC <CPF> <Nome> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - Cadastrar Cliente" << std::endl;
            std::cout << "RC <CPF> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Remover Cliente" << std::endl;
            std::cout << "LC [C|N] -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Listar Clientes ordenados por CPF ou Nome:" << std::endl;
            std::cout << "AL <CPF> <Codigo1> <Codigo N> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Aluguel Filme" << std::endl;
            std::cout << "DV <CPF> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Devolução Filme" << std::endl;
            std::cout << "FS -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Finalizar Sistema" << std::endl;
        }
    }while(std::cin);


    return 0;
}