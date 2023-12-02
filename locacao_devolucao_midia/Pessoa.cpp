#include <string>
#include "Pessoa.hpp"

Pessoa::Pessoa(std::string nome, long long cpf){
  this->nome = nome;
  this->cpf = cpf;
}


bool Pessoa::isValidCPF(std::string cpf) {
    unsigned lenght = 0;
    int ver1 = 0, ver2 = 0;
    char aux;

    while (cpf[lenght]) {
        lenght++;
    }

    if (lenght != 11)
        return false;

    for (int j = 0; j < 9; j++) {
        aux = cpf[j];
        ver1 += atoi(&aux) * (j + 1);
    }

    ver1 %= 11;


    for (int j = 0; j < 9; j++) {
        aux = cpf[j];
        ver2 += atoi(&aux) * j;
    }

    ver2 += ver1 * 9;
    ver2 %= 11;

    aux = cpf[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(lenght) - 2];
    if (atoi(&aux) == ver1) {
        aux = cpf[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(lenght) - 1];
        if (atoi(&aux) == ver2)
            return true;
    }
    return false;
}

