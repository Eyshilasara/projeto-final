#include "Cliente.hpp"

string Cliente::get_nome(){
    return this->_nome;
}

string Cliente::get_cpf(){
    return this->_cpf;
}

void Cliente::locacaoMidia(std::map<std::string, std::pair<std::string, int>>& midias, const std::vector<std::string>& codigos) {
    // Obtém a data atual
    time_t agora = time(0);
    tm* ltm = localtime(&agora);
    std::string dataLocacao = std::to_string(1900 + ltm->tm_year) + '-' + std::to_string(1 + ltm->tm_mon) + '-' + std::to_string(ltm->tm_mday);
    // Abre o arquivo 
    std::ofstream arquivo("locacoes.txt", std::ios::app);
    // Itera sobre os códigos de mídias
    for (const std::string& codigo : codigos) {
        auto it = midias.find(codigo);
        // Verifica se a mídia existe e tem quantidade disponível
        if (it != midias.end() && it->second.second > 0) {
            // Atualiza a quantidade disponível
            it->second.second--;
            arquivo << "Status: 0, " << "Data: " << dataLocacao << ',' << "CPF do cliente: " << this->_cpf << ',' << "Código da mídia: " << codigo << std::endl;
            // Escreve as informações de locação diretamente no arquivo
            arquivo << "0" << ' ' << get_cpf() << ' ' << codigo << ' ' << dataLocacao << ' ' << "*" << std::endl;
        } else {
            // Imprime uma mensagem se a mídia não estiver disponível
            std::cout << "Não há quantidade disponível de " << it->second.first << " para locação" << std::endl;
        }
    }
    // Fecha o arquivo após o loop
    arquivo.close();
}
