#ifndef GERENCIADOR_DE_ARQUIVOS_HPP
#define GERENCIADOR_DE_ARQUIVOS_HPP
#include <string>
#include <vector>

using namespace std;

void novoArquivo(string nomeArquivo, vector<vector<string>> linhas);
string getCurrentDateAsString();
vector<string> converterLinhaParaVetor(string);
vector<vector<string>> PegarLinhasDoArquivo(string);
void relatorio(int, string);
void atualizarDataDeLocacao(const string&, vector<string>, string);
string verificarTipoMidia(string);
bool estoque(const string&, string, int);
vector<vector<string>> filtro(string fileName, int columnNumber, string arg, bool isSingleRow);
#endif // !FILE_REPO_HPP
