#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <random>


class Cliente{
    private:
    std::string _nome;
    std::string _cpf;
    
    public:
    Cliente(std::string nome, std::string cpf) : _nome(nome), _cpf(cpf){}  
    std::string get_nome();
    std::string get_cpf();
};

#endif