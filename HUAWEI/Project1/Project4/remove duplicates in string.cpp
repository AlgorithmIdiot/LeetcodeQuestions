#include<vector>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main() {
	string str = "dBowNgxyPZXZXlBTMKFskExQEK";
		char item;
		vector<char> results;
		results.clear();
		results.push_back(str[0]);
		for (size_t j = 1; j < str.length(); j++) {
			item = str[j];
			size_t i = 0;
			for (i = 0; i < results.size(); i++) {
				if (results[i] == item)
					break;
			}
			if (i < results.size())
				continue;
			else
				results.push_back(item);
		}

		for (auto & i : results) {
			cout << i;
		}
		cout << endl;
		system("pause");
	return 0;
}