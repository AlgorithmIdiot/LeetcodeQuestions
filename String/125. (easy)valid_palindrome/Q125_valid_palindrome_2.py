##considering the "isalnum()" function

class Solution:
    def isPalindrome(s):
        ss = ""
        for i in range(0, len(s)):
            if s[i].isalnum():
                ss+=s[i] # connect a string after a string
        ss = ss.lower()
        return ss==ss[::-1]
    
def main():
    a = Solution
    string_1 = "A man, a plan, a canal: Panama"
    print(a.isPalindrome(string_1))
    
    em = "As"
    em.lower()
    print(em)
    

if __name__=='__main__':
    main()