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
#include "Gerenciador_de_arquivos.hpp"


class Cliente{
    private:
    std::string _nome;
    std::string _cpf;
    
    public:
    Cliente(std::string nome, std::string cpf) : _nome(nome), _cpf(cpf){}  
    std::string get_nome();
    std::string get_cpf();
    void locacaoMidia(std::vector<std::string>& codigos);
    void Devolver_Midia(std::vector<std::string> codes);
    double Calcular_Valor(std::string codigo, std::string rentDate);
    int diasCorridos(std::string aluguel);
};

#endif