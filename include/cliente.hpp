#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "pessoa.hpp"

#include <string>
#include <map>

class Cliente : public pessoa {

public:
    Cliente(const std::string& nome, const std::string& cpf);
    void locacaoMidia(std::map<std::string, std::pair<std::string, int>>& midias, const std::string& codigo);

private:
    void registrarLocacao(const std::string& codigo);
};

#endif