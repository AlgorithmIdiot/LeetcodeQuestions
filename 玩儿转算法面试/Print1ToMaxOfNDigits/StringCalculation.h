#pragma once
#include<iostream>

bool Increment(char *number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = 0, index_len = 0;
	// size of the array
	while (number[index_len] != '\n')
	{
		nLength++;
		index_len++;
	}
	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}

void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	//int nLength = strlen(number);
	int nLength = 0, index_len = 0;
	// size of the array
	while (number[index_len] != '\n')
	{
		nLength++;
		index_len++;
	}
	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}
}

void Print1ToMaxOfNDigits(int n)
{
	if (n < 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\n';
	while (!Increment(number))
	{
		PrintNumber(number);
	}
	delete[]number;
}