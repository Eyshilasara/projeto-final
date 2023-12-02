#include "ArquivoClientes.hpp"

void BancoClientes::cadastrarCliente(string cpf, string nome){
    map<string , Cliente*> m;
    fstream file("Clientes.txt", std::ios::in | std::ios::out| std::ios::app);
    if(this->Pesquisar(cpf))
        throw invalid_argument("CPF repetido.");
    else{
        Cliente *cliente = new Cliente(nome, cpf);
        this->banco.insert(pair<string ,Cliente*>(cpf, cliente));
        if (file.is_open()) {
            file << cpf << " " << nome << endl;
        }
        else 
            cerr << "Arquivo não está aberto." << endl;
        cout << "Cliente " << cpf  << " cadastrado com sucesso." << endl;
    }
    file.close();
}

void BancoClientes::removerCliente(string cpf){
    ofstream temp("temp.txt"); //arquivo temporario para auxiliar
    string line;
    ifstream file("Clientes.txt");
    if(this->Pesquisar(cpf)){
        while(getline(file, line)){ // loop em cada linha
            
            string key;
            string value;
            stringstream ss(line); // transforma a linha em um stream
            getline(ss, key, ' '); // le a linha ate chega em ' '
            ss >> ws;              // ignora espaços em branco
            getline(ss, value);    // le o restante da linha
            
            if(key!=cpf){
                
                temp << key << " " << value << endl;
                
            }
        }

        
        this->banco.erase(cpf);
        cout << "Cliente " << cpf << " removido com sucesso." << endl;
        temp.close();
        file.close();
        rename("temp.txt","Clientes.txt");

    }
    else{
        throw invalid_argument("Cliente não encontrado");
        temp.close();
        file.close();
        rename("temp.txt","Clientes.txt");
    }

}

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

void BancoClientes::imprimirRelatorio(char ordem){
    if(ordem != 'C' && ordem != 'T')
        throw invalid_argument ("Entrada Invalida.");

    map<long long int, string> :: iterator it;
    multimap<string,  long long int > :: iterator it2;

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