#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;


class Solution {
public:
	string minWindow(string s, string t) {
		int cnt[128] = {}, remain = t.size(), pos = 0;
		int len = INT_MAX;
		for (char c : t) cnt[c]--;
		for (unsigned r = 0, l = 0; r < s.size(); r++) {
			if (cnt[s[r]] < 0) remain--;
			cnt[s[r]]++;
			while (cnt[s[l]] > 0) cnt[s[l++]]--;
			if (!remain && r - l + 1 < len) {
				len = r - l + 1;
				pos = l;
			}
		}
		return !remain ? s.substr(pos, len) : "";
	}
};


//If there is no such window in S that covers all characters in T, return the empty string "".
//If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
int main() {
	string S = "ADOBECODEBANC", T = "ABC";
	string str = Solution().minWindow(S, T);
	for (auto &i : str) {
		cout << i << " ";
	}
	cout << endl;
	cin.get();
	return 0;
}