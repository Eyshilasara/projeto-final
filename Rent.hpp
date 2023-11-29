#ifndef RENT_HPP
#define RENT_HPP
#include <string>
#include <vector>
#include "Rent.hpp"

using namespace std;

struct Rent {
	int status = 0;
	long long cpf;
	string codigo;
	string data_locacao;
	string data_devolucao;
};

vector<Rent> getRents();

#endif