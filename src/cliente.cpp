#include "cliente.hpp"
#include <iostream>
#include <fstream>
#include <ctime>

Cliente::Cliente(const std::string& nome, const std::string& cpf) {
    this->nome = nome;
    this->cpf = cpf;
}

void Cliente::locacaoMidia(std::map<std::string, std::pair<std::string, int>>& midias, const std::string& codigo) {
    auto it = midias.find(codigo);
    if (it != midias.end() && it->second.second > 0) {
        it->second.second--;
        registrarLocacao(codigo);
    } else {
        std::cout << "Não há quantidade disponível de " << it->second.first << " para locação" << std::endl;
    }
}

void Cliente::registrarLocacao(const std::string& codigo) {
    std::ofstream arquivo;
    arquivo.open("locacoes.txt", std::ios::app);
    time_t agora = time(0);
    tm* ltm = localtime(&agora);
    arquivo << "0," << 1900 + ltm->tm_year << '-' << 1 + ltm->tm_mon << '-' << ltm->tm_mday << ',' << cpf << ',' << codigo << std::endl;
    arquivo.close();
}