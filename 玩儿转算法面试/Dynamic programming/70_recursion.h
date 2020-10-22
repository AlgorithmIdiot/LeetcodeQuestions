#pragma once

class Solution {
private:
	int calcWays(int n) {
		if (n == 0)
			return 1;

		if (n == 1)
			return 1;

		return calcWays(n - 1) + calcWays(n - 2);
	}
public:
	int climbStairs(int n) {
		return calcWays(n);
	}
};
