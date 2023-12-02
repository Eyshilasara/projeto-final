#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Pessoa.hpp"

#include <string>
#include <vector>
using namespace std; 
class Cliente : public Pessoa {
  public:
      Cliente(const string& nome, long long cpf);
      void locacaoMidia(vector<string> codigos);
      void Devolver_Midia(vector<string> codigos);
      double Calcular_Valor(string codigo, string rentDate);
      int diasCorridos(string aluguel);
};

#endif
