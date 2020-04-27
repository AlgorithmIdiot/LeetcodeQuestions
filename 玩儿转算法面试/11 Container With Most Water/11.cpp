#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// brute force solution 
//class Solution1{
//public:
//	int maxArea(vector<int>& height) {
//		int maxArea = 0;
//		for (int i = 0; i < height.size() - 1; i++) {
//			for (int j = i + 1; j < height.size(); j++) {
//				if ((j - i) * min(height[i], height[j]) > maxArea)
//					maxArea = (j - i) * min(height[i], height[j]);
//			}
//		}
//		return maxArea;
//	}
//};

//IDEA 
// two pointers at two sides
// move the pointer with smaller height 
class Solution{
public:
	int maxArea(vector<int>& height) {
		int maxArea = 0;
		int left = 0;
		int right = height.size() - 1;
		while (left < right) {
			if (height[left] <= height[right]) {
				maxArea = max(maxArea, (right - left) * height[left]);
				left++;
			}
			else {
				maxArea = max(maxArea, (right - left) * height[right]);
				right--;
			}
		}
		return maxArea;
	}
};

int main() {
	vector<int> height{ 1,8,6,2,5,4,8,3,7 }; 
	cout << Solution().maxArea(height);
	cin.get();
	return 0;
}