#ifndef GERENCIADOR_DE_ARQUIVOS_HPP
#define GERENCIADOR_DE_ARQUIVOS_HPP
#include <string>
#include <vector>

using namespace std;

bool novoArquivo(string nomeArquivo, vector<vector<string>> linhas);
string getCurrentDateAsString();
vector<string> converterLinhaParaVetor(string);
vector<vector<string>> PegarLinhasDoArquivo(string, bool);
void relatorio(int, string);
bool atualizarDataDeLocacao(const string&, vector<string>, string, vector<bool>);
string verificarTipoMidia(string);
bool estoque(const string&, string, int);
vector<vector<string>> filtro(string fileName, int columnNumber, string arg, bool isSingleRow);
#endif // !FILE_REPO_HPP
