#ifndef ARQUIVOCLIENTES_H
#define ARQUIVOCLIENTES_H

#include <ctime>
#include <stdexcept>
#include "Cliente.hpp"


class BancoClientes{
    private:
    std::map<std::string ,Cliente*> banco;   //!< map com os clientes e as chaves, é perdido após o fim da execução
  
    public:

    ~BancoClientes(){
        std::map<std::string ,Cliente*>::iterator it;
        for (it = banco.begin(); it != banco.end(); it++) 
            delete(it->second);
    }

    void cadastrarCliente(std::string cpf, std::string nome);
    void removerCliente(std::string cpf);
    bool Pesquisar(std::string cpf); 
    void imprimirRelatorio(char ordem);
    Cliente* getCliente(std::string cpf);
    bool isValidCPF(std::string cpf);
};


#endif