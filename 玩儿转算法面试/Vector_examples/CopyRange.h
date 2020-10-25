#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class CopyRange
{
private:
	vector<int> nums{ -12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10 };
	vector<int> l{ 0, 1, 6, 4, 8, 7 };
	vector<int> r{ 4, 4, 9, 7, 9, 10 };

	bool ArithmeticHelpter(vector<int>& range)
	{
		std::sort(range.begin(), range.end());
		int diff = range[1] - range[0];
		for (int i = 1; i < range.size(); i++)
		{
			if (range[i] - range[i - 1] != diff)
				return false;
		}
		return true;
	}
public:
	vector<bool> checkArithmeticSubarrays() {
		vector<bool> ans;
		for (int i = 0; i < l.size(); i++)
		{
			// this line is the copyRange constructor
			vector<int> range(nums.begin() + l[i], nums.begin() + r[i] +1 ); 
			ans.push_back(ArithmeticHelpter(range));
		}
		return ans;
	}


};