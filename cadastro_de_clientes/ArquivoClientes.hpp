#ifndef ARQUIVOCLIENTES_H
#define ARQUIVOCLIENTES_H

#include <ctime>
#include <stdexcept>
#include "Cliente.hpp"

using namespace std;

class BancoClientes{
    public:
    map<string ,Cliente*> banco;   // mapa com os clientes e os nomes, é perdido
  
    public:

    ~BancoClientes(){
        map<string ,Cliente*>::iterator it;
        for (it = banco.begin(); it != banco.end(); it++) 
            delete(it->second);
    }

    void cadastrarCliente(string cpf, string nome);
    void removerCliente(string cpf);
    bool Pesquisar(string cpf); 
    void imprimirRelatorio(char ordem);
    Cliente* getCliente(string cpf);
    bool isValidCPF(std::string cpf);
};


#endif