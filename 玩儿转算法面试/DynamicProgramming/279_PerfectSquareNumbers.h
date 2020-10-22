#pragma once
#include<algorithm>
class Solution {

private:
	int minLayers = INT_MAX;
	int FindMinLayers(int n, int layer)
	{
		if (n == 0)
		{
			return layer;
		}
		for (int i = 1; i*i <= n; ++i)
		{
			minLayers = std::min(FindMinLayers((n - i * i), ++layer) , minLayers);
		}
		return minLayers;
	}
public:
	int numSquares(int n) {

		return FindMinLayers(n, 0);
	}
};