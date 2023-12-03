#include <iostream>
#include "..\include\ArquivoClientes.hpp"
#include "..\include\cadastroMidia.hpp"
#include "..\include\Gerenciador_de_arquivos.hpp"
#include "..\include\controle_locacao.hpp"



using namespace std;

int main(){

    BancoClientes banco;
    std::string entrada;
    std::string nome;
    char ordem;
    std::string cpf;
    std::vector<std::string> codigos;
    Midia midia;
    Jogo jogo;
    FitaVideo fitaVideo;
    Filme filme;
    Disco disco;
    DVD dvd;
    int codigo;
    
    do{
        std::cin >> entrada;
        if(entrada == "CC"){
            std::cin >> cpf;
            std::cin >> nome;
            try{
                banco.cadastrarCliente(cpf, nome);
            }
            catch(std::invalid_argument &e){
                std::cout << "ERRO: " << e.what() << std::endl;

            }
        }

        else if(entrada == "RC"){
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
            std::cout << "Digite C para ordenar de acordo com o código ou N para ordem alfabética dos títulos."<< std::endl;
            std::cin >> ordem;
            banco.imprimirRelatorio(ordem);

            }
            catch (std::invalid_argument &e){
                std::cout << "ERRO: " << e.what() << std::endl;
            }
            
            
        }

        else if(entrada == "LF"){


        }

        else if(entrada == "LA"){

        }
        
        else if(entrada == "CF"){
           cadastrarMidia(midia, dvd, disco, jogo, fitaVideo, filme);
        }
        
        
        else if(entrada == "RF"){
            cin >> codigo;
            removerMidia(codigo);
        }
        

        else if(entrada == "AL"){
            int numFilmes;
            cout << "Digite o CPF (apenas numeros) do cliente e quantos filmes serao alugados (separados por espaco): ";
            cin >> cpf >> numFilmes;

            if(banco.Pesquisar(cpf)){
            // Cria um vetor para armazenar os códigos dos filmes
            vector<string> codigos(numFilmes);
            for (int i = 0; i < numFilmes; ++i) {
                cout << "Digite o codigo do filme " << i + 1 << ": ";
                cin >> codigos[i];
            }

            try{
                locacaoMidia(codigos, cpf);
                cout << "Midias alugadas com sucesso." << endl;
                codigos.clear();
            }
            catch (invalid_argument &e) {
                cout << "ERRO: " << e.what() << endl;
            }
            }
            else{
                cout <<"CPF não encontrado." << endl;
            }


        }

        else if(entrada == "DV"){
        int numFilmes;
        cout << "Digite o CPF (apenas numeros) do cliente e quantos filmes serao devolvidos (separados por espaco): ";
        cin >> cpf >> numFilmes;

        vector<string> codigos(numFilmes);
            for (int i = 0; i < numFilmes; ++i) {
                cout << "Digite o codigo do filme " << i + 1 << ": ";
                cin >> codigos[i];
            }

            Devolver_Midia(codigos, cpf);
            cout << "Midias devolvidas com sucesso." << endl;

        codigos.clear();
        }

        else if(entrada == "FS")
            break;
        
        else {
            std::cout << "Entre com algum dos comando:" << std::endl;
            std::cout << "LA <Nome do Arquivo> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Ler arquivo de cadastro" << std::endl;
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