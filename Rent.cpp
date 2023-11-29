#include "Rent.hpp"
#include <vector>
#include "File_Manager.hpp"
using namespace std;


vector<Rent> getRents() {
	auto rawRents = GetFileRows("locacoes.txt");
	vector<Rent> rents;
	Rent rent;
	for (vector<string> rentRow : rawRents)
	{
		rent.status = stoi(rentRow[0]);
		rent.cpf = stoll(rentRow[1]);
		rent.codigo = rentRow[2];
		rent.data_locacao = rentRow[3];
		rent.data_devolucao = rentRow[4];
		rents.push_back(rent);
	}
	return rents;

}