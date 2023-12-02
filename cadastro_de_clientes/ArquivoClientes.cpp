#include "ArquivoClientes.hpp"

bool BancoClientes::Pesquisar(string cpf){
        map<string, string> configuration; 
        string line;
        fstream file("Clientes.txt",std::ios::in | std::ios::out| std::ios::app);
        
        while(getline(file, line)){ 
            string key;
            string value;
            stringstream ss(line); 
            getline(ss, key, ' '); 
            ss >> ws;              
            getline(ss, value);    
            
            // Store them
            configuration[key] = value;
        }
        file.close();
        if(configuration[cpf] == ""){
            return false;
        }
        else 
            return true;
        
        

}
void BancoClientes::cadastrarCliente(string cpf, string nome){
    time_t agora = time(0);// Define a data que começou uma execucao
    tm* ltm = localtime(&agora);
    std::string dataCadastro = std::to_string(1900 + ltm->tm_year) + '-' + std::to_string(1 + ltm->tm_mon) + '-' + std::to_string(ltm->tm_mday);
    if(this->isValidCPF(cpf)){
        fstream file("Clientes.txt", std::ios::in | std::ios::out| std::ios::app);
        if(this->Pesquisar(cpf))
            throw invalid_argument("CPF repetido.");
        else{
            Cliente *cliente = new Cliente(nome, cpf);
            this->banco.insert(pair<string ,Cliente*>(cpf, cliente));
            if (file.is_open()) {
                file << cpf << " " << nome << " " << dataCadastro<< endl;
            }
            else 
                cerr << "Arquivo não está aberto." << endl;
            cout << "Cliente " << cpf  << " cadastrado com sucesso." << endl;
        }
        file.close();
    }
    else{
        throw invalid_argument("CPF Inválido.");
    }
}

void BancoClientes::removerCliente(string cpf){
    ofstream temp("temp.txt"); //arquivo temporario para auxiliar
    string line;
    ifstream file("Clientes.txt");
    if(this->Pesquisar(cpf)){
        while(getline(file, line)){ // loop em cada linha
            
            string key;
            string value;
            string data;
            stringstream ss(line); // transforma a linha em um stream
            getline(ss, key, ' '); // le a linha ate chega em ' '
            ss >> ws;              // ignora espaços em branco
            getline(ss, value, ' ');    
            ss >> ws;              
            getline(ss, data);   // le o restante da linha
            
            if(key!=cpf){
                
                temp << key << " " << value << " " << data << endl;
                
            }
        }
        
        this->banco.erase(cpf);
        cout << "Cliente " << cpf << " removido com sucesso." << endl;
        temp.close();
        file.close();
        const char * p = "Clientes.txt";
        remove(p);
        rename("temp.txt", p);

    }
    else{
        throw invalid_argument("Cliente não encontrado");
        temp.close();
        file.close();
        rename("temp.txt","Clientes.txt");
    }
}

void BancoClientes::imprimirRelatorio(char ordem){
    if(ordem != 'C' && ordem != 'N')
        throw invalid_argument ("Entrada Invalida.");

    map<long long int, string> :: iterator it;
    multimap<string, long long int > :: iterator it2;

    map<long long int, string> historico; 
    string line;
    fstream file("Clientes.txt",std::ios::in | std::ios::out| std::ios::app);
    
    while(getline(file, line)){ 
        string key;
        string value;
        stringstream ss(line); 
        getline(ss, key, ' '); 
        ss >> ws;              
        getline(ss, value);   

        if(key != "CADASTRO" && key != ""){
            historico[stoll(key)] = value;
        }
    }

    if(ordem == 'C'){
    for (it = historico.begin(); it != historico.end(); it++) 
        cout << it->first << " " << it->second << endl;

    }
    else if (ordem == 'N'){
        multimap<string, long long int> aux;
        for (it = historico.begin(); it != historico.end(); it++)  
            aux.insert(pair<string, long long int>(it->second,it->first));

        for (it2 = aux.begin(); it2 != aux.end(); it2++) 
            cout << it2->second << " " << it2->first << endl;

    }
    file.close();

}

Cliente* BancoClientes::getCliente(string cpf){
    if(this->Pesquisar(cpf)){
        return this->banco[cpf];
    }
    else{
        throw invalid_argument("Cliente não encontrado");
    }
}


bool BancoClientes::isValidCPF(std::string cpf) {
    // unsigned lenght = 0;
    // int ver1 = 0, ver2 = 0;
    // char aux;

    // while (cpf[lenght]) {
    //     lenght++;
    // }

    // if (lenght != 11)
    //     return false;

    // for (int j = 0; j < 9; j++) {
    //     aux = cpf[j];
    //     ver1 += atoi(&aux) * (j + 1);
    // }

    // ver1 %= 11;


    // for (int j = 0; j < 9; j++) {
    //     aux = cpf[j];
    //     ver2 += atoi(&aux) * j;
    // }

    // ver2 += ver1 * 9;
    // ver2 %= 11;

    // aux = cpf[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(lenght) - 2];
    // if (atoi(&aux) == ver1) {
    //     aux = cpf[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(lenght) - 1];
    //     if (atoi(&aux) == ver2)
    //         return true;
    // }
    // return false;
    return true;
}
