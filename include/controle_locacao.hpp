#ifndef CONTROLE_LOCACAO_HPP
#define CONTROLE_LOCACAO_HPP

#include <string>
#include <vector>

using namespace std; 

void locacaoMidia(vector<string> codigos, string cpf);
void Devolver_Midia(vector<string> codigos, string cpf);
double Calcular_Valor(string codigo, string rentDate);
int diasCorridos(string aluguel);

#endif