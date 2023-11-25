
#include "BancoClientes.hpp"
using namespace std;

int main(){

    BancoClientes banco;
    string entrada, nome;
    char ordem;
    long long int cpf;


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
        
        else if(entrada == "IR"){
            do{
            cout << "Digite C para ordenar de acordo com o CPF ou N para ordem alfabética dos nomes."<< endl;
            cin >> ordem;
            if(ordem != 'C' && ordem != 'N')
                cout << "Entrada inválida."<< endl;
            
            }while(ordem != 'C' && ordem != 'N');

            banco.imprimirRelatorio(ordem);
            
        }

        

    }while(entrada != "EXIT");





    return 0;
}