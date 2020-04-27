#include<string>
#include<iostream>

using namespace std;
class Solution {
public:
	bool isVowel(char char1) {
		if (char1 == 'a' || char1 == 'A' ||
			char1 == 'e' || char1 == 'E'
			|| char1 == 'i' || char1 == 'I'
			|| char1 == 'o' || char1 == 'O'
			|| char1 == 'u' || char1 == 'U')
			return true;
		else
			return false;
	}
	string reverseVowels(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right) {
			while (!isVowel(s[left])) {
				left++;
				if (left == s.size()|| left >= right ) return s;
			}
			while (!isVowel(s[right])) {
				right--;
			}
			swap(s[left], s[right]);
			left++;
			right--;
		}
		return s;
	}

	void print(string s ) {
		for (auto i : s) {
			cout << i << " ";
		}
		cout << endl;
	}
};

int main() {
	string s = "hello";
	string reversed_s = Solution().reverseVowels(s);
	Solution().print(reversed_s);
	cin.get();
	return 0;
}