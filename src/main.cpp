#include <iostream>
#include "..\include\ArquivoClientes.hpp"
#include "..\include\cadastroMidia.hpp"

int main(){

    BancoClientes banco;
    std::string entrada;
    std::string nome;
    char ordem;
    std::string cpf;
    std::vector<std::string> codigos;
	std::string codigo;
    std::string tipo;
    std::string titulo;
    int codigo1;
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
            std::string cadastrarMidia(Midia &midia, DVD &dvd, Disco &disco, Jogo &jogo, FitaVideo &fitaVideo, Filme &filme);
        }

        else if(entrada == "RF"){
            void removerMidia(int codigo);
        }
        
        else if(entrada == "LF"){

        }

        else if(entrada == "AL"){
            int numFilmes;
            std::cin >> cpf >> numFilmes;

            if(banco.Pesquisar(cpf)){
            // Cria um vetor para armazenar os códigos dos filmes
            std::vector<std::string> codigos(numFilmes);
            for (int i = 0; i < numFilmes; ++i) {
                std::cin >> codigos[i];
            }

            try{
                banco.getCliente(cpf)->locacaoMidia(codigos);
                codigos.clear();
            }
            catch (std::invalid_argument &e) {
                std::cout << "ERRO: " << e.what() << std::endl;
            }
            }
            else{
                std::cout <<"CPF não encontrado." << std::endl;
            }
            

        }

        else if(entrada == "DV"){
        std::cout << "Digite o CPF do cliente: ";
        std::cin >> cpf;
	    std::cout << "Digite o codigo da midia que sera devolvida (para encerrar digite \"sair\"): ";

	    while (std::cin >> codigo && codigo != "sair") {
	        codigos.push_back(codigo);
	    }
        try{
            banco.getCliente(cpf)->Devolver_Midia(codigos);
        }
        catch (std::invalid_argument &e){
            std::cout << "ERRO: " << e.what() << std::endl;
        }
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
            std::cout << "LC [C|N] -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Listar Clientes ordenados por Código ou Nome:" << std::endl;
            std::cout << "AL <CPF> <Codigo1> <Codigo N> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Aluguel Filme" << std::endl;
            std::cout << "DV <CPF> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Devolução Filme" << std::endl;
            std::cout << "FS -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Finalizar Sistema" << std::endl;
        }
    }while(std::cin);


    return 0;
}