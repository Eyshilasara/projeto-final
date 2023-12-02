#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Gerenciador_de_arquivos.hpp"
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

void novoArquivo(string nomeArquivo, vector<vector<string>> linhas){
  ofstream arquivo(nomeArquivo);
  if (!arquivo.is_open()) {
    cerr << "Erro ao escrever no arquivo" << endl;
    return;
  }

  string registro = "";
  for (const vector<string>& linha : linhas) {
    for(const string& coluna : linha){
      //converter vetor de strings em uma unica string
      registro = registro + coluna + " ";
    }

    //escrever no arq e remover espaço da ultima coluna
    arquivo << registro.substr(0, registro.size() - 1) << endl;
  }

  arquivo.close();
}

std::string getCurrentDateAsString() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&currentTime), " %Y-%m-%d");

    return oss.str();
}

//Altera o arquivo de locações, nas colunas de status e data de devolução nas linhas especificadas pelos codigos (args)
void atualizarDataDeLocacao(const string& nomeArq, vector<string> codigos, string cpf) {
  
	ifstream arquivo(nomeArq);
	if (!arquivo.is_open()) {
		cerr << "Erro ao abrir o arquivo." << endl;
		return;
	}

	string linha;
	bool foiEncontrado = false;
	vector<string> linhas;

	while (getline(arquivo, linha)) {
		for (string codigo : codigos) {//para cada codigo em codigos (arg em args)
      
	 //verificar se o cpf da linha corresponde ao cpf do cliente que está fazendo a locada/devoulvida && o codigo da linha corresponde ao codigo da midia que sera locada/devoulvida
			if (linha.find(" " + cpf + " ") != string::npos && linha.find(" " + codigo + " ") != string::npos && isblank(linha[linha.length() - 2])) {
				foiEncontrado = true;

				//atualiza o status
				linha = linha.replace(0, 1, "1");

				string termoSubstituido = getCurrentDateAsString();

				//atualiza a data de devolução de 0 para a data atual
				linha = linha.replace(linha.length() - 2, 10, termoSubstituido);
			}
		}
		linhas.push_back(linha);
	}

	if (!foiEncontrado) {
		cout << "A consulta não gerou resultados." << endl;
	}

	arquivo.close();

  //============================
	ofstream arquivoSaida(nomeArq);
	if (!arquivoSaida.is_open()) {
		cerr << "Erro ao escrever no arquivo" << endl;
		return;
	}
	for (const string& linha : linhas) {//reescreve o arquivo com as linhas atualizadas
		arquivoSaida << linha << '\n';
	}

	arquivoSaida.close();
}

string removeDoubleQuotes(string textoPuro, int i) {
	string texto = "";
  
	while (textoPuro[i] != '\"') {
		texto += textoPuro[i];
		i++;
		if (textoPuro[i] == '\"') {
			break;
		}
	}
	return texto;
}

// Converte a linha do arquivo txt em um vetor
vector<string> converterLinhaParaVetor(string linha) {
	vector<string> resultado;
	string texto;

	for (int i = 0; i < linha.length(); i++) {
		// isspace verifica se aquele char é um espaço em branco.
		if (!isspace(linha[i])) {
			if (linha[i] == '\"') {
				i++;
				texto = removeDoubleQuotes(linha, i);
				i = i + texto.length();
				continue;
			}
			texto += linha[i];
		}
		else {
			resultado.push_back(texto);
			texto.clear();
		}
	}

	if (!texto.empty()) {
		resultado.push_back(texto);
	}

	return resultado;
}

// Pega todas as linhas do arquivo e o transforma num vetor de vetores. O método
// que o chama que deve fazer a implementação do struct correspondente
vector<vector<string>> PegarLinhasDoArquivo(string nomeArquivo) {
	//ofstream arquivo(nomeArquivo);
	ifstream arquivo(nomeArquivo);
	vector<vector<string>> linhas;


	// isspace verifica se o arquivo está aberto.
	if (arquivo.is_open()) {
		string dadosLinha;

		while (getline(arquivo, dadosLinha)) {
			istringstream dados(dadosLinha);
			vector<string> linha = converterLinhaParaVetor(dadosLinha);
			linhas.push_back(linha);
		}

		arquivo.close();
		return linhas;
	}

	else {
		cerr << "Erro ao abrir o arquivo." << nomeArquivo << std::endl;
		return linhas;
	}
}

//busca na coluna numeroColuna do arquivo especificado a(s) linha(s) em que o(s) registro(s) é(são) igual(is) a arg e retorna a(s) linha(s) em formato de vetor
vector<vector<string>> filtro(string nomeArquivo, int numeroColuna, string arg, bool retornarUmaLinha) {
  
	vector<vector<string>> linhas = PegarLinhasDoArquivo(nomeArquivo);
	vector<vector<string>> linhasFiltradas;

	for (vector<string> linha : linhas) {
		if (linha[numeroColuna] == arg) {
			if (retornarUmaLinha) {
				linhasFiltradas.push_back(linha);
				return linhasFiltradas;
			}
			linhasFiltradas.push_back(linha);
		}
	}
	return linhasFiltradas;
}

//TROCAR O NOME DA FUNÇÃO E DAS SUAS VARIAVEIS PARA QUE FIQUE CLARO QUE ELA É RESTRITA AO ARQ LOC
void relatorio(int relatorio = 0, string arg = "") {
	vector<vector<string>> linhas = PegarLinhasDoArquivo("locacoes.txt");
	vector<vector<string>> linhasFiltradas;
	switch (relatorio) {

	case 0: //imprimir TODAS as locações (imprimir todo o arquivo)
		linhasFiltradas = linhas;
		break;
	case 1: // impressão por cliente: funcionário informa cpf do cliente e são
			// impressos apenas as linhas contendo as suas locações
		linhasFiltradas = filtro("locacoes.txt", 1, arg, false);
		break;
	case 2: // imprimir apenas as locações em aberto ou concluidas (depende do arg informado)
		linhasFiltradas = filtro("locacoes.txt", 0, arg, false);
		break;
	}
	for (auto& linha : linhasFiltradas) {
		string dataAluguel = linha[3].substr(8, 2) + "/" + linha[3].substr(5, 2) + "/" + linha[3].substr(0, 4);
		string dataRetorno = linha[4].length() > 1 ? linha[4].substr(8, 2) + "/" + linha[4].substr(5, 2) + "/" + linha[4].substr(0, 4) : linha[4];

		cout << "Status: " << linha[0] << " CPF: " << linha[1] << " Código: " << linha[2]
			<< " Data de Locação: " << dataAluguel
			<< " Data de Devolução: " << dataRetorno << endl;
	}
}

//retorna o tipo de mídia de acordo com o codigo informado
string verificarTipoMidia(string codigoMidia) {
	vector<vector<string>> midia = filtro("midias.txt", 0, codigoMidia, true);

	//verifica se é ou não uma fita
	//VERIFICAR O INDICE DA COLUNA ONDE FICARÁ ARMAZENADO "REBOBINADO" (supor: 5)
	if (midia[0][5] == "0" || midia[0][5] == "1") {
		return "F";
	}

	//verifica o tipo do DVD
	//VERIFICAR O INDICE DA COLUNA ONDE FICARÁ ARMAZENADO "TIPO" (supor: 6)
	else if (midia[0][6] == "Lancamento") {
		return "DL";
	}
	else if (midia[0][6] == "Estoque") {
		return "DE";
	}
	else if (midia[0][6] == "Promocao") {
		return "DP";
	}

	else {
		return "Not Found";
	}
}

int numDigitos(int numero) {
	int digitos = 0;
	if (numero < 0) digitos = 1;
	while (numero) {
		numero /= 10;
		digitos++;
	}
	return digitos;
}

//Altera o arquivo de mídias na coluna de quantidade disponível
bool estoque(const string& nomeArquivo, string codigo, int status) {
  
	ifstream arquivo(nomeArquivo);
	if (!arquivo.is_open()) {
		cerr << "Erro ao abrir o arquivo." << endl;
		return false;
	}

	vector<vector<string>> midia = filtro("midias.txt", 0, codigo, true);
  vector<vector<string>> midias = PegarLinhasDoArquivo("midias.txt");
  
	int quantidadeDisponivel = stoi(midia[0][1]);
	int tamQtd_disponivel = numDigitos(quantidadeDisponivel);
  int tamCodigo = numDigitos(stoi(codigo));
    
	string linha;
	bool foiEncontrado = false;
	vector<string> linhas;

  bool alterou = false;
  
  while (getline(arquivo, linha)) {    
		if (linha.find(codigo + " ") != string::npos) {

			foiEncontrado = true;

      if(status == 1){//se for devolucao
        //VERIFICAR O INDICE DA COLUNA ONDE FICARÁ ARMAZENADO "QTD_DISPONIVEL" (supor: 1)
        //VERIFICAR O TAMANHO DO CODIGO, SOMAR 1 E PASSAR COMO PRIMEIRO PARÂMETRO NO REPLACE
        linha = linha.replace(tamCodigo+1, tamQtd_disponivel, to_string((quantidadeDisponivel + 1)));
        alterou = true;
      }
      
      else {//se for locacao
        //verificar se há qtd disponivel
        if(quantidadeDisponivel > 0){
          //VERIFICAR O INDICE DA COLUNA ONDE FICARÁ ARMAZENADO "QTD_DISPONIVEL" (supor: 1)
          //VERIFICAR O TAMANHO DO CODIGO, SOMAR 1 E PASSAR COMO PRIMEIRO PARÂMETRO NO REPLACE
          linha = linha.replace(tamCodigo+1, tamQtd_disponivel, to_string((quantidadeDisponivel - 1)));
          alterou = true;
        } else {
          cout << "Não há quantidade disponível para locação" << endl;
        }
      }
      
		}

		linhas.push_back(linha);
	}

	if (!foiEncontrado) {
		cout << "A consulta não gerou resultados." << endl;
	}

	arquivo.close();

  //=================================
	ofstream arquivoSaida(nomeArquivo);
	if (!arquivoSaida.is_open()) {
		cerr << "Erro ao escrever no arquivo" << endl;
		return false;
	}
	for (const string& linha : linhas) {//reescreve o arquivo com as linhas atualizadas
		arquivoSaida << linha << '\n';
	}

	arquivoSaida.close();

  return alterou;
}