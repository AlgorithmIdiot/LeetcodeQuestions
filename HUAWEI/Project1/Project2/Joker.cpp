#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

vector<string> split(string s, const char delim) {
	stringstream ss(s);
	string item;
	vector<string> result;
	while (getline(ss, item, delim)) {// �ո�Ӧ��û��Ӱ���
		result.push_back(item);
	}
	return result;
}
void output(vector<string> a) {
	for (auto& i : a)
	{
		cout << i << " " ;
	}
	cout << endl;
	system("pause");
}
int main() {
	ifstream infile("input_JOKER.txt");
	string inputS;
	getline(infile,inputS);
		vector<string> twoPlayers = split(inputS, '-');// twoPlayers[0] 
		stringstream left(twoPlayers[0]), right(twoPlayers[1]);
		vector<string> player1, player2;
		string temp;
		while (left >> temp) {
			player1.push_back(temp);
		}
		while (right >> temp) {
			player2.push_back(temp);
		}
		string str = "345678910JQKA2jokerJOKER";
		//���һ�������������ģ�ֱ�ӷ���
		if (player1[0] == "joker" && player1.size() == 2) {
			output(player1);
		}
		else if (player2[0] == "joker" && player2.size() == 2) {
			output(player2);
		}
		// size ��ͬ����Ϊ��ͬ���͵���,ֱ�ӱȽ���ֵ��С
		else if (player1.size() == player2.size()) {
			if (player1[0] == "joker") {
				if (player2[0] == "JOKER")
				{
					output(player2);
				}
				else {
					output(player1);
				}
			}
			else if (player2[0] == "joker")
			{
				if (player1[0] == "JOKER")
				{
					output(player1);
					return 0;
				}
				else {
					output(player2);
					return 0;
				}
			}
			//vector<string> tempout = player1[0] < player2[0] ? player2 : player1;
			//output(tempout);
			output(str.find(player1[0]) < str.find(player2[0] ) ? player2 : player1);
			return 0;
		}
		// size ��ͬ����Ϊ�ǲ�ͬ���͵���
		else {
			//�����ը���ͷ��� ը, size==4 �ʹ���ը
			if (player1.size() == 4) {
				output(player1);
				return 0;
			}
			else if (player2.size() == 4) {
				output(player2);
				return 0;
			}
			cout << "ERROR" << endl;
			return 0;
		}
		system("pause");
}