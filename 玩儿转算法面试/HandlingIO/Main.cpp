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
		stringstream ss(temp);//��temp�����ݷŽ�ss��������
		string str;
		while (getline(ss, str, ',')) {//����ָ���ķָ�����ȡ�ַ�����
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