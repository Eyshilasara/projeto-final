#include <iostream>
#include "cadastro_de_clientes\ArquivoClientes.hpp"

int main(){

    BancoClientes banco;
    string entrada, nome;
    char ordem;
    string cpf;
    std::vector<std::string> codigos;
	std::string codigo;
    
    do{
        cin >> entrada;
        if(entrada == "CC"){
            cin >> cpf;
            cin >> nome;
            try{
                banco.cadastrarCliente(cpf, nome);
            }
            catch(invalid_argument &e){
                cout << "ERRO: " << e.what() << endl;

            }
        }

        else if(entrada == "RC"){
          cin >> cpf;
            try{
                banco.removerCliente(cpf);
            }
            catch(invalid_argument &e){
                cout << "ERRO: " << e.what() << endl;

            }
        }

        else if(entrada == "LC"){
            try{
            cout << "Digite C para ordenar de acordo com o código ou N para ordem alfabética dos títulos."<< endl;
            cin >> ordem;
            banco.imprimirRelatorio(ordem);

            }
            catch (invalid_argument &e){
                cout << "ERRO: " << e.what() << endl;
            }
            
            
        }

        else if(entrada == "LF"){


        }

        else if(entrada == "LA"){

        }
        else if(entrada == "CF"){

        }
        else if(entrada == "RF"){

        }
        else if(entrada == "LF"){

        }

        else if(entrada == "AL"){
            int numFilmes;
            cin >> cpf >> numFilmes;

            try{
                Cliente* cliente = banco.getCliente(cpf);
            }
            catch (invalid_argument &e) {
                cout << "ERRO: " << e.what() << endl;
            }

            // Cria um vetor para armazenar os códigos dos filmes
            vector<string> codigos(numFilmes);
            for (int i = 0; i < numFilmes; ++i) {
                cin >> codigos[i];
            }

            banco.getCliente(cpf)->locacaoMidia(codigos);
            codigos.clear();

        }

        else if(entrada == "DV"){
        cout << "Digite o CPF do cliente: ";
        cin >> cpf;
	    cout << "Digite o codigo da midia que sera devolvida (para encerrar digite \"sair\"): ";

	    while (cin >> codigo && codigo != "sair") {
	        codigos.push_back(codigo);
	    }
        try{
            banco.getCliente(cpf)->Devolver_Midia(codigos);
        }
        catch (invalid_argument &e){
            cout << "ERRO: " << e.what() << endl;
        }
        codigos.clear();
        }


        else if(entrada == "FS")
            break;
        
        else {
            cout << "Entre com algum dos comando:" << endl;
            cout << "LA <Nome do Arquivo> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Ler arquivo de cadastro" << endl;
            cout << "CF <Tipo: F|D> <quantidade> <codigo> <titulo> <categoria no caso de DVD> - -- Cadastrar filme" << endl;
            cout << "RF <codigo> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Remover filme" << endl;
            cout << "LF [C|T] -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Listar Filmes ordenados por Código ou Título:" << endl;
            cout << "CC <CPF> <Nome> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - Cadastrar Cliente" << endl;
            cout << "RC <CPF> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Remover Cliente" << endl;
            cout << "LC [C|N] -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Listar Clientes ordenados por Código ou Nome:" << endl;
            cout << "AL <CPF> <Codigo1> <Codigo N> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Aluguel Filme" << endl;
            cout << "DV <CPF> -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Devolução Filme" << endl;
            cout << "FS -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Finalizar Sistema" << endl;
        }
    }while(cin);



    return 0;
}