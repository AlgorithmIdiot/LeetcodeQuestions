#include<iostream>
#include<fstream>
#include<sstream>
#include<stack>
#include<vector>
using namespace std;
//(add(sub(div 8 2) (mul 1 9)) 20)

int main()
{
	fstream file("Text.txt");
	int a, b, c;
	string tempStr;
	vector<string> v;
	//file.getline(tempStr, '\t');
	//while (getline(file, tempStr, '\\t')) {//按照指定的分隔符读取字符串流
	//	v.push_back(tempStr);
	//}
	while (file >> a >> b >> c)
	{
	}

	//cout << v[0] << v[1] << v[2];
	cin.get();
	return 0;
}