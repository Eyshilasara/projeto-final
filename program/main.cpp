#include "cliente.hpp"
#include "midia.hpp"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

  // Cria um mapa de mídias com código, nome e quantidade
  std::map<std::string, std::pair<std::string, int>> midias = {
      {"DL001", {"Filme A", 5}},
      {"DP002", {"Filme B", 2}},
      // Adicione mais mídias conforme necessário
  };

  // Cria um vetor para armazenar os códigos das mídias a serem locadas
  std::vector<std::string> codigos;

  // Criando um cliente
   Cliente cliente("Joao", 12345678901LL);

  // Loop para receber códigos de mídias
  std::string codigo;
  std::cout << "Digite os códigos das mídias para locação (digite 'sair' para finalizar):" << std::endl;
  while (std::cin >> codigo && codigo != "sair") {
      // Verifica se o código existe no mapa de mídias
      if (midias.find(codigo) != midias.end()) {
          // Adiciona o código à lista de locação
          codigos.push_back(codigo);
      } else {
          std::cout << "Código de mídia não encontrado: " << codigo << std::endl;
      }
  }

  // Chama a função locacaoMidia com os códigos recebidos
  cliente.locacaoMidia(midias, codigos);

  // Verifica o estado atual do mapa de mídias
  for (const auto& par : midias) {
      std::cout << "Mídia: " << par.second.first << " - Quantidade: " << par.second.second << std::endl;
  }

  return 0;

}