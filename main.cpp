#include <iostream>
#include "cadastro_de_clientes\ArquivoClientes.hpp"
#include "cadastro_de_midia\cadastroMidia.cpp"

int main(){

    BancoClientes banco;
    std::string entrada
    std::string nome;
    char ordem;
    std::string cpf;
    std::vector<std::string> codigos;
	std::string codigo;
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
    
    do{
        std::cin >> entrada;
        if(entrada == "CC"){
            std::cin >> cpf;
            std::cin >> nome;
            try{
                banco.cadastrarCliente(cpf, nome);
            }
            catch(invalid_argument &e){
                std::cout << "ERRO: " << e.what() << endl;

            }
        }

        else if(entrada == "RC"){
          cin >> cpf;
            try{
                banco.removerCliente(cpf);
            }
            catch(invalid_argument &e){
                std::cout << "ERRO: " << e.what() << endl;

            }
        }

        else if(entrada == "LC"){
            try{
            std::cout << "Digite C para ordenar de acordo com o código ou N para ordem alfabética dos títulos."<< endl;
            std::cin >> ordem;
            banco.imprimirRelatorio(ordem);

            }
            catch (invalid_argument &e){
                std::cout << "ERRO: " << e.what() << endl;
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
            std::vector<string> codigos(numFilmes);
            for (int i = 0; i < numFilmes; ++i) {
                cin >> codigos[i];
            }

            try{
                banco.getCliente(cpf)->locacaoMidia(codigos);
                codigos.clear();
            }
            catch (invalid_argument &e) {
                std::cout << "ERRO: " << e.what() << endl;
            }
            }
            else{
                std::cout <<"CPF não encontrado." << endl;
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
        catch (invalid_argument &e){
            std::cout << "ERRO: " << e.what() << endl;
        }
        codigos.clear();
        }


        else if(entrada == "FS")
            break;
        
        else {
            std::cout << "Entre com algum dos comando:" << endl;
            std::cout << "LA <Nome do Arquivo> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Ler arquivo de cadastro" << endl;
            std::cout << "CF <Tipo: F|D> <quantidade> <codigo> <titulo> <categoria no caso de DVD> - -- Cadastrar filme" << endl;
            std::cout << "RF <codigo> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Remover filme" << endl;
            std::cout << "LF [C|T] -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Listar Filmes ordenados por Código ou Título:" << endl;
            std::cout << "CC <CPF> <Nome> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - Cadastrar Cliente" << endl;
            std::cout << "RC <CPF> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Remover Cliente" << endl;
            std::cout << "LC [C|N] -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Listar Clientes ordenados por Código ou Nome:" << endl;
            std::cout << "AL <CPF> <Codigo1> <Codigo N> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Aluguel Filme" << endl;
            std::cout << "DV <CPF> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Devolução Filme" << endl;
            std::cout << "FS -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Finalizar Sistema" << endl;
        }
    }while(cin);


    return 0;
}