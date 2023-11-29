#include "Cliente.hpp"
#include "Pessoa.hpp"

#include "File_Manager.hpp"
#include "Rent.hpp"

#include <chrono>
#include <ctime>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;

Cliente::Cliente(const string &nome, long long cpf) : Pessoa(nome, cpf) {}

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

  vector<Rent> rents = getRents();

  Rent currentCustomer = find(rents, cpf);

  if (currentCustomer.cpf != 0) {
    for (const auto &code : codes) {
      value = Calcular_Valor(code, currentCustomer.data_locacao);
      if (!value) {
        return;
      }
      total_value += value;
    }
    cout << "Valor total: R$" << total_value << endl;
  } else {
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

  chrono::duration_cast<chrono::duration<int>>(currentTimePoint -
                                               userTimePoint);

  auto duration = chrono::duration_cast<chrono::hours>(currentTimePoint - userTimePoint);
  cout << duration.count();
  
  return duration.count() / 24;
}

bool isRewindedTape() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(0, 1);
  return distrib(gen) == 1;
}

int Cliente::Calcular_Valor(string codigo, string rentDate) {
  int valor = 0, elapsed_days = getRentElapsedDays(rentDate);

  if (codigo.substr(0, 2) == "DL") { // DVD’s Lançamento
    valor = 20 * elapsed_days;
    cout << "Dias: " << elapsed_days << endl;
  } else if (codigo.substr(0, 2) == "DE") { // DVD’s Estoque
    valor = 10 * elapsed_days;
  } else if (codigo.substr(0, 2) == "DP") { // DVD’s Promoção
    valor = 10;                             // preço fixo
  } else if (codigo.at(0) == 'F') {         // Fita
    bool isRewinded = isRewindedTape();
    valor = isRewinded ? 5 + 2 : 5; // preço fixo
  } else {
    cerr << "Code not found";
  }

  return valor;
}