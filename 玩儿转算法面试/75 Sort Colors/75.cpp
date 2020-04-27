#include<iostream>
#include<vector>
using namespace std;

// two pass version
class Solution1 {
public:
	void sortColors(vector<int>& nums) {
		int count_0 = 0;
		int count_1 = 0;
		int count_2 = 0;
		for (auto i : nums) {
			if (i == 0)
				count_0++;
			else if (i == 1)
				count_1++;
			else if (i == 2)
				count_2++;
		}
		for (int i = 0; i < count_0; i++) {
			nums[i] = 0;
		}

		for (int i = count_0; i < count_0 + count_1; i++)
			nums[i] = 1;

		for (unsigned i = count_0 + count_1; i < nums.size(); i++)
			nums[i] = 2;

		
		return;
	}
	// one pass solution 

	void sortColors2(vector<int>& nums) {
		int i = 0, j = nums.size() - 1;
		for (int k = 0; k <= j;) {
			if (nums[k] == 0) swap(nums[i++], nums[k++]);
			else if (nums[k] == 2) swap(nums[k], nums[j--]);
			else k++;
		}

		return;
	}
};

int main() {
	vector<int> arr{ 2,0,2,1,1,0 };
	Solution1().sortColors(arr);

	for (unsigned i = 0; i < arr.size(); i++) {
		cout << arr[i]<<"  ";
	}
	cout << endl;

	cout << "the one pass solution" << endl;
	// test of the one pass solution 
	vector<int> arr2{ 2,0,2,1,1,0 };
	Solution1().sortColors2(arr2);

	for (unsigned i = 0; i < arr2.size(); i++) {
		cout << arr2[i] << "  ";
	}
	cout << endl;
	cin.get();
	return 0;
}