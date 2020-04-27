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
	while (getline(ss, item, delim)) {// 空格应该没有影响吧
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
		//如果一对王，就是最大的，直接返回
		if (player1[0] == "joker" && player1.size() == 2) {
			output(player1);
		}
		else if (player2[0] == "joker" && player2.size() == 2) {
			output(player2);
		}
		// size 相同就认为是同类型的牌,直接比较数值大小
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
		// size 不同就认为是不同类型的牌
		else {
			//如果有炸，就饭回 炸, size==4 就代表炸
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