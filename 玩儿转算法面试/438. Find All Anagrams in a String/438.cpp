#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// sliding window
//compare frequency array of the pattern with the frequency array of the string windows
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int>pattern(26, 0);
		vector<int>str(26, 0);
		int np = p.length();
		//final output vector
		vector<int> result;

		//Building the frequency mapping of the pattern
		for (unsigned i = 0; i < p.length(); i++) {
			pattern[p[i] - 'a']++;
		}

		//interating through 2nd string for finding anagrams
		for (unsigned i = 0; i < s.length(); i++) {
			//adding new element in array
			str[s[i] - 'a']++;

			//if array size greater than p ..reduce the string from backwards like in queue
			if (i >= np) {
				str[s[i - np] - 'a']--;
			}

			// Checking if the string window is anagram
			if (str == pattern) {
				result.push_back(i - np + 1);
			}
		}
		return result;
	}
};

int main() {
	string s = "cbaebabacd";
	string p = "abc";
	vector<int> vec = Solution().findAnagrams(s, p);
	for (auto & i : vec) {
		cout << i << ' ';
	}
	cout << endl;
	cin.get();
	return 0;
}