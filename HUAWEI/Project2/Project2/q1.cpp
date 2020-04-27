#include<string>
#include<iostream>
#include<map>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;


int main() {
	ifstream file("Input.txt");
	int n; // the line number to process
	while (file >> n) {
		map<string, string> VariableTable; // first is name, second is value
		for (int i = 0; i < n - 1; i++) {
			string TempString;
			file >> TempString;
			VariableTable[TempString.substr(0, TempString.rfind("="))] = TempString.substr(TempString.rfind("=")+1);
		}
		//expand the variables
		for (map<string, string>::iterator iter = VariableTable.begin(); iter != VariableTable.end(); iter++) {
			size_t start_index = (*iter).second.find("{");
			while (start_index != string::npos) {
				size_t end_index = (*iter).second.find("}");
				string key = (*iter).second.substr(start_index + 1, end_index - start_index - 1);
				size_t length = end_index - start_index + 2;
				(*iter).second.replace(start_index - 1, length, VariableTable[key]);  // 如果VariableTable[key] 还是包含${xxx} 就要继续替换
				start_index = (*iter).second.find("{");
			}
		}


		vector<string> lastVariable;
		string lastLine;
		file >> lastLine;
		lastLine = lastLine.substr(lastLine.rfind("=")+1);
		stringstream ss(lastLine);
		string item;
		while (getline(ss, item, '/')) {
			if(item=="") continue;
			lastVariable.push_back(item);
		}
		for (int i = 0; i < lastVariable.size(); i++) {
			if (lastVariable[i][0] != '$') continue;
			string key = lastVariable[i].substr(lastVariable[i].rfind("{") + 1);
			key.pop_back();
			lastVariable[i] = VariableTable[key];
		}
		for (int i = 0; i < lastVariable.size(); i++) {
			cout << "/" << lastVariable[i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}