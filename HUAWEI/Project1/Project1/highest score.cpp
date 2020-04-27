#include<fstream>// reading into data from files
#include<string>
#include<vector> 
#include<sstream>
#include<iostream>
#include<algorithm>
// find the maximum between the range [left, right]
int findMax(std::vector<int> vec, int left, int right) {
	// use the iterator of vector to output the maximum value
	int maximum = 0;
	for (int i =left-1; i < right ; i++) {
		if (vec[i] >= maximum) maximum = vec[i];
	}
	return maximum;
}

int main() {
	std::ifstream infile("input.txt");
	int StudentNum;
	int OperationNum;
	// open the space for the score vector
	infile >> StudentNum >> OperationNum;
	std::vector<int> score;// store the score of students
	//initialize the score
	for (int i = 0; i < StudentNum; i++) {
		int temp;
		infile >> temp;
		score.push_back(temp);
	}
	std::string operation;
	int a, b;
	while (infile >> operation >> a >> b) {
		if (operation == "Q")
			std::cout << findMax(score, std::min(a, b),std::max(a,b) ) << std::endl;
		else if (operation == "U")
			score[a - 1] = b;
	}
	system("pause");
	return 0;
}