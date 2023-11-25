#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;


class Cliente{
    private:
    string _nome;
    long long int _cpf;
    
    public:
    Cliente(string nome, long long int cpf) : _nome(nome), _cpf(cpf){}  
    string get_nome();
    long long int get_cpf();
};

#endif