#include <iostream>
#include "/home/andregp/Projeto/projeto-final/cadastro_de_clientes/ArquivoClientes.hpp"

int main(){

    BancoClientes banco("Clientes.txt");
    string entrada, nome;
    char ordem;
    string cpf;


    do{
        cin >> entrada;
        if(entrada == "CC"){
            cin >> cpf;
            cin >> nome;
            banco.cadastrarCliente(cpf, nome);
        }
        else if(entrada == "RC"){
            cin >> cpf;
            banco.removerCliente(cpf);
        }
        else if(entrada =="P"){
            bool teste = banco.Pesquisar("307");
            cout << teste;
        }
        else if(entrada == "LC"){
            do{
            cout << "Digite C para ordenar de acordo com o CPF ou N para ordem alfabética dos nomes."<< endl;
            cin >> ordem;
            if(ordem != 'C' && ordem != 'N')
                cout << "Entrada inválida."<< endl;
            
            }while(ordem != 'C' && ordem != 'N');

            banco.imprimirRelatorio(ordem);
            
        }

        else if(entrada == "LF"){
            do{
            cout << "Digite C para ordenar de acordo com o código ou T para ordem alfabética dos títulos."<< endl;
            cin >> ordem;
            if(ordem != 'C' && ordem != 'T')
                cout << "Entrada inválida."<< endl;
            
            }while(ordem != 'C' && ordem != 'T');

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

        }
        else if(entrada == "DV"){
        }


        else if(entrada == "FS")
            break;

        

    }while(entrada != "EXIT");



    return 0;
}