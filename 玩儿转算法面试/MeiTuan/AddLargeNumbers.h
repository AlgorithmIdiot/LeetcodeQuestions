#pragma once
#include"Solution.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>


// this code can deal with positive nubmers, but it cannot handle the negative numbers
class AddLargeNumbers: public Solution
{
private:

public:
	AddLargeNumbers()
	{}
	~AddLargeNumbers()
	{}

	void run() const {

		std::cout << "this is derived AddLargeNumbers: \n"; 
		std::fstream file("AddLargeNumbers.txt ");
		std::string num1, num2;
		std::string skip;
		std::getline(std::getline(file, skip, '"'), num1, '"'  );
		std::getline(std::getline(file, skip, '"'), num2, '"');
		//file >> std::quoted(num1) >> num2; // 
		int index1 = num1.size() - 1;
		int index2 = num2.size() - 1;
		int temp = 0;
		std::vector<int> sum;
		while ( (index1>=0) && (index2>=0) ) {
			int digit1 = num1[index1]-'0';
			int digit2 = num2[index2]-'0';
			sum.insert(sum.begin(), (digit1 + digit2 + temp) % 10);
			temp = (digit1 + digit2) / 10;
			index1--;
			index2--;
		}
		while (index1 >= 0)
		{
			int digit = num1[index1] - '0';
			sum.insert(sum.begin(), digit);
			index1--;
		}
		while (index2 >= 0)
		{
			int digit = num2[index2] - '0';
			sum.insert(sum.begin(), digit);
			index2--;
		}
		for (int i = 0; i < sum.size(); i++)
			std::cout << sum[i];

		return;
	}

};