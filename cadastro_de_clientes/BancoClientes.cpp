#include "BancoClientes.hpp"
using namespace std;



void BancoClientes::cadastrarCliente(long long int cpf, string nome){
    map<long long int, Cliente*> m;
    if(this->Pesquisar(cpf))
        cout<<"ERRO: CPF repetido" << endl;
    else{
        Cliente *cliente = new Cliente(nome, cpf);
        this->banco.insert(pair<long long int,Cliente*>(cpf, cliente));
        cout << "Cliente " << cpf  << " cadastrado com sucesso." << endl;
    }
}

void BancoClientes::removerCliente(long long int cpf){
    if(this->Pesquisar(cpf)){
        this->banco.erase(cpf);
        cout << "Cliente " << cpf << " removido com sucesso." << endl;
    }
    else
        cout << "ERRO: Cliente nao encontrado" << endl;
   
}
bool BancoClientes::Pesquisar(long long int cpf){
    if (this->banco.find(cpf) != this->banco.end())
        return true;
    else
        return false;
}
void BancoClientes::imprimirRelatorio(char ordem){
    map<long long int, Cliente*> :: iterator it;
    map<string, long long int> :: iterator it2;
    if(ordem == 'C'){
    for (it = this->banco.begin(); it != this->banco.end(); it++) 
        cout << it->first << " " << it->second->get_nome() << endl;
    
    }
    else if (ordem == 'N'){
        map<string, long long int> aux;
        for (it = this->banco.begin(); it != this->banco.end(); it++) 
            aux.insert(pair<string, int>(it->second->get_nome(),it->second->get_cpf()));

        for (it2 = aux.begin(); it2 != aux.end(); it2++) 
            cout << it2->second << " " << it2->first << endl;

    }

}