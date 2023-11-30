#include "Cliente.hpp"
#include "Pessoa.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include "File_Manager.hpp"
#include "Rent.hpp"
#include "File_Manager.hpp"
using namespace std;
using namespace chrono;


Cliente::Cliente(const string& nome, long long cpf) : Pessoa(nome, cpf) {}


Rent find(vector<Rent> rentList, long long cpf) {
	size_t rentalsCount = rentList.size();
	for (int i = 0; i < rentalsCount; i++) {
		if (rentList[i].cpf == cpf) {
			return rentList[i];
		}
	}

	return Rent{};

}

void Cliente::Devolver_Midia(vector<string> codes) {
	long long total_value = 0, value = 0;
	vector<Rent>  rents = getRents();
	Rent currentCustomer = find(rents, cpf);
	if (currentCustomer.cpf) {
		changeRentRowData("locacoes.txt", codes);
		for (const auto& code : codes) {
			value = Calcular_Valor(code, currentCustomer.data_locacao);
			if (!value) {
				return;
			}
			total_value += value;
		}

		cout << "Valor total: " << total_value << endl;
		report(1,to_string(cpf));
	}
	else {
		cerr << "CPF não encontrado";
	}


}

int Cliente::getRentElapsedDays(string rent) {
	tm tm = {};
	string date = rent;
	stringstream ss(rent);
	ss >> get_time(&tm, "%Y-%m-%d");
	time_t t = mktime(&tm);
	system_clock::time_point userTimePoint = system_clock::from_time_t(t);
	system_clock::time_point currentTimePoint = system_clock::now();
	chrono::duration_cast<chrono::duration<int>>(currentTimePoint - userTimePoint);
	auto duration = chrono::duration_cast<chrono::hours>(currentTimePoint - userTimePoint);
	return duration.count() / 24;

}

bool isRewindedTape() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(0, 1);
	return distrib(gen) == 1;
}


int Cliente::Calcular_Valor(string codigo, string rentDate) {
	int valor = 0, elapsedDays = getRentElapsedDays(rentDate);

	if (codigo.substr(0, 2) == "DL") {//DVD’s Lançamento
		valor = 20 * elapsedDays;
	}
	else if (codigo.substr(0, 2) == "DE") {//DVD’s Estoque
		valor = 10 * elapsedDays;
	}
	else if (codigo.substr(0, 2) == "DP") {//DVD’s Promoção
		valor = 10; //preço fixo
	}
	else if (codigo.at(0) == 'F') {//Fita
		bool isRewinded = isRewindedTape();
		valor = isRewinded ? 5 + 2 : 5; //preço fixo
	}
	else {
		cerr << "Code not found";
	}

	return valor;
}
