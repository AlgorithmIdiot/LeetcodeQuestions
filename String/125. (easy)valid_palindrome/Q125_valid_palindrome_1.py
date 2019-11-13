# -*- coding: utf-8 -*-
## using regrex to judge whether the char is a english words

import re
class Solution:
    def isPalindrome(s):
        s = ''.join(re.findall(r'\w',s)).lower()
        print(s)
        return s==s[::-1]
            
    
def main():
    s=Solution
    string_1 = "A man, a plan, a canal: Panama"
    print(s.isPalindrome(string_1))
    
    
if __name__=='__main__':
    main()
    