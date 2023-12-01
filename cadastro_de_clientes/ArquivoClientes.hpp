#ifndef ARQUIVOCLIENTES_H
#define ARQUIVOCLIENTES_H

#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include "Cliente.hpp"

using namespace std;

class BancoClientes{
    public:
    ofstream file;
    map<long long int,Cliente*> banco;

    time_t now = time(0);
    char* dt = ctime(&now);


    public:
    BancoClientes(const string& filename) : file(filename, std::ios::in | std::ios::out| std::ios::app) {
        if (!file) {
            cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        }
        else{
            this->file << " \nCADASTRO DE CLIENTES " << dt  <<endl;
        }
    }
    ~BancoClientes(){
        map<long long int,Cliente*>::iterator it;
        for (it = banco.begin(); it != banco.end(); it++) 
            delete(it->second);
        if (this->file.is_open()) {
            this->file.close();
        }
    }

    void cadastrarCliente(long long int cpf, string nome);
    void removerCliente(long long int cpf);
    bool Pesquisar(long long int cpf); 
    void imprimirRelatorio(char ordem);
};


#endif