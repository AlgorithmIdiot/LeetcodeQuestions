class Solution {
public:
    //#include <cctype>
    bool isPalindrome(string s) {
        int l = 0;
        if (s.size() == 0 ) return true;
        int r = s.size() - 1; 
        while (l < r)
        {
            while( !isalnum(s[l]) && l < s.size()) l++;
            while( !isalnum(s[r]) && r > 0) r--;
            if (r == 0 || l == r) return true;
            if (toupper(s[l]) == toupper(s[r]) )
            {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};