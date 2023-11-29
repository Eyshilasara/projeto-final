#include <string>
#include <vector>
#include <iostream>
#include "Rent.hpp"
#include "Cliente.hpp"

using namespace std;

int main() {
  
	string nome = "Leticia";
	long long cpf = 14554163613;
	vector<string> codigos;
  
	cout << "Enter the codes (enter 'exit' to finish): ";

	string code;
	while (cin >> code && code != "exit") {
		//Inserir tratamento de erro caso codigo esteja errado
		codigos.push_back(code);
	}

	Cliente cliente(nome, cpf);
	cliente.Devolver_Midia(codigos);

	return 0;
}
