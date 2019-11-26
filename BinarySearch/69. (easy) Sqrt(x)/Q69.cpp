class Solution {
public:
	int mySqrt(int x) {
		if (x < 2)
			return x;
		long low = 2;
		long high = x / 2.;

		while (low <= high)
		{
			long mid = (low + high) / 2;
			if (std::pow(mid, 2) > x)
				high = mid - 1;
			else if (std::pow(mid, 2) < x)
			{
				// if (std::pow(mid+1, 2) > x)
					// return mid; 
				low = mid + 1;
			}
			else
				return mid;
		}
		return high;

	}
};