#include <string>
#include <vector>
#include <iostream>
#include "Gerenciador_de_arquivos.hpp"
#include "Cliente.hpp"


int main() {

	std::string nome = "Leticia";
	long long cpf = 14554163613LL;
	std::vector<std::string> codigos;
	std::string codigo;
  

    cout << "Digite o codigo da midia que será alugada (para encerrar digite \"sair\"): ";

	while (cin >> codigo && codigo != "sair") {
	 codigos.push_back(codigo);
	}
	Cliente cliente(nome, cpf);
	cliente.locacaoMidia(codigos);
  
    codigos.clear();
	cout << "Digite o codigo da midia que será devolvida (para encerrar digite \"sair\"): ";
  
	while (cin >> codigo && codigo != "sair") {
	 codigos.push_back(codigo);
	}
  
	cliente.Devolver_Midia(codigos);
  
	return 0;
}