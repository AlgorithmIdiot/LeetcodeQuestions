#include<iostream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;

int main()
{
	ifstream file("Text.txt");
	int N; 
	file >> N;// read into the people numbers
	vector<vector<int>> peopleWill(N, vector<int>());
	for (int i = 0; i < N; i++)// peopleWill 一共有N 行
	{
		while (peopleWill[i].size() < N)
		{
			int temp;
			file >> temp;
			peopleWill[i].push_back(temp);
		}
	}

	vector<int> job(N, 0);// check if the job is occupied 1: occupied,  0: not occupied
	vector<int >ans(N, 0);// ans[i] is the ith people's job id

	for (int peopleId = 0; peopleId < N; peopleId++)
	{
		for (int jobId = 0; jobId < N; jobId++)
		{
			if (job[peopleWill[peopleId][jobId] - 1] == 0)
			{
				ans[peopleId] = peopleWill[peopleId][jobId];
				job[peopleWill[peopleId][jobId] - 1] = 1;
				break; // break the inner loop
			}
			else
				continue;
		}
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << " " ;

	return 0;
}