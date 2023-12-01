#ifndef ARQUIVOCLIENTES_H
#define ARQUIVOCLIENTES_H

#include <iostream>
#include <map>
#include <ctime>
#include <sstream> 
#include <iomanip>  // ws
#include <fstream>
#include "Cliente.hpp"

using namespace std;

class BancoClientes{
    public:
    fstream file;
    map<string ,Cliente*> banco;

    time_t now = time(0);
    char* dt = ctime(&now);


    public:
    BancoClientes(const string& filename) : file(filename, std::ios::in | std::ios::out| std::ios::app) {
        if (!file) {
            cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        }
        else{
            this-> file << " \nCADASTRO DE CLIENTES " << dt  <<endl;
        }
    }
    ~BancoClientes(){
        map<string ,Cliente*>::iterator it;
        for (it = banco.begin(); it != banco.end(); it++) 
            delete(it->second);
        if (this->file.is_open()) {
            this->file.close();
        }
    }

    void cadastrarCliente(string  cpf, string nome);
    void removerCliente(string  cpf);
    bool Pesquisar(string cpf); 
    void imprimirRelatorio(char ordem);
};


#endif