#ifndef ARQUIVOCLIENTES_H
#define ARQUIVOCLIENTES_H

#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <sstream> 
#include <iomanip>  // ws
#include <fstream>
#include <stdexcept>
#include "Cliente.hpp"

using namespace std;

class BancoClientes{
    public:
    fstream file;                  // arquivo com as informações do clientes, é mantido apos o fim do main
    map<string ,Cliente*> banco;   // mapa com os clientes e os nomes, é perdido
  
    time_t now = time(0);          // Define a data que começou uma execucao
    char* dt = ctime(&now);

    public:
    BancoClientes() : file("Clientes.txt", std::ios::in | std::ios::out| std::ios::app) {
        if (!file) {
            cerr << "Erro ao abrir o arquivo: Clientes.txt" << std::endl;
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