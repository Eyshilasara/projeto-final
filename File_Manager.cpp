#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "File_Manager.hpp"
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

string getCurrentDateAsString() {
	struct tm newtime;
	auto now = system_clock::now();
	time_t currentTime = system_clock::to_time_t(now);
	localtime_s(&newtime, &currentTime);
	stringstream ss;
	ss << put_time(&newtime, "%Y-%m-%d");
	return ss.str();
}

//Cria um arquivo no sistema de arquivos
void createFile(string path) {
	ofstream fileOut(path, ios::app);
	ifstream fileIn(path);
	// Verifica se o arquivo existe
	if (!fileIn) {
		cerr << "Error opening the file." << endl;
		return;
	}
	fileOut.close();
}

//Altera o arquivo de locações, nas linhas de status e data de devolução. 
void changeRentRowData(const string& fileName, vector<string> args) {
	ifstream file(fileName);
	if (!file.is_open()) {
		cerr << "Error opening the file." << endl;
		return;
	}
	string line;
	int lineNumber = 0;
	bool found = false;
	vector<string> rows;
	while (getline(file, line)) {
		lineNumber++;
		for (string arg : args) {
			if (line.find(arg) != string::npos) {
				found = true;
				string firstChar = "", lastChar = "";
				firstChar = '1';
				lastChar = isblank(line[line.length() - 2]) ? "0" : "1";
				string replacement = getCurrentDateAsString();
				line = line.replace(0, 1, firstChar);
				line = line.replace(line.length() - (lastChar == "0" ? 1 : 10), 10, replacement);
			}
		}
		rows.push_back(line);
	}
	if (!found) {
		cout << "String not found in the file." << endl;
	}
	file.close();
	ofstream fileOut(fileName);
	if (!fileOut.is_open()) {
		cerr << "Error opening the file for writing." << endl;
		return;
	}
	for (const string& row : rows) {
		fileOut << row << '\n';
	}
	fileOut.close();


}

// Converte a linha do arquivo txt em um array.
vector<string> convertRowToArray(string row) {
	vector<string> result;
	string currentChar;

	for (int i = 0; i < row.length(); i++) {
		// isspace verifica se aquele char é um espaço em branco.
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

// Pega todas as linhas do arquivo e o transforma num vetor de vetores. O método
// que o chama que deve fazer a implementação do struct correspondente
vector<vector<string>> GetFileRows(string fileName) {
	ifstream file(fileName);
	vector<vector<string>> rows;
	// isspace verifica se o arquivo está aberto.
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
		cerr << "Error opening the file." << endl;
		return rows;
	}
}

vector<vector<string>> filter(int columnNumber, string arg) {
	vector<vector<string>> rows = GetFileRows("locacoes.txt");
	vector<vector<string>> filteredRows;
	for (vector<string> row : rows) {
		if (row[columnNumber] == arg) {
			filteredRows.push_back(row);
		}
	}
	return filteredRows;
}


void report(int reportType = 0, string arg = "") {
	vector<vector<string>> rows = GetFileRows("locacoes.txt");
	vector<vector<string>> filteredRows;
	switch (reportType) {

	case 0: // imprimir TODAS as locações (imprimir todo o arquivo)
		filteredRows = rows;
		break;
	case 1: // impressão por cliente: funcionário informa cpf do cliente e é
			// impresso apenas as linhas contendo as suas locações
		filteredRows = filter(1, arg);
		break;
	case 2: // imprimir apenas as locações em aberto ou concluidas (depende do arg informado)
		filteredRows = filter(0, arg);
		break;
	}
	for (auto& row : filteredRows) {
		string rentDate = row[3].substr(8, 2) + "/" + row[3].substr(5, 2) + "/" + row[3].substr(0, 4);
		string returnDate = row[4].length() > 1 ? row[4].substr(8, 2) + "/" + row[4].substr(5, 2) + "/" + row[4].substr(0, 4) : row[4];

		cout << "Status: " << row[0] << " CPF: " << row[1] << " Código: " << row[2]
			<< " Data de Locação: " << rentDate
			<< " Data de Devolução: " << returnDate << endl;
	}
}

