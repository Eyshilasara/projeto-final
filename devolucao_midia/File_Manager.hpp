#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
#include <string>
#include <vector>

using namespace std;

void createFile(string fileName);
vector<string> convertRowToArray(string row);
vector<vector<string>> GetFileRows(string fileName);




#endif // !FILE_REPO_HPP
