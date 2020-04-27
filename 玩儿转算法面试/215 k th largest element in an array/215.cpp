#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:

	// this is the partition of quick sort
	int findKthLargest(vector<int>& nums, int k) {
		int low = 0;
		int high = nums.size() - 1;
		int pi = partition(nums, low, high);
		while (pi != k - 1) {
			if (pi > k - 1) {
				high = pi - 1;
				pi = partition(nums, low, high);

			}
			else {
				low = pi + 1;
				pi = partition(nums, low, high);
			}

		}
		return nums[pi];
	}
	int partition(vector<int>& nums, int low, int high) {
		int random_index = low + rand() % (high - low + 1);
		swap(nums[random_index], nums[high]);
		int pivot = nums[high];
		int i = low - 1;
		for (int j = low; j < high; j++) {
			if (nums[j] > pivot) {
				i++;
				swap(nums[i], nums[j]);
			}
		}
		i++;
		swap(nums[i], nums[high]);
		return i;
	}
};


class QuickSort {
public:
	// partion the array within [low, high]
	int partition(vector<int>&nums, int low, int high) {
		int pivot = nums[high]; 
		int i = low - 1;
		for (int j = low; j < high; j++) {
			if (nums[j] < pivot) { 
				i++; // is this redundent?
				swap(nums[i], nums[j]); 
			}
		}
		i++;
		swap(nums[i], nums[high]);
		return i;
	}

	void quickSort(vector<int>& nums, int low, int high) {
		// implement the quickSort algorithm 
		if (low < high) {
			int pi = partition(nums, low, high);

			quickSort(nums, low, pi-1);
			quickSort(nums, pi + 1, high);
		}
		return;
	}
};
void printArray(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	vector<int> arr{ 3,2,1,5,6,4 };
	int k = 2; 


	cout << "\n the k th largest element is :\n ";
	cout << Solution().findKthLargest(arr, k) << endl;

	cout << "before sorting the array\n";
	printArray(arr);
	QuickSort().quickSort(arr, 0, arr.size() - 1);

	cout << "after sorting the array by quick sort\n";
	printArray(arr);
	cin.get();
	return 0;
}