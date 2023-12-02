#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


class Cliente{
    private:
    string _nome;
    string _cpf;
    
    public:
    Cliente(string nome, string cpf) : _nome(nome), _cpf(cpf){}  
    string get_nome();
    string get_cpf();
    void locacaoMidia(std::map<std::string, std::pair<std::string, int>>& midias, const std::vector<std::string>& codigos);
};

#endif