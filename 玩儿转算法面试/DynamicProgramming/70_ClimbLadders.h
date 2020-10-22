#pragma once
// 性质，拥有重叠子结构
class Solution {
public:
	int climbStairs(int n) {
		vector<int> memo(n + 1, -1); 
		memo[0] = 1;
		memo[1] = 1;
		for (int i = 2; i < n; i++)
		{
			memo[i] = memo[i-1] + memo[i-1]
		}
		return memo[n];
	}
};