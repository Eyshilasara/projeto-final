#include <fstream>
#include <iostream>

void escreverNoArquivo(std::ofstream& arquivo, int _codigo, const std::string& _tipo, const std::string& _titulo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, const std::string& _categoria, const std::string _grupo = 0, int _notaCritica = 0, const std::string& _cantorBanda = 0, int _numeroMusicas = 0, const std::string _plataforma = 0, bool _rebobinado = 0) {
    arquivo << _codigo << "\t" << _tipo << "\t" <<  _grupo << "\t" << _categoria << "\t" << _titulo << "\t" << _genero << "\t" << _notaCritica << "\t" <<  _quantidadeTotal << "\t" << _quantidadeDisponivel << "\t" <<  _numeroMusicas << "\t" << _cantorBanda << "\t" << _plataforma << "\t" << _rebobinado << std::endl;
}


int main() {
    std::ofstream arquivo("midias.txt", std::ios::app);

    if (!arquivo) {
        std::cout << "Erro ao abrir o arquivo para escrita.\n";
        return 1;
    }

    escreverNoArquivo(arquivo, 1, "Filme", "Título do Filme 1", "Gênero do Filme 1", 0, 0, "", "", 0, "", false);
    escreverNoArquivo(arquivo, 2, "Livro", "Título do Livro 1", "Gênero do Livro 1", 0, 0, "", "", 0, "", false);
    escreverNoArquivo(arquivo, 3, "Fita", "Título da Fita 1", "Gênero da Fita 1", 0, 0, "", "", 0, "", false);

    arquivo.close();

    std::cout << "Arquivo gerado com sucesso.\n";

    return 0;
}

