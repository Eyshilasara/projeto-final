#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "pessoa.hpp"
#include <map>
#include <vector>
#include <string>

class Cliente{

    private:
    std::string _nome;
    long long int _cpf;

    public:
    Cliente(std::string nome, long long int cpf) : _nome(nome), _cpf(cpf){}  
    std::string get_nome();
    long long int get_cpf();
    void locacaoMidia(std::map<std::string, std::pair<std::string, int>>& midias, const std::vector<std::string>& codigos);

};

#endif
