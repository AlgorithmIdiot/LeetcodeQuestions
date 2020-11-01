#include<string>
#include<iostream>
#include<map>
#include<fstream>
using namespace std;
int main()
{
	ifstream file("Text.txt");
	int len; // string length
	string str; //
	file >> len;
	file >> str;
	int index1 = 0, index2 = len - 1;
	map<char, int> head;
	map<char, int> tail;
	head['M'] = 0;
	head['T'] = 0;
	tail['M'] = 0;
	tail['T'] = 0;
	string ans;// the answer
	
	while ( head['M'] == 0 || head['T'] == 0 || tail['M'] == 0 || tail['T'] == 0)
	{
		if (index1 >= index2) break;
		// handle the head
		if (str[index1] == 'M' && head['M'] == 0 && head['T'] == 0)
		{
			head['M'] = 1;
			index1++;
		}
		else if (str[index1] == 'T' && head['M'] == 1 && head['T'] == 0)
		{
			head['T'] = 1;
			index1++;
		}
		else if (head['M'] == 0 || head['T'] == 0) index1++;
		// handle the tail 
		if (str[index2] == 'T'  && tail['T'] == 0 && tail['M'] == 0)
		{
			tail['T'] = 1;
			index2--;
		}
		else if (str[index2] == 'M' && tail['T'] == 1 && tail['M'] == 0)
		{
			tail['M'] = 1;
			index2--;
		}
		else if (tail['M'] == 0 || tail['T'] == 0) index2--;
		
	}
	//ans = str.substr(str.begin() + index1 , str.begin()+ index2+1);
	for (int i = index1; i <= index2; i++)
	{
		ans += str[i];
	}
	cout << ans << std::endl;
	return 0;
}