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
#include "Gerenciador_de_arquivos.hpp"

using namespace std;
using namespace chrono;


Cliente::Cliente(const string& nome, long long cpf) : Pessoa(nome, cpf) {}

void Cliente::locacaoMidia(vector<string> codigos) {
  vector<vector<string>> locacoes = PegarLinhasDoArquivo("locacoes.txt");
  vector<string> locacao;
  string dataAtual;
  
    for (const auto& codigo : codigos) {
      //verifica e atualiza a disponível para locacao para a mídia específicada pelo codigo
      if(estoque("midias.txt", codigo, 0) == true){
        //se deu tudo certo no estoque, atualizar arquivo de locacoes
        dataAtual = getCurrentDateAsString();
        locacao = {"0", to_string(this->cpf), codigo, dataAtual.replace(0, 1, ""), "0"};
        locacoes.push_back(locacao);
      }
    }
    //cria um novo arquivo locacoes com as novas locacoes
    novoArquivo("locacoes.txt", locacoes);
}

void Cliente::Devolver_Midia(vector<string> codigos) {
  double valorTotal = 0, valor = 0;
  
  string dataAtual = getCurrentDateAsString();
  cout << dataAtual.replace(0, 1, "") << endl;
  
  vector<vector<string>> cliente = filtro("locacoes.txt", 1, to_string(this->cpf), true);

  //verifica se o cliente foi encontrado em alguma locação
  if (cliente[0][1] == to_string(this->cpf)) {

    //atualiza o status e a data de devoluçao do arq locacoes
    atualizarDataDeLocacao("locacoes.txt", codigos, cliente[0][1]);

    for (const auto& codigo : codigos) {
      
      //atualiza a quantidade disponível do arq mídias para a mídia específicada pelo codigo
      estoque("midias.txt", codigo, 1);

      valor = Calcular_Valor(codigo, cliente[0][3]);

      if (!valor) {
        return;
      }
      valorTotal += valor;
    }

    cout << "Valor total: R$ " << valorTotal << endl;
  }
  else {
    cerr << "CPF não encontrado";
  }
}

int Cliente::diasCorridos(string aluguel) {
  tm tm = {};
  string data = aluguel;
  stringstream ss(aluguel);
  ss >> get_time(&tm, "%Y-%m-%d");
  time_t tempo = mktime(&tm);
  system_clock::time_point momentoUsuario = system_clock::from_time_t(tempo);
  system_clock::time_point momentoAtual = system_clock::now();
  auto duracao = chrono::duration_cast<chrono::hours>(momentoAtual - momentoUsuario);
  return duracao.count() / 24;
}

//gera numero aleatorio entre 0 e 1
bool fitaEstaRebobinada() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(0, 1);
  return distrib(gen) == 1;
}

double Cliente::Calcular_Valor(string codigo, string rentDate) {
  double valor = 0;
  int dias = diasCorridos(rentDate);
  string type = verificarTipoMidia(codigo);

  if (type == "DL") {//DVD’s Lançamento
    valor = 20 * dias;
  }
  else if (type == "DE") {//DVD’s Estoque
    valor = 10 * dias;
  }
  else if (type == "DP") {//DVD’s Promoção
    valor = 10; //preço fixo
  }
  else if (type == "F") {//Fita
    bool estaRebobinada = fitaEstaRebobinada();
    valor = estaRebobinada ? 5 + 2 : 5; //preço fixo
  }
  else {
    cerr << "Código não encontrado";
  }

  return valor;
}
