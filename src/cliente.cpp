#include "cliente.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>

void Cliente::locacaoMidia(std::map<std::string, std::pair<std::string, int>>& midias, const std::vector<std::string>& codigos) {
    std::ofstream arquivo;
    arquivo.open("locacoes.txt", std::ios::app);

    time_t agora = time(0);
    tm* ltm = localtime(&agora);
    std::string dataLocacao = std::to_string(1900 + ltm->tm_year) + '-' + std::to_string(1 + ltm->tm_mon) + '-' + std::to_string(ltm->tm_mday);

    for (const std::string& codigo : codigos) {
        auto it = midias.find(codigo);

        if (it != midias.end() && it->second.second > 0) {
            it->second.second--;
            arquivo << "Status: 0, " << "Data: " << dataLocacao << ',' << "CPF do cliente: " << this->cpf << ',' << "Código da mídia: " << codigo << std::endl;
        } else {
            std::cout << "Não há quantidade disponível de " << it->second.first << " para locação" << std::endl;
        }
    }

    arquivo.close();
}
