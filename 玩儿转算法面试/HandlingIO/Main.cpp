#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;


int main() {
	string temp;
	vector<string>v;
	while (cin >> temp) {
		stringstream ss(temp);//把temp的内容放进ss输入流里
		string str;
		while (getline(ss, str, ',')) {//按照指定的分隔符读取字符串流
			v.push_back(str);
		}
		if (cin.get() == '\n') {
			sort(v.begin(), v.end());
			int n = v.size();
			for (int j = 0; j < n; j++) {
				if (j == n - 1) {
					cout << v[j] << endl;
				}
				else {
					cout << v[j] << ",";
				}
			}
			v.clear();
		}
	}
	return 0;
}