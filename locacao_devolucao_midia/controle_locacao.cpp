#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include "controle_locacao.hpp"
#include "Gerenciador_de_arquivos.hpp"

using namespace std;
using namespace chrono;

void locacaoMidia(vector<string> codigos, string cpf) {
  vector<vector<string>> locacoes = PegarLinhasDoArquivo("locacoes.txt", false);
  vector<string> locacao;
  string dataAtual;
  
    for (const auto& codigo : codigos) {
      //verifica e atualiza a disponível para locacao para a mídia específicada pelo codigo
      if(estoque("midias.txt", codigo, 0)){
        //se deu tudo certo no estoque, atualizar arquivo de locacoes
        dataAtual = getCurrentDateAsString();
        locacao = {"0", cpf, codigo, dataAtual.replace(0, 1, ""), "0"};
        locacoes.push_back(locacao);
      }
    }
    //cria um novo arquivo locacoes com as novas locacoes
    novoArquivo("locacoes.txt", locacoes);
}

void Devolver_Midia(vector<string> codigos, string cpf) {
  double valorTotal = 0, valor = 0;
  
  vector<vector<string>> cliente = filtro("locacoes.txt", 1, cpf, true);
  vector<bool> estoquesValidos;

  //verifica se o cliente foi encontrado em alguma locação
  if (cliente[0][1] == cpf) {

    for (const auto& codigo : codigos) {
      
      //atualiza a quantidade disponível do arq mídias para a mídia específicada pelo codigo
      if(estoque("midias.txt", codigo, 1)){
          estoquesValidos.push_back(true);
        
        valor = Calcular_Valor(codigo, cliente[0][3]);
        
        if (!valor) {//valor = 0
          return;
        }
        
        valorTotal += valor;
      }else{
          estoquesValidos.push_back(false);
      }
    }

    //atualiza o status e a data de devoluçao do arq locacoes
    atualizarDataDeLocacao("locacoes.txt", codigos, cliente[0][1], estoquesValidos);

    cout << "Valor total: R$ " << valorTotal << endl;
  }
  else {
    cerr << "CPF não encontrado";
  }
}

int diasCorridos(string aluguel) {
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

double Calcular_Valor(string codigo, string dataLocacao) {
  double valor = 0;
  int dias = diasCorridos(dataLocacao);
  string tipo = verificarTipoMidia(codigo);

  string dataDevolucao = getCurrentDateAsString();

  if(dataDevolucao.replace(0, 1, "") == dataLocacao){
    if (tipo == "DL") {//DVD’s Lançamento
      valor = 20 * 0.6;
    }
    else if (tipo == "DE") {//DVD’s Estoque
      valor = 10 * 0.6;
    }
  }
    
  else{
    if (tipo == "DL") {//DVD’s Lançamento
      valor = 20 * dias;
    }
    else if (tipo == "DE") {//DVD’s Estoque

      valor = 10 * dias;
    }
    else if (tipo == "DP") {//DVD’s Promoção
      valor = 10; //preço fixo
    }
    else if (tipo == "F") {//Fita
      bool estaRebobinada = fitaEstaRebobinada();
      valor = estaRebobinada ? 5 + 2 : 5; //preço fixo
    }
    else {
      cerr << "Código não encontrado";
    }
  }

  return valor;
}
