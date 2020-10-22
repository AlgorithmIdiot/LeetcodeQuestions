#pragma once
#include<vector>

class Solution {
private:
	vector<int> memo(n+1,-1);

public:
	int count = 0;
	int fib(int k) { //���仯������ ����fib ���� (2n-1) ��
		num++;
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		if (memo[n] == -1)
			memo[n] = fib(n - 1) + fib(n - 2);
		return memo[n];
	}

	int fib_dp(int n) { //��̬�滮
		memo[0] = 0;
		memo[1] = 1;
		for (int i = 2; i <= n; i++) {
			memo[i] = memo[i - 1] + memo[i - 2];
		}
		return memo[n];
	}

};
