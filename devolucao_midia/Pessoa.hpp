#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa{
  protected:
    std::string nome;
    long long cpf;
  
  public:
    Pessoa(std::string nome, long long cpf);

};

#endif
