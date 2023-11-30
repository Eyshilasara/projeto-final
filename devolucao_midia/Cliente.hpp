#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Pessoa.hpp"

#include <string>
#include <vector>
using namespace std; 
class Cliente : public Pessoa {
  public:
      Cliente(const string& nome, long long cpf);
      void Devolver_Midia(vector<string> codes);
      int Calcular_Valor(string codigo, string rentDate);
      int getRentElapsedDays(string rentDate);

};

#endif
