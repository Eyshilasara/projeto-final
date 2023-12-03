#ifndef GERENCIADOR_DE_ARQUIVOS_HPP
#define GERENCIADOR_DE_ARQUIVOS_HPP
#include <string>
#include <vector>

void novoArquivo(std::string nomeArquivo, std::vector<std::vector<std::string>> linhas);
std::string getCurrentDateAsString();
std::vector<std::string> converterLinhaParaVetor(std::string);
std::vector<std::vector<std::string>> PegarLinhasDoArquivo(std::string);
void relatorio(int, std::string);
void atualizarDataDeLocacao(const std::string&, std::vector<std::string>, std::string);
std::string verificarTipoMidia(std::string);
bool estoque(const std::string&, std::string, int);
std::vector<std::vector<std::string>> filtro(std::string fileName, int columnNumber, std::string arg, bool isSingleRow);
#endif // !FILE_REPO_HPP
