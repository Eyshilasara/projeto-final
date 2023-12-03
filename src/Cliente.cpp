#include "..\include\Cliente.hpp"

using namespace std::chrono;

std::string Cliente::get_nome(){
    return this->_nome;
}

std::string Cliente::get_cpf(){
    return this->_cpf;
}
