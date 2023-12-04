#include "..\include\ArquivoClientes.hpp"

bool BancoClientes::Pesquisar(std::string cpf){
    /*!
    * Função que procura pelo cpf no arquivo de cadastro de clientes. Se encontra o cpf retorna 1.
    */
    std::map<std::string, std::string> configuration; 
    std::string line;
    std::fstream file("Clientes.txt",std::ios::in | std::ios::out| std::ios::app);
    
    while(getline(file, line)){ //!< Itera sobre o arquivo de clientes.
        std::string chaveCpf;
        std::string valorNome;
        std::stringstream ss(line);       //!< Transforma a linha em um stream.
        getline(ss, chaveCpf, ' ');  //!< Lê a linha ate chega em ' '.
        ss >> std::ws;                    //!< Ignora espaços em branco.
        getline(ss, valorNome);      //!< Lê o restante da linha.
        
        configuration[chaveCpf] = valorNome;
    }
    file.close();
    if(configuration[cpf] == ""){ //!< Verifica se o cpf pedido se encontra no map com os cpf's e nomes.
        return false;
    }
    else 
        return true;
        

}

void BancoClientes::cadastrarCliente(std::string cpf, std::string nome){
    /*!
    * Função que preenche o arquivo de cadastro de clientes.
    */
    time_t agora = time(0);
    tm* ltm = localtime(&agora);
    std::string dataCadastro = std::to_string(1900 + ltm->tm_year) + '-' + std::to_string(1 + ltm->tm_mon) + '-' + std::to_string(ltm->tm_mday);
    
    if(this->isValidCPF(cpf)){
        std::fstream file("Clientes.txt", std::ios::in | std::ios::out| std::ios::app);

        if(this->Pesquisar(cpf))
            throw std::invalid_argument("CPF repetido.");

        else{
            Cliente *cliente = new Cliente(nome, cpf);
            this->banco.insert(std::pair<std::string ,Cliente*>(cpf, cliente));
            if (file.is_open()) {
                file << cpf << " " << nome << " " << dataCadastro<< std::endl;
            }
            else 
                std::cerr << "Arquivo nao esta aberto." << std::endl;
            std::cout << "Cliente " << cpf  << " cadastrado com sucesso." << std::endl;
        }

        file.close();
    }

    else{
        throw std::invalid_argument("CPF Invalido.");
    }
}

void BancoClientes::removerCliente(std::string cpf){
    /*!
    * Função que remove um cliente a partir do cpf no arquivo de cadastro de clientes.
    */
    std::ofstream temp("temp.txt"); //!< Arquivo temporario para auxiliar.
    std::string line;
    std::ifstream file("Clientes.txt");

    if(this->Pesquisar(cpf)){
        while(getline(file, line)){ 
            std::string _cpf;
            std::string nome;
            std::string data;
            std::stringstream ss(line);     
            getline(ss, _cpf, ' ');  
            ss >> std::ws;                    
            getline(ss, nome, ' ');      
            ss >> std::ws;                    
            getline(ss, data);  

            if(_cpf!=cpf){
                
                temp << _cpf << " " << nome << " " << data << std::endl;
                
            }
        }
        
        this->banco.erase(cpf);
        std::cout << "Cliente " << cpf << " removido com sucesso." << std::endl;
        temp.close();
        file.close();
        const char * p = "Clientes.txt";
        remove(p);
        rename("temp.txt", p); //!< Descarta o arquivo antigo e subtitui pelo atualizado.
    }

    

    else{
        temp.close();
        file.close();
        const char * p = "Clientes.txt";
        remove(p);
        rename("temp.txt", p); //!< Descarta o arquivo antigo e subtitui pelo atualizado.
        throw std::invalid_argument("Cliente nao encontrado."); 
    }
}

void BancoClientes::imprimirRelatorio(char ordem){
    /*!
    * Função que imprimi o cpf e o nome de todos os clientes cadastrados. De acordo com o critério de ordenação informado pelo usuário.
    */
    if(ordem != 'C' && ordem != 'N')
        throw std::invalid_argument ("Entrada Invalida.");

    std::map<long long int, std::string> historico; 
    std::multimap<std::string, long long int> aux;

    std::map<long long int, std::string> :: iterator it;
    std::multimap<std::string, long long int > :: iterator it2;

    
    std::string line;
    std::fstream file("Clientes.txt",std::ios::in | std::ios::out| std::ios::app);
    std::cout << "###################################"<< std::endl;
    std::cout << "\n    CPF     Nome  Data/cadastro"<< std::endl;
    std::cout << std::endl;

    while(getline(file, line)){ 
        std::string key;
        std::string value;
        std::stringstream ss(line); 
        getline(ss, key, ' ');              
        getline(ss, value);   

        if(key != ""){
            historico[stoll(key)] = value;
        }
    }

    if(ordem == 'C'){  //!< Ordena pelo cpf.
    for (it = historico.begin(); it != historico.end(); it++) 
        std::cout << it->first << " " << it->second << std::endl;

    }
    else if (ordem == 'N'){ //!< Ordena pelo nome.
        for (it = historico.begin(); it != historico.end(); it++)  
            aux.insert(std::pair<std::string, long long int>(it->second,it->first));

        for (it2 = aux.begin(); it2 != aux.end(); it2++) 
            std::cout << it2->second << " " << it2->first << std::endl;

    }
    std::cout << "\n###################################"<< std::endl;
    file.close();

}

Cliente* BancoClientes::getCliente(std::string cpf){
    /*!
    * Função que retorna o endereço de memória de um cliente a partir do seu cpf.
    */
    if(this->Pesquisar(cpf)){
        return this->banco[cpf];
    }
    else{
        throw std::invalid_argument("Cliente nao encontrado");
    }
}


bool BancoClientes::isValidCPF(std::string cpf) {
    /*!
    * Função que verifica se o cpf apresenta um formato válido.
    */

    unsigned length = 0;
    length = cpf.length();

    if(length == 11)
        return true;
    return false;


}
