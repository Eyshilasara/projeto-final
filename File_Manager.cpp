#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include "File_Manager.hpp"
using namespace std;

//Cria um arquivo no sistema de arquivos
void createFile(string path) {
	ofstream fileOut(path, ios::app);
	ifstream fileIn(path);
	//Verifica se o arquivo existe
	if (!fileIn) {
		cerr << "Error opening the file." << std::endl;
		return;
	}
	fileOut.close();
}

//Converte a linha do arquivo txt em um array.
vector<string> convertRowToArray(string row) {
	vector<string> result;
	string currentChar;

	for (int i = 0; i < row.length(); i++) {
		//isspace verifica se aquele char é um espaço em branco.
		if (!isspace(row[i])) {
			currentChar += row[i];
		}
		else {
			result.push_back(currentChar);
			currentChar.clear();
		}
	}

	if (!currentChar.empty()) {
		result.push_back(currentChar);
	}

	return result;
}
//Pega todas as linhas do arquivo e o transforma num vetor de vetores. O método que o chama que deve fazer a implementação do struct correspondente
vector<vector<string>> GetFileRows(string fileName) {
	ifstream file(fileName);
	vector<vector<string>> rows;
	//isspace verifica se o arquivo está aberto.
	if (file.is_open()) {
		string rowData;
		while (getline(file, rowData)) {
			istringstream input(rowData);
			vector<string> row = convertRowToArray(rowData);
			rows.push_back(row);

		}
		file.close();
		return rows;
	}

	else {
		cerr << "Error opening the file." << std::endl;
		return rows;
	}

}

	
