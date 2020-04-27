#include<vector>
#include<iostream>
using namespace std;
/*idae 1: 
use two indexes 
Index0 specify the location to modify : nums[Index0] = nums[Index1]
Index1 specify the starting point of new value 
i - Index1 < MaxDuplicates : control the number of new values

*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		const int MaxDuplicates = 2;
		int Index1 = 0; // the start of new value
		int Index0 = 0; // specify the position need to modify
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != nums[Index1]) {
				Index1 = i;
				nums[Index0] = nums[Index1];
				Index0++;
			}
			else if (nums[i] == nums[Index1] && i - Index1 < MaxDuplicates) {
				nums[Index0] = nums[Index1];
				Index0++;
			}
			else {
				continue;
			}
		}
		return Index0;
	}
};

int main() {
	vector<int> arr{ 0,0,1,1,1,1,2,3,3 };
	int count = Solution().removeDuplicates(arr);
	std::cout << count << endl;
	std::cin.get();
	return 0;
}