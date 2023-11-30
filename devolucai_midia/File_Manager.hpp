#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
#include <string>
#include <vector>

using namespace std;

void createFile(string fileName);
vector<string> convertRowToArray(string row);
vector<vector<string>> GetFileRows(string fileName);
void report(int reportType, string arg);
void changeRentRowData(const std::string& fileName, vector<string> args);

#endif // !FILE_REPO_HPP
