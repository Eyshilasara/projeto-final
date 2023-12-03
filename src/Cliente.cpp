#include "../include/Cliente.hpp"

using namespace std::chrono;

std::string Cliente::get_nome(){
    return this->_nome;
}

std::string Cliente::get_cpf(){
    return this->_cpf;
}

void Cliente::locacaoMidia(std::vector<std::string>& codigos) {
  std::vector<std::vector<std::string>> locacoes = PegarLinhasDoArquivo("locacoes.txt");
  std::vector<std::string> locacao;
  std::string dataAtual;
  
    for (const auto& codigo : codigos) {
      //verifica e atualiza a disponível para locacao para a mídia específicada pelo codigo
      if(estoque("midias.txt", codigo, 0) == true){
        //se deu tudo certo no estoque, atualizar arquivo de locacoes
        dataAtual = getCurrentDateAsString();
        locacao = {"0", this->_cpf, codigo, dataAtual.replace(0, 0, ""), "0"};
        locacoes.push_back(locacao);
      }
    }
    //cria um novo arquivo locacoes com as novas locacoes
    novoArquivo("locacoes.txt", locacoes);
}

void Cliente::Devolver_Midia(std::vector<std::string> codigos) {
  double valorTotal = 0, valor = 0;
  
  std::string dataAtual;
  std::cout << dataAtual.replace(0, 0, "") << std::endl;
  
  std::vector<std::vector<std::string>> cliente = filtro("locacoes.txt", 1, this->_cpf, true);

  //verifica se o cliente foi encontrado em alguma locação
  if (cliente[0][1] == this->_cpf) {

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

    std::cout << "Valor total: R$ " << valorTotal << std::endl;
  }
  else {
    std::cerr << "CPF não encontrado";
  }
}

int Cliente::diasCorridos(std::string aluguel) {
  tm tm = {};
  std::string data = aluguel;
  std::stringstream ss(aluguel);
  ss >> std::get_time(&tm, "%Y-%m-%d");
  time_t tempo = mktime(&tm);
  system_clock::time_point momentoUsuario = system_clock::from_time_t(tempo);
  system_clock::time_point momentoAtual = system_clock::now();
  auto duracao = std::chrono::duration_cast<std::chrono::hours>(momentoAtual - momentoUsuario);
  return duracao.count() / 24;
}

//gera numero aleatorio entre 0 e 1
bool fitaEstaRebobinada() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 1);
  return distrib(gen) == 1;
}

double Cliente::Calcular_Valor(std::string codigo, std::string rentDate) {
  double valor = 0;
  int dias = diasCorridos(rentDate);
  std::string type = verificarTipoMidia(codigo);

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
    std::cerr << "Código não encontrado";
  }

  return valor;
}