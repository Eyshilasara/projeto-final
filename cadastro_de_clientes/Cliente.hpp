#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;


class Cliente{
    private:
    string _nome;
    string _cpf;
    
    public:
    Cliente(string nome, string cpf) : _nome(nome), _cpf(cpf){}  
    string get_nome();
    string get_cpf();
};

#endif