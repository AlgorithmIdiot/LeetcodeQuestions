#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// sliding window 
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int l = 0, r = -1;
		int frequencey[256] = {0};
		int res=0;
		while (l < s.size()) {
			// make sure r+1 is wihtin the range and s[r+1] has not appeared
			if (r+1 < s.size() && frequencey[s[r+1]] == 0) { 
				frequencey[s[++r]] ++;
			}
			else { 
				frequencey[s[l]]--;
				l++;
			}
			
			res = max(res, r - l + 1);
			
		}
		return res;
	}
};

int main() {
	string s = "abcabcbb";
	int length = Solution().lengthOfLongestSubstring(s);
	cout << length << endl;
	cin.get();
	return 0;
}