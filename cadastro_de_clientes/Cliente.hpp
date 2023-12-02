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
#include "../locacao_devolucao_midia/Gerenciador_de_arquivos.hpp"


class Cliente{
    private:
    string _nome;
    string _cpf;
    
    public:
    Cliente(string nome, string cpf) : _nome(nome), _cpf(cpf){}  
    string get_nome();
    string get_cpf();
    void locacaoMidia(vector<string>& codigos);
    void Devolver_Midia(vector<string> codes);
    double Calcular_Valor(string codigo, string rentDate);
    int diasCorridos(string aluguel);
};

#endif