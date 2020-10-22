#ifndef __77__
#define __77__

#include<vector>
#include<iostream>

class Solution {
private:
	std::vector<std::vector<int>> res;
	//vector<bool> visited;
	void getcombination( std::vector<int>& comb ,int index, int n ,int k)
	{
		if (comb.size() == k) // the vector starts at zero
		{
			res.push_back(comb);
			return;
		}

		for (int i = index; i <= n; i++)
		{
			
				comb.push_back(i ); // the value should be i+1
				//visited[i] == true;
				getcombination(comb, i+ 1, n, k);
				comb.pop_back();
		}


		return;

	}
public:
	std::vector<std::vector<int>> combine(int n, int k) {
		//visited(n, false);
		if (n < 0 || k<0 || k>n) return res;
		std::vector<int> temp;
		getcombination(temp, 1, n, k);
		return res;
	}
};

#endif 
