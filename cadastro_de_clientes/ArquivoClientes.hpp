#ifndef BANCOCLIENTES_H
#define BANCOCLIENTES_H

#include <iostream>
#include <fstream>
#include <map>

#include "Cliente.hpp"

using namespace std;

class BancoClientes{
    public:
    ofstream file;
    map<long long int,Cliente*> banco;


    public:
    ~BancoClientes(){
        map<long long int,Cliente*>::iterator it;
        for (it = banco.begin(); it != banco.end(); it++) 
            delete(it->second);
        this->file.close();
    }
    void cadastrarCliente(long long int cpf, string nome);
    void removerCliente(long long int cpf);
    bool Pesquisar(long long int cpf); 
    void imprimirRelatorio(char ordem);
};
#endif